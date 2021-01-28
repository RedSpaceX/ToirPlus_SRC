#include "MathUtilsCPA.h"
#include "MathUtils.h"


float SMALL_NUM = 0.00000001f;
//-------------------------------------------------//-----------------------//----------
// cpa_time(): compute the time of CPA for two tracks
//    Input:  two tracks Tr1 and Tr2
//    Return: the time at which the two tracks are closest
float cpa_time(_Track Tr1, _Track Tr2)
{
	Vec3D dv = Tr1.v - Tr2.v;

	float dv2 = Dot2D(dv, dv);
	if (dv2 < SMALL_NUM)			// the  tracks are almost parallel
		return 0.0f;				// any time is ok.  Use time 0.

	Vec3D w0 = Tr1.P0 - Tr2.P0;
	float cpatime = -Dot2D(w0, dv) / dv2;

	return cpatime;             // time of CPA
}

//-------------------------------------------------//-----------------------//----------
float CPAPointsEx(Vec3D p1, Vec3D v1, Vec3D p2, Vec3D v2, Vec3D p1end, Vec3D p2end)
{
	_Track Tr1(p1, v1);
	_Track Tr2(p2, v2);

	float ctime = max(0, cpa_time(Tr1, Tr2));

	Vec3D P1 = Tr1.P0 + (Tr1.v * ctime);
	Vec3D P2 = Tr2.P0 + (Tr2.v * ctime);

	P1 = d(p1, P1) > d(p1, p1end) ? p1end : P1;
	P2 = d(p2, P2) > d(p2, p2end) ? p2end : P2;

	return d(P1, P2);
}

//-------------------------------------------------//-----------------------//----------
float CPAPointsEx(Vec3D p1, Vec3D v1, Vec3D p2, Vec3D v2, Vec3D p1end, Vec3D p2end,Vec3D &p1out, Vec3D &p2out)
{
	_Track Tr1(p1, v1);
	_Track Tr2(p2, v2);

	float ctime = cpa_time(Tr1, Tr2);

	if (ctime == 0)
	{
		bool  collision;
		float collisionTime = GetCollisionTime(p1, p2, v1, v2, 10, 10, collision);

		if (collision)
		{
			ctime = collisionTime;
		}               
	}

	Vec3D P1 = Tr1.P0 + (Tr1.v * ctime);
	Vec3D P2 = Tr2.P0 + (Tr2.v * ctime);

	//////P1 = d(p1, P1) > d(p1, p1end) ? p1end : P1;
	//////P2 = d(p2, P2) > d(p2, p2end) ? p2end : P2;

	p1out = P1;//////P1.ProjectOn(p1, p1end).SegmentPoint;//P1;
	p2out = P2;//////P2.ProjectOn(p2, p2end).SegmentPoint;

	return d(P1, P2);
}