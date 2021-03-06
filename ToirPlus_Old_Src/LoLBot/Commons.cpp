#include "StdAfx.h"
#include "Commons.h"
//#include "VMProtectSDK.h"

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool __oMsg(const char * format, ...)
{
	char buffer[1000];

	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);

	strcat_s(buffer, "\n");
	//const wchar_t *wbuff = C2W(buffer); 
	OutputDebugStringA(buffer);
	//delete []wbuff;
	return true;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void StrReplace(char * inputStr, char needReplace, char toReplace)
{
	int len = strlen(inputStr);
	for (int i = 0; i < len; ++i)
	{
		if (inputStr[i] == needReplace)
		{
			inputStr[i] = toReplace;
		}
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* ArrInt2Str(int * inputArr)
{
	int key[3] = {13, 26 , 39};
	//char key[3] = {'K', 'C', 'Q'};
	std::string ketQua = "";
	ketQua.insert(0, 1, *inputArr);
	for (int i = 1;inputArr[i] != -1; ++i)
	{
		char ch =  char( ((inputArr[i])^key[i%(sizeof(key)/sizeof(int))])/7-13-(*inputArr) );
		//char ch =  char( ( ( (inputArr[i])-(*inputArr) )^3 )/7-13);
		ketQua.insert(i, 1, ch);
	}
	char * tmp = new char[ketQua.size() + 1];
	strcpy_s(tmp, MAX_PATH, ketQua.c_str());
	ketQua.clear();
	return tmp;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
wchar_t* C2W(CONST char *strInput)
{
	int leng = strlen(strInput);
	wchar_t* ketqua = new wchar_t[leng + 1];
	for (int i = 0; i < leng; ++i)
		ketqua[i] = strInput[i];
	ketqua[leng] = '\0';
	return ketqua;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* W2C(const wchar_t *strInput)
{
	int leng = wcslen(strInput);
	char* ketqua = new char[leng + 1];
	for (int i = 0; i < leng; ++i)
		ketqua[i] = strInput[i];
	ketqua[leng] = '\0';
	return ketqua;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsWin7OrLater()
{
	DWORD version = GetVersion();
	DWORD major = (DWORD) (LOBYTE(LOWORD(version)));
	DWORD minor = (DWORD) (HIBYTE(LOWORD(version)));

	return (major > 6) || ((major == 6) && (minor >= 1));
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
BOOL DnsFlushResolverCache()
{
	BOOL (WINAPI *DoDnsFlushResolverCache)();
	*(FARPROC *)&DoDnsFlushResolverCache = GetProcAddress(LoadLibraryA("dnsapi.dll"), "DnsFlushResolverCache");
	if(!DoDnsFlushResolverCache) return FALSE;
	return DoDnsFlushResolverCache();
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetCurrentVersion()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectApp == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___checkversion_php));

	char data[MAX_PATH];
	sprintf_s(data,  (sz__appversion__s),  (APPVERSION));
	DWORD data_len = strlen(data);

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen( C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);

	if (g_bCheckConnectApp == true)
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTPS_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);
	}
	else
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTP_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			0);
	}

	// Send a Request.
	if (hRequest) 
		bResults = WinHttpSendRequest( hRequest, 
		//WINHTTP_NO_ADDITIONAL_HEADERS,
		//C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
		L"Content-Type: application/x-www-form-urlencoded\r\n",
		-1, data, data_len, 
		data_len, 0);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);

	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{                                  
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				//printf("%s", pszOutBuffer);
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	//MessageBox(NULL, pszOutBuffer, NULL, MB_OK);
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetCurrentVersion4WinXP()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectApp == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___checkversion_php));
	//MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), NULL, MB_OK);

	char data[MAX_PATH];
	sprintf_s(data,  (sz__appversion__s),  (APPVERSION));
	DWORD data_len = strlen(data);

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(  C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	if (g_bCheckConnectApp == true)
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTPS_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);
	}
	else
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTP_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			0);
	}

	bool retry = true;
	DWORD result;
	do
	{
		retry = false;
		result = NO_ERROR;

		// no retry on success, possible retry on failure
		// Send a Request.
		if (hRequest) 
			bResults = WinHttpSendRequest( hRequest, 
			//WINHTTP_NO_ADDITIONAL_HEADERS,
			//C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
			L"Content-Type: application/x-www-form-urlencoded\r\n",
			-1, data, data_len, 
			data_len, 0);
		//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

		if(bResults == 0)
		{
			result = GetLastError();
			//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

			// (1) If you want to allow SSL certificate errors and continue
			// with the connection, you must allow and initial failure and then
			// reset the security flags. From: "HOWTO: Handle Invalid Certificate
			// Authority Error with WinInet"
			// http://support.microsoft.com/default.aspx?scid=kb;EN-US;182888
			if(result == ERROR_WINHTTP_SECURE_FAILURE)
			{
				DWORD dwFlags =
					SECURITY_FLAG_IGNORE_UNKNOWN_CA |
					SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE |
					SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
					SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

				if(WinHttpSetOption(
					hRequest,
					WINHTTP_OPTION_SECURITY_FLAGS,
					&dwFlags,
					sizeof(dwFlags)))
				{
					retry = true;
				}
			}
			// (2) Negotiate authorization handshakes may return this error
			// and require multiple attempts
			// http://msdn.microsoft.com/en-us/library/windows/desktop/aa383144%28v=vs.85%29.aspx
			else if(result == ERROR_WINHTTP_RESEND_REQUEST)
			{
				retry = true;
			}
		}
	} while(retry);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );
	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				//printf("%s", pszOutBuffer);
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetRequestResult(const char* username, const char* password)
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectApp == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___checklogin_php));

	static const IDE_INFO ideInfo = ReadPhysicalDriveInNTUsingSmart();
	static DWORD lastCheck = GetTickCount();
	static DWORD timeCheck = GetTickCount();
	lastCheck = timeCheck;
	timeCheck = GetTickCount();
	DWORD timeUsed = timeCheck - lastCheck;
	char  data[MAX_PATH];
	char osName[64];
	GetOS(osName);
#define INFO_BUFFER_SIZE 32767
	TCHAR  pcName[INFO_BUFFER_SIZE];
	TCHAR  pcUser[INFO_BUFFER_SIZE];
	ZeroMemory(pcName, INFO_BUFFER_SIZE);
	ZeroMemory(pcUser, INFO_BUFFER_SIZE);

	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	// Get and display the name of the computer. 
	bufCharCount = INFO_BUFFER_SIZE;
	GetComputerName( pcName, &bufCharCount );
	// Get and display the user name. 
	bufCharCount = INFO_BUFFER_SIZE;
	GetUserName( pcUser, &bufCharCount );
	sprintf_s(data, (sz__username__s_password__s_sndisk__s_os__s_pcname__s_pcuser__s_appversion__s_sessionid__s_iphost__s_timeused__d), username, password, strlen(ideInfo.serialNumber) != 0 ? ideInfo.serialNumber : GetMACAddress(), osName, W2C(pcName), W2C(pcUser), (APPVERSION), g_szSessionID, GetIPHost(), timeUsed);
	DWORD data_len = strlen(data);
	//MessageBoxW(NULL, C2W(data), L"Get SNdisk", MB_OK);

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(  C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);

	if (g_bCheckConnectApp == true)
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTPS_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);
	}
	else
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTP_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			0);
	}

	//MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), NULL, MB_OK);
	// Send a Request.
	if (hRequest) 
		bResults = WinHttpSendRequest( hRequest, 
		//WINHTTP_NO_ADDITIONAL_HEADERS,
		//C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
		L"Content-Type: application/x-www-form-urlencoded\r\n",
		-1, data, data_len, 
		data_len, 0);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);

	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{                                  
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				//printf("%s", pszOutBuffer);
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetRequestResult4WinXP(const char* username, const char* password)
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectApp == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___checklogin_php));

	static const IDE_INFO ideInfo = ReadPhysicalDriveInNTUsingSmart();
	static DWORD lastCheck = GetTickCount();
	static DWORD timeCheck = GetTickCount();
	lastCheck = timeCheck;
	timeCheck = GetTickCount();
	DWORD timeUsed = timeCheck - lastCheck;
	char  data[MAX_PATH];
	char osName[64];
	GetOS(osName);
#define INFO_BUFFER_SIZE 32767
	TCHAR  pcName[INFO_BUFFER_SIZE];
	TCHAR  pcUser[INFO_BUFFER_SIZE];
	ZeroMemory(pcName, INFO_BUFFER_SIZE);
	ZeroMemory(pcUser, INFO_BUFFER_SIZE);

	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	// Get and display the name of the computer. 
	bufCharCount = INFO_BUFFER_SIZE;
	GetComputerName( pcName, &bufCharCount );
	// Get and display the user name. 
	bufCharCount = INFO_BUFFER_SIZE;
	GetUserName( pcUser, &bufCharCount );
	sprintf_s(data, (sz__username__s_password__s_sndisk__s_os__s_pcname__s_pcuser__s_appversion__s_sessionid__s_iphost__s_timeused__d), username, password, strlen(ideInfo.serialNumber) != 0 ? ideInfo.serialNumber : GetMACAddress(), osName, W2C(pcName), W2C(pcUser), (APPVERSION), g_szSessionID, GetIPHost(), timeUsed);
	DWORD data_len = strlen(data);
	//MessageBoxW(NULL, C2W(data), L"Get SNdisk", MB_OK);

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(  C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	if (g_bCheckConnectApp == true)
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTPS_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);
	}
	else
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTP_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			0);
	}

	bool retry;
	DWORD result;
	do
	{
		retry = false;
		result = NO_ERROR;

		// no retry on success, possible retry on failure
		// Send a Request.
		if (hRequest) 
			bResults = WinHttpSendRequest( hRequest, 
			//WINHTTP_NO_ADDITIONAL_HEADERS,
			//C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
			L"Content-Type: application/x-www-form-urlencoded\r\n",
			-1, data, data_len, 
			data_len, 0);
		//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

		if(bResults == 0)
		{
			result = GetLastError();
			//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

			// (1) If you want to allow SSL certificate errors and continue
			// with the connection, you must allow and initial failure and then
			// reset the security flags. From: "HOWTO: Handle Invalid Certificate
			// Authority Error with WinInet"
			// http://support.microsoft.com/default.aspx?scid=kb;EN-US;182888
			if(result == ERROR_WINHTTP_SECURE_FAILURE)
			{
				DWORD dwFlags =
					SECURITY_FLAG_IGNORE_UNKNOWN_CA |
					SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE |
					SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
					SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

				if(WinHttpSetOption(
					hRequest,
					WINHTTP_OPTION_SECURITY_FLAGS,
					&dwFlags,
					sizeof(dwFlags)))
				{
					retry = true;
				}
			}
			// (2) Negotiate authorization handshakes may return this error
			// and require multiple attempts
			// http://msdn.microsoft.com/en-us/library/windows/desktop/aa383144%28v=vs.85%29.aspx
			else if(result == ERROR_WINHTTP_RESEND_REQUEST)
			{
				retry = true;
			}
		}
	} while(retry);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );
	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				////printf("%s", pszOutBuffer);
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetTimeServer()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectApp == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___gettime_php));

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen( C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);

	if (g_bCheckConnectApp == true)
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTPS_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);
	}
	else
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTP_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			0);
	}

	//MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), L"Get Time Server", MB_OK);
	// Send a Request.
	if (hRequest) 
		bResults = WinHttpSendRequest( hRequest, 
		//WINHTTP_NO_ADDITIONAL_HEADERS,
		C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
		-1, "", 0, 
		0, 0);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);

	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{                                  
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				//printf("%s", pszOutBuffer);
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	//MessageBox(NULL, pszOutBuffer, NULL, MB_OK);
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetTimeServer4WinXP()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectApp == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___gettime_php));
	//MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), NULL, MB_OK);

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(  C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	if (g_bCheckConnectApp == true)
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTPS_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);
	}
	else
	{
		// Specify an HTTP server.
		if (hSession)
			hConnect = WinHttpConnect( hSession, server,
			INTERNET_DEFAULT_HTTP_PORT, 0);

		// Create an HTTP Request handle.
		if (hConnect)
			hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
			strURI, 
			0, WINHTTP_NO_REFERER, 
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			0);
	}

	bool retry = true;
	DWORD result;
	do
	{
		retry = false;
		result = NO_ERROR;

		// no retry on success, possible retry on failure
		// Send a Request.
		if (hRequest) 
			bResults = WinHttpSendRequest( hRequest, 
			//WINHTTP_NO_ADDITIONAL_HEADERS,
			C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
			-1, "", 0, 
			0, 0);
		//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

		if(bResults == 0)
		{
			result = GetLastError();
			//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

			// (1) If you want to allow SSL certificate errors and continue
			// with the connection, you must allow and initial failure and then
			// reset the security flags. From: "HOWTO: Handle Invalid Certificate
			// Authority Error with WinInet"
			// http://support.microsoft.com/default.aspx?scid=kb;EN-US;182888
			if(result == ERROR_WINHTTP_SECURE_FAILURE)
			{
				DWORD dwFlags =
					SECURITY_FLAG_IGNORE_UNKNOWN_CA |
					SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE |
					SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
					SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

				if(WinHttpSetOption(
					hRequest,
					WINHTTP_OPTION_SECURITY_FLAGS,
					&dwFlags,
					sizeof(dwFlags)))
				{
					retry = true;
				}
			}
			// (2) Negotiate authorization handshakes may return this error
			// and require multiple attempts
			// http://msdn.microsoft.com/en-us/library/windows/desktop/aa383144%28v=vs.85%29.aspx
			else if(result == ERROR_WINHTTP_RESEND_REQUEST)
			{
				retry = true;
			}
		}
	} while(retry);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );
	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				//printf("%s", pszOutBuffer);
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool TestConnect()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	LPCWSTR strURI=C2W( (sz___gettime_php));

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen( C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect( hSession, server,
		INTERNET_DEFAULT_HTTPS_PORT, 0);

	// Create an HTTP Request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
		strURI, 
		0, WINHTTP_NO_REFERER, 
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		WINHTTP_FLAG_SECURE);

	//MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), L"Get Time Server", MB_OK);
	// Send a Request.
	if (hRequest) 
		bResults = WinHttpSendRequest( hRequest, 
		//WINHTTP_NO_ADDITIONAL_HEADERS,
		C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
		-1, "", 0, 
		0, 0);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);

	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{                                  
				return false;
			}
			else
			{
				return true;
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool TestConnect4WinXP()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	LPCWSTR strURI=C2W( (sz___gettime_php));
	//MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), NULL, MB_OK);

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(  C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME, 
		WINHTTP_NO_PROXY_BYPASS, 0);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect( hSession, server,
		INTERNET_DEFAULT_HTTPS_PORT,
		0);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	// Create an HTTP Request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
		strURI, 
		strURI, WINHTTP_NO_REFERER, 
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		WINHTTP_FLAG_SECURE);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	bool retry = true;
	DWORD result;
	do
	{
		retry = false;
		result = NO_ERROR;

		// no retry on success, possible retry on failure
		// Send a Request.
		if (hRequest) 
			bResults = WinHttpSendRequest( hRequest, 
			//WINHTTP_NO_ADDITIONAL_HEADERS,
			C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
			-1, "", 0, 
			0, 0);
		//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

		if(bResults == 0)
		{
			result = GetLastError();
			//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

			// (1) If you want to allow SSL certificate errors and continue
			// with the connection, you must allow and initial failure and then
			// reset the security flags. From: "HOWTO: Handle Invalid Certificate
			// Authority Error with WinInet"
			// http://support.microsoft.com/default.aspx?scid=kb;EN-US;182888
			if(result == ERROR_WINHTTP_SECURE_FAILURE)
			{
				DWORD dwFlags =
					SECURITY_FLAG_IGNORE_UNKNOWN_CA |
					SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE |
					SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
					SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

				if(WinHttpSetOption(
					hRequest,
					WINHTTP_OPTION_SECURITY_FLAGS,
					&dwFlags,
					sizeof(dwFlags)))
				{
					retry = true;
				}
			}
			// (2) Negotiate authorization handshakes may return this error
			// and require multiple attempts
			// http://msdn.microsoft.com/en-us/library/windows/desktop/aa383144%28v=vs.85%29.aspx
			else if(result == ERROR_WINHTTP_RESEND_REQUEST)
			{
				retry = true;
			}
		}
	} while(retry);

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);
	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );
	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do 
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
			{
				//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
				break;
			}

			// No more available data.
			if (!dwSize)
				break;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize+1];
			if (!pszOutBuffer)
			{
				//printf("Out of memory\n");
				break;
			}

			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize+1);

			if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
				dwSize, &dwDownloaded))
			{
				//printf( "Error %u in WinHttpReadData.\n", GetLastError());
				return false;
			}
			else
			{
				//printf("%s", pszOutBuffer);
				return true;
			}

			// Free the memory allocated to the buffer.
			//delete [] pszOutBuffer;

			// This condition should never be reached since WinHttpQueryDataAvailable
			// reported that there are bits to read.
			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
	}
	else
	{
		// Report any errors.
		//printf( "Error %d has occurred.\n", GetLastError() );
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	return false;
}

void GetPhysicalDriveSerialNumber(UINT nDriveNumber IN, CString& strSerialNumber OUT)
{
	strSerialNumber.Empty();

	// Format physical drive path (may be '\\.\PhysicalDrive0', '\\.\PhysicalDrive1' and so on).
	CString strDrivePath;
	strDrivePath.Format(_T("\\\\.\\PhysicalDrive%u"), nDriveNumber);

	// 2. Set the default process security level 
	// http://msdn.microsoft.com/en-us/library/windows/desktop/aa393617(v=vs.85).aspx
	HRESULT hr =  ::CoInitializeSecurity(
		NULL,                        // Security descriptor    
		-1,                          // COM negotiates authentication service
		NULL,                        // Authentication services
		NULL,                        // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication level for proxies
		RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation level for proxies
		NULL,                        // Authentication info
		EOAC_NONE,                   // Additional capabilities of the client or server
		NULL);                       // Reserved

	ATLENSURE_SUCCEEDED(hr);

	// 3. Create a connection to WMI namespace
	// http://msdn.microsoft.com/en-us/library/windows/desktop/aa389749(v=vs.85).aspx

	// 3.1. Initialize the IWbemLocator interface
	CComPtr<IWbemLocator> pIWbemLocator;
	hr = ::CoCreateInstance(CLSID_WbemLocator, 0, 
		CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&pIWbemLocator);

	ATLENSURE_SUCCEEDED(hr);

	// 3.2. Call IWbemLocator::ConnectServer for connecting to WMI 
	CComPtr<IWbemServices> pIWbemServices;
	hr = pIWbemLocator->ConnectServer(L"ROOT\\CIMV2",
		NULL, NULL, 0, NULL, 0, 0, &pIWbemServices);

	ATLENSURE_SUCCEEDED(hr);

	// 4. Set the security levels on WMI connection
	// http://msdn.microsoft.com/en-us/library/windows/desktop/aa393619(v=vs.85).aspx
	hr = ::CoSetProxyBlanket(
		pIWbemServices, 
		RPC_C_AUTHN_WINNT,
		RPC_C_AUTHZ_NONE, 
		NULL, 
		RPC_C_AUTHN_LEVEL_CALL,
		RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL,
		EOAC_NONE);

	ATLENSURE_SUCCEEDED(hr);

	// 5. Execute a WQL (WMI Query Language) query to get physical media info
	const BSTR szQueryLanguage = L"WQL";
	const BSTR szQuery =  L"SELECT Tag, SerialNumber FROM Win32_PhysicalMedia";
	CComPtr<IEnumWbemClassObject> pIEnumWbemClassObject;
	hr = pIWbemServices->ExecQuery(
		szQueryLanguage,                                       // Query language
		szQuery,                                               // Query
		WBEM_FLAG_FORWARD_ONLY|WBEM_FLAG_RETURN_IMMEDIATELY,   // Flags
		NULL,                                                  // Context
		&pIEnumWbemClassObject);                               // Enumerator

	ATLENSURE_SUCCEEDED(hr);

	// 6. Get each enumerator element until find the desired physical drive 
	ULONG uReturn = 0;
	while(pIEnumWbemClassObject)
	{
		CComPtr<IWbemClassObject> pIWbemClassObject;
		hr = pIEnumWbemClassObject->Next(WBEM_INFINITE, 1, &pIWbemClassObject, &uReturn);
		if(0 == uReturn || FAILED(hr))
			break;

		variant_t vtTag;           // unique tag, e.g. '\\.\PHYSICALDRIVE0'
		variant_t vtSerialNumber;  // manufacturer-provided serial number

		hr = pIWbemClassObject->Get(L"Tag", 0, &vtTag, NULL, NULL);
		ATLENSURE_SUCCEEDED(hr);

		CString strTag(vtTag.bstrVal);
		if(!strTag.CompareNoCase(strDrivePath)) // physical drive found
		{
			hr = pIWbemClassObject->Get(L"SerialNumber", 0, &vtSerialNumber, NULL, NULL);
			ATLENSURE_SUCCEEDED(hr);
			strSerialNumber = vtSerialNumber.bstrVal; // get the serial number
			break;
		}
	}
}

char* GetHardDiskSN(unsigned int diskIndex)
{
	CString strResult;
	//try
	{
		// 1. Initialize COM 
		// http://msdn.microsoft.com/en-us/library/windows/desktop/aa390885(v=vs.85).aspx
		HRESULT hr = ::CoInitializeEx(0, COINIT_MULTITHREADED); 

		ATLENSURE_SUCCEEDED(hr);

		CString strSerialNumber;
		UINT nDriveNumber = diskIndex;
		GetPhysicalDriveSerialNumber(nDriveNumber, strSerialNumber);
		strResult.Format(_T("%s"), strSerialNumber);
	}
	//catch(CAtlException& e)
	{
		//strResult.Format(_T("Get hard disk serial number failure. Error code: 0x%08X"), (HRESULT)e);
	}

	// Uninitialize COM
	::CoUninitialize();
	char * result = new char[strResult.GetLength() + 1];
	strResult.Replace('-', '_');
	strcpy_s(result, MAX_PATH, W2C(strResult.GetString()));
	//MessageBoxW(NULL, C2W(result), L"Get SNdisk", MB_OK);
	return result;
}

IDE_INFO ReadPhysicalDriveInNTUsingSmart (void)
{
	int drive = 0;

	IDE_INFO ideInfo;
	ZeroMemory(&ideInfo, sizeof(ideInfo));

	OSVERSIONINFO version;
	memset (&version, 0, sizeof (version));
	version.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
	GetVersionEx (&version);

	if (version.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		HANDLE hPhysicalDriveIOCTL = 0;

		//  Try to get a handle to PhysicalDrive IOCTL, report failure
		//  and exit if can't.
		TCHAR driveName [256];

		swprintf (driveName, 256, _T("\\\\.\\PhysicalDrive%d"), drive);

		//  Windows NT, Windows 2000, Windows Server 2003, Vista
		hPhysicalDriveIOCTL = CreateFile (driveName,
			GENERIC_READ | GENERIC_WRITE, 
			FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE, 
			NULL, OPEN_EXISTING, 0, NULL);

		if (hPhysicalDriveIOCTL != INVALID_HANDLE_VALUE)
		{
			GETVERSIONINPARAMS GetVersionParams;
			DWORD cbBytesReturned = 0;

			// Get the version, etc of PhysicalDrive IOCTL
			memset ((void*) & GetVersionParams, 0, sizeof(GetVersionParams));

			if ( DeviceIoControl (hPhysicalDriveIOCTL, SMART_GET_VERSION,
				NULL, 
				0,
				&GetVersionParams, sizeof (GETVERSIONINPARAMS),
				&cbBytesReturned, NULL) )
			{
				// Print the SMART version
				// PrintVersion (& GetVersionParams);
				// Allocate the command buffer
				ULONG CommandSize = sizeof(SENDCMDINPARAMS) + IDENTIFY_BUFFER_SIZE;
				PSENDCMDINPARAMS Command = (PSENDCMDINPARAMS) malloc (CommandSize);
				// Retrieve the IDENTIFY data
				// Prepare the command
				Command -> irDriveRegs.bCommandReg = ID_CMD;
				DWORD BytesReturned = 0;
				if ( DeviceIoControl (hPhysicalDriveIOCTL, 
					SMART_RCV_DRIVE_DATA, Command, sizeof(SENDCMDINPARAMS),
					Command, CommandSize,
					&BytesReturned, NULL) )
				{
					// Print the IDENTIFY data
					DWORD diskdata [256];
					USHORT *pIdSector = (USHORT *) (PIDENTIFY_DATA) ((PSENDCMDOUTPARAMS) Command) -> bBuffer;

					for (int ijk = 0; ijk < 256; ijk++)
						diskdata [ijk] = pIdSector [ijk];

					//  copy the hard drive serial number to the buffer
					ConvertToString (diskdata, 10, 19, ideInfo.serialNumber);
					ConvertToString (diskdata, 27, 46, ideInfo.model);
					ConvertToString (diskdata, 23, 26, ideInfo.firmware);
				}
				// Done
				CloseHandle (hPhysicalDriveIOCTL);
				free (Command);
			}
		}
	}

	return ideInfo;
}

char *ConvertToString (DWORD diskdata [256], int firstIndex, int lastIndex, char* buf)
{
	int index = 0;
	int position = 0;

	//  each integer has two characters stored in it backwards
	for (index = firstIndex; index <= lastIndex; index++)
	{
		if ((char) (diskdata [index] / 256) != ' ')
		{
			//  get high byte for 1st character
			buf [position++] = (char) (diskdata [index] / 256);
		}
		if ((char) (diskdata [index] % 256) != ' ')
		{
			//  get low byte for 2nd character
			buf [position++] = (char) (diskdata [index] % 256);
		}
	}

	//  end the string 
	buf[position] = '\0';

	//  cut off the trailing blanks
	for (index = position - 1; index > 0 && isspace(buf [index]); index--)
		buf [index] = '\0';

	return buf;
}

char* GetMACAddress(){
	PIP_ADAPTER_INFO AdapterInfo;
	DWORD dwBufLen = sizeof(AdapterInfo);
	char *mac_addr = (char*)malloc(17);

	AdapterInfo = (IP_ADAPTER_INFO *) malloc(sizeof(IP_ADAPTER_INFO));
	if (AdapterInfo == NULL) {
		//printf("Error allocating memory needed to call GetAdaptersinfo\n");
	}

	// Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen     variable
	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW) {
		AdapterInfo = (IP_ADAPTER_INFO *) malloc(dwBufLen);
		if (AdapterInfo == NULL) {
			//printf("Error allocating memory needed to call GetAdaptersinfo\n");
		}
	}

	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR) {
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
		do {
			sprintf_s(mac_addr, MAX_PATH, "%02X:%02X:%02X:%02X:%02X:%02X",
				pAdapterInfo->Address[0], pAdapterInfo->Address[1],
				pAdapterInfo->Address[2], pAdapterInfo->Address[3],
				pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
			//printf("Address: %s, mac: %s\n", pAdapterInfo->IpAddressList.IpAddress.String, mac_addr);
			if (strcmp("0.0.0.0", pAdapterInfo->IpAddressList.IpAddress.String) == 0)
			{
				pAdapterInfo = pAdapterInfo->Next;
				continue;
			}
			return mac_addr;
		}while(pAdapterInfo);
	}
	free(AdapterInfo);
	return mac_addr;
}

BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;

	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.

	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;
	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress( GetModuleHandle(C2W( (sz__kernel32))),  (sz__IsWow64Process));

	if(NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}

void GetOS(char theos[MAX_PATH])
{
	ZeroMemory(theos, MAX_PATH);
	OSVERSIONINFO OS;
	OS.dwOSVersionInfoSize = sizeof(OS);
	GetVersionEx(&OS);
	switch (OS.dwPlatformId)
	{
	case 0:
		strcpy_s(theos, MAX_PATH,(sz__Win3_1));
		break;
	case 1:
		switch (OS.dwMinorVersion)
		{
		case 0:
			strcpy_s(theos, MAX_PATH, (sz__Win95));
			break;
		case 10:
			strcpy_s(theos, MAX_PATH, (sz__Win98));
			break;
		case 98:
			strcpy_s(theos, MAX_PATH, (sz__WinMe));
			break;
		}
		break;
	case 2:
		switch (OS.dwMajorVersion)
		{
		case 3:
			strcpy_s(theos, MAX_PATH, (sz__WinNT));
			break;
		case 4:
			strcpy_s(theos, MAX_PATH, (sz__WinNT));
			break;
		case 5:
			switch (OS.dwMinorVersion)
			{
			case 0:
				strcpy_s(theos, MAX_PATH, (sz__Win2000));
				break;
			case 1:
			case 2:
				strcpy_s(theos, MAX_PATH, (sz__WinXP));
				break;
			}
			break;
		case 6:
			switch (OS.dwMinorVersion)
			{
			case  0:
				strcpy_s(theos, MAX_PATH, (sz__Vista));
				break;
			case 1:
				strcpy_s(theos, MAX_PATH, (sz__Win7));
				break;
			case 2:
				strcpy_s(theos, MAX_PATH, (sz__Win8));
				break;
			case 3:
				strcpy_s(theos, MAX_PATH, (sz__Win8_1));
				break;
			}
			break;
		case 10:
			switch (OS.dwMinorVersion)
			{
			case  0:
				strcpy_s(theos, MAX_PATH, (sz__Win10));
				break;
			}
			break;
		}
		break;
	}
	int x =strlen(theos);
	if (x <=0)
	{
		strcpy_s(theos, MAX_PATH, (sz__Unknown_OS));
	}
	if (IsWow64())
	{
		strcat_s(theos, MAX_PATH, (sz____64bit));
	}
	else
	{
		strcat_s(theos, MAX_PATH, (sz____32bit));
	}
}

char* GetIPHost()
{
	//return "125.212.222.163";
	return "203.116.112.222";
}
//=====================================================
//======== Encrypt - Decrypt using Wincrypt.h =========
//=====================================================
CCrypt::CCrypt(void)
{
	m_hProv= m_hHash= m_hKey= 0; 
	m_pszDefaultKeyRaw=  (sz__fdC_Y_yum3ww09);
}
BOOL CCrypt::SetKey( LPCSTR szKey, LPCSTR szSalt/*=0*/ )
{
	m_fOK= TRUE;
	if ( 0 == m_hProv ) {
		m_fOK= CryptAcquireContext( &m_hProv, NULL, 
			//MS_DEF_PROV, 
			NULL, 
			PROV_RSA_FULL, 
			CRYPT_VERIFYCONTEXT 
			);
	}
	if ( m_fOK && (0 != m_hHash) ) {
		m_fOK= CryptDestroyHash( m_hHash ); 
		m_hHash= 0;
	}
	if ( m_fOK && (0 == m_hHash) ) {
		m_fOK= CryptCreateHash( m_hProv, CALG_MD5, 0, 0, &m_hHash );
	}
	if ( m_fOK ) {
		if ( 0 == szKey ) {  // request to use default rawKey
			char szTmp[100];
			strcpy_s( szTmp, sizeof(szTmp), m_pszDefaultKeyRaw );
			if ( szSalt ) {
				strncat_s( szTmp, sizeof(szTmp), szSalt, 5 ); // use part of salt
			}
			// minor security tweak -- scramble the key+salt
			int nLen= strlen(szTmp)-1;  
			for ( int j=0; j< nLen; j++ ) {
				char c= szTmp[nLen-j];
				szTmp[nLen-j]= (char)(szTmp[j]+5);
				szTmp[j]= c;
			}
			szKey= &szTmp[4]; // discard the first part, for fun
		}
		m_fOK= CryptHashData( m_hHash, (BYTE*)szKey, strlen(szKey), 0);
	}
	if ( m_fOK ) {
		m_fOK= CryptDeriveKey( m_hProv, CALG_RC4, m_hHash, CRYPT_EXPORTABLE, &m_hKey);
	}
	if ( !m_fOK ) { 
		m_nLastErr= GetLastError(); 
		//m_sErrMsg= "Error creating encryption key";
	}
	return( m_fOK );
}
//--- workhorse function:  Encrypt or decrypt "in place"
BOOL CCrypt::EncryptDecrypt( BYTE* pData, DWORD* dwDataLen, LPCSTR pKey, BOOL fEncrypt )
{
	m_fOK= TRUE;
	SetKey( (LPCSTR)pKey );	
	if ( fEncrypt ) {
		m_fOK= CryptEncrypt( m_hKey, 0, TRUE, 0, pData, dwDataLen, *dwDataLen );
	}
	else  {
		m_fOK= CryptDecrypt( m_hKey, 0, TRUE, 0, pData, dwDataLen );
	}
	return( m_fOK );
}

CString CCrypt::EncryptStrToHex( LPCSTR szText, LPCSTR pszKey/*= 0*/, LPCSTR pszSalt/*= 0*/ )
{
	m_fOK= TRUE;
	CString sRet= L"";
	DWORD nDataLen= strlen( szText );
	if ( pszSalt || pszKey || (0 == m_hKey) ) {
		m_fOK= SetKey( (LPCSTR)pszKey, pszSalt );	
	}
	if ( m_fOK ) {
		char* pTmp= new char[nDataLen+1] ;
		strncpy_s( pTmp, nDataLen+1, szText, nDataLen+1 );
		m_fOK= CryptEncrypt( m_hKey, 0, TRUE, 0, (BYTE*)pTmp, &nDataLen, nDataLen );
		if (m_fOK ) {
			sRet= EncodeToHex( (BYTE*)pTmp, nDataLen );
		}
		delete pTmp;
	}
	return( sRet );
}

CString CCrypt::DecryptStrFromHex( LPCSTR szHex, LPCSTR pszKey/*=0*/, LPCSTR pszSalt/*= 0*/ )
{
	m_fOK= TRUE;
	CString sRet= L"";
	DWORD nDataLen= strlen( szHex );

	if ( pszSalt || pszKey || (0 == m_hKey) ) {
		m_fOK= SetKey( (LPCSTR)pszKey, pszSalt );	
	}
	if ( m_fOK ) {
		DWORD nDecryptLen= nDataLen/2;
		char* pTmp= new char[ nDecryptLen+1 ];
		DecodeFromHex( szHex, (BYTE*)pTmp, nDecryptLen );
		m_fOK= CryptDecrypt( m_hKey, 0, TRUE, 0, (BYTE*)pTmp, &nDecryptLen );
		if ( m_fOK ) {
			sRet= pTmp;
		}
		delete pTmp;
	}
	return( sRet );
}

//--------------------------------------------------------
// inefficient but requires no explanation :-)
CString CCrypt::EncodeToHex( BYTE* p, int nLen )
{
	CString sRet, sTmp;
	for( int j=0; j< nLen; j++ ) {
		sTmp.Format( C2W( (sz___02x)), p[j] );
		sRet+= sTmp;
	}
	return (sRet );
}

//---------------------------------------------------------
// returns length of decoded hex buffer
int CCrypt::DecodeFromHex( LPCSTR pSrc, BYTE* pDest, int nBufLen )
{
	int nRet= 0;
	int nLen= strlen(pSrc);
	*pDest = 0;
	BYTE cIn1, cIn2, nFinal;
	for( int j=0; j< nLen; j += 2 ) {
		cIn1= (BYTE)toupper(*pSrc++);  cIn1 -= '0'; if ( cIn1>9 ) cIn1 -= 7;
		cIn2= (BYTE)toupper(*pSrc++);  cIn2 -= '0'; if ( cIn2>9 ) cIn2 -= 7;
		nFinal= (BYTE)((cIn1 << 4) | cIn2); 
		if (nFinal>255) nFinal=0; // in case trying to decode non-hex data
		*pDest++ = nFinal; 
		*pDest = 0;
		if ( nRet >= nBufLen ) {
			break;
		}
		nRet++;
	}
	return( nRet );
}
//=====================================================
//======== Encrypt - Decrypt using Wincrypt.h ===END===
//=====================================================

//=====================================================
//========== File Manager - User Information ==========
//=====================================================
CFileUserInfoMgr* CFileUserInfoMgr::s_Instance = NULL;

void CFileUserInfoMgr::AddUser(CUserInfo &aUser)
{
	int index = 0;
	while (strcmp(m_ListUser[index].GetUser(), "") != 0)
	{
		if (strcmp(m_ListUser[index].GetUser(), aUser.GetUser()) == 0)
		{ // user nay da duoc luu, chi can cap nhat lai du lieu moi
			m_ListUser[index] = aUser;
			return;
		}
		++index;
	}
	m_ListUser[index] = aUser;
}

CUserInfo CFileUserInfoMgr::GetUserLogin()
{
	CUserInfo EmptyUser;
	int index = 0;
	while (strcmp(m_ListUser[index].GetUser(), "") != 0)
	{
		if (m_ListUser[index].GetLogin() == true)
		{ // user nay vua login
			if (m_ListUser[index].GetEncrypt() == true)
			{
				m_ListUser[index].Decrypt();
			}
			return m_ListUser[index];
		}
		++index;
	}
	return EmptyUser;
}

//==========================================================================================================
void Crypt(TCHAR *inp, DWORD inplen, TCHAR* key, DWORD keylen)
{
	//we will consider size of sbox 256 bytes
	//(extra byte are only to prevent any mishep just in case)
	TCHAR Sbox[257], Sbox2[257];
	unsigned long i, j, t, x;

	TCHAR temp, k;
	i = j = t = x = 0;
	temp = 0;
	k = 0;

	//always initialize the arrays with zero
	ZeroMemory(Sbox, sizeof(Sbox));
	ZeroMemory(Sbox2, sizeof(Sbox2));

	//initialize sbox i
	for (i = 0; i < 256U; i++)
	{
		Sbox[i] = (TCHAR)i;
	}

	j = 0;
	//whether user has sent any inpur key
	if (keylen)
	{
		//initialize the sbox2 with user key
		for (i = 0; i < 256U; i++)
		{
			if (j == keylen)
			{
				j = 0;
			}
			Sbox2[i] = key[j++];
		}
	}

	j = 0; //Initialize j
		   //scramble sbox1 with sbox2
	for (i = 0; i < 256; i++)
	{
		j = (j + (unsigned long)Sbox[i] + (unsigned long)Sbox2[i]) % 256U;
		temp = Sbox[i];
		Sbox[i] = Sbox[j];
		Sbox[j] = temp;
	}

	i = j = 0;
	for (x = 0; x < inplen; x++)
	{
		//increment i
		i = (i + 1U) % 256U;
		//increment j
		j = (j + (unsigned long)Sbox[i]) % 256U;

		//Scramble SBox #1 further so encryption routine will
		//will repeat itself at great interval
		temp = Sbox[i];
		Sbox[i] = Sbox[j];
		Sbox[j] = temp;

		//Get ready to create pseudo random  byte for encryption key
		t = ((unsigned long)Sbox[i] + (unsigned long)Sbox[j]) % 256U;

		//get the random byte
		k = Sbox[t];

		//xor with the data and done
		//__oMsg("T: %d = %d [k=%d]", x, inp[x], k);
		inp[x] = (inp[x] ^ k);
		if (inp[x] == 0)
		{
			inp[x] = inp[x] ^ k;
			//__oMsg("Bang-0 roi day : %d", inp[x]);
		}
	}
}

//==========================================================================================================
void Crypt_2(char *inp, DWORD inplen, char* key, DWORD keylen)
{
	//we will consider size of sbox 256 bytes
	//(extra byte are only to prevent any mishep just in case)
	char Sbox[257], Sbox2[257];
	unsigned long i, j, t, x;

	char temp, k;
	i = j = t = x = 0;
	temp = 0;
	k = 0;

	//always initialize the arrays with zero
	ZeroMemory(Sbox, sizeof(Sbox));
	ZeroMemory(Sbox2, sizeof(Sbox2));

	//initialize sbox i
	for (i = 0; i < 256U; i++)
	{
		Sbox[i] = (char)i;
	}

	j = 0;
	//whether user has sent any inpur key
	if (keylen)
	{
		//initialize the sbox2 with user key
		for (i = 0; i < 256U; i++)
		{
			if (j == keylen)
			{
				j = 0;
			}
			Sbox2[i] = key[j++];
		}
	}

	j = 0; //Initialize j
	//scramble sbox1 with sbox2
	for (i = 0; i < 256; i++)
	{
		j = (j + (unsigned long)Sbox[i] + (unsigned long)Sbox2[i]) % 256U;
		temp = Sbox[i];
		Sbox[i] = Sbox[j];
		Sbox[j] = temp;
	}

	i = j = 0;
	for (x = 0; x < inplen; x++)
	{
		//increment i
		i = (i + 1U) % 256U;
		//increment j
		j = (j + (unsigned long)Sbox[i]) % 256U;

		//Scramble SBox #1 further so encryption routine will
		//will repeat itself at great interval
		temp = Sbox[i];
		Sbox[i] = Sbox[j];
		Sbox[j] = temp;

		//Get ready to create pseudo random  byte for encryption key
		t = ((unsigned long)Sbox[i] + (unsigned long)Sbox[j]) % 256U;

		//get the random byte
		k = Sbox[t];

		//xor with the data and done
		//__oMsg("T: %d = %d [k=%d]", x, inp[x], k);
		inp[x] = (inp[x] ^ k);
		if (inp[x] == 0)
		{
			inp[x] = inp[x] ^ k;
			//__oMsg("Bang-0 roi day : %d", inp[x]);
		}
		//__oMsg("S: %d = %d [k=%d]",x, inp[x], k);
	}
}

//==========================================================================================================
void CFileUserInfoMgr::SaveInfo2File(char* filename)
{
	TCHAR szExeFileName[MAX_PATH];
	GetModuleFileName(NULL, szExeFileName, MAX_PATH);
	string strPath(W2C(szExeFileName));
	strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
	strPath = strPath.append(filename);
	ofstream userInfoFile (strPath.c_str(), ios::binary);
	//__oMsg("path exe file: %s; data file: %s", W2C(szExeFileName), strPath.c_str());
	if (userInfoFile.is_open())
	{
		/*int index = 0;
		while ( strcmp(m_ListUser[index].GetUser(), "") != 0 )
		{
			//__oMsg("ghi file exe: %s, %s, %s", m_ListUser[index].GetUser(), m_ListUser[index].GetPass(), m_ListUser[index].GetSessionID());
			//m_ListUser[index].Encrypt();

			char str_write[MAX_PATH] = "";
			strcat(str_write, m_ListUser[index].GetUser());			
			strcat(str_write,"|");
			strcat(str_write, m_ListUser[index].GetPass());
			strcat(str_write, "|");
			strcat(str_write, m_ListUser[index].GetSessionID());
			
			//OutputDebugStringA(str_write);
						
			char sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };

			TCHAR* Key = C2W(sz__fdC_Y_yum3ww09);

			//OutputDebugStringW(Key);

			TCHAR* Data = C2W(str_write);

			//OutputDebugStringW(Data);

			//Encrypt
			Crypt(Data, _tcslen(Data), Key, _tcslen(Key));

			//char *str_write_enc = W2C(Data);

			char content[MAX_PATH];
			size_t   i;
			wcstombs_s(&i, content, Data, _tcslen(Data));

			strcat(content, "%%%");

			//OutputDebugStringA(content);

			userInfoFile.write(content, sizeof(content));

			++index;
		}
		userInfoFile.close();
		*/
		int index = 0;
		while (strcmp(m_ListUser[index].GetUser(), "") != 0)
		{
			//__oMsg("[SAVE-FILE-2]: ghi file dll: %s, %s, %s", m_ListUser[index].GetUser(), m_ListUser[index].GetPass(), m_ListUser[index].GetSessionID());
			m_ListUser[index].Encrypt();
			userInfoFile.write((char*)&m_ListUser[index], sizeof(CUserInfo));
			++index;
		}
		userInfoFile.close();
	}
	//else __oMsg("Unable to open file:%s", filename);
}

void CFileUserInfoMgr::ReadInfoFromFile(char* filename)
{
	TCHAR szExeFileName[MAX_PATH];
	GetModuleFileName(NULL, szExeFileName, MAX_PATH);
	string strPath(W2C(szExeFileName));
	strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
	strPath = strPath.append(filename);
	ifstream userInfoFile (strPath.c_str(), ios::binary);
	//__oMsg("path exe file: %s; data file: %s", W2C(szExeFileName), strPath.c_str());
	int nIndex = 0;
	if (userInfoFile.is_open())
	{
		while ( userInfoFile.read((char*)&m_ListUser[nIndex], sizeof(CUserInfo)) )
		{
			m_ListUser[nIndex].Decrypt();
			//__oMsg("doc file exe: %s, %s, %s", m_ListUser[nIndex].GetUser(), m_ListUser[nIndex].GetPass(), m_ListUser[nIndex].GetSessionID());
			++nIndex;
		}
		userInfoFile.close();
	}
	else
	{
		//__oMsg("Unable to open file:%s", filename); 
		SaveInfo2File(filename);
	}

}

//void CFileUserInfoMgr::ShowListUser()
//{
//	CUserInfo userInfo;
//	int index = 0;
//	while (strcmp(m_ListUser[index].GetUser(), "") != 0)
//	{
//		userInfo = m_ListUser[index];
//		++index;
//		cout << userInfo.GetUser() << '\n';
//		cout << userInfo.GetPass() << '\n';
//		cout << userInfo.GetSessionID() << '\n';
//		cout << userInfo.GetLogin() << '\n';
//		cout << userInfo.GetSavePass() << '\n';
//	}
//}
//=====================================================
//========== File Manager - User Information ===END====
//=====================================================

//============ Process Result From Server =============
vector<string> split(const string &source, char delimit) {
	vector<string> elems;
	stringstream ssSource;
	ssSource.str(source);
	string item;
	while (getline(ssSource, item, delimit)) {
		elems.push_back(item);
	}
	return elems;
}
char* GetValueFromVectorString(vector<string> vSource, int indexValue)
{
	if (vSource.size() <= (unsigned)indexValue) return NULL;
	vector<string> vResult = split(vSource[indexValue], '=');
	if (vResult.size() <= 1) return NULL;
	//int x = vResult[1].length();
	char* ret = new char[vResult[1].length() + 1];
	strcpy_s(ret, MAX_PATH, vResult[1].c_str());
	vResult.clear();
	return ret;
};
//============ Process Result From Server =====END=====

TCHAR* GenerateTitle()
{
	//TCHAR szASCII[] = L"0123456789ABCDEFGHIKLMabc";
	//srand(time(NULL));
	//BYTE x = rand() % 5 + 8;   // khoang do dai 8-12
	//TCHAR szTitle[13]; // toi da 12 ky tu
	//__oMsg("x o ngoai=%d", x);
	//for(int i = 0; i < x; ++i)
	//{
	//	x = rand() % 27;
	//	__oMsg("x o trong=%d", x);
	//	szTitle[i] = (TCHAR)szASCII[x];   // value in the range 32-126
	//}
	//szTitle[x] = 0;
	//return szTitle;

	srand((unsigned)time(NULL));
	BYTE nLength = rand() % 5 + 8;   // khoang do dai 8-12
	char szRandomTitle[13]; // lay toi da
	//gen_random(s, x);
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < nLength; ++i) {
		szRandomTitle[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	szRandomTitle[nLength] = 0;
	return C2W(szRandomTitle);
}
void gen_random(char *s, const int len) {
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}
TCHAR* GetTitle()
{
	return L"Toir+";
#define NUM_ROW_OF_ARRAY 43
	char szTitle[NUM_ROW_OF_ARRAY][100] = {
		"Google - Google Chrome",
		"New Tab - Google Chrome",
		"Google - Mozilla Firefox",
		"Mozilla Firefox",
		"Mozilla Firefox Start Page - Mozilla Firefox",
		"New Tab - Mozilla Firefox",
		"Skype",
		"Garena+ (Beta)",
		"PVP.net Client",
		"TeamViewer",
		"UltraViewer 5.1 - Free",
		"UltraViewer 5.0.23 - Free",
		"UltraViewer 5.0.24 - Free",
		"UltraViewer 5.0.20 - Free",
		"UltraViewer 5.0.21 - Free",
		"UltraViewer 5.0.23 - Free",
		"untitled - Paint",
		"UniKey 4.2 RC4",
		"UniKey 4.0 RC2",
		"Untitled - Notepad",
		"Document - WordPad",
		"new 3 - Notepad++",
		"new 1 - Notepad++",
		"new 2 - Notepad++",
		"Release - WinRAR",
		"7-Zip File Manager",
		"Microsoft Excel - Book1",
		"Book1 - Microsoft Excel",
		"Document1 - Microsoft Word",
		"Internet Download Manager 6.19",
		"Internet Download Manager 6.20",
		"Internet Download Manager 6.21",
		"Internet Download Manager 6.22",
		"Internet Download Manager 6.23",
		"Microsoft Visual Studio",
		"Calculator",
		"KMPlayer",
		"Command Prompt",
		"Total Commander 9.0a - NOT REGISTERED",
		"Desktop",
		"My Computer",
		"Downloads",
		"Piriform CCleaner"
	};
	srand((unsigned)time(NULL));
	BYTE nRowOfArray = rand() % NUM_ROW_OF_ARRAY;   // khoang gia tri 0-42
	return C2W(szTitle[nRowOfArray]);
}
