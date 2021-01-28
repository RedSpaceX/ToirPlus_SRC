#include "stdafx.h"
#include "Server.h"

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
	//BOOL (WINAPI *DoDnsFlushResolverCache)();
	//*(FARPROC *)&DoDnsFlushResolverCache = GetProcAddress(LoadLibraryA(sz__dnsapi_dll), sz__DnsFlushResolverCache);
	//if(!DoDnsFlushResolverCache) return FALSE;
	//return DoDnsFlushResolverCache();
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool g_bCheckConnectDLL = true;//true = Https
char* GetCurrentVersion()
{
	//LPCWSTR server=C2W( (sz__autolols_com));
	//if (g_bCheckConnectDLL == false)
	//{
	//	server = C2W( (sz__autolols01_clemas_vn));
	//}
	//LPCWSTR strURI=C2W( (sz___checkversion_php));

	//DWORD dwSize = 0;
	//DWORD dwDownloaded = 0;
	//LPSTR pszOutBuffer = NULL;
	//BOOL  bResults = FALSE;
	//HINTERNET hSession = NULL,
	//	hConnect = NULL,
	//	hRequest = NULL;

	//// Use WinHttpOpen to obtain a session handle.
	//hSession = WinHttpOpen( C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
	//	WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
	//	WINHTTP_NO_PROXY_NAME, 
	//	WINHTTP_NO_PROXY_BYPASS, 0);

	//if (g_bCheckConnectDLL == true)
	//{
	//	// Specify an HTTP server.
	//	if (hSession)
	//		hConnect = WinHttpConnect( hSession, server,
	//		INTERNET_DEFAULT_HTTPS_PORT, 0);

	//	// Create an HTTP Request handle.
	//	if (hConnect)
	//		hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
	//		strURI, 
	//		0, WINHTTP_NO_REFERER, 
	//		WINHTTP_DEFAULT_ACCEPT_TYPES,
	//		WINHTTP_FLAG_SECURE);
	//}
	//else
	//{
	//	// Specify an HTTP server.
	//	if (hSession)
	//		hConnect = WinHttpConnect( hSession, server,
	//		INTERNET_DEFAULT_HTTP_PORT, 0);

	//	// Create an HTTP Request handle.
	//	if (hConnect)
	//		hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
	//		strURI, 
	//		0, WINHTTP_NO_REFERER, 
	//		WINHTTP_DEFAULT_ACCEPT_TYPES,
	//		0);
	//}

	//// Send a Request.
	//if (hRequest) 
	//	bResults = WinHttpSendRequest( hRequest, 
	//	//WINHTTP_NO_ADDITIONAL_HEADERS,
	//	C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
	//	-1, "", 0, 
	//	0, 0);

	//// End the request.
	//if (bResults)
	//	bResults = WinHttpReceiveResponse( hRequest, NULL);

	//// Keep checking for data until there is nothing left.
	//if (bResults)
	//{
	//	do 
	//	{
	//		// Check for available data.
	//		dwSize = 0;
	//		if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
	//		{
	//			//printf( "Error %u in WinHttpQueryDataAvailable.\n",	GetLastError());
	//			break;
	//		}

	//		// No more available data.
	//		if (!dwSize)
	//			break;

	//		// Allocate space for the buffer.
	//		pszOutBuffer = new char[dwSize+1];
	//		if (!pszOutBuffer)
	//		{
	//			//printf("Out of memory\n");
	//			break;
	//		}

	//		// Read the Data.
	//		ZeroMemory(pszOutBuffer, dwSize+1);

	//		if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
	//			dwSize, &dwDownloaded))
	//		{
	//			//printf( "Error %u in WinHttpReadData.\n", GetLastError());
	//		}
	//		else
	//		{
	//			//printf("%s", pszOutBuffer);
	//		}

	//		// Free the memory allocated to the buffer.
	//		//delete [] pszOutBuffer;

	//		// This condition should never be reached since WinHttpQueryDataAvailable
	//		// reported that there are bits to read.
	//		if (!dwDownloaded)
	//			break;

	//	} while (dwSize > 0);
	//}
	//else
	//{
	//	// Report any errors.
	//	//printf( "Error %d has occurred.\n", GetLastError() );
	//}

	//// Close any open handles.
	//if (hRequest) WinHttpCloseHandle(hRequest);
	//if (hConnect) WinHttpCloseHandle(hConnect);
	//if (hSession) WinHttpCloseHandle(hSession);
	////MessageBox(NULL, pszOutBuffer, NULL, MB_OK);
	//return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetCurrentVersion4WinXP()
{
	//LPCWSTR server=C2W( (sz__autolols_com));
	//if (g_bCheckConnectDLL == false)
	//{
	//	server = C2W( (sz__autolols01_clemas_vn));
	//}
	//LPCWSTR strURI=C2W( (sz___checkversion_php));
	////MessageBoxW(NULL, C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)), NULL, MB_OK);

	//DWORD dwSize = 0;
	//DWORD dwDownloaded = 0;
	//LPSTR pszOutBuffer = NULL;
	//BOOL  bResults = FALSE;
	//HINTERNET hSession = NULL,
	//	hConnect = NULL,
	//	hRequest = NULL;

	//// Use WinHttpOpen to obtain a session handle.
	//hSession = WinHttpOpen(  C2W( (sz__A_WinHTTP_Example_Program_1_0)), 
	//	WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
	//	WINHTTP_NO_PROXY_NAME, 
	//	WINHTTP_NO_PROXY_BYPASS, 0);
	////printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	//if (g_bCheckConnectDLL == true)
	//{
	//	// Specify an HTTP server.
	//	if (hSession)
	//		hConnect = WinHttpConnect( hSession, server,
	//		INTERNET_DEFAULT_HTTPS_PORT, 0);

	//	// Create an HTTP Request handle.
	//	if (hConnect)
	//		hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
	//		strURI, 
	//		0, WINHTTP_NO_REFERER, 
	//		WINHTTP_DEFAULT_ACCEPT_TYPES,
	//		WINHTTP_FLAG_SECURE);
	//}
	//else
	//{
	//	// Specify an HTTP server.
	//	if (hSession)
	//		hConnect = WinHttpConnect( hSession, server,
	//		INTERNET_DEFAULT_HTTP_PORT, 0);

	//	// Create an HTTP Request handle.
	//	if (hConnect)
	//		hRequest = WinHttpOpenRequest( hConnect, C2W( (sz__POST)), 
	//		strURI, 
	//		0, WINHTTP_NO_REFERER, 
	//		WINHTTP_DEFAULT_ACCEPT_TYPES,
	//		0);
	//}

	//bool retry = true;
	//DWORD result;
	//do
	//{
	//	retry = false;
	//	result = NO_ERROR;

	//	// no retry on success, possible retry on failure
	//	// Send a Request.
	//	if (hRequest) 
	//		bResults = WinHttpSendRequest( hRequest, 
	//		//WINHTTP_NO_ADDITIONAL_HEADERS,
	//		C2W( (sz__Content_Type__application_x_www_form_urlencoded_r_n)),
	//		-1, "", 0, 
	//		0, 0);
	//	//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	//	if(bResults == 0)
	//	{
	//		result = GetLastError();
	//		//printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );

	//		// (1) If you want to allow SSL certificate errors and continue
	//		// with the connection, you must allow and initial failure and then
	//		// reset the security flags. From: "HOWTO: Handle Invalid Certificate
	//		// Authority Error with WinInet"
	//		// http://support.microsoft.com/default.aspx?scid=kb;EN-US;182888
	//		if(result == ERROR_WINHTTP_SECURE_FAILURE)
	//		{
	//			DWORD dwFlags =
	//				SECURITY_FLAG_IGNORE_UNKNOWN_CA |
	//				SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE |
	//				SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
	//				SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

	//			if(WinHttpSetOption(
	//				hRequest,
	//				WINHTTP_OPTION_SECURITY_FLAGS,
	//				&dwFlags,
	//				sizeof(dwFlags)))
	//			{
	//				retry = true;
	//			}
	//		}
	//		// (2) Negotiate authorization handshakes may return this error
	//		// and require multiple attempts
	//		// http://msdn.microsoft.com/en-us/library/windows/desktop/aa383144%28v=vs.85%29.aspx
	//		else if(result == ERROR_WINHTTP_RESEND_REQUEST)
	//		{
	//			retry = true;
	//		}
	//	}
	//} while(retry);

	//// End the request.
	//if (bResults)
	//	bResults = WinHttpReceiveResponse( hRequest, NULL);
	////printf( "[line:%d]Error %d has occurred.\n", __LINE__, GetLastError() );
	//// Keep checking for data until there is nothing left.
	//if (bResults)
	//{
	//	do 
	//	{
	//		// Check for available data.
	//		dwSize = 0;
	//		if (!WinHttpQueryDataAvailable( hRequest, &dwSize)) 
	//		{
	//			//printf( "Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
	//			break;
	//		}

	//		// No more available data.
	//		if (!dwSize)
	//			break;

	//		// Allocate space for the buffer.
	//		pszOutBuffer = new char[dwSize+1];
	//		if (!pszOutBuffer)
	//		{
	//			//printf("Out of memory\n");
	//			break;
	//		}

	//		// Read the Data.
	//		ZeroMemory(pszOutBuffer, dwSize+1);

	//		if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
	//			dwSize, &dwDownloaded))
	//		{
	//			//printf( "Error %u in WinHttpReadData.\n", GetLastError());
	//		}
	//		else
	//		{
	//			//printf("%s", pszOutBuffer);
	//		}

	//		// Free the memory allocated to the buffer.
	//		//delete [] pszOutBuffer;

	//		// This condition should never be reached since WinHttpQueryDataAvailable
	//		// reported that there are bits to read.
	//		if (!dwDownloaded)
	//			break;

	//	} while (dwSize > 0);
	//}
	//else
	//{
	//	// Report any errors.
	//	//printf( "Error %d has occurred.\n", GetLastError() );
	//}

	//// Close any open handles.
	//if (hRequest) WinHttpCloseHandle(hRequest);
	//if (hConnect) WinHttpCloseHandle(hConnect);
	//if (hSession) WinHttpCloseHandle(hSession);
	//return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetRequestResult(const char* username, const char* password)
{
//VMProtectBegin("DLL_VM__GetRequestResult");
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectDLL == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___checklogin_php));

	static const IDE_INFO ideInfo = ReadPhysicalDriveInNTUsingSmart();
	char  data[250];
	char osName[64];
	GetOS(osName);
#define INFO_BUFFER_SIZE 32767
	TCHAR  pcName[INFO_BUFFER_SIZE];
	TCHAR  pcUser[INFO_BUFFER_SIZE] = _T("Default222");
	ZeroMemory(pcName, INFO_BUFFER_SIZE);
	//ZeroMemory(pcUser, INFO_BUFFER_SIZE);

	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	// Get and display the name of the computer. 
	bufCharCount = INFO_BUFFER_SIZE;
	GetComputerName( pcName, &bufCharCount );
	// Get and display the user name. 
	bufCharCount = INFO_BUFFER_SIZE;
	//GetUserName( pcUser, &bufCharCount );
	sprintf_s(data,  (sz__username__s_password__s_sndisk__s_os__s_pcname__s_pcuser__s_appversion__s_sessionid__s_timeused__d), username, password, strlen(ideInfo.serialNumber) != 0 ? ideInfo.serialNumber : GetMACAddress(), osName, pcName, pcUser,  (APPVERSION), CFileUserInfoMgr::GetInstance()->GetUserLogin().GetSessionID(), time(NULL));
	DWORD data_len = strlen(data);
	//__oMsg("data gui len: %s", data);

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

	if (g_bCheckConnectDLL == true)//https xem no co vao day ko
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
		//__oMsg("http-ssss: hSession=%x, hConnect=%x", hSession, hConnect);
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
		//__oMsg("http-0000: hSession=%x, hConnect=%x", hSession, hConnect);
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
	//__oMsg("bResults-1: =%x", bResults);
	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse( hRequest, NULL);
	//__oMsg("bResults-2: =%x", bResults);
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
//VMProtectEnd();
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetRequestResult4WinXP(const char* username, const char* password)
{
//VMProtectBegin("DLL_VM__GetRequestResult4WinXP");
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectDLL == false)
	{
		server = C2W( (sz__autolols01_clemas_vn));
	}
	LPCWSTR strURI=C2W( (sz___checklogin_php));

	static const IDE_INFO ideInfo = ReadPhysicalDriveInNTUsingSmart();
	char  data[250];
	char osName[64];
	GetOS(osName);
#define INFO_BUFFER_SIZE 32767
	TCHAR  pcName[INFO_BUFFER_SIZE];
	TCHAR  pcUser[INFO_BUFFER_SIZE] = _T("Default222");
	ZeroMemory(pcName, INFO_BUFFER_SIZE);
	//ZeroMemory(pcUser, INFO_BUFFER_SIZE);

	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	// Get and display the name of the computer. 
	bufCharCount = INFO_BUFFER_SIZE;
	GetComputerName( pcName, &bufCharCount );
	// Get and display the user name. 
	bufCharCount = INFO_BUFFER_SIZE;
	//GetUserName( pcUser, &bufCharCount );
	sprintf_s(data,  (sz__username__s_password__s_sndisk__s_os__s_pcname__s_pcuser__s_appversion__s_sessionid__s_timeused__d), username, password, strlen(ideInfo.serialNumber) != 0 ? ideInfo.serialNumber : GetMACAddress(), osName, pcName, pcUser,  (APPVERSION), CFileUserInfoMgr::GetInstance()->GetUserLogin().GetSessionID(), time(NULL));
	DWORD data_len = strlen(data);
	//__oMsg("data gui len: %s", data);

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

	if (g_bCheckConnectDLL == true)
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
//VMProtectEnd();
	return pszOutBuffer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* GetTimeServer()
{
	LPCWSTR server=C2W( (sz__autolols_com));
	if (g_bCheckConnectDLL == false)
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

	if (g_bCheckConnectDLL == true)
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
	if (g_bCheckConnectDLL == false)
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

	if (g_bCheckConnectDLL == true)
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
DWORD WINAPI ChooseLine(void*)
{
	CIniManager::GetInstance()->ReadIniFile();
	if (CIniManager::GetInstance()->GetChooseLine2())
	{
		g_bCheckConnectDLL = false;
	} 
	else
	{
		g_bCheckConnectDLL = IsWin7OrLater() ? TestConnect() : TestConnect4WinXP();
	}
	DnsFlushResolverCache();
	//__oMsg("chon line=%s", g_bCheckConnectDLL ? "https://AutoLoLs.com" : "http://AutoLoLs.clemas.vn");
	return g_bCheckConnectDLL;
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

//==================================================================================//
//==================================================================================//
//==================================================================================//
HWND g_hWinDLL;
extern bool g_Exit;
DWORD WINAPI CheckLogin(void *)
{
//VMProtectBegin("DLL_VM__CheckLogin");
	CFileUserInfoMgr::GetInstance()->ReadInfoFromFile( (sz__config_info_dat));
	char* szResult = NULL;
	//__oMsg("[CheckLogin-1] kiem tra dang nhap!:%s,%s", CFileUserInfoMgr::GetInstance()->GetUserLogin().GetUser(), CFileUserInfoMgr::GetInstance()->GetUserLogin().GetPass());
	if (IsWin7OrLater())
	{
		szResult = GetRequestResult(CFileUserInfoMgr::GetInstance()->GetUserLogin().GetUser(), CFileUserInfoMgr::GetInstance()->GetUserLogin().GetPass());
	} 
	else
	{
		szResult = GetRequestResult4WinXP(CFileUserInfoMgr::GetInstance()->GetUserLogin().GetUser(), CFileUserInfoMgr::GetInstance()->GetUserLogin().GetPass());
	}
	DnsFlushResolverCache();
	//__oMsg("[CheckLogin-2] ket qua tra ve tu server:%s", szResult);
	if (szResult == NULL)
	{
		//__oMsg("Loi dang nhap! ko lay duoc ket qua tra ve tu server");
		//g_hWinDLL = ::FindWindow(NULL, _T( (sz__League_of_Legends__TM__Client)));
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	}
	vector<string> result2Process = split(szResult, '&');
	char* ssid = GetValueFromVectorString(result2Process, SR_SESSION_ID);
	char *tsv = GetValueFromVectorString(result2Process, SR_TIME_SERVER);
	char *ec = GetValueFromVectorString(result2Process, SR_ERROR_CODE);
	result2Process.clear();
	if (ec)//tam thoi them cai nay vi tren server chua tra ve truong nay
	switch (atoi(ec))
	{
	case EC_SUCCESSFUL:
		break;
	case EC_INVALID_USERNAME:
		//__oMsg("Sai ten dang nhap");
		//SEND_TEXT_SYSTEM( (sz__Sai_ten_dang_nhap));
		SEND_TEXT_SYSTEM("wrong 1");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	case EC_WRONG_PASSWORD:
		//__oMsg("Sai mat khau");
		//SEND_TEXT_SYSTEM( (sz__Sai_mat_khau));
		SEND_TEXT_SYSTEM("wrong 2");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	case EC_LOGIN_OTHER_PLACE:
		//__oMsg("Tai khoan cua ban da bi dang nhap o noi khac111");
		//SEND_TEXT_SYSTEM( (sz__Tai_khoan_cua_ban_da_bi_dang_nhap_o_1_noi_khac));
		SEND_TEXT_SYSTEM("wrong 3");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	case EC_EXPIRED_ACCOUNT:
		//__oMsg("Tai khoan da het han su dung, nap them de tiep tuc su dung");
		//SEND_TEXT_SYSTEM( (sz__Tai_khoan_da_het_han_su_dung__nap_them_de_tiep_tuc_su_dung));
		SEND_TEXT_SYSTEM("wrong 4");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	case EC_IP_HOST_FROM_VN:
		//__oMsg("IP host ko phai cua quoc te");
		SEND_TEXT_SYSTEM("wrong 5");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	}
	if (!ssid)
	{
		//__oMsg("Tai khoan cua ban da bi dang nhap o noi khac222");
		//SEND_TEXT_SYSTEM( (sz__Tai_khoan_cua_ban_da_bi_dang_nhap_o_1_noi_khac));
		SEND_TEXT_SYSTEM("wrong 6");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;// tk da bi dang nhap o noi khac
	}
	// cap nhat session id
	CUserInfo userInfo;
	//__oMsg("ssid=%s;user=%s;pass=%s", ssid, CFileUserInfoMgr::GetInstance()->GetUserLogin().GetUser(), CFileUserInfoMgr::GetInstance()->GetUserLogin().GetPass());
	userInfo.SetSessionID(ssid);
	userInfo.SetUser(CFileUserInfoMgr::GetInstance()->GetUserLogin().GetUser());
	userInfo.SetPass(CFileUserInfoMgr::GetInstance()->GetUserLogin().GetPass());
	userInfo.SetLogin(true);
	CFileUserInfoMgr::GetInstance()->AddUser(userInfo);
	CFileUserInfoMgr::GetInstance()->SaveInfo2File( (sz__config_info_dat));
	
	__int64 nTimeServerResult = atoi(tsv); // lay time tu server
	__int64 nTimeServerRequest = time(NULL);
	if (IsWin7OrLater())
	{
		nTimeServerRequest = atoi(GetTimeServer());
	} 
	else
	{
		nTimeServerRequest = atoi(GetTimeServer4WinXP());
	}
	DnsFlushResolverCache();
	__int64 nTime2Check = nTimeServerRequest - nTimeServerResult;
	if (nTime2Check < 0) nTime2Check = -nTime2Check;
	if (nTime2Check >= 300)
	{
		//__oMsg("Loi dang nhap! gio may tinh bi sai, de nghi cap nhat lai gio may tinh");
		SEND_TEXT_SYSTEM("wrong 7");
		g_Exit = true;
		//UnmapDll_Real(g_hWinDLL);
		RecheckLoginMsg(false);
		return 0;
	}
	//InjectDll(g_hWinDLL);
	RecheckLoginMsg(true);
//VMProtectEnd();
	return 1;
}

//==========================================================================================================
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

//==========================================================================================================
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
	strcpy_s(result, MAX_PATH, strResult.GetString());
	return result;
}

//==========================================================================================================
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

		sprintf_s (driveName, "\\\\.\\PhysicalDrive%d", drive);

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

//==========================================================================================================
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

//==========================================================================================================
char* GetMACAddress()
{
	return "NULL";
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

//==========================================================================================================
BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;

	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.

	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;
	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress( GetModuleHandle( (sz__kernel32)),  (sz__IsWow64Process));

	if(NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}

//==========================================================================================================
void GetOS(char theos[MAX_PATH])
{
	ZeroMemory(theos, MAX_PATH);
	OSVERSIONINFO OS;
	OS.dwOSVersionInfoSize = sizeof(OS);
	GetVersionEx(&OS);
	switch (OS.dwPlatformId)
	{
	case 0:
		strcpy_s(theos, MAX_PATH, (sz__Win3_1));
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
				strcpy_s(theos, MAX_PATH,  (sz__Win8_1));
				break;
			}
			break;
		case 10:
			switch (OS.dwMinorVersion)
			{
			case  0:
				strcpy_s(theos, MAX_PATH,  (sz__Win10));
				break;
			}
			break;
		}
		break;
	}
	int x =strlen(theos);
	if (x <=0)
	{
		strcpy_s(theos, MAX_PATH,  (sz__Unknown_OS));
	}
	if (IsWow64())
	{
		strcat_s(theos, MAX_PATH,  (sz____64bit));
	}
	else
	{
		strcat_s(theos, MAX_PATH,  (sz____32bit));
	}
}
char* GetIPHost()
{
	return "";
	////VMProtectBegin("DLL_VM__GetIPHost");
	DWORD hModule	= (DWORD)MyGetModuleHandle((sz__League_of_Legends_exe));
	DWORD nTemp_ECXSENDCHAT = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule;
	DWORD nIPHost = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule + 0x5C;

	DWORD dw 		= *(DWORD*)&nIPHost;
	char* szIPHost = (char*)dw;
	////VMProtectEnd();
	//__oMsg("ECX_SEND_CHAT = %x, [%x]ip host;dw=%x;sziphost=%x;str=%s",nTemp_ECXSENDCHAT, nIPHost, dw, &szIPHost, szIPHost);
	if (szIPHost)
		return szIPHost;
	return "";
}
//=====================================================
//======== Encrypt - Decrypt using Wincrypt.h =========
//=====================================================
CCrypt::CCrypt(void)
{
	m_hProv= m_hHash= m_hKey= 0; 
	m_pszDefaultKeyRaw=  (sz__fdC_Y_yum3ww09);
}

//==========================================================================================================
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

//==========================================================================================================
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

//==========================================================================================================
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

//==========================================================================================================
CString CCrypt::DecryptStrFromHex( LPCSTR szHex, LPCSTR pszKey/*=0*/, LPCSTR pszSalt/*= 0*/ )
{
	m_fOK= TRUE;
	CString sRet= L"";
	DWORD nDataLen= strlen( szHex );
	//__oMsg("[READ-FILE-6]: DecryptStrFromHex 1: %d", GetLastError());
	if ( pszSalt || pszKey || (0 == m_hKey) ) {
		m_fOK= SetKey( (LPCSTR)pszKey, pszSalt );		
		//__oMsg("[READ-FILE-6]: DecryptStrFromHex 2: %d", GetLastError());
	}
	if ( m_fOK ) {
		//__oMsg("[READ-FILE-6]: DecryptStrFromHex 3: %d", GetLastError());
		DWORD nDecryptLen= nDataLen/2;
		char* pTmp= new char[ nDecryptLen+1 ];
		DecodeFromHex( szHex, (BYTE*)pTmp, nDecryptLen );
		m_fOK= CryptDecrypt( m_hKey, 0, TRUE, 0, (BYTE*)pTmp, &nDecryptLen );
		if ( m_fOK ) {
			sRet= pTmp;
		}
		delete pTmp;
	}
	//__oMsg("[READ-FILE-6]: DecryptStrFromHex 4: %d", GetLastError());
	return( sRet );
}

//--------------------------------------------------------
// inefficient but requires no explanation :-)
CString CCrypt::EncodeToHex( BYTE* p, int nLen )
{
	CString sRet, sTmp;
	for( int j=0; j< nLen; j++ ) {
		sTmp.Format(  (sz___02x), p[j] );
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

//==========================================================================================================
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
				//__oMsg("GetUserLogin(): xxxxx");
				m_ListUser[index].Decrypt();
			}
			return m_ListUser[index];
		}
		++index;
	}
	return EmptyUser;
}

//==========================================================================================================
extern HINSTANCE			hDll;
static TCHAR g_strPath2DLL_Game[MAX_PATH];

void Crypt(TCHAR *inp, DWORD inplen, TCHAR* key, DWORD keylen)
{
	//VMProtectBegin("DLL_VM__Crypt");
	//we will consider size of sbox 256 bytes
	//(extra byte are only to prevent any mishep just in case)
	TCHAR Sbox[257], Sbox2[257];
	unsigned long i, j, t, x;

	TCHAR temp, k;
	i = j = t = x = 0;
	temp = 0;
	k    = 0;
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
		//__oMsg("S: %d = %d [k=%d]",x, inp[x], k);
	}
	//VMProtectEnd();
}

//==========================================================================================================
void Crypt_2(char *inp, DWORD inplen, char* key, DWORD keylen)
{
	//VMProtectBegin("DLL_VM__Crypt_2");
	//we will consider size of sbox 256 bytes
	//(extra byte are only to prevent any mishep just in case)
	char Sbox[257], Sbox2[257];
	unsigned long i, j, t, x;

	char temp, k;
	i = j = t = x = 0;
	temp = 0;
	k    = 0;
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
	//VMProtectEnd();
}

//==========================================================================================================
void get_path(char* path_out) 
{
//VMProtectBegin("DLL_VM__get_path");
	DWORD dwRetVal = 0;

	TCHAR lpTempPathBuffer[MAX_PATH];
	TCHAR szTempFileName[MAX_PATH] = "";

	HANDLE hTempFile = INVALID_HANDLE_VALUE;

	//char buf[1];
	DWORD dwBytesRead = 0;

	dwRetVal = GetTempPath(MAX_PATH,          // length of the buffer
		lpTempPathBuffer); // buffer for path 

						   //__oMsg("lpTempPathBuffer: %s",lpTempPathBuffer);

	strcat_s(szTempFileName, lpTempPathBuffer);
	strcat_s(szTempFileName, TEMP_FILE_NAME);
	//__oMsg("[-get_path()-0]szTempFileName: %s %d",szTempFileName, GetLastError());

	hTempFile = CreateFile((LPTSTR)szTempFileName, // file name 
		GENERIC_READ,        // open for write 
		FILE_SHARE_READ,                    // do not share 
		NULL,                 // default security 
		OPEN_EXISTING,        // overwrite existing
		FILE_ATTRIBUTE_NORMAL,// normal file 
		NULL);                // no template
	//__oMsg("[-get_path()- 0.1]hTempFile: %x, GetLastError(%d)", hTempFile, GetLastError());

	DWORD size = GetFileSize(hTempFile, 0);
	DWORD read;
	char* pszText = (char*)GlobalAlloc(GPTR, size + 1);
	//__oMsg("[-get_path()-0.2]pszText: %s, GetLastError(%d)", pszText, GetLastError());
	if (size != 0xFFFFFFFF)
	{
		//__oMsg("[-get_path()-0.3]");
		ReadFile(hTempFile, pszText, size, &read, 0);
		//__oMsg("[-get_path()-0.4]pszText: %s, GetLastError(%d) -size:%d", pszText, GetLastError(), size);
	}
	//__oMsg("[-get_path()-1]pszText: %s, GetLastError(%d)", pszText, GetLastError());

	char sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };

	TCHAR* Data = (char*)pszText;
	TCHAR* Key = sz__fdC_Y_yum3ww09;
	//__oMsg("[-get_path()-11]pszText: %s, GetLastError(%d)", pszText, GetLastError());
	Crypt(Data, _tcslen(Data), Key, _tcslen(Key));
	//__oMsg("[-get_path()-0]pszText: %s - %s, GetLastError(%d)", path_out, Data,GetLastError());

	strcpy_s(path_out, MAX_PATH, Data);//chet o day
	if(_tcslen(Data) > 0)
	{
		memset(Data, 0, _tcslen(Data));
		//__oMsg("[Crypt-4xxx]: [%x - %x] %s [%d ]", &Data[0], Data, Data, _tcslen(Data));
	}
	//__oMsg("[-get_path()-1]pszText: %s, GetLastError(%d)", path_out, GetLastError());

	CloseHandle(hTempFile);
	//return Data;
	//return pszText;
//VMProtectEnd();
}

//==========================================================================================================
void CFileUserInfoMgr::SaveInfo2File(char* filename)
{
//VMProtectBegin("DLL_VM__SaveInfo2File");
	//__oMsg("[SAVE-FILE-0]:  g_strPath2DLL_Game(%s)", g_strPath2DLL_Game);
	if (strlen(g_strPath2DLL_Game) > 0) {
		string strPath(g_strPath2DLL_Game);
		strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
		strPath = strPath.append(filename);
		//__oMsg("[SAVE-FILE-1]: path dll ghi file: %s; data file: %s", g_strPath2DLL_Game, strPath.c_str());
		ofstream userInfoFile(strPath.c_str(), ios::binary);
		if (userInfoFile.is_open())
		{
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
	}		
	else {
		//__oMsg("[SAVE-FILE-3..0]");
		char path_out[MAX_PATH]  = "";
		get_path(path_out);
		string strPath(path_out);
		if (strlen(path_out) > 0) 
		{
			memset(path_out, 0, strlen(path_out));
		}
		strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
		strPath = strPath.append(filename);
		//__oMsg("[SAVE-FILE-3]: path dll ghi file: %s; data file: %s", g_strPath2DLL_Game, strPath.c_str());
		ofstream userInfoFile(strPath.c_str(), ios::binary);
		if (userInfoFile.is_open())
		{
			/*int index = 0;
			while (strcmp(m_ListUser[index].GetUser(), "") != 0)
			{
				//__oMsg("[SAVE-FILE-4]: ghi file dll: %s, %s, %s", m_ListUser[index].GetUser(), m_ListUser[index].GetPass(), m_ListUser[index].GetSessionID());
				//m_ListUser[index].Encrypt();
				
				char str_write[MAX_PATH] = "";
				strcat(str_write, m_ListUser[index].GetUser());
				strcat(str_write, "|");
				strcat(str_write, m_ListUser[index].GetPass());
				strcat(str_write, "|");
				strcat(str_write, m_ListUser[index].GetSessionID());
				
				char sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };

				TCHAR* Data = str_write;
				TCHAR* Key = sz__fdC_Y_yum3ww09;

				//__oMsg("SAVE-FILE Data %s", Data);

				Crypt(Data, _tcslen(Data), Key, _tcslen(Key));

				strcat(str_write, "%%%");
								
				//__oMsg("SAVE-FILE str_write %s", str_write);

				userInfoFile.write(str_write, strlen(str_write));
				
				++index;
			}
			userInfoFile.close();
			*/

			int index = 0;
			while (strcmp(m_ListUser[index].GetUser(), "") != 0)
			{
				//__oMsg("[SAVE-FILE-4]: ghi file dll: %s, %s, %s", m_ListUser[index].GetUser(), m_ListUser[index].GetPass(), m_ListUser[index].GetSessionID());
				m_ListUser[index].Encrypt();
				userInfoFile.write((char*)&m_ListUser[index], sizeof(CUserInfo));
				++index;
			}
			userInfoFile.close();
		}
	}
	//else __oMsg("Unable to open file:%s", strPath.c_str());
//VMProtectEnd();
}

//==========================================================================================================

int DecodeFromHex(LPCSTR pSrc, BYTE* pDest, int nBufLen)
{
	int nRet = 0;
	int nLen = strlen(pSrc);
	*pDest = 0;
	BYTE cIn1, cIn2, nFinal;
	for (int j = 0; j< nLen; j += 2) {
		cIn1 = (BYTE)toupper(*pSrc++);  cIn1 -= '0'; if (cIn1>9) cIn1 -= 7;
		cIn2 = (BYTE)toupper(*pSrc++);  cIn2 -= '0'; if (cIn2>9) cIn2 -= 7;
		nFinal = (BYTE)((cIn1 << 4) | cIn2);
		if (nFinal>255) nFinal = 0; // in case trying to decode non-hex data
		*pDest++ = nFinal;
		*pDest = 0;
		if (nRet >= nBufLen) {
			break;
		}
		nRet++;
	}
	return(nRet);
}

void CFileUserInfoMgr::ReadInfoFromFile(char* filename)
{
//VMProtectBegin("DLL_VM__ReadInfoFromFile");
	//__oMsg("[READ-FILE-0]:  g_strPath2DLL_Game(%s)", g_strPath2DLL_Game);
	if (strlen(g_strPath2DLL_Game) > 0) {
		string strPath(g_strPath2DLL_Game);
		//__oMsg("[READ-FILE-1]: strPath : %s", strPath);
		strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
		strPath = strPath.append(filename);
		//__oMsg("[READ-FILE-2]: path dll doc file: %s; data file: %s", g_strPath2DLL_Game, strPath.c_str());
		int nIndex = 0;
		ifstream userInfoFile(strPath.c_str(), ios::binary);
		if (userInfoFile.is_open())
		{
			while (userInfoFile.read((char*)&m_ListUser[nIndex], sizeof(CUserInfo)))
			{
				m_ListUser[nIndex].Decrypt();
				//__oMsg("[READ-FILE-3]: doc file dll: %s, %s, %s", m_ListUser[nIndex].GetUser(), m_ListUser[nIndex].GetPass(), m_ListUser[nIndex].GetSessionID());
				++nIndex;
			}
			userInfoFile.close();
		}
		else
		{
			//__oMsg("Unable to open file:%s", strPath.c_str());
			SaveInfo2File(filename);
		}
	}		
	else {
		//__oMsg("[READ-FILE-4..0]");
		char path_out[MAX_PATH]  = "";
		get_path(path_out);
		string strPath(path_out);
		if (strlen(path_out) > 0) 
		{
			memset(path_out, 0, strlen(path_out));
		}
		//__oMsg("[READ-FILE-4]: strPath : %s", strPath.c_str());
		strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
		strPath = strPath.append(filename);
		//__oMsg("[READ-FILE-5]: path dll doc file: %s; data file: %s", g_strPath2DLL_Game, strPath.c_str());
		int nIndex = 0;
		ifstream userInfoFile(strPath.c_str(), ios::binary);
		if (userInfoFile.is_open())
		{
			/*userInfoFile.seekg(0, userInfoFile.end);
			int length = userInfoFile.tellg();
			userInfoFile.seekg(0, userInfoFile.beg);

			char * buffer = new char[length];

			userInfoFile.read(buffer, length);

			userInfoFile.close();

			char *next_token = NULL;
			char * _pch;
			_pch = strtok_s(buffer, "%%%", &next_token);
			int j = 1;
			while (_pch != NULL)
			{
				if (j == 1) {
					break;
				}
			}
			//__oMsg("_pch %s", _pch);
			char sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };

			TCHAR* Data = _pch;
			TCHAR* Key = sz__fdC_Y_yum3ww09;
			Crypt(Data, _tcslen(Data), Key, _tcslen(Key));
			//__oMsg("Data %s", Data);

			char * pch;			
			pch = strtok(Data, "|");

			char m_szUser[64];
			char m_szPass[64];
			char m_szSessionID[125];

			int i = 1;
			while (pch != NULL)
			{
				if (i == 1) {					
					strcpy(m_szUser, pch);
				}
				if (i == 2) {					
					strcpy(m_szPass, pch);
				}
				if (i == 3) {					
					strcpy(m_szSessionID, pch);
				}
				if (i == 3) {
					break;
				}
				pch = strtok(NULL, "|");
				i++;
			}
	
			//__oMsg("[READ-FILE-6]: doc file dll: %s, %s, %s %d", m_szUser, m_szPass, m_szSessionID, GetLastError());

			m_ListUser[nIndex].SetUser(m_szUser);
			m_ListUser[nIndex].SetPass(m_szPass);
			m_ListUser[nIndex].SetSessionID(m_szSessionID);
			m_ListUser[nIndex].SetLogin(true);
			m_ListUser[nIndex].SetEncrypt(false);

			++nIndex;*/

			while (userInfoFile.read((char*)&m_ListUser[nIndex], sizeof(CUserInfo)))
			{
				//__oMsg("Decrypt--1");
				m_ListUser[nIndex].Decrypt();
				//__oMsg("[READ-FILE-7]: doc file dll: %s, %s, %s", m_ListUser[nIndex].GetUser(), m_ListUser[nIndex].GetPass(), m_ListUser[nIndex].GetSessionID());
				++nIndex;
			}
			userInfoFile.close();
		}
		else
		{
			//__oMsg("Unable to open file:%s", strPath.c_str());
			SaveInfo2File(filename);
		}
	}
//VMProtectEnd();
}


//==========================================================================================================
extern bool g_isDrawing;
extern int nComboHotKey;
extern int nLaneClearHotKey;
extern int nHarassHotKey;
extern int nLastHitHotKey;
DWORD WINAPI ReadConfig(void *)
{
	char path_out[MAX_PATH]  = "";
	get_path(path_out);
	//__oMsg("path_out1: %s ", path_out);
	CIniManager::GetInstance()->ReadIniFile2(path_out);

	SLMHTClientData::GetInstance()->SetCBAtkCurrentSelected(CIniManager::GetInstance()->GetAtkCurrentSelected());
	SLMHTClientData::GetInstance()->SetCBCombo(CIniManager::GetInstance()->GetCombo());
	SLMHTClientData::GetInstance()->SetCBComboUseQ(CIniManager::GetInstance()->GetComboUseQ());
	SLMHTClientData::GetInstance()->SetCBComboUseW(CIniManager::GetInstance()->GetComboUseW());
	SLMHTClientData::GetInstance()->SetCBComboUseE(CIniManager::GetInstance()->GetComboUseE());
	SLMHTClientData::GetInstance()->SetCBComboUseR(CIniManager::GetInstance()->GetComboUseR());
	SLMHTClientData::GetInstance()->SetCBClearLane(CIniManager::GetInstance()->GetClearLane());
	SLMHTClientData::GetInstance()->SetCBClearLaneUseQ(CIniManager::GetInstance()->GetClearLaneUseQ());
	SLMHTClientData::GetInstance()->SetCBClearLaneUseW(CIniManager::GetInstance()->GetClearLaneUseW());
	SLMHTClientData::GetInstance()->SetCBClearLaneUseE(CIniManager::GetInstance()->GetClearLaneUseE());
	SLMHTClientData::GetInstance()->SetCBClearLaneUseR(CIniManager::GetInstance()->GetClearLaneUseR());
	SLMHTClientData::GetInstance()->SetCBHarass(CIniManager::GetInstance()->GetHarass());
	SLMHTClientData::GetInstance()->SetCBHarassUseQ(CIniManager::GetInstance()->GetHarassUseQ());
	SLMHTClientData::GetInstance()->SetCBHarassUseW(CIniManager::GetInstance()->GetHarassUseW());
	SLMHTClientData::GetInstance()->SetCBHarassUseE(CIniManager::GetInstance()->GetHarassUseE());
	SLMHTClientData::GetInstance()->SetCBHarassUseR(CIniManager::GetInstance()->GetHarassUseR());
	SLMHTClientData::GetInstance()->SetCBLastHit(CIniManager::GetInstance()->GetLastHit());
	SLMHTClientData::GetInstance()->SetCBMove2Mouse(CIniManager::GetInstance()->GetMove2Mouse());
	SLMHTClientData::GetInstance()->SetCBEvadeLine(CIniManager::GetInstance()->GetEvadeLine());
	SLMHTClientData::GetInstance()->SetCBEvadeCircle(CIniManager::GetInstance()->GetEvadeCircle());
	SLMHTClientData::GetInstance()->SetCBEvadeDangerous(CIniManager::GetInstance()->GetEvadeDangerous());
	SLMHTClientData::GetInstance()->SetCBHackZoom(CIniManager::GetInstance()->GetHackZoom());
	SLMHTClientData::GetInstance()->SetCBModSkin(CIniManager::GetInstance()->GetModSkin());
	SLMHTClientData::GetInstance()->SetCBDanhVoiMay(CIniManager::GetInstance()->GetPlayWithBot());

	SLMHTClientData::GetInstance()->SetCBPercentManaHarass(CIniManager::GetInstance()->GetPercentManaHarass());
	SLMHTClientData::GetInstance()->SetCBPercentManaClearLane(CIniManager::GetInstance()->GetPercentManaClearLane());
	SLMHTClientData::GetInstance()->SetCBDelaySkillAfter(CIniManager::GetInstance()->GetDelaySkillAfter());

	//__oMsg("UpdateConfig: %d", CIniManager::GetInstance()->GetBatTatVeHinh());
	SLMHTClientData::GetInstance()->SetCBBatTatVe(CIniManager::GetInstance()->GetBatTatVeHinh());
	g_isDrawing = SLMHTClientData::GetInstance()->GetCBBatTatVe();
	//g_isDrawing ? Detour_EndScene() : Retour_EndScene();

	SLMHTClientData::GetInstance()->SetCBVeMatThuong(CIniManager::GetInstance()->GetVeMatThuong());
	SLMHTClientData::GetInstance()->SetCBVeMatKiemSoat(CIniManager::GetInstance()->GetVeMatKiemSoat());
	SLMHTClientData::GetInstance()->SetCBVeCanhBaoGank(CIniManager::GetInstance()->GetVeCanhBaoGank());
	SLMHTClientData::GetInstance()->SetCBVeDoanHuong(CIniManager::GetInstance()->GetVeDoanHuong());
	SLMHTClientData::GetInstance()->SetCBVeTamTruDich(CIniManager::GetInstance()->GetVeTamTruDich());
	SLMHTClientData::GetInstance()->SetCBVeTamTruDongMinh(CIniManager::GetInstance()->GetVeTamTruDongMinh());
	SLMHTClientData::GetInstance()->SetCBVeTimeEnemyRecall(CIniManager::GetInstance()->GetVeTimeEnemyRecall());
	SLMHTClientData::GetInstance()->SetCBVeTimeEnemyHoiSkill(CIniManager::GetInstance()->GetVeTimeEnemyHoiSkill());
	SLMHTClientData::GetInstance()->SetCBVeTimeEnemyHoiSpell(CIniManager::GetInstance()->GetVeTimeEnemyHoiSpell());
	SLMHTClientData::GetInstance()->SetCBVeTimeXuatHienQuaiRung(CIniManager::GetInstance()->GetVeTimeXuatHienQuaiRung());
	SLMHTClientData::GetInstance()->SetCBVePlayerDanhThuong(CIniManager::GetInstance()->GetVePlayerDanhThuong());
	SLMHTClientData::GetInstance()->SetCBVePlayerSkillQ(CIniManager::GetInstance()->GetVePlayerSkillQ());
	SLMHTClientData::GetInstance()->SetCBVePlayerSkillW(CIniManager::GetInstance()->GetVePlayerSkillW());
	SLMHTClientData::GetInstance()->SetCBVePlayerSkillE(CIniManager::GetInstance()->GetVePlayerSkillE());
	SLMHTClientData::GetInstance()->SetCBVePlayerSkillR(CIniManager::GetInstance()->GetVePlayerSkillR());
	SLMHTClientData::GetInstance()->SetCBVeEnemyDanhThuong(CIniManager::GetInstance()->GetVeEnemyDanhThuong());
	SLMHTClientData::GetInstance()->SetCBVeEnemySkillQ(CIniManager::GetInstance()->GetVeEnemySkillQ());
	SLMHTClientData::GetInstance()->SetCBVeEnemySkillW(CIniManager::GetInstance()->GetVeEnemySkillW());
	SLMHTClientData::GetInstance()->SetCBVeEnemySkillE(CIniManager::GetInstance()->GetVeEnemySkillE());
	SLMHTClientData::GetInstance()->SetCBVeEnemySkillR(CIniManager::GetInstance()->GetVeEnemySkillR());

	SLMHTClientData::GetInstance()->SetCBHoiMau_Skill(CIniManager::GetInstance()->GetHoiMau_Skill());
	SLMHTClientData::GetInstance()->SetCBHoiMau_Item(CIniManager::GetInstance()->GetHoiMau_Item());
	SLMHTClientData::GetInstance()->SetCBThieuDot(CIniManager::GetInstance()->GetThieuDot());
	SLMHTClientData::GetInstance()->SetCBThanhTay(CIniManager::GetInstance()->GetThanhTay());
	SLMHTClientData::GetInstance()->SetCBLaChan(CIniManager::GetInstance()->GetLaChan());
	SLMHTClientData::GetInstance()->SetCBTrungPhat(CIniManager::GetInstance()->GetTrungPhat());
	SLMHTClientData::GetInstance()->SetCBVoDanh(CIniManager::GetInstance()->GetVoDanh());
	SLMHTClientData::GetInstance()->SetCBHextech(CIniManager::GetInstance()->GetHextech());
	SLMHTClientData::GetInstance()->SetCBTiamat(CIniManager::GetInstance()->GetTiamat());
	SLMHTClientData::GetInstance()->SetCBIronSolari(CIniManager::GetInstance()->GetIronSolari());
	SLMHTClientData::GetInstance()->SetCBSonThach(CIniManager::GetInstance()->GetSonThach());
	SLMHTClientData::GetInstance()->SetCBDongHoCat(CIniManager::GetInstance()->GetDongHoCat());
	SLMHTClientData::GetInstance()->SetCBQuyenTruongDTS(CIniManager::GetInstance()->GetQuyenTruongDTS());
	SLMHTClientData::GetInstance()->SetCBKhanGiaiThuat(CIniManager::GetInstance()->GetKhanGiaiThuat());
	SLMHTClientData::GetInstance()->SetCBHomMikael(CIniManager::GetInstance()->GetHomMikael());
	SLMHTClientData::GetInstance()->SetCBChuocToi(CIniManager::GetInstance()->GetChuocToi());
	SLMHTClientData::GetInstance()->SetCBKhienBang(CIniManager::GetInstance()->GetKhienBang());
	SLMHTClientData::GetInstance()->SetCBPercentHP4Skill(CIniManager::GetInstance()->GetPercentHP4Skill());
	SLMHTClientData::GetInstance()->SetCBPercentHP4Item(CIniManager::GetInstance()->GetPercentHP4Item());
	SLMHTClientData::GetInstance()->SetCBPercentHP4LaChan(CIniManager::GetInstance()->GetPercentHP4LaChan());
	SLMHTClientData::GetInstance()->SetCBPercentHP4IronSolari(CIniManager::GetInstance()->GetPercentHP4IronSolari());
	SLMHTClientData::GetInstance()->SetCBPercentHP4SonThach(CIniManager::GetInstance()->GetPercentHP4SonThach());
	SLMHTClientData::GetInstance()->SetCBPercentHP4DongHoCat(CIniManager::GetInstance()->GetPercentHP4DongHoCat());
	SLMHTClientData::GetInstance()->SetCBPercentHP4QT_DTS(CIniManager::GetInstance()->GetPercentHP4QT_DTS());
	SLMHTClientData::GetInstance()->SetCBPercentHP4ChuocToi(CIniManager::GetInstance()->GetPercentHP4ChuocToi());


	//nComboHotKey	   = GetHotKey_Combo();
	//nLaneClearHotKey = GetHotKey_LaneClear();
	//nHarassHotKey	   = GetHotKey_Harass();
	//nLastHitHotKey   = GetHotKey_LastHit();

	return 0;
}

//==========================================================================================================
DWORD WINAPI WriteConfig(void *)
{
	char path_out[MAX_PATH]  = "";
	
	get_path(path_out);
	//CIniManager::GetInstance()->SetUsername(m_szUsername);
	CIniManager::GetInstance()->WriteIniFile2(path_out);
	return 0;
}

//==========================================================================================================
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
//==========================================================================================================
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
