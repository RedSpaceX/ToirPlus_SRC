#pragma once

#include "Utils.h"
#include "fucker.h"


bool		  PlayerInSkillShot(Spell spell);
PositionInfo* InitPositionInfo(Vec3D pos, float extraDelayBuffer, float extraEvadeDistance, Vec3D lastMovePos, Spell lowestEvadeTimeSpell);

PositionInfo* GetBestPosition();
PositionInfo* GetBestPositionMovementBlock(Vec3D movePos);
PositionInfo* GetBestPositionBlink();
PositionInfo* GetBestPositionDash(EvadeSpellData spell);
PositionInfo* GetBestPositionTargetedDash(EvadeSpellData spell);
bool		  PositionInfoStillValid(PositionInfo* posInfo, float moveSpeed = 0);
Vec3D		  GetExtendedSafePosition(Vec3D from, Vec3D to, float extendDistance);
void		  CalculateEvadeTime();
Vec3D		  GetFastestPosition(Spell spell);
std::vector<Vec3D> GetFastestPositions();
float		  GetMinCPADistance(Vec3D movePos);

Vec3D		  GetNearWallPoint(Vec3D start, Vec3D end);

PositionInfo* CanHeroWalkToPos(Vec3D pos, float speed, float delay, float extraDist, bool useServerPosition = true);
float		  GetClosestDistanceApproach(Spell spell, Vec3D pos, float speed, float delay, Vec3D heroPos, float extraDist);
bool		  PredictSpellCollision(Spell spell, Vec3D pos, float speed, float delay, Vec3D heroPos, float extraDist, bool useServerPosition = true);
bool		  CheckPathCollision(KNpc* unit, Vec3D movePos);
bool		  CheckPointCollision(KNpc* unit, Vec3D movePos);
bool		  CheckMovePath(Vec3D movePos, float extraDelay = 0);
bool		  CheckMoveToDirection(Vec3D from, Vec3D movePos, float extraDelay = 0);