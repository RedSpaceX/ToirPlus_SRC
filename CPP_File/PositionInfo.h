#pragma once
#include "Utils.h"
#include "fucker.h"



PositionInfo* SetAllDodgeable();
PositionInfo* SetAllDodgeable(Vec3D position);

PositionInfo* SetAllUndodgeable();
bool		  isBetterMovePos(PositionInfo* newPosInfo);
PositionInfo* CompareLastMovePos(PositionInfo* newPosInfo);