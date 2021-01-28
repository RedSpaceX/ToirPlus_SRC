#pragma once
#include "Utils.h"
#include "fucker.h"



//-----------------------------------------//-------------------------//

SpellSlot GetSummonerSlot(std::string spellName);
int       GetDefaultSpellMode(EvadeSpellData spell);
bool	  PreferEvadeSpell();
void	  UseEvadeSpell();
bool	  CompareEvadeOption(PositionInfo* posInfo, bool checkSpell = false);
bool	  ShouldActivateEvadeSpell(Spell spell);
bool	  ShouldUseMovementBuff(Spell spell);
int		  GetSpellDangerLevel_ES(EvadeSpellData evadeSpell);
bool	  ActivateEvadeSpell(Spell spell, bool checkSpell = false);