#pragma once
#include "Utils.h"
#include "fucker.h"


struct sphereQE
{
	Vec3D posQE;
	float timeSpawn;
};

void Load_HeroSpecial();
void Evade_SpellSpecial();	//OnTicj
void Special_OnProcessSpell(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Special_OnCreateMissile(KNpc* missileObj, SpellData &spellData);

void Test_misile();