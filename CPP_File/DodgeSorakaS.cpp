#include "DodgeSorakaS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
void Evade_Soraka_Q()
{
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		  continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Soraka")) continue;

	////////	//------//------//------:
	////////	if (IsCanSee(enemyHero))
	////////	{
	////////		if (Distance(enemyHero, myHero) > 2500)	continue;

	////////		KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////////		if (!args) continue;

	////////		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////////		if(!pK_str2) continue;

	////////		std::string spell_name(pK_str2->GetSkillName());
	////////		if (spell_name.compare("SorakaQ") != 0) continue;		

	////////		if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;

	////////		//------//------//------:
	////////		std::string Special_name = spell_name;
	////////		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////		{
	////////			SpellData spellData = it_onProcessSpells->second;

	////////			Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	////////			Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
	////////			float KC = Distance(StartPos, EndPos);
	////////			spellData.spellDelay = 200 +  KC + 25;

	////////			if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////			{
	////////				float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////				{
	////////					//__oMsg("---((*11*))----- SorakaQ-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////				}
	////////			}
	////////		}
	////////	}
	////////	else
	////////	{
	////////		if (DodgeFOWSpells_menu == false) return;

	////////		//------//------//------:
	////////		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	////////		DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	////////		if (!dw0) return;

	////////		DWORD dw1 = *(DWORD*)(dw0 + 8);
	////////		if (!dw1) return;

	////////		int nCount = *(DWORD*)(dw0 + 0xC);
	////////		if (!nCount) return;

	////////		for (int kk = 0; kk < nCount; ++kk)
	////////		{
	////////			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	////////			if (dw3 == 0) continue;
	////////			KNpc *missileObj = (KNpc*)dw3;

	////////			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	////////			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
	////////			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
	////////			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;

	////////			if (CheckName("SorakaQMissile", missileObj->GetNameNpc()))
	////////			{
	////////				//------//------//------:
	////////				std::string Special_name("SorakaQ");
	////////				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////				{
	////////					SpellData spellData = it_onProcessSpells->second;

	////////					Vec3D StartPos(missileObj->MissileSrcPos.x , missileObj->MissileSrcPos.y , missileObj->MissileSrcPos.z);
	////////					Vec3D EndPos  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
	////////					
	////////					float KC = Distance(StartPos, EndPos);
	////////					spellData.spellDelay = 0 +  KC - 225;

	////////					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////					{
	////////						float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////						{
	////////							//__oMsg("---((*22*))----- SorakaQ_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}
}

////---------------------------------------------------------------------//--------------------//
//void Evade_Sion_Q()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)	  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Sion")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2000)	continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("SionQ") != 0) continue;		
//
//			//if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//	
//			//------//------//------:
//			KBuffs* buffQ = GET_BUFF(enemyHero, "SionQ");
//			if (buffQ)
//			{
//				float startTime = buffQ->nBegin_Time;
//				if (GetTimeGame() - startTime > 0.4)
//				{
//					std::string Special_name = spell_name;
//					std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//					if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//					{
//						SpellData spellData = it_onProcessSpells->second;
//
//						Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//						Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//						{
//							float missileLifeTime = spellData.projectileSpeed > 0 ? 2666 + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//							if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((*11*))----- SionQQQ-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//								it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							}
//						}
//					}
//				}
//			}
//		}
//		else
//		{
//			//if (DodgeFOWSpells_menu == false) return;
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Sion_E()
{
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	  continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Sion")) continue;

	////////	//------//------//------:
	////////	if (IsCanSee(enemyHero))
	////////	{
	////////		if (Distance(enemyHero, myHero) > 2500)	continue;

	////////		KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////////		if (!args) continue;

	////////		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////////		if(!pK_str2) continue;

	////////		std::string spell_name(pK_str2->GetSkillName());
	////////		if (spell_name.compare("SionE") != 0) continue;		

	////////		if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;

	////////		//------//------//------:
	////////		std::string Special_name = spell_name;
	////////		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////		{
	////////			SpellData spellData = it_onProcessSpells->second;

	////////			Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	////////			Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
	////////			Vec3D End_Extend = Extend(StartPos, EndPos, 850);

	////////			if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1500 )
	////////			{
	////////				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////				{
	////////					DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	////////					DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////					DWORD dw1x = *(DWORD*)tempUnit;
	////////					DWORD dw2x = *(DWORD*)tempUnitMax;
	////////					if (dw1x && dw2x )
	////////					{
	////////						int nCount = (dw2x - dw1x)/4;
	////////						for (int kkk = 0; kkk < nCount; ++kkk)
	////////						{
	////////							DWORD dw3 = *(DWORD*)(dw1x + 4*kkk);
	////////							if (dw3 == 0) continue;
	////////							KNpc *allyMinion = (KNpc*)dw3;
	////////							if (IS_DEAD(allyMinion))    continue;
	////////							if (allyMinion->nTeam_ID != myHero->nTeam_ID) continue;
	////////							if (!IS_MINION(allyMinion)) continue;
	////////							if (!IsCanSee(allyMinion))  continue;
	////////							if (!CheckName(sz__Minion, allyMinion->GetNameNpc())) continue;

	////////							ProjectionInfo projection = ProjectOn(allyMinion->currentPos(), StartPos, End_Extend);
	////////							if (projection.IsOnSegment && projection.SegmentPoint.Distance2D(allyMinion->currentPos()) <= spellData.radius + 95)
	////////							{
	////////								//__oMsg("---((*VAO-VAO-VAO-MINION----)");
	////////								spellData.range     = 1375;
	////////								spellData.waitExtra	= 275;
	////////								break;
	////////							}
	////////						}
	////////					}

	////////					//__oMsg("---((*11*))----- SionEEE-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////				}
	////////			}
	////////		}
	////////	}
	////////	else
	////////	{
	////////		if (DodgeFOWSpells_menu == false) return;

	////////		//------//------//------:
	////////		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	////////		DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	////////		if (!dw0) return;

	////////		DWORD dw1 = *(DWORD*)(dw0 + 8);
	////////		if (!dw1) return;

	////////		int nCount = *(DWORD*)(dw0 + 0xC);
	////////		if (!nCount) return;

	////////		for (int kk = 0; kk < nCount; ++kk)
	////////		{
	////////			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	////////			if (dw3 == 0) continue;
	////////			KNpc *missileObj = (KNpc*)dw3;

	////////			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	////////			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
	////////			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
	////////			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;

	////////			if (CheckName("SionEMissile", missileObj->GetNameNpc()))
	////////			{
	////////				//------//------//------:
	////////				std::string Special_name("SionE");
	////////				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////				{
	////////					SpellData spellData = it_onProcessSpells->second;

	////////					Vec3D StartPos(missileObj->MissileSrcPos.x , missileObj->MissileSrcPos.y , missileObj->MissileSrcPos.z);
	////////					Vec3D EndPos  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);

	////////					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1500 )
	////////					{
	////////						float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////						{
	////////							//__oMsg("---((*22*))----- SionEEE_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////							CreateSpellData(enemyHero, StartPos, EndPos, spellData, missileObj, 0);
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Sion_R_and_Q()
{
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	  continue;
	////////	if (!IsCanSee(enemyHero))						  continue;
	////////	if (Distance(myHero, enemyHero) > 1500)			  continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Sion")) continue;

	////////	//------//------//------:
	////////	
	////////	KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////////	if (!args) continue;

	////////	KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////////	if(!pK_str2) continue;

	////////	std::string spell_name(pK_str2->GetSkillName());

	////////	//---R---//------//------:
	////////	if (spell_name.compare("SionR") == 0)
	////////	{
	////////		std::string Special_name = spell_name;
	////////		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////		{
	////////			SpellData spellData = it_onProcessSpells->second;

	////////			spellData.projectileSpeed = enemyHero->nMoveSpeed;

	////////			Vec3D facingPos = GET_REAL_FACING_POS(enemyHero);
	////////			Vec3D endPos    = enemyHero->currentPos() + (facingPos - enemyHero->currentPos()).Normalized() * 450;
	////////			Vec3D startPos  = enemyHero->currentPos();
	////////			spellData.range = 1300;

	////////			if (startPos.Distance2D(myHero->currentPos()) < 900)
	////////			{
	////////				float missileLifeTime = spellData.projectileSpeed > 0 ? 9999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////				{
	////////					//__oMsg("---((*11*))----- SionRRRR-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), startPos.Distance2D(endPos), spellData.spellDelay);
	////////					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////					CreateSpellData(enemyHero, startPos, endPos, spellData, 0, 0);
	////////				}
	////////			}
	////////		}
	////////	}

	////////	//---Q---//------//------:
	////////	if (spell_name.compare("SionQ") == 0)
	////////	{
	////////		KBuffs* buffQ = GET_BUFF(enemyHero, "SionQ");
	////////		if (buffQ)
	////////		{
	////////			float startTime = buffQ->nBegin_Time;
	////////			if (GetTimeGame() - startTime > 0.4)
	////////			{
	////////				std::string Special_name = spell_name;
	////////				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////				{
	////////					SpellData spellData = it_onProcessSpells->second;

	////////					Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	////////					Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);

	////////					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////					{
	////////						float missileLifeTime = spellData.projectileSpeed > 0 ? 2666 + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////						{
	////////							//__oMsg("---((*11*))----- SionQQQ-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Sion_E_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("SionE") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (Distance(hero, myHero) > 2000) return;

	//////////------//------//------:
	////////Vec3D StartPos(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////Vec3D End_Extend = Extend(StartPos, EndPos, 850);
	////////
	////////DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dw1x = *(DWORD*)tempUnit;
	////////DWORD dw2x = *(DWORD*)tempUnitMax;
	////////if (dw1x && dw2x )
	////////{
	////////	int nCount = (dw2x - dw1x)/4;
	////////	for (int kkk = 0; kkk < nCount; ++kkk)
	////////	{
	////////		DWORD dw3 = *(DWORD*)(dw1x + 4*kkk);
	////////		if (dw3 == 0) continue;
	////////		KNpc *allyMinion = (KNpc*)dw3;
	////////		if (IS_DEAD(allyMinion))    continue;
	////////		if (allyMinion->nTeam_ID != myHero->nTeam_ID) continue;
	////////		if (!IS_MINION(allyMinion)) continue;
	////////		if (!IsCanSee(allyMinion))  continue;
	////////		if (Distance(allyMinion, hero) > 1000) continue;
	////////		if (!CheckName(sz__Minion, allyMinion->GetNameNpc())) continue;

	////////		ProjectionInfo projection = ProjectOn(allyMinion->currentPos(), StartPos, End_Extend);
	////////		if (projection.IsOnSegment && projection.SegmentPoint.Distance2D(allyMinion->currentPos()) <= spellData.radius + 95)
	////////		{
	////////			//__oMsg("---((*VAO-VAO-VAO-MINION----)");
	////////			spellData.range     = 1375;
	////////			spellData.waitExtra	= 275;
	////////			break;
	////////		}
	////////	}
	////////}

	//////////__oMsg("---((*11*))----- SionEEE-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);
	////////for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////{
	////////	it_2->second.KoUpCurrentPos = true;
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Sion_E_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("SionEMissile") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
	////////	
	////////	if (start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
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
	////////					//__oMsg("	  ---------(SI-ON-E.mis)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			//__oMsg("---((*22*))----- SION_E_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellData.spellName.c_str(), start.Distance2D(end), spellData.spellDelay);
	////////			spellData.lastCreateMissileTime = (float)GetTickCount();

	////////			CreateSpellData(hero, start, end, spellData, 0, 0);
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Soraka_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("SorakaQ") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:

	////////Vec3D StartPos(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////float KC = Distance(StartPos, EndPos);
	////////spellData.spellDelay = 200 +  KC + 25;

	////////if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////{
	////////	//__oMsg("---((*11*))----- SorakaQ_CREATE_OPS-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////	CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);
	////////	for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	{
	////////		it_2->second.KoUpCurrentPos = true;
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Soraka_Q_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("SorakaQMissile") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	if (start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
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
	////////					//__oMsg("	  ---------(So-ra-ka-Q.mis)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		float KC = Distance(start, end);
	////////		spellData.spellDelay = 0 +  KC - 225;

	////////		float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			//__oMsg("---((*22*))----- SorakaQ_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellData.spellName.c_str(), start.Distance2D(end), spellData.spellDelay);
	////////			spellData.lastCreateMissileTime = (float)GetTickCount();

	////////			CreateSpellData(hero, start, end, spellData, 0, 0);
	////////		}
	////////	}
	////////}
}