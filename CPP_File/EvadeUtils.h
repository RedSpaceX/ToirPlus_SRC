#pragma once

#include "Utils.h"
//#include "Log.h"


class EvadeUtils
{
public:
	//public static Random random = new Random(DateTime.Now.Millisecond);
	//private static DateTime assemblyLoadTime = DateTime.Now;

	EvadeUtils()
	{

	}

	float TickCount()
	{
		return (float)GetTickCount();
	}
};


Vec3D GetGamePosition(KNpc* hero, float delay = 0);
std::vector<Vec3D> Cut_Path(std::vector<Vec3D> path, KNpc* unit, float delay, float speed = 0);
std::vector<Vec3D> Cut_Path(std::vector<Vec3D> path, float distance);
Vec3D ExtendDir(Vec3D pos, Vec3D dir, float distance);
