//public static PositionInfo InitPositionInfo(Vector2 pos, float extraDelayBuffer, float extraEvadeDistance, Vector2 lastMovePos, Spell lowestEvadeTimeSpell) //clean this shit up
//{
//	var posInfo = CanHeroWalkToPos(pos, ObjectCache.myHeroCache.moveSpeed, extraDelayBuffer + ObjectCache.gamePing, extraDist);
//	posInfo.isDangerousPos = pos.CheckDangerousPos(6);
//	posInfo.hasExtraDistance = extraEvadeDistance > 0 ? pos.CheckDangerousPos(extraEvadeDistance) : false;// ? 1 : 0;            
//	posInfo.closestDistance = posInfo.distanceToMouse; //GetMovementBlockPositionValue(pos, lastMovePos);
//	posInfo.intersectionTime = GetMinCPADistance(pos);
//	//GetIntersectDistance(lowestEvadeTimeSpell, ObjectCache.myHeroCache.serverPos2D, pos);               
//	//GetClosestDistanceApproach(lowestEvadeTimeSpell, pos, ObjectCache.myHeroCache.moveSpeed, ObjectCache.gamePing, ObjectCache.myHeroCache.serverPos2D, 0);
//	posInfo.distanceToMouse = pos.GetPositionValue();
//}