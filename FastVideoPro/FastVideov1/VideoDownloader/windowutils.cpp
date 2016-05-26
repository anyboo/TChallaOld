//#pragma comment(lib,"iphlpapi.lib")
//#pragma comment(lib,"wsock32.lib")
#include "windowutils.h"
#include <windows.h>
#include <Winsock2.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <QNetworkInterface>
#include "PING.h"
#include <IPTypes.h>
#include "pcap.h"
#include "utils.h"


WindowUtils::WindowUtils()
{
}


bool WindowUtils::isValidNetMacaddress(const QString& macaddress)
{
    return !macaddress.isEmpty() && macaddress != "00:00:00:00:00:00:00:E0"
            && !macaddress.startsWith("00:50:56:C0");
}


void WindowUtils::getLocalIPs(std::vector<QString> &IPs)
{
    IPs.clear();
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface i, list) {
        if (i.isValid() && isValidNetMacaddress(i.hardwareAddress()) &&
             i.humanReadableName() == QString::fromLocal8Bit("��������"))
        {
            qDebug() << i.humanReadableName();
            foreach(QHostAddress address,i.allAddresses())
            {
                if (address.protocol() == QAbstractSocket::IPv4Protocol
                        && !address.isLoopback())
                {
                    if (IPs.end() == std::find(IPs.begin(), IPs.end(), address.toString()))
                    {
                        IPs.push_back(address.toString());
                        qDebug() << address.toString();
                    }
                }
            }
        }

    }
}

void WindowUtils::getLocalIPs(const QString& sHostName, std::vector<QString> &IPs){
    IPs.clear();
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface i, list) {
        if (i.isValid() && isValidNetMacaddress(i.hardwareAddress()))
        {
            qDebug() << i.name() << i.humanReadableName();
            
            foreach(QHostAddress address, i.allAddresses())
            {
                if (address.protocol() == QAbstractSocket::IPv4Protocol
                    && !address.isLoopback())
                {
                    if (IPs.end() == std::find(IPs.begin(), IPs.end(), address.toString()))
                    {
                        IPs.push_back(address.toString());
                        qDebug() << address.toString();
                    }
                }
            }
        }

    }
}

BOOL FindProcessByName(const char* szFileName, PROCESSENTRY32& pe)
{
    // ���ý��̿���ö�ٽ��̵ķ�������ָ�����ƽ���
    HANDLE hProcesses;
    PROCESSENTRY32 lpe =
    {
        sizeof(PROCESSENTRY32)
    };

    QString sFileName(QString::fromLocal8Bit(szFileName).toLower());

    // �������̿���
    hProcesses = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcesses == INVALID_HANDLE_VALUE)
        return FALSE;
    // ��ȡ��һ������ʵ��
    BOOL isExist = ::Process32First(hProcesses, &lpe);
    BOOL isRunning = FALSE;
    QString strName;
    while (isExist)
    {
        strName = QString::fromWCharArray(lpe.szExeFile).toLower();
        if (sFileName.indexOf(strName) >= 0)
        {
            isRunning = TRUE;
            break;
        }
        // ������һ������ʵ��
        isExist = ::Process32Next(hProcesses, &lpe);
    }

    if (isRunning)
    {
        memcpy(&pe, &lpe, sizeof(PROCESSENTRY32));
    }

    CloseHandle(hProcesses);

    return isRunning;
}

bool WindowUtils::findProcessByName(const char* szFileName){
    PROCESSENTRY32 pe;
    return FindProcessByName(szFileName, pe);
}

void WindowUtils::terminateProcess(const char* szFileName){
    HANDLE hProcesses;
    PROCESSENTRY32 lpe =
    {
        sizeof(PROCESSENTRY32)
    };

    QString sFileName(QString::fromLocal8Bit(szFileName).toLower());

    // �������̿���
    hProcesses = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcesses == INVALID_HANDLE_VALUE)
    {
        qDebug() << "INVALID_HANDLE_VALUE";
        return;
    }
       
    // ��ȡ��һ������ʵ��
    BOOL isExist = ::Process32First(hProcesses, &lpe);
    BOOL isRunning = FALSE;
    QString strName;
    while (isExist)
    {
        strName = QString::fromWCharArray(lpe.szExeFile).toLower();
        if (strName.indexOf(sFileName) >= 0)
        {
            HANDLE h = OpenProcess(1, TRUE, lpe.th32ProcessID);   //ȡ����ʵ�� PROCESS_TERMINATE
            TerminateProcess(h, 0);
        }
        // ������һ������ʵ��
        isExist = ::Process32Next(hProcesses, &lpe);
    }

    CloseHandle(hProcesses);
}

void WindowUtils::copy(const QFileInfo& source, const QDir& dest, const QString& destName){
    if (!source.exists())
    {
        return;
    }

    QString destFile;
    if (destName.isEmpty())
    {
        destFile = dest.path() + "/" + source.fileName();
    }
    else{
        destFile = dest.path() + "/" + destName;
    }

    if (!dest.exists()){
        dest.mkpath(dest.path());
    }
   
    if (source.isFile())
    {
        CopyFileA(source.filePath().toLocal8Bit().data(),
            destFile.toLocal8Bit().data(), false);
    }
    else if (source.isDir())
    {
        QFileInfoList list = QDir(source.absoluteFilePath()).entryInfoList();
        for (int i = 0; i < list.size(); ++i) {
            const QFileInfo& fileInfo = list.at(i);
            qDebug() << fileInfo.fileName();
            if (!fileInfo.fileName().startsWith("."))
            {
                WindowUtils::copy(fileInfo, QDir(destFile));
            }
        }
    }
}
bool WindowUtils::setNetConfig(const QString& sName, const QString& sIP, const QString& sMask, const QString& sGate, bool bWait){
//    return true;
    QString mask = QString("mask=%1").arg(sMask);
    QString name = QString("name=\"%1\"").arg(sName);
    QString addr = QString("addr=%1").arg(sIP);
    QStringList argList = QStringList() << "interface" << "ip" << "set" << "address" << name << "source=static" << addr << mask;

    if (!sGate.isEmpty())
    {
        QString gateway = QString("gateway=%1").arg(sGate);
        QProcess::execute("netsh", QStringList() << "interface" << "ip" << "set" << "address" << name << "source=static" << addr << mask << gateway);
    }
    else{
        QProcess::execute("netsh", QStringList() << "interface" << "ip" << "set" << "address" << name << "source=static" << addr << mask );
    }
    if (!bWait)
    {
        return true;
    }
    int maxPingTime = 1000 * 3;
    ::Sleep(2000);
    while (maxPingTime > 0 && !CPing::instance().Ping(sIP.toStdString().c_str(), 20)){
        ::Sleep(1000);
        maxPingTime -= 1000;
    }
    
    return maxPingTime > 0;
}

bool WindowUtils::setNetDhcp(const QString& sName){
    QString name = QString("name=\"%1\"").arg(sName);
    QProcess::execute("netsh", QStringList() << "interface" << "ip" << "set" << "address" << name << "source=dhcp");
    
    return true;
}

bool WindowUtils::isConnecteTo(const QString& IP){
    return CPing::instance().Ping(IP.toStdString().c_str(), 500);
}


typedef struct arppkt
{
    unsigned short hdtyp;//Ӳ������
    unsigned short protyp;//Э������
    unsigned char hdsize;//Ӳ����ַ����
    unsigned char prosize;//Э���ַ����
    unsigned short op;//���������ͣ�����ֵ:ARP/RARP
    u_char smac[6];//ԴMAC��ַ
    u_char sip[4];//ԴIP��ַ
    u_char dmac[6];//Ŀ��MAC��ַ
    u_char dip[4];//Ŀ��IP��ַ
}arpp;


#define  INNDER_SPECIAL_IP "170.151.24.203"
bool WindowUtils::getDirectDevice(QString& ip, QString& netGate)
{
    ip.clear();
    struct tm * timeinfo;
    struct tm *ltime;
    time_t rawtime;

    int result;
    int i = 0, inum;
    pcap_if_t * alldevs;//ָ��pcap_if_t�ṹ�б�ָ��
    pcap_t * adhandle;//�������׽���
    char errbuf[PCAP_ERRBUF_SIZE];//���󻺳���СΪ256
    u_int netmask; //������������
    char packet_filter[] = "ether proto \\arp";
    struct bpf_program fcode;
    struct pcap_pkthdr * header;
    const u_char * pkt_data;
    //����־�ļ�

    //��ǰ���п��õ������豸
    if (pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        qDebug() << "Error in pcap_findalldevs:" << errbuf;
        return false;
    }

    if (!alldevs)
    {
        qDebug() << "cannot find net device!  install WinPcap?";
        return false;
    }

    qDebug() << alldevs->description << alldevs->name;

    if ((adhandle = pcap_open_live(alldevs->name, 65536, 1, 1000, errbuf)) == NULL)
    {
        qDebug() << "pcap_open_live failed!  not surpport by WinPcap ?" << alldevs->name;
        pcap_freealldevs(alldevs);
        return false;
    }

    if (pcap_datalink(adhandle) != DLT_EN10MB || alldevs->addresses == NULL) {
        qDebug() << "pcap_datalink(adhandle) != DLT_EN10MB || alldevs->addresses == NULL";
        return false;
    }


    netmask = ((struct sockaddr_in *)(alldevs->addresses->netmask))->sin_addr.S_un.S_addr;
    pcap_freealldevs(alldevs);
    

    //�����������ֻ����ARP��
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) < 0)
    {
        qDebug() << "unable to compile the packet filter.Check the syntax.";
        return false;
    }

    //���ù�����
    if (pcap_setfilter(adhandle, &fcode) < 0)
    {
        qDebug() << "Error setting the filter.";
        return false;
    }
    std::vector<QString> IPs;
    getLocalIPs(IPs);
    const int nMaxSeconds = 30;
    int start = GetTickCount();
    QString specialIP;
    while (true)
    {
        if (GetTickCount() - start > 30 * 1000)
        {
            qDebug() << "arp time out";
            break;
        }
        //ѭ������ARP���ݰ�
        if (pcap_next_ex(adhandle, &header, &pkt_data) == 0){
            continue;
        }
        arpp* arph = (arpp *)(pkt_data + 14);
        if (arph->op == 256) //arp
        {
            if (arph->sip[0] == 0)
            {
                continue;
            }
            if (arph->sip[0] == 169 && arph->sip[1] == 254)
            {
                continue;
            }
            QString source = QString("%1.%2.%3.%4").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]).arg(arph->sip[3]);
            if (IPs.end() != std::find(IPs.begin(), IPs.end(), source)){
                continue;
            }

            netGate = source;
            if (ip.isEmpty())
            {
                start = GetTickCount() - 29 * 1000;
            }

            ip = QString("%1.%2.%3.%4").arg(arph->dip[0]).arg(arph->dip[1]).arg(arph->dip[2]).arg(arph->dip[3]);
            if (arph->dip[0] != arph->sip[0] || arph->dip[1] != arph->sip[1] || arph->dip[2] != arph->sip[2] || ip == netGate)
            {
                if (arph->sip[3] != 1)
                {
                    ip = QString("%1.%2.%3.1").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]);
                }
                else{
                    ip = QString("%1.%2.%3.254").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]);
                }
            }

            qDebug() << "arp" << ip << netGate;
        }
        else
        {
            if (arph->dip[0] == 0)
            {
                continue;
            }
            if (arph->dip[0] == 169 && arph->dip[1] == 254)
            {
                continue;
            }

            QString source  = QString("%1.%2.%3.%4").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]).arg(arph->sip[3]);
            if (IPs.end() != std::find(IPs.begin(), IPs.end(), source)){
                continue;
            }


            netGate = source;
            ip = QString("%1.%2.%3.%4").arg(arph->dip[0]).arg(arph->dip[1]).arg(arph->dip[2]).arg(44);
            qDebug() << "aarp" << ip << netGate;
            break;
        }

    }

    return !ip.isEmpty();
}

bool WindowUtils::getDirectDevice(QString& ip, QString& netGate, std::set<QString>& otherIPS, int secondsWait){

    ip.clear();
    struct tm * timeinfo;
    struct tm *ltime;
    time_t rawtime;

    int result;
    int i = 0, inum;
    pcap_if_t * alldevs;//ָ��pcap_if_t�ṹ�б�ָ��
    pcap_t * adhandle;//�������׽���
    char errbuf[PCAP_ERRBUF_SIZE];//���󻺳���СΪ256
    u_int netmask; //������������
    char packet_filter[] = "ether proto \\arp";
    struct bpf_program fcode;
    struct pcap_pkthdr * header;
    const u_char * pkt_data;

    //��ǰ���п��õ������豸
    if (pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        qDebug() << "Error in pcap_findalldevs:" << errbuf;
        return false;
    }

    if (!alldevs)
    {
        qDebug() << "cannot find net device!  install WinPcap?";
        return false;
    }

    qDebug() << alldevs->description << alldevs->name;

    if ((adhandle = pcap_open_live(alldevs->name, 65536, 1, 1000, errbuf)) == NULL)
    {
        qDebug() << "pcap_open_live failed!  not surpport by WinPcap ?" << alldevs->name;
        pcap_freealldevs(alldevs);
        return false;
    }

    if (pcap_datalink(adhandle) != DLT_EN10MB || alldevs->addresses == NULL) {
        qDebug() << "pcap_datalink(adhandle) != DLT_EN10MB || alldevs->addresses == NULL";
        return false;
    }


    netmask = ((struct sockaddr_in *)(alldevs->addresses->netmask))->sin_addr.S_un.S_addr;
    pcap_freealldevs(alldevs);
    std::map<QString, std::set<QString>> mpDestSource;

    //�����������ֻ����ARP��
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) < 0)
    {
        qDebug() << "unable to compile the packet filter.Check the syntax.";
        return false;
    }

    //���ù�����
    if (pcap_setfilter(adhandle, &fcode) < 0)
    {
        qDebug() << "Error setting the filter.";
        return false;
    }
    QString specialIP;
    std::vector<QString> IPs;
    getLocalIPs(IPs);
    int start = GetTickCount();
    const int MAX_WAIT_OTHER_IP_SECONDS = 10;
    while (true)
    {
        if (GetTickCount() - start > secondsWait * 1000)
        {
            qDebug() << "arp time out";
            break;
        }
        //ѭ������ARP���ݰ�
        if (pcap_next_ex(adhandle, &header, &pkt_data) == 0){
            continue;
        }

        arpp* arph = (arpp *)(pkt_data + 14);
        if (arph->op == 256) //arp
        {
            if (arph->sip[0] == 0)
            {
                continue;
            }
            if (arph->sip[0] == 169 && arph->sip[1] == 254)
            {
                continue;
            }

            QString source = QString("%1.%2.%3.%4").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]).arg(arph->sip[3]);
            QString destIP = QString("%1.%2.%3.%4").arg(arph->dip[0]).arg(arph->dip[1]).arg(arph->dip[2]).arg(arph->dip[3]);
            if (IPs.end() != std::find(IPs.begin(), IPs.end(), source)){
                continue;
            }
            if (source == INNDER_SPECIAL_IP)
            {
                specialIP = destIP;
                continue;
            }
            if (!Utils::isInnerIP(source))
            {
                continue;
            }
            
            if (netGate.isEmpty())
            {
                netGate = source;
            }
            
            if (ip.isEmpty() && secondsWait * 1000 - GetTickCount() + start > MAX_WAIT_OTHER_IP_SECONDS * 1000)
            {
                start = GetTickCount() - (secondsWait - MAX_WAIT_OTHER_IP_SECONDS) * 1000;
                ip = destIP;
                if (arph->dip[0] != arph->sip[0] || arph->dip[1] != arph->sip[1] || arph->dip[2] != arph->sip[2] || ip == netGate)
                {
                    if (arph->sip[3] != 1)
                    {
                        ip = QString("%1.%2.%3.1").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]);
                    }
                    else{
                        ip = QString("%1.%2.%3.254").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]);
                    }
                }
            }

            
            otherIPS.insert(source);
            if (Utils::isInnerIP(destIP))
            {
                mpDestSource[destIP].insert(source);
            }
            
 
            qDebug() << "arp" << source << destIP;
        }
        else
        {
            if (arph->dip[0] == 0)
            {
                continue;
            }
            if (arph->dip[0] == 169 && arph->dip[1] == 254)
            {
                continue;
            }
            
            QString source = QString("%1.%2.%3.%4").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]).arg(arph->sip[3]);
            QString dest = QString("%1.%2.%3.%4").arg(arph->dip[0]).arg(arph->dip[1]).arg(arph->dip[2]).arg(arph->dip[3]);
            if (IPs.end() != std::find(IPs.begin(), IPs.end(), source)){
                continue;
            }
            if (!Utils::isInnerIP(source))
            {
                continue;
            }

            netGate = source;
            otherIPS.insert(source);
            
            if (ip.isEmpty() && secondsWait * 1000 - GetTickCount() + start > MAX_WAIT_OTHER_IP_SECONDS * 1000)
            {
                start = GetTickCount() - (secondsWait - MAX_WAIT_OTHER_IP_SECONDS) * 1000;
            }

            ip = QString("%1.%2.%3.%4").arg(arph->sip[0]).arg(arph->sip[1]).arg(arph->sip[2]).arg(44);
            qDebug() << "aarp" << source << dest;
           // break;
        }

    }
    
    std::map<QString, std::set<QString>>::iterator itNetgate = mpDestSource.end();
    for (auto it = mpDestSource.begin(); it != mpDestSource.end(); it++)
    {
        if (it->second.size() > 1 &&
            (itNetgate == mpDestSource.end() || itNetgate->second.size() < it->second.size()))
        {
            itNetgate = it;
        }
    }
    if (itNetgate != mpDestSource.end())
    {
        netGate = itNetgate->first;
        QString s = netGate.left(netGate.lastIndexOf(".") + 1);
        for (int i  = 2; i < 255; i++)
        {
            ip = s + QString::number(i);
            if (ip != netGate && itNetgate->second.find(ip) == itNetgate->second.end())
            {
                break;
            }
        }
    }
    else{
        if (netGate.isEmpty() && !specialIP.isEmpty())
        {
            netGate = specialIP;
        }
        if (!netGate.isEmpty())
        {
            netGate = netGate.left(netGate.lastIndexOf(".") + 1) + "1";
            for (int i = 2; i < 255; i++)
            {
                ip = netGate.left(netGate.lastIndexOf(".") + 1) + QString::number(i);
                if (ip != specialIP)
                {
                    break;
                }
            }
        }
    }


    return !ip.isEmpty();
}
bool WindowUtils::setIPByDHCP(QString& ip, QString& mask, QString& netGate){
    QString sName = QString::fromLocal8Bit("��������");
    WindowUtils::setNetDhcp(sName);
    std::vector<QString> ips;
    int maxPingTime = 1000 * 3;
    ::Sleep(2000);
    for (WindowUtils::getLocalIPs(sName, ips); ips.size() == 0 && maxPingTime > 0; WindowUtils::getLocalIPs(sName, ips)){
        ::Sleep(1000);
        maxPingTime -= 1000;
    }
    
    bool r = false;
    if (ips.size() > 0)
    {
        _IP_ADAPTER_INFO* pIpAdapterInfo = (PIP_ADAPTER_INFO)malloc(sizeof(PIP_ADAPTER_INFO));
        ULONG uOutBufLen = sizeof(PIP_ADAPTER_INFO);//���������Ϣ�Ļ�������С

		//add by zhangyaofa 2016/5/17
		char *pOldIpAdapterInfo = (char *)pIpAdapterInfo;
		//add end
				
        //��һ�ε���GetAdapterInfo��ȡulOutBufLen��С
        int errorNo = GetAdaptersInfo(pIpAdapterInfo, &uOutBufLen);
        if (errorNo == ERROR_BUFFER_OVERFLOW)
        {
            //��ȡ��Ҫ�Ļ�������С
            free(pIpAdapterInfo);
            pIpAdapterInfo = (PIP_ADAPTER_INFO)malloc(uOutBufLen);//��������Ҫ���ڴ�

			//add by zhangyaofa 2016/5/17
			pOldIpAdapterInfo = (char *)pIpAdapterInfo;
			//add end

            errorNo = (GetAdaptersInfo(pIpAdapterInfo, &uOutBufLen));
        }

        if (NO_ERROR == errorNo)
        {
            while (pIpAdapterInfo && (!r))
            {
                for (IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
                    pIpAddrString != NULL && (!r); pIpAddrString = pIpAddrString->Next){
                    if (*ips.begin() == pIpAddrString->IpAddress.String)
                    {
                        if (!WindowUtils::setNetConfig(sName, *ips.begin(), pIpAddrString->IpMask.String, pIpAdapterInfo->GatewayList.IpAddress.String, true))
                        {
                            break;
                        }
                        ip = *ips.begin();
                        mask = pIpAddrString->IpMask.String;
                        netGate = pIpAdapterInfo->GatewayList.IpAddress.String;
                        r = true;
                    }


                }
                pIpAdapterInfo = pIpAdapterInfo->Next;
            }
        }
		//modify by zhangyaofa 2016/5/17
        //free(pIpAdapterInfo);
		////////////////////////////////
		free(pOldIpAdapterInfo);
		//modify end
    }

    return r;
}
