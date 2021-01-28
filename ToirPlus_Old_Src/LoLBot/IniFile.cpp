// IniFile.cpp : implementation file

#include "stdafx.h"

#include "IniFile.h"
#include "Utils.h"
#include "DataText.h"
#include <iostream>
#include <Windows.h>

CIniFile::CIniFile(const char* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}

//====================== READ ==========================
int CIniFile::ReadInteger(char* szSection, char* szKey, int iDefaultValue)
{
	int iResult = GetPrivateProfileIntA(szSection,  szKey, iDefaultValue, m_szFileName); 
	return iResult;
}
float CIniFile::ReadFloat(char* szSection, char* szKey, float fltDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	float fltResult;
	sprintf_s(szDefault, "%f",fltDefaultValue);
	GetPrivateProfileStringA(szSection,  szKey, szDefault, szResult, 255, m_szFileName); 
	fltResult =  (float)atof(szResult);
	return fltResult;
}
bool CIniFile::ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	bool bolResult;
	sprintf_s(szDefault, "%s", bolDefaultValue?  (sz__True) :  (sz__False));
	GetPrivateProfileStringA(szSection, szKey, szDefault, szResult, 255, m_szFileName); 
	bolResult =  (strcmp(szResult,  (sz__True)) == 0 || 
		strcmp(szResult,  (sz__true)) == 0) ? true : false;
	return bolResult;
}
char* CIniFile::ReadString(char* szSection, char* szKey, const char* szDefaultValue)
{
	char* szResult = new char[255];
	memset(szResult, 0x00, 255);
	GetPrivateProfileStringA(szSection,  szKey, 
		szDefaultValue, szResult, 255, m_szFileName); 
	return szResult;
}

//====================== WRITE ==========================
void CIniFile::WriteInteger(char* szSection, char* szKey, int iValue)
{
	char szValue[255];
	sprintf_s(szValue, "%d", iValue);
	WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName); 
}
void CIniFile::WriteFloat(char* szSection, char* szKey, float fltValue)
{
	char szValue[255];
	sprintf_s(szValue, "%f", fltValue);
	WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName); 
}
void CIniFile::WriteBoolean(char* szSection, char* szKey, bool bolValue)
{
	char szValue[255];
	sprintf_s(szValue, "%s", bolValue ?  (sz__True) :  (sz__False));
	WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName); 
}
void CIniFile::WriteString(char* szSection, char* szKey, char* szValue)
{
	WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName);
}