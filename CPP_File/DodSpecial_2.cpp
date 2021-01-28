#include "DodSpecial_2.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;

extern  DWORD				G_Module;
extern  int					myTeamId;
extern  KNpc*				MY_HERO;

extern bool hasLulu, hasZed, hasZoe, hasVarus, hasPantheon, hasXerath, hasTwistedFate, hasKhazix, hasRiven, hasSyndra, hasViktor, hasOrianna, hasZiggs;
extern bool hasVelkoz, hasGraves, hasSoraka, hasSion, hasJanna, hasIrelia, hasKarma, hasJayce, hasRumble;

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Lulu_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))
	{
		char szTemp[] = {76,117,108,117,81,77,105,115,115,105,108,101,0};	// "LuluQMissile"
		if ( !CheckName(szTemp, MIS_NAME) ) return;							// "LuluQMissile" va "LuluQMissileTwo"
		
		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOW.FOW_Lulu_Q(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Zed_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))
	{
		char szTemp[] = {90,101,100,81,77,105,115,115,105,108,101,0};				// "ZedQMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;		 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOW.FOW_Zed_Q(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Pantheon_R(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))
	{
		char szTemp[] = {80,97,110,116,104,101,111,110,82,77,105,115,115,105,108,101,51,0};		// "PantheonRMissile3"	 
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < 6000)
		{
			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Pantheon_R(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			spellData.range = Distance(Start, End) + 600;
			spellData.spellDelay = 1800.0f;
			CreateSpellData(enemyHero, Start, End, spellData, 0, 0);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_TwistedFate_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))
	{
		char szTemp[] = {83,101,97,108,70,97,116,101,77,105,115,115,105,108,101,0};	// "SealFateMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return; 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW_TwistedFate_Q(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Khazix_W(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))
	{
		char szTemp[] = {75,104,97,122,105,120,87,77,105,115,115,105,108,101,0};	// "KhazixWMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return; 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW_Khazix_W(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Riven_R(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))
	{
		//co 3 ten : RivenWindslashMissileCenter, RivenWindslashMissileLeft, RivenWindslashMissileRight

		char szTemp[] = {82,105,118,101,110,87,105,110,100,115,108,97,115,104,77,105,115,115,105,108,101,0};	// "RivenWindslashMissile"
		if ( !CheckName(szTemp, MIS_NAME) ) return;	 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW_Riven_R(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Ziggs_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)		//FOW
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))		//co 3 ten : ZiggsQSpell, ZiggsQSpell2, ZiggsQSpell3, nhung chi can dung` ZiggsQSpell thoi
	{
		char szTemp[] = {90,105,103,103,115,81,83,112,101,108,108,0};	// "ZiggsQSpell"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;	 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 
		
		spellData.range = 850;
		
		if (Distance(MY_HERO, End) < spellData.range + 1000)
		{
			Vec3D dir = (End - Start).Normalized();
			if (End.Distance2D(Start) > 850)
			{
				End = Start + dir * 850;
			}

			CreateSpellData(enemyHero, Start, End, spellData, objectMis, 0, false);

			float exEntick = 575;
			Vec3D endPos2 = End + dir * 0.4f * Start.Distance2D(End);
			spellData.range = Start.Distance2D(endPos2); 
			CreateSpellData(enemyHero, Start, endPos2, spellData, objectMis, exEntick, false);

			exEntick = 950;
			Vec3D endPos3 = endPos2 + dir * 0.6f * End.Distance2D(endPos2);
			spellData.range = Start.Distance2D(endPos3);
			//__oMsg("---((*222*))----- DodS_NooFOW_Ziggs_Q-22222: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			//CreateSpellData(enemyHero, Start, endPos3, spellData, objectMis, exEntick);
			CreateSpellData(enemyHero, Start, endPos3, spellData, objectMis, exEntick, true, None, true, 240);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Graves_Q2(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)		//FOW
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))		
	{
		char szTemp[] = {71,114,97,118,101,115,81,76,105,110,101,77,105,115,0};	// "GravesQLineMis"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;

		SpellData spellData_xxx = spellData;

		Vec3D StartPos(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D EndPos  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Distance(MY_HERO, EndPos) < spellData_xxx.range + 1000)
		{
			//__oMsg("---((*111*))----- DodS_FOWFOW_Graves_Q2_BTHUONG: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, false);

			EndPos = StartPos + (EndPos - StartPos).Normalized() * spellData_xxx.range;

			float spellDelay3 = 1000 + 250 + 1000 * Distance(StartPos, EndPos) / 3000;	//ghi 2s, nhung chi 1.25 + 0.25(timeCast) la dan quay ve

			spellData_xxx.spellDelay	  = spellDelay3 - 250;
			spellData_xxx.range			  = Distance(StartPos, EndPos) + 50;
			spellData_xxx.projectileSpeed = 1600;
			//__oMsg("---((*222*))----- DodS_FOWFOW_Graves_Q2_BACK: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
			CreateSpellData(enemyHero, EndPos, StartPos, spellData_xxx, 0, 0, false, None, true, 90);

			//---- Line-1:(vuongGoc)
			spellData_xxx.spellDelay	  = spellDelay3;
			spellData_xxx.isPerpendicular = true;
			spellData_xxx.secondaryRadius = 300;
			spellData_xxx.updatePosition  = false;
			spellData_xxx.projectileSpeed = FLT_MAX;
			spellData_xxx.waitExtra       = 0;
			spellData_xxx.extraEndTime    = 100;

			//__oMsg("---((*333*))----- DodS_FOWFOW_Graves_Q2_NGANG: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, 0, 0, true, None, true, 170);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Soraka_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)		//FOW
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))		
	{
		char szTemp[] = {83,111,114,97,107,97,81,77,105,115,115,105,108,101,0};	// "SorakaQMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;

		SpellData spellData_xxx = spellData;

		Vec3D StartPos(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D EndPos  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Distance(MY_HERO, EndPos) < spellData_xxx.range + 1000)
		{
			float khoangCach = Distance(objectMis->currentPos(), EndPos);;
			int	  delay		 = (int)khoangCach/100;
			//__oMsg("kc : %f, delay: %d -> %d", khoangCach, 100*delay, 100*delay + 200);

			spellData_xxx.spellDelay = (float)delay * 100 + 50;

			//__oMsg("---((*111*))----- DodS_FOWFOW_Soraka_Q: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, 0, 0);	//0 vi co tinh ca delay
		}
	}
}


//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Sion_E(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)		//FOW
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))		
	{
		char szTemp[] = {83,105,111,110,69,77,105,115,115,105,108,101,0};	// "SionEMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;

		SpellData spellData_xxx = spellData;

		Vec3D StartPos(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D EndPos  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Distance(MY_HERO, StartPos) < spellData_xxx.range + 1000)
		{
			//__oMsg("---((*111*))----- DodS_FOWFOW_Sion_E: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0);

			//----- KO CAN LAM xxx
			//////Vec3D End_Extend = Extend(StartPos, EndPos, spellData.range + 50);

			//////DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
			//////DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			//////DWORD dw1x = *(DWORD*)tempUnit;
			//////DWORD dw2x = *(DWORD*)tempUnitMax;
			//////if (dw1x && dw2x )
			//////{
			//////	int nCount = (dw2x - dw1x)/4;
			//////	for (int kkk = 0; kkk < nCount; ++kkk)
			//////	{
			//////		DWORD dw3 = *(DWORD*)(dw1x + 4*kkk);
			//////		if (dw3 == 0) continue;
			//////		KNpc *allyMinion = (KNpc*)dw3;

			//////		if (!IS_MINION(allyMinion))							continue;
			//////		if (IS_DEAD(allyMinion))							continue;
			//////		if (allyMinion->nTeam_ID != myTeamId)				continue;

			//////		if (Distance(allyMinion, MY_HERO) > 1500)			continue;

			//////		char sz_Temp[] = {77, 105, 110, 105, 111, 110, 0};	// "Minion"
			//////		if (!CheckName(sz_Temp, allyMinion->GetNameNpc()))	continue;

			//////		ProjectionInfo projection = ProjectOn(allyMinion->currentPos(), StartPos, End_Extend);
			//////		if (projection.IsOnSegment && projection.SegmentPoint.Distance2D(allyMinion->currentPos()) <= spellData.radius + 95)
			//////		{
			//////			spellData.range     = 1400;
			//////			spellData.waitExtra	= 275;
			//////			break;
			//////		}
			//////	}
			//////}
			//////__oMsg("---((*111*))----- DodS_FOWFOW_Sion_E: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
			//////CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Karma_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)		//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))		
	{
		Vec3D StartPos(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D EndPos  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 
		
		char szTemp1[] = {75,97,114,109,97,81,77,105,115,115,105,108,101,0};	// "KarmaQMissile"
		if ( CheckNameEx(szTemp1, MIS_NAME) )
		{
			SpellData spellData_xxx = spellData;

			if (Distance(MY_HERO, StartPos) < spellData_xxx.range + 1000)
			{
				//__oMsg("---((*111*))----- DodS_FOWFOW_Karma_Q_BTHUONG: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0);
				return;
			}
		}
		
		char szTemp2[] = {75,97,114,109,97,81,77,105,115,115,105,108,101,77,97,110,116,114,97,0};	// "KarmaQMissileMantra"
		if ( CheckNameEx(szTemp2, MIS_NAME) )
		{
			SpellData spellData_xxx = spellData;

			if (Distance(MY_HERO, StartPos) < spellData_xxx.range + 1000)
			{
				//__oMsg("---((*3333*))----- DodS_FOWFOW_Karma_Q_22.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, false, None, false, 80);

				EndPos = Extend(StartPos, EndPos, spellData_xxx.range);
				//__oMsg("---((*4444*))----- DodS_FOWFOW_Karma_Q_22.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, 0, 1650, true, Circular, false, 300);
			}
		}
	}
}


//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW_Jayce_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)		//FOW 
{
	if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero && !IS_DEAD(enemyHero) && !IsCanSee(enemyHero))		
	{
		Vec3D StartPos(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D EndPosTemp  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 
		Vec3D EndPos = Extend(StartPos, EndPosTemp, spellData.range);

		char szTemp1[] = {74,97,121,99,101,83,104,111,99,107,66,108,97,115,116,77,105,115,0};	// "JayceShockBlastMis"
		if ( CheckNameEx(szTemp1, MIS_NAME) )
		{
			SpellData spellData_xxx = spellData;

			if (Distance(MY_HERO, StartPos) < spellData_xxx.range + 1000)
			{
				//__oMsg("---((*0000*))----- DodS_FOWFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, false);

				//__oMsg("---((*0000*))----- DodS_FOWFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, true, Circular, false, 165);
				return;
			}
		}

		char szTemp2[] = {74,97,121,99,101,83,104,111,99,107,66,108,97,115,116,87,97,108,108,77,105,115,0};	// "JayceShockBlastWallMis"
		if ( CheckNameEx(szTemp2, MIS_NAME) )
		{
			SpellData spellData_xxx = spellData;
			//float deltaDelay = Distance(pointI, StartPos)/1450 - Distance(pointI, StartPos)/2350;
			//spellData.spellDelay += 1000*deltaDelay - 20;
			spellData_xxx.projectileSpeed = 2350;
			spellData_xxx.range			  = 1600;
			EndPos = Extend(StartPos, EndPosTemp, spellData_xxx.range);

			if (Distance(MY_HERO, StartPos) < spellData_xxx.range + 1000)
			{
				Vec3D unitPosSeg = GetCollisionAllyPos(StartPos, EndPos, spellData_xxx.range, spellData_xxx.radius, 20, -46);
				if (unitPosSeg.IsValid())
				{
					//__oMsg("---((*1111*))----- DodS_FOWFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
					CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, false);

					//__oMsg("---((*1111*))----- DodS_FOWFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
					CreateSpellData(enemyHero, StartPos, unitPosSeg, spellData_xxx, objectMis, 0, true, Circular, false, 275);
					return;
				}

				//__oMsg("---((*2222*))----- DodS_FOWFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, false);

				//__oMsg("---((*2222*))----- DodS_FOWFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", MIS_NAME, spellData_xxx.spellName.c_str(), StartPos.Distance2D(EndPos), spellData_xxx.spellDelay, spellData_xxx.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData_xxx, objectMis, 0, true, Circular, false, 275);
			}
		}
	}
}



//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Zoe_Q2(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero))
	{
		char szTemp[] = {90,111,101,81,77,105,115,50,0};	// "ZoeQMis2"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;		 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1500)
		{
			spellData.range = Distance(Start, End) + 50;
			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Zoe_Q2(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Varus_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	//////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero))
	{
		char szTemp[] = {86,97,114,117,115,81,77,105,115,115,105,108,101,0};		// "VarusQMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return; 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Varus_Q(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			spellData.range = 85.0f + Distance_2D(objectMis->MissileSrcPos, objectMis->MissileDestPos);		//range thay doi theo tgian
			CreateSpellData(enemyHero, Start, End, spellData, objectMis);	
		}
	}
}


//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Xerath_R(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	//////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero && !IS_DEAD(enemyHero))
	{
		char szTemp[] = {88,101,114,97,116,104,76,111,99,117,115,80,117,108,115,101,0};		// "XerathLocusPulse"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;	 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Xerath_R(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, 0, 0);	// 0 vi dung delay=600
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Syndra_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	//////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero && !IS_DEAD(enemyHero))
	{
		char szTemp[] = {83,121,110,100,114,97,81,83,112,101,108,108,0};		// "SyndraQSpell"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;	 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			extern sphereQE* _xin1SlotQESyndra;
			if (_xin1SlotQESyndra && !_xin1SlotQESyndra->posQE.IsValid())
			{
				_xin1SlotQESyndra->posQE	 = End;
				_xin1SlotQESyndra->timeSpawn = GetTimeGame();
				//__oMsg("CHO 1SLOT ROI NHA: %f, %f [%f, %f]", objectMis->currentPos().x, objectMis->currentPos().z, End.x, End.z);
			}

			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Syndra_Q(): MISS_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, 0, 0);			// 0 vi dung delay=650
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Viktor_E12(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	//////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )
	{
		char szTemp1[] = {86,105,107,116,111,114,68,101,97,116,104,82,97,121,77,105,115,115,105,108,101,0};		// "ViktorDeathRayMissile"
		if ( CheckNameEx(szTemp1, MIS_NAME) ) 
		{
			Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
			Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

			if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
			{
				//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Viktor_E1_BTHUONG(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f", MIS_NAME, spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
				CreateSpellData(enemyHero, Start, End, spellData, objectMis, 0);			
			}
		}

		char szTemp2[] = {86,105,107,116,111,114,69,65,117,103,77,105,115,115,105,108,101,0};		// "ViktorEAugMissile"
		if ( CheckNameEx(szTemp2, MIS_NAME) ) 
		{
			Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
			Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

			if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
			{
				CreateSpellData(enemyHero, Start, End, spellData, objectMis, 0, false);
					
				//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Viktor_E2(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f", MIS_NAME, spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
				CreateSpellData(enemyHero, Start, End, spellData, 0);				// 0 vi dung delay=950	
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Oriana_Q(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	//////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )
	{
		char szTemp[] = {79,114,105,97,110,97,73,122,117,110,97,0};		// "OrianaIzuna"
		if ( CheckNameEx(szTemp, MIS_NAME) ) 
		{
			Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
			Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

			if (Start.Distance2D(MY_HERO->currentPos()) < 2200)
			{
				spellData.range = Start.Distance2D(End) + 0;

				//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Oriana_Q(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f", MIS_NAME, spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
				CreateSpellData(enemyHero, Start, End, spellData, objectMis, 0);			
			}
		}

	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Oriana_E(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	//////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )
	{
		char szTemp[] = {79,114,105,97,110,97,82,101,100,97,99,116,0};		// "OrianaRedact"
		if ( CheckNameEx(szTemp, MIS_NAME) ) 
		{
			Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
			Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

			if (Start.Distance2D(MY_HERO->currentPos()) < 2000)
			{
				spellData.range = Start.Distance2D(End) + 0;

				//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Oriana_E(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f", MIS_NAME, spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
				CreateSpellData(enemyHero, Start, End, spellData, objectMis, 0);			
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Velkoz_W(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )
	{
		char szTemp[] = {86,101,108,107,111,122,87,77,105,115,115,105,108,101,0};	// "VelkozWMissile"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;		 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Velkoz_W(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f", MIS_NAME, spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, 0, 0);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Velkoz_Q2(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )
	{
		char szTemp[] = {86,101,108,107,111,122,81,77,105,115,115,105,108,101,83,112,108,105,116,0};	// "VelkozQMissileSplit"
		if ( !CheckNameEx(szTemp, MIS_NAME) ) return;		 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Velkoz_Q2(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f", MIS_NAME, spellData.missileName.c_str(), Start.Distance2D(End), spellData.spellDelay);
			CreateSpellData(enemyHero, Start, End, spellData, 0, 0);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Janna_Q (KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )		// "HowlingGaleSpell", "HowlingGaleSpell1" ---> "HowlingGaleSpell16"
	{
		char szTemp[] = {72,111,119,108,105,110,103,71,97,108,101,83,112,101,108,108,0};	// "HowlingGaleSpell"
		if ( !CheckName(szTemp, MIS_NAME) ) return;		 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			SpellData spellData_Qxx = spellData;
			
			spellData_Qxx.range = Start.Distance2D(End) + 50;
			spellData_Qxx.projectileSpeed = spellData_Qxx.range / 1.5f;

			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Janna_Q(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f - %f", MIS_NAME, spellData_Qxx.missileName.c_str(), Start.Distance2D(End), spellData_Qxx.spellDelay, spellData_Qxx.projectileSpeed);
			CreateSpellData(enemyHero, Start, End, spellData_Qxx, objectMis, 0);	
		}
	}
}

//--------------------//----------------------------------//--------------------//
Vec3D lastIreliaBlade_1(0,0,0);
void DodS_FOWFOW__AND__NOFOW_Irelia_E (KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )		
	{
		char szTemp[] = {73,114,101,108,105,97,69,77,105,115,115,105,108,101,0};	// "IreliaEMissile"
		if ( CheckNameEx(szTemp, MIS_NAME) ) 
		{
			if (!lastIreliaBlade_1.IsValid())
			{
				Vec3D v11   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 
				lastIreliaBlade_1 = v11;
				return;
			}
			else
			{
				SpellData spellData_Ex = spellData;
				if (lastIreliaBlade_1.Distance2D(MY_HERO->currentPos()) < spellData_Ex.range + 1000)
				{
					Vec3D Start = lastIreliaBlade_1;
					Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

					spellData_Ex.range		= Start.Distance2D(End) + 50;
					spellData_Ex.spellDelay = 325 + 1000*Distance(enemyHero, End)/2000;

					//__oMsg("TH__1 : DISTANT 1: %f, 2: %f, delay: %f", Distance(enemyHero, End), Distance(Start, End), spellData_Ex.spellDelay);
					//__oMsg("TH__1 : ---[222]-DodS_FOWFOW__AND__NOFOW_Irelia_E_2KIEM(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f - %f", MIS_NAME, spellData_Ex.missileName.c_str(), Start.Distance2D(End), spellData_Ex.spellDelay, spellData_Ex.projectileSpeed);

					CreateSpellData(enemyHero, Start, End, spellData_Ex, 0, 0, false);		//0 vi co delay kha 
					CreateSpellData(enemyHero, End, Start, spellData_Ex, 0, 0);				//0 vi co delay kha cao
					Vec3D zezo(0,0,0);
					lastIreliaBlade_1 = zezo;
					return;
				}
			}
		}

		char szTemp22[] = {73,114,101,108,105,97,69,80,97,114,116,105,99,108,101,77,105,115,115,105,108,101,0};	// "IreliaEParticleMissile"
		if ( CheckNameEx(szTemp22, MIS_NAME) ) 
		{
			Vec3D Start = lastIreliaBlade_1;
			Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 
			
			////if (lastIreliaBlade_1.IsValid()) __oMsg("TH_2 : DISTANT xxxx: %f", Distance(Start, End));

			if (lastIreliaBlade_1.IsValid() && Distance(Start, End) > 90 )
			{
				SpellData spellData_Ex = spellData;
				if (lastIreliaBlade_1.Distance2D(MY_HERO->currentPos()) < spellData_Ex.range + 1000)
				{
					spellData_Ex.range		= Start.Distance2D(End) + 50;
					spellData_Ex.spellDelay = 350 ;

					//__oMsg("TH__2 : DISTANT 1: %f, 2: %f, delay: %f", Distance(enemyHero, End), Distance(Start, End), spellData_Ex.spellDelay);
					//__oMsg("TH__2 : ---[11111]-DodS_FOWFOW__AND__NOFOW_Irelia_E_11KIEM(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f - %f", MIS_NAME, spellData_Ex.missileName.c_str(), Start.Distance2D(End), spellData_Ex.spellDelay, spellData_Ex.projectileSpeed);

					CreateSpellData(enemyHero, Start, End, spellData_Ex, 0, 0, false);		//0 vi co delay kha 
					CreateSpellData(enemyHero, End, Start, spellData_Ex, 0, 0);				//0 vi co delay kha cao
					Vec3D zezo(0,0,0);
					lastIreliaBlade_1 = zezo;
					return;
				}
			}
		}

		char szTemp33[] = {73,114,101,108,105,97,69,83,101,99,111,110,100,97,114,121,0};	// "IreliaESecondary"
		if ( lastIreliaBlade_1.IsValid() && CheckNameEx(szTemp33, MIS_NAME) ) 
		{
			Vec3D zezo(0,0,0);
			lastIreliaBlade_1 = zezo;
			//__oMsg("TH__3 : SETTTT = 0000000000000000000");	// it khi vao lam
		}
	}
}	

//--------------------//----------------------------------//--------------------//
void DodS_FOWFOW__AND__NOFOW_Rumble_R (KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	//FOW + NO_FOW
{
	////if (DodgeFOWSpells_menu == false)		 return;

	KNpc* enemyHero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);

	if (enemyHero /*&& !IS_DEAD(enemyHero)*/ )		
	{
		char szTemp[] = {82,117,109,98,108,101,67,97,114,112,101,116,66,111,109,98,77,105,115,115,105,108,101,0};	// "RumbleCarpetBombMissile"
		if ( !CheckName(szTemp, MIS_NAME) ) return;		 

		Vec3D Start (objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z );
		Vec3D End   (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z); 

		if (Start.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
		{
			SpellData spellData_Qxx = spellData;

			//__oMsg("---[00]-DodS_FOWFOW__AND__NOFOW_Rumble_R(): MISS_NAME: [%s] %s, KC.Start.End = %.3f - delay: %f - %f", MIS_NAME, spellData_Qxx.missileName.c_str(), Start.Distance2D(End), spellData_Qxx.spellDelay, spellData_Qxx.projectileSpeed);
			CreateSpellData(enemyHero, Start, End, spellData_Qxx, 0, 0);	
		}
	}
}



//--------------------//----------------------------------//--------------------//
//--------------------//----------------------------------//--------------------//
void Dodge_Special_2222(KNpc* objectMis, SpellData &spellData, char* MIS_NAME)	// dung voi missile va` khi isSpecial_22x = true
{
	if (!MY_HERO || !myTeamId || !G_Module)	 return;

	//---- Lulu.Q :
	if (hasLulu)			DodS_FOWFOW_Lulu_Q(objectMis, spellData, MIS_NAME);					//FOW 

	//---- Zed.Q :
	if (hasZed)				DodS_FOWFOW_Zed_Q(objectMis, spellData, MIS_NAME);					//FOW 

	//---- Pantheon.Q :
	if (hasPantheon)		DodS_FOWFOW_Pantheon_R(objectMis, spellData, MIS_NAME);				//FOW 

	//---- TwistedFate.Q :
	if (hasTwistedFate)		DodS_FOWFOW_TwistedFate_Q(objectMis, spellData, MIS_NAME);			//FOW 
	
	//---- Khazix.W :
	if (hasKhazix)			DodS_FOWFOW_Khazix_W(objectMis, spellData, MIS_NAME);				//FOW 
	
	//---- Riven.R :
	if (hasRiven)			DodS_FOWFOW_Riven_R(objectMis, spellData, MIS_NAME);				//FOW 

	//---- Ziggs.Q :
	if (hasZiggs)			DodS_FOWFOW_Ziggs_Q(objectMis, spellData, MIS_NAME);				//FOW 
	
	//---- Graves.Q2 :
	if (hasGraves)			DodS_FOWFOW_Graves_Q2(objectMis, spellData, MIS_NAME);				//FOW 
	
	//---- Soraka.Q :
	if (hasSoraka)			DodS_FOWFOW_Soraka_Q(objectMis, spellData, MIS_NAME);				//FOW 
	
	//---- Sion:
	if (hasSion)			DodS_FOWFOW_Sion_E(objectMis, spellData, MIS_NAME);					//FOW 

	//---- Karma:
	if (hasKarma)			DodS_FOWFOW_Karma_Q(objectMis, spellData, MIS_NAME);				//FOW 

	//---- Jayce:
	if (hasJayce)			DodS_FOWFOW_Jayce_Q(objectMis, spellData, MIS_NAME);				//FOW



	//---- Zoe.Q2 :
	if (hasZoe)				DodS_FOWFOW__AND__NOFOW_Zoe_Q2(objectMis, spellData, MIS_NAME);		//FOW + NO_FOW

	//---- Varus.Q :
	if (hasVarus)			DodS_FOWFOW__AND__NOFOW_Varus_Q(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW

	//---- Xerath.R :
	if (hasXerath)			DodS_FOWFOW__AND__NOFOW_Xerath_R(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW

	//---- Syndra.Q :
	if (hasSyndra)			DodS_FOWFOW__AND__NOFOW_Syndra_Q(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW

	//---- Viktor.E :
	if (hasViktor)			DodS_FOWFOW__AND__NOFOW_Viktor_E12(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW

	//---- Orianna.Q.E :
	if (hasOrianna)			
	{
							DodS_FOWFOW__AND__NOFOW_Oriana_Q(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW
							DodS_FOWFOW__AND__NOFOW_Oriana_E(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW
	}

	//---- Velkoz.W :
	if (hasVelkoz)			
	{	
							DodS_FOWFOW__AND__NOFOW_Velkoz_W(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW
							DodS_FOWFOW__AND__NOFOW_Velkoz_Q2(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW
	}
		
	//---- Janna.Q :
	if (hasJanna)			DodS_FOWFOW__AND__NOFOW_Janna_Q(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW)

	//---- Irelia.E :
	if (hasIrelia)			DodS_FOWFOW__AND__NOFOW_Irelia_E(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW)

	//---- Rumble.R :
	if (hasRumble)			DodS_FOWFOW__AND__NOFOW_Rumble_R(objectMis, spellData, MIS_NAME);	//FOW + NO_FOW)
}