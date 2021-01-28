#pragma once
#include "Utils.h"

#include "fucker.h"



//-----------------------------------------//-------------------------//
float	GetSpellRadius(Spell spell);
int		GetSpellDangerLevel(Spell &spell);
bool	hasProjectile(Spell &spell);
Vec3D	GetSpellProjection(Spell &spell, Vec3D pos, bool predictPos = false);
Vec3D	GetCollisionAllyPos(Vec3D startPos, Vec3D endPos, float range, float Radius, float extraRadius, float extraResult);
KNpc*	CheckSpellCollision_Sp(Spell &spell, bool ignoreSelf = true);
float	GetSpellHitTime(Spell spell, Vec3D pos);
bool	CanHeroEvade(Spell spell, KNpc* hero, float &rEvadeTime, float &rSpellHitTime);

Vec3D	GetSpellEndPosition(Spell spell);
Vec3D	GetSpellEndPosition_forDraw(Spell spell, float fakeRange);
void	UpdateSpellInfo(Spell &spell);
Vec3D	GetCurrentSpellPosition(Spell &spell, bool allowNegative = false, float delay = 0, float extraDistance = 0);

bool	LineIntersectLinearSpell(Spell spell, Vec3D a, Vec3D b);

