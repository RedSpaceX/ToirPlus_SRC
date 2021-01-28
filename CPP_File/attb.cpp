#include "attb.h"



bool isRecall(KNpc* unit)
{
	return unit == 0 ? false : ((BYTE)unit->nIsBasing == 6 ? true : false);
}

//------------------------------------------------------------------------------------------------//
bool isDead(KNpc* unit)
{
	return unit == 0 ? false : unit->isDead();
}