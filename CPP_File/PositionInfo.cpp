
#include "PositionInfo.h"
#include "EvadeHelper.h"

extern PositionInfo*	_PositionInfo;
extern SpellDetector*	_SpellDetector;
//-------------------------------------------------//-----------------------//----------
PositionInfo*	_SetAllDodgeable = 0;
PositionInfo* SetAllDodgeable()
{
	Vec3D vZezo(0,0,0);

	KNpc* myHero = GetPlayer();
	Vec3D position(0,0,0);
	if(myHero) position = myHero->currentPos();

	return SetAllDodgeable(position);
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* SetAllDodgeable(Vec3D position)
{
	if (_SetAllDodgeable == 0) _SetAllDodgeable = new PositionInfo;

	std::vector<int>  *dodgeableSpells	 = 0;	
	std::vector<int>  *undodgeableSpells = 0;
	
	if(dodgeableSpells   == 0) dodgeableSpells   = new std::vector<int>;	//co the LAGGG vi tao nhieu con tro
	if(undodgeableSpells == 0) undodgeableSpells = new std::vector<int>;	//co the LAGGG vi tao nhieu con tro

	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		dodgeableSpells->push_back(it_spells->first);
	}

	_SetAllDodgeable->position			= position;
	_SetAllDodgeable->posDangerLevel	= 0;
	_SetAllDodgeable->posDangerCount	= 0;
	_SetAllDodgeable->isDangerousPos	= true;
	_SetAllDodgeable->distanceToMouse	= 0;
	_SetAllDodgeable->dodgeableSpells	= dodgeableSpells;
	_SetAllDodgeable->undodgeableSpells = undodgeableSpells;
	_SetAllDodgeable->timestamp			= (float)GetTickCount();
	//__oMsg("SetAllDodgeable-2 : size = %d, %f", (int)_SetAllDodgeable->dodgeableSpells->size(), _SetAllDodgeable->position.x);
	
	return _SetAllDodgeable;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* SetAllUndodgeable()
{
	KNpc* myHero = GetPlayer();
	
	std::vector<int>  *dodgeableSpells	 = new std::vector<int>;	//co the LAGGG vi tao nhieu con tro	
	std::vector<int>  *undodgeableSpells = new std::vector<int>;	//co the LAGGG vi tao nhieu con tro

	int posDangerLevel = 0;
	int posDangerCount = 0;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		undodgeableSpells->push_back(it_spells->first);

		int spellDangerLevel = spell.dangerlevel;

		posDangerLevel = max(posDangerLevel, spellDangerLevel);
		posDangerCount += spellDangerLevel;
	}

	Vec3D position(0,0,0);
	if(myHero) position = myHero->currentPos();

	PositionInfo* result = new PositionInfo(position , posDangerLevel, posDangerCount, true, 0, dodgeableSpells, undodgeableSpells);
	
	return result;
} 

//-------------------------------------------------//-----------------------//----------
bool isBetterMovePos(PositionInfo* newPosInfo)
{
	PositionInfo* posInfo = 0;
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

	std::vector<Vec3D> path = Unit_Path(myHero);	
	if((int)path.size() > 0)
	{
		Vec3D movePos = path.back();
		posInfo = CanHeroWalkToPos(movePos, myHero->nMoveSpeed, 0, 0, false);
	}
	else
	{
		posInfo = CanHeroWalkToPos(myHero->currentPos(), myHero->nMoveSpeed, 0, 0, false);
	}

	if (posInfo->posDangerCount < newPosInfo->posDangerCount)
	{
		return false;
	}

	return true;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* CompareLastMovePos(PositionInfo* newPosInfo)
{
	PositionInfo* posInfo = 0;
	KNpc* myHero = GetPlayer();
	if (!myHero) return posInfo;
	
	Vec3D movePos = myHero->currentPos();

	std::vector<Vec3D> path = Unit_Path(myHero);
	if ((int)path.size() > 0)
	{
		movePos = path.back();
	}
	posInfo = CanHeroWalkToPos(movePos, myHero->nMoveSpeed, 0, 0, false);

	if (posInfo->posDangerCount < newPosInfo->posDangerCount)
	{
		//__oMsg("xxxxxxxxxxxCompareLastMovePosxxxxxxxxxxxxxxxxxxxxxxx-1: posInfo: %x - newPosInfo: %x", posInfo, newPosInfo);
		return posInfo;
	}
	
	//__oMsg("xxxxxxxxxxxxxxxCompareLastMovePosxxxxxxxxxxxxxxxxxxx-2: posInfo: %x - newPosInfo: %x", posInfo, newPosInfo);
	return newPosInfo;
}