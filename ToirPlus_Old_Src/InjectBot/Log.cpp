#include "Log.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
using namespace std;

//==================================================================================//
//==================================================================================//
//==================================================================================//
//bool __oMsg(const char * format, ...)
//{
//	char buffer[1000];
//
//	va_list argptr;
//	va_start(argptr, format);
//	vsprintf_s(buffer, format, argptr);
//	va_end(argptr);
//
//	strcat_s(buffer, "\n");
//	//const wchar_t *wbuff = C2W(buffer); 
//	OutputDebugString(buffer);
//	//delete []wbuff;
//	return true;
//}

////==================================================================================//
//bool __oMsg_PrintFile(const char * format, ...)
//{
//	//-----------------------------:
//	if (chi1lan == true)
//	{
//		//vai_logFile = 0;
//		if (!vai_logFile) 
//		{
//			wstring filepathBase = L"D:\\___WORKING\\Temp\\FOR_ADDRESS\\Release\\PRINT_XXX.h";	//D:\\___WORKING\\Temp\\FOR_ADDRESS\\Release\\riot.dll
//			vai_logFile = CreateFileW(filepathBase.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	
//		}
//		chi1lan = false;
//	}
//	
//	
//
//	//-----------------------------:
//	char buffer[1000] = {0};
//	va_list argptr;
//	va_start(argptr, format);
//	vsprintf_s(buffer, format, argptr);
//	va_end(argptr);
//	strcat_s(buffer, "\n");
//		
//	if (vai_logFile)
//	{
//		DWORD dwBytesWritten = 0;
//		string logme = buffer;
//		WriteFile(vai_logFile, logme.c_str(), logme.size(), &dwBytesWritten, NULL);
//	}
//
//	//if (vai_logFile)
//	//	CloseHandle(vai_logFile);
//
//
//	//freopen("CONOUT$", "w", stdout);
//	//std::cout << buffer ;
//
//	return true;
//}

////==================================================================================//
//bool __oMsg_Console(const char * format, ...)
//{
//	AllocConsole();
//	char buffer[1000];
//
//	va_list argptr;
//	va_start(argptr, format);
//	vsprintf_s(buffer, format, argptr);
//	va_end(argptr);
//	//strcat_s(buffer, "\n");
//
//	freopen("CONOUT$", "w", stdout);
//	std::cout << buffer ;
//
//	return true;
//}


enum TypeLog
{
	NO_LOGG__    = 0,
	DEBUG_VIEW__ = 1,
	CONSOLE__    = 2,
	PRINT_FILE__ = 3,
};

//==================================================================================//
HANDLE vai_logFile = 0;	
bool   chi1lan = true;
bool __oMsg(const char * format, ...)
{
	//int LOG_TYPE = NO_LOGG__;			//<============ ************* QUAN TRONG ******************

	int LOG_TYPE = DEBUG_VIEW__;		//<============ ************* QUAN TRONG ******************

	//int LOG_TYPE = CONSOLE__;			//<============ ************* QUAN TRONG ******************

	//int LOG_TYPE = PRINT_FILE__;		//<============ ************* QUAN TRONG ******************

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
		//const wchar_t *wbuff = C2W(buffer); 
		OutputDebugString(buffer);
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
				wstring filepathBase = L"D:\\___WORKING\\Temp\\FOR_ADDRESS\\Release\\PRINT_XXX.h";	//D:\\___WORKING\\Temp\\FOR_ADDRESS\\Release\\riot.dll
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

//==================================================================================//
extern char* GetIPHost();
//#include "OrbWalker/Prediction.h"


//==================================================================================//
bool IS_CAN_SEE(KNpc* pNpc)		//--not solved yet
{
	if(!pNpc) return true;

	DWORD v1 = *(BYTE *)((DWORD)pNpc + 0x1AC);
	DWORD v2 = (DWORD)pNpc + 0x1A8;
	DWORD v3 = 0;
	DWORD v4 = *(BYTE *)(v2 + 1);
	DWORD v5 = *(BYTE *)(v1 + v2 + 5);
	DWORD v13 = *(BYTE *)(v1 + v2 + 5);
	DWORD result = 0;
	if ( v4 )
	{
		DWORD v6 = v2 + 3;
		do
		{
			DWORD v7 = *(DWORD *)v6;
			v6 += 4;
			//*((DWORD *)&v11 + v3++) ^= ~(v7 /*^ OFF_ENCRYPT_1*/);
			*((DWORD *)&v13 + v3++) ^= ~v7;
		}
		while ( v3 < v4 );
		v5 = v13;
	}
	DWORD v8 = *(BYTE *)(v2 + 2);
	unsigned int v9 = 1 - v8;
	if ( v8 && v9 < 1 )
	{
		DWORD v10 = v9 + v2 + 3;
		do
		{
			BYTE v11 = *(BYTE *)v10++;
			*(&v13 + v9) ^= ~v11;
			++v9;
		}
		while ( v9 < 1 );
		result = v13;
	}
	else
	{
		result = v5;
	}

	return (BYTE)result == 1 ? true : false;
}

//==================================================================================//
bool IS_DEAD(KNpc* pNpc)		//--solved : void __thiscall sub_6420A0(void *this)		case 2:(v8.14)
{
	if(!pNpc) return true;
	int result = 0;

	DWORD v1 = *(BYTE *)((DWORD)pNpc + 0x218);
	DWORD v2 = (DWORD)pNpc + 0x214;
	DWORD v3 = 0;
	DWORD v4 = *(BYTE *)(v2 + 1);
	DWORD v5 = *(BYTE *)(v1 + v2 + 5);
	DWORD v13 = *(BYTE *)(v1 + v2 + 5);
	if ( v4 )
	{
		DWORD v6 = v2 + 3;
		do
		{
			DWORD v7 = *(DWORD *)v6;
			v6 += 4;
			*((DWORD *)&v13 + v3++) ^= ~v7;
		}
		while ( v3 < v4 );
		v5 = v13;
	}
	DWORD v8 = *(BYTE *)(v2 + 2);
	unsigned int v9 = 1 - v8;
	if ( v8 && v9 < 1 )
	{
		DWORD v10 = v9 + v2 + 3;
		do
		{
			BYTE v11 = *(BYTE *)v10++;
			*(&v13 + v9) ^= ~v11;
			++v9;
		}
		while ( v9 < 1 );
		result = v13;
	}
	else
	{
		result = v5;
	}

	return (BYTE)result == 1 ? true : false;
}

//==================================================================================//
DWORD GET_BARSOURCE(KNpc* pNpc)		//--solved : void __thiscall sub_ 627D50		case 2:(v8.16)
{
	if(!pNpc) return 0;

	DWORD result = 0;
	int v30 = 0;
	//__try
	{
		DWORD v3 = (DWORD)pNpc;

		int   v31 = *(BYTE *)(v3 + 0x4949);
		DWORD a3  = *(DWORD *)(v3 + 4 * *(BYTE *)(v3 + 0x4950) +  0x4954);

		if ( v31 )
		{
			DWORD v35 = v3 + 0x494C;
			do
			{
				DWORD v36 = *(DWORD *)v35;
				v35 += 4;
				*(&a3 + v30) ^= ~v36;
				++v30;
			}
			while ( v30 < v31 );
		}

		int v18 = *(BYTE *)(v3 + 0x494A);
		if ( v18 )
		{
			int v19 = 4 - v18;
			if ( (unsigned int)v19 < 4 )
			{
				DWORD v20 = v19 + v3 + 0x494C;
				do
				{
					BYTE v21 = *(BYTE *)v20++;
					*((BYTE *)&a3 + v19++) ^= ~v21;
				}
				while ( (unsigned int)v19 < 4 );
			}
		}
		result = a3;
	}
	/*__except(EXCEPTION_EXECUTE_HANDLER)
	{
		SEND_TEXT_SYSTEM("Err: GET.BARSOURCE");
		return 0;
	}*/

	return result;
}

//==================================================================================//
bool IsMoving(KNpc* pNpc)	//Fixed : 643090 -> GET_BASIC_ATTACK_FUNC_ 5CBBA0 (8.16)
{
	//return IS_MOVE_NEW(pNpc);

	int nAddMore = 9;

	if(!pNpc) return false;	//-- code co gi do chua chuan
	
	DWORD v3 = (DWORD) pNpc;
	int v4 = 0;
	int v5 = *(BYTE *)(v3 + 0x4BFD +nAddMore);
	int v6 = *(BYTE *)(*(BYTE *)(v3 + 0x4C00 +nAddMore) + v3 + 0x4C01 +nAddMore);
	int v44 = v6;
	
	if ( v5 )
	{
		DWORD v7 = v3 + 0x4BFF +nAddMore;
		do
		{
			DWORD v8 = *(DWORD *)v7;
			v7 += 4;
			*((DWORD *)&v44 + v4++) ^= ~v8;
		}
		while ( v4 < v5 );
		v6 = v44;
	}

	int v9 = *(BYTE *)(v3 + 0x4BFE  +nAddMore);
	if ( v9 )
	{
		int v10 = 1 - v9;
		if ( (unsigned int)v10 < 1 )
		{
			DWORD v11 = v10 + v3 + 0x4BFF +nAddMore;
			do
			{
				BYTE v12 = *(BYTE *)v11++;
				*(DWORD*)((BYTE *)&v44 + v10++) ^= ~v12;
			}
			while ( (unsigned int)v10 < 1 );
			v6 = v44;
		}
	}

	return (BYTE)v6 == 1 ? true : false;
}

//==================================================================================//
bool IS_OBJ_DELETED(KNpc* Obj, char* szFuck)			//dung ham nay hay hon, neu ==true ---> doi tuong da~ bi xoa roi, ko ton tai nua
{
	if(!Obj) return true;
	////return (BYTE)Obj->nDeleted == 0 ? true : false;

	DWORD nRs = 0;

	DWORD nFunc = IS_OBJ_DELETED_FUNC - TEMP_ENTRY_POINT + G_Module;		//0x5B4BE0;//(8.22)
	DWORD _ECX  = (DWORD)Obj;

	__asm
	{
		mov ecx, _ECX
			mov eax, nFunc
			call eax
			mov nRs, eax
	}

	return (BYTE)nRs == 0 ? true : false;
}

//---------------------------------------------------------------------//--------------------//
int OBJECT_TYPE(KNpc* obj) // 0x8000 = missile, 0x1000 = Hero, 0x800 = Minion, 0x2000 = Turret ....
{
	if(!obj) return 0;

	DWORD _this = (DWORD)obj;

	DWORD v2  = _this;
	int   v3  = 0;
	BYTE  v4  = *(BYTE *)(_this + 81);
	DWORD v12 = *(DWORD *)(_this + 4 * *(BYTE *)(_this + 88) + 92);
	if ( v4 )
	{
		DWORD v5 = _this + 84;
		do
		{
			DWORD v6 = *(DWORD *)v5;
			v5 += 4;
			*(&v12 + v3) ^= ~v6;
			++v3;
		}
		while ( v3 < v4 );
	}
	BYTE v7 = *(BYTE *)(v2 + 82);
	if ( v7 )
	{
		int v8 = 4 - v7;
		if ( (unsigned int)v8 < 4 )
		{
			DWORD v9 = v8 + v2 + 84;
			do
			{
				BYTE v10 = *(BYTE *)v9++;
				*(DWORD*)((BYTE *)&v12 + v8++) ^= ~v10;
			}
			while ( (unsigned int)v8 < 4 );
		}
	}

	return v12;
}

//==================================================================================//
bool IS_OBJECT_TYPE(KNpc* obj, DWORD objType) // 0x8000 = missile, 0x1000 = Hero, 0x800 = Minion, 0x2000 = Turret ....
{
	if(!obj) return false;

	DWORD _this = (DWORD)obj;

	DWORD v2  = _this;
	int   v3  = 0;
	BYTE  v4  = *(BYTE *)(_this + 81);
	DWORD v12 = *(DWORD *)(_this + 4 * *(BYTE *)(_this + 88) + 92);
	if ( v4 )
	{
		DWORD v5 = _this + 84;
		do
		{
			DWORD v6 = *(DWORD *)v5;
			v5 += 4;
			*(&v12 + v3) ^= ~v6;
			++v3;
		}
		while ( v3 < v4 );
	}
	BYTE v7 = *(BYTE *)(v2 + 82);
	if ( v7 )
	{
		int v8 = 4 - v7;
		if ( (unsigned int)v8 < 4 )
		{
			DWORD v9 = v8 + v2 + 84;
			do
			{
				BYTE v10 = *(BYTE *)v9++;
				*(DWORD*)((BYTE *)&v12 + v8++) ^= ~v10;
			}
			while ( (unsigned int)v8 < 4 );
		}
	}

	return (v12 & objType) == 0 ? false : true;

	return false;	
}


//==================================================================================//
bool sort_Descending_Ranged_Test(KEnemyDistance p1, KEnemyDistance p2)
{
	//if      (p1.pEnemy->nOverrideCollisionRadius > p2.pEnemy->nOverrideCollisionRadius) return true;	//tap trung siege truoc
	//else if (p1.pEnemy->nOverrideCollisionRadius < p2.pEnemy->nOverrideCollisionRadius) return false;
	//if      (p1.pEnemy->nAttackRange < p2.pEnemy->nAttackRange) return true;							//roi den melee, vi melee nhieu tien hon ranged
	//else if (p1.pEnemy->nAttackRange > p2.pEnemy->nAttackRange) return false;
	//if      (p1.nHP > p2.nHP) return true;
	//else if (p1.nHP < p2.nHP) return false;

	return false;
}

void test_sort_x()
{
	KEnemyDistance pUnitAttackable_v[60] = {0};
	int jCount_3 = 0;

	DWORD nTempUnit     = BASE_AttackableUnit - TEMP_ENTRY_POINT + G_Module;
	DWORD nTempUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD dw1 = *(DWORD*)nTempUnit;
	DWORD dw2 = *(DWORD*)nTempUnit_MAX;
	if (!dw1 || !dw2 ) return;
	int nCountUnit = (dw2 - dw1)/4;

	for (int i = 0; i < nCountUnit; ++i)
	{

		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pMinion = (KNpc*)dw3;

		if (!IS_MINION(pMinion))				  continue;		//cho nay L# danh ca "Minion" va "ward"				
		if (Distance_2D(GetPlayer()->CurrentPos.x, GetPlayer()->CurrentPos.z, pMinion->CurrentPos.x, pMinion->CurrentPos.z) > 800) continue; 

		pUnitAttackable_v[jCount_3].nIndex	  = pMinion->nIndex;
		pUnitAttackable_v[jCount_3].pEnemy	  = pMinion;
		pUnitAttackable_v[jCount_3].nHP		  = pMinion->nHP;
		pUnitAttackable_v[jCount_3].nDamage   = pMinion->nBaseAttackDamage + pMinion->nFlat_PhysicalDamageMod;
		//pUnitAttackable_v[jCount_3].fDistance = Distance_2D(pPlayer->CurrentPos, pMinion->CurrentPos);
		jCount_3 = jCount_3 + 1;


		if (jCount_3 > 58) break;
	}

	__oMsg("sort-------------------------");
	std::sort(pUnitAttackable_v, pUnitAttackable_v + jCount_3, sort_Descending_Ranged_Test);	//test
	//std::reverse(pUnitAttackable_v, pUnitAttackable_v + jCount_3);
	for (int i = 0; i < jCount_3; ++i)
	{
		if (pUnitAttackable_v[i].pEnemy == 0) continue;
		if (pUnitAttackable_v[i].nIndex == 0) continue;
		if (GetObjectByNetworkID(pUnitAttackable_v[i].nIndex) != (DWORD)pUnitAttackable_v[i].pEnemy) continue;

		if (IS_DEAD(pUnitAttackable_v[i].pEnemy) == true) continue;

		__oMsg("name: %s - nHP: %.2f - dame: %x", pUnitAttackable_v[i].pEnemy->GetNameHero(), pUnitAttackable_v[i].nHP, pUnitAttackable_v[i].pEnemy->nIndex);
	}




	__oMsg("\nnormal-------------------------");
}

//==================================================================================//
#include "Logger.h"
#include <iostream>
#include "GEN_CODE.h"
void TestTest()
{
	//__oMsg("(threadID: %x - %d)" , GetCurrentThreadId(), GetCurrentThreadId());
	//return;


	//__oMsg("(gameModule: %x)" , GetGameModule());
	//Test_misile();
	//PrintWithConditional(500);
	//return;

	//__oMsgGameF("xxxx");
	//return;

	//__oMsg_2("is-can-see: %d", IsCanSee((KNpc*)0x412ab840));
	//PrintWithConditional(500);

	//return;



//	__oMsg_2("VAI-LOLZ");
//return;

//GENARATE();
return;


	
//return;

	//__oMsg_2("---||=====================");
	//LPCSTR SignatureVN = "\x6A\x01\x6A\x01\x8D\x44\x24\x0C";
	//LPCSTR Mask = "xxxxxxxx";
	
	//GEN_CODE("BASE",  SignatureVN,  Mask, 0x136, 3696 );

	//SignatureScanner SigScanner;
	//SigScanner.GetProcess("League of Legends.exe");
	//SigScanner.GetModule("League of Legends.exe");

	
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
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
VOID CalcDistance()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
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
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void PrintWithConditional(float nRadius)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return;
	int nCount = (dw2 - dw1)/4;

	//DWORD nTempBASE_BASE_ObjectAI = BASE_ObjectAI - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_BASE_ObjectAI_MAX = BASE_ObjectAI_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD dw1_x = *(DWORD*)nTempBASE_BASE_ObjectAI;
	//DWORD dw2_x = *(DWORD*)nTempBASE_BASE_ObjectAI_MAX;
	//int nCount_x = (dw2_x - dw1_x)/4;
	//__oMsg("nCount: %d - nCount_x: %d",nCount,nCount_x);
	KNpc *pPlayer = GetPlayer();
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;

		//if (IS_DEAD(pNpc)) continue;

		if(pNpc != GetPlayer()) continue;
		//if (!IS_HERO(pNpc)) continue;
		//if (!IS_TURRET(pNpc)) continue;
		//__oMsg("sassa");
		//if (!IS_NEXUS(pNpc)) continue;
		//if (!IS_MINION(pNpc)) continue;

		//if (!IS_MINION(pNpc) && !IS_TURRET(pNpc)) continue;

		float nDistance = Distance_3D(pPlayer->CurrentPos.x, pPlayer->CurrentPos.y, pPlayer->CurrentPos.z, pNpc->CurrentPos.x, pNpc->CurrentPos.y, pNpc->CurrentPos.z);
		if (nDistance > nRadius) continue;
		//__oMsg("i=%d - %x", i, pNpc);

		//PrintAllGameInfo(pNpc);
		PrintAllGameInfo_222(pNpc);

	}

	//__oMsg("-----------------------------------  ------");
}

//==================================================================================//
void PrintAllGameInfo_222(KNpc *pNpc)
{
	//if (abs(pNpc->nOverrideCollisionRadius - 140.0f) < FLT_EPSILON)
	//	__oMsg("jelpme : %s", pNpc->GetNameHero());
	//
	////__oMsg("[%d], col: %.2f, bound: %.2f, range: %.2f, AaDelay: %.4f, Animate: %.4f, HeroName: %s", pNpc->nCombatType, pNpc->nOverrideCollisionRadius, GetBoundingRadius(pNpc), pNpc->nAttackRange,
	////	Get_AA_Delay(pNpc), Get_AA_Animate_Delay(pNpc), pNpc->GetNameHero());
	//return;

	//__oMsg("[%x - %s] [%.2f] %.2f - %.2f - [%x]", pNpc, pNpc->GetNameHero(), pNpc->nHP, pNpc->nAttackRange, pNpc->nOverrideCollisionRadius, pNpc->nIndex);
	//return;

	//if (pNpc == NULL /*|| (BYTE)pNpc->nIsTargetableToTeam != 4*/)
	//{
	//	__oMsg("----- NPC bi null hoac XXX- %x", pNpc);
	//	return;
	//}

	////////__oMsg("[%x - %s]: alive: %d, targetAble: %d, cansee: %d, colis : %f - %f ", pNpc, pNpc->GetNameNpc(), IS_ALIVE(pNpc), IS_TARGET_ABLE(pNpc), IS_CAN_SEE(pNpc), pNpc->nOverrideCollisionRadius, GetBoundingRadius(pNpc));
	////////__oMsg("[%x - %s]:  colis : %f - %f ", pNpc, pNpc->GetNameNpc(), pNpc->nOverrideCollisionRadius, GetBoundingRadius(pNpc));
	//////
	//////__oMsg("\n");
	//////__oMsg("%x - %s, COL = %f - %d", pNpc, pNpc->GetNameNpc(), pNpc->nOverrideCollisionRadius, IS_ALIVE(pNpc));
	//__oMsg("%x - %s", pNpc, pNpc->GetNameNpc());
	//__oMsg("Turr: %d, Hero: %d, Mini: %d, Nexus: %d, Inhb: %d", IS_TURRET(pNpc), IS_HERO(pNpc), IS_MINION(pNpc), IS_NEXUS(pNpc), IS_INHIBITOR(pNpc));
	//__oMsg("alive: %d - DEAD: %d, able:%d - %x - %d", IS_ALIVE(pNpc), IS_DEAD(pNpc), IS_TARGET_ABLE(pNpc), pNpc->nIndex, (BYTE)pNpc->nIsTargetableToTeam);
	//__oMsg("----------\n");
	//return;

	//////__oMsg("targetAble = %d", IS_TARGET_ABLE(pNpc));
	//////__oMsg("IsCanSee   = %d ", IsCanSee(pNpc));
	//////__oMsg("colis      = %f - %f", pNpc->nOverrideCollisionRadius, GetBoundingRadius(pNpc));
	//////__oMsg("BoundRadius= %f", GetBoundingRadius(pNpc));
	////__oMsg("--------------\n");

	////return;

	//__oMsg_2("is-can-see: %d - %s - %x", IS_CAN_SEE(pNpc), pNpc->GetNameNpc(), pNpc);
	//return;


	//__oMsg_2("[%x]", pNpc);
	//return;

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

	if (pNpc == NULL)
	{
		__oMsg("NPC bi null");
		return;
	}
	KNpc *kGetPlayer = pNpc;
	
	

	////*********************////***********
	__oMsg("IS_DEAD: %d", IS_DEAD(GetPlayer()));
	__oMsg("IS_ON_SCREEN: %d", IS_CAN_SEE(GetPlayer()));
	__oMsg("IS_MOVE_NEW: %d", IsMoving(GetPlayer()));

	//return;

	

	//__oMsg_2("IS_DEAD: %d - IS_MOVE_NEW: %d - IS_ON_SCREEN: %d", IS_DEAD(GetPlayer()), IsMoving(GetPlayer()), IS_CAN_SEE(GetPlayer()));
	//__oMsg_2("TIME_GAME_NEW  = %f", GetTimeGame());
//return;
//========= THONG TIN pPLAYER ==================================================================================================
	__oMsg("======================= pPLAYER : ==========================");
	__oMsg("[%x]", kGetPlayer);


//	__oMsg_2("[%x - %d]Name = %s - isHero: %d", kGetPlayer, kGetPlayer, kGetPlayer->GetNameNpc(), IS_HERO(kGetPlayer));

	__oMsg("isTurret    :  %d", IS_TURRET(kGetPlayer));

	__oMsg("IsChampion  :  %d", IS_HERO(kGetPlayer));
	__oMsg("IsMinion    :  %d", IS_MINION(kGetPlayer));
	__oMsg("IsNexus     :  %d", IS_NEXUS(kGetPlayer));
	__oMsg("IsInhibitor :  %d", IS_INHIBITOR(kGetPlayer));
	__oMsg("\n");

	__oMsg("[%x - %x] nIs_Nexus                = %x", &kGetPlayer->nIs_Nexus, (DWORD)&kGetPlayer->nIs_Nexus - (DWORD)kGetPlayer, kGetPlayer->nIs_Nexus);
	__oMsg("[%x - %x] nID                      = %x", &kGetPlayer->nID, (DWORD)&kGetPlayer->nID - (DWORD)kGetPlayer, kGetPlayer->nID);
	__oMsg("[%x - %x] nTeam_ID                 = %x", &kGetPlayer->nTeam_ID, (DWORD)&kGetPlayer->nTeam_ID - (DWORD)kGetPlayer, kGetPlayer->nTeam_ID);
	__oMsg("[%x - %x] nType_1                  = %x", &kGetPlayer->nType_1, (DWORD)&kGetPlayer->nType_1 - (DWORD)kGetPlayer, kGetPlayer->nType_1);
//return;
	__oMsg("[%x - %x] szPlayerName             = %s", &kGetPlayer->szPlayerName, (DWORD)&kGetPlayer->szPlayerName - (DWORD)kGetPlayer, kGetPlayer->GetNameNpc());
	__oMsg("[%x - %x] nLen_Name                = %d", &kGetPlayer->nLen_Name, (DWORD)&kGetPlayer->nLen_Name - (DWORD)kGetPlayer, kGetPlayer->nLen_Name);
	__oMsg("[%x - %x] nMaxlen_Name             = %d", &kGetPlayer->nMaxlen_Name, (DWORD)&kGetPlayer->nMaxlen_Name - (DWORD)kGetPlayer, kGetPlayer->nMaxlen_Name);
	__oMsg("[%x - %x] nIndex                   = %x", &kGetPlayer->nIndex, (DWORD)&kGetPlayer->nIndex - (DWORD)kGetPlayer, kGetPlayer->nIndex);
	__oMsg("[%x - %x] BBoxMinPos               = %f, %f, %f", &kGetPlayer->BBoxMin.x, (DWORD)&kGetPlayer->BBoxMin.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMin.x, kGetPlayer->BBoxMin.y, kGetPlayer->BBoxMin.z);
	__oMsg("[%x - %x] BBoxMaxPos               = %f, %f, %f", &kGetPlayer->BBoxMax.x, (DWORD)&kGetPlayer->BBoxMax.x - (DWORD)kGetPlayer, kGetPlayer->BBoxMax.x, kGetPlayer->BBoxMax.y, kGetPlayer->BBoxMax.z);
//return;
	__oMsg("[%x - %x] nDeleted(tim:OnDeleteObj)= %d", &kGetPlayer->nDeleted, (DWORD)&kGetPlayer->nDeleted - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nDeleted);
	__oMsg("[%x - %x] nCanSee                  = %d", &kGetPlayer->nCanSee, (DWORD)&kGetPlayer->nCanSee - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nCanSee);
	__oMsg("[%x - %x] CurrentPos(server)       = %f, %f, %f", &kGetPlayer->ServerPosition.x, (DWORD)&kGetPlayer->ServerPosition.x - (DWORD)kGetPlayer, kGetPlayer->ServerPosition.x, kGetPlayer->ServerPosition.y, kGetPlayer->ServerPosition.z);
	__oMsg("[%x - %x] nIsDie                   = %d", &kGetPlayer->nIsDie, (DWORD)&kGetPlayer->nIsDie - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsDie);
	__oMsg("[%x - %x] CurrentPos               = %f, %f, %f", &kGetPlayer->CurrentPos.x, (DWORD)&kGetPlayer->CurrentPos.x - (DWORD)kGetPlayer, kGetPlayer->CurrentPos.x, kGetPlayer->CurrentPos.y, kGetPlayer->CurrentPos.z);
	__oMsg("[%x - %x] nMissileData             = %x", &kGetPlayer->nMissileData, (DWORD)&kGetPlayer->nMissileData - (DWORD)kGetPlayer, kGetPlayer->nMissileData);
	__oMsg("[%x - %x] nMissileOwnerID_1        = %x", &kGetPlayer->nMissileOwnerID_1, (DWORD)&kGetPlayer->nMissileOwnerID_1 - (DWORD)kGetPlayer, kGetPlayer->nMissileOwnerID_1);
	__oMsg("[%x - %x] nMissileOwnerID_2        = %x", &kGetPlayer->nMissileOwnerID_2, (DWORD)&kGetPlayer->nMissileOwnerID_2 - (DWORD)kGetPlayer, kGetPlayer->nMissileOwnerID_2);
	//__oMsg_2("[%x - %x] nSpawnTime               = %f", &kGetPlayer->nSpawnTime, (DWORD)&kGetPlayer->nSpawnTime - (DWORD)kGetPlayer, kGetPlayer->nSpawnTime);
//return;
	__oMsg("[%x - %x] nMP                      = %f", &kGetPlayer->nMP, (DWORD)&kGetPlayer->nMP - (DWORD)kGetPlayer, kGetPlayer->nMP);
	__oMsg("[%x - %x] nMaxMP                   = %f",& kGetPlayer->nMaxMP, (DWORD)&kGetPlayer->nMaxMP - (DWORD)kGetPlayer, kGetPlayer->nMaxMP);
	__oMsg("[%x - %x] nJhinMissile             = %f", &kGetPlayer->nJhinMissile, (DWORD)&kGetPlayer->nJhinMissile - (DWORD)kGetPlayer, kGetPlayer->nJhinMissile);
	__oMsg("[%x - %x] nIsInvulnerable          = %d", &kGetPlayer->nIsInvulnerable, (DWORD)&kGetPlayer->nIsInvulnerable - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsInvulnerable & 1);
	__oMsg("[%x - %x] nOverrideCollisionRadius = %f", &kGetPlayer->nOverrideCollisionRadius, (DWORD)&kGetPlayer->nOverrideCollisionRadius - (DWORD)kGetPlayer, kGetPlayer->nOverrideCollisionRadius);
	__oMsg("[%x - %x] nIsTargetable            = %d", &kGetPlayer->nIsTargetable, (DWORD)&kGetPlayer->nIsTargetable - (DWORD)kGetPlayer, kGetPlayer->nIsTargetable);
	__oMsg("[%x - %x] nIsTargetableToTeam      = %d", &kGetPlayer->nIsTargetableToTeam, (DWORD)&kGetPlayer->nIsTargetableToTeam - (DWORD)kGetPlayer, kGetPlayer->nIsTargetableToTeam);
	__oMsg("[%x - %x] nIsBasing                = %d", &kGetPlayer->nIsBasing, (DWORD)&kGetPlayer->nIsBasing - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsBasing);
	__oMsg("[%x - %x] nHP                      = %f", &kGetPlayer->nHP, (DWORD)&kGetPlayer->nHP - (DWORD)kGetPlayer, kGetPlayer->nHP);
	__oMsg("[%x - %x] nMaxHP                   = %f", &kGetPlayer->nMaxHP, (DWORD)&kGetPlayer->nMaxHP - (DWORD)kGetPlayer, kGetPlayer->nMaxHP);
//return;
	__oMsg("[%x - %x] nGiapMau                 = %f", &kGetPlayer->nGiap_Mau, (DWORD)&kGetPlayer->nGiap_Mau - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau);
	__oMsg("[%x - %x] nGiap_Mau_Rengar         = %f", &kGetPlayer->nGiap_Mau_Rengar, (DWORD)&kGetPlayer->nGiap_Mau_Rengar - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau_Rengar);
	__oMsg("[%x - %x] nGiap_Mau_AP             = %f", &kGetPlayer->nGiap_Mau_AP, (DWORD)&kGetPlayer->nGiap_Mau_AP - (DWORD)kGetPlayer, kGetPlayer->nGiap_Mau_AP);
	__oMsg("[%x - %x] nModSkinID               = %d", &kGetPlayer->nModSkinID, (DWORD)&kGetPlayer->nModSkinID - (DWORD)kGetPlayer, kGetPlayer->nModSkinID);
	__oMsg("[%x - %x] nXyenPhep_Diem           = %f", &kGetPlayer->nXyenPhep_Diem, (DWORD)&kGetPlayer->nXyenPhep_Diem - (DWORD)kGetPlayer, kGetPlayer->nXyenPhep_Diem);
	__oMsg("[%x - %x] nXyenGiap_Diem           = %f", &kGetPlayer->nXyenGiap_Diem, (DWORD)&kGetPlayer->nXyenGiap_Diem - (DWORD)kGetPlayer, kGetPlayer->nXyenGiap_Diem);
//return;
	__oMsg("[%x - %x] nFlat_PhysicalDamageMod  = %f", &kGetPlayer->nFlat_PhysicalDamageMod, (DWORD)&kGetPlayer->nFlat_PhysicalDamageMod - (DWORD)kGetPlayer, kGetPlayer->nFlat_PhysicalDamageMod);
	__oMsg("[%x - %x] nFlat_MagicDamageMod     = %f", &kGetPlayer->nFlat_MagicDamageMod, (DWORD)&kGetPlayer->nFlat_MagicDamageMod - (DWORD)kGetPlayer, kGetPlayer->nFlat_MagicDamageMod);
	__oMsg("[%x - %x] nPercent_MagicDamageMod  = %f", &kGetPlayer->nPercent_MagicDamageMod, (DWORD)&kGetPlayer->nPercent_MagicDamageMod - (DWORD)kGetPlayer, kGetPlayer->nPercent_MagicDamageMod);
	__oMsg("[%x - %x] nAttackSpeedMod          = %f", &kGetPlayer->nAttackSpeedMod, (DWORD)&kGetPlayer->nAttackSpeedMod - (DWORD)kGetPlayer, kGetPlayer->nAttackSpeedMod);
	__oMsg("[%x - %x] nBaseAttackDamage        = %f", &kGetPlayer->nBaseAttackDamage, (DWORD)&kGetPlayer->nBaseAttackDamage - (DWORD)kGetPlayer, kGetPlayer->nBaseAttackDamage);
	__oMsg("[%x - %x] nCritChance              = %f", &kGetPlayer->nCritChance, (DWORD)&kGetPlayer->nCritChance - (DWORD)kGetPlayer, kGetPlayer->nCritChance);
	__oMsg("[%x - %x] nArmor                   = %f", &kGetPlayer->nArmor, (DWORD)&kGetPlayer->nArmor - (DWORD)kGetPlayer, kGetPlayer->nArmor);
	__oMsg("[%x - %x] nArmor_CongThem          = %f", &kGetPlayer->nArmor_CongThem, (DWORD)&kGetPlayer->nArmor_CongThem - (DWORD)kGetPlayer, kGetPlayer->nArmor_CongThem);
	__oMsg("[%x - %x] nSpellBlock              = %f", &kGetPlayer->nSpellBlock, (DWORD)&kGetPlayer->nSpellBlock - (DWORD)kGetPlayer, kGetPlayer->nSpellBlock);
	__oMsg("[%x - %x] nSpellBlock_CongThem     = %f", &kGetPlayer->nSpellBlock_CongThem, (DWORD)&kGetPlayer->nSpellBlock_CongThem - (DWORD)kGetPlayer, kGetPlayer->nSpellBlock_CongThem);
	__oMsg("[%x - %x] nMoveSpeed               = %f", &kGetPlayer->nMoveSpeed, (DWORD)&kGetPlayer->nMoveSpeed - (DWORD)kGetPlayer, kGetPlayer->nMoveSpeed);
	__oMsg("[%x - %x] nAttackRange             = %f", &kGetPlayer->nAttackRange, (DWORD)&kGetPlayer->nAttackRange - (DWORD)kGetPlayer, kGetPlayer->nAttackRange);
//return;
	__oMsg("[%x - %x] nIsBot                   = %d", &kGetPlayer->nIsBot, (DWORD)&kGetPlayer->nIsBot - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsBot);
	__oMsg("[%x - %x] nHoiMauMoiGiay           = %f", &kGetPlayer->nHoiMauMoiGiay, (DWORD)&kGetPlayer->nHoiMauMoiGiay - (DWORD)kGetPlayer, kGetPlayer->nHoiMauMoiGiay);
	__oMsg("[%x - %x] nPet_ID_1                = %x", &kGetPlayer->nPet_ID_1, (DWORD)&kGetPlayer->nPet_ID_1 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_1);
	__oMsg("[%x - %x] nPet_ID_2                = %x", &kGetPlayer->nPet_ID_2, (DWORD)&kGetPlayer->nPet_ID_2 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_2);
	__oMsg("[%x - %x] nPet_ID_3                = %x", &kGetPlayer->nPet_ID_3, (DWORD)&kGetPlayer->nPet_ID_3 - (DWORD)kGetPlayer, kGetPlayer->nPet_ID_3);
	__oMsg("[%x - %x] nAI_LastPetSpawnedID     = %x", &kGetPlayer->nAI_LastPetSpawnedID, (DWORD)&kGetPlayer->nAI_LastPetSpawnedID - (DWORD)kGetPlayer, kGetPlayer->nAI_LastPetSpawnedID);
	__oMsg("[%x - %x] nGold                    = %f", &kGetPlayer->nGold, (DWORD)&kGetPlayer->nGold - (DWORD)kGetPlayer, kGetPlayer->nGold);
	__oMsg("[%x - %x] FacingPos               = %f, %f, %f", &kGetPlayer->facingPos.x, (DWORD)&kGetPlayer->facingPos.x - (DWORD)kGetPlayer, kGetPlayer->facingPos.x, kGetPlayer->facingPos.y, kGetPlayer->facingPos.z);
	__oMsg("[%x - %x] nCombatType              = %d", &kGetPlayer->nCombatType, (DWORD)&kGetPlayer->nCombatType - (DWORD)kGetPlayer, kGetPlayer->nCombatType);
	__oMsg("[%x - %x] DWORD pBuffs             = %x", &kGetPlayer->pBuffs, (DWORD)&kGetPlayer->pBuffs - (DWORD)kGetPlayer, kGetPlayer->pBuffs);
	__oMsg("[%x - %x] DWORD pMax_Buffs         = %x", &kGetPlayer->pMax_Buffs, (DWORD)&kGetPlayer->pMax_Buffs - (DWORD)kGetPlayer, kGetPlayer->pMax_Buffs);
return;





	//__oMsg_2("[%x - %x] szName_Hero              = %s", &kGetPlayer->szName_Hero, (DWORD)&kGetPlayer->szName_Hero - (DWORD)kGetPlayer, kGetPlayer->GetNameHero());
	//__oMsg_2("[%x - %x] nLen_Name_Hero           = %d", &kGetPlayer->nLen_Name_Hero, (DWORD)&kGetPlayer->nLen_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nLen_Name_Hero);
	//__oMsg_2("[%x - %x] nMax_Len_Name_Hero       = %d", &kGetPlayer->nMax_Len_Name_Hero, (DWORD)&kGetPlayer->nMax_Len_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nMax_Len_Name_Hero);
	__oMsg("[%x - %x] DWORD _pMOVE             = %x", &kGetPlayer->_pMOVE, (DWORD)&kGetPlayer->_pMOVE - (DWORD)kGetPlayer, kGetPlayer->_pMOVE);
	__oMsg("[%x - %x] int _pCastSpellBook      = %x", &kGetPlayer->_pCastSpellBook, (DWORD)&kGetPlayer->_pCastSpellBook - (DWORD)kGetPlayer, kGetPlayer->_pCastSpellBook);
	__oMsg("[%x - %x] DWORD *_pCastSpell       = %x", &kGetPlayer->_pCastSpell, (DWORD)&kGetPlayer->_pCastSpell - (DWORD)kGetPlayer, kGetPlayer->_pCastSpell);
	__oMsg("[%x - %x] nIsCastingSpell          = %d", &kGetPlayer->nIsCastingSpell, (DWORD)&kGetPlayer->nIsCastingSpell - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsCastingSpell);
	//__oMsg_2("[%x - %x] DWORD _pNormalAttack     = %x", &kGetPlayer->_pNormalAttack, (DWORD)&kGetPlayer->_pNormalAttack - (DWORD)kGetPlayer, kGetPlayer->_pNormalAttack);
	__oMsg("[%x - %x] DWORD _pSkill[63][from canCast2] = %x  ", &kGetPlayer->_pSkill, (DWORD)&kGetPlayer->_pSkill - (DWORD)kGetPlayer, kGetPlayer->_pSkill);
	
	__oMsg("[%x - %x] szName_Hero              = %s", &kGetPlayer->szName_Hero, (DWORD)&kGetPlayer->szName_Hero - (DWORD)kGetPlayer, kGetPlayer->GetNameHero());
	__oMsg("[%x - %x] nLen_Name_Hero           = %d", &kGetPlayer->nLen_Name_Hero, (DWORD)&kGetPlayer->nLen_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nLen_Name_Hero);
	__oMsg("[%x - %x] nMax_Len_Name_Hero       = %d", &kGetPlayer->nMax_Len_Name_Hero, (DWORD)&kGetPlayer->nMax_Len_Name_Hero - (DWORD)kGetPlayer, kGetPlayer->nMax_Len_Name_Hero);
//return;

	__oMsg("[%x - %x] nEnemy_ID                = %x", &kGetPlayer->nEnemy_ID, (DWORD)&kGetPlayer->nEnemy_ID - (DWORD)kGetPlayer, kGetPlayer->nEnemy_ID);
	__oMsg("[%x - %x] nBLOCK_MOVE              = %x", &kGetPlayer->nBLOCK_MOVE, (DWORD)&kGetPlayer->nBLOCK_MOVE - (DWORD)kGetPlayer, kGetPlayer->nBLOCK_MOVE);
	__oMsg("[%x - %x] nIsMinion                = %d", &kGetPlayer->nIsMinion, (DWORD)&kGetPlayer->nIsMinion - (DWORD)kGetPlayer, kGetPlayer->nIsMinion);
	__oMsg("[%x - %x] nMinion_Level            = %d", &kGetPlayer->nMinion_Level, (DWORD)&kGetPlayer->nMinion_Level - (DWORD)kGetPlayer, kGetPlayer->nMinion_Level);
	__oMsg("[%x - %x] nBar_Soucre              = %x", &kGetPlayer->nBar_Source, (DWORD)&kGetPlayer->nBar_Source - (DWORD)kGetPlayer, kGetPlayer->nBar_Source);
	//__oMsg_2("[%x - %x] nCooldownExpiresBA       = %f", &kGetPlayer->nCooldownExpiresBA, (DWORD)&kGetPlayer->nCooldownExpiresBA - (DWORD)kGetPlayer, kGetPlayer->nCooldownExpiresBA);
	__oMsg("[%x - %x] _pNormalAttack			 = %x", &kGetPlayer->_pNormalAttack, (DWORD)&kGetPlayer->_pNormalAttack - (DWORD)kGetPlayer, kGetPlayer->_pNormalAttack);
	__oMsg("[%x - %x] nIsMove                  = %d", &kGetPlayer->nIsMove, (DWORD)&kGetPlayer->nIsMove - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nIsMove);

	__oMsg("[%x - %x] nIS_MOVE_1               = %d", &kGetPlayer->nIS_MOVE_1, (DWORD)&kGetPlayer->nIS_MOVE_1 - (DWORD)kGetPlayer, kGetPlayer->nIS_MOVE_1);
	__oMsg("[%x - %x] nIS_MOVE_2               = %d", &kGetPlayer->nIS_MOVE_2, (DWORD)&kGetPlayer->nIS_MOVE_2 - (DWORD)kGetPlayer, kGetPlayer->nIS_MOVE_2);
	__oMsg("====> IS_MOVE_NEW				   = %d", (kGetPlayer->nIS_MOVE_1 == 0) & (kGetPlayer->nIS_MOVE_2 != 0));

	__oMsg("[%x - %x] nLevel                   = %d", &kGetPlayer->nLevel, (DWORD)&kGetPlayer->nLevel - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nLevel);
	__oMsg("[%x - %x] nRemainingPoint          = %d", &kGetPlayer->nRemainingPoint, (DWORD)&kGetPlayer->nRemainingPoint - (DWORD)kGetPlayer, (BYTE)kGetPlayer->nRemainingPoint);
	
	__oMsg("[%x - %x] DWORD _pItem[0]]         = %x", &kGetPlayer->_pItem, (DWORD)&kGetPlayer->_pItem - (DWORD)kGetPlayer, kGetPlayer->_pItem);

	
//return;

	__oMsg("isTurret    :  %d", IS_TURRET(kGetPlayer));
	__oMsg("IsChampion  :  %d", IS_HERO(kGetPlayer));
	__oMsg("IsMinion    :  %d", IS_MINION(kGetPlayer));
	__oMsg("IsNexus     :  %d", IS_NEXUS(kGetPlayer));
	__oMsg("IsInhibitor :  %d", IS_INHIBITOR(kGetPlayer));





	__oMsg("BoundingRadius :  %f", GetBoundingRadius(kGetPlayer));

//-----------------------------------------------------

//return;


//========= THONG TIN pMOVE ==================================================================================================
	__oMsg("\n");
	__oMsg("======================= pMOVE : ==========================");
	//DWORD movNote = (DWORD)kGetPlayer->_pMOVE;
	//DWORD strMove  = *(DWORD*)(movNote + 4);
	//stMOVE *destPos = (stMOVE *)strMove;
	DWORD movNote = GET_PMOVE_NEW(kGetPlayer);
	stMOVE *destPos = (stMOVE *)movNote;
	if (destPos)
	{
		__oMsg("[%x]pMOVE:", destPos);
		__oMsg("[%x - %x]IS MOVING(OLD)     = %d", &destPos->nIsMoving, (DWORD)&destPos->nIsMoving - (DWORD)destPos, (BYTE)destPos->nIsMoving);
		__oMsg("[%x]IS MOVE					= %d", &kGetPlayer->nIsMove, (BYTE)kGetPlayer->nIsMove);
		__oMsg("[%x - %x]POSITION_E_OLD     = %f,%f,%f", &destPos->__strPosDest_OLD.x, (DWORD)&destPos->__strPosDest_OLD.x - (DWORD)destPos, destPos->__strPosDest_OLD.x, destPos->__strPosDest_OLD.y, destPos->__strPosDest_OLD.z);
		__oMsg("[%x - %x]POSITION-END       = %f,%f,%f)", &destPos->__strPosDest.x, (DWORD)&destPos->__strPosDest.x - (DWORD)destPos, destPos->__strPosDest.x, destPos->__strPosDest.y, destPos->__strPosDest.z);
		__oMsg("[%x - %x]POSITION-START     = %f,%f,%f)", &destPos->__strPosStart.x, (DWORD)&destPos->__strPosStart.x - (DWORD)destPos, destPos->__strPosStart.x, destPos->__strPosStart.y, destPos->__strPosStart.z);
		__oMsg("[%x - %x]nWayPoint_Start    = %x)", &destPos->nWayPoint_Start, (DWORD)&destPos->nWayPoint_Start - (DWORD)destPos, destPos->nWayPoint_Start);
		__oMsg("[%x - %x]nWayPoint_End      = %x)", &destPos->nWayPoint_End, (DWORD)&destPos->nWayPoint_End - (DWORD)destPos, destPos->nWayPoint_End);
		__oMsg("[%x - %x]nWayPoint_MaxEnd   = %x)", &destPos->nWayPoint_MaxEnd, (DWORD)&destPos->nWayPoint_MaxEnd - (DWORD)destPos, destPos->nWayPoint_MaxEnd);
		__oMsg("[%x - %x]nIsDash            = %d)", &destPos->nIsDash, (DWORD)&destPos->nIsDash - (DWORD)destPos, (BYTE)destPos->nIsDash);
		__oMsg("[%x - %x]nDashSpeed         = %f)", &destPos->nDashSpeed, (DWORD)&destPos->nDashSpeed - (DWORD)destPos, destPos->nDashSpeed);
		__oMsg("[%x - %x]IsDashing_Old      = %d", &destPos->nIsDashing, (DWORD)&destPos->nIsDashing - (DWORD)destPos, (BYTE)destPos->nIsDashing);
		__oMsg("[%x - %x]nIsDashGravity     = %d)", &destPos->nDashGravity, (DWORD)&destPos->nDashGravity - (DWORD)destPos, (BYTE)destPos->nDashGravity);
		__oMsg("[%x - %x]IS IN FOG_1        = %d", &destPos->nIsInFog, (DWORD)&destPos->nIsInFog - (DWORD)destPos, (BYTE)destPos->nIsInFog);
		__oMsg("[%x - %x]IS IN FOG_2		= %d", &destPos->nInFog2, (DWORD)&destPos->nInFog2 - (DWORD)destPos, (WORD)destPos->nInFog2);
	}
	else __oMsg("GetPMove_Test() = 000"); 
//return;

//========= THONG TIN NORMAL-ATTACK && pCASTSPELL =============================================================================
	__oMsg("\n");
	__oMsg("======================= NORMAL-ATTACK && pCASTSPELL : ==========================");

	//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)kGetPlayer->_pNormalAttack;
	//if (_stNORMAL_ATTACK)
		__oMsg("Get_BasicAttack(): %x", Get_BasicAttack());

		////__oMsg_2("[%x]CooldownExpires = %f", (DWORD)&kGetPlayer->nCooldownExpiresBA, kGetPlayer->nCooldownExpiresBA);
		////__oMsg_2("[%x]CooldownExpires = %f", (DWORD)&kGetPlayer->nCooldownExpiresBA, GetCDBA_Test());// ko hieu sao cu cho (DWORD)&kGetPlayer->nCooldownExpiresBA vao la crash

		__oMsg("GetCDBA_Test()  = %f", GET_CDBA_NEW(kGetPlayer));
		__oMsg("GetCDBA_Test()  = %f", GET_CDBA_NEW(kGetPlayer));
		__oMsg("-----------------------------");
	if (kGetPlayer->_pCastSpell != 0)
	{
		//__oMsg_2("VKLLLL");

		__oMsg("GAA_Animate: %f - AADelay : %f ", Get_AA_Animate_Delay(kGetPlayer), Get_AA_Delay(kGetPlayer));

		KCastSpell *pCastSpell = (KCastSpell *)kGetPlayer->_pCastSpell;
		__oMsg("[%x - %x]pCASTSPELL - __pK_str2 = %x:", pCastSpell, (DWORD)&pCastSpell->__pK_str2 - (DWORD)pCastSpell, pCastSpell->__pK_str2);
		__oMsg("[%x - %x]nMy_ID_1		= %x", &pCastSpell->nMy_ID_1, (DWORD)&pCastSpell->nMy_ID_1 - (DWORD)pCastSpell, pCastSpell->nMy_ID_1);
		__oMsg("[%x - %x]nMy_ID_2		= %x", &pCastSpell->nMy_ID_2, (DWORD)&pCastSpell->nMy_ID_2 - (DWORD)pCastSpell, pCastSpell->nMy_ID_2);
		__oMsg("-----------------------------");
		__oMsg("Skill Position: ");
		__oMsg("[%x - %x]Source          = %f, %f, %f", &pCastSpell->SourcePos.x,  (DWORD)&pCastSpell->SourcePos.x - (DWORD)pCastSpell, pCastSpell->SourcePos.x,  pCastSpell->SourcePos.y,  pCastSpell->SourcePos.z);
		__oMsg("[%x - %x]MaxDest         = %f, %f, %f", &pCastSpell->MaxDestPos.x, (DWORD)&pCastSpell->MaxDestPos.x - (DWORD)pCastSpell, pCastSpell->MaxDestPos.x, pCastSpell->MaxDestPos.y, pCastSpell->MaxDestPos.z);
		__oMsg("[%x - %x]Mouse           = %f, %f, %f", &pCastSpell->MousePos.x,   (DWORD)&pCastSpell->MousePos.x - (DWORD)pCastSpell, pCastSpell->MousePos.x,   pCastSpell->MousePos.y,   pCastSpell->MousePos.z);
		__oMsg("[%x - %x]nEnemy_ID		 = %x", &pCastSpell->nEnemy_ID, (DWORD)&pCastSpell->nEnemy_ID - (DWORD)pCastSpell, pCastSpell->nEnemy_ID);
		__oMsg("[%x - %x]nDelay_AAAnimate    = %f = DELAY_SKILL CHANNELING BTHUONG", &pCastSpell->nDelay_AAAnimate, (DWORD)&pCastSpell->nDelay_AAAnimate - (DWORD)pCastSpell, pCastSpell->nDelay_AAAnimate);
		__oMsg("[%x - %x]nDelay_AAAnimate_2  = %f", &pCastSpell->nDelay_AAAnimate_2, (DWORD)&pCastSpell->nDelay_AAAnimate_2 - (DWORD)pCastSpell, pCastSpell->nDelay_AAAnimate_2);
		__oMsg("[%x - %x]nCoolDownAA		    = %f", &pCastSpell->nCoolDownAA, (DWORD)&pCastSpell->nCoolDownAA - (DWORD)pCastSpell, pCastSpell->nCoolDownAA);
		__oMsg("[%x - %x]nSlot			    = %d", &pCastSpell->nSlot, (DWORD)&pCastSpell->nSlot - (DWORD)pCastSpell, (BYTE)pCastSpell->nSlot);
		__oMsg("[%x - %x]nTime_BatDauBan     = %f (CHU Y CHECK CA TRU. NUA)", &pCastSpell->nTime_BatDauBAN, (DWORD)&pCastSpell->nTime_BatDauBAN - (DWORD)pCastSpell, pCastSpell->nTime_BatDauBAN);
		__oMsg("[%x - %x]nTime_DanBatDauBay  = %f", &pCastSpell->nTime_DanBatDauBay, (DWORD)&pCastSpell->nTime_DanBatDauBay - (DWORD)pCastSpell, pCastSpell->nTime_DanBatDauBay);
		__oMsg("[%x - %x]nTime_CooldownExpires_AA= %f", &pCastSpell->nTime_CDExpiresAA, (DWORD)&pCastSpell->nTime_CDExpiresAA - (DWORD)pCastSpell, pCastSpell->nTime_CDExpiresAA);
		
		KSkill_2* pSkill_2 = (KSkill_2*)pCastSpell->__pK_str2;
		if(pSkill_2)
		{
			__oMsg("Name: %s - __pK_str3 = %x [%x]", pSkill_2->GetSkillName(), pSkill_2->__pK_str3, (DWORD)&pSkill_2->__pK_str3 - (DWORD)pSkill_2);
			KMissile_Struct_3* pStruct_3 = (KMissile_Struct_3*)pSkill_2->__pK_str3;
			if(pStruct_3)
			{
				__oMsg("[%x]nRange	    = %f [%x]", &pStruct_3->nRange, pStruct_3->nRange, (DWORD)&pStruct_3->nRange - (DWORD)pStruct_3);
				__oMsg("[%x]nRange_2    = %f [%x]", &pStruct_3->nRange_2, pStruct_3->nRange_2, (DWORD)&pStruct_3->nRange_2 - (DWORD)pStruct_3);
				__oMsg("[%x]nRadius	    = %f [%x]", &pStruct_3->nRadius, pStruct_3->nRadius, (DWORD)&pStruct_3->nRadius - (DWORD)pStruct_3);
				__oMsg("[%x]nSpeed      = %f [%x]", &pStruct_3->nMissileSpeed, pStruct_3->nMissileSpeed, (DWORD)&pStruct_3->nMissileSpeed - (DWORD)pStruct_3);
				__oMsg("[%x]nWidth	    = %f [%x]", &pStruct_3->nMissileWidth, pStruct_3->nMissileWidth, (DWORD)&pStruct_3->nMissileWidth - (DWORD)pStruct_3);
			}
		}
	}
	else
	{
		__oMsg("pCastSpell : nEnemy_ID = [xxxxxxx] (Chua Cast Spell)");
	}

//========= THONG TIN TIME_GAME ================================================================================================
	__oMsg("\n");
	__oMsg("======================= TIME_GAME : ============================================");
	__oMsg("TIME_GAME_OLD  = %f", GetTimeGame_OLD());
	__oMsg("TIME_GAME_NEW  = %f", GetTimeGame());
	__oMsg("TIME_GAME_TEST = %f", GetTimeGame_Test());
	__oMsg("TIME_GAME_DUBI = %f", GetTimeGame_Dubi());		//***** KO THAY DIA CHI LA CHET ********************************

//return;




//========= THONG TIN SKILL ====================================================================================================
	__oMsg("\n");
	__oMsg("======================= SKILL INFORMATION : ====================================");

	KSkill*   pSkillQ = (KSkill*) kGetPlayer->_pSkill[0];
	KSkill*   pSkillW = (KSkill*) kGetPlayer->_pSkill[1];
	KSkill*   pSkillE = (KSkill*) kGetPlayer->_pSkill[2];
	KSkill*   pSkillR = (KSkill*) kGetPlayer->_pSkill[3];
	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillQ, &pSkillQ->nLevel, (DWORD)&pSkillQ->nLevel - (DWORD)pSkillQ, (BYTE)pSkillQ->nLevel);
	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillQ, &pSkillQ->nCooldownExpires, (DWORD)&pSkillQ->nCooldownExpires - (DWORD)pSkillQ, pSkillQ->nCooldownExpires);
	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillQ, &pSkillQ->nStack, (DWORD)&pSkillQ->nStack - (DWORD)pSkillQ, (BYTE)pSkillQ->nStack);
	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillQ, &pSkillQ->nCooldownExpires_3, (DWORD)&pSkillQ->nCooldownExpires_3 - (DWORD)pSkillQ, pSkillQ->nCooldownExpires_3);
	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillQ, &pSkillQ->nToggle, (DWORD)&pSkillQ->nToggle - (DWORD)pSkillQ, (BYTE)pSkillQ->nToggle);
	__oMsg(" [-Q-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillQ, &pSkillQ->nTotalCooldown, (DWORD)&pSkillQ->nTotalCooldown - (DWORD)pSkillQ, pSkillQ->nTotalCooldown);
	
	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillW, &pSkillW->nLevel, (DWORD)&pSkillW->nLevel - (DWORD)pSkillW, (BYTE)pSkillW->nLevel);
	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillW, &pSkillW->nCooldownExpires, (DWORD)&pSkillW->nCooldownExpires - (DWORD)pSkillW, pSkillW->nCooldownExpires);
	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillW, &pSkillW->nStack, (DWORD)&pSkillW->nStack - (DWORD)pSkillW, (BYTE)pSkillW->nStack);
	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillW, &pSkillW->nCooldownExpires_3, (DWORD)&pSkillW->nCooldownExpires_3 - (DWORD)pSkillW, pSkillW->nCooldownExpires_3);
	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillW, &pSkillW->nToggle, (DWORD)&pSkillW->nToggle - (DWORD)pSkillW, (BYTE)pSkillW->nToggle);
	__oMsg(" [-W-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillW, &pSkillW->nTotalCooldown, (DWORD)&pSkillW->nTotalCooldown - (DWORD)pSkillW, pSkillW->nTotalCooldown);

	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillE, &pSkillE->nLevel, (DWORD)&pSkillE->nLevel - (DWORD)pSkillE, (BYTE)pSkillE->nLevel);
	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillE, &pSkillE->nCooldownExpires, (DWORD)&pSkillE->nCooldownExpires - (DWORD)pSkillE, pSkillE->nCooldownExpires);
	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillE, &pSkillE->nStack, (DWORD)&pSkillE->nStack - (DWORD)pSkillE, (BYTE)pSkillE->nStack);
	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillE, &pSkillE->nCooldownExpires_3, (DWORD)&pSkillE->nCooldownExpires_3 - (DWORD)pSkillE, pSkillE->nCooldownExpires_3);
	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillE, &pSkillE->nToggle, (DWORD)&pSkillE->nToggle - (DWORD)pSkillE, (BYTE)pSkillE->nToggle);
	__oMsg(" [-E-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillE, &pSkillE->nTotalCooldown, (DWORD)&pSkillE->nTotalCooldown - (DWORD)pSkillE, pSkillE->nTotalCooldown);

	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nLevel                      = %d", pSkillR, &pSkillR->nLevel, (DWORD)&pSkillR->nLevel - (DWORD)pSkillR, (BYTE)pSkillR->nLevel);
	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires            = %f", pSkillR, &pSkillR->nCooldownExpires, (DWORD)&pSkillR->nCooldownExpires - (DWORD)pSkillR, pSkillR->nCooldownExpires);
	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nStack[Ammo]				   = %d", pSkillR, &pSkillR->nStack, (DWORD)&pSkillR->nStack - (DWORD)pSkillR, (BYTE)pSkillR->nStack);
	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires_3		   = %f", pSkillR, &pSkillR->nCooldownExpires_3, (DWORD)&pSkillR->nCooldownExpires_3 - (DWORD)pSkillR, pSkillR->nCooldownExpires_3);
	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nToggle                     = %d", pSkillR, &pSkillR->nToggle, (DWORD)&pSkillR->nToggle - (DWORD)pSkillR, (BYTE)pSkillR->nToggle);
	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nTotalCooldown              = %f\n", pSkillR, &pSkillR->nTotalCooldown, (DWORD)&pSkillR->nTotalCooldown - (DWORD)pSkillR, pSkillR->nTotalCooldown);

	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nCooldownExpires_2(Leblanc) = %f", pSkillR, &pSkillR->nCooldownExpires_2, (DWORD)&pSkillR->nCooldownExpires_2 - (DWORD)pSkillR, pSkillR->nCooldownExpires_2);
	__oMsg(" [-R-] [%x]K Skill -- [%x - %x]nTotalCooldown_2(Leblanc)   = %f", pSkillR, &pSkillR->nTotalCooldown_2, (DWORD)&pSkillR->nTotalCooldown_2 - (DWORD)pSkillR, pSkillR->nTotalCooldown_2);
	__oMsg("--------------------------------");
	KSkill_2*  pKSkill_Q = (KSkill_2*) pSkillQ->__pK_str2;
	__oMsg(" [-Q-] [%x]pK Skill 2[%x - %x] ",&pSkillQ->__pK_str2, (DWORD)&pSkillQ->__pK_str2 - (DWORD)pSkillQ, (DWORD)pSkillQ->__pK_str2);
	if (pKSkill_Q)
		__oMsg(" [-Q-] [%x]pK Skill 2[%x - %x] -- SkillName = %s", (DWORD)pKSkill_Q, &pKSkill_Q->szName, (DWORD)&pKSkill_Q->szName - (DWORD)pKSkill_Q, pKSkill_Q->GetSkillName());
//return;




//========= THONG TIN VE BUFF ===================================================================================================
	__oMsg("\n");
	__oMsg("======================= BUFF INFORMATION : ====================================");

	int nBuff_Count = (pNpc->pMax_Buffs - pNpc->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(pNpc->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(pBuffs->nIndex == -1) continue;
		KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
		if(!pBuffs_1) continue;
		//if ((BYTE)pBuffs->nIndex != 26) continue;

		__oMsg("[Type = %d][%x]Buff Name:  %s",(BYTE)pBuffs->nIndex, pBuffs, pBuffs_1->szName);
		__oMsg(" - [%x - %x]begin_time  = %f, [%x - %x]end_time  = %f", &pBuffs->nBegin_Time, (DWORD)&pBuffs->nBegin_Time - (DWORD)pBuffs, pBuffs->nBegin_Time ,    /*----*/   &pBuffs->nEnd_Time, (DWORD)&pBuffs->nEnd_Time - (DWORD)pBuffs, pBuffs->nEnd_Time);
		__oMsg(" - [%x - %x]start_count = %x, [%x - %x]end_count = %x --> [Stacks = %d]", &pBuffs->nStart_Count, (DWORD)&pBuffs->nStart_Count - (DWORD)pBuffs, pBuffs->nStart_Count,  /*----*/   &pBuffs->nEnd_Count, (DWORD)&pBuffs->nEnd_Count - (DWORD)pBuffs, pBuffs->nEnd_Count, (pBuffs->nEnd_Count - pBuffs->nStart_Count)/8);
		__oMsg(" - [%x - %x]nCountz     = %d", &pBuffs->nCount, (DWORD)&pBuffs->nCount - (DWORD)pBuffs, pBuffs->nCount);
		__oMsg(" - [%x - %x]nOwnerData  = %x", &pBuffs->__pOwenerData, (DWORD)&pBuffs->__pOwenerData - (DWORD)pBuffs, pBuffs->__pOwenerData);
		if(pBuffs->__pOwenerData)
		{
			KBuff_OwnerData* pOwnerData = (KBuff_OwnerData*)pBuffs->__pOwenerData;
			__oMsg("   pOwnerData = %x", pBuffs->__pOwenerData);
			__oMsg(" - [%x - %x]pOwnerNpc     = %x", &pOwnerData->pOwnerNpc, (DWORD)&pOwnerData->pOwnerNpc - (DWORD)pOwnerData, pOwnerData->pOwnerNpc);
			__oMsg(" - [%x - %x]pOwnerId      = %x", &pOwnerData->nOwnerId, (DWORD)&pOwnerData->nOwnerId - (DWORD)pOwnerData, pOwnerData->nOwnerId);
			__oMsg(" - [%x - %x]pOwnerNetId   = %x", &pOwnerData->nOwnerNetworkId, (DWORD)&pOwnerData->nOwnerNetworkId - (DWORD)pOwnerData, pOwnerData->nOwnerNetworkId);
		}
		__oMsg("[..]======>> CHU Y CHECK : nLua_pBuff = *(DWORD*)(pBaseScriptBuff + 0xC) --> ben trong OnRemoveBuff");
		__oMsg("-------------------------------------------------------------------");
	}
//return;




//========= CHECK WALL ==========================================================================================================
	__oMsg("\n");
	__oMsg("======================= CHECK WALL : ====================================");

							DWORD nSourceFolder = LoadFolderSource(pNpc->GetNameHero());
							if (nSourceFolder)
							{
								DWORD dw1 = *(DWORD*)(nSourceFolder + 32);				// ref: 006D279B (8.16)
								if (dw1)
								{
									DWORD Circle_DDS = *(DWORD*)(dw1 + 0x258);			// can lay backup hoac print khi update	(9.24.1)
									DWORD Square_DDS = *(DWORD*)(dw1 + 0x268);			// can lay backup hoac print khi update (9.24.1)

									// Uu tien lay Square cho dep ...
									if (Square_DDS )	
									{
										__oMsg("[%s] - > %s", pNpc->GetNameHero(), (char*)Square_DDS);			
									}
									if (Circle_DDS )	
									{
										__oMsg("[%s] - > %s", pNpc->GetNameHero(), (char*)Circle_DDS);			
									}
								}
							}


	KPos* mousePos = GetMousePos();
	__oMsg("Mouse Cursor: [%x] = %.2f, %.2f, %.2f", &mousePos->x, mousePos->x, mousePos->y, mousePos->z);
	__oMsg("Wall        : %d ",IsWall(mousePos));
	__oMsg("--------------------------------");
	__oMsg("IS_CHATTING : %d",IS_CHATTING());
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_ENDGAME = BASE_ENDGAME - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_ENDGAME;
	__oMsg("End Game    : %d", *(DWORD*)(dw1 + 8));		// = 2 : dang hoat dong; =3,4,5 ket thuc game
//return;


	DWORD hModule1 = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule1;
	DWORD dw1_1 = *(DWORD*)nTempBASE_SKILL;
	if(!dw1_1) return;
	DWORD dw2_2 = *(DWORD*)(dw1_1 + 0xC);
	if(!dw2_2) return;
	KHackZoom* pHackZoom = (KHackZoom*)dw2_2;
	__oMsg("[%x] HackZoom: %f",&pHackZoom->nHackZoom, pHackZoom->nHackZoom);// ban dau la 1.28
	__oMsg("pDecive  : %x",Get_Device());
	__oMsg("pRenderer: %x",GetRenderer());
//return;	


	DWORD nEndSceneFuncion = 111;
	DWORD* vtbl = 0;
	DWORD table = FindPattern((DWORD)GetModuleHandle( (sz__d3d9_dll)), 0x128000,     (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86",  (sz__xx____xx____xx) );
	if (table != 0)
	{
		memcpy(&vtbl, (void*)(table+2), 4);
		nEndSceneFuncion = vtbl[42];
	}

	__oMsg("nEndSceneFuncion-d3d9 = [%x]", nEndSceneFuncion);


	DWORD hModule2 = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_SKILL1 = BASE_SKILL - TEMP_ENTRY_POINT + hModule2;
	DWORD dw1_1_1 = *(DWORD*)nTempBASE_SKILL1;
	DWORD dw2_3_1 = *(DWORD*)(dw1_1_1 + 0x24);
	__oMsg("ECX_RCLICK_MOVE_FUNC: %x ==> [x=%d, y=%d] (gameModule: %x)",dw2_3_1, *(DWORD*)(dw2_3_1 + 0x68), *(DWORD*)(dw2_3_1 + 0x6C) , hModule2);
	__oMsg("GetGameCursorPos:  [x=%f, y=%f]", GetGameCursorPos().x, GetGameCursorPos().y);
    DWORD dw2_4 = *(DWORD*)(dw1_1_1 + 0x30);
	if(!dw2_4) return;
	KSelectTarget* pSelectTarget = (KSelectTarget*)dw2_4;
	__oMsg("[%x]nSelectOrNot      = %d", &pSelectTarget->nSelectOrNot, (BYTE)pSelectTarget->nSelectOrNot);
	__oMsg("nIDTargetSelected = %x",pSelectTarget->nIDTargetSelected);
	__oMsg("GAA_Animate: %f - AADelay : %f ", Get_AA_Animate_Delay(), Get_AA_Delay());
	__oMsg("Ping: %d", GetPingGame());
	__oMsg("GetObjectByID        : %x", GetObjectByID(kGetPlayer->nID));
	__oMsg("GetObjectByNetworkID : %x", GetObjectByNetworkID(kGetPlayer->nIndex));
//return;

	//--------ITEM---------------------------------
	KItem *pItem = (KItem*)kGetPlayer->_pItem[0];// Item[0]
	if(pItem)
	{
		//__oMsg_2("[pItem] : %x", pItem);
		KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
		if(pItem_1)
		{
			//__oMsg_2("[pItem_1] : %x", pItem_1);
			KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
			if(pItem_2) __oMsg("[Name] : %s - ID = %x", pItem_1->pName, pItem_2->nID);
		}
		
	}
__oMsg("------ LUU Y CHUA CHECK TRONG OnCreateObject-->[GetMissileOwner_Name]------- \n\n");
	
	

	
//==========================================================================================================================================================

//	//////////////////////////////////////
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

	if (pNpc == NULL)
	{
		__oMsg("NPC bi null");
		return;
	}
	KNpc *kGetPlayer = pNpc;


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
	__try
	{
		DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
		if (hModule == NULL) return;

		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + hModule;

		DWORD dw0 = nTempBASE_OBJECT_ALL + 8;
		DWORD dw1 = *(DWORD*)dw0;
		if(!dw1) return;

		int nCount_n = *(DWORD*)(dw0 + 4);
		if (!nCount_n) return;

		for (int kk = 0; kk < nCount_n; ++kk)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
			if (dw3 == 0) continue;
			KNpc *object = (KNpc*)dw3;
			if(object->nIndex < 0x3FFFFCC8) continue;
			//if(CheckName("reticle_self", object->GetNameNpc())/* && CheckName(".troy", object->GetNameNpc())*/)
			if(CheckName("SivirQMissile", object->GetNameNpc())/* && CheckName(".troy", object->GetNameNpc())*/)
			{
				tickTest = GetTimeGame();
				fuck = object;
				__oMsg("1[%x]--name: %s :%x, :%x [del: %d - %f][%f,%f,%f][%f,%f,%f]\n", object->nTeam_ID, object->GetNameNpc(), object->nIndex, object->nType_1, (BYTE)object->nDeleted, GetTimeGame(), object->currentPos().x, object->currentPos().y, object->currentPos().z, object->MissileDestPos.x, object->MissileDestPos.y, object->MissileDestPos.z);
			}
			//if(CheckName("SivirQMissileReturn", object->GetNameNpc())/* && CheckName(".troy", object->GetNameNpc())*/)
			//{
			//	tickTest = GetTimeGame();
			//	fuck = object;
			//	__oMsg("2--name: %s :%x, :%x [del: %d - %f][%f,%f,%f][%f,%f,%f]\n", object->GetNameNpc(), object->nIndex, object->nType_1, object->nDeleted, GetTimeGame(), object->currentPos().x, object->currentPos().y, object->currentPos().z, object->ServerPosition.x, object->ServerPosition.y, object->ServerPosition.z);
			//}
		}
		if(fuck)
		{
			if(GetTimeGame() - tickTest < 0.2)
			{
				__oMsg("TEST: %x {%f}", (BYTE)fuck->nDeleted, GetTimeGame());
			}
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{ 
		__oMsg("error ...."); 
	}
}




void Test_misile()
{
	//return;

	KNpc* myHero = GetPlayer();
	if(!myHero) return;
	
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == 0) return;

	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + hModule;
	
	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	if (!dw0) return;

	DWORD dw1 = *(DWORD*)(dw0 + 8);
	if (!dw1) return;

	int nCount_n = *(DWORD*)(dw0 + 0xC);
	if (!nCount_n) return;
	
	//__oMsg_PrintFile("\n----------------------");
	for (int kk = 0; kk < nCount_n; ++kk)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
		if (dw3 == 0) continue;
		KNpc *missileObj = (KNpc*)dw3;

		//if (IS_OBJECT_TYPE(missileObj, 0x8000))
		//{
		//	//__oMsg("sasa");
		//	//__oMsg("delete: %d", IS_OBJ_DELETED(missileObj, "123"));
		//	__oMsg("alive: %d,", IS_ALIVE(missileObj));
		//	//__oMsg("alive: %d, delete: %d, able: %d", IS_ALIVE(missileObj), IS_OBJ_DELETED(missileObj, "123"), IS_TARGET_ABLE(missileObj));
		//	//__oMsg("--------------\n");

		//	/*if (IS_ALIVE(missileObj))
		//	{
		//		__oMsg_PrintFile("[%x] name: %s", missileObj, missileObj->GetNameNpc());
		//	}*/
		//}
		//
		//continue;

		if (IS_OBJ_DELETED(missileObj, "123") == true)	 continue;
		//if(missileObj->nIndex < 0x3FFFFCC8)      continue;
		//if(!IS_OBJECT_TYPE(missileObj, 0x8000))	 continue;
		
		if (CheckName("SRU", missileObj->GetNameNpc())) continue;
		if (CheckName("sru", missileObj->GetNameNpc())) continue;
		if (CheckName("Sru", missileObj->GetNameNpc())) continue;
		if (CheckName("LevelProp", missileObj->GetNameNpc())) continue;
		if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
		if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
		if (CheckName("Barracks", missileObj->GetNameNpc())) continue;
		if (CheckName("Turret", missileObj->GetNameNpc())) continue;
		if (CheckName("Swain_", missileObj->GetNameNpc())) continue;
		if (CheckName("candle_", missileObj->GetNameNpc())) continue;
		if (CheckName("Plinths_", missileObj->GetNameNpc())) continue;
		if (CheckName("Plant", missileObj->GetNameNpc())) continue;
		if (CheckName("_T1", missileObj->GetNameNpc())) continue;
		if (CheckName("_T2", missileObj->GetNameNpc())) continue;
		if (CheckName("monsterCamp", missileObj->GetNameNpc())) continue;
		
		
		////if (CheckName("Ashe", missileObj->GetNameNpc()))		//if (IS_OBJECT_TYPE(missileObj, 0x8001))
		////{
		////	KMissileData* misData = (KMissileData*)missileObj->nMissileData;
		////	//__oMsg("[%x]misData: %x - OwnerID_1: %x - OwnerID_2: %x", missileObj, missileObj->nMissileData, missileObj->nMissileOwnerID_1, missileObj->nMissileOwnerID_2);
		////	__oMsg("----------- misData: %x [%s] - type: %x", misData, missileObj->GetNameNpc(), OBJECT_TYPE(missileObj));
		////	//return;
		////}


		if (CheckName("AsheBasicAttack", missileObj->GetNameNpc()) && IS_OBJECT_TYPE(missileObj, 0x8000))
		//if (CheckName("Senna", missileObj->GetNameNpc()) && IS_OBJECT_TYPE(missileObj, 0x8000))
		{
			KMissileData* misData = (KMissileData*)missileObj->nMissileData;
			__oMsg("[%x]misData: %x - OwnerID_1: %x - OwnerID_2: %x", missileObj, missileObj->nMissileData, missileObj->nMissileOwnerID_1, missileObj->nMissileOwnerID_2);
			__oMsg("----------- misData: %x -  temp2: %x", misData, /*missileObj->nTemp_9_11,*/ missileObj->nTemp_9_11);
			
			//return;

			//__oMsg("Temp[0]: %x", missileObj->nTemp_9_12[0]);
			//__oMsg("Temp[1]: %x", missileObj->nTemp_9_12[1]);
			//__oMsg("Temp[2]: %x", missileObj->nTemp_9_12[2]);
			//__oMsg("Temp[3]: %x", missileObj->nTemp_9_12[3]);
			//__oMsg("Temp[4]: %x", missileObj->nTemp_9_12[4]);
			//__oMsg("Temp[5]: %x", missileObj->nTemp_9_12[5]);
			//__oMsg("Temp[6]: %x", missileObj->nTemp_9_12[6]);
			
			if (misData)
			{
				KMissile_Struct_3* pMiss_Struct_3 = (KMissile_Struct_3*)misData->nMissile_Struct_3;
				if (pMiss_Struct_3)
				{
					__oMsg("MisSpeed: %f (%.2f - %.2f), %s, %s [src: %.3f, %.3f, %.3f][des: %.3f, %.3f, %.3f][cursor: %.3f, %.3f, %.3f]",pMiss_Struct_3->nMissileSpeed, pMiss_Struct_3->nMissileMinSpeed, pMiss_Struct_3->nMissileMaxSpeed, misData->GetMissileOwner_Name(), missileObj->GetNameNpc(), missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z, missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z, missileObj->MissileCursorPos.x, missileObj->MissileCursorPos.y, missileObj->MissileCursorPos.z);
				}
			}
		}
		
	}	
}



void test_wardd()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pWard = (KNpc*)dw3;
		int isDie = IS_DEAD(pWard) == true ? 1 : 0;
		if (pWard->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pWard->nHP == 0)
			continue;
		if(IS_CAN_SEE(pWard) == false) continue;// chi ve trong man hinh nhin thay

		if ( CheckName("SightWard", pWard->GetNameNpc()) || CheckName("VisionWard", pWard->GetNameNpc()) 
			|| CheckName("JammerDevice", pWard->GetNameNpc())
			
			)
		{

			//if (pWard->nMaxMP > 0)
			{
				KSkill* pSkill_0= (KSkill*) pWard->_pSkill[0];
				if(!pSkill_0) continue;
				float nTimeCoolDown = pSkill_0->nCooldownExpires;
				float delta = GetTimeGame() - nTimeCoolDown;

				//float nTimeRemain = nTimeExist - delta;
	
				float nTimeRemain = pWard->nMaxMP - delta;

				__oMsg("delta : %f, Tgame: %f, cd: %f  maxMP: %f , MP: %f, HP: %f - %f (%s, %s), bool : %d, %d", delta, GetTimeGame(), nTimeCoolDown, pWard->nMaxMP, pWard->nMP, pWard->nHP, pWard->nMaxHP, pWard->GetNameNpc(), pWard->GetNameHero(), pWard->nMP == 0, pWard->nHP == 0);
			}
		}
	}
}