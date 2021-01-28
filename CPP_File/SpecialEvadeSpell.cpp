#include "SpecialEvadeSpell.h"
#include "EvadeHelper.h"
#include "EvadeCommand.h"
#include "Position.h"
#include "DelayAction.h"


extern cb_UseSpellFunc useSpellFunc_CB;
extern DelayAction* _DelayAction;
//-----------------------------------------//-------------------------//
void LoadSpecialSpell(EvadeSpellData spellData)
{
	if (spellData.spellName.compare("EkkoEAttack") == 0)
	{
		useSpellFunc_CB = UseEkkoE2;
	}

	if (spellData.spellName.compare("EkkoR") == 0)
	{
		useSpellFunc_CB = UseEkkoR;
	}

	if (spellData.spellName.compare("RivenTriCleave") == 0)
	{
		useSpellFunc_CB = UseBrokenWings;
	}

	if (spellData.spellName.compare("TalonQ") == 0)
	{
		useSpellFunc_CB = UseTalon_Q;
	}
	
	if (spellData.spellName.compare("EliseSpiderEInitial") == 0)
	{
		useSpellFunc_CB = UseRappel;
	}
}

//-----------------------------------------//-------------------------//
bool UseEkkoE2(EvadeSpellData evadeSpell, bool process)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;
	
	if (GET_BUFF(myHero, "ekkoeattackbuff"))
	{
		PositionInfo* posInfo = GetBestPositionTargetedDash(evadeSpell);
		if (posInfo != 0 && posInfo->target != 0)
		{
			if (process == true)
			{
				EC_Attack(evadeSpell, posInfo->target);
				//-//DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
				return true;
			}
		}
	}

	return false;
}

//-----------------------------------------//-------------------------//
bool UseEkkoR(EvadeSpellData evadeSpell, bool process)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

	DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw_1 = *(DWORD*)tempUnit;
	DWORD dw_2 = *(DWORD*)tempUnitMax;
	if (dw_1 && dw_2 )
	{	
		int nCount = (dw_2 - dw_1)/4;
		for (int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw_1 + 4*i);
			KNpc *object = (KNpc*)dw3;

			if (object == 0)      continue;
			if (object == myHero) continue;
			if (IS_DEAD(object) == true || (BYTE)object->nIsTargetableToTeam == 4) continue;	//nIsTargetableToTeam = 3
			if (object->nTeam_ID != myHero->nTeam_ID) continue;
			if (CheckName("Ekko", object->GetNameNpc()))
			{
				//__oMsg("name: %s - %d", object->GetNameNpc(), (BYTE)object->nIsTargetableToTeam);
				Vec3D blinkPos = object->currentPos();
				if (!CheckDangerousPos(blinkPos, 10))
				{
					if (process == true)
					{
						EC_CastSpell(&evadeSpell);
						//-//DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
						return true;
					}
				}
			}
		}
	}

	return false;
}

//-----------------------------------------//-------------------------//
void riven_ChemTungRau()
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	Cast2Target(myHero, _Q);
}

//--------------//-------------//
bool UseBrokenWings(EvadeSpellData evadeSpell, bool process)
{
	PositionInfo* posInfo = GetBestPositionDash(evadeSpell);
	if (posInfo != 0)
	{
		if (process == true)
		{
			EC_MoveTo(posInfo->position);
			
			_DelayAction->Add(50, riven_ChemTungRau);
			//EC_CastSpell(&evadeSpell);
			//__oMsg("vaovaoavo---vaovoavovaoavoavoavo");
			//-//DelayAction.Add(50, () => EvadeSpell.CastEvadeSpell(() => EvadeCommand.CastSpell(evadeSpell), process));
			return true;
		}
	}

	return false;
}

//-----------------------------------------//-------------------------//
bool UseTalon_Q(EvadeSpellData evadeSpell, bool process)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

	PositionInfo* posInfo = GetBestPositionTargetedDash(evadeSpell);
	if (posInfo != 0 && posInfo->target != 0 && Distance(myHero, posInfo->target) > 295)
	{
		if (process == true)
		{
			//__oMsg("--TALON----VAO-----Q");
			EC_CastSpell(&evadeSpell, posInfo->target);
			EC_CastSpell(&evadeSpell, posInfo->target);
			return true;
		}
	}

	return false;
}

//-----------------------------------------//-------------------------//
bool UseRappel(EvadeSpellData evadeSpell, bool process)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

	if (myHero->nAttackRange < 400)		//dang la nhen.
	{
		if (process == true)
		{
			//__oMsg("Cast---EEEE-Nhen");
			EC_CastSpell(&evadeSpell, myHero);
			return true;
		}
	}

	/*if (myHero->nAttackRange >= 400)
	{
		if (CanCast(_R) == true)
		{
			__oMsg("Cast---R");
			Cast2Target(myHero, _R);
		}
	}*/

	return false;
}