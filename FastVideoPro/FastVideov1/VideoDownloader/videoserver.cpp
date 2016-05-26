#include "videoserver.h"
#include <QCoreApplication>
#include <QList>
#include <QLibrary>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <qdebug.h>
#include "windowutils.h"
#include <QThread>
#include <eh.h>
#include <algorithm>
#include "xmlsettings.h"
#include <QTcpSocket>
#include "time.h"
#include "videoserversSvr.h"

SERIAL_MEMMBER_8(LoginServerInfo, name, ip, port, user, password, macAddress, factory, id)


QDataStream & operator << (QDataStream &dataStream, RecordFile &d)
{
    dataStream<<d.beginTime;
    dataStream<<d.channel;
    dataStream<<d.endTime;
    dataStream<<QString::fromLocal8Bit(d.name.c_str());
    dataStream<<d.size;
    dataStream<<d.getPrivateDataSize();
    if (d.getPrivateDataSize() > 0)
    {
        dataStream.writeBytes((char*)d.getPrivateData(), d.getPrivateDataSize());
    }

    return dataStream;
}

QDataStream & operator >> (QDataStream &dataStream, RecordFile &d)
{
    dataStream>>d.beginTime;
    dataStream>>d.channel;
    dataStream>>d.endTime;
    QString qName;
    dataStream>>qName;
    d.name = qName.toStdString();
    dataStream>>d.size;
    dataStream>>d.PrivateDataDataSize;
    if (d.PrivateDataDataSize > 0)
    {
        uint bufLen = d.PrivateDataDataSize;
        dataStream.readBytes(d.pPrivateData, bufLen);
        d.PrivateDataDataSize = bufLen;
    }

    return dataStream;
}

QDataStream & operator << (QDataStream &dataStream, LoginServerInfo &d)
{
    dataStream << (qint32)d.factory << d.ip << d.macAddress << d.name << d.password
                  << d.port << d.user <<d.id;

    return dataStream;
}

QDataStream & operator >> (QDataStream &dataStream, LoginServerInfo &d)
{
    qint32 f = 0;
    dataStream >> f;
    d.factory = (DeviceFactory)f;
    dataStream >> d.ip >> d.macAddress >> d.name >> d.password
                                    >> d.port >> d.user >> d.id;

    return dataStream;
}


std::deque<videoserverFactory *> videoserverFactory::s_Factorys;
std::recursive_mutex videoserverFactory::s_mutexFactorys;
std::vector<std::string> videoserverFactory::s_vcExternFunStrings;

OEMFacMap videoserverFactory::m_OEMXMFacMap;   //����OEMϵ��
OEMFacMap videoserverFactory::m_OEMHIKFacMap;  //����OEMϵ��
OEMFacMap videoserverFactory::m_OEMDHFacMap;   //��OEMϵ��
OEMFacMap videoserverFactory::m_OEMWSDFacMap;  //���˴�OEMϵ��
OEMFacMap videoserverFactory::m_OEMJiuAnFacMap;  //�Ű�OEMϵ��
OEMFacMap videoserverFactory::m_OEMDongYangFacMap; //����OEMϵͳ
OEMFacMap videoserverFactory::m_OEMZhongWeiFacMap; //��άOEMϵ��


downloadEvent::downloadEvent(videoserver* pSvr, qint64 totalSize, qint64 size, bool failed) :
   QEvent(SERVICE_CALLBACK_EVENT), m_pSvr(pSvr), m_totalSize(totalSize), m_size(size), m_failed(failed)
{

}


const std::deque<videoserverFactory*>& videoserverFactory::getFactorys()
{
    std::lock_guard<std::recursive_mutex> lock(s_mutexFactorys);
    
    if (s_Factorys.size() == 0)
    {
        qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << "s_Factorys.size() == 0";
        std::vector< int > vcFactorys;
        SvrFactory::getFactorys(vcFactorys);
        for (int i = 0; i < vcFactorys.size(); i++)
        {
            int f = vcFactorys[i];
            IVideoServerFactory* pFactory = new SvrFactory(f);
            videoserverFactory* pvsf = new videoserverFactory(pFactory);
            s_Factorys.push_back(pvsf);
            qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << f;
            addFakeFactory(pFactory);
        }
    }

    return s_Factorys;
}

void videoserverFactory::initOEMFacList()
{
	// ������OEM
	{
		m_OEMXMFacMap["�޷�Ƽ�"] = SISC_IPC_JF;
		m_OEMXMFacMap["ʩ�Ͱ�"] = SISC_IPC_SNA;
		m_OEMXMFacMap["����"] = SISC_IPC_XM;
		m_OEMXMFacMap["����̩"] = SISC_IPC_HAISHITAI;
		m_OEMXMFacMap["�´ﹲ��"] = SISC_IPC_XINDAGONGCHUANG;
		m_OEMXMFacMap["���Ӵ�"] = SISC_IPC_TIANSHIDA;
		m_OEMXMFacMap["������"] = SISC_IPC_SHOUWEIZHE;
		m_OEMXMFacMap["����˼��"] = SISC_IPC_SILANG;
		m_OEMXMFacMap["����Τ��"] = SISC_IPC_HUONIWEIER;
		m_OEMXMFacMap["�Ƶ���"] = SISC_IPC_YUNDIANSHI;
		m_OEMXMFacMap["���ǰ���"] = SISC_IPC_SHIXINGANFANG;
		m_OEMXMFacMap["������"] = SISC_IPC_LIANDA;
		m_OEMXMFacMap["������̩"] = SISC_IPC_NANNINGGUANGTAI;
		m_OEMXMFacMap["�Ƶ���"] = SISC_IPC_YUNDIANSHI;
		m_OEMXMFacMap["�¼���"] = SISC_IPC_DEJIALA;


 		m_OEMXMFacMap["����ΰҵ"] = SISC_IPC_MEIFANGWEIYE;
 		m_OEMXMFacMap["��������"] = SISC_IPC_GUANGZHOUBANGSHI;
 		m_OEMXMFacMap["�Ӱ�����"] = SISC_IPC_GUANGZHOUSHIAN;
 		m_OEMXMFacMap["�ǰ��Ƽ�"] = SISC_IPC_QIAOAN;
        m_OEMXMFacMap["������"] = SISC_IPC_LANGSHIXIN;
        m_OEMXMFacMap["�ǰ�"] = SISC_IPC_YAAN;
 		m_OEMXMFacMap["̩���߿�"] = SISC_IPC_TAIWEIGAOKE;
        m_OEMXMFacMap["��������"] = SISC_IPC_GUANGZHOUYISHI;
        m_OEMXMFacMap["���ں꿵����OEM����"] = SISC_IPC_HONGKANGWEISHIOEMXM;

        m_OEMXMFacMap["����˳"] = SISC_IPC_ZHENSHISHUN;                      // ����˳
        m_OEMXMFacMap["��ɽƷ��"] = SISC_IPC_JINSHANPINKE;                            // ��ɽƷ��
        m_OEMXMFacMap["�������"] = SISC_IPC_XUFENGWS;                                // �������
        m_OEMXMFacMap["���ӱ�"] = SISC_IPC_XINGSHIBAO;                              // ���ӱ�

        m_OEMXMFacMap["���Ӱ�"] = SISC_IPC_ZSB;                      // ���Ӱ�
        m_OEMXMFacMap["������"] = SISC_IPC_KER;                            // ������
        m_OEMXMFacMap["����"] = SISC_IPC_AN;                                // ����
        m_OEMXMFacMap["������"] = SISC_IPC_AWT;                              // ������

        m_OEMXMFacMap["������"] = SISC_IPC_JAA;                      // ������
        m_OEMXMFacMap["�ν�Ѷ"] = SISC_IPC_XJX;                            // �ν�Ѷ
        m_OEMXMFacMap["����"] = SISC_IPC_HY;                                // ����
        m_OEMXMFacMap["��о"] = SISC_IPC_QX;                              // ��о

        m_OEMXMFacMap["�ʿ�"] = SISC_IPC_YK;                      // �ʿ�
        m_OEMXMFacMap["�Ӱ���"] = SISC_IPC_JAB;                            // �Ӱ���
        m_OEMXMFacMap["����"] = SISC_IPC_NZ;                                // ����
        m_OEMXMFacMap["��֮��"] = SISC_IPC_LZJ;                              // ��֮��

        m_OEMXMFacMap["����"] = SISC_IPC_SX;                      // ����
        m_OEMXMFacMap["������"] = SISC_IPC_WTS;                            // ������
        m_OEMXMFacMap["��֮Ѷ"] = SISC_IPC_AZX;                                // ��֮Ѷ
        m_OEMXMFacMap["�ٿƲ�"] = SISC_IPC_BKB;                              // �ٿƲ�

        m_OEMXMFacMap["���ƻ�ǿ"] = SISC_IPC_DTHQ;                      // ���ƻ�ǿ
        m_OEMXMFacMap["����"] = SISC_IPC_HAIY;                            // ����
        m_OEMXMFacMap["��������"] = SISC_IPC_ALKJ;                                // ��������
        m_OEMXMFacMap["�����Ƽ�"] = SISC_IPC_XTKJ;                              // �����Ƽ�

        m_OEMXMFacMap["�������"] = SISC_IPC_HXGJ;                      // �������
        m_OEMXMFacMap["����"] = SISC_IPC_ERJIA;                            // ����
        m_OEMXMFacMap["��Ϊ��Ѷ"] = SISC_IPC_HWSX;                                // ��Ϊ��Ѷ
        m_OEMXMFacMap["����Ȫ"] = SISC_IPC_XINGRQ;                              // ����Ȫ

        m_OEMXMFacMap["г������"] = SISC_IPC_XMDZ;                      // г������
        m_OEMXMFacMap["�������"] = SISC_IPC_AOKS;                            // �Ŀ�ɭ
        m_OEMXMFacMap["�������"] = SISC_IPC_HRRS;                                // �������
        m_OEMXMFacMap["���οƼ�"] = SISC_IPC_AJKJ;                              // ���οƼ�

        m_OEMXMFacMap["�ᰲ�Ƽ�"] = SISC_IPC_NAKJ;                      // �ᰲ�Ƽ�
        m_OEMXMFacMap["��ͼ��Ѷ"] = SISC_IPC_LTSX;                            // ��ͼ��Ѷ
        m_OEMXMFacMap["����˹"] = SISC_IPC_WEIDS;                                // ����˹
        m_OEMXMFacMap["�����б���"] = SISC_IPC_SZSBD;                              // �����б���

        m_OEMXMFacMap["ӡ�οƼ�"] = SISC_IPC_YMKJ;                      // ӡ�οƼ�
        m_OEMXMFacMap["������"] = SISC_IPC_RUILT;                            // ������
        m_OEMXMFacMap["Ӣ����"] = SISC_IPC_YINGFT;                                // Ӣ����
        m_OEMXMFacMap["��������"] = SISC_IPC_LATX;                              // ��������

        m_OEMXMFacMap["ά�����"] = SISC_IPC_WBDZ;                      // ά�����
        m_OEMXMFacMap["���񻪿�"] = SISC_IPC_XRHK;                            // ���񻪿�
        m_OEMXMFacMap["�㲩����"] = SISC_IPC_DBDZ;                                // �㲩����
        m_OEMXMFacMap["�ɺ���"] = SISC_IPC_FEIHX;                              // �ɺ���

        m_OEMXMFacMap["������"] = SISC_IPC_CHAOBL;                      // ������
        m_OEMXMFacMap["��˸��ó"] = SISC_IPC_YSSM;                            // ��˸��ó
        m_OEMXMFacMap["�����"] = SISC_IPC_PANK;                                // �����
        m_OEMXMFacMap["���Ӽ�"] = SISC_IPC_BAOJS;                              // ���Ӽ�

        m_OEMXMFacMap["����"] = SISC_IPC_KELAN;                      // ����
        m_OEMXMFacMap["����ͨ"] = SISC_IPC_BEIST;                            // ����ͨ
        m_OEMXMFacMap["�ƴ�Ƽ�"] = SISC_IPC_KDKJ;                                // �ƴ�Ƽ�
        m_OEMXMFacMap["ɽ������"] = SISC_IPC_SBZN;                              // ɽ������

        m_OEMXMFacMap["������"] = SISC_IPC_JINGDR;                      // ������
        m_OEMXMFacMap["����ʥ��"] = SISC_IPC_HZSS;                            // ����ʥ��
        m_OEMXMFacMap["���Ͷ���"] = SISC_IPC_HTDF;                                // ���Ͷ���
        m_OEMXMFacMap["�Ǳ�����"] = SISC_IPC_XBWS;                              // �Ǳ�����

        m_OEMXMFacMap["����Ӣ����ҵ"] = SISC_IPC_BJYKJY;                      // ����Ӣ����ҵ
        m_OEMXMFacMap["������̩��"] = SISC_IPC_GZSTH;                            // ������̩��
        m_OEMXMFacMap["�����а�ԣ"] = SISC_IPC_SZSAY;                                // �����а�ԣ
        m_OEMXMFacMap["��������"] = SISC_IPC_GZZT;                              // ��������
	}
	
	// ����OEM
	{
		m_OEMHIKFacMap["�㶫����"] = SISC_IPC_GUANGDONGLINYU;

        m_OEMHIKFacMap["���Ӱ�"] = SISC_IPC_KUANGSHIAN;
		m_OEMHIKFacMap["���ݺ���"] = SISC_IPC_GZHX;

		m_OEMHIKFacMap["����ʢ"] = SISC_IPC_BAOXINGSHENG;
		m_OEMHIKFacMap["������OEM"] = SISC_IPC_LANDAOEMHK;
		m_OEMHIKFacMap["��������"] = SISC_IPC_XIANHAIFANG;
		m_OEMHIKFacMap["��������ʱ��"] = SISC_IPC_BEIJINGZHENGFANG;
		m_OEMHIKFacMap["̩��ΰҵOEM����"] = SISC_IPC_TAIKANGWEIYEOEMHK;
		m_OEMHIKFacMap["����"] = SISC_IPC_TIANMIN;
		m_OEMHIKFacMap["�ƶ�"] = SISC_IPC_KEEN;
		m_OEMHIKFacMap["������"] = SISC_IPC_ANJULIAO;
		m_OEMHIKFacMap["�������ڹ���"] = SISC_IPC_YIRONGGUANSHI;
		m_OEMHIKFacMap["�������ƽ̨"] = SISC_IPC_DONGDAJIZHI;
		m_OEMHIKFacMap["GEӲ��¼���"] = SISC_IPC_GERECORDER;
		m_OEMHIKFacMap["�����׿�61ϵ��"] = SISC_IPC_MIKA61;
		m_OEMHIKFacMap["�����׿�8081ϵ��NVR"] = SISC_IPC_MIKA8081;
		m_OEMHIKFacMap["����"] = SISC_IPC_HENGYI;
		m_OEMHIKFacMap["���ڰ˰�"] = SISC_IPC_BAAN;
		m_OEMHIKFacMap["���ڰٻ�"] = SISC_IPC_BAIHUI;
		m_OEMHIKFacMap["���ں��Ӱ�"] = SISC_IPC_HAISHIAN;
		m_OEMHIKFacMap["���ھ��J"] = SISC_IPC_JUFU;
		m_OEMHIKFacMap["��������"] = SISC_IPC_SAIQING;
		m_OEMHIKFacMap["�����˿ư�"] = SISC_IPC_XINGKEAN;
		m_OEMHIKFacMap["������"] = SISC_IPC_TIANTIANYOU;
	}
	
	// ���˴�OEM
	{
		m_OEMWSDFacMap["��������"] = SISC_IPC_XP;
	}
	
	// �Ű����OEM
	{
		m_OEMJiuAnFacMap["̩��ΰҵ"] = SISC_IPC_TAIKANGWEIYE;
	}
	
	// ��������OEM
	{
		m_OEMDongYangFacMap["�꿵����"] = SISC_IPC_HONGKANGWEISHI;
	}
	
	// ��άOEM
	{
		m_OEMZhongWeiFacMap["ʨ����Ѷ"] = SISC_IPC_SALX;
		m_OEMZhongWeiFacMap["��������"] = SISC_IPC_GZLL;
		m_OEMZhongWeiFacMap["���ﰲ��"] = SISC_IPC_ZHONGTIANANBAO;
		m_OEMZhongWeiFacMap["����"] = SISC_IPC_JIRUI;
		m_OEMZhongWeiFacMap["�����"] = SISC_IPC_HUABANGHAISHI;
	}
}

void videoserverFactory::addFakeFactory(IVideoServerFactory *pFactory)
{
	switch(pFactory->factory())
	{
		case SISC_IPC_DIZHIPU:
		{
			OEMFacMap::iterator itr = m_OEMXMFacMap.begin();
			for(itr; itr !=m_OEMXMFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_HIKVISION:
		{
			OEMFacMap::iterator itr = m_OEMHIKFacMap.begin();
			for(itr; itr !=m_OEMHIKFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_WSD:
		{
			OEMFacMap::iterator itr = m_OEMWSDFacMap.begin();
			for(itr; itr !=m_OEMWSDFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_JIUAN:
		{
			OEMFacMap::iterator itr = m_OEMJiuAnFacMap.begin();
			for(itr; itr !=m_OEMJiuAnFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_DOANGYANG:
		{
			 OEMFacMap::iterator itr = m_OEMDongYangFacMap.begin();
			for(itr; itr !=m_OEMDongYangFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}	
		case SISC_IPC_ZHONGWEI:
		{
			OEMFacMap::iterator itr = m_OEMZhongWeiFacMap.begin();
			for(itr; itr !=m_OEMZhongWeiFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}	
		default:
			break;
	}
}

//<<<<<<<<<<<<<add by zhangyaofa 2016/5/19
OEMFacMap videoserverFactory::GetFakeFactory(int nDeviceFactory)
{
	switch (nDeviceFactory)
	{
	case SISC_IPC_DIZHIPU:
		return m_OEMWSDFacMap;
	case SISC_IPC_HIKVISION:
	case SISC_IPC_WSD:
	case SISC_IPC_JIUAN:
	case SISC_IPC_DOANGYANG:
	case SISC_IPC_ZHONGWEI:
	default:
		break;
	}
}
//>>>>>>>>>>>add end

videoserverFactory* videoserverFactory::getFactory(DeviceFactory f)
{
    getFactorys();
    std::lock_guard<std::recursive_mutex> lock(s_mutexFactorys);
    for (int index = 0; index < s_Factorys.size(); index++)
    {
        if (s_Factorys[index]->factory() == f)
        {
            return s_Factorys[index];
        }
    }
    return nullptr;
}



void videoserverFactory::releaseVideoServerFactory()
{
    std::lock_guard<std::recursive_mutex> lock(s_mutexFactorys);
    for (int i = 0; i < s_Factorys.size(); i++)
    {
        delete s_Factorys[i];
    }
    s_Factorys.clear();
}

videoserverFactory::videoserverFactory(IVideoServerFactory *p)
    :  mpFactory(p), mInit(false)
{
	initOEMFacList();
    sheInit();
}

videoserverFactory::~videoserverFactory()
{
    mpFactory->destroy();
}

std::shared_ptr<videoserver> videoserverFactory::create(bool nullSver)
{
    if (!mInit)
    {        
        mInit = sheInit();
        mInit = true;
    }
    std::shared_ptr<videoserver> p;
    if (mInit)
    {        
        std::lock_guard<std::recursive_mutex> lock(m_mutexService);
        for (auto it =  m_vcServices.begin(); it != m_vcServices.end(); it++)
        {
            if ((*it)->isRelease())
            {   
                if ((*it)->isNull())
                {
                    if (nullSver || nullptr == mpFactory)
                    {                       
                        p = *it;
                        break;
                    }
                }
                else
                {
                    if (!nullSver && nullptr != mpFactory)
                    {                       
                        p = *it;
                        break;
                    }
                }
            }
        }

        if (!p)
        {
            std::vector< std::shared_ptr<videoserver> > s_vcServices;
            if (nullptr == mpFactory || nullSver)
            {                
                p = std::shared_ptr<videoserver>(new videoserver(nullptr, this));
            }
            else{
                IVideoServer* pvr = mpFactory->create();               
                if (pvr != nullptr)
                {
                   
                    p = std::shared_ptr<videoserver>(new videoserver(pvr, this));
                }
            }
        }
    }

    if (p)
    {       
        p->setRelease(false);
    }

    return p;
}
void videoserverFactory::destroy(videoserver* p){
    std::lock_guard<std::recursive_mutex> lock(m_mutexService);
    for (auto it = m_vcServices.begin(); it != m_vcServices.end(); it++)
    {
        if ((*it).get() == p)
        {
            m_vcServices.erase(it);
            return;
        }
    }
}
IVideoServer* videoserverFactory::createDerect()
{
    if (!mInit)
    {
        mInit = sheInit();
        mInit = true;
    }

    if (mInit)
    {
        if (nullptr == mpFactory)
        {
            return nullptr;
        }

        return mpFactory->create();
    }

    return nullptr;
}

PlayBackPosCaculator::PlayBackPosCaculator()
{
    _time64(&mStartPlayTime);
}

int PlayBackPosCaculator::getPos()
{
    if (mPlaySeconds <= 0)
    {
        return 100;
    }

    __time64_t nowPlayTime;
    _time64(&nowPlayTime);

    __time64_t pos =  (nowPlayTime - mStartPlayTime) * 100 / mPlaySeconds;
    if (pos > 100)
    {
        return 100;
    }

    return pos;
}

void PlayBackPosCaculator::setPos(unsigned int pos)
{
    if (mPlaySeconds <= 0)
    {
        return;
    }

    __time64_t nowPlayTime;
    _time64(&nowPlayTime);

    mStartPlayTime = nowPlayTime - (pos * mPlaySeconds) / 100;
}
__int64 DownloadPosCaculator::getFileSize(const std::string& sFile)
{
    QFile f(QString::fromLocal8Bit(sFile.c_str()));
    if (f.exists())
    {
        return f.size();
    }
    else
    {
        return 0;
    }
}
DownloadPosCaculator::DownloadPosCaculator()
{
    mTotalSize = 0;
}

int DownloadPosCaculator::getPos(__int64& totalSize, __int64& currentSize)
{
    currentSize = getFileSize(mSaveFile);
    totalSize = mTotalSize;
    if (totalSize > 0 && totalSize >= currentSize)
    {
        return currentSize * 100 / totalSize;
    }

    return 100;
}
videoserver* videoserver::getServerByPort(int port)
{
    return nullptr;
}
videoserver::videoserver(IVideoServer *p, videoserverFactory *f) :
    mpServer(p), mpFactory(f), mStop(false), mpThrDowload(nullptr)
{
    m_bRelease = true;
}

videoserver::~videoserver()
{
    std::lock_guard<std::recursive_mutex> lockeThread(mMutexThread);
    if (mpThrDowload != nullptr)
    {
        mStop = true;
        mpThrDowload->join();
        delete mpThrDowload;
    }
    if (nullptr != mpServer)
    {
        mpServer->destroy();
        mpServer = nullptr;
    }
     

}

//����ɾ������ʱ��¼������
void videoserver::remove()
{
	delete this;
}
void videoserver::destroy()
{
    
}
std::shared_ptr<videoserver>  videoserver::clone()
{
    auto pNewServer = mpFactory->create(true);
    if (nullptr == mpServer || !pNewServer)
    {
        return pNewServer;
    }
    
    IVideoServer* p = mpServer->clone();
    if (p != nullptr)
    {
        pNewServer->mpServer = p;
		bool bStop = false;
        if (pNewServer->login(mpLoginInfo, &bStop))
        {
            return pNewServer;
        }
        else
        {
            p->destroy();
            pNewServer->mpServer = nullptr;
            pNewServer->setRelease(true);
        }
    }

    return std::shared_ptr<videoserver>();
}
videoserver* videoserver::cloneDerect()
{
    if (nullptr == mpServer)
    {
        return new videoserver(nullptr, mpFactory);
    }

    IVideoServer* p = mpServer->clone();
    if (p != nullptr)
    {
        return new videoserver(p, mpFactory);
    }

    return nullptr;
}

bool videoserver::PlayBackByRecordFile(RecordFile& file, QWidget &w, play_handle_t& playbackHandle)
{

    if (nullptr != mpServer)
    {
        if (!mpServer->PlayBackByRecordFile(file, (HWND)w.winId(), playbackHandle))
        {
            this->mLastError = mpServer->getLastError();
            return false;
        }

        mMpPlayBackPosCaculators[playbackHandle].setPlaySeconds(file.endTime - file.beginTime);
        return true;
    }

    return false;

}

bool videoserver::SetPlayBack(play_handle_t playbackHandle, qint32 pos)
{

    if (nullptr != mpServer)
    {
        bool r = mpServer->SetPlayBack(playbackHandle, pos);
        if (!r)
        {
            addLog("SetPlayBack", __LINE__);
        }
        else
        {
            mMpPlayBackPosCaculators[playbackHandle].setPos(pos);
        }

        return r;
    }

    return false;

}

bool videoserver::getPlayBackPos(play_handle_t playbackHandle, qint32& pos)
{
    if (nullptr != mpServer)
    {
        bool r = mpServer->getPlayBackPos(playbackHandle, &pos);
        if (!r)
        {
            pos = mMpPlayBackPosCaculators[playbackHandle].getPos();
            return true;
        }
        return r;
    }

    return false;

}

bool videoserver::StopPlayBack(play_handle_t playbackHandle, int mPause)
{

    if (nullptr != mpServer)
    {
        bool r = mpServer->StopPlayBack(playbackHandle, mPause);
        if (!r)
        {
            addLog("StopPlayBack", __LINE__);
        }
        else
        {
            mMpPlayBackPosCaculators.erase(playbackHandle);
        }

        return r;
    }

    return false;

}


void getCommonFactorys(std::vector<videoserverFactory *>& factorys)
{
    factorys.clear();
    XmlSettings setings("cf");
    auto fs = videoserverFactory::getFactorys();
    std::vector< std::pair<int, int> > vcSorts;
    for (auto it = fs.begin(); it != fs.end(); it++)
    {
        videoserverFactory* pF = (*it);
		factorys.push_back(pF);
//         vcSorts.push_back(std::make_pair(pF->factory(),
//                                          setings.value(QString::number(pF->factory()), 0).toInt()));
    }
//     std::stable_sort(vcSorts.begin(), vcSorts.end(),
//               [](const std::pair<int, int>& f, const std::pair<int, int>& s)
//     {
//         return f.second > s.second;
//     });

//     for (int i = 0; i < vcSorts.size(); i++)
//     {
//         factorys.push_back((DeviceFactory)vcSorts[i].first);
//     }
}

void plusCommonFactorySort(const std::vector<DeviceFactory>& factories, int index)
{
    if (index >= factories.size())
    {
        return;
    }

    XmlSettings setings("cf");
    int nSort = setings.value(QString::number(factories[index]), 0).toInt() + 1;
    setings.setValue(QString::number(factories[index]), nSort);
}

bool videoserver::login(std::shared_ptr<LoginServerInfo> p, bool *pbStop)
{
	if (!p || *pbStop)
    {
        Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:%4").arg(__FILE__)
            .arg(__FUNCTION__).arg(__LINE__).arg(*pbStop));
        return false;
    }

    mpLoginInfo = p;


    if (SISC_IPC_UNDEFINE == mpFactory->factory())
    {
        Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:%4").arg(__FILE__)
            .arg(__FUNCTION__).arg(__LINE__).arg(SISC_IPC_UNDEFINE));
		std::vector<videoserverFactory *> factorys;
        getCommonFactorys(factorys);
        int nPort = 0;
        QString sUser;
        QString sPasswords;
		std::shared_ptr<LoginServerInfo> tmpLoginfo = std::make_shared<LoginServerInfo>();
        for(int i = 0; i < factorys.size(); i++)
        {
			if (*pbStop)
			{
				return false;
			}
			
			videoserverFactory *f = factorys[i];
            if (f == nullptr)
            {
                Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:f == nullptr").arg(__FILE__)
                    .arg(__FUNCTION__).arg(__LINE__));
                continue;
            }

            if (SISC_IPC_UNDEFINE == f->factory() || f->IsOEMFac())
			{
                Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, oem factory:%4").arg(__FILE__)
                    .arg(__FUNCTION__).arg(__LINE__).arg(f->name()));
				continue;
			}

            IVideoServer* pServer = f->createDerect();
            if (pServer == nullptr)
            {
                Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:f->createDerect == nullptr").arg(__FILE__)
                    .arg(__FUNCTION__).arg(__LINE__));
                continue;
            }

            if (p->port == 0)
            {
                nPort = f->port();
            }
            else
            {
                nPort = p->port;
            }

            if (p->user == UNDEFIN_DEVICE_DEFAULT_USER)
            {
                sUser = f->defaultUser();
            }
            else
            {
                sUser = p->user;
            }

            if (p->password == UNDEFIN_DEVICE_DEFAULT_PASSWORD)
            {
                sPasswords = f->defaultPasswords();
            }
            else
            {
                sPasswords = p->password;
            }
					
            if (sheLogin(pServer, p->ip.toStdString(), nPort, sUser.toStdString(), sPasswords.toStdString()))
            {
				Log::instance().AddLog(QString("OK!") + mpFactory->name() + "," + f->name() + " " + p->ip);
                mpServer = pServer;
                this->mpFactory = f;
                p->factory = f->factory();
				p->name = f->name() + "(" + p->ip + ")";
                p->user = sUser;
                p->password = sPasswords;
                p->port = nPort;
				mpLoginInfo = p;
				mpLoginInfo->ip = p->ip;
                return true;
            }
            else
            {
				Log::instance().AddLog(QString("Failed!") + mpFactory->name() + "," + f->name() + " " + p->ip);
                pServer->destroy();
            }
        }

        mLastError = "�޷�ʶ����豸!";
        return false;
    }

	if (p->user == UNDEFIN_DEVICE_DEFAULT_USER)
	{
		p->user = mpFactory->defaultUser();
	}

	if (p->password == UNDEFIN_DEVICE_DEFAULT_PASSWORD)
	{
		p->password = mpFactory->defaultPasswords();
	}

    if (sheLogin(mpServer, p->ip.toStdString(), p->port, p->user.toStdString(), p->password.toStdString()))
    {
        return true;
    }
    return false;
}

//<<<<<<<<<<<<<add by zhangyaofa 2016/5/18
bool videoserver::loginByBroadcast(int nFactory, std::shared_ptr<LoginServerInfo> p, bool *pbStop)
{
	if (!p || *pbStop)
	{
		Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:%4").arg(__FILE__)
			.arg(__FUNCTION__).arg(__LINE__).arg(*pbStop));
		return false;
	}

	std::vector<videoserverFactory *> factorys;
	getCommonFactorys(factorys);
	int nPort = 0;
	QString sUser;
	QString sPasswords;

	for (int i = 0; i < factorys.size(); i++)
	{
		if (*pbStop)
		{
			return false;
		}

		videoserverFactory *f = factorys[i];
		if (f == nullptr)
		{
			Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:f == nullptr").arg(__FILE__)
				.arg(__FUNCTION__).arg(__LINE__));
			continue;
		}

		if (SISC_IPC_UNDEFINE == f->factory() || f->IsOEMFac())
		{
			Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, oem factory:%4").arg(__FILE__)
				.arg(__FUNCTION__).arg(__LINE__).arg(f->name()));
			continue;
		}

		if (f->factory() != nFactory)
		{
			continue;
		}

		//auto pServer = f->create();
		IVideoServer* pServer = f->createDerect();
		if (pServer == nullptr)
		{
			Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, error:f->createDerect == nullptr").arg(__FILE__)
				.arg(__FUNCTION__).arg(__LINE__));
			continue;
		}

		if (p->name.trimmed().isEmpty())
		{
			p->name = QString("%1(%2)").arg(f->name()).arg(p->ip);
		}

		if (p->port == 0)
		{
			nPort = f->port();
		}
		else
		{
			nPort = p->port;
		}

		if (p->user == UNDEFIN_DEVICE_DEFAULT_USER)
		{
			sUser = f->defaultUser();
		}
		else
		{
			sUser = p->user;
		}

		if (p->password == UNDEFIN_DEVICE_DEFAULT_PASSWORD)
		{
			sPasswords = f->defaultPasswords();
		}
		else
		{
			sPasswords = p->password;
		}

		if (sheLogin(pServer, p->ip.toStdString(), nPort, sUser.toStdString(), sPasswords.toStdString()))
		{
			Log::instance().AddLog(QString("OK!") + mpFactory->name() + "," + f->name() + " " + p->ip);
			mpServer = pServer;
			this->mpFactory = f;
			p->factory = f->factory();
			p->name = f->name() + "(" + p->ip + ")";
			p->user = sUser;
			p->password = sPasswords;
			p->port = nPort;
			mpLoginInfo = p;
			mpLoginInfo->ip = p->ip;
			return true;
		}
		else
		{
			Log::instance().AddLog(QString("Failed!") + mpFactory->name() + "," + f->name() + " " + p->ip);
			pServer->destroy();

			return false;
		}
		
	}	

	return false;
}
//>>>>>>>>>>>add end


void videoserver::DealDownLoadCallback(download_handle_t h, qint64 totalSize, qint64 size, bool failed)
{
    if (nullptr == mpServer)
    {
        return;
    }

    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    if (failed)
    {
        size = 0;
    }
    if (mEventReceivers.find(h) != mEventReceivers.end() && NULL != mEventReceivers[h])
    {

       QCoreApplication::postEvent(mEventReceivers[h], new downloadEvent(this, totalSize, size, failed));
    }

    if (failed || totalSize <= size)
    {
        if (mEventReceivers.find(h) != mEventReceivers.end() && NULL != mEventReceivers[h])
        {
            stopDownload(mEventReceivers[h]);
        }
        else
        {
            mpServer->stopDownload(h);
        }
    }
}

void videoserver::SendDownLoadHeartbeat(download_handle_t h)
{
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);

    if (mEventReceivers.find(h) != mEventReceivers.end() && NULL != mEventReceivers[h])
    {
        QCoreApplication::postEvent(mEventReceivers[h], new heartbeatEvent(this));
    }
}

void videoserver::DealDisconnectCallback()
{
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin(); it != mEventReceivers.end();
         it++)
    {
        if (NULL != it->second)
        {
            QCoreApplication::postEvent(it->second, new disconnectEvent(this));
        }
    }
}

void videoserver::DealReconnectCallback()
{
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
         it != mEventReceivers.end();
         it++)
    {
        if (NULL != it->second)
        {
            QCoreApplication::postEvent(it->second, new reconnectEvent(this));
        }
    }
}


bool videoserver::logout()
{
    if (!stopDownloadAll())
    {
        return false;
    }

    if (nullptr != mpServer)
    {
        if (!mpServer->logout())
        {
            return false;
        }

        return true;
    }

    return true;

}
bool videoserver::reLogin(){
    //this->logout();
    return sheLogin(mpServer, mpLoginInfo->ip.toStdString(), mpLoginInfo->port, mpLoginInfo->user.toStdString(), mpLoginInfo->password.toStdString());
}
bool videoserver::GetRecordFileList(std::vector<RecordFile>& files, /*int nChannelId */ std::vector<int>& channelVec, const QDateTime& timeStart, const QDateTime& timeEnd)
{

    if (nullptr != mpServer)
    {

        QTime tmS(timeStart.time());
        QTime tmE(timeEnd.time());
        QDate dtE(timeStart.date());
        const int DAYS = 3;
        for (QDate start(timeStart.date()); start <= timeEnd.date(); start = start.addDays(DAYS))
        {
            std::vector<RecordFile> daysFiles;
            if (start == timeStart.date())
            {
                tmS = timeStart.time();
            }
            else{
                tmS = QTime(0, 0);
            }
            dtE = start.addDays(DAYS - 1);
            if (dtE >= timeEnd.date())
            {
                dtE = timeEnd.date();
                tmE = timeEnd.time();
            }
            else{
                tmE = QTime(23, 59);
            }
            bool r = mpServer->GetRecordFileList(daysFiles, channelVec, QDateTime(start, tmS).toTime_t(), QDateTime(dtE, tmE).toTime_t());
            if (!r)
            {
                return false;
            }

            for (int i = 0; i < daysFiles.size(); i++)
            {
                files.push_back(daysFiles[i]);
            }
            
        }
		
        std::stable_sort(files.begin(), files.end(), [](const RecordFile& a, const RecordFile& b){
            return a.channel < b.channel;
        });

        return true;
    }

    return false;

}

bool videoserver::GetRecordFileListZone(std::vector<RecordFile>& files, /*int nChannelId*/std::vector<int>& channelVec,
                           const QDateTime& timeStart, const QDateTime& timeEnd)
{
    for (QDate start(timeStart.date()); start <= timeEnd.date(); start = start.addDays(1))
    {
        std::vector<RecordFile> oneDayFiles;
		if (GetRecordFileList(oneDayFiles, channelVec, QDateTime(start, timeStart.time()),
                              QDateTime(start, timeEnd.time())))
        {
            for (int i = 0; i < oneDayFiles.size(); i++)
            {
                files.push_back(oneDayFiles[i]);
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}
#define SLEEP_MILLISECONDE                      500
#define DISCONNECT_TIME                         1
#define CONNECTD_TIME                           20
bool videoserver::downLoad(const QString& saveFileName, const RecordFile& file, QObject* eventReceiver)
{
    if (nullptr == mpServer)
    {
        return false;
    }

    if (DownloadPosCaculator::getFileSize(saveFileName.toLocal8Bit().data()) >= file.size){
        QCoreApplication::postEvent(eventReceiver, new downloadEvent(this, file.size, file.size, false));
        return true;
    }

    download_handle_t hdl;
    try
    {
        if (shedownLoadByRecordFile(saveFileName.toLocal8Bit().data(), file, hdl))
		{
            std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
            std::lock_guard<std::recursive_mutex> lockeThread(mMutexThread);
            mMpDownloadPosCaculators[hdl].init(file.size, saveFileName.toLocal8Bit().data());
            mEventReceivers[hdl] = eventReceiver;
            if (nullptr == mpThrDowload)
            {
                mpThrDowload = new std::thread([&](videoserver* pThis)
                {
                    int mTimes = 0;
                    int totalTime = 20;
                    bool isconnect = false;
                    qint64  totalSize = 0;
                    qint64 currentSize = 0;
                    bool failed = false;

                    while (!mStop)
                    {
                        mTimes = mTimes + 2;
                        QThread::msleep(2000);
                        if (mTimes >= totalTime)
                        {
                            isconnect = WindowUtils::isConnecteTo(pThis->ip());
                            if (!isconnect)
                            {
                                //Log::instance().AddLog(QString("################### 05"));
                                DealDisconnectCallback();
                                //Log::instance().AddLog(QString("################### 06"));
                                totalTime = DISCONNECT_TIME;
                            }
                            else if (totalTime == DISCONNECT_TIME)
                            {
                                isconnect = pThis->reLogin();
                            }
                            if (isconnect)
                            {
                                totalTime = CONNECTD_TIME;
                            }
                            mTimes = 0;
                        }
                        if (!isconnect)
                        {
                            continue;
                        }
                         std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
                         for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
                               it != mEventReceivers.end(); /*it++*/)
                         {
							 std::map<download_handle_t, QObject*>::iterator itTmp = it;
							 it++;
							 if (pThis->mpServer->getDownloadPos(itTmp->first, &totalSize, &currentSize, &failed))
                             {
								 DealDownLoadCallback(itTmp->first, totalSize, currentSize, failed);
                             }
                             else
                             {
							     pThis->mMpDownloadPosCaculators[itTmp->first].getPos(totalSize, currentSize);
								 DealDownLoadCallback(itTmp->first, totalSize, currentSize, failed);
                             }
                         }

                    }
                }, this);
            }

            return true;
        }
        else
        {
            this->mLastError = mpServer->getLastError();
            Log::instance().AddLog(QString("%1:%2-%3  %4(%5)").arg(__FILE__)
                .arg(__LINE__).arg(this->mpFactory->name()).arg("download failed:").arg(getLastError()));
            return false;
        }
    }
    catch(...)
    {
		Log::instance().AddLog(QString("################### exception"));
        return false;
    }
}

bool videoserver::stopDownload(QObject* eventReceiver)
{
    if (nullptr != mpServer)
    {
        std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
        for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
             it != mEventReceivers.end(); it++)
        {
            if (it->second == eventReceiver)
            {
				mpServer->stopDownload(it->first);
				mMpDownloadPosCaculators.erase(it->first);
				it = mEventReceivers.erase(it);
				return true;
//                 if (mpServer->stopDownload(it->first))
// 				{
// 					mMpDownloadPosCaculators.erase(it->first);
// 					it = mEventReceivers.erase(it);
//                     return true;
//                 }
// 
//                 return false;
            }
        }
    }

    return true;
}

bool videoserver::stopDownloadAll()
{
    if (nullptr == mpServer)
    {
        return true;
    }
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
         it != mEventReceivers.end(); /*it++*/)
    {
        if (!mpServer->stopDownload(it->first))
        {
            return false;
        }
        else
        {
            it = mEventReceivers.erase(it);
        }
    }
    mStop = true;
    mpThrDowload->join();
    delete mpThrDowload;
    mpThrDowload = nullptr;
    return true;
}

QString videoserver::getChannelName(int channel)
{
    if (m_channels.find(channel) != m_channels.end())
    {
         QString s = QString::fromLocal8Bit(m_channels.at(channel).c_str());
         if (s.isEmpty())
         {
             s = QString::fromLocal8Bit("ͨ��%1").arg(channel);
         }
         s.replace(" ", "");
         return s;
    }

    return "";
}
QString videoserver::getFileName(const RecordFile &f)
{
    return f.name.c_str();
}
void videoserver::addLog(const char* sLog, int nLine)
{
    qDebug() << sLog;
    Log::instance().AddLog(QString("%1:%2-%3  %4(%5)").arg(__FILE__)
        .arg(nLine).arg(this->mpFactory->name()).arg(sLog).arg(getLastError()));
}

bool videoserver::shedownLoadByRecordFile(const std::string& saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (nullptr == mpServer)
    {
        return false;
    }
    SHE_BEGING
        bool r = mpServer->downLoadByRecordFile(saveFileName.c_str(), file, hdl);
    if (!r)
    {
        // addLog("downLoadByRecordFile", __LINE__);
        return false;
    }
    std::cout << "she try end" << std::endl;
    return r;
    SHE_END_RETURN_FALSE
}
bool videoserver::shegetDownloadPos(download_handle_t h, qint64* totalSize, qint64* currentSize, bool* failed)
{
    if (nullptr == mpServer)
    {
        return false;
    }
    SHE_BEGING

        bool r = mpServer->getDownloadPos(h, totalSize, currentSize, failed);
    std::cout << "she try end" << std::endl;
    if (!r)
    {
        addLog("getDownloadPos", __LINE__);
    }
    return r;
    SHE_END_RETURN_FALSE
}
bool videoserver::shestopDownload(download_handle_t h)
{
    if (nullptr == mpServer)
    {
        return true;
    }
    SHE_BEGING
        bool r = mpServer->stopDownload(h);
    std::cout << "she try end" << std::endl;
    if (!r)
    {
        addLog("shestopDownload", __LINE__);
    }
    return r;

    SHE_END_RETURN_FALSE
}

bool videoserver::sheLogin(IVideoServer* pServer, const std::string& IP, int port, const std::string& user, const std::string& password)
{
    if (nullptr == pServer)
    {
        return false;
    }

	
    SHE_BEGING

        bool r = pServer->login(IP.c_str(), port, user.c_str(), password.c_str(), m_channels);

    if (!r)
	{
		
        this->mLastError = pServer->getLastError();
		addLog(IP.c_str(), __LINE__);			
		char szPort[10] = { 0 };
		itoa(port, szPort, 10);
		addLog(szPort, __LINE__);
		addLog(user.c_str(), __LINE__);
		addLog(password.c_str(), __LINE__);
        addLog("videoserver::sheLogin failed", __LINE__);
    }
    else{
		addLog(IP.c_str(), __LINE__);		
		char szPort[10] = { 0 };
		itoa(port, szPort, 10);
		addLog(szPort, __LINE__);
		addLog(user.c_str(), __LINE__);
		addLog(password.c_str(), __LINE__);
        addLog("videoserver::sheLogin true", __LINE__);
    }
    return r;

    SHE_END_RETURN_FALSE
}

OEMFactory::OEMFactory()
{
	m_name[32] = {0};
	m_FacID = SISC_IPC_UNDEFINE;
	m_OemFlag = false;
	m_pFactory = NULL;
}

OEMFactory::OEMFactory(DeviceFactory FacID, bool bOEMFlag, char *FacName, IVideoServerFactory *pFactory)
{
	m_FacID = FacID;
	m_OemFlag = bOEMFlag;
	strcpy_s(m_name, FacName);
	m_pFactory = pFactory;

 	m_port = 0;
	memset(m_usr, 0, strlen(m_usr));
	memset(m_pass, 0, strlen(m_pass));

	switch (m_FacID)
	{
	case SISC_IPC_GZLL:
	case SISC_IPC_JIRUI:
	case SISC_IPC_HUABANGHAISHI:
		strcpy_s(m_usr, "admin");
		strcpy_s(m_pass, "");
        m_OemFlag = (m_FacID != SISC_IPC_GZLL);
		m_port = 9101;
		break;
	case SISC_IPC_SALX:
		strcpy_s(m_usr, "admin");
		strcpy_s(m_pass, "123456");
		m_port = 34567;
        m_OemFlag = false;
		break;
	default:
		break;
	}
}

const char* OEMFactory::name()
{
	return m_name;
}

DeviceFactory OEMFactory::factory()
{
	return m_FacID;
}
