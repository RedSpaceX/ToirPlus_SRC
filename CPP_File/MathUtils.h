#pragma once
#include "Utils.h"



bool	CheckLineIntersection(Vec3D a, Vec3D b, Vec3D c, Vec3D d);
float	GetCollisionDistanceEx(Vec3D Pa, Vec3D Va, float Ra, Vec3D Pb, Vec3D Vb, float Rb, Vec3D &PA, Vec3D &PB);
float	GetCollisionTime(Vec3D Pa, Vec3D Pb, Vec3D Va, Vec3D Vb, float Ra, float Rb, bool &collision);