#pragma once
#pragma comment(lib,"advapi32.lib")
#include <winsvc.h>

// Define device type and status
#define FILE_DEVICE_UNKNOWN             0x00000022
#define FILE_ANY_ACCESS     0
#define METHOD_BUFFERED	0

class cDrvCtrl
{
public:

	cDrvCtrl()
	{
		// Initialize variables
		m_pSysPath = NULL;
		m_pServiceName = NULL;
		m_pDisplayName = NULL;
		m_hSCManager = NULL;
		m_hService = NULL;
		m_hDriver = INVALID_HANDLE_VALUE;
	}
	~cDrvCtrl()
	{
		// clear
		if (m_hService != NULL) {
			CloseServiceHandle(m_hService);
		}
		if (m_hSCManager != NULL) {
			CloseServiceHandle(m_hSCManager);
		}
		if (m_hDriver != NULL) {
			CloseHandle(m_hDriver);
		}		
	}
public:
	DWORD m_dwLastError;
	PCHAR m_pSysPath;
	PCHAR m_pServiceName;
	PCHAR m_pDisplayName;
	HANDLE m_hDriver;
	SC_HANDLE m_hSCManager;
	SC_HANDLE m_hService;
public:
	BOOL Install(PCHAR pSysPath,PCHAR pServiceName,PCHAR pDisplayName);
	BOOL Start();
	BOOL Stop();
	BOOL Remove();
	BOOL Open(PCHAR pLinkName);
	BOOL IoControl(DWORD dwIoCode, PVOID InBuff, DWORD InBuffLen, PVOID OutBuff, DWORD OutBuffLen, DWORD *RealRetBytes);
private:
	BOOL GetSvcHandle(PCHAR pServiceName);
	DWORD CTL_CODE_GEN(DWORD lngFunction);
protected:
	//null
};
