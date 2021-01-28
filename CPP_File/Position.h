#pragma once

#include "Utils.h"
#include "fucker.h"
#include "Spell.h"


bool	InSkillShot(Vec3D position, Spell spell, float radius, bool predictCollision = true);
bool	isLeftOfLineSegment(Vec3D pos, Vec3D start, Vec3D end);
float   GetDistanceToChampions(Vec3D pos);
bool	HasExtraAvoidDistance(Vec3D pos, float extraBuffer);
float	GetPositionValue(Vec3D pos);
bool	CheckDangerousPos(Vec3D pos, float extraBuffer, bool checkOnlyDangerous = false);