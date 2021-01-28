#pragma once
#include "Utils.h"
#include "fucker.h"



//---------------------------------------------------------------------//--------------------//
//void Evade_Soraka_Q();

//void Evade_Sion_E();

void Evade_Sion_R_and_Q();	//onTick

void Evade_Sion_E_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Sion_E_OCM(KNpc* missileObj, SpellData &spellData);

void Evade_Soraka_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Soraka_Q_OCM(KNpc* missileObj, SpellData &spellData);