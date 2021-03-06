//#include "fastvideo.h"
#include <Windows.h>
#include <DbgHelp.h>
#pragma comment(lib, "DbgHelp.lib")

#include "log.h"
#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>
#include <QProcess>
#include <QSqlDatabase>
#include <QTranslator>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QString>

#include "videoserversSvr.h"
#include "dialog.h"
#include "mystyle.h"
#include "md5.h"
#include "GetMac.h"
#include "settings.h"

#include "Verify.h"
#include <QUdpSocket>
#include <iostream>
#include <string>
#include "logdata.h"
#include "videoserver.h"
#include "downloadtask.h"
#include "taskwidget.h"

#include "windowutils.h"
using namespace std;

#include "./VideoDownloader/singleapllication.h"
#include "TempAuthDialog.h"
#include "TaskLog.h"
#include "Service.h"
void execDlg(MainWindow& dlg)
{
// 	__try{
		dlg.exec();
// 	}
// 	__except (EXCEPTION_EXECUTE_HANDLER)
// 	{
// 		std::cout << "execDlg unkonw error!" << std::endl;
// 		//Log::add("execDlg unkonw error!", fatal);
// 		exit(-1);
// 	}
}
void showMainDlg(SingleApplication& a)
{
	MainWindow logd;
	a.setMainWidget(&logd);
	execDlg(logd);
}


void showMainDlgNoExcept(SingleApplication& a)
{
    __try{
		showMainDlg(a);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
// 		std::cout << "showMainDlgNoExcept unkonw error!" << std::endl;
        exit(-1);
    }
}

LONG
WINAPI
MyUnhandledExceptionFilter(
_In_ struct _EXCEPTION_POINTERS * ExceptionInfo
)
{
    return TRUE;
//    Verify::uninit();
	char szFileName[MAX_PATH];
	ZeroMemory(szFileName, sizeof(szFileName));
	GetModuleFileNameA(NULL, szFileName, MAX_PATH);
	string strFileName = szFileName;
	int iIndex = strFileName.rfind('\\');
	if (iIndex == string::npos)
	{
		return FALSE;
	}
	strFileName = strFileName.substr(0, iIndex + 1);
	strFileName += "crashReport.dmp";

	HANDLE hFile = ::CreateFileA(strFileName.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{

		MINIDUMP_EXCEPTION_INFORMATION einfo;
		einfo.ThreadId = ::GetCurrentThreadId();
		einfo.ExceptionPointers = ExceptionInfo;
		einfo.ClientPointers = FALSE;

		::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(), hFile, MiniDumpNormal, &einfo, NULL, NULL);
		::CloseHandle(hFile);

		return TRUE;
	}
	return FALSE;
}

void my_terminate_handler()
{
    exit(1);
}

void initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("fast_video.db");
    db.setUserName("fast_video");
    db.setPassword("fast_video!@#");
    if (!db.open())
    {
        return;
    }

    Settings::createTable();
    Logdata::createTable();
    TaskLog::createTable();
    LoginServerInfo::createTable();
    DownloadRow::createTable();
    RecordFileInfo::createTable();
    DownloadTask::createTable();

    return;
}

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch (type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QFile file(QApplication::applicationDirPath() + "/log/fastvideo_q.log");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

void checkDirectory(){

    QString sDir(Verify::downloadDir());
  
    QDir d(sDir);
    if (!d.exists())
    {
        d.mkpath(sDir);
    }
    std::string dirDirect("C:/Program Files (x86)/OVPlayer");
    QDir dPalyer(dirDirect.c_str()); //\\OVPlayer.exe   
    if (!dPalyer.exists())
    {
        QString appDir = QApplication::applicationDirPath() + "/";
        if (QFile::exists(appDir + "player/StormPlayer.exe"))
        {
            WindowUtils::copy(QFileInfo(appDir + "player/"), QDir("C:/Program Files (x86)"), "OVPlayer");
            WindowUtils::copy(QFileInfo(appDir + "player/StormPlayer.exe"), dPalyer, "OVPlayer.exe");
        }
    }
}

#define PORT_VIDEO_MAIN         100000

int main(int argc, char *argv[])
{
    SetErrorMode(SEM_NOGPFAULTERRORBOX | SEM_FAILCRITICALERRORS | SEM_NOALIGNMENTFAULTEXCEPT | SEM_NOOPENFILEERRORBOX);
	SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
    set_terminate(my_terminate_handler);
	SingleApplication a(argc, argv, APP_KEY_FAST_EXE);
    qInstallMessageHandler(outputMessage);
	if (a.isRunning())
	{
		return 0;
	}

    QString appDir = QApplication::applicationDirPath() + "/";
    if (argc <= 1 || strcmp(argv[1], "-s") != 0)
    {

        QProcess::startDetached(appDir + Verify::startExe());
        return 0;

    }

    QTranslator qt;
    if (qt.load("qt_zh_CN.qm", appDir))
    {
        a.installTranslator(&qt);
    }
    SvrFactory::startSver();
    initDb();
	MD5 md5_toApply;//用于生成申请码

	QString PhysicalAddr;
	if (getLocalMac(PhysicalAddr))
	{
		md5_toApply.update(PhysicalAddr.toStdString());//生成申请码
	}
	else
	{

	}

    if (!Dialog::hasKey() && !TempAuthDialog::instance().hasAuthority())
	{
		//没有授权文件，运行授权面板

        Dialog w;
        w.show();
        a.exec();
        exit(0);
	}
	
    if (Verify::init())
    {
        WindowUtils::disableWindowMsg();
        checkDirectory();
        showMainDlgNoExcept(a);
        Verify::uninit();
    }
	

	return  -1;
}
