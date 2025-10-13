[Setup]
AppName=IPNPlotter
AppVersion=1.0
DefaultDirName={pf}\IPNPlotter
DefaultGroupName=IPNPlotter
OutputDir=dist
OutputBaseFilename=IPNPlotterSetup
Compression=lzma
SolidCompression=yes

[Files]
Source: "InstallerFiles\*"; DestDir: "{app}"; Flags: recursesubdirs

[Icons]
Name: "{group}\plotter_icon.png"; Filename: "{app}\IPNPlotter.exe"
Name: "{group}\Uninstall plotter_icon.png"; Filename: "{uninstallexe}"
