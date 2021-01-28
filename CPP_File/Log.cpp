#include "Log.h"

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


//==================================================================================//
//==================================================================================//
//==================================================================================//

HANDLE vai_logFile = 0;	
bool   chi1lan = true;

//bool __oMsg(const char * format, ...)
//{
//	int LOG_TYPE = NO_LOGG__;			//<============ ************* QUAN TRONG ******************
//
//	//int LOG_TYPE = DEBUG_VIEW__;		//<============ ************* QUAN TRONG ******************
//	//int LOG_TYPE = CONSOLE__;			//<============ ************* QUAN TRONG ******************
//	//int LOG_TYPE = PRINT_FILE__;		//<============ ************* QUAN TRONG ******************
//
//	//-------------------------------------------------:
//	
//	if (LOG_TYPE == NO_LOGG__) return true;
//
//	else if (LOG_TYPE == DEBUG_VIEW__)
//	{
//			char buffer[1000];
//
//			va_list argptr;
//			va_start(argptr, format);
//			vsprintf_s(buffer, format, argptr);
//			va_end(argptr);
//
//			strcat_s(buffer, "\n");
//			//const wchar_t *wbuff = C2W(buffer); 
//			OutputDebugString(buffer);
//			//delete []wbuff;
//	}
//	else if (LOG_TYPE == CONSOLE__)		
//	{
//			AllocConsole();
//			char buffer[1000];
//
//			va_list argptr;
//			va_start(argptr, format);
//			vsprintf_s(buffer, format, argptr);
//			va_end(argptr);
//			//strcat_s(buffer, "\n");
//
//			freopen("CONOUT$", "w", stdout);
//			std::cout << buffer ;
//	}
//	else if (LOG_TYPE == PRINT_FILE__)
//	{
//		if (chi1lan == true)
//		{
//			if (!vai_logFile) 
//			{
//				char path_out[MAX_PATH]  = "";
//				get_path2(path_out);
//				//__oMsg("path_out: %s", path_out);
//
//				string strPath(path_out);
//				if (strlen(path_out) > 0) 
//				{
//					memset(path_out, 0, strlen(path_out));
//				}
//				strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
//
//				char f_name[MAX_PATH];
//				sprintf_s(f_name, "\\Logged_.txt");
//				strPath = strPath.append(f_name);
//				//__oMsg("strPath: %s", strPath.c_str());
//
//				wstring filepathBase = ConvertToWChar(strPath.c_str());
//				vai_logFile = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	
//			}
//			chi1lan = false;
//		}
//
//		//-----------------------------:
//		char buffer[1000] = {0};
//		va_list argptr;
//		va_start(argptr, format);
//		vsprintf_s(buffer, format, argptr);
//		va_end(argptr);
//		strcat_s(buffer, "\n");
//
//		if (vai_logFile)
//		{
//			DWORD dwBytesWritten = 0;
//			string logme = buffer;
//			WriteFile(vai_logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
//		}
//
//		//freopen("CONOUT$", "w", stdout);
//		//std::cout << buffer ;
//	}
//
//	return true;
//}

//==================================================================================//
bool __oMsg_PrintFile(const char * format, ...)
{
	//if (chi1lan == true)
	//{
	//	if (!vai_logFile) 
	//	{
	//		char path_out[MAX_PATH]  = "";
	//		get_path2(path_out);
	//		//__oMsg("path_out: %s", path_out);

	//		string strPath(path_out);
	//		if (strlen(path_out) > 0) 
	//		{
	//			memset(path_out, 0, strlen(path_out));
	//		}
	//		strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);

	//		char f_name[MAX_PATH];
	//		sprintf_s(f_name, "\\Logged_.txt");
	//		strPath = strPath.append(f_name);
	//		
	//		//__oMsg("strPath: %s", strPath.c_str());

	//		wstring filepathBase = ConvertToWChar(strPath.c_str());

	//		//wstring filepathBase = L"I:\\__PHACH\\______WORKING\\TOIRPLUS_WORKING\\Release\\PRINT_XXX.h";	//I:\__PHACH\______WORKING\TOIRPLUS_WORKING\Release
	//		vai_logFile = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	
	//	}
	//	chi1lan = false;
	//}
	//
	////-----------------------------:
	//char buffer[1000] = {0};
	//va_list argptr;
	//va_start(argptr, format);
	//vsprintf_s(buffer, format, argptr);
	//va_end(argptr);
	//strcat_s(buffer, "\n");
	//	
	//if (vai_logFile)
	//{
	//	DWORD dwBytesWritten = 0;
	//	string logme = buffer;
	//	WriteFile(vai_logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
	//}


	////freopen("CONOUT$", "w", stdout);
	////std::cout << buffer ;

	return true;
}

//==================================================================================//
bool __oMsg_Console(const char * format, ...)
{
	//AllocConsole();
	//char buffer[1000];

	//va_list argptr;
	//va_start(argptr, format);
	//vsprintf_s(buffer, format, argptr);
	//va_end(argptr);
	////strcat_s(buffer, "\n");

	//freopen("CONOUT$", "w", stdout);
	//std::cout << buffer ;

	return true;
}

//==================================================================================//
//bool IS_DEAD_TEST(KNpc* pNpc)
//{
//	if(!pNpc) return false;
//
//	DWORD v1 = (DWORD)pNpc;
//
//	int v21 = 0;
//	int v22 = *(BYTE*)(v1 + 0x54F);
//	DWORD v36 = *(BYTE *)(*(BYTE *)(v1 + 0x53D) + v1 + 0x53E);
//	if ( v22 )
//	{
//		DWORD v3 = v1 + 0x54E;
//		do
//		{
//			DWORD v23 = *(DWORD*)v3;
//			v3 += 4;
//			*(DWORD*)(&v36 + v21) ^= v23 ^ 0x6A6393FC;
//			++v21;
//		}
//		while ( v21 < v22 );
//	}
//	int v24 = *(BYTE*)(v1 + 0x550);
//	if ( v24 )
//	{
//		for ( int k = 1 - v24; k < 1; ++k )
//			*(DWORD*)((BYTE *)&v36 + k) ^= *(BYTE*)(v1 + k + 0x54E) ^ 0xFC;
//	}
//	
//	__oMsg("v36 = %x ---> %d", v36, (BYTE)v36);
//	return false;
//}

//==================================================================================//
//==================================================================================//
extern char* GetIPHost();
//extern void DoEndGame();
void TestTest()
{

//GENARATE();
//return;


	//__oMsg_2("---|not.found|=====================: %d", sizeof(Pattern));
	//GEN_CODE2(Pattern, 9);

	//for(int i = 0; i < (int)ModuleSize; i++)
	//{
	//	if(memcmp((void*)(ModuleBase + i), Pattern, PatternSize) == 0)
	//	{
	//		__oMsg_2("---| FOUND |=====================: %x", ModuleBase + i);
	//		return;
	//		//return ModuleBase + i;
	//	}
	//}
			
	

	

//return;

	//__oMsg_2("---||=====================");
	//LPCSTR SignatureVN = "\x6A\x01\x6A\x01\x8D\x44\x24\x0C";
	//LPCSTR Mask = "xxxxxxxx";
	
	//GEN_CODE("BASE",  SignatureVN,  Mask, 0x136, 3696 );

	//SignatureScanner SigScanner;
	//SigScanner.GetProcess("League of Legends.exe");
	//SigScanner.GetModule("League of Legends.exe");

	//AllocConsole();
	/*if (!AllocConsole())
		MessageBoxW(NULL, L"The console window was not created", NULL, MB_ICONEXCLAMATION);

	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	printf("Hello console on\n");
	std::cout.clear();
	std::cout << "Cout line one." << std::endl;
	cout << "Cout line two." << std::endl;
	MessageBoxW(NULL, (L"Pause to see console output."), (L"Pause Here"), MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
	fclose(fp);*/


	/*Logger _logger(L"OFF_SET");

	_logger.startLog();

	_logger.LogString("testString.1 : ", "ABC_XYZ_1");
	_logger.LogString("testString.2 : ", "ABC_XYZ_2");
	_logger.LogInt("testInt : ", 1233411);
	_logger.LogInt("testInt22 : ", 999911);

	_logger.stopLog();*/


	//__oMsg("Max: %f, min: %f", FLT_MAX, FLT_MIN);
	//stMOVE *destPos = (stMOVE *)GetPlayer()->_pMOVE;
	//KPos pDest = destPos->__strPosDest;
	//KPos start = GetPlayer()->CurrentPos;

	//Vec3D vStart = GetPlayer()->ServerPosition;
	////Vec3D dest(pDest.x, 0, pDest.z);
	//Vec3D dest(vStart.x + 1000, 0, vStart.z + 1000);
	//__oMsg("1: %x", GetPlayer()->ServerPosition);

	//KPathOutWayPoint* pathOutStruct = CreatPathWays(GetPlayer(), vStart, dest);
	//__oMsg("2: pathOutStruct :%x", pathOutStruct);
	//__oMsg("GetWaypoints_New: size:");
	//__oMsg("temp1: %x", pathOutStruct->nTemp1);
	//__oMsg("temp2: %x", pathOutStruct->nTemp2);
	//__oMsg("start: %f - %f", pathOutStruct->vStartPos.x, pathOutStruct->vStartPos.z);
	//__oMsg("End  : %f - %f", pathOutStruct->vEndPos.x, pathOutStruct->vEndPos.z);
	//__oMsg("waySt: %x", pathOutStruct->pWayPointStart);
	//__oMsg("wayEn: %x", pathOutStruct->pWayPointEnd);
	//__oMsg("wayME: %x", pathOutStruct->pWayPointMaxEnd);


	/*std::vector<Vec3D> result = GetWaypoints_Old(GetPlayer());
	__oMsg("GetWaypoints_Olde: size: %d \n", result.size());
	for (int i = 0; i < (int)result.size(); i++)
	{
		__oMsg("[%f - %f]", result[i].x, result[i].z);
	}*/

	/*PredictionInput input;
	__oMsg("Range: %f - PathLength: %f", input.Range, PathLength(result));
	__oMsg("Unit: %x", input.Unit);
	PredictionOutput out = GetPrediction(input, true, false);
	StoredPath* xxx = new StoredPath;
	__oMsg("------xxx.GetTime: %d", xxx->GetTime());
	__oMsg("out.Hitchance: %d", out.Hitchance);
	__oMsg("out._aoeTargetsHitCount: %d", out._aoeTargetsHitCount);
	__oMsg("out.x,z : %f-%f, [%f-%f]", out.GetCastPosition().x,out.GetCastPosition().z, GetPlayer()->ServerPosition.x, GetPlayer()->ServerPosition.z);*/


				//DoEndGame();
				//GameTEST();
				//GET_ITEM(123);
				//CalcDistance();

//PrintWithConditional(300);
//Test_misile();

				//KRenderer *pRender = GetRenderer();
				//__oMsg("%x", pRender);
				//KNpc *pPlayer = GetPlayer();
				//
				//D3DXVECTOR4* pPosOutIn = new D3DXVECTOR4;

				//pPosOutIn->x = pPlayer->CurrentPos.x;
				//pPosOutIn->y = pPlayer->CurrentPos.y;
				//pPosOutIn->z = pPlayer->CurrentPos.z;
				//pPosOutIn->w = 1.0;

				//__oMsg("TRUOC: %f - %f - %f -% f",pPosOutIn->x,pPosOutIn->y,pPosOutIn->z,pPosOutIn->w);
				//World2Screen(pPosOutIn);
				//__oMsg("SAU  : %f - %f - %f -% f",pPosOutIn->x,pPosOutIn->y,pPosOutIn->z,pPosOutIn->w);
				//D3DXVECTOR3* vScreen = new D3DXVECTOR3;
				//D3DXVECTOR3* pPosIn = new D3DXVECTOR3;

				//pPosIn->x = pPlayer->CurrentPos.x;
				//pPosIn->y = pPlayer->CurrentPos.y;
				//pPosIn->z = pPlayer->CurrentPos.z;
				//World2Screen_ViewPort(pPosIn, vScreen);
				//__oMsg("SAU2 : %f - %f - %f -% f",vScreen->x,vScreen->y,vScreen->z);

	//WorldToScreen_DangTest(pPosIn, vScreen);
	//__oMsg("SAU3 : %f - %f - %f -% f",vScreen->x,vScreen->y,vScreen->z);
	//Get_All_ObjectGame();
	//PRINT_SKILL();
	//KNpc *pPlayer = GetPlayer();
	//DO_SKILL_E_Darius((KNpc*)0x2eb034a8); // test cua ky cuc
	//DO_SKILL_ITEM(/*(KNpc*)0x37fc4010*/pPlayer, "S5_SummonerSmiteDuel");		//==> trung phat
	//CANCEL_SKILL(0);
	//GET_BUFF(pPlayer , "AlphaStrike");
	//__oMsg("test-test getbuff jinxqicon--------------%d", IS_CHATTING()); // bang chiu, khau 6 nong
	//__oMsg("test-test getbuff JinxQ--------------%x", GET_BUFF(pPlayer, "JinxQ")); // xuong ca, khau sung phong luu (co ton mana)
	//MOVE_TO(8589.,5694.);
	//KNpc *pPlayer = GetPlayer();
	//DO_FLASH(new KPos(pPlayer->CurrentPos.x + 1000, pPlayer->CurrentPos.y, pPlayer->CurrentPos.z + 1000));
	//PrintAllGameInfo(GetJungle());
	//char * txt = "<font color='#ece079'> [-autoLMHT.com-] : lien minh huyen thoai</font>";
	//char * txt = "<font color='#ebe215'> [-autoLMHT.com-] : lien minh huyen thoai</font>";
	//SEND_TEXT_SYSTEM(txt);
	//UnBlockMove();
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
VOID CalcDistance()
{
	/*DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = IS_DEAD(pEnemyPlayer) ? 1 : 0;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !IS_HERO(pEnemyPlayer))
			continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos.x, pPlayer->CurrentPos.z, pEnemyPlayer->CurrentPos.x, pEnemyPlayer->CurrentPos.z);
		__oMsg("TEN PLAYER - HERO: %s, %s, Distance: %f", pEnemyPlayer->GetNameNpc(), pEnemyPlayer->szName_Hero, fdistance);
	}*/
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void PrintWithConditional(float nRadius)
{
	////DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	////DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	////DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	////DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	////DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	////if (!dw1 || !dw2 ) return;
	////int nCount = (dw2 - dw1)/4;

	//////DWORD nTempBASE_BASE_ObjectAI = BASE_ObjectAI - TEMP_ENTRY_POINT + hModule;
	//////DWORD nTempBASE_BASE_ObjectAI_MAX = BASE_ObjectAI_MAX - TEMP_ENTRY_POINT + hModule;
	//////DWORD dw1_x = *(DWORD*)nTempBASE_BASE_ObjectAI;
	//////DWORD dw2_x = *(DWORD*)nTempBASE_BASE_ObjectAI_MAX;
	//////int nCount_x = (dw2_x - dw1_x)/4;
	//////__oMsg("nCount: %d - nCount_x: %d",nCount,nCount_x);
	////KNpc *pPlayer = GetPlayer();
	////for (int i = 0; i < nCount; ++i)
	////{
	////	DWORD dw3 = *(DWORD*)(dw1 + 4*i);
	////	if (dw3 == 0) continue;
	////	KNpc *pNpc = (KNpc*)dw3;

	////	//if(pNpc != GetPlayer()) continue;
	////	float nDistance = Distance_3D(pPlayer->CurrentPos.x, pPlayer->CurrentPos.y, pPlayer->CurrentPos.z, pNpc->CurrentPos.x, pNpc->CurrentPos.y, pNpc->CurrentPos.z);
	////	if (nDistance > nRadius) continue;
	////	
	////	//PrintAllGameInfo(pNpc);
	////	//PrintAllGameInfo_222(pNpc);
	////	//float TIMEGAME = GetTimeGame();
	////	//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pNpc->_pNormalAttack;
	////	//if (_stNORMAL_ATTACK == NULL) return;
	////	//float nTimeCoolDown = _stNORMAL_ATTACK->nCooldownExpires;
	////	//float nDelta = nTimeCoolDown - TIMEGAME;
	////	//__oMsg("--xxxx--XXXX-delta: [%x] - %x - %x - %f", pNpc, pNpc->_pNormalAttack, &_stNORMAL_ATTACK->nCooldownExpires, nDelta);
	////	//__oMsg("-----------------------------------  ------");
	////}
}

//==================================================================================//
void PrintAllGameInfo_222(KNpc *pNpc)
{
//////	//////Logger _logger(L"OFF_SET");
//////	//////_logger.startLog();
//////
//////	////////_logger.LogString("testString.1 : ", "ABC_XYZ_1");
//////	////////_logger.LogString("testString.2 : ", "ABC_XYZ_2");
//////	//////_logger.LogAll("IS_DEAD: %d ", IS_DEAD(GetPlayer()));
//////	//////_logger.LogAll("IS_MOVE_NEW: %d ", IsMoving(GetPlayer()));
//////	//////_logger.LogAll("IS_ON_SCREEN: %d ", IS_CAN_SEE(GetPlayer()));
//////	//////_logger.LogAll("nIndex: %x ", kGetPlayer->nIndex);
//////	//////_logger.LogAll("[%x - %x] nIs_Nexus                = %x", &kGetPlayer->nIs_Nexus, (DWORD)&kGetPlayer->nIs_Nexus - (DWORD)kGetPlayer, kGetPlayer->nIs_Nexus);
//////	//////_logger.LogAll("[%x - %x] nID                      = %x", &kGetPlayer->nID, (DWORD)&kGetPlayer->nID - (DWORD)kGetPlayer, kGetPlayer->nID);
//////	//////_logger.LogAll("[%x - %x] nTeam_ID                 = %x", &kGetPlayer->nTeam_ID, (DWORD)&kGetPlayer->nTeam_ID - (DWORD)kGetPlayer, kGetPlayer->nTeam_ID);
//////	//////_logger.LogAll("[%x - %x] nType_1                  = %x", &kGetPlayer->nType_1, (DWORD)&kGetPlayer->nType_1 - (DWORD)kGetPlayer, kGetPlayer->nType_1);
//////
//////	//////_logger.LogAll("[%x - %x] szPlayerName             = %s", &kGetPlayer->szPlayerName, (DWORD)&kGetPlayer->szPlayerName - (DWORD)kGetPlayer, kGetPlayer->GetNameNpc());
//////	//////_logger.LogAll("[%x - %x] nLen_Name                = %d", &kGetPlayer->nLen_Name, (DWORD)&kGetPlayer->nLen_Name - (DWORD)kGetPlayer, kGetPlayer->nLen_Name);
//////	//////_logger.LogAll("[%x - %x] nMaxlen_Name             = %d", &kGetPlayer->nMaxlen_Name, (DWORD)&kGetPlayer->nMaxlen_Name - (DWORD)kGetPlayer, kGetPlayer->nMaxlen_Name);
//////	//////_logger.LogAll("[%x - %x] nIndex                   = %x", &kGetPlayer->nIndex, (DWORD)&kGetPlayer->nIndex - (DWORD)kGetPlayer, kGetPlayer->nIndex);
//////	//////_logger.LogAll("[%x - %x] BBoxMinPos               = %f, %f, %f", &kGetPlayer->BBoxMin.x, (DWORD)&kGetPlayer->BBoxMin.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMin.x, kGetPlayer->BBoxMin.y, kGetPlayer->BBoxMin.z);
//////	//////_logger.LogAll("[%x - %x] BBoxMaxPos               = %f, %f, %f", &kGetPlayer->BBoxMax.x, (DWORD)&kGetPlayer->BBoxMax.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMax.x, kGetPlayer->BBoxMax.y, kGetPlayer->BBoxMax.z);
//////	//////_logger.stopLog();
//////	//////SEND_TEXT_SYSTEM("----STOP-LOG-FILE----");
//////
//////	if (pNpc == NULL)
//////	{
//////		__oMsg_2("NPC bi null");
//////		return;
//////	}
//////	KNpc *kGetPlayer = pNpc;
//////
//////
//////	//*********************////***********
//////	__oMsg_2("IS_DEAD: %d - IS_MOVE_NEW: %d - IS_ON_SCREEN: %d", IS_DEAD(GetPlayer()), IsMoving(GetPlayer()), IS_CAN_SEE(GetPlayer()));
//////	__oMsg_2("TIME_GAME_NEW  = %f", GetTimeGame());
////////return;
////////========= THONG TIN pPLAYER ==================================================================================================
//////	__oMsg_2("======================= pPLAYER : ==========================");
//////	__oMsg_2("[%x]", kGetPlayer);
//////
////////return;
////////	__oMsg_2("[%x - %d]Name = %s - isHero: %d", kGetPlayer, kGetPlayer, kGetPlayer->GetNameNpc(), IS_HERO(kGetPlayer));
//////
//////	__oMsg_2("isTurret    :  %d", IS_TURRET(kGetPlayer));
//////	__oMsg_2("IsChampion  :  %d", IS_HERO(kGetPlayer));
//////	__oMsg_2("IsMinion    :  %d", IS_MINION(kGetPlayer));
//////	__oMsg_2("IsNexus     :  %d", IS_NEXUS(kGetPlayer));
//////	__oMsg_2("IsInhibitor :  %d", IS_INHIBITOR(kGetPlayer));
//////	__oMsg_2("\n");
////////return;
//////	__oMsg_2("[%x - %x] nIs_Nexus                = %x", &kGetPlayer->nIs_Nexus_KODUNGNUA, (DWORD)&kGetPlayer->nIs_Nexus_KODUNGNUA - (DWORD)kGetPlayer, kGetPlayer->nIs_Nexus_KODUNGNUA);
//////	__oMsg_2("[%x - %x] nID                      = %x", &kGetPlayer->nID, (DWORD)&kGetPlayer->nID - (DWORD)kGetPlayer, kGetPlayer->nID);
//////	__oMsg_2("[%x - %x] nTeam_ID                 = %x", &kGetPlayer->nTeam_ID, (DWORD)&kGetPlayer->nTeam_ID - (DWORD)kGetPlayer, kGetPlayer->nTeam_ID);
//////	__oMsg_2("[%x - %x] nType_1                  = %x", &kGetPlayer->nType_1_KODUNGNUA, (DWORD)&kGetPlayer->nType_1_KODUNGNUA - (DWORD)kGetPlayer, kGetPlayer->nType_1_KODUNGNUA);
////////return;
//////	__oMsg_2("[%x - %x] szPlayerName             = %s", &kGetPlayer->szPlayerName, (DWORD)&kGetPlayer->szPlayerName - (DWORD)kGetPlayer, kGetPlayer->GetNameNpc());
//////	__oMsg_2("[%x - %x] nLen_Name                = %d", &kGetPlayer->nLen_Name, (DWORD)&kGetPlayer->nLen_Name - (DWORD)kGetPlayer, kGetPlayer->nLen_Name);
//////	__oMsg_2("[%x - %x] nMaxlen_Name             = %d", &kGetPlayer->nMaxlen_Name, (DWORD)&kGetPlayer->nMaxlen_Name - (DWORD)kGetPlayer, kGetPlayer->nMaxlen_Name);
//////	__oMsg_2("[%x - %x] nIndex                   = %x", &kGetPlayer->nIndex, (DWORD)&kGetPlayer->nIndex - (DWORD)kGetPlayer, kGetPlayer->nIndex);
//////	__oMsg_2("[%x - %x] BBoxMinPos               = %f, %f, %f", &kGetPlayer->BBoxMin.x, (DWORD)&kGetPlayer->BBoxMin.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMin.x, kGetPlayer->BBoxMin.y, kGetPlayer->BBoxMin.z);
//////	__oMsg_2("[%x - %x] BBoxMaxPos               = %f, %f, %f", &kGetPlayer->BBoxMax.x, (DWORD)&kGetPlayer->BBoxMax.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMax.x, kGetPlayer->BBoxMax.y, kGetPlayer->BBoxMax.z);
////////return;
//////	__oMsg_2("[%x - %x] nDeleted(tim:OnDeleteObj)= %d", &kGetPlayer->nDeleted, (DWORD)&kGetPlayer->nDeleted - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nDeleted);
//////	__oMsg_2("[%x - %x] nCanSee                  = %d", &kGetPlayer->nCanSee_KODUNGNUA, (DWORD)&kGetPlayer->nCanSee_KODUNGNUA - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nCanSee_KODUNGNUA);
//////	__oMsg_2("[%x - %x] CurrentPos(server)       = %f, %f, %f", &kGetPlayer->ServerPosition.x, (DWORD)&kGetPlayer->ServerPosition.x - (DWORD)kGetPlayer, kGetPlayer->ServerPosition.x, kGetPlayer->ServerPosition.y, kGetPlayer->ServerPosition.z);
//////	__oMsg_2("[%x - %x] nIsDie                   = %d", &kGetPlayer->nIsDie_KODUNGNUA, (DWORD)&kGetPlayer->nIsDie_KODUNGNUA - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsDie_KODUNGNUA);
//////	__oMsg_2("[%x - %x] CurrentPos               = %f, %f, %f", &kGetPlayer->CurrentPos.x, (DWORD)&kGetPlayer->CurrentPos.x - (DWORD)kGetPlayer, kGetPlayer->CurrentPos.x, kGetPlayer->CurrentPos.y, kGetPlayer->CurrentPos.z);
//////	__oMsg_2("[%x - %x] nMissileData             = %x", &kGetPlayer->nMissileData, (DWORD)&kGetPlayer->nMissileData - (DWORD)kGetPlayer, kGetPlayer->nMissileData);
//////	__oMsg_2("[%x - %x] nMissileOwnerID_1        = %x", &kGetPlayer->nMissileOwnerID_1, (DWORD)&kGetPlayer->nMissileOwnerID_1 - (DWORD)kGetPlayer, kGetPlayer->nMissileOwnerID_1);
//////	__oMsg_2("[%x - %x] nMissileOwnerID_2        = %x", &kGetPlayer->nMissileOwnerID_2, (DWORD)&kGetPlayer->nMissileOwnerID_2 - (DWORD)kGetPlayer, kGetPlayer->nMissileOwnerID_2);
//////	//__oMsg_2("[%x - %x] nSpawnTime               = %f", &kGetPlayer->nSpawnTime, (DWORD)&kGetPlayer->nSpawnTime - (DWORD)kGetPlayer, kGetPlayer->nSpawnTime);
////////return;
//////	__oMsg_2("[%x - %x] nMP                      = %f", &kGetPlayer->nMP, (DWORD)&kGetPlayer->nMP - (DWORD)kGetPlayer, kGetPlayer->nMP);
//////	__oMsg_2("[%x - %x] nMaxMP                   = %f",& kGetPlayer->nMaxMP, (DWORD)&kGetPlayer->nMaxMP - (DWORD)kGetPlayer, kGetPlayer->nMaxMP);
//////	__oMsg_2("[%x - %x] nJhinMissile             = %f", &kGetPlayer->nJhinMissile, (DWORD)&kGetPlayer->nJhinMissile - (DWORD)kGetPlayer, kGetPlayer->nJhinMissile);
//////	__oMsg_2("[%x - %x] nIsInvulnerable          = %d", &kGetPlayer->nIsInvulnerable, (DWORD)&kGetPlayer->nIsInvulnerable - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsInvulnerable & 1);
//////	__oMsg_2("[%x - %x] nOverrideCollisionRadius = %f", &kGetPlayer->nOverrideCollisionRadius, (DWORD)&kGetPlayer->nOverrideCollisionRadius - (DWORD)kGetPlayer, kGetPlayer->nOverrideCollisionRadius);
//////	__oMsg_2("[%x - %x] nIsTargetable            = %d", &kGetPlayer->nIsTargetable, (DWORD)&kGetPlayer->nIsTargetable - (DWORD)kGetPlayer, kGetPlayer->nIsTargetable);
//////	__oMsg_2("[%x - %x] nIsTargetableToTeam      = %d", &kGetPlayer->nIsTargetableToTeam, (DWORD)&kGetPlayer->nIsTargetableToTeam - (DWORD)kGetPlayer, kGetPlayer->nIsTargetableToTeam);
//////	__oMsg_2("[%x - %x] nIsBasing                = %d", &kGetPlayer->nIsBasing, (DWORD)&kGetPlayer->nIsBasing - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsBasing);
//////	__oMsg_2("[%x - %x] nHP                      = %f", &kGetPlayer->nHP, (DWORD)&kGetPlayer->nHP - (DWORD)kGetPlayer, kGetPlayer->nHP);
//////	__oMsg_2("[%x - %x] nMaxHP                   = %f", &kGetPlayer->nMaxHP, (DWORD)&kGetPlayer->nMaxHP - (DWORD)kGetPlayer, kGetPlayer->nMaxHP);
////////return;
//////	__oMsg_2("[%x - %x] nGiapMau                 = %f", &kGetPlayer->nGiap_Mau, (DWORD)&kGetPlayer->nGiap_Mau - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau);
//////	__oMsg_2("[%x - %x] nGiap_Mau_Rengar         = %f", &kGetPlayer->nGiap_Mau_Rengar, (DWORD)&kGetPlayer->nGiap_Mau_Rengar - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau_Rengar);
//////	__oMsg_2("[%x - %x] nGiap_Mau_AP             = %f", &kGetPlayer->nGiap_Mau_AP, (DWORD)&kGetPlayer->nGiap_Mau_AP - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau_AP);
//////	__oMsg_2("[%x - %x] nModSkinID               = %d", &kGetPlayer->nModSkinID, (DWORD)&kGetPlayer->nModSkinID - (DWORD)kGetPlayer, kGetPlayer->nModSkinID);
//////	__oMsg_2("[%x - %x] nXyenPhep_Diem           = %f", &kGetPlayer->nXyenPhep_Diem, (DWORD)&kGetPlayer->nXyenPhep_Diem - (DWORD)kGetPlayer, kGetPlayer->nXyenPhep_Diem);
//////	__oMsg_2("[%x - %x] nXyenGiap_Diem           = %f", &kGetPlayer->nXyenGiap_Diem, (DWORD)&kGetPlayer->nXyenGiap_Diem - (DWORD)kGetPlayer, kGetPlayer->nXyenGiap_Diem);
////////return;
//////	__oMsg_2("[%x - %x] nFlat_PhysicalDamageMod  = %f", &kGetPlayer->nFlat_PhysicalDamageMod, (DWORD)&kGetPlayer->nFlat_PhysicalDamageMod - (DWORD)kGetPlayer, kGetPlayer->nFlat_PhysicalDamageMod);
//////	__oMsg_2("[%x - %x] nFlat_MagicDamageMod     = %f", &kGetPlayer->nFlat_MagicDamageMod, (DWORD)&kGetPlayer->nFlat_MagicDamageMod - (DWORD)kGetPlayer, kGetPlayer->nFlat_MagicDamageMod);
//////	__oMsg_2("[%x - %x] nPercent_MagicDamageMod  = %f", &kGetPlayer->nPercent_MagicDamageMod, (DWORD)&kGetPlayer->nPercent_MagicDamageMod - (DWORD)kGetPlayer, kGetPlayer->nPercent_MagicDamageMod);
//////	__oMsg_2("[%x - %x] nAttackSpeedMod          = %f", &kGetPlayer->nAttackSpeedMod, (DWORD)&kGetPlayer->nAttackSpeedMod - (DWORD)kGetPlayer, kGetPlayer->nAttackSpeedMod);
//////	__oMsg_2("[%x - %x] nBaseAttackDamage        = %f", &kGetPlayer->nBaseAttackDamage, (DWORD)&kGetPlayer->nBaseAttackDamage - (DWORD)kGetPlayer, kGetPlayer->nBaseAttackDamage);
//////	__oMsg_2("[%x - %x] nCritChance              = %f", &kGetPlayer->nCritChance, (DWORD)&kGetPlayer->nCritChance - (DWORD)kGetPlayer, kGetPlayer->nCritChance);
//////	__oMsg_2("[%x - %x] nArmor                   = %f", &kGetPlayer->nArmor, (DWORD)&kGetPlayer->nArmor - (DWORD)kGetPlayer, kGetPlayer->nArmor);
//////	__oMsg_2("[%x - %x] nArmor_CongThem          = %f", &kGetPlayer->nArmor_CongThem, (DWORD)&kGetPlayer->nArmor_CongThem - (DWORD)kGetPlayer, kGetPlayer->nArmor_CongThem);
//////	__oMsg_2("[%x - %x] nSpellBlock              = %f", &kGetPlayer->nSpellBlock, (DWORD)&kGetPlayer->nSpellBlock - (DWORD)kGetPlayer, kGetPlayer->nSpellBlock);
//////	__oMsg_2("[%x - %x] nSpellBlock_CongThem     = %f", &kGetPlayer->nSpellBlock_CongThem, (DWORD)&kGetPlayer->nSpellBlock_CongThem - (DWORD)kGetPlayer, kGetPlayer->nSpellBlock_CongThem);
//////	__oMsg_2("[%x - %x] nMoveSpeed               = %f", &kGetPlayer->nMoveSpeed, (DWORD)&kGetPlayer->nMoveSpeed - (DWORD)kGetPlayer, kGetPlayer->nMoveSpeed);
//////	__oMsg_2("[%x - %x] nAttackRange             = %f", &kGetPlayer->nAttackRange, (DWORD)&kGetPlayer->nAttackRange - (DWORD)kGetPlayer, kGetPlayer->nAttackRange);
////////return;	
//////	__oMsg_2("[%x - %x] nIsBot                   = %d", &kGetPlayer->nIsBot, (DWORD)&kGetPlayer->nIsBot - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsBot);
//////	__oMsg_2("[%x - %x] nHoiMauMoiGiay           = %f", &kGetPlayer->nHoiMauMoiGiay, (DWORD)&kGetPlayer->nHoiMauMoiGiay - (DWORD)kGetPlayer, kGetPlayer->nHoiMauMoiGiay);
//////	__oMsg_2("[%x - %x] nPet_ID_1                = %x", &kGetPlayer->nPet_ID_1, (DWORD)&kGetPlayer->nPet_ID_1 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_1);
//////	__oMsg_2("[%x - %x] nPet_ID_2                = %x", &kGetPlayer->nPet_ID_2, (DWORD)&kGetPlayer->nPet_ID_2 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_2);
//////	__oMsg_2("[%x - %x] nPet_ID_3                = %x", &kGetPlayer->nPet_ID_3, (DWORD)&kGetPlayer->nPet_ID_3 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_3);
//////	__oMsg_2("[%x - %x] nAI_LastPetSpawnedID     = %x", &kGetPlayer->nAI_LastPetSpawnedID, (DWORD)&kGetPlayer->nAI_LastPetSpawnedID - (DWORD)kGetPlayer, kGetPlayer->nAI_LastPetSpawnedID);
//////	__oMsg_2("[%x - %x] nGold                    = %f", &kGetPlayer->nGold, (DWORD)&kGetPlayer->nGold - (DWORD)kGetPlayer, kGetPlayer->nGold);
//////	__oMsg_2("[%x - %x] FacingPos               = %f, %f, %f", &kGetPlayer->facingPos.x, (DWORD)&kGetPlayer->facingPos.x - (DWORD)kGetPlayer, kGetPlayer->facingPos.x, kGetPlayer->facingPos.y, kGetPlayer->facingPos.z);
//////	__oMsg_2("[%x - %x] nCombatType              = %d", &kGetPlayer->nCombatType, (DWORD)&kGetPlayer->nCombatType - (DWORD)kGetPlayer, kGetPlayer->nCombatType);
//////	__oMsg_2("[%x - %x] DWORD pBuffs             = %x", &kGetPlayer->pBuffs, (DWORD)&kGetPlayer->pBuffs - (DWORD)kGetPlayer, kGetPlayer->pBuffs);
//////	__oMsg_2("[%x - %x] DWORD pMax_Buffs         = %x", &kGetPlayer->pMax_Buffs, (DWORD)&kGetPlayer->pMax_Buffs - (DWORD)kGetPlayer, kGetPlayer->pMax_Buffs);
////////return;
//////
//////	//__oMsg_2("[%x - %x] szName_Hero              = %s", &kGetPlayer->szName_Hero, (DWORD)&kGetPlayer->szName_Hero - (DWORD)kGetPlayer, kGetPlayer->GetNameHero());
//////	//__oMsg_2("[%x - %x] nLen_Name_Hero           = %d", &kGetPlayer->nLen_Name_Hero, (DWORD)&kGetPlayer->nLen_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nLen_Name_Hero);
//////	//__oMsg_2("[%x - %x] nMax_Len_Name_Hero       = %d", &kGetPlayer->nMax_Len_Name_Hero, (DWORD)&kGetPlayer->nMax_Len_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nMax_Len_Name_Hero);
//////	__oMsg_2("[%x - %x] DWORD _pMOVE             = %x", &kGetPlayer->_pMOVE_KODUNGNUA, (DWORD)&kGetPlayer->_pMOVE_KODUNGNUA - (DWORD)kGetPlayer, kGetPlayer->_pMOVE_KODUNGNUA);
//////	__oMsg_2("[%x - %x] int _pCastSpellBook      = %x", &kGetPlayer->_pCastSpellBook, (DWORD)&kGetPlayer->_pCastSpellBook - (DWORD)kGetPlayer, kGetPlayer->_pCastSpellBook);
//////	__oMsg_2("[%x - %x] DWORD *_pCastSpell       = %x", &kGetPlayer->_pCastSpell, (DWORD)&kGetPlayer->_pCastSpell - (DWORD)kGetPlayer, kGetPlayer->_pCastSpell);
//////	__oMsg_2("[%x - %x] nIsCastingSpell          = %d", &kGetPlayer->nIsCastingSpell, (DWORD)&kGetPlayer->nIsCastingSpell - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsCastingSpell);
//////	//__oMsg_2("[%x - %x] DWORD _pNormalAttack     = %x", &kGetPlayer->_pNormalAttack, (DWORD)&kGetPlayer->_pNormalAttack - (DWORD)kGetPlayer, kGetPlayer->_pNormalAttack);
//////	__oMsg_2("[%x - %x] DWORD _pSkill[63][from canCast2] = %x  ", &kGetPlayer->_pSkill, (DWORD)&kGetPlayer->_pSkill - (DWORD)kGetPlayer, kGetPlayer->_pSkill);
//////	
//////	__oMsg_2("[%x - %x] szName_Hero              = %s", &kGetPlayer->szName_Hero, (DWORD)&kGetPlayer->szName_Hero - (DWORD)kGetPlayer, kGetPlayer->GetNameHero());
//////	__oMsg_2("[%x - %x] nLen_Name_Hero           = %d", &kGetPlayer->nLen_Name_Hero, (DWORD)&kGetPlayer->nLen_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nLen_Name_Hero);
//////	__oMsg_2("[%x - %x] nMax_Len_Name_Hero       = %d", &kGetPlayer->nMax_Len_Name_Hero, (DWORD)&kGetPlayer->nMax_Len_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nMax_Len_Name_Hero);
////////return;
//////
//////	__oMsg_2("[%x - %x] nEnemy_ID                = %x", &kGetPlayer->nEnemy_ID, (DWORD)&kGetPlayer->nEnemy_ID - (DWORD)kGetPlayer, kGetPlayer->nEnemy_ID);
//////	__oMsg_2("[%x - %x] nBLOCK_MOVE              = %x", &kGetPlayer->nBLOCK_MOVE, (DWORD)&kGetPlayer->nBLOCK_MOVE - (DWORD)kGetPlayer, kGetPlayer->nBLOCK_MOVE);
//////	__oMsg_2("[%x - %x] nIsMinion                = %d", &kGetPlayer->nIsMinion, (DWORD)&kGetPlayer->nIsMinion - (DWORD)kGetPlayer, kGetPlayer->nIsMinion);
//////	__oMsg_2("[%x - %x] nMinion_Level            = %d", &kGetPlayer->nMinion_Level, (DWORD)&kGetPlayer->nMinion_Level - (DWORD)kGetPlayer, kGetPlayer->nMinion_Level);
//////	__oMsg_2("[%x - %x] nBar_Soucre              = %x", &kGetPlayer->nBar_Source_KODUNGNUA, (DWORD)&kGetPlayer->nBar_Source_KODUNGNUA - (DWORD)kGetPlayer, kGetPlayer->nBar_Source_KODUNGNUA);
//////	//__oMsg_2("[%x - %x] nCooldownExpiresBA       = %f", &kGetPlayer->nCooldownExpiresBA, (DWORD)&kGetPlayer->nCooldownExpiresBA - (DWORD)kGetPlayer, kGetPlayer->nCooldownExpiresBA);
//////	__oMsg_2("[%x - %x] DWORD _pNormalAttack     = %x", &kGetPlayer->_pNormalAttack, (DWORD)&kGetPlayer->_pNormalAttack - (DWORD)kGetPlayer, kGetPlayer->_pNormalAttack);
//////	__oMsg_2("[%x - %x] nIsMove                  = %d", &kGetPlayer->nIsMove_KODUNGNUA, (DWORD)&kGetPlayer->nIsMove_KODUNGNUA - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsMove_KODUNGNUA);
//////
//////	__oMsg_2("[%x - %x] nIS_MOVE_1               = %d", &kGetPlayer->nIS_MOVE_1, (DWORD)&kGetPlayer->nIS_MOVE_1 - (DWORD)kGetPlayer, kGetPlayer->nIS_MOVE_1);
//////	__oMsg_2("[%x - %x] nIS_MOVE_2               = %d", &kGetPlayer->nIS_MOVE_2, (DWORD)&kGetPlayer->nIS_MOVE_2 - (DWORD)kGetPlayer, kGetPlayer->nIS_MOVE_2);
//////	__oMsg_2("====> IS_MOVE_NEW				   = %d", (kGetPlayer->nIS_MOVE_1 == 0) & (kGetPlayer->nIS_MOVE_2 != 0));
//////
//////	__oMsg_2("[%x - %x] nLevel                   = %d", &kGetPlayer->nLevel, (DWORD)&kGetPlayer->nLevel - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nLevel);
//////	__oMsg_2("[%x - %x] nRemainingPoint          = %d", &kGetPlayer->nRemainingPoint, (DWORD)&kGetPlayer->nRemainingPoint - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nRemainingPoint);
//////	
//////	__oMsg_2("[%x - %x] DWORD _pItem[0]]         = %x", &kGetPlayer->_pItem, (DWORD)&kGetPlayer->_pItem - (DWORD)kGetPlayer, kGetPlayer->_pItem);
//////
//////	
////////return;
//////
//////	__oMsg_2("isTurret    :  %d", IS_TURRET(kGetPlayer));
//////	__oMsg_2("IsChampion  :  %d", IS_HERO(kGetPlayer));
//////	__oMsg_2("IsMinion    :  %d", IS_MINION(kGetPlayer));
//////	__oMsg_2("IsNexus     :  %d", IS_NEXUS(kGetPlayer));
//////	__oMsg_2("IsInhibitor :  %d", IS_INHIBITOR(kGetPlayer));
//////
//////	__oMsg_2("BoundingRadius :  %f", GetBoundingRadius(kGetPlayer));
//////
////////-----------------------------------------------------
//////
////////return;
//////
//////
////////========= THONG TIN pMOVE ==================================================================================================
//////	__oMsg_2("\n");
//////	__oMsg_2("======================= pMOVE : ==========================");
//////	//DWORD movNote = (DWORD)kGetPlayer->_pMOVE;
//////	//DWORD strMove  = *(DWORD*)(movNote + 4);
//////	//stMOVE *destPos = (stMOVE *)strMove;
//////	DWORD movNote = GET_PMOVE_NEW(kGetPlayer);
//////	stMOVE *destPos = (stMOVE *)movNote;
//////	if (destPos)
//////	{
//////		__oMsg_2("[%x]pMOVE:", destPos);
//////		__oMsg_2("[%x - %x]IS MOVING(OLD)     = %d", &destPos->nIsMoving, (DWORD)&destPos->nIsMoving - (DWORD)destPos, (BYTE)destPos->nIsMoving);
//////		__oMsg_2("[%x]IS MOVE					= %d", &kGetPlayer->nIsMove_KODUNGNUA, (BYTE)kGetPlayer->nIsMove_KODUNGNUA);
//////		__oMsg_2("[%x - %x]POSITION_E_OLD     = %f,%f,%f", &destPos->__strPosDest_OLD.x, (DWORD)&destPos->__strPosDest_OLD.x - (DWORD)destPos, destPos->__strPosDest_OLD.x, destPos->__strPosDest_OLD.y, destPos->__strPosDest_OLD.z);
//////		__oMsg_2("[%x - %x]POSITION-END       = %f,%f,%f)", &destPos->__strPosDest.x, (DWORD)&destPos->__strPosDest.x - (DWORD)destPos, destPos->__strPosDest.x, destPos->__strPosDest.y, destPos->__strPosDest.z);
//////		__oMsg_2("[%x - %x]POSITION-START     = %f,%f,%f)", &destPos->__strPosStart.x, (DWORD)&destPos->__strPosStart.x - (DWORD)destPos, destPos->__strPosStart.x, destPos->__strPosStart.y, destPos->__strPosStart.z);
//////		__oMsg_2("[%x - %x]nWayPoint_Start    = %x)", &destPos->nWayPoint_Start, (DWORD)&destPos->nWayPoint_Start - (DWORD)destPos, destPos->nWayPoint_Start);
//////		__oMsg_2("[%x - %x]nWayPoint_End      = %x)", &destPos->nWayPoint_End, (DWORD)&destPos->nWayPoint_End - (DWORD)destPos, destPos->nWayPoint_End);
//////		__oMsg_2("[%x - %x]nWayPoint_MaxEnd   = %x)", &destPos->nWayPoint_MaxEnd, (DWORD)&destPos->nWayPoint_MaxEnd - (DWORD)destPos, destPos->nWayPoint_MaxEnd);
//////		__oMsg_2("[%x - %x]nIsDash            = %d)", &destPos->nIsDash, (DWORD)&destPos->nIsDash - (DWORD)destPos, (BYTE)destPos->nIsDash);
//////		__oMsg_2("[%x - %x]nDashSpeed         = %f)", &destPos->nDashSpeed, (DWORD)&destPos->nDashSpeed - (DWORD)destPos, destPos->nDashSpeed);
//////		__oMsg_2("[%x - %x]IsDashing_Old      = %d", &destPos->nIsDashing, (DWORD)&destPos->nIsDashing - (DWORD)destPos, (BYTE)destPos->nIsDashing);
//////		__oMsg_2("[%x - %x]nIsDashGravity     = %d)", &destPos->nDashGravity, (DWORD)&destPos->nDashGravity - (DWORD)destPos, (BYTE)destPos->nDashGravity);
//////		__oMsg_2("[%x - %x]IS IN FOG_1        = %d", &destPos->nIsInFog, (DWORD)&destPos->nIsInFog - (DWORD)destPos, (BYTE)destPos->nIsInFog);
//////		__oMsg_2("[%x - %x]IS IN FOG_2		= %d", &destPos->nInFog2, (DWORD)&destPos->nInFog2 - (DWORD)destPos, (WORD)destPos->nInFog2);
//////	}
//////	else __oMsg_2("GetPMove_Test() = 000"); 
////////return;
//////
////////========= THONG TIN NORMAL-ATTACK && pCASTSPELL =============================================================================
//////	__oMsg_2("\n");
//////	__oMsg_2("======================= NORMAL-ATTACK && pCASTSPELL : ==========================");
//////	//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)kGetPlayer->_pNormalAttack;
//////	//if (_stNORMAL_ATTACK)
//////		__oMsg_2("Get_BasicAttack(): %x", Get_BasicAttack());
//////
//////		//__oMsg_2("[%x]CooldownExpires = %f", (DWORD)&kGetPlayer->nCooldownExpiresBA, kGetPlayer->nCooldownExpiresBA);
//////		//__oMsg_2("[%x]CooldownExpires = %f", (DWORD)&kGetPlayer->nCooldownExpiresBA, GetCDBA_Test());// ko hieu sao cu cho (DWORD)&kGetPlayer->nCooldownExpiresBA vao la crash
//////
//////		__oMsg_2("GetCDBA_Test()  = %f", GET_CDBA_NEW(kGetPlayer));
//////		__oMsg_2("GetCDBA_Test()  = %f", GET_CDBA_NEW(kGetPlayer));
//////		__oMsg_2("-----------------------------");
//////	if (kGetPlayer->_pCastSpell != 0)
//////	{
//////		KCastSpell *pCastSpell = (KCastSpell *)kGetPlayer->_pCastSpell;
//////		__oMsg_2("[%x - %x]pCASTSPELL - __pK_str2 = %x:", pCastSpell, (DWORD)&pCastSpell->__pK_str2 - (DWORD)pCastSpell, pCastSpell->__pK_str2);
//////		__oMsg_2("[%x - %x]nMy_ID_1		= %x", &pCastSpell->nMy_ID_1, (DWORD)&pCastSpell->nMy_ID_1 - (DWORD)pCastSpell, pCastSpell->nMy_ID_1);
//////		__oMsg_2("[%x - %x]nMy_ID_2		= %x", &pCastSpell->nMy_ID_2, (DWORD)&pCastSpell->nMy_ID_2 - (DWORD)pCastSpell, pCastSpell->nMy_ID_2);
//////		__oMsg_2("-----------------------------");
//////		__oMsg_2("Skill Position: ");
//////		__oMsg_2("[%x - %x]Source          = %f, %f, %f", &pCastSpell->SourcePos.x,  (DWORD)&pCastSpell->SourcePos.x - (DWORD)pCastSpell, pCastSpell->SourcePos.x,  pCastSpell->SourcePos.y,  pCastSpell->SourcePos.z);
//////		__oMsg_2("[%x - %x]MaxDest         = %f, %f, %f", &pCastSpell->MaxDestPos.x, (DWORD)&pCastSpell->MaxDestPos.x - (DWORD)pCastSpell, pCastSpell->MaxDestPos.x, pCastSpell->MaxDestPos.y, pCastSpell->MaxDestPos.z);
//////		__oMsg_2("[%x - %x]Mouse           = %f, %f, %f", &pCastSpell->MousePos.x,   (DWORD)&pCastSpell->MousePos.x - (DWORD)pCastSpell, pCastSpell->MousePos.x,   pCastSpell->MousePos.y,   pCastSpell->MousePos.z);
//////		__oMsg_2("[%x - %x]nEnemy_ID		 = %x", &pCastSpell->nEnemy_ID, (DWORD)&pCastSpell->nEnemy_ID - (DWORD)pCastSpell, pCastSpell->nEnemy_ID);
//////		__oMsg_2("[%x - %x]nDelay_AAAnimate    = %f", &pCastSpell->nDelay_AAAnimate, (DWORD)&pCastSpell->nDelay_AAAnimate - (DWORD)pCastSpell, pCastSpell->nDelay_AAAnimate);
//////		__oMsg_2("[%x - %x]nDelay_AAAnimate_2  = %f", &pCastSpell->nDelay_AAAnimate_2, (DWORD)&pCastSpell->nDelay_AAAnimate_2 - (DWORD)pCastSpell, pCastSpell->nDelay_AAAnimate_2);
//////		__oMsg_2("[%x - %x]nCoolDownAA		    = %f", &pCastSpell->nCoolDownAA, (DWORD)&pCastSpell->nCoolDownAA - (DWORD)pCastSpell, pCastSpell->nCoolDownAA);
//////		__oMsg_2("[%x - %x]nSlot			    = %d", &pCastSpell->nSlot, (DWORD)&pCastSpell->nSlot - (DWORD)pCastSpell, (BYTE)pCastSpell->nSlot);
//////		__oMsg_2("[%x - %x]nTime_BatDauBan     = %f", &pCastSpell->nTime_BatDauBAN, (DWORD)&pCastSpell->nTime_BatDauBAN - (DWORD)pCastSpell, pCastSpell->nTime_BatDauBAN);
//////		__oMsg_2("[%x - %x]nTime_DanBatDauBay  = %f", &pCastSpell->nTime_DanBatDauBay, (DWORD)&pCastSpell->nTime_DanBatDauBay - (DWORD)pCastSpell, pCastSpell->nTime_DanBatDauBay);
//////		__oMsg_2("[%x - %x]nTime_CooldownExpires_AA= %f", &pCastSpell->nTime_CDExpiresAA, (DWORD)&pCastSpell->nTime_CDExpiresAA - (DWORD)pCastSpell, pCastSpell->nTime_CDExpiresAA);
//////		KSkill_2* pSkill_2 = (KSkill_2*)pCastSpell->__pK_str2;
//////		if(pSkill_2)
//////		{
//////			__oMsg_2("Name: %s - __pK_str3 = %x [%x]", pSkill_2->GetSkillName(), pSkill_2->__pK_str3, (DWORD)&pSkill_2->__pK_str3 - (DWORD)pSkill_2);
//////			KMissile_Struct_3* pStruct_3 = (KMissile_Struct_3*)pSkill_2->__pK_str3;
//////			if(pStruct_3)
//////			{
//////				__oMsg_2("[%x]nRange	    = %f [%x]", &pStruct_3->nRange, pStruct_3->nRange, (DWORD)&pStruct_3->nRange - (DWORD)pStruct_3);
//////				__oMsg_2("[%x]nRange_2    = %f [%x]", &pStruct_3->nRange_2, pStruct_3->nRange_2, (DWORD)&pStruct_3->nRange_2 - (DWORD)pStruct_3);
//////				__oMsg_2("[%x]nRadius	    = %f [%x]", &pStruct_3->nRadius, pStruct_3->nRadius, (DWORD)&pStruct_3->nRadius - (DWORD)pStruct_3);
//////				__oMsg_2("[%x]nSpeed      = %f [%x]", &pStruct_3->nMissileSpeed, pStruct_3->nMissileSpeed, (DWORD)&pStruct_3->nMissileSpeed - (DWORD)pStruct_3);
//////				__oMsg_2("[%x]nWidth	    = %f [%x]", &pStruct_3->nMissileWidth, pStruct_3->nMissileWidth, (DWORD)&pStruct_3->nMissileWidth - (DWORD)pStruct_3);
//////			}
//////		}
//////	}
//////	else
//////	{
//////		__oMsg_2("pCastSpell : nEnemy_ID = [xxxxxxx] (Chua Cast Spell)");
//////	}
//////
////////========= THONG TIN TIME_GAME ================================================================================================
//////	__oMsg_2("\n");
//////	__oMsg_2("======================= TIME_GAME : ============================================");
//////	__oMsg_2("TIME_GAME_OLD  = %f", GetTimeGame_OLD());
//////	//__oMsg_2("TIME_GAME_NEW  = %f", GetTimeGame());
//////	
//////	__oMsg_2("TIME_GAME_DUBI = %f", GetTimeGame_Dubi());
//////
////////return;
//////
////////========= THONG TIN SKILL ====================================================================================================
//////	__oMsg_2("\n");
//////	__oMsg_2("======================= SKILL INFORMATION : ====================================");
//////	KSkill*   pSkillQ = (KSkill*) kGetPlayer->_pSkill[0];
//////	KSkill*   pSkillW = (KSkill*) kGetPlayer->_pSkill[1];
//////	KSkill*   pSkillE = (KSkill*) kGetPlayer->_pSkill[2];
//////	KSkill*   pSkillR = (KSkill*) kGetPlayer->_pSkill[3];
//////	__oMsg_2(" [-Q-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillQ, &pSkillQ->nLevel, (DWORD)&pSkillQ->nLevel - (DWORD)pSkillQ, (BYTE)pSkillQ->nLevel);
//////	__oMsg_2(" [-Q-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillQ, &pSkillQ->nCooldownExpires, (DWORD)&pSkillQ->nCooldownExpires - (DWORD)pSkillQ, pSkillQ->nCooldownExpires);
//////	__oMsg_2(" [-Q-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillQ, &pSkillQ->nStack, (DWORD)&pSkillQ->nStack - (DWORD)pSkillQ, (BYTE)pSkillQ->nStack);
//////	__oMsg_2(" [-Q-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillQ, &pSkillQ->nCooldownExpires_3, (DWORD)&pSkillQ->nCooldownExpires_3 - (DWORD)pSkillQ, pSkillQ->nCooldownExpires_3);
//////	__oMsg_2(" [-Q-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillQ, &pSkillQ->nToggle, (DWORD)&pSkillQ->nToggle - (DWORD)pSkillQ, (BYTE)pSkillQ->nToggle);
//////	__oMsg_2(" [-Q-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillQ, &pSkillQ->nTotalCooldown, (DWORD)&pSkillQ->nTotalCooldown - (DWORD)pSkillQ, pSkillQ->nTotalCooldown);
//////	
//////	__oMsg_2(" [-W-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillW, &pSkillW->nLevel, (DWORD)&pSkillW->nLevel - (DWORD)pSkillW, (BYTE)pSkillW->nLevel);
//////	__oMsg_2(" [-W-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillW, &pSkillW->nCooldownExpires, (DWORD)&pSkillW->nCooldownExpires - (DWORD)pSkillW, pSkillW->nCooldownExpires);
//////	__oMsg_2(" [-W-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillW, &pSkillW->nStack, (DWORD)&pSkillW->nStack - (DWORD)pSkillW, (BYTE)pSkillW->nStack);
//////	__oMsg_2(" [-W-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillW, &pSkillW->nCooldownExpires_3, (DWORD)&pSkillW->nCooldownExpires_3 - (DWORD)pSkillW, pSkillW->nCooldownExpires_3);
//////	__oMsg_2(" [-W-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillW, &pSkillW->nToggle, (DWORD)&pSkillW->nToggle - (DWORD)pSkillW, (BYTE)pSkillW->nToggle);
//////	__oMsg_2(" [-W-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillW, &pSkillW->nTotalCooldown, (DWORD)&pSkillW->nTotalCooldown - (DWORD)pSkillW, pSkillW->nTotalCooldown);
//////
//////	__oMsg_2(" [-E-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillE, &pSkillE->nLevel, (DWORD)&pSkillE->nLevel - (DWORD)pSkillE, (BYTE)pSkillE->nLevel);
//////	__oMsg_2(" [-E-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillE, &pSkillE->nCooldownExpires, (DWORD)&pSkillE->nCooldownExpires - (DWORD)pSkillE, pSkillE->nCooldownExpires);
//////	__oMsg_2(" [-E-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillE, &pSkillE->nStack, (DWORD)&pSkillE->nStack - (DWORD)pSkillE, (BYTE)pSkillE->nStack);
//////	__oMsg_2(" [-E-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillE, &pSkillE->nCooldownExpires_3, (DWORD)&pSkillE->nCooldownExpires_3 - (DWORD)pSkillE, pSkillE->nCooldownExpires_3);
//////	__oMsg_2(" [-E-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillE, &pSkillE->nToggle, (DWORD)&pSkillE->nToggle - (DWORD)pSkillE, (BYTE)pSkillE->nToggle);
//////	__oMsg_2(" [-E-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillE, &pSkillE->nTotalCooldown, (DWORD)&pSkillE->nTotalCooldown - (DWORD)pSkillE, pSkillE->nTotalCooldown);
//////
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillR, &pSkillR->nLevel, (DWORD)&pSkillR->nLevel - (DWORD)pSkillR, (BYTE)pSkillR->nLevel);
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillR, &pSkillR->nCooldownExpires, (DWORD)&pSkillR->nCooldownExpires - (DWORD)pSkillR, pSkillR->nCooldownExpires);
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillR, &pSkillR->nStack, (DWORD)&pSkillR->nStack - (DWORD)pSkillR, (BYTE)pSkillR->nStack);
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillR, &pSkillR->nCooldownExpires_3, (DWORD)&pSkillR->nCooldownExpires_3 - (DWORD)pSkillR, pSkillR->nCooldownExpires_3);
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillR, &pSkillR->nToggle, (DWORD)&pSkillR->nToggle - (DWORD)pSkillR, (BYTE)pSkillR->nToggle);
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillR, &pSkillR->nTotalCooldown, (DWORD)&pSkillR->nTotalCooldown - (DWORD)pSkillR, pSkillR->nTotalCooldown);
//////
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires_2(Leblanc) = %f", pSkillR, &pSkillR->nCooldownExpires_2, (DWORD)&pSkillR->nCooldownExpires_2 - (DWORD)pSkillR, pSkillR->nCooldownExpires_2);
//////	__oMsg_2(" [-R-] [%x]K Skill -- [%x - %x]nTotalCooldown_2(Leblanc)   = %f", pSkillR, &pSkillR->nTotalCooldown_2, (DWORD)&pSkillR->nTotalCooldown_2 - (DWORD)pSkillR, pSkillR->nTotalCooldown_2);
//////	__oMsg_2("--------------------------------");
//////	KSkill_2*  pKSkill_Q = (KSkill_2*) pSkillQ->__pK_str2;
//////	__oMsg_2(" [-Q-] [%x]pK Skill 2[%x - %x] = %x ",&pSkillQ->__pK_str2, (DWORD)&pSkillQ->__pK_str2 - (DWORD)pSkillQ, (DWORD)pSkillQ->__pK_str2);
//////	if (pKSkill_Q)
//////		__oMsg_2(" [-Q-] [%x]pK Skill 2[%x - %x] -- SkillName = %s", (DWORD)pKSkill_Q, &pKSkill_Q->szName, (DWORD)&pKSkill_Q->szName - (DWORD)pKSkill_Q, pKSkill_Q->GetSkillName());
////////return;
//////
////////========= THONG TIN VE BUFF ===================================================================================================
//////	__oMsg_2("\n");
//////	__oMsg_2("======================= BUFF INFORMATION : ====================================");
//////	int nBuff_Count = (pNpc->pMax_Buffs - pNpc->pBuffs)/8;
//////	for(int i=0; i< nBuff_Count; i++){
//////		DWORD dw = *(DWORD*)(pNpc->pBuffs + 8*i);
//////		KBuffs* pBuffs = (KBuffs*)dw;
//////		if(pBuffs->nIndex == -1) continue;
//////		KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
//////		if(!pBuffs_1) continue;
//////		//if ((BYTE)pBuffs->nIndex != 26) continue;
//////
//////		__oMsg_2("[Type = %d][%x]Buff Name:  %s",(BYTE)pBuffs->nIndex, pBuffs, pBuffs_1->szName);
//////		__oMsg_2(" - [%x - %x]begin_time  = %f, [%x - %x]end_time  = %f", &pBuffs->nBegin_Time, (DWORD)&pBuffs->nBegin_Time - (DWORD)pBuffs, pBuffs->nBegin_Time ,    /*----*/   &pBuffs->nEnd_Time, (DWORD)&pBuffs->nEnd_Time - (DWORD)pBuffs, pBuffs->nEnd_Time);
//////		__oMsg_2(" - [%x - %x]start_count = %x, [%x - %x]end_count = %x --> [Stacks = %d]", &pBuffs->nStart_Count, (DWORD)&pBuffs->nStart_Count - (DWORD)pBuffs, pBuffs->nStart_Count,  /*----*/   &pBuffs->nEnd_Count, (DWORD)&pBuffs->nEnd_Count - (DWORD)pBuffs, pBuffs->nEnd_Count, (pBuffs->nEnd_Count - pBuffs->nStart_Count)/8);
//////		__oMsg_2(" - [%x - %x]nCountz     = %d", &pBuffs->nCount, (DWORD)&pBuffs->nCount - (DWORD)pBuffs, pBuffs->nCount);
//////		__oMsg_2(" - [%x - %x]nOwnerData  = %x", &pBuffs->__pOwenerData, (DWORD)&pBuffs->__pOwenerData - (DWORD)pBuffs, pBuffs->__pOwenerData);
//////		if(pBuffs->__pOwenerData)
//////		{
//////			KBuff_OwnerData* pOwnerData = (KBuff_OwnerData*)pBuffs->__pOwenerData;
//////			__oMsg_2("   pOwnerData = %x", pBuffs->__pOwenerData);
//////			__oMsg_2(" - [%x - %x]pOwnerNpc     = %x", &pOwnerData->pOwnerNpc, (DWORD)&pOwnerData->pOwnerNpc - (DWORD)pOwnerData, pOwnerData->pOwnerNpc);
//////			__oMsg_2(" - [%x - %x]pOwnerId      = %x", &pOwnerData->nOwnerId, (DWORD)&pOwnerData->nOwnerId - (DWORD)pOwnerData, pOwnerData->nOwnerId);
//////			__oMsg_2(" - [%x - %x]pOwnerNetId   = %x", &pOwnerData->nOwnerNetworkId, (DWORD)&pOwnerData->nOwnerNetworkId - (DWORD)pOwnerData, pOwnerData->nOwnerNetworkId);
//////		}
//////		__oMsg_2("[..]======>> CHU Y CHECK : nLua_pBuff = *(DWORD*)(pBaseScriptBuff + 0xC) --> ben trong OnRemoveBuff");
//////		__oMsg_2("-------------------------------------------------------------------");
//////	}
//////return;
//////
//////
////////========= CHECK WALL ==========================================================================================================
//////	__oMsg_2("\n");
//////	__oMsg_2("======================= CHECK WALL : ====================================");
//////	KPos* mousePos = GetMousePos();
//////	__oMsg_2("Mouse Cursor: [%x] = %.2f, %.2f, %.2f", &mousePos->x, mousePos->x, mousePos->y, mousePos->z);
//////	__oMsg_2("Wall        : %d ",IsWall(mousePos));
//////	__oMsg_2("--------------------------------");
//////	__oMsg_2("IS_CHATTING : %d",IS_CHATTING());
//////	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//////	DWORD nTempBASE_ENDGAME = BASE_ENDGAME - TEMP_ENTRY_POINT + hModule;
//////	DWORD dw1 = *(DWORD*)nTempBASE_ENDGAME;
//////	__oMsg_2("End Game    : %d", *(DWORD*)(dw1 + 8));		// = 2 : dang hoat dong; =3,4,5 ket thuc game
////////return;
//////
//////
//////	DWORD hModule1 = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//////	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule1;
//////	DWORD dw1_1 = *(DWORD*)nTempBASE_SKILL;
//////	if(!dw1_1) return;
//////	DWORD dw2_2 = *(DWORD*)(dw1_1 + 0xC);
//////	if(!dw2_2) return;
//////	KHackZoom* pHackZoom = (KHackZoom*)dw2_2;
//////	__oMsg_2("[%x] HackZoom: %f",&pHackZoom->nHackZoom, pHackZoom->nHackZoom);// ban dau la 1.28
//////	__oMsg_2("pDecive  : %x",Get_Device());
//////	__oMsg_2("pRenderer: %x",GetRenderer());
////////return;	
//////
//////
//////	DWORD nEndSceneFuncion = 111;
//////	DWORD* vtbl = 0;
//////	DWORD table = FindPattern((DWORD)GetModuleHandle( (sz__d3d9_dll)), 0x128000,     (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86",  (sz__xx____xx____xx) );
//////	if (table != 0)
//////	{
//////		memcpy(&vtbl, (void*)(table+2), 4);
//////		nEndSceneFuncion = vtbl[42];
//////	}
//////
//////	__oMsg_2("nEndSceneFuncion-d3d9 = [%x]", nEndSceneFuncion);
//////
//////
//////	DWORD hModule2 = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//////	DWORD nTempBASE_SKILL1 = BASE_SKILL - TEMP_ENTRY_POINT + hModule2;
//////	DWORD dw1_1_1 = *(DWORD*)nTempBASE_SKILL1;
//////	DWORD dw2_3_1 = *(DWORD*)(dw1_1_1 + 0x24);
//////	__oMsg_2("ECX_RCLICK_MOVE_FUNC: %x ==> [x=%d, y=%d]",dw2_3_1, *(DWORD*)(dw2_3_1 + 0x68), *(DWORD*)(dw2_3_1 + 0x6C) );
//////	__oMsg_2("GetGameCursorPos:  [x=%f, y=%f]", GetGameCursorPos().x, GetGameCursorPos().y);
//////    DWORD dw2_4 = *(DWORD*)(dw1_1_1 + 0x30);
//////	if(!dw2_4) return;
//////	KSelectTarget* pSelectTarget = (KSelectTarget*)dw2_4;
//////	__oMsg_2("[%x]nSelectOrNot      = %d", &pSelectTarget->nSelectOrNot, (BYTE)pSelectTarget->nSelectOrNot);
//////	__oMsg_2("nIDTargetSelected = %x",pSelectTarget->nIDTargetSelected);
//////	__oMsg_2("GAA_Animate: %f - AADelay : %f ", Get_AA_Animate_Delay(), Get_AA_Delay());
//////	__oMsg_2("Ping: %d", GetPingGame());
//////	__oMsg_2("GetObjectByID        : %x", GetObjectByID(kGetPlayer->nID));
//////	__oMsg_2("GetObjectByNetworkID : %x", GetObjectByNetworkID(kGetPlayer->nIndex));
////////return;
//////
//////	//--------ITEM---------------------------------
//////	KItem *pItem = (KItem*)kGetPlayer->_pItem[0];// Item[0]
//////	if(pItem)
//////	{
//////		//__oMsg_2("[pItem] : %x", pItem);
//////		KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
//////		if(pItem_1)
//////		{
//////			//__oMsg_2("[pItem_1] : %x", pItem_1);
//////			KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
//////			if(pItem_2) __oMsg_2("[Name] : %s - ID = %x", pItem_1->pName, pItem_2->nID);
//////		}
//////		
//////	}
//////__oMsg_2("------ LUU Y CHUA CHECK TRONG OnCreateObject-->[GetMissileOwner_Name]------- \n\n");
//////	
//////	
//////
//////	
////////==========================================================================================================================================================
//////
////////	//////////////////////////////////////
}

void PrintAllGameInfo(KNpc *pNpc)
{
	
	//////Logger _logger(L"OFF_SET");
	//////_logger.startLog();

	////////_logger.LogString("testString.1 : ", "ABC_XYZ_1");
	////////_logger.LogString("testString.2 : ", "ABC_XYZ_2");
	//////_logger.LogAll("IS_DEAD: %d ", IS_DEAD(GetPlayer()));
	//////_logger.LogAll("IS_MOVE_NEW: %d ", IsMoving(GetPlayer()));
	//////_logger.LogAll("IS_ON_SCREEN: %d ", IS_CAN_SEE(GetPlayer()));
	//////_logger.LogAll("nIndex: %x ", kGetPlayer->nIndex);
	//////_logger.LogAll("[%x - %x] nIs_Nexus                = %x", &kGetPlayer->nIs_Nexus, (DWORD)&kGetPlayer->nIs_Nexus - (DWORD)kGetPlayer, kGetPlayer->nIs_Nexus);
	//////_logger.LogAll("[%x - %x] nID                      = %x", &kGetPlayer->nID, (DWORD)&kGetPlayer->nID - (DWORD)kGetPlayer, kGetPlayer->nID);
	//////_logger.LogAll("[%x - %x] nTeam_ID                 = %x", &kGetPlayer->nTeam_ID, (DWORD)&kGetPlayer->nTeam_ID - (DWORD)kGetPlayer, kGetPlayer->nTeam_ID);
	//////_logger.LogAll("[%x - %x] nType_1                  = %x", &kGetPlayer->nType_1, (DWORD)&kGetPlayer->nType_1 - (DWORD)kGetPlayer, kGetPlayer->nType_1);

	//////_logger.LogAll("[%x - %x] szPlayerName             = %s", &kGetPlayer->szPlayerName, (DWORD)&kGetPlayer->szPlayerName - (DWORD)kGetPlayer, kGetPlayer->GetNameNpc());
	//////_logger.LogAll("[%x - %x] nLen_Name                = %d", &kGetPlayer->nLen_Name, (DWORD)&kGetPlayer->nLen_Name - (DWORD)kGetPlayer, kGetPlayer->nLen_Name);
	//////_logger.LogAll("[%x - %x] nMaxlen_Name             = %d", &kGetPlayer->nMaxlen_Name, (DWORD)&kGetPlayer->nMaxlen_Name - (DWORD)kGetPlayer, kGetPlayer->nMaxlen_Name);
	//////_logger.LogAll("[%x - %x] nIndex                   = %x", &kGetPlayer->nIndex, (DWORD)&kGetPlayer->nIndex - (DWORD)kGetPlayer, kGetPlayer->nIndex);
	//////_logger.LogAll("[%x - %x] BBoxMinPos               = %f, %f, %f", &kGetPlayer->BBoxMin.x, (DWORD)&kGetPlayer->BBoxMin.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMin.x, kGetPlayer->BBoxMin.y, kGetPlayer->BBoxMin.z);
	//////_logger.LogAll("[%x - %x] BBoxMaxPos               = %f, %f, %f", &kGetPlayer->BBoxMax.x, (DWORD)&kGetPlayer->BBoxMax.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMax.x, kGetPlayer->BBoxMax.y, kGetPlayer->BBoxMax.z);
	//////_logger.stopLog();
	//////SEND_TEXT_SYSTEM("----STOP-LOG-FILE----");

	//if (pNpc == NULL)
	//{
	//	__oMsg("NPC bi null");
	//	return;
	//}
	//KNpc *kGetPlayer = pNpc;


//	//*********************////***********
//	__oMsg("IS_DEAD: %d - IS_MOVE_NEW: %d - IS_ON_SCREEN: %d", IS_DEAD(GetPlayer()), IsMoving(GetPlayer()), IS_CAN_SEE(GetPlayer()));
////return;
//
//	__oMsg("TIME_GAME_NEW  = %f", GetTimeGame());
//
////========= THONG TIN pPLAYER ==================================================================================================
//	__oMsg("======================= pPLAYER : ==========================");
//	
//
//	//__oMsg("isHero  = %d", IS_HERO_Test(kGetPlayer));
//
//	//KNpc *kGetPlayer = GetPlayer();
//	__oMsg("[%x - %d]Name = %s - isHero: %d", kGetPlayer, kGetPlayer, kGetPlayer->GetNameNpc(), IS_HERO(kGetPlayer));
//	__oMsg("isTurret    :  %d", IS_TURRET(kGetPlayer));
//	__oMsg("IsChampion  :  %d", IS_HERO(kGetPlayer));
//	__oMsg("IsMinion    :  %d", IS_MINION(kGetPlayer));
//	__oMsg("IsNexus     :  %d", IS_NEXUS(kGetPlayer));
//	__oMsg("IsInhibitor :  %d", IS_INHIBITOR(kGetPlayer));
//	__oMsg("\n");
////return;
//	__oMsg("[%x - %x] nIs_Nexus                = %x", &kGetPlayer->nIs_Nexus, (DWORD)&kGetPlayer->nIs_Nexus - (DWORD)kGetPlayer, kGetPlayer->nIs_Nexus);
//	__oMsg("[%x - %x] nID                      = %x", &kGetPlayer->nID, (DWORD)&kGetPlayer->nID - (DWORD)kGetPlayer, kGetPlayer->nID);
//	__oMsg("[%x - %x] nTeam_ID                 = %x", &kGetPlayer->nTeam_ID, (DWORD)&kGetPlayer->nTeam_ID - (DWORD)kGetPlayer, kGetPlayer->nTeam_ID);
//	__oMsg("[%x - %x] nType_1                  = %x", &kGetPlayer->nType_1, (DWORD)&kGetPlayer->nType_1 - (DWORD)kGetPlayer, kGetPlayer->nType_1);
////return;
//	__oMsg("[%x - %x] szPlayerName             = %s", &kGetPlayer->szPlayerName, (DWORD)&kGetPlayer->szPlayerName - (DWORD)kGetPlayer, kGetPlayer->GetNameNpc());
//	__oMsg("[%x - %x] nLen_Name                = %d", &kGetPlayer->nLen_Name, (DWORD)&kGetPlayer->nLen_Name - (DWORD)kGetPlayer, kGetPlayer->nLen_Name);
//	__oMsg("[%x - %x] nMaxlen_Name             = %d", &kGetPlayer->nMaxlen_Name, (DWORD)&kGetPlayer->nMaxlen_Name - (DWORD)kGetPlayer, kGetPlayer->nMaxlen_Name);
//	__oMsg("[%x - %x] nIndex                   = %x", &kGetPlayer->nIndex, (DWORD)&kGetPlayer->nIndex - (DWORD)kGetPlayer, kGetPlayer->nIndex);
//	__oMsg("[%x - %x] BBoxMinPos               = %f, %f, %f", &kGetPlayer->BBoxMin.x, (DWORD)&kGetPlayer->BBoxMin.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMin.x, kGetPlayer->BBoxMin.y, kGetPlayer->BBoxMin.z);
//	__oMsg("[%x - %x] BBoxMaxPos               = %f, %f, %f", &kGetPlayer->BBoxMax.x, (DWORD)&kGetPlayer->BBoxMax.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMax.x, kGetPlayer->BBoxMax.y, kGetPlayer->BBoxMax.z);
////return;
//	__oMsg("[%x - %x] nDeleted(tim:OnDeleteObj)= %d", &kGetPlayer->nDeleted, (DWORD)&kGetPlayer->nDeleted - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nDeleted);
//	__oMsg("[%x - %x] nCanSee                  = %d", &kGetPlayer->nCanSee, (DWORD)&kGetPlayer->nCanSee - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nCanSee);
//	__oMsg("[%x - %x] CurrentPos(server)       = %f, %f, %f", &kGetPlayer->ServerPosition.x, (DWORD)&kGetPlayer->ServerPosition.x - (DWORD)kGetPlayer, kGetPlayer->ServerPosition.x, kGetPlayer->ServerPosition.y, kGetPlayer->ServerPosition.z);
//	__oMsg("[%x - %x] nIsDie                   = %d", &kGetPlayer->nIsDie, (DWORD)&kGetPlayer->nIsDie - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsDie);
//	__oMsg("[%x - %x] CurrentPos               = %f, %f, %f", &kGetPlayer->CurrentPos.x, (DWORD)&kGetPlayer->CurrentPos.x - (DWORD)kGetPlayer, kGetPlayer->CurrentPos.x, kGetPlayer->CurrentPos.y, kGetPlayer->CurrentPos.z);
//	__oMsg("[%x - %x] nMissileData             = %x", &kGetPlayer->nMissileData, (DWORD)&kGetPlayer->nMissileData - (DWORD)kGetPlayer, kGetPlayer->nMissileData);
//	__oMsg("[%x - %x] nMissileOwnerID_1        = %x", &kGetPlayer->nMissileOwnerID_1, (DWORD)&kGetPlayer->nMissileOwnerID_1 - (DWORD)kGetPlayer, kGetPlayer->nMissileOwnerID_1);
//	__oMsg("[%x - %x] nMissileOwnerID_2        = %x", &kGetPlayer->nMissileOwnerID_2, (DWORD)&kGetPlayer->nMissileOwnerID_2 - (DWORD)kGetPlayer, kGetPlayer->nMissileOwnerID_2);
//	//__oMsg("[%x - %x] nSpawnTime               = %f", &kGetPlayer->nSpawnTime, (DWORD)&kGetPlayer->nSpawnTime - (DWORD)kGetPlayer, kGetPlayer->nSpawnTime);
////return;
//	__oMsg("[%x - %x] nMP                      = %f", &kGetPlayer->nMP, (DWORD)&kGetPlayer->nMP - (DWORD)kGetPlayer, kGetPlayer->nMP);
//	__oMsg("[%x - %x] nMaxMP                   = %f",& kGetPlayer->nMaxMP, (DWORD)&kGetPlayer->nMaxMP - (DWORD)kGetPlayer, kGetPlayer->nMaxMP);
//	__oMsg("[%x - %x] nJhinMissile             = %f", &kGetPlayer->nJhinMissile, (DWORD)&kGetPlayer->nJhinMissile - (DWORD)kGetPlayer, kGetPlayer->nJhinMissile);
//	__oMsg("[%x - %x] nIsInvulnerable          = %d", &kGetPlayer->nIsInvulnerable, (DWORD)&kGetPlayer->nIsInvulnerable - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsInvulnerable & 1);
//	__oMsg("[%x - %x] nOverrideCollisionRadius = %f", &kGetPlayer->nOverrideCollisionRadius, (DWORD)&kGetPlayer->nOverrideCollisionRadius - (DWORD)kGetPlayer, kGetPlayer->nOverrideCollisionRadius);
//	__oMsg("[%x - %x] nIsTargetable            = %d", &kGetPlayer->nIsTargetable, (DWORD)&kGetPlayer->nIsTargetable - (DWORD)kGetPlayer, kGetPlayer->nIsTargetable);
//	__oMsg("[%x - %x] nIsTargetableToTeam      = %d", &kGetPlayer->nIsTargetableToTeam, (DWORD)&kGetPlayer->nIsTargetableToTeam - (DWORD)kGetPlayer, kGetPlayer->nIsTargetableToTeam);
//	__oMsg("[%x - %x] nIsBasing                = %d", &kGetPlayer->nIsBasing, (DWORD)&kGetPlayer->nIsBasing - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsBasing);
//	__oMsg("[%x - %x] nHP                      = %f", &kGetPlayer->nHP, (DWORD)&kGetPlayer->nHP - (DWORD)kGetPlayer, kGetPlayer->nHP);
//	__oMsg("[%x - %x] nMaxHP                   = %f", &kGetPlayer->nMaxHP, (DWORD)&kGetPlayer->nMaxHP - (DWORD)kGetPlayer, kGetPlayer->nMaxHP);
////return;
//	__oMsg("[%x - %x] nGiapMau                 = %f", &kGetPlayer->nGiap_Mau, (DWORD)&kGetPlayer->nGiap_Mau - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau);
//	__oMsg("[%x - %x] nGiap_Mau_Rengar         = %f", &kGetPlayer->nGiap_Mau_Rengar, (DWORD)&kGetPlayer->nGiap_Mau_Rengar - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau_Rengar);
//	__oMsg("[%x - %x] nGiap_Mau_AP             = %f", &kGetPlayer->nGiap_Mau_AP, (DWORD)&kGetPlayer->nGiap_Mau_AP - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau_AP);
//	__oMsg("[%x - %x] nModSkinID               = %d", &kGetPlayer->nModSkinID, (DWORD)&kGetPlayer->nModSkinID - (DWORD)kGetPlayer, kGetPlayer->nModSkinID);
//	__oMsg("[%x - %x] nXyenPhep_Diem           = %f", &kGetPlayer->nXyenPhep_Diem, (DWORD)&kGetPlayer->nXyenPhep_Diem - (DWORD)kGetPlayer, kGetPlayer->nXyenPhep_Diem);
//	__oMsg("[%x - %x] nXyenGiap_Diem           = %f", &kGetPlayer->nXyenGiap_Diem, (DWORD)&kGetPlayer->nXyenGiap_Diem - (DWORD)kGetPlayer, kGetPlayer->nXyenGiap_Diem);
////return;
//	__oMsg("[%x - %x] nFlat_PhysicalDamageMod  = %f", &kGetPlayer->nFlat_PhysicalDamageMod, (DWORD)&kGetPlayer->nFlat_PhysicalDamageMod - (DWORD)kGetPlayer, kGetPlayer->nFlat_PhysicalDamageMod);
//	__oMsg("[%x - %x] nFlat_MagicDamageMod     = %f", &kGetPlayer->nFlat_MagicDamageMod, (DWORD)&kGetPlayer->nFlat_MagicDamageMod - (DWORD)kGetPlayer, kGetPlayer->nFlat_MagicDamageMod);
//	__oMsg("[%x - %x] nPercent_MagicDamageMod  = %f", &kGetPlayer->nPercent_MagicDamageMod, (DWORD)&kGetPlayer->nPercent_MagicDamageMod - (DWORD)kGetPlayer, kGetPlayer->nPercent_MagicDamageMod);
//	__oMsg("[%x - %x] nAttackSpeedMod          = %f", &kGetPlayer->nAttackSpeedMod, (DWORD)&kGetPlayer->nAttackSpeedMod - (DWORD)kGetPlayer, kGetPlayer->nAttackSpeedMod);
//	__oMsg("[%x - %x] nBaseAttackDamage        = %f", &kGetPlayer->nBaseAttackDamage, (DWORD)&kGetPlayer->nBaseAttackDamage - (DWORD)kGetPlayer, kGetPlayer->nBaseAttackDamage);
//	__oMsg("[%x - %x] nCritChance              = %f", &kGetPlayer->nCritChance, (DWORD)&kGetPlayer->nCritChance - (DWORD)kGetPlayer, kGetPlayer->nCritChance);
//	__oMsg("[%x - %x] nArmor                   = %f", &kGetPlayer->nArmor, (DWORD)&kGetPlayer->nArmor - (DWORD)kGetPlayer, kGetPlayer->nArmor);
//	__oMsg("[%x - %x] nArmor_CongThem          = %f", &kGetPlayer->nArmor_CongThem, (DWORD)&kGetPlayer->nArmor_CongThem - (DWORD)kGetPlayer, kGetPlayer->nArmor_CongThem);
//	__oMsg("[%x - %x] nSpellBlock              = %f", &kGetPlayer->nSpellBlock, (DWORD)&kGetPlayer->nSpellBlock - (DWORD)kGetPlayer, kGetPlayer->nSpellBlock);
//	__oMsg("[%x - %x] nSpellBlock_CongThem     = %f", &kGetPlayer->nSpellBlock_CongThem, (DWORD)&kGetPlayer->nSpellBlock_CongThem - (DWORD)kGetPlayer, kGetPlayer->nSpellBlock_CongThem);
//	__oMsg("[%x - %x] nMoveSpeed               = %f", &kGetPlayer->nMoveSpeed, (DWORD)&kGetPlayer->nMoveSpeed - (DWORD)kGetPlayer, kGetPlayer->nMoveSpeed);
//	__oMsg("[%x - %x] nAttackRange             = %f", &kGetPlayer->nAttackRange, (DWORD)&kGetPlayer->nAttackRange - (DWORD)kGetPlayer, kGetPlayer->nAttackRange);
////return;	
//	__oMsg("[%x - %x] nIsBot                   = %d", &kGetPlayer->nIsBot, (DWORD)&kGetPlayer->nIsBot - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsBot);
//	__oMsg("[%x - %x] nHoiMauMoiGiay           = %f", &kGetPlayer->nHoiMauMoiGiay, (DWORD)&kGetPlayer->nHoiMauMoiGiay - (DWORD)kGetPlayer, kGetPlayer->nHoiMauMoiGiay);
//	__oMsg("[%x - %x] nPet_ID_1                = %x", &kGetPlayer->nPet_ID_1, (DWORD)&kGetPlayer->nPet_ID_1 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_1);
//	__oMsg("[%x - %x] nPet_ID_2                = %x", &kGetPlayer->nPet_ID_2, (DWORD)&kGetPlayer->nPet_ID_2 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_2);
//	__oMsg("[%x - %x] nPet_ID_3                = %x", &kGetPlayer->nPet_ID_3, (DWORD)&kGetPlayer->nPet_ID_3 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_3);
//	__oMsg("[%x - %x] nAI_LastPetSpawnedID     = %x", &kGetPlayer->nAI_LastPetSpawnedID, (DWORD)&kGetPlayer->nAI_LastPetSpawnedID - (DWORD)kGetPlayer, kGetPlayer->nAI_LastPetSpawnedID);
//	__oMsg("[%x - %x] nGold                    = %f", &kGetPlayer->nGold, (DWORD)&kGetPlayer->nGold - (DWORD)kGetPlayer, kGetPlayer->nGold);
//	__oMsg("[%x - %x] FacingPos               = %f, %f, %f", &kGetPlayer->facingPos.x, (DWORD)&kGetPlayer->facingPos.x - (DWORD)kGetPlayer, kGetPlayer->facingPos.x, kGetPlayer->facingPos.y, kGetPlayer->facingPos.z);
//	__oMsg("[%x - %x] nCombatType              = %d", &kGetPlayer->nCombatType, (DWORD)&kGetPlayer->nCombatType - (DWORD)kGetPlayer, kGetPlayer->nCombatType);
//	__oMsg("[%x - %x] DWORD pBuffs             = %x", &kGetPlayer->pBuffs, (DWORD)&kGetPlayer->pBuffs - (DWORD)kGetPlayer, kGetPlayer->pBuffs);
//	__oMsg("[%x - %x] DWORD pMax_Buffs         = %x", &kGetPlayer->pMax_Buffs, (DWORD)&kGetPlayer->pMax_Buffs - (DWORD)kGetPlayer, kGetPlayer->pMax_Buffs);
////return;
//
//	//__oMsg("[%x - %x] szName_Hero              = %s", &kGetPlayer->szName_Hero, (DWORD)&kGetPlayer->szName_Hero - (DWORD)kGetPlayer, kGetPlayer->GetNameHero());
//	//__oMsg("[%x - %x] nLen_Name_Hero           = %d", &kGetPlayer->nLen_Name_Hero, (DWORD)&kGetPlayer->nLen_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nLen_Name_Hero);
//	//__oMsg("[%x - %x] nMax_Len_Name_Hero       = %d", &kGetPlayer->nMax_Len_Name_Hero, (DWORD)&kGetPlayer->nMax_Len_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nMax_Len_Name_Hero);
//	__oMsg("[%x - %x] DWORD _pMOVE             = %x", &kGetPlayer->_pMOVE, (DWORD)&kGetPlayer->_pMOVE - (DWORD)kGetPlayer, kGetPlayer->_pMOVE);
//	__oMsg("[%x - %x] int _pCastSpellBook      = %x", &kGetPlayer->_pCastSpellBook, (DWORD)&kGetPlayer->_pCastSpellBook - (DWORD)kGetPlayer, kGetPlayer->_pCastSpellBook);
//	__oMsg("[%x - %x] DWORD *_pCastSpell       = %x", &kGetPlayer->_pCastSpell, (DWORD)&kGetPlayer->_pCastSpell - (DWORD)kGetPlayer, kGetPlayer->_pCastSpell);
//	__oMsg("[%x - %x] nIsCastingSpell          = %d", &kGetPlayer->nIsCastingSpell, (DWORD)&kGetPlayer->nIsCastingSpell - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsCastingSpell);
//	//__oMsg("[%x - %x] DWORD _pNormalAttack     = %x", &kGetPlayer->_pNormalAttack, (DWORD)&kGetPlayer->_pNormalAttack - (DWORD)kGetPlayer, kGetPlayer->_pNormalAttack);
//	__oMsg("[%x - %x] DWORD _pSkill[63][from canCast2] = %x  ", &kGetPlayer->_pSkill, (DWORD)&kGetPlayer->_pSkill - (DWORD)kGetPlayer, kGetPlayer->_pSkill);
//	
//	__oMsg("[%x - %x] szName_Hero              = %s", &kGetPlayer->szName_Hero, (DWORD)&kGetPlayer->szName_Hero - (DWORD)kGetPlayer, kGetPlayer->GetNameHero());
//	__oMsg("[%x - %x] nLen_Name_Hero           = %d", &kGetPlayer->nLen_Name_Hero, (DWORD)&kGetPlayer->nLen_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nLen_Name_Hero);
//	__oMsg("[%x - %x] nMax_Len_Name_Hero       = %d", &kGetPlayer->nMax_Len_Name_Hero, (DWORD)&kGetPlayer->nMax_Len_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nMax_Len_Name_Hero);
////return;
//
//	__oMsg("[%x - %x] nEnemy_ID                = %x", &kGetPlayer->nEnemy_ID, (DWORD)&kGetPlayer->nEnemy_ID - (DWORD)kGetPlayer, kGetPlayer->nEnemy_ID);
//	__oMsg("[%x - %x] nBLOCK_MOVE              = %x", &kGetPlayer->nBLOCK_MOVE, (DWORD)&kGetPlayer->nBLOCK_MOVE - (DWORD)kGetPlayer, kGetPlayer->nBLOCK_MOVE);
//	__oMsg("[%x - %x] nIsMinion                = %d", &kGetPlayer->nIsMinion, (DWORD)&kGetPlayer->nIsMinion - (DWORD)kGetPlayer, kGetPlayer->nIsMinion);
//	__oMsg("[%x - %x] nMinion_Level            = %d", &kGetPlayer->nMinion_Level, (DWORD)&kGetPlayer->nMinion_Level - (DWORD)kGetPlayer, kGetPlayer->nMinion_Level);
//	__oMsg("[%x - %x] nBar_Soucre              = %x", &kGetPlayer->nBar_Source, (DWORD)&kGetPlayer->nBar_Source - (DWORD)kGetPlayer, kGetPlayer->nBar_Source);
//	//__oMsg("[%x - %x] nCooldownExpiresBA       = %f", &kGetPlayer->nCooldownExpiresBA, (DWORD)&kGetPlayer->nCooldownExpiresBA - (DWORD)kGetPlayer, kGetPlayer->nCooldownExpiresBA);
//	__oMsg("[%x - %x] DWORD _pNormalAttack     = %x", &kGetPlayer->_pNormalAttack, (DWORD)&kGetPlayer->_pNormalAttack - (DWORD)kGetPlayer, kGetPlayer->_pNormalAttack);
//	__oMsg("[%x - %x] nIsMove                  = %d", &kGetPlayer->nIsMove, (DWORD)&kGetPlayer->nIsMove - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsMove);
//
//	__oMsg("[%x - %x] nIS_MOVE_1               = %d", &kGetPlayer->nIS_MOVE_1, (DWORD)&kGetPlayer->nIS_MOVE_1 - (DWORD)kGetPlayer, kGetPlayer->nIS_MOVE_1);
//	__oMsg("[%x - %x] nIS_MOVE_2               = %d", &kGetPlayer->nIS_MOVE_2, (DWORD)&kGetPlayer->nIS_MOVE_2 - (DWORD)kGetPlayer, kGetPlayer->nIS_MOVE_2);
//	__oMsg("====> IS_MOVE_NEW				   = %d", (kGetPlayer->nIS_MOVE_1 == 0) & (kGetPlayer->nIS_MOVE_2 != 0));
//
//	__oMsg("[%x - %x] nLevel                   = %d", &kGetPlayer->nLevel, (DWORD)&kGetPlayer->nLevel - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nLevel);
//	__oMsg("[%x - %x] nRemainingPoint          = %d", &kGetPlayer->nRemainingPoint, (DWORD)&kGetPlayer->nRemainingPoint - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nRemainingPoint);
//	
//	__oMsg("[%x - %x] DWORD _pItem[0]]         = %x", &kGetPlayer->_pItem, (DWORD)&kGetPlayer->_pItem - (DWORD)kGetPlayer, kGetPlayer->_pItem);

	//__oMsg("GetPMove_Test() = [%x]", GetPMove_Test());
	//__oMsg("GetCDBA_Test()  = %f", GetCDBA_Test());

	//if(GetCDBA_Test() < 0x5000)	__oMsg("... GetCDBA_Test() < 0x5000"); 
return;

	//__oMsg("isTurret    :  %d", IS_TURRET(kGetPlayer));
	//__oMsg("IsChampion  :  %d", IS_HERO(kGetPlayer));
	//__oMsg("IsMinion    :  %d", IS_MINION(kGetPlayer));
	//__oMsg("IsNexus     :  %d", IS_NEXUS(kGetPlayer));
	//__oMsg("IsInhibitor :  %d", IS_INHIBITOR(kGetPlayer));

	//__oMsg("BoundingRadius :  %f", GetBoundingRadius(kGetPlayer));

////-----------------------------------------------------
//
////return;
//
//
////========= THONG TIN pMOVE ==================================================================================================
//	__oMsg("\n");
//	__oMsg("======================= pMOVE : ==========================");
//	//DWORD movNote = (DWORD)kGetPlayer->_pMOVE;
//	//DWORD strMove  = *(DWORD*)(movNote + 4);
//	//stMOVE *destPos = (stMOVE *)strMove;
//	DWORD movNote = GET_PMOVE_NEW(kGetPlayer);
//	stMOVE *destPos = (stMOVE *)movNote;
//	if (destPos)
//	{
//		__oMsg("[%x]pMOVE:", destPos);
//		__oMsg("[%x - %x]IS MOVING(OLD)     = %d", &destPos->nIsMoving, (DWORD)&destPos->nIsMoving - (DWORD)destPos, (BYTE)destPos->nIsMoving);
//		__oMsg("[%x]IS MOVE					= %d", &kGetPlayer->nIsMove, (BYTE)kGetPlayer->nIsMove);
//		__oMsg("[%x - %x]POSITION_E_OLD     = %f,%f,%f", &destPos->__strPosDest_OLD.x, (DWORD)&destPos->__strPosDest_OLD.x - (DWORD)destPos, destPos->__strPosDest_OLD.x, destPos->__strPosDest_OLD.y, destPos->__strPosDest_OLD.z);
//		__oMsg("[%x - %x]POSITION-END       = %f,%f,%f)", &destPos->__strPosDest.x, (DWORD)&destPos->__strPosDest.x - (DWORD)destPos, destPos->__strPosDest.x, destPos->__strPosDest.y, destPos->__strPosDest.z);
//		__oMsg("[%x - %x]POSITION-START     = %f,%f,%f)", &destPos->__strPosStart.x, (DWORD)&destPos->__strPosStart.x - (DWORD)destPos, destPos->__strPosStart.x, destPos->__strPosStart.y, destPos->__strPosStart.z);
//		__oMsg("[%x - %x]nWayPoint_Start    = %x)", &destPos->nWayPoint_Start, (DWORD)&destPos->nWayPoint_Start - (DWORD)destPos, destPos->nWayPoint_Start);
//		__oMsg("[%x - %x]nWayPoint_End      = %x)", &destPos->nWayPoint_End, (DWORD)&destPos->nWayPoint_End - (DWORD)destPos, destPos->nWayPoint_End);
//		__oMsg("[%x - %x]nWayPoint_MaxEnd   = %x)", &destPos->nWayPoint_MaxEnd, (DWORD)&destPos->nWayPoint_MaxEnd - (DWORD)destPos, destPos->nWayPoint_MaxEnd);
//		__oMsg("[%x - %x]nIsDash            = %d)", &destPos->nIsDash, (DWORD)&destPos->nIsDash - (DWORD)destPos, (BYTE)destPos->nIsDash);
//		__oMsg("[%x - %x]nDashSpeed         = %f)", &destPos->nDashSpeed, (DWORD)&destPos->nDashSpeed - (DWORD)destPos, destPos->nDashSpeed);
//		__oMsg("[%x - %x]IsDashing_Old      = %d", &destPos->nIsDashing, (DWORD)&destPos->nIsDashing - (DWORD)destPos, (BYTE)destPos->nIsDashing);
//		__oMsg("[%x - %x]nIsDashGravity     = %d)", &destPos->nDashGravity, (DWORD)&destPos->nDashGravity - (DWORD)destPos, (BYTE)destPos->nDashGravity);
//		__oMsg("[%x - %x]IS IN FOG_1        = %d", &destPos->nIsInFog, (DWORD)&destPos->nIsInFog - (DWORD)destPos, (BYTE)destPos->nIsInFog);
//		__oMsg("[%x - %x]IS IN FOG_2		= %d", &destPos->nInFog2, (DWORD)&destPos->nInFog2 - (DWORD)destPos, (WORD)destPos->nInFog2);
//	}
//	else __oMsg("GetPMove_Test() = 000"); 
////return;

////========= THONG TIN NORMAL-ATTACK && pCASTSPELL =============================================================================
//	__oMsg("\n");
//	__oMsg("======================= NORMAL-ATTACK && pCASTSPELL : ==========================");
//	//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)kGetPlayer->_pNormalAttack;
//	//if (_stNORMAL_ATTACK)
//		__oMsg("Get_BasicAttack(): %x", Get_BasicAttack());
//
//		//__oMsg("[%x]CooldownExpires = %f", (DWORD)&kGetPlayer->nCooldownExpiresBA, kGetPlayer->nCooldownExpiresBA);
//		//__oMsg("[%x]CooldownExpires = %f", (DWORD)&kGetPlayer->nCooldownExpiresBA, GetCDBA_Test());// ko hieu sao cu cho (DWORD)&kGetPlayer->nCooldownExpiresBA vao la crash
//
//		__oMsg("GetCDBA_Test()  = %f", GET_CDBA_NEW(kGetPlayer));
//		__oMsg("GetCDBA_Test()  = %f", GET_CDBA_NEW(kGetPlayer));
//		__oMsg("-----------------------------");
//	if (kGetPlayer->_pCastSpell != 0)
//	{
//		KCastSpell *pCastSpell = (KCastSpell *)kGetPlayer->_pCastSpell;
//		__oMsg("[%x - %x]pCASTSPELL - __pK_str2 = %x:", pCastSpell, (DWORD)&pCastSpell->__pK_str2 - (DWORD)pCastSpell, pCastSpell->__pK_str2);
//		__oMsg("[%x - %x]nMy_ID_1		= %x", &pCastSpell->nMy_ID_1, (DWORD)&pCastSpell->nMy_ID_1 - (DWORD)pCastSpell, pCastSpell->nMy_ID_1);
//		__oMsg("[%x - %x]nMy_ID_2		= %x", &pCastSpell->nMy_ID_2, (DWORD)&pCastSpell->nMy_ID_2 - (DWORD)pCastSpell, pCastSpell->nMy_ID_2);
//		__oMsg("-----------------------------");
//		__oMsg("Skill Position: ");
//		__oMsg("[%x - %x]Source          = %f, %f, %f", &pCastSpell->SourcePos.x,  (DWORD)&pCastSpell->SourcePos.x - (DWORD)pCastSpell, pCastSpell->SourcePos.x,  pCastSpell->SourcePos.y,  pCastSpell->SourcePos.z);
//		__oMsg("[%x - %x]MaxDest         = %f, %f, %f", &pCastSpell->MaxDestPos.x, (DWORD)&pCastSpell->MaxDestPos.x - (DWORD)pCastSpell, pCastSpell->MaxDestPos.x, pCastSpell->MaxDestPos.y, pCastSpell->MaxDestPos.z);
//		__oMsg("[%x - %x]Mouse           = %f, %f, %f", &pCastSpell->MousePos.x,   (DWORD)&pCastSpell->MousePos.x - (DWORD)pCastSpell, pCastSpell->MousePos.x,   pCastSpell->MousePos.y,   pCastSpell->MousePos.z);
//		__oMsg("[%x - %x]nEnemy_ID		 = %x", &pCastSpell->nEnemy_ID, (DWORD)&pCastSpell->nEnemy_ID - (DWORD)pCastSpell, pCastSpell->nEnemy_ID);
//		__oMsg("[%x - %x]nDelay_AAAnimate    = %f", &pCastSpell->nDelay_AAAnimate, (DWORD)&pCastSpell->nDelay_AAAnimate - (DWORD)pCastSpell, pCastSpell->nDelay_AAAnimate);
//		__oMsg("[%x - %x]nDelay_AAAnimate_2  = %f", &pCastSpell->nDelay_AAAnimate_2, (DWORD)&pCastSpell->nDelay_AAAnimate_2 - (DWORD)pCastSpell, pCastSpell->nDelay_AAAnimate_2);
//		__oMsg("[%x - %x]nCoolDownAA		    = %f", &pCastSpell->nCoolDownAA, (DWORD)&pCastSpell->nCoolDownAA - (DWORD)pCastSpell, pCastSpell->nCoolDownAA);
//		__oMsg("[%x - %x]nSlot			    = %d", &pCastSpell->nSlot, (DWORD)&pCastSpell->nSlot - (DWORD)pCastSpell, (BYTE)pCastSpell->nSlot);
//		__oMsg("[%x - %x]nTime_BatDauBan     = %f", &pCastSpell->nTime_BatDauBAN, (DWORD)&pCastSpell->nTime_BatDauBAN - (DWORD)pCastSpell, pCastSpell->nTime_BatDauBAN);
//		__oMsg("[%x - %x]nTime_DanBatDauBay  = %f", &pCastSpell->nTime_DanBatDauBay, (DWORD)&pCastSpell->nTime_DanBatDauBay - (DWORD)pCastSpell, pCastSpell->nTime_DanBatDauBay);
//		__oMsg("[%x - %x]nTime_CooldownExpires_AA= %f", &pCastSpell->nTime_CDExpiresAA, (DWORD)&pCastSpell->nTime_CDExpiresAA - (DWORD)pCastSpell, pCastSpell->nTime_CDExpiresAA);
//		KSkill_2* pSkill_2 = (KSkill_2*)pCastSpell->__pK_str2;
//		if(pSkill_2)
//		{
//			__oMsg("Name: %s - __pK_str3 = %x [%x]", pSkill_2->GetSkillName(), pSkill_2->__pK_str3, (DWORD)&pSkill_2->__pK_str3 - (DWORD)pSkill_2);
//			KMissile_Struct_3* pStruct_3 = (KMissile_Struct_3*)pSkill_2->__pK_str3;
//			if(pStruct_3)
//			{
//				__oMsg("[%x]nRange	    = %f [%x]", &pStruct_3->nRange, pStruct_3->nRange, (DWORD)&pStruct_3->nRange - (DWORD)pStruct_3);
//				__oMsg("[%x]nRange_2    = %f [%x]", &pStruct_3->nRange_2, pStruct_3->nRange_2, (DWORD)&pStruct_3->nRange_2 - (DWORD)pStruct_3);
//				__oMsg("[%x]nRadius	    = %f [%x]", &pStruct_3->nRadius, pStruct_3->nRadius, (DWORD)&pStruct_3->nRadius - (DWORD)pStruct_3);
//				__oMsg("[%x]nSpeed      = %f [%x]", &pStruct_3->nMissileSpeed, pStruct_3->nMissileSpeed, (DWORD)&pStruct_3->nMissileSpeed - (DWORD)pStruct_3);
//				__oMsg("[%x]nWidth	    = %f [%x]", &pStruct_3->nMissileWidth, pStruct_3->nMissileWidth, (DWORD)&pStruct_3->nMissileWidth - (DWORD)pStruct_3);
//			}
//		}
//	}
//	else
//	{
//		__oMsg("pCastSpell : nEnemy_ID = [xxxxxxx] (Chua Cast Spell)");
//	}
//
////========= THONG TIN TIME_GAME ================================================================================================
//	__oMsg("\n");
//	__oMsg("======================= TIME_GAME : ============================================");
//	__oMsg("TIME_GAME_OLD  = %f", GetTimeGame_OLD());
//	//__oMsg("TIME_GAME_NEW  = %f", GetTimeGame());
//	
//	__oMsg("TIME_GAME_DUBI = %f", GetTimeGame_Dubi());
//
////return;

////========= THONG TIN SKILL ====================================================================================================
//	__oMsg("\n");
//	__oMsg("======================= SKILL INFORMATION : ====================================");
//	KSkill*   pSkillQ = (KSkill*) kGetPlayer->_pSkill[0];
//	KSkill*   pSkillW = (KSkill*) kGetPlayer->_pSkill[1];
//	KSkill*   pSkillE = (KSkill*) kGetPlayer->_pSkill[2];
//	KSkill*   pSkillR = (KSkill*) kGetPlayer->_pSkill[3];
//	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillQ, &pSkillQ->nLevel, (DWORD)&pSkillQ->nLevel - (DWORD)pSkillQ, (BYTE)pSkillQ->nLevel);
//	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillQ, &pSkillQ->nCooldownExpires, (DWORD)&pSkillQ->nCooldownExpires - (DWORD)pSkillQ, pSkillQ->nCooldownExpires);
//	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillQ, &pSkillQ->nStack, (DWORD)&pSkillQ->nStack - (DWORD)pSkillQ, (BYTE)pSkillQ->nStack);
//	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillQ, &pSkillQ->nCooldownExpires_3, (DWORD)&pSkillQ->nCooldownExpires_3 - (DWORD)pSkillQ, pSkillQ->nCooldownExpires_3);
//	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillQ, &pSkillQ->nToggle, (DWORD)&pSkillQ->nToggle - (DWORD)pSkillQ, (BYTE)pSkillQ->nToggle);
//	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillQ, &pSkillQ->nTotalCooldown, (DWORD)&pSkillQ->nTotalCooldown - (DWORD)pSkillQ, pSkillQ->nTotalCooldown);
//	
//	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillW, &pSkillW->nLevel, (DWORD)&pSkillW->nLevel - (DWORD)pSkillW, (BYTE)pSkillW->nLevel);
//	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillW, &pSkillW->nCooldownExpires, (DWORD)&pSkillW->nCooldownExpires - (DWORD)pSkillW, pSkillW->nCooldownExpires);
//	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillW, &pSkillW->nStack, (DWORD)&pSkillW->nStack - (DWORD)pSkillW, (BYTE)pSkillW->nStack);
//	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillW, &pSkillW->nCooldownExpires_3, (DWORD)&pSkillW->nCooldownExpires_3 - (DWORD)pSkillW, pSkillW->nCooldownExpires_3);
//	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillW, &pSkillW->nToggle, (DWORD)&pSkillW->nToggle - (DWORD)pSkillW, (BYTE)pSkillW->nToggle);
//	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillW, &pSkillW->nTotalCooldown, (DWORD)&pSkillW->nTotalCooldown - (DWORD)pSkillW, pSkillW->nTotalCooldown);
//
//	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillE, &pSkillE->nLevel, (DWORD)&pSkillE->nLevel - (DWORD)pSkillE, (BYTE)pSkillE->nLevel);
//	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillE, &pSkillE->nCooldownExpires, (DWORD)&pSkillE->nCooldownExpires - (DWORD)pSkillE, pSkillE->nCooldownExpires);
//	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillE, &pSkillE->nStack, (DWORD)&pSkillE->nStack - (DWORD)pSkillE, (BYTE)pSkillE->nStack);
//	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillE, &pSkillE->nCooldownExpires_3, (DWORD)&pSkillE->nCooldownExpires_3 - (DWORD)pSkillE, pSkillE->nCooldownExpires_3);
//	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillE, &pSkillE->nToggle, (DWORD)&pSkillE->nToggle - (DWORD)pSkillE, (BYTE)pSkillE->nToggle);
//	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillE, &pSkillE->nTotalCooldown, (DWORD)&pSkillE->nTotalCooldown - (DWORD)pSkillE, pSkillE->nTotalCooldown);
//
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillR, &pSkillR->nLevel, (DWORD)&pSkillR->nLevel - (DWORD)pSkillR, (BYTE)pSkillR->nLevel);
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillR, &pSkillR->nCooldownExpires, (DWORD)&pSkillR->nCooldownExpires - (DWORD)pSkillR, pSkillR->nCooldownExpires);
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillR, &pSkillR->nStack, (DWORD)&pSkillR->nStack - (DWORD)pSkillR, (BYTE)pSkillR->nStack);
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillR, &pSkillR->nCooldownExpires_3, (DWORD)&pSkillR->nCooldownExpires_3 - (DWORD)pSkillR, pSkillR->nCooldownExpires_3);
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillR, &pSkillR->nToggle, (DWORD)&pSkillR->nToggle - (DWORD)pSkillR, (BYTE)pSkillR->nToggle);
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillR, &pSkillR->nTotalCooldown, (DWORD)&pSkillR->nTotalCooldown - (DWORD)pSkillR, pSkillR->nTotalCooldown);
//
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires_2(Leblanc) = %f", pSkillR, &pSkillR->nCooldownExpires_2, (DWORD)&pSkillR->nCooldownExpires_2 - (DWORD)pSkillR, pSkillR->nCooldownExpires_2);
//	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nTotalCooldown_2(Leblanc)   = %f", pSkillR, &pSkillR->nTotalCooldown_2, (DWORD)&pSkillR->nTotalCooldown_2 - (DWORD)pSkillR, pSkillR->nTotalCooldown_2);
//	__oMsg("--------------------------------");
//	KSkill_2*  pKSkill_Q = (KSkill_2*) pSkillQ->__pK_str2;
//	__oMsg(" [-Q-] [%x]pK Skill 2[%x - %x] = %x ",&pSkillQ->__pK_str2, (DWORD)&pSkillQ->__pK_str2 - (DWORD)pSkillQ, (DWORD)pSkillQ->__pK_str2);
//	if (pKSkill_Q)
//		__oMsg(" [-Q-] [%x]pK Skill 2[%x - %x] -- SkillName = %s", (DWORD)pKSkill_Q, &pKSkill_Q->szName, (DWORD)&pKSkill_Q->szName - (DWORD)pKSkill_Q, pKSkill_Q->GetSkillName());
////return;

////========= THONG TIN VE BUFF ===================================================================================================
//	__oMsg("\n");
//	__oMsg("======================= BUFF INFORMATION : ====================================");
//	int nBuff_Count = (pNpc->pMax_Buffs - pNpc->pBuffs)/8;
//	for(int i=0; i< nBuff_Count; i++){
//		DWORD dw = *(DWORD*)(pNpc->pBuffs + 8*i);
//		KBuffs* pBuffs = (KBuffs*)dw;
//		if(pBuffs->nIndex == -1) continue;
//		KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
//		if(!pBuffs_1) continue;
//		if ((BYTE)pBuffs->nIndex != 26) continue;
//
//		__oMsg("[Type = %d][%x]Buff Name:  %s",(BYTE)pBuffs->nIndex, pBuffs, pBuffs_1->szName);
//		__oMsg(" - [%x - %x]begin_time  = %f, [%x - %x]end_time  = %f", &pBuffs->nBegin_Time, (DWORD)&pBuffs->nBegin_Time - (DWORD)pBuffs, pBuffs->nBegin_Time ,    /*----*/   &pBuffs->nEnd_Time, (DWORD)&pBuffs->nEnd_Time - (DWORD)pBuffs, pBuffs->nEnd_Time);
//		__oMsg(" - [%x - %x]start_count = %x, [%x - %x]end_count = %x --> [Stacks = %d]", &pBuffs->nStart_Count, (DWORD)&pBuffs->nStart_Count - (DWORD)pBuffs, pBuffs->nStart_Count,  /*----*/   &pBuffs->nEnd_Count, (DWORD)&pBuffs->nEnd_Count - (DWORD)pBuffs, pBuffs->nEnd_Count, (pBuffs->nEnd_Count - pBuffs->nStart_Count)/8);
//		__oMsg(" - [%x - %x]nCountz     = %d", &pBuffs->nCount, (DWORD)&pBuffs->nCount - (DWORD)pBuffs, pBuffs->nCount);
//		__oMsg(" - [%x - %x]nOwnerData  = %x", &pBuffs->__pOwenerData, (DWORD)&pBuffs->__pOwenerData - (DWORD)pBuffs, pBuffs->__pOwenerData);
//		if(pBuffs->__pOwenerData)
//		{
//			KBuff_OwnerData* pOwnerData = (KBuff_OwnerData*)pBuffs->__pOwenerData;
//			__oMsg("   pOwnerData = %x", pBuffs->__pOwenerData);
//			__oMsg(" - [%x - %x]pOwnerNpc     = %x", &pOwnerData->pOwnerNpc, (DWORD)&pOwnerData->pOwnerNpc - (DWORD)pOwnerData, pOwnerData->pOwnerNpc);
//			__oMsg(" - [%x - %x]pOwnerId      = %x", &pOwnerData->nOwnerId, (DWORD)&pOwnerData->nOwnerId - (DWORD)pOwnerData, pOwnerData->nOwnerId);
//			__oMsg(" - [%x - %x]pOwnerNetId   = %x", &pOwnerData->nOwnerNetworkId, (DWORD)&pOwnerData->nOwnerNetworkId - (DWORD)pOwnerData, pOwnerData->nOwnerNetworkId);
//		}
//		__oMsg("[..]======>> CHU Y CHECK : nLua_pBuff = *(DWORD*)(pBaseScriptBuff + 0xC) --> ben trong OnRemoveBuff");
//		__oMsg("-------------------------------------------------------------------");
//	}
////return;


////========= CHECK WALL ==========================================================================================================
//	__oMsg("\n");
//	__oMsg("======================= CHECK WALL : ====================================");
//	KPos* mousePos = GetMousePos();
//	__oMsg("Mouse Cursor: [%x] = %.2f, %.2f, %.2f", &mousePos->x, mousePos->x, mousePos->y, mousePos->z);
//	__oMsg("Wall        : %d ",IsWall(mousePos));
//	__oMsg("--------------------------------");
//	__oMsg("IS_CHATTING : %d",IS_CHATTING());
//	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	DWORD nTempBASE_ENDGAME = BASE_ENDGAME - TEMP_ENTRY_POINT + hModule;
//	DWORD dw1 = *(DWORD*)nTempBASE_ENDGAME;
//	__oMsg("End Game    : %d", *(DWORD*)(dw1 + 8));		// = 2 : dang hoat dong; =3,4,5 ket thuc game
////return;


//	DWORD hModule1 = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule1;
//	DWORD dw1_1 = *(DWORD*)nTempBASE_SKILL;
//	if(!dw1_1) return;
//	DWORD dw2_2 = *(DWORD*)(dw1_1 + 0xC);
//	if(!dw2_2) return;
//	KHackZoom* pHackZoom = (KHackZoom*)dw2_2;
//	__oMsg("[%x] HackZoom: %f",&pHackZoom->nHackZoom, pHackZoom->nHackZoom);// ban dau la 1.28
//	__oMsg("pDecive  : %x",Get_Device());
//	__oMsg("pRenderer: %x",GetRenderer());
////return;	


	//DWORD nEndSceneFuncion = 111;
	//DWORD* vtbl = 0;
	//DWORD table = FindPattern((DWORD)GetModuleHandle( (sz__d3d9_dll)), 0x128000,     (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86",  (sz__xx____xx____xx) );
	//if (table != 0)
	//{
	//	memcpy(&vtbl, (void*)(table+2), 4);
	//	nEndSceneFuncion = vtbl[42];
	//}

	//__oMsg("nEndSceneFuncion-d3d9 = [%x]", nEndSceneFuncion);


//	DWORD hModule2 = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	DWORD nTempBASE_SKILL1 = BASE_SKILL - TEMP_ENTRY_POINT + hModule2;
//	DWORD dw1_1_1 = *(DWORD*)nTempBASE_SKILL1;
//	DWORD dw2_3_1 = *(DWORD*)(dw1_1_1 + 0x24);
//	__oMsg("ECX_RCLICK_MOVE_FUNC: %x ==> [x=%d, y=%d]",dw2_3_1, *(DWORD*)(dw2_3_1 + 0x68), *(DWORD*)(dw2_3_1 + 0x6C) );
//	__oMsg("GetGameCursorPos:  [x=%f, y=%f]", GetGameCursorPos().x, GetGameCursorPos().y);
//    DWORD dw2_4 = *(DWORD*)(dw1_1_1 + 0x30);
//	if(!dw2_4) return;
//	KSelectTarget* pSelectTarget = (KSelectTarget*)dw2_4;
//	__oMsg("[%x]nSelectOrNot      = %d", &pSelectTarget->nSelectOrNot, (BYTE)pSelectTarget->nSelectOrNot);
//	__oMsg("nIDTargetSelected = %x",pSelectTarget->nIDTargetSelected);
//	__oMsg("GAA_Animate: %f - AADelay : %f ", Get_AA_Animate_Delay(), Get_AA_Delay());
//	__oMsg("Ping: %d", GetPingGame());
//	__oMsg("GetObjectByID        : %x", GetObjectByID(kGetPlayer->nID));
//	__oMsg("GetObjectByNetworkID : %x", GetObjectByNetworkID(kGetPlayer->nIndex));
////return;

	////--------ITEM---------------------------------
	//KItem *pItem = (KItem*)kGetPlayer->_pItem[0];// Item[0]
	//if(pItem)
	//{
	//	//__oMsg("[pItem] : %x", pItem);
	//	KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
	//	if(pItem_1)
	//	{
	//		//__oMsg("[pItem_1] : %x", pItem_1);
	//		KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
	//		if(pItem_2) __oMsg("[Name] : %s - ID = %x", pItem_1->pName, pItem_2->nID);
	//	}
	//	
	//}
//__oMsg("------ LUU Y CHUA CHECK TRONG OnCreateObject-->[GetMissileOwner_Name]------- \n\n");
	
	

	
//==========================================================================================================================================================

//	//////////////////////////////////////
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
static float tickTest = 0;
KNpc* fuck = 0;
void Get_All_ObjectGame()
{
	return;
	//__try
	//{
	//	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	//	if (hModule == NULL) return;

	//	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + hModule;

	//	DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
	//	DWORD dw1 = *(DWORD*)dw0;
	//	if(!dw1) return;

	//	int nCount_n = *(DWORD*)(dw0 + 4);
	//	if (!nCount_n) return;

	//	for (int kk = 0; kk < nCount_n; ++kk)
	//	{
	//		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//		if (dw3 == 0) continue;
	//		KNpc *object = (KNpc*)dw3;
	//		if(object->nIndex < 0x3FFFFCC8) continue;
	//		//if(CheckName("reticle_self", object->GetNameNpc())/* && CheckName(".troy", object->GetNameNpc())*/)
	//		if(CheckName("SivirQMissile", object->GetNameNpc())/* && CheckName(".troy", object->GetNameNpc())*/)
	//		{
	//			tickTest = GetTimeGame();
	//			fuck = object;
	//			//__oMsg("1[%x]--name: %s :%x, :%x [del: %d - %f][%f,%f,%f][%f,%f,%f]\n", object->nTeam_ID, object->GetNameNpc(), object->nIndex, object->nType_1, (BYTE)object->nDeleted, GetTimeGame(), object->currentPos().x, object->currentPos().y, object->currentPos().z, object->MissileDestPos.x, object->MissileDestPos.y, object->MissileDestPos.z);
	//		}
	//		//if(CheckName("SivirQMissileReturn", object->GetNameNpc())/* && CheckName(".troy", object->GetNameNpc())*/)
	//		//{
	//		//	tickTest = GetTimeGame();
	//		//	fuck = object;
	//		//	__oMsg("2--name: %s :%x, :%x [del: %d - %f][%f,%f,%f][%f,%f,%f]\n", object->GetNameNpc(), object->nIndex, object->nType_1, object->nDeleted, GetTimeGame(), object->currentPos().x, object->currentPos().y, object->currentPos().z, object->ServerPosition.x, object->ServerPosition.y, object->ServerPosition.z);
	//		//}
	//	}
	//	if(fuck)
	//	{
	//		if(GetTimeGame() - tickTest < 0.2)
	//		{
	//			__oMsg("TEST: %x {%f}", (BYTE)fuck->nDeleted, GetTimeGame());
	//		}
	//	}
	//}
	//__except(EXCEPTION_EXECUTE_HANDLER)
	//{ 
	//	__oMsg("error ...."); 
}


//void Test_misile()
//{
//	////return;
//
//	//KNpc* myHero = GetPlayer();
//	//if(!myHero) return;
//	//
//	//DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	//if (hModule == 0) return;
//
//	////------//------//------:
//	//DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//	//DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
//	//if (!dw0) return;
//
//	//DWORD dw1 = *(DWORD*)(dw0 + 8);
//	//if (!dw1) return;
//
//	//int nCount_xxx = *(DWORD*)(dw0 + 0xC);
//	//if (!nCount_xxx) return;
//
//	//for (int kk = 0; kk < nCount_xxx; ++kk)
//	//{
//	//	DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//	//	if (dw3 == 0) continue;
//	//	KNpc *missileObj = (KNpc*)dw3;
//	//	if (IS_OBJ_DELETED(missileObj, "123") == true)	 continue;
//
//	//	//if(missileObj->nIndex < 0x3FFFFCC8)      continue;
//	//	//if(!IS_OBJECT_TYPE(missileObj, 0x8000))	 continue;
//	//	
//	//	if (CheckName("SRU", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("sru", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Sru", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("LevelProp", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Barracks", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Turret", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Swain_", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("candle_", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Plinths_", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("Plant", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("_T1", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("_T2", missileObj->GetNameNpc())) continue;
//	//	if (CheckName("monsterCamp", missileObj->GetNameNpc())) continue;
//	//	
//	//	
//	//	////if (CheckName("Ashe", missileObj->GetNameNpc()))		//if (IS_OBJECT_TYPE(missileObj, 0x8001))
//	//	////{
//	//	////	KMissileData* misData = (KMissileData*)missileObj->nMissileData;
//	//	////	//__oMsg("[%x]misData: %x - OwnerID_1: %x - OwnerID_2: %x", missileObj, missileObj->nMissileData, missileObj->nMissileOwnerID_1, missileObj->nMissileOwnerID_2);
//	//	////	__oMsg("----------- misData: %x [%s] - type: %x", misData, missileObj->GetNameNpc(), OBJECT_TYPE(missileObj));
//	//	////	//return;
//	//	////}
//
//
//	//	if (CheckName("Tristana", missileObj->GetNameNpc()) && IS_OBJECT_TYPE(missileObj, 0x8000))
//	//	{
//	//		KMissileData* misData = (KMissileData*)missileObj->nMissileData;
//	//		__oMsg_2("[%x]misData: %x - OwnerID_1: %x - OwnerID_2: %x", missileObj, missileObj->nMissileData, missileObj->nMissileOwnerID_1, missileObj->nMissileOwnerID_2);
//	//		__oMsg_2("----------- misData: %x", misData);
//	//		//return;
//	//		//__oMsg("Temp[0]: %x", missileObj->nTemp_9_12[0]);
//	//		//__oMsg("Temp[1]: %x", missileObj->nTemp_9_12[1]);
//	//		//__oMsg("Temp[2]: %x", missileObj->nTemp_9_12[2]);
//	//		//__oMsg("Temp[3]: %x", missileObj->nTemp_9_12[3]);
//	//		//__oMsg("Temp[4]: %x", missileObj->nTemp_9_12[4]);
//	//		//__oMsg("Temp[5]: %x", missileObj->nTemp_9_12[5]);
//	//		//__oMsg("Temp[6]: %x", missileObj->nTemp_9_12[6]);
//	//		
//	//		if (misData)
//	//		{
//	//			KMissile_Struct_3* pMiss_Struct_3 = (KMissile_Struct_3*)misData->nMissile_Struct_3;
//	//			if (pMiss_Struct_3)
//	//			{
//	//				__oMsg_2("MisSpeed: %f (%.2f - %.2f), %s, %s [src: %.3f, %.3f, %.3f][des: %.3f, %.3f, %.3f][cursor: %.3f, %.3f, %.3f]",pMiss_Struct_3->nMissileSpeed, pMiss_Struct_3->nMissileMinSpeed, pMiss_Struct_3->nMissileMaxSpeed, misData->GetMissileOwner_Name(), missileObj->GetNameNpc(), missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z, missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z, missileObj->MissileCursorPos.x, missileObj->MissileCursorPos.y, missileObj->MissileCursorPos.z);
//	//			}
//	//		}
//	//	}
//	//	
//	//}	
//}