#include "Logger.h"



Logger::Logger(wstring filename)
	:logText(NULL), DoLog(false), filename(filename)
{
}


Logger::~Logger()
{
	if (logText)
		CloseHandle(logText);
}

void Logger::startLog()
{
	if (!logText) {
		//wstring filepathBase = L"C:\\Users\\Hunter\\Desktop\\Logfiles\\" + filename + L".txt";
		wstring filepathBase = L"E:\\Temp\\FOR_ADDR8.19 - Copy\\Release\\" + filename + L".txt";
		logText = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	}

	DoLog = true;
}

void Logger::stopLog()
{
	DoLog = false;
}

string Logger::LogString(string explaination, const string str)
{
	if (DoLog && logText) {
		DWORD dwBytesWritten = 0;
		string logme = "Log_string : " + explaination + " ! " + str + "\r\n" ;
		WriteFile(logText, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}
	return str;
}

float Logger::LogFloat(string explaination, const float value)
{
	if (DoLog && logText) {
		DWORD dwBytesWritten = 0;
		string logme = "Log_Float : " + explaination + " ! " + tostr<float>(value) + "\r\n";
		WriteFile(logText, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}
	return value;
}

#include "Log.h"
int Logger::LogAll(const char * format, ...)
{
	__oMsg("DoLog: %d, logText: %x", DoLog, logText);

	if (DoLog && logText) {

		char buffer[1000];

		va_list argptr;
		va_start(argptr, format);
		vsprintf_s(buffer, format, argptr);
		va_end(argptr);

		strcat_s(buffer, "\n");

		DWORD dwBytesWritten = 0;
		//string logme = "Log_Int : " + explaination + " ! " + tostr<int>(value) + "\r\n" ;
		WriteFile(logText, buffer, strlen(buffer), &dwBytesWritten, NULL);
	}
	return 1;
}



int Logger::LogInt(string explaination, const int value)
{
	if (DoLog && logText) {
		DWORD dwBytesWritten = 0;
		string logme = "Log_Int : " + explaination + " ! " + tostr<int>(value) + "\r\n" ;
		WriteFile(logText, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}
	return value;
}
BYTE Logger::LogBYTE(string explaination, const BYTE value)
{
	if (DoLog && logText) {
		DWORD dwBytesWritten = 0;
		string logme = "Log_BYTE : " + explaination + " ! " + tostr<BYTE>(value) + "\r\n";
		WriteFile(logText, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}
	return value;
}

DWORD64 Logger::LogAddress(string explaination, const DWORD64 value)
{
	if (DoLog && logText) {
		DWORD dwBytesWritten = 0;
		ostringstream os;
		os << hex << value;
		string logme = "Log_Address : " + explaination + " ! "  + "0x" + os.str() + "\r\n";
		WriteFile(logText, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}
	return value;
}
