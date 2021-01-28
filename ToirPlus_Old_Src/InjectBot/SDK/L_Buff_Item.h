#pragma once


#include "LuaUtils.h"

int GetBuff(lua_State *L);
void SetTable_UpdateBuff(lua_State *L, KBuffs* pBuffs);
void SetTable_RemoveBuff(lua_State *L, KBuffs* pBuffs);

KItem* GetItemPointer(int iCount);
int GetItem(lua_State *L);
