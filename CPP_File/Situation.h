#pragma once
#include "Utils.h"
#include "fucker.h"


bool	CheckTeam(KNpc* unit);
bool	isNearEnemy(Vec3D pos, float distance, bool alreadyNear = true);

bool	ShouldDodge();
bool	ShouldUseEvadeSpell();
bool	CommonChecks();
bool	ChampionSpecificChecks();
bool	IsChannelingImportantSpell(KNpc* unit);
bool	HasSpellShield(KNpc* unit);








