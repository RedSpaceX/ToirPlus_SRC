#include "DodSpecial_1.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"
#include "Position.h"
#include "EvadeHelper.h"

extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;

extern  DWORD				G_Module;
extern  int					myTeamId;
extern  KNpc*				MY_HERO;

extern bool hasLulu, hasZed, hasYasuo, hasTwistedFate, hasKhazix, hasRiven, hasPyke, hasSyndra, hasOrianna, hasSylas, hasYorick, hasZiggs, hasGraves;
extern bool hasSoraka, hasSion, hasAatrox, hasTahmKench, hasKarma, hasJayce;
//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_Lulu_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {76,117,108,117,81,0};					// "LuluQ"
	if ( !CheckNameEx(SPELL_NAME, szTemp) ) return;

	Vec3D Start(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	Vec3D End  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	//------//------//----------:
	bool hasLuluFaerie = false;

	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwUnit1 = *(DWORD*)tempUnit;
	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	if ( !dwUnit1 || !dwUnit2 ) return;

	int countUnit = (dwUnit2 - dwUnit1)/4;
	for ( int iii = 0; iii < countUnit; ++iii )
	{
		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
		if (dwUnit3 == 0) continue;
		KNpc *minion = (KNpc*)dwUnit3;

		if (!IS_MINION(minion))						continue;
		if (IS_DEAD(minion))						continue;

		if (minion->isJungle())						continue;
		if (minion->nTeam_ID == myTeamId)			continue;

		if ((BYTE)minion->nIsTargetableToTeam == 4) continue;
		if (Distance(minion, enemyHero) > 1500)		continue;
 
		char szTemp1[] = {82,111,98,111,116,66,117,100,100,121,0};			// "RobotBuddy"
		if (!CheckName(szTemp1, minion->GetNameNpc()))	continue;

		char szTemp2[] = {76,117,108,117,70,97,101,114,105,101,0};			// "LuluFaerie"
		if (!CheckName(szTemp2, minion->GetNameHero())) continue;

		hasLuluFaerie = true;

		//__oMsg("---[00]-DodS_NO_FOW_Lulu_Q(): SPELL_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
		CreateSpellData(enemyHero, Start, End, spellData, 0, 0, false);

		//__oMsg("---[11]-DodS_NO_FOW_Lulu_Q(): SPELL_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
		CreateSpellData(enemyHero, minion->currentPos(), End, spellData);
		return;
	}
	if (hasLuluFaerie == false)
	{
		//__oMsg("---[22]-DodS_NO_FOW_Lulu_Q(): SPELL_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
		CreateSpellData(enemyHero, Start, End, spellData);
	}
}

//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_Zed_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {90,101,100,81,0};						// "ZedQ"
	if ( !CheckNameEx(SPELL_NAME, szTemp) ) return;
	
	Vec3D Start(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	Vec3D End  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	//------//------//------:
	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwUnit1 = *(DWORD*)tempUnit;
	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	if (!dwUnit1 || !dwUnit2 ) return;

	int countUnit = (dwUnit2 - dwUnit1)/4;

	for (int iii = 0; iii < countUnit; ++iii)
	{
		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
		if (dwUnit3 == 0) continue;
		KNpc *minion = (KNpc*)dwUnit3;

		if (!IS_MINION(minion)) continue;
		if (IS_DEAD(minion))    continue;
		
		if (minion->isJungle())						continue;
		if (minion->nTeam_ID == myTeamId)			continue;

		if ((BYTE)minion->nIsTargetableToTeam == 4) continue;
		if (Distance(minion, MY_HERO) > 2000)		continue;
		
		char szTemp1[] = {83, 104, 97, 100, 111, 119, 0};					// "Shadow"
		if (!CheckName( szTemp1, minion->GetNameNpc()))	 continue;
		
		char szTemp2[] = {90, 101, 100, 83, 104, 97, 100, 111, 119, 0};		// "ZedShadow"
		if (!CheckName( szTemp2, minion->GetNameHero())) continue;

		//__oMsg("---[11]-DodS_NO_FOW_ZED_Q(): SPELL_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
		CreateSpellData(enemyHero, minion->currentPos(), End, spellData, 0, 0, false);
	}
	
	//__oMsg("---[22]-DodS_NO_FOW_ZED_Q(): SPELL_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
	CreateSpellData(enemyHero, Start, End, spellData);	
}

//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_Yasuo_Q12	(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp1[] = {89,97,115,117,111,81,49,0};			// "YasuoQ1"
	char szTemp2[] = {89,97,115,117,111,81,50,0};			// "YasuoQ2"

	if ( !CheckNameEx(SPELL_NAME, szTemp1) && 
		 !CheckNameEx(SPELL_NAME, szTemp2) )  return;

	Vec3D Start = enemyHero->currentPos();
	Vec3D End   = GET_REAL_FACING_POS(enemyHero);
	 
	//__oMsg("---[11]-DodS_NO_FOW_YASUO_Q12(): SPELL_NAME: %s, KC.Start.End = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
	CreateSpellData(enemyHero, Start, End, spellData);
}

//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_TwistedFate_Q	(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {87,105,108,100,67,97,114,100,115,0};		// "WildCards"		
	
	if ( !CheckNameEx(SPELL_NAME, szTemp) ) return;

	Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	if (Distance(MY_HERO, StartPos) < spellData.range + 1000)
	{
		//__oMsg("---((*11*))----- DodS_NooFOW_TwistedFate_Q-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

		CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

		float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));

		Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
		CreateSpellData(enemyHero, StartPos, EndPos2, spellData, 0, 0, false);

		Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
		CreateSpellData(enemyHero, StartPos, EndPos3, spellData, 0, 0);
	}
}

//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_Khazix_W (KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {75,104,97,122,105,120,87,0};	// "KhazixW"	
	if ( CheckNameEx(SPELL_NAME, szTemp) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, StartPos) < spellData.range + 1000)
		{
			//__oMsg("---((*11*))----- DodS_NooFOW_Khazix_W_BTHUONG-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
			return;
		}
	}

	char szTempLong[] = {75,104,97,122,105,120,87,76,111,110,103,0};	// "KhazixWLong"			
	if ( CheckNameEx(szTempLong, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, StartPos) < spellData.range + 1000)
		{
			//__oMsg("---((*22*))----- DodS_NooFOW_Khazix_W_LOONGG-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

			float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));

			Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
			CreateSpellData(enemyHero, StartPos, EndPos2, spellData, 0, 0, false);

			Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
			CreateSpellData(enemyHero, StartPos, EndPos3, spellData, 0, 0);
		}
	}
}

//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_Riven_R(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {82,105,118,101,110,73,122,117,110,97,66,108,97,100,101,0};	// "RivenIzunaBlade"			
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, StartPos) < spellData.range + 1000)
		{
			//__oMsg("---((*22*))----- DodS_NooFOW_Riven_R-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

			float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));

			Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
			CreateSpellData(enemyHero, StartPos, EndPos2, spellData, 0, 0, false);

			Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
			CreateSpellData(enemyHero, StartPos, EndPos3, spellData, 0, 0);
		}
	}
}

//--------------------//----------------------------------//--------------------//-------------------------//
void DodS_NooFOW_Pyke_E(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {80,121,107,101,69,0};		// "PykeE"			
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D TempSrcPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D TempEndPos(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, TempSrcPos) < spellData.range + 1200)
		{
			Vec3D StartPos = Extend(TempSrcPos, TempEndPos, -150.0f);
			Vec3D EndPos   = enemyHero->currentPos();

			//__oMsg("---((*22*))----- DodS_NooFOW_Pyke_E-11111: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
		}
	}
}

//--------------------//----------------------------------//--------------------//-------------------------//
Vec3D nexus1(1551.0f, 86.0f, 1659.0f);
Vec3D nexus2(13243.0f, 91.0f, 13235.0f);
void DodS_NooFOW_Pyke_R(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {80,121,107,101,82,0};	// "PykeR"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D tempSrcPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D tempEndPos(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, tempEndPos) < spellData.range + 1000)
		{
			ProjectionInfo pProj = ProjectOn(tempEndPos ,nexus1, nexus2);
			if ( pProj.SegmentPoint.IsValid() )
			{
				Vec3D StartPos1 = Extend(tempEndPos, pProj.SegmentPoint,   spellData.range/2);
				Vec3D EndPos1	= Extend(tempEndPos, pProj.SegmentPoint, - spellData.range/2);

				//__oMsg("---((*111*))----- DodS_NooFOW_Pyke_R-11111: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), StartPos1.Distance2D(EndPos1), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos1, EndPos1, spellData, 0, 0, false);

				float angle = 90 * ((float)(3.14159265358979323846f / 180));
				Vec3D StartPos2 = RotateAroundPoint(StartPos1, tempEndPos, angle);
				Vec3D EndPos2	= RotateAroundPoint(EndPos1  , tempEndPos, angle);
				//__oMsg("---((*222*))----- DodS_NooFOW_Pyke_R-22222: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), StartPos1.Distance2D(EndPos1), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos2, EndPos2, spellData, 0, 0);
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//-------------------------//
extern sphereQE* _xin1SlotQESyndra;
float radiusConeSyndraE = 215;

void DodS_NooFOW_Syndra_E(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {83,121,110,100,114,97,69,0};	// "SyndraE"
	if ( CheckName(szTemp, SPELL_NAME ) )
	{
		if ( !CheckNameEx(szTemp, SPELL_NAME ) )	// SPELL_NAME = "5SyndraE5"
			radiusConeSyndraE = 465;

		Vec3D tempSrcPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D tempEndPos_0(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
		Vec3D tempEndPos = Extend(tempSrcPos, tempEndPos_0, 802);;
		
		if (Distance(MY_HERO, tempEndPos) < spellData.range + 1000)
		{
			Vec3D dir     = (tempEndPos - tempSrcPos).Normalized();
			Vec3D cnLeft  = tempEndPos + Perpendicular(dir) * (radiusConeSyndraE + 155 + 50);
			Vec3D cnRight = tempEndPos - Perpendicular(dir) * (radiusConeSyndraE + 155 + 50);

			bool hasCreateSpellOne = false;

			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dwUnit1 = *(DWORD*)tempUnit;
			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
			if (!dwUnit1 || !dwUnit2 ) return;
			int countUnit = (dwUnit2 - dwUnit1)/4;
			for (int iii = 0; iii < countUnit; ++iii)
			{
				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
				if (dwUnit3 == 0) continue;
				KNpc *sphere = (KNpc*)dwUnit3;

				if (!IS_MINION(sphere))							continue;
				if (sphere->nTeam_ID == 0x12C)					continue;
				if (sphere->nTeam_ID == myTeamId)				continue;
				if (IS_DEAD(sphere))							continue;
				if ((BYTE)sphere->nIsTargetableToTeam == 4)		continue;
				if (Distance(MY_HERO, sphere) > 2000)			continue;

				char sz_temp1[] = {83, 101, 101, 100, 0};					
				if (!CheckName(sz_temp1, sphere->GetNameNpc())) continue;	// "Seed"

				char sz_temp2[] = {83, 121, 110, 100, 114, 97, 83, 112, 104, 101, 114, 101, 0};
				if (!CheckName(sz_temp2, sphere->GetNameHero()))continue;	// "SyndraSphere"

				if( !isLeftOfLineSegment(sphere->currentPos(), tempSrcPos , cnLeft) && 
					!isLeftOfLineSegment(sphere->currentPos(), cnRight, tempSrcPos) &&
					!isLeftOfLineSegment(sphere->currentPos(), cnLeft, cnRight) ) 
				{
					spellData.range		 = 1300 - Distance(sphere, enemyHero);					//phai co dinh luon range
					spellData.spellDelay = 250  + 1000 * Distance(sphere, enemyHero) / 2500;	//phai co dinh luon delayE va speedE
					
					Vec3D StartPos = sphere->currentPos();
					Vec3D EndPos   = sphere->currentPos() + (sphere->currentPos() - enemyHero->currentPos()).Normalized() * spellData.range;
					
					//__oMsg("---((*11*))----- DodS_NooFOW_Syndra_E_1-11111: SPELL_NAME: %s - %s, sphere_eHero = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), Distance(sphere, enemyHero), spellData.spellDelay, spellData.range);
					if (hasCreateSpellOne == false)
					{
						hasCreateSpellOne = true;
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
					}
					else
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);
				}
			}
			
			//---------------------------//----------------------------------
			if (_xin1SlotQESyndra && _xin1SlotQESyndra->posQE.IsValid())
			{
				if( !isLeftOfLineSegment( _xin1SlotQESyndra->posQE, tempSrcPos , cnLeft) && 
					!isLeftOfLineSegment( _xin1SlotQESyndra->posQE, cnRight, tempSrcPos) &&
					!isLeftOfLineSegment( _xin1SlotQESyndra->posQE, cnLeft, cnRight) ) 
				{
					spellData.range		 = 1300 - Distance(enemyHero, _xin1SlotQESyndra->posQE);				//phai co dinh luon range
					spellData.spellDelay = 250  + 1000 * Distance(enemyHero, _xin1SlotQESyndra->posQE) / 2500;	//phai co dinh luon delayE va speedE

					Vec3D StartPos = _xin1SlotQESyndra->posQE;
					Vec3D EndPos   = _xin1SlotQESyndra->posQE + (_xin1SlotQESyndra->posQE - enemyHero->currentPos()).Normalized() * spellData.range;

					//__oMsg("---((*22*))----- DodS_NooFOW_Syndra_E_1-11111: SPELL_NAME: %s - %s, sphere_eHero = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), Distance(enemyHero, _xin1SlotQESyndra->posQE), spellData.spellDelay, spellData.range);
					
					if (hasCreateSpellOne == false)
					{
						hasCreateSpellOne = true;
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
					}
					else
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);
				}
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Orianna_R(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {79,114,105,97,110,97,68,101,116,111,110,97,116,101,67,111,109,109,97,110,100,0};	// "OrianaDetonateCommand"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
		DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dwUnit1 = *(DWORD*)tempUnit;
		DWORD dwUnit2 = *(DWORD*)tempUnitMax;
		if (!dwUnit1 || !dwUnit2 ) return;
		int countUnit = (dwUnit2 - dwUnit1)/4;
		for (int iii = 0; iii < countUnit; ++iii)
		{
			DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
			if (dwUnit3 == 0) continue;
			KNpc *enemyObj = (KNpc*)dwUnit3;
			
			if (IS_HERO(enemyObj) && enemyObj->nTeam_ID != myTeamId && !IS_DEAD(enemyObj))
			{
				char sz_tempBuff1[] = {111, 114, 105, 97, 110, 97, 103, 104, 111, 115, 116, 115, 101, 108, 102, 0};	// "orianaghostself"
				char sz_tempBuff2[] = {111,114,105,97,110,97,103,104,111,115,116,0};								// "orianaghost"
				if (GET_BUFF(enemyObj, sz_tempBuff1) || GET_BUFF(enemyObj, sz_tempBuff2))
				{
					Vec3D Start = enemyObj->currentPos();
					Vec3D End   = enemyObj->currentPos();

					if (Distance(MY_HERO, Start) < 1500)
					{
						//__oMsg("---((*22*))----- DodS_NooFOW_Orianna_R_BUFFF-11111: SPELL_NAME: %s - %s, sphere_eHero = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), Distance(enemyObj, enemyHero), spellData.spellDelay, spellData.range);
						CreateSpellData(enemyHero, Start, End, spellData, 0, 0);
						return;
					}	
				}
			}

			if (!IS_MINION(enemyObj))							continue;
			if (enemyObj->nTeam_ID == 0x12C)					continue;
			if (enemyObj->nTeam_ID == myTeamId)					continue;
			if (IS_DEAD(enemyObj))								continue;
			if ((BYTE)enemyObj->nIsTargetableToTeam == 4)		continue;
			if (Distance(MY_HERO, enemyObj) > 1500)				continue;

			char sz_temp1[] = {84,104,101,68,111,111,109,66,97,108,108,0};	// "TheDoomBall"				
			if (!CheckName(sz_temp1, enemyObj->GetNameNpc()))	continue;	

			char sz_temp2[] = {79,114,105,97,110,110,97,66,97,108,108,0};	// "OriannaBall"
			if (!CheckName(sz_temp2, enemyObj->GetNameHero()))	continue;	

			Vec3D StartPos = enemyObj->currentPos();
			Vec3D EndPos   = enemyObj->currentPos();

			if (Distance(MY_HERO, StartPos) < 1500)
			{
				//__oMsg("---((*22*))----- DodS_NooFOW_Orianna_R_BALL-11111: SPELL_NAME: %s - %s, sphere_eHero = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), Distance(enemyObj, enemyHero), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
				return;
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Sylas_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {83,121,108,97,115,81,0};	// "SylasQ"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
		
		if (StartPos.Distance2D(EndPos) < 185)
		{
			EndPos = Extend(StartPos, EndPos, 185);
		}

		if (Distance(MY_HERO, EndPos) < spellData.range + 1000)
		{
			Vec3D direction  = (EndPos - StartPos).Normalized();
			Vec3D pDirection = Perpendicular(direction);
			Vec3D targetPoint = StartPos;

			Vec3D pos1 = targetPoint - pDirection * 150;
			Vec3D pos2 = targetPoint + pDirection * 150;

			//__oMsg("---((*222*))----- DodS_NooFOW_Sylas_Q-22222: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), pos1.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, pos1, EndPos, spellData, 0, 0, false);
			CreateSpellData(enemyHero, pos2, EndPos, spellData, 0, 0, false);

			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 1000, true, Circular, true, 165);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Yorick_E(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {89,111,114,105,99,107,69,0};	// "YorickE"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
		
		if (Distance(MY_HERO, EndPos) < spellData.range + 1000)
		{
			Vec3D direction = (EndPos - StartPos).Normalized();

			if (StartPos.Distance2D(EndPos) > spellData.range)
				EndPos = StartPos + (EndPos - StartPos).Normalized() * spellData.range;

			Vec3D spellStart = Extend(EndPos, enemyHero->currentPos(), 100);
			Vec3D spellEnd   = spellStart + direction * 550;

			spellData.range = 550;
			spellData.spellDelay += 1000 * Distance(EndPos, StartPos)/1800;		

			//__oMsg("---((*222*))----- DodS_NooFOW_Yorick_E-22222: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, spellStart, spellEnd, spellData, 0, 0);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Ziggs_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {90,105,103,103,115,81,0};	// "ZiggsQ"

	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, EndPos) < spellData.range + 1000)
		{
			Vec3D dir = (EndPos - StartPos).Normalized();
			if (EndPos.Distance2D(StartPos) > 850)
			{
				EndPos = StartPos + dir * 850;
			}
			
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);
			
			float exEntick = 575;
			Vec3D endPos2 = EndPos + dir * 0.4f * StartPos.Distance2D(EndPos);
			spellData.range = StartPos.Distance2D(endPos2); 
			CreateSpellData(enemyHero, StartPos, endPos2, spellData, 0, exEntick, false);

			exEntick = 950;
			Vec3D endPos3 = endPos2 + dir * 0.6f * EndPos.Distance2D(endPos2);
			spellData.range = StartPos.Distance2D(endPos3);

			//__oMsg("---((*222*))----- DodS_NooFOW_Ziggs_Q-22222: SPELL_NAME: %s - %s, KC_Missile = %.3f - delay: %f - spell.range: %f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, endPos3, spellData, 0, exEntick, true, None, true, 240);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Graves_Q12(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {71,114,97,118,101,115,81,76,105,110,101,83,112,101,108,108,0};	// "GravesQLineSpell"

	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, EndPos) < spellData.range + 1000)
		{
			//__oMsg("---((*111*))----- DodS_NooFOW_Graves_Q_BTHUONG: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);
		
			EndPos = StartPos + (EndPos - StartPos).Normalized() * spellData.range;

			float spellDelay3 = 1000 + 250 + 250 + 1000 * Distance(StartPos, EndPos) / 3000;	//ghi 2s, nhung chi 1.25 + 0.25(timeCast) la dan quay ve

			Vec3D w = GetNearWallPoint(StartPos, EndPos);
			if (w.IsValid())
			{
				EndPos = w;
				spellDelay3 = 200 + 200 + 250 + 250 + 1000 * Distance(StartPos, EndPos)/3000;	//3000 la speed cua Q1, 625 la time no? khi va vao` wall, xFuck la delay cua Q1(deo hieu sao 625-650 lai chuan the)
				
				EndPos = Extend(EndPos, StartPos, 160);
				//__oMsg("--DIS_VV_VVVV: %f", Distance(EndPos, StartPos));
			}

			spellData.spellDelay	  = spellDelay3 - 250;
			spellData.range			  = Distance(StartPos, EndPos) + 160;
			spellData.projectileSpeed = 1600;
			//__oMsg("---((*222*))----- DodS_NooFOW_Graves_Q_BACK: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, EndPos, StartPos, spellData, 0, 0, false, None, true, 90);

			//---- Line-1:(vuongGoc)
			spellData.spellDelay	  = spellDelay3;
			spellData.isPerpendicular = true;
			spellData.secondaryRadius = 300;
			spellData.updatePosition  = false;
			spellData.projectileSpeed = FLT_MAX;
			spellData.waitExtra       = 0;
			spellData.extraEndTime    = 100;

			//__oMsg("---((*333*))----- DodS_NooFOW_Graves_Q_NGANG: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, true, None, true, 170);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Soraka_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {83,111,114,97,107,97,81,0};	// "SorakaQ"

	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, EndPos) < spellData.range + 1000)
		{
			float khoangCach = Distance(StartPos, EndPos);;
			int	  delay		 = (int)khoangCach/100;
			//__oMsg("kc : %f, delay: %d -> %d", khoangCach, 100*delay, 100*delay + 200);

			spellData.spellDelay = 200 + (float)delay * 100 + 50;

			//__oMsg("---((*111*))----- DodS_NooFOW_Soraka_Q: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Sion_E(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {83,105,111,110,69,0};	// "SionE"

	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		if (Distance(MY_HERO, StartPos) < spellData.range + 1500)
		{
			Vec3D End_Extend = Extend(StartPos, EndPos, spellData.range + 50);

			DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dw1x = *(DWORD*)tempUnit;
			DWORD dw2x = *(DWORD*)tempUnitMax;
			if (dw1x && dw2x )
			{
				int nCount = (dw2x - dw1x)/4;
				for (int kkk = 0; kkk < nCount; ++kkk)
				{
					DWORD dw3 = *(DWORD*)(dw1x + 4*kkk);
					if (dw3 == 0) continue;
					KNpc *allyMinion = (KNpc*)dw3;

					if (!IS_MINION(allyMinion))							continue;
					if (IS_DEAD(allyMinion))							continue;
					if (allyMinion->nTeam_ID != myTeamId)				continue;
					
					if (Distance(allyMinion, MY_HERO) > 1500)			continue;

					char sz_Temp[] = {77, 105, 110, 105, 111, 110, 0};	// "Minion"
					if (!CheckName(sz_Temp, allyMinion->GetNameNpc()))	continue;

					ProjectionInfo projection = ProjectOn(allyMinion->currentPos(), StartPos, End_Extend);
					if (projection.IsOnSegment && projection.SegmentPoint.Distance2D(allyMinion->currentPos()) <= spellData.radius + 95)
					{
						spellData.range     = 1375;
						spellData.waitExtra	= 300;
						break;
					}
				}
			}

			//__oMsg("---((*111*))----- DodS_NooFOW_Sion_E: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
		}
	}
}


//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Aatrox_Q123(KNpc* enemyHero, KCastSpell* spellCast, /*SpellData spellData,*/ char* SPELL_NAME)
{
	char szTemp[] = {65,97,116,114,111,120,81,87,114,97,112,112,101,114,67,97,115,116,0};	// "AatroxQWrapperCast"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		if (Distance(MY_HERO, enemyHero) < 1800)
		{
			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
			DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
			if (!dw0) return;

			DWORD dw1 = *(DWORD*)(dw0 + 8);
			if (!dw1) return;

			int countAllObj = *(DWORD*)(dw0 + 0xC);
			if (!countAllObj) return;

			for (int kk = 0; kk < countAllObj; ++kk)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
				if (dw3 == 0) continue;
				KNpc *object = (KNpc*)dw3;

				if (OBJECT_TYPE(object) != 1)			continue;
				if ((object->nIndex & 0x3fff) <= 0 || 
					(object->nIndex & 0x3fff) > 0xFF00) continue;
				if (IS_OBJ_DELETED(object) == true)		continue;

				char szTemp_01[] = {95,81,95,73,110,100,105,99,97,116,111,114,95,48,49,0};		// "_Q_Indicator_01"
				if (CheckName(szTemp_01, object->GetNameNpc()) && CheckName("Aatrox",object->GetNameNpc()))		// Q.1
				{
					char szTemp[] = {65,97,116,114,111,120,81,95,83,115,0};		// "AatroxQ_Ss"	
					std::string mis_Name(szTemp);

					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
					{
						SpellData spellData = it_onMissileSpells->second;

						Vec3D StartPos = enemyHero->currentPos();
						Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
						//__oMsg("---((*111*))----- DodS_NooFOW_Aatrox_Q123: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
						return;
					}
				}

				char szTemp_02[] = {95,81,95,73,110,100,105,99,97,116,111,114,95,48,50,0};		// "_Q_Indicator_02"
				if (CheckName(szTemp_02, object->GetNameNpc()) && CheckName("Aatrox",object->GetNameNpc()))	// Q.2
				{
					char szTemp[] = {65,97,116,114,111,120,81,50,95,83,115,0};		// "AatroxQ2_Ss"	
					std::string mis_Name(szTemp);

					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
					{
						SpellData spellData = it_onMissileSpells->second;

						Vec3D StartPos = enemyHero->currentPos();
						Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
						//__oMsg("---((*222*))----- DodS_NooFOW_Aatrox_Q123: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
						return;
					}
				}

				char szTemp_03[] = {95,81,95,73,110,100,105,99,97,116,111,114,95,48,51,0};		// "_Q_Indicator_03"
				if (CheckName(szTemp_03, object->GetNameNpc()) && CheckName("Aatrox",object->GetNameNpc()))	// Q.3
				{
					char szTemp[] = {65,97,116,114,111,120,81,51,95,83,115,0};		// "AatroxQ3_Ss"
					std::string mis_Name(szTemp);

					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
					{
						SpellData spellData = it_onMissileSpells->second;

						Vec3D StartPos = enemyHero->currentPos();
						Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
						//__oMsg("---((*333*))----- DodS_NooFOW_Aatrox_Q123: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
					}
				}
			}
		}
	}
}

//--------------------//---------------:
void TRY_EXCEPT_DodS_NooFOW_Aatrox_Q123(KNpc* enemyHero, KCastSpell* spellCast/*, SpellData spellData*/, char* SPELL_NAME)
{
	__try
	{
		DodS_NooFOW_Aatrox_Q123( enemyHero, spellCast/*, spellData*/, SPELL_NAME);
	}
	__except(1)
	{
		char szTemp[] = {69,82,82,79,82,32,58,32,68,111,100,103,101,32,65,97,116,114,111,120,32,81,0};	// "ERROR : Dodge Aatrox Q"
		SEND_TEXT_SYSTEM(szTemp);
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_TahmKench_W(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {84,97,104,109,75,101,110,99,104,87,67,97,115,116,84,105,109,101,65,110,100,65,110,105,109,97,116,105,111,110,0}; // "TahmKenchWCastTimeAndAnimation"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		if (Distance(MY_HERO, enemyHero) < spellData.range + 1000)
		{
			DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dw1x = *(DWORD*)tempUnit;
			DWORD dw2x = *(DWORD*)tempUnitMax;
			if (dw1x && dw2x )
			{
				int nCount = (dw2x - dw1x)/4;
				for (int kkk = 0; kkk < nCount; ++kkk)
				{
					DWORD dw3 = *(DWORD*)(dw1x + 4*kkk);
					if (dw3 == 0) continue;
					KNpc *Minion = (KNpc*)dw3;

					if (!IS_MINION(Minion))						continue;
					if (IS_DEAD(Minion))						continue;

					if (Minion->nMaxHP < 20)					continue;
					if ((BYTE)Minion->nIsTargetableToTeam == 4) continue;
					if (Distance(Minion, enemyHero) > 185)		continue;
					if (Distance(Minion, MY_HERO) > 2000)		continue;

					if (Minion->nTeam_ID == myTeamId)				
					{
						char sz_Temp[] = {77, 105, 110, 105, 111, 110, 0};			// "Minion"
						if (!CheckName(sz_Temp, Minion->GetNameNpc()))	continue;
						
						char szTempBuff[] = {116,97,104,109,107,101,110,99,104,119,100,101,118,111,117,114,101,100,0}; // "tahmkenchwdevoured"
						if (GET_BUFF(Minion, szTempBuff))
						{
							Vec3D StartPos		= enemyHero->currentPos();
							Vec3D EndPos		= GET_REAL_FACING_POS(enemyHero);

							//__oMsg("---((*111*))----- DodS_NooFOW_TahmKench_W_MINION: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
							return;
						}
					}
					else if (Minion->nTeam_ID == 0x12C)
					{
						if ( CheckName(sz__SRU_, Minion->GetNameNpc()) || CheckName(sz__Sru_, Minion->GetNameNpc()) || CheckName(sz__MiniKrug, Minion->GetNameNpc()) ) 
						{
							char szTempBuff[] = {116,97,104,109,107,101,110,99,104,119,100,101,118,111,117,114,101,100,0}; // "tahmkenchwdevoured"
							if (GET_BUFF(Minion, szTempBuff))
							{
								Vec3D StartPos		= enemyHero->currentPos();
								Vec3D EndPos		= GET_REAL_FACING_POS(enemyHero);

								//__oMsg("---((*222*))----- DodS_NooFOW_TahmKench_W_JUNGLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
								return;
							}
						}
					}
				}
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Karma_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {75,97,114,109,97,81,0}; // "KarmaQ"
	if ( CheckNameEx(szTemp, SPELL_NAME ) )
	{
		Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D EndPosTemp  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
		Vec3D EndPos = Extend(StartPos, EndPosTemp, spellData.range);

		if (Distance(MY_HERO, StartPos) < spellData.range + 1000)
		{
			char szTempBuff[] = {75,97,114,109,97,77,97,110,116,114,97,0};	// "KarmaMantra"
			if (!GET_BUFF(enemyHero, szTempBuff))	//Q.Bthuong
			{
				Vec3D unitPosSeg = GetCollisionAllyPos(StartPos, EndPos, spellData.range, spellData.radius, 20, 1);
				if (unitPosSeg.IsValid())
				{
					//__oMsg("---((*0000*))----- DodS_NooFOW_Karma_Q_22.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

					//__oMsg("---((*0000*))----- DodS_NooFOW_Karma_Q_22.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, unitPosSeg, spellData, 0, 650, true, Circular, false, 275);
					return;
				}

				//__oMsg("---((*1111*))----- DodS_NooFOW_Karma_Q_22.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
			}
			else	//Q+R
			{
				Vec3D unitPosSeg = GetCollisionAllyPos(StartPos, EndPos, spellData.range, spellData.radius + 20, 20, -5);
				if (unitPosSeg.IsValid())
				{
					
					//__oMsg("---((*2222*))----- DodS_NooFOW_Karma_Q_22.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false, None, false, 80);

					//__oMsg("---((*2222*))----- DodS_NooFOW_Karma_Q_22.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, unitPosSeg, spellData, 0, 1650, true, Circular, false, 300);
					return;
				}

				//__oMsg("---((*3333*))----- DodS_NooFOW_Karma_Q_22.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false, None, false, 80);

				//__oMsg("---((*3333*))----- DodS_NooFOW_Karma_Q_22.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 1650, true, Circular, false, 300);
			}
		}
	}
}

//--------------------//----------------------------------//--------------------//
void DodS_NooFOW_Jayce_Q(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)
{
	char szTemp[] = {74,97,121,99,101,83,104,111,99,107,66,108,97,115,116,0}; // "JayceShockBlast"
	if ( !CheckNameEx(szTemp, SPELL_NAME ) ) return;

	Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	Vec3D EndPosTemp  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	Vec3D EndPos = Extend(StartPos, EndPosTemp, spellData.range);

	if (Distance(MY_HERO, StartPos) < spellData.range + 1000)
	{
		std::vector<Vec3D> listHiuPos;

		DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
		DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dwUnit1 = *(DWORD*)tempUnit;
		DWORD dwUnit2 = *(DWORD*)tempUnitMax;
		if (!dwUnit1 || !dwUnit2 ) return;
		int countUnit = (dwUnit2 - dwUnit1)/4;
		for (int iii = 0; iii < countUnit; ++iii)
		{
			DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
			if (dwUnit3 == 0) continue;
			KNpc *eHiu = (KNpc*)dwUnit3;

			if (!IS_MINION(eHiu))							continue;
			if ((BYTE)eHiu->nIsTargetableToTeam != 2)		continue;		//co ca 2.3.4, lay =2 vi Xerath lay=3 roi
			if (IS_DEAD(eHiu))								continue;
			if (eHiu->nTeam_ID == 0x12C)					continue;
			if (eHiu->nTeam_ID == myTeamId)					continue;
			if (Distance(MY_HERO, eHiu) > 2000)				continue;

			if (!CheckNameEx(eHiu->GetNameNpc(), "hiu"))	continue;
			char szTemp[] = {84,101,115,116,67,117,98,101,82,101,110,100,101,114,49,48,86,105,115,105,111,110,0};	// "TestCubeRender10Vision"
			if (!CheckNameEx(eHiu->GetNameHero(), szTemp))	continue;

			listHiuPos.push_back(eHiu->currentPos());
			//__oMsg("%d", listHiuPos.size());
		}
		//----------
		if ( listHiuPos.size() > 1 && fabs(listHiuPos[0].x - listHiuPos.back().x) > FLT_EPSILON)
		{
			Vec3D posHiu1 = Extend(listHiuPos[0], listHiuPos.back(), -75);
			Vec3D posHiu2 = Extend(listHiuPos.back(), listHiuPos[0], -75);

			if ( Intersection(StartPos, EndPos, posHiu1, posHiu2).Intersects )
			{
				Vec3D pointI = Intersection(StartPos, EndPos, posHiu1, posHiu2).Point;
				if (pointI.IsValid())
				{
					float deltaDelay = Distance(pointI, StartPos)/1450 - Distance(pointI, StartPos)/2350;
					spellData.spellDelay += 1000*deltaDelay - 20;
					spellData.projectileSpeed = 2350;
					spellData.range			  = 1600;

					Vec3D unitPosSeg = GetCollisionAllyPos(StartPos, EndPos, spellData.range, spellData.radius, 20, -46);
					if (unitPosSeg.IsValid())
					{
						//__oMsg("---((*0000*))----- DodS_NooFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

						//__oMsg("---((*0000*))----- DodS_NooFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
						CreateSpellData(enemyHero, StartPos, unitPosSeg, spellData, 0, 0, true, Circular, false, 275);
						return;
					}

					//__oMsg("---((*1111*))----- DodS_NooFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

					EndPos = Extend(StartPos, EndPosTemp, spellData.range);
					//__oMsg("---((*1111*))----- DodS_NooFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, true, Circular, false, 275);
				}
			}
			else	//ko co E hoac ko nam giua E
			{
				Vec3D unitPosSeg = GetCollisionAllyPos(StartPos, EndPos, spellData.range, spellData.radius, 20, -46);
				if (unitPosSeg.IsValid())
				{
					//__oMsg("---((*2222*))----- DodS_NooFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

					//__oMsg("---((*2222*))----- DodS_NooFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
					CreateSpellData(enemyHero, StartPos, unitPosSeg, spellData, 0, 0, true, Circular, false, 165);
					return;
				}

				//__oMsg("---((*3333*))----- DodS_NooFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

				//__oMsg("---((*3333*))----- DodS_NooFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, true, Circular, false, 165);
			}
		}
		else
		{
			Vec3D unitPosSeg = GetCollisionAllyPos(StartPos, EndPos, spellData.range, spellData.radius, 20, -46);
			if (unitPosSeg.IsValid())
			{
				//__oMsg("---((*4444*))----- DodS_NooFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

				//__oMsg("---((*4444*))----- DodS_NooFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
				CreateSpellData(enemyHero, StartPos, unitPosSeg, spellData, 0, 0, true, Circular, false, 165);
				return;
			}

			//__oMsg("---((*5555*))----- DodS_NooFOW_Jayce_Q.LINE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, false);

			//__oMsg("---((*5555*))----- DodS_NooFOW_Jayce_Q.CIRCLE: SPELL_NAME: [%s] %s, KC_Missile = %.3f - delay: %.3f - spell.range: %.3f", SPELL_NAME, spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay, spellData.range);
			CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0, true, Circular, false, 165);
		}
	}
}



//--------------------//----------------------------------//--------------------//
//--------------------//----------------------------------//--------------------//
void Dodge_Special_1111(KNpc* enemyHero, KCastSpell* spellCast, SpellData spellData, char* SPELL_NAME)	// dung voi pCast va` khi isSpecial_11x = true
{
	if (!MY_HERO || !myTeamId || !G_Module)	 return;
	if (IsCanSee(enemyHero) == false)		 return;
	if (Distance(enemyHero, MY_HERO) > 2500) return;

	//---- Lulu.Q :
	if (hasLulu)			DodS_NooFOW_Lulu_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Zed.Q :
	if (hasZed)				DodS_NooFOW_Zed_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Yasuo.Q12 :
	if (hasYasuo)			DodS_NooFOW_Yasuo_Q12(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- TwistedFate.Q:
	if (hasTwistedFate)		DodS_NooFOW_TwistedFate_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Khazix.W :
	if (hasKhazix)			DodS_NooFOW_Khazix_W(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Riven.R :
	if (hasRiven)			DodS_NooFOW_Riven_R(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Pyke.E :
	if (hasPyke)			
	{
							DodS_NooFOW_Pyke_E(enemyHero, spellCast, spellData, SPELL_NAME);
							DodS_NooFOW_Pyke_R(enemyHero, spellCast, spellData, SPELL_NAME);
	}

	//---- Syndra.E :
	if (hasSyndra)			DodS_NooFOW_Syndra_E(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Orianna.R :
	if (hasOrianna)			DodS_NooFOW_Orianna_R(enemyHero, spellCast, spellData, SPELL_NAME);
	
	//---- Sylas:
	if (hasSylas)			DodS_NooFOW_Sylas_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Yorick:
	if (hasYorick)			DodS_NooFOW_Yorick_E(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Ziggs:
	if (hasZiggs)			DodS_NooFOW_Ziggs_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Graves:
	if (hasGraves)			DodS_NooFOW_Graves_Q12(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Soraka:
	if (hasSoraka)			DodS_NooFOW_Soraka_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Sion:
	if (hasSion)			DodS_NooFOW_Sion_E(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Aatrox:
	if (hasAatrox)			TRY_EXCEPT_DodS_NooFOW_Aatrox_Q123(enemyHero, spellCast/*, spellData*/, SPELL_NAME);	// meo' try-except dc

	//---- TahmKench:
	if (hasTahmKench)		DodS_NooFOW_TahmKench_W(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Karma:
	if (hasKarma)			DodS_NooFOW_Karma_Q(enemyHero, spellCast, spellData, SPELL_NAME);

	//---- Jayce:
	if (hasJayce)			DodS_NooFOW_Jayce_Q(enemyHero, spellCast, spellData, SPELL_NAME);
}