#pragma once
#include "Utils.h"
#include "fucker.h"



//------ 1 so Spell-ThreeWay cho vao day ---------:
//---------------------------------------------------------------------//--------------------//
//void Evade_TwistedFate_Q();
//void Evade_Khazix_WLong();
//void Evade_Riven_R();


void Evade_TwistedFate_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);	//Tam-Thoi-Lam-OPS-Thoi
void Evade_Khazix_WLong_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);	//Tam-Thoi-Lam-OPS-Thoi
void Evade_Riven_R_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData);			//Tam-Thoi-Lam-OPS-Thoi

void Evade_TahmKench_W();	//phai dung o OnTick + pCastSpell va doi pCastSpell xuat hien vai` mili-second
