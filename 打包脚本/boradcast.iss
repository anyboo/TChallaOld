; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "VideoDownLoad"
#define MyAppVersion "v2.2.0.1"
#define MyAppPublisher "��������"
#define MyAppURL "http://www.sisec.com.cn/"
#define MyAppExeName "FastVideo.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{92156374-EE64-4A6B-9486-DEB0EFAD5FB3}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName=C:\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=����������{#MyAppVersion}
Compression=lzma
ShowLanguageDialog=no
SolidCompression=yes
UsePreviousUserInfo=no
UsePreviousAppDir=no 
UsePreviousGroup=no 
UsePreviousLanguage=no 
UsePreviousSetupType=no 
UsePreviousTasks=no 
DisableDirPage=yes 
DisableFinishedPage=no 
DisableProgramGroupPage=yes 
DisableReadyMemo=yes 
DisableReadyPage=yes 
DisableStartupPrompt=yes 
DisableWelcomePage=no 

[Languages] 
Name: "en"; MessagesFile: "compiler:Default.isl"  
Name: "Chinese"; MessagesFile: "compiler:Languages\ChineseSimplified.isl"  

[Tasks]
Name: "desktopicon"; 		Description: "{cm:CreateDesktopIcon}"; 		GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1
Name: "quicklaunchicon"; 	Description: "{cm:CreateQuickLaunchIcon}"; 	GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\VideoDownLoad\*.dll"; 					    DestDir: "{app}"; Flags: ignoreversion
Source: "C:\VideoDownLoad\auto.bat"; 				    DestDir: "{app}"; Flags: ignoreversion
Source: "C:\VideoDownLoad\*.sys"; 					    DestDir: "{app}"; Flags: ignoreversion
								                            Source: "C:\VideoDownLoad\*.exe"; 		          DestDir: "{app}"; Flags: ignoreversion;    Excludes:"unins000.*"
Source: "C:\VideoDownLoad\DaHuaTool\*"; 			  DestDir: "{app}\DaHuaTool"; 	Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\VideoDownLoad\factorys\*"; 		      DestDir: "{app}\factorys"; 		Flags: ignoreversion recursesubdirs createallsubdirs;   Excludes:"*.lib;*.pdb"	
Source: "C:\VideoDownLoad\hikPlay\*"; 			    DestDir: "{app}\hikPlay"; 		Flags: ignoreversion recursesubdirs createallsubdirs;Source: "C:\VideoDownLoad\image\*"; 				    DestDir: "{app}\images"; 		Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\VideoDownLoad\platforms\*"; 			  DestDir: "{app}\platforms"; 	Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\VideoDownLoad\sqldrivers\*"; 			  DestDir: "{app}\sqldrivers"; 	Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\VideoDownLoad\tool\*"; 					    DestDir: "{app}\tool"; 			Flags: ignoreversion recursesubdirs createallsubdirs
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Dirs]
Name: "{app}\log"; 	  Flags: uninsalwaysuninstall
Name: "{app}\file"; 	Flags: uninsalwaysuninstall

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; 	Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]Filename: "{app}\WinPcap_4_1_3.exe"; Description: "ץ������"; Flags: skipifsilent shellexec runhidden nowait postinstall
;Filename: "{app}\TC CARD.AAC_i1.1.0.161.0.exe"; Description: "TC CARD"; Flags: skipifsilent shellexec runhidden nowait postinstall
;Filename: "{app}\DRIVER.CY3014_YS 1.1.0.161.3.exe"; Description: "TC CARD ����"; Flags: skipifsilent shellexec runhidden nowait postinstall
Filename: "{app}\auto.bat"; 			Description: "�Զ�ע��"; 				Flags: skipifsilent shellexec runhidden nowait postinstall
Filename: "{app}\{#MyAppExeName}"; 		Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: filesandordirs; Name:"{app}\"