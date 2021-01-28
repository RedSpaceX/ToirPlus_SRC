#pragma once
#include "Utils.h"



float	cpa_time(_Track Tr1, _Track Tr2);
float	CPAPointsEx(Vec3D p1, Vec3D v1, Vec3D p2, Vec3D v2, Vec3D p1end, Vec3D p2end);
float	CPAPointsEx(Vec3D p1, Vec3D v1, Vec3D p2, Vec3D v2, Vec3D p1end, Vec3D p2end,Vec3D &p1out, Vec3D &p2out);