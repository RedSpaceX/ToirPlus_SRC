#include "DodgeZacS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
DWORD _zacObject[2] = {0};
void Evade_Zac_E_va_R()
{	
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	if (G_Module == 0) return;

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
		if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
		if (Distance(enemyHero, myHero) > 2500) return;
		if (!CheckName(enemyHero->GetNameHero(), "Zac")) continue;
		if (!IsDashing(enemyHero)) continue;

		//------//------//------:
		_zacObject[0] = 0;
		_zacObject[1] = 0;

		//------//------//------:
		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
		DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
		if (!dw0) return;

		DWORD dw1 = *(DWORD*)(dw0 + 8);
		if (!dw1) return;

		int nCount = *(DWORD*)(dw0 + 0xC);
		if (!nCount) return;

		for (int kk = 0; kk < nCount; ++kk)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
			if (dw3 == 0) continue;
			KNpc *missileObj = (KNpc*)dw3;

			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
			if (OBJECT_TYPE(missileObj) != 1) continue;

			if (_zacObject[0] == 0 && CheckName("Zac_", missileObj->GetNameNpc()) && CheckName("_E_Moving", missileObj->GetNameNpc()))	//"Zac_Base_E_Moving" : chi E co thoi
			{
				_zacObject[0] = (DWORD)missileObj;
				continue;
			}
			if (_zacObject[1] == 0 && CheckName("Zac_", missileObj->GetNameNpc()) && CheckName("E_LandPositionIndicator", missileObj->GetNameNpc()))	//"Zac_Base_E_LandPositionIndicator"	: R va E deu co
			{
				_zacObject[1] = (DWORD)missileObj;
				continue;
			}
			if (_zacObject[0] != 0 && _zacObject[1] != 0) break;
		}

		//------//------//------:
		KNpc* zac_00 = (KNpc*)_zacObject[0];
		KNpc* zac_11 = (KNpc*)_zacObject[1];
		
		
		if (zac_00 != 0 && zac_11 != 0)		//---- E:
		{
			std::string spellSpecial("ZacE_Special");
			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
			{
				SpellData spellData = it_onProcessSpells->second;
				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
				{
					Vec3D Start = enemyHero->currentPos();
					Vec3D End   = zac_11->currentPos();
					spellData.range = Start.Distance2D(End);
					spellData.projectileSpeed = 600 + 100* spellData.range/210;
					//__oMsg("E-2: %f - %f", spellData.range, spellData.projectileSpeed);
					if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
					{
						//__oMsg("---((*11.2*))----- Zac_EE_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), Start.Distance2D(End), spellData.spellDelay);
						CreateSpellData(enemyHero, Start, End, spellData, 0, 0);
						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
					}		
				}
			}
		}
		
		//------//------:
		if (zac_00 == 0 && zac_11 != 0)		//---- R:
		{
			std::string spellSpecial("ZacR_Special");
			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
			{
				SpellData spellData = it_onProcessSpells->second;
				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
				{
					Vec3D Start = enemyHero->currentPos();
					Vec3D End   = zac_11->currentPos();
					spellData.range = Start.Distance2D(End);
					if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
					{
						//__oMsg("---((*11.2*))----- Zac_RR_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), Start.Distance2D(End), spellData.spellDelay);
						CreateSpellData(enemyHero, Start, End, spellData, 0, 0);
						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
					}		
				}
			}
		}
	}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Yorick_E_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("YorickE") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////Vec3D start(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////Vec3D end(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	////////Vec3D direction = (end - start).Normalized();

	////////if (start.Distance2D(end) > spellData.range)
	////////	end = start + (end - start).Normalized() * spellData.range;

	////////Vec3D spellStart = Extend(end, hero->currentPos(), 100);
	////////Vec3D spellEnd   = spellStart + direction * 500;
	////////
	////////spellData.range = 550;
	////////spellData.spellDelay += 1000 * Distance(end, start)/1800;		//
	//////////__oMsg("---((*11.1*))----- YorickE_CREATE-OPS-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), spellStart.Distance2D(spellEnd), spellData.spellDelay);
	////////CreateSpellData(hero, spellStart, spellEnd, spellData);
}

////---------------------------------------------------------------------//--------------------//
//DWORD _yorickObject[2] = {0};
//void Evade_Yorick_E()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Yorick")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500) continue;
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("YorickE") != 0) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::string spellSpecial("YorickE_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D end  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//					Vec3D start(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z); 
//					Vec3D direction = (end - start).Normalized();
//
//					if (start.Distance2D(end) > spellData.range)
//						end = start + (end - start).Normalized() * spellData.range;
//
//					Vec3D spellStart = Extend(end, enemyHero->currentPos(), 100);
//					Vec3D spellEnd   = spellStart + direction * 500;
//					
//					spellData.range = 550;
//					spellData.spellDelay += 1000 * Distance(end, start)/1800;		//
//					//__oMsg("---((*11.1*))----- YorickE_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), spellStart.Distance2D(spellEnd), spellData.spellDelay);
//					CreateSpellData(enemyHero, spellStart, spellEnd, spellData);
//
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}
//			}
//		}
//		else
//		{
//			return;		//E-FOW kho ne', phai tim duoc srcPos tu` Yorick_Base_E_Indicator2, chu' srcPos tu YorickEMissile qua' nhanh
//
//			//////return....
//
//			//if (DodgeFOWSpells_menu == false) return;
//
//			//_yorickObject[0] = 0;
//			//_yorickObject[1] = 0;
//			////------//------//------:
//			//DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			//DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			//DWORD dw1 = *(DWORD*)dw0;
//			//if (!dw1) return;
//
//			//int countAllObj = *(DWORD*)(dw0 + 4);
//			//if (!countAllObj) return;
//
//			//for (int kk = 0; kk < countAllObj; ++kk)
//			//{
//			//	DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			//	if (dw3 == 0) continue;
//			//	KNpc *missileObj = (KNpc*)dw3;
//
//			//	if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			//	if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//			//	if (OBJECT_TYPE(missileObj) != 1 && OBJECT_TYPE(missileObj) != 0x8001) continue;
//			//	//if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//			//	if (CheckName("E_Indicator", missileObj->GetNameNpc()) && CheckName("Yorick", missileObj->GetNameNpc()))
//			//	{
//			//		_yorickObject[0] = (DWORD)missileObj;
//			//		continue;
//			//	}
//			//	if (missileObj->nTeam_ID == enemyHero->nTeam_ID && CheckName("YorickEMissile", missileObj->GetNameNpc()))
//			//	{
//			//		_yorickObject[1] = (DWORD)missileObj;
//			//		continue;
//			//	}
//			//	if (_yorickObject[0] && _yorickObject[1]) break;
//
//			//}
//	
//			////------//------//------:
//			//KNpc* yr_00 = (KNpc*)_yorickObject[0];
//			//KNpc* yr_11 = (KNpc*)_yorickObject[1];
//			//if (yr_00 && yr_11 && Distance(yr_00, yr_11) > 6)
//			//{
//			//	std::string spellSpecial("YorickE_Special");
//			//	std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			//	if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			//	{
//			//		SpellData spellData = it_onProcessSpells->second;
//			//		float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//			//		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//			//		{
//			//			Vec3D end   (yr_11->MissileDestPos.x, yr_11->MissileDestPos.y, yr_11->MissileDestPos.z);
//			//			Vec3D start (yr_11->MissileSrcPos.x, yr_11->MissileSrcPos.y, yr_11->MissileSrcPos.z);	//missile
//
//			//			//Vec3D end   = yr_00->currentPos();		//Yorick_Base_E_Indicator2
//			//			//Vec3D start = yr_11->currentPos();	//missile
//
//			//			Vec3D direction = (end - start).Normalized();
//
//			//			if (start.Distance2D(end) > spellData.range)
//			//				end = start + (end - start).Normalized() * spellData.range;
//
//			//			Vec3D spellStart = Extend(end, start, 100);
//			//			Vec3D spellEnd   = spellStart + direction * 500;
//
//			//			spellData.range = 550;
//			//			spellData.spellDelay = 1000 * Distance(end, yr_11->currentPos())/1800;		
//			//			//__oMsg("---((*222*))----- YorickE_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), spellStart.Distance2D(spellEnd), spellData.spellDelay);
//			//			CreateSpellData(enemyHero, spellStart, spellEnd, spellData);
//
//			//			it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//			//		}
//			//	}
//			//}
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
//void Evade_Yorick_W()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Yorick")) continue;
//
//		//------//------//------:
//		//if (DodgeFOWSpells_menu == false) return;
//
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
//			if (OBJECT_TYPE(missileObj) != 1) continue;
//			if (CheckName("_W_Warning", missileObj->GetNameNpc()) && CheckName("Yorick", missileObj->GetNameNpc()))
//			{
//				//------//------//------:
//				std::string spellSpecial("YorickW_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					SpellData spellData = it_onProcessSpells->second;
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 5500 + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						Vec3D end   = missileObj->currentPos();
//						Vec3D start = end + (end - enemyHero->currentPos()).Normalized() * spellData.range;
//
//						//__oMsg("---((*111*))----- YorickWW_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), start.Distance2D(end), spellData.spellDelay);
//						CreateSpellData(enemyHero, start, end, spellData);
//
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//					}
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Yasuo_Q12()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Yasuo")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2000) continue;
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("YasuoQ1") != 0 && spell_name.compare("YasuoQ2") != 0) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 1.5f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::string spellSpecial("YasuoQ12_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D end   = GET_REAL_FACING_POS(enemyHero);
//					Vec3D start = enemyHero->currentPos(); 
//					
//					if (start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						//__oMsg("---((*11.1*))----- Yasuo_Q12_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), start.Distance2D(end), spellData.spellDelay);
//						CreateSpellData(enemyHero, start, end, spellData);
//
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//					}
//				}
//			}
//		}
//	}
//}