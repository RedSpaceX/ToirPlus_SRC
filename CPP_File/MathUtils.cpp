#include "MathUtils.h"



//-------------------------------------------------//-----------------------//----------
bool CheckLineIntersection(Vec3D a, Vec3D b, Vec3D c, Vec3D d)
{
	return Intersection(a, b, c, d).Intersects;
}

//-------------------------------------------------//-----------------------//----------
float GetCollisionDistanceEx(Vec3D Pa, Vec3D Va, float Ra,
							 Vec3D Pb, Vec3D Vb, float Rb, 
							 Vec3D &PA, Vec3D &PB)
{
	bool collision;
	float collisionTime = GetCollisionTime(Pa, Pb, Va, Vb, Ra, Rb, collision);

	if (collision)
	{
		PA = Pa + (Va * collisionTime);
		PB = Pb + (Vb * collisionTime);

		return PA.Distance2D(PB);
	}
	
	Vec3D vZezo(0,0,0);
	PA = vZezo;
	PB = vZezo;

	return FLT_MAX;
}

//-------------------------------------------------//-----------------------//----------
float GetCollisionTime(Vec3D Pa, Vec3D Pb, Vec3D Va, Vec3D Vb, float Ra, float Rb, bool &collision)
{
	Vec3D Pab = Pa - Pb;
	Vec3D Vab = Va - Vb;
	float a   = Dot2D(Vab, Vab);
	float b   = 2 * Dot2D(Pab, Vab);
	float c   = Dot2D(Pab, Pab) - (Ra + Rb) * (Ra + Rb);

	float discriminant = b * b - 4 * a * c;

	float t;
	if (discriminant < 0)
	{
		t = -b / (2 * a);
		collision = false;
	}
	else
	{
		float t0 = (-b + (float)sqrt(discriminant)) / (2 * a);
		float t1 = (-b - (float)sqrt(discriminant)) / (2 * a);

		if(t0 >= 0 && t1 >= 0)	t = min(t0, t1);
		else					t = max(t0, t1);

		if (t < 0)	collision = false;
		else		collision = true;
	}

	if (t < 0) t = 0;

	return t;
}