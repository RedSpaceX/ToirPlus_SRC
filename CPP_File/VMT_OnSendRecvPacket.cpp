#include "VMT_OnSendRecvPacket.h"
#include "VMTHooked.h"
#include <tlhelp32.h>

#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>


struct buff_data
{
	int temp_1[2];
	DWORD TypePack;
};

HANDLE logFile      = 0;

//bool __oMsg_2(const char * format, ...)
//{
//	AllocConsole();
//	char buffer[1000];
//
//	va_list argptr;
//	va_start(argptr, format);
//	vsprintf_s(buffer, format, argptr);
//	va_end(argptr);
//	strcat_s(buffer, "\n");
//
//	freopen("CONOUT$", "w", stdout);
//	std::cout << buffer ;
//
//	return true;
//}


extern OnSendRecvPacketAction* OSRP_HookedList;
//==================================================================================//
//---------------VMT-HOOKING NEW-ON-PROCESS-SPELL ----------------------------------//

typedef int (__thiscall *OnSendRecvPacket ) (DWORD); 
OnSendRecvPacket Org_OnSendRecvPacket = 0; 

//------------//-------------------//---------:

DWORD  _ECX_SRP  = 0;
DWORD  _arg1_srp = 0;
//---------------//-------------//-------:
void __declspec(naked) VMTHook_OnSendRecvPacket()
{
	__asm mov _ECX_SRP, ecx
		__asm
	{
		push eax
		mov eax, dword ptr [esp + 8]
		mov _arg1_srp, eax
		pop eax 
	} 

	__asm pushad 
	//__asm pushfd

		if(_arg1_srp)
		{
			if (OSRP_HookedList) 
			{
				OSRP_HookedList->OSRP_Called(_arg1_srp);
			}

			if (*(BYTE*) (_arg1_srp + 0x8 +3) == 5)
			{
				buff_data* accc = (buff_data*)_arg1_srp;
				accc->TypePack  = 0x2000000;
			}

			if (*(BYTE*) (_arg1_srp + 0x8 +3) == 5)
			{
				if (logFile)
				{
					char buffer[500] = {0};
					sprintf_s(buffer, "Time: %f, ------ WTFFFFFFF ------- \n", GetTimeGame());
					DWORD dwBytesWritten = 0;
					//string logme = buffer;
					WriteFile(logFile, buffer, 499, &dwBytesWritten, NULL);
				}
			}
			
		}

	//__asm popfd
	__asm popad
	__asm
	{
		push _arg1_srp
		mov ecx, _ECX_SRP
		call Org_OnSendRecvPacket
		retn 0x4
	} 
}



//---------------------------------------------------------------------------------//
struct vmt_osrp
{
	int	  temp[7];
	DWORD funtion;
};

//---------------------------------------------------------------------------------//
PDWORD pdwOldVMT_OnSendRecvPacket = 0;
PDWORD pdwNewVMT_OnSendRecvPacket = 0;
bool   add1Lan_OSRP = true;	
//---------------------------------------------------------------------------------//
void Detour_VMT_OnSendRecvPacket()
{
	if (OSRP_HookedList && add1Lan_OSRP == true)
	{
		if (!logFile) {
			wstring filepathBase = L"I:\\__PHACH\\______TEST_CHOI_CHOI\\PacketLoggVIP.h";	//I:\__PHACH\______TEST_CHOI_CHOI\CHECK_PACKET\Release
			logFile = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		}

		//if (ListProcessModules_x(GetCurrentProcessId()))
		{
			add1Lan_OSRP = false;
			OSRP_HookedList->Add(xxxx);
			//return;
		}
	}

	if (OSRP_HookedList && Org_OnSendRecvPacket == 0)
	{
		DWORD hModule = (DWORD)MyGetModuleHandle(sz__League_of_Legends_exe);
		if (!hModule) return;

		DWORD temp1 = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule;

		DWORD temp2 = *(DWORD*)temp1;
		if (!temp2) return;

		DWORD temp3 = temp2 + 0x54;
		DWORD v4    = *(DWORD*)temp3;
		if (!v4) return;

		DWORD v6 = *(DWORD*)(v4 + 0x1D0);
		if ( !v6 )
			v6 = v4 + 0x1C4;
		
		DWORD temp5 = *(DWORD*)v6;
		if (!temp5) return;

		DWORD temp6 = *(DWORD*)(temp5 + 0x1C);
		if (!temp6) return;

		Org_OnSendRecvPacket = (OnSendRecvPacket)temp6;
		
		
		if (SwapVMT ((PDWORD*)v6, pdwOldVMT_OnSendRecvPacket, pdwNewVMT_OnSendRecvPacket))
		{
			HookVMTFuncion ((PDWORD*)v6, (DWORD) VMTHook_OnSendRecvPacket, 7); 
		}
		

		///*vmt_osrp* _vmt = (vmt_osrp*)temp5;
		//__oMsg_2("Org_OnSendRecvPacket = %x, _vmt = %x, v6 = %x, _vmt->funtion: %x", Org_OnSendRecvPacket, _vmt, v6, _vmt->funtion);
		//if (_vmt)
		//{
		//	DWORD FUNC    = (DWORD)VMTHook_OnSendRecvPacket;
		//	__oMsg_2("FUNC1 = %x", FUNC);
		//	_vmt->funtion = FUNC;
		//	__oMsg_2("FUNC2 = %x", FUNC);
		//}

		//__oMsg_2("Org_OnSendRecvPacket = %x, _vmt = %x, v6 = %x, _vmt->funtion: %x", Org_OnSendRecvPacket, _vmt, v6, _vmt->funtion);*/
	}
}

//==================================================================================//
void Retour_VMT_OnSendRecvPacket()
{
	if (logFile)
		CloseHandle(logFile);

	if (pdwOldVMT_OnSendRecvPacket) 
	{
		DWORD hModule = (DWORD)MyGetModuleHandle(sz__League_of_Legends_exe);
		if (!hModule) return;

		DWORD temp1 = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule;

		DWORD temp2 = *(DWORD*)temp1;
		if (!temp2) return;

		DWORD temp3 = temp2 + 0x54;
		DWORD v4    = *(DWORD*)temp3;
		if (!v4) return;

		DWORD v6 = *(DWORD*)(v4 + 0x1D0);
		if ( !v6 )
			v6 = v4 + 0x1C4;

		SwapVMT_Back((PDWORD*)v6, pdwOldVMT_OnSendRecvPacket);
	}
}

//---------------------------------------------------------------------------------//
struct List_Modules
{
	char  modName[36];
	DWORD modBaseAddr;
	DWORD modBaseSize;
	DWORD modEndCode;
};

std::vector<List_Modules>* listModule = 0;
//---------------------------------------------------------------------------------//
BOOL ListProcessModules_x( DWORD dwPID )
{
	if (listModule == 0)
	{
		listModule = new std::vector<List_Modules>;
	}

	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me32;

	// Take a snapshot of all modules in the specified process.
	hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
	if( hModuleSnap == INVALID_HANDLE_VALUE )
	{
		//__oMsg_2( "CreateToolhelp32Snapshot (of modules)" );
		return( FALSE );
	}

	// Set the size of the structure before using it.
	me32.dwSize = sizeof( MODULEENTRY32 );

	// Retrieve information about the first module,
	// and exit if unsuccessful
	if( !Module32First( hModuleSnap, &me32 ) )
	{
		//__oMsg_2( "Module32First" );  // show cause of failure
		CloseHandle( hModuleSnap );           // clean the snapshot object
		return( FALSE );
	}

	// Now walk the module list of the process,
	// and display information about each module
	do
	{
		//__oMsg_2( "\n========================================================");
		//__oMsg_2( "     MODULE NAME:     %s",	  me32.szModule );
		//__oMsg_2( "     Executable     = %s",	  me32.szExePath );
		//__oMsg_2( "     Process ID     = 0x%08X", me32.th32ProcessID );
		//__oMsg_2( "     Ref count (g)  = 0x%04X", me32.GlblcntUsage );
		//__oMsg_2( "     Ref count (p)  = 0x%04X", me32.ProccntUsage );
		//__oMsg_2( "     Base address   = 0x%08X", (DWORD) me32.modBaseAddr );
		//__oMsg_2( "     Base size      = %d",     me32.modBaseSize );

		List_Modules temp;

		sprintf_s(temp.modName, "%s", me32.szModule);
		temp.modBaseAddr = (DWORD)me32.modBaseAddr;
		temp.modBaseSize = me32.modBaseSize;
		temp.modEndCode  = (DWORD)me32.modBaseAddr + me32.modBaseSize;

		if (listModule) 
			listModule->push_back(temp);

	} while( Module32Next( hModuleSnap, &me32 ) );

	CloseHandle( hModuleSnap );
	return( TRUE );
}

//---------------------------------------------------------------------------------//
int sub_1DAC11DC(DWORD a1)
{
	if (listModule)
	{
		for (int i = 0; i < (int)listModule->size(); ++i)
		{
			//__oMsg_2("(%s) : %x - %x - %x", listModule->at(i).modName, listModule->at(i).modBaseAddr, listModule->at(i).modBaseSize, listModule->at(i).modEndCode);

			if ( a1 >= listModule->at(i).modBaseAddr && a1 <= listModule->at(i).modEndCode )         
				return i;
		}
	}
	return -1;
}

//---------------------------------------------------------------------------------//

void xxxx(DWORD buff)
{
	int   sOrR  = *(BYTE*) (buff + 0x8 +3);
	DWORD data  = *(DWORD*)(buff + 0x24);
	int   size1 = *(WORD*) (buff + 0x28);
	DWORD size2 = *(DWORD*)(buff + 0x28);
	int packetID = 0;
	if (data)
		packetID = *(WORD*) (data );

	if (sOrR == 5 /*&& size1 >= 0x320*/)
	{
		buff_data* accc = (buff_data*)buff;

		//__oMsg_2("Time: %f - packID: %x, typePack : %x - sOrR:%d, size: %x\n", GetTimeGame(), packetID, accc->TypePack, *(BYTE*) (buff + 0x8 +3), size1);

		if (logFile)
		{
			char buffer[500] = {0};
			sprintf_s(buffer, "Time: %f, packID: %x, typePack : %x - sOrR:%d, size: %x\n", GetTimeGame(), packetID, accc->TypePack, *(BYTE*) (buff + 0x8 +3), size1);
			DWORD dwBytesWritten = 0;
			string logme = buffer;
			WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
		}

		//buff_data* accc = (buff_data*)buff;
		//__oMsg_2("1-accc->TypePack: %x", accc->TypePack);
		accc->TypePack  = 0x2000000;
		//__oMsg_2("2-accc->TypePack: %x - %d", accc->TypePack, *(BYTE*) (buff + 0x8 +3));
	}
	
	////////--------------------------:
	//////if (packetID == 0x220)			// 2 - 0x0E - 0x220 : hinh nhu la server phat Gold
	//////{
	//////	//.......
	//////}
	//////else if (packetID == 0x201)		// 2 - 0x0A - 0x201 : server tra ve khi di chuyen,AA, CastSkill
	//////{
	//////	//.......
	//////}
	//////else if (packetID == 0x9B)		// 4 - 0x11 - 0x9B : kha' nghi ngo`
	//////{
	//////	//....... XXXXXXX.....
	//////}
	//////else if (packetID == 0x129)		// 1 - 0x1F - 0x129 : hinh nhu la update Npc gi do
	//////{
	//////	//.......
	//////}
	//////else if (packetID == 0x9)	{/*...*/}		// 3 - 0x23 - 0x9   : Send.Chat
	//////else if (packetID == 0xC0)	{/*...*/}		// 1 - 0x23 - 0xC0  : AA.Move
	//////else if (packetID == 0x185)					// 1 - 0x31 - 0x185 : Cast.Skill
	//////{
	//////	//DWORD a1 = buff;
	//////	//int   countRet = 0;
	//////	//int   v8 = 0;
	//////	//DWORD v1 = a1 + 4;
	//////	//do
	//////	//{
	//////	//	DWORD v2 = *(DWORD*)v1;

	//////	//	//__oMsg_2("v2: %x", v2);
	//////	//	//++v8;
	//////	//	//v1 += 4;
	//////	//	//continue;

	//////	//	int v3 = sub_1DAC11DC(v2);
	//////	//	if ( v3 < 0 || *(BYTE*)(v2 - 5) != 0xE8 )	{/*...*/}
	//////	//	else
	//////	//	{
	//////	//		//__oMsg_2("[%6x]: Return to %x from [call %x]", v1, v2, v2 + *(DWORD*)(v2 - 4));
	//////	//		countRet += 1;
	//////	//		__oMsg_2("	 [%d] [%6x]: Return to %x from [call %x] - G_Module= %x", countRet, v1, v2, v2 + *(DWORD*)(v2 - 4), G_Module);
	//////	//	}

	//////	//	++v8;
	//////	//	v1 += 4;
	//////	//}
	//////	//while ( v8 < 50 );
	//////	//__oMsg_2(" --------------------------------------------------------------------------------------\n\n");
	//////}
	//////else if (packetID == 0x1A3)	{/*...*/}		// 1 - 0x07 - 0x1a3 : Space
	//////else if (packetID == 0x53)	{/*...*/}		// 1 - 07,c - 0x1a3 : L.Click vao npc
	//////else if (packetID == 0x1A)	{/*...*/}		// 1 - xxxx - 0x1a  : Ping.lienlac
	//////else if (packetID == 0x22)	{/*...*/}		// 1 - xxxx - 0x22  : Cong.LvL.Skill
	//////else if (packetID == 0x13c)	{/*...*/}		// 1 - xxxx - 0x13c : xuat hien cai lolz gi day
	//////else if (packetID == 0x9F)	{/*...*/}		// 1 - xxxx - 0x9F  : click.Shop
	//////else if (packetID == 0x1ba)	{/*...*/}		// 1 - xxxx - 0x1ba : mua do shop
	//////else if (packetID == 0x6e)	{/*...*/}		// 1 - xxxx - 0x6e  : ban do shop
	//////else if (packetID == 0x178)	{/*...*/}		// 1 - xxxx - 0x178 : hoan.tac shop
	//////else if (packetID == 0x154)	{/*...*/}		// 1 - xxxx - 0x154 : ping.item
	//////else if (packetID == 0x192)	{/*...*/}		// 1 - xxxx - 0x192 : swap.item
	//////else if (packetID == 0x1e4)	{/*...*/}		// 1 - xxxx - 0x154 : ping.skill
	//////else if (packetID == 0x19e)	{/*...*/}		// 1 - xxxx - 0x154 : ping.Npc
	//////else
	//////{
	//////	////extern DWORD G_Module;
	//////	////
	//////	////
	//////	////if (logFile)
	//////	////{
	//////	////	char buffer[56] = {0};
	//////	////	sprintf_s(buffer, "TimeGame: %f - G_Module: %x\n", GetTimeGame(), G_Module);
	//////	////	DWORD dwBytesWritten = 0;
	//////	////	string logme = buffer;
	//////	////	WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////}
	//////	////__oMsg_2("TimeGame: %f - G_Module: %x", GetTimeGame(), G_Module);

	//////	////

	//////	////if (size1 < 0x10)
	//////	////{
	//////	////	if (logFile)
	//////	////	{
	//////	////		char buffer[128] = {0};
	//////	////		sprintf_s(buffer, "Type: %d, size:  %x -  %x, packetID: %x\n", sOrR, size1, size2, packetID);
	//////	////		DWORD dwBytesWritten = 0;
	//////	////		string logme = buffer;
	//////	////		WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////	}
	//////	////	__oMsg_2("Type: %d, size:  %x -  %x, packetID: %x", sOrR, size1, size2, packetID);
	//////	////}
	//////	////else 
	//////	////{
	//////	////	if (logFile)
	//////	////	{
	//////	////		char buffer[128] = {0};
	//////	////		sprintf_s(buffer, "Type: %d, size:  %x -  %x, packetID: %x\n", sOrR, size1, size2, packetID);
	//////	////		DWORD dwBytesWritten = 0;
	//////	////		string logme = buffer;
	//////	////		WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////	}
	//////	////	__oMsg_2("Type: %d, size: %x - %x, packetID: %x", sOrR, size1, size2, packetID);
	//////	////}

	//////	////DWORD a1 = buff;
	//////	////int   countRet = 0;
	//////	////int   v8 = 0;
	//////	////DWORD v1 = a1 + 4;
	//////	////do
	//////	////{
	//////	////	DWORD v2 = *(DWORD*)v1;
	//////	////	//int v3 = sub_1DAC11DC(v2);
	//////	////	//if ( v3 < 0 || *(BYTE*)(v2 - 5) != 0xE8 )	
	//////	////	{
	//////	////		//if ( (v2 & 0xFFFF0000) == 0x120000 )
	//////	////		//{
	//////	////		//	if (logFile)
	//////	////		//	{
	//////	////		//		char buffer[256] = {0};
	//////	////		//		sprintf_s(buffer, "	[%d] [%6x]: %10x  (st)==> %x\n", countRet, v1, v2, *(DWORD*)v2);
	//////	////		//		DWORD dwBytesWritten = 0;
	//////	////		//		string logme = buffer;
	//////	////		//		WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////		//	}
	//////	////		//	//__oMsg_2("	[%d] [%6x]: %10x  (st)==> %x", countRet, v1, v2, *(DWORD*)v2);
	//////	////		//}
	//////	////		//else
	//////	////		{
	//////	////			if (logFile)
	//////	////			{
	//////	////				char buffer[256] = {0};
	//////	////				sprintf_s(buffer, "	[%d] [%6x]: %10x  (%10x)\n", countRet, v1, v2, v2 - G_Module);
	//////	////				DWORD dwBytesWritten = 0;
	//////	////				string logme = buffer;
	//////	////				WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////			}
	//////	////			//__oMsg_2("	[%d] [%6x]: %10x %20d", countRet, v1, v2, v2);
	//////	////		}
	//////	////	}
	//////	////	//else
	//////	////	{
	//////	////		////countRet += 1;
	//////	////		////if (logFile)
	//////	////		////{
	//////	////		////	char buffer[256] = {0};
	//////	////		////	sprintf_s(buffer, "	[%d] [%6x]: Return to %x from [call %x](%s) - G_Module= %x  ->[%x - %x]\n", countRet, v1, v2, v2 + *(DWORD*)(v2 - 4), v3 >= 0 ? listModule->at(v3).modName : "NULLED: v3<0", G_Module, v2-G_Module, v2 + *(DWORD*)(v2 - 4) - G_Module);
	//////	////		////	DWORD dwBytesWritten = 0;
	//////	////		////	string logme = buffer;
	//////	////		////	WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////		////}
	//////	////		////__oMsg_2("	[%d] [%6x]: Return to %x from [call %x](%s) - G_Module= %x  ->[%x - %x]", countRet, v1, v2, v2 + *(DWORD*)(v2 - 4), v3 >= 0 ? listModule->at(v3).modName : "NULLED: v3<0", G_Module, v2-G_Module, v2-G_Module + *(DWORD*)(v2 - 4) );
	//////	////	}

	//////	////	++v8;
	//////	////	v1 += 4;
	//////	////}
	//////	////while ( v8 < 30 );

	//////	////if (logFile)
	//////	////{
	//////	////	char buffer[128] = {0};
	//////	////	sprintf_s(buffer, "--------------------------------------------------------------------------------------\n");
	//////	////	DWORD dwBytesWritten = 0;
	//////	////	string logme = buffer;
	//////	////	WriteFile(logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//////	////}
	//////	////__oMsg_2("--------------------------------------------------------------------------------------\n");
	//////}
	
}