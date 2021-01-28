#pragma once


#include "LuaUtils.h"

int GetTypeObject(KNpc* pNpc);
float GetHitBox(KNpc* pNpc);

int GetADDamage(lua_State *L);
int GetAPDamage(lua_State *L);
int GetADDamage_000(lua_State *L);
int GetAPDamage_000(lua_State *L);

int GetPos(lua_State *L);		//chua can dung

int Get_CanCastSkill(lua_State *L);		//myHero
int Get_CanCastSkill_000(lua_State *L);		//otherHero

int Get_SpellState (lua_State *L);		//myHero. otherHero ko check dc
int Get_StackSpell(lua_State *L);		//(ammo)myHero. otherHero ko check dc
int Get_SpellToggle(lua_State *L);		//myHero
int Get_SpellCD(lua_State *L);			//myHero
int Get_LevelSkill(lua_State *L);		//myHero
int HasBuff(lua_State *L);
int HasBuffType(lua_State *L);

int Get_SpellState_2(lua_State *L);		//AllHero
int Get_StackSpell_2(lua_State *L);		//AllHero
int Get_SpellToggle_2(lua_State *L);	//AllHero
int Get_SpellCD_2(lua_State *L);		//AllHero
int Get_LevelSkill_2(lua_State *L);		//AllHero
int HasBuff_2(lua_State *L);
int HasBuffType_2(lua_State *L);

int HasItem(lua_State *L);//myHero
int HasItem_000(lua_State *L);//otherHero

int Get_WayPath(lua_State *L);
int Get_WayPath_000(lua_State *L);

int Get_WayPath_2(lua_State *L);
int Get_WayPath_000_2(lua_State *L);

int GetMyHero(lua_State *L);
int GetAIHero(lua_State *L);

