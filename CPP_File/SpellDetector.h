#pragma once
#include "Utils.h"
#include "fucker.h"
#include "Spell.h"

//-----------------------------------------//-------------------------//
void	OnGameUpdate_SpellDetector();

void	CreateSpellData(KNpc* hero, Vec3D spellStartPos, Vec3D spellEndPos, SpellData spellData, KNpc* obj = 0, float extraEndTick = 0, bool processSpell = true,
					    SpellType spellType = None, bool checkEndExplosion = true, float spellRadius = 0);
int		CreateSpell(Spell &newSpell, bool processSpell = true);
void	DeleteSpell(int spellID);
int		GetCurrentSpellID();
std::vector<int>* GetSpellList();
int		GetHighestDetectedSpellID();
float	GetLowestEvadeTime(Spell &lowestSpell);
Spell	GetMostDangerousSpell(bool hasProjectile = false);

void	UpdateSpells();
void	CheckSpellEndTime();
void	CheckSpellCollision_SpD();
bool	CanHeroWalkIntoSpell(Spell spell);
void	AddDetectedSpells();
void	RemoveNonDangerousSpells();

void	OnProcessSpell_SpellDetector();

void	OnProcessSpell_2_SpellDetector(KNpc* hero, KCastSpell* spellCast);
void	OnProcessSpell_2_SpellDetector_Main(KNpc* hero, KCastSpell* spellCast);

void	OnCreate_SpellMissile();
