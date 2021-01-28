#include "DodgeOriannaS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
////---------------------------------------------------------------------//--------------------//
//void Evade_Orianna_Q()	//co the lam nhu missile bthuong dc, khac o cho~ range thay doi
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Orianna")) continue;
//		if (Distance(enemyHero, myHero) > 2500) continue;
//
//		//------//------//------:
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
//			if (CheckName("OrianaIzuna", missileObj->GetNameNpc()))
//			{
//				std::string mis_Name(missileObj->GetNameNpc());	//"OrianaIzuna"
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					Vec3D StartPos(missileObj->MissileSrcPos.x , missileObj->MissileSrcPos.y , missileObj->MissileSrcPos.z);
//					Vec3D EndPos  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//					
//					it_onMissileSpells->second.range = Distance(StartPos, EndPos) + 25;
//					SpellData spellData = it_onMissileSpells->second;
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 2000)
//					{
//						//--------------------------------:
//						if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//						float missileLifeTime = 888 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//						if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((***))----- Orianna_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//		}
//	}	
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Orianna_E()	//co the lam nhu missile bthuong dc, khac o cho~ range thay doi
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Orianna")) continue;
//		if (Distance(enemyHero, myHero) > 2500) continue;
//
//		//------//------//------:
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
//			if (CheckName("OrianaRedact", missileObj->GetNameNpc()))
//			{
//				std::string mis_Name(missileObj->GetNameNpc());	//"OrianaRedact"
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					Vec3D StartPos(missileObj->MissileSrcPos.x , missileObj->MissileSrcPos.y , missileObj->MissileSrcPos.z);
//					Vec3D EndPos  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//
//					it_onMissileSpells->second.range = Distance(StartPos, EndPos) + 5;
//					SpellData spellData = it_onMissileSpells->second;
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 2000)
//					{
//						//--------------------------------:
//						if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//						float missileLifeTime = 888 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//						if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((***))----- Orianna_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//		}
//	}	
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Orianna_R()	
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		 continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Orianna")) continue;
//		if (Distance(enemyHero, myHero) > 2500)				 continue;
//		
//		if (IsCanSee(enemyHero))
//		{
//			if (enemyHero->isRecall())	continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name));		//L#: .TryGetValue
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//
//				DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//				DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//				DWORD dwUnit1 = *(DWORD*)tempUnit;
//				DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//				if (!dwUnit1 || !dwUnit2 ) return;
//				int countUnit = (dwUnit2 - dwUnit1)/4;
//
//				bool hasDoomBall = false;
//				for (int iii = 0; iii < countUnit; ++iii)
//				{
//					DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//					if (dwUnit3 == 0) continue;
//					KNpc *enemyDoomBall = (KNpc*)dwUnit3;
//					if (IS_DEAD(enemyDoomBall))    continue;
//					if (!IS_MINION(enemyDoomBall)) continue;
//					if (enemyDoomBall->nTeam_ID == myHero->nTeam_ID)			continue;
//					if (CheckName(enemyDoomBall->GetNameNpc(), "TheDoomBall"))
//					{
//						if (CheckNameEx(enemyDoomBall->GetNameHero(), "OriannaBall"))
//						{	
//							hasDoomBall = true;
//							Vec3D endPos2 = enemyDoomBall->currentPos();
//
//							float missileLifeTime = 3000;
//							if ((float)GetTickCount() - it_onProcessSpells->second.lastCastSpellTime > missileLifeTime)
//							{
//								CreateSpellData(enemyHero, endPos2, endPos2, spellData, 0, 0);
//								it_onProcessSpells->second.lastCastSpellTime = (float)GetTickCount();
//								break;
//							}
//						}	
//					}
//				}
//
//				if (hasDoomBall == false)
//				{
//					Vec3D endPos2 = enemyHero->currentPos();
//
//					float missileLifeTime = 3000;
//					//__oMsg("delta : %f", (float)GetTickCount() - it_onProcessSpells->second.lastCastSpellTime);
//					if ((float)GetTickCount() - it_onProcessSpells->second.lastCastSpellTime > missileLifeTime)
//					{
//						CreateSpellData(enemyHero, endPos2, endPos2, spellData, 0, 0);
//						it_onProcessSpells->second.lastCastSpellTime = (float)GetTickCount();
//					}
//				}	
//			}
//		}
//		else	//FOW
//		{
//			if (DodgeFOWSpells_menu == false) return;
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
//				if (CheckName("R_VacuumIndicator",missileObj->GetNameNpc()) && CheckName("Orianna",missileObj->GetNameNpc()))
//				{			
//					//__oMsg("--ORIANNA_FOW-YES-222: %f ", GetTimeGame());
//					std::string mis_Name("OrianaR_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//						DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//						DWORD dwUnit1 = *(DWORD*)tempUnit;
//						DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//						if (!dwUnit1 || !dwUnit2 ) return;
//						int countUnit = (dwUnit2 - dwUnit1)/4;
//
//						bool hasDoomBall = false;
//						for (int iii = 0; iii < countUnit; ++iii)
//						{
//							DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//							if (dwUnit3 == 0) continue;
//							KNpc *enemyDoomBall = (KNpc*)dwUnit3;
//							if (IS_DEAD(enemyDoomBall))    continue;
//							if (!IS_MINION(enemyDoomBall)) continue;
//							if (enemyDoomBall->nTeam_ID == myHero->nTeam_ID)			continue;
//							if (CheckName(enemyDoomBall->GetNameNpc(), "TheDoomBall"))
//							{
//								if (CheckNameEx(enemyDoomBall->GetNameHero(), "OriannaBall"))
//								{	
//									hasDoomBall = true;
//									Vec3D endPos2 = enemyDoomBall->currentPos();
//									
//									if (endPos2.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//									{
//										float missileLifeTime = 3000;
//										if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//										{
//											CreateSpellData(enemyHero, endPos2, endPos2, spellData, 0, 0);
//											it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//											break;
//										}
//									}
//								}	
//							}
//						}
//
//						if (hasDoomBall == false)	//co ve ko vao cho~ nay`
//						{
//							Vec3D endPos2 = enemyHero->currentPos();
//
//							if (endPos2.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//							{
//								float missileLifeTime = 3000;
//								if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//								{
//									CreateSpellData(enemyHero, endPos2, endPos2, spellData, 0, 0);
//									it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//								}
//							}
//						}	
//					}
//				}
//			}
//		}
//	}	
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Orianna_Q_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (spellData.missileName.compare("OrianaIzuna") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	if (start.Distance2D(myHero->currentPos()) < 2500)
	////////	{
	////////		//--------------------------------:
	////////		std::string mis_Name(missileObj->GetNameNpc());
	////////		bool objectAssigned = false;

	////////		for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
	////////		{
	////////			Spell spell = it_1->second;
	////////			Vec3D dir   = (end - start).Normalized();

	////////			if(str_tolower(spell.info.missileName).compare(str_tolower(mis_Name)) == 0)			// todo: fix urf spells
	////////			{
	////////				if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
	////////				{
	////////					it_1->second.spellObject = missileObj;

	////////					spellData.lastCreateMissileTime = (float)GetTickCount();
	////////					objectAssigned = true;
	////////					//__oMsg("	  ---------(Orianna-Q)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		float missileLifeTime = 1666;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			spellData.range = start.Distance2D(end) + 50;
	////////			//__oMsg("---((*11.1: %.3f))----- Orianna_Q_CREATE-MISSLE-11111: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			CreateSpellData(hero, start, end, spellData, missileObj);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Orianna_E_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (spellData.missileName.compare("OrianaRedact") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	if (start.Distance2D(myHero->currentPos()) < 2000)
	////////	{
	////////		//--------------------------------:
	////////		std::string mis_Name(missileObj->GetNameNpc());
	////////		bool objectAssigned = false;

	////////		for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
	////////		{
	////////			Spell spell = it_1->second;
	////////			Vec3D dir   = (end - start).Normalized();

	////////			if(str_tolower(spell.info.missileName).compare(str_tolower(mis_Name)) == 0)			// todo: fix urf spells
	////////			{
	////////				if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
	////////				{
	////////					it_1->second.spellObject = missileObj;

	////////					spellData.lastCreateMissileTime = (float)GetTickCount();
	////////					objectAssigned = true;
	////////					//__oMsg("	  ---------(Orianna-E)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		float missileLifeTime = 1666;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			spellData.range = start.Distance2D(end) + 25;
	////////			//__oMsg("---((*11.1: %.3f))----- Orianna_E_CREATE-MISSLE-11111: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			CreateSpellData(hero, start, end, spellData, missileObj);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Orianna_R_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("OrianaDetonateCommand") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:
	////////DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////if (!dwUnit1 || !dwUnit2 ) return;
	////////int countUnit = (dwUnit2 - dwUnit1)/4;

	////////bool hasDoomBall = false;
	////////for (int iii = 0; iii < countUnit; ++iii)
	////////{
	////////	DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////	if (dwUnit3 == 0) continue;
	////////	KNpc *enemyDoomBall = (KNpc*)dwUnit3;
	////////	if (IS_DEAD(enemyDoomBall))    continue;
	////////	if (!IS_MINION(enemyDoomBall)) continue;
	////////	if (enemyDoomBall->nTeam_ID == myHero->nTeam_ID) continue;
	////////	if (Distance(myHero, enemyDoomBall) > 1500)		 continue;
	////////	if (CheckName(enemyDoomBall->GetNameNpc(), "TheDoomBall"))
	////////	{
	////////		if (CheckNameEx(enemyDoomBall->GetNameHero(), "OriannaBall"))
	////////		{	
	////////			//__oMsg("create-khi-co-ball");
	////////			hasDoomBall = true;
	////////			CreateSpellData(hero, enemyDoomBall->currentPos(), enemyDoomBall->currentPos(), spellData, 0, 0);
	////////			return;
	////////		}	
	////////	}
	////////}

	////////if (hasDoomBall == false)
	////////{
	////////	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD dwHero1 = *(DWORD*)tempHero;
	////////	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////	if (!dwHero1 || !dwHero2 ) return;
	////////
	////////	int countHero = (dwHero2 - dwHero1)/4;
	////////	for (int i = 0; i < countHero; ++i)
	////////	{
	////////		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////		if (dwHero3 == 0) continue;
	////////		KNpc *enemyHero = (KNpc*)dwHero3;
	////////		if (enemyHero->nTeam_ID == myHero->nTeam_ID) continue;
	////////		if (Distance(myHero, enemyHero) > 1500)		 continue;
	////////		if (GET_BUFF(enemyHero, sz__orianaghostself) || GET_BUFF(enemyHero, "orianaghost"))
	////////		{
	////////			//__oMsg("create-khi-KO.CO-ball");

	////////			CreateSpellData(hero, enemyHero->currentPos(), enemyHero->currentPos(), spellData, 0, 0);
	////////			return;
	////////		}
	////////	}
	////////}


	//////////for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	//////////{
	//////////	it_2->second.KoUpCurrentPos = true;
	//////////}
}