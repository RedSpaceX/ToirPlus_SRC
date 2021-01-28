#pragma once
#include "Utils.h"
#include "fucker.h"



//---------------------------------------------------------------------//--------------------//
//void Evade_Zed_Q();
//void Evade_Lulu_Q();

//void Evade_Ziggs_Q();
//void Evade_Zoe_Q2();

void Evade_Lulu_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Lulu_Q_OCM(KNpc* missileObj, SpellData &spellData);

void Evade_Zed_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Zed_Q_OCM(KNpc* missileObj, SpellData &spellData);

void Evade_Ziggs_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);
void Evade_Ziggs_Q_OCM(KNpc* missileObj, SpellData &spellData);

void Evade_Zoe_Q2_OCM(KNpc* missileObj, SpellData &spellData);