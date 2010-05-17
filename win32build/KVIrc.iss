; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]

AppName=KVIrc
AppVerName=KVIrc 3.4.3 "Shiny"
AppId=KVIrc
AppPublisher=Szymon Stefanek and The KVIrc Development Team
AppPublisherURL=http://www.kvirc.net
AppSupportURL=http://www.kvirc.net
AppUpdatesURL=http://www.kvirc.net
DefaultDirName={pf}\KVIrc
DefaultGroupName=KVIrc
AllowNoIcons=yes
;Compression=bzip/9
Compression=lzma/max
SolidCompression=yes
SourceDir=.\package
OutputDir=.\setup
ShowLanguageDialog=yes
SetupIconFile=..\..\data\resources\icon1.ico
Uninstallable=yes

[InstallDelete]

; These dlls are dead, we don't want them to be accidentally loaded
Type: files; Name: "{app}\modules\kvitb_options.dll"
Type: files; Name: "{app}\modules\kvitb_scripting.dll"
Type: files; Name: "{app}\modules\kvitb_winops.dll"
; Same for the relative caps
Type: files; Name: "{app}\modules\caps\toolbar\tb_options"
Type: files; Name: "{app}\modules\caps\toolbar\tb_scripting"
Type: files; Name: "{app}\modules\caps\toolbar\tb_winops"
Type: files; Name: "{app}\modules\caps\toolbar\url"

[Tasks]

Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}";
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}";

[Files]

Source: "kvirc.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "README.txt"; DestDir: "{app}"; Flags: ignoreversion isreadme
Source: "Microsoft.VC80.CRT.manifest"; DestDir: "{app}"; Flags: ignoreversion
Source: "modules\Microsoft.VC80.CRT.manifest"; DestDir: "{app}\modules\"; Flags: ignoreversion
Source: "*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "config\*"; DestDir: "{app}\config\"; Flags: ignoreversion recursesubdirs
Source: "defscript\*"; DestDir: "{app}\defscript\"; Flags: ignoreversion recursesubdirs
Source: "doc\*"; DestDir: "{app}\doc\"; Flags: ignoreversion recursesubdirs
Source: "help\*"; DestDir: "{app}\help\"; Flags: ignoreversion recursesubdirs
Source: "license\*"; DestDir: "{app}\license\"; Flags: ignoreversion recursesubdirs
Source: "locale\*"; DestDir: "{app}\locale\"; Flags: ignoreversion recursesubdirs
Source: "msgcolors\*"; DestDir: "{app}\msgcolors\"; Flags: ignoreversion recursesubdirs
Source: "modules\*"; DestDir: "{app}\modules\"; Flags: ignoreversion recursesubdirs
Source: "pics\*"; DestDir: "{app}\pics\"; Flags: ignoreversion recursesubdirs
Source: "themes\*"; DestDir: "{app}\themes\"; Flags: ignoreversion recursesubdirs

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]

Filename: "{app}\kvirc.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://www.kvirc.net"

[Icons]

Name: "{group}\KVIrc"; Filename: "{app}\kvirc.exe"
Name: "{group}\{cm:ProgramOnTheWeb,KVIrc}"; Filename: "{app}\kvirc.url"
Name: "{group}\{cm:UninstallProgram,KVIrc}"; Filename: "{uninstallexe}"
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\KVIrc"; Filename: "{app}\kvirc.exe"; Tasks: quicklaunchicon
Name: "{userdesktop}\KVIrc"; Filename: "{app}\kvirc.exe"; Tasks: desktopicon

[Languages]

; The default translation files are in the Inno Setup's Language directory
; The Italian translation can be downloaded from the innosetup's site

Name: "en"; MessagesFile: "compiler:Default.isl"
Name: "nl"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "pl"; MessagesFile: "compiler:Languages\Polish.isl"
Name: "ru"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "de"; MessagesFile: "compiler:Languages\German.isl"
Name: "no"; MessagesFile: "compiler:Languages\Norwegian.isl"
Name: "pt"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"
Name: "pt"; MessagesFile: "compiler:Languages\Portuguese.isl"
Name: "fr"; MessagesFile: "compiler:Languages\French.isl"
Name: "sl"; MessagesFile: "compiler:Languages\Slovenian.isl"
Name: "ca"; MessagesFile: "compiler:Languages\Catalan.isl"
Name: "it"; MessagesFile: "compiler:Languages\Italian.isl"

[Run]

Filename: "{app}\kvirc.exe"; Description: "{cm:LaunchProgram,KVIrc}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]

Type: files; Name: "{app}\kvirc.url"
