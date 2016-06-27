#include "dh_videoserver.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"

Log g_log("DH_videoserver");

IVideoServerFactory* VideoServerFactory()
{
    return new CFactoryDH();
}

static std::string GetLastErrorString()
{
    DWORD dwError;
    dwError = Api_DH::Api().m_pGetLastError();

    switch (dwError)
    {
        case NET_NOERROR: return "û�д���";
		case NET_ERROR: return "δ֪����";
		case NET_SYSTEM_ERROR: return "Windowsϵͳ����";
		case NET_NETWORK_ERROR: return "������󣬿�������Ϊ���糬ʱ";
		case NET_DEV_VER_NOMATCH: return "�豸Э�鲻ƥ��";
		case NET_INVALID_HANDLE: return "�����Ч";
		case NET_OPEN_CHANNEL_ERROR: return "��ͨ��ʧ��";
		case NET_CLOSE_CHANNEL_ERROR: return "�ر�ͨ��ʧ��";
		case NET_ILLEGAL_PARAM: return "�û��������Ϸ�";
		case NET_SDK_INIT_ERROR: return "SDK��ʼ������";
		case NET_SDK_UNINIT_ERROR: return "SDK�������";
		case NET_RENDER_OPEN_ERROR: return "����render��Դ����";
		case NET_DEC_OPEN_ERROR: return "�򿪽�������";
		case NET_DEC_CLOSE_ERROR: return "�رս�������";
		case NET_MULTIPLAY_NOCHANNEL: return "�໭��Ԥ���м�⵽ͨ����Ϊ0";
		case NET_TALK_INIT_ERROR: return "¼�����ʼ��ʧ��";
		case NET_TALK_NOT_INIT: return "¼����δ����ʼ��";
		case NET_TALK_SENDDATA_ERROR: return "������Ƶ���ݳ���";
		case NET_REAL_ALREADY_SAVING: return "ʵʱ�����Ѿ����ڱ���״̬";
		case NET_NOT_SAVING: return "δ����ʵʱ����";
		case NET_OPEN_FILE_ERROR: return "���ļ�����";
		case NET_PTZ_SET_TIMER_ERROR: return "������̨���ƶ�ʱ��ʧ��";
		case NET_RETURN_DATA_ERROR: return "�Է������ݵ�У�����";
		case NET_INSUFFICIENT_BUFFER: return "û���㹻�Ļ���";
		case NET_NOT_SUPPORTED: return "��ǰSDKδ֧�ָù���";
		case NET_NO_RECORD_FOUND: return "��ѯ����¼��";
		case NET_NOT_AUTHORIZED: return "�޲���Ȩ��";
		case NET_NOT_NOW: return "��ʱ�޷�ִ��";
		case NET_NO_TALK_CHANNEL: return "δ���ֶԽ�ͨ��";
		case NET_NO_AUDIO: return "δ������Ƶ";
		case NET_NO_INIT: return "����SDKδ����ʼ��";
		case NET_DOWNLOAD_END: return "�����ѽ���";
		case NET_EMPTY_LIST: return "��ѯ���Ϊ��";
		case NET_ERROR_GETCFG_SYSATTR: return "��ȡϵͳ��������ʧ��";
		case NET_ERROR_GETCFG_SERIAL: return "��ȡ���к�ʧ��";
		case NET_ERROR_GETCFG_GENERAL: return "��ȡ��������ʧ��";
		case NET_ERROR_GETCFG_DSPCAP: return "��ȡDSP��������ʧ��";
		case NET_ERROR_GETCFG_NETCFG: return "��ȡ��������ʧ��";
		case NET_ERROR_GETCFG_CHANNAME: return "��ȡͨ������ʧ��";
		case NET_ERROR_GETCFG_VIDEO: return "��ȡ��Ƶ����ʧ��";
		case NET_ERROR_GETCFG_RECORD: return "��ȡ¼������ʧ��";
		case NET_ERROR_GETCFG_PRONAME: return "��ȡ������Э������ʧ��";
		case NET_ERROR_GETCFG_FUNCNAME: return "��ȡ232���ڹ�������ʧ��";
		case NET_ERROR_GETCFG_485DECODER: return "��ȡ����������ʧ��";
		case NET_ERROR_GETCFG_232COM: return "��ȡ232��������ʧ��";
		case NET_ERROR_GETCFG_ALARMIN: return "��ȡ�ⲿ������������ʧ��";
		case NET_ERROR_GETCFG_ALARMDET: return "��ȡ��̬��ⱨ��ʧ��";
		case NET_ERROR_GETCFG_SYSTIME: return "��ȡ�豸ʱ��ʧ��";
		case NET_ERROR_GETCFG_PREVIEW: return "��ȡԤ������ʧ��";
		case NET_ERROR_GETCFG_AUTOMT: return "��ȡ�Զ�ά������ʧ��";
		case NET_ERROR_GETCFG_VIDEOMTRX: return "��ȡ��Ƶ��������ʧ��";
		case NET_ERROR_GETCFG_COVER: return "��ȡ�����ڵ�����ʧ��";
		case NET_ERROR_GETCFG_WATERMAKE: return "��ȡͼ��ˮӡ����ʧ��";
		case NET_ERROR_SETCFG_GENERAL: return "�޸ĳ�������ʧ��";
		case NET_ERROR_SETCFG_NETCFG: return "�޸���������ʧ��";
		case NET_ERROR_SETCFG_CHANNAME: return "�޸�ͨ������ʧ��";
		case NET_ERROR_SETCFG_VIDEO: return "�޸���Ƶ����ʧ��";
		case NET_ERROR_SETCFG_RECORD: return "�޸�¼������ʧ��";
		case NET_ERROR_SETCFG_485DECODER: return "�޸Ľ���������ʧ��";
		case NET_ERROR_SETCFG_232COM: return "�޸�232��������ʧ��";
		case NET_ERROR_SETCFG_ALARMIN: return "�޸��ⲿ���뱨������ʧ��";
		case NET_ERROR_SETCFG_ALARMDET: return "�޸Ķ�̬��ⱨ������ʧ��";
		case NET_ERROR_SETCFG_SYSTIME: return "�޸��豸ʱ��ʧ��";
		case NET_ERROR_SETCFG_PREVIEW: return "�޸�Ԥ������ʧ��";
		case NET_ERROR_SETCFG_AUTOMT: return "�޸��Զ�ά������ʧ��";
		case NET_ERROR_SETCFG_VIDEOMTRX: return "�޸���Ƶ��������ʧ��";
		case NET_ERROR_SETCFG_COVER: return "�޸������ڵ�����ʧ��";
		case NET_ERROR_SETCFG_WATERMAKE: return "�޸�ͼ��ˮӡ����ʧ��";
		case NET_ERROR_SETCFG_WLAN: return "�޸�����������Ϣʧ��";
		case NET_ERROR_SETCFG_WLANDEV: return "ѡ�����������豸ʧ��";
		case NET_ERROR_SETCFG_REGISTER: return "�޸�����ע���������ʧ��";
		case NET_ERROR_SETCFG_CAMERA: return "�޸�����ͷ��������ʧ��";
		case NET_ERROR_SETCFG_INFRARED: return "�޸ĺ��ⱨ������ʧ��";
		case NET_ERROR_SETCFG_SOUNDALARM: return "�޸���Ƶ��������ʧ��";
		case NET_ERROR_SETCFG_STORAGE: return "�޸Ĵ洢λ������ʧ��";
		case NET_AUDIOENCODE_NOTINIT: return "��Ƶ����ӿ�û�гɹ���ʼ��";
		case NET_DATA_TOOLONGH: return "���ݹ���";
		case NET_UNSUPPORTED: return "�豸��֧�ָò���";
		case NET_DEVICE_BUSY: return "�豸��Դ����";
		case NET_SERVER_STARTED: return "�������Ѿ�����";
		case NET_SERVER_STOPPED: return "��������δ�ɹ�����";
		case NET_LISTER_INCORRECT_SERIAL: return "�������к�����";
		case NET_QUERY_DISKINFO_FAILED: return "��ȡӲ����Ϣʧ��";
		case NET_ERROR_GETCFG_SESSION: return "��ȡ����Session��Ϣ";
		case NET_USER_FLASEPWD_TRYTIME: return "����������󳬹����ƴ���";
		case NET_LOGIN_ERROR_PASSWORD: return "���벻��ȷ";
		case NET_LOGIN_ERROR_USER: return "�ʻ�������";
		case NET_LOGIN_ERROR_TIMEOUT: return "�ȴ���¼���س�ʱ";
		case NET_LOGIN_ERROR_RELOGGIN: return "�ʺ��ѵ�¼";
		case NET_LOGIN_ERROR_LOCKED: return "�ʺ��ѱ�����";
		case NET_LOGIN_ERROR_BLACKLIST: return "�ʺ��ѱ���Ϊ������";
		case NET_LOGIN_ERROR_BUSY: return "��Դ���㣬ϵͳæ";
		case NET_LOGIN_ERROR_CONNECT: return "��¼�豸��ʱ���������粢����";
		case NET_LOGIN_ERROR_NETWORK: return "��������ʧ��";
		case NET_LOGIN_ERROR_SUBCONNECT: return "��¼�豸�ɹ������޷�������Ƶͨ������������״��";
		case NET_LOGIN_ERROR_MAXCONNECT: return "�������������";
		case NET_LOGIN_ERROR_PROTOCOL3_ONLY: return "ֻ֧��3��Э��";
		case NET_LOGIN_ERROR_UKEY_LOST: return "δ����U�ܻ�U����Ϣ����";
		case NET_LOGIN_ERROR_NO_AUTHORIZED: return "�ͻ���IP��ַû�е�¼Ȩ��";
		case NET_RENDER_SOUND_ON_ERROR: return "Render�����Ƶ����";
		case NET_RENDER_SOUND_OFF_ERROR: return "Render��ر���Ƶ����";
		case NET_RENDER_SET_VOLUME_ERROR: return "Render�������������";
		case NET_RENDER_ADJUST_ERROR: return "Render�����û����������";
		case NET_RENDER_PAUSE_ERROR: return "Render����ͣ���ų���";
		case NET_RENDER_SNAP_ERROR: return "Render��ץͼ����";
		case NET_RENDER_STEP_ERROR: return "Render�ⲽ������";
		case NET_RENDER_FRAMERATE_ERROR: return "Render������֡�ʳ���";
		case NET_RENDER_DISPLAYREGION_ERROR: return "Render��������ʾ�������";
		case NET_GROUP_EXIST: return "�����Ѵ���";
		case NET_GROUP_NOEXIST: return "����������";
		case NET_GROUP_RIGHTOVER: return "���Ȩ�޳���Ȩ���б�Χ";
		case NET_GROUP_HAVEUSER: return "�������û�������ɾ��";
		case NET_GROUP_RIGHTUSE: return "���ĳ��Ȩ�ޱ��û�ʹ�ã����ܳ���";
		case NET_GROUP_SAMENAME: return "������ͬ���������ظ�";
		case NET_USER_EXIST: return "�û��Ѵ���";
		case NET_USER_NOEXIST: return "�û�������";
		case NET_USER_RIGHTOVER: return "�û�Ȩ�޳�����Ȩ��";
		case NET_USER_PWD: return "�����ʺţ��������޸�����";
		case NET_USER_FLASEPWD: return "���벻��ȷ";
		case NET_USER_NOMATCHING: return "���벻ƥ��";
		case NET_USER_INUSE: return "�˺�����ʹ����";
		case NET_ERROR_GETCFG_ETHERNET: return "��ȡ��������ʧ��";
		case NET_ERROR_GETCFG_WLAN: return "��ȡ����������Ϣʧ��";
		case NET_ERROR_GETCFG_WLANDEV: return "��ȡ���������豸ʧ��";
		case NET_ERROR_GETCFG_REGISTER: return "��ȡ����ע�����ʧ��";
		case NET_ERROR_GETCFG_CAMERA: return "��ȡ����ͷ����ʧ��";
		case NET_ERROR_GETCFG_INFRARED: return "��ȡ���ⱨ������ʧ��";
		case NET_ERROR_GETCFG_SOUNDALARM: return "��ȡ��Ƶ��������ʧ��";
		case NET_ERROR_GETCFG_STORAGE: return "��ȡ�洢λ������ʧ��";
		case NET_ERROR_GETCFG_MAIL: return "��ȡ�ʼ�����ʧ��";
		case NET_CONFIG_DEVBUSY: return "��ʱ�޷�����";
		case NET_CONFIG_DATAILLEGAL: return "�������ݲ��Ϸ�";
		case NET_ERROR_GETCFG_DST: return "��ȡ����ʱ����ʧ��";
		case NET_ERROR_SETCFG_DST: return "��������ʱ����ʧ��";
		case NET_ERROR_GETCFG_VIDEO_OSD: return "��ȡ��ƵOSD��������ʧ��";
		case NET_ERROR_SETCFG_VIDEO_OSD: return "������ƵOSD��������ʧ��";
		case NET_ERROR_GETCFG_GPRSCDMA: return "��ȡCDMA\GPRS��������ʧ��";
		case NET_ERROR_SETCFG_GPRSCDMA: return "����CDMA\GPRS��������ʧ��";
		case NET_ERROR_GETCFG_IPFILTER: return "��ȡIP��������ʧ��";
		case NET_ERROR_SETCFG_IPFILTER: return "����IP��������ʧ��";
		case NET_ERROR_GETCFG_TALKENCODE: return "��ȡ�����Խ���������ʧ��";
		case NET_ERROR_SETCFG_TALKENCODE: return "���������Խ���������ʧ��";
		case NET_ERROR_GETCFG_RECORDLEN: return "��ȡ¼������������ʧ��";
		case NET_ERROR_SETCFG_RECORDLEN: return "����¼������������ʧ��";
		case NET_DONT_SUPPORT_SUBAREA: return "��֧������Ӳ�̷���";
		case NET_ERROR_GET_AUTOREGSERVER: return "��ȡ�豸������ע���������Ϣʧ��";
		case NET_ERROR_CONTROL_AUTOREGISTER: return "����ע���ض���ע�����";
		case NET_ERROR_DISCONNECT_AUTOREGISTER: return "�Ͽ�����ע�����������";
		case NET_ERROR_GETCFG_MMS: return "��ȡmms����ʧ��";
		case NET_ERROR_SETCFG_MMS: return "����mms����ʧ��";
		case NET_ERROR_GETCFG_SMSACTIVATION: return "��ȡ���ż���������������ʧ��";
		case NET_ERROR_SETCFG_SMSACTIVATION: return "���ö��ż���������������ʧ��";
		case NET_ERROR_GETCFG_DIALINACTIVATION: return "��ȡ���ż���������������ʧ��";
		case NET_ERROR_SETCFG_DIALINACTIVATION: return "���ò��ż���������������ʧ��";
		case NET_ERROR_GETCFG_VIDEOOUT: return "��ѯ��Ƶ�����������ʧ��";
		case NET_ERROR_SETCFG_VIDEOOUT: return "������Ƶ�����������ʧ��";
		case NET_ERROR_GETCFG_OSDENABLE: return "��ȡosd����ʹ������ʧ��";
		case NET_ERROR_SETCFG_OSDENABLE: return "����osd����ʹ������ʧ��";
		case NET_ERROR_SETCFG_ENCODERINFO: return "��������ͨ��ǰ�˱����������ʧ��";
		case NET_ERROR_GETCFG_TVADJUST: return "��ȡTV��������ʧ��";
		case NET_ERROR_SETCFG_TVADJUST: return "����TV��������ʧ��";
		case NET_ERROR_CONNECT_FAILED: return "����������ʧ��";
		case NET_ERROR_SETCFG_BURNFILE: return "�����¼�ļ��ϴ�ʧ��";
		case NET_ERROR_SNIFFER_GETCFG: return "��ȡץ��������Ϣʧ��";
		case NET_ERROR_SNIFFER_SETCFG: return "����ץ��������Ϣʧ��";
		case NET_ERROR_DOWNLOADRATE_GETCFG: return "��ѯ����������Ϣʧ��";
		case NET_ERROR_DOWNLOADRATE_SETCFG: return "��������������Ϣʧ��";
		case NET_ERROR_SEARCH_TRANSCOM: return "��ѯ���ڲ���ʧ��";
		case NET_ERROR_GETCFG_POINT: return "��ȡԤ�Ƶ���Ϣ����";
		case NET_ERROR_SETCFG_POINT: return "����Ԥ�Ƶ���Ϣ����";
		case NET_SDK_LOGOUT_ERROR: return "SDKû�������ǳ��豸";
		case NET_ERROR_GET_VEHICLE_CFG: return "��ȡ��������ʧ��";
		case NET_ERROR_SET_VEHICLE_CFG: return "���ó�������ʧ��";
		case NET_ERROR_GET_ATM_OVERLAY_CFG: return "��ȡatm��������ʧ��";
		case NET_ERROR_SET_ATM_OVERLAY_CFG: return "����atm��������ʧ��";
		case NET_ERROR_GET_ATM_OVERLAY_ABILITY: return "��ȡatm��������ʧ��";
		case NET_ERROR_GET_DECODER_TOUR_CFG: return "��ȡ������������Ѳ����ʧ��";
		case NET_ERROR_SET_DECODER_TOUR_CFG: return "���ý�����������Ѳ����ʧ��";
		case NET_ERROR_CTRL_DECODER_TOUR: return "���ƽ�����������Ѳʧ��";
		case NET_GROUP_OVERSUPPORTNUM: return "�����豸֧������û�����Ŀ";
		case NET_USER_OVERSUPPORTNUM: return "�����豸֧������û���Ŀ";
		case NET_ERROR_GET_SIP_CFG: return "��ȡSIP����ʧ��";
		case NET_ERROR_SET_SIP_CFG: return "����SIP����ʧ��";
		case NET_ERROR_GET_SIP_ABILITY: return "��ȡSIP����ʧ��";
		case NET_ERROR_GET_WIFI_AP_CFG: return "��ȡWIFI ap����ʧ��";
		case NET_ERROR_SET_WIFI_AP_CFG: return "����WIFI ap����ʧ��";
		case NET_ERROR_GET_DECODE_POLICY: return "��ȡ�����������ʧ��";
		case NET_ERROR_SET_DECODE_POLICY: return "���ý����������ʧ��";
		case NET_ERROR_TALK_REJECT: return "�ܾ��Խ�";
		case NET_ERROR_TALK_OPENED: return "�Խ��������ͻ��˴�";
		case NET_ERROR_TALK_RESOURCE_CONFLICIT: return "��Դ��ͻ";
		case NET_ERROR_TALK_UNSUPPORTED_ENCODE: return "��֧�ֵ����������ʽ";
		case NET_ERROR_TALK_RIGHTLESS: return "��Ȩ��";
		case NET_ERROR_TALK_FAILED: return "����Խ�ʧ��";
		case NET_ERROR_GET_MACHINE_CFG: return "��ȡ�����������ʧ��";
		case NET_ERROR_SET_MACHINE_CFG: return "���û����������ʧ��";
		case NET_ERROR_GET_DATA_FAILED: return "�豸�޷���ȡ��ǰ��������";
		case NET_ERROR_MAC_VALIDATE_FAILED: return "MAC��ַ��֤ʧ��";
		case NET_ERROR_GET_INSTANCE: return "��ȡ������ʵ��ʧ��";
		case NET_ERROR_JSON_REQUEST: return "���ɵ�jason�ַ�������";
		case NET_ERROR_JSON_RESPONSE: return "��Ӧ��jason�ַ�������";
		case NET_ERROR_VERSION_HIGHER: return "Э��汾���ڵ�ǰʹ�õİ汾";
		case NET_SPARE_NO_CAPACITY: return "�ȱ�����ʧ��, ��������";
		case NET_ERROR_SOURCE_IN_USE: return "��ʾԴ���������ռ��";
		case NET_ERROR_REAVE: return "�߼��û���ռ�ͼ��û���Դ";
		case NET_ERROR_NETFORBID: return "��ֹ����";
		case NET_ERROR_GETCFG_MACFILTER: return "��ȡMAC��������ʧ��";
		case NET_ERROR_SETCFG_MACFILTER: return "����MAC��������ʧ��";
		case NET_ERROR_GETCFG_IPMACFILTER: return "��ȡIP/MAC��������ʧ��";
		case NET_ERROR_SETCFG_IPMACFILTER: return "����IP/MAC��������ʧ��";
		case NET_ERROR_OPERATION_OVERTIME: return "��ǰ������ʱ";
		case NET_ERROR_SENIOR_VALIDATE_FAILED: return "�߼�У��ʧ��";
		case NET_ERROR_DEVICE_ID_NOT_EXIST: return "�豸ID������";
		case NET_ERROR_UNSUPPORTED: return "��֧�ֵ�ǰ����";
		case NET_ERROR_PROXY_DLLLOAD: return "��������ʧ��";
		case NET_ERROR_PROXY_ILLEGAL_PARAM: return "�����û��������Ϸ�";
		case NET_ERROR_PROXY_INVALID_HANDLE: return "��������Ч";
		case NET_ERROR_PROXY_LOGIN_DEVICE_ERROR: return "�������ǰ���豸ʧ��";
		case NET_ERROR_PROXY_START_SERVER_ERROR: return "�����������ʧ��";
		case NET_ERROR_SPEAK_FAILED: return "���󺰻�ʧ��";
		case NET_ERROR_NOT_SUPPORT_F6: return "�豸��֧�ִ�F6�ӿڵ���";
		default: return "δ֪����";
    }
}



CFactoryDH::CFactoryDH()
{
    init();
}

CFactoryDH::~CFactoryDH()
{
    clean();
}






bool CFactoryDH::init()
{
    if (!m_init)
    {
        m_init = Api_DH::Api().m_pInit(0, 0);
        //NET_DVR_SetConnectTime(1000, 30);
        //NET_DVR_SetReconnect(3000);
        //NET_DVR_SetDVRMessage()
        if (!m_init)
        {
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("��ʼ��SDKʧ�ܣ�����ԭ��") + m_sLastError);
        }

		g_log.AddLog(string("��ʼ��SDK�ɹ�"));
    }

    return m_init;
}


void CFactoryDH::clean()
{
    Api_DH::Api().m_pUninit();
}




IVideoServer* CFactoryDH::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new dh_videoserver();
}

bool CFactoryDH::searchDevice(std::vector<DeviceInfo>& devices){
    g_log.AddLog(std::string("searchDevice :"));
    DH::DEVICE_NET_INFO dhdevices[254];
    int retLen = 0;
    Api_DH::Api().m_pSearchDevices((char*)dhdevices, sizeof(dhdevices), &retLen, 1000, NULL);
    g_log.AddLog(QString("Api_DH::Api().m_pSearchDevices:%1 %2").arg(retLen).arg(sizeof(DH::DEVICE_NET_INFO)));
    for (int num = retLen / sizeof(DH::DEVICE_NET_INFO), i = 0; i < num; i++){
        DeviceInfo d;
        d.szIP = dhdevices[i].szIP;
        d.nPort = dhdevices[i].nPort;
        d.Factory = SISC_IPC_DH;
        devices.push_back(d);
    }
    return true;
}


static void timeDHToStd(DH::NET_TIME *pTimeDH, tm *pTimeStd)
{
	pTimeStd->tm_year = pTimeDH->dwYear - 1900;
	pTimeStd->tm_mon = pTimeDH->dwMonth - 1;
	pTimeStd->tm_mday = pTimeDH->dwDay;
	pTimeStd->tm_hour = pTimeDH->dwHour;
	pTimeStd->tm_min = pTimeDH->dwMinute;
	pTimeStd->tm_sec = pTimeDH->dwSecond;
}

static void timeStdToDH(tm *pTimeStd, DH::NET_TIME *pTimeDH)
{
	pTimeDH->dwYear = pTimeStd->tm_year + 1900;
	pTimeDH->dwMonth = pTimeStd->tm_mon + 1;
	pTimeDH->dwDay = pTimeStd->tm_mday;
	pTimeDH->dwHour = pTimeStd->tm_hour;
	pTimeDH->dwMinute = pTimeStd->tm_min;
	pTimeDH->dwSecond = pTimeStd->tm_sec;
}

// std::vector<dh_videoserver*> dh_videoserver::sServers;
// std::recursive_mutex dh_videoserver::sMtServers;

/*
 * ��������
 */
dh_videoserver::dh_videoserver()
{
//     std::lock_guard<std::recursive_mutex> lock(dh_videoserver::sMtServers);
//     sServers.push_back(this);
}

dh_videoserver::~dh_videoserver()
{
    logout();
//     std::lock_guard<std::recursive_mutex> lock(dh_videoserver::sMtServers);
//     for (int i = 0; i < sServers.size(); i++)
//     {
//         if (sServers[i] == this)
//         {
//             sServers.erase(sServers.begin() + i);
//             break;
//         }
//     }
}

static void CALLBACK PosCallBack(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser)
{
	dh_videoserver * pThis = (dh_videoserver *)dwUser;
	{
		Mutex::ScopedLock lock(pThis->m_mtxPos);
		map<long long, stPos_DownPlay>::iterator itr = pThis->m_mapPosDownPlay.find(lPlayHandle);
		if (itr != pThis->m_mapPosDownPlay.end())
		{
			itr->second.iTotalSize = dwTotalSize * 1024;
			itr->second.iCurSize = dwDownLoadSize * 1024;
			itr->second.iPercent = ((float)dwDownLoadSize/(float)dwTotalSize)*100;
		}
	}
}

IVideoServer* dh_videoserver::clone()
{
 dh_videoserver *svr = new dh_videoserver();
// 	memcpy(svr, this, sizeof(dh_videoserver));
//     return svr;
 return svr;
}

bool dh_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string>& channels)
{
//     if (0 < m_lLoginHandle && !logout())
//     {
//         return false;
//     }

    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));

	int iError = 0;
    m_lLoginHandle = Api_DH::Api().m_pLogin((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo, &iError);
    if (m_lLoginHandle == 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("login ��¼ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

	/*char szChannelNames[16*32];
	ZeroMemory(szChannelNames, sizeof(szChannelNames));
	int iChannelCount = 0;
    bool bRet = Api_DH::Api().m_pGetChannel(m_lLoginHandle, szChannelNames, 16*32, &iChannelCount, 500);
	if (!bRet)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("login ��ȡͨ��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}
	g_log.AddLog(string(szChannelNames, 16 * 32));*/

	int nRetLen = 0;
	int iChannelCount = 0;
	DH::NET_DEV_CHN_COUNT_INFO stuChn = { sizeof(DH::NET_DEV_CHN_COUNT_INFO) };
	stuChn.stuVideoIn.dwSize = sizeof(stuChn.stuVideoIn);
	stuChn.stuVideoOut.dwSize = sizeof(stuChn.stuVideoOut);
	if (Api_DH::Api().m_pQueryDevState(m_lLoginHandle, DH_DEVSTATE_DEV_CHN_COUNT, (char*)&stuChn, stuChn.dwSize, &nRetLen, 1000))
	{
		iChannelCount = stuChn.stuVideoIn.nMaxTotal;
	}
	else
	{
		iChannelCount = m_deviceInfo.byChanNum;
	}

	channels.clear();
	char szName[32+2];
	for (int i=1; i<=iChannelCount; i++)
	{
		ZeroMemory(szName, sizeof(szName));
		//memcpy(szName, szChannelNames + (i - 1)*32, 32);
		sprintf(szName, "ͨ��%d", i);
		string strName = szName;
		channels.insert(std::make_pair(i, strName));
	}

    return true;
}

bool dh_videoserver::logout()
{
    if (m_lLoginHandle > 0 && !Api_DH::Api().m_pLogout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }

    return true;
}



#define MAX_SEARCH_COUNT 1000
bool dh_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
    if (m_lLoginHandle <= 0)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("GetRecordFileList ���ȵ�¼"));
        return false;
    }

    if (timeStart >= timeEnd)
    {
        m_sLastError = "ʱ�䷶Χ����!";
		g_log.AddLog(string("GetRecordFileList ʱ�䷶Χ����"));
        return false;
    }

	files.clear();
	//m_mapArcItem.clear();

	auto itr = channelVec.begin();
	for (; itr != channelVec.end(); itr++)
	{
		int nChannelId = *itr;

		DH::NET_TIME stime;
		DH::NET_TIME etime;
		tm STime;
		tm ETime;
		_localtime64_s(&STime, (const time_t*)&timeStart);
		_localtime64_s(&ETime, (const time_t*)&timeEnd);

		timeStdToDH(&STime, &stime);
		timeStdToDH(&ETime, &etime);
		char szTime[512];
		ZeroMemory(szTime, 512);
		sprintf(szTime, " s_time:%d-%02d-%02d %02d:%02d:%02d e_time:%d-%02d-%02d %02d:%02d:%02d channel:%d linkID:%d", stime.dwYear, stime.dwMonth, stime.dwDay,
			stime.dwHour, stime.dwMinute, stime.dwSecond,
			etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond, nChannelId, m_lLoginHandle);
		g_log.AddLog(string("GetRecordFileList ") + string(szTime));

		DH::NET_RECORDFILE_INFO ifileinfo[MAX_SEARCH_COUNT];
		ZeroMemory(ifileinfo, sizeof(ifileinfo));
		int iMaxNum = 0;
		bool bRet = Api_DH::Api().m_pSearchFileByTime(m_lLoginHandle,
			nChannelId - 1,
			0,
			&stime,
			&etime,
			0,
			ifileinfo,
			sizeof(ifileinfo),
			&iMaxNum,
			5000, true);

		if (!bRet)
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			continue;
		}
		if (iMaxNum <= 0)
		{
			g_log.AddLog(string("GetRecordFileList ��ѯ¼��ɹ���¼�����Ϊ0"));
			continue;
		}

		{
			Mutex::ScopedLock lock(m_mtx);
			DH::NET_RECORDFILE_INFO item;
			RecordFile info;
			tm sTm;
			tm eTm;
			for (int i = 0; i < iMaxNum; i++)
			{
				item = ifileinfo[i];

				timeDHToStd(&item.starttime, &sTm);
				timeDHToStd(&item.endtime, &eTm);

				stime = item.starttime;
				etime = item.endtime;
// 				ZeroMemory(szTime, 512);
// 				sprintf(szTime, "channel%d %d-%02d-%02d %02d-%02d-%02d %d-%02d-%02d %02d-%02d-%02d", nChannelId,
// 					stime.dwYear, stime.dwMonth, stime.dwDay,
// 					stime.dwHour, stime.dwMinute, stime.dwSecond,
// 					etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);
// 				m_mapArcItem.insert(std::make_pair(string(szTime), item));

				info.channel = item.ch + 1;
				info.size = item.size * 1024;
				info.name = szTime;
				info.beginTime = mktime(&sTm);
				info.endTime = mktime(&eTm);
				info.setPrivateData(&ifileinfo[i], sizeof(DH::NET_RECORDFILE_INFO));
				files.push_back(info);

				char szLog[1024];
				ZeroMemory(szLog, 1024);
				sprintf(szLog, "GetRecordFileList �ļ���:%s �ļ���С:%d ͨ��:%d", item.filename, item.size, item.ch);
				g_log.AddLog(string(szLog));
			}
		}
	}
	return true;
}



bool dh_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (0 >= m_lLoginHandle)
    {
        m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("downLoadByRecordFile ���ȵ�¼"));
        return false;
    }

// 	DH::NET_RECORDFILE_INFO info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, DH::NET_RECORDFILE_INFO>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("downLoadByRecordFile ���ļ�������"));
// 			return false;
// 		}
// 
// 		info = itr->second;
// 	}

	DH::NET_RECORDFILE_INFO* pData = (DH::NET_RECORDFILE_INFO*)file.getPrivateData();
	g_log.AddLog(string("downLoadByRecordFile �ļ���:") + saveFileName);
	hdl = Api_DH::Api().m_pDownloadByFile(m_lLoginHandle, pData, (char *)saveFileName, PosCallBack, (DWORD)this);
	if (hdl == 0)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("downLoadByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}

	{
		Mutex::ScopedLock lock(m_mtx);
		m_mapDownloadOrPlay.insert(std::make_pair(hdl, file));
	}
	{
		stPos_DownPlay pos;
		pos.iTotalSize = file.size;
		pos.iCurSize = 0;
		pos.iPercent = 0;
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.insert(std::make_pair(hdl, pos));
	}

	return true;
}


bool  dh_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("PlayBackByRecordFile ���ȵ�¼"));
        return false;
	}

// 	DH::NET_RECORDFILE_INFO info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, DH::NET_RECORDFILE_INFO>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("PlayBackByRecordFile ���ļ�������"));
// 			return false;
// 		}
// 
// 		info = itr->second;
// 	}
	DH::NET_RECORDFILE_INFO* pData = (DH::NET_RECORDFILE_INFO*)file.getPrivateData();
	playbackHandle = Api_DH::Api().m_pPlayBackByFile(m_lLoginHandle, pData, hwnd, PosCallBack, (DWORD)this);
	if (playbackHandle == 0)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("PlayBackByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}

	{
		Mutex::ScopedLock lock(m_mtx);
		m_mapDownloadOrPlay.insert(std::make_pair(playbackHandle, file));
	}
	{
		stPos_DownPlay pos;
		pos.iTotalSize = file.size;
		pos.iCurSize = 0;
		pos.iPercent = 0;
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.insert(std::make_pair(playbackHandle, pos));
	}

	return true;
}

bool dh_videoserver::SetPlayBack(__int64 playbackHandle, __int32 pos)
{
	RecordFile file;
	{
		Mutex::ScopedLock lock(m_mtx);
		map<long long, RecordFile>::iterator itr = m_mapDownloadOrPlay.find(playbackHandle);
		if (itr == m_mapDownloadOrPlay.end())
		{
			m_sLastError = "���ļ�������";
			g_log.AddLog(string("SetPlayBack ���ļ�������"));
			return false;
		}
		file = itr->second;
	}
	__time64_t iPlayPos = (file.size * pos)/100;
	iPlayPos /= 1024;
    return FALSE != Api_DH::Api().m_pSeekPlayBack(playbackHandle, 0xffffffff, (unsigned int)iPlayPos);
}

bool dh_videoserver::StopPlayBack(__int64 playbackHandle, __int32 mPause)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("StopPlayBack ���ȵ�¼"));
        return false;
    }
	if (mPause == 1)
	{
		g_log.AddLog(string("StopPlayBack ��ʼ��ͣ����"));
		if (!Api_DH::Api().m_pPausePlayBack(playbackHandle, TRUE))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ��ͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}
	else
	{
		char szLog[1024];
		ZeroMemory(szLog, 1024);
		sprintf(szLog, "StopPlayBack ��ʼֹͣ���� playbackHandle:%d", playbackHandle);
		g_log.AddLog(string(szLog));

		{
			Mutex::ScopedLock lock(m_mtx);
			m_mapDownloadOrPlay.erase(playbackHandle);
		}
		{
			Mutex::ScopedLock lock(m_mtxPos);
			m_mapPosDownPlay.erase(playbackHandle);
		}
		if (!Api_DH::Api().m_pStopPlayBack(playbackHandle))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}

    return true;
}

bool dh_videoserver::stopDownload(download_handle_t h)
{
	g_log.AddLog(string("stopDownload ��ʼֹͣ����"));
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("stopDownload ���ȵ�¼"));
        return false;
	}

	{
		Mutex::ScopedLock lock(m_mtx);
		m_mapDownloadOrPlay.erase(h);
	}
	{
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.erase(h);
	}

    if (FALSE == Api_DH::Api().m_pStopDownload(h))
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("stopDownload ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    return true;
}

bool dh_videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
{
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getPlayBackPos ���ȵ�¼"));
		return false;
	}

	Mutex::ScopedLock lock(m_mtxPos);
	map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(playbackHandle);
	if (itr != m_mapPosDownPlay.end())
	{
		*pos = itr->second.iPercent;
		return true;
	}
	m_sLastError = "�Ҳ����ûط�";
	g_log.AddLog(string("getPlayBackPos �Ҳ����ûط�"));
	return false;
}

bool dh_videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getDownloadPos ���ȵ�¼"));
		return false;
	}

	Mutex::ScopedLock lock(m_mtxPos);
	map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(h);
	if (itr != m_mapPosDownPlay.end())
	{
		*totalSize = itr->second.iTotalSize;
		*currentSize = itr->second.iCurSize;

		*failed = false;
		return true;
	}
	m_sLastError = "�Ҳ���������";
	g_log.AddLog(string("getDownloadPos �Ҳ���������"));
	*failed = true;
	return false;
}