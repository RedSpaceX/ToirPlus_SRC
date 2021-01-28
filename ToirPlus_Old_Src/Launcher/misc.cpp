#include "stdafx.h"
///////////////////////////////////////////////////////////////////////////////////////////
// loader: command-line interface dll injector
// Copyright (C) 2009-2011 Wadim E. <wdmegrv@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////////////////
#include "misc.h"

//-------------------------------------------------------------------------------------------------------------------
bool __oMsg_22(const char * format, ...)
{
	char buffer[1000];

	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);

	strcat_s(buffer, "\n");
	const wchar_t *wbuff = C2W(buffer); 
	OutputDebugStringW(wbuff);
	delete []wbuff;
	return true;
}

//==================================================================================//
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
using namespace std;

enum TypeLog
{
	NO_LOGG__    = 0,
	DEBUG_VIEW__ = 1,
	CONSOLE__    = 2,
	PRINT_FILE__ = 3,
};

HANDLE vai_logFile = 0;	
bool   chi1lan = true;
bool __oMsg(const char * format, ...)
{
	//int LOG_TYPE = NO_LOGG__;			//<============ ************* QUAN TRONG ******************

	//int LOG_TYPE = DEBUG_VIEW__;		//<============ ************* QUAN TRONG ******************

	//int LOG_TYPE = CONSOLE__;			//<============ ************* QUAN TRONG ******************

	int LOG_TYPE = PRINT_FILE__;		//<============ ************* QUAN TRONG ******************

	//-------------------------------------------------:
	if (LOG_TYPE == NO_LOGG__) return true;

	else if (LOG_TYPE == DEBUG_VIEW__)
	{
		char buffer[1000];

		va_list argptr;
		va_start(argptr, format);
		vsprintf_s(buffer, format, argptr);
		va_end(argptr);

		strcat_s(buffer, "\n");
		const wchar_t *wbuff = C2W(buffer); 
		OutputDebugStringW(wbuff);
		//delete []wbuff;
	}
	else if (LOG_TYPE == CONSOLE__)		
	{
		AllocConsole();
		char buffer[1000];

		va_list argptr;
		va_start(argptr, format);
		vsprintf_s(buffer, format, argptr);
		va_end(argptr);
		//strcat_s(buffer, "\n");

		freopen("CONOUT$", "w", stdout);
		std::cout << buffer ;
	}
	else if (LOG_TYPE == PRINT_FILE__)
	{
		if (chi1lan == true)
		{
			if (!vai_logFile) 
			{
				wstring filepathBase = L"GenAccount.txt";	//D:\\___WORKING\\Temp\\FOR_ADDRESS\\Release\\riot.dll
				vai_logFile = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	
			}
			chi1lan = false;
		}

		//-----------------------------:
		char buffer[1000] = {0};
		va_list argptr;
		va_start(argptr, format);
		vsprintf_s(buffer, format, argptr);
		va_end(argptr);
		strcat_s(buffer, "\n");

		if (vai_logFile)
		{
			DWORD dwBytesWritten = 0;
			string logme = buffer;
			WriteFile(vai_logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
		}

		//freopen("CONOUT$", "w", stdout);
		//std::cout << buffer ;
	}

	return true;
}
//---------------------------------------------------------------------------------
wchar_t* C2W(CONST char *strInput)
{
	int leng = strlen(strInput);
	wchar_t* ketqua = new wchar_t[leng + 1];
	for (int i = 0; i < leng; ++i)
		ketqua[i] = strInput[i];
	ketqua[leng] = '\0';
	return ketqua;
}

//---------------------------------------------------------------------------------
char* W2C(const wchar_t *strInput)
{
	int leng = wcslen(strInput);
	char* ketqua = new char[leng + 1];
	for (int i = 0; i < leng; ++i)
		ketqua[i] = strInput[i];
	ketqua[leng] = '\0';
	return ketqua;
}

//---------------------------------------------------------------------------------
using namespace std;
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

//-------------------------------------------------------------------------------------------------------------------
TCHAR* Lpcwstr_2_Tchar(LPCWSTR lpStr)
{
	/*USES_CONVERSION;
	LPCWSTR lpcwstr_Path2DLL;
	TCHAR g_strPath2DLL_Game[MAX_PATH] = "aaaa1234";
	lpcwstr_Path2DLL = T2W(g_strPath2DLL_Game);*/
}

//-------------------------------------------------------------------------------------------------------------------
void PrintErrorMsgA(char *format, ...)
{
	//va_list ap;
	//DWORD dwLastError = 0;
	//va_start(ap, format);
	//
	////printf("Error: ");
	//vprintf(format, ap);
	//va_end(ap);

	//dwLastError = GetLastError();
	//if(dwLastError)
	//{
	//	//printf(" [LastError: %d]", GetLastError());
	//}
	//SetLastError(0);
	//printf("\n");
}

//-------------------------------------------------------------------------------------------------------------------
void PrintErrorMsgW(wchar_t *format, ...)
{
	//va_list ap;
	//DWORD dwLastError = 0;
	//va_start(ap, format);
	//
	////printf("Error: ");
	//vwprintf(format, ap);
	//va_end(ap);

	//dwLastError = GetLastError();
	//if(dwLastError)
	//{
	//	//printf(" [LastError: %d]", GetLastError());
	//}
	//SetLastError(0);
	//printf("\n");
}

//-------------------------------------------------------------------------------------------------------------------
// This function will convert a char string to a wchar_t string.
wchar_t *__stdcall char_to_wchar_t(const char *src)
{
	wchar_t *out_str = 0;
	size_t len = 0;
	int i = 0;

	if(src == 0)
	{
		return 0;
	}

	len = (strlen(src) + 1) * sizeof(wchar_t);
	out_str = (wchar_t*)malloc(len);

	// memory allocation failed
	if(!out_str)
	{
		//printf("Error: Memory allocation failed.\n");
		return 0;
	}

	memset(out_str, 0, len);
	
	while(src[i] != '\0')
	{
		out_str[i] = (wchar_t)src[i];
		++i;
	}

	return out_str;
}

//-------------------------------------------------------------------------------------------------------------------
int parse_int(const char *str)
{
	int int_ret = 0;
	if(str == 0)
	{
		return 0;
	}

	// try to get dec format
	sscanf_s(str, "%d", &int_ret);

	// try to get hex format
	if(int_ret == 0 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		sscanf_s(str, "%x", &int_ret);
	}

	return int_ret;
}

//-------------------------------------------------------------------------------------------------------------------
char *alloc_stra(char *in_str)
{
	size_t len = 0;
	char *out_str = 0;

	if(in_str == 0)
	{
		return 0;
	}
	
	len = strlen(in_str) + 1;
	out_str = (char*)malloc(len);

	// memory allocation failed
	if(!out_str)
	{
		//printf("Error: Memory allocation failed.\n");
		return 0;
	}
	
	// strcpy_s failed
	if(strcpy_s(out_str, len, in_str) != 0)
	{
		free(out_str);
		return 0;
	}

	return out_str;
}