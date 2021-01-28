#include "DodgeFioraS.h"
//#include "SpellSpecial.h"
#include "SpellDetector.h"
//
//
//extern SpellDetector* _SpellDetector;
////---------------------------------------------------------------------//--------------------//
//void Evade_Fiora_W()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Fiora")) continue;
//		if (Distance(enemyHero, myHero) > 1800) continue;
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
//			if (OBJECT_TYPE(missileObj) != 1)		 continue;
//
//			if (CheckName("Fiora", missileObj->GetNameNpc()) && CheckName("_W_Cas",missileObj->GetNameNpc()))
//			{
//				//__oMsg("--Fiora-YES-222: %f - %f", GetTimeGame(), Distance(enemyHero, GET_REAL_FACING_POS(enemyHero)));
//				 
//				std::string mis_Name("FioraW_Special");
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					//it_onMissileSpells->second.range = max_KC + 25;
//					SpellData spellData = it_onMissileSpells->second;
//
//					Vec3D StartPos = enemyHero->currentPos();
//					Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						//if (IsCanSee(enemyHero))	//xerath ko can cai nay
//						{
//							//--------------------------------:
//							if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//							float missileLifeTime = 1000 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Fiora-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//		}
//	}	
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Sylas_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("SylasQ") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////Vec3D StartPos(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////Vec3D EndPos(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////if (StartPos.Distance2D(EndPos) < 185)
	////////{
	////////	EndPos = Extend(StartPos, EndPos, 185);
	////////}
	////////Vec3D direction  = (EndPos - StartPos).Normalized();
	////////Vec3D pDirection = Perpendicular(direction);
	////////Vec3D targetPoint = StartPos;

	////////Vec3D pos1 = targetPoint - pDirection * 150;
	////////Vec3D pos2 = targetPoint + pDirection * 150;

	////////if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////{
	////////	//__oMsg("---((*11*))----- SylasQ-CREATE-OPS-11111: O-P-S: %s, KC_Missile = %.3f - delay: %f",spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////	CreateSpellData(hero, pos1, EndPos, spellData, 0, 0, false);
	////////	CreateSpellData(hero, pos2, EndPos, spellData, 0, 0);
	////////	
	////////	// ko can cai nay vi ko co missile
	////////	/*for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	{
	////////		it_2->second.KoUpCurrentPos = true;
	////////	}*/
	////////}
}