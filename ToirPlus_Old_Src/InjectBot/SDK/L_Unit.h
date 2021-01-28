#pragma once


#include "LuaUtils.h"


int HasBuff_Unit(lua_State *L);
int Get_WayPath_Minion(lua_State *L);
int Get_WayPath_Minion_000(lua_State *L);

int GetAIMinion(lua_State *L);
int GetAIBarrack(lua_State *L);	// Nexus, Inbihitor
int GetMissile(lua_State *L);

void SetTableUnit(lua_State *L, KNpc* pUnit);// ham nay tam thoi ko dung

void SetTable_Unit_OnProcessSpell(lua_State *L, KNpc* pUnit);

void SetTable_UnitCreate(lua_State *L, KNpc* pUnit);

void SetTable_UnitDelete(lua_State *L, KNpc* pUnit);

void SetTable_SrcUnit_UpdateBuff(lua_State *L, KNpc* pUnit);
void SetTable_DestUnit_UpdateBuff(lua_State *L, KNpc* pUnit);

void SetTable_Unit_RemoveBuff(lua_State *L, KNpc* pUnit);

void SetTable_Unit_PlayAnimation(lua_State *L, KNpc* pUnit);

void SetTable_Target_OnBeforeAttack(lua_State *L, KNpc* pUnit);	//OnBeforeAttack

void SetTable_Unit_OnAttack  (lua_State *L, KNpc* pUnit);		//OnAttack
void SetTable_Target_OnAttack(lua_State *L, KNpc* pUnit);

void SetTable_Unit_OnAfterAttack  (lua_State *L, KNpc* pUnit);	//OnAfterAttack
void SetTable_Target_OnAfterAttack(lua_State *L, KNpc* pUnit);

void SetTable_Unit_OnDoCast(lua_State *L, KNpc* pUnit);
void SetTable_Unit_OnNewPath(lua_State *L, KNpc* pUnit);