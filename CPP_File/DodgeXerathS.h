#pragma once
#include "Utils.h"
#include "fucker.h"



//---------------------------------------------------------------------//--------------------//
void Evade_Xerath_Q_1(KNpc* hero, KCastSpell* spellCast, SpellData spellData);	//OnProcessSpell
void Evade_Xerath_Q_2();	//OnTick (FOW)
void Evade_Xerath_R(KNpc* missileObj, SpellData &spellData);

//void Evade_Xerath_W();	//FOW + ko FOW	(tam thoi ko lam FOW, FOW lam voi onCreate on? hon la search obj-dropFPS)


