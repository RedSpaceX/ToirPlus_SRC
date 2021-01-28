#pragma once


#include "LuaUtils.h"

int GetSpell(lua_State *L);

void SetTable_Spell_OnProcessSpell(lua_State *L, KCastSpell* pCastSpell);
void SetTable_Spell_OnDoCast(lua_State *L, KCastSpell* pCastSpell);
void SetTable_Spellbook_OnStopCast(lua_State *L, KCastSpell* pCastSpell);