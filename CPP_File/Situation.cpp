#include "Situation.h"
#include "Position.h"


extern Evade*		_Evade;
extern int			myTeamId;

extern bool DodgeSkillShots_menu, DodgeOnlyOnComboKeyEnabled_menu, DontDodgeKeyEnabled_menu, PreventDodgingNearEnemy_menu, ActivateEvadeSpells_menu;
extern int DodgeComboKey_menu, DontDodgeKey_menu, ActivateEvadeSpells_Key_menu;
//-------------------------------------------------//-----------------------//----------
bool CheckTeam(KNpc* unit)
{
	return unit->nTeam_ID != myTeamId /*|| _Evade->devModeOn*/;
}

//-------------------------------------------------//-----------------------//----------
bool isNearEnemy(Vec3D pos, float distance, bool alreadyNear)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	if (PreventDodgingNearEnemy_menu)
	{
		float curDistToEnemies = GetDistanceToChampions(myHero->currentPos());
		float posDistToEnemies = GetDistanceToChampions(pos);

		if (curDistToEnemies < distance)
		{
			if (curDistToEnemies > posDistToEnemies)
			{
				return true;
			}
		}
		else
		{
			if (posDistToEnemies < distance)
			{
				return true;
			}
		}
	}

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool ShouldDodge()
{
	if (DontDodgeKeyEnabled_menu && (GetAsyncKeyState(DontDodgeKey_menu) & 0x8000))
	{
		return false;
	}	

	if (DodgeSkillShots_menu == false || CommonChecks())
	{
		//has spellshield - sivir, noc, morgana
		//vlad pool
		//tryndamere r?
		//kayle ult buff?
		//hourglass
		//invulnerable
		//rooted
		//sion ult -> tenacity = 100?
		//stunned
		//elise e
		//zilean ulted
		//isdashing

		return false;
	}
	return true;
}

//-------------------------------------------------//-----------------------//----------
bool ShouldUseEvadeSpell()
{
	if (DontDodgeKeyEnabled_menu == true && !(GetAsyncKeyState(DodgeComboKey_menu) & 0x8000))
	{
		return false;
	}

	if (ActivateEvadeSpells_menu == false || CommonChecks() || _Evade->lastWindupTime - (float)GetTickCount() > 0)
	{
		return false;
	}

	return true;
}

//-------------------------------------------------//-----------------------//----------
bool CommonChecks()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	return
		_Evade->isChanneling
		|| IsChannelingImportantSpell(myHero)	// ham nay chinh la _Evade->isChanneling == true
		|| (DodgeOnlyOnComboKeyEnabled_menu == true && !(GetAsyncKeyState(DodgeComboKey_menu) & 0x8000))
		|| IS_DEAD(myHero)
		////|| myHero.IsInvulnerable
		////|| Evade.hasGameEnded == true

		|| (BYTE)myHero->nIsTargetableToTeam == 3
		|| (BYTE)myHero->nIsTargetable == 0
		|| HasSpellShield(myHero)
		|| ChampionSpecificChecks()
		|| IsDashing(myHero);
}

//-------------------------------------------------//-----------------------//----------
bool ChampionSpecificChecks()
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;
	bool result = false;

	//hinh nhu chi can check Sion, vi bon kia nIsTargetableToTeam = 3
	if (CheckName(myHero->GetNameHero(), "Sion") && (GET_BUFF(myHero, "SionR") || GET_BUFF(myHero, "sionpassivezombie"))) result = true;
	//if (CheckName(myHero->GetNameHero(), "KogMaw") && GET_BUFF(myHero, "KogMawIcathianSurprise"))  result = true;
	//if (CheckName(myHero->GetNameHero(), "Karthus") && GET_BUFF(myHero, "KarthusDeathDefiedBuff")) result = true;
	return result;

	//Untargetable
	//|| (myHero.ChampionName == "KogMaw" && myHero.HasBuff("kogmawicathiansurprise"))
	//|| (myHero.ChampionName == "Karthus" && myHero.HasBuff("KarthusDeathDefiedBuff"))

	//Invulnerable
	//|| myHero.HasBuff("kalistarallyspelllock"); 
}

//-------------------------------------------------//-----------------------//----------
bool IsChannelingImportantSpell(KNpc* unit)
{
	extern bool g_bDoingR_Xerath, g_bDoingR_MissFortune, g_bDoingR_Katarina, g_bDoingR_Jhin, g_bDoingR_Jana, g_bDoingR_Nunu, g_bDoingW_Yi;

	if(g_bDoingR_Xerath || g_bDoingR_MissFortune || g_bDoingR_Katarina || g_bDoingR_Jhin || g_bDoingR_Jana || g_bDoingR_Nunu || g_bDoingW_Yi)
	{
		if(_Evade->isDodging == true) _Evade->isDodging = false;
		return true;
	}

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool HasSpellShield(KNpc* unit)
{
	if(!unit) return false;

	//if (COUNT_BUFF_BY_TYPE(unit, SpellShield_Buff)) return true;	// dung cai nay hoi nguy hiem

	//Olaf R
	if (CheckName(unit->GetNameHero(), "Olaf") && GET_BUFF(unit, "OlafR"))
	{
		KBuffs* buff = GET_BUFF(unit, "OlafR");
		if(buff && buff->nEnd_Time - GetTimeGame() > 0.3) return true;
	}

	if (COUNT_BUFF_BY_TYPE(unit, SpellImmunity_Buff)) return true;	

	//Sivir E
	if (CheckName(unit->GetNameHero(), "Sivir") && GET_BUFF(unit, "SivirE"))
	{
		KBuffs* buff = GET_BUFF(unit, "SivirE");
		if(buff && buff->nEnd_Time - GetTimeGame() > 0.3) return true;
	}

	//Morganas E
	if (GET_BUFF(unit, "BlackShield"))
	{
		KBuffs* buff = GET_BUFF(unit, "BlackShield");
		if(buff && buff->nEnd_Time - GetTimeGame() > 0.3) return true;
	}

	//Nocturnes E
	if (CheckName(unit->GetNameHero(), "Nocturne") && GET_BUFF(unit, "NocturneShit"))
	{
		KBuffs* buff = GET_BUFF(unit, "NocturneShit");
		if(buff && buff->nEnd_Time - GetTimeGame() > 0.3) return true;
	}

	return false;
}