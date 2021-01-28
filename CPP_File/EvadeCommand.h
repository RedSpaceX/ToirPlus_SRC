#pragma once
#include "Utils.h"
#include "fucker.h"





void	EC_MoveTo(Vec3D movePos, bool xxx = false);
void	EC_Attack(EvadeSpellData spellData, KNpc* target, bool xxx = false);
void	EC_CastSpell(EvadeSpellData* spellData, KNpc* target);
void	EC_CastSpell(EvadeSpellData* spellData, Vec3D movePos);
void	EC_CastSpell(EvadeSpellData* spellData);					//chac la cast_ban_than
