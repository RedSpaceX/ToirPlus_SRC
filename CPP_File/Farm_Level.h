#pragma once
#include "Combo/Combo.h"

bool IS_TEAM_1();
bool IS_TEAM_2();

KNpc* GET_ENEMY_TURRET(char* sz_HeroName, float nRange); // so voi diem Giua_ManHinh
KNpc* GET_ALLY_TURRET(char* sz_HeroName, float nRange);  // so voi diem Giua_ManHinh
KNpc* GET_ENEMY_INHIBITOR(float nRange);  // so voi diem Giua_ManHinh
KNpc* GET_ENEMY_NEXUS(float nRange);      // so voi diem Giua_ManHinh
void  DoEndGame();
bool  ADC_AUTO_UP_LEVEL();
bool  CHECK_AND_BUY_ITEM();


void Farm_Level();