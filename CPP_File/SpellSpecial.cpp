#include "SpellSpecial.h"
#include "DodgeXerathS.h"
#include "DodgeLuxS.h"
#include "DodgeFioraS.h"
#include "DodgeSyndraS.h"
#include "DodgeOriannaS.h"
#include "DodgeMalphiteS.h"
#include "DodgeAatroxS.h"
#include "DodgeIreliaS.h"
#include "DodgeTFS.h"
#include "DodgeMalzaharS.h"
#include "DodgeZedS.h"
#include "DodgeZacS.h"
#include "DodgeXinZhaoS.h"
#include "DodgeViktorS.h"
#include "DodgeSorakaS.h"
#include "DodgePykeS.h"

#include "DodSpecial_3.h"
#include "DodSpecial_4.h"



extern int		myTeamId;
extern KNpc*	MY_HERO;

bool hasXerath, hasLux, hasFiora, hasSyndra, hasOrianna, hasMalphite, hasTryndamere, hasSejuani, hasLeblanc, hasGragas, hasAatrox, hasGnar, hasShen, hasJinx, hasJhin = false;
bool hasIrelia, hasTwistedFate, hasKhazix, hasTahmKench, hasMalzahar, hasVelkoz, hasGraves, hasZed, hasZoe, hasZiggs, hasLulu, hasZac, hasYorick, hasYasuo, hasXinZhao = false;	  
bool hasNeeko, hasViktor, hasVarus, hasSoraka, hasSion, hasRiven, hasRakan, hasPyke, hasOrnn, hasSylas, hasPantheon, hasJanna, hasKarma, hasJayce, hasRumble = false;

//---------------------------------------------------------------------//--------------------//
void Load_HeroSpecial()
{
	static bool read1lan = false;
	if (read1lan == true) return;

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwHero1 = *(DWORD*)tempHero;
	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	if (!dwHero1 || !dwHero2 ) return;

	int countHero = (dwHero2 - dwHero1)/4;
	for (int i = 0; i < countHero; ++i)
	{
		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
		if (dwHero3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dwHero3;
		if (enemyHero->nTeam_ID == myTeamId) continue;

		if (CheckName(enemyHero->GetNameHero(), "Xerath"))		hasXerath	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Lux"))			hasLux		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Fiora"))		hasFiora	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Syndra"))		hasSyndra     = true;
		if (CheckName(enemyHero->GetNameHero(), "Orianna"))		hasOrianna    = true;
		if (CheckName(enemyHero->GetNameHero(), "Malphite"))	hasMalphite   = true;
		if (CheckName(enemyHero->GetNameHero(), "Tryndamere"))	hasTryndamere = true;
		if (CheckName(enemyHero->GetNameHero(), "Sejuani"))		hasSejuani	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Leblanc"))		hasLeblanc	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Gragas"))		hasGragas	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Aatrox"))		hasAatrox     = true;
		if (CheckName(enemyHero->GetNameHero(), "Gnar"))		hasGnar	      = true;
		if (CheckName(enemyHero->GetNameHero(), "Shen"))		hasShen	      = true;
		if (CheckName(enemyHero->GetNameHero(), "Jinx"))		hasJinx	      = true;
		if (CheckName(enemyHero->GetNameHero(), "Jhin"))		hasJhin	      = true;
		if (CheckName(enemyHero->GetNameHero(), "Irelia"))		hasIrelia     = true;
		if (CheckName(enemyHero->GetNameHero(), "TwistedFate"))	hasTwistedFate= true;
		if (CheckName(enemyHero->GetNameHero(), "Khazix"))		hasKhazix	  = true;
		if (CheckName(enemyHero->GetNameHero(), "TahmKench"))	hasTahmKench  = true;
		if (CheckName(enemyHero->GetNameHero(), "Malzahar"))	hasMalzahar   = true;
		if (CheckName(enemyHero->GetNameHero(), "Velkoz"))		hasVelkoz	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Graves"))		hasGraves	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Zed"))			hasZed		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Zoe"))			hasZoe		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Ziggs"))		hasZiggs	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Lulu"))		hasLulu		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Zac"))			hasZac		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Yorick"))		hasYorick	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Yasuo"))		hasYasuo	  = true;
		if (CheckName(enemyHero->GetNameHero(), "XinZhao"))		hasXinZhao	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Neeko"))		hasNeeko	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Viktor"))		hasViktor	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Varus"))		hasVarus	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Soraka"))		hasSoraka	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Sion"))		hasSion		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Riven"))		hasRiven	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Rakan"))		hasRakan	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Pyke"))		hasPyke		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Ornn"))		hasOrnn		  = true;
		if (CheckName(enemyHero->GetNameHero(), "Sylas"))		hasSylas	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Pantheon"))	hasPantheon	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Janna"))		hasJanna	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Karma"))		hasKarma	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Jayce"))		hasJayce	  = true;
		if (CheckName(enemyHero->GetNameHero(), "Rumble"))		hasRumble	  = true;

		//if (CheckName(enemyHero->GetNameHero(), "Ziggs"))		hasLulu		  = true;
		//if (CheckName(enemyHero->GetNameHero(), "Ziggs"))		hasLulu		  = true;


	}

	read1lan = true;
}

//---------------------------------------------------------------------//--------------------//
sphereQE* _xin1SlotQESyndra = 0;
//---------------------------------------------------------------------//--------------------//
void fuckSyndra()
{
	//---- Syndra :
	if (hasSyndra)
	{
		if (!_xin1SlotQESyndra) _xin1SlotQESyndra = new sphereQE;
		if (_xin1SlotQESyndra->posQE.IsValid() && GetTimeGame() - _xin1SlotQESyndra->timeSpawn > 0.75f)
		{
			Vec3D zeze(0,0,0);
			_xin1SlotQESyndra->posQE	 = zeze;
			_xin1SlotQESyndra->timeSpawn = GetTimeGame();
			//__oMsg("ZERO_xin1SlotQESyndra->posQE");
		}
	}
}

//---------------------------------------------------------------------//--------------------//
char error_specialSpell[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,83,112,101,99,105,97,108,108,32,83,112,101,108,108,0};	//"ERROR : Dodge Speciall Spell";
void Evade_SpellSpecial()
{
	if (!MY_HERO || !myTeamId || !G_Module)	 return;

	Load_HeroSpecial();
	fuckSyndra();

	__try
	{
		////////////---- Zac :
		//////////if (hasZac)
		//////////{
		//////////	sprintf_s(error_specialSpell, "%s", "ERROR : Evade Zac E-R");
		//////////	Evade_Zac_E_va_R();
		//////////}


		//---- Lux :
		if (hasLux)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,76,117,120,32,82,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Lux R"
			DodS_FOWFOW_Lux_R();
		}
		
		//---- Xerath:
		if (hasXerath)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,88,101,114,97,116,104,32,81,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Xerath Q"
			DodS_FOWFOW__AND__NOFOW_Xerath_Q();
		}

		//---- Sion:
		if (hasSion)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,83,105,111,110,32,81,46,82,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Sion Q.R"
			DodS_NOFOW_Sion_R_and_Q();
		}	
				
		//---- Fiora :
		if (hasFiora)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,70,105,111,114,97,32,87,0};
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Fiora W"
			DodS_Fiora_W(); 
		}

		//---- Leblanc.W+WR :
		if (hasLeblanc)
		{ 
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,76,101,98,108,97,110,99,32,87,43,87,82,0};		
			sprintf_s(error_specialSpell, szTemp);					// "ERROR : Dodge Leblanc W+WR"
			DodS_Leblanc_W_WR();
		}

		//---- Rakan :
		if (hasRakan)
		{		
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,82,97,107,97,110,32,87,0};						
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Rakan W"
			DodS_Rakan_W();
		}

		//---- Malphite :
		if (hasMalphite)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,77,97,108,112,104,105,116,101,32,82,0};
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Malphite R"
			DodS_Malphite_R();
		}

		//---- Sejuani :
		if (hasSejuani)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,83,101,106,117,97,110,105,32,81,0};
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Sejuani Q"
			DodS_Sejuani_Q();
		}
		
		//---- Shen :
		if (hasShen)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,83,104,101,110,32,69,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Shen E"
			DodS_Shen_E();
		}

		//---- Tryndamere :
		if (hasTryndamere)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,84,114,121,110,100,97,109,101,114,101,32,69,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Tryndamere E"
			DodS_Tryndamere_E();
		}

		//---- Gragas :
		if (hasGragas)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,71,114,97,103,97,115,32,69,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Gragas E"
			DodS_Gragas_E();
		}
		
		//---- Gnar :
		if (hasGnar)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,71,110,97,114,32,69,49,50,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Gnar E12"
			DodS_Gnar_E1E2();
		}

		//---- Khazix :
		if (hasKhazix)
		{
			char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,75,104,97,122,105,120,32,69,49,50,0};	
			sprintf_s(error_specialSpell, "%s", szTemp);			// "ERROR : Dodge Khazix E12"
			DodS_Khazix_E12();
		}
	}
	__except(1)
	{
		SEND_TEXT_SYSTEM(error_specialSpell);
	}
}

//---------------------------------------------------------------------//--------------------//
void Special_OnProcessSpell(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	//....
}

//---------------------------------------------------------------------//--------------------//
void Special_OnCreateMissile(KNpc* missileObj, SpellData &spellData)
{	
	//...
}

////---------------------------------------------------------------------//--------------------//
//void List_Unit()
//{
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwUnit1 = *(DWORD*)tempUnit;
//	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//	if (!dwUnit1 || !dwUnit2 ) return;
//	int countUnit = (dwUnit2 - dwUnit1)/4;
//	for (int iii = 0; iii < countUnit; ++iii)
//	{
//		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//		if (dwUnit3 == 0) continue;
//		KNpc *enemyHiu = (KNpc*)dwUnit3;
//		if (IS_OBJ_DELETED(enemyHiu))    continue;
//		if (IS_DEAD(enemyHiu))    continue;
//		if (!IS_MINION(enemyHiu)) continue;
//		//if (enemyHiu->nTeam_ID == 0x12C)    continue;
//		if (CheckName("Turret", enemyHiu->GetNameNpc())) continue;
//		if (CheckName("Minion", enemyHiu->GetNameNpc())) continue;
//		if (CheckName(sz__Sru_, enemyHiu->GetNameNpc())) continue;
//		if (CheckName(sz__SRU_, enemyHiu->GetNameNpc())) continue;
//		if (CheckName("Plant", enemyHiu->GetNameNpc())) continue;
//
//		//if (!CheckNameEx(enemyHiu->GetNameHero(), "TestCubeRender10Vision")) continue;
//		
//		__oMsg("Unit : %s [%x][%x][%s]", enemyHiu->GetNameNpc(), enemyHiu->nTeam_ID, enemyHiu->nIndex, enemyHiu->GetNameHero());
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//#include "SpellDrawer.h"
//#include "Position.h"
//void TEST_E_SYNDRA()
//{
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//	
//	std::vector<KNpc*> _listSphere;
//
//	KCastSpell* pCast = (KCastSpell*)myHero->_pCastSpell;
//	if (!pCast) return;
//
//	Vec3D estart(pCast->SourcePos.x, pCast->SourcePos.y, pCast->SourcePos.z);
//	Vec3D eend_1  (pCast->MaxDestPos.x, pCast->MaxDestPos.y, pCast->MaxDestPos.z);
//	Vec3D eend = Extend(estart, eend_1, 800);
//
//	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwUnit1 = *(DWORD*)tempUnit;
//	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//	if (!dwUnit1 || !dwUnit2 ) return;
//	int countUnit = (dwUnit2 - dwUnit1)/4;
//	for (int iii = 0; iii < countUnit; ++iii)
//	{
//		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//		if (dwUnit3 == 0) continue;
//		KNpc *sphere = (KNpc*)dwUnit3;
//		if (IS_DEAD(sphere))    continue;
//		if (!IS_MINION(sphere)) continue;
//
//		if ((BYTE)sphere->nIsTargetableToTeam != 4 && CheckName(sz__Seed, sphere->GetNameNpc()) && CheckName(sz__SyndraSphere, sphere->GetNameHero()))
//		{	
//			Vec3D direction = (eend - estart).Normalized();
//			Vec3D cnLeft    = eend + Perpendicular(direction) * (465 + 155 + 50);
//			Vec3D cnRight   = eend - Perpendicular(direction) * (465 + 155 + 50);
//			
//			if( !isLeftOfLineSegment(sphere->currentPos(), estart , cnLeft) && !isLeftOfLineSegment(sphere->currentPos(), cnLeft, cnRight) && !isLeftOfLineSegment(sphere->currentPos(), cnRight, estart))
//			{
//					if ((int)_listSphere.size() == 0)
//					{
//						_listSphere.push_back(sphere);
//						continue;
//					}
//
//					bool coSphereGanNhau = false;
//					for (int xx = 0; xx < (int)_listSphere.size(); ++xx)
//					{
//						if (IsUnitInList(_listSphere[xx]) && !IS_DEAD(_listSphere[xx]))
//						{
//							if (Distance(_listSphere[xx], sphere) <= 30)
//							{
//								coSphereGanNhau = true;
//								break;
//							}
//						}
//					}
//					if (coSphereGanNhau == false)
//					{
//						_listSphere.push_back(sphere);
//					}
//			}
//		}
//	}
//
//	for (int xx = 0; xx < (int)_listSphere.size(); ++xx)
//	{
//		if (IsUnitInList(_listSphere[xx]) && !IS_DEAD(_listSphere[xx]))
//		{
//			IsDashing(_listSphere[xx]);
//			Vec3D start = _listSphere[xx]->currentPos();
//			Vec3D end   = _listSphere[xx]->currentPos() + (_listSphere[xx]->currentPos() - myHero->currentPos()).Normalized() * (1250 - Distance(_listSphere[xx], myHero));
//			DrawLineRectangle(start, end, 90, 1, YELLOW);
//		}
//	}
//	
//
//	//Vec3D start = sphere->currentPos();
//	//Vec3D end   = sphere->currentPos() + (sphere->currentPos() - myHero->currentPos()).Normalized() * (1250 - Distance(sphere, myHero));
//	//DrawLineRectangle(start, end, 90, 1, YELLOW);
//}
//
////---------------------------------------------------------------------//--------------------//
//KNpc* enemy = 0;
//float timeXXX = 0;
//void Test_misile()
//{
//	return;
//
//	if ((float)GetTickCount() - timeXXX > 3000) timeXXX = 0;
//
//	KNpc* myHero = GetPlayer();
//	if(!myHero) return;
//
//	//Vec3D facePos_extend = Extend(myHero->currentPos(), GET_REAL_FACING_POS(myHero), 200);
//	//Draw2DCircle(facePos_extend, 10, x_BLACK);
//	////return;
//	
//	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	if (hModule == 0) return;
//
//	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + hModule;
//
//	DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//	DWORD dw1 = *(DWORD*)dw0;
//	if (!dw1) return;
//
//	int nCount_n = *(DWORD*)(dw0 + 4);
//	if (!nCount_n) return;
//	
//	KEnemyDistance phacHIU[3] = {0};
//	int tempCount_Hiu = 0;
//
//	float radius = 12;
//	for (int kk = 0; kk < nCount_n; ++kk)
//	{
//		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//		if (dw3 == 0) continue;
//		KNpc *missileObj = (KNpc*)dw3;
//		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//
//		//if(missileObj->nIndex < 0x3FFFFCC8)      continue;
//		//if(!IS_OBJECT_TYPE(missileObj, 0x8000))	 continue;
//		
//		if (CheckName("SRU", missileObj->GetNameNpc())) continue;
//		if (CheckName("sru", missileObj->GetNameNpc())) continue;
//		if (CheckName("Sru", missileObj->GetNameNpc())) continue;
//		if (CheckName("LevelProp", missileObj->GetNameNpc())) continue;
//		if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
//		if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
//		if (CheckName("Barracks", missileObj->GetNameNpc())) continue;
//		if (CheckName("Turret", missileObj->GetNameNpc())) continue;
//		if (CheckName("Swain_", missileObj->GetNameNpc())) continue;
//		if (CheckName("candle_", missileObj->GetNameNpc())) continue;
//		if (CheckName("Plinths_", missileObj->GetNameNpc())) continue;
//		if (CheckName("Plant", missileObj->GetNameNpc())) continue;
//		if (CheckName("_T1", missileObj->GetNameNpc())) continue;
//		if (CheckName("_T2", missileObj->GetNameNpc())) continue;
//		if (CheckName("monsterCamp", missileObj->GetNameNpc())) continue;
//		
//		
//		
//		/*if (CheckName("hiu", missileObj->GetNameNpc()))
//		{
//			if (!IS_DEAD(missileObj))
//			{
//				if (tempCount_Hiu < 3)
//				{
//					phacHIU[tempCount_Hiu].pEnemy = missileObj;
//					tempCount_Hiu += 1;
//				}
//
//				Draw2DCircle(missileObj->currentPos(), radius, x_ORANGE);
//				radius = radius + 3;
//				__oMsg("[DEAD: %x], [Time: %.3f] [%s]", IS_DEAD(missileObj), GetTimeGame(), missileObj->GetNameHero());
//			}
//		}*/
//		
//		if (CheckName("Poppy_Base_P_cas",missileObj->GetNameNpc()) || CheckName("Poppy_Base_R_preChannel",missileObj->GetNameNpc()) ||  
//			CheckName("Poppy_Base_R_cas",missileObj->GetNameNpc()) ||
//			CheckName("Rakan_Base_P_wing_avatar",missileObj->GetNameNpc())
//		       
//		   )
//		{
//			continue;
//		}
//
//		/*if (CheckName("SyndraQSpell", missileObj->GetNameNpc()))
//		{
//			__oMsg("(Type: %x)[TeamID: %x](%s) :%x, [Time: %.3f] - [currentPos: %.2f,%.2f,%.2f] - [serPos: %.2f,%.2f,%.2f]", OBJECT_TYPE(missileObj), missileObj->nTeam_ID, missileObj->GetNameNpc(), missileObj->nIndex, GetTimeGame(), missileObj->currentPos().x, missileObj->currentPos().y, missileObj->currentPos().z, missileObj->ServerPosition.x, missileObj->ServerPosition.y, missileObj->ServerPosition.z);
//			Draw2DCircle(missileObj->MissileDestPos, 25, x_GREEN_BLUE);
//
//			Vec3D start(missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//			Vec3D end   = start + (start - myHero->currentPos()).Normalized() * (1250 - Distance(start, myHero->currentPos()));
//			DrawLineRectangle(start, end, 90, 1, YELLOW);
//			
//			
//		}*/
//		
//		
//		if (IS_HERO(missileObj) && missileObj != myHero) enemy = missileObj;
//		if (CheckName("Ornn_Base_E_destination_mark",missileObj->GetNameNpc()) && CheckName("Ornn_Base_E_destination_mark",missileObj->GetNameNpc()))			//Irelia_Base_E_Blades - IreliaEParticleMissile
//		{
//			if (!IS_OBJ_DELETED(missileObj) && !IS_DEAD(missileObj))
//			{
//				/*if (tempCount_Hiu < 3)
//				{
//					phacHIU[tempCount_Hiu].pEnemy = missileObj;
//					tempCount_Hiu += 1;
//				}
//				else break;*/
//
//
//				//if (enemy != 0)__oMsg("(DISTANT: %f)", Distance(enemy, missileObj));
//
//				//IsDashing(myHero);
//				//__oMsg("(Type: %x)[TeamID: %x](%s) :%x, [Time: %.3f] - [currentPos: %.2f,%.2f,%.2f] - [serPos: %.2f,%.2f,%.2f]", OBJECT_TYPE(missileObj), missileObj->nTeam_ID, missileObj->GetNameNpc(), missileObj->nIndex, GetTimeGame(), missileObj->currentPos().x, missileObj->currentPos().y, missileObj->currentPos().z, missileObj->ServerPosition.x, missileObj->ServerPosition.y, missileObj->ServerPosition.z);
//				Draw2DCircle(myHero->currentPos(), 6, x_GREEN_BLUE);
//				Draw2DCircle(missileObj->currentPos(), 25, x_BLACK);
//			}
//		}
//
//		if (CheckName("EyebeamVision",missileObj->GetNameNpc()) && CheckName("EyebeamVision",missileObj->GetNameNpc()))	//Irelia_Base_E_Team_Indicator
//		{
//			if (!IS_OBJ_DELETED(missileObj) && !IS_DEAD(missileObj))
//			{
//				//IsDashing(myHero);
//				//__oMsg("(Type: %x)[TeamID: %x](%s) :%x, [Time: %.3f] - [currentPos: %.2f,%.2f,%.2f] - [serPos: %.2f,%.2f,%.2f]", OBJECT_TYPE(missileObj), missileObj->nTeam_ID, missileObj->GetNameNpc(), missileObj->nIndex, GetTimeGame(), missileObj->currentPos().x, missileObj->currentPos().y, missileObj->currentPos().z, missileObj->ServerPosition.x, missileObj->ServerPosition.y, missileObj->ServerPosition.z);
//				Draw2DCircle(myHero->currentPos(), 30, x_YELLOW);
//				Draw2DCircle(missileObj->currentPos(), 45, x_BLACK);
//				//List_Unit();
//			}
//		}
//
//		
//		if (CheckName("GravesChargeShotShot", missileObj->GetNameNpc()) || CheckName("GravesChargeShotFxMissile", missileObj->GetNameNpc())) 
//		{
//			//__oMsg("DDD- : %f", Distance_2D(missileObj->MissileSrcPos, missileObj->MissileDestPos));
//			//__oMsg("DDD- : %f", Distance_2D(missileObj->MissileSrcPos, missileObj->CurrentPos));
//		}
//
//		//if (myHero->_pCastSpell) __oMsg(" --------------------: %f\n", GetTimeGame());
//
//
//		char szTest[100] = "Ziggs123";
//
//		if (CheckName("Nami", missileObj->GetNameNpc()) || IS_OBJECT_TYPE(missileObj, 0x8000) || CheckName("EyebeamVision", missileObj->GetNameNpc()) 
//			|| CheckName("Poot", missileObj->GetNameNpc()) || CheckName("jeremiah", missileObj->GetNameNpc())
//			|| CheckName("hiu", missileObj->GetNameNpc()) || CheckName("testcube", missileObj->GetNameNpc()))
//		{
//			//__oMsg("(Type: %x)[TeamID: %x](%s) :%x, [Time: %.3f] - [cur: %.2f,%.2f,%.2f] - [src: %.2f,%.2f,%.2f] [des: %.2f,%.2f,%.2f]", OBJECT_TYPE(missileObj), missileObj->nTeam_ID, missileObj->GetNameNpc(), missileObj->nIndex, GetTimeGame(), missileObj->currentPos().x, missileObj->currentPos().y, missileObj->currentPos().z, missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z, missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//				////__oMsg("	   (Hero: %x, %.2f,%.2f,%.2f]", myHero, myHero->currentPos().x, myHero->currentPos().y, myHero->currentPos().z);
//		
//				////__oMsg("[ownerID: %x][src: %.2f,%.2f,%.2f] - [dest: %.2f,%.2f,%.2f] - [cursor: %.2f,%.2f,%.2f]\n", missileObj->nMissileOwnerID_1, missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z, missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z, missileObj->CurrentPos.x, missileObj->CurrentPos.y, missileObj->CurrentPos.z);
//		}
//
//		if (/*CheckName("Zac", missileObj->GetNameNpc()) && */IS_OBJECT_TYPE(missileObj, 0x8000))
//		{
//			KMissileData* misData = (KMissileData*)missileObj->nMissileData;
//			if (misData)
//			{
//				KMissile_Struct_3* pMiss_Struct_3 = (KMissile_Struct_3*)misData->nMissile_Struct_3;
//				if (pMiss_Struct_3)
//				{
//					__oMsg("           -[%.3f][%.3f]MisSpeed: %f (%.2f - %.2f), %s, %s [src: %.3f, %.3f, %.3f][des: %.3f, %.3f, %.3f]", GetTimeGame(), Distance_3D(missileObj->MissileSrcPos, missileObj->MissileDestPos),pMiss_Struct_3->nMissileSpeed, pMiss_Struct_3->nMissileMinSpeed, pMiss_Struct_3->nMissileMaxSpeed, misData->GetMissileOwner_Name(), missileObj->GetNameNpc(), missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z, missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//
//					//List_Unit();
//				}
//
//				//continue;
//
//				Draw2DCircle(missileObj->currentPos(), 6, x_YELLOW);
//				Vec3D src(missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//				Vec3D des(missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//				if (timeXXX == 0) timeXXX = (float)GetTickCount();
//				if (timeXXX > 0)
//				{
//					//Vec3D spellPos = spell.startPos + spell.direction * spell.info.projectileSpeed * (spellTime / 1000);
//					float spellTime = (float)GetTickCount() - timeXXX;
//					float xxx = 1500;
//					if (pMiss_Struct_3->nMissileSpeed > 0) xxx = pMiss_Struct_3->nMissileSpeed ;
//					Vec3D spellPos  = src+ (des-src).Normalized() * xxx * (spellTime / 1000);
//					Draw2DCircle(spellPos, 18, x_RED);
//				}
//			}
//		}
//		
//	}
//
//	if (phacHIU[0].pEnemy && phacHIU[1].pEnemy && phacHIU[2].pEnemy)
//	{
//		Vec3D s1(phacHIU[0].pEnemy->MissileSrcPos.x, phacHIU[0].pEnemy->MissileSrcPos.y, phacHIU[0].pEnemy->MissileSrcPos.z);
//		Vec3D s2(phacHIU[1].pEnemy->MissileSrcPos.x, phacHIU[1].pEnemy->MissileSrcPos.y, phacHIU[1].pEnemy->MissileSrcPos.z);
//		Vec3D s3(phacHIU[2].pEnemy->MissileSrcPos.x, phacHIU[2].pEnemy->MissileSrcPos.y, phacHIU[2].pEnemy->MissileSrcPos.z);
//
//		Vec3D d1(phacHIU[0].pEnemy->MissileDestPos.x, phacHIU[0].pEnemy->MissileDestPos.y, phacHIU[0].pEnemy->MissileDestPos.z);
//		Vec3D d2(phacHIU[1].pEnemy->MissileDestPos.x, phacHIU[1].pEnemy->MissileDestPos.y, phacHIU[1].pEnemy->MissileDestPos.z);
//		Vec3D d3(phacHIU[2].pEnemy->MissileDestPos.x, phacHIU[2].pEnemy->MissileDestPos.y, phacHIU[2].pEnemy->MissileDestPos.z);
//
//		Vec3D goc1 = (d1 - s1).Normalized();
//		Vec3D goc2 = (d2 - s2).Normalized();
//		Vec3D goc3 = (d3 - s3).Normalized();
//
//		__oMsg("%f - %f - %f", AngleBetween(goc1, goc2), AngleBetween(goc2, goc3), AngleBetween(goc1, goc3));
//	}
//
//	/*if (phacHIU[0].pEnemy) 
//	{
//		Draw2DCircle(phacHIU[0].pEnemy->currentPos(), 15, x_ORANGE);
//		__oMsg("%.3f, %.3f, %.3f", phacHIU[0].pEnemy->currentPos().x, phacHIU[0].pEnemy->currentPos().y, phacHIU[0].pEnemy->currentPos().z);
//	}
//	if (phacHIU[1].pEnemy)
//	{
//		Draw2DCircle(phacHIU[1].pEnemy->currentPos(), 25, x_BLUE);
//		__oMsg("%.3f, %.3f, %.3f ----", phacHIU[1].pEnemy->currentPos().x, phacHIU[1].pEnemy->currentPos().y, phacHIU[1].pEnemy->currentPos().z);
//	}*/
//}


