SHELL := cmd.exe
CYGWIN=nontsec
export PATH := C:\Program Files\Python\Scripts\;C:\Program Files\Python\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\TortoiseGit\bin;C:\Program Files\Git\cmd;C:\Program Files\Graphviz\bin;C:\Users\ryclj\AppData\Local\Microsoft\WindowsApps;C:\Users\ryclj\AppData\Local\gitkraken\bin;C:\Users\ryclj\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.9_qbz5n2kfra8p0\LocalCache\local-packages\Python39\Scripts;C:\Users\ryclj\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Users\ryclj\AppData\Local\Microsoft\WindowsApps;C:\Users\ryclj\AppData\Local\gitkraken\bin;C:\Users\ryclj\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.9_qbz5n2kfra8p0\LocalCache\local-packages\Python39\Scripts;C:\Users\ryclj\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\BrAutomation\AS412\Bin-en\4.12;C:\BrAutomation\AS412\Bin-en\4.11;C:\BrAutomation\AS412\Bin-en\4.10;C:\BrAutomation\AS412\Bin-en\4.9;C:\BrAutomation\AS412\Bin-en\4.8;C:\BrAutomation\AS412\Bin-en\4.7;C:\BrAutomation\AS412\Bin-en\4.6;C:\BrAutomation\AS412\Bin-en\4.5;C:\BrAutomation\AS412\Bin-en\4.4;C:\BrAutomation\AS412\Bin-en\4.3;C:\BrAutomation\AS412\Bin-en\4.2;C:\BrAutomation\AS412\Bin-en\4.1;C:\BrAutomation\AS412\Bin-en\4.0;C:\BrAutomation\AS412\Bin-en
export AS_BUILD_MODE := Rebuild
export AS_VERSION := 4.12.4.107 SP
export AS_WORKINGVERSION := 4.12
export AS_COMPANY_NAME :=  
export AS_USER_NAME := ryclj
export AS_PATH := C:/BrAutomation/AS412
export AS_BIN_PATH := C:/BrAutomation/AS412/Bin-en
export AS_PROJECT_PATH := C:/projects/Bridge_RUC_Motor/Bridge_RUC_Motor
export AS_PROJECT_NAME := Bridge_RUC_Motor
export AS_SYSTEM_PATH := C:/BrAutomation/AS/System
export AS_VC_PATH := C:/BrAutomation/AS412/AS/VC
export AS_TEMP_PATH := C:/projects/Bridge_RUC_Motor/Bridge_RUC_Motor/Temp
export AS_CONFIGURATION := Config1
export AS_BINARIES_PATH := C:/projects/Bridge_RUC_Motor/Bridge_RUC_Motor/Binaries
export AS_GNU_INST_PATH := C:/BrAutomation/AS412/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH := C:/BrAutomation/AS412/AS/GnuInst/V4.1.2/4.9/bin
export AS_GNU_INST_PATH_SUB_MAKE := C:/BrAutomation/AS412/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH_SUB_MAKE := C:/BrAutomation/AS412/AS/GnuInst/V4.1.2/4.9/bin
export AS_INSTALL_PATH := C:/BrAutomation/AS412
export WIN32_AS_PATH := "C:\BrAutomation\AS412"
export WIN32_AS_BIN_PATH := "C:\BrAutomation\AS412\Bin-en"
export WIN32_AS_PROJECT_PATH := "C:\projects\Bridge_RUC_Motor\Bridge_RUC_Motor"
export WIN32_AS_SYSTEM_PATH := "C:\BrAutomation\AS\System"
export WIN32_AS_VC_PATH := "C:\BrAutomation\AS412\AS\VC"
export WIN32_AS_TEMP_PATH := "C:\projects\Bridge_RUC_Motor\Bridge_RUC_Motor\Temp"
export WIN32_AS_BINARIES_PATH := "C:\projects\Bridge_RUC_Motor\Bridge_RUC_Motor\Binaries"
export WIN32_AS_GNU_INST_PATH := "C:\BrAutomation\AS412\AS\GnuInst\V4.1.2"
export WIN32_AS_GNU_BIN_PATH := "C:\BrAutomation\AS412\AS\GnuInst\V4.1.2\bin"
export WIN32_AS_INSTALL_PATH := "C:\BrAutomation\AS412"

.suffixes:

ProjectMakeFile:

	@'$(AS_BIN_PATH)/4.9/BR.AS.AnalyseProject.exe' '$(AS_PROJECT_PATH)/Bridge_RUC_Motor.apj' -t '$(AS_TEMP_PATH)' -c '$(AS_CONFIGURATION)' -o '$(AS_BINARIES_PATH)'   -sfas -buildMode 'Rebuild'   

