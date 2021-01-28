#include "DodgeViktorS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
////---------------------------------------------------------------------//--------------------//
//void Evade_Viktor_W()
//{
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwHero1 = *(DWORD*)tempHero;
//	DWORD dwHero2 = *(DWORD*)tempHeroMax;
//	if (!dwHero1 || !dwHero2 ) return;
//
//	int countHero = (dwHero2 - dwHero1)/4;
//	for (int i = 0; i < countHero; ++i)
//	{
//		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
//		if (dwHero3 == 0) continue;
//		KNpc *enemyHero = (KNpc*)dwHero3;
//		if (IS_DEAD(enemyHero)) continue;
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Viktor")) continue;
//
//		//------//------//------:
//		//if (IsCanSee(enemyHero))
//		//{
//		//	if (Distance(enemyHero, myHero) > 2500)	continue;
//
//		//	KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//		//	if (!args) continue;
//
//		//	KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//		//	if(!pK_str2) continue;
//
//		//	std::string spell_name(pK_str2->GetSkillName());
//		//	if (spell_name.compare("XerathArcaneBarrage2") != 0) continue;		
//
//		//	if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//		//	//------//------//------:
//		//	std::string Special_name("XerathW_Special");
//		//	std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//		//	if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//		//	{
//		//		SpellData spellData = it_onProcessSpells->second;
//
//		//		Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//		//		Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//
//		//		if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//		//		{
//		//			float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//		//			if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//		//			{
//		//				//__oMsg("---((*11*))----- Xeratth-W-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//		//				it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//		//				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//		//			}
//		//		}
//		//	}
//		//}
//		//else
//		{
//			//if (DodgeFOWSpells_menu == false) return;
//
//			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			DWORD dw1 = *(DWORD*)dw0;
//			if (!dw1) return;
//
//			int countAllObj = *(DWORD*)(dw0 + 4);
//			if (!countAllObj) return;
//
//			for (int kk = 0; kk < countAllObj; ++kk)
//			{
//				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//				if (dw3 == 0) continue;
//				KNpc *missileObj = (KNpc*)dw3;
//
//				if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//				if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//				if (OBJECT_TYPE(missileObj) != 1)		 continue;
//
//				if (CheckName("Viktor_Catalyst_", missileObj->GetNameNpc()) || (CheckName("_W_AUG_", missileObj->GetNameNpc()) && CheckName("Viktor", missileObj->GetNameNpc())))	//Viktor_Catalyst_green , Viktor_base_W_AUG_green
//				{
//					//------//------//------:
//					std::string Special_name("ViktorW_Special");
//					std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//					if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//					{
//						SpellData spellData = it_onProcessSpells->second;
//
//						Vec3D EndPos   = missileObj->currentPos();
//						Vec3D StartPos = Extend(EndPos, enemyHero->currentPos(), -spellData.range);
//
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//						{
//							float missileLifeTime = spellData.projectileSpeed > 0 ? 5225.0f : 1000.0f;
//
//							if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((*22*))----- Viktor_W_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//								it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Viktor_E()
//{
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwHero1 = *(DWORD*)tempHero;
//	DWORD dwHero2 = *(DWORD*)tempHeroMax;
//	if (!dwHero1 || !dwHero2 ) return;
//
//	int countHero = (dwHero2 - dwHero1)/4;
//	for (int i = 0; i < countHero; ++i)
//	{
//		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
//		if (dwHero3 == 0) continue;
//		KNpc *enemyHero = (KNpc*)dwHero3;
//		if (IS_DEAD(enemyHero)) continue;
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Viktor")) continue;
//		
//		//----//----//----:
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//			if (CheckNameEx("ViktorDeathRayMissile", missileObj->GetNameNpc()) || CheckName("ViktorEAugMissile", missileObj->GetNameNpc()))	//ViktorDeathRayMissile, ViktorEAugMissile
//			{
//				//------//------//------:
//				std::string Special_name("ViktorE_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					SpellData spellData = it_onProcessSpells->second;
//
//					Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//					Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//					{
//						float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;
//
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((*11*))----- Viktor_E1_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//						}
//					}
//				}
//			}
//			if (CheckName("ViktorEAugMissile", missileObj->GetNameNpc()))	//ViktorEAugMissile
//			{
//				//------//------//------:
//				std::string Special_name("ViktorE2_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					SpellData spellData = it_onProcessSpells->second;
//		
//					Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//					Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
//					
//					spellData.spellDelay = 1000 * spellData.range/1050 + 250;		//1050 la speed cua E-1
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//					{
//						float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay : 1000.0f;
//
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((*22*))----- Viktor_E222_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//						}
//					}
//				}
//			}
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Viktor_E2_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (spellData.missileName.compare("ViktorEAugMissile") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	spellData.range = StartPos.Distance2D(EndPos);

	////////	if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////	{
	////////		float missileLifeTime = 1222.0f;

	////////		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////			
	////////			spellData.projectileSpeed = 1050;																	
	////////			spellData.spellDelay      = 0;
	////////			spellData.waitExtra		  = 0;

	////////			//__oMsg("---((*11*))----- Viktor_E2.1_-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////			CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);

	////////			spellData.projectileSpeed = 1500;																	
	////////			spellData.spellDelay      = 1000;
	////////			spellData.waitExtra		  = 200;
	////////			//__oMsg("---((*22*))----- Viktor_E2.2_-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////			CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0, true, None, true, 85);
	////////		}
	////////	}
	////////}
}

////---------------------------------------------------------------------//--------------------//
void Evade_Varus_Q_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (spellData.missileName.compare("VarusQMissile") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////
	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D curPos   = missileObj->currentPos();
	////////	Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
	////////	
	////////	spellData.range = StartPos.Distance2D(EndPos);

	////////	if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////	{
	////////		float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;

	////////		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			//__oMsg("---((*11*))----- Varus_Q_-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////			CreateSpellData(hero, curPos, EndPos, spellData, 0, 0);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}

////---------------------------------------------------------------------//--------------------//
//void Evade_Varus_Q()
//{
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwHero1 = *(DWORD*)tempHero;
//	DWORD dwHero2 = *(DWORD*)tempHeroMax;
//	if (!dwHero1 || !dwHero2 ) return;
//
//	int countHero = (dwHero2 - dwHero1)/4;
//	for (int i = 0; i < countHero; ++i)
//	{
//		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
//		if (dwHero3 == 0) continue;
//		KNpc *enemyHero = (KNpc*)dwHero3;
//		if (IS_DEAD(enemyHero)) continue;
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID) continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Varus")) continue;
//
//		//----//----//----:
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//			if (CheckNameEx("VarusQMissile", missileObj->GetNameNpc()))	//VarusQMissile, 
//			{
//				//------//------//------:
//				std::string Special_name("VarusQ_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					SpellData spellData = it_onProcessSpells->second;
//
//					Vec3D curPos   = missileObj->currentPos();
//					Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//					Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
//					
//					spellData.range = StartPos.Distance2D(EndPos);
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//					{
//						float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;
//
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((*11*))----- Varus_Q_-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//							CreateSpellData(enemyHero, curPos, EndPos, spellData, 0, 0);
//						}
//					}
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Rakan_W()
//{
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwHero1 = *(DWORD*)tempHero;
//	DWORD dwHero2 = *(DWORD*)tempHeroMax;
//	if (!dwHero1 || !dwHero2 ) return;
//
//	int countHero = (dwHero2 - dwHero1)/4;
//	for (int i = 0; i < countHero; ++i)
//	{
//		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
//		if (dwHero3 == 0) continue;
//		KNpc *enemyHero = (KNpc*)dwHero3;
//		if (IS_DEAD(enemyHero)) continue;
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID) continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Rakan")) continue;
//
//		//----//----//----:
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)    continue;
//			if (OBJECT_TYPE(missileObj) != 1)       continue;
//
//			//if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//			//if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//			if (CheckName("_W_indicator", missileObj->GetNameNpc()) && CheckName("Rakan", missileObj->GetNameNpc()))	//Rakan_Base_W_indicator
//			{
//				//------//------//------:
//				std::string Special_name("RakanW_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					SpellData spellData = it_onProcessSpells->second;
//
//					Vec3D EndPos   = missileObj->currentPos(); 
//					Vec3D StartPos = Extend(EndPos, myHero->currentPos(), -spellData.range); 
//
//					spellData.range = StartPos.Distance2D(EndPos);
//
//					if (EndPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//					{
//						float missileLifeTime = spellData.projectileSpeed > 0 ? 1666 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;
//
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							//spellData.spellDelay = 550 + 1000 * EndPos.Distance2D(enemyHero->currentPos())/spellData.projectileSpeed;
//
//							//__oMsg("---((*11*))----- Rakan_W_-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//						}
//					}
//				}
//			}
//		}
//	}
//}


