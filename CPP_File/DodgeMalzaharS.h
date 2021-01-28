#pragma once
#include "Utils.h"
#include "fucker.h"



//------ 1 so Spell-ChieuNgang cho vao day ---------:
//---------------------------------------------------------------------//--------------------//
//void Evade_Malzahar_Q();

//void Evade_Velkoz_Q2();
//void Evade_Velkoz_W();
//void Evade_Velkoz_E();

//void Evade_Graves_Q2();
//void Evade_Graves_R2();	//Hinh non co gi do sai sai (can check lai)

void Evade_Graves_Q2_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);

void Evade_Malzahar_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);

void Evade_Velkoz_Q_1_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Velkoz_Q_1_OCM(KNpc* missileObj, SpellData &spellData);

void Evade_Velkoz_Q_2_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Velkoz_Q_2_OCM(KNpc* missileObj, SpellData &spellData);
