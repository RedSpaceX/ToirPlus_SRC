#include "EvadeUtils.h"



//-------------------------------------------------//-----------------------//----------
Vec3D GetGamePosition(KNpc* hero, float delay)
{
	if (hero != 0)
	{
		if (IsMoving(hero))
		{
			std::vector<Vec3D> path;
			path.push_back(hero->currentPos());
			
			std::vector<Vec3D> unitPath = Unit_Path(hero);
			for (int i = 0; i < (int)unitPath.size(); i++)
			{
				path.push_back(unitPath[i]);
			}

			std::vector<Vec3D> finalPath = Cut_Path(path, hero, delay);

			return finalPath.back();
		}

		return hero->currentPos();
	}
	
	Vec3D Zero(0,0,0);
	return Zero;
}

//-------------------------------------------------//-----------------------//----------
std::vector<Vec3D> Cut_Path(std::vector<Vec3D> path, KNpc* unit, float delay, float speed)
{
	if (speed == 0)
	{
		speed = unit->nMoveSpeed;
	}

	float dist = speed * delay / 1000;
	return Cut_Path(path, dist);
}

//-------------------------------------------------//-----------------------//----------
std::vector<Vec3D> Cut_Path(std::vector<Vec3D> path, float distance)	//cut_path nay va cutpath(prediction) hoi khac nhau
{
	std::vector<Vec3D> result;
	float Distance = distance;

	if ((int)path.size() > 0)
	{
		result.push_back(path[0]);
	}

	for (int i = 0; i < (int)path.size() - 1; i++)
	{
		float dist = path[i].Distance2D(path[i + 1]);
		if (dist > Distance)
		{
			result.push_back(path[i] + (path[i + 1] - path[i]).Normalized() * Distance);
			break;
		}
		else
		{
			result.push_back(path[i + 1]);
		}
		Distance -= dist;
	}
	if((int)result.size() > 0) return result;

	result.push_back(path.back());
	return result;
}

//-------------------------------------------------//-----------------------//----------
Vec3D ExtendDir(Vec3D pos, Vec3D dir, float distance)
{
	return pos + dir * distance;
}