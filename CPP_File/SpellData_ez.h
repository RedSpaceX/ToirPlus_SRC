#pragma once
#include "Utils.h"

//enum SpellType
//{
//	Line,
//	Circular,
//	Cone,
//	Arc_x,
//	None
//};
//
//enum CollisionObjectType
//{
//	EnemyChampions,
//	EnemyMinions,
//	AllyYasuoWall,
//	None_1x,
//	None_2x,
//	None_3x
//};
//
//class SpellData //: ICloneable
//{  
//public:
//	std::string charName;
//	//SpellSlot spellKey = SpellSlot.Q
//	int spellKey;	//Q
//	int dangerlevel;
//	std::string spellName;
//	std::string name;
//	float range;
//	float radius;
//	float secondaryRadius;
//	float projectileSpeed;
//	std::string missileName;
//	SpellType spellType;
//	float spellDelay;
//	bool fixedRange;
//	bool useEndPosition;
//	float angle;
//	float sideRadius;
//	//public int splits; no idea when this was added xd
//	bool usePackets;
//	bool invert;
//	float extraDelay;
//	float extraDistance;
//	bool isThreeWay;
//	bool defaultOff;
//	bool noProcess;
//	bool isWall;
//	bool isPerpendicular;
//	float extraEndTime;
//	bool hasEndExplosion;
//	bool hasTrap;
//	bool isSpecial;
//	bool updatePosition;
//	float extraDrawHeight;
//	//std::string[] extraSpellNames = { };
//	//std::string[] extraMissileNames = { };
//	std::vector<CollisionObjectType>  collisionObjects;
//	std::string trapBaseName;
//	std::string trapTroyName;
//
//	SpellData()
//	{
//		spellKey = 0;	// _Q
//		dangerlevel = 1;
//		projectileSpeed = FLT_MAX;
//		missileName = "";
//		spellDelay = 250;
//		fixedRange = false;
//		useEndPosition = false;
//		usePackets = false;
//		invert = false;
//		extraDelay = 0;
//		extraDistance = 0;
//		isThreeWay = false;
//		defaultOff = false;
//		noProcess = false;
//		isWall = false;
//		isPerpendicular = false;
//		extraEndTime = 0;
//		hasEndExplosion = false;
//		hasTrap = false;
//		isSpecial = false;
//		updatePosition = true;
//		extraDrawHeight = 0;
//
//		trapBaseName = "";
//		trapTroyName = "";
//	}
//
//	SpellData(std::string charName, std::string spellName, std::string name, int range, int radius, int dangerlevel, SpellType spellType)
//	{
//		charName	 = charName;
//		spellName	 = spellName;
//		name		 = name;
//		range		 = range;
//		radius		 = radius;
//		dangerlevel  = dangerlevel;
//		spellType	 = spellType;
//	}
//
//	//public object Clone()
//	//{
//	//	return MemberwiseClone();
//	//}
//};