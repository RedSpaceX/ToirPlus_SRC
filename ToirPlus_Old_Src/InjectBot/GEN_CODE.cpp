//#include "stdafx.h"
#include "GEN_CODE.h"
#include "Indicator.h"
#include "Logger.h"
//=========================================================================================
DWORD GEN_CODE(char* nameFunc, LPCSTR Sign, LPCSTR Mask, int addSub, int processId )
{
	//HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_CREATE_THREAD|PROCESS_VM_OPERATION|
	//								PROCESS_VM_WRITE|PROCESS_VM_READ, FALSE, processId);
	//__oMsg("found-Window-ID: %d", dwProcessID);
	//SigScanner.TargetProcess = hProcess;
	
	SignatureScanner SigScanner;
	SigScanner.GetProcess("League of Legends.exe");
	SigScanner.GetModule("League of Legends.exe");
	
	DWORD addr = SigScanner.FindSignature(SigScanner.TargetModule.dwBase, SigScanner.TargetModule.dwSize, Sign, Mask);
	//DWORD addr = SigScanner.FindSignature(SigScanner.TargetModule.dwBase + 0x61E4C0, 0x300, Sign, Mask);
	//DWORD addr = SigScanner.FindSignature(SigScanner.TargetModule.dwBase + 0x61E4BE, 0x88300, Sign, Mask);
	//DWORD addr = SigScanner.FindSignature(SigScanner.TargetModule.dwBase + 0x2000, 0x62E4C0 + 0x2400, Sign, Mask);
	//DWORD addr = SigScanner.FindSignature(0x848000, 0x1d000, Sign, Mask);
	
	//DWORD value;
	//ReadProcessMemory(SigScanner.TargetProcess, (LPCVOID)(addr + addSub), &value, sizeof(value), NULL);
	__oMsg("--- %s : %x           //[%x] ", nameFunc, addr + addSub, addr);
	//__oMsg_2("--- %s : %x           //[%x] --> %x", nameFunc, addr + addSub, addr, *(DWORD*)(addr + addSub));
	return addr + addSub;
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
const BYTE HEX[0x80] = //This is the ASCII table in number value form
{   //0     1     2     3     4     5     6    7      8     9     A     B     C     D     E     F
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//0
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//1
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//2
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//3
	0x00, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//4
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//5
	0x00, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//6
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 //7
};
void StringToHex(const char* str, BYTE* hex)
{
	int len = strlen(str)/2;
	for(int i = 0; i < len; i++)
	{
		hex[i] =  (HEX[*str++] << 4);
		hex[i] += (HEX[*str++]);
	}
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
unsigned int __cdecl CUT_1(const char *a1, int a2, char *a3)
{
	unsigned int result; // eax@1
	int v4; // esi@2

	result = strlen(a1);
	//__oMsg_2("\n(ressult-TEXT: %d)", result);
	if ( (signed int)(a2 - result) > 0 )
	{
		v4 = a2 - result;
		do
		{
			result = (unsigned int)strcat(a3, " ");
			--v4;
		}
		while ( v4 );
	}
	return result;
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
unsigned int __cdecl CUT_2(int a1, int a2, char *a3)
{
	int result; // eax@1
	int v4; // edi@2
	char v5[12] = {0}; // [sp+4h] [bp-68h]@1

	sprintf_s(v5, "%x", a1);
	result = strlen(v5);
	//__oMsg_2("(ressult-so 0x1234: %d)\n", result);
	if ( (a2 - result) > 0 )
	{
		v4 = a2 - result;
		do
		{
			result = (int)strcat(a3, " ");
			--v4;
		}
		while ( v4 );
	}
	return result;
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
DWORD GEN_CODE2(BYTE*  Pattern, int p_Size)
{
	SignatureScanner SigScanner;
	SigScanner.GetProcess("League of Legends.exe");
	SigScanner.GetModule("League of Legends.exe");

	DWORD addr = SigScanner.FindSignature_memcmp(SigScanner.TargetModule.dwBase, SigScanner.TargetModule.dwSize, Pattern, p_Size);

	__oMsg("---  : %x            ", addr);

	return addr;
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
struct Indicators
{
	string	exportName;
	string	indicator;
	int		type;			//0=$D, 1=$A, 2=$B(bodyFunc), 3=$F
	int		addMore;
};

std::vector<Indicators> *List_Indicators = 0;

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
HANDLE logFile = 0;
void GENARATE()
{
	logFile = 0;
	if (!logFile) {
		wstring filepathBase = L"D:\\___WORKING\\Temp\\FOR_ADDRESS\\Release\\LogFile.h";
		logFile = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	}
	
	//-------------------------------:
	//Logger _logger(L"ADDR_GAME");
	//_logger.startLog();

	//-------------------------------:
	SignatureScanner SigScanner;
	SigScanner.GetProcess("League of Legends.exe");
	SigScanner.GetModule("League of Legends.exe");
		
	
	if (logFile)
	{
		char Buffer[512] = {0};
		sprintf_s(Buffer, "#pragma once\n\n#define TEMP_ENTRY_POINT_FAKE		0x49d2a\n#define TEMP_ENTRY_POINT\t\t\t0x%x\n//GetModule -> dwSize : \t\t0x%x\n\n\n#define OFF_ENCRYPT_1\t\t\t\t0x0000000\n#define OFF_ENCRYPT_2\t\t\t\t0x0000000\n\n\n", SigScanner.TargetModule.dwBase, SigScanner.TargetModule.dwSize);
		DWORD dwBytesWritten = 0;
		string logme = Buffer;
		WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}

	INIT_INDICATOR();
	
	int sizeIndi = (int)List_Indicators->size();
	if (sizeIndi == 0) return;
	
	int nCount = 0;
	for (int yy = 0; yy < sizeIndi; yy++)
	{
					//nCount += 1;
					//__oMsg_2("------- nCount : %d", nCount);
					////-------TEST.LOG-----------------------------
					//DWORD dwBytesWritten = 0;
					//string logme = "\n----------xxxx---1";
					//WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		if (List_Indicators->at(yy).type == 0)			//0=$D
		{
			PRINT_RESULT(0, 0, "xxx", 0/*, _logger*/);
			continue;
		}

		if (List_Indicators->at(yy).type == 3)			//3=$F
		{
			PRINT_RESULT(0, 0, (char*)List_Indicators->at(yy).exportName.c_str(), 3/*, _logger*/);
			continue;
		}

					////-------TEST.LOG-----------------------------
					//dwBytesWritten = 0;
					//string logme2 = "\n----------xxxx---2";
					//WriteFile(logFile, logme2.c_str(), logme2.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		string EXPORT_NAME = List_Indicators->at(yy).exportName;
		string INDICATOR   = List_Indicators->at(yy).indicator;
		int	   TYPE		   = List_Indicators->at(yy).type;
		int	   ADD_MORE    = List_Indicators->at(yy).addMore;

		for (int i = 0; i < (int)INDICATOR.length(); i++)
		{
			if (INDICATOR.at(i) == 32)
			{
				//__oMsg("i: %d ->%d", i, BASE.at(i));
				INDICATOR.erase (INDICATOR.begin() + i);
			}
		}

					////-------TEST.LOG-----------------------------
					//dwBytesWritten = 0;
					//string logme3 = "\n----------xxxx---3";
					//WriteFile(logFile, logme3.c_str(), logme3.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		int nLeng = strlen(INDICATOR.c_str())/2;
		//__oMsg_2("TESTs-2 :%s - %d", BASE123.c_str(), nLeng); 

		BYTE* BYTE_PATTEN = new BYTE[nLeng];
		StringToHex(INDICATOR.c_str(), BYTE_PATTEN);
					
					////-------TEST.LOG-----------------------------
					//dwBytesWritten = 0;
					//string logme4 = "\n----------xxxx---4";
					//WriteFile(logFile, logme4.c_str(), logme4.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		DWORD AddrFound = SigScanner.FindSignature_memcmp(SigScanner.TargetModule.dwBase, SigScanner.TargetModule.dwSize, BYTE_PATTEN, nLeng);
		//__oMsg_2("#define %s\t\t\t\t  : [%x] %x           *(%x) ", EXPORT_NAME.c_str(), AddrFound, AddrFound + ADD_MORE, *(DWORD*)(AddrFound + ADD_MORE));

					////-------TEST.LOG-----------------------------
					//dwBytesWritten = 0;
					//string logme5 = "\n----------xxxx---5";
					//WriteFile(logFile, logme5.c_str(), logme5.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		PRINT_RESULT(AddrFound, AddrFound + ADD_MORE, (char*)EXPORT_NAME.c_str(), TYPE/*, _logger*/);
		if (AddrFound != 0)
		{
			//__oMsg_3("    //---{AddrFound + ADD_MORE: %x ---> *[%x - %x]}\n", AddrFound + ADD_MORE, *(DWORD*)(AddrFound + ADD_MORE), *(DWORD*)(AddrFound + ADD_MORE + 4));
		}

					////-------TEST.LOG-----------------------------
					//dwBytesWritten = 0;
					//string logme6= "\n----------xxxx---6";
					//WriteFile(logFile, logme6.c_str(), logme6.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		delete[] BYTE_PATTEN;
	}


	if (logFile)
		CloseHandle(logFile);

	//_logger.stopLog();
	

	//string BASE123 = "6A 01 6A 01 8D 44 24 0C 50";
	////__oMsg("TESTs-1 :%s", BASE.c_str()); 
	//for (int i = 0; i < (int)BASE123.length(); i++)
	//{
	//	if (BASE123.at(i) == 32)
	//	{
	//		//__oMsg("i: %d ->%d", i, BASE.at(i));
	//		BASE123.erase (BASE123.begin() + i);
	//	}
	//}

	//int nLeng = strlen(BASE123.c_str())/2;
	//__oMsg_2("TESTs-2 :%s - %d", BASE123.c_str(), nLeng); 

	//BYTE* INDICATOR = new BYTE[nLeng];
	//StringToHex(BASE123.c_str(), INDICATOR);
	//GEN_CODE2(INDICATOR, nLeng);
	////LogArray("GKY", GKY, len);
	//delete[] INDICATOR;
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
bool check_Fucking(DWORD addres)
{
	__try
	{
		__oMsg("1111111111KKKKKKKKKKKKCCC--------------");
		BYTE TEST_0 = *(BYTE *)addres;
		BYTE TEST_1 = *(BYTE *)(addres +1);
		BYTE TEST_2 = *(BYTE *)(addres +2);
		BYTE TEST_3 = *(BYTE *)(addres +3);
		__oMsg("222222222222222222KKKKKKKKKKKKCCC--------------");
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		/*DWORD dwBytesWrittenxx= 0;
		string logmez3xx = "\n----------HAM_LONGGG";
		WriteFile(logFile, logmez3xx.c_str(), logmez3xx.size(), &dwBytesWrittenxx, NULL);*/

		__oMsg("FUCCCCCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKCCC--------------");
		MessageBoxA(NULL, "Injection failed !!!", "Failed", MB_OK);
		return true;
	}
	return false;
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
void PRINT_RESULT(DWORD AddrFound, DWORD AddrFinish, char* exportName, int type/*, Logger printLog*/)
{
	if (type == 0)
	{
		//__oMsg_3("\n");

		if (logFile)
		{
			DWORD dwBytesWritten = 0;
			string logme = "\n";
			WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
		}

		return;
	}

	if (type == 3)
	{
		//__oMsg_3("%s\n", exportName);

		if (logFile)
		{
			char tmp1Text[256] = {0};
			sprintf_s(tmp1Text, "%s\n",exportName);
			DWORD dwBytesWritten = 0;
			string logme = tmp1Text;
			WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
		}

		return;
	}

					////-------TEST.LOG-----------------------------
					//DWORD dwBytesWritten1= 0;
					//string logme1 = "\n----------zzzz---0";
					//WriteFile(logFile, logme1.c_str(), logme1.size(), &dwBytesWritten1, NULL);
					////-------END.TEST.LOG--------------------------

	//----------------------------------:
	char Buffer[256] = {0};
	if (AddrFound == 0)
	{
					////-------TEST.LOG-----------------------------
					//DWORD dwBytesWritten= 0;
					//string logme = "\n----------zzzz---1";
					//WriteFile(logFile, logme1.c_str(), logme.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		char v45[128] = {0};
		sprintf_s(v45, "// ===========<<NOT FOUND>>===========");
		
		//char v9[64];
		char v42[48] = {0};
		char v43[48] = {0};
		CUT_1(exportName, 28, v42);
		CUT_2(0, 10, v43);
		sprintf_s(Buffer, "#define %s%s0x%x%s%s\n", exportName, v42, 0, v43, v45);
	}
	else
	{

					////-------TEST.LOG-----------------------------
					//DWORD dwBytesWritten= 0;
					//string logme = "\n----------zzzz---2";
					//WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		//if (check_Fucking(AddrFinish)) return;

		char v28[128] = {0};	// chinh la v12 la v45
		BYTE v11_BYTE = *(BYTE *)AddrFinish;					// ========> CO THE DIE O DAY <--------
		DWORD v3  = 0;
		bool v14  = false;
		DWORD v32 = 0;
		DWORD v36 = 0;
		DWORD v37 = 0;
		//----------------------------
					
					////-------TEST.LOG-----------------------------
					//dwBytesWritten= 0;
					//string logmez3 = "\n----------zzzz---3";
					//char v28xxxx[128] = {0};
					//sprintf_s(v28xxxx, "%s : %d", logmez3.c_str(), v11_BYTE);
					//WriteFile(logFile, v28xxxx, strlen(v28xxxx), &dwBytesWritten, NULL);
					////-------END.TEST.LOG--------------------------

		//---------------BodyFunc	........
		if ( type == 2 )	
		{
			v3 = AddrFinish;
			char v45[128] = {0};
			sprintf_s(v45, "//%x\tBodyFunc\t........", AddrFinish);
			char v42[48] = {0};
			char v43[48] = {0};
			CUT_1(exportName, 28, v42);
			CUT_2(v3, 10, v43);
			sprintf_s(Buffer, "#define %s%s0x%x%s%s\n", exportName, v42, v3, v43, v45);

			goto END_FUNCTION;
		}
					
		//------------------------0x01-----------------------------:
		if ( *(BYTE *)AddrFinish == 1 )
		{
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( *(BYTE *)(AddrFinish + 1) == 0x8E )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tadd dword ptr ds:[esi + %x],ecx", v32, v37);
				goto LABEL_157;
			}
			v36 = AddrFinish;
			sprintf_s(v28, "\t\t//%x\t(01) ====<<UNKNOW COMMAND>>====", v36);
			goto LABEL_157;
		}

		//---------------0x39-----------------------------:
		if ( v11_BYTE == 0x39 )
		{
			BYTE v13 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v13 == 29 )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tcmp dword ptr ds:[%x],ebx", v32, v37);
			}
			else
			{
				if ( v13 == 45 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tcmp dword ptr ds:[%x],ebp", v32, v37);
				}
				else
				{
					if ( v13 != 61 )
					{
						v14 = v13 == 0x98;
						if ( v14 )
						{
							v37 = *(DWORD *)(AddrFinish + 2);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tcmp dword ptr ds:[eax + %x],ebx", v32, v37);
							goto LABEL_157;
						}
						v36 = AddrFinish;
						sprintf_s(v28, "\t\t//%x\t(39) ====<<UNKNOW COMMAND>>====", v36);
						goto LABEL_157;
					}
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tcmp dword ptr ds:[%x],edi", v32, v37);
				}
			}
			goto LABEL_157;
		}
		if ( v11_BYTE == 0x68 )
		{
			v3 = *(DWORD *)(AddrFinish + 1);
			v37 = *(DWORD *)(AddrFinish + 1);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tpush %x", v32, v37);
			goto LABEL_157;
		}

		//---------------0x69-----------------------------:
		if ( v11_BYTE == 0x69 )
		{
			BYTE v15 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v15 == 0xC9 )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\timul ecx,ecx,%x", v32, v37);
			}
			else
			{
				if ( v15 == 0xC0 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\timul eax,eax,%x", v32, v37);
				}
				else
				{
					if ( v15 != 0xDB )
					{
						v14 = v15 == 0xED;
						if ( v14 )
						{
							v37 = *(DWORD *)(AddrFinish + 2);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\timul ebp,ebp,%x", v32, v37);
							goto LABEL_157;
						}
						v36 = AddrFinish;
						sprintf_s(v28, "\t\t//%x\t(69) ====<<UNKNOW COMMAND>>====", v36);
						goto LABEL_157;
					}
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\timul ebx,ebx,%x", v32, v37);
				}
			}
			goto LABEL_157;
		}	

		//---------------0xE8-----------------------------:
		if ( v11_BYTE == 0xE8 )
		{
			DWORD  v16 = *(DWORD *)(AddrFinish + 1);
			v3 = v16 + AddrFinish + 5;
			v37 = v16 + AddrFinish + 5;
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tcall %x", v32, v37);
			goto LABEL_157;
		}
		if ( v11_BYTE == 233 )
		{
			DWORD  v17 = *(DWORD *)(AddrFinish + 1);
			v3 = v17 + AddrFinish + 5;
			v37 = v17 + AddrFinish + 5;
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tJMP %x", v32, v37);
			goto LABEL_157;
		}
		if ( v11_BYTE == 185 )
		{
			v3 = *(DWORD *)(AddrFinish + 1);
			v37 = *(DWORD *)(AddrFinish + 1);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov ecx, %x", v32, v37);
			goto LABEL_157;
		}
		if ( v11_BYTE == 187 )
		{
			v3 = *(DWORD *)(AddrFinish + 1);
			v37 = *(DWORD *)(AddrFinish + 1);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov ebx, %x");
			goto LABEL_157;
		}
		if ( v11_BYTE == 161 )
		{
			v3 = *(DWORD *)(AddrFinish + 1);
			v37 = *(DWORD *)(AddrFinish + 1);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov eax, dword ptr ds:[%x]", v32, v37);
			goto LABEL_157;
		}

		//---------------0x81---------------------------:
		if ( v11_BYTE == 0x81 )
		{
							////-------TEST.LOG-----------------------------
							//DWORD dwBytesWritten = 0;
							//string logme = "\n----------yyyy---1";
							//WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
							////-------END.TEST.LOG--------------------------

			BYTE v18 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v18 == 237 )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tsub ebp,%x", v32, v37);
			}
			else
			{
							////-------TEST.LOG-----------------------------
							//DWORD dwBytesWritten = 0;
							//string logme = "\n----------yyyy---2";
							//WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
							////-------END.TEST.LOG--------------------------

				if ( v18 == 198 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tadd esi,%x", v32, v37);
				}
				else
				{
							////-------TEST.LOG-----------------------------
							//DWORD dwBytesWritten = 0;
							//string logme = "\n----------yyyy---3";
							//WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
							////-------END.TEST.LOG--------------------------

					if ( v18 != 193 )
					{
						v14 = v18 == 0xC3;
						if ( v14 )
						{
										////-------TEST.LOG-----------------------------
										//DWORD dwBytesWritten = 0;
										//string logme = "\n----------yyyy---4";
										//WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
										////-------END.TEST.LOG--------------------------

							v37 = *(DWORD *)(AddrFinish + 2);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tadd ebx,%x", v32, v37);
							goto LABEL_157;
						}
						v36 = AddrFinish;
						sprintf_s(v28, "\t\t//%x\t(81) ====<<UNKNOW COMMAND>>====", v36);
						goto LABEL_157;
					}
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tadd ecx,%x", v32, v37);
				}
			}
			goto LABEL_157;
		}

		//---------------0x83---------------------------:
		if ( v11_BYTE == 0x83 )
		{
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( *(BYTE *)(AddrFinish + 1) == 61 )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tcmp dword ptr ds:[%x],0", v32, v37);
				goto LABEL_157;
			}
			v36 = AddrFinish;
			sprintf_s(v28, "\t\t//%x\t(83) ====<<UNKNOW COMMAND>>====", v36);
			goto LABEL_157;
		}
		
		//---------------0x89-------------------------------:
		if ( v11_BYTE == 0x89 )
		{
			BYTE v19 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v19 == 13 )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tmov dword ptr ds:[%x],ecx", v32, v37);
			}
			else
			{
				if ( v19 == 21 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov dword ptr ds:[%x],edx", v32, v37);
				}
				else
				{
					if ( v19 != 53 )
					{
						v14 = v19 == 0xB3;
						if ( v14 )
						{
							v37 = *(DWORD *)(AddrFinish + 2);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tmov dword ptr ds:[ebx + %x],esi", v32, v37);
							goto LABEL_157;
						}
						v36 = AddrFinish;
						sprintf_s(v28, "\t\t//%x\t(89) ====<<UNKNOW COMMAND>>====", v36);
						goto LABEL_157;
					}
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov dword ptr ds:[%x],esi", v32, v37);
				}
			}
			goto LABEL_157;
		}
		if ( v11_BYTE == 138 )
		{
			BYTE v20 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v20 != 0x85 )
			{
				v14 = v20 == 0x88;
				if ( v14 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov cl,byte ptr ds:[eax + %x]", v32, v37);
					goto LABEL_157;
				}
				v36 = AddrFinish;
				sprintf_s(v28, "\t\t//%x\t(8A) ====<<UNKNOW COMMAND>>====", v36);
				goto LABEL_157;
			}
			v37 = *(DWORD *)(AddrFinish + 2);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov al,byte ptr ss:[ebp + %x]", v32, v37);
			goto LABEL_157;
		}	

		//--------------0x8B-------------------------------:
		if (v11_BYTE == 0x8B)
		{
			BYTE v21 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v21 == 0x15 )
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tmov edx,dword ptr ds:[%x]", v32, v37);
			}
			else if ( v21 == 0x1D )	//tu them vao code cua ong phuong
			{
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tmov ebx,dword ptr ds:[%x]", v32, v37);
			}
			else
			{
				if ( v21 == 0xD )
					goto LABEL_177;
				if ( v21 == 0x35 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov esi, dword ptr ds:[%x]", v32, v37);
					goto LABEL_157;
				}
				if ( v21 == 0x3D )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28,  "//%x\tmov edi, dword ptr ds:[%x]", v32, v37);
					goto LABEL_157;
				}
				if ( v21 == 0xB3 )
				{
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov esi,dword ptr ds:[ebx + %x]", v32, v37);
					goto LABEL_157;
				}
				if ( v21 == 0xB8 )
				{
LABEL_177:
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov ecx, dword ptr ds:[%x]", v32, v37);
					goto LABEL_157;
				}
				//------------------------:
				switch ( v21 )
				{
				case 131:
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov eax, dword ptr ds:[ebp + %x]", v32, v37);
					break;
				case 133:
					v37 = *(DWORD *)(AddrFinish + 2);
					v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov eax, dword ptr ss:[ebp + %x]", v32, v37);
					break;
				case 134:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov eax, dword ptr ds:[esi + %x]", v32, v37);
					break;
				case 136:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov ecx, dword ptr ds:[eax + %x]", v32, v37);
					break;
				case 141:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov ecx, dword ptr ss:[ebp + %x]", v32, v37);
					break;
				case 142:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov ecx, dword ptr ds:[esi + %x]", v32, v37);
					break;
				case 143:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov ecx, dword ptr ds:[edi + %x]", v32, v37);
					break;
				case 150:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov edx, dword ptr ds:[esi + %x]", v32, v37);
					break;
				case 151:
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov edx, dword ptr ds:[edi + %x]", v32, v37);
					break;
				default:
					if ( v21 != 0x9F )
					{
						if ( v21 == 4 )
						{
							if ( *(BYTE *)(AddrFinish + 2) == 0x85 )
							{
								v3 = *(DWORD *)(AddrFinish + 3);
								v37 = *(DWORD *)(AddrFinish + 3);
								v32 = AddrFinish;
								sprintf_s(v28, "//%x\tmov eax, dword ptr ds:[eax*4 + %x]", v32, v37);
								break;
							}
							if ( *(BYTE *)(AddrFinish + 2) == 0x95 )
							{
								v3 = *(DWORD *)(AddrFinish + 3);
								v37 = *(DWORD *)(AddrFinish + 3);
								v32 = AddrFinish;
								sprintf_s(v28, "//%x\tmov eax, dword ptr ds:[edx*4 + %x]", v32, v37);
								break;
							}
						}
						if ( v21 != 20 || *(BYTE *)(AddrFinish + 2) != 0x95 )
						{
							if ( v21 != 52 || *(BYTE *)(AddrFinish + 2) != 0x85 )
							{
								//__oMsg_2("v21: %x, %x", v21, *(BYTE *)(AddrFinish + 2));
								v36 = AddrFinish;
								sprintf_s(v28, "\t\t//%x\t(8B) ====<<UNKNOW COMMAND>>====", v36);
								goto LABEL_157;
							}
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tmov esi, dword ptr ds:[eax*4 + %x]", v32, v37);
						}
						else
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tmov edx, dword ptr ds:[edx*4 + %x]", v32, v37);
						}
						break;
					}
					 v37 = *(DWORD *)(AddrFinish + 2);
					 v32 = AddrFinish;
					sprintf_s(v28, "//%x\tmov ebx, dword ptr ds:[edi + %x]", v32, v37);
					break;
				}
			}
			goto LABEL_157;
		}
		
		//---------------0x8D------------------:
		if ( v11_BYTE == 0x8D )
		{
			BYTE v22 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			switch ( v22 )
			{
			case 134:
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tlea ecx,dword ptr ds:[esi+%x]", v32, v37);
				break;
			case 136:
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tlea ecx,dword ptr ds:[eax+%x]", v32, v37);
				break;
			case 138:
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tlea ecx,dword ptr ds:[edx+%x]", v32, v37);
				break;
			default:
				if ( v22 != 0x8C || *(BYTE *)(AddrFinish + 2) != 8 )
				{
					if ( v22 == 12 )
					{
						if ( *(BYTE *)(AddrFinish + 2) == 0x95 )
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[edx*4 + %x]", v32, v37);
							goto LABEL_157;
						}
						if ( *(BYTE *)(AddrFinish + 2) == 0xC5 )
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[eax*8 + %x]", v32, v37);
							goto LABEL_157;
						}
						if ( *(BYTE *)(AddrFinish + 2) == 0xD5 )
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[edx*8 + %x]", v32, v37);
							goto LABEL_157;
						}
						if ( *(BYTE *)(AddrFinish + 2) == 0xCD )
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[ecx*8 + %x]", v32, v37);
							goto LABEL_157;
						}
						if ( *(BYTE *)(AddrFinish + 2) == 0x8D )
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[ecx*4 + %x]", v32, v37);
							goto LABEL_157;
						}
						if ( *(BYTE *)(AddrFinish + 2) == 0x85 )
						{
							v3 = *(DWORD *)(AddrFinish + 3);
							v37 = *(DWORD *)(AddrFinish + 3);
							v32 = AddrFinish;
							sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[eax*4 + %x]", v32, v37);
							goto LABEL_157;
						}
					}
					v36 = AddrFinish;
					sprintf_s(v28, "\t\t//%x\t(8D) ====<<UNKNOW COMMAND>>====", v36);
					goto LABEL_157;
				}
				v3 = *(DWORD *)(AddrFinish + 3);
				v37 = *(DWORD *)(AddrFinish + 3);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tlea ecx, dword ptr ds:[eax + ecx + %x]", v32, v37);
				break;
			}
			goto LABEL_157;
		}
		if ( v11_BYTE == 163 )
		{
			v3 = *(DWORD *)(AddrFinish + 1);
			v37 = *(DWORD *)(AddrFinish + 1);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov dword ptr ds:[%x],eax", v32, v37);
			goto LABEL_157;
		}
		if ( v11_BYTE == 198 )
		{
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( *(BYTE *)(AddrFinish + 1) != 0x83 )
				goto LABEL_157;
			v37 = *(DWORD *)(AddrFinish + 2);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov byte ptr ds:[ebx + %x], xx", v32, v37);
			goto LABEL_157;
		}
		if ( v11_BYTE == 199 )
		{
			BYTE v23 = *(BYTE *)(AddrFinish + 1);
			v3 = *(DWORD *)(AddrFinish + 2);
			if ( v23 != 5 )
			{
				v14 = v23 == 69;
				if ( !v14 )
				{
					v36 = AddrFinish;
					sprintf_s(v28, "\t\t//%x\t(C7) ====<<UNKNOW COMMAND>>====", v36);
					goto LABEL_157;
				}
				v3 = *(DWORD *)(AddrFinish + 3);
				v37 = *(DWORD *)(AddrFinish + 3);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tmov dword ptr ss:[ebp - xx],%x", v32, v37);
				goto LABEL_157;
			}
			v37 = *(DWORD *)(AddrFinish + 2);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov dword ptr ds:[%x],0", v32, v37);
			goto LABEL_157;
		}
		if ( v11_BYTE == 0xBE )
		{
			v3 = *(DWORD *)(AddrFinish + 1);
			v37 = *(DWORD *)(AddrFinish + 1);
			v32 = AddrFinish;
			sprintf_s(v28, "//%x\tmov esi,%x", v32, v37);
			goto LABEL_157;
		}

		//====<<ADDED CODE>>==== ----tu them code:
		if ( v11_BYTE == 0xFF )	
		{
			BYTE v22 = *(BYTE *)(AddrFinish + 1);
			if (v22 == 0x35)		//FF35 14A83703				PUSH DWORD PTR DS:[0x337A814]
			{
				v3 = *(DWORD *)(AddrFinish + 2);
				v37 = *(DWORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tpush  dword ptr ds:[%x]\t\t\t\t====<<ADDED CODE>>====", v32, v37);
				goto LABEL_157;
			}
			else if (v22 == 0x50)		//FF50 6C					CALL DWORD PTR DS:[EAX+0x6C]
			{
				v3 = *(BYTE *)(AddrFinish + 2);
				v37 = *(BYTE *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tcall  dword ptr ds:[eax+%x]\t\t\t\t\t====<<ADDED CODE>>====", v32, (BYTE)v37);
				goto LABEL_157;
			}
			else if (v22 == 0x90)		//FF90 10040000				CALL DWORD PTR DS:[EAX+0x410]
			{
				v3 = *(WORD *)(AddrFinish + 2);
				v37 = *(WORD *)(AddrFinish + 2);
				v32 = AddrFinish;
				sprintf_s(v28, "//%x\tcall  dword ptr ds:[eax+%x]\t\t\t\t====<<ADDED CODE>>====", v32, (WORD)v37);
				goto LABEL_157;
			}
		}


		sprintf_s(v28, "\t\t//%x\t====<<UNKNOW COMMAND>>====", AddrFinish);
		v3 = 0;


//----------------------
LABEL_157:
		char v42[48] = {0};
		char v43[48] = {0};
		CUT_1(exportName, 28, v42);
		CUT_2(v3, 10, v43);
		sprintf_s(Buffer, "#define %s%s0x%x%s%s\n", exportName, v42, v3, v43, v28);

		goto END_FUNCTION;

		//----------------------
		//----------------------
		sprintf_s(Buffer, "#define --- xxxx %s", exportName);
	}



END_FUNCTION:

	//__oMsg_3("%s", Buffer);

	if (logFile)
	{
		DWORD dwBytesWritten = 0;
		string logme = Buffer;
		WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	}
}

//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
//-----------------//-----------------//-----------------//-----------------//-----------------//-----------------//
void INIT_INDICATOR()
{
	if (List_Indicators == 0)
	{
		List_Indicators = new std::vector<Indicators>;
		

	//-------- OFF_FUCKING_MOVE:
	Indicators INDICATOR_0a;	
	INDICATOR_0a.exportName  = "OFF_FUCKING_MOVE";		// ADD ESP,0x18  - RETN
	INDICATOR_0a.indicator	 = "83 C4 18 C3";
	INDICATOR_0a.addMore	 = 0x3;
	INDICATOR_0a.type		 = 2;
	List_Indicators->push_back(INDICATOR_0a);

	//-------- OFF_FUCKING_CAST:
	Indicators INDICATOR_0b;	
	INDICATOR_0b.exportName  = "OFF_FUCKING_CAST";		// ADD ESP,0x14  - RETN
	INDICATOR_0b.indicator	 = "83 C4 14 C3";
	INDICATOR_0b.addMore	 = 0x3;
	INDICATOR_0b.type		 = 2;
	List_Indicators->push_back(INDICATOR_0b);

	//-------- \n\n\:
	Indicators INDICATOR_0c;
	INDICATOR_0c.type		 = 0;
	List_Indicators->push_back(INDICATOR_0c);


		//-------- BASE:
		Indicators INDICATOR_1;	
		INDICATOR_1.exportName   = "BASE";
		INDICATOR_1.indicator	 = "6A 01 6A 01 8D 44 24 0C 50";
		INDICATOR_1.addMore		 = 0x12D;
		INDICATOR_1.type		 = 1;
		List_Indicators->push_back(INDICATOR_1);
		
		//-------- BASE_SKILL:
		Indicators INDICATOR_2;
		INDICATOR_2.exportName   = "BASE_SKILL";
		INDICATOR_2.indicator	 = "FF 77 40 8B CE FF 77 3C 6A 00 6A 00 50";
		INDICATOR_2.addMore	     = -0x47;
		INDICATOR_2.type		 = 1;
		List_Indicators->push_back(INDICATOR_2);

		//-------- BASE_ENDGAME:
		Indicators INDICATOR_3;
		INDICATOR_3.exportName   = "BASE_ENDGAME";
		INDICATOR_3.indicator	 = "C6 46 0C 02 8D 4C 24 18";
		INDICATOR_3.addMore	     = 0x15;
		INDICATOR_3.type		 = 1;
		List_Indicators->push_back(INDICATOR_3);

	//-------- \n\n\:
	Indicators INDICATOR_4;
	INDICATOR_4.type		 = 0;
	List_Indicators->push_back(INDICATOR_4);
		
		//-------- BASE_MAPDATA:
		Indicators INDICATOR_5;
		INDICATOR_5.exportName   = "BASE_MAPDATA";
		INDICATOR_5.indicator	 = "40 81 C1 84 00 00 00 3B C2";
		INDICATOR_5.addMore	     = -0x24;
		INDICATOR_5.type		 = 1;
		List_Indicators->push_back(INDICATOR_5);
		
		//-------- BASE_MAPDATA_2:
		Indicators INDICATOR_6;
		INDICATOR_6.exportName   = "BASE_MAPDATA_2";
		INDICATOR_6.indicator	 = "F3 0F 5C 04 B0 C7 44 24 14 00 00 80 3F";
		INDICATOR_6.addMore	     = -0x9F;
		INDICATOR_6.type		 = 1;
		List_Indicators->push_back(INDICATOR_6);
		  
		//-------- BASE_TIME_DU_BI:
		Indicators INDICATOR_7;
		INDICATOR_7.exportName   = "BASE_TIME_DU_BI";
		INDICATOR_7.indicator	 = "C7 44 24 0C 00 00 00 00 57 83 7E 64 00";
		INDICATOR_7.addMore	     = 0x36;
		INDICATOR_7.type		 = 1;
		List_Indicators->push_back(INDICATOR_7);
		
		//-------- BASE_OBJECT_ALL:
		Indicators INDICATOR_8;
		INDICATOR_8.exportName   = "BASE_OBJECT_ALL";
		INDICATOR_8.indicator	 = "33 FF 8B BF A0 05 00 00 85 FF";
		INDICATOR_8.addMore	     = 0x10;
		INDICATOR_8.type		 = 1;
		List_Indicators->push_back(INDICATOR_8);
		
		//-------- BASE_RENDERER:
		Indicators INDICATOR_9;
		INDICATOR_9.exportName   = "BASE_RENDERER";
		INDICATOR_9.indicator	 = "83 C4 04 80 B9 8C 00 00 00 00 74 05";
		INDICATOR_9.addMore	     = -0x4E;
		INDICATOR_9.type		 = 1;
		List_Indicators->push_back(INDICATOR_9);
		
		//-------- BASE_RENDERER_2:
		Indicators INDICATOR_10;
		INDICATOR_10.exportName  = "BASE_RENDERER_2";
		INDICATOR_10.indicator	 = "88 47 1C 80 7F 1C 00";
		INDICATOR_10.addMore	 = -0x12;
		INDICATOR_10.type		 = 1;
		List_Indicators->push_back(INDICATOR_10);
	
	//-------- \n\n\:
	Indicators INDICATOR_11;
	INDICATOR_11.type			 = 0;
	List_Indicators->push_back(INDICATOR_11);
		
		//-------- BASE_GAME_TIME_NOW_X:
		Indicators INDICATOR_12a;
		INDICATOR_12a.exportName  = "BASE_GAME_TIME_NOW_X";
		INDICATOR_12a.indicator	 = "F3 0F 10 44 24 14 C6 46 1C 00";
		INDICATOR_12a.addMore	 = 0x10;
		INDICATOR_12a.type		 = 1;
		List_Indicators->push_back(INDICATOR_12a);

		//-------- BASE_GAME_TIME1:
		Indicators INDICATOR_12;
		INDICATOR_12.exportName  = "BASE_GAME_TIME1";
		INDICATOR_12.indicator	 = "83 F9 43 74 09 8B 47 14";
		INDICATOR_12.addMore	 = 0xE;
		INDICATOR_12.type		 = 1;
		List_Indicators->push_back(INDICATOR_12);

		//-------- GET_GAMETIME_FUNC:
		Indicators INDICATOR_13;
		INDICATOR_13.exportName  = "GET_GAMETIME_FUNC";
		INDICATOR_13.indicator	 = "83 F9 43 74 09 8B 47 14";
		INDICATOR_13.addMore	 = 0x1A;
		INDICATOR_13.type		 = 1;
		List_Indicators->push_back(INDICATOR_13);
		
	//-------- \n\n\:
	Indicators INDICATOR_14;
	INDICATOR_14.type			 = 0;
	List_Indicators->push_back(INDICATOR_14);
		
		//-------- BASE_AttackableUnit:
		Indicators INDICATOR_15;
		INDICATOR_15.exportName  = "BASE_AttackableUnit";
		INDICATOR_15.indicator	 = "C1 F8 02 D1 E8";
		INDICATOR_15.addMore	 = 0x32;
		INDICATOR_15.type		 = 1;
		List_Indicators->push_back(INDICATOR_15);

		//-------- BASE_AttackableUnit_MAX:
		Indicators INDICATOR_16;
		INDICATOR_16.exportName  = "BASE_AttackableUnit_MAX";
		INDICATOR_16.indicator	 = "C1 F8 02 D1 E8";
		INDICATOR_16.addMore	 = 0x2C;
		INDICATOR_16.type		 = 1;
		List_Indicators->push_back(INDICATOR_16);
	
	//-------- \n\n\:
	Indicators INDICATOR_17;
	INDICATOR_17.type			 = 0;
	List_Indicators->push_back(INDICATOR_17);

		//-------- BASE_HERO:
		Indicators INDICATOR_18;
		INDICATOR_18.exportName  = "BASE_HERO";
		INDICATOR_18.indicator	 = "8B 0E 3B 41 4C 75 15";
		INDICATOR_18.addMore	 = -0x16;
		INDICATOR_18.type		 = 1;
		List_Indicators->push_back(INDICATOR_18);

		//-------- BASE_HERO_MAX:
		Indicators INDICATOR_19;
		INDICATOR_19.exportName  = "BASE_HERO_MAX";
		INDICATOR_19.indicator	 = "8B 0E 3B 41 4C 75 15";
		INDICATOR_19.addMore	 = -0x1E;
		INDICATOR_19.type		 = 1;
		List_Indicators->push_back(INDICATOR_19);
		
	//-------- $D:
	Indicators INDICATOR_20;
	INDICATOR_20.type			 = 0;
	List_Indicators->push_back(INDICATOR_20);

	//-------- $F:
	Indicators INDICATOR_21;
	INDICATOR_21.exportName		 = "//-----------------------------------";
	INDICATOR_21.type			 = 3;
	List_Indicators->push_back(INDICATOR_21);

		//-------- BASE_DDS_NEW:
		Indicators INDICATOR_22;
		INDICATOR_22.exportName  = "BASE_DDS_NEW";
		INDICATOR_22.indicator	 = "89 44 24 34 8B 43 20 83 C0 28";
		INDICATOR_22.addMore	 = -0xD;
		INDICATOR_22.type		 = 1;
		List_Indicators->push_back(INDICATOR_22);

		//-------- GET_DDS_NEW_FUNC:
		Indicators INDICATOR_23;
		INDICATOR_23.exportName  = "GET_DDS_NEW_FUNC";
		INDICATOR_23.indicator	 = "8D 3C 80 C1 E7 02 57";
		INDICATOR_23.addMore	 = -0x63;
		INDICATOR_23.type		 = 1;
		List_Indicators->push_back(INDICATOR_23);
		
						////-------- BASE_DIRECTION:
						//Indicators INDICATOR_24;
						//INDICATOR_24.exportName  = "BASE_DIRECTION";
						//INDICATOR_24.indicator	 = "83 C4 48 8B 00 6A 00 51 C7 04 24 00 00 FA 43";
						//INDICATOR_24.addMore	 = -0xF5;
						//INDICATOR_24.type		 = 1;
						//List_Indicators->push_back(INDICATOR_24);
	
		//-------- BASE_TEXTURE_DDS:
		Indicators INDICATOR_25;
		INDICATOR_25.exportName  = "BASE_TEXTURE_DDS";
		INDICATOR_25.indicator	 = "83 C4 04 85 C0 74 15 FF 74 24 28";
		INDICATOR_25.addMore	 = 0xD;
		INDICATOR_25.type		 = 1;
		List_Indicators->push_back(INDICATOR_25);
		
		//-------- OFFSET_TEXTURE_DDS:
		Indicators INDICATOR_26;
		INDICATOR_26.exportName  = "OFFSET_TEXTURE_DDS";
		INDICATOR_26.indicator	 = "83 C4 48 8B 00 6A 00 51 C7 04 24 00 00 FA 43";
		INDICATOR_26.addMore	 = -0x162;
		INDICATOR_26.type		 = 1;
		List_Indicators->push_back(INDICATOR_26);
		
						////-------- GET_TEXTURE_GAME_FUNC:
						//Indicators INDICATOR_27;
						//INDICATOR_27.exportName  = "GET_TEXTURE_GAME_FUNC";
						//INDICATOR_27.indicator	 = "8D 44 24 1C 6A 01 6A 00 57 50";
						//INDICATOR_27.addMore	 = 0xA;
						//INDICATOR_27.type		 = 1;
						//List_Indicators->push_back(INDICATOR_27);

	//-------- $F:
	Indicators INDICATOR_28;
	INDICATOR_28.exportName		 = "//-----------------------GAME_DRAW_CIRCLE_FUNC: 47 83 C4 1C 3B 7C 24 20 (-B)";
	INDICATOR_28.type			 = 3;
	List_Indicators->push_back(INDICATOR_28);	
		
		//-------- GAME_DRAW_CIRCLE_FUNC:
		Indicators INDICATOR_29;
		INDICATOR_29.exportName  = "GAME_DRAW_CIRCLE_FUNC";
		INDICATOR_29.indicator	 = "8B 47 1C 83 F8 01 0F 4C C1";
		INDICATOR_29.addMore	 = 0x62;
		INDICATOR_29.type		 = 1;
		List_Indicators->push_back(INDICATOR_29);
		
	//-------- $D:
	Indicators INDICATOR_30;
	INDICATOR_30.type			 = 0;
	List_Indicators->push_back(INDICATOR_30);
	
		//-------- HamChuaLuNay_CIRCLEMINIMAP:
		Indicators INDICATOR_31;
		INDICATOR_31.exportName  = "HamChuaLuNay_CIRCLEMINIMAP";
		INDICATOR_31.indicator	 = "C6 00 00 0F B6 46 24 83 E8 00";
		INDICATOR_31.addMore	 = 0x9A;
		INDICATOR_31.type		 = 1;
		List_Indicators->push_back(INDICATOR_31);
	
		//-------- BASE_DRAW_CIRCLEMINIMAP:
		Indicators INDICATOR_32;
		INDICATOR_32.exportName  = "BASE_DRAW_CIRCLEMINIMAP";
		INDICATOR_32.indicator	 = "C6 00 00 0F B6 46 24 83 E8 00";
		INDICATOR_32.addMore	 = 0x3E;
		INDICATOR_32.type		 = 1;
		List_Indicators->push_back(INDICATOR_32);
			
		//-------- DRAWCIRCLEMINIMAP_OFFSET1:
		Indicators INDICATOR_33;
		INDICATOR_33.exportName  = "DRAWCIRCLEMINIMAP_OFFSET1";
		INDICATOR_33.indicator	 = "C6 00 00 0F B6 46 24 83 E8 00";
		INDICATOR_33.addMore	 = 0x43;
		INDICATOR_33.type		 = 1;
		List_Indicators->push_back(INDICATOR_33);
		 
		//-------- DRAWCIRCLEMINIMAP_OFFSET2:
		Indicators INDICATOR_34;
		INDICATOR_34.exportName  = "DRAWCIRCLEMINIMAP_OFFSET2";
		INDICATOR_34.indicator	 = "83 C0 78 3B C2 75 F5";
		INDICATOR_34.addMore	 = -0x3B;
		INDICATOR_34.type		 = 1;
		List_Indicators->push_back(INDICATOR_34);

		//-------- GAMEDRAW_CIRCLE_MiMAP_FUNC:
		Indicators INDICATOR_35;
		INDICATOR_35.exportName  = "GAMEDRAW_CIRCLE_MiMAP_FUNC";
		INDICATOR_35.indicator	 = "83 C0 78 3B C2 75 F5";
		INDICATOR_35.addMore	 = 0x79;
		INDICATOR_35.type		 = 1;
		List_Indicators->push_back(INDICATOR_35);

	//-------- $D:
	Indicators INDICATOR_36;
	INDICATOR_36.type			 = 0;
	List_Indicators->push_back(INDICATOR_36);

		//-------- DrawCircleChuaCanDung_FUNC:
		Indicators INDICATOR_37;
		INDICATOR_37.exportName  = "DrawCircleChuaCanDung_FUNC";
		INDICATOR_37.indicator	 = "51 F3 0F 11 04 24 C7 00 00 00 00 00";
		INDICATOR_37.addMore	 = 0x11;
		INDICATOR_37.type		 = 1;
		List_Indicators->push_back(INDICATOR_37);
		
		//-------- GAME_DRAW_LINE_FUNC:
		Indicators INDICATOR_38;
		INDICATOR_38.exportName  = "GAME_DRAW_LINE_FUNC";
		INDICATOR_38.indicator	 = "83 C4 14 A8 02 74 18";
		INDICATOR_38.addMore	 = -0x9;
		INDICATOR_38.type		 = 1;
		List_Indicators->push_back(INDICATOR_38);

		//-------- GAME_DRAW_LINE_FUNC_222:
		Indicators INDICATOR_38_a;
		INDICATOR_38_a.exportName= "GAME_DRAW_LINE_FUNC_222";
		INDICATOR_38_a.indicator = "8B D0 BF 80 00 00 00 8B 0A";
		INDICATOR_38_a.addMore	 = 0xB2;
		INDICATOR_38_a.type		 = 1;
		List_Indicators->push_back(INDICATOR_38_a);

	//-------- $D:
	Indicators INDICATOR_39;
	INDICATOR_39.type			 = 0;
	List_Indicators->push_back(INDICATOR_39);	
		
		//-------- GET_WPOS_BAR_FUNC: ($B)
		Indicators INDICATOR_40;
		INDICATOR_40.exportName  = "GET_WPOS_BAR_FUNC";
		INDICATOR_40.indicator	 = "83 C4 04 8B F0 80 BB 8C 00"; 
		INDICATOR_40.addMore	 = -0x67;
		INDICATOR_40.type		 = 2;			//$B
		List_Indicators->push_back(INDICATOR_40);
		
		//-------- WPOS_2_SPOS_FUNC:
		Indicators INDICATOR_41;
		INDICATOR_41.exportName  = "WPOS_2_SPOS_FUNC";
		INDICATOR_41.indicator	 = "83 C4 04 8B F0 80 BB 8C 00";
		INDICATOR_41.addMore	 = -0x3F;
		INDICATOR_41.type		 = 1;
		List_Indicators->push_back(INDICATOR_41);
			
							////-------- GET_BAR_DETAIL_FUNC: ($B)
							//Indicators INDICATOR_42;
							//INDICATOR_42.exportName  = "GET_BAR_DETAIL_FUNC";
							//INDICATOR_42.indicator	 = "85 F6 75 1A 6A 01 8B CB";
							//INDICATOR_42.addMore	 = -0x12;
							//INDICATOR_42.type		 = 2;			//$B
							//List_Indicators->push_back(INDICATOR_42);
		
		//-------- GAME_DRAW_2D_FUNC:
		Indicators INDICATOR_43;
		INDICATOR_43.exportName  = "GAME_DRAW_2D_FUNC";
		INDICATOR_43.indicator	 = "C7 44 24 08 00 00 00 40 C7 44 24 04 00 00 00 00";
		INDICATOR_43.addMore	 = -0x4F;
		INDICATOR_43.type		 = 1;
		List_Indicators->push_back(INDICATOR_43);
		
		//-------- DRAW_ICON2D_1_FUNC:
		Indicators INDICATOR_44;
		INDICATOR_44.exportName  = "DRAW_ICON2D_1_FUNC";
		INDICATOR_44.indicator	 = "83 C4 10 83 38 00 75 0C";
		INDICATOR_44.addMore	 = -0x17;
		INDICATOR_44.type		 = 1;
		List_Indicators->push_back(INDICATOR_44);
		
		//-------- DRAW_ICON2D_2_FUNC:
		Indicators INDICATOR_45;
		INDICATOR_45.exportName  = "DRAW_ICON2D_2_FUNC";
		INDICATOR_45.indicator	 = "83 C4 10 83 38 00 75 0C";
		INDICATOR_45.addMore	 = 0x1A;
		INDICATOR_45.type		 = 1;
		List_Indicators->push_back(INDICATOR_45);
		
		//-------- DRAW_ICON2D_3_FUNC:
		Indicators INDICATOR_46;
		INDICATOR_46.exportName  = "DRAW_ICON2D_3_FUNC";
		INDICATOR_46.indicator	 = "83 C4 10 83 38 00 75 0C";
		INDICATOR_46.addMore	 = 0x4A;
		INDICATOR_46.type		 = 1;
		List_Indicators->push_back(INDICATOR_46);

		//-------- BASE_ICON2D:
		Indicators INDICATOR_47;
		INDICATOR_47.exportName  = "BASE_ICON2D";
		INDICATOR_47.indicator	 = "8B 37 83 7E 3C 00 74 06";
		INDICATOR_47.addMore	 = -0x1D;
		INDICATOR_47.type		 = 1;
		List_Indicators->push_back(INDICATOR_47);

	//-------- $D:
	Indicators INDICATOR_48;
	INDICATOR_48.type			 = 0;
	List_Indicators->push_back(INDICATOR_48);	

		//-------- WPOS2_SCREENMINI_FUNC:
		Indicators INDICATOR_49;
		INDICATOR_49.exportName  = "WPOS2_SCREENMINI_FUNC";
		INDICATOR_49.indicator	 = "8B F9 50 FF 74 24 60";
		INDICATOR_49.addMore	 = 0x7;
		INDICATOR_49.type		 = 1;
		List_Indicators->push_back(INDICATOR_49);
			
		//-------- BASE_FOLDER_SOURCE:
		Indicators INDICATOR_50;
		INDICATOR_50.exportName  = "BASE_FOLDER_SOURCE";
		INDICATOR_50.indicator	 = "C7 44 24 10 40 00 00 00 89 4C 24 18 C7 44 24 1C 12 00 00 00";
		INDICATOR_50.addMore	 = -0xF6;
		INDICATOR_50.type		 = 1;
		List_Indicators->push_back(INDICATOR_50);
		
		//-------- LOAD_FOLDER_SOURCE_OLD_FUNC:
		Indicators INDICATOR_51;
		INDICATOR_51.exportName  = "LOAD_FOLDER_SOURCE_OLD_FUNC";
		INDICATOR_51.indicator	 = "C7 44 24 10 40 00 00 00 89 4C 24 18 C7 44 24 1C 12 00 00 00";
		INDICATOR_51.addMore	 = -0xF1;
		INDICATOR_51.type		 = 1;
		List_Indicators->push_back(INDICATOR_51);
		
		//-------- LOAD_FOLDER_SOURCE_FUNC:
		Indicators INDICATOR_52;
		INDICATOR_52.exportName  = "LOAD_FOLDER_SOURCE_FUNC";
		INDICATOR_52.indicator	 = "8B 07 6A 00 55 50";
		INDICATOR_52.addMore	 = 0xB;
		INDICATOR_52.type		 = 1;
		List_Indicators->push_back(INDICATOR_52);
	
	//-------- $D:
	Indicators INDICATOR_53;
	INDICATOR_53.type			 = 0;
	List_Indicators->push_back(INDICATOR_53);

		//-------- MODSKIN_FUNC: ($B)
		Indicators INDICATOR_54;
		INDICATOR_54.exportName  = "MODSKIN_FUNC";
		INDICATOR_54.indicator	 = "BB 00 80 FF FF 66 3B FB 74 0D";
		INDICATOR_54.addMore	 = -0x12E;
		INDICATOR_54.type		 = 2;				//($B)
		List_Indicators->push_back(INDICATOR_54);

		//-------- MODSKIN_FUNC_2:
		Indicators INDICATOR_55;
		INDICATOR_55.exportName  = "MODSKIN_FUNC_2";
		INDICATOR_55.indicator	 = "6A 00 89 48 04";
		INDICATOR_55.addMore	 = -0xD0;
		INDICATOR_55.type		 = 1;
		List_Indicators->push_back(INDICATOR_55);
		
		//-------- MODSKIN_HU1_FUNC:
		Indicators INDICATOR_56;
		INDICATOR_56.exportName  = "MODSKIN_HU1_FUNC";				//"character", "Body", "Header"
		INDICATOR_56.indicator	 = "6A 00 8D 44 24 48 53 50";
		INDICATOR_56.addMore	 = 0x8;
		INDICATOR_56.type		 = 1;
		List_Indicators->push_back(INDICATOR_56);
		
		//-------- MODSKIN_HU2_FUNC:
		Indicators INDICATOR_57;
		INDICATOR_57.exportName  = "MODSKIN_HU2_FUNC";
		INDICATOR_57.indicator	 = "C7 80 94 01 00 00 00 00 C8 42";
		INDICATOR_57.addMore	 = -0x4F;
		INDICATOR_57.type		 = 1;
		List_Indicators->push_back(INDICATOR_57);
	
	//-------- $D:
	Indicators INDICATOR_58;
	INDICATOR_58.type			 = 0;
	List_Indicators->push_back(INDICATOR_58);

	//-------- $F:
	Indicators INDICATOR_59;
	INDICATOR_59.exportName		 = "//-----------------------------------";
	INDICATOR_59.type			 = 3;
	List_Indicators->push_back(INDICATOR_59);
		
							////-------- CHAT_TO_PLAYER_FUNC:
							//Indicators INDICATOR_60;
							//INDICATOR_60.exportName  = "CHAT_TO_PLAYER_FUNC";
							//INDICATOR_60.indicator	 = "0F B7 07 83 E8 65";
							//INDICATOR_60.addMore	 = -0x24;
							//INDICATOR_60.type		 = 1;
							//List_Indicators->push_back(INDICATOR_60);

		//-------- ECX_SEND_CHAT:
		Indicators INDICATOR_61;
		INDICATOR_61.exportName  = "ECX_SEND_CHAT";
		INDICATOR_61.indicator	 = "83 C4 1C 80 FB 0D 75 09";
		INDICATOR_61.addMore	 = 0x67;
		INDICATOR_61.type		 = 1;
		List_Indicators->push_back(INDICATOR_61);
		
		//-------- GET_PINGGAME_FUNC:
		Indicators INDICATOR_62;
		INDICATOR_62.exportName  = "GET_PINGGAME_FUNC";
		INDICATOR_62.indicator	 = "83 C4 10 89 6B 20 5F 5E C6 43 0C 00";
		INDICATOR_62.addMore	 = -0x2B;
		INDICATOR_62.type		 = 1;
		List_Indicators->push_back(INDICATOR_62);

	//-------- $D:
	Indicators INDICATOR_63;
	INDICATOR_63.type			 = 0;
	List_Indicators->push_back(INDICATOR_63);

		//-------- BASE_IS_CHATTING:
		Indicators INDICATOR_64;
		INDICATOR_64.exportName  = "BASE_IS_CHATTING";
		INDICATOR_64.indicator	 = "C6 87 0C 01 00 00 00 5E";
		INDICATOR_64.addMore	 = -0x8A;
		INDICATOR_64.type		 = 1;
		List_Indicators->push_back(INDICATOR_64);
		
	//-------- $D:
	Indicators INDICATOR_65;
	INDICATOR_65.type			 = 0;
	List_Indicators->push_back(INDICATOR_65);
	
		//-------- BASE_CHAT_SYS:
		Indicators INDICATOR_66;
		INDICATOR_66.exportName  = "BASE_CHAT_SYS";
		INDICATOR_66.indicator	 = "83 7E 64 10 8D 46 50";
		INDICATOR_66.addMore	 = 0x11;
		INDICATOR_66.type		 = 1;
		List_Indicators->push_back(INDICATOR_66);
		
		//-------- SEND_TEXT_SYSTEM_FUNC:
		Indicators INDICATOR_67;
		INDICATOR_67.exportName  = "SEND_TEXT_SYSTEM_FUNC";
		INDICATOR_67.indicator	 = "83 7E 64 10 8D 46 50";
		INDICATOR_67.addMore	 = 0x18;
		INDICATOR_67.type		 = 1;
		List_Indicators->push_back(INDICATOR_67);
		
	//-------- $D:
	Indicators INDICATOR_68;
	INDICATOR_68.type			 = 0;
	List_Indicators->push_back(INDICATOR_68);
	
	//-------- $F:
	Indicators INDICATOR_69;
	INDICATOR_69.exportName		 = "//-----------------------------------";
	INDICATOR_69.type			 = 3;
	List_Indicators->push_back(INDICATOR_69);
		
		//-------- GET_PMOVE_FUNC:
		Indicators INDICATOR_70;
		INDICATOR_70.exportName  = "GET_PMOVE_FUNC";
		INDICATOR_70.indicator	 = "2B CA 51 55 8D 4C 24 34";
		INDICATOR_70.addMore	 = -0x9D;
		INDICATOR_70.type		 = 1;
		List_Indicators->push_back(INDICATOR_70);
		
		//-------- GET_CDBA_NEW_FUNC:
		Indicators INDICATOR_71;
		INDICATOR_71.exportName  = "GET_CDBA_NEW_FUNC";
		INDICATOR_71.indicator	 = "C7 44 24 20 00 00 20 00 51";
		INDICATOR_71.addMore	 = -0x2F2;
		INDICATOR_71.type		 = 1;
		List_Indicators->push_back(INDICATOR_71);

	//-------- $D:
	Indicators INDICATOR_72;
	INDICATOR_72.type			 = 0;
	List_Indicators->push_back(INDICATOR_72);
		
		//-------- IS_OBJ_DELETED_FUNC:
		Indicators INDICATOR_73;
		INDICATOR_73.exportName  = "IS_OBJ_DELETED_FUNC";
		INDICATOR_73.indicator	 = "83 C4 0C 83 83 B4 00 00 00 FC ";
		INDICATOR_73.addMore	 = -0xB7;
		INDICATOR_73.type		 = 1;
		List_Indicators->push_back(INDICATOR_73);
		
		//-------- IS_HERO_FUNC:
		Indicators INDICATOR_74;
		INDICATOR_74.exportName  = "IS_HERO_FUNC";
		INDICATOR_74.indicator	 = "8B 13 8B CB FF 52 04 5B 5F 8B C6";
		INDICATOR_74.addMore	 = -0x70;
		INDICATOR_74.type		 = 1;
		List_Indicators->push_back(INDICATOR_74);
		
		//-------- IS_MINION_FUNC:
		Indicators INDICATOR_75;
		INDICATOR_75.exportName  = "IS_MINION_FUNC";
		INDICATOR_75.indicator	 = "8B 13 8B CB FF 52 04 5B 5F 8B C6";
		INDICATOR_75.addMore	 = -0x84;
		INDICATOR_75.type		 = 1;
		List_Indicators->push_back(INDICATOR_75);
		
		//-------- IS_TURRET_FUNC:
		Indicators INDICATOR_76;
		INDICATOR_76.exportName  = "IS_TURRET_FUNC";
		INDICATOR_76.indicator	 = "8B 13 8B CB FF 52 04 5B 5F 8B C6";
		INDICATOR_76.addMore	 = -0x5C;
		INDICATOR_76.type		 = 1;
		List_Indicators->push_back(INDICATOR_76);
		
		//-------- IS_NEXUS_FUNC:
		Indicators INDICATOR_77;
		INDICATOR_77.exportName  = "IS_NEXUS_FUNC";
		INDICATOR_77.indicator	 = "8B 13 8B CB FF 52 04 5B 5F 8B C6";
		INDICATOR_77.addMore	 = -0x48;
		INDICATOR_77.type		 = 1;
		List_Indicators->push_back(INDICATOR_77);
	
		//-------- IS_INHIBITOR_FUNC:
		Indicators INDICATOR_78;
		INDICATOR_78.exportName  = "IS_INHIBITOR_FUNC";
		INDICATOR_78.indicator	 = "8B 13 8B CB FF 52 04 5B 5F 8B C6";
		INDICATOR_78.addMore	 = -0x34;
		INDICATOR_78.type		 = 1;
		List_Indicators->push_back(INDICATOR_78);

	//-------- $D:
	Indicators INDICATOR_79;
	INDICATOR_79.type			 = 0;
	List_Indicators->push_back(INDICATOR_79);
		
		//-------- IS_ALIVE_FUNC:($B)
		Indicators INDICATOR_79a;
		INDICATOR_79a.exportName  = "IS_ALIVE_FUNC";
		INDICATOR_79a.indicator	 = "FF D0 84 C0 75 04 B0 01 5E C3 32 C0";
		INDICATOR_79a.addMore	 = -0x20;
		INDICATOR_79a.type		 = 2;
		List_Indicators->push_back(INDICATOR_79a);

		//-------- BASE_DEVICE:	
		Indicators INDICATOR_79b;
		INDICATOR_79b.exportName = "BASE_DEVICE";				//"d3dcompiler_43.dll"			
		INDICATOR_79b.indicator	 = "51 0F 11 44 24 18 6A 02";	
		INDICATOR_79b.addMore	 = -0x5;
		INDICATOR_79b.type		 = 1;
		List_Indicators->push_back(INDICATOR_79b);

	//-------- $D:
	Indicators INDICATOR_79c;
	INDICATOR_79c.type			 = 0;
	List_Indicators->push_back(INDICATOR_79c);

	//-------- $F:
	Indicators INDICATOR_80;
	INDICATOR_80.exportName		 = "//-----------------------------------";
	INDICATOR_80.type			 = 3;
	List_Indicators->push_back(INDICATOR_80);
		
		//-------- GET_AA_DELAY_FUNC:
		Indicators INDICATOR_81;
		INDICATOR_81.exportName  = "GET_AA_DELAY_FUNC";
		INDICATOR_81.indicator	 = "C7 44 24 20 00 00 20 00 51";
		INDICATOR_81.addMore	 = -0x2B6;
		INDICATOR_81.type		 = 1;
		List_Indicators->push_back(INDICATOR_81);
	
		//-------- GET_AA_DELAY_FUNC_2:
		Indicators INDICATOR_82;
		INDICATOR_82.exportName  = "GET_AA_DELAY_FUNC_2";
		INDICATOR_82.indicator	 = "51 56 8B F1 57 8B 4E 04 8B 01";
		INDICATOR_82.addMore	 = 0x15;
		INDICATOR_82.type		 = 1;
		List_Indicators->push_back(INDICATOR_82);
		
		//-------- GET_BASIC_ATTACK_FUNC:
		Indicators INDICATOR_83;
		INDICATOR_83.exportName  = "GET_BASIC_ATTACK_FUNC";
		INDICATOR_83.indicator	 = "C7 44 24 20 00 00 20 00 51";
		INDICATOR_83.addMore	 = -0x2CC;
		INDICATOR_83.type		 = 1;
		List_Indicators->push_back(INDICATOR_83);
	
		//-------- GET_AA_ANIMATE_DELAY_FUNC:
		Indicators INDICATOR_84;
		INDICATOR_84.exportName  = "GET_AA_ANIMATE_DELAY_FUNC";
		INDICATOR_84.indicator	 = "C7 44 24 20 00 00 20 00 51";
		INDICATOR_84.addMore	 = -0x2C2;
		INDICATOR_84.type		 = 1;
		List_Indicators->push_back(INDICATOR_84);

		//-------- GET_AA_ANIMATE_DELAY_FUNC_2:
		Indicators INDICATOR_85;
		INDICATOR_85.exportName  = "GET_AA_ANIMATE_DELAY_FUNC_2";
		INDICATOR_85.indicator	 = "80 3F 01 75 07 80 7C 24 1C 00";
		INDICATOR_85.addMore	 = 0x28;
		INDICATOR_85.type		 = 1;
		List_Indicators->push_back(INDICATOR_85);

	//-------- $D:
	Indicators INDICATOR_86;
	INDICATOR_86.type			 = 0;
	List_Indicators->push_back(INDICATOR_86);

		//-------- VMT_ONPROCESSSPELL_INDEX:
		Indicators INDICATOR_87;
		INDICATOR_87.exportName  = "VMT_ONPROCESSSPELL_INDEX";
		INDICATOR_87.indicator	 = "83 C4 04 6A 00 57 6A 0B";
		INDICATOR_87.addMore	 = 0x8;
		INDICATOR_87.type		 = 1;
		List_Indicators->push_back(INDICATOR_87);

		//-------- VMT_ONPROCESSSPELL_OFFSET:
		Indicators INDICATOR_88;
		INDICATOR_88.exportName  = "VMT_ONPROCESSSPELL_OFFSET";
		INDICATOR_88.indicator	 = "83 C4 04 6A 00 57 6A 0B";
		INDICATOR_88.addMore	 = 0xB;
		INDICATOR_88.type		 = 1;
		List_Indicators->push_back(INDICATOR_88);
		
		//-------- VMT_ONCREAREMISSILE_INDEX:
		Indicators INDICATOR_89;
		INDICATOR_89.exportName  = "VMT_ONCREAREMISSILE_INDEX";
		INDICATOR_89.indicator	 = "B8 00 00 01 00 5B 83 C4 10 C2 04 00 8B 74 24 14";
		INDICATOR_89.addMore	 = 0x8C;
		INDICATOR_89.type		 = 1;
		List_Indicators->push_back(INDICATOR_89);
		
		//-------- VMT_ONCREAREMISSILE_OFFSET:
		Indicators INDICATOR_90;
		INDICATOR_90.exportName  = "VMT_ONCREAREMISSILE_OFFSET";
		INDICATOR_90.indicator	 = "83 C4 10 8D 4C 24 18 BB 04 00 00 00 12 34 56";			   // them 12 34 56 cho no NOT_FOUND (vi offet luon bang 0 nen ko can)
		INDICATOR_90.addMore	 = 0x34;
		INDICATOR_90.type		 = 1;
		List_Indicators->push_back(INDICATOR_90);

		//-------- VMT_ONPLAYANIMATION_INDEX:
		Indicators INDICATOR_91;
		INDICATOR_91.exportName  = "VMT_ONPLAYANIMATION_INDEX";
		INDICATOR_91.indicator	 = "6A 02 51 C7 04 24 00 00 80 3F 8D 4C 24 30 6A 01";
		INDICATOR_91.addMore	 = 0x1A;
		INDICATOR_91.type		 = 1;
		List_Indicators->push_back(INDICATOR_91);
		
		//-------- VMT_ONPLAYANIMATION_OFFSET:
		Indicators INDICATOR_92;
		INDICATOR_92.exportName  = "VMT_ONPLAYANIMATION_OFFSET";
		INDICATOR_92.indicator	 = "6A 02 51 C7 04 24 00 00 80 3F 8D 4C 24 30 6A 01 12 34 56";	// them 12 34 56 cho no NOT_FOUND (vi offet luon bang 0 nen ko can)
		INDICATOR_92.addMore	 = -0x2;
		INDICATOR_92.type		 = 1;
		List_Indicators->push_back(INDICATOR_92);
	
	//-------- $F:
	Indicators INDICATOR_92_1;
	INDICATOR_92_1.exportName	 = "//-----------------------------------";
	INDICATOR_92_1.type			 = 3;
	List_Indicators->push_back(INDICATOR_92_1);

		//-------- ON_PLAY_ANIMATION_FUNC:($B)
		Indicators INDICATOR_93;
		INDICATOR_93.exportName  = "ON_PLAY_ANIMATION_FUNC";
		INDICATOR_93.indicator	 = "57 68 C5 9D 1C 81 FF 74 24 28";
		INDICATOR_93.addMore	 = -0x4;
		INDICATOR_93.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_93);
		
		//-------- ON_DO_CAST_FUNC:
		Indicators INDICATOR_94;
		INDICATOR_94.exportName  = "ON_DO_CAST_FUNC";
		INDICATOR_94.indicator	 = "C7 44 24 04 00 00 80 BF C7 04 24 00 00 00 00";
		INDICATOR_94.addMore	 = -0xD7;
		INDICATOR_94.type		 = 1;
		List_Indicators->push_back(INDICATOR_94);

		//-------- ON_PROCESS_SPELL_FUNC:($B)
		Indicators INDICATOR_95;
		INDICATOR_95.exportName  = "ON_PROCESS_SPELL_FUNC";
		INDICATOR_95.indicator	 = "6A 01 FF 12 5E B0 01 5F C2 04 00";
		INDICATOR_95.addMore	 = -0x49;
		INDICATOR_95.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_95);

		//-------- ON_CREATE_OBJ_FUNC:
		Indicators INDICATOR_96;
		INDICATOR_96.exportName  = "ON_CREATE_OBJ_FUNC";
		INDICATOR_96.indicator	 = "FF 74 24 10 C6 46 10 01";
		INDICATOR_96.addMore	 = 0x8;
		INDICATOR_96.type		 = 1;
		List_Indicators->push_back(INDICATOR_96);

		//-------- ON_DELETE_OBJ_FUNC:
		Indicators INDICATOR_97;
		INDICATOR_97.exportName  = "ON_DELETE_OBJ_FUNC";
		INDICATOR_97.indicator	 = "57 55 56 C6 44 24 1F 00";
		INDICATOR_97.addMore	 = -0x1C;
		INDICATOR_97.type		 = 1;
		List_Indicators->push_back(INDICATOR_97);
		
		//-------- ON_UPDATE_BUFF_FUNC:
		Indicators INDICATOR_98;
		INDICATOR_98.exportName  = "ON_UPDATE_BUFF_FUNC";
		INDICATOR_98.indicator	 = "83 C4 04 8B F8 6A 01 51";
		INDICATOR_98.addMore	 = 0x22;
		INDICATOR_98.type		 = 1;
		List_Indicators->push_back(INDICATOR_98);
	
		//-------- ON_REMOVE_ADD_BUFF_FUNC:($B)
		Indicators INDICATOR_99;
		INDICATOR_99.exportName  = "ON_REMOVE_ADD_BUFF_FUNC";
		INDICATOR_99.indicator	 = "56 57 BF 06 00 00 00 8B 03";
		INDICATOR_99.addMore	 = -0x4E;
		INDICATOR_99.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_99);
			
		//-------- ON_NEW_PATH_FUNC:($B)
		Indicators INDICATOR_100;
		INDICATOR_100.exportName = "ON_NEW_PATH_FUNC";
		INDICATOR_100.indicator	 = "8A 40 01 24 01 80 7C 24 3C 00";
		INDICATOR_100.addMore	 = -0xAF;
		INDICATOR_100.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_100);

	//-------- $D:
	Indicators INDICATOR_101;
	INDICATOR_101.type			 = 0;
	List_Indicators->push_back(INDICATOR_101);

		//-------- NAVMESH_CREATEPATH_FUNC:
		Indicators INDICATOR_102;
		INDICATOR_102.exportName = "NAVMESH_CREATEPATH_FUNC";
		INDICATOR_102.indicator	 = "50 B8 10 27 00 00 0F 44 C1";
		INDICATOR_102.addMore	 = 0x31;
		INDICATOR_102.type		 = 1;
		List_Indicators->push_back(INDICATOR_102);

		//-------- NAVMESH_SMOOTHPATH_FUNC:($B)
		Indicators INDICATOR_103;
		INDICATOR_103.exportName = "NAVMESH_SMOOTHPATH_FUNC";
		INDICATOR_103.indicator	 = "6A 05 51 C7 04 24 00 40 1C 45";
		INDICATOR_103.addMore	 = -0x6D;
		INDICATOR_103.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_103);
		
	//-------- $D:
	Indicators INDICATOR_104;
	INDICATOR_104.type			 = 0;
	List_Indicators->push_back(INDICATOR_104);
		
		//-------- GET_OBJ_BY_NET_ID:
		Indicators INDICATOR_105;
		INDICATOR_105.exportName = "GET_OBJ_BY_NET_ID";
		INDICATOR_105.indicator	 = "6A 01 51 0F B6 4C 24 20";
		INDICATOR_105.addMore	 = -0x10;
		INDICATOR_105.type		 = 1;
		List_Indicators->push_back(INDICATOR_105);
		
		//-------- BASE_OBJ_BY_ID:
		Indicators INDICATOR_106;
		INDICATOR_106.exportName = "BASE_OBJ_BY_ID";
		INDICATOR_106.indicator	 = "FE C1 80 F9 05 72 E4";
		INDICATOR_106.addMore	 = -0xC6;
		INDICATOR_106.type		 = 1;
		List_Indicators->push_back(INDICATOR_106);
		
		//-------- GET_OBJ_BY_ID:
		Indicators INDICATOR_107;
		INDICATOR_107.exportName = "GET_OBJ_BY_ID";
		INDICATOR_107.indicator	 = "FE C1 80 F9 05 72 E4";
		INDICATOR_107.addMore	 = -0xBB;
		INDICATOR_107.type		 = 1;
		List_Indicators->push_back(INDICATOR_107);
	
	//-------- $D:
	Indicators INDICATOR_108;
	INDICATOR_108.type			 = 0;
	List_Indicators->push_back(INDICATOR_108);
		
		//-------- GET_BOUND_RADIUS_FUNC:($B)
		Indicators INDICATOR_109;
		INDICATOR_109.exportName = "GET_BOUND_RADIUS_FUNC";
		INDICATOR_109.indicator	 = "D8 4C 24 08 5E 83 C4 08";
		INDICATOR_109.addMore	 = -0x40;
		INDICATOR_109.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_109);
		
	//-------- $D:
	Indicators INDICATOR_110;
	INDICATOR_110.type			 = 0;
	List_Indicators->push_back(INDICATOR_110);

		//-------- Offset__pBuffs:
		Indicators INDICATOR_111;
		INDICATOR_111.exportName = "Offset__pBuffs";
		INDICATOR_111.indicator	 = "89 74 24 10 FF 50 64 8B D8 33 FF";
		INDICATOR_111.addMore	 = 0x11;
		INDICATOR_111.type		 = 1;
		List_Indicators->push_back(INDICATOR_111);
		
		//-------- Offset__pMax_Buffs:
		Indicators INDICATOR_112;
		INDICATOR_112.exportName = "Offset__pMax_Buffs";
		INDICATOR_112.indicator	 = "89 74 24 10 FF 50 64 8B D8 33 FF";
		INDICATOR_112.addMore	 = 0xB;
		INDICATOR_112.type		 = 1;
		List_Indicators->push_back(INDICATOR_112);

		//-------- Offset__pMOVE:
		Indicators INDICATOR_113;
		INDICATOR_113.exportName = "Offset__pMOVE";
		INDICATOR_113.indicator	 = "80 F9 02 74 05 80 F9 06";
		INDICATOR_113.addMore	 = 0xBA;
		INDICATOR_113.type		 = 1;
		List_Indicators->push_back(INDICATOR_113);
		
		//-------- Offset__pNormalAttack:
		Indicators INDICATOR_114;
		INDICATOR_114.exportName = "Offset__pNormalAttack";
		INDICATOR_114.indicator	 = "80 7C 24 0B 00 75 0C B8 01 00 00 00";
		INDICATOR_114.addMore	 = -0x113;
		INDICATOR_114.type		 = 1;
		List_Indicators->push_back(INDICATOR_114);
		
		//-------- Offset__Enemy_ID:
		Indicators INDICATOR_115;
		INDICATOR_115.exportName = "Offset__Enemy_ID";
		INDICATOR_115.indicator	 = "80 F9 02 74 05 80 F9 06";
		INDICATOR_115.addMore	 = -0x19;
		INDICATOR_115.type		 = 1;
		List_Indicators->push_back(INDICATOR_115);
		
		//-------- Offset__nBLOCK_MOVE:
		Indicators INDICATOR_116;
		INDICATOR_116.exportName = "Offset__nBLOCK_MOVE";
		INDICATOR_116.indicator	 = "8B 7C 24 0C 83 7F 44 01";
		INDICATOR_116.addMore	 = 0x1B;
		INDICATOR_116.type		 = 1;
		List_Indicators->push_back(INDICATOR_116);

		//-------- Offset__nBar_Soucre:
		Indicators INDICATOR_117;
		INDICATOR_117.exportName = "Offset__nBar_Soucre";
		INDICATOR_117.indicator	 = "50 C7 44 24 08 80 00 00 00";
		INDICATOR_117.addMore	 = 0x28;
		INDICATOR_117.type		 = 1;
		List_Indicators->push_back(INDICATOR_117);

	//-------- $D:
	Indicators INDICATOR_118;
	INDICATOR_118.type			 = 0;
	List_Indicators->push_back(INDICATOR_118);	

		//-------- EVENT_MOVE_TO_FUNC:($B)
		Indicators INDICATOR_119;
		INDICATOR_119.exportName = "EVENT_MOVE_TO_FUNC";
		INDICATOR_119.indicator	 = "FF 77 40 8B CE FF 77 3C 6A 00 6A 00 50";
		INDICATOR_119.addMore	 = -0x88;
		INDICATOR_119.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_119);
		
		//-------- RCLICK_MOVE_TO_FUNC:
		Indicators INDICATOR_120;
		INDICATOR_120.exportName = "RCLICK_MOVE_TO_FUNC";
		INDICATOR_120.indicator	 = "FF 77 40 8B CE FF 77 3C 6A 00 6A 00 50";
		INDICATOR_120.addMore	 = 0xD;
		INDICATOR_120.type		 = 1;
		List_Indicators->push_back(INDICATOR_120);
		
		//-------- MOVE_TO_FUNC:
		Indicators INDICATOR_121;
		INDICATOR_121.exportName = "MOVE_TO_FUNC";
		INDICATOR_121.indicator	 = "6A 01 6A 01 8D 44 24 0C 50";
		INDICATOR_121.addMore	 = 0x140;
		INDICATOR_121.type		 = 1;
		List_Indicators->push_back(INDICATOR_121);
		
		//-------- NORMAL_ATK_FUNC:($B)
		Indicators INDICATOR_122;
		INDICATOR_122.exportName = "NORMAL_ATK_FUNC";
		INDICATOR_122.indicator	 = "D0 8B CF F3 0F 10 80 BC 02 00 00 8B 07 F3";
		INDICATOR_122.addMore	 = -0x2EA;
		INDICATOR_122.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_122);

	//-------- $D:
	Indicators INDICATOR_123;
	INDICATOR_123.type			 = 0;
	List_Indicators->push_back(INDICATOR_123);	
		
		//-------- CAN_SEE_FUNC:($B)
		Indicators INDICATOR_124;
		INDICATOR_124.exportName = "CAN_SEE_FUNC";
		INDICATOR_124.indicator	 = "6A 01 8B 40 30 FF D0 84 C0 75 05";
		INDICATOR_124.addMore	 = -0x4D;
		INDICATOR_124.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_124);
			
							////-------- POS2CELL_FUNC:
							//Indicators INDICATOR_125;
							//INDICATOR_125.exportName = "POS2CELL_FUNC";
							//INDICATOR_125.indicator	 = "83 C4 0C 80 7D 74 00";
							//INDICATOR_125.addMore	 = 0x137;
							//INDICATOR_125.type		 = 1;
							//List_Indicators->push_back(INDICATOR_125);

	//-------- $F:
	Indicators INDICATOR_126;
	INDICATOR_126.exportName	 = "//-----------------------------------";
	INDICATOR_126.type			 = 3;
	List_Indicators->push_back(INDICATOR_126);	

		//-------- CAST_SPELL_XYZ_FUNC:
		Indicators INDICATOR_127;
		INDICATOR_127.exportName = "CAST_SPELL_XYZ_FUNC";
		INDICATOR_127.indicator	 = "FF 74 24 28 8B 4C 24 1C 8B F8";
		INDICATOR_127.addMore	 = 0x1E;
		INDICATOR_127.type		 = 1;
		List_Indicators->push_back(INDICATOR_127);
		
		//-------- OFF_THIS_CAST_SPELL_XYZ:
		Indicators INDICATOR_128;
		INDICATOR_128.exportName = "OFF_THIS_CAST_SPELL_XYZ";
		INDICATOR_128.indicator	 = "FF 74 24 28 8B 4C 24 1C 8B F8";
		INDICATOR_128.addMore	 = 0x14;
		INDICATOR_128.type		 = 1;
		List_Indicators->push_back(INDICATOR_128);
	
		//-------- RELEASE_SPELL_XYZ_FUNC:
		Indicators INDICATOR_129;
		INDICATOR_129.exportName = "RELEASE_SPELL_XYZ_FUNC";
		INDICATOR_129.indicator	 = "6A 01 8D 4C 24 14 51 50";
		INDICATOR_129.addMore	 = 0xF;
		INDICATOR_129.type		 = 1;
		List_Indicators->push_back(INDICATOR_129);

							////-------- CAN_CASTSPELL_FUNC:($B)
							//Indicators INDICATOR_130;
							//INDICATOR_130.exportName = "CAN_CASTSPELL_FUNC";
							//INDICATOR_130.indicator	 = "F6 C3 20 74 07 B9 02 00 00 00";
							//INDICATOR_130.addMore	 = -0xCF;
							//INDICATOR_130.type		 = 2;				//$B
							//List_Indicators->push_back(INDICATOR_130);

	//-------- $F:
	Indicators INDICATOR_131;
	INDICATOR_131.exportName	 = "//-----------------------CAN_CASTSPELL2_FUNC: 51 6A 03 8B C8 (+0x5) -OldNotFound";
	INDICATOR_131.type			 = 3;
	List_Indicators->push_back(INDICATOR_131);

		//-------- CAN_CASTSPELL2_FUNC:
		Indicators INDICATOR_132;
		INDICATOR_132.exportName = "CAN_CASTSPELL2_FUNC";
		INDICATOR_132.indicator	 = "C6 44 24 13 00 83 F8 FF 74 1B";	
		INDICATOR_132.addMore	 = 0x1C;
		INDICATOR_132.type		 = 1;
		List_Indicators->push_back(INDICATOR_132);
		
	//-------- $F:
	Indicators INDICATOR_133;
	INDICATOR_133.exportName	 = "//-----------------------------------";
	INDICATOR_133.type			 = 3;
	List_Indicators->push_back(INDICATOR_133);	
		
		//-------- HACK_R_VELKOZ_FUNC:
		Indicators INDICATOR_134;
		INDICATOR_134.exportName = "HACK_R_VELKOZ_FUNC";
		INDICATOR_134.indicator	 = "8B 45 24 8B 40 34 F3 0F 10 80 1C 03 00 00";
		INDICATOR_134.addMore	 = -0x5;
		INDICATOR_134.type		 = 1;
		List_Indicators->push_back(INDICATOR_134);

		//-------- LEVELUP_SPELL_1_FUNC:
		Indicators INDICATOR_135;
		INDICATOR_135.exportName = "LEVELUP_SPELL_1_FUNC";
		INDICATOR_135.indicator	 = "6A 03 85 C9 74 0A";
		INDICATOR_135.addMore	 = 0x6;
		INDICATOR_135.type		 = 1;
		List_Indicators->push_back(INDICATOR_135);
		
		//-------- LEVELUP_SPELL_2_FUNC:
		Indicators INDICATOR_136;
		INDICATOR_136.exportName = "LEVELUP_SPELL_2_FUNC";
		INDICATOR_136.indicator	 = "6A 03 85 C9 74 0A";
		INDICATOR_136.addMore	 = 0x19;
		INDICATOR_136.type		 = 1;
		List_Indicators->push_back(INDICATOR_136);
						
		//-------- BUY_ITEM_FUNC:
		Indicators INDICATOR_137;
		INDICATOR_137.exportName = "BUY_ITEM_FUNC";
		INDICATOR_137.indicator	 = "83 C4 04 C1 E8 06 A8 01";
		INDICATOR_137.addMore	 = -0x8C;
		INDICATOR_137.type		 = 1;
		List_Indicators->push_back(INDICATOR_137);
						
		//-------- OFF_THIS_BUY_ITEM:
		Indicators INDICATOR_138;
		INDICATOR_138.exportName = "OFF_THIS_BUY_ITEM";
		INDICATOR_138.indicator	 = "83 C4 04 C1 E8 06 A8 01";
		INDICATOR_138.addMore	 = -0x92;
		INDICATOR_138.type		 = 1;
		List_Indicators->push_back(INDICATOR_138);
				
		//-------- SELL_ITEM_FUNC:
		Indicators INDICATOR_139;
		INDICATOR_139.exportName = "SELL_ITEM_FUNC";
		INDICATOR_139.indicator	 = "83 C4 04 C1 E8 06 5F A8 01";
		INDICATOR_139.addMore	 = -0x2E;
		INDICATOR_139.type		 = 1;
		List_Indicators->push_back(INDICATOR_139);
	
		//-------- OFF_THIS_SELL_ITEM:
		Indicators INDICATOR_140;
		INDICATOR_140.exportName = "OFF_THIS_SELL_ITEM";
		INDICATOR_140.indicator	 = "83 C4 04 C1 E8 06 A8 01";
		INDICATOR_140.addMore	 = -0x92;
		INDICATOR_140.type		 = 1;
		List_Indicators->push_back(INDICATOR_140);
					

	//-------- $D:
	Indicators INDICATOR_141;
	INDICATOR_141.type			 = 0;
	List_Indicators->push_back(INDICATOR_141);
	
	//-------- $F:
	Indicators INDICATOR_142;
	INDICATOR_142.exportName	 = "//-------------------||----------------||-------------------|";
	INDICATOR_142.type			 = 3;
	List_Indicators->push_back(INDICATOR_142);
		
		//-------- NEXUS:
		Indicators INDICATOR_143;
		INDICATOR_143.exportName = "NEXUS";
		INDICATOR_143.indicator	 = "46 18 00 04 00 00 74 04";
		INDICATOR_143.addMore	 = 0x1E;
		INDICATOR_143.type		 = 1;
		List_Indicators->push_back(INDICATOR_143);
		
		//-------- INHIBITOR:
		Indicators INDICATOR_144;
		INDICATOR_144.exportName = "INHIBITOR";
		INDICATOR_144.indicator	 = "46 18 00 04 00 00 74 04";
		INDICATOR_144.addMore	 = 0x17;
		INDICATOR_144.type		 = 1;
		List_Indicators->push_back(INDICATOR_144);
		
	//---------------------//---------------------//---------------------
	//---------------------//---------------------//---------------------
	//---------------------//---------------------//---------------------

		//-------- BASE_DIRECTION:
		Indicators INDICATOR_24;
		INDICATOR_24.exportName  = "BASE_DIRECTION";
		INDICATOR_24.indicator	 = "83 C4 48 8B 00 6A 00 51 C7 04 24 00 00 FA 43";
		INDICATOR_24.addMore	 = -0xF5;
		INDICATOR_24.type		 = 1;
		List_Indicators->push_back(INDICATOR_24);
	
		//-------- GET_TEXTURE_GAME_FUNC:
		Indicators INDICATOR_27;
		INDICATOR_27.exportName  = "GET_TEXTURE_GAME_FUNC";
		INDICATOR_27.indicator	 = "8D 44 24 1C 6A 01 6A 00 57 50";
		INDICATOR_27.addMore	 = 0xA;
		INDICATOR_27.type		 = 1;
		List_Indicators->push_back(INDICATOR_27);

		//-------- GET_BAR_DETAIL_FUNC: ($B)
		Indicators INDICATOR_42;
		INDICATOR_42.exportName  = "GET_BAR_DETAIL_FUNC";
		INDICATOR_42.indicator	 = "85 F6 75 1A 6A 01 8B CB";
		INDICATOR_42.addMore	 = -0x12;
		INDICATOR_42.type		 = 2;			//$B
		List_Indicators->push_back(INDICATOR_42);
		
		//-------- CHAT_TO_PLAYER_FUNC:
		Indicators INDICATOR_60;
		INDICATOR_60.exportName  = "CHAT_TO_PLAYER_FUNC";
		INDICATOR_60.indicator	 = "0F B7 07 83 E8 65";
		INDICATOR_60.addMore	 = -0x24;
		INDICATOR_60.type		 = 1;
		List_Indicators->push_back(INDICATOR_60);
		
		//-------- POS2CELL_FUNC:
		Indicators INDICATOR_125;
		INDICATOR_125.exportName = "POS2CELL_FUNC";
		INDICATOR_125.indicator	 = "83 C4 0C 80 7D 74 00";
		INDICATOR_125.addMore	 = 0x137;
		INDICATOR_125.type		 = 1;
		List_Indicators->push_back(INDICATOR_125);

		//-------- CAN_CASTSPELL_FUNC:($B)
		Indicators INDICATOR_130;
		INDICATOR_130.exportName = "CAN_CASTSPELL_FUNC";
		INDICATOR_130.indicator	 = "F6 C3 20 74 07 B9 02 00 00 00";
		INDICATOR_130.addMore	 = -0xCF;
		INDICATOR_130.type		 = 2;				//$B
		List_Indicators->push_back(INDICATOR_130);
			
	
		


		
		
		////-------- GET_WPOS_BAR_FUNC:
		//Indicators INDICATOR_9999;
		//INDICATOR_9999.exportName   = "GET_WPOS_BAR_FUNC";
		//INDICATOR_9999.indicator	= "83 C4 04 8B F0 80 7B 7C 00";
		//INDICATOR_9999.addMore		= -0x67;
		//INDICATOR_9999.type			= 2;
		//List_Indicators->push_back(INDICATOR_9999);
		
	
	}
	//------ END.GAME ------/------/------/------
}