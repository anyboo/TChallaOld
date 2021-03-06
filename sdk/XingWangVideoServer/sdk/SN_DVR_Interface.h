#ifndef _SN_DVR_INTERFACE_HEADER_FILE_
#define _SN_DVR_INTERFACE_HEADER_FILE_

#include <Windows.h>
#include <time.h>


//不建议使用这种导入导出方式
#ifndef _SN_DVR_EXPORT_DLL_
	#define SN_DVR_INTERFACE __declspec(dllimport) __stdcall
#else 
	#define SN_DVR_INTERFACE __declspec(dllexport) __stdcall
#endif


//-------------------------------------------------------------------------------------
//数据类型定义区start
//-------------------------------------------------------------------------------------
typedef LPVOID	HSLIDE;
typedef signed long long int64_t;
//-------------------------------------------------------------------------------------
//数据类型定义区end
//-------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------
//enum类型start
//-------------------------------------------------------------------------------------
enum DEVICE_CONFIGURE_CLASS{
	DeviceParameterInformation,				//G/S  DEVICE_PARAMETER_INFO  设备参数信息
	DeviceNetParameterInformation,			//G/S  DEVICE_NET_PARAMETER_INFO  设备网络参数信息
	// 设置网络参数，可能造成网络连接断开
	DevicePictureParameterInformation,		//G/S  DEVICE_PICTURE_PARAMETER_INFORMATION  设备图像参数信息 
	DeviceCompressionParameterInformation,	//G/S  DEVICE_COMPRESSION_PARMATER_INFORMATION  设备压缩参数信息
	DeviceRecordParameterInformation,		//G/S  DEVICE_RECORD_PARAMETER_INFORMATION   设备录像参数信息
	DevicePTZDecoderParameterInformation,	//G/S  DEVICE_PTZ_DECODER_PARAMETER_INFORMATION  设备云台解码器参数信息
	DeviceRS232ParameterInformation,		//G/S  DEVICE_RS232_PARAMETER_INFORMATION      设备232串口参数信息
	DeviceAlarmInParameterInformation,		//G/S  DEVICE_ALARM_IN_PARAMETER_INFORAMTION    设备报警输入参数信息
	DeviceAlarmOutParameterInformation,		//G/S  DEVICE_ALARM_OUT_PARAMETER_INFORAMTION    设备报警输出参数信息
	DeviceVideoOutputParameterInformation,	//G/S  DEVICE_VIDEO_OUTPUT_PARAMETER_INFORMATION   设备视频输出参数信息(不支持)
	DeviceUserParameterInformation,			//G/S  DEVICE_USER_PARAMETER_INFORMATION    设备用户参数信息
	DeviceExceptionParameterInformation,	//G/S  DEVICE_EXCEPTION_PARAMETER_INFORMATION   设备异常参数信息
	DeviceTextOutParameterInformation,		//G/S  DEVICE_TEXTOUT_PARAMETER_INFORMATION       设备字符叠加参数信息
	DeviceAuxOutParameterInformation,		//G/S  DEVICE_AUX_OUT_PARAMETER_INFORMATION       设备报警触发辅助输出信息(不支持)
	DeviceNetAppParameterInformation,		//G/S  DEVICE_NET_APP_PARAMETER_INFORMATION       设备网络应用参数信息
	DeviceNfsParameterInformation,			//G/S  DEVICE_NFS_PARAMETER_INFORMATION           设备网络文件系统参数信息(不支持)
	DeviceIPResourceParameterInformation,	//G/S  DEVICE_IP_RESOURCE_PARAMETER_INFORMATION   IP设备接入资源参数信息(不支持)
	DeviceHardDiskParameterInformation,		//G/S  DEVICE_HARDDISK_PARAMETER_INFORMATION    设备硬盘参数信息
	DevicePTZParameterInformation,			//G/S  DEVICE_PTZ_PARAMETER_INFORMATION          云台参数信息(不支持)

	//手机联动配置参数
	DeviceContactParameterInformation,		//联系人参数信息
	DeviceAlarmKeyParameterInformation,		//8路摄像头告警开关信息
	DeviceAlarmInputParameterInformation,	//8路输入告警开关
	DeviceIMGParameterInformation,			//拍照、图片效果参数
	DeviceMMSParameterInformation,			//彩信参数
	DeviceAUTOENABLEParameterInformation,	//定时参数
	DeviceOtherParameterInformation,		//OTHER参数
	DeviceRestoreAllPhoneInfo,				//回复手机配置为出厂设置
	DeviceGetGSMStatueInfo,					//获取GSM模块状态信息

	//GSM V2版参数
	DeviceGSMNetParameterInformation,       //G/S  GSM网络参数 SN_GSM_NETPARA
	DeviceGSMTimmingMMS,					//G/S  定时彩信 SN_T_TIMING 
	DeviceGSMTimmingMonitor,				//G/S  定时布防 SN_T_AUTO 
	DeviceGSMAlarmSchedule,					//G/S  报警布防 SN_T_AUTO 
	DeviceGSMWorkMode,						//G/S  工作模式 SN_GSMWorkMode
	DeviceGSMTotalSettings,					//G    GSM总体参数 只能获取 SN_GSM_TOTAL_SETTINGS
	//SN6116
	DevicePictureParameterInformationV2,	//G/S  DEVICE_PICTURE_PARAMETER_INFORMATION_V2 设备图像参数信息 V2版本 NVR不支持视频画面参数和区域屏蔽
	DeviceRecordParameterInformationV2,		//G/S  DEVICE_RECORD_PARAMETER_INFORMATION_V2 设备录像参数信息 V2版本
	DeviceAlarmInParameterInformationV2,	//G/S  DEVICE_ALARM_IN_PARAMETER_INFORAMTION_V2    设备报警输入参数信息 V2版本
	DeviceAlarmOutParameterInformationV2,	//G/S  DEVICE_ALARM_OUT_PARAMETER_INFORAMTION_V2    设备报警输出参数信息 V2版本
	DeviceUserParameterInformationV2,		//G/S  DEVICE_USER_PARAMETER_INFORMATION_V2 设备用户参数信息 V2版本
	DeviceUserGroupParameterInformation,	//G/S  DEVICE_USER_GROUP_PARAMETER_INFORMATION  设备用户组信息
	DevicePowerTimmingParameterInformation,	//G/S  DEVICE_POWER_TIMMING_PARAMETER_INFORMATION 设备定时开关机参数信息
	//all
	DeviceClientCenterParameterInformation, //G/S  DEVICE_CLIENT_CENTER_PARAMETER_INFORMATION DVR报警中心信息
	DevicePhoneParameterInformation,		//G/S  DEVICE_PHONE_PARAMETER_INFORMATION	手机监控参数信息
	//SN6***
	DeviceVideoDisplayDefaultParameterInformation,	//G DEVICE_VIDEO_DISPLAY_DEFAULT_PARAMETER_INFORMATION 视频显示参数默认值 包括亮度、对比度等
	DeviceAlarmMovMasterSwitchParameterInformation,	// G/S DEVICE_ALARM_MOV_MASTER_SWITCH_PARAMETER_INFORMATION  报警及移动侦测使能总开关
	Device3GNetworkParameterInformation,			//G/S  DEVICE_3G_NETWORK_PARAMETER_INFORAMTION    3G无线网络参数信息结构体 
	DeviceSMTPParameterInformaton,			//G/S	 DEVICE_SMTP_PARAMETER_INFORMATION	SMTP参数信息 包括邮件收件人列表
	DeviceMMSParameterInformationSN6,		//G/S	 SN_MMSCONFIGSN6 彩信参数
	DevicePhoneListInformation,				//G/S	 SN_PHONE_LIST_INFO 电话联系人列表
	DeviceGeneralCfgInformaton,				//G/S	 DEVICE_GENERAL_CFG_BASIC 设备通用配置信息
	DeviceWIFIBasicInformaton,				//G/S	 SN_DVR_WIFI_CFG_BASE WIFI基本配置
	DeviceWIFISeniorInformaton,				//G/S	 SN_DVR_WIFI_CFG_ADV WIFI高级配置
	DeviceWIFIPasswordRCD,					//G/S	 SN_DVR_WIFI_KEY_SET WIFI密码记录	
	DeviceMotionDetectLinkageVoice,			//G/S	 DEVICE_PRM_MOTION_DETECT_LINKAGE 移动侦测语音播报联动
	DeviceVideoLostLinkageVoice,			//G/S	 DEVICE_PRM_VIDEO_LOST_LINKAGE 视频丢失语音播报联动 
	DeviceAlarmInLinkageVoice,				//G/S	 DEVICE_PRM_ALARM_IN_LINKAGE 报警输入语音播报联动 
	DevicePlayVoiceTimes,					//G/S	 DEVICE_PRM_VOICE_PLAY_TIMES 语音播放次数 
	DeviceAuthorityInfo,					//G		 DEVICE_PRM_AUTHLOCK_INFO获取当前设备期锁状态 
	//SN17**
	DeviceUPNPParameterInformaton,			//G/S	 DEVICE_UPNP_PARAMETER_INFO	设备端口映射
	DevicePictureoverturn,					//G/S	 DEVICE_PICTURE_OVERTURN 图像翻转功能
	//车载DVR
	DeviceGPSprofessionalServiceInformaton, //G/S	 SN_GPS_DVR_SERVER_ADDR GPS业务服务器设置
	DeviceGPSVideoServiceAddress,			//G/S	 SN_GPS_DVR_VIDEO_SERVER_ADDR 视频服务器平台地址
	DeviceGPSTermAlarmVideoUpload,			//G/S	 SN_GPS_DVR_TERM_ALARM_VIDEO_UPLOAD 条件报警录像上传
	DeviceGPSDevInformation,				//G/S	 SN_GPS_DVR_DEVICE_INFO GPS设备信息
	DeviceGPSControlOffAndOnTimer,			//G/S	 SN_GPS_DVR_FIXED_TIME 受GPS模块控制的定时开关机
	DeviceGPSInformaton,					//G/S	 SN_GPS_DVR_VEHICLE_INFO 车辆信息
	DeviceGPSOSDInformaton,					//G/S	 SN_GPS_DVR_INFO_OSD_CHAN GPS OSD信息
	DeviceGPSRecordControl,					//G/S	 SN_GPS_DVR_RCD_CTRL 录像控制
	//NVR
	DeviceNVRNetConnectSetting,				//G/S	 SN_DVR_NET_CONNECT_SETTING IPC连接配置 //NVR使用
	DeviceNVRTimeSync,						//G/S	 DEVICE_PRM_NVR_TIMESYNC	IPC时间同步间隔设置//youxnNVR
	DeviceNVRPTZConfigSwitch,				//G/S	 DEVICE_PRM_PTZ_SWITCH		本地/远程云台选择配置//youxnNVR
	DeviceNVRPTZDecoderParameterInformation,//G		 NVR_PTZ_DECODER_PARAMETER_INFORMATION 设备云台解码器参数信息,设置用DevicePTZDecoderParameterInformation//youxnNVR
	DeviceNVRDisplayCfgChan,				//G/S	 SN_DVR_IMAGE_PARAM 图像显示参数信息(远程配置)//youxnNVR	
	DeviceNVROsdCfgChan,					//G/S	 DEVICE_PRM_NVR_OSDCFGCHAN OSD显示参数信息(远程配置)//youxnNVR	
	DeviceNVRChanCfgBasicChan,				//G/S	 DEVICE_PRM_NVR_CHANBASICCFG 通道基本配置信息(远程配置)//youxnNVR	
	DeviceNVRAlarmInParameterInformationV2,	//G/S	 DEVICE_ALARM_IN_PARAMETER_INFORAMTION_V2 设备报警输入参数信息V2版本(远程配置)//youxnNVR
	DeviceVoIPAlarmLinkage,					//G/S	 DEVICE_PRM_VOIP_ALARM_LINK VoIP报警联动参数配置
	DeviceScanGunParameterInformation,		//G/S	 DEVICE_SCAN_GUN_CFG	扫描输入配置(扫描枪)
	DeviceSeniorPictureParameterInformation,//G/S	 DEVICE_SENSOR_ADV_CFG 设备图像高级参数信息
	DeviceNVRIPCPortSetting,                //G/S	 IPC远程端口配置//NVR使用
	DeviceAlarmBuzzerParameterInformation,	//G/S    DEVICE_ALARM_BUZZER_PARAMETER_INFORMATION报警蜂鸣时长参数配置
	//NVS
	DeviceNVSDecodeMode,                    //NVS主动解码解码模式及预览模式,对应SN_NVS_PRM_DECODE结构体
	DeviceNVSAlarmAudioSetting,             //NVS主动解码报警画面切换延时、音频总开关配置,对应SN_NVS_PRM_PREVIEW_ADV_CFG结构体
	DeviceNVSPreviewSetting,                //NVS主动解码不同预览模式下,各通道的参数配置,对应SN_NVS_PRM_PREVIEW_CFG_EX结构体
	DeviceNVSSwitchChan,                    //NVS主动解码页面配置,对应SN_NVS_PRM_SWITCHINFO结构体
	DeviceNVSPasDecodeSetting,              //NVS被动解码设备信息及各通道使能配置,对应SN_NVS_PRM_PASDECODEINFO结构体
	DeviceNVSAlarmInLinkSetting,            //NVS报警关联通道配置,对应SN_NVS_PRM_ALMINLINKAGE结构体
	DeviceNVSRS485KeyboardSetting,          //NVS键盘配置,对应SN_NVS_PRM_RS485_CFG结构体
};
//IPC连接测试
//支持255家公司, 每家公司支持255款产品
enum NVR_IPC_COMPANY
{
	NVR_STARNET = 0,//星网
	NVR_OTHER = 255	//其他
};
//每家公司支持配置的产品型号从 (对应公司_enum << 8)       开始,
//      不支持配置的产品型号从 (对应公司_enum << 8 + 0x80) 开始,
enum NVR_IPC_PRODUCT
{
	IPC_SN_Series	= (NVR_STARNET << 8),		    //IPC-Z
	IPC_SN_DVR,                                     //新增DVR、NVR、IPC和NVS的产品类型
	IPC_SN_NVR,
	IPC_SN_IPC,
	IPC_SN_NVS,
	IPC_SN_IPCA		= (NVR_STARNET << 8) | 0x80,	//IPC-A
	IPC_SN_IPCK,									//IPC-K
	IPC_SN_IPCJ,									//IPC-J
	IPC_SN_ELSE,									//其他
	IPC_UNKNOWN		= (NVR_OTHER << 8 ) | 0x80
};
//NVS解码模式枚举
enum DecodecMode_enum
{
	SwitchDecode  = 0,       //主动解码
	PassiveDecode = 1        //被动解码
};

//NVS主动解码状态枚举,主动解码使用
enum SwitchState_enum
{
	SCM_CHNSWITCH_START = 5, //开始轮询(从5开始,以跟设备端一致)
	SCM_CHNSWITCH_END   = 6  //关闭轮询
};

//NVS连接模式,主动解码使用
enum ConnetcMode_enum
{
	SingleConnect = 0,       //单连接
	MulConnetc    = 1        //多连接
};
//对应NVR SN8616-28-HD第二码流配置结构体中的分辨率
enum _SN_Resolution_enum
{
	_SN_4CIF = 0, //704*576
	_SN_DCIF,     //528*384
	_SN_2CIF,     //704*288
	_SN_CIF,      //352*288
	_SN_QCIF,     //176*144
	_SN_720P,     //1280*720 
	_SN_UXGA,     //1600*1200
	_SN_960H,     //960*576
	_SN_SXGA,     //1280*1024
	_SN_120W,     //1280*960
	_SN_160W,     //1696*954
	_SN_1080P,    //1920*1080
	_SN_3M        //2048*1536
};
//本地视频预览模式
enum SN_PRM_PREVIEWOUTMODE_EM
{
	StretchMode = 0,  //拉伸模式
	SameScaleMole,    //等比例模式
	IntelligentMode   //智能模式
};

//-------------------------------------------------------------------------------------
//enum类型end
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
//定义区域start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//1.会话管理相关定义
//-----------------------------------------
#define SDK_INVALID_SESSION_ID			((LONG)(-1))					  //无效的设备会话ID
#define SDK_IS_INVALID_SESSION_ID(x)	(SDK_INVALID_SESSION_ID == (x))	  //true=无效会话ID，false=有效
#define SDK_INVALID_HANDLE_VALUE		((LONG)(-1))					  //无效SDK句柄
#define SDK_IS_INVALID_HANDLE_VALUE(x)	(SDK_INVALID_HANDLE_VALUE == (x)) //true=无效SDK句柄,false=有效



//-------------------------------------------------------------------------------------
//2.配置相关常量的定义start
//-------------------------------------------------------------------------------------
#define MAX_USERNAME_LEN			32				//操作员名最大长度
#define MAX_NAME_LEN				32              //名称长度
#define MAX_URL_STR_LEN             64              //URL最大长度
#define SN_DEVICE_SERIALNO_LEN		64				//设备序列号最大长度
#define DEVICE_NAME_LEN				64				//设备名最大长度
#define MAX_CHANNEL_NAME_LEN		45              //通道名称最大长度
#define MACADDR_LEN					6				//MAC地址字节长度
#define IPADDRESS_MAX_LEN			48				//IP地址字符串最大长度
#define MAX_DEVICE_FILENAME_LEN		100				//录像文件名最大长度
#define PTZ_PROTOCOL_DESCRIPT_LEN	32				//云台协议描述字符串最大长度
#define PTZ_PROTOCOL_MAX_COUNT		200				//支持的云台协议的最大数
#define LOG_INFO_LEN                11840			//日志附加信息最大长度
#define MAX_LINK					16				//最大连接数  
#define MAX_DISKNUM				32		//DVR支持的最大硬盘数量
#define MAX_CHANNUM				32		//DVR支持的最大通道数量
#define MAX_ALARMIN				25		//DVR支持的最大报警输入数量
#define MAX_ALARMOUT			16		//DVR支持的最大报警输出数量
#define PASSWD_LEN				16		//密码最大长度
#define MAX_ETHERNET			2		//支持最大网卡数量
#define MAX_DOMAIN_NAME			64		//最大域名长度
#define MAX_SCHEDULE_DAYS		7		//最大计划周期天数，这里定为一周
#define MAX_TIMESEGMENT			8		//最大一天计划时间段数量
#define MAX_SHELTERNUM			4		//最大遮挡数量
#define MAX_PTZ_PRESET			256		//设备支持的云台预置点数
#define MAX_PTZ_TRACK			256		//设备支持的云台轨迹数
#define MAX_PTZ_CRUISE			256		//设备支持的云台巡航数
#define PHONENUMBER_LEN			32		//拨号号码最大长度
#define MAX_ANALOG_CHANNUM		32		//最大模拟通道数量
#define MAX_VIDEOOUT			4		//设备的视频输出数
#define MAX_VGA					4		//设备最大可接VGA数
#define MAX_MATRIXOUT           16		// 最大模拟矩阵输出个数 
#define MAX_RIGHT			    32		//设备支持的权限（1-21表示本地权限，13-32表示远程权限）
#define MAX_USERNUM				32		//设备最大用户数
#define MAX_GROUPNUM			20		//最大用户组数
#define MAX_EXCEPTIONNUM		32		//设备最大异常处理数
#define MAX_STRINGNUM			8		//设备最大OSD字符行数
#define MAX_DDNS_NUMS	        10		//设备最大可配ddns数
#define MAX_ONLINE_USER_COUNT	20		//最大在线用户数
#define MAX_NFS_DISK			8		//设备支持的最大网络硬盘数
#define MAX_WINDOW				16		//设备最大播放窗口数
#define MAX_AUXOUT			    4		//设备最大辅助输出数
#define CRUISE_MAX_PRESET_NUMS	32	 	//一条巡航最多的巡航点
#define MAX_MOTION_AREA			16		//移动侦测最大区域数
#define MAX_HIDE_AREA			16		//视频遮盖区域最大数
#define MAX_COVER_AREA			16		//视频遮挡区域最大数
#define MAX_PRODUCT_TYPE_LEN	20		//产品类型最大长度
#define MAX_AUDIO_LISTEN_NUM    16		//最大监听频道数
#define MAX_NVR_CHANNUM			255		//NVR支持的最大通道数量
#define MAX_ALARMIN				25		//DVR支持的最大报警输入数量
//#define MAX_CHANNEL_NUM		16		//最大频道号
#define MAX_OWNERCNT			11		//主人号码最大位数
#define MAX_PHONELEN			20		//电话号码长度
#define MAX_PWDLEN				5		//密码长度
#define MAX_EMAILLEN			30		//邮件长度
#define MAX_NAMELEN				20		//联系人长度
#define MAX_MMSCLEN 			50		//mmsc最大长度
#define MAX_GATEWAYLEN			20		//网关的最大长度
#define MAX_APNLEN				20		//apn的最大长度
#define MAX_USERNAMELEN			20		//用户名的最大长度
#define MAX_PASSWORDLEN			20		//密码的最大长度
#define REVERSEMAX				10		//预留参数最大长度
#define MAX_PINLEN 				10		//pin码最大长度
#define MAX_MNCLEN 				10		//mnc的最大长度
#define MAX_IMSILEN				26		//ims最大长度
#define MAX_OSD_STRING_LEN		44		//osd字符串最大长度

#define MAX_3G_APN_LEN			32		//3G的apn的最大长度
#define MAX_3G_PHONE_LEN		32		//3G拨号号码的最大长度
#define MAX_3G_NAME_LEN			32		//3G用户名的最大长度
#define MAX_3G_PASSWORD_LEN 	32		//3G用户名密码的最大长度
#define MAX_3G_RESERVE_LEN 		32		//3G保留字段的最大长度

#define MAX_DEVID_LEN			64		//设备身份信息的最大长度

#define MAX_PHONE_LIST_NUM		10 		//电话联系人最大数

#define MAX_DIALNUMLEN			32		//拨号号码的最大长度

#define IPC_RESOLUTION_NUM      128		//IPC分辨率
#define IPC_CODECS_LEN          12		//IPC编码长度
#define IPC_QUAAREA_LEN         256		//NVR图像质量范围
//-------------------------------------------------------------------------------------
//2.配置相关常量的定义end
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
//1.设备类型定义区域start
//-------------------------------------------------------------------------------------
#define SN_CLASS_DVR		0	//DVR设备
#define SN_CLASS_IPC		1	//IPC设备
#define SN_CLASS_DECODER    2	//解码器设备类
#define SN_CLASS_NVR	    3	//NVR设备类
//-----------------------------------------
//SN_CLASS_IPC，6
//-----------------------------------------
#define DEV_IPC_UNKNOWN		-1	//未知IPC
#define DEV_SN_1700			0	//SN1700(D1)
#define DEV_SN_1712			1	//SN1712（720P）
#define DEV_SN_1500H		2	//IPC_1500H
#define DEV_SN_1612         3	//SN1612
#define DEV_IPC_SN1732		4	//SN1732
//-----------------------------------------
//SN_CLASS_DVR
//-----------------------------------------
#define DEV_SN_8616_28_M    52  // SN8616-28-M
#define DEV_SN_8616_3U_HD   51  // SN8616-3U-HD
#define DEV_SN_ZA08         50  // SN6108ZA
#define DEV_SN_9234H		49	// 解码器
#define DEV_SN_8616_HD		48	// SN8616HD-28-HD
#define DEV_SN_6004			47  // SN6004
#define DEV_SN_6116_LC		46	// SN6116LC		//DVR
#define DEV_SN_6904			45	// SN6904
#define DEV_SN_6116_HC      44	// SN6116HC
#define DEV_SN_8616M_LE		43	// SN8616M LE	//NVR
#define DEV_SN_8616D_LE		42	// SN8616D LE
#define DEV_SN_8608M_LE		41	// SN8608M LE
#define DEV_SN_8608D_LE		40	// SN8608D LE
#define DEV_SN_8608M		39	// SN8608M
#define DEV_SN_8608D		38	// SN8608D
#define DEV_SN_8604M		37	// SN8604M
#define DEV_SN_8604D		36	// SN8604D
#define DEV_ZT_680_HD_B		46  // ZT680/HD-B	
#define DEV_ZT_640_HC		35	// ZT640/HC		
#define DEV_ZT_620_HD		26	// ZT620/HD
#define DEV_ZT_380_HD		20	// ZT380/HD
#define DEV_ZT_680_HD		19	// ZT680/HD
#define DEV_ZT_340_HD		16	// ZT340/HD	 
#define DEV_ZT_640_HD		15	// ZT640/HD
#define DEV_ZT_680_HC		12	// ZT680/HC
#define DEV_ZT_860B_H_HC	9	// ZT860B-H/HC
#define DEV_SN_2008_LE      35	// SN2008LE		//DVR
#define DEV_SN_2016HS_V2    34	// SN2016HS v2
#define DEV_SN_2016HE_V2    33	// SN2016HE v2
#define DEV_SN_2116_LE_V2   32	// SN2116LE v2
#define DEV_SN_2116_LS_V2   31	// SN2116LS v2
#define DEV_SN_2116_LP_V2   30	// SN2116LP v2
#define DEV_SN_2116_HE_V2   29  // SN2116HE v2
#define DEV_SN_2116_HS_V2   28	// SN2116HS v2
#define DEV_SN_2116_HP_V2   27	// SN2116HP v2
#define DEV_SN_6004			47  // SN6004
#define DEV_SN_6104	   	    26	// SN6104,SG2000
#define DEV_SN_6108			25	// SN6108
#define DEV_SN_6116_HS		24	// SN6116HS
#define DEV_SN_6116_LS		23	// SN6116LS
#define DEV_SN_6116_HP		22	// SN6116HP
#define DEV_SN_6116_LP		21	// SN6116LP
#define DEV_SN_6116_HE		20	// SN6116HE
#define DEV_SN_6116_LE		19	// SN6116LE
#define DEV_SN_6108_HS		18	// SN6108HS
#define DEV_SN_6108_LS		17	// SN6108LS
#define DEV_SN_6108_HE		16	// SN6108HE
#define DEV_SN_6108_LE		15	// SN6108LE
#define DEV_SN_6104_HE		14	// SN6104HE
#define DEV_SN_6104_LE		13	// SN6104LE
#define DEV_SN_2016_HE  	12	// SN2016-HE
#define DEV_SN_2016_HS  	11	// SN2016-HS
#define DEV_SN_2016			10	// SN2016
#define DEV_SN_2116_LE  	9	// SN2116-HE
#define DEV_SN_2116_LS  	8	// SN2116-HS
#define DEV_SN_2116_LP		7	// SN2116-HP
#define DEV_SN_2116_HE  	6	// SN2116-HE
#define DEV_SN_2116_HS  	5	// SN2116-HS
#define DEV_SN_2116_HP		4	// SN2116-HP
#define DEV_SN_6116			2	// SN6116
#define DEV_SN_2004			1	// SN2004
#define DEV_SN_2008			0	// SN2008

#define DEV_IPC_NOTSUPPORT	-3  //提示: 该型号暂不支持配置
#define DEV_IPC_NOTLOGIN	-2  //提示: 用户名或密码错误
#define DEV_IPC_UNKNOWN		-1  //未配置或未启用或未连接等情况,不提示  
//-------------------------------------------------------------------------------------
//1.设备类型定义end
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//2. 结构体成员相关的定义start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//结构体DeviceRegisterNotify.dwNotifyCode,通知代码
//-----------------------------------------
#define DEV_REGISTER_NOTIFY_PRECONNECT		0	//设备预连接通知 设备正进行连接注册 可以通过回调返回非零值拒绝设备注册
#define DEV_REGISTER_NOTIFY_CONNECTED		1	//设备连接通知 设备注册完成，这之后可以进行设备登录、预览等后续操作
#define DEV_REGISTER_NOTIFY_DISCONNECT		2	//设备断开

//-----------------------------------------
//结构体DeviceRegisterNotify.dwStreamSet,码流类型
//-----------------------------------------
#define STREAM_TYPE_NORMAL			1		//主码流
#define STREAM_TYPE_NET				2		//子码流

//-----------------------------------------
//结构体SN_DVR_ALARMER.flag，指示SN_DVR_ALARMER成员是否可用
//-----------------------------------------
#define ALARMER_FLAG_SESSION_ID		(0x00000001)	//SN_DVR_ALARMER.lSessionID可用
#define ALARMER_FLAG_SERIAL_NUMBER	(0x00000002)	//SN_DVR_ALARMER.sSerialNumber可用
#define ALARMER_FLAG_DEVICE_VERSION	(0x00000004)	//SN_DVR_ALARMER.dwDeviceVersion可用
#define ALARMER_FLAG_DEVICE_NAME	(0x00000008)	//SN_DVR_ALARMER.sDeviceName可用
#define ALARMER_FLAG_MAC_ADDR		(0x00000010)	//SN_DVR_ALARMER.byMacAddr可用
#define ALARMER_FLAG_LINK_PORT		(0x00000020)	//SN_DVR_ALARMER.wLinkPort可用
#define ALARMER_FLAG_DEVICE_IP		(0x00000040)	//SN_DVR_ALARMER.sDeviceIP可用
#define ALARMER_FLAG_SOCKET_IP		(0x00000080)	//SN_DVR_ALARMER.sSocketIP可用
#define ALARMER_FLAG_IP_PROTOCOL	(0x00000100)	//SN_DVR_ALARMER.byIpProtocol可用

//-----------------------------------------
//SN_GSM_TOTAL_SETTINGS.dwFlags
//-----------------------------------------
#define SN_GSM_TOTAL_SETTINGS_VERSION_FLAGS_NORMAL		1	//GSM正常版本标示
#define SN_GSM_TOTAL_SETTINGS_VERSION_FLAGS_NETWORK		2	//GSM网络版本标示

//-----------------------------------------
//DEVICE_NOTIFY_ST.dwNotifyCode 设备通知码
//-----------------------------------------
#define DEVICE_NOTIFY_PARAMETER_UPDATE		0			//参数更新
#define DEVICE_NOTIFY_POWER_OFF				1			//设备关机
#define DEVICE_NOTIFY_REBOOT				2			//设备重启
#define DEVICE_NOTIFY_TIME_UPDATE			3			//时间更新
#define DEVICE_NOTIFY_DEVICE_IP_CHANGE		4			//设备IP改变
#define DEVICE_NOTIFY_UNKNOWN_TYPE			0x627		//未知类型


//DEVICE_USER_GROUP_PARAMETER_INFORMATION.dwOperate，用户组操作
#define UG_ALL_GROUP					0							//获取所有用户组
#define UG_SINGLE_GROUP					1							//获取单个用户组
#define UG_ADD_GROUP					0							//添加用户组
#define UG_UPDATE_GROUP					1							//更新用户组
#define UG_DELETE_GROUP					2							//删除用户组

//DEVICE_3G_NETWORK_PARAMETER_INFORAMTION.byOperatorType	运营商
#define UNKNOW_COMPANY				0		//未知
#define CHINA_MOBILE				1		//中国移动
#define CHINA_UNICOM				2		//中国联通
#define CHINA_TELECOM				3		//中国电信


//-------------------------------------------------------
//SN_DVR_ALARMINFO
//-------------------------------------------------------
//SN_DVR_ALARMINFO.dwAlarmType报警主类型
#define SN_INPUT_ALARM_START			0	//信号量报警开始
#define SN_INPUT_ALARM_END				1	//信号量报警结束
#define SN_MOTION_DETECT_ALARM_START	2	//移动侦测开始
#define SN_MOTION_DETECT_ALARM_END		3	//移动侦测结束
#define SN_VIDEO_COVER_ALARM_START		4	//视频遮挡开始
#define SN_VIDEO_COVER_ALARM_END		5	//视频遮挡结束
#define SN_VIDEO_LOST_ALARM_START		6	//视频丢失开始
#define SN_VIDEO_LOST_ALARM_END			7	//视频丢失结束
#define SN_MANUAL_ALARM_START			8	//手动报警开始
#define SN_MANUAL_ALARM_END				9	//手动报警结束
#define SN_EXP_OCCUR_ALARM_START		10	//异常报警开始
#define SN_EXP_OCCUR_ALARM_END			11	//异常报警结束

//SN_DVR_ALARMINFO.dwExcepSubType异常报警类型枚举
#define SN_EXP_DISK_FULL			1	//磁盘满
#define SN_EXP_DISK_ERROR			2	//磁盘错误
#define SN_EXP_NETWORK_ERROR		3	//网络断开
#define SN_EXP_IP_CONFLICT			4	//ip冲突
#define SN_EXP_ILLEGAL_ACCESS		5	//非法访问
#define SN_EXP_VIDEO_ABNORMAL		6	//视频输入异常
#define SN_EXP_VIDEO_STANDARD		7	//输入输出制式不匹配
#define SN_EXP_GSM_ERROR			8	//GSM模块异常
#define SN_EXP_REC_FAIL				9	//录像失败

//-------------------------------------------------------------------------------------
//2. 结构体相关成员的定义end
//-------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------
//3. 设备操作状态相关的定义start
//   相关函数SN_DVR_SetExceptionFilter
//-------------------------------------------------------------------------------------
//-----------------------------------------
//预览
//-----------------------------------------
#define PREVIEW_EXCEPTION	1				// 预览异常，非阻塞模式发起预览
#define PREVIEW_SUCCESS		5				// 预览成功
#define SESSION_PREVIEW_REPLAY_SUCCESS	6	// 预览重开成功 
#define SESSION_PREVIEW_REPLAY_FAILED	7   // 预览重开失败 

//-----------------------------------------
//语音对讲
//-----------------------------------------
#define SESSION_TALKBACK_REPLAY_SUCCESS	8	// 对讲重开成功 
#define SESSION_TALKBACK_REPLAY_FAILED	9	// 对讲重开失败

//-----------------------------------------
//远程回放
//-----------------------------------------
#define SESSION_REMOTEPLAYBACK_REPLAY_SUCCESS	10	// 远程回放重开成功 
#define SESSION_REMOTEPLAYBACK_REPLAY_FAILED	11	// 远程回放重开失败

//-----------------------------------------
//网络
//-----------------------------------------
#define CONNECTION_BROKEN	2		//与设备端连接断开
#define DEVICE_NOTIFY		3		//设备参数更新通知
#define RECONNECT_REPORT	4		//重连报告

//-------------------------------------------------------------------------------------
//3. 设备操作状态相关的定义end
//-------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------
//4.常见类型start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//log信息的重要等级
//-----------------------------------------
#define SCI_TRACE_NONE		0		//无级别
#define SCI_TRACE_HIGH		1		//高级
#define SCI_TRACE_NORMAL	2		//正常级别
#define SCI_TRACE_LOW		3		//低级

//-----------------------------------------
//流媒体数据类型定义
//-----------------------------------------
#define SN_DVR_STREAMAUDIO	0		//流媒体音频数据
#define SN_DVR_STREAMHEAD	1		//流媒体数据头 
#define SN_DVR_STREAMDATA	2		//流媒体视频数据
//-----------------------------------------
//远程回放控制码
//开始播放 调用SN_DVR_PlayBackByFileName之后已经进行了播放
//-----------------------------------------
#define SN_DVR_PLAYSTOP			2//停止播放
#define SN_DVR_PLAYPAUSE		3//暂停播放
#define SN_DVR_PLAYRESUME		4//恢复播放
#define SN_DVR_PLAYFAST			5//快放
#define SN_DVR_PLAYSLOW			6//慢放
#define SN_DVR_PLAYNORMAL		7//正常速度
#define SN_DVR_PLAYFRAME		8//单帧放
#define SN_DVR_PLAYSTARTAUDIO	9//打开声音
#define SN_DVR_PLAYSTOPAUDIO	10//关闭声音
#define SN_DVR_PLAYAUDIOVOLUME	11//调节音量
#define SN_DVR_PLAYGETPOS		13//获取文件回放的进度  返回完成的千分比

//-----------------------------------------
//回调报警消息类型PFN_DEVICEMSGCallBack.dwMsgType
//-----------------------------------------
#define ALARM_INFO_UPLOAD	1			//报警消息上传
#define ALARM_INFO_NOTIFY	2			//报警消息通知

//-----------------------------------------
//SDK版本信息
//-----------------------------------------
#define MAJOR_VERSION   2		//主版本
#define MINOR_VERSION	1		//次版本
#define BUILD_NUMBER	32		//构建号
//-----------------------------------------
//条形码扫描相关
//-----------------------------------------
#define MAX_SCAN_GUN_DATA_LEN		128		//条码信息最大长度

//-----------------------------------------
//VOIP相关
//-----------------------------------------
#define MAX_VOIP_NAME_LEN 			32		//VOIP用户名最大长度
#define MAX_VOIP_PASS_LEN 			32		//VOIP密码最大长度
#define MAX_VOIP_IP_NAME_LEN 		128		//VOIPIP地址最大长度
#define MAX_VOIP_PORT_NAME_LEN		10		//VOIP端口最大长度

//-----------------------------------------
//图像参数相关
//-----------------------------------------
// 图像参数：亮度(0~255)，饱和度(0~255)，锐度(0~255)
// 编码参数：分辨率D1~QCIF
#define SENSOR_IPC_D1       1		//IPC_D1系列图像参数
// 图像参数：亮度(0~200)，饱和度(0~255)，对比度(0~20)，锐度(0~35)，水平翻转，垂直翻转，彩转黑设置
// 编码参数：分辨率UXGA, 720P, D1~QCIF
#define SENSOR_IPC_720P     2		//IPC_720P系列图像参数
// 图像参数：亮度(0~255)，饱和度(0~255)，锐度(0~255)，彩转黑设置
// 编码参数：分辨率960H, D1~QCIF
#define SENSOR_IPC_960H     3		//IPC_960H系列图像参数
// 图像参数：亮度(0~255)，饱和度(0~255)，对比度(0~255)，色调(0~255)
// 编码参数：分辨率D1~QCIF
#define SENSOR_IPC_D1_EX    4		//IPC_D1_EX系列图像参数
//NVS解码器使用
#define MAX_CONNECT_NUM             32                   //主动解码每个通道最大配置的设备数
#define	MAX_LINKAGE_NUM				4                    //告警管理每个通道最大配置的设备数 
#define MAX_URL_LEN                 128                  //URL地址最大长度
//-------------------------------------------------------------------------------------
//4.常见类型end
//-------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------
//5.配置相关常量的定义end
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//6.返回代码的定义start
//-------------------------------------------------------------------------------------
#define SN_DVR_ERROR_SUCESS						0x00000000	//操作成功
#define SN_DVR_PASSWORD_ERROR					0x00000001	//密码错误
#define SN_DVR_USERNAME_ERROR					0x00000002	//用户名错误
#define SN_DVR_ACCESS_DENIED					0x00000003	//访问拒绝
#define SN_DVR_MAX_DEVICE_CONNECTION			0x00000004	//设备达到最大连接数
#define SN_DVR_OUT_OF_MEMORY					0x00000005	//内存不足
#define SN_DVR_REQUEST_TIMEOUT					0x00000006	//请求超时
#define SN_DVR_INVALID_PARAMETER				0x00000007	//无效参数
#define SN_DVR_CONNECT_SERVER_FAILED			0x00000008	//连接服务器失败
#define SN_DVR_SEND_FAILED						0x00000009	//发送失败
#define SN_DVR_CREATE_SOCKET_ERROR				0x0000000A	//创建socket失败
#define SN_DVR_ALREADY_LOGIN					0x0000000B	//已经登录
#define SN_DVR_MAC_OR_IP_NOT_MATCH				0x0000000C	//MAC地址或者IP地址不匹配
#define SN_DVR_VIDEO_PREVIEW_ERROR				0x0000000D	//视频流预览出错
#define SN_DVR_LOCAL_PORT_INUSE					0x0000000E	//本地端口已经被使用
#define SN_DVR_FILE_NO_FOUND					0x0000000F	//文件(查找目标)未找到
#define SN_DVR_DEVICE_CONNECTION_LIMIT			0x00000010	//设备连接受限
#define SN_DVR_SET_PARAMETER_ERROR				0x00000011	//设置参数失败
#define SN_DVR_PARAMETER_DATA_ERROR				0x00000012	//参数数据错误
#define SN_DVR_NOT_SUPPORT						0x00000013	//不支持
#define SN_DVR_INNER_DATA_ERROR					0x00000014	//内部数据错误
#define SN_DVR_RESPONSE_ERROR_MSG				0x00000015	//设备返回请求失败消息
#define SN_DVR_CRUISE_POINT_EXISTING			0x00000016	//关键点已经存在
#define SN_DVR_GSMERROR_OPER					0x00000017  //操作异常
#define SN_DVR_GSMERROR_PARAM					0x00000018	//参数异常
#define SN_DVR_GSMERROR_EXP						0x00000019	//设备异常
#define SN_DVR_GSMERROR_NOSIM					0x0000001A	//无SIM卡
#define SN_DVR_GSMERROR_NONET					0x0000001B	//未联网
#define SN_DVR_GSMERROR_NONE					0x0000001C	//配置成功 
#define SN_DVR_GSMRESTARTING_IND				0x0000001D	//设备重启
#define SN_DVR_CRUISE_POINT_INVALID	            0x0000001E  //预置点无效
#define SN_DVR_MOD_VOA_TK_ERR_PB				0x0000001F  //对讲请求错误码,正在回放
#define SN_DVR_SQL_ERROR						0x00000020  //数据库操作失败
#define SN_DVR_CONDITION_ERROR					0x00000021  //条件错误
#define SN_DVR_NO_MATCH_RECORD					0x00000022  //没有可匹配的记录
#define SN_DVR_MAX_RECORD						0x00000023	//达到记录上限，一般用于增加记录操作
#define SN_DVR_PTZ_POINT_INVALID_ERR			0x00000024  //关键点不存在    删除的时候使用
#define SN_DVR_PTZ_PRESET_USE_ERR				0x00000025  //预置点已使用   添加的时候使用
#define SN_DVR_PTZ_PRESET_INVALID_ERR			0x00000026  //预置点无效  添加的时候使用
#define SN_DVR_PTZ_CRUISE_USE_ERR				0x00000027  //正在巡航  
#define SN_DVR_INNER_COMPONENT_CLOSED			0x00000028  //内部组件处于关闭状态  
#define SN_DVR_CREATE_AUDIO_OUTPUT_DEVICE_ERROR	0x00000029	//创建音频输出设备失败 
#define SN_DVR_CREATE_AUDIO_INPUT_DEVICE_ERROR	0x0000002A	//创建音频输入设备失败 
#define SN_DVR_CRUISE_OPERATION_ERROR			0x0000002B	//巡航操作失败 
#define SN_DVR_DEVICE_BUSY						0x0000002C	//设备忙 
#define SN_DVR_NO_HARDDISK						0x0000002D	//设备无硬盘 
#define SN_DVR_HARDDISK_FULL					0x0000002E	//硬盘数据满 
#define SN_DVR_ALL_HARDDISK_NOT_FORMATED		0x0000002F	//所有硬盘均未格式化 
#define SN_DVR_ANY_HARDDISK_NOT_FORMATED		0x00000030	//部分硬盘未格式化 
#define SN_DVR_HARDDISK_ERROR					0x00000031	//硬盘状态异常 
#define SN_DVR_NO_3G_MODULAR 					0x00000032	//无3G模块
#define SN_DVR_IS_TALKING 						0x00000033	//设备对讲中
#define SN_NVR_DIGITALCHAN_UNCONFIG				0x00000034	//NVR当前通道未配置
#define SN_DVR_AUTHORITY_LOCK					0x00000035	//权限到期
#define SN_DVR_UNAUTHORITY						0x00000036	//无权限		
#define SN_DVR_DATASIZE_TOOLAEAGE				0x00000037	//文件太大	
#define SN_DVR_SERIALCOM_UNOPEN					0x00000038	//串口未打开	
#define SN_DVR_SERIALCOM_OPEN_FAIL				0x00000039	//串口打开失败
#define SN_DVR_DEVICE_EXP						0x00000040	//设备端异常	
#define SN_NVR_REMOTE_CONF_DEVICE_EXP			0x00000041	//NVR远程配置设备端异常
#define SN_DVR_PASS_OR_USER_ERROR				0x00000042	//用户名或密码错误
#define SN_DVR_TEST_CONNECT_ERROR				0x00000043	//测试连接失败
#define SN_DVR_TEST_LOGON_ERROR					0x00000044	//登陆测试失败
#define SN_DVR_ERR_RESET_PASSWORD				0x00000045	//密码重置
#define SN_NVR_NOT_SUPPORT                      0x00000046	//NVR设备不支持
#define SN_NVS_NOT_SUPPORT                      0x00000046	//NVS设备不支持
#define SN_NVR_PTZ_OPT_FAILED                   0x00000047	//云台操作不成功

#define SN_DVR_3G_CONNECT_FAILED 				0x00000100	//3G连接失败
#define SN_DVR_STARTED_RECORD_ERROR				0x00000101	//已经开始录像
#define SN_DVR_NO_STARTED_RECORD_ERROR			0x00000102	//未开始录像
#define SN_DVR_UNKNOWN_ERROR					0x00000626	//未知错误

#define SN_NVR_PTZ_OPT_FAILED                   0x00000047	//云台操作不成功
//解码器云台控制错误码
#define SN_ERR_PTZ_PASDECODE_LOCALPTZ          (151)//被动解码下，操作本地云台错误               
#define SN_ERR_PTZ_PASDECODE_REMOTEPTZ         (152)//被动解码下，操作远程云台错误      
#define SN_ERR_PTZ_SWITCHSTATE_LOCALPTZ        (153)//轮询状态下，操作本地云台错误
#define SN_ERR_PTZ_SWITCHSTATE_REMOTEPTZ       (154)//轮询状态下，操作远程云台错误   

//-------------------------------------------------------------------------------------
//6.返回代码的定义end
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
//7.云台控制的定义start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//SN_DVR_PTZControlWithSpeed
//SN_DVR_PTZControl
//-----------------------------------------
#define ZOOM_IN			1	// 焦距以速度dwSpeed变大(倍率变大) 
#define ZOOM_OUT		2	// 焦距以速度dwSpeed变小(倍率变小) 
#define FOCUS_NEAR      3   // 焦点以速度dwSpeed前调 
#define FOCUS_FAR       4   // 焦点以速度dwSpeed后调 
#define HALO_OPEN       5   // 光圈以速度dwSpeed扩大 
#define HALO_CLOSE      6   // 光圈以速度dwSpeed缩小 
#define TILT_UP			7	// 云台以dwSpeed的速度上仰 
#define TILT_DOWN		8	// 云台以dwSpeed的速度下俯 
#define PAN_LEFT		9	// 云台以dwSpeed的速度左转 
#define PAN_RIGHT		10	// 云台以dwSpeed的速度右转 
#define UPPER_LEFT		11	// 云台以dwSpeed的速度上仰和左转 
#define UPPER_RIGHT		12	// 云台以dwSpeed的速度上仰和右转 
#define DOWN_LEFT		13	// 云台以dwSpeed的速度下俯和左转 
#define DOWN_RIGHT		14	// 云台以dwSpeed的速度下俯和右转 
#define PAN_AUTO		15	// 云台以dwSpeed的速度左右自动扫描 
#define LIGHT_ON		16	// 打开云台灯光
#define LIGHT_OFF		17	// 关闭云台灯光
#define BRUSH_ON		18	// 打开云台雨刷
#define BRUSH_OFF		19	// 关闭云台雨刷
//-----------------------------------------
//SN_DVR_PTZPreset 控制命令
//-----------------------------------------
#define ADD_PRESET		1 //设置预置点
#define DEL_PRESET		2 //清除预置点
#define CALL_PRESET		3 //转到预置点

//-----------------------------------------
//SN_DVR_PTZCruise 控制命令
//-----------------------------------------
#define DEL_ALLPRE_CRUISE	0 //删除巡航路径所有的巡航预置点
#define FILL_PRE_CRUISE	    1 //将预置点加入巡航序列、停顿时间、巡航速度
#define DEL_PRE_CRUISE	    2 //将预置点从巡航序列中删除
#define RUN_CRUISE		    3 //开始巡航
#define STOP_CRUISE		    4 //停止巡航

//-----------------------------------------
//SN_DVR_PTZTrack 控制命令
//-----------------------------------------
#define START_MEM_TRACK	1 //开始记录轨迹
#define STOP_MEM_TRACK  2 //停止记录轨迹
#define RUN_TRACK		3 //开始轨迹


//-------------------------------------------------------------------------------------
//7.云台控制的定义end
//-------------------------------------------------------------------------------------


//-----------------------------------------
//设置设备用户信息时请在第二个参数lChannel中传递相应的值完成相应功能
//-----------------------------------------
#define USER_OPT_PWD		0	//修改指定用户密码密码
#define USER_OPT_ALL		1	//修改指定用户全部信息包括权限
#define USER_OPT_ADD		2	//增加新用户
#define USER_OPT_DELETE		3	//删除指定用户	




//-------------------------------------------------------------------------------------
//8.日志类型相关的定义start
//-------------------------------------------------------------------------------------
#define PRM_ID_LOG_MAJOR_ALL                0		// 主类型：全部日志
//-----------------------------------------
//报警日志
//-----------------------------------------
#define	 PRM_ID_LOG_MAJOR_ALARM             1		// 主类型:报警日志
#define	 PRM_ID_LOG_MINOR_ALARM_ALL         0		// 全部报警日志 
#define	 PRM_ID_LOG_MINOR_ALARM_IN          1		// 报警输入 
#define	 PRM_ID_LOG_MINOR_ALARM_OUT         2		// 报警输出 
#define	 PRM_ID_LOG_MINOR_ALARM_MOT_BEGIN   3		// 移动侦测报警开始 
#define	 PRM_ID_LOG_MINOR_ALARM_MOT_END     4		// 移动侦测报警结束 
#define	 PRM_ID_LOG_MINOR_ALARM_SHT_BEGIN   5		// 遮挡报警开始 
#define	 PRM_ID_LOG_MINOR_ALARM_SHT_END     6		// 遮挡报警结束 
#define	 PRM_ID_LOG_MINOR_VIDEO_LOST_BEGIN	7		// 视频丢失开始
#define	 PRM_ID_LOG_MINOR_VIDEO_LOST_END	8		// 视频丢失结束
//-----------------------------------------
//异常日志
//-----------------------------------------
#define  PRM_ID_LOG_MAJOR_EXCEPTION          			2		// 主类型:异常日志
#define	 PRM_ID_LOG_MINOR_EXCEPTION_ALL     			0		// 全部异常日志 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_VI_LOST     		1		// 信号丢失 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_ILLEGAL_ACCESS     	2		// 非法访问 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_HD_FULL     		3		// 硬盘满 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_HD_ERROR     		4		// 硬盘错误 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_DCD_LOST     		5		// MODEM 掉线 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_IP_CONFLICT    		6		// IP地址冲突 
#define	 PRM_ID_LOG_MINOR_EXCEPTION_NET_BROKEN    		7		// 网线断 
#define	 PRM_ID_LOG_MINOR_REC_ERROR    					8		// 录像出错
#define	 PRM_ID_LOG_MINOR_IPC_NO_LINK    				9		// IPC连接异常
#define	 PRM_ID_LOG_MINOR_IPC_VI_EXCEPTION				10		// 视频输入异常(只针对模拟通道)
#define	 PRM_ID_LOG_MINOR_OUTPUT_INPUT_NOT_MATCH		11		// 输入输出制式不匹配
//-----------------------------------------
//操作日志
//-----------------------------------------
#define PRM_ID_LOG_MAJOR_OPERARATION        				3		//主类型：操作日志
#define PRM_ID_LOG_MINOR_OPERARATION_ALL     				0		//全部操作日志 
#define PRM_ID_LOG_MINOR_OPERARATION_START_DVR     			1		//开机 
#define PRM_ID_LOG_MINOR_OPERARATION_STOP_DVR     			2		//关机 
#define PRM_ID_LOG_MINOR_OPERARATION_STOP_ABNORMAL     		3		//非法关机 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_RESET     		4		//本地重启设备
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_LOGIN			5		//本地登陆
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_LOGOUT			6		//本地注销登陆
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_CFG_PARM			7		//本地配置参数
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_PLAYBYFILE		8		//本地按文件回放或下载
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_START_REC 		9		//本地开始录像
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_STOP_REC 		10		//本地停止录像
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_PTZCTRL  		11		//本地云台控制
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_PREVIEW  		12		//本地预览 (保留不使用) 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_MODIFY_TIME 		13		//本地修改时间(保留不使用) 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_UPGRADE 			14		//本地升级 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_RECFILE_OUTPUT 	15		//本地备份录象文件 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_FORMAT_HDD 		16		//本地初始化硬盘 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_CFGFILE_OUTPUT 	17		//导出本地配置文件 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_CFGFILE_INPUT 	18		//导入本地配置文件 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_COPYFILE 		19		//本地备份文件 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_LOCKFILE 		20		//本地锁定录像文件 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_UNLOCKFILE 		21		//本地解锁录像文件 
#define PRM_ID_LOG_MINOR_OPERARATION_LOCAL_DVR_ALARM 		22		//本地手动清除和触发报警 
#define PRM_ID_LOG_MINOR_OPERARATION_IPC_ADD 				23		//本地添加IPC 
#define PRM_ID_LOG_MINOR_OPERARATION_IPC_DEL 				24		//本地删除IPC 
#define PRM_ID_LOG_MINOR_OPERARATION_IPC_SET 				25		//本地修改IPC 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_LOGIN 			26		//远程登录 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_LOGOUT 			27		//远程注销登陆 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_START_REC 		28		//远程开始录像 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_STOP_REC 		29		//远程停止录像 
#define PRM_ID_LOG_MINOR_OPERARATION_START_TRANS_CHAN 		30		//开始透明传输 
#define PRM_ID_LOG_MINOR_OPERARATION_STOP_TRANS_CHAN 		31		//停止透明传输 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_GET_PARM 		32		//远程获取参数 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_CFG_PARM 		33		//远程配置参数 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_GET_STATUS 		34		//远程获取状态 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_ARM 			35		//远程布防 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_DISARM 			36		//远程撤防 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_REBOOT 			37		//远程重启 
#define PRM_ID_LOG_MINOR_OPERARATION_START_VT 				38		//开始语音对讲 
#define PRM_ID_LOG_MINOR_OPERARATION_STOP_VT 				39		//停止语音对讲 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_UPGRADE 		40		//远程升级 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_PLAYBYFILE 		41		//远程按文件回放 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_PLAYBYTIME 		42		//远程按时间回放 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_PTZCTRL 		43		//远程云台控制 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_FORMAT_HDD 		44		//远程格式化硬盘 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_STOP 			45		//远程关机 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_LOCKFILE 		46		//远程锁定文件 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_UNLOCKFILE 		47		//远程解锁文件 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_CFGFILE_OUTPUT 	48		//远程导出配置文件 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_CFGFILE_INTPUT 	49		//远程导入配置文件 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_RECFILE_OUTPUT 	50		//远程导出录象文件 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_DVR_ALARM 		51		//远程手动清除和触发报警 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_IPC_ADD 		52		//远程添加IPC 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_IPC_DEL 		53		//远程删除IPC 
#define PRM_ID_LOG_MINOR_OPERARATION_REMOTE_IPC_SET 		54		//远程设置IPC
//-----------------------------------------
//new add
//-----------------------------------------
// #define MSG_ID_VOA_START				(MOD_VOA<<16)
// #define MSG_ID_VOA_VOICE_REQ			(MSG_ID_VOA_START+1) 	//对讲请求
// #define MSG_ID_VOA_VOICE_RSP		    (MSG_ID_VOA_START+2)	//对讲请求
// #define MSG_ID_VOA_IS_PB_REQ			(MSG_ID_VOA_START+3)	//查询是否回放状态
// #define MSG_ID_VOA_IS_PB_RSP			(MSG_ID_VOA_START+4)

//-----------------------------------------
//录像文件类型
//-----------------------------------------
#define PRM_ID_RECORD_FILE_ALL                0  //全部录像
#define PRM_ID_RECORD_FILE_TIMER              1  //定时录像
#define PRM_ID_RECORD_FILE_MANUAL             2  //手动录像
#define PRM_ID_RECORD_FILE_MOTO               3  //移动侦测录像
#define PRM_ID_RECORD_FILE_ALARM              4  //报警录像
#define PRM_ID_RECORD_FILE_MOTO_AND_ALARM     5  //移动侦测录像&&报警录像
#define PRM_ID_RECORD_FILE_MOTO_OR_ALARM      6  //移动侦测录像||报警录像


//-----------------------------------------
//恢复出厂操作ID
//-----------------------------------------
#define GENERALCFG	0	//常规参数
#define NETCFG		1	//网络配置
#define PTZCFG		2	//云台配置
#define DISPLAYMAN	3	//显示管理
#define RECORDMAN	4	//录像管理
#define ALARMMAN	5	//报警管理

//-------------------------------------------------------------------------------------
//8.日志类型相关的定义end
//-------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------
//常规结构体区域start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//1.SDK版本信息结构体，12字节
//-----------------------------------------
typedef struct _SN_SDK_VERSIONINFO{
	DWORD dwMajorVersion;				//主版本
	DWORD dwMinorVersion;				//次版本
	DWORD dwBuildNumber;				//构建号
}SN_SDK_VERSIONINFO,*LPSN_SDK_VERSIONINFO;

//Flash中各部分版本号信息，
typedef  struct _SN_FlashVersion{
	char UbootVer[4];    //UBOOT 版本
	char KernelVer[4];	 //Kernel 版本
	char UbootSlaVer[4]; //UBOOT从片版本
	char KernelSlaVer[4];//Kernel从片版本
	char CramfsSlaVer[4];//文件系统从片版本
	char MtdVer[4];      //MTD 版本
	char CramfsVer[4];   //文件系统 版本
}SN_FLASHVERSION,*LPSN_FLASHVERSION;
//HI3520版本包含中上述7部分版本号；HI3515中只包含4部分，其中3个从片相关的版本为全0

//-----------------------------------------
//2.IP地址结构体，48字节，为IPv6预留了足够空间，
//-----------------------------------------
typedef struct _SN_DVR_IPADDR
{		
	char sIpAddr[IPADDRESS_MAX_LEN];						//IP地址
}SN_DVR_IPADDR, *LPSN_DVR_IPADDR;



//-----------------------------------------
//3.设备信息，单字节对齐，723字节
//-----------------------------------------
#pragma pack(push, 1)
typedef struct _SN_DEVICEINFO 
{
	DWORD	cbsize;									//4,结构体大小 
	DWORD	dwVersion;								//4,设备版本  
	DWORD	wLinkPort;								//4,设备通信端口
	BYTE	byAlarmInPortCount;						//1,报警输入个数
	BYTE	byAlarmOutPortCount;					//1,报警输出个数
	BYTE	byDiskCount;							//1,硬盘个数
	BYTE	byDeviceType;							//1,设备类型，0 -- SN2008 ; 1 -- SN2004
	BYTE	byChannelCount;							//1,设备模拟通道数
	BYTE	byStartChannel;							//1,起始通道号
	BYTE	byAudioChannelCount;					//1,声音通道数
	BYTE	byIPChannelCount;						//1,数字通道数，
	//----4x3+1x8=20
	BYTE	sSerialNumber[SN_DEVICE_SERIALNO_LEN];	//1x64,设备序列号, 固定为64
	BYTE	byMacAddr[MACADDR_LEN];					//1x6,设备MAC地址，固定为6
	char	sDeviceName[DEVICE_NAME_LEN];			//1x64,设备名，固定为64
	BYTE	byRS232Num;								//1,232串口个数
	BYTE	byRS485Num;								//1,485串口个数
	BYTE	byNetworkPortNum;						//1,网络口个数
	BYTE	byDiskCtrlNum;							//1,硬盘控制器个数
	BYTE	byDecodeChans;							//1,解码路数
	BYTE	byVGANum;								//1,VGA口的个数
	BYTE	byUSBNum;								//1,USB口的个数
	BYTE	byAuxoutNum;							//1,辅口的个数
	//----64+6+64+1x8=142+20=162
	DWORD   dwSoftwareVersion;						//4,软件版本号,高16位是主版本,低16位是次版本
	DWORD	dwSoftwareBuildDate;					//4,软件生成日期,0xYYYYMMDD
	DWORD	dwDSPSoftwareVersion;					//4,DSP软件版本,高16位是主版本,低16位是次版本
	DWORD	dwDSPSoftwareBuildDate;					//4,DSP软件生成日期,0xYYYYMMDD
	DWORD	dwPanelVersion;							//4,前面板版本,高16位是主版本,低16位是次版本
	DWORD	dwHardwareVersion;						//4,硬件版本,高16位是主版本,低16位是次版本
	BYTE	ProductType[MAX_PRODUCT_TYPE_LEN];		//1x20,产品型号	
	BYTE	u8HideAreaNum;							//1,支持的遮盖区域最大数
	BYTE	u8MotionAreaNum;						//1,支持的移动侦测区域最大数
	BYTE	u8CoverAreaNum;							//1,支持的遮挡区域最大数
	BYTE	u8EmaiDestNUm;							//1,支持的邮件接受者最大数量
	BYTE	u8DDNSMaxNum;							//1,支持的最大的DDNS数量
	BYTE	bGSM;									//1,have GSM 0--no GSM 
	//---4x6+1x20+6=50+162=212
	DWORD	dwHttpPort;								//4,http端口
	DWORD	dwSinglePort;							//4,单播端口,ffserver
	DWORD	dwRPCPort;								//4,RPC 端口
	DWORD	dwDataPort;								//4,文件传输端口	
	BYTE	strGSMVersion[40];						//1x40,GSM版本信息 注意bGSM为1时 此字段才有效	
	DWORD	dwTalkport;								//4,语音对讲端口	
	BYTE	byDeviceClass;							//1,设备类 0---表示DVR,1---表示IPC,2---解码器,3---NVR
	BYTE	by3GDevNum;								//1,3G 模块的数目，为0表示不存在。为1表示有一个并且存在。
	BYTE	byWIFIDevNum;							//1,WIFI 模块的数目，为0表示不存在。为1表示有一个并且存在。
	UINT8	isGps;									//1,是否为车载DVR，0=不是，1=是
	UINT32	IsDigitMask[8];							//4x8,以位的方式标识当前通道是否为数字通道，c31c30...c0，表示对应通道的值
	INT8	FixedProductType[20];					//1x20,产品型号，用于升级文件合法性判断	
	UINT32	Manufacturers;							//4,厂家信息，1-自有,2-白牌,其它-非法值
	UINT8	SensorParamType;						//IPC衍生产品的图像参数类型 //zhangxh
	UINT8	u8VOIP;									//是否有VOIP模块			//zhangxh
	SN_FLASHVERSION flashVersion;					//Flash中各部分版本号信息	//zhangxh
	UINT8   DispScr;								//1	可以显示的屏幕数		//zhangxh
	UINT8	ScrNum[4];								//4	用来表示每一屏显示通道的大小，一共支持4屏	//zhangxh
	UINT16  MaxPixel;								//2	设备全帧率情况下，支持的分辨率的个数以D1为标准	//zhangxh
	UINT8	AudioDsp;								//1	本地支持的音频输出个数	//zhangxh
	UINT32  IsOpt;                                  //最高位取值为1表示支持走廊模式,次高位为1表示支持获取IPC参数范围
	BYTE    Reserved[349];	
}SN_DEVICEINFO, *LPSN_DEVICEINFO;	//SN_DEVICEINFO，设备基本信息，单字节对齐，定长723
#pragma pack(pop)




//-----------------------------------------
//4.区域矩形结构体(左上角坐标及宽高)，8字节
//-----------------------------------------
typedef struct _SN_DVR_SCOPE_RECT{
	WORD left;						//左上角x坐标
	WORD top;						//左上角y坐标
	WORD width;						//长
	WORD height;					//高
} SN_DVR_SCOPE_RECT, *LPSN_DVR_SCOPE_RECT;	

//-----------------------------------------
//5.预览信息结构体，12字节
//-----------------------------------------
typedef struct _PREVIEWINFO 
{
	LONG  lChannel;		//通道号,从1开始？
	HWND  hWnd;			//视频显示窗口句柄
	LONG  lLinkMode;	//最高位(31)为0表示主码流，为1表示子码流;bit0-bit2 0表示Multicast 1表示Unicast
}PREVIEWINFO, *LPPREVIEWINFO;	

//-----------------------------------------
//6.时间结构体,24字节
//-----------------------------------------
typedef struct _SN_DVR_TIME
{
	DWORD  dwYear;
	DWORD  dwMonth;
	DWORD  dwDay;
	DWORD  dwHour;
	DWORD  dwMinute;
	DWORD  dwSecond;
}SN_DVR_TIME, *LPSN_DVR_TIME;



//-----------------------------------------
//7.报警设备信息，252字节
//-----------------------------------------
typedef struct _SN_DVR_ALARMER{
	DWORD cbsize;			//结构体大小
	DWORD flag;				//这个标志每位指示下面的成员是否可用,参见前面#define SN_DVR_ALARMER.flag
	LONG  lSessionID;		//会话ID
	BYTE  sSerialNumber[SN_DEVICE_SERIALNO_LEN];//设备序列号
	DWORD  dwDeviceVersion;						//设备版本
	char  sDeviceName[DEVICE_NAME_LEN];			//设备名
	BYTE  byMacAddr[MACADDR_LEN];				//设备MAC地址
	WORD  wLinkPort;							//设备通信端口
	char  sDeviceIP[IPADDRESS_MAX_LEN];			//设备IP
	char  sSocketIP[IPADDRESS_MAX_LEN];			//报警主动上传的IP地址，本机的一个IP
	BYTE  byIpProtocol;							//Ip协议：0－IPV4；1－IPV6
}SN_DVR_ALARMER, *LPSN_DVR_ALARMER;



//-----------------------------------------
//8.文件查找条件，64字节
//-----------------------------------------
typedef struct _SN_DVR_FILECONDITION{
	LONG  lSessionID;			//会话ID
	LONG   lChannel;			//录像通道号
	DWORD  dwFileType;			//录像文件类型
	DWORD  dwIsLocked;			//录像文件是否被锁定：0－正常文件；1－锁定文件；0xff表示所有文件
	SN_DVR_TIME  tmStartTime;	//文件开始时间
	SN_DVR_TIME  tmEndTime;     //文件结束时间
}SN_DVR_FILECONDITION, *LPSN_DVR_FILECONDITION;


//-----------------------------------------
//9.文件信息结构，164字节
//-----------------------------------------
typedef struct _SN_DVR_FILEDATA{
	char strFileName[MAX_DEVICE_FILENAME_LEN];	//文件名
	int	 FileType;								//文件类型
	BYTE Protect;								//文件是否加锁保护
	DWORD dwFileSizeLow;						//文件大小低32位
	DWORD dwFileSizeHigh;						//文件大小高32位
	SN_DVR_TIME tmFileStartTime;				//文件开始时间
	SN_DVR_TIME tmFileEndTime;					//文件结束时间
}SN_DVR_FILEDATA, *LPSN_DVR_FILEDATA;



//-----------------------------------------
//10.云台协议结构体，36字节
//-----------------------------------------
typedef struct _SN_DVR_PTZ_PROTOCOL{
	DWORD  dwType;									//云台协议类型值
	BYTE  byDescribe[PTZ_PROTOCOL_DESCRIPT_LEN];	//云台协议类型文本描述
}SN_DVR_PTZ_PROTOCOL, LPSN_DVR_PTZ_PROTOCOL;


//-----------------------------------------
//11.云台协议配置结构体，7208字节
//-----------------------------------------
typedef struct _SN_DVR_PTZCFG{
	DWORD  cbsize;												//结构体大小
	DWORD  dwPtzCount;											//云台协议数量
	SN_DVR_PTZ_PROTOCOL  PtzItemList[PTZ_PROTOCOL_MAX_COUNT];	//云台协议列表
}SN_DVR_PTZCFG, *LPSN_DVR_PTZCFG;


//-----------------------------------------
//12.日志查找条件，72字节
//-----------------------------------------
typedef struct _SN_LOG_CONDITION{
	LONG  lSessionID;				//会话ID
	int	  iChannel;					//通道号
	LONG  lFindType;				//查询方式：0－全部；1－按类型；2－按时间；3－按时间和类型
	DWORD  dwLogType;				//日志类型：0－全部；1－报警；2-异常；3－操作
	DWORD	dwMinorType;			//次类型
	SN_DVR_TIME  tmStartTime;		//开始时间
	SN_DVR_TIME  tmEndTime;			//结束时间	
	BOOL  bOnlySmart;				//字段无效，是否只搜索带S.M.A.R.T信息的日志，
									//bOnlySmart为TRUE，只搜索S.M.A.R.T信息的硬盘运行日志记录。
}SN_LOG_CONDITION, *LPSN_LOG_CONDITION;



//-----------------------------------------
//13.日志信息结构体，12012字节
//-----------------------------------------
typedef struct _SN_DEVICE_LOGDATA{
	int			iLogID;
	SN_DVR_TIME  tmLogTime;						//日志记录时间
	DWORD  dwLogType;							//日志类型
	DWORD	MinorType; 							//次类型
	BYTE  sPanelUser[MAX_USERNAME_LEN];			//面板操作用户名
	BYTE  sRemoteUser[MAX_USERNAME_LEN];		//远程操作用户名
	char  strRemoteHostAddr[IPADDRESS_MAX_LEN]; //远程主机地址
	DWORD  dwParaType;							//参数类型
	DWORD  dwChannel;							//通道号
	DWORD  dwDiskNumber;						//磁盘号
	DWORD  dwAlarmInPort;						//报警输入端口
	DWORD  dwAlarmOutPort;						//报警输出端口
	DWORD  dwInfoLen;							//日志附加信息长度
	char  sInfo[LOG_INFO_LEN];					//日志附加信息
}SN_DEVICE_LOGDATA, *LPSN_DEVICE_LOGDATA;



//-----------------------------------------
//14.硬盘信息结构体，16字节
//-----------------------------------------
typedef struct _SN_DVR_DISKINFO{
	DWORD  dwVolume;						//硬盘容量 MB计
	DWORD  dwFreeSpace;						//硬盘空闲大小 MB计
	DWORD  dwHardDiskState;					//硬盘工作状况,1=满,0=OK
	BOOL   bFormated;						//1=格式化 0=未格式化
}SN_DVR_DISKINFO,*LPSN_DVR_DISKINFO;


//-----------------------------------------
//15.通道状态，788字节
//-----------------------------------------
typedef struct _SN_DVR_CHANNELSTATE{
	DWORD cbsize;							//结构体大小
	BYTE  bRecord;							//通道是否在录像：0－不录像；1－录像
	BYTE  bSignalLost;						//通道信号是否丢失	
	BYTE  bHardwareError; 					//硬件是否出错	
	DWORD  dwBitRate;						//实际bit率	
	DWORD  dwLinkNum;						//客户端连接的个数
	SN_DVR_IPADDR  struClientIP[MAX_LINK];	//这个目前不可用
	DWORD  dwIPLinkNum ;
}SN_DVR_CHANNELSTATE, LPSN_DVR_CHANNELSTATE;



//-----------------------------------------
//16.设备状态信息结构体，25768字节
//-----------------------------------------
typedef struct _SN_DEVICE_STATE{
	DWORD  dwDeviceStatic;								//设备工作状态
	SN_DVR_DISKINFO  struHardDiskStatic[MAX_DISKNUM];	//硬盘状态
	SN_DVR_CHANNELSTATE  struChanStatic[MAX_CHANNUM];	//通道状态
	BYTE  byAlarmInStatic[MAX_ALARMIN];					//报警输入状态,0=没有报警；1=有报警 
	BYTE  byAlarmOutStatic[MAX_ALARMOUT];				//报警输出状态,0=没有输出；1=有报警输出
	DWORD  dwLocalDisplay;								//本地显示状态：0=正常；1=不正常
}SN_DEVICE_STATE, *LPSN_DEVICE_STATE;


//-----------------------------------------
//17.异常信息回调结构体，60字节
//-----------------------------------------
typedef struct _SN_DVR_EXCEPTIONINFO{
	DWORD msgType;			//异常类型，1=Socket读异常，2=Socket写异常
	LONG  lSessionID;		//会话ID
	char  sDeviceIP[IPADDRESS_MAX_LEN]; //设备IP
	DWORD dwLinkPort;					//设备通信端口
}SN_DVR_EXCEPTIONINFO, *LPSN_DVR_EXCEPTIONINFO;


//-------------------------------------------------------------------------------------
//常规结构体区域end
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
//手机相关结构体区域start 
//-------------------------------------------------------------------------------------
#pragma pack(push, 1)

//-----------------------------------------
//17.其他参数，17字节
//-----------------------------------------
typedef struct	 _SN_OTHER				
{
	int 	AutoSignal;		//自动发送信号强度改变信息 1=开启,0=关闭(默认)
	char 	pwd[MAX_PWDLEN];//短信设置命令密码
	int 	Language; 		//语言,0=Chinese(默认),1=English
	int		bAlarmAll;		//总撤防布防开关,0=撤防,1=布防
}SN_OTHER,*LPSN_OTHER;		//其他参数,单字节对齐

//-----------------------------------------
//18.联系人,70字节
//-----------------------------------------
typedef struct _SN_CONTACT{
	char Name[MAX_NAMELEN];		//联系人名
	char phone[MAX_PHONELEN];	//联系人电话号码
	char email[MAX_EMAILLEN];	//联系人邮箱
}SN_CONTACT,*LPSN_ContactInfo;

//-----------------------------------------
//19.彩信中心参数配置，143字节
//-----------------------------------------
typedef struct _SN_MMSCONFIG{
	char szmmsc[MAX_MMSCLEN];  			//默认"http://mmsc.monternet.com"
	char szgatewapIp[MAX_GATEWAYLEN];  	//默认10.0.0.172
	int	 iwtp_port;  					//默认9201 
	int	 ihttp_port; 					//默认80
	char  szapn[MAX_APNLEN];            //默认cmwap
	char  szusername[MAX_USERNAMELEN]; 	//默认wap
	char  szpassword[MAX_PASSWORDLEN]; 	//默认wap
	int   mmsType;						//彩信传输方式0wap, 1http, 2:MMI接口 默认1
	unsigned char iMNC; 				//运营商名称 0移动 1联通  2其他   默认0
}SN_MMSCONFIG,*LPSN_MMSConfigInfo;
//-----------------------------------------
//20.抓拍图像配置，12字节
//-----------------------------------------
typedef struct _SN_IMG_PARAM
{
	int quality;		//图片质量,[1,5],默认=3,1=最高,2=较高,3=中,4=较低,5=最低
	int alert_img_count;//报警发送张数,[2-8],默认取5,如果是大图片，固定取2
	int interval;		//拍照间隔，间隔值3~100，单位为100ms，默认值为5
}SN_IMG_PARAM,*LPSN_IMG_PARAM;

//-----------------------------------------
//21.报警配置，236字节
//-----------------------------------------
typedef struct _SN_ALARM_PARAM
{
	int bEnable;	//是否布防,0=撤防(默认),1=设防,
	int bSendSms;	//报警是否发送短信,0=不发送(默认),1=发短信  		
	int bSendMms;	//报警是否发送彩信,0=不发送(默认),1=发彩信
	int bCC;		//报警是否语音监听,0=不监听(默认),1=监听
	int bSendMail;	//是否发送到邮箱,  0=不发送(默认),1=发送
	int bCallHost;	//报警是否呼叫主人,0=不拨打(默认),1=拨打电话
	int Listen[MAX_AUDIO_LISTEN_NUM];	//语音监听,对应id,0=off(默认),1=开
	int Capture[MAX_CHANNUM];			//抓图关联通道，对应id，0=off（默认）,1=开
	char AlarmName[MAX_NAMELEN];		//报警名称对应原来的des描述符
}SN_ALARM_PARAM,*LPSN_ALARM_PARAM;

//-----------------------------------------
//22.定时参数，16字节
//-----------------------------------------
typedef struct _SN_TIMEPERIOD
{
	int startHour;
	int StartMin;
	int endHour;
	int endMin;
}SN_TIMEPERIOD,*LPSN_TIMEPERIOD;//定时参数

//-----------------------------------------
//23.自动布防，82字节
//-----------------------------------------
typedef struct _SN_AUTONABLE
{
	int enable;
	SN_TIMEPERIOD Period[3];
	char period_t[6][5];
}SN_AUTOENABLE,*LPSN_AUTOENABLE;

//GSM V2版参数
//-----------------------------------------
//24.定时彩信/定时布防，56字节
//-----------------------------------------
typedef struct _SN_T_TIMING
{
	unsigned char enable;		//是否启用,0=关闭,1=启用
	unsigned char day;			//日期模式,[0,8]
	SN_TIMEPERIOD Period[3];	//时段
	unsigned short interval[3];	//时间间隔>=10,单位:分钟,定时彩信有用,定时布防不用 
}SN_T_TIMING, *LPSN_T_TIMING;	//定时功能,定时布防和定时彩信共用

//-----------------------------------------
//25.自动布防的一周时间，48字节
//-----------------------------------------
typedef struct _SN_T_AUTO_WEEK
{
	SN_TIMEPERIOD Period[3];	   //时段
}SN_T_AUTO_WEEK, *LPSN_T_AUTO_WEEK;//自动布防的一周时间

//-----------------------------------------
//26.自动布防的参数,337字节，定时布防/报警布防
//-----------------------------------------
typedef struct _SN_T_AUTO
{
	unsigned char enable;		//是否启用 0关闭 1启用
	SN_T_AUTO_WEEK   setTime[7];//自动布防的一周时间段的设置
}SN_T_AUTO, *LPSN_T_AUTO;		//自动布防的参数

//-----------------------------------------
//27.GSM网络参数，68字节
//-----------------------------------------
typedef struct _SN_GSM_NETPARA
{
	int bHeartEnable;	//0=关闭心跳,1=启动心跳,目前不可配置
	int HeartInterval;	//心跳间隔,单位分钟,默认10,目前不可配置
	char apn[20];		//APN 默认cmnet 国内与彩信用的相同，国外有些地方是不同的
	char user[20];		//用户名
	char pwd[20];		//密码
}SN_GSM_NETPARA, *LPSN_GSM_NETPARA;	//GSM网络参数

//-----------------------------------------
//28.工作模式 SN_GSMWorkMode，1字节
//-----------------------------------------
typedef struct _SN_GSMWorkMode 
{
	unsigned char mode;		//0=普通版,1=网络版
}SN_GSMWorkMode, *LPSN_GSMWorkMode;

//-----------------------------------------
//29.工作模式 SN_GSMWorkMode，68字节
//-----------------------------------------
typedef struct _SN_GSM_HIGHSETTING
{
	int PinLockMode;			//锁卡模式,0不锁卡,1锁固定pin,2锁随机pin
	char PinCode[MAX_PINLEN];	//设置的pin
	char DefaultPin[MAX_PINLEN];//默认原始pin(一般是1234)
	int MncLockMode;			//锁运营商模式,0不锁,1移动 2联通 3移动和联通
	char MncCode[MAX_MNCLEN];
	int ImsiLockMode;			//锁机,0不锁,1锁
	char ImsiCode[MAX_IMSILEN];
}SN_GSM_HIGHSETTING, *LPSN_GSM_HIGHSETTING;

//-----------------------------------------
//30.服务端配置，85字节
//-----------------------------------------
typedef struct _SN_T_SERVER_CFG{
	unsigned char active;		//1=已经激活,0=未激活
	unsigned char EID[10];		//设备ID,设备激活时由平台下发,识别设备的唯一性16位的字符串?
	unsigned char gateIP[32];	//后台IP,设备激活时由平台下发 
	unsigned char port[20];		//端口号,设备激活时由平台下发
	unsigned char serv_num[20]; //客服号,设备激活时由平台下发 平台以此卡号发送命令短信
	unsigned char bHeartEnable; //心跳包是否启用, 0=关闭,1=启用(默认)
	unsigned char HeartInterval;//心跳间隔时间,单位:分钟,默认15,现在平台做成固定值
}SN_T_SERVER_CFG, *LPSN_T_SERVER_CFG;

//-----------------------------------------
//31.APN参数，60字节
//-----------------------------------------
typedef struct _SN_T_NETAPN
{
	char apn[20];	//APN 默认cmnet 国内与彩信用的相同，国外有些地方是不同的
	char user[20];	//用户名
	char pwd[20];	//密码
}SN_T_NETAPN, *LPSN_T_NETAPN;

//-----------------------------------------
//32.主机参数，6字节不用
//-----------------------------------------
typedef struct _SN_T_MAIN_CFG
{
	unsigned char bAlarmSms;
	unsigned char bAlarmMMS;
	unsigned char bAlarmCall;
	unsigned char bVersion;		// 广告牌版0，基站版1 
	unsigned char temp;			//温度
	unsigned char funcversion;	//功能版本,2=网络版
}SN_T_MAIN_CFG, *LPSN_T_MAIN_CFG;


//-----------------------------------------
//33.?，31226字节
//-----------------------------------------
typedef struct _SN_GSM_TOTAL_SETTINGS
{
	DWORD		dwFlags;	//位标志,用于判断以下两组成员字段有效性,参见SN_GSM_TOTAL_SETTINGS.dwFlags
	//SN_GSM_VERSION_FLAGS_NORMAL 以下成员有效
	SN_CONTACT owner[MAX_OWNERCNT];			//0:主人号码,1~10：家人号码
	SN_ALARM_PARAM key_video[MAX_CHANNUM];	//摄像头告警开关
	SN_ALARM_PARAM key_input[MAX_ALARMIN];	//输入告警开关
	SN_IMG_PARAM img_para;					//拍照、图片效果参数
	SN_GSM_HIGHSETTING highsetting;			//高级参数
	SN_MMSCONFIG MmsSetting;				//彩信参数
	SN_AUTOENABLE Autoenable[8];			//定时参数
	SN_OTHER OtherSetting;					//其他参数
	unsigned char Reverse[REVERSEMAX];		//预留参数
	char version[64];						//保存版本信息，如果代码版本与保存的版本不对，格式化数据
	//SN_GSM_VERSION_FLAGS_NETWORK 以下成员有效
	SN_T_AUTO   Autoen_Video[MAX_CHANNUM];	//每个子机的自动布防参数独立
	SN_T_AUTO   Autoen_input[MAX_ALARMIN];	//每个输入信号的参数独立，报警输入的时间布防
	SN_T_TIMING AutoMms[MAX_CHANNUM];		//定时彩信 每个子机的参数独立
	SN_T_SERVER_CFG ServerSetting;			//平台参数
	SN_T_NETAPN NetApn;						//网络版APN
	SN_T_MAIN_CFG maincfg;					//主机参数，不用
	unsigned char  bNetServer;				//网络版标志,0=单机版,1=网络版
	int netLogin;							//标记网络版是否登录 0=未登录,1=已登录
	char imei[30];							//模块软件的IMEI号
}SN_GSM_TOTAL_SETTINGS, *LPSN_GSM_TOTAL_SETTINGS;

#pragma pack(pop)
//-------------------------------------------------------------------------------------
//手机相关结构体区域end
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//结构体区域start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//35.?，4字节
//-----------------------------------------
typedef struct _PREVIEW_EXCEPTION_ST 
{
	LONG	lPrevHandle;
}PREVIEW_EXCEPTION_ST, *LPPREVIEW_EXCEPTION_ST;
//-----------------------------------------
//36.?，8字节
//-----------------------------------------
typedef struct _CONNECTION_BROKEN_ST {
	LONG	lSessionID;
	BOOL	bReconnect;		//是否进行重新连接 默认重连
}CONNECTION_BROKEN_ST, *LPCONNECTION_BROKEN_ST;


//-----------------------------------------
//37.设备状态通知，16字节,对应了RPC协议
//-----------------------------------------
typedef struct _DEVICE_NOTIFY_ST  {
	LONG	lSessionID;
	DWORD	dwNotifyCode;	//设备通知码,参见DEVICE_NOTIFY_ST.dwNotifyCode
	char	*pNewIP;		//新IP,仅当类型为DEVICE_NOTIFY_DEVICE_IP_CHANGE有效
	BOOL	bAutoIP;		//是否自动获取IP
}DEVICE_NOTIFY_ST, *LPDEVICE_NOTIFY_ST;

//-----------------------------------------
//38.重连结果报告，8字节
//-----------------------------------------
typedef struct _RECONNECT_REPORT_ST {
	LONG	lSessionID;		//会话ID
	DWORD	dwResult;		//0=成功,oth=失败
}RECONNECT_REPORT_ST, *LPRECONNECT_REPORT_ST;

//-----------------------------------------
//39.?，8字节
//-----------------------------------------
typedef struct _SESSION_PREVIEW_REPLAY_ST {
	LONG	lSessionID;		//会话ID
	LONG	lPreviewHandle;	//预览句柄
}SESSION_PREVIEW_REPLAY_ST, *PSESSION_PREVIEW_REPLAY_ST;

//-----------------------------------------
//40.?，8字节
//-----------------------------------------
typedef struct _SESSION_TALKBACK_REPLAY_ST {
	LONG	lSessionID;		//会话ID
	LONG	lVoiceComHandle;//对讲句柄
}SESSION_TALKBACK_REPLAY_ST, *PSESSION_TALKBACK_REPLAY_ST;
//-----------------------------------------
//41.?，8字节
//-----------------------------------------
typedef struct _SESSION_REMOTEPLAYBACK_REPLAY_ST {
	LONG	lSessionID;				// 会话ID 
	LONG	lRemotePlayBackHandle;	// 远程回放句柄 
}SESSION_REMOTEPLAYBACK_REPLAY_ST, *PSESSION_REMOTEPLAYBACK_REPLAY_ST;


//-----------------------------------------
//42.位图结构体，56字节，用于幻灯片预览本地文件
//-----------------------------------------
typedef struct _BitmapPict {
	BITMAPINFO	BitmapInfo;		//位图信息
	void		*lpDIBbits;		//位图数据
	LONG		Width;			//位图宽
	LONG		Height;			//位图高
}BitmapPict, *PBitmapPict;
//-----------------------------------------
//43.帧节点结构体,16字节，用于保存关键帧索引和时间标签
//-----------------------------------------
typedef	struct _FrameNode {	
	int			iFrameIndex; //关键帧索引，调用SN_File_GetSlidePictureByIndex时需要传递这个值给第三个参数	
	DWORD		dwFrameTime; //该帧时间,以秒计	
	__int64		i64SeekPos;	 //定位
}FrameNode, *PFrameNode;
//-----------------------------------------
//44.视频信息，20字节
//-----------------------------------------
typedef struct _VideoInfo{	
	DWORD	Duration;		//视频长度，以秒计	
	LONG	Width;			//画面宽	
	LONG	Height;			//画面高	
	int		iFrameCount;	//关键帧数量 即下面数组长度	
	FrameNode	*FrameList;	//关键帧数组
}VideoInfo, *PVideoInfo;
//-----------------------------------------
//45.设备参数信息,180字节，DeviceParameterInformation
//----------------------------------------- 
typedef struct _DEVICE_PARAMETER_INFO{
	DWORD dwSize;								//?
	BYTE sDVRName[DEVICE_NAME_LEN];				//DVR名称
	DWORD dwDVRID;								//DVR ID,用于遥控器
	DWORD dwRecycleRecord;						//循环写入,0:关闭; 1:开启	
	BYTE sSerialNumber[SN_DEVICE_SERIALNO_LEN]; //序列号
	DWORD dwSoftwareVersion;		//软件版本号,高16位是主版本,低16位是次版本
	DWORD dwSoftwareBuildDate;		//软件生成日期,0xYYYYMMDD 值非10进制，而是16进制，如2012=8210
	DWORD dwDSPSoftwareVersion;		//DSP软件版本,高16位是主版本,低16位是次版本
	DWORD dwDSPSoftwareBuildDate;	//DSP软件生成日期,0xYYYYMMDD
	DWORD dwPanelVersion;			//前面板版本,高16位是主版本,低16位是次版本
	DWORD dwHardwareVersion;		//硬件版本,高16位是主版本,低16位是次版本
	BYTE byAlarmInPortNum;			//DVR报警输入个数
	BYTE byAlarmOutPortNum;			//DVR报警输出个数
	BYTE byRS232Num;				//DVR 232串口个数
	BYTE byRS485Num;				//DVR 485串口个数
	BYTE byNetworkPortNum;			//网络口个数
	BYTE byDiskCtrlNum;				//DVR 硬盘控制器个数
	BYTE byDiskNum;					//DVR 硬盘个数
	BYTE byDVRType;					//设备类型，0 -- SN2008 ; 1 -- SN2004
	BYTE byChanNum;					//DVR 通道个数
	BYTE byStartChan;				//起始通道号,例如DVR - 1
	BYTE byDecodeChans;				//DVR 解码路数
	BYTE byVGANum;					//VGA口的个数
	BYTE byUSBNum;					//USB口的个数
	BYTE byAuxoutNum;				//辅口的个数
	BYTE byAudioNum;				//语音口的个数
	BYTE byIPChanNum;				//最大数字通道数
}DEVICE_PARAMETER_INFO, *LPDEVICE_PARAMETER_INFO;


//-----------------------------------------
//46.以太网信息数据结构,108字节
//----------------------------------------- 
typedef struct _SN_DVR_ETHERNET
{
	SN_DVR_IPADDR	struDVRIP;      //DVR IP地址
	SN_DVR_IPADDR	struDVRIPMask;	//DVR IP地址掩码
	DWORD	dwNetInterface;   		//网络接口0-auto, 10M半双工，10M全双工，100M半双工，100M全双工
	WORD	wMTU;					//默认1500。 目前不支持配置
	BYTE	byMACAddr[MACADDR_LEN];	//物理地址
}SN_DVR_ETHERNET, *LPSN_DVR_ETHERNET;

//-----------------------------------------
//47.PPPoE结构,84字节
//-----------------------------------------
typedef struct _SN_DVR_PPPOE_INFO
{
	DWORD	dwPPPOE;										//0-不启用,1-启用
	BYTE	sPPPoEUser[DEVICE_NAME_LEN];					//PPPoE用户名
	BYTE	sPPPoEPassword[PASSWD_LEN];						//PPPoE密码	
}SN_DVR_PPPOE_INFO, *LPSN_DVR_PPPOE_INFO;

//-----------------------------------------
//48.设备网络参数信息,620+12字节，DeviceNetParameterInformation
//-----------------------------------------
typedef struct  _DEVICE_NET_PARAMETER_INFO
{	
	DWORD dwSize;
	SN_DVR_ETHERNET	struEtherNet[MAX_ETHERNET];	//以太网口
	SN_DVR_IPADDR	struAlarmHostIpAddr;		//报警主机IP地址
	WORD	wAlarmHostIpPort;					//报警主机端口号 
	BYTE    byUseDhcp;                          //是否启用DHCP 0xff-无效 0-不启用 1-启用
	BYTE	byAutoGetDNS;						//是否自动获取DNS
	SN_DVR_IPADDR	struDnsServer1IpAddr;		//域名服务器1的IP地址 
	SN_DVR_IPADDR	struDnsServer2IpAddr;		//域名服务器2的IP地址 
	BYTE	byIpResolver[MAX_DOMAIN_NAME];		//目前不支持 IP解析服务器域名或IP地址 
	WORD	wIpResolverPort;					//目前不支持 IP解析服务器端口号

	WORD	wHttpPortNo;						// HTTP端口号
	WORD	wDVRPort;							//端口号
	WORD	wSinglePort; 						//单播端口
	WORD	wDataPort;    						//数据端口文件传输使用
	WORD	wReserved1; 						//语音对讲端口
	WORD	wReserved2;							//保留端口2
	WORD 	wReserved3;							//保留端口3
	WORD 	wReserved4;							//保留端口4

	SN_DVR_IPADDR	struMulticastIpAddr;		//多播组地址 
	SN_DVR_IPADDR	struGatewayIpAddr;			//网关地址 
	SN_DVR_PPPOE_INFO struPPPoE;				//PPPoE信息
} DEVICE_NET_PARAMETER_INFO, *LPDEVICE_NET_PARAMETER_INFO;



//-----------------------------------------
//49.视频画面参数，6字节
//-----------------------------------------
typedef struct _SN_DVR_IMAGE_PARAM
{
	BYTE byBrightness;  	//亮度,0-255
	BYTE byContrast;    	//对比度,0-255	
	BYTE bySaturation;  	//饱和度,0-255
	BYTE byHue;    			//色调,0-255
	BYTE xAdjust;			//横向移位
	BYTE yAdjust ;			//纵向移位
}SN_DVR_IMAGE_PARAM, *LPSN_DVR_IMAGE_PARAM;


enum SN_Alarm_Shield_Time_EM
{
	SN_Disable_EM = 0,		//未开启
	SN_Time_10s_EM,			//10秒
	SN_Time_20s_EM,			//20秒
	SN_Time_30s_EM,			//30秒
	SN_Time_1min_EM,		//1分钟
	SN_Time_2min_EM,		//2分钟
	SN_Time_5min_EM,		//5分钟
	SN_Time_10min_EM,		//10分钟
	SN_Time_30min_EM,		//30分钟
};
typedef struct _SN_DVR_ALARM_IN_SHIELD
{
	unsigned char AlmShieldTime;	// 报警屏蔽时间, SN_Alarm_Shield_Time_EM
	unsigned char CaptureDelay;		// 报警抓图延时,0S--10S
}SN_DVR_ALARM_IN_SHIELD,*LPSN_DVR_ALARM_IN_SHIELD;

//-----------------------------------------
//50.报警和异常处理结构，20字节
//-----------------------------------------
typedef struct _SN_DVR_EXCEPTIONHANDLE
{
	DWORD	dwHandleType;	//处理方式,0x00=无响应,0x01=弹出报警画面,0x02=声音警告,
							//         0x04=邮件通知,0x08=上传中心,0x10=触发报警输出,0x20=上传图片
	BYTE	byRelAlarmOut[MAX_ALARMOUT]; //报警触发的输出通道,1=表示触发该通道输出
	BYTE	bSmsAlm;		// 是否是启用 1-启用 0-关闭,以8位为计:1位:短信报警，2位:电话报警
}SN_DVR_EXCEPTIONHANDLE, *LPSN_DVR_EXCEPTIONHANDLE;

//-----------------------------------------
//51.时间段(子结构)，4字节
//-----------------------------------------
typedef struct _SN_DVR_SCHEDTIME
{
	BYTE byStartHour;	//开始时间,小时
	BYTE byStartMin;	//开始时间,分		
	BYTE byStopHour;	//结束时间,小时
	BYTE byStopMin;		//结束时间,分
}SN_DVR_SCHEDTIME, *LPSN_DVR_SCHEDTIME;

//-----------------------------------------
//52.时间段（V2版本），48字节
//-----------------------------------------
typedef struct  _SN_DVR_SCHEDTIME_V2
{
	BYTE bTimeSel[48];			//1=该半小时被选中,0=该半小时没有被选中
} SN_DVR_SCHEDTIME_V2, *LPSN_DVR_SCHEDTIME_V2;

//-----------------------------------------
//53.抓怕参数，3字节
//-----------------------------------------
typedef struct _SN_DVR_SNAP_PIC
{
	BYTE bSnap;			//是否抓拍
	BYTE SnapNum;		//抓拍数量
	BYTE SnapInterval;	//抓拍间隔
}SN_DVR_SNAP_PIC, *LPSN_DVR_SNAP_PIC;

//-----------------------------------------
//54.信号丢失报警结构，248字节
//-----------------------------------------
typedef struct _SN_DVR_SIGNALLOST
{
	BYTE byEnableHandleSignalLost;										//是否处理信号丢失报警 
	SN_DVR_EXCEPTIONHANDLE strSignalLostHandleType;						//处理方式 
	SN_DVR_SCHEDTIME struAlarmTime[MAX_SCHEDULE_DAYS][MAX_TIMESEGMENT];	//布防时间
}SN_DVR_SIGNALLOST, *LPSN_DVR_SIGNALLOST;


//-----------------------------------------
//55.信号丢失报警结构(V2版本)，528字节
//-----------------------------------------
typedef struct  _SN_DVR_SIGNALLOST_V2
{
	BYTE	byEnableHandleSignalLost;					 //是否启用视频丢失报警   1-开启
	SN_DVR_EXCEPTIONHANDLE strSignalLostHandleType;		 //视频丢失报警处理方式
	SN_DVR_SCHEDTIME_V2 struAlarmTime[MAX_SCHEDULE_DAYS];//视频丢失布防时间
	BYTE byTrigChannel[MAX_CHANNUM];    //联动的录像通道,1-联动选中通道
	BYTE byRcdKeepTime;					//录像保护时间,0=永久保存,1=10天,2=20天,3=30天
	BYTE bAlarmRcd;						//是否录像联动,1=联动,0=不联动	
	BYTE bEnablePTZ;					//云台联动,报警使能
	BYTE byPTZLinkage[MAX_CHANNUM];     //云台联动,预置点有效 0-不设置 1-预置点有效 2-巡航有效
	BYTE byPreSetPoint[MAX_CHANNUM];    //云台联动,当前云台的预置点
	BYTE byCruise[MAX_CHANNUM];         //云台联动,当前云台的巡航号
	BYTE byLocus[MAX_CHANNUM];			//云台联动,当前云台的轨迹	
	SN_DVR_SNAP_PIC struSnap;			//云台联动,抓拍选项

	unsigned char CaptureDelay;			// 报警抓图延时,0S--10S 

	BOOLEAN bMMS;						//彩信报警是否是启用 1-启用 0-关闭
	BOOLEAN bSMS;						//是否是启用 1-启用 0-关闭,以8位为计:1位:短信报警，2位:电话报警

}SN_DVR_SIGNALLOST_V2, *LPSN_DVR_SIGNALLOST_V2;     


//-----------------------------------------
//56.移动侦测结构，408字节
//-----------------------------------------
typedef struct _SN_DVR_MOTIONDETECT
{
	SN_DVR_SCOPE_RECT MotionScope[MAX_MOTION_AREA];		//侦测区域 具体多少个区域详见设备信息结构体
	BYTE byMotionSensitive;								//移动侦测灵敏度, [0,5],越高越灵敏,oxff关闭
	BYTE byEnableHandleMotion;							//是否处理移动侦测，0=否，1=是 
	BYTE byPrecision;									//目前支持0值,宏块大小: 0=16*16, 1=32*32, 2=64*64 ... 	
	SN_DVR_EXCEPTIONHANDLE struMotionHandleType;		//处理方式 
	SN_DVR_SCHEDTIME struAlarmTime[MAX_SCHEDULE_DAYS][MAX_TIMESEGMENT]; //布防时间
	BYTE byRelRecordChan[MAX_CHANNUM];					// 统一放在处理方式里面了 报警触发的录象通道
}SN_DVR_MOTIONDETECT, *LPSN_DVR_MOTIONDETECT;

//-----------------------------------------
//57.移动侦测结构 V2版本，656字节
//-----------------------------------------
typedef struct  _SN_DVR_MOTIONDETECT_V2
{
	SN_DVR_SCOPE_RECT MotionScope[MAX_MOTION_AREA];	 //动测区域选择
	BYTE byMotionSensitive;							 //移动侦测灵敏度选择
	BYTE byEnableHandleMotion;						 //是否移动侦测,0=不开启,1=开启
	BYTE byPrecision;								 //目前支持0值,移动侦测算法: 0--16*16, 1--32*32, 2--64*64 ... 
	SN_DVR_EXCEPTIONHANDLE struMotionHandleType;	 //移动侦测报警处理方式
	SN_DVR_SCHEDTIME_V2 struAlarmTime[MAX_SCHEDULE_DAYS];//动测布防时间
	BYTE byRelRecordChan[MAX_CHANNUM];	//联动的录像通道,1=联动选中通道
	BYTE byRcdKeepTime;					//录像保护时间,0=永久保存,1=10天,2=20天,3=30天
	BYTE bAlarmRcd;						//是否录像联动,1=联动 0=不联动	
	BYTE bEnablePTZ;					//云台联动,报警使能
	BYTE byPTZLinkage[MAX_CHANNUM];     //云台预置点有效 0=不设置,1=预置点有效,2=巡航有效
	BYTE byPreSetPoint[MAX_CHANNUM];    //当前云台的预置点
	BYTE byCruise[MAX_CHANNUM];         //当前云台的巡航号
	BYTE byLocus[MAX_CHANNUM];			//当前云台的轨迹	
	SN_DVR_SNAP_PIC struSnap;			//抓拍选项
	SN_DVR_ALARM_IN_SHIELD struAlarmInShield;		//报警屏蔽

	BOOLEAN bMMS;						//彩信报警是否是启用 1-启用 0-关闭
	BOOLEAN bSMS;						//是否是启用 1-启用 0-关闭,以8位为计:1位:短信报警，2位:电话报警

}SN_DVR_MOTIONDETECT_V2, *LPSN_DVR_MOTIONDETECT_V2; //对应每个通道 记录数=通道数

//-----------------------------------------
//58.遮挡报警,376字节，line2676
//-----------------------------------------
typedef struct _SN_DVR_COVERALARM
{
	BYTE	byEnableCoverAlarm;							 //是否启动遮挡报警 ,0-否,1-开启
	BYTE    byCoverAlarmSensitive;						 //视频遮挡灵敏度选择
	SN_DVR_SCOPE_RECT	CoverAlarmArea[MAX_COVER_AREA];	 //遮挡区域 具体区域数目详见设备信息结构体
	SN_DVR_EXCEPTIONHANDLE strCoverAlarmHandleType;		 //处理方式
	SN_DVR_SCHEDTIME struCoverAlarmTime[MAX_SCHEDULE_DAYS][MAX_TIMESEGMENT];//布防时间
}SN_DVR_COVERALARM, *LPSN_DVR_COVERALARM;

//-----------------------------------------
//59.遮挡报警结构体,656字节，V2版本,对应每个通道 记录数=通道数
//-----------------------------------------
typedef struct  _SN_DVR_COVERALARM_V2
{
	BYTE byEnableCoverAlarm;							//是否启动视频遮挡报警   1-开启
	BYTE byCoverAlarmSensitive;							//视频遮挡灵敏度选择
	SN_DVR_SCOPE_RECT CoverAlarmArea[MAX_COVER_AREA];	//视频遮挡侦测区域选择
	SN_DVR_EXCEPTIONHANDLE strCoverAlarmHandleType;		//视频遮挡报警处理方式
	SN_DVR_SCHEDTIME_V2 struCoverAlarmTime[MAX_SCHEDULE_DAYS];//视频遮挡报警布防时间
	BYTE byTrigChannel[MAX_CHANNUM];	//联动的录像通道,1=联动选中通道
	BYTE byRcdKeepTime;					//录像保护时间,0=永久保存,1=10天,2=20天,3=30天
	BYTE bAlarmRcd;						//是否录像联动,1=联动,0=不联动	
	BYTE bEnablePTZ;					//云台联动报警使能
	BYTE byPTZLinkage[MAX_CHANNUM];     //云台预置点有效,0=不设置,1=预置点有效,2=巡航有效
	BYTE byPreSetPoint[MAX_CHANNUM];    //当前云台的预置点
	BYTE byCruise[MAX_CHANNUM];         //当前云台的巡航号
	BYTE byLocus[MAX_CHANNUM];			//当前云台的轨迹	
	SN_DVR_SNAP_PIC struSnap;			//抓拍选项
}SN_DVR_COVERALARM_V2, *LPSN_DVR_COVERALARM_V2;  


//-----------------------------------------
//60.屏蔽，132字节
//-----------------------------------------
typedef struct _SN_DVR_AREAHIDE {	
	WORD  wEnableHide;								//是否启动屏蔽 ,0-否,1-是
	WORD  wHideNum;									//屏蔽区域数
	SN_DVR_SCOPE_RECT	HideArea[MAX_HIDE_AREA];	//屏蔽区域,具体区域数目详见设备信息结构体
}SN_DVR_AREAHIDE, *LPSN_DVR_AREAHIDE;

//-----------------------------------------
//61.设备图像参数信息,1264字节,DevicePictureParameterInformation，line2755   
//	byOSDType
//		 0: XXXX-XX-XX 年月日 
//		 1: XX-XX-XXXX 月日年 
//		 2: XXXX年XX月XX日 
//		 3: XX月XX日XXXX年 
//		 4: XX-XX-XXXX 日月年
//		 5: XX日XX月XXXX年 
//	byOSDAttrib
//		 0: 不显示OSD 
//		 1: 透明,闪烁 
//		 2: 透明,不闪烁 
//		 3: 闪烁,不透明 
//		 4: 不透明,不闪烁 
//-----------------------------------------
typedef struct _DEVICE_PICTURE_PARAMETER_INFORMATION {
	DWORD dwSize;
	BYTE sChanName[DEVICE_NAME_LEN];
	DWORD dwVideoFormat;					//视频制式,1=NTSC,2=PAL,目前这个参数不支持
	SN_DVR_IMAGE_PARAM struImageParam;		//视频画面参数	
	DWORD dwShowChanName;					//预览是否显示通道名称,0=不显示,1=显示 区域大小720*480->16*12
	WORD wShowNameTopLeftX;					//通道名称显示位置的x坐标 
	WORD wShowNameTopLeftY;					//通道名称显示位置的y坐标 	
	SN_DVR_SIGNALLOST struSignalLost;		//视频信号丢失报警	
	SN_DVR_MOTIONDETECT struMotionDetect;	//移动侦测	
	SN_DVR_COVERALARM struCoverAlarm;		//遮挡报警	
	SN_DVR_AREAHIDE struAreaHider;			//区域屏蔽	
	DWORD dwShowOsd;						//预览是否显示OSD,0=不显示,1=显示,区域大小704*576
	WORD wOSDTopLeftX;						//OSD的x坐标 
	WORD wOSDTopLeftY;						//OSD的y坐标 
	BYTE byOSDType;							//OSD类型(主要是年月日格式),参见上面注释	
	BYTE byDispWeek;						//是否显示星期 
	BYTE byOSDAttrib;						//OSD透明闪烁属性
	BYTE byHourOSDType;						//OSD小时制:0=24小时制,1=12小时制,这个参数不支持  
}DEVICE_PICTURE_PARAMETER_INFORMATION  , *LPDEVICE_PICTURE_PARAMETER_INFORMATION  ;



//-----------------------------------------
//62.设备图像参数信息 V2版本,2072字节，DevicePictureParameterInformationV2   
//-----------------------------------------
//byOSDType
//	0: XXXX-XX-XX 年月日 
//	1: XX-XX-XXXX 月日年 
//	2: XXXX年XX月XX日 
//	3: XX月XX日XXXX年 
//	4: XX-XX-XXXX 日月年
//	5: XX日XX月XXXX年 
//byOSDAttrib
//	0: 不显示OSD 
//	1: 透明,闪烁 
//	2: 透明,不闪烁 
//	3: 闪烁,不透明 
//	4: 不透明,不闪烁 
typedef struct _DEVICE_PICTURE_PARAMETER_INFORMATION_V2  {
	DWORD dwSize;
	BYTE sChanName[DEVICE_NAME_LEN];
	DWORD dwVideoFormat;					//目前这个参数不支持 只读 视频制式 1=NTSC 2=PAL
	SN_DVR_IMAGE_PARAM struImageParam;		//视频画面参数
	DWORD dwShowChanName;					//预览是否显示通道名称,0=不显示,1=显示 区域大小720*480->16*12
	WORD wShowNameTopLeftX;					//通道名称显示位置的x坐标 
	WORD wShowNameTopLeftY;					//通道名称显示位置的y坐标 
	SN_DVR_SIGNALLOST_V2 struSignalLost;	//视频信号丢失报警
	SN_DVR_MOTIONDETECT_V2 struMotionDetect;//移动侦测
	SN_DVR_COVERALARM_V2 struCoverAlarm;	//遮挡报警
	SN_DVR_AREAHIDE struAreaHider;			//区域屏蔽
	DWORD dwShowOsd;				// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				// OSD的x坐标 
	WORD wOSDTopLeftY;				// OSD的y坐标 
	BYTE byOSDType;					// OSD类型(主要是年月日格式),参见上面注释
	BYTE byDispWeek;				// 是否显示星期 
	BYTE byOSDAttrib;				// OSD透明闪烁属性,参见上面注释
	BYTE byHourOSDType;				// 这个参数不支持 OSD小时制:0-24小时制,1-12小时制
	WORD wScancodePositionX;		// 条形码显示位置x坐标 SN6004有此功能,-1表示该设备无此功能
	WORD wScancodePositionY;		// 条形码显示位置y坐标 SN6004有此功能,-1表示该设备无此功能
	BYTE ScancodeDsp;				// 显示条形码 SN6004有此功能,-1表示该设备无此功能
}DEVICE_PICTURE_PARAMETER_INFORMATION_V2  , *LPDEVICE_PICTURE_PARAMETER_INFORMATION_V2;
//当主码流byStreamType取值为StreamTypeFlag,说明当前设置子码流;当子码流byStreamType取值为StreamTypeFlag,说明当前设置主码流
#define StreamTypeFlag  0xFF    //NVR录像配置主码流和子码流标识



//-----------------------------------------
//63.码流压缩参数，16字节
//dwVideoBitrate
//-----------------------------------------
//码流压缩参数
typedef struct _SN_DVR_COMPRESSION_INFO
{
	BYTE byStreamType;		//码流类型   0-复合流   1-视频流
	BYTE byResolution;  	//分辨率_4CIF = 0,_DCIF = 1, _2CIF = 2 ,_CIF = 3, _QCIF = 4, 720P = 5, UXGA = 6, _960H=7, _SXGA=8, _120W=9, _160W=10, _1080P=11, _3M=12
	BYTE byBitrateType;		//码率类型 0:变码率1:定码率，
	BYTE byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差
	DWORD dwVideoBitrate; 	//视频码率 0-32,1-48,2-64,3-80, 4-96, 5-128, 6-160, 7-192, 8-224,9- 256,10- 320,11- 384,12- 448,13- 512, 14-640,15- 768,16- 896, 17-1024, 18-1280,19- 1536,20- 1792,21- 2048,22-4096k,(720P)23-6144K,(720P)24-8192K,25-8192K, 26-12288K, 27-16384K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K 
	//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值。
	DWORD dwVideoFrameRate;	//帧率 0-全帧率(N制30帧，P制25帧); 1-22; 2-20 3-18fps,4-_16fps,_15fps,_12fps,_10fps,_8fps,_6fps,_4fps,_2fps,_1fps,_25fps
	WORD  wIntervalFrameI;  //I帧间隔 此参数不支持

	BYTE  byIntervalBPFrame;//这个参数不支持
}SN_DVR_COMPRESSION_INFO, *LPSN_DVR_COMPRESSION_INFO;

//-----------------------------------------
//64.通道压缩参数,52字节，DeviceCompressionParameterInformation   
//-----------------------------------------
typedef struct _DEVICE_COMPRESSION_PARMATER_INFORMATION 
{
	DWORD dwSize;
	SN_DVR_COMPRESSION_INFO struNormHighRecordPara;    //录像 
	SN_DVR_COMPRESSION_INFO struEventRecordPara;       //事件触发压缩参数 SN6008 SN6004该参数无效
	SN_DVR_COMPRESSION_INFO struNetPara;               //网传子码流
}DEVICE_COMPRESSION_PARMATER_INFORMATION , *LPDEVICE_COMPRESSION_PARMATER_INFORMATION ;

//-----------------------------------------
//65.时间段录像参数配置(子结构)，5字节
//byRecordType
//		0=定时录像，1=移动侦测，2=报警录像,3=动测||报警
//		4=动测&报警, 5=命令触发, 6=手动录像
//-----------------------------------------
typedef struct _SN_DVR_RECORDSCHED
{
	SN_DVR_SCHEDTIME struRecordTime;	//？
	BYTE byRecordType;					//录像类型
}SN_DVR_RECORDSCHED, *LPSN_DVR_RECORDSCHED;

//-----------------------------------------
//66.全天录像参数配置(子结构)，4字节
//-----------------------------------------
typedef struct _SN_DVR_RECORDDAY
{
	WORD wAllDayRecord;				// 是否全天录像 0-否 1-是
	BYTE byRecordType;				// 录象类型 
}SN_DVR_RECORDDAY, *LPSN_DVR_RECORDDAY;



//-----------------------------------------
//67.设备录像参数信息,332字节，DeviceRecordParameterInformation     
//-----------------------------------------
typedef struct _DEVICE_RECORD_PARAMETER_INFORMATION
{
	DWORD	dwSize;
	DWORD	dwRecord;  										//是否录像 0-否 1-是
	SN_DVR_RECORDDAY	struRecAllDay[MAX_SCHEDULE_DAYS];	//全天录像计划
	SN_DVR_RECORDSCHED	struRecordSched[MAX_SCHEDULE_DAYS][MAX_TIMESEGMENT];	//时间段录像计划
	DWORD	dwRecordTime;		// 录象延时长度 以秒计 
	DWORD	dwPreRecordTime;	// 预录时间 0-不预录 1-1秒 2-2秒 3-3秒 4-4秒 5-5秒 
	DWORD	dwRecorderDuration;	// 参数不支持 录像保存的最长时间 
	BYTE	byRedundancyRec;	// 参数不支持  是否冗余录像,重要数据双备份：0/1
	BYTE	byAudioRec;			// 录像时复合流编码时是否记录音频数据：国外有此法规
}DEVICE_RECORD_PARAMETER_INFORMATION, *LPDEVICE_RECORD_PARAMETER_INFORMATION;



//-----------------------------------------
//68.设备录像参数信息,368字节,DeviceRecordParameterInformationV2     
//-----------------------------------------
typedef struct _DEVICE_RECORD_PARAMETER_INFORMATION_V2
{
	DWORD	dwSize;
	DWORD	dwRecord;  							//是否录像 0-否 1-是
	BYTE	byRecAllDay[MAX_SCHEDULE_DAYS];		//是否全天录像计划
	SN_DVR_SCHEDTIME_V2	struRecordSched[MAX_SCHEDULE_DAYS];	//时间段录像计划
	DWORD	dwRecordTime;			// 录象延时长度 以秒计 
	DWORD	dwPreRecordTime;		// 预录时间 0-不预录 1-1秒 2-2秒 3-3秒 4-4秒 5-5秒 
	DWORD	dwRecorderDuration;		// 参数不支持 录像保存的最长时间 
	BYTE	byRedundancyRec;		// 参数不支持  是否冗余录像,重要数据双备份：0/1
	BYTE	byAudioRec;				// 录像时复合流编码时是否记录音频数据：国外有此法规
}DEVICE_RECORD_PARAMETER_INFORMATION_V2, *LPDEVICE_RECORD_PARAMETER_INFORMATION_V2;


//-----------------------------------------
//69. 设备云台解码器参数信息,16字节,DevicePTZDecoderParameterInformation   
//	 波特率0-300 1- 600 2-1200 3- 2400 4-4800 5-9600 6-19200 7-38400 8-57600 9-115200
//-----------------------------------------
typedef struct _DEVICE_PTZ_DECODER_PARAMETER_INFORMATION
{
	DWORD dwSize;
	DWORD dwBaudRate;		//波特率
	BYTE byDataBit;			//数据有几位
	BYTE byStopBit;			//停止位[1,2];
	BYTE byParity;			//校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;		//0－无，1－软流控,2-硬流控
	WORD wDecoderType;		//解码器类型, 从0开始，对应ptz协议列表
	WORD wDecoderAddress;	//解码器地址:0 - 255
}DEVICE_PTZ_DECODER_PARAMETER_INFORMATION, *LPDEVICE_PTZ_DECODER_PARAMETER_INFORMATION;

//-----------------------------------------
//70. RS232串口，12字节
//波特率0-300 1- 600 2-1200 3- 2400 4-4800 5-9600 6-19200 7-38400 8-57600 9-115200
//-----------------------------------------
typedef struct _SN_DVR_SINGLE_RS232
{
	DWORD dwBaudRate;   // 波特率
	BYTE byDataBit;     // 数据有几位
	BYTE byStopBit;     // 停止位 0－1位，1－2位 
	BYTE byParity;      // 校验 0－无校验，1－奇校验，2－偶校验 
	BYTE byFlowcontrol; // 0－无，1－软流控,2-硬流控 
	DWORD dwWorkMode;   // 参数不支持 工作模式，0－232串口用于PPP拨号，1－232串口用于参数控制，2－透明通道 
}SN_DVR_SINGLE_RS232, *LPSN_DVR_SINGLE_RS232;

//-----------------------------------------
//71.DDNS参数，210字节
//-----------------------------------------
typedef struct  _SN_DVR_DDNS
{    
	BYTE sUsername[DEVICE_NAME_LEN];	// DDNS账号用户名
	BYTE sPassword[PASSWD_LEN];			// 密码 
	BYTE sDomainName[MAX_DOMAIN_NAME];	// 设备配备的域名地址 当_SN_DVR_DDNSPARA.byHostIndex为STARNET时 此字段无效
	BYTE sServerName[MAX_DOMAIN_NAME];	// DDNS协议对应的服务器地址，可以是IP地址或域名 
	WORD wDDNSPort;						// 当_SN_DVR_DDNSPARA.byHostIndex为STARNET时 端口号才有效 
} SN_DVR_DDNS, *LPSN_DVR_DDNS;

//-----------------------------------------
//72.NTP参数信息，70字节
//-----------------------------------------
typedef struct _SN_DVR_NTPPARA
{
	BYTE sNTPServer[MAX_DOMAIN_NAME];   // Domain Name or IP addr of NTP server 
	WORD wInterval;						// enum NTPCheckTimeInterval_enum{_1Hour=0,_3Hour,_6Hour,_12Hour,_24Hour}; 
	BYTE byEnableNTP;					// enable NPT client 0-no，1-yes
	BYTE TimezoneSelect;				// 时区选择 TimeZoneSlt_enum
	WORD wNtpPort;						// ntp server port 这个参数不支持 
}SN_DVR_NTPPARA, *LPSN_DVR_NTPPARA;

//-----------------------------------------
//73.?,2102字节
//-----------------------------------------
typedef struct _SN_DVR_DDNSPARA
{
	BYTE byEnableDDNS;
	BYTE byHostIndex;					// DHS = 0, DYNS = 1,DYNDNS = 2, STARNET = 3
	SN_DVR_DDNS struDDNS[MAX_DDNS_NUMS];
}SN_DVR_DDNSPARA, *LPSN_DVR_DDNSPARA;

//-----------------------------------------
//74.Email用户和地址信息，128字节
//-----------------------------------------
typedef struct _SN_DVR_EMAIL_INFO
{
	BYTE	sName[DEVICE_NAME_LEN];			//姓名 
	BYTE	sAddress[MAX_DOMAIN_NAME];		//地址
}SN_DVR_EMAIL_INFO, *LPSN_DVR_EMAIL_INFO;

//-----------------------------------------
//75.EMAIL详细信息，728字节
//-----------------------------------------
typedef struct _SN_DVR_EMAIL_PARAM
{		
	DWORD		dwSize;
	BYTE		sAccount[DEVICE_NAME_LEN];		// 账号 
	BYTE		sPassword[PASSWD_LEN];			// 密码 
	SN_DVR_EMAIL_INFO struSender;				// 发件人 
	BYTE		sSmtpServer[MAX_DOMAIN_NAME];	// smtp服务器 
	BYTE		sPop3Server[MAX_DOMAIN_NAME];	// pop3服务器 
	SN_DVR_EMAIL_INFO struReceiver[3];			// 收件人 // 最多可以设置3个收件人 
	BYTE		byAttachment;					// 是否带附件 
	BYTE		bySmtpServerVerify;				// 发送服务器要求身份验证 
	BYTE        byMailInterval;                 // mail interval 
} SN_DVR_EMAIL_PARAM, *LPSN_DVR_EMAIL_PARAM;


//-----------------------------------------
//76.单NFS结构，308字节
//-----------------------------------------
typedef struct _SN_DVR_SINGLE_NFS
{
	SN_DVR_IPADDR sNfsHostIPAddr;
	BYTE sNfsDirectory[MAX_PATH];        
}SN_DVR_SINGLE_NFS, *LPSN_DVR_SINGLE_NFS;


//-----------------------------------------
//77.设备网络文件系统参数信息,2468字节，DeviceNfsParameterInformation
//这个目前不支持
//-----------------------------------------
typedef struct _DEVICE_NFS_PARAMETER_INFORMATION
{
	DWORD  dwSize;
	SN_DVR_SINGLE_NFS struNfsDiskParam[MAX_NFS_DISK];
}DEVICE_NFS_PARAMETER_INFORMATION, *LPDEVICE_NFS_PARAMETER_INFORMATION;

//-----------------------------------------
//78.硬盘信息,88字节
//-----------------------------------------
typedef struct _SN_DVR_SINGLE_HD
{
	char chDiskName[DEVICE_NAME_LEN]; //硬盘名 
	DWORD dwHDNo;					  //硬盘号, 取值0~MAX_DISKNUM-1
	DWORD dwCapacity;				  //硬盘容量(不可设置)
	DWORD dwFreeSpace;				  //硬盘剩余空间(不可设置)
	DWORD dwHdStatus;				  //硬盘状态(不可设置) 1 -满 0-OK    
	BYTE  byHDAttr;					  //目前不支持冗余和只读  0-默认, 1-冗余; 2-只读
	BYTE  byIsFormated;				  //硬盘是否格式化
	DWORD dwHdGroup;				  //目前只支持一个盘组0  属于哪个盘组 1-MAX_HD_GROUP
}SN_DVR_SINGLE_HD, *LPSN_DVR_SINGLE_HD;
//-----------------------------------------
//79.设备硬盘参数信息，2824字节,DEVICE_HARDDISK_PARAMETER_INFORMATION,DeviceHardDiskParameterInformation
//-----------------------------------------
typedef struct  _DEVICE_HARDDISK_PARAMETER_INFORMATION
{
	DWORD dwSize;
	DWORD dwHDCount;						 //硬盘数(不可设置)
	SN_DVR_SINGLE_HD struHDInfo[MAX_DISKNUM];//硬盘相关操作都需要重启才能生效；
}DEVICE_HARDDISK_PARAMETER_INFORMATION, *LPDEVICE_HARDDISK_PARAMETER_INFORMATION;

//-----------------------------------------
//80.球机范围信息,12字节
//-----------------------------------------
typedef struct _SN_DVR_PTZSCOPE
{
	WORD wPanPosMin;	//水平参数min
	WORD wPanPosMax;	//水平参数max
	WORD wTiltPosMin;	//垂直参数min
	WORD wTiltPosMax;	//垂直参数max
	WORD wZoomPosMin;	//变倍参数min
	WORD wZoomPosMax;	//变倍参数max
}SN_DVR_PTZSCOPE, *LPSN_DVR_PTZSCOPE;


//-----------------------------------------
//81.球机位置信息，8字节
//-----------------------------------------
typedef struct _SN_DVR_PTZPOS
{
	WORD wAction;	//获取时该字段无效
	WORD wPanPos;	//水平参数
	WORD wTiltPos;	//垂直参数
	WORD wZoomPos;	//变倍参数
}SN_DVR_PTZPOS, *LPSN_DVR_PTZPOS;


//-----------------------------------------
//82.DVR实现巡航数据结构，136字节
//-----------------------------------------
typedef struct _SN_DVR_CRUISE_PARA
{	
	DWORD 	dwSize;
	BYTE	byPresetNo[CRUISE_MAX_PRESET_NUMS];		// 预置点号 
	BYTE 	byCruiseSpeed[CRUISE_MAX_PRESET_NUMS];	// 巡航速度 
	WORD	wDwellTime[CRUISE_MAX_PRESET_NUMS];		// 停留时间 
	BYTE	byEnableThisCruise;						// 是否启用
}SN_DVR_CRUISE_PARA, *LPSN_DVR_CRUISE_PARA; 


//-----------------------------------------
//83.云台参数信息,156字节，DevicePTZParameterInformation
//这个参数目前不支持
//-----------------------------------------
typedef struct _DEVICE_PTZ_PARAMETER_INFORMATION{
	SN_DVR_PTZPOS  PTZPos;				//球机位置
	SN_DVR_PTZSCOPE  PTZScope;			//位置范围
	SN_DVR_CRUISE_PARA  CruiseParam;	//巡航参数
}DEVICE_PTZ_PARAMETER_INFORMATION, *LPDEVICE_PTZ_PARAMETER_INFORMATION;


//-----------------------------------------
//84.PPP参数配置，264字节，不支持
//-----------------------------------------
typedef struct _SN_DVR_PPP_INFO
{
	SN_DVR_IPADDR struRemoteIP;		//远端IP地址
	SN_DVR_IPADDR struLocalIP;		//本地IP地址
	SN_DVR_IPADDR struLocalIPMask;	//本地IP地址掩码
	BYTE sUsername[DEVICE_NAME_LEN];//用户名
	BYTE sPassword[PASSWD_LEN];		//密码
	BYTE byPPPMode;					//PPP模式, 0－主动，1－被动
	BYTE byRedial;					//是否回拨 ：0-否,1-是
	BYTE byRedialMode;				//回拨模式,0-由拨入者指定,1-预置回拨号码
	BYTE byDataEncrypt;				//数据加密,0-否,1-是
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //电话号码
}SN_DVR_PPP_INFO, *LPSN_DVR_PPP_INFO;

//-----------------------------------------
//85.?,6字节
//-----------------------------------------
typedef struct	_POWER_TIME_INFO				
{
	BYTE bEnabelTime;	//开关机定时使能  1-开启 0-关闭
	BYTE byHour;		//时
	BYTE byMinute;		//分
	BYTE byTimeType;	//时间类型: 1--Day有效，2--Date有效
	BYTE byDay;			//0-表示每天 1--表示星期一 2--表示星期二 以此类推	
	BYTE byDate;		//对应日期，1--1号，以此类推!
}POWER_TIME_INFO,*LPPOWER_TIME_INFO;

//-----------------------------------------
//86.G/S  设备定时开关机参数信息，16字节，DevicePowerTimmingParameterInformation
//-----------------------------------------
typedef struct _DEVICE_POWER_TIMMING_PARAMETER_INFORMATION {
	DWORD	cbSize;						//结构体大小
	POWER_TIME_INFO	struPowerInfo[2];	//数组0 -- 定时开机  1 -- 定时关机
}DEVICE_POWER_TIMMING_PARAMETER_INFORMATION, *LPDEVICE_POWER_TIMMING_PARAMETER_INFORMATION;

//-----------------------------------------
//87.设备232串口参数信息,280字节，DeviceRS232ParameterInformation   
//-----------------------------------------
typedef struct _DEVICE_RS232_PARAMETER_INFORMATION 
{
	DWORD dwSize;
	SN_DVR_SINGLE_RS232 struRs232;			//R32串口信息
	SN_DVR_PPP_INFO struPPPConfig;			//PPP配置信息,目前版本不支持    
}DEVICE_RS232_PARAMETER_INFORMATION , *LPDEVICE_RS232_PARAMETER_INFORMATION ;

//-----------------------------------------
//88.G/S  DVR报警中心信息，116字节，DeviceClientCenterParameterInformation 
//-----------------------------------------
typedef struct _DEVICE_CLIENT_CENTER_PARAMETER_INFORMATION {
	char   server[MAX_DOMAIN_NAME];	//服务器域名
	DWORD port;						//端口号
	char username[MAX_USERNAME_LEN];//用户名
	BYTE password[PASSWD_LEN];		//保存用户输入的密码的MD5值
}DEVICE_CLIENT_CENTER_PARAMETER_INFORMATION, *LPDEVICE_CLIENT_CENTER_PARAMETER_INFORMATION;

//-----------------------------------------
//89.设备报警输入参数信息,540字节，DeviceAlarmInParameterInformation       
//-----------------------------------------
typedef struct _DEVICE_ALARM_IN_PARAMETER_INFORAMTION
{
	DWORD dwSize;								//结构大小
	BYTE sAlarmInName[DEVICE_NAME_LEN];			//名称 
	BYTE byAlarmType;							//报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;						//是否处理 0-不处理 1-处理		
	SN_DVR_EXCEPTIONHANDLE struAlarmHandleType;	//处理方式 
	SN_DVR_SCHEDTIME struAlarmTime[MAX_SCHEDULE_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM];		// 报警触发的录象通道,为1表示触发该通道
	BYTE byEnablePreset[MAX_CHANNUM];		// 是否调用预置点 0-否,1-是
	BYTE byPresetNo[MAX_CHANNUM];			// 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。
	BYTE byEnableCruise[MAX_CHANNUM];		// 是否调用巡航 0-否,1-是
	BYTE byCruiseNo[MAX_CHANNUM];			// 巡航 
	BYTE byEnablePtzTrack[MAX_CHANNUM];		// 是否调用轨迹 0-否,1-是
	BYTE byPTZTrack[MAX_CHANNUM];			// 调用的云台的轨迹序号 
}DEVICE_ALARM_IN_PARAMETER_INFORAMTION, *LPDEVICE_ALARM_IN_PARAMETER_INFORAMTION;

//-----------------------------------------
//90.G/S 手机监控参数信息，64字节，DevicePhoneParameterInformation
//-----------------------------------------
typedef struct _DEVICE_PHONE_PARAMETER_INFORMATION {
	DWORD	dwSize;				//结构体大小
	WORD	wPhoneConnPort;		//手机连接端口
	BYTE	byReserved[58];		//保留
}DEVICE_PHONE_PARAMETER_INFORMATION, *LPDEVICE_PHONE_PARAMETER_INFORMATION;

//-----------------------------------------
//91.?，12字节，DeviceVideoDisplayDefaultParameterInformation
//-----------------------------------------
typedef struct _DEVICE_VIDEO_DISPLAY_DEFAULT_PARAMETER_INFORMATION {
	BYTE	byColorContrast;                //对比度
	BYTE	byBrightness;                   //亮度
	BYTE	byHue;                          //色调
	BYTE	bySaturation;                   //饱和度
	int		xAdjust;						//横向移位
	int		yAdjust;						//纵向移位
}DEVICE_VIDEO_DISPLAY_DEFAULT_PARAMETER_INFORMATION, *LPDEVICE_VIDEO_DISPLAY_DEFAULT_PARAMETER_INFORMATION;

//-----------------------------------------
//92.G/S  报警及移动侦测使能总开关，4字节，DeviceAlarmMovMasterSwitchParameterInformation
//-----------------------------------------
enum SN_Alarm_Armed_Delay_Time_EM
{
	_SN_Disable_EM = 0,		//未开启
	_SN_1min_EM,			//1分钟
	_SN_5min_EM,			//5分钟
	_SN_10min_EM,			//10分钟
	_SN_15min_EM,			//15分钟
};

typedef struct _DEVICE_ALARM_MOV_MASTER_SWITCH_PARAMETER_INFORMATION {
	DWORD	dwMasterState;		//报警总控制的状态 0 -- 撤防 1 -- 布防
	unsigned char ArmedDelay;	//报警总控制布防延迟,SN_Alarm_Armed_Delay_Time_EM 当dwMasterState为TRUE时生效
}DEVICE_ALARM_MOV_MASTER_SWITCH_PARAMETER_INFORMATION, *LPDEVICE_ALARM_MOV_MASTER_SWITCH_PARAMETER_INFORMATION;

//-----------------------------------------
//93.G/S  3G无线网络参数信息结构体，162字节,Device3GNetworkParameterInformation
//lChannel 保留目前必须传0
//-----------------------------------------
typedef struct _DEVICE_3G_NETWORK_PARAMETER_INFORAMTION {
	BYTE	byEnable;                   		//3G使能，默认为0 不启动
	BYTE	byOperatorType;						//运营商，参见DEVICE_3G_NETWORK_PARAMETER_INFORAMTION.byOperatorType
	char	sApn[MAX_3G_APN_LEN];            	//3G接入点名称
	char	sDialNum[MAX_3G_PHONE_LEN]; 	  	//拨号号码
	char	sUserName[MAX_3G_NAME_LEN]; 	  	//3G用户名
	BYTE	byPassWord[MAX_3G_PASSWORD_LEN];  	//3G用户名密码
	BYTE	byReserved[MAX_3G_RESERVE_LEN];		//保留字段
	char	sSMSCenterlNo[32];					//短信中心号码
	unsigned short BellTime;					//响铃时间(秒) 
	int		nCallFrequency;						//呼叫次数 
}DEVICE_3G_NETWORK_PARAMETER_INFORAMTION, *LPDEVICE_3G_NETWORK_PARAMETER_INFORAMTION;

//-----------------------------------------
//94.G/S  SMTP参数信息,564字节，包括邮件收件人列表，DeviceSMTPParameterInformaton
//lChannel 保留目前必须传0
//-----------------------------------------
typedef struct _DEVICE_SMTP_PARAMETER_INFORMATION {
	BYTE byEnableSMTP;							 //开启SMTP
	char sMailBoxServer[MAX_DOMAIN_NAME];		 //邮箱服务器地址
	WORD wEmailPort;							 //邮件服务器端口号
	char sEmailSubject[MAX_DOMAIN_NAME];		 //邮件主题
	char sSenderEmailAddr[MAX_DOMAIN_NAME];		 //发送邮件地址
	char sEmailUser[MAX_USERNAME_LEN];           //用户名
	BYTE byEmailPasswd[PASSWD_LEN];				 //密码
	char sReceiverEmailAddr[MAX_DOMAIN_NAME];	 //邮件接收地址1
	char sReceiverEmailAddr2[MAX_DOMAIN_NAME];	 //邮件接收地址2
	char sReceiverEmailAddr3[MAX_DOMAIN_NAME];	 //邮件接收地址3
	char sReceiverEmailAddr4[MAX_DOMAIN_NAME];	 //邮件接收地址4
	char sReceiverEmailAddr5[MAX_DOMAIN_NAME];	 //邮件接收地址5
}DEVICE_SMTP_PARAMETER_INFORMATION, *LPDEVICE_SMTP_PARAMETER_INFORMATION;



//-----------------------------------------
//95.报警信息
//-----------------------------------------
typedef struct _SN_DVR_ALARMINFO{
	DWORD dwAlarmType;						//报警主类型,参见SN_DVR_ALARMINFO.dwAlarmType
	DWORD dwExcepSubType;					//异常子类型,参见SN_DVR_ALARMINFO.dwExcepSubType
	DWORD dwAlarmInputNumber;				//报警输入通道
	SN_DVR_TIME tAlarmTime;					//报警时间
	BYTE byAlarmOutputNumber[MAX_ALARMOUT];	//报警通道输出
	BYTE byAlarmRelateChannel[MAX_CHANNUM];	//关联录像通道
	BYTE byChannel[MAX_CHANNUM];			//异常视频通道数组
	BYTE byDiskNumber[MAX_DISKNUM];			//异常磁盘数组
}SN_DVR_ALARMINFO, *LPSN_DVR_ALARMINFO;


//-----------------------------------------
//?.G/S 3G无线网络参数信息结构体,Device3GNetworkParameterInformation
//lChannel 保留目前必须传0
//-----------------------------------------

#define VIDEO_YV12								0		//视频图像YV12格式 Y V U
#define VIDEO_YUV420							1		//视频图像YUV420格式  Y U V
#define AUDIO_PCM8K16S							2		//音频数据PCM数据 8K采样率 16位有符号


//-----------------------------------------
//?.Stream type
//-----------------------------------------
#define SN_STREAME_REALTIME 0		//实时流
#define SN_STREAME_FILE		1		//文件流



//-----------------------------------------
//设备报警输入参数信息 V2版本,DeviceAlarmInParameterInformationV2       
//-----------------------------------------
typedef struct _DEVICE_ALARM_IN_PARAMETER_INFORAMTION_V2
{
	DWORD dwSize;
	BYTE bEnableAlarmIn;            		// 是否启用移动侦测   0-不开启   1-开启
	BYTE sAlarmInName[DEVICE_NAME_LEN];		// 名称 
	BYTE byAlarmType;						// 报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;					// 是否处理 0-不处理 1-处理		
	SN_DVR_EXCEPTIONHANDLE struAlarmHandleType;	// 处理方式 
	SN_DVR_SCHEDTIME_V2 struAlarmTime[MAX_SCHEDULE_DAYS];//布防时间
	BYTE byRcdKeepTime;						// 录像保护时间 0-永久保存 1-10天 2-20天 3-30天
	BYTE bAlarmRcd;							// 是否录像联动   1-联动 0-不联动
	BYTE bEnablePTZ;						// 云台联动报警使能
	BYTE byRelRecordChan[MAX_CHANNUM];		// 报警触发的录象通道,为1表示触发该通道
	BYTE byEnablePreset[MAX_CHANNUM];		// 是否调用预置点 0-否,1-是
	BYTE byPresetNo[MAX_CHANNUM];			// 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。
	BYTE byEnableCruise[MAX_CHANNUM];		// 是否调用巡航 0-否,1-是
	BYTE byCruiseNo[MAX_CHANNUM];			// 巡航 
	BYTE byEnablePtzTrack[MAX_CHANNUM];		// 是否调用轨迹 0-否,1-是
	BYTE byPTZTrack[MAX_CHANNUM];			// 调用的云台的轨迹序号 
	BYTE byLocus[MAX_CHANNUM];				// 当前云台的轨迹	
	SN_DVR_SNAP_PIC	struSnap;				// 报警输入抓拍 
	SN_DVR_ALARM_IN_SHIELD struAlarmInShield;//报警屏蔽
	BOOLEAN bMMS;		//彩信报警是否是启用 1-启用 0-关闭
	BOOLEAN bSMS;		//是否是启用 1-启用 0-关闭,以8位为计:1位:短信报警，2位:电话报警
}DEVICE_ALARM_IN_PARAMETER_INFORAMTION_V2, *LPDEVICE_ALARM_IN_PARAMETER_INFORAMTION_V2;

//-----------------------------------------
//设备报警输出参数信息
//DeviceAlarmOutParameterInformation  
//DEVICE_ALARM_OUT_PARAMETER_INFORAMTION    
//-----------------------------------------
typedef struct _DEVICE_ALARM_OUT_PARAMETER_INFORAMTION
{
	DWORD dwSize;
	BYTE sAlarmOutName[DEVICE_NAME_LEN];	// 名称
	DWORD dwAlarmOutDelay;					// 输出保持时间,0-5s,1-10s,2-30s, 3-60s, 4-120s, 5-300s, 6-600s, 7-手动清除
	SN_DVR_SCHEDTIME struAlarmOutTime[MAX_SCHEDULE_DAYS][MAX_TIMESEGMENT];//报警输出激活时间段 
}DEVICE_ALARM_OUT_PARAMETER_INFORAMTION, *LPDEVICE_ALARM_OUT_PARAMETER_INFORAMTION;



//-----------------------------------------
//?.设备报警输出参数信息
//DeviceAlarmOutParameterInformationV2  DEVICE_ALARM_OUT_PARAMETER_INFORAMTION_V2    
//-----------------------------------------
typedef struct _DEVICE_ALARM_OUT_PARAMETER_INFORAMTION_V2
{
	DWORD dwSize;
	BYTE sAlarmOutName[DEVICE_NAME_LEN];	//名称 
	DWORD dwAlarmOutDelay;					//输出保持时间,0-5s,1-10s,2-30s, 3-60s, 4-120s, 5-300s, 6-600s, 7-手动清除
	SN_DVR_SCHEDTIME_V2 struAlarmOutTime[MAX_SCHEDULE_DAYS];//报警输出激活时间段
}DEVICE_ALARM_OUT_PARAMETER_INFORAMTION_V2, *LPDEVICE_ALARM_OUT_PARAMETER_INFORAMTION_V2;

//-----------------------------------------
//?.VGA视频输出
//-----------------------------------------
typedef struct _SN_DVR_VGAPARA
{
	WORD wResolution;							//分辨率 
	WORD wFreq;									//刷新频率
	DWORD dwBrightness;							//亮度 
}SN_DVR_VGAPARA, *LPSN_DVR_VGAPARA;


//-----------------------------------------
//?.预览MATRIX输出参数结构
//-----------------------------------------
typedef struct _SN_DVR_MATRIXPARA
{		
	WORD	wOrder[MAX_ANALOG_CHANNUM];		//预览顺序, 0xff表示相应的窗口不预览
	WORD	wSwitchTime;					//预览切换时间
}SN_DVR_MATRIXPARA, *LPSN_DVR_MATRIXPARA;



//-----------------------------------------
//?.视频输出参数结构体
//-----------------------------------------
typedef struct _SN_DVR_VIDEOOUT
{
	BYTE byVideoFormat;						// 输出制式,0-PAL,1-NTSC 
	BYTE byMenuAlphaValue;					// 菜单与背景图象对比度 
	WORD wScreenSaveTime;					// 屏幕保护时间 0-从不,1-1分钟,2-2分钟,3-5分钟,4-10分钟,5-20分钟,6-30分钟 
	WORD wVOffset;							// 视频输出偏移 
	WORD wBrightness;						// 视频输出亮度 
	BYTE byStartMode;						// 启动后视频输出模式(0:菜单,1:预览)
	BYTE byEnableScaler;                    // 是否启动缩放 (0-不启动, 1-启动)
}SN_DVR_VIDEOOUT, *LPSN_DVR_VIDEOOUT;


//-----------------------------------------
//设备视频输出参数信息
//这个结构体目前版本不支持
//DeviceVideoOutputParameterInformation,  
//G/S  DEVICE_VIDEO_OUTPUT_PARAMETER_INFORMATION
//-----------------------------------------   
typedef struct _DEVICE_VIDEO_OUTPUT_PARAMETER_INFORMATION
{
	DWORD dwSize;
	SN_DVR_VIDEOOUT struVOOut[MAX_VIDEOOUT];			//视频输出信息
	SN_DVR_VGAPARA struVGAPara[MAX_VGA];				//VGA参数,这个参数目前不支持  
	SN_DVR_MATRIXPARA struMatrixPara[MAX_MATRIXOUT];	//MATRIX参数
}DEVICE_VIDEO_OUTPUT_PARAMETER_INFORMATION, *LPDEVICE_VIDEO_OUTPUT_PARAMETER_INFORMATION;


//-----------------------------------------
//单用户参数
//byLocalRight
//	数组0: 本地设置参数
//	数组1: 本地查看状态、日志
//	数组2: 本地重启，关机
//	数组3: 本地管理
//	数组4: 本地通道管理    
//byRemoteRight
//	数组0: 远程设置参数
//	数组1: 远程查看状态、日志
//	数组2: 远程高级管理
//	数组3: 远程发起语音对讲
//	数组4: 远程报警布防
//	数组5: 远程请求报警上传、报警输出
//	数组6: 远程控制，本地输出
//	数组7: 远程控制串口	
//	数组8: 远程通道管理 
//	数组9: 远程关机/重启 
//byPriority
//	低……默认权限:包括本地和远程回放,本地和远程查看日志和状态,本地和远程关机/重启
//	中……包括本地和远程控制云台,本地和远程手动录像,本地和远程回放,语音对讲和远程预览,本地备份,本地/远程关机/重启
//	高……管理员
//-----------------------------------------
typedef struct _SN_DVR_USER_INFO
{
	BYTE sUserName[DEVICE_NAME_LEN];		// 用户名 
	BYTE sPassword[PASSWD_LEN];				// 密码 
	BYTE byLocalRight[MAX_RIGHT];			// 本地权限 
	BYTE byRemoteRight[MAX_RIGHT];			// 远程权限 		
	BYTE byNetPreviewRight[MAX_CHANNUM];	// 远程可以预览的通道 0-有权限，1-无权限
	BYTE byLocalPlaybackRight[MAX_CHANNUM];	// 本地可以回放的通道 0-有权限，1-无权限
	BYTE byNetPlaybackRight[MAX_CHANNUM];	// 远程可以回放的通道 0-有权限，1-无权限
	BYTE byLocalRecordRight[MAX_CHANNUM];	// 本地可以录像的通道 0-有权限，1-无权限
	BYTE byNetRecordRight[MAX_CHANNUM];		// 远程可以录像的通道 0-有权限，1-无权限
	BYTE byLocalPTZRight[MAX_CHANNUM];		// 本地可以PTZ的通道 0-有权限，1-无权限
	BYTE byNetPTZRight[MAX_CHANNUM];		// 远程可以PTZ的通道 0-有权限，1-无权限
	BYTE byLocalBackupRight[MAX_CHANNUM];	// 本地备份权限通道 0-有权限，1-无权限
	SN_DVR_IPADDR struUserIP;				// 用户IP地址(为0时表示允许任何地址) 
	BYTE byMACAddr[MACADDR_LEN];			// 物理地址 
	BYTE byPriority;						// 优先级，0=高(Admin)，1=中(操作员)，2=低(普通用户) 
}SN_DVR_USER_INFO, *LPSN_DVR_USER_INFO;


//-----------------------------------------
//设备用户参数信息,DeviceUserParameterInformation      
//注意:                                                                 
//设置设备用户信息时需在lChannel中指定是修改密码、增加新用户、修改用户
//全部信息还是删除用户												    
//获取或者获取设备用户信息时需指明当前用户于sUserName，比如"Admin"    
//只有"Admin"用户才能进行这四个操作									
//操作员和普通用户只能修改自身的密码，lChannel值被忽略				
//目前版本的SDK只支持一次修改一个用户的信息                           
//-----------------------------------------
typedef struct _DEVICE_USER_PARAMETER_INFORMATION
{
	DWORD dwSize;													//结构体大小
	BYTE  sUserName[DEVICE_NAME_LEN];								//当前用户
	SN_DVR_USER_INFO struUser[MAX_USERNUM];							//指定的用户信息 包括用户名 密码 权限等信息
}DEVICE_USER_PARAMETER_INFORMATION, *LPDEVICE_USER_PARAMETER_INFORMATION;

//-----------------------------------------
//权限结构体
//byLocalRight
//	数组0: 本地设置参数
//	数组1: 本地查看状态、日志
//	数组2: 本地重启，关机
//	数组3: 本地管理
//	数组4: 本地通道管理    
//byRemoteRight
//	数组0: 远程设置参数
//	数组1: 远程查看状态、日志
//	数组2: 远程高级管理
//	数组3: 远程发起语音对讲
//	数组4: 远程报警布防
//	数组5: 远程请求报警上传、报警输出
//	数组6: 远程控制，本地输出
//	数组7: 远程控制串口	
//	数组8: 远程通道管理 
//	数组9: 远程关机/重启 
//byPriority
//	低……默认权限:包括本地和远程回放,本地和远程查看日志和状态,本地和远程关机/重启
//	中……包括本地和远程控制云台,本地和远程手动录像,本地和远程回放,语音对讲和远程预览,本地备份,本地/远程关机/重启
//	高……管理员
//-----------------------------------------
typedef struct _SN_DVR_PERMISSION_INFO
{
	BYTE byLocalRight[MAX_RIGHT];			// 本地权限 
	BYTE byRemoteRight[MAX_RIGHT];			// 远程权限	
	BYTE byNetPreviewRight[MAX_CHANNUM];	// 远程可以预览的通道 0-有权限，1-无权限
	BYTE byLocalPlaybackRight[MAX_CHANNUM];	// 本地可以回放的通道 0-有权限，1-无权限
	BYTE byNetPlaybackRight[MAX_CHANNUM];	// 远程可以回放的通道 0-有权限，1-无权限
	BYTE byLocalRecordRight[MAX_CHANNUM];	// 本地可以录像的通道 0-有权限，1-无权限
	BYTE byNetRecordRight[MAX_CHANNUM];		// 远程可以录像的通道 0-有权限，1-无权限
	BYTE byLocalPTZRight[MAX_CHANNUM];		// 本地可以PTZ的通道 0-有权限，1-无权限
	BYTE byNetPTZRight[MAX_CHANNUM];		// 远程可以PTZ的通道 0-有权限，1-无权限
	BYTE byLocalBackupRight[MAX_CHANNUM];	// 本地备份权限通道 0-有权限，1-无权限
	BYTE byPriority;						// 优先级，0=高(Admin)，1=中(操作员)，2=低(普通用户) 
}SN_DVR_PERMISSION_INFO, *LPSN_DVR_PERMISSION_INFO;


//-----------------------------------------
//单用户参数
//-----------------------------------------
typedef struct _SN_DVR_USER_INFO_V2
{
	BYTE  sUserName[DEVICE_NAME_LEN];			//用户名
	BYTE sPassword[PASSWD_LEN];					//用户密码
	BYTE byUserGroup;							//用户组 
	BYTE byMACAddr[MACADDR_LEN];				//用户MAC地址
	SN_DVR_IPADDR struUserIP;					//用户IP地址(为0时表示允许任何地址) 
	BYTE bUserEnable;							//用户是否启用1-启用 0-禁用
	SN_DVR_PERMISSION_INFO struUserPermission;  //用户权限 此权限是其所在组权限的子集 
}SN_DVR_USER_INFO_V2, *LPSN_DVR_USER_INFO_V2;


//-----------------------------------------
//设备用户参数信息V2版本,DeviceUserParameterInformationV2     
//对应每一个用户
//-----------------------------------------
typedef struct  _DEVICE_USER_PARAMETER_INFORMATION_V2{
	DWORD dwSize;								//结构体大小
	BYTE  sUserName[DEVICE_NAME_LEN];			//当前用户，或要修改的的用户
	SN_DVR_USER_INFO_V2 struUser[MAX_USERNUM];	//指定的用户信息 包括用户名 密码等信息
}DEVICE_USER_PARAMETER_INFORMATION_V2, *LPDEVICE_USER_PARAMETER_INFORMATION_V2;


//-----------------------------------------
//单用户组参数
//-----------------------------------------
typedef struct _SN_DVR_GROUP_INFO
{
	BYTE byGroupName[DEVICE_NAME_LEN];           // 用户组名称
	SN_DVR_PERMISSION_INFO struGroupPermission;  // 用户组权限
	BYTE byGroupEnable;							 // 用户组是否启用 1-启用 0-禁用
}SN_DVR_GROUP_INFO, *LPSN_DVR_GROUP_INFO;

//-----------------------------------------
//设备用户组信息,DeviceUserGroupParameterInformation      
//一次只能配置一个用户组
//SN_DVR_GetDeviceConfig
//	ALL_GROUP    获取所有用户组,byUserGroup必须为0,sUserName当前用户
//	SINGLE_GROUP 获取单用户组,byUserGroup必须设置为用户组ID,sUserName当前用户
//SN_DVR_SetDeviceConfig
//	ADD_GROUP 添加用户组 struGroup[0]新增用户组信息 sUserName当前用户,新增的用户组ID通过byUserGroup返回
//	UPDATE_GROUP 更新用户组 byGroupName指定需要更新的用户组名(更新之前的用户组名) sUserName当前用户
//	UG_DELETE_GROUP 删除用户组 byGroupName指定需要删除的用户组名 sUserName当前用户
//-----------------------------------------
typedef struct  _DEVICE_USER_GROUP_PARAMETER_INFORMATION
{
	DWORD dwSize;			//结构体大小
	DWORD dwOperate;		//操作类型,参见DEVICE_USER_GROUP_PARAMETER_INFORMATION.dwOperate	
	BYTE  byUserGroup;      //用户组ID
	BYTE  sUserName[DEVICE_NAME_LEN];			//当前用户 只有Admin用户才能查询所有用户组
	BYTE   byGroupName[DEVICE_NAME_LEN];        //用户组名称
	SN_DVR_GROUP_INFO struGroup[MAX_GROUPNUM];	//指定的用户信息 包括用户名 密码等信息
}DEVICE_USER_GROUP_PARAMETER_INFORMATION,*LPDEVICE_USER_GROUP_PARAMETER_INFORMATION;

//-----------------------------------------
//设备异常参数信息,DeviceExceptionParameterInformation     
//设置设备异常参数信息 只能单独设置
//在struExceptionHandleType相应单元位置填写异常信息，并在lChannel中传入相应的数组索引
//struExceptionHandleType
//	数组0=IP冲突,
//	数组1=非法访问,
//	数组2-视频信号异常,
//	数组3-视频信号丢失,
//	数组4-输入输出制式不符, 
//	数组5-网络断开, 
//	数组6-硬盘错误 
//	数组7-硬盘满 
//	数组8-录像失败
//-----------------------------------------
typedef struct _DEVICE_EXCEPTION_PARAMETER_INFORMATION
{
	DWORD dwSize;
	SN_DVR_EXCEPTIONHANDLE struExceptionHandleType[MAX_EXCEPTIONNUM];//异常信息
	
}DEVICE_EXCEPTION_PARAMETER_INFORMATION, *LPDEVICE_EXCEPTION_PARAMETER_INFORMATION;

//-----------------------------------------
//单字符串参数
//-----------------------------------------
typedef struct _SN_DVR_SHOWSTRINGINFO
{
	WORD wShowString;					// 预览是否显示字符,0-不显示,1-显示
	WORD wStringSize;					// 该行字符的长度，不能大于44个字符 
	WORD wShowStringTopLeftX;			// 字符显示位置的x坐标 
	WORD wShowStringTopLeftY;			// 字符名称显示位置的y坐标 
	char sString[MAX_OSD_STRING_LEN];	// 要显示的字符内容 
}SN_DVR_SHOWSTRINGINFO, *LPSN_DVR_SHOWSTRINGINFO;


//-----------------------------------------
//设备字符叠加参数信息,DeviceTextOutParameterInformation         
//这个结构体目前不支持
//-----------------------------------------
typedef struct _DEVICE_TEXTOUT_PARAMETER_INFORMATION
{
	DWORD dwSize;
	SN_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM];	// 要显示的字符串内容数组
}DEVICE_TEXTOUT_PARAMETER_INFORMATION, *LPDEVICE_TEXTOUT_PARAMETER_INFORMATION;


//-----------------------------------------
//设备报警触发辅助输出信息,DeviceAuxOutParameterInformation    
//这个结构体目前不支持
//-----------------------------------------
typedef struct _DEVICE_AUX_OUT_PARAMETER_INFORMATION
{
	DWORD dwSize;
	DWORD dwAlarmOutChan;                       // 选择报警弹出大报警通道切换时间：1画面的输出通道: 0:主输出/1:辅1/2:辅2/3:辅3/4:辅4 
	DWORD dwAlarmChanSwitchTime;                // 报警通道切换时间1:1秒 - 10:10秒 
	DWORD dwAuxSwitchTime[MAX_AUXOUT];			// 辅助输出切换时间: 0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s 
	BYTE  byAuxOrder[MAX_AUXOUT][MAX_WINDOW];	// 辅助输出预览顺序, 0xff表示相应的窗口不预览 
}DEVICE_AUX_OUT_PARAMETER_INFORMATION, *LPDEVICE_AUX_OUT_PARAMETER_INFORMATION;

//-----------------------------------------
//设备期锁信息,DeviceAuthorityInfo    
//这个结构体2x16和6000及2008LE支持
//-----------------------------------------
typedef struct
{
	unsigned short	Year;	// 年 
	BYTE			Month;	// 月 
	BYTE			Day;	// 日 
} DEVICE_PRM_DATE_LT;

typedef struct _DEVICE_PRM_AUTHLOCK_INFO
{ 
	DEVICE_PRM_DATE_LT	LimitDate;		//到期时间
	DEVICE_PRM_DATE_LT	LastDate;		//上一次记录的时间
	unsigned short		usLeftDays;		//剩余使用天数
	BYTE				bLockFlag;		//授权状态 0 -解锁状态 1-锁定状态 2-超过期限
	BYTE				bEnable;		//开关 
	BYTE				bReserve[20];	//保留字段
} DEVICE_PRM_AUTHLOCK_INFO, *LPDEVICE_PRM_AUTHLOCK_INFO;


//设备网络应用参数信息,DeviceNetAppParameterInformation         
typedef struct _DEVICE_NET_APP_PARAMETER_INFORMATION
{
	DWORD  dwSize;
	SN_DVR_IPADDR  sDNSIp;					 // DNS服务器地址 
	SN_DVR_NTPPARA  struNtpClientParam;      // NTP参数 
	SN_DVR_DDNSPARA struDDNSClientParam;     // DDNS参数
	SN_DVR_EMAIL_PARAM   struEMailParam;	 // EMail 参数
}DEVICE_NET_APP_PARAMETER_INFORMATION, *LPDEVICE_NET_APP_PARAMETER_INFORMATION;


//-----------------------------------------
//?.Frame Info
//-----------------------------------------
typedef struct{
	DWORD dwWidth;			//宽
	DWORD dwHeight;			//高
	DWORD dwTimeStamp;		//时间戳,单位ms.
	DWORD dwType;			//数据类型,VIDEO_YV12,VIDEO_YUV420 
	DWORD dwFrameRate;		//帧率
}SN_FRAME_INFO, *PSN_FRAME_INFO;


//-----------------------------------------
//图片查找条件，line4260
//-----------------------------------------
typedef struct _SN_DVR_PICTURECONDITION{
	LONG	lSessionID;			//会话ID
	LONG	lChannelSet;		//通道号集,IPC--0;DVR二进制对应通道,0bit表示1通道,1bit表示2通道,对应位置1表示包含该通道
	DWORD	dwPictureType;		//图片类型 位集合 IPC:0xff全部 2报警 1移动侦测；DVR:1表示预览抓图 2表示移动侦测抓图 4表示报警抓图 8表示视频丢失抓图 16定时 0xff全部
	DWORD	dwIsLocked;			//录像文件是否被锁定：0正常文件 1锁定文件 0xff表示所有文件 
	SN_DVR_TIME  tmStartTime;	//开始时间
	SN_DVR_TIME  tmEndTime;     //结束时间
}SN_DVR_PICTURECONDITION, *LPSN_DVR_PICTURECONDITION;

//参数配置 
//设备报警输入参数信息
// typedef struct _DEVICE_ALARM_IN_PARAMETER_INFORAMTION
// {
// 	DWORD dwSize;
// 	BYTE sAlarmInName[64];	/* 名称 */
// 	BYTE byAlarmType;	            //报警器类型,0：常开,1：常闭
// 	BYTE byAlarmInHandle;	        /* 是否处理 0-不处理 1-处理*/		
// 	SN_DVR_EXCEPTIONHANDLE struAlarmHandleType;	/* 处理方式 */
// 	SN_DVR_SCHEDTIME struAlarmTime[7][8];//布防时间
// 	BYTE byRelRecordChan[32]; //报警触发的录象通道,为1表示触发该通道
// 	BYTE byEnablePreset[32];		/* 是否调用预置点 0-否,1-是*/
// 	BYTE byPresetNo[32];			/* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。*/
// 	BYTE byEnableCruise[32];		/* 是否调用巡航 0-否,1-是*/
// 	BYTE byCruiseNo[32];			/* 巡航 */
// 	BYTE byEnablePtzTrack[32];		/* 是否调用轨迹 0-否,1-是*/
// 	BYTE byPTZTrack[32];			/* 调用的云台的轨迹序号 */
// }DEVICE_ALARM_IN_PARAMETER_INFORAMTION, *LPDEVICE_ALARM_IN_PARAMETER_INFORAMTION;

//-----------------------------------------
//?.图片信息结构
//-----------------------------------------
typedef struct _SN_DVR_PICTUREDATA{
	char	strFileName[MAX_DEVICE_FILENAME_LEN];//文件名
	int		PictureId;							 //图片内部ID 
	int		Channel;							 //图片所在通道
	int		PictureFormat;						 //图片格式 jpeg BMP PNG,目前只支持jpeg
	int		PictureType;						 //图片类型  1表示预览抓图,2表示移动侦测抓图,4表示报警抓图,8表示视频丢失抓图
	BYTE	Protect;							 //是否写保护
	DWORD	dwPictureSize;						 //图片文件大小
	SN_DVR_TIME tmPictureCreateTime;			 //文件开始时间
}SN_DVR_PICTUREDATA, *LPSN_DVR_PICTUREDATA;


//-----------------------------------------
//D1 及IPC在线用户信息
//相关函数:SN_DVR_GetDeviceOnlineUserInfo
//-----------------------------------------
typedef struct _SN_DEVICE_ONLINE_USER_INFO
{
	BYTE byUserName[MAX_USERNAME_LEN];		//用户名
	BYTE byUserType;						//用户类型
	BYTE byUserGroup[MAX_USERNAME_LEN];	    //用户组 SN1700使用
	BYTE byIPAddress[IPADDRESS_MAX_LEN];	//IP地址
	BYTE byMacAddress[MACADDR_LEN];			//mac地址
	DWORD dwLoginTime;						//登录时间，单位:秒
}SN_DEVICE_ONLINE_USER_INFO, *PSN_DEVICE_ONLINE_USER_INFO; 

//-----------------------------------------
//参数配置，D1及IPC在线用户信息
//-----------------------------------------
typedef struct _SN_DEVICE_ONLINE_USER_LIST{
	DWORD dwOnlineUserCount;	//在线用户个数 指示下面这个结构体成员有效个数 
								//这个值有可能超过MAX_ONLINE_USER_COUNT 
								//则下面数据只是前面MAX_ONLINE_USER_COUNT个有效
	SN_DEVICE_ONLINE_USER_INFO	arrOnlineUserInfo[MAX_ONLINE_USER_COUNT];	//在线用户信息数组
}SN_DEVICE_ONLINE_USER_LIST, *PSN_DEVICE_ONLINE_USER_LIST;


//-----------------------------------------
//手动抓图
//相关函数:SN_DVR_SnapDevPicture
//-----------------------------------------
#define		SN_SNAP_EM			(1<<0)		//设备抓图
#define 	SN_UPLOAD_EM		(1<<1)		//
#define		SN_UPLOAD_PHOTO_EM	(1<<2)		//上传中心图片

//抓图类型
enum SN_PIC_SNAP{
	SN_MAN_MMS = 0,			//预览抓图
	SN_MOV_MMS,				//移动侦测抓图
	SN_ALM_MMS,				//报警抓图
	SN_VLOSS_MMS			//视频丢失抓图
};

typedef struct{
	int type;				//触发拍照的事件类型(目前只支持MAN_MMS) 参考枚举类型 SN_PIC_SNAP
	int channel;			//拍照的摄像通道 最大通道数32
	int SnapMold;			//抓图类型 详见宏定义SN_SNAP_EM，SN_UPLOAD_EM，SN_UPLOAD_PHOTO_EM,其值可以为其中任意一个或者是交集，分别表示图片是否要保存，上传报警中心以及上传至SDK
	int num;				//抓拍数量 只支持1
	int interval;			//抓图间隔 设置1s
}SN_DVR_SNAP_REQ,*LPSN_DVR_SNAP_REQ;



//-----------------------------------------
//设备通道名称
//-----------------------------------------
typedef struct _DeviceChannelNames  {
	DWORD	dwChannelCount;
	char	ChannelName[MAX_CHANNUM][DEVICE_NAME_LEN]; 
}DeviceChannelNames, *LPDeviceChannelNames;

//-----------------------------------------
//WIFI基本配置
//-----------------------------------------
typedef struct {
	unsigned char	bEnable;		//使能
	char			SSID[128];		//SSID
	char			BSSID[24];		//BSSID 唯一标识
	char			PassWord[32];	//认证密码
	char			Security;
}SN_DVR_WIFI_CFG_BASE,*LPSN_DVR_WIFI_CFG_BASE;

//-----------------------------------------
//WIFI高级配置
//-----------------------------------------
typedef struct{
	unsigned char IPAddress[4];		//IP地址
	unsigned char IPMask[4];		//子网掩码
	unsigned char GateWayIP[4];		//默认网关
	unsigned char DNSAddress[4];	//首选DNS服务器地址
	unsigned char StandbyDNS[4];	//备用DNS服务器地址
	unsigned char AutoGetIPAddr;	//是否自动获取ip
	unsigned char AutoGetDNS;		//是否自动获取DNS
}SN_DVR_WIFI_CFG_ADV,*LPSN_DVR_WIFI_CFG_ADV;

//-----------------------------------------
//WIFI密码认证
//-----------------------------------------
typedef struct {
	char			SSID[128];		//SSID
	char			BSSID[24];		//BSSID
	unsigned char	PassWord[32];	//认证密码
	time_t			atime;			//访问时间
}SN_DVR_WIFI_KEY_REC,*LPSN_DVR_WIFI_KEY_REC;

#define WIFI_KEY_REC_NUM 10
typedef struct {
	SN_DVR_WIFI_KEY_REC WifiKeySet[WIFI_KEY_REC_NUM];
}SN_DVR_WIFI_KEY_SET,*LPSN_DVR_WIFI_KEY_SET;

//-----------------------------------------
//移动侦测语音播报联动
//-----------------------------------------
typedef struct _DEVICE_PRM_MOTION_DETECT_LINKAGE{
	BYTE	bVoice;			// 是否联动语音播报，1—是 0—否 
	char	Reserve[11];	// 预留
} DEVICE_PRM_MOTION_DETECT_LINKAGE,*LPDEVICE_PRM_MOTION_DETECT_LINKAGE; 

//-----------------------------------------
//视频丢失语音播报联动
//-----------------------------------------
typedef struct _DEVICE_PRM_VIDEO_LOST_LINKAGE
{
	BYTE	bVoice;			// 是否联动语音播报，1—是 0—否 
	char	Reserve[11];	// 预留
}DEVICE_PRM_VIDEO_LOST_LINKAGE,*LPDEVICE_PRM_VIDEO_LOST_LINKAGE;

//-----------------------------------------
//信号量报警语音播报联动
//-----------------------------------------
typedef struct _DEVICE_PRM_ALARM_IN_LINKAGE
{
	BYTE	bVoice;			// 是否联动语音播报，1—是 0—否 
	char	Reserve[11];	// 预留
}DEVICE_PRM_ALARM_IN_LINKAGE,*LPDEVICE_PRM_ALARM_IN_LINKAGE;

//-----------------------------------------
//语音播报次数
//-----------------------------------------
typedef struct _DEVICE_PRM_VOICE_PLAY_TIMES
{
	unsigned char	FileId;		//预留
	unsigned char	Times;		// 语音播放次数，值范围0—5 
} DEVICE_PRM_VOICE_PLAY_TIMES,*LPDEVICE_PRM_VOICE_PLAY_TIMES;

//-----------------------------------------
//告警号码和邮箱、密码
//-----------------------------------------
typedef struct  _SN_PHONE_LIST{
	BOOLEAN bSelect;				//该用户是否被选中,以8位为计：第一位:总开关,第二位:短信,第三位:彩信,第三位:电话
	char  UserName[MAX_NAMELEN];
	char  PhoneNum[MAX_PHONELEN];
	char  Email[MAX_EMAILLEN];
}SN_PHONE_LIST,*LPSN_PHONE_LIST; 
//-----------------------------------------
//电话联系人列表
//-----------------------------------------
typedef struct  _SN_PHONE_LIST_INFO{
	SN_PHONE_LIST struPhoneList[MAX_PHONE_LIST_NUM];
}SN_PHONE_LIST_INFO,*LPSN_PHONE_LIST_INFO; 
//-----------------------------------------
//彩信中心参数配置 SN_6***
//-----------------------------------------
typedef struct _SN_MMSCONFIGSN6
{
	char szmmsc[MAX_MMSCLEN];  			//默认"http://mmsc.monternet.com"
	char szgatewapIp[MAX_GATEWAYLEN];  	//默认10.0.0.172
	int	 iwtp_port;  					//默认9201 
	int	 ihttp_port; 					//默认80
	char szapn[MAX_APNLEN];             //默认"cmwap"
	char szusername[MAX_USERNAMELEN]; 	//默认""
	char szpassword[MAX_PASSWORDLEN]; 	//默认""
	int  mmsType;						//彩信传输方式0wap, 1http, 2:MMI接口 默认1  
	char DialNum[MAX_DIALNUMLEN]; 	  	// 拨号号码 默认值"*98*1#"
	unsigned char iMNC; 				//运营商名称 0移动 1联通  2其他   默认0
}SN_MMSCONFIGSN6,*LPSN_MMSConfigInfoSN6;

//-----------------------------------------
//设备通用配置
//-----------------------------------------
typedef struct  _DEVICE_GENERAL_CFG_BASIC{
	unsigned char Language;                     //系统语言   对应Language_enum
	unsigned char OutPutType;					//HDVGA输出选择0-HD   1-VGA
	unsigned char CVBSOutputType;               //CVBS输出制式   0-NTSC   1-PAL
	unsigned char VGAResolution;                //显示器分辨率  对应VGAResolution_enum
	unsigned char TimeZoneSlt;                  //时区设置 TimeZoneSlt_enum
	unsigned char DataDisplayForm;              //日期显示格式  0为 YYYY-MM-DD   1为 MM-DD-YYYY   2为DD-MM-YYYY   3为YYYY年MM月DD日   4为MM月DD日YYYY年
	unsigned char MouseSpeed;                   //鼠标移动速度
	unsigned char EnableOPPasswd;				//启动操作密码   0-不启动   1-启动
	unsigned char NoShake;                      //电视去抖   0-不启动   1-启动
	unsigned char OutputSel;                    //输出设备选择 0-HD/VGA   1-CVBS1 2- CVBS2
	unsigned char Wizard;                       //是否打开向导
}DEVICE_GENERAL_CFG_BASIC, *LPDEVICE_GENERAL_CFG_BASIC;

//-----------------------------------------
//网络upnp端口映射
//-----------------------------------------
typedef struct  _DEVICE_UPNP_PARAMETER_INFO
{	
	UINT32 dwHttpPort;		//http端口
	UINT32 dwSinglePort; 	//单播端口
	UINT32 dwRPCPort;	 	//信令端口RPC使用
	UINT32 dwDataPort;    	//数据端口文件传输使用
	UINT32 dwReserved1; 	//语音对讲端口
	UINT32 dwReserved2;		//保留端口2
	UINT32 dwReserved3;		//保留端口3
	UINT32 dwReserved4;		//保留端口4


	BOOLEAN bAutoPortMap;		//自动端口映射
	UINT32 dwUpnpHttpPort;		//http映射端口
	UINT32 dwUpnpSinglePort;	//单播映射端口
	UINT32 dwUpnpRPCPort;		//信令映射端口 RPC使用
	UINT32 dwUpnpDataPort;		//数据映射端口 文件传输使用
	UINT32 dwUpnpReserved1;		//语音对讲映射端口
	UINT32 dwUpnpReserved2;		//手机监控映射端口
	UINT32 dwUpnpReserved3;		//保留映射端口3
	UINT32 dwUpnpReserved4;		//保留映射端口4

} DEVICE_UPNP_PARAMETER_INFO, *LPDEVICE_UPNP_PARAMETER_INFO;

//-----------------------------------------
//IPC图像翻转参数
//-----------------------------------------

typedef struct _DEVICE_PICTURE_OVERTURN
{
	unsigned int	xRoll;			//左右翻转 0:不翻转，1:翻转
	unsigned int	yRoll;			//上下翻转 0:不翻转，1:翻转
	unsigned int	AutoBanlance;	//保留赋值0
	unsigned int	AutoExpose;		//保留赋值0
	unsigned int	AutoFocus;		//保留赋值0
	unsigned int	xStart;			//保留赋值0
	unsigned int	yStart;			//保留赋值0
}DEVICE_PICTURE_OVERTURN , *LPDEVICE_PICTURE_OVERTURN;


//-----------------------------------------
//GPS业务服务器设置结构体
//-----------------------------------------
typedef struct _SN_GPS_DVR_SERVER_ADDR
{	
	char LocalNum[13];	//(12)本机号
	char IpAddr[16];	//IP地址--数据格式为字符串
	char Port[6];		//端口号--数据格式为字符串
	char Apn[21];		//APN
	char UserName[17];	//用户名
	char PassWord[17];	//密码
}SN_GPS_DVR_SERVER_ADDR, *LPSN_GPS_DVR_SERVER_ADDR; 

//-----------------------------------------
//视频服务器平台地址结构体
//-----------------------------------------
typedef struct _SN_GPS_DVR_VIDEO_SERVER_ADDR
{	
	char			IpAddr[16];			/*IP地址--数据格式为字符串*/
	char			Port[6];			/*端口号--数据格式为字符串*/
	unsigned char	platformInfo[20];	/*平台描述信息*/

}SN_GPS_DVR_VIDEO_SERVER_ADDR, *LPSN_GPS_DVR_VIDEO_SERVER_ADDR; 


//-----------------------------------------
//条件报警录像上传结构体
//-----------------------------------------
typedef struct  {
	unsigned char bTimeSel[48];			//对于布防时间，1-代表布防 0-代表不布防， 对于录像联动 RECORDTYPE 枚举 指定录像类型
}SN_SCHEDTIME, *LPSN_SCHEDTIME;

typedef struct{
	unsigned char	bSnap;			//是否抓拍
	unsigned char   SnapNum;		//抓拍数量
	unsigned char   SnapInterval;	//抓拍间隔
}SN_ALARM_SNAP;

typedef struct _SN_GPS_DVR_TERM_ALARM_VIDEO_UPLOAD
{	
	unsigned char bEnable;            		//是否启用条件报警 1--启用 0--禁用
	SN_SCHEDTIME SchedTime[7];				//处理报警输入布防时间(预留,UI上未体现)
	char AlarmName[32];						//报警输入端名称
	unsigned char HandleType[2];			//处理方式选择(预留,UI上未体现)  HandleType[0]-弹出报警画面	[1]-声音警告
	unsigned char TrigChannel[MAX_CHANNUM];	//联动的通道   1-联动选中通道 0-未选中

	//联动的录像通道
	unsigned char bAlarmRcd;				//是否录像联动   1-联动 0-不联动
	unsigned short	RcdTime;				//条件报警录像的时间，单位分钟，值范围0-60 
	unsigned char RcdKeepTime;				//录像保护时间 RCDKEEPTIME_NO -不保存 RCDKEEPTIME_10 -10天 RCDKEEPTIME_20 -20天 RCDKEEPTIME_30 -30天 RCDKEEPTIME_ALL-永久保存
	//抓拍
	SN_ALARM_SNAP Snap;						//抓拍选项
	char Reserved[8];						//预留
}SN_GPS_DVR_TERM_ALARM_VIDEO_UPLOAD, *LPSN_GPS_DVR_TERM_ALARM_VIDEO_UPLOAD; 
//-----------------------------------------
//GPS设备信息结构体
//-----------------------------------------
typedef struct _SN_GPS_DVR_DEVICE_INFO
{
	char DeviceId[21];            			//GPS设备ID，初始值为SN号，不足前面补0
	char Reserved[32];						//预留
}SN_GPS_DVR_DEVICE_INFO, *LPSN_GPS_DVR_DEVICE_INFO;
//-----------------------------------------
//受GPS模块控制的定时开关机
//-----------------------------------------
typedef struct _SN_GPS_DVR_FIXED_TIME_ST
{
	unsigned char bEnable;			//GPS定时开关机使能
	char		  DateType;			//日期类型 0--每天 1--每周一~周五 2--按照有效日期开关机(yymmdd)
	char 		  UpTime[6];		//开机时间--hhmmss
	char 		  DownTime[6];		//关机时间--hhmmss
	char 		  EffDateBegin[6];	//有效开始日期--yymmdd
	char 		  EffDateEnd[6];	//有效结束日期--yymmdd
}SN_GPS_DVR_FIXED_TIME,*LPSN_GPS_DVR_FIXED_TIME;
//-----------------------------------------
//车辆信息
//-----------------------------------------
typedef struct _SN_GPS_DVR_VEHICLE_INFO_ST
{
	unsigned int	ProvinceId;			//省域ID--GB/T 2260-2007中规定的行政区划代码六位中前2位
	unsigned int 	CityId;				//市域ID--GB/T 2260-2007中规定的行政区划代码六位中前4位
	char 			CarClass[16];		//车辆分类--字符串(UI上限制12个字符，不包含'\0')
	char 			CarVIN[20];			//车辆VIN--字符串(UI上限制17个字符，不包含'\0')
	char 			LicenPlaNum[16];	//车牌号--字符串，如闽AY3154(UI上限制12个字符，不包含'\0')
	unsigned int 	DriverId;			//驾驶员ID
	char 			LicenNum[20];		//驾驶证号--字符串(UI上限制18个字符，不包含'\0')
}SN_GPS_DVR_VEHICLE_INFO,*LPSN_GPS_DVR_VEHICLE_INFO;
//-----------------------------------------
//GPS OSD信息
//-----------------------------------------
typedef struct  {
	unsigned char bGpsInfoDsp;				//显示GPS信息   0-不显示   1-显示
	unsigned short GpsInfoPosition_x;		//GPS信息显示位置x坐标
	unsigned short GpsInfoPosition_y;		//GPS信息显示位置y坐标
}SN_GPS_DVR_INFO_OSD_CHAN, *LPSN_GPS_DVR_INFO_OSD_CHAN;
//-----------------------------------------
//录像控制
//-----------------------------------------
typedef struct  {
	unsigned char 	RcdCtrlType;			//录像控制类型   0-启用录像计划   1-启用点火录像
	unsigned short  TurnOffDelTime;			//熄火延迟时间(0-60分钟)，仅启用点火录像时有效
}SN_GPS_DVR_RCD_CTRL, *LPSN_GPS_DVR_RCD_CTRL;
//IPC设备搜索(NVR)
//相关函数:SN_NVR_FindNextIPC、SN_NVR_FindFirstIPC
typedef struct _SN_DEVICE_IPC_INFO{
	char			IPCName[DEVICE_NAME_LEN];	// 设备名称
	char			IPCIP[IPADDRESS_MAX_LEN];	// 设备IP地址
	char 			IPCWeb[64];					// web地址 这里包含设备IP
	unsigned char	IPCMAC[MACADDR_LEN];		// MAC 地址
	char			IPCGateWay[4];				// 网关地址
	char			IPCSubnetMask[4];			// 子网掩码
	SN_DVR_TIME		IPCTime;					// 设备时间
	int				ConfigPort;					// 标识配置端口号
	unsigned char	DeviceType;					// 搜索的设备类型NVR/DVR/IPC
}SN_DEVICE_IPC_INFO, *LPSN_DEVICE_IPC_INFO;
typedef struct _SN_DEVICE_IPC_INFO_V2
{
	char			IPCName[DEVICE_NAME_LEN];	// 设备名称
	char			IPCIP[IPADDRESS_MAX_LEN];	// 设备IP地址
	char 			IPCWeb[MAX_URL_STR_LEN];	// web地址 这里包含设备IP
	unsigned char	IPCMAC[MACADDR_LEN];		// MAC 地址
	unsigned char	IPCGateWay[4];				// 网关地址
	unsigned char	IPCSubnetMask[4];			// 子网掩码
	SN_DVR_TIME		IPCTime;					// 设备时间
	int				ConfigPort;					// 标识配置端口号
	unsigned char	DeviceType;					// 搜索的设备类型NVR/DVR/IPC
	char			ProductTypeStr[MAX_NAME_LEN];// 设备类型
	unsigned short  MediaPort;					//远程主机端口号(RTSP端口)
}SN_DEVICE_IPC_INFO_V2, *LPSN_DEVICE_IPC_INFO_V2;
//获取当前设备的连接情况
//函数相关:SN_NVR_GetConnectState
typedef struct _SN_DEVICE_CONNECT_STATE{
	char cDevState[MAX_NVR_CHANNUM];		//0:表示未连接 1:已连接   1个字节代表1个通道;
}SN_DEVICE_CONNECT_STATE, *LPSN_DEVICE_CONNECT_STATE;
//NVR IPC连接测试消息
typedef struct _SN_NVR_IPC_TEST_INFO{
	char			szusername[MAX_USERNAME_LEN];
	unsigned char   szpassword[PASSWD_LEN];
	unsigned char   HostIP[IPADDRESS_MAX_LEN];
	unsigned short  HostPort;
	unsigned short	ProductType;					//产品型号 enum NVR_IPC_PRODUCT
	char		    URL[128];
}SN_NVR_IPC_TEST_INFO,*LPSN_NVR_IPC_TEST_INFO;
//包含IPC远程配置端口的连接测试消息结构体
typedef struct _SN_NVR_IPC_TEST_INFO_V2
{
	char			szusername[MAX_USERNAME_LEN];
	unsigned char   szpassword[PASSWD_LEN];
	unsigned char   HostIP[IPADDRESS_MAX_LEN];
	unsigned short  HostPort;
	unsigned short	ProductType;  //产品型号*/
	char		    URL[128];
	unsigned short  ParamPort;    //新增的IPC端配置端口
	unsigned short  RemoteChannel;//远程通道号
	unsigned char   DecodeMode;	  //解码模式
	unsigned char   reserved[5];  //预留字段
}SN_NVR_IPC_TEST_INFO_V2,*LPSN_NVR_IPC_TEST_INFO_V2;
//获取数字通道类型返回结构体
typedef struct _SN_NVR_GET_IPCTYPE_RSP_ST
{	  
	short	type;		//保留字段
	short	length;		//data段的实际长度，取data的索引时以length为准
	char	data[MAX_NVR_CHANNUM];	//索引为通道号(从0开始), 值为设备类型(对应宏DEV_IPC_XXX)
}SN_NVR_GET_IPCTYPE_RSP_ST,*LPSN_NVR_GET_IPCTYPE_RSP_ST;

typedef struct _DeviceAliveInfo {
	char		*DeviceName;		//设备型号
	char		*DName;				//设备名称
	char		*WebAddress;		//web地址  这里包含设备IP
	char		*SN;				//设备序列号
	char		*IPAddress;			//设备IP地址
	BYTE		byState;			//0 Alive  1 Bye  0 表示设备在线 1 表示设备退出
	BYTE		byChannelCount;		//通道数
	BYTE		byVGA;				
	BYTE		byBNC;
	BYTE		byMAC[6];			//MAC Address
	char		sVersionInfo[256];	//软件版本信息
	DWORD		dwDeviceType;		//0-DVR,1-IPC,2-NVR,3-解码器,4=DVS,5=IPSAN
	SN_DVR_TIME	DvrTime;			//设备时间
	int			MultiPortIndex;	
	int			AliveTime;			//设备通知在线时间 以秒计
	clock_t		clkRecvTime;		//接收到数据时调用clock()的返回值
	unsigned short	DataPort;		//数据传输端口 即ftp文件传输端口	默认为9000
	unsigned short	LinkPort;		//连接端口 即RPC连接端口	默认为8081
	unsigned short	RTSPPort;		//RTSP流媒体端口,默认为554
}DeviceAliveInfo,LPDeviceAliveInfo;


typedef struct _SN_DRV_SET_COM_REQ_ST
{
	int  ComId;			//串口ID
	int  BaudRate;		//波特率
	int  CheckBit;		//奇偶校验位 ，0 — 无奇偶校验位 1 — 奇数校验 2 — 偶数校验
	int  DataBit;		//数据位
	int  StopBit;		//停止位
}SN_DRV_SET_COM_REQ_ST,LPSN_DRV_SET_COM_REQ_ST;

//发送透传数据
//相关函数：SN_DVR_SerialSend
typedef struct _SN_DRV_PASS_THROUGH_REQ
{
	BYTE	 bResp;		//是否需要等待串口的回复 1——是 0——否
						//若是:DVR回复时，将串口的数据填充在pPassRsp->pRevBuf中。
						//若否:DVR则不等待串口的回复，直接返回透传是否成功.

	DWORD	 dwBufSize;
	char	 *pSendBuf;
} SN_DRV_PASS_THROUGH_REQ,LPSN_DRV_PASS_THROUGH_REQ;

//获取DVR透传串口ID
//相关函数:SN_DVR_GetSerialID
typedef struct _SN_DRV_GET_PASSTHR_COM_LIST
{
	int							ComNum;			//表示串口ID数 同时也描述了变长数组pComInfo的元素个数			
	SN_DRV_SET_COM_REQ_ST		ComInfo[128];
} SN_DRV_GET_PASSTHR_COM_LIST,LPSN_DRV_GET_PASSTHR_COM_LIST;



//----------------------------------------------------------------
//条形码查询
//相关函数:SN_DVR_GetBarCodeTable
typedef struct  {
	int   id;     								//扫描记录的ID号 
	char  czBarCode[MAX_SCAN_GUN_DATA_LEN];    	//条码信息
	char  czUser[MAX_USERNAME_LEN];				//联动的录像通道   1-联动选中通道
	int	  iVideoChannel;						//联动的录像通道   多通道 1-联动选中通道
	int   iSnapChannel;							//联动的抓图通道  多通道   1-联动选中通道
	SN_DVR_TIME startTime;						//扫描录像的开始的时间
	SN_DVR_TIME finishTime;						//扫描录像的结束的时间
	int	  iState;								// 0:录像状态正常,1:录像不存在
}SN_DEV_BARCODE_INFO,*LPSN_DEV_BARCODE_INFO;	//条码对应的信息

typedef struct					//发送条码信息请求
{
	int			 iType;								//查询类型 1:条码2：时间 3:条码与时间 4:条码的模糊查询
	char		 szScanData[MAX_SCAN_GUN_DATA_LEN];	//条码信息
	SN_DVR_TIME  BegTime;							//表示一段时间间隔时，是开始时间；   
	SN_DVR_TIME  EndTime;							//表示一段时间间隔时，是结束时间； 
	int			 iCurOrder;							//该字段暂时填0 该条码对应的录像信息列表， 表示当前从第几个开始的回复给查询方
}SN_DEV_SCAN_GUN_CONDITION,*LPSN_DEV_SCAN_GUN_CONDITION;

typedef struct								//发送条码信息回复
{
	int iTotalnum;							//查到的记录总的数目
	int iCurOrder;							//该字段暂时无效 从查到的所有数据中，第几个开始传给查询方，如查到100，这个值等于50，表示从第50个开始传
	int iNum;								//表示本次传输的数据的记录数目，最大500条记录
	SN_DEV_BARCODE_INFO BarcodeInfo[500];   //记录的内容
}SN_DEV_SCAN_GUN_INFO,*LPSN_DEV_SCAN_GUN_INFO;


typedef struct	_SN_DEV_BARCODEPROT_INFO		//发送扫描枪扫描到的条码加锁请求
{
	unsigned char iLockType;						//锁类型，0 解锁 1加锁
	int iCount;										//表示加解锁记录的个数,取值范围1-500
	int BarCodeProtInfo[500];						//扫描记录的ID号数组，最大500条
}SN_DEV_BARCODEPROT_INFO,*LPSN_DEV_BARCODEPROT_INFO;

//----------------------------------------------------------------
//NVR参数配置相关结构体
//----------------------------------------------------------------
typedef struct {
	int			 iMode;				//0:白天 1:夜晚(做获取和设置配置时必须先填上该字段)
	/*降噪*/
	unsigned int uiEnableDenoise;	//0:关闭,1:使能
	unsigned int uiDenoiseLevel;	//降噪强度:-2 ~ 2
	/*自动白平衡*/
	unsigned int uiAwbMode;			//0:自动，1:室内,2:室外,3:手动
	unsigned int uiRG;				//0~255
	unsigned int uiBG;				//0~255
	/*自动曝光*/
	unsigned int uiEnableAE;	//自动曝光使能0:关闭，1:使能
	unsigned int uiShutter;		//快门时间, 0:1/3, 1:1/6, 2:1/12, 3:1/25, 4:1/50, 5:1/100, 6:1/200, 7:1/500, 8:1/1000, 9:1/10000

	/*彩转黑设置*/
	unsigned int uiColor2Black;		//0:低电平有效,1:高电平有效,2:强制彩转黑
	/*宽动态设置*/
	unsigned int uiWdrMode;			//0:线性模式，1:宽动态高, 2:宽动态中,3:宽动态低
	/*光圈*/
	unsigned int uiApeType;			//0:DC光圈,1:非DC光圈
	unsigned int uiApeMode;			//0:自动,1:手动全打开
	/*抗闪烁*/
	unsigned int uiFlicker;			//0:50HZ, :1:60HZ
	/*增益*/
	unsigned int uiAGC;				//增益:0~65535
}DEVICE_SENSOR_ADV_CFG, *LPDEVICE_SENSOR_ADV_CFG;

//扫描输入配置
typedef struct
{
	char    szScanGunName[MAX_USERNAME_LEN];//扫描输入端名称
	BYTE	byHandleScanEnable;				//是否处理扫描输入  0-不处理
	//联动的录像通道
	BYTE	byAlarmRcd;						//是否录像联动   1-联动 0-不联动
	BYTE	byRcdKeepTime;					//录像保护时间 0-不保存 1-10天 2-20天 3-30天 4-永久保存
	BYTE	byRcdEndTime;					//录像结束延迟时间 1-60 分钟  默认值5分钟
	BYTE	szTrigChannel[MAX_CHANNUM];		//联动的录像通道   1-联动选中通道
	//抓拍
	BYTE	bySnap;							//是否抓拍 1:是,0:否
	BYTE    bySnapNum;						//抓拍数量
	BYTE    bySnapInterval;					//抓拍间隔
	BYTE	byCaptureDelay;					//抓图延时,0S--10S

	BYTE	byPreviewCode;					//预览条码 0不预览  1预览 
	BYTE	szHandleType[5];				//处理方式选择  HandleType[0]-弹出报警画面   1-声音警告2-邮件通知(0 不通知 1-通知接受者1，2通知接受者2以此类推)  3-上传中心   4-触发报警输出
	BYTE	szTrigAlarmOut[MAX_ALARMOUT];	//触发的报警输出端口号   1-触发该输出端
	BYTE	byMMS;							//彩信报警是否是启用 1-启用 0-关闭
	BYTE	bySMS;							//短信报警是否是启用 1-启用 0-关闭
	BYTE	byReserve1;						//预留1 
	BYTE	byReserve2;						//预留2 
}DEVICE_SCAN_GUN_CFG, *LPDEVICE_SCAN_GUN_CFG; //对应每个扫描输入端

//IPC连接配置
typedef struct
{
	unsigned char   Channel;							//通道号
	unsigned short  CompanyNo;							//公司名称 enum NVR_IPC_COMPANY
	unsigned short  ProductType;						//产品型号 enum NVR_IPC_PRODUCT
	unsigned char	PreviewMode;						//预览模式 0-实时 1-默认 2-流畅
	unsigned char   TransMode;							//传输模式0-TCP 1-UDP
	char			HostIP[IPADDRESS_MAX_LEN];			//IP地址
	unsigned short  HostPort;							//端口号
	unsigned char   ConnectStatus;						//连接状态 0-未配置 1-已配置//未配置是表示该表项的值不可用 //当添加/删除设备时：0:删除 1：添加
	unsigned char   MACAddress[MACADDR_LEN];			//MAC地址
	char			szusername[MAX_USERNAME_LEN]; 		//用户名
	unsigned char   szpassword[PASSWD_LEN]; 			//密码
	char			ServerAddr[128];					//URL服务器地址
	unsigned char	Enable;								//使能开关该选项
}SN_DVR_NET_CONNECT_SETTING, *LPSN_DVR_NET_CONNECT_SETTING;

//数字通道IPC远程端口配置
typedef struct
{
	unsigned short  ParamPort;		//参数配置端口号
	unsigned char   StreamType;		//码流类型  保留
	unsigned char   RemoteChannel;  //远程通道  保留
	unsigned char   Reserved[8];  	//保留
}SN_NVR_NET_CONNECT_PORT, *LPSN_NVR_NET_CONNECT_PORT;
//NVR 3531添加设备配置结构体
typedef struct
{
	unsigned char   nChannel;                   //当前设备的通道号
	unsigned short  nCompanyNo;                 //公司名称 enum IPC_COMPANY
	unsigned short  nProductType;               //产品型号 enum IPC_PRODUCT
	unsigned char   nAudioEnable;               //音频使能
	unsigned char   nTransMode;                 //传输模式 0-TCP 1-UDP
	char			sHostIP[IPADDRESS_MAX_LEN]; //IP地址
	unsigned short  nMediaPort;                 //RTSP端口号
	unsigned char   nConnectStatus;             //连接状态 0-未配置 1-已配置
	unsigned char   sMACAddress[MACADDR_LEN];   //MAC地址
	char            sUsername[MAX_USERNAME_LEN];//用户名
	unsigned char   sPassword[PASSWD_LEN];      //密码
	char            sServerAddr[MAX_URL_LEN];   //URL服务器地址
	unsigned char   bEnable;                    //使能开关该选项
	unsigned char   bMultiScreen;               //是否多画面
	char            sSubUrl[MAX_URL_LEN];       //子码流URL
	unsigned char   nSerialNo;                  //系列号
	unsigned char   nRemoteChannel;             //远程通道号，产品类型为NVR，DVR时有效
	char            sProductName[MAX_NAME_LEN]; //产品型号
	char            sProductType[MAX_NAME_LEN]; //产品类型
	unsigned char   nStreamType;                //码流选择，0：主码流，1：次码流……
	char            sConfigName[MAX_CHANNEL_NAME_LEN];//配置名称
	unsigned short  nParamPort;                 //参数配置端口号
}SN_NVR_NET_CONNECT_SETTING, *LPSN_NVR_NET_CONNECT_SETTING;
//VoIP报警联动参数配置
typedef struct
{
	char			cVoice;   					//是否开启语音对讲
	WORD			wVoicechannelId;			//语音对讲通道号
	char			csVideo[MAX_NVR_CHANNUM];	//是否开启视频 1:是0:否 按实际设备预览通道数赋值,其余清0
	char			csAudio[MAX_NVR_CHANNUM];	//是否开启音频 1:是0:否 
	char			cCallalarm;					//是否开启呼出报警
	WORD			wAlarmchannelId;			//呼出报警使用通道
	char			csNumber[32];				//呼出报警时，呼叫的电话号码
	WORD			wLastTime;					//报警呼出持续时间（秒为单位）有效时间为30--600秒
}DEVICE_PRM_VOIP_ALARM_LINK,*LPDEVICE_PRM_VOIP_ALARM_LINK;

//youxnNVR
typedef struct
{
	unsigned short			ChannelNamePosition_x;		//通道名称显示位置x坐标
	unsigned short			ChannelNamePosition_y;		//通道名称显示位置y坐标
	unsigned short			ChannelTimePosition_x;		//通道时间显示位置x坐标
	unsigned short			ChannelTimePosition_y;		//通道时间显示位置y坐标
	unsigned char			OSDAttribute;               //OSD属性 0:不显示OSD 1:透明,闪烁 2:透明,不闪烁 3:闪烁,不透明4:不透明,不闪烁 

} DEVICE_PRM_NVR_OSDCFGCHAN, *LPDEVICE_PRM_NVR_OSDCFGCHAN;

typedef struct
{
	char					ChannelName[45];			//通道名称
	BYTE					ChanNameDsp;				//显示通道名称   0-不显示   1-显示
	BYTE					ChanDataDsp;				//显示日期   0-不显示   1-显示
	BYTE					ChanWeekdayDsp;				//显示星期   0-不显示   1-显示
	BYTE					ChanDataDspForm;			//通道日期显示格式
	BYTE					ChanTimeDspType;			//时间制式,0-12小时制,1-24小时制
} DEVICE_PRM_NVR_CHANBASICCFG, *LPDEVICE_PRM_NVR_CHANBASICCFG;

//youxnNVR
typedef struct
{
	int				iPtzSwitch;						//0使用本地云台配置 1使用远程云台配置
	unsigned char	Reserved[3];					//保留
}DEVICE_PRM_PTZ_SWITCH, *LPDEVICE_PRM_PTZ_SWITCH;

//youxnNVR
typedef struct
{
	unsigned short	Interval;						//时间同步间隔 单位小时 范围1-24
	BYTE			TimeSync;						//时间同步开关
	unsigned char	Reserved;						//保留
} DEVICE_PRM_NVR_TIMESYNC, *LPDEVICE_PRM_NVR_TIMESYNC;

// 设备云台解码器参数信息
typedef struct _NVR_PTZ_DECODER_PARAMETER_INFORMATION
{
	BYTE  byRemoteOrLocal;	//0:本地配置，1:远程配置
	DWORD dwSize;		
	DWORD dwBaudRate;		//波特率0-300 1- 600 2-1200 3- 2400 4-4800 5-9600 6-19200 7-38400 8-57600 9-115200
	BYTE byDataBit;			//数据有几位
	BYTE byStopBit;			//停止位 0－1位，1－2位
	BYTE byParity;			//校验 0－无校验，1－奇校验，2－偶校验
	BYTE byFlowcontrol;		//0－无，1－软流控,2-硬流控
	WORD wDecoderType;		//解码器类型, 从0开始，对应ptz协议列表
	WORD wDecoderAddress;	//解码器地址:0 - 255
}NVR_PTZ_DECODER_PARAMETER_INFORMATION, *LPNVR_PTZ_DECODER_PARAMETER_INFORMATION;

//NVS解码器解码模式结构体
typedef struct _SN_NVS_PRM_DECODEMODE
{
	unsigned char   DecodeMode; //解码模式：主动解码或被动解码，对应DecodecMode_enum
	unsigned char   reserve0;
	unsigned char   reserve1;
	unsigned char   reserve2;
}SN_NVS_PRM_DECODEMODE,*LPSN_NVS_PRM_DECODEMODE;
//NVS报警画面切换延时、音频总开关结构体
typedef struct  _SN_NVS_PRM_PREVIEW_ADV_CFG
{
	unsigned char AlarmChanSwitchDelay;   //报警画面切换延时
	unsigned char AlarmHandlePort;        //报警触发端口对应0-HD/VGA 1-CVBS1, 2-CVBS2
	unsigned char AudioPreview[16];       //音频预览,只有AudioPreview[0]有效:0-关闭,1-打开
}SN_NVS_PRM_PREVIEW_ADV_CFG, *LPSN_NVS_PRM_PREVIEW_ADV_CFG;
//NVS主动解码不同预览模式下,各通道的参数配置结构体
typedef struct _SN_NVS_PRM_PREVIEW_CFG_EX
{
	unsigned char   SingleOrder;	  //单画面预览时配置的解码通道号。例如SingleOrder=1表示单画面预览时对应解码通道2。
	unsigned char   FourOrder[4];	  //四画面预览时配置的解码通道号。数组下标表示画面的序号-1，而对应的数值表示配置的解码通道-1。例如FourOrder[1]=2表示画面2对应解码通道3。
	unsigned char   NineOrder[9];	  //九画面预览时配置的解码通道号。数组下标表示画面的序号-1，而对应的数值表示配置的解码通道-1。例如FourOrder[1]=2表示画面2对应解码通道3。
	unsigned char   SixteenOrder[16]; //十六画面预览时配置的解码通道号。数组下标表示画面的序号-1，而对应的数值表示配置的解码通道-1。例如FourOrder[1]=2表示画面2对应解码通道3。
	unsigned char   AudioChn[4];      //四种预览模式下对应开启音频的画面，AudioChn[0]表示单画面预览，AudioChn[1]表示四画面预览，AudioChn[2]表示九画面预览，AudioChn[1]表示十六画面预览
									  //对应的数值表示画面序号-1，255表示所有画面都未开启音频。例如AudioChn[1]=2表示四画面预览时画面3开启音频
	unsigned char   PreviewMode;      //主动解码下的预览模式：0=单画面预览，2=四画面预览，5=九画面预览，6=十六画面预览
	unsigned char   reserve[5];
}SN_NVS_PRM_PREVIEW_CFG_EX,*LPSN_NVS_PRM_PREVIEW_CFG_EX;//主动解码下，各个通道的参数配置

//NVS主被动解码的设备配置信息结构体
typedef struct _SN_NVS_SCM_NET_CONNECT_SETTING
{
	unsigned char   nChannel;                    //当前设备的通道号
	unsigned short  nCompanyNo;			         //公司名称,enum NVR_IPC_COMPANY，主动解码使用
	unsigned short  nProductType;			     //产品型号,enum NVR_IPC_PRODUCT，主动解码使用
	unsigned char   nAudioEnable;			     //音频使能
	unsigned char   nTransMode;			         //传输模式,0-TCP 1-UDP
	char		    sHostIP[IPADDRESS_MAX_LEN];	 //远程主机IP地址
	unsigned short  nMediaPort;                  //RTSP端口号
	unsigned char   nConfigStatus;               //配置状态 0-未配置 1-已配置
	unsigned char   sMACAddress[MACADDR_LEN];    //MAC地址
	char            sUsername[MAX_USERNAME_LEN]; //远程主机用户名
	unsigned char   sPassword[PASSWD_LEN];       //远程主机密码
	char	        sServerAddr[MAX_URL_LEN];    //URL服务器地址
	unsigned char   bEnable;				     //设备是否使能
	unsigned char   nSerialNo;			         //序号，主动解码使用
	unsigned char   nRemoteChannel;				 //远程主机通道号,主动解码使用
	char            sProductName[MAX_NAME_LEN];  //产品型号，被动解码下不用
	char            sProductType[MAX_NAME_LEN];  //产品类型，被动解码下不用
	unsigned char   nStreamType;			     //码流选择,0：主码流，1：次码流……主动解码使用
	char	        sConfigName[MAX_CHANNEL_NAME_LEN];//                                     
	unsigned short  nParamPort;                   //参数配置端口号
}SN_NVS_NET_CONNECT_SETTING,*LPSN_NVS_NET_CONNECT_SETTING;//设备配置信息
//NVS主动解码单通道参数配置结构体
typedef struct _SN_NVS_PRM_SWITCHINFO
{
	unsigned char  	Enable;	    //当前通道是否使能
	unsigned char   SerilNo;    //配置序号，单连接模式使用
	unsigned short  SwitchTime; //轮巡时间，多连接模式使用
	unsigned char   ConnectMode;//连接模式,ConnetcMode_enum
	unsigned char   reserve[3];	//扩展字段，保留
	SN_NVS_NET_CONNECT_SETTING	SwitchDevInfo[MAX_CONNECT_NUM];//单通道设备列表
}SN_NVS_PRM_SWITCHINFO,*LPSN_NVS_PRM_SWITCHINFO;
typedef struct _DEVICE_ALARM_BUZZER_PARAMETER_INFORMATION
{
	WORD RingTime; //蜂鸣时长
} DEVICE_ALARM_BUZZER_PARAMETER_INFORMATION, *LPDEVICE_ALARM_BUZZER_PARAMETER_INFORMATION; //蜂鸣器响铃时长
//NVS被动解码设备信息及各通道使能结构体
typedef struct _SN_NVS_PRM_PASDECODEINFO
{
	unsigned char   Enable[16];//通道使能   
	SN_NVS_NET_CONNECT_SETTING	PasDevInfo;//被动解码下设备信息
}SN_NVS_PRM_PASDECODEINFO,*LPSN_NVS_PRM_PASDECODEINFO;//被动解码下，单画面预览模式各个通道的参数配置
//NVS关联通道单关联配置结构体
typedef struct _SN_NVS_ALMINLINKAGE
{
	unsigned char  chn;       //报警输出关联的解码通道号
	unsigned char  SerialNo;  //设备序列号
	unsigned char  Enable;    //报警使能开关
	unsigned char  reserve;   //预览字段
}SN_NVS_ALMINLINKAGE;//报警输入联动关联通道号和对应设备系列号
//NVS告警关联通道配置结构体
typedef struct _SN_NVS_PRM_ALMINLINKAGE
{
	unsigned char  ALMInChn;  //报警输入通道号
	unsigned char  reserve[3];
	SN_NVS_ALMINLINKAGE  LinkageInfo[MAX_LINKAGE_NUM]; //最大支持4个关联设备，
}SN_NVS_PRM_ALMINLINKAGE,*LPSN_NVS_PRM_ALMINLINKAGE;
//NVS主动解码轮询状态设置结构体(开启轮询、关闭轮询使用)
typedef struct _SN_NVS_SWITCHSTATE
{
	char            RspState;   //开启和关闭轮询是否成功标识
	unsigned char	SwitchState;//轮询状态enum Scm_Update_enum
	unsigned char   reserve[2];
}SN_NVS_SWITCHSTATE,*LPSN_NVS_SWITCHSTATE;//轮巡状态，主动解码下有效
//NVS键盘配置结构体
typedef struct _SN_NVS_PRM_RS485_CFG
{
	unsigned short baud;
	unsigned char  data;
	unsigned char  stop;
	unsigned char  parity;
	unsigned char  reserved[3]; //reserved[0]表示是否启用键盘
}SN_NVS_PRM_RS485_CFG,*LPSN_NVS_PRM_RS485_CFG;
//NVS云台控制停止轮询消息接口
typedef struct _SN_NVS_STOP_PTZSWITCH_REQ
{
	unsigned char sChn;//云台操作通道号
	unsigned char sPtzCtlState;//1:进入云台控制;0:退出云台控制.
}SN_NVS_STOP_PTZSWITCH_REQ,*LPSN_NVS_STOP_PTZSWITCH_REQ;
//-------------------------------------------------------------------------------------
//结构体区域end
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//回调函数start
//-------------------------------------------------------------------------------------

//-----------------------------------------
// Method:    回调1.预览期间的流数据处理回调
// Note:	  一次回调的数据必须被完整传输到对端才能解码，否则将导致解码端崩溃
//  		  建议网络传输采用TCP协议，若用UDP协议，必须保证一次回调数据的完整性 
//			  数据不完整请进行丢弃处理  
// FullName:  PFN_PREVIEWCALLBACK
// Returns:   void
// Parameter: LONG  lPrevHandle,预览窗口句柄
// Parameter: DWORD  dwDataType,数据播放类型，参见SN_DVR_STREAMDATA，SN_DVR_STREAMHEAD
// Parameter: BYTE  *pBuffer,	流数据缓冲区
// Parameter: DWORD  dwBufSize,	流数据大小
// Parameter: void  *pContext,  用户自定义的上下文数据
//-----------------------------------------
typedef void (CALLBACK *PFN_PREVIEWCALLBACK)
(
	LONG  lPrevHandle,
	DWORD  dwDataType,
	BYTE  *pBuffer, 
	DWORD  dwBufSize,
	void  *pContext
);

//-----------------------------------------
// Method:    回调2.SDK异常回调函数指针类型
// Note:	  禁止在回调函数内部执行任何SDK调用，否者有可能导致程序死锁	
// FullName:  PFN_EXCEPTIONCALLBACKFUNCTION
// Returns:   void
// Parameter: DWORD dwExceptionType,[in]异常类型 CONNECTION_BROKEN=网络异常，对应SN_DVR_EXCEPTIONINFO
// Parameter: LPVOID pExceptionInfo,[in]特定类型的异常，该指针指向特定的结构体，CONNECTION_BROKEN对应SN_DVR_EXCEPTIONINFO
// Parameter: LPVOID pContext,		[in]外部函数设置该函数指针时设置的自定义类型数据指针
//-----------------------------------------
typedef void (CALLBACK *PFN_EXCEPTIONCALLBACKFUNCTION)
(
 DWORD dwExceptionType,
 LPVOID pExceptionInfo,
 LPVOID pContext
 );

//-----------------------------------------
// Method:    回调3.实时预览画面特殊前景绘制回调函数
// FullName:  PFN_DRAWFUNCTION
// Returns:   void
// Parameter: LONG  lPreviewHandle, 预览播放句柄
// Parameter: HDC	hDc,			设备上下文句柄
// Parameter: void *pContext,		用户自定义上下文数据;
//-----------------------------------------
typedef void (CALLBACK * PFN_DRAWFUNCTION)
(
	LONG  lPreviewHandle,
	HDC  hDc,			
	void *pContext
);	

//-----------------------------------------
// Method:    回调4.实时预览画面特殊前景绘制回调函数Ex
// FullName:  PFN_DRAWFUNCTIONEX
// Returns:   void
// Parameter: LONG  lPreviewHandle, 预览播放句柄
// Parameter: HDC	hDc,			设备上下文句柄
// Parameter: void *pContext,		用户自定义上下文数据;
//-----------------------------------------
typedef void (CALLBACK * PFN_DRAWFUNCTIONEX)
(	
	LONG lPreviewHandle,
	HDC  hDc,
	LONG pContext
);

//-----------------------------------------
// Method:    回调5.?
// FullName:  fPlayDataCallBack
// Returns:   void
// Parameter: LONG lRemotePlayHandle,?
// Parameter: DWORD     dwDataType,	 ?
// Parameter: BYTE      *pBuffer,	 ?
// Parameter: DWORD     dwBufSize	 ?
// Parameter: DWORD     dwUser		 ?	
//-----------------------------------------
typedef void(CALLBACK *fPlayDataCallBack)
(
	LONG      lRemotePlayHandle,
	DWORD     dwDataType,
	BYTE      *pBuffer,
	DWORD     dwBufSize,
	DWORD     dwUser
);


//-----------------------------------------
// Method:    回调6.告警回调函数
// FullName:  PFN_DEVICEMSGCallBack
// Returns:   void
// Parameter: DWORD dwMsgType	告警消息类型参见PFN_DEVICEMSGCallBack.dwMsgType
// Parameter: LPSN_DVR_ALARMER  pAlarmer,  告警DVR的信息
// Parameter: BYTE  *pAlarmInfo, SN_DVR_ALARMINFO结构体，原始数据告警ALM_UPLOAD_CENTER_ST
// Parameter: DWORD  dwInfoLen,	 数据长度
// Parameter: void  *pContext	 用户自定义指针，指针引用	
//-----------------------------------------
typedef void (CALLBACK *PFN_DEVICEMSGCallBack) 
(
	DWORD dwMsgType,
	LPSN_DVR_ALARMER  pAlarmer, 
	BYTE  *pAlarmInfo, 
	DWORD  dwInfoLen, 
	void  *pContext
);	

//-----------------------------------------
// Method:    回调7.预览期间GPS数据回调
// FullName:  PFN_GPSCALLBACK
// Returns:   void 
// Parameter: LONG lPreviewHandle,
// Parameter: LONG ChannelNo,
// Parameter: BYTE* Gpsdata,
// Parameter: int dwBuffSize,
// Parameter: void *pContext
//-----------------------------------------
typedef void (CALLBACK *PFN_GPSCALLBACK)
(
	LONG lPreviewHandle,
	LONG ChannelNo,
	BYTE* Gpsdata,
	int dwBuffSize,
	void *pContext
);


//-----------------------------------------
// Method:    回调8.回放期间数据回调
// FullName:  PFN_NVRDISPLAYCALLBACK
// Returns:   void
// Parameter: LONG	lFilePlay
// Parameter: BYTE	*pData
// Parameter: int		size
// Parameter: void	*pContext
//-----------------------------------------
typedef void (CALLBACK *PFN_NVRDISPLAYCALLBACK)
(	LONG	lFilePlay,
	BYTE	*pData,
	int		size,
	void	*pContext
);



//-----------------------------------------
// Method:    回调9.对讲语音数据回调
// FullName:  PFN_VOICEDATACALLBACK
// Returns:   void
// Parameter: LONG  lVoiceComHandle,	 语音对讲句柄	
// Parameter: char  *pRecvDataBuffer,    语音数据
// Parameter: DWORD  dwBufSize,			 语音数据大小
// Parameter: BYTE  byAudioFlag,		 语音数据标志，0=本地采集的数据；1=设备的语音数据
// Parameter: void  *pContext			 用户自定义指针	
//-----------------------------------------
typedef void (CALLBACK * PFN_VOICEDATACALLBACK)
(
	LONG  lVoiceComHandle, 
	char  *pRecvDataBuffer, 
	DWORD  dwBufSize, 
	BYTE  byAudioFlag, 
	void  *pContext
);
//-----------------------------------------
// Method:    回调10.视频解码显示回调函数指针类型
// FullName:  PFN_DISPLAYCALLBACKFUNCTION
// Returns:   void
// Parameter: LONG lFilePlay,播放句柄 可能是预览句柄、本地播放句柄、远程回放句柄，
//							 外部可以通过不同回调函数，或者在pContext中使用不同的参数
// Parameter: BYTE * pData,				帧数据
// Parameter: DWORD dwSize,				数据长度
// Parameter: PSN_FRAME_INFO frame_info,帧信息
// Parameter: void *pContext,			用户自定义参数
//-----------------------------------------
typedef void (CALLBACK *PFN_DISPLAYCALLBACKFUNCTION)
(
	LONG lFilePlay,
	BYTE * pData,			
	DWORD dwSize,			
	PSN_FRAME_INFO frame_info, 
	void *pContext
);		

//-----------------------------------------
// Method:    11.回放期间GPS数据回调
// FullName:  PFN_DISPLAYGPSCALLBACK
// Returns:   void
// Parameter: LONG lFilePlay, ?
// Parameter: BYTE *GpsData,  ?
// Parameter: int *size,      ?
// Parameter: void *pContext  ?
//-----------------------------------------
typedef void (CALLBACK *PFN_DISPLAYGPSCALLBACK)
(
	LONG lFilePlay,
	BYTE *GpsData,
	int *size,
	void *pContext
);

//-----------------------------------------
// Method:    12.?
// FullName:  PFN_DISPLAYCALLBACKFUNCTIONEX
// Returns:   void
// Parameter: long nPort,    ?
// Parameter: char * pBuf,   ?
// Parameter: long nSize,    ?
// Parameter: long nWidth,   ?
// Parameter: long nHeight,  ?
// Parameter: long nStamp,   ?
// Parameter: long nType,	 ?
// Parameter: long nReceaved ?
//-----------------------------------------
typedef void (CALLBACK *PFN_DISPLAYCALLBACKFUNCTIONEX)
(
	long nPort,
	char * pBuf,
	long nSize,
	long nWidth,
	long nHeight,
	long nStamp, 
	long nType,
	long nReceaved
);		


//-----------------------------------------
// Method:    13?
// FullName:  PFN_UPNPNOTIFYROUTINE
// Returns:   void
// Parameter: PDeviceAliveInfo pUPnPInfo 
// Parameter: void *pContext 
//-----------------------------------------
typedef void (CALLBACK *PFN_UPNPNOTIFYROUTINE) 
(
	DeviceAliveInfo	*pUPnPInfo, void  *pContext	
);	//回调函数


//串口数据回调函数
typedef void(CALLBACK *fSerialDataCallBack)
(	LONG     lSerialHandle,		//SN_DVR_UserLogon()的返回值
	char     *pRecvDataBuffer,	//存放数据的缓冲区指针
	DWORD	 dwBufSize,			//数据大小
	void     *pContext			//用户自定义数据指针
);		


//-----------------------------------------
// Method:    回调14.回调主动注册设备信息
// FullName:  PFN_RegDevInfoCallBack
// Returns:   void
// Parameter:  SN_DEVICEINFO devInfo	//回调的设备信息
// Parameter:  const char * devIP		//回调设备IP
// Parameter: int devPor				//回调的设备端口
// Parameter: void  *pContext	 用户自定义指针，指针引用	
//-----------------------------------------
typedef void (CALLBACK *PFN_RegDevInfoCallBack)
(
 SN_DEVICEINFO devInfo,
 const char * devIP, 
 int devPort,
 const char *userName,
 const char *passWord,
 void  *pContext
 );	

//-----------------------------------------
// Method:    回调15.回调广播数据流信息
// FullName:  PFN_TalkMultiCallBack
// Returns:   void
// Parameter:  char *data	//回调音频数据
// Parameter:  int size		//回调音频数据大小
// Parameter: void  *pContext	 用户自定义指针，指针引用	
//-----------------------------------------
typedef void (CALLBACK *PFN_TalkMultiCallBack)
(
 void *data,
 int size,
 void  *pContext
 );	

//-----------------------------------------
// Method:    回调16.语音对讲上行数据超时回调
// FullName:  PFN_TalkBackTimeOutCallBack
// Returns:   void
// Parameter: void	*pContext
//-----------------------------------------
typedef void (CALLBACK *PFN_TalkBackTimeOutCallBack)
(
	void	*pContext
 );

//-------------------------------------------------------------------------------------
//回调函数end
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//设备注册相关start
//-------------------------------------------------------------------------------------
//-----------------------------------------
//1.注册设备信息
//-----------------------------------------
typedef struct _DeviceRegisterNotify {
	DWORD			cbSize;					//本结构体大小
	DWORD			dwNotifyCode;			//通知代码,参见DeviceRegisterNotify.dwNotifyCode
	SN_DVR_IPADDR	stDevAddress;			//设备IP地址
	DWORD			dwDevPort;				//设备端口 可使用上一个IP地址和这个端口调用SN_DVR_UserLogon登录设备
	char			DevID[MAX_DEVID_LEN];	//设备身份ID
	LONG			lChannelNum;			//设备通道数
	DWORD			dwStreamSet;			//设备支持码流集.参见DeviceRegisterNotify.dwStreamSet
	SN_DVR_IPADDR	stPrivateAddress;		//设备所处局域网IP地址
	DWORD			dwPrivatePort;			//设备所处局域网端口
}DeviceRegisterNotify, *PDeviceRegisterNotify;
//-----------------------------------------
//2.设备注册通知回调
//-----------------------------------------
// Method:    设备注册通知回调
// FullName:  PFN_PLATFORMDEVICEREGISTER
// Returns:   DWORD,	0=允许设备注册，oth=拒绝设备注册
// Parameter: PDeviceRegisterNotify pNotifyInfo,设备注册信息
// Parameter: PVOID  pRes,保留指针 
// Parameter: LPVOID pContext,?
//-----------------------------------------
typedef DWORD (CALLBACK *PFN_PLATFORMDEVICEREGISTER)
(
	 PDeviceRegisterNotify pNotifyInfo,	//设备注册信息
	 PVOID  pRes,						//保留指针
	 LPVOID pContext
 );	

//平台监听信息
typedef struct _SN_DVR_PlatformInfo { 
	DWORD	cbSize;					// 本结构体大小
	WORD	wUDPPort;				// 本地UDP 监听端口 这个端口必须配置 SDK通过这个端口进行设备注册
	WORD	wTCPPort;				// 本地TCP 监听端口 这个端口必须配置 SDK通过这个端口进行设备登录、预览、文件传输等
	SN_DVR_IPADDR	stLocalIP;		// 本地绑定IP地址 可以为空，将由操作系统分配	
	WORD	wNatUDPPort;			// 公网映射对应wUDPPort在外部的映射端口 必须配置
	WORD	wNatTCPPort;			// 公网映射对应wTCPPort在外部的映射端口 必须配置
	SN_DVR_IPADDR	stNatIP;		// 公网IP，必须设置 否者将无法进行设备登录
	DWORD	dwKeepaliveInterval;	// 心跳时间间隔,单位秒
	DWORD	dwMaxLinkCount;			// 最大设备连接数
	PFN_PLATFORMDEVICEREGISTER pfnPlatformDevRegister;	//设备注册回调，每次一台设备进行注册，
														//可以通过返回值控制是否让该设备进行注册，
														//TRUE允许注册 FALSE拒绝注册
	LPVOID pContext;				//自定义指针
}SN_DVR_PlatformInfo, *PSN_DVR_PlatformInfo;

//NVR对应的带有锐度的视频参数结构体
typedef struct	_SN_DEV_VIDEO_INFO		
{
	DWORD	dwBrightValue;		//亮度
	DWORD	dwContrastValue;	//对比度
	DWORD	dwSaturationValue;	//饱和度
	DWORD	dwHueValue;			//色度
	DWORD   dwSharpValue;		//锐度
	DWORD	dwXAdjust;			//横向位移
	DWORD	dwYAdjust;			//纵向位移
}SN_DEV_VIDEO_INFO,*LPSN_DEV_VIDEO_INFO;

//------------------------------------------------------------------------------------------------------------------------
//VoIP

//查询设备VoIP信息
//相关函数:SN_DVR_GetVoIPDeviceInfo
typedef struct
{
	BYTE byDoman		[MAX_VOIP_IP_NAME_LEN];			//registar doman
	BYTE byPort			[MAX_VOIP_PORT_NAME_LEN];		//registar port
	BYTE byProxy		[MAX_VOIP_IP_NAME_LEN];			//outband proxy
	BYTE byProxy_port	[MAX_VOIP_PORT_NAME_LEN];		//outband proxy port
}SN_DEV_VOIP_INFO,*LPSN_DEV_VOIP_INFO;

//查询当前用户信息
//相关函数:SN_DVR_GetVoIPUserInfo,SN_DVR_GetVoIPUserInfo
typedef struct
{
	char cRegist;							//用户是否已注册 0:否 1:是
	char cEnable;							//是否开启 0:否 1:是
	WORD wExpires;							//注册超时时间
	char szServer		[MAX_VOIP_NAME_LEN];//服务器名
	char szDisplayName	[MAX_VOIP_NAME_LEN];//名称
	char szNumber		[MAX_VOIP_NAME_LEN];//号码
	char szAuthid		[MAX_VOIP_NAME_LEN];//认证账户
	char szPassword		[MAX_VOIP_PASS_LEN];//密码
}SN_DEV_VOIP_USER_INFO,*LPSN_DEV_VOIP_USER_INFO;

//配置注册信息
//相关函数:SN_DVR_SetVoIPRegisterInfo
typedef struct
{
	char			cIsEable;							//用户是否开启 0:否 1:是
	WORD			wExpires;							//注册超时
	char			czDisplayName[MAX_VOIP_NAME_LEN];	//名称
	char			czNumber[MAX_VOIP_NAME_LEN];		//号码
	char			czAuthId[MAX_VOIP_NAME_LEN];		//认证账户
	char			czPassword[MAX_VOIP_PASS_LEN];		//密码
}SN_DEV_VOIP_REGISTER_INFO,*LPSN_DEV_VOIP_REGISTER_INFO;
//NVR SN8616-28-HD第二码流配置结构体(第二子码流分辨率有：CIF,QCIF)
typedef struct _SN_NVR_CGI_RCD_CFG_BASIC
{
	unsigned char  nResolution;//分辨率(_SN_Resolution_enum枚举)
	unsigned char  nConstantBitrate;//0-变码率;1-定码率
	unsigned int   nBitrate;//码率
	unsigned char  nFramerate;//视频帧率
	unsigned char  nQuality;//图像质量
}SN_NVR_CGI_RCDCFG, *LPSN_NVR_CGI_RCDCFG;

//主、子、第N码流录像通用配置
typedef enum _SN_BITSTREAM_TYPE_EM
{
	SN_MAIN_STREAM_EM = 0,//主码流
	SN_SUB_STREAM_EM,	  //子码流
	SN_2ND_STREAM_EM,     //第二码流
	SN_3RD_STREAM_EM,     //第三码流
	SN_4TH_STREAM_EM,     //第四码流
}SN_BITSTREAM_TYPE_EM;

typedef struct _SN_NVR_BITSTREAM_CFG
{
	unsigned int   nResolutionWidth;
	unsigned int   nResolutionHeight;
	unsigned int   nBitrate;
	unsigned char  nConstantBitrate; //0是变码率，1是定码率
	unsigned char  nFramerate;
	unsigned char  nQuality; //0-5
	unsigned char  nProfile;
	unsigned short nGovLength;
}SN_NVR_BITSTREAM_CFG,*LPSN_NVR_BITSTREAM_CFG;
//本地视频预览模式结构体
typedef struct _SN_LOCAL_PREVIEW_MODE
{
	UINT8  PreviewVoMode;  //SN_PRM_PREVIEWOUTMODE_EM
	UINT8  reserve[7];
}SN_PRM_PREVIEW_MODE, *LPSN_PRM_PREVIEW_MODE;

//NVR前端IPC能力集获取
typedef struct
{	
	char VideoCodecs[IPC_CODECS_LEN];  //视频编码类型，暂不关心
	char AudioCodesc[IPC_CODECS_LEN];  //音频编码类型，暂不关心
	char Resolution[IPC_RESOLUTION_NUM];	//分辨率能力集，以逗号分隔
	char H264frameRate[IPC_RESOLUTION_NUM * 3]; 	//帧率能力集，以逗号分隔
	char Bitrate [IPC_RESOLUTION_NUM * 4]; 	//码率能力集，以逗号分隔
	unsigned int AlmInPort;  //支持报警输入端口个数
	unsigned int AlmOutPort;    //支持报警输出端口个数
	char Reserved[IPC_RESOLUTION_NUM];
}SNIPCCapabilitySet;

typedef struct _SN_NVR_IPCCAPASETS
{	
	SNIPCCapabilitySet IpcCapSets;
	char Reserved[20];
}SN_NVR_IPCCAPA_SETS, *LPSN_NVR_IPCCAPA_SETS;

//NVR图像质量范围(亮度,饱和度,锐度,对比度,色度)
typedef struct
{
	char ImageQuaRange[IPC_QUAAREA_LEN];//Bright(0,255),Saturation(0,255),Sharp(0,255),Contrast(0,255),Hue(0,255)
}SN_NVR_IMAGEQUA_RANGE,*LPSN_NVR_IMAGEQUA_RANGE;
//-------------------------------------------------------------------------------------
//整理过函数区域start
//-------------------------------------------------------------------------------------
//-----------------------------------------
// Method:    001.SDK初始化函数，
// Note:	  只能调用一次不能重复调用，失败情况不能再次调用,
//			  调用失败情况下请与开发者联系
// FullName:  SN_DVR_SDKInit
// PairFun :  SN_DVR_SDKUninit
// Returns:   LONG，0=成功，-1=重复调用，-n=错误产生的行数，
//-----------------------------------------
LONG  SN_DVR_SDKInit();


//-----------------------------------------
// Method:    002.SDK反向初始化函数
// Note:	  SN_DVR_SDKUninit调用必须在SN_DVR_SDKInit调用成功情况下调用
//			  调用失败情况下请与开发者联系
// FullName:  SN_DVR_SDKUninit
// PairFun :  SN_DVR_SDKInit
// Returns:   LONG，0=成功，
//					-1=没有调用SN_DVR_SDKInit,
//					其它负数=错误产生的行数
//-----------------------------------------
LONG  SN_DVR_SDKUninit();


//-----------------------------------------
// Method:    003.获取最后错误
// FullName:  SN_DVR_GetLastError
// Returns:   DWORD		参见错误代码定义
//-----------------------------------------
DWORD  SN_DVR_GetLastError();




//-------------------------------------------------------------------------------------
//整理过函数区域end
//-------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------
//函数区域start
//-------------------------------------------------------------------------------------




//-----------------------------------------
// Method:    3.设备用户登录
// FullName:  SN_DVR_UserLogon
// Returns:   LONG,-1=失败，other=登录会话ID
//					失败情况下调用SN_SDK_GetLastError获取错误提示信息
// Parameter: char * strDeviceIP			[in]	设备IP
// Parameter: WORD Port						[in]	设备的RPC数据端口
// Parameter: char * UserName				[in]	用户名
// Parameter: char * Passwd					[in]	用户密码
// Parameter: LPSN_DEVICEINFO lpDeviceInfo	[io]	设备信息
//-----------------------------------------
LONG  SN_DVR_UserLogon( char *strDeviceIP, 
						WORD Port,
						char *UserName,
						char *Passwd, 
						LPSN_DEVICEINFO lpDeviceInfo);	



//-----------------------------------------
// Method:    4.设备用户登出
// FullName:  SN_DVR_UserLogoff
// Returns:   BOOL,									TRUE=成功，FALSE=失败
// Parameter: LONG SessionID			    [in]	登录会话ID，即SN_DVR_UserLogon返回的有效值
//-----------------------------------------
BOOL  SN_DVR_UserLogoff(LONG SessionID); 



//-----------------------------------------
// Method:    6.开始预览
// FullName:  SN_DVR_StartPreview
// Returns:   LONG，-1表示预览失败，-2=同一用户不能多次预览同一通道，大于0=返回实时播放会话ID
// Parameter: LONG SessionID,登陆设备的会话ID
// Parameter: LPPREVIEWINFO lpPreviewInfo,预览信息结构体，包括预览窗口句柄和通道号等信息
// Parameter: PFN_PREVIEWCALLBACK pfnPreviewCallBack,预览期间的流数据处理回调
// Parameter: void * pContext,传给回调函数的上下文数据
// Parameter: BOOL bBlocked,是否阻塞直到播放成功,true=阻塞,false=非堵塞,参数无效
//-----------------------------------------
LONG  SN_DVR_StartPreview (LONG SessionID, 
						   LPPREVIEWINFO lpPreviewInfo,
						   PFN_PREVIEWCALLBACK pfnPreviewCallBack,
						   void *pContext, 
						   BOOL bBlocked);	

//-----------------------------------------
// Method:    7.停止预览
// FullName:  SN_DVR_StopPreview
// Returns:   BOOL	 true=停止预览成功，false=停止预览失败
// Parameter: LONG lPreviewHandle	预览会话ID
//-----------------------------------------
BOOL  SN_DVR_StopPreview(LONG lPreviewHandle); 

//-----------------------------------------
// Method:    8.SDK初始化播放器函数
// FullName:  SN_DVR_SDKInitEx
// Returns:   LONG	0=成功，other=失败				
//-----------------------------------------
LONG  SN_DVR_SDKInitEx();
//-----------------------------------------
// Method:    9.设置全局异常处理回调函数指针
// FullName:  SN_DVR_SetExceptionFilter
// Returns:   BOOL												true=成功，false=失败
// Parameter: PFN_EXCEPTIONCALLBACKFUNCTION pfnExceptionFunc	异常处理函数指针
// Parameter: LPVOID pContext									自定义上下文指针，内部调用传递给pfnExceptionFunc作为最后一个参数
//-----------------------------------------
BOOL   SN_DVR_SetExceptionFilter(PFN_EXCEPTIONCALLBACKFUNCTION  pfnExceptionFunc,
								  LPVOID pContext);
//-----------------------------------------
// Method:    10.开始预览函数Ex
// FullName:  SN_DVR_StartPreviewEx
// Returns:   LONG										-1=失败，other=实时播放句柄
// Parameter: LONG lSessionID							登陆设备的会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LPPREVIEWINFO lpPreviewInfo				预览信息结构体指针，包括预览窗口句柄和通道号等信息
// Parameter: PFN_PREVIEWCALLBACK pfnPreviewCallBack	预览期间的流数据处理回调函数
// Parameter: void * pContext							传给回调函数的上下文数据指针
// Parameter: BOOL bBlocked								是否阻塞直到播放成功
//-----------------------------------------
LONG  SN_DVR_StartPreviewEx (LONG lSessionID, 
						     LPPREVIEWINFO lpPreviewInfo, 
						     PFN_PREVIEWCALLBACK pfnPreviewCallBack, 
						     void *pContext, 
						     BOOL bBlocked);	


//-----------------------------------------
// Method:    11.停止预览函数Ex
// FullName:  SN_DVR_StopPreviewEx
// Returns:   BOOL					true=成功，false=失败 
// Parameter: LONG lPreviewHandle	实时预览播放句柄，由SN_DVR_StartPreview返回有效值
//-----------------------------------------
BOOL SN_DVR_StopPreviewEx(LONG lPreviewHandle);
//-----------------------------------------
// Method:    12.设置设备本地视频参数
// FullName:  SN_DVR_SetLocalVideoEffect
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lPreviewHandle		预览播放句柄，由SN_DVR_StartPreview返回有效值
// Parameter: DWORD dwBrightValue		亮度
// Parameter: DWORD dwContrastValue		对比度
// Parameter: DWORD dwSaturationValue	饱和度
// Parameter: DWORD dwHueValue			色度
//-----------------------------------------
BOOL SN_DVR_SetLocalVideoEffect (LONG  lPreviewHandle, 
								 DWORD dwBrightValue, 
								 DWORD dwContrastValue, 
								 DWORD dwSaturationValue, 
								 DWORD dwHueValue); 
//-----------------------------------------
// Method:    13.设置设备本地视频参数Ex
// FullName:  SN_DVR_SetLocalVideoEffectEx
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lPreviewHandle		预览播放句柄
// Parameter: DWORD dwBrightValue		亮度
// Parameter: DWORD dwContrastValue		对比度
// Parameter: DWORD dwSaturationValue	饱和度
// Parameter: DWORD dwHueValue			色度
// Parameter: DWORD dwXAdjust			横向位移
// Parameter: DWORD dwYAdjust			纵向位移
//-----------------------------------------
BOOL SN_DVR_SetLocalVideoEffectEx (LONG  lPreviewHandle,
								   DWORD  dwBrightValue, 
								   DWORD  dwContrastValue, 
								   DWORD  dwSaturationValue,
								   DWORD  dwHueValue,
								   DWORD  dwXAdjust,
								   DWORD  dwYAdjust); 
//-----------------------------------------
// Method:    14.获取设备本地视频参数
// FullName:  SN_DVR_GetLocalVideoEffect
// Returns:   BOOL							true=成功，false=失败
// Parameter: LONG lPreviewHandle			预览播放句柄，由SN_DVR_StartPreview返回有效值
// Parameter: DWORD * pdwBrightValue		亮度
// Parameter: DWORD * pdwContrastValue		对比度
// Parameter: DWORD * pdwSaturationValue	饱和度
// Parameter: DWORD * pdwHueValue			色度
//-----------------------------------------
BOOL SN_DVR_GetLocalVideoEffect (LONG  lPreviewHandle, 
								 DWORD *pdwBrightValue, 
								 DWORD *pdwContrastValue, 
								 DWORD *pdwSaturationValue, 
								 DWORD *pdwHueValue);
//-----------------------------------------
// Method:    15.获取设备本地视频参数Ex
// FullName:  SN_DVR_GetLocalVideoEffectEx
// Returns:   BOOL							true=成功，false=失败
// Parameter: LONG lPreviewHandle			预览播放句柄，由SN_DVR_StartPreview返回有效值
// Parameter: DWORD * pdwBrightValue		亮度
// Parameter: DWORD * pdwContrastValue		对比度
// Parameter: DWORD * pdwSaturationValue	饱和度
// Parameter: DWORD * pdwHueValue			色度
// Parameter: DWORD * pdwXAdjust			横向位移
// Parameter: DWORD * pdwYAdjust			纵向位移
//-----------------------------------------
BOOL SN_DVR_GetLocalVideoEffectEx (LONG  lPreviewHandle, 
								   DWORD *pdwBrightValue, 
								   DWORD *pdwContrastValue, 
								   DWORD *pdwSaturationValue,
								   DWORD *pdwHueValue, 
								   DWORD *pdwXAdjust,
								   DWORD *pdwYAdjust); 

//-----------------------------------------
// Method:    16.设置实时预览画面的特殊前景绘制
// FullName:  SN_DVR_RigisterDrawFun
// Returns:   BOOL							true=成功，false=失败
// Parameter: LONG lPreviewHandle			预览播放句柄，由SN_DVR_StartPreview返回有效值
// Parameter: PFN_DRAWFUNCTION fDrawFun		绘制回调函数
// Parameter: void * pContext				用户自定义上下文数据
//-----------------------------------------
BOOL SN_DVR_RigisterDrawFun (LONG  lPreviewHandle,	
							 PFN_DRAWFUNCTION fDrawFun,
							 void *pContext);	
//-----------------------------------------
// Method:    17.设置实时预览画面的特殊前景绘制Ex
// FullName:  SN_DVR_RigisterDrawFunEx
// Returns:   BOOL							true=成功，false=失败
// Parameter: LONG lPreviewHandle			预览播放句柄，由SN_DVR_StartPreview返回有效值
// Parameter: PFN_DRAWFUNCTIONEX fDrawFun	绘制回调函数
// Parameter: LONG pContext					用户自定义上下文数据
//-----------------------------------------
BOOL SN_DVR_RigisterDrawFunEx (LONG lPreviewHandle,	
							   PFN_DRAWFUNCTIONEX fDrawFun, 
							   LONG pContext);		
//-----------------------------------------
// Method:    18.按照文件名回放设备端录像文件
// FullName:  SN_DVR_PlayBackByFileName 
// Returns:   LONG						-1=失败，other=播放句柄
// Parameter: LONG lSessionID			登录设备的会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: char * sPlayBackFileName	需回放的录像文件名
// Parameter: HWND hWnd					视频显示窗口句柄，NSDK未使用
// Parameter: PFN_NVRDISPLAYCALLBACK pfnCallBack	回放期间的流数据处理回调,NSDK修改
// Parameter: void *pContext						传给回调函数的上下文数据,NSDK修改
//-----------------------------------------
LONG SN_DVR_PlayBackByFileName(LONG lSessionID,
							   char *sPlayBackFileName , 
							   HWND hWnd,
							   PFN_NVRDISPLAYCALLBACK pfnCallBack, 
							   void *pContext);					   
//-----------------------------------------
// Method:    19.按照文件名回放设备端录像文件EX
// FullName:  SN_DVR_PlayBackByFileNameEX
// Returns:   LONG						-1=失败，other=播放句柄
// Parameter: LONG lSessionID			登录设备的会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: char * sPlayBackFileName	需回放的录像文件名
// Parameter: HWND hWnd					视频显示窗口句柄
//-----------------------------------------
LONG SN_DVR_PlayBackByFileNameEX(LONG lSessionID,
								 char *sPlayBackFileName, 
								 HWND hWnd);	
//-----------------------------------------
// Method:    20.按照时间区间回放设备端录像
// FullName:  SN_DVR_PlayBackByTime
// Returns:   LONG							-1=失败，other=播放句柄
// Parameter: LONG lSessionID				登录设备的会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannel					需回放的通道号
// Parameter: LPSN_DVR_TIME lpStartTime		需回放的开始时间
// Parameter: LPSN_DVR_TIME lpStopTime		需回放的结束时间
// Parameter: HWND hWnd						视频显示窗口句柄，NSDK未使用
// Parameter: PFN_NVRDISPLAYCALLBACK pfnCallBack	回放期间的流数据处理回调,NSDK修改
// Parameter: void *pContext						传给回调函数的上下文数据,NSDK修改
//-----------------------------------------
LONG SN_DVR_PlayBackByTime (LONG lSessionID,
							LONG lChannel, 
							LPSN_DVR_TIME lpStartTime, 
							LPSN_DVR_TIME lpStopTime , 
							HWND hWnd,
							PFN_NVRDISPLAYCALLBACK pfnCallBack, 
							void *pContext); 
//-----------------------------------------
// Method:    21.按照时间区间回放设备端录像EX
// FullName:  SN_DVR_PlayBackByTimeEX
// Returns:   LONG							-1=失败，other=播放句柄
// Parameter: LONG lSessionID				登录设备的会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannel					需回放的通道号
// Parameter: LPSN_DVR_TIME lpStartTime		需回放的开始时间	
// Parameter: LPSN_DVR_TIME lpStopTime		需回放的结束时间
// Parameter: HWND hWnd						视频显示窗口句柄
//-----------------------------------------
LONG SN_DVR_PlayBackByTimeEX (LONG lSessionID,
	                          LONG lChannel, 
	                          LPSN_DVR_TIME lpStartTime, 
	                          LPSN_DVR_TIME lpStopTime , 
	                          HWND hWnd); 
//-----------------------------------------
// Method:    22.停止回放
// FullName:  SN_DVR_StopPlayBack
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPlayHandle		播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
//-----------------------------------------
BOOL SN_DVR_StopPlayBack (LONG lPlayHandle);
//-----------------------------------------
// Method:    23.停止回放EX
// FullName:  SN_DVR_StopPlayBackEX
// Returns:   BOOL					true=成功，false=失败 
// Parameter: LONG lPlayHandle		播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
//-----------------------------------------
BOOL SN_DVR_StopPlayBackEX (LONG lPlayHandle);	
//-----------------------------------------
// Method:    24.远程回放控制
// FullName:  SN_DVR_PlayBackControl
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPlayHandle		播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: DWORD dwControlCode	控制码
// Parameter: DWORD dwInValue		控制输入参数
// Parameter: DWORD * lpOutValue	控制反馈输出参数
//-----------------------------------------
BOOL SN_DVR_PlayBackControl(LONG  lPlayHandle,
							DWORD dwControlCode,
							DWORD dwInValue,
							DWORD *lpOutValue);

//-----------------------------------------
// Method:    25.远程回放控制EX
// FullName:  SN_DVR_PlayBackControlEX
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPlayHandle		播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: DWORD dwControlCode	控制码
// Parameter: DWORD dwInValue		控制输入参数
// Parameter: DWORD * lpOutValue	控制反馈输出参数
//-----------------------------------------
BOOL SN_DVR_PlayBackControlEX(LONG  lRemotePlayHandle,
	                          DWORD dwControlCode,
	                          DWORD dwInValue,
	                          DWORD *lpOutValue); 
//-----------------------------------------
// Method:    26.远程回放录像剪辑
// FullName:  SN_DVR_PlayBackSaveData	
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPlayHandle		播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: char * sFileName		保存的本地文件名，完整路径
//-----------------------------------------
BOOL SN_DVR_PlayBackSaveData (LONG lPlayHandle,char *sFileName);
//-----------------------------------------
// Method:    27.远程回放录像剪辑EX
// FullName:  SN_DVR_PlayBackSaveDataEX
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lRemotePlayHandle	远程播放句柄
// Parameter: char * sFileName			保存的本地文件名，完整路径
//-----------------------------------------
BOOL SN_DVR_PlayBackSaveDataEX (LONG lRemotePlayHandle,char *sFileName);
//-----------------------------------------
// Method:    28.停止远程回放录像剪辑
// FullName:  SN_DVR_StopPlayBackSave
// Returns:   BOOL					true=成功，false=失败 
// Parameter: LONG lPlayHandle		播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
//-----------------------------------------
BOOL SN_DVR_StopPlayBackSave(LONG lPlayHandle);
//-----------------------------------------
// Method:    29.停止远程回放录像剪辑EX
// FullName:  SN_DVR_StopPlayBackSaveEX
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lRemotePlayHandle	远程播放句柄	
//-----------------------------------------
BOOL SN_DVR_StopPlayBackSaveEX(LONG lRemotePlayHandle);
//-----------------------------------------
// Method:    30.SN_DVR_SetPlayDataCallBack
// FullName:  SN_DVR_SetPlayDataCallBack
// Returns:   BOOL
// Parameter: LONG lRemotePlayHandle
// Parameter: fPlayDataCallBack cbPlayDataCallBack
// Parameter: DWORD dwUser
//-----------------------------------------
BOOL SN_DVR_SetPlayDataCallBack(LONG lRemotePlayHandle,
	                            fPlayDataCallBack cbPlayDataCallBack,
	                            DWORD dwUser);
//-----------------------------------------
// Method:    31.预览时设备端码流动态产生一个关键帧
// FullName:  SN_DVR_MakeKeyFrame
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID		登录会话ID
// Parameter: LONG lChannel			通道号
// Parameter: DWORD dwStreamID		码流类型   0--主码流 1--子码流
//-----------------------------------------
BOOL SN_DVR_MakeKeyFrame (LONG  lSessionID, 
						  LONG  lChannel,
						  DWORD	dwStreamID); 
//-----------------------------------------
// Method:    32.远程回放抓图(bmp格式)
// FullName:  SN_DVR_PlayBackCaptureFile
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lPlayHandle	播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: char * sFileName	保存的bmp本地文件名，完整路径
//-----------------------------------------
BOOL SN_DVR_PlayBackCaptureFile (LONG lPlayHandle,
								 char *sFileName);
//-----------------------------------------
// Method:    33.远程回放抓图EX(bmp格式)
// FullName:  SN_DVR_PlayBackCaptureFileEX
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lRemotePlayHandle    远程播放句柄
// Parameter: char * sFileName			保存的bmp本地文件名，完整路径
//-----------------------------------------
BOOL SN_DVR_PlayBackCaptureFileEX (LONG lRemotePlayHandle,char *sFileName); 
//-----------------------------------------
// Method:    34.开始实时预览录像
// FullName:  SN_DVR_StartPreviewRecordFile
// Returns:   BOOL						true=成功，false=失败 
// Parameter: LONG lPreviewHandle		预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: char * SavedFileName		录像保存本地文件名
//-----------------------------------------
BOOL SN_DVR_StartPreviewRecordFile(LONG lPreviewHandle,char *SavedFileName);

//-----------------------------------------
// Method:    35.开始实时预览录像Ex
// FullName:  SN_DVR_StartPreviewRecordFileEx
// Returns:   BOOL						true=成功，false=失败 
// Parameter: LONG lPreviewHandle		预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: char * SavedFileName		录像保存本地文件名
//-----------------------------------------
BOOL SN_DVR_StartPreviewRecordFileEx(LONG lPreviewHandle,char *SavedFileName);
//-----------------------------------------
// Method:    36.停止实时预览录像
// FullName:  SN_DVR_StopPreviewRecordFile
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览播放句柄，由SN_DVR_StartPreview返回的有效值
//-----------------------------------------
BOOL SN_DVR_StopPreviewRecordFile(LONG lPreviewHandle);
//-----------------------------------------
// Method:    37.停止实时预览录像Ex
// FullName:  SN_DVR_StopPreviewRecordFileEx
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览播放句柄，由SN_DVR_StartPreview返回的有效值
//-----------------------------------------
BOOL SN_DVR_StopPreviewRecordFileEx(LONG lPreviewHandle);

//-----------------------------------------
// Method:    38.实时预览视频截图
// FullName:  SN_DVR_PreviewCaptureFile
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: char * SavedFileName	截图保存文件名
//-----------------------------------------
BOOL SN_DVR_PreviewCaptureFile(LONG lPreviewHandle,char *SavedFileName);

//-----------------------------------------
// Method:    39.实时预览视频截图Ex
// FullName:  SN_DVR_PreviewCaptureFileEx 
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: char * SavedFileName	截图保存文件名
//-----------------------------------------
BOOL SN_DVR_PreviewCaptureFileEx(LONG lPreviewHandle,char *SavedFileName);

//-----------------------------------------
// Method:    40.分配本地文件播放句柄
// FullName:  SN_File_AllocFilePlayHandle
// Returns:   LONG		-1=失败，other=本地文件播放句柄
//-----------------------------------------
LONG SN_File_AllocFilePlayHandle();	
//-----------------------------------------
// Method:    41.释放本地文件播放句柄
// FullName:  SN_File_FreeFilePlayHandle
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_FreeFilePlayHandle(LONG lFilePlay);

//-----------------------------------------
// Method:    42.指定的播放句柄上打开本地文件	
// FullName:  SN_File_OpenFile
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lFilePlay			本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: char * sLocalFileName		本地文件名
//-----------------------------------------
BOOL SN_File_OpenFile(LONG lFilePlay, char *sLocalFileName); 

//-----------------------------------------
// Method:    43.关闭在播放句柄上打开的本地文件(如果之前没有停止播放，这个函数将首先停止播放)
// FullName:  SN_File_CloseFile
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_CloseFile(LONG lFilePlay);		

//-----------------------------------------
// Method:    44.播放本地录像文件(播放之前在播放句柄上打开的本地文件)
// FullName:  SN_File_Play
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: HWND hWnd			视频播放窗口句柄
//-----------------------------------------
BOOL SN_File_Play(LONG lFilePlay, HWND hWnd);

//-----------------------------------------
// Method:    45.设置播放结束窗口通知消息
// FullName:  SN_File_SetPlayEndMsg
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: HWND hWnd			接收消息窗口句柄
// Parameter: UINT uMsg			自定义窗口消息
//-----------------------------------------
BOOL SN_File_SetPlayEndMsg(LONG lFilePlay, HWND hWnd, UINT uMsg);	

//-----------------------------------------
// Method:    46.停止本地文件播放
// FullName:  SN_File_Stop
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_Stop(LONG lFilePlay);	

//-----------------------------------------
// Method:    47.暂停或播放本地文件
// FullName:  SN_File_Pause
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: BOOL bPause		true=暂停，false=播放
//-----------------------------------------
BOOL SN_File_Pause(LONG lFilePlay, BOOL bPause);	

//-----------------------------------------
// Method:    48.本地播放快进
// FullName:  SN_File_Fast		
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_Fast(LONG lFilePlay);

//-----------------------------------------
// Method:    49.本地播放慢进
// FullName:  SN_File_Slow
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_Slow(LONG lFilePlay);	

//-----------------------------------------
// Method:    50.每秒钟一帧播放
// FullName:  SN_File_OneByOne
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
//注意:流数据播放，不支持一秒钟一帧播放不能调用此接口
//-----------------------------------------
BOOL SN_File_OneByOne(LONG lFilePlay);

//-----------------------------------------
// Method:    51.单帧播放
// FullName:  SN_File_NextFrame
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
//说明:每调一次这个接口，视频才播放一帧，和SN_File_OneByOne有区别,等同于暂停播放，可使用SN_File_Pause进行恢复正常播放
//-----------------------------------------
BOOL SN_File_NextFrame(LONG lFilePlay);	

//-----------------------------------------
// Method:    52.恢复播放
// FullName:  SN_File_Resume
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
//说明:恢复快进、慢放、一秒一帧播放到正常播放
//-----------------------------------------
BOOL SN_File_Resume(LONG lFilePlay);

//-----------------------------------------
// Method:    53.获取当前播放进度	
// FullName:  SN_File_GetPlayPos
// Returns:   BOOL					true=成功，false=失败	
// Parameter: LONG lFilePlay		本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: double * pdPlayPos	当前播放位置，归一化在0~1之间
//-----------------------------------------
BOOL SN_File_GetPlayPos(LONG lFilePlay, double * pdPlayPos);

//-----------------------------------------
// Method:    55.定位本地文件播放
// FullName:  SN_File_SetPlayPos
// Returns:   BOOL				true=成功，false=失败	
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: double dPlayPos	播放位置，归一化在0~1之间
//-----------------------------------------
BOOL SN_File_SetPlayPos(LONG lFilePlay,double dPlayPos);

BOOL SN_File_SetPlayPosEx(LONG lFilePlay,double dPlayPos);

//-----------------------------------------
// Method:    56.播放声音
// FullName:  SN_File_PlaySound
// Returns:   BOOL				true=成功，false=失败				
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_PlaySound(LONG lFilePlay);	

//-----------------------------------------
// Method:    57.停止播放声音
// FullName:  SN_File_StopSound 
// Returns:   BOOL				true=成功，false=失败	
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_StopSound(LONG lFilePlay);

//-----------------------------------------
// Method:    58.设置音量
// FullName:  SN_File_SetVolume
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: DWORD dwVolume	音量大小，范围0-10000
//-----------------------------------------
BOOL SN_File_SetVolume(LONG lFilePlay, DWORD dwVolume);

//-----------------------------------------
// Method:    59.获取音量
// FullName:  SN_File_GetVolume
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lFilePlay		本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: DWORD * pdwVolume		返回音量大小，范围0-10000
//-----------------------------------------
BOOL SN_File_GetVolume(LONG lFilePlay, DWORD *pdwVolume);

//-----------------------------------------
// Method:    60.获取文件播放持续时间
// FullName:  SN_File_GetFileTime 
// Returns:   DWORD				文件播放长度，以毫秒计
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
DWORD SN_File_GetFileTime(LONG lFilePlay);

//-----------------------------------------
// Method:    61.获取文件已经播放时间 
// FullName:  SN_File_GetPlayedTime
// Returns:   DWORD				文件播放时间，以毫秒计
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
DWORD SN_File_GetPlayedTime(LONG lFilePlay);

//-----------------------------------------
// Method:    62.获取文件已经播放帧数
// FullName:  SN_File_GetPlayedFrames
// Returns:   DWORD				已经播放的帧数
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
DWORD SN_File_GetPlayedFrames(LONG lFilePlay);

//-----------------------------------------
// Method:    63.本地文件播放抓图(bmp格式)
// FullName:  SN_File_CaptureFile
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: char * filename	保存的本地文件名
//-----------------------------------------
BOOL SN_File_CaptureFile(LONG lFilePlay,char *filename);
//-----------------------------------------
// Method:    64.本地文件播放抓图Ex(bmp格式)
// FullName:  SN_File_CaptureFileEx 
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lHandle		本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: char * filename	保存的本地文件名
//-----------------------------------------
BOOL SN_File_CaptureFileEx(LONG lHandle, char *filename);	

//-----------------------------------------
// Method:    65.开始本地文件播放剪辑
// FullName:  SN_File_StartRecord 
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
// Parameter: char * filename	保存的本地文件名
//-----------------------------------------
BOOL SN_File_StartRecord(LONG lFilePlay,char *filename);

//-----------------------------------------
// Method:    66.停止本地文件播放剪辑
// FullName:  SN_File_StopRecord
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	本地文件播放句柄，由SN_File_AllocFilePlayHandle的有效值
//-----------------------------------------
BOOL SN_File_StopRecord(LONG lFilePlay);

//-----------------------------------------
// Method:    67.以幻灯片方式打开视频
// FullName:  SN_File_OpenVideoSlide
// Returns:   HSLIDE					后续使用的幻灯片句柄， NULL=失败
// Parameter: char * filename			本地视频文件名
// Parameter: VideoInfo * videoinfo		输出视频帧信息
//-----------------------------------------
HSLIDE	SN_File_OpenVideoSlide(char * filename, VideoInfo * videoinfo);

//-----------------------------------------
// Method:    68.关闭视频幻灯片
// FullName:  SN_File_CloseVideoSlide 
// Returns:   BOOL				true=成功，false=失败
// Parameter: HSLIDE hSlide		幻灯片预览句柄，由SN_File_OpenVideoSlide返回的有效值
//-----------------------------------------
BOOL SN_File_CloseVideoSlide(HSLIDE hSlide);

//-----------------------------------------
// Method:    69.获取指定时间位置的视频幻灯片
// FullName:  SN_File_GetSlidePicture
// Returns:   BOOL					true=成功，false=失败
// Parameter: HSLIDE hSlide			幻灯片预览句柄，由SN_File_OpenVideoSlide返回的有效值
// Parameter: BitmapPict * bitmap	输出视频位图
// Parameter: int64_t timepos		指定的时间位置，以秒计
//-----------------------------------------
BOOL SN_File_GetSlidePicture(HSLIDE hSlide, BitmapPict * bitmap, __int64 timepos);

//-----------------------------------------
// Method:    70.获取指定索引位置的视频幻灯片
// FullName:  SN_File_GetSlidePictureByIndex
// Returns:   BOOL					true=成功，false=失败
// Parameter: HSLIDE hSlide			幻灯片预览句柄，由SN_File_OpenVideoSlide返回的有效值
// Parameter: BitmapPict * bitmap	输出视频位图
// Parameter: int index				指定索引位置,即为_FrameNode的iFrameIndex
//-----------------------------------------
BOOL SN_File_GetSlidePictureByIndex(HSLIDE hSlide,BitmapPict *bitmap,int index);

//-----------------------------------------
// Method:    71.释放位图结构体内部内存
// FullName:  SN_File_ReleaseSlidePicture
// Returns:   BOOL					true=成功，false=失败
// Parameter: BitmapPict * bitmap	输出视频位图
//-----------------------------------------
BOOL SN_File_ReleaseSlidePicture(BitmapPict * bitmap);

//-----------------------------------------
// Method:    72.释放视频信息结构体内部内存
// FullName:  SN_File_ReleaseVideoInfo
// Returns:   BOOL						true=成功，false=失败	
// Parameter: VideoInfo * videoinfo		视频信息结构体
//-----------------------------------------
BOOL SN_File_ReleaseVideoInfo(VideoInfo *videoinfo);
//-----------------------------------------
//音频播放接口
//-----------------------------------------
//函数功能与现有音频播放冲突 未实现 
//-----------------------------------------
// Method:    73.设置声音播放模式（独享/共享）
// FullName:  SN_DVR_SetAudioMode
// Returns:   BOOL			true=成功，false=失败
// Parameter: DWORD dwMode	1－独占声卡，单路音频模式；2－共享声卡，多路音频模式
//-----------------------------------------
BOOL SN_DVR_SetAudioMode (DWORD  dwMode);
//-----------------------------------------
// Method:    74.独占声卡模式下开启某一个预览播放通道声音
// FullName:  SN_DVR_OpenSound
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览句柄
//-----------------------------------------
BOOL SN_DVR_OpenSound (LONG lPreviewHandle);
//-----------------------------------------
// Method:    75.独占声卡模式下关闭某一个预览播放通道声音
// FullName:  SN_DVR_CloseSound
// Returns:   BOOL		true=成功，false=失败
//-----------------------------------------
BOOL SN_DVR_CloseSound();
//-----------------------------------------
// Method:    76.共享声卡模式下开启一路声音
// FullName:  SN_DVR_OpenSoundShare
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览句柄
//-----------------------------------------
BOOL SN_DVR_OpenSoundShare (LONG lPreviewHandle); 
//-----------------------------------------
// Method:    77.共享声卡模式下关闭一路声音
// FullName:  SN_DVR_CloseSoundShare
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览句柄
//-----------------------------------------
BOOL SN_DVR_CloseSoundShare(LONG lPreviewHandle);

//-----------------------------------------
// Method:    78.设置实时预览音频音量
// FullName:  SN_DVR_Volume
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	实时预览句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: WORD wVolume			音量大小，范围0-10000
//-----------------------------------------
BOOL SN_DVR_Volume (LONG  lPreviewHandle,WORD  wVolume); 
//-----------------------------------------
// Method:    79.开始音频播放剪辑
// FullName:  SN_DVR_StartAudioRecord
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lPreviewHandle		预览句柄
// Parameter: char * SavedFileName		保存的文件名
//-----------------------------------------
BOOL SN_DVR_StartAudioRecord(LONG lPreviewHandle,char *SavedFileName);

//-----------------------------------------
// Method:    80.停止音频播放剪辑
// FullName:  SN_DVR_StopAudioRecord
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	预览句柄
//-----------------------------------------
BOOL SN_DVR_StopAudioRecord(LONG lPreviewHandle);

//-----------------------------------------
// Method:    81.云台基本控制（焦距 焦点 光圈 转动 不带速度）
// FullName:  SN_DVR_PTZControl
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: DWORD dwPTZCommand	控制命令
// Parameter: BOOL bStop			是否停止
//-----------------------------------------
BOOL SN_DVR_PTZControl (LONG  lPreviewHandle,
						DWORD dwPTZCommand,
						BOOL  bStop);	

//-----------------------------------------
// Method:    82.云台基本控制（焦距 焦点 光圈 转动 带速度）
// FullName:  SN_DVR_PTZControlWithSpeed
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: DWORD dwPTZCommand	控制命令
// Parameter: DWORD dwSpeed			云台动作速度
// Parameter: BOOL bStop			是否停止
//-----------------------------------------
BOOL SN_DVR_PTZControlWithSpeed(LONG  lPreviewHandle,
								DWORD dwPTZCommand,
								DWORD dwSpeed,
								BOOL  bStop);

//-----------------------------------------
// Method:    83.云台预置点控制
// FullName:  SN_DVR_PTZPreset
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lPreviewHandle		实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: DWORD dwPTZPresetCmd		预置点控制命令
// Parameter: DWORD dwPresetIndex		云台预置点索引
//-----------------------------------------
BOOL SN_DVR_PTZPreset (LONG  lPreviewHandle,
					   DWORD dwPTZPresetCmd,
					   DWORD dwPresetIndex);

//-----------------------------------------
// Method:    84.云台巡航控制
// FullName:  SN_DVR_PTZCruise
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lPreviewHandle		实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: DWORD dwPTZCruiseCmd		巡航控制命令
// Parameter: BYTE byCruiseRoute		云台巡航路径号
// Parameter: BYTE byCruisePoint		云台巡航路径关键点号
// Parameter: BYTE byPresetIndex		云台对应的预置点号
// Parameter: BYTE byStayTime			预置点停留时间
// Parameter: BYTE bySpeed				云台转动速度
//-----------------------------------------
BOOL SN_DVR_PTZCruise(LONG  lPreviewHandle,
					  DWORD dwPTZCruiseCmd,
					  BYTE  byCruiseRoute, 
					  BYTE  byCruisePoint, 
					  BYTE	byPresetIndex,
					  BYTE  byStayTime,
					  BYTE  bySpeed);

//-----------------------------------------
// Method:    85.云台轨迹控制
// FullName:  SN_DVR_PTZTrack
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: DWORD dwPTZTrackCmd	轨迹控制命令
//-----------------------------------------
BOOL SN_DVR_PTZTrack (LONG lPreviewHandle,DWORD dwPTZTrackCmd);

//-----------------------------------------
// Method:    86.云台透传控制
// FullName:  SN_DVR_PTZDirectControl
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: BYTE * pPTZCodeBuf	控制命令透传缓冲区
// Parameter: DWORD dwBufSize		控制缓冲区大小
//-----------------------------------------
BOOL SN_DVR_PTZDirectControl (LONG  lPreviewHandle,
					          BYTE  *pPTZCodeBuf,
					          DWORD dwBufSize);
//-----------------------------------------
//云台控制特殊接口
//通过会话ID和通道号进行索引控制
//-----------------------------------------
// Method:    87.不带速度云台控制特殊接口(通过会话ID lSessionID和通道号lChannelNO进行控制)
// FullName:  SN_DVR_PTZControl_Special
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID		会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannelID		云台所在通道号
// Parameter: DWORD dwPTZCommand	控制命令
// Parameter: BOOL bStop			是否停止
//-----------------------------------------
BOOL SN_DVR_PTZControl_Special (LONG  lSessionID,	
								LONG  lChannelID, 
								DWORD dwPTZCommand,
								BOOL  bStop);

//-----------------------------------------
// Method:    88.带速度云台控制特殊接口(通过会话ID lSessionID和通道号lChannelNO进行控制)
// FullName:  SN_DVR_PTZControlWithSpeed_Special
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID		会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannelNO		云台所在通道号
// Parameter: DWORD dwPTZCommand	控制命令
// Parameter: DWORD dwSpeed			云台动作速度
// Parameter: BOOL bStop			是否停止
//-----------------------------------------
BOOL SN_DVR_PTZControlWithSpeed_Special(LONG  lSessionID,
										LONG  lChannelNO,	
										DWORD dwPTZCommand,
										DWORD dwSpeed,
										BOOL  bStop);

//-----------------------------------------
// Method:    89.云台预置点控制特殊接口(通过会话ID和通道号进行索引控制)
// FullName:  SN_DVR_PTZPreset_Special
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lSessionID			会话ID，由SN_DVR_UserLogon返回的有效值			
// Parameter: LONG lChannelNO			云台所在通道号
// Parameter: DWORD dwPTZPresetCmd		预置点控制命令
// Parameter: DWORD dwPresetIndex		云台预置点索引
//-----------------------------------------
BOOL SN_DVR_PTZPreset_Special (LONG  lSessionID,	
							   LONG  lChannelNO, 
							   DWORD dwPTZPresetCmd,
							   DWORD dwPresetIndex);

//-----------------------------------------
// Method:    90.云台巡航特殊接口(通过会话ID和通道号进行索引控制)
// FullName:  SN_DVR_PTZCruise_Special
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lSessionID			会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannelNO			云台所在通道号
// Parameter: DWORD dwPTZCruiseCmd		巡航控制命令
// Parameter: BYTE byCruiseRoute		云台巡航路径号
// Parameter: BYTE byCruisePoint		云台巡航路径关键点号
// Parameter: BYTE byPresetIndex		云台对应的预置点号
// Parameter: BYTE byStayTime			预置点停留时间
// Parameter: BYTE bySpeed				云台转动速度
//-----------------------------------------
BOOL SN_DVR_PTZCruise_Special(LONG  lSessionID,	
							  LONG  lChannelNO,   
							  DWORD dwPTZCruiseCmd,
							  BYTE  byCruiseRoute, 
							  BYTE  byCruisePoint, 
							  BYTE	byPresetIndex,
							  BYTE  byStayTime,
							  BYTE  bySpeed);

//-----------------------------------------
// Method:    91.云台轨迹特殊接口(通过会话ID和通道号直接控制)
// FullName:  SN_DVR_PTZTrack_Special
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID		会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannelNO		云台所在通道号
// Parameter: DWORD dwPTZTrackCmd	轨迹控制命令
//-----------------------------------------
BOOL SN_DVR_PTZTrack_Special (LONG  lSessionID,
							  LONG  lChannelNO,
							  DWORD dwPTZTrackCmd);

//-----------------------------------------
// Method:    云台轨迹特殊接口EX
// FullName:  SN_DVR_PTZTrack_SpecialEX
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID		会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannelNO		云台所在通道号
// Parameter: LONG lbyTrackRoute	云台轨迹号(轨迹号从0开始)
// Parameter: DWORD dwPTZTrackCmd	轨迹控制命令
//-----------------------------------------
BOOL SN_DVR_PTZTrack_SpecialEX (LONG  lSessionID,
								LONG  lChannelNO,	
								LONG  lbyTrackRoute,
								DWORD dwPTZTrackCmd);
//-----------------------------------------
// Method:    云台轨迹控制EX
// FullName:  SN_DVR_PTZTrackEX 
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lPreviewHandle	实时预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: LONG lbyTrackRoute	云台轨迹号(轨迹号从0开始)
// Parameter: DWORD dwPTZTrackCmd	轨迹控制命令
//-----------------------------------------
BOOL SN_DVR_PTZTrackEX (LONG lPreviewHandle,
						LONG lbyTrackRoute,
						DWORD dwPTZTrackCmd);

//-----------------------------------------
// Method:    92.云台透传控制特殊接口(通过会话ID和通道号索引控制)
// FullName:  SN_DVR_PTZDirectControl_Special
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID		会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannelNO		云台所在通道号
// Parameter: BYTE * pPTZCodeBuf	控制命令透传缓冲区
// Parameter: DWORD dwBufSize		控制缓冲区大小
//-----------------------------------------
BOOL SN_DVR_PTZDirectControl_Special (LONG  lSessionID,	
									  LONG  lChannelNO,  
									  BYTE  *pPTZCodeBuf,
									  DWORD dwBufSize);

//-----------------------------------------
// Method:    解码器云台控制通道切换等操作前,停止轮询消息接口
// FullName:  SN_NVS_StopPTZSwitchControl
// Returns:   BOOL														
// Parameter: LONG lSessionID								
// Parameter: LPSN_NVS_STOP_PTZSWITCH_REQ pSwitchControl
//-----------------------------------------
BOOL SN_NVS_StopPTZSwitchControl(LONG lSessionID, 
								 LPSN_NVS_STOP_PTZSWITCH_REQ pSwitchControl);
//-----------------------------------------
// Method:    93.获取设备通道相应的配置参数信息
// FullName:  SN_DVR_GetDeviceConfig 
// Returns:   BOOL						[out],true=成功，false=失败						
// Parameter: LONG lSessionID			[in],会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannel				[in],通道号，从0开始
// Parameter: DWORD dwConfigType		[in],参见DEVICE_CONFIGURE_CLASS枚举类型
// Parameter: LPVOID lpOutBuffer		[in],配置参数相应的结构体，指针引用
// Parameter: DWORD dwOutBufferSize		[in],配置参数的空间大小
// Parameter: LPDWORD lpBytesReturned   [out],实际读取数据的大小
//-----------------------------------------
BOOL SN_DVR_GetDeviceConfig (LONG    lSessionID,
 							 LONG    lChannel, 
 							 DWORD   dwConfigType,
 							 LPVOID  lpOutBuffer,
 							 DWORD   dwOutBufferSize,
 							 LPDWORD lpBytesReturned); 

//-----------------------------------------
// Method:    94.设置设备相应的配置参数信息
// FullName:  SN_DVR_SetDeviceConfig
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lSessionID			会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lChannel
// Parameter: DWORD dwConfigType		DEVICE_CONFIGURE_CLASS枚举类型
// Parameter: LPVOID lpInBuffer			相应结构体指针
// Parameter: DWORD dwInBufferSize
//在用户信息更新时需将更新用户设定为指定struUser[0]的信息
//-----------------------------------------
BOOL SN_DVR_SetDeviceConfig(LONG   lSessionID,
							LONG   lChannel,  
							DWORD  dwConfigType,
							LPVOID lpInBuffer,
							DWORD  dwInBufferSize);


//-----------------------------------------
// Method:    95.获取云台协议
// FullName:  SN_DVR_GetPTZProtocol
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lSessionID			会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_DVR_PTZCFG pPtzCfg
//-----------------------------------------
BOOL SN_DVR_GetPTZProtocol (LONG lSessionID,LPSN_DVR_PTZCFG pPtzCfg);
//-----------------------------------------
//磁盘管理接口
//-----------------------------------------
// Method:    96.远程格式化硬盘
// FullName:  SN_DVR_FormatDisk 
// Returns:   LONG					格式化过程句柄
// Parameter: LONG lSessionID		会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: LONG lDiskNumber
//-----------------------------------------
LONG SN_DVR_FormatDisk (LONG lSessionID,LONG lDiskNumber); 
//-----------------------------------------
// Method:    97.关闭SN_DVR_FormatDisk接口所创建的句柄，释放资源
// FullName:  SN_DVR_CloseFormatHandle
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lFormatHandle
//-----------------------------------------
BOOL SN_DVR_CloseFormatHandle (LONG lFormatHandle);
//-----------------------------------------
// Method:    98.获取格式化的进度
// FullName:  SN_DVR_GetFormatProgress
// Returns:   BOOL
// Parameter: LONG lFormatHandle
// Parameter: LONG * pCurrentFormatingDiskNO
// Parameter: LONG * pCurrentDiskPos			进度百分比数值
// Parameter: LONG * pFormatState
//-----------------------------------------
BOOL SN_DVR_GetFormatProgress (LONG lFormatHandle,
							   LONG *pCurrentFormatingDiskNO,
							   LONG *pCurrentDiskPos,
							   LONG *pFormatState);
//-----------------------------------------
// Method:    99.设置来自远端设备的告警消息回调,只能调用一次
// FullName:  SN_DVR_SetDVRMessageCallBack
// Returns:   BOOL,TRUE=成功,FALSE=失败
// Parameter: PFN_DEVICEMSGCallBack fMessageCallBack，告警回调指针
// Parameter: void * pContext						  用户自定义指针
//-----------------------------------------
BOOL SN_DVR_SetDVRMessageCallBack(PFN_DEVICEMSGCallBack fMessageCallBack,void *pContext);	

//-----------------------------------------
// Method:    100.设备设置了报警IP和端口，软件主动监听
// FullName:  SN_DVR_StartListenMessage
// Returns:   LONG
// Parameter: char * sLocalIP
// Parameter: WORD wLocalPort
// Parameter: PFN_DEVICEMSGCallBack pfnCallback
// Parameter: void * pContext
//-----------------------------------------
LONG SN_DVR_StartListenMessage (char  *sLocalIP, 
								WORD  wLocalPort, 
								PFN_DEVICEMSGCallBack  pfnCallback , 
								void  *pContext );
//-----------------------------------------
// Method:    101.停止软件主动监听
// FullName:  SN_DVR_StopListenMessage
// Returns:   BOOL
// Parameter: LONG lListenHandle
//-----------------------------------------
BOOL SN_DVR_StopListenMessage(LONG lListenHandle);


//---------------------------------------------------------------------------------------
//远程文件接口
//---------------------------------------------------------------------------------------
// Method:    102.按照查找条件查找文件（类似windows的文件查找）
// FullName:  SN_DVR_FindFirstFile
// Returns:   LONG										[out],查找句柄，查找成功将在lpFileData返回第一条文件信息
// Parameter: LPSN_DVR_FILECONDITION lpFileCondition	[in] ,查找条件
// Parameter: LPSN_DVR_FILEDATA lpFileData				[out],找到的文件信息
//-----------------------------------------
LONG SN_DVR_FindFirstFile(LPSN_DVR_FILECONDITION lpFileCondition,LPSN_DVR_FILEDATA lpFileData);	

//-----------------------------------------
// Method:    103.查找下一个文件信息
// FullName:  SN_DVR_FindNextFile
// PairFun:   SN_DVR_FindFirstFile、SN_DVR_FindClose
// Returns:   BOOL								true=成功，false=查询失败或者到达文件尾			
// Parameter: LONG lFindHandle					查找句柄,devSID
// Parameter: LPSN_DVR_FILEDATA lpFileData		找到的文件信息
//-----------------------------------------
BOOL SN_DVR_FindNextFile(LONG lFindHandle,LPSN_DVR_FILEDATA lpFileData);

//-----------------------------------------
// Method:    104.关闭文件查找，释放资源
// FullName:  SN_DVR_FindClose
// Returns:   BOOL					true=成功，false=失败	
// Parameter: LONG lFindHandle		查找句柄,devSID
//-----------------------------------------
BOOL SN_DVR_FindClose (LONG lFindHandle);

//-----------------------------------------
// Method:    105.按照文件名下载文件
// FullName:  SN_DVR_DownloadFileByName 
// Returns:   LONG						下载句柄
// Parameter: LONG lSessionID			会话SID
// Parameter: char * sDVRFileName		DVR存储的文件名
// Parameter: char * sSavedFileName		用户保存的文件名
//-----------------------------------------
LONG SN_DVR_DownloadFileByName (LONG lSessionID,
								char *sDVRFileName,
								char *sSavedFileName);

//-----------------------------------------
// Method:    106.停止下载
// FullName:  SN_DVR_StopDownloadFile
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lDownloadHandle		SN_DVR_DownloadFileByTime或者SN_DVR_DownloadFileByName的返回值
//-----------------------------------------
BOOL SN_DVR_StopDownloadFile (LONG lDownloadHandle);
//-----------------------------------------
// Method:    107.按照时间下载文件
// FullName:  SN_DVR_DownloadFileByTime
// Returns:   LONG							下载句柄
// Parameter: LONG lSessionID				会话SID
// Parameter: LONG lChannel					通道号
// Parameter: LPSN_DVR_TIME lpStartTime		开始时间
// Parameter: LPSN_DVR_TIME lpStopTime		结束时间
// Parameter: char * sSavedFileName			用户保存的文件名
//-----------------------------------------
LONG SN_DVR_DownloadFileByTime (LONG lSessionID,	
								LONG lChannel, 
								LPSN_DVR_TIME lpStartTime, 
								LPSN_DVR_TIME lpStopTime, 
								char *sSavedFileName); 

//-----------------------------------------
// Method:    108.获取当前下载进度
// FullName:  SN_DVR_GetDownloadPos
// Returns:   int						下载进度 0-1000  1000表示下载完成
// Parameter: LONG lDownloadHandle
//-----------------------------------------
int SN_DVR_GetDownloadPos (LONG lDownloadHandle); 

//-----------------------------------------
// Method:    109.关闭下载句柄
// FullName:  SN_DVR_CloseDownloadHandle
// Returns:   BOOL						true=成功，false=失败
// Parameter: long lDownloadHandle
//-----------------------------------------
BOOL SN_DVR_CloseDownloadHandle(long lDownloadHandle);
//-----------------------------------------
//远程日志接口
//-----------------------------------------
// Method:    110.根据条件查询日志
// FullName:  SN_DVR_FindFirstDeviceLog
// Returns:   LONG									第一条日志信息		
// Parameter: LPSN_LOG_CONDITION lpLogCondition
// Parameter: LPSN_DEVICE_LOGDATA lpDeviceLogData
//-----------------------------------------
LONG SN_DVR_FindFirstDeviceLog(LPSN_LOG_CONDITION lpLogCondition,
							   LPSN_DEVICE_LOGDATA lpDeviceLogData);

//-----------------------------------------
// Method:    111.查找下一条日志信息
// FullName:  SN_DVR_FindNextDeviceLog
// Returns:   BOOL
// Parameter: LONG lLogHandle
// Parameter: LPSN_DEVICE_LOGDATA lpDeviceLogData
//-----------------------------------------
BOOL SN_DVR_FindNextDeviceLog (LONG lLogHandle,LPSN_DEVICE_LOGDATA lpDeviceLogData);

//-----------------------------------------
// Method:    112.关闭日志查找
// FullName:  SN_DVR_FindDeviceLogClose 
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lLogHandle
//-----------------------------------------
BOOL SN_DVR_FindDeviceLogClose (LONG  lLogHandle);

//-----------------------------------------
//对讲接口
//-----------------------------------------
//----------------------------------------
// Method:    设备语音对讲2秒无流超时回调
// FullName:  NSdk_Dvr_SetTalkBackTimeOutFun
// Access:    public 
// Parameter: PFN_TalkBackTimeOutCallBack pFun
// void *pContext
//----------------------------------------
BOOL SN_DVR_SetTalkBackTimeOutFun(PFN_TalkBackTimeOutCallBack pFun, void *pContext);

//----------------------------------------
// Method:    113.开始语音对讲
// FullName:  SN_DVR_StartVoiceCom
// Returns:   LONG						失败=-1,成功=设备会话SID					
// Parameter: LONG lSessionID			设备会话SID
// Parameter: DWORD dwVoiceChan			对讲通道,暂时固定为0
// Parameter: BOOL bNeedCBNoEncData		需要回调的语音数据类型 ：0－编码后的语音数据，1－编码前的PCM原始数据
// Parameter: PFN_VOICEDATACALLBACK fVoiceDataCallBack	语音对讲
// Parameter: void * pContext			用户自定义指针
//-----------------------------------------
LONG SN_DVR_StartVoiceCom(LONG  lSessionID,
						  DWORD  dwVoiceChan,		
						  BOOL  bNeedCBNoEncData,	
						  PFN_VOICEDATACALLBACK fVoiceDataCallBack, 
						  void  *pContext);	
//-----------------------------------------
// Method:    114.设置语音对讲客户端的音量
// FullName:  SN_DVR_SetVoiceComClientVolume
// Access:    public 
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lVoiceComHandle
// Parameter: WORD wVolume
//-----------------------------------------
BOOL SN_DVR_SetVoiceComClientVolume (LONG lVoiceComHandle,WORD wVolume); 
//-----------------------------------------
// Method:    115.停止语音对讲
// FullName:  SN_DVR_StopVoiceCom 
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lVoiceComHandle
//-----------------------------------------
BOOL SN_DVR_StopVoiceCom (LONG lVoiceComHandle); 
//-----------------------------------------
//设备控制接口
//-----------------------------------------
// Method:    116.远程设备重启
// FullName:  SN_DVR_RebootDevice 
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID
//-----------------------------------------
BOOL SN_DVR_RebootDevice(LONG lSessionID);	
//-----------------------------------------
// Method:    117.远程设备关机
// FullName:  SN_DVR_ShutdownDevice		
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID
//-----------------------------------------
BOOL SN_DVR_ShutdownDevice(LONG lSessionID);
//-----------------------------------------
//维护接口
//-----------------------------------------
// Method:    118.设备校时
// FullName:  SN_DVR_Time_Correction
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lSessionID
// Parameter: LPSN_DVR_TIME pCurTime
//-----------------------------------------
BOOL SN_DVR_Time_Correction(LONG lSessionID,LPSN_DVR_TIME pCurTime);
//-----------------------------------------
// Method:    119.获取设备状态
// FullName:  SN_DVR_GetDeviceState
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LPSN_DEVICE_STATE lpDeviceState
//-----------------------------------------
BOOL SN_DVR_GetDeviceState(LONG lSessionID,LPSN_DEVICE_STATE lpDeviceState);

//-----------------------------------------
// Method:    120.恢复设备默认配置（恢复所有参数到出厂值，包括网络参数，可能造成网络连接断开）
// FullName:  SN_DVR_RestoreConfig
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID	会话ID，由SN_DVR_UserLogon返回的有效值
//-----------------------------------------
BOOL SN_DVR_RestoreConfig(LONG lSessionID);

//-----------------------------------------
// Method:    121.恢复设备默认配置(网络设置不恢复)
// FullName:  SN_DVR_RestoreConfigExceptNet 
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID	会话ID，由SN_DVR_UserLogon返回的有效值
//-----------------------------------------
BOOL SN_DVR_RestoreConfigExceptNet(LONG lSessionID);

//-----------------------------------------
// Method:    122.设备升级
// FullName:  SN_DVR_Upgrade
// Returns:   LONG
// Parameter: LONG lSessionID	会话ID
// Parameter: char * sFileName	升级文件的文件名
//-----------------------------------------
LONG SN_DVR_Upgrade (LONG lSessionID,char *sFileName);

//-----------------------------------------
// Method:    123.关闭设备升级句柄
// FullName:  SN_DVR_CloseUpgradeHandle 
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lUpgradeHandle
//-----------------------------------------
BOOL SN_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);

//-----------------------------------------
// Method:    124.获取设备升级过程
// FullName:  SN_DVR_GetUpgradeProgress
// Returns:   int
// Parameter: LONG lUpgradeHandle
//-----------------------------------------
int SN_DVR_GetUpgradeProgress (LONG lUpgradeHandle);

//-----------------------------------------
// Method:    125.获取设备升级状态
// FullName:  SN_DVR_GetUpgradeState
// Returns:   int					-1=失败，0=升级成功，1=升级成功，2=升级失败，3=设备正在操作
// Parameter: LONG lUpgradeHandle
//-----------------------------------------
int SN_DVR_GetUpgradeState (LONG lUpgradeHandle);
						 
//-----------------------------------------
// Method:    126.获取配置文件
// FullName:  SN_DVR_GetConfigFile
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID
// Parameter: char * sFileName
//-----------------------------------------
BOOL SN_DVR_GetConfigFile(LONG lSessionID,char *sFileName);
						   
//-----------------------------------------
// Method:    127.获取配置文件Ex
// FullName:  SN_DVR_GetConfigFileEx
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID
// Parameter: char * sOutBuffer
// Parameter: DWORD dwOutSize
// Parameter: DWORD * pReturnSize
//-----------------------------------------
BOOL SN_DVR_GetConfigFileEx (LONG  lSessionID, 
							 char  *sOutBuffer, 
							 DWORD dwOutSize, 
							 DWORD *pReturnSize);
										  
//-----------------------------------------
// Method:    128.设置配置文件
// FullName:  SN_DVR_SetConfigFile
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID
// Parameter: char * sFileName
//-----------------------------------------
BOOL SN_DVR_SetConfigFile(LONG lSessionID,char *sFileName);
						   
//-----------------------------------------
// Method:    129.设置配置文件Ex
// FullName:  SN_DVR_SetConfigFileEx
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lSessionID
// Parameter: char * sInBuffer
// Parameter: DWORD dwInSize
//-----------------------------------------
BOOL SN_DVR_SetConfigFileEx(LONG  lSessionID, 
							char  *sInBuffer, 
							DWORD dwInSize);
							  

								


//-----------------------------------------
//远程面板控制
//-----------------------------------------
// BOOL SN_DVR_INTERFACE  SN_DVR_ClickDevicePanelKey(LONG lSessionID,LONG lKeyIndex);
// BOOL SN_DVR_INTERFACE  SN_DVR_LockDevicePanel(LONG lSessionID);
// BOOL SN_DVR_INTERFACE  SN_DVR_UnlockDevicePanel(LONG lSessionID);
//-----------------------------------------
// SDK版本信息
//-----------------------------------------
// Method:    130.获取版本信息
// FullName:  SN_DVR_GetSDKVersion
// Returns:   BOOL
// Parameter: SN_SDK_VERSIONINFO *lpSDKVersionInfo
//-----------------------------------------
BOOL SN_DVR_GetSDKVersion(SN_SDK_VERSIONINFO *lpSDKVersionInfo);

//-----------------------------------------
// Method:    131.对已经打开的文件播放句柄，输入流数据头部打开相应的流
// FullName:  SN_File_OpenStream
// Returns:   BOOL						true=成功，false=失败
// Parameter: LONG lFilePlay			文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值
// Parameter: PBYTE pFileHeaderBuf		流数据头部指针，相应PFN_PREVIEWCALLBACK回调的SN_DVR_STREAMHEAD数据
// Parameter: DWORD nSize				流数据头部长度
// Parameter: DWORD nReserve			保留值，请传递0值
//-----------------------------------------
BOOL SN_File_OpenStream(LONG  lFilePlay, 
						PBYTE pFileHeaderBuf, 
						DWORD nSize, 
						DWORD nReserve);
//-----------------------------------------
// Method:    132.对已经打开的文件播放句柄，输入流数据(注意：如果数据输入失败，必须重试直到返回TRUE)
// FullName:  SN_File_InputData
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值
// Parameter: PBYTE pBuf		流数据指针，相应PFN_PREVIEWCALLBACK回调的SN_DVR_STREAMDATA数据
// Parameter: DWORD nBuf		流数据长度
//-----------------------------------------
BOOL SN_File_InputData(LONG lFilePlay, PBYTE pBuf, DWORD nBuf);

//-----------------------------------------
// Method:    133.对已经打开的文件播放句柄，结束流输入
// FullName:  SN_File_SetStreamEnd
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值
//-----------------------------------------
BOOL SN_File_SetStreamEnd(LONG lFilePlay);

//-----------------------------------------
// Method:    134.对已经打开的文件播放句柄，关闭流
// FullName:  SN_File_CloseStream
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值
//-----------------------------------------
BOOL SN_File_CloseStream(LONG lFilePlay);

//-----------------------------------------
// Method:    135.对已经打开的文件播放句柄，设置播放显示回调
// FullName:  SN_File_SetDisplayCallBack 
// Returns:   BOOL											true=成功，false=失败
// Parameter: LONG lFilePlay								文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值
// Parameter: PFN_DISPLAYCALLBACKFUNCTION pfnDisplayCB		显示回调函数指针
// Parameter: void * pContext								用户自定义数据指针
//-----------------------------------------
BOOL SN_File_SetDisplayCallBack(LONG lFilePlay, 
								PFN_DISPLAYCALLBACKFUNCTION  pfnDisplayCB, 
						        void *pContext);


//-----------------------------------------
// Method:    136.设置实时预览显示回调
// FullName:  SN_DVR_SetPreviewDisplayCallBack
// Returns:   BOOL											true=成功，false=失败
// Parameter: LONG lPreviewHandle							预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: PFN_DISPLAYCALLBACKFUNCTION pfnDisplayCB		显示回调函数指针
// Parameter: void * pContext								用户自定义数据指针
//-----------------------------------------
BOOL SN_DVR_SetPreviewDisplayCallBack(LONG lPreviewHandle, 
									  PFN_DISPLAYCALLBACKFUNCTION pfnDisplayCB, 
									  void *pContext); 

//-----------------------------------------
// Method:    137.设置实时预览显示回调Ex
// FullName:  SN_DVR_SetPreviewDisplayCallBackEx 
// Returns:   BOOL											true=成功，false=失败
// Parameter: LONG lPreviewHandle							预览播放句柄，由SN_DVR_StartPreview返回的有效值
// Parameter: PFN_DISPLAYCALLBACKFUNCTION pfnDisplayCB		显示回调函数指针
// Parameter: void * pContext								用户自定义数据指针
//-----------------------------------------
BOOL SN_DVR_SetPreviewDisplayCallBackEx(LONG lPreviewHandle, 
										PFN_DISPLAYCALLBACKFUNCTION  pfnDisplayCB, 
										void *pContext); 

//-----------------------------------------
// Method:    138.设置Gps回调
// FullName:  SN_DVR_SetGpsCallBack
// Returns:   BOOL								true=成功，false=失败
// Parameter: LONG lPreviewHandle
// Parameter: PFN_GPSCALLBACK pfnGpsCallBack
// Parameter: void * pContext
//-----------------------------------------
BOOL SN_DVR_SetGpsCallBack(LONG lPreviewHandle,
						   PFN_GPSCALLBACK pfnGpsCallBack,
						   void *pContext);

//-----------------------------------------
// Method:    139.设置远程回放显示回调
// FullName:  SN_DVR_SetDisplayCallBack 
// Returns:   BOOL											true=成功，false=失败
// Parameter: LONG lRemoteHandle							播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: PFN_DISPLAYCALLBACKFUNCTION pfnDisplayCB		显示回调函数指针
// Parameter: void * pContext								用户自定义数据指针
//-----------------------------------------
BOOL SN_DVR_SetDisplayCallBack(LONG lRemoteHandle, 
							   PFN_DISPLAYCALLBACKFUNCTION  pfnDisplayCB, 
							   void *pContext); 
//-----------------------------------------
// Method:    140.设置远程回放显示回调EX
// FullName:  SN_DVR_SetDisplayCallBackEX 
// Returns:   BOOL											true=成功，false=失败
// Parameter: LONG lRemoteHandle							播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: PFN_DISPLAYCALLBACKFUNCTION pfnDisplayCB		显示回调函数指针
// Parameter: void * pContext								用户自定义数据指针
//-----------------------------------------
BOOL SN_DVR_SetDisplayCallBackEX(LONG lRemoteHandle, 
								 PFN_DISPLAYCALLBACKFUNCTIONEX  pfnDisplayCB, 
								 void *pContext); 

//-----------------------------------------
// Method:    141.设置远程回放显示Gps回调
// FullName:  SN_DVR_SetDisplayGpsCallBack
// Returns:   BOOL											true=成功，false=失败
// Parameter: LONG lRemoteHandle							播放句柄，由SN_DVR_PlayBackByFileName返回的有效值
// Parameter: PFN_DISPLAYGPSCALLBACK pfnDisplayGpsCallBack	显示回调函数指针
// Parameter: void * pContext								用户自定义数据指针
//-----------------------------------------
BOOL SN_DVR_SetDisplayGpsCallBack(LONG lRemoteHandle,
								  PFN_DISPLAYGPSCALLBACK pfnDisplayGpsCallBack,
								  void *pContext);


//-----------------------------------------
// Method:    142.平台开始监听接口
// FullName:  SN_DVR_PlatformStartListen
// Returns:   BOOL									true=成功，false=失败
// Parameter: PSN_DVR_PlatformInfo pPlatformInfo	平台监听信息，包括TCP/UDP监听端口
//-----------------------------------------
//BOOL SN_DVR_PlatformStartListen(PSN_DVR_PlatformInfo pPlatformInfo);

//-----------------------------------------
// Method:    143.平台停止监听接口
// FullName:  SN_DVR_PlatformStopListen
// Returns:   BOOL		true=成功，false=失败				
//-----------------------------------------
BOOL SN_DVR_PlatformStopListen() ;

//-----------------------------------------
// Method:    144.开启设备手动录像
// FullName:  SN_DVR_StartDVRRecord
// Returns:   BOOL					true=成功，false=失败(获取错误码调用SN_DVR_GetLastError)
// Parameter: LONG lSessionID		SN_DVR_UserLogon()的返回值 
// Parameter: LONG lChannel			通道号 
// Parameter: LONG lRecordType		录像类型(此参数暂时保留) 
//-----------------------------------------
BOOL SN_DVR_StartDVRRecord(LONG lSessionID,
						   LONG lChannel,
						   LONG lRecordType);

//-----------------------------------------
// Method:    145.关闭设备手动录像
// FullName:  SN_DVR_StopDVRRecord
// Returns:   BOOL				true=成功，false=失败(获取错误码调用SN_DVR_GetLastError)
// Parameter: LONG lSessionID	SN_DVR_UserLogon()的返回值 
// Parameter: LONG lChannel		通道号
//-----------------------------------------
BOOL SN_DVR_StopDVRRecord(LONG lSessionID,LONG lChannel);

//-----------------------------------------
// Method:    146.设置设备报警输出
// FullName:  SN_DVR_SetAlarmOut
// Returns:   BOOL						true=成功，false=失败(获取错误码调用SN_DVR_GetLastError)
// Parameter: LONG lSessionID			会话ID, SN_DVR_UserLogon的返回值 
// Parameter: DWORD dwAlarmOutPort		报警输出口。初始输出口从0开始 
// Parameter: DWORD dwAlarmOutStatic	报警输出状态：0－停止输出，1－输出 
//-----------------------------------------
BOOL SN_DVR_SetAlarmOut(LONG  lSessionID,
						DWORD dwAlarmOutPort,
						DWORD dwAlarmOutStatic);


//-----------------------------------------
// Method:    SN_DVR_SnapDevPicture
// FullName:  SN_DVR_SnapDevPicture
// Returns:   BOOL
// Parameter: LONG lSessionID			登陆句柄
// Parameter: char * pFileName			图片本地存放文件名 若要输入绝对路径不要使用'\'符号,使用'/'或'\\'来表示
// Parameter: LPSN_DVR_SNAP_REQ pReq	抓图信息
//-----------------------------------------
BOOL SN_DVR_SnapDevPicture(LONG lSessionID,
						   char *pFileName,			
						   LPSN_DVR_SNAP_REQ pReq);

//-----------------------------------------
// Method:    147.设置颜色
// FullName:  SN_File_SetColor
// Returns:   BOOL
// Parameter: LONG lFilePlay
// Parameter: DWORD dwRegionNum
// Parameter: int iBrightness
// Parameter: int iContrast
// Parameter: int iSaturation
// Parameter: int iHue
//-----------------------------------------
BOOL SN_File_SetColor(LONG  lFilePlay, 
					  DWORD dwRegionNum, 
					  int   iBrightness, 
					  int   iContrast, 
					  int   iSaturation, 
					  int   iHue);
//-----------------------------------------
// Method:    148.获取颜色
// FullName:  SN_File_GetColor
// Returns:   BOOL
// Parameter: LONG lFilePlay
// Parameter: DWORD dwRegionNum
// Parameter: int * iBrightness
// Parameter: int * iContrast
// Parameter: int * iSaturation
// Parameter: int * iHue
//-----------------------------------------
BOOL SN_File_GetColor(LONG  lFilePlay, 
					  DWORD dwRegionNum, 
					  int   *iBrightness, 
					  int   *iContrast, 
					  int   *iSaturation, 
					  int   *iHue);

//-----------------------------------------
// Method:    149.设置流打开方式
// FullName:  SN_File_SetStreamOpenMode
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值 
// Parameter: DWORD dwMode		流打开方式， SN_STREAME_FILE 或者 SN_STREAME_REALTIME
//-----------------------------------------
BOOL SN_File_SetStreamOpenMode(LONG lFilePlay,DWORD dwMode);

//-----------------------------------------
// Method:    150.获取流打开方式。
// FullName:  SN_File_GetStreamOpenMode
// Returns:   BOOL				true=成功，false=失败
// Parameter: LONG lFilePlay	文件播放句柄，由SN_File_AllocFilePlayHandle返回的有效值 
// Parameter: DWORD * pdwMode	返回流打开方式， SN_STREAME_FILE 或者 SN_STREAME_REALTIME
//-----------------------------------------
BOOL SN_File_GetStreamOpenMode(LONG lFilePlay, DWORD * pdwMode);
//-----------------------------------------
// Method:    151.按照查找条件查找图片（类似windows的文件查找）
// FullName:  SN_DVR_FindFirstPicture
// Returns:   LONG												查找句柄
// Parameter: LPSN_DVR_PICTURECONDITION lpPictureCondition		查找条件
// Parameter: LPSN_DVR_PICTUREDATA lpPictureData				找到的文件信息
//-----------------------------------------
LONG SN_DVR_FindFirstPicture(LPSN_DVR_PICTURECONDITION lpPictureCondition,	
							 LPSN_DVR_PICTUREDATA lpPictureData);	
//-----------------------------------------
// Method:    152.查找下一个图片
// FullName:  SN_DVR_FindNextPicture
// Returns:   BOOL									true=成功，false=失败
// Parameter: LONG lFindPicHandle					查找句柄
// Parameter: LPSN_DVR_PICTUREDATA lpPictureData	找到的文件信息
//-----------------------------------------
BOOL SN_DVR_FindNextPicture(LONG  lFindPicHandle,
							LPSN_DVR_PICTUREDATA lpPictureData);
//-----------------------------------------
// Method:    153.关闭图片查找，释放资源
// FullName:  SN_DVR_FindPictureClose 
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lFindPicHandle	查找句柄
//-----------------------------------------
BOOL SN_DVR_FindPictureClose (LONG lFindPicHandle);	
//-----------------------------------------
// Method:    154.删除IPC抓拍图片
// FullName:  SN_DVR_DeletePicture
// Returns:   BOOL					true=成功，false=失败
// Parameter: LONG lSessionID
// Parameter: char * sPicFileName
//-----------------------------------------
BOOL SN_DVR_DeletePicture (LONG lSessionID,char	*sPicFileName);	
//-----------------------------------------
// Method:    155.获取设备在线用户信息
// FullName:  SN_DVR_GetDeviceOnlineUserInfo
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: PSN_DEVICE_ONLINE_USER_LIST pOnlineUserList
//-----------------------------------------
BOOL SN_DVR_GetDeviceOnlineUserInfo(LONG lSessionID, PSN_DEVICE_ONLINE_USER_LIST pOnlineUserList);

//-----------------------------------------
// Method:    156.获取设备所有通道名称
// FullName:  SN_DVR_GetAllChannelNames
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LPDeviceChannelNames pDeviceChannelNames
//-----------------------------------------
BOOL SN_DVR_GetAllChannelNames( LONG  lSessionID, 
							   LPDeviceChannelNames  pDeviceChannelNames) ;
							   
							   
							   
							   
							   

							   


//-------------------------------------------------------------------------------------
//2012-9-11 增加语音对讲广播start
//					调用顺序SN_DVR_ClientAudioStart，
//									SN_DVR_AddDevToBCGroup/SN_DVR_DelDevFromBCGroup
//									SN_DVR_ClientAudioStop
//-------------------------------------------------------------------------------------							   
//-----------------------------------------
// Method:    启动语音广播的PC端声音捕获
// FullName:  SN_DVR_ClientAudioStart
// Returns:   BOOL,TRUE表示成功，FALSE表示失败
//-----------------------------------------
BOOL  SN_DVR_ClientAudioStart();

//-----------------------------------------
// Method:    添加设备语音通道到广播组
// FullName:  SN_DVR_AddDevToBCGroup
// Returns:   LONG				 [out]语音广播对讲会话,失败返回-1
// Parameter: LONG aSessionID	 [in],登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: DWORD aVoiceChan   [in],设备语音对讲通道
//-----------------------------------------
LONG  SN_DVR_AddDevToBCGroup(LONG aSessionID,DWORD aVoiceChan);

//-----------------------------------------
// Method:    广播组里删除设备
// FullName:  SN_DVR_DelDevFromBCGroup
// Returns:   BOOL				,TRUE表示成功，FALSE表示失败
// Parameter: LONG aVoiceHandle ,[in],语音广播对讲会话，参见SN_DVR_AddDevToBCGroup
//-----------------------------------------
BOOL  SN_DVR_DelDevFromBCGroup(LONG   aVoiceHandle);

//-----------------------------------------
// Method:    停止语音广播的PC端声音捕获
// FullName:  SN_DVR_ClientAudioStop
// Returns:   BOOL   ,TRUE表示成功，FALSE表示失败
//-----------------------------------------
BOOL  SN_DVR_ClientAudioStop();
//2012-9-11 增加语音对讲广播end
//-------------------------------------------------------------------------------------
//-----------------------------------------
// Method:    设置广播模式
// FullName:  NSdk_SetTalkMultiMode
// Returns:   BOOL
// Parameter: int mode  1--带录音 2--外来音频数据
//-----------------------------------------
BOOL SN_DVR_SetTalkMultiMode(int mode);

//-----------------------------------------
// Method:    设置广播音频数据回调函数
// FullName:  SN_DVR_SetTalkMultiCallBack
// Returns:   void
// Parameter: PFN_TalkMultiCallBack pFun 回调函数
// Parameter: void * usrContext  用户自定义
//-----------------------------------------
void SN_DVR_SetTalkMultiCallBack(PFN_TalkMultiCallBack pFun, void *usrContext);




//-----------------------------------------
// Method:    搜索IPC设备信息
// FullName:  SN_NVR_FindFirstIPC
// Returns:   LONG								查找句柄
// Parameter: LONG lSessionID					登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_DEVICE_IPC_INFO lpDevData	查找到的第一条IPC信息
//-----------------------------------------
LONG  SN_NVR_FindFirstIPC(LONG  lSessionID,							
						  LPSN_DEVICE_IPC_INFO  lpDevData);

//-----------------------------------------
// Method:    搜索IPC下一条设备信息
// FullName:  SN_NVR_FindNextIPC
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lFindHandle					查找句柄，SN_NVR_FindFirstIPC返回的有效值
// Parameter: LPSN_DEVICE_IPC_INFO lpDevData	查找到的下一条IPC信息
//-----------------------------------------
BOOL  SN_NVR_FindNextIPC(LONG  lFindHandle,
						 LPSN_DEVICE_IPC_INFO  lpDevData) ;
							   
//-----------------------------------------
// Method:    关闭IPC查找，释放资源
// FullName:  SN_NVR_FindIPCClose 
// Returns:   BOOL				TRUE表示成功，FALSE表示失败
// Parameter: LONG lFindHandle	查找句柄，SN_NVR_FindFirstIPC返回的有效值
//-----------------------------------------
BOOL SN_NVR_FindIPCClose (LONG lFindHandle);	//关闭IPC查找，释放资源

//-----------------------------------------
// Method:    搜索IPC设备信息V2
// FullName:  SN_NVR_FindFirstIPC_V2
// Returns:   LONG								查找句柄
// Parameter: LONG lSessionID					登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_DEVICE_IPC_INFO_V2 lpDevData	查找到的第一条IPC信息
//-----------------------------------------
LONG  SN_NVR_FindFirstIPC_V2(LONG  lSessionID,							
							 LPSN_DEVICE_IPC_INFO_V2  lpDevData);

//-----------------------------------------
// Method:    搜索IPC下一条设备信息
// FullName:  SN_NVR_FindNextIPC_V2
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lFindHandle					查找句柄，SN_NVR_FindFirstIPC返回的有效值
// Parameter: LPSN_DEVICE_IPC_INFO_V2 lpDevData	查找到的下一条IPC信息
//-----------------------------------------
BOOL  SN_NVR_FindNextIPC_V2(LONG  lFindHandle,
							LPSN_DEVICE_IPC_INFO_V2  lpDevData) ;

//-----------------------------------------
// Method:    关闭IPC查找，释放资源
// FullName:  SN_NVR_FindIPCClose_V2 
// Returns:   BOOL				TRUE表示成功，FALSE表示失败
// Parameter: LONG lFindHandle	查找句柄，SN_NVR_FindFirstIPC返回的有效值
//-----------------------------------------
BOOL SN_NVR_FindIPCClose_V2 (LONG lFindHandle);	//关闭IPC查找，释放资源
//-----------------------------------------
// Method:    获取当前设备的连接情况
// FullName:  SN_NVR_GetConnectState 
// Returns:   BOOL									TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID						登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_DEVICE_CONNECT_STATE pDevOut		设备连接信息状态信息
//-----------------------------------------
BOOL SN_NVR_GetConnectState(LONG  lSessionID,LPSN_DEVICE_CONNECT_STATE pDevOut);
//-----------------------------------------
// Method:    IPC连接测试
// FullName:  SN_NVR_IPCTestConnect 
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID					登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_NVR_IPC_TEST_INFO pIPCInfo	IPC连接信息
//-----------------------------------------
BOOL SN_NVR_IPCTestConnect(LONG lSessionID, LPSN_NVR_IPC_TEST_INFO pIPCInfo);
//-----------------------------------------
// Method:    IPC连接测试V2
// FullName:  SN_NVR_IPCConnectTestV2 
// Returns:   BOOL									TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID						登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_NVR_IPC_TEST_INFO_V2 pIPCInfoV2	IPC连接信息V2
//-----------------------------------------
BOOL SN_NVR_IPCConnectTestV2(LONG lSessionID, LPSN_NVR_IPC_TEST_INFO_V2 pIPCInfoV2);
//-----------------------------------------
// Method:    获取数字通道类型
// FullName:  SN_NVR_GetChannelIPCType 
// Returns:   BOOL									TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID						登录会话，由SN_DVR_UserLogon返回的有效值
// Parameter: LPSN_NVR_GET_IPCTYPE_RSP_ST pIPCType	数字通道类型
//-----------------------------------------
BOOL SN_NVR_GetChannelIPCType(LONG  lSessionID,LPSN_NVR_GET_IPCTYPE_RSP_ST pIPCType);


//-----------------------------------------
// Method:    NVR按时间远程回放
// FullName:  SN_NVR_PlayBackByTime
// Returns:   LONG									成功:NVR回放句柄，-1表示失败
// Parameter: LONG lSessionID						[in] 登陆句柄
// Parameter: LONG lChannel							[in] 通道号
// Parameter: PFN_NVRDISPLAYCALLBACK pfnCallBack	[in] 数据回调
// Parameter: void * pContext						[in] 上下文
// Parameter: LPSN_DVR_TIME lpStartTime				[in] 开始时间
// Parameter: LPSN_DVR_TIME lpStopTime				[in] 结束时间
//-----------------------------------------
LONG  SN_NVR_PlayBackByTime(LONG  lSessionID,
							LONG  lChannel, 
							PFN_NVRDISPLAYCALLBACK pfnCallBack,		//回放期间的流数据处理回调,修改
							void *pContext,							//传给回调函数的上下文数据
							SN_DVR_TIME  *lpStartTime, 
							SN_DVR_TIME  *lpStopTime);


//-----------------------------------------
// Method:    NVR按时间远程下载
// FullName:  SN_NVR_DownLoadByTime
// Returns:   LONG							成功:NVR下载句柄，-1表示失败
// Parameter: LONG lSessionID				[in] 登陆句柄
// Parameter: LONG lChannel					[in] 通道号
// Parameter: char * pFileName				[in] 本地保存文件名
// Parameter: LPSN_DVR_TIME lpStartTime		[in] 开始时间
// Parameter: LPSN_DVR_TIME lpStopTime		[in] 结束时间
//-----------------------------------------
LONG SN_NVR_DownLoadByTime(LONG lSessionID, 
						   LONG lChannel, 
						   char *pFileName, 
						   LPSN_DVR_TIME lpStartTime, 
						   LPSN_DVR_TIME lpStopTime);

//-----------------------------------------
// Method:    NVR按文件名远程回放
// FullName:  SN_NVR_PlayBackByFileName
// Returns:   LONG									成功:NVR回放句柄，-1表示失败	
// Parameter: LONG lSessionID						[in] 登陆句柄
// Parameter: char * sPlayBackFileName				[in] 远程录像回放的文件名
// Parameter: PFN_NVRDISPLAYCALLBACK pfnCallBack	[in] 数据回调
// Parameter: void * pContext						[in] 上下文
//-----------------------------------------
LONG SN_NVR_PlayBackByFileName( LONG lSessionID, 
							   char *sPlayBackFileName , 
							   PFN_NVRDISPLAYCALLBACK pfnCallBack, 
							   void *pContext );


//-----------------------------------------
// Method:    NVR按文件名远程下载
// FullName:  SN_NVR_DownLoadByFileName
// Returns:   LONG							成功:NVR回放句柄，-1表示失败
// Parameter: LONG lSessionID				[in] 登陆句柄
// Parameter: char * sDownFileName			[in] 远程文件的文件名
// Parameter: char * pLocalFile				[in] 本地文件名
//-----------------------------------------
LONG SN_NVR_DownLoadByFileName(LONG lSessionID, 
							   char *sDownFileName ,
							   char *pLocalFile);

//-----------------------------------------
// Method:    停止NVR远程下载/回放
// FullName:  SN_NVR_StopPlayBack
// Returns:   BOOL								true:成功，false表示失败
// Parameter: LONG lPlayHandle					[in]下载/回放句柄
//-----------------------------------------
BOOL SN_NVR_StopPlayBack(LONG lPlayHandle);

//-----------------------------------------
// Method:    NVR回放/下载速度控制
// FullName:  SN_NVR_SetFileTransferRate
// Returns:   BOOL					true:成功，false表示失败
// Parameter: LONG lPlayBackHandle	[in] 下载/回放句柄
// Parameter: WORD wTransType		[in] 传输类型，1=文件下载，2=远程回放，默认为文件下载
// Parameter: WORD wTransRate		[in] 传输速度，1=正常速度，2=2倍速，4=4倍速，8=倍速，16=16倍速，默认为正常速度
//-----------------------------------------
BOOL SN_NVR_SetFileTransferRate(LONG lPlayBackHandle, WORD wTransType, WORD wTransRate);

//-----------------------------------------
// Method:    设置设备本地视频参数EX(NVR)
// FullName:  SN_NVR_SetLocalVideoEffectEx
// Returns:   BOOL							TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID				[in]登陆句柄
// Parameter: LONG lChannel					[in]预览通道
// Parameter: DWORD dwBrightValue			[out]亮度
// Parameter: DWORD dwContrastValue			[out]对比度
// Parameter: DWORD dwSaturationValue		[out]饱和度
// Parameter: DWORD dwHueValue				[out]色度
// Parameter: DWORD dwXAdjust				[out]横向位移
// Parameter: DWORD dwYAdjust				[out]纵向位移
//-----------------------------------------
BOOL  SN_NVR_SetLocalVideoEffectEx (LONG	lSessionID,			//登陆句柄
									LONG	lChannel,			//预览通道
									DWORD	dwBrightValue,		//亮度		// 0-255  亮度	(720P:0-199)
									DWORD	dwContrastValue,	//对比度	// 0-255  对比度(720P:0-20)
									DWORD	dwSaturationValue,	//饱和度	// 0-255  饱和度
									DWORD	dwHueValue,			//色度		// 0-255  色调	(720p:0-35)
									DWORD	dwXAdjust,			//横向位移	// 0-255  画面横向偏移
									DWORD	dwYAdjust);			//纵向位移	// 0-255  画面纵向偏移
	

//-----------------------------------------
// Method:    获取设备本地视频参数EX(NVR)
// FullName:  SN_NVR_GetLocalVideoEffectEx
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID					[in]登陆句柄
// Parameter: LONG lChannel						[in]预览通道
// Parameter: DWORD * pdwBrightValue			[out]亮度
// Parameter: DWORD * pdwContrastValue			[out]对比度
// Parameter: DWORD * pdwSaturationValue		[out]饱和度
// Parameter: DWORD * pdwHueValue				[out]色度	
// Parameter: DWORD * pdwXAdjust				[out]横向位移
// Parameter: DWORD * pdwYAdjust				[out]纵向位移
//-----------------------------------------
BOOL  SN_NVR_GetLocalVideoEffectEx (LONG	lSessionID,				//登陆句柄
									LONG	lChannel,				//预览通道
									DWORD	*pdwBrightValue,		//亮度		// 0-255  亮度	(720P:0-199)
									DWORD	*pdwContrastValue,		//对比度	// 0-255  对比度(720P:0-20)
									DWORD	*pdwSaturationValue,	//饱和度	// 0-255  饱和度
									DWORD	*pdwHueValue,			//色度		// 0-255  色调	(720p:0-35)
									DWORD	*pdwXAdjust,			//横向位移	// 0-255  画面横向偏移
									DWORD	*pdwYAdjust);			//纵向位移	// 0-255  画面纵向偏移


//-----------------------------------------
// Method:    控制NVR执行自动组网操作(NVR)
// FullName:  SN_NVR_DevSearchAuto
// Returns:   BOOL							TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID				[in]登陆句柄
//-----------------------------------------
BOOL  SN_NVR_DevSearchAuto(LONG lSessionID);
	
//-----------------------------------------
// Method:    告警布防
// FullName:  SN_DVR_SetupAlarmChan
// Returns:   LONG									成功返回0，-1表示失败。
// Parameter: LONG lSessionID						登录会话，由SN_DVR_UserLogon返回的有效值
//-----------------------------------------
LONG SN_DVR_SetupAlarmChan (LONG lSessionID);


//-----------------------------------------
// Method:    告警撤防
// FullName:  SN_DVR_CloseAlarmChan
// Returns:   BOOL									TRUE表示成功，FALSE表示失败。
// Parameter: LONG lSessionID						登录会话，由SN_DVR_UserLogon返回的有效值
//-----------------------------------------
BOOL SN_DVR_CloseAlarmChan (LONG lSessionID);


BOOL SN_DVR_SetNetworkEnvironment(DWORD dwEnvironmentLevel);


//-----------------------------------------
// Method:    建立透传通道
// FullName:  SN_DVR_SerialStart
// Returns:   LONG						句柄 成功，-1表示失败
// Parameter: LONG lSessionID			[in]登陆句柄
// Parameter: int nComId				[in]串口号
// Parameter: fSerialDataCallBack cbSerialDataCallBack			[in]回调函数
// Parameter: void * pContext			[in] 上下文
//-----------------------------------------
LONG SN_DVR_SerialStart(LONG lSessionID,
						int  nComId,
						fSerialDataCallBack cbSerialDataCallBack,
						void *pContext);


//-----------------------------------------
// Method:    设置透传通道
// FullName:  SN_DVR_SerialSetup
// Returns:   BOOL										TRUE 成功，FALSE表示失败
// Parameter: LONG lSessionID							[in]登陆句柄
// Parameter: SN_DRV_SET_COM_REQ_ST *pDrvOpenCom		[in] 透明通道信息
//-----------------------------------------
BOOL SN_DVR_SerialSetup(LONG lSessionID,
						SN_DRV_SET_COM_REQ_ST *pDrvOpenCom);



//-----------------------------------------
// Method:    断开透传通道
// FullName:  SN_DVR_SerialStop
// Returns:   BOOL							TRUE 成功，FALSE表示失败
// Parameter: LONG lSerialHandle			[in]lSerialHandle,SN_DVR_SerialStart返回句柄
//-----------------------------------------
BOOL SN_DVR_SerialStop( LONG  lSerialHandle );


//-----------------------------------------
// Method:    发送透传数据
// FullName:  SN_DVR_SerialSend
// Returns:   BOOL										TRUE 成功，FALSE表示失败
// Parameter: LONG lSerialHandle						[in] SN_DVR_SerialStart返回句柄	
// Parameter: SN_DRV_PASS_THROUGH_REQ * pPassReq		[in] 发送数据信息
// Parameter: char * pRevBuf							[out] //获取数据	透传数据接收的长度应该小于或等于发送的数据长度，
															  //若接收数据长度超过发送数据长度则会返回错误。

// Parameter: DWORD * dwRevBufSize						[out] 获取数据长度
//-----------------------------------------
BOOL SN_DVR_SerialSend(	LONG	 lSerialHandle,
						SN_DRV_PASS_THROUGH_REQ *pPassReq,
						char	*pRevBuf,										
						DWORD	*dwRevBufSize
						);

//-----------------------------------------
// Method:    获取DVR透传串口ID
// FullName:  SN_DVR_GetSerialID
// Returns:   BOOL										TRUE 成功，FALSE表示失败		
// Parameter: LONG lSessionID							[in]lSessionID,登陆句柄	
// Parameter: SN_DRV_GET_PASSTHR_COM_LIST * pComIDList	[out]pComIDList,获得串口ID数组
//-----------------------------------------
BOOL SN_DVR_GetSerialID( LONG  lSessionID,
						SN_DRV_GET_PASSTHR_COM_LIST *pComIDList);


//-----------------------------------------
// Method:    更新设备语音文件
// FullName:  SN_DVR_UpdateDeviceAudioFile
// Returns:   BOOL								TRUE 成功，FALSE表示失败
// Parameter: LONG lSessionID					[in] lSessionID,登陆句柄	
// Parameter: char * sFileName					[in] sFileName 发送语音文件
//-----------------------------------------
BOOL  SN_DVR_UpdateDeviceAudioFile(LONG  lSessionID, char  *sFileName);


//-----------------------------------------
// Method:    自定义恢复设备默认出厂配置
// FullName:  SN_DVR_OptionalRestoreConfig
// Returns:   BOOL								TRUE 成功，FALSE表示失败
// Parameter: LONG lSessionID					[in]lSessionID,会话ID，由SN_DVR_UserLogon返回的有效值
// Parameter: int nType							[in]nType,操作ID,参见GENERALCFG宏定义
//-----------------------------------------
BOOL SN_DVR_OptionalRestoreConfig( LONG  lSessionID, int  nType);


//-----------------------------------------
// Method:    获取带有锐度的本地视频参数
// FullName:  SN_NVR_GetLocalVideo
// Returns:   BOOL								TRUE 成功，FALSE表示失败
// Parameter: LONG lSessionID					
// Parameter: LONG lChannel						
// Parameter: SN_DEV_VIDEO_INFO *pDevVideoInfo	[out]
//-----------------------------------------
BOOL  SN_NVR_GetLocalVideo (
							LONG  lSessionID,					//登陆句柄
							LONG  lChannel,						//预览通道
							SN_DEV_VIDEO_INFO *pDevVideoInfo	//视频参数
							);

//-----------------------------------------
// Method:    设置带有锐度的本地视频参数
// FullName:  SN_NVR_SetLocalVideo
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: SN_DEV_VIDEO_INFO devVideoInfo	[in]
//-----------------------------------------
BOOL  SN_NVR_SetLocalVideo (
							LONG  lSessionID,					//登陆句柄
							LONG  lChannel,						//预览通道
							SN_DEV_VIDEO_INFO devVideoInfo		//视频参数
							);


//-----------------------------------------
// Method:    检查设备是否在线
// FullName:  SN_DVR_CheckOnlineDevice 
// Returns:   BOOL						//成功=在线，失败=不在线
// Parameter: LONG lSessionID			//登录ID
//-----------------------------------------
BOOL SN_DVR_CheckOnlineDevice(LONG lSessionID);

//-----------------------------------------
// Method:    条形码查询
// FullName:  NSdk_DVR_GetBarCodeTable
// Returns:   BOOL							TRUE=成功，FALSE=失败
// Parameter: LONG lSessionID								登录ID
// Parameter: SN_DEV_SCAN_GUN_CONDITION * pScanGunIn		[in]查询条件
// Parameter: SN_DEV_SCAN_GUN_INFO * pScanGunOut			[out]查询结果
//-----------------------------------------
BOOL SN_DVR_GetBarCodeTable( LONG lSessionID, SN_DEV_SCAN_GUN_CONDITION *pScanGunIn, SN_DEV_SCAN_GUN_INFO *pScanGunOut );

//-------------------------------------------------------
// Method:    条形码加解锁请求							调用此函数前应先调用条形码查询函数SN_DVR_GetBarCodeTable
// FullName:  SN_DVR_SetBarCodeProtect
// Returns:   LONG SN_DVR_INTERFACE						成功返回加解锁的条码数目，失败返回-1
// Parameter: LONG lSessionID							[in]登陆句柄
// Parameter: SN_DEV_BARCODEPROT_REQ * pBarCodeProtIn	[in]条形码加解锁请求信息，需要根据查询结果LPSN_DEV_SCAN_GUN_INFO来填充
//-------------------------------------------------------
LONG SN_DVR_SetBarCodeProtect( LONG lSessionID, SN_DEV_BARCODEPROT_INFO *pBarCodeProtIn );

//-------------------------------------------------------
// Method:    查询设备VoIP信息
// FullName:  SN_DVR_GetVoIPDeviceInfo 
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID					[in]登陆句柄
// Parameter: LPSN_DEV_VOIP_INFO pVoIPInfo		[Out]VoIP信息
//-------------------------------------------------------
BOOL SN_DVR_GetVoIPDeviceInfo(LONG  lSessionID,	LPSN_DEV_VOIP_INFO pVoIPInfo);

//-------------------------------------------------------
// Method:    配置设备VoIP信息
// FullName:  SN_DVR_SetVoIPDeviceInfo
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID					[in]登陆句柄
// Parameter: LPSN_DEV_VOIP_INFO pUsrInfo		[in]用户信息
//-------------------------------------------------------
BOOL SN_DVR_SetVoIPDeviceInfo(LONG  lSessionID,LPSN_DEV_VOIP_INFO pUsrInfo);

//-------------------------------------------------------
// Method:    查询当前用户信息
// FullName:  SN_DVR_GetVoIPUserInfo
// Returns:   BOOL								TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID					[in]登陆句柄
// Parameter: LPSN_DEV_VOIP_USER_INFO pUsrInfo	[Out]用户信息
//-------------------------------------------------------
BOOL SN_DVR_GetVoIPUserInfo(LONG  lSessionID,LPSN_DEV_VOIP_USER_INFO pUsrInfo);

//-------------------------------------------------------
// Method:    配置注册信息
// FullName:  SN_DVR_SetVoIPRegisterInfo
// Returns:   BOOL									TRUE表示成功，FALSE表示失败
// Parameter: LONG lSessionID						[in]登陆句柄
// Parameter: LPSN_DEV_VOIP_REGISTER_INFO pUsrInfo	[in]用户信息
//-------------------------------------------------------
BOOL SN_DVR_SetVoIPRegisterInfo(LONG  lSessionID,LPSN_DEV_VOIP_REGISTER_INFO pUsrInfo);

//----------------------------------------
// Method:    转发注册
// FullName:  SN_DVR_AutoRegSendToServer
// Returns:   int	//return 1 == 成功 -1--主动注册服务未启动  -2--设备未注册上来 -3、通讯错误 -4、未知错误
// Parameter: char * aServerIp	//服务IP
// Parameter: int aServerPort	//服务端口
// Parameter: char * DevSn		//设备序列号
//----------------------------------------
int SN_DVR_AutoRegSendToServer(char *aServerIp, int aServerPort, char * DevSn);

//------------------------------------------
// Method:    启动主动注册服务
// FullName:  SN_DVR_AutoRegStart
// Returns:   BOOL		
// Parameter: int ListenPort   监听端口
// Parameter: PFN_RegDevInfoCallBack regDevInfoCbFun  设备信息回调函数
// Parameter: void * pContext  回调函数自定义上下文
//------------------------------------------
BOOL  SN_DVR_AutoRegStart(int ListenPort, PFN_RegDevInfoCallBack regDevInfoCbFun, void *pContext);

//--------------------------------------
// Method:    停止主动注册服务
// FullName:  SN_DVR_AutoRegStop
// Returns:   BOOL
//--------------------------------------
BOOL SN_DVR_AutoRegStop();

//------------------------------------
// Method:    开启自动服务
// FullName:  SN_DVR_AutoServiceStart
// Returns:   BOOL
// Parameter: int listenPort	监听端口
// Parameter: int type			1--文件下载 2--视频流预览  3--语音对讲
// Parameter: char*  natIP		填空-获取本地  填入IP=路由IP，用于转发映射
//------------------------------------
BOOL  SN_DVR_AutoServiceStart(int listenPort, int type, char*  natIP);

//--------------------------------------
// Method:    停止自动服务
// FullName:  SN_DVR_AutoServiceStop
// Parameter: int type   关闭服务器类型 1--文件下载 2--视频流预览  3--语音对讲
// Returns:   BOOL
//--------------------------------------
BOOL  SN_DVR_AutoServiceStop(int type);
//-----------------------------------------
// Method:	  设置主动注册回调设备信息函数
// FullName:  SN_DVR_SetRegdevInfoCallBack
// Returns:   BOOL
// Parameter: PFN_RegDevInfoCallBack regDevInfoCbFun
// Parameter: void * pContext
//-----------------------------------------
BOOL SN_DVR_SetRegdevInfoCallBack(PFN_RegDevInfoCallBack regDevInfoCbFun,void *pContext);
//解码器相关函数接口
//--------------------------------------
// Method:    获取和设置NVS解码器轮询状态(仅主动解码时,才调用此接口)
// FullName:  SN_NVS_GetSetSwitchState
// Returns:   BOOL 
// Parameter: LONG lSessionID						[in]登陆句柄
// Parameter: BOOL bSetGetFlag						[in]轮询状态获取或设置的标识。取值为TRUE,表示获取状态;否则,表示设置状态
// Parameter: LPSN_NVS_SWITCHSTATE pSwitchState		[in/out]主动解码轮询状态.当获取状态时,为输出参数;当设置状态时,为输入参数
//--------------------------------------
BOOL SN_NVS_GetSetSwitchState(LONG lSessionID, 
							  BOOL bSetGetFlag, 
							  LPSN_NVS_SWITCHSTATE pSwitchState);

//NVR SN8616-28-HD第二码流配置获取和设置
//--------------------------------------
// Method:    获取第二码流配置
// FullName:  SN_NVR_GetCgiRcdCfg
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: LPSN_NVR_CGI_RCDCFG pCgiRcdCfg
//--------------------------------------
BOOL SN_NVR_GetCgiRcdCfg(LONG lSessionID, LONG lChannel, LPSN_NVR_CGI_RCDCFG pCgiRcdCfg);
//--------------------------------------
// Method:    设置第二码流配置
// FullName:  SN_NVR_SetCgiRcdCfg
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: LPSN_NVR_CGI_RCDCFG pCgiRcdCfg
//--------------------------------------
BOOL SN_NVR_SetCgiRcdCfg(LONG lSessionID, LONG lChannel, LPSN_NVR_CGI_RCDCFG pCgiRcdCfg);

//--------------------------------------
// Method:    获取主、子、第N码流配置
// FullName:  SN_NVR_GetUniBitStream
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: SN_BITSTREAM_TYPE_EM nStreamType
// Parameter: LPSN_NVR_BITSTREAM_CFG pCgiRcdCfg
//--------------------------------------
BOOL SN_NVR_GetUniBitStream(LONG lSessionID, LONG lChannel, SN_BITSTREAM_TYPE_EM nStreamType, LPSN_NVR_BITSTREAM_CFG pCgiRcdCfg);
//--------------------------------------
// Method:    设置主、子、第N码流配置
// FullName:  SN_NVR_SetUniBitStream
// Access:    public 
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: SN_BITSTREAM_TYPE_EM nStreamType
// Parameter: LPSN_NVR_BITSTREAM_CFG pCgiRcdCfg
//--------------------------------------
BOOL SN_NVR_SetUniBitStream(LONG lSessionID, LONG lChannel, SN_BITSTREAM_TYPE_EM nStreamType, LPSN_NVR_BITSTREAM_CFG pCgiRcdCfg);

//--------------------------------------
// Method:    获取本地视频预览模式
// FullName:  SN_NVR_GetLocalPreviemMode
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LPSN_PRM_PREVIEW_MODE pPreviewModeCfg
//--------------------------------------
BOOL SN_NVR_GetLocalPreviemMode(LONG lSessionID, LPSN_PRM_PREVIEW_MODE pPreviewModeCfg);
//--------------------------------------
// Method:    设置本地视频预览模式
// FullName:  SN_NVR_SetLocalPreviemMode
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LPSN_PRM_PREVIEW_MODE pPreviewModeCfg
//--------------------------------------
BOOL SN_NVR_SetLocalPreviemMode(LONG lSessionID, LPSN_PRM_PREVIEW_MODE pPreviewModeCfg);

//--------------------------------------
// Method:    获取NVR前端IPC能力集
// FullName:  SN_NVR_GetIPCCapaSets
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: LPSN_NVR_IPCCAPA_SETS pCapaSetsCfg
//--------------------------------------
BOOL SN_NVR_GetIPCCapaSets(LONG lSessionID, LONG lChannel, LPSN_NVR_IPCCAPA_SETS pCapaSetsCfg);

//--------------------------------------
// Method:    获取NVR图像质量范围
// FullName:  SN_NVR_GetImageQuaRange
// Returns:   BOOL
// Parameter: LONG lSessionID
// Parameter: LONG lChannel
// Parameter: LPSN_NVR_IMAGEQUA_RANGE pQuaRangeCfg
//--------------------------------------
BOOL SN_NVR_GetImageQuaRange(LONG lSessionID, LONG lChannel, LPSN_NVR_IMAGEQUA_RANGE pQuaRangeCfg);


//--------------------------------------
// Method:    获得设备在线状态
// FullName:  SN_DVR_GetDevOnlineState
// Returns:   BOOL
// Parameter: LONG lSessionID
//--------------------------------------
BOOL SN_DVR_GetDevOnlineState(LONG lSessionID);


//--------------------------------------
// Method:    设置Socket绑定IP
// FullName:  SN_DVR_SetSocketBindIP
// Returns:   BOOL
// Parameter: char* bindIp
//--------------------------------------
BOOL SN_DVR_SetSocketBindIP(char* bindIp);

//--------------------------------------
// Method:    设置Socket绑定IP
// FullName:  SN_DVR_SetSocketBindIP
// Returns:   BOOL
// Parameter: char* bindIp
//--------------------------------------
//--------------------------------------
// Method:    设置RPC指令交互等待超时时间
// FullName:  SN_DVR_SetRpcTimeOut
// Returns:   BOOL				
// Parameter: int secondCount		设置秒数，取值范围[2,20]，默认20秒
//--------------------------------------
BOOL SN_DVR_SetRpcTimeOut(int secondCount);

//-------------------------------------------------------------------------------------
//函数区域end
//-------------------------------------------------------------------------------------

#endif
