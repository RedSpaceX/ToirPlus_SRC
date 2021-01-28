#pragma once

#include "Utils.h"

enum CastType
{
	_Position,
	_Target,
	_Self,
};

enum SpellTargets
{
	_AllyMinions,
	_EnemyMinions,
	_AllyChampions,
	_EnemyChampions,
	_Targetables,
	_Nonoe_Targetables,
};

enum EvadeType
{
	_Blink,
	_Dash,
	_Invulnerability,
	_MovementSpeedBuff,
	_Shield,
	_SpellShield,
	_WindWall,
};

enum EvadeOrderCommand
{
	Order_None_0 = 0,
	Order_None_1 = 1,
	Order_MoveTo = 2,
	Order_Attack = 3,
	Order_CastSpell = 4
};

enum SpellSlot
{
	Unknown_slot = -1,
	Q_slot = 0,
	W_slot = 1,
	E_slot = 2,
	R_slot = 3,
	Summoner1_slot = 4,
	Summoner2_slot = 5,
	Item1_slot = 6,
	Item2_slot = 7,
	Item3_slot = 8,
	Item4_slot = 9,
	Item5_slot = 10,
	Item6_slot = 11,
	Trinket_slot = 12,
	Recall_slot = 13,
	OathSworn_slot = 92,
	CapturePoint_slot = 94,
	Internal_slot = 10000
};

enum SpellType
{
	Line,
	Circular,
	Cone,
	Arc_x,
	None
};

enum CollisionObjectType
{
	EnemyChampions,
	EnemyMinions,
	AllyYasuoWall,
	None_1x,
	None_2x,
	None_3x
};


class SpellSetting 
{  
public:
	std::string NameMenu;					//Hien Name TA tren menu cho haway
	std::string key_spell;
	std::string key_spell_lower;

	std::string Hero_spell;					//"Lux Q Setting"	==> de tao menu cha
	std::string DrawSpell_Name;
	bool		DrawSpell;	
	std::string DodgeSpell_Name_Beta;		// dung cho spell beta(hoac cone) deo gi day
	bool		DodgeSpell_Beta;
	std::string DodgeSpell_Name;		
	bool		DodgeSpell;
	std::string SpellRadius_Name;		
	float		SpellRadius;
	std::string FastEvade_Name;				//Force Fast Evade
	bool		FastEvade;
	std::string DodgeIgnoreHP_Name;				
	float		DodgeIgnoreHP;				//float slider 100%
	std::string DangerLevel_Name;				
	int			DangerLevel;				//comboBox
	std::string	ReactionTime_Name;			//float slider
	float		ReactionTime;

//for--drawing----:
	//......

};

class SpellData //: ICloneable
{  
public:
	SpellSetting sSetting;

	std::string charName;
	//SpellSlot spellKey = SpellSlot.Q
	int spellKey;	//Q
	int dangerlevel;
	std::string spellName;
	std::string name;
	float range;
	float radius;
	float secondaryRadius;
	float projectileSpeed;
	std::string missileName;
	SpellType spellType;
	float spellDelay;
	bool fixedRange;
	bool useEndPosition;
	float EndPosMouse_add;			// dung cho 1 so con destPos=mousePos
	float angle;
	float sideRadius;
	//public int splits; no idea when this was added xd
	bool usePackets;
	bool invert;
	float extraDelay;
	float extraDistance;
	bool isThreeWay;
	bool defaultOff;
	bool noProcess;
	bool isWall;
	bool isPerpendicular;
	float extraEndTime;
	bool hasEndExplosion;
	bool hasTrap;
	bool isSpecial;
	bool isSpecial_00x;
	bool isSpecial_11x;
	bool isSpecial_22x;
	bool updatePosition;
	float extraDrawHeight;
	std::vector<std::string> extraSpellNames;			// de~ khoi tao hon
	std::vector<std::string> extraMissileNames;			// de~ khoi tao hon
	
	std::vector<CollisionObjectType>  collisionObjects; // de~ khoi tao hon
	std::string trapBaseName;
	std::string trapTroyName;
	
	float lastCastSpellTime;			// tu. them vao, tinh theo timeGame*1000 (ms)
	float lastCreateMissileTime;		// tu. them vao, tinh theo tickCount (ms)
	float missileDelay;					// tu. them vao, dung cho spell kha' nguy hiem tro len co missile, tang them chut delay de ne' kieu co' dam' an xoi
	float waitExtra;					// tu. them vao, them tgian doi. truoc khi can ne'
	SpellData()
	{
		spellKey = 0;	// _Q
		dangerlevel = 1;
		projectileSpeed = FLT_MAX;
		missileName = "";
		spellDelay = 250;
		fixedRange = false;
		useEndPosition = false;
		EndPosMouse_add  = 0;
		usePackets = false;
		invert = false;
		extraDelay = 0;
		extraDistance = 0;
		isThreeWay = false;
		defaultOff = false;
		noProcess = false;
		isWall = false;
		isPerpendicular = false;
		extraEndTime = 0;
		hasEndExplosion = false;
		hasTrap = false;
		isSpecial = false;
		isSpecial_00x = false;
		isSpecial_11x = false;
		isSpecial_22x = false;
		updatePosition = true;
		extraDrawHeight = 0;
		
		//extraSpellNames   = new std::vector<std::string>;
		//extraMissileNames = new std::vector<std::string>;

		trapBaseName = "";
		trapTroyName = "";

		lastCastSpellTime     = 0;
		lastCreateMissileTime = 0;
		missileDelay          = 0;
		waitExtra			  = 5;	//(ms), ==0 thi ko can doi
	}

	SpellData(std::string charName, std::string spellName, std::string name, int range, int radius, int dangerlevel, SpellType spellType)
	{
		charName	 = charName;
		spellName	 = spellName;
		name		 = name;
		range		 = range;
		radius		 = radius;
		dangerlevel  = dangerlevel;
		spellType	 = spellType;
	}

	//public object Clone()
	//{
	//	return MemberwiseClone();
	//}
};

class Spell
{
public:
	float startTime;
	float endTime;
	Vec3D startPos;
	Vec3D startPos_2; //dung cho missile-in-Fow va khi missileDelay>0
	Vec3D endPos;
	Vec3D direction;
	float height;
	int heroID;				//lay Index
	int projectileID;
	SpellData info;
	int spellID;
	KNpc* spellObject;
	SpellType spellType;

	Vec3D cnLeft;
	Vec3D cnRight;
	Vec3D cnStart;
	Vec3D currentSpellPosition;
	Vec3D currentNegativePosition;
	Vec3D predictedEndPos;

	float radius;			// default = 0
	int dangerlevel;		// default = 1

	float evadeTime;		// default = float.minvalue
	float spellHitTime;		// default = float.minvalue
	
	bool KoUpCurrentPos;	// tu them, neu da CreateSpell o OnProcessSpell, thi KoUpCurrentPos=true --> se~ ko update currentPos o GetCurrentPos()

	float nTest_1;
	Spell()
	{
		nTest_1 = 1000.0;
		//nTest_2 = 2000.0;

		spellObject = 0;
		Vec3D vZezo(0,0,0);
		currentSpellPosition    = vZezo;
		currentNegativePosition = vZezo;
		predictedEndPos         = vZezo;

		radius = 0;
		dangerlevel = 1;

		evadeTime    = FLT_MIN;
		spellHitTime = FLT_MIN;
		KoUpCurrentPos = false;
	}
	/*void Test_1()
	{
		this->nTest_1 = 1.0;
		this->nTest_2 = this->Test_2();
	}
	float Test_2()
	{
		this->nTest_2 = 2.0f;
		if (info.updatePosition == true)
		{
			return 3.0f;
		}
		return this->nTest_2;
	}*/
};


class SpellDetector
{
public:
	//public delegate void OnProcessDetectedSpellsHandler();
	//public static event OnProcessDetectedSpellsHandler OnProcessDetectedSpells;

	//public delegate void OnProcessSpecialSpellHandler(Obj_AI_Base hero, GameObjectProcessSpellCastEventArgs args,
	//	SpellData spellData, SpecialSpellEventArgs specialSpellArgs);
	//public static event OnProcessSpecialSpellHandler OnProcessSpecialSpell;

	//KNpc* myHero;

	std::map<int, Spell> *spells;
	std::map<int, Spell> *drawSpells;						//List Spell dang ban' -> can ve~
	std::map<int, Spell> *detectedSpells;					//List Spell dang ban' -> co the can ne'
	
	//public static Dictionary<string, ChampionPlugin> championPlugins = new Dictionary<string, ChampionPlugin>();

	std::map<std::string, std::string> channeledSpells;	// de the nay de~ khoi tao hon

	//public static Dictionary<string, SpellData> onProcessTraps = new Dictionary<string, SpellData>();

	std::map<std::string, SpellData> *onProcessSpells;		//List Spell can ne' trong tran
	std::map<std::string, SpellData> *onMissileSpells;		//List Missile can ne' trong tran

	//public static Dictionary<string, SpellData> windupSpells = new Dictionary<string, SpellData>();

	int spellIDCount;

	float lastCheckTime;
	float lastCheckSpellCollisionTime;
	float test_SpD;
	SpellDetector()
	{
		//myHero		   = GetPlayer();
		spellIDCount    = 0;

		spells		    = new std::map<int, Spell>;
		drawSpells      = new std::map<int, Spell>;
		detectedSpells  = new std::map<int, Spell>;
		
		//channeledSpells = new std::map<std::string, std::string>;

		onProcessSpells = new std::map<std::string, SpellData>;
		onMissileSpells = new std::map<std::string, SpellData>;

		lastCheckTime = 0;
		lastCheckSpellCollisionTime = 0;
		test_SpD = 1234.0f;
		//LoadSpellDictionary();
		//InitChannelSpells();
	}

//private:	
	//int spellIDCount;
};

class PositionInfo
{
public:
	//KNpc* myHero { get { return ObjectManager.Player; } }

	int posDangerLevel;
	int posDangerCount;
	bool isDangerousPos;
	float distanceToMouse;
	std::vector<int> *dodgeableSpells;
	std::vector<int> *undodgeableSpells;
	std::vector<int> *spellList;
	Vec3D position;
	float timestamp;
	float endTime;
	bool hasExtraDistance;
	float closestDistance;
	float intersectionTime;
	bool rejectPosition;
	float posDistToChamps;
	bool hasComfortZone;
	KNpc* target;
	bool recalculatedPath;
	float speed;

	PositionInfo()
	{
		posDangerLevel  = 0;
		posDangerCount  = 0;
		isDangerousPos  = false;
		distanceToMouse = 0;
		dodgeableSpells   = new std::vector<int>;
		undodgeableSpells = new std::vector<int>;
		spellList		  = new std::vector<int>;

		endTime = 0;
		hasExtraDistance = false;
		closestDistance  = FLT_MAX;
		intersectionTime = FLT_MAX;
		rejectPosition   = false;
		posDistToChamps  = FLT_MAX;
		hasComfortZone   = true;
		target			 = 0;
		recalculatedPath = false;
		speed			 = 0;
	}

	PositionInfo(Vec3D _position, int _posDangerLevel, int _posDangerCount, bool _isDangerousPos, float _distanceToMouse, std::vector<int> *_dodgeableSpells, std::vector<int> *_undodgeableSpells)
	{
		position		  = _position;
		posDangerLevel    = _posDangerLevel;
		posDangerCount    = _posDangerCount;
		isDangerousPos    = _isDangerousPos;
		distanceToMouse   = _distanceToMouse;
		dodgeableSpells	  = _dodgeableSpells;
		undodgeableSpells = _undodgeableSpells;
		timestamp		  = (float)GetTickCount();

		//------ them cai nay nua --
		endTime = 0;
		hasExtraDistance = false;
		closestDistance  = FLT_MAX;
		intersectionTime = FLT_MAX;
		rejectPosition   = false;
		posDistToChamps  = FLT_MAX;
		hasComfortZone   = true;
		target			 = 0;
		recalculatedPath = false;
		speed			 = 0;
	}

	PositionInfo(Vec3D _position, bool _isDangerousPos, float _distanceToMouse)
	{
		position		= _position;
		isDangerousPos	= _isDangerousPos;
		distanceToMouse = _distanceToMouse;
		timestamp		= (float)GetTickCount();

		//------ them cai nay nua --
		posDangerLevel  = 0;
		posDangerCount  = 0;
		dodgeableSpells   = new std::vector<int>;
		undodgeableSpells = new std::vector<int>;
		spellList		  = new std::vector<int>;
		endTime = 0;
		hasExtraDistance = false;
		closestDistance  = FLT_MAX;
		intersectionTime = FLT_MAX;
		rejectPosition   = false;
		posDistToChamps  = FLT_MAX;
		hasComfortZone   = true;
		target			 = 0;
		recalculatedPath = false;
		speed			 = 0;
	}

};

class EvadeSpellSetting
{
public:
	std::string NameMenu;						//charName - SpellNam (Q) EvadeSpellSetting

	std::string UseSpell_Name;				
	bool		UseSpell;	

	std::string EvadeSpellDangerLevel_Name;				
	int			EvadeSpellDangerLevel;			//comboBox

	std::string EvadeSpellMode_Name;				
	int			EvadeSpellMode;					//comboBox
};

class EvadeSpellData
{
public:
	EvadeSpellSetting esSetting;

	std::string charName;
	SpellSlot spellKey;
	int dangerlevel;
	std::string spellName;
	std::string name;
	bool checkSpellName;
	float spellDelay;
	float range;
	float speed;
	float speedArray[5];
	bool fixedRange;
	EvadeType evadeType;
	bool isReversed;
	bool behindTarget;
	bool infrontTarget;
	bool isSummonerSpell;
	bool isItem;
	int itemID;
	CastType castType;
	SpellTargets spellTargets[6];
	//UseSpellFunc useSpellFunc = null;
	bool isSpecial;
	bool untargetable;

	EvadeSpellData()
	{
		charName = "";
		spellKey = Q_slot;
		dangerlevel = 1;
		checkSpellName = false;
		spellDelay = 250;
		speed = 0;
		speedArray[0] = 0;
		speedArray[1] = 0;
		speedArray[2] = 0;
		speedArray[3] = 0;
		speedArray[4] = 0;
		spellTargets[0] = _Nonoe_Targetables;
		spellTargets[1] = _Nonoe_Targetables;
		spellTargets[2] = _Nonoe_Targetables;
		spellTargets[3] = _Nonoe_Targetables;
		spellTargets[4] = _Nonoe_Targetables;
		spellTargets[5] = _Nonoe_Targetables;
		fixedRange = false;
		isReversed = false;
		behindTarget = false;
		infrontTarget = false;
		isSummonerSpell = false;
		isItem = false;
		itemID = 0;
		castType = _Position;
		//UseSpellFunc useSpellFunc = null;
		isSpecial = false;
		untargetable = false;
	}

	EvadeSpellData(std::string _charName, std::string _name, SpellSlot _spellKey, EvadeType _evadeType, int _dangerlevel)
	{
		charName	= _charName;
		name		= _name;
		spellKey	= _spellKey;
		evadeType	= _evadeType;
		dangerlevel = _dangerlevel;

		checkSpellName = false;
		spellDelay = 250;
		speed = 0;
		speedArray[0] = 0;
		speedArray[1] = 0;
		speedArray[2] = 0;
		speedArray[3] = 0;
		speedArray[4] = 0;
		fixedRange = false;
		isReversed = false;
		behindTarget = false;
		infrontTarget = false;
		isSummonerSpell = false;
		isItem = false;
		itemID = 0;
		castType = _Position;
		//UseSpellFunc useSpellFunc = null;
		isSpecial = false;
		untargetable = false;
	}
};

typedef bool (*cb_UseSpellFunc)(EvadeSpellData, bool);

class EvadeCommand
{
	//private static Obj_AI_Hero myHero { get { return ObjectManager.Player; } }
public:
	EvadeOrderCommand order;
	Vec3D targetPosition;
	KNpc* target;
	float timestamp;
	bool isProcessed;
	EvadeSpellData* evadeSpellData;

	EvadeCommand()
	{
		evadeSpellData = new EvadeSpellData;
		timestamp	   = (float)GetTickCount();
		isProcessed    = false;
	}
};

class EvadeSpell
{
public:
	//delegate void Callback();

	std::vector<EvadeSpellData> *evadeSpells;
	std::vector<EvadeSpellData> *itemSpells;
	EvadeCommand *lastSpellEvadeCommand;

	EvadeSpell()
	{
		evadeSpells = new std::vector<EvadeSpellData>;
		itemSpells  = new std::vector<EvadeSpellData>;

		lastSpellEvadeCommand = new EvadeCommand;
		lastSpellEvadeCommand->isProcessed = true;
		lastSpellEvadeCommand->timestamp   = (float)GetTickCount();
	}
};

class Evade
{

public:
	KNpc* myHero()
	{ return GetPlayer(); }

	//public static SpellDetector spellDetector;
	//private static SpellDrawer spellDrawer;
	//private static EvadeTester evadeTester;
	//private static PingTester pingTester;
	//private static EvadeSpell evadeSpell;
	//private static SpellTester spellTester;
	//private static AutoSetPing autoSetPing;

	//public static SpellSlot lastSpellCast;

	float lastSpellCastTime;

	float lastWindupTime;

	float lastTickCount;
	float lastStopEvadeTime;

	Vec3D lastMovementBlockPos;
	float lastMovementBlockTime;

	float lastEvadeOrderTime;
	float lastIssueOrderGameTime;
	float lastIssueOrderTime;
	GameObjectIssueOrderEventArgs* lastIssueOrderArgs;

	Vec3D lastMoveToPosition;
	Vec3D lastMoveToServerPos;
	Vec3D lastStopPosition;

	//public static DateTime assemblyLoadTime = DateTime.Now;

	bool isDodging;
	bool dodgeOnlyDangerous;

	bool devModeOn;
	bool hasGameEnded;
	bool isChanneling;
	Vec3D channelPosition;

	PositionInfo* lastPosInfo;
	
	EvadeCommand* lastEvadeCommand;
	EvadeCommand* lastBlockedUserMoveTo;
	
	float lastDodgingEndTime;

	//public static Menu menu;

	float sumCalculationTime;
	float numCalculationTime;
	float avgCalculationTime;
	

	Evade()
	{
		//LoadAssembly();

		lastSpellCastTime = 0;
		lastWindupTime = 0;
		lastTickCount = 0;
		lastStopEvadeTime = 0;
		lastMovementBlockTime = 0;
		lastEvadeOrderTime = 0;
		lastIssueOrderGameTime = 0;
		lastIssueOrderTime = 0;
		lastIssueOrderArgs = 0;
		//public static DateTime assemblyLoadTime = DateTime.Now;

		isDodging = false;
		dodgeOnlyDangerous = false;
		devModeOn = false;
		hasGameEnded = false;
		isChanneling = false;

		lastPosInfo = new PositionInfo;

		lastEvadeCommand = new EvadeCommand;
		lastEvadeCommand->isProcessed = true;
		lastEvadeCommand->timestamp   = (float)GetTickCount();
			
		lastBlockedUserMoveTo = new EvadeCommand;
		lastBlockedUserMoveTo->isProcessed = true;
		lastBlockedUserMoveTo->timestamp   = (float)GetTickCount();

		lastDodgingEndTime = 0;
		sumCalculationTime = 0;
		numCalculationTime = 0;
		avgCalculationTime = 0;
	}

};

class EvadeHelper
{
public:
	bool fastEvadeMode;
	EvadeHelper()
	{
		fastEvadeMode = false;
	}
};




std::string str_tolower(std::string s);

float	BoundRadius(KNpc* unit);			//100.0f
float	BoundRadius_Minion(KNpc* unit);		//65.0f

void	InitClass_Evade();
bool	AllClassReady();
void	OnGameUpdate_DelayAction();
void	OnGameUpdate_ezEvade();
void	OnGameUpdate_ezEvade_4DRAWING();

void	LoadEvadeSpellList();
void	defaultValue_ListEvadeSpells();
void	setting_ListEvadeSpells_Menu();
void	setting_ListEvadeSpells_Menu_VN();
void	setting_ListEvadeSpells_Menu_CN();

void	LoadSpellDictionary();
void	InitChannelSpells();

void	defaultValue_ListSpellsEnemy();
void	setting_ListSpellsEnemy_Menu();
void	setting_ListSpellsEnemy_Menu_VN();
void	setting_ListSpellsEnemy_Menu_CN();

void	LoadSpellDatabaseFromIniFile();

class SpellDatabase
{
public:
	std::vector<SpellData> *vSpells;

	SpellDatabase()
	{
		vSpells = new std::vector<SpellData>;

//-- region AllChampions

		/*Spells.Add(
			new SpellData
		{
				charName = "AllChampions",
				dangerlevel = 1,
				missileName = "summonersnowball",
				name = "Mark",
				projectileSpeed = 1300,
				radius = 60,
				range = 1600,
				spellDelay = 0,
				spellKey = SpellSlot.Q,
				spellName = "summonersnowball",
				extraSpellNames = new[] { "summonerporothrow", },
				spellType = SpellType.Line,
				collisionObjects = new[] { CollisionObjectType.EnemyChampions, CollisionObjectType.EnemyMinions }
		});*/

	//-- endregion AllChampions

	//============== ## region Lux:
		//-------------------- Q:
		SpellData spd_1;
		spd_1.charName        = "Lux";
		spd_1.dangerlevel     = 3;
		spd_1.missileName     = "LuxLightBindingMis";
		spd_1.name            = "Light Binding";
		spd_1.projectileSpeed = 1200;
		spd_1.radius          = 70;
		spd_1.range           = 1300;
		spd_1.spellDelay      = 250;
		spd_1.spellKey        = _Q;
		spd_1.spellName       = "LuxLightBinding";
		spd_1.spellType       = Line;
		spd_1.fixedRange      = true;
		vSpells->push_back(spd_1);
		
		//-------------------- E:
		SpellData spd_2;
		spd_2.charName        = "Lux";
		spd_2.dangerlevel     = 2;
		spd_2.missileName     = "LuxLightStrikeKugel";
		spd_2.name            = "Lucent Singularity(E-1)";
		spd_2.projectileSpeed = 1300;
		spd_2.radius          = 315;					//game : 295, do < 310 thi trung, 311 ko trung, ko tinh boundRadius
		spd_2.range           = 1100;
		spd_2.spellDelay      = 250;
		//spd_2.extraEndTime    = 500;					//L#:500
		spd_2.spellKey        = _E1;
		spd_2.spellName       = "LuxLightStrikeKugel";
		spd_2.spellType       = Circular;
		vSpells->push_back(spd_2);
		
		////-------------------- E-2:
		//SpellData spd_3;
		//spd_3.charName        = "Lux";
		//spd_3.dangerlevel     = 2;
		//spd_3.name            = "Lucent Singularity(E-2)";
		//spd_3.radius          = 330;
		//spd_3.range           = 1100;
		//spd_3.spellDelay      = 250;
		//spd_3.spellKey        = _22;
		//spd_3.spellName       = "LuxLightStrikeKugel";
		//spd_3.spellType       = Circular;
		//spd_3.trapTroyName    = "lux_base_e_tar_aoe_" + Situation.EmitterColor() + ".troy";
		//spd_3.extraDrawHeight = -100;
		//spd_3.hasTrap		  = true;
		//vSpells->push_back(spd_3);
		
		//-------------------- R:
		SpellData spd_4;
		spd_4.charName        = "Lux";
		spd_4.dangerlevel     = 4;
		spd_4.missileName     = "LuxR_Ss";								//"LuxRVfxMis" this missile is detected too late	==> ko dung dc,xuat hien qua cham. (should : Lux_Base_R_mis_beam_middle, Lux_Base_R_mis_beam)
		spd_4.name            = "Final Spark";
		spd_4.projectileSpeed = FLT_MAX;
		spd_4.radius          = 190;
		spd_4.range           = 3300;
		spd_4.spellDelay      = 1000;
		spd_4.spellKey        = _R;
		spd_4.spellName       = "LuxMaliceCannonMis";					//L#: "LuxMaliceCannon";	
		spd_4.spellType       = Line;
		spd_4.fixedRange      = true;
		spd_4.isSpecial_22x   = true;									// ko ne' missile, ma ne theo MisBeam va Hiu rieng
		vSpells->push_back(spd_4);	
	//================================ ## End.region Lux =================================
	
		//============== ##region Thresh:
		//-------------------- Q:
		SpellData spd_5;
		spd_5.charName        = "Thresh";
		spd_5.dangerlevel     = 2;
		spd_5.missileName     = "ThreshQMissile";
		spd_5.name            = "Death Sentence";
		spd_5.projectileSpeed = 1900;								
		spd_5.radius          = 70;									
		spd_5.range           = 1200;
		spd_5.spellDelay      = 500;
		spd_5.missileDelay    = 0;									//tu them vao(chi dung voi skill nguy hiem)
		spd_5.spellKey        = _Q;
		spd_5.spellName       = "ThreshQ";							//L#: "ThreshQ";	//dung cai nay ko dc, sai data (ThreshQInternal ko dung dc)
		spd_5.spellType       = Line;
		spd_5.collisionObjects.push_back(EnemyMinions);
		spd_5.collisionObjects.push_back(EnemyChampions);
		spd_5.fixedRange      = true;
		spd_5.waitExtra       = 200;
		spd_5.isSpecial_00x   = true;		// [-Evade in OnProcessSpell-]
		spd_5.isSpecial_11x   = true;

		vSpells->push_back(spd_5);	

		//-------------------- E:
		SpellData spd_6;
		spd_6.charName        = "Thresh";
		spd_6.dangerlevel     = 3;
		spd_6.missileName     = "ThreshEMissile1xx";		// ko can ne' missile vi deo the nao ne dc
		spd_6.name            = "Flay";
		spd_6.projectileSpeed = 2000;								
		spd_6.radius          = 110;
		spd_6.range           = 550;						//L#: 1075
		spd_6.spellDelay      = 125;						//L#: 125, game: 388
		spd_6.spellKey        = _E;
		spd_6.spellName       = "ThreshE";	
		//spd_6.extraSpellNames.push_back("ThreshEFlay");		//L#: co' dung, deo hieu de lam gi
		spd_6.spellType       = Line;
		spd_6.fixedRange      = true;
		//spd_6.usePackets      = true;						//L#: co' dung, chac dung` ne' se~ nhanh hon
		spd_6.waitExtra       = 200;

		vSpells->push_back(spd_6);	
	//================================ ## End.region Thresh =================================
		
		//============== ##region Blitzcrank:
		//-------------------- Q:
		SpellData spd_7;
		spd_7.charName        = "Blitzcrank";
		spd_7.dangerlevel     = 3;
		spd_7.extraDelay	  = 75;									//ko thay dung trong code L#
		spd_7.missileName     = "RocketGrabMissile";
		spd_7.name            = "Rocket Grab";
		spd_7.projectileSpeed = 1800;								//L#: 1800
		spd_7.radius          = 70;									//L#: 70
		spd_7.range           = 1080;
		spd_7.spellDelay      = 250;
		spd_7.spellKey        = _Q;
		spd_7.spellName       = "RocketGrab";	
		//spd_7.extraSpellNames.push_back("RocketGrabMissile");		//L#: co' dung, deo hieu de lam gi
		spd_7.spellType       = Line;
		spd_7.collisionObjects.push_back(EnemyMinions);
		spd_7.collisionObjects.push_back(EnemyChampions);
		spd_7.fixedRange      = true;
		vSpells->push_back(spd_7);
		
		//-------------------- R:
		SpellData spd_8;
		spd_8.charName        = "Blitzcrank";
		spd_8.dangerlevel     = 2;
		spd_8.defaultOff      = true;
		spd_8.missileName     = "Blitz_NO";
		spd_8.name            = "StaticField";	
		spd_8.projectileSpeed = 0;
		spd_8.radius          = 600;									
		spd_8.range           = 600;
		spd_8.spellDelay      = 200;								//L#: 250
		spd_8.spellKey        = _R;
		spd_8.spellName       = "StaticField";	
		spd_8.spellType       = Circular;
		vSpells->push_back(spd_8);
	
	//================================ ## End.region Blitzcrank =================================

	//============== ##region Ryze:
		//-------------------- Q:
		SpellData spd_9;
		spd_9.charName        = "Ryze";
		spd_9.dangerlevel     = 2;
		spd_9.missileName     = "RyzeQ";
		spd_9.name            = "Overload";
		spd_9.projectileSpeed = 1700;								
		spd_9.radius          = 60;									
		spd_9.range           = 900;
		spd_9.spellDelay      = 250;
		spd_9.spellKey        = _Q;
		spd_9.spellName       = "RyzeQ";	
		spd_9.spellType       = Line;
		spd_9.collisionObjects.push_back(EnemyMinions);
		spd_9.collisionObjects.push_back(EnemyChampions);
		spd_9.fixedRange      = true;
		vSpells->push_back(spd_9);

	//================================ ## End.region Ryze =================================

	//============== ##region Ezreal:
		//-------------------- Q:
		SpellData spd_10;
		spd_10.charName        = "Ezreal";
		spd_10.dangerlevel     = 2;
		spd_10.missileName     = "EzrealQ";
		spd_10.name            = "Mystic Shot";
		spd_10.projectileSpeed = 2000;								
		spd_10.radius          = 55;									//L#: 60							
		spd_10.range           = 1200;
		spd_10.spellDelay      = 250;
		spd_10.spellKey        = _Q;
		spd_10.spellName       = "EzrealQ";	
		spd_10.spellType       = Line;
		spd_10.collisionObjects.push_back(EnemyMinions);
		spd_10.collisionObjects.push_back(EnemyChampions);
		//spd_10.extraSpellNames.push_back("ezrealmysticshotwrapper");				//L#: co' dung, deo hieu de lam gi
		//spd_10.extraMissileNames.push_back("EzrealMysticShotPulseMissile");		//L#: co' dung, deo hieu de lam gi
		vSpells->push_back(spd_10);
		
		//-------------------- W:
		SpellData spd_11;
		spd_11.charName        = "Ezreal";
		spd_11.dangerlevel     = 1;
		spd_11.missileName     = "EzrealW";
		spd_11.name            = "Essence Flux";
		spd_11.projectileSpeed = 1600;								
		spd_11.radius          = 65;									//L#: 80								
		spd_11.range           = 1050;
		spd_11.spellDelay      = 250;
		spd_11.spellKey        = _W;
		spd_11.spellName       = "EzrealW";	
		spd_11.spellType       = Line;
		vSpells->push_back(spd_11);

		//-------------------- R:
		SpellData spd_12;
		spd_12.charName        = "Ezreal";
		spd_12.dangerlevel     = 2;
		spd_12.missileName     = "EzrealR";
		spd_12.name            = "Trueshot Barrage";
		spd_12.projectileSpeed = 2000;								
		spd_12.radius          = 160;									
		spd_12.range           = 20000;
		spd_12.spellDelay      = 1000;
		spd_12.spellKey        = _R;
		spd_12.spellName       = "EzrealR";	
		spd_12.spellType       = Line;
		spd_12.waitExtra	   = 0;		//==0 la ne' luon khi thay dan.
		vSpells->push_back(spd_12);	

	//================================ ## End.region Ezreal =================================

	//============== ##region Morgana:
		//-------------------- Q:
		SpellData spd_13;
		spd_13.charName        = "Morgana";
		spd_13.dangerlevel     = 3;
		spd_13.missileName     = "MorganaQ";
		spd_13.name            = "Dark Binding";
		spd_13.projectileSpeed = 1200;								
		spd_13.radius          = 80;																
		spd_13.range           = 1300;
		spd_13.spellDelay      = 250;
		spd_13.missileDelay    = 50;
		spd_13.spellKey        = _Q;
		spd_13.spellName       = "MorganaQ";	
		spd_13.spellType       = Line;
		spd_13.collisionObjects.push_back(EnemyMinions);
		spd_13.collisionObjects.push_back(EnemyChampions);
		spd_13.fixedRange      = true;
		vSpells->push_back(spd_13);
		
		////-------------------- W:(.troy) - lam sau
		//SpellData spd_14;
		//spd_14.charName        = "Morgana";
		//spd_14.dangerlevel     = 1;						//L#: 2
		//spd_14.name            = "Tormented Soil";							
		//spd_14.radius          = 279;																
		//spd_14.range           = 1300;
		//spd_14.spellKey        = _W;
		//spd_14.spellName       = "TormentedSoil";	
		//spd_14.spellType       = Circular;
		//trapTroyName = "morgana_base_w_tar_" + Situation.EmitterColor() + ".troy",
		//spd_14.spellType      = true;
		//vSpells->push_back(spd_14);
	//================================ ## End.region Morgana =================================
			
	//============== ##region LeeSin:
		//-------------------- Q:
		SpellData spd_15;
		spd_15.charName        = "LeeSin";
		spd_15.dangerlevel     = 3;
		spd_15.missileName     = "BlindMonkQOne";
		spd_15.name            = "Sonic Wave";
		spd_15.projectileSpeed = 1800;								
		spd_15.radius          = 60;																
		spd_15.range           = 1200;
		spd_15.spellDelay      = 250;
		spd_15.missileDelay    = 35;
		spd_15.spellKey        = _Q;
		spd_15.spellName       = "BlindMonkQOne";	
		spd_15.spellType       = Line;
		spd_15.collisionObjects.push_back(EnemyMinions);
		spd_15.collisionObjects.push_back(EnemyChampions);
		spd_15.fixedRange      = true;
		vSpells->push_back(spd_15);
	//================================ ## End.region LeeSin =================================	
	
	//============== ##region Kalista:
		//-------------------- Q:
		SpellData spd_16;
		spd_16.charName        = "Kalista";
		spd_16.dangerlevel     = 2;
		spd_16.missileName     = "KalistaMysticShotMisTrue";		//L#: "kalistamysticshotmis";
		spd_16.name            = "Pierce";
		spd_16.projectileSpeed = 2000;								//L#: 1700
		spd_16.radius          = 45;																
		spd_16.range           = 1200;
		spd_16.spellDelay      = 250;
		spd_16.spellKey        = _Q;
		spd_16.spellName       = "KalistaMysticShot";	
		//spd_16.extraMissileNames.push_back("kalistamysticshotmistrue");;
		spd_16.spellType       = Line;
		spd_16.collisionObjects.push_back(EnemyMinions);
		spd_16.collisionObjects.push_back(EnemyChampions);
		spd_16.fixedRange      = true;
		vSpells->push_back(spd_16);
	//================================ ## End.region Kalista =================================
	
	//============== ##region Sivir:
		//-------------------- Q:
		SpellData spd_17;
		spd_17.charName        = "Sivir";
		spd_17.dangerlevel     = 2;
		spd_17.missileName     = "SivirQMissile";	
		//spd_17.extraMissileNames.push_back("SivirQMissileReturn");	//bo cai return di, co the gay loi~
		spd_17.name            = "Boomerang Blade";
		spd_17.projectileSpeed = 1350;
		spd_17.radius	       = 100;
		spd_17.range	       = 1275;
		spd_17.spellDelay      = 250;
		spd_17.spellKey        = _Q;
		spd_17.spellName       = "SivirQ";	
		//spd_17.extraMissileNames.push_back("SivirQReturn");		//chac dung cho ban? detour dc ham`
		spd_17.spellType       = Line;
		spd_17.fixedRange      = true;
		vSpells->push_back(spd_17);
	//================================ ## End.region Sivir =================================
		
	//============== ##region Jinx:
		//-------------------- W:
		SpellData spd_18;
		spd_18.charName        = "Jinx";
		spd_18.dangerlevel     = 3;
		spd_18.missileName     = "JinxW_Special";	//L#: "JinxWMissile" -->cai nay ko ne' dc vi toc do qua nhanh, chac phai ne = .troy(lamSau)	
		spd_18.name            = "Zap!";
		spd_18.projectileSpeed = 3300;
		spd_18.radius	       = 60;
		spd_18.range	       = 1500;
		spd_18.spellDelay      = 600;
		spd_18.spellKey        = _W;
		spd_18.spellName       = "JinxWMissile";	
		spd_18.spellType       = Line;
		spd_18.collisionObjects.push_back(EnemyMinions);
		spd_18.collisionObjects.push_back(EnemyChampions);
		spd_18.fixedRange      = true;
		vSpells->push_back(spd_18);

		////-------------------- E:
		//SpellData spd_19;
		//spd_19.charName        = "Jinx";
		//spd_19.dangerlevel     = 3;
		////-//spd_19.missileName = "JinxEHit";	
		//spd_19.name            = "Flame Chompers!";
		////-//spd_19.projectileSpeed = 2300;
		//spd_19.radius	       = 120;
		//spd_19.range	       = 900;
		//spd_19.spellDelay      = 1200;
		//spd_19.spellKey        = _E;
		//spd_19.spellName       = "JinxE";				//ko vao voi ban pCastSpell
		//spd_19.spellType       = Circular;
		//spd_19.hasTrap		   = true;
		//spd_19.trapBaseName.push_back("jinxmine");
		//spd_19.updatePosition  = false;
		//vSpells->push_back(spd_19);

		//-------------------- R:
		SpellData spd_20;
		spd_20.charName        = "Jinx";
		spd_20.dangerlevel     = 3;	
		spd_20.missileName     = "JinxR";						//L# ko co, chac missileNam trung spellName nen ko cho vao
		spd_20.name            = "Super Mega Death Rocket!";	
		spd_20.projectileSpeed = 2200;
		spd_20.radius	       = 140;
		spd_20.range	       = 20000;
		spd_20.spellDelay      = 600;
		spd_20.spellKey        = _R;
		spd_20.spellName       = "JinxR";	
		spd_20.spellType       = Line;
		//spd_20.extraMissileNames.push_back("JinxRWrapper");
		spd_20.fixedRange      = true;
		spd_20.waitExtra	   = 0;		//==0 la ne' luon khi thay dan.
		vSpells->push_back(spd_20);
	//================================ ## End.region Jinx =================================
	
		//============== ##region Jhin:
		//-------------------- W:
		SpellData spd_21;
		spd_21.charName        = "Jhin";
		spd_21.dangerlevel     = 3;
		spd_21.missileName     = "JhinW_NO";			//L#: there is NO missile -->cai nay ko ne' dc vi toc do qua nhanh, chac phai ne = .troy(lamSau)	
		spd_21.name            = "Deadly Flourish";
		spd_21.projectileSpeed = 7500;						//L# : FLT_MAX: se~ bi createSpell 2lan vi pCastSpell ton tai 900ms, va delete qua nhanh
		spd_21.radius	       = 40;
		spd_21.range		   = 2625;						//L#: 2550
		spd_21.spellDelay      = 650;
		spd_21.spellKey        = _W;
		spd_21.spellName       = "JhinW";	
		spd_21.spellType       = Line;
		spd_21.collisionObjects.push_back(EnemyChampions);
		spd_21.fixedRange      = true;
		vSpells->push_back(spd_21);

		//-------------------- R:
		SpellData spd_22;
		spd_22.charName        = "Jhin";
		spd_22.dangerlevel     = 2;	
		spd_22.missileName     = "JhinRShotMis";	
		spd_22.extraMissileNames.push_back("JhinRShotMis4");
		spd_22.name            = "Curtain Call";	
		spd_22.projectileSpeed = 5000;
		spd_22.radius	       = 80;
		spd_22.range	       = 3500;
		spd_22.spellDelay      = 250;
		spd_22.spellKey        = _R;
		spd_22.spellName       = "JhinRShot_kodungdc";					//chac ko vao cai nay, vi ko co pCastSpell
		spd_22.spellType       = Line;
		spd_22.collisionObjects.push_back(EnemyChampions);
		spd_22.waitExtra	   = 0;		//==0 la ne' luon khi thay dan.
		vSpells->push_back(spd_22);
	//================================ ## End.region Jhin =================================
		
	//============== ##region Quinn:
		//-------------------- Q:
		SpellData spd_23;
		spd_23.charName        = "Quinn";
		spd_23.dangerlevel     = 3;
		spd_23.missileName     = "QuinnQ";	
		spd_23.name            = "Blinding Assault";
		spd_23.projectileSpeed = 1550;						
		spd_23.radius	       = 60;
		spd_23.range		   = 1050;						
		spd_23.spellDelay      = 250;
		spd_23.spellKey        = _Q;
		spd_23.spellName       = "QuinnQ";	
		spd_23.spellType       = Line;
		spd_23.collisionObjects.push_back(EnemyMinions);
		spd_23.collisionObjects.push_back(EnemyChampions);
		spd_23.fixedRange      = true;
		vSpells->push_back(spd_23);
	//================================ ## End.region Quinn =================================
		
	//============== ##region Kennen:
		//-------------------- Q:
		SpellData spd_24;
		spd_24.charName        = "Kennen";
		spd_24.dangerlevel     = 2;
		spd_24.missileName     = "KennenShurikenHurlMissile1";	
		spd_24.name            = "Thundering Shuriken";
		spd_24.projectileSpeed = 1700;						
		spd_24.radius	       = 50;
		spd_24.range		   = 1050;						
		spd_24.spellDelay      = 150;						//L#: 125
		spd_24.spellKey        = _Q;
		spd_24.spellName       = "KennenShurikenHurlMissile1";	
		spd_24.spellType       = Line;
		spd_24.collisionObjects.push_back(EnemyMinions);
		spd_24.collisionObjects.push_back(EnemyChampions);
		spd_24.fixedRange      = true;
		vSpells->push_back(spd_24);
	//================================ ## End.region Kennen =================================
	
	//============== ##region Karthus:
		//-------------------- Q:
		SpellData spd_25;
		spd_25.charName        = "Karthus";
		spd_25.dangerlevel     = 2;
		spd_25.missileName     = "KoCo_MissileName";	
		spd_25.name            = "Lay Waste";						
		spd_25.radius	       = 200;						//game : 160, do < 200 thi trung, 201 ko trung, ko tinh boundRadius
		spd_25.range		   = 875;						
		spd_25.spellDelay      = 800;						//L#: 625 ( 250 delay + 500 se no?)					
		spd_25.spellKey        = _Q;
		spd_25.spellName       = "KarthusLayWasteA1";	
		spd_25.spellType       = Circular;
		spd_25.extraSpellNames.push_back("karthuslaywastea2");
		spd_25.extraSpellNames.push_back("karthuslaywastea3");
		spd_25.extraSpellNames.push_back("karthuslaywastedeada1");
		spd_25.extraSpellNames.push_back("karthuslaywastedeada2");
		spd_25.extraSpellNames.push_back("karthuslaywastedeada3");
		vSpells->push_back(spd_25);
	//================================ ## End.region Karthus =================================
	
	//============== ##region Ashe:
		//-------------------- R:
		SpellData spd_26;
		spd_26.charName        = "Ashe";
		spd_26.dangerlevel     = 3;
		spd_26.missileName     = "EnchantedCrystalArrow";	
		spd_26.name            = "Enchanted Crystal Arrow";	
		spd_26.projectileSpeed = 1600;
		spd_26.radius	       = 130;
		spd_26.range		   = 20000;						
		spd_26.spellDelay      = 250;											
		spd_26.spellKey        = _R;
		spd_26.spellName       = "EnchantedCrystalArrow";	
		spd_26.spellType       = Line;
		spd_26.waitExtra	   = 0;		//==0 la ne' luon khi thay dan.
		vSpells->push_back(spd_26);

		////-------------------- W:
		//SpellData spd_27;
		//spd_27.charName        = "Ashe";
		//spd_27.dangerlevel     = 1;
		////spd_27.missileName     = "VolleyAttack";	
		//spd_27.name            = "Volley";	
		//spd_27.projectileSpeed = 1500;
		//spd_27.radius	       = 20;
		//spd_27.range		   = 1350;						
		//spd_27.spellDelay      = 250;										
		//spd_27.spellKey        = _W;
		//spd_27.spellName       = "Volley";	
		//spd_27.spellType       = Line;
		//spd_27.collisionObjects.push_back(EnemyMinions);
		//spd_27.collisionObjects.push_back(EnemyChampions);
		//spd_27.isSpecial	   = true;
		//vSpells->push_back(spd_27);
	//================================ ## End.region Ashe =================================
		
	//============== ##region Caitlyn:
		//-------------------- Q:
		SpellData spd_28;
		spd_28.charName        = "Caitlyn";
		spd_28.dangerlevel     = 2;
		spd_28.missileName     = "CaitlynPiltoverPeacemaker";		//L#: ko thay no ghi
		spd_28.name            = "Piltover Peacemaker";	
		spd_28.projectileSpeed = 2200;
		spd_28.radius	       = 90;
		spd_28.range		   = 1300;						
		spd_28.spellDelay      = 625;											
		spd_28.spellKey        = _Q;
		spd_28.spellName       = "CaitlynPiltoverPeacemaker";	
		spd_28.spellType       = Line;
		vSpells->push_back(spd_28);

		////-------------------- W:
		//SpellData spd_29;
		//spd_29.charName        = "Caitlyn";
		//spd_29.dangerlevel     = 3;
		//spd_29.missileName     = "xxxxCaitlynTrap";	
		//spd_29.name            = "Yordle Trap";	
		//spd_29.radius	       = 75;
		//spd_29.range		   = 800;																
		//spd_29.spellKey        = _W;
		//spd_29.spellName       = "CaitlynYordleTrap";	
		//spd_29.trapBaseName.push_back("CaitlynTrap");
		//spd_29.spellType       = Circular;
		//spd_29.hasTrap	   = true;
		//vSpells->push_back(spd_29);

		//-------------------- E:
		SpellData spd_30;
		spd_30.charName        = "Caitlyn";
		spd_30.dangerlevel     = 3;
		spd_30.missileName     = "CaitlynEntrapmentMissile";		
		spd_30.name            = "90 Caliber Net";	
		spd_30.projectileSpeed = 2000;
		spd_30.radius	       = 80;
		spd_30.range		   = 875;					//L#: 950				
		spd_30.spellDelay      = 125;											
		spd_30.spellKey        = _E;
		spd_30.spellName       = "CaitlynEntrapment";	
		spd_30.spellType       = Line;
		spd_30.collisionObjects.push_back(EnemyMinions);
		spd_30.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_30);
	//================================ ## End.region Caitlyn =================================
	
	//============== ##region Amumu:
		//-------------------- R:
		SpellData spd_31;
		spd_31.charName        = "Amumu";
		spd_31.dangerlevel     = 4;
		spd_31.missileName     = "abcxxxx";							//L#: ko thay no ghi
		spd_31.name            = "Curse of the Sad Mummy";	
		spd_31.projectileSpeed = 0;
		spd_31.radius	       = 555;								//game : 550, do < 550 thi trung, 551 ko trung, ko tinh boundRadius
		spd_31.range		   = 555;						
		spd_31.spellDelay      = 250;											
		spd_31.spellKey        = _R;
		spd_31.spellName       = "CurseoftheSadMummy";	
		spd_31.spellType       = Circular;
		vSpells->push_back(spd_31);

		//-------------------- Q:
		SpellData spd_32;
		spd_32.charName        = "Amumu";
		spd_32.dangerlevel     = 3;
		spd_32.missileName     = "SadMummyBandageToss";			//L#: Bandage Toss
		spd_32.name            = "Bandage Toss";	
		spd_32.projectileSpeed = 2000;
		spd_32.radius	       = 80;
		spd_32.range		   = 1100;									
		spd_32.spellDelay      = 250;											
		spd_32.spellKey        = _Q;
		spd_32.spellName       = "BandageToss";	
		spd_32.spellType       = Line;
		spd_32.collisionObjects.push_back(EnemyMinions);
		spd_32.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_32);
	//================================ ## End.region Amumu =================================
		
	//============== ##region KogMaw:
		//-------------------- Q:
		SpellData spd_33;
		spd_33.charName        = "KogMaw";
		spd_33.dangerlevel     = 2;
		spd_33.missileName     = "KogMawQ";							
		spd_33.name            = "Caustic Spittle";	
		spd_33.projectileSpeed = 1650;
		spd_33.radius	       = 70;
		spd_33.range		   = 1200;						
		spd_33.spellDelay      = 250;											
		spd_33.spellKey        = _Q;
		spd_33.spellName       = "KogMawQ";	
		spd_33.spellType       = Line;
		spd_33.collisionObjects.push_back(EnemyMinions);
		spd_33.collisionObjects.push_back(EnemyChampions);
		spd_33.fixedRange	   = true;
		vSpells->push_back(spd_33);

		//-------------------- E:
		SpellData spd_34;
		spd_34.charName        = "KogMaw";
		spd_34.dangerlevel     = 2;
		spd_34.missileName     = "KogMawVoidOozeMissile";		
		spd_34.name            = "Void Ooze";	
		spd_34.projectileSpeed = 1350;					//L#: 1350
		spd_34.radius	       = 120;					//L#: 120
		spd_34.range		   = 1360;									
		spd_34.spellDelay      = 250;											
		spd_34.spellKey        = _E;
		spd_34.spellName       = "KogMawVoidOoze";	
		spd_34.spellType       = Line;
		spd_34.fixedRange	   = true;
		vSpells->push_back(spd_34);

		//-------------------- R:
		SpellData spd_35;
		spd_35.charName        = "KogMaw";
		spd_35.dangerlevel     = 2;
		spd_35.missileName     = "KogMawLivingArtillery";		
		spd_35.name            = "Living Artillery";	
		spd_35.projectileSpeed = FLT_MAX;
		spd_35.radius	       = 245;					//L#: 235
		spd_35.range		   = 2200;									
		spd_35.spellDelay      = 1200;					//L#: 1100						
		spd_35.spellKey        = _R;
		spd_35.spellName       = "KogMawLivingArtillery";	
		spd_35.spellType       = Circular;
		vSpells->push_back(spd_35);
	//================================ ## End.region KogMaw =================================
		
	//============== ##region Leona:
		//-------------------- R:
		SpellData spd_37;
		spd_37.charName        = "Leona";
		spd_37.dangerlevel     = 4;
		spd_37.missileName     = "LeonaSolarFlare";		//Perks_ArcaneComet_Mis: du lieu cham	
		spd_37.name            = "Solar Flare";	
		spd_37.projectileSpeed = FLT_MAX;
		spd_37.radius	       = 250;					//game : 250, do < 325 thi trung, 326 ko trung, vong trong = 175(gay choang), ko tinh boundRadius
		spd_37.range		   = 1200;									
		spd_37.spellDelay      = 675;					//L#: 625 . cast=0.25, time no? = 0.625									
		spd_37.spellKey        = _R;
		spd_37.spellName       = "LeonaSolarFlare";	
		spd_37.spellType       = Circular;
		spd_37.waitExtra	   = 0;
		vSpells->push_back(spd_37);

		//-------------------- E:
		SpellData spd_36;
		spd_36.charName        = "Leona";
		spd_36.dangerlevel     = 3;
		//spd_36.extraDistance = 65;
		spd_36.missileName     = "LeonaZenithBladeMissile";							
		spd_36.name            = "Zenith Blade";	
		spd_36.projectileSpeed = 2000;					//L#: 2000
		spd_36.radius	       = 70;
		spd_36.range		   = 875;						
		spd_36.spellDelay      = 250;					//L#: 200
		spd_36.spellKey        = _E;
		spd_36.spellName       = "LeonaZenithBlade";	
		spd_36.spellType       = Line;
		spd_36.fixedRange	   = true;
		spd_36.waitExtra	   = 0;
		vSpells->push_back(spd_36);
	//================================ ## End.region Leona =================================
		
	//============== ##region Lulu:
		//-------------------- Q:
		SpellData spd_38;
		spd_38.charName        = "Lulu";
		spd_38.dangerlevel     = 2;
		spd_38.missileName     = "LuluQMissile";					//dan chinh						
		spd_38.extraMissileNames.push_back("LuluQMissileTwo");		//dan con pix			
		spd_38.name            = "Glitterlance";	
		spd_38.projectileSpeed = 1450;
		spd_38.radius	       = 60;
		spd_38.range		   = 950;						
		spd_38.spellDelay      = 250;											
		spd_38.spellKey        = _Q;
		spd_38.spellName       = "LuluQ";							//"LuluQ"
		spd_38.spellType       = Line;	
		spd_38.isSpecial_11x   = true;	
		spd_38.isSpecial_22x   = true;
		spd_38.waitExtra	   = 0;
		vSpells->push_back(spd_38);
	//================================ ## End.region Lulu =================================
		
	//============== ##region Leblanc:
		//-------------------- E:
		SpellData spd_39;
		spd_39.charName        = "Leblanc";
		spd_39.dangerlevel     = 3;
		spd_39.missileName     = "LeblancEMissile";
		spd_39.extraMissileNames.push_back("LeblancREMissile");
		spd_39.name            = "Ethereal Chains";	
		spd_39.projectileSpeed = 1750;							
		spd_39.radius	       = 55;
		spd_39.range		   = 945;						
		spd_39.spellDelay      = 250;											
		spd_39.spellKey        = _E;
		spd_39.spellName       = "LeblancE";	
		spd_39.extraSpellNames.push_back("LeblancRE");		
		spd_39.spellType       = Line;
		spd_39.collisionObjects.push_back(EnemyMinions);
		spd_39.collisionObjects.push_back(EnemyChampions);
		spd_39.fixedRange	   = true;
		vSpells->push_back(spd_39);

		//-------------------- W and WR:
		SpellData spd_39W;
		spd_39W.charName        = "Leblanc";
		spd_39W.dangerlevel     = 2;
		spd_39W.missileName     = "LeblancW_Ss";
		spd_39W.name            = "Distortion";	
		spd_39W.projectileSpeed = 1450;							//dash-Speed : 1450				
		spd_39W.radius	        = 305;							//game : 260, do < 300 thi trung, 301 qua trung qua ko, ko tinh boundRadius
		spd_39W.range		    = 600;						
		spd_39W.spellDelay      = 0;											
		spd_39W.spellKey        = _W;
		spd_39W.spellName       = "LeblancW";	
		spd_39W.extraSpellNames.push_back("LeblancRW");		
		spd_39W.spellType       = Circular;
		spd_39W.isSpecial_11x   = true;						
		spd_39W.isSpecial_22x   = true;
		vSpells->push_back(spd_39W);
	//================================ ## End.region Leblanc =================================

	//============== ##region Draven:
		//-------------------- R:
		SpellData spd_40;
		spd_40.charName        = "Draven";
		spd_40.dangerlevel     = 2;
		spd_40.missileName     = "DravenR";
		spd_40.name            = "Whirling Death";	
		spd_40.projectileSpeed = 2000;
		spd_40.radius	       = 160;
		spd_40.range		   = 20000;						
		spd_40.spellDelay      = 500;											
		spd_40.spellKey        = _R;
		spd_40.spellName       = "DravenRCast";	
		spd_40.spellType       = Line;
		spd_40.waitExtra	   = 0;		//==0 la ne' luon khi thay dan.
		vSpells->push_back(spd_40);

		//-------------------- E:
		SpellData spd_41;
		spd_41.charName        = "Draven";
		spd_41.dangerlevel     = 3;
		spd_41.missileName     = "DravenDoubleShotMissile";
		spd_41.name            = "Stand Aside";	
		spd_41.projectileSpeed = 1400;
		spd_41.radius	       = 130;
		spd_41.range		   = 1100;						
		spd_41.spellDelay      = 250;											
		spd_41.spellKey        = _E;
		spd_41.spellName       = "DravenDoubleShot";	
		spd_41.spellType       = Line;
		vSpells->push_back(spd_41);
	//================================ ## End.region Draven =================================
		
	//============== ##region DrMundo:
		//-------------------- Q:
		SpellData spd_42;
		spd_42.charName        = "DrMundo";
		spd_42.dangerlevel     = 2;
		spd_42.missileName     = "InfectedCleaverMissile";
		spd_42.name            = "Infected Cleaver";	
		spd_42.projectileSpeed = 2000;
		spd_42.radius	       = 60;
		spd_42.range		   = 1050;						
		spd_42.spellDelay      = 250;											
		spd_42.spellKey        = _Q;
		spd_42.spellName       = "InfectedCleaverMissile";	
		spd_42.spellType       = Line;
		spd_42.collisionObjects.push_back(EnemyMinions);
		spd_42.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_42);
	//================================ ## End.region DrMundo =================================
		
	//============== ##region Shyvana:
		//-------------------- E:
		SpellData spd_43;
		spd_43.charName        = "Shyvana";
		spd_43.dangerlevel     = 2;
		spd_43.missileName     = "ShyvanaFireballMissile";
		spd_43.name            = "Flame Breath(E-1)";	
		spd_43.projectileSpeed = 1575;
		spd_43.radius	       = 60;
		spd_43.range		   = 950;						
		spd_43.spellDelay      = 250;											
		spd_43.spellKey        = _E1;
		spd_43.spellName       = "ShyvanaFireball";	
		spd_43.spellType       = Line;;
		vSpells->push_back(spd_43);

		//-------------------- E-2:	
		SpellData spd_44;
		spd_44.charName        = "Shyvana";
		spd_44.dangerlevel     = 2;
		spd_44.missileName     = "ShyvanaFireballDragonMissile";	
		spd_44.name            = "Flame Breath Dragon(E-2)";	
		spd_44.projectileSpeed = 1575;
		spd_44.radius	       = 70;	//160old
		spd_44.range		   = 975;
		//spd_44.extraEndTime    = 200;		//L# dung`, ko can cai nay
		spd_44.spellDelay      = 250;											
		spd_44.spellKey        = _E2;
		spd_44.spellName       = "ShyvanaFireballDragon2";	
		spd_44.spellType       = Line;
		spd_44.useEndPosition  = true;
		spd_44.hasEndExplosion = true;
		spd_44.secondaryRadius = 275;
		spd_44.EndPosMouse_add = 5;		//them cai nay de bay den vi tri chuot
		vSpells->push_back(spd_44);

		//-------------------- R:
		SpellData spd_45;
		spd_45.charName        = "Shyvana";
		spd_45.dangerlevel     = 3;
		spd_45.missileName     = "ShyvanaTransformCast_xx";			//ko co missile
		spd_45.name            = "Dragon's Descent";	
		spd_45.projectileSpeed = 900;
		spd_45.radius	       = 150;
		spd_45.range		   = 975;
		spd_45.spellDelay      = 250;											
		spd_45.spellKey        = _R;
		spd_45.spellName       = "ShyvanaTransformLeap";	
		spd_45.spellType       = Line;
		spd_45.useEndPosition  = true;
		spd_45.EndPosMouse_add = 50;		//them cai nay de bay den vi tri chuot
		vSpells->push_back(spd_45);
	//================================ ## End.region Shyvana =================================

	//============== ##region Xerath:
		//-------------------- Q:	
		SpellData spd_47;
		spd_47.charName        = "Xerath";
		spd_47.dangerlevel     = 2;
		spd_47.missileName     = "XerathQ_Ss";					//L#: "XerathArcanopulse2"
		spd_47.name            = "Arcanopulse";	
		spd_47.projectileSpeed = FLT_MAX;
		spd_47.radius	       = 70;
		spd_47.range		   = 1525;
		spd_47.spellDelay      = 500;											
		spd_47.spellKey        = _Q;
		spd_47.spellName       = "XerathArcanopulse2";	
		spd_47.spellType       = Line;
		spd_47.waitExtra       = 0;
		spd_47.isSpecial_11x   = true;							// vao` nhung ko dung`
		spd_47.isSpecial_22x   = true;							// vao` nhung ko dung`, ham` ne' o onTick
		vSpells->push_back(spd_47);

		//-------------------- W:
		SpellData spd_46;
		spd_46.charName        = "Xerath";
		spd_46.dangerlevel     = 2;
		spd_46.missileName     = "XerathArcaneBarrage2";		//trong game ko thay co missile, chac dung .troy
		spd_46.name            = "Eye of Destruction";	
		spd_46.radius	       = 270;
		spd_46.range		   = 1000;						
		spd_46.spellDelay      = 800;							//L#: 750
		spd_46.spellKey        = _W;
		spd_46.spellName       = "XerathArcaneBarrage2";		
		spd_46.spellType       = Circular;;
		spd_46.waitExtra       = 250;
		vSpells->push_back(spd_46);
		
		//-------------------- E:	
		SpellData spd_48;
		spd_48.charName        = "Xerath";
		spd_48.dangerlevel     = 3;
		spd_48.missileName     = "XerathMageSpearMissile";	
		spd_48.name            = "Shocking Orb";	
		spd_48.projectileSpeed = 1400;
		spd_48.radius	       = 60;
		spd_48.range		   = 1125;
		spd_48.spellDelay      = 250;											
		spd_48.spellKey        = _E;
		spd_48.spellName       = "XerathMageSpear";	
		spd_48.spellType       = Line;
		spd_48.collisionObjects.push_back(EnemyMinions);
		spd_48.collisionObjects.push_back(EnemyChampions);
		spd_48.fixedRange      = true;
		spd_48.waitExtra       = 150;
		vSpells->push_back(spd_48);

		//-------------------- R:	(dung missile tot hon, vi qua? dau tien van~ ne' dc)
		SpellData spd_49;
		spd_49.charName        = "Xerath";
		spd_49.dangerlevel     = 3;
		spd_49.missileName     = "XerathLocusPulse";		
		spd_49.name            = "Rite of the Arcane";	
		spd_49.projectileSpeed = FLT_MAX;
		spd_49.radius	       = 200;
		spd_49.range		   = 5600;
		spd_49.spellDelay      = 600;
		spd_49.spellKey        = _R;
		spd_49.spellName       = "XerathR_NO";						// "XerathRMissileWrapper" : chac cai nay chi dung o ban? detour thoi
		//spd_49.extraSpellNames.push_back("XerathLocusPulse");		// chac cai nay chi dung o ban? detour thoi
		spd_49.spellType       = Circular;
		spd_49.waitExtra	   = 0;									
		spd_49.isSpecial_11x   = true;								// ko co pCast, ko ne' o day
		spd_49.isSpecial_22x   = true;								// ne bang missile vi delay luon = 600
		vSpells->push_back(spd_49);	
	//================================ ## End.region Xerath =================================
		
	//============== ##region Brand:
		//-------------------- W:
		SpellData spd_50;
		spd_50.charName        = "Brand";
		spd_50.dangerlevel     = 2;
		spd_50.missileName     = "x12345667";			//L#: ko thay dung`, ko co missile, chac phai lay .troy
		spd_50.name            = "Pillar of Flame";	
		spd_50.radius	       = 250;
		spd_50.range		   = 1100;						
		spd_50.spellDelay      = 850;						
		spd_50.spellKey        = _W;
		spd_50.spellName       = "BrandW";	
		spd_50.spellType       = Circular;;
		vSpells->push_back(spd_50);

		//-------------------- Q:	
		SpellData spd_51;
		spd_51.charName        = "Brand";
		spd_51.dangerlevel     = 3;
		spd_51.missileName     = "BrandQMissile";	
		spd_51.name            = "Sear";	
		spd_51.projectileSpeed = 1800;				//L#: 2000
		spd_51.radius	       = 60;
		spd_51.range		   = 1100;
		spd_51.spellDelay      = 250;											
		spd_51.spellKey        = _Q;
		spd_51.spellName       = "BrandQ";	
		spd_51.spellType       = Line;
		spd_51.collisionObjects.push_back(EnemyMinions);
		spd_51.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_51);
	//================================ ## End.region Brand =================================

	//============== ##region Braum:
		//-------------------- Q:	
		SpellData spd_52;
		spd_52.charName        = "Braum";
		spd_52.dangerlevel     = 3;
		spd_52.missileName     = "BraumQMissile";	
		spd_52.name            = "Winter's Bite";	
		spd_52.projectileSpeed = 1100;				
		spd_52.radius	       = 100;
		spd_52.range		   = 1000;
		spd_52.spellDelay      = 250;											
		spd_52.spellKey        = _Q;
		spd_52.spellName       = "BraumQ";	
		spd_52.spellType       = Line;
		spd_52.collisionObjects.push_back(EnemyMinions);
		spd_52.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_52);

		//-------------------- R:	
		SpellData spd_53;
		spd_53.charName        = "Braum";
		spd_53.dangerlevel     = 4;
		spd_53.missileName     = "BraumRMissile";	
		spd_53.name            = "Glacial Fissure";	
		spd_53.projectileSpeed = 1125;				
		spd_53.radius	       = 120;
		spd_53.range		   = 1250;
		spd_53.spellDelay      = 500;											
		spd_53.spellKey        = _R;
		spd_53.spellName       = "BraumRWrapper";	
		spd_53.spellType       = Line;
		vSpells->push_back(spd_53);
	//================================ ## End.region Braum =================================
		
	//============== ##region Elise:
		//-------------------- Q:	
		SpellData spd_54;
		spd_54.charName        = "Elise";
		spd_54.dangerlevel     = 3;
		spd_54.missileName     = "EliseHumanE";	
		spd_54.name            = "Cocoon";	
		spd_54.projectileSpeed = 1600;				
		spd_54.radius	       = 55;
		spd_54.range		   = 1100;
		spd_54.spellDelay      = 250;											
		spd_54.spellKey        = _E;
		spd_54.spellName       = "EliseHumanE";	
		spd_54.spellType       = Line;
		spd_54.collisionObjects.push_back(EnemyMinions);
		spd_54.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_54);
	//================================ ## End.region Elise =================================

	//============== ##region Xayah:
		//-------------------- Q:	
		SpellData spd_55;
		spd_55.charName        = "Xayah";
		spd_55.dangerlevel     = 2;
		spd_55.missileName     = "XayahQMissile1";
		//spd_55.extraMissileNames.push_back("XayahQMissile2");	//dan. nay cham. hon
		spd_55.name            = "Double Daggers";	
		spd_55.projectileSpeed = 1700;				
		spd_55.radius	       = 50;
		spd_55.range		   = 1150;
		spd_55.spellDelay      = 250;											
		spd_55.spellKey        = _Q;
		spd_55.spellName       = "XayahQ";	
		spd_55.spellType       = Line;
		//spd_55.collisionObjects.push_back(EnemyMinions);			//hinh nhu ko co va cham linh chan' duong`
		//spd_55.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_55);
	//================================ ## End.region Xayah =================================

	//============== ##region Rakan:
		//-------------------- Q:	
		SpellData spd_56;
		spd_56.charName        = "Rakan";
		spd_56.dangerlevel     = 2;
		spd_56.missileName     = "RakanQMis";			// co ca "RakanQReturnMis" chac dan. luc cham. vao` dich. no?
		spd_56.name            = "Gleaming Quill";	
		spd_56.projectileSpeed = 1850;					//game: 1850		
		spd_56.radius	       = 65;
		spd_56.range		   = 875;
		spd_56.spellDelay      = 250;											
		spd_56.spellKey        = _Q;
		spd_56.spellName       = "RakanQ";	
		spd_56.spellType       = Line;
		spd_56.collisionObjects.push_back(EnemyMinions);
		spd_56.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_56);

		//-------------------- W:
		SpellData spd_57;
		spd_57.charName        = "Rakan";
		spd_57.dangerlevel     = 2;
		spd_57.missileName     = "RakanW_Ss";			
		spd_57.name            = "Grand Entrance";	
		spd_57.projectileSpeed = 1700;							//DashSpeed: 1700
		spd_57.radius	       = 280;
		spd_57.range		   = 625;
		spd_57.spellDelay      = 555;							// Game:350, nhung de~ ne' nen lay cao cao chut					
		spd_57.spellKey        = _W;		
		spd_57.spellName       = "RakanW";						// thuc chat la "RakanWCast" nhung dung` thi` se cham. hon 1chut (delay dashing)
		spd_57.spellType       = Circular;
		spd_57.isSpecial_11x   = true;
		spd_57.isSpecial_22x   = true;
		spd_57.waitExtra	   = 0;
		vSpells->push_back(spd_57);
	//================================ ## End.region Rakan =================================
		
	//============== ##region Fiora:
		//-------------------- W:	
		SpellData spd_58;
		spd_58.charName        = "Fiora";
		spd_58.dangerlevel     = 2;
		spd_58.missileName     = "FioraW_Ss";			
		spd_58.name            = "Riposte";	
		spd_58.projectileSpeed = 3500;								
		spd_58.radius	       = 70;
		spd_58.range		   = 750;
		spd_58.spellDelay      = 500;											
		spd_58.spellKey        = _W;
		spd_58.spellName       = "FioraW";						//ko co pCastSpell
		spd_58.spellType       = Line;
		spd_58.isSpecial_11x   = true;
		spd_58.isSpecial_22x   = true;
		vSpells->push_back(spd_58);
	////================================ ## End.region Fiora =================================

	//============== ##region Evelynn:
		//-------------------- Q:	
		SpellData spd_59;
		spd_59.charName        = "Evelynn";
		spd_59.dangerlevel     = 2;
		spd_59.missileName     = "EvelynnQ";			
		spd_59.name            = "Hate Spike";	
		spd_59.projectileSpeed = 2200;						
		spd_59.radius	       = 60;
		spd_59.range		   = 900;
		spd_59.spellDelay      = 250;											
		spd_59.spellKey        = _Q;
		spd_59.spellName       = "EvelynnQ";	
		spd_59.spellType       = Line;
		spd_59.collisionObjects.push_back(EnemyMinions);
		spd_59.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_59);
	//================================ ## End.region Evelynn =================================
	
	//============== ##region Nautilus:
		//-------------------- Q:	
		SpellData spd_60;
		spd_60.charName        = "Nautilus";
		spd_60.dangerlevel     = 3;
		spd_60.missileName     = "NautilusAnchorDragMissile";			
		spd_60.name            = "Dredge Line";	
		spd_60.projectileSpeed = 2000;						
		spd_60.radius	       = 90;
		spd_60.range		   = 1200;
		spd_60.spellDelay      = 250;											
		spd_60.spellKey        = _Q;
		spd_60.spellName       = "NautilusAnchorDragMissile";		//L#: "NautilusAnchorDrag"
		spd_60.spellType       = Line;
		spd_60.collisionObjects.push_back(EnemyMinions);
		spd_60.collisionObjects.push_back(EnemyChampions);
		spd_60.fixedRange = true;
		vSpells->push_back(spd_60);
	//================================ ## End.region Nautilus =================================

	//============== ##region Nidalee:
		//-------------------- Q:	
		SpellData spd_61;
		spd_61.charName        = "Nidalee";
		spd_61.dangerlevel     = 3;
		spd_61.missileName     = "JavelinToss";			
		spd_61.name            = "Javelin Toss";	
		spd_61.projectileSpeed = 1300;						
		spd_61.radius	       = 40;
		spd_61.range		   = 1500;
		spd_61.spellDelay      = 250;											
		spd_61.spellKey        = _Q;
		spd_61.spellName       = "JavelinToss";	
		spd_61.spellType       = Line;
		spd_61.collisionObjects.push_back(EnemyMinions);
		spd_61.collisionObjects.push_back(EnemyChampions);
		spd_61.fixedRange = true;
		vSpells->push_back(spd_61);

		////-------------------- W:	
		//SpellData spd_62;
		//spd_62.charName        = "Nidalee";
		//spd_62.dangerlevel     = 3;
		//spd_62.missileName     = "JavelinToss";			
		//spd_62.name            = "Bushwhack";	
		//spd_62.radius	       = 80;
		//spd_62.range		   = 1500;					
		//spd_62.spellKey        = _W;
		//spd_62.spellName       = "Bushwhack";	
		//spd_62.spellType       = Circular;
		////trapTroyName = "nidalee_base_w_tc_" + Situation.EmitterColor() + ".troy",
		//spd_62.hasTrap		   = true;
		//vSpells->push_back(spd_62);
	//================================ ## End.region Nidalee =================================
		
	//============== ##region Nocturne:
		//-------------------- Q:	
		SpellData spd_63;
		spd_63.charName        = "Nocturne";
		spd_63.dangerlevel     = 2;
		spd_63.missileName     = "NocturneDuskbringer";			
		spd_63.name            = "Duskbringer";	
		spd_63.projectileSpeed = 1400;						
		spd_63.radius	       = 60;
		spd_63.range		   = 1250;
		spd_63.spellDelay      = 250;											
		spd_63.spellKey        = _Q;
		spd_63.spellName       = "NocturneDuskbringer";	
		spd_63.spellType       = Line;
		spd_63.fixedRange = true;
		vSpells->push_back(spd_63);
	//================================ ## End.region Nocturne =================================
		
	//============== ##region Ahri:
		//-------------------- Q:	
		SpellData spd_64;
		spd_64.charName        = "Ahri";
		spd_64.dangerlevel     = 2;
		spd_64.missileName     = "AhriOrbMissile";			
		spd_64.name            = "Orb of Deception";	
		spd_64.projectileSpeed = 1600;						//L#: 1750					
		spd_64.radius	       = 100;
		spd_64.range		   = 975;						//L#: 925	
		spd_64.spellDelay      = 250;											
		spd_64.spellKey        = _Q;
		spd_64.spellName       = "AhriOrbofDeception";	
		spd_64.spellType       = Line;
		vSpells->push_back(spd_64);

		////-------------------- Q-back:	
		//SpellData spd_65;
		//spd_65.charName        = "Ahri";
		//spd_65.dangerlevel     = 3;
		//spd_65.missileName     = "AhriOrbReturn";			
		//spd_65.name            = "Orb of Deception Back";	
		//spd_65.projectileSpeed = 915;						
		//spd_65.radius	       = 100;
		//spd_65.range		   = 975;
		//spd_65.spellDelay      = 250;											
		//spd_65.spellKey        = 22;
		//spd_65.spellName       = "AhriOrbofDeception2";	
		//spd_65.spellType       = Line;
		//spd_65.isSpecial = true
		//vSpells->push_back(spd_65);

		//-------------------- E:	
		SpellData spd_66;
		spd_66.charName        = "Ahri";
		spd_66.dangerlevel     = 3;
		spd_66.missileName     = "AhriSeduceMissile";			
		spd_66.name            = "Charm";	
		spd_66.projectileSpeed = 1500;						//L#: 1550
		spd_66.radius	       = 60;
		spd_66.range		   = 1025;
		spd_66.spellDelay      = 250;											
		spd_66.spellKey        = _E;
		spd_66.spellName       = "AhriSeduce";	
		spd_66.spellType       = Line;
		spd_66.collisionObjects.push_back(EnemyMinions);
		spd_66.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_66);
	//================================ ## End.region Ahri =================================
		
	//============== ##region Bard:
		//-------------------- Q:	
		SpellData spd_67;
		spd_67.charName        = "Bard";
		spd_67.dangerlevel     = 3;
		spd_67.missileName     = "BardQMissile";			
		spd_67.name            = "Cosmic Binding";	
		spd_67.projectileSpeed = 1600;											
		spd_67.radius	       = 60;
		spd_67.range		   = 950;							
		spd_67.spellDelay      = 250;											
		spd_67.spellKey        = _Q;
		spd_67.spellName       = "BardQ";	
		spd_67.spellType       = Line;
		vSpells->push_back(spd_67);

		//-------------------- R:	
		SpellData spd_68;
		spd_68.charName        = "Bard";
		spd_68.dangerlevel     = 2;
		spd_68.missileName     = "BardRMissileRange1";					//dung` .troy chac nhanh hon
		spd_68.extraMissileNames.push_back("BardRMissileRange2");	
		spd_68.extraMissileNames.push_back("BardRMissileRange3");	
		spd_68.extraMissileNames.push_back("BardRMissileRange4");	
		spd_68.extraMissileNames.push_back("BardRMissileRange5");	
		spd_68.extraMissileNames.push_back("BardRMissileRange6");
		spd_68.name            = "Tempered Fate";	
		spd_68.projectileSpeed = 2100;						
		spd_68.radius	       = 350;
		spd_68.range		   = 3400;
		spd_68.spellDelay      = 250;											
		spd_68.spellKey        = _R;
		spd_68.spellName       = "BardR";	
		spd_68.spellType       = Circular;
		spd_68.waitExtra	   = 0;		//==0 la ne' luon khi thay dan.
		vSpells->push_back(spd_68);
	//================================ ## End.region Bard =================================
		
	//============== ##region Sona:
		//-------------------- R:	
		SpellData spd_69;
		spd_69.charName        = "Sona";				//chac ne = skill hay hon
		spd_69.dangerlevel     = 4;
		spd_69.missileName     = "SonaR";			
		spd_69.name            = "Crescendo";	
		spd_69.projectileSpeed = 2400;											
		spd_69.radius	       = 145;
		spd_69.range		   = 1000;							
		spd_69.spellDelay      = 250;											
		spd_69.spellKey        = _R;
		spd_69.spellName       = "SonaR";	
		spd_69.spellType       = Line;
		spd_69.fixedRange      = true;
		vSpells->push_back(spd_69);
	//================================ ## End.region Sona =================================
		
	//============== ##region Nami:
		//-------------------- Q:	
		SpellData spd_70;
		spd_70.charName        = "Nami";				
		spd_70.dangerlevel     = 3;
		spd_70.missileName     = "NamiQMissile";			
		spd_70.name            = "Aqua Prison";	
		spd_70.projectileSpeed = 2500;				//L#:2500, Game:1750							
		spd_70.radius	       = 215;
		spd_70.range		   = 875;							
		spd_70.spellDelay      = 450;											
		spd_70.spellKey        = _Q;
		spd_70.spellName       = "NamiQ";	
		spd_70.spellType       = Circular;
		spd_70.waitExtra	   = 0;
		vSpells->push_back(spd_70);

		//-------------------- R:	
		SpellData spd_71;
		spd_71.charName        = "Nami";				
		spd_71.dangerlevel     = 2;
		spd_71.missileName     = "NamiRMissile";			
		spd_71.name            = "Tidal Wave";	
		spd_71.projectileSpeed = 850;											
		spd_71.radius	       = 235;
		spd_71.range		   = 2750;							
		spd_71.spellDelay      = 500;											
		spd_71.spellKey        = _R;
		spd_71.spellName       = "NamiRMissile";	
		spd_71.spellType       = Line;
		spd_71.fixedRange	   = true;
		spd_71.waitExtra	   = 200;
		vSpells->push_back(spd_71);
	//================================ ## End.region Nami =================================
	
	//============== ##region Kaisa:
		//-------------------- W:	
		SpellData spd_72;
		spd_72.charName        = "Kaisa";				
		spd_72.dangerlevel     = 2;
		spd_72.missileName     = "KaisaW";			
		spd_72.name            = "Void Seeker";	
		spd_72.projectileSpeed = 1700;					//Game: 1750						
		spd_72.radius	       = 95;
		spd_72.range		   = 3025;							
		spd_72.spellDelay      = 400;					//Game: 400									
		spd_72.spellKey        = _W;
		spd_72.spellName       = "KaisaW";	
		spd_72.spellType       = Line;
		spd_72.collisionObjects.push_back(EnemyMinions);
		spd_72.collisionObjects.push_back(EnemyChampions);
		//spd_72.fixedRange	   = true;
		vSpells->push_back(spd_72);
	//================================ ## End.region Kaisa =================================

	//============== ##region Soraka:
		//-------------------- Q:	
		SpellData spd_73;
		spd_73.charName        = "Soraka";				
		spd_73.dangerlevel     = 1;
		spd_73.missileName     = "SorakaQMissile";			
		spd_73.name            = "Starcall";	
		spd_73.projectileSpeed = FLT_MAX;			//L#: 1100, Game:1750										
		spd_73.radius	       = 265;				//game : 230, do < 265 thi trung, 266 ko trung, ko tinh boundRadius
		spd_73.range		   = 800;				//    KC:50/100/150/200/250/300/350/400/450/500/550/600/650/700/750/800
		spd_73.spellDelay      = 250;				//--> delay: 0.25/0.3/0.35/0.4/0.45/0.5/0.55/0.6/0.65/0.7/0.75/0.8/0.85/0.9/0.95/1.0							
		spd_73.spellKey        = _Q;
		spd_73.spellName       = "SorakaQ";	
		spd_73.spellType       = Circular;
		spd_73.isSpecial_11x   = true;
		spd_73.isSpecial_22x   = true;
		spd_73.waitExtra       = 0;
		vSpells->push_back(spd_73);

		//-------------------- E:	
		SpellData spd_74;
		spd_74.charName        = "Soraka";				
		spd_74.dangerlevel     = 3;
		spd_74.defaultOff      = true;
		spd_74.missileName     = "KoCo_Missi";		//L#: ko thay dung`	, ko thay co missile
		spd_74.name            = "Equinox";	
		spd_74.projectileSpeed = 15000;				//L#: FLT_MAX (logic cua L# chi ne' E-khi no? gay choang					
		spd_74.radius	       = 265;				//game : 260, do < 260 thi trung, 262 qua trung qua ko, ko tinh boundRadius
		spd_74.range		   = 875;							
		spd_74.spellDelay      = 1750;				//L#: 1750
		spd_74.spellKey        = _E;
		spd_74.spellName       = "SorakaE";	
		spd_74.spellType       = Circular;
		spd_74.waitExtra       = 250;
		vSpells->push_back(spd_74);
	//================================ ## End.region Soraka =================================
		
	//============== ##region Alistar:
		//-------------------- Q:	
		SpellData spd_75;
		spd_75.charName        = "Alistar";	
		spd_75.defaultOff	   = true;
		spd_75.dangerlevel     = 3;
		spd_75.missileName     = "KoCo_Missile";			
		spd_75.name            = "Pulverize";										
		spd_75.radius	       = 365;				//chuan, k tinh boundRadius
		spd_75.range		   = 365;						
		spd_75.spellDelay      = 250;											
		spd_75.spellKey        = _Q;
		spd_75.spellName       = "Pulverize";	
		spd_75.spellType       = Circular;
		vSpells->push_back(spd_75);

	//================================ ## End.region Alistar =================================

	//============== ##region Anivia:
		//-------------------- Q:	
		SpellData spd_76;
		spd_76.charName        = "Anivia";	
		spd_76.dangerlevel     = 3;
		spd_76.missileName     = "FlashFrostSpell";			
		spd_76.name            = "Flash Frost";	
		spd_76.projectileSpeed = 850;
		spd_76.radius	       = 110;				
		spd_76.range		   = 1350;						
		spd_76.spellDelay      = 250;											
		spd_76.spellKey        = _Q;
		spd_76.spellName       = "FlashFrostSpell";	
		spd_76.spellType       = Line;
		vSpells->push_back(spd_76);
	//================================ ## End.region Anivia =================================

	//============== ##region Zed:
		//-------------------- Q:	
		SpellData spd_77;
		spd_77.charName        = "Zed";	
		spd_77.dangerlevel     = 3;
		spd_77.missileName     = "ZedQMissile";				//ko can dung`	
		spd_77.name            = "Razor Shuriken";	
		spd_77.projectileSpeed = 1700;						//L#:1700
		spd_77.radius	       = 50;				
		spd_77.range		   = 975;						
		spd_77.spellDelay      = 250;											
		spd_77.spellKey        = _Q;
		spd_77.spellName       = "ZedQ";	
		spd_77.spellType       = Line;
		spd_77.isSpecial_11x   = true;
		spd_77.isSpecial_22x   = true;
		spd_77.waitExtra	   = 0;
		vSpells->push_back(spd_77);
	//================================ ## End.region Zed =================================

	//============== ##region Yasuo:
		//-------------------- Q-3:	
		SpellData spd_78;
		spd_78.charName        = "Yasuo";	
		spd_78.dangerlevel     = 3;
		spd_78.missileName     = "YasuoQ3Mis";			
		spd_78.name            = "Steel Tempest (Tornado)";	
		spd_78.projectileSpeed = 1275;
		spd_78.radius	       = 90;				
		spd_78.range		   = 1150;						
		spd_78.spellDelay      = 350;						//L#: 300, Game: 313					
		spd_78.spellKey        = _Q3;
		spd_78.spellName       = "YasuoQ3";	
		spd_78.spellType       = Line;
		spd_78.fixedRange      = true;
		spd_78.waitExtra       = 175;
		vSpells->push_back(spd_78);

		//-------------------- Q-1-2:			(ko ne' dc vi mousePos = DestPos = SrcPos)
		SpellData spd_79;
		spd_79.charName        = "Yasuo";
		spd_79.dangerlevel     = 2;
		spd_79.defaultOff      = true;
		spd_79.missileName     = "YasuoQ12_NO";					//ko co Missile
		spd_79.name            = "Steel Tempest(Q1-2)";	
		spd_78.projectileSpeed = FLT_MAX;
		spd_79.radius	       = 40;				
		spd_79.range		   = 550;						
		spd_79.spellDelay      = 350;											
		spd_79.spellKey        = _Q1;
		spd_79.spellName       = "YasuoQ1";						//"YasuoQ1", "YasuoQ2"
		spd_79.extraSpellNames.push_back("YasuoQ2");
		spd_79.spellType       = Line;
		spd_79.fixedRange      = true;
		spd_79.waitExtra       = 0;
		spd_79.isSpecial_11x   = true;
		spd_79.isSpecial_22x   = true;
		vSpells->push_back(spd_79);
	//================================ ## End.region Yasuo =================================

	//============== ##region Kayn:
		//-------------------- W:							//Kayn pCastSpell ton tai 1.99s
		SpellData spd_80;
		spd_80.charName        = "Kayn";	
		spd_80.dangerlevel     = 2;
		spd_80.missileName     = "KaynW_1234";				//ko co missile
		spd_80.name            = "Blade's Reach";	
		spd_80.projectileSpeed = 10000;
		spd_80.radius	       = 90;				
		spd_80.range		   = 780;						
		spd_80.spellDelay      = 550;											
		spd_80.spellKey        = _W;
		spd_80.spellName       = "KaynW";	
		spd_80.spellType       = Line;
		vSpells->push_back(spd_80);
	//================================ ## End.region Kayn =================================

	//============== ##region Pyke:
		//-------------------- Q:							
		SpellData spd_81;
		spd_81.charName        = "Pyke";	
		spd_81.dangerlevel     = 3;
		spd_81.missileName     = "PykeQRange";				
		spd_81.name            = "Bone Skewer";	
		spd_81.projectileSpeed = 2000;
		spd_81.radius	       = 65;				
		spd_81.range		   = 1105;						
		spd_81.spellDelay      = 200;						//Qrange:200ms, Qmelee: 250ms
		spd_81.spellKey        = _Q;
		spd_81.spellName       = "PykeQRange";
		//spd_81.extraSpellNames.push_back("PykeQMelee");	//PykeQMelee : srcPos=destPos=mousePos
		spd_81.spellType       = Line;
		spd_81.waitExtra       = 0;
		spd_81.collisionObjects.push_back(EnemyMinions);
		spd_81.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_81);

		//-------------------- E:							
		SpellData spd_82;
		spd_82.charName        = "Pyke";	
		spd_82.dangerlevel     = 3;
		spd_82.missileName     = "PykeEMissile_xx";			//ko can ne bang missile
		spd_82.name            = "Phantom Undertow";	
		spd_82.projectileSpeed = 3000;
		spd_82.radius	       = 155;				
		spd_82.range		   = 850;						//Range thay doi					
		spd_82.spellDelay      = 700;											
		spd_82.spellKey        = _E;
		spd_82.spellName       = "PykeE";		
		spd_82.spellType       = Line;
		spd_82.isSpecial_11x   = true;
		spd_82.isSpecial_22x   = true;
		spd_82.waitExtra       = 0;
		vSpells->push_back(spd_82);

		//-------------------- R:							
		SpellData spd_82_R;
		spd_82_R.charName        = "Pyke";	
		spd_82_R.dangerlevel     = 3;
		spd_82_R.missileName     = "PykeR_xx";					//ko co missile
		spd_82_R.name            = "Death from Below [Beta]";	
		spd_82_R.projectileSpeed = FLT_MAX;
		spd_82_R.radius	         = 40;				
		spd_82_R.range		     = 675;							//Range thay doi					
		spd_82_R.spellDelay      = 550;											
		spd_82_R.spellKey        = _R;
		spd_82_R.spellName       = "PykeR";		
		spd_82_R.spellType       = Line;
		spd_82_R.isSpecial_11x	 = true;					//choi sanh dieu
		spd_82_R.isSpecial_22x	 = true;
		spd_82_R.waitExtra       = 0;
		vSpells->push_back(spd_82_R);
	//================================ ## End.region Pyke =================================
		
	//============== ##region Varus:
		//-------------------- E:							
		SpellData spd_83;
		spd_83.charName        = "Varus";	
		spd_83.dangerlevel     = 2;
		spd_83.missileName     = "VarusEMissile";				
		spd_83.name            = "Hail of Arrows";	
		spd_83.projectileSpeed = 1500;					//L#: 1500
		spd_83.radius	       = 235;					//game 235, do < 300 thi trung, 301 ko trung, ko tinh boundRadius
		spd_83.range		   = 925;						
		spd_83.spellDelay      = 250;											
		spd_83.spellKey        = _E;
		spd_83.spellName       = "VarusE";	
		spd_83.spellType       = Circular;
		vSpells->push_back(spd_83);

		//-------------------- Q:							
		SpellData spd_84;
		spd_84.charName        = "Varus";	
		spd_84.dangerlevel     = 2;
		spd_84.missileName     = "VarusQMissile";				
		spd_84.name            = "Piercing Arrow";	
		spd_84.projectileSpeed = 1900;
		spd_84.radius	       = 70;				
		spd_84.range		   = 1525;							//range thay doi theo tgian, set range luc create roi
		spd_84.spellDelay      = 0;											
		spd_84.spellKey        = _Q;
		spd_84.spellName       = "VarusQ_CANT";					//ko dung ten "VarusQ" nay cho ban? safe dc
		spd_84.spellType       = Line;
		spd_84.waitExtra       = 200;
		spd_84.isSpecial_11x   = true;							
		spd_84.isSpecial_22x   = true;
		vSpells->push_back(spd_84);
		
		//-------------------- R:							
		SpellData spd_85;
		spd_85.charName        = "Varus";	
		spd_85.dangerlevel     = 3;
		spd_85.missileName     = "VarusRMissile";				
		spd_85.name            = "Chain of Corruption";	
		spd_85.projectileSpeed = 1950;
		spd_85.radius	       = 110;				
		spd_85.range		   = 1225;						
		spd_85.spellDelay      = 250;											
		spd_85.spellKey        = _R;
		spd_85.spellName       = "VarusR";			
		spd_85.spellType       = Line;
		spd_85.fixedRange	   = true;	
		spd_85.waitExtra       = 150;
		spd_85.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_85);
	//================================ ## End.region Varus =================================
			
	//============== ##region Corki:
		//-------------------- Q:							
		SpellData spd_86;
		spd_86.charName        = "Corki";	
		spd_86.dangerlevel     = 2;
		spd_86.missileName     = "PhosphorusBombMissile";				
		spd_86.name            = "Phosphorus Bomb";	
		spd_86.projectileSpeed = 1125;					
		spd_86.radius	       = 275;				//game : 250, do < 275 thi trung, 276 ko trung, ko tinh boundRadius
		spd_86.range		   = 825;						
		spd_86.spellDelay      = 500;											
		spd_86.spellKey        = _Q;
		spd_86.spellName       = "PhosphorusBomb";	
		spd_86.spellType       = Circular;
		spd_86.extraDrawHeight = 110;
		spd_86.waitExtra       = 0;
		vSpells->push_back(spd_86);

		//-------------------- R:							
		SpellData spd_87;
		spd_87.charName        = "Corki";	
		spd_87.dangerlevel     = 2;
		spd_87.missileName     = "MissileBarrageMissile";				
		spd_87.name            = "Missile Barrage";	
		spd_87.projectileSpeed = 2000;
		spd_87.radius	       = 40;				
		spd_87.range		   = 1300;						
		spd_87.spellDelay      = 175;											
		spd_87.spellKey        = _R1;
		spd_87.spellName       = "MissileBarrageMissile";			
		spd_87.spellType       = Line;
		spd_87.collisionObjects.push_back(EnemyMinions);
		spd_87.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_87);
			
		//-------------------- R-Big:							
		SpellData spd_88;
		spd_88.charName        = "Corki";	
		spd_88.dangerlevel     = 3;
		spd_88.missileName     = "MissileBarrageMissile2";				
		spd_88.name            = "Missile Barrage [Big]";	
		spd_88.projectileSpeed = 2000;
		spd_88.radius	       = 40;				
		spd_88.range		   = 1500;						
		spd_88.spellDelay      = 175;											
		spd_88.spellKey        = _R2;
		spd_88.spellName       = "MissileBarrageMissile2";			
		spd_88.spellType       = Line;
		spd_88.collisionObjects.push_back(EnemyMinions);
		spd_88.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_88);
	//================================ ## End.region Corki =================================

	//============== ##region Janna:
		//-------------------- Q:													
		SpellData spd_89;
		spd_89.charName        = "Janna";	
		spd_89.dangerlevel     = 2;
		spd_89.missileName     = "HowlingGaleSpell";
		for (int iv = 1; iv <= 16; ++iv)
		{
			char tmp[32];
			sprintf_s(tmp,"HowlingGaleSpell%d", iv);
			spd_89.extraMissileNames.push_back(tmp);		//spd_89.extraMissileNames.push_back("HowlingGaleSpell1");
		}
		spd_89.name            = "Howling Gale";	
		spd_89.projectileSpeed = 900;
		spd_89.radius	       = 120;				
		spd_89.range		   = 1700;						
		spd_89.spellDelay      = 0;							// dung` 0 vi k co pCastSpell								
		spd_89.spellKey        = _Q;
		spd_89.spellName       = "HowlingGale";				// ko co pCastSpell	
		spd_89.spellType       = Line;
		spd_89.isSpecial_11x   = true;						// ko ne' o day vi k co pCastSpell
		spd_89.isSpecial_22x   = true;						// ne' o day vi speed, range thay doi theo tgian
		vSpells->push_back(spd_89);
	//================================ ## End.region Janna =================================

	//============== ##region Jayce:
		//-------------------- Q:													
		SpellData spd_90;
		spd_90.charName        = "Jayce";	
		spd_90.dangerlevel     = 2;
		spd_90.missileName     = "JayceShockBlastMis";
		spd_90.extraMissileNames.push_back("JayceShockBlastWallMis");
		spd_90.name            = "Shock Blast";	
		spd_90.projectileSpeed = 1450;
		spd_90.radius	       = 70;				
		spd_90.range		   = 1050;		//L#: 1170				
		spd_90.spellDelay      = 250;											
		spd_90.spellKey        = _Q;
		spd_90.spellName       = "JayceShockBlast";			
		spd_90.spellType       = Line;
		spd_90.collisionObjects.push_back(EnemyMinions);
		spd_90.collisionObjects.push_back(EnemyChampions);
		//spd_90.hasEndExplosion = true;
		//spd_90.secondaryRadius = 210;		
		spd_90.fixedRange      = true;
		spd_90.waitExtra       = 0;			//cho ne luon
		spd_90.isSpecial_11x   = true;						// 
		spd_90.isSpecial_22x   = true;						// ne' o day vi speed, range thay doi 
		vSpells->push_back(spd_90);

		////-------------------- Q-E(wall):													
		//SpellData spd_91;
		//spd_91.charName        = "Jayce";	
		//spd_91.dangerlevel     = 3;
		//spd_91.missileName     = "JayceShockBlastWallMis";
		//spd_91.name            = "Shock Blast Fast(Q-E)";	
		//spd_91.projectileSpeed = 2350;
		//spd_91.radius	       = 70;				
		//spd_91.range		   = 1600;						
		//spd_91.spellDelay      = 250;											
		//spd_91.spellKey        = _Q2;
		//spd_91.spellName       = "JayceShockBlastFast";			//trong OnProcessSpell co the co ten "JayceShockBlastFast", trong pCastSpell thi ko	co
		//spd_91.spellType       = Line;
		//spd_91.collisionObjects.push_back(EnemyMinions);
		//spd_91.collisionObjects.push_back(EnemyChampions);
		//spd_91.hasEndExplosion = true;
		//spd_91.secondaryRadius = 250;		
		//spd_91.waitExtra       = 0;			//cho ne luon
		//vSpells->push_back(spd_91);
	//================================ ## End.region Jayce =================================
		
	//============== ##region Veigar:
		//-------------------- Q:													
		SpellData spd_92;
		spd_92.charName        = "Veigar";	
		spd_92.dangerlevel     = 2;
		spd_92.missileName     = "VeigarBalefulStrikeMis";
		spd_92.name            = "Baleful Strike";	
		spd_92.projectileSpeed = 2200;					//L#: 2200
		spd_92.radius	       = 70;				
		spd_92.range		   = 950;						
		spd_92.spellDelay      = 250;											
		spd_92.spellKey        = _Q;
		spd_92.spellName       = "VeigarBalefulStrike";			
		spd_92.spellType       = Line;
		spd_92.fixedRange = true;
		vSpells->push_back(spd_92);

		//-------------------- W:													
		SpellData spd_93;
		spd_93.charName        = "Veigar";	
		spd_93.dangerlevel     = 2;
		spd_93.missileName     = "VeigarW_Special";	//"VeigarDarkMatter" ko co missile, nen check = "Veigar_Base_W_cas_red"
		spd_93.name            = "Dark Matter";	
		spd_93.projectileSpeed = FLT_MAX;
		spd_93.radius	       = 240;				//game : 225, do < 240 thi trung, 241 ko trung, ko tinh boundRadius
		spd_93.range		   = 900;						
		spd_93.spellDelay      = 1200;											
		spd_93.spellKey        = _W;
		spd_93.spellName       = "VeigarDarkMatterCastLockout";			//L#: "VeigarDarkMatter"		
		spd_93.spellType       = Circular;
		spd_93.waitExtra	   = 150;
		vSpells->push_back(spd_93);

		//-------------------- E:													
		SpellData spd_94;
		spd_94.charName        = "Veigar";	
		spd_94.dangerlevel     = 3;
		spd_94.missileName     = "Event Horizon";
		spd_94.name            = "Event Horizon";	
		spd_94.projectileSpeed = FLT_MAX;
		spd_94.radius	       = 375;					//L#: 375		
		spd_94.range		   = 700;						
		spd_94.spellDelay      = 500;
		spd_94.extraEndTime    = 3300;
		spd_94.spellKey        = _E;
		spd_94.spellName       = "VeigarEventHorizon";			
		spd_94.spellType       = Circular;
		spd_94.defaultOff	   = true;
		vSpells->push_back(spd_94);

	//================================ ## End.region Veigar =================================
		
	//============== ##region Aatrox:
		//-------------------- W:													
		SpellData spd_95;
		spd_95.charName        = "Aatrox";	
		spd_95.dangerlevel     = 2;
		spd_95.missileName     = "AatroxW";
		spd_95.name            = "Infernal Chains";	
		spd_95.projectileSpeed = 1700;					
		spd_95.radius	       = 65;				
		spd_95.range		   = 875;						
		spd_95.spellDelay      = 250;											
		spd_95.spellKey        = _W;
		spd_95.spellName       = "AatroxW";			
		spd_95.spellType       = Line;
		spd_95.collisionObjects.push_back(EnemyMinions);
		spd_95.collisionObjects.push_back(EnemyChampions);
		spd_95.waitExtra	   = 0;
		vSpells->push_back(spd_95);

		//-------------------- Q-1:	
		SpellData spd_96Q1;
		spd_96Q1.charName        = "Aatrox";	
		spd_96Q1.dangerlevel     = 2;
		spd_96Q1.missileName     = "AatroxQ_Ss";
		spd_96Q1.name            = "The Darkin Blade 1";	
		spd_96Q1.projectileSpeed = 2800;					
		spd_96Q1.radius	         = 110;				
		spd_96Q1.range		     = 700;						
		spd_96Q1.spellDelay      = 600;											
		spd_96Q1.spellKey        = _Q1;
		spd_96Q1.spellName       = "AatroxQ1";							//"AatroxQWrapperCast"	
		spd_96Q1.extraSpellNames.push_back("AatroxQWrapperCast");
		spd_96Q1.spellType       = Line;
		spd_96Q1.waitExtra		 = 0;
		spd_96Q1.isSpecial_11x   = true;
		spd_96Q1.isSpecial_22x   = true;
		vSpells->push_back(spd_96Q1);

		//-------------------- Q-2:	
		SpellData spd_96Q2;
		spd_96Q2.charName        = "Aatrox";	
		spd_96Q2.dangerlevel     = 3;
		spd_96Q2.missileName     = "AatroxQ2_Ss";
		spd_96Q2.name            = "The Darkin Blade 2";	
		spd_96Q2.projectileSpeed = 3000;					
		spd_96Q2.radius	         = 235;				
		spd_96Q2.range		     = 550;						
		spd_96Q2.spellDelay      = 600;											
		spd_96Q2.spellKey        = _Q2;
		spd_96Q2.spellName       = "AatroxQ2";							//"AatroxQWrapperCast"	
		spd_96Q2.extraSpellNames.push_back("AatroxQWrapperCast");
		spd_96Q2.spellType       = Line;
		spd_96Q2.waitExtra		 = 0;
		spd_96Q2.isSpecial_11x   = true;
		spd_96Q2.isSpecial_22x   = true;
		vSpells->push_back(spd_96Q2);

		//-------------------- Q-3:	
		SpellData spd_96Q3;
		spd_96Q3.charName        = "Aatrox";	
		spd_96Q3.dangerlevel     = 2;
		spd_96Q3.missileName     = "AatroxQ3_Ss";
		spd_96Q3.name            = "The Darkin Blade 3";	
		spd_96Q3.projectileSpeed = 2800;					
		spd_96Q3.radius	         = 320;				
		spd_96Q3.range		     = 200;						
		spd_96Q3.spellDelay      = 600;											
		spd_96Q3.spellKey        = _Q3;
		spd_96Q3.spellName       = "AatroxQ3";							//"AatroxQWrapperCast"	
		spd_96Q3.extraSpellNames.push_back("AatroxQWrapperCast");
		spd_96Q3.spellType       = Circular;
		spd_96Q3.waitExtra		 = 0;
		spd_96Q3.isSpecial_11x   = true;
		spd_96Q3.isSpecial_22x   = true;
		vSpells->push_back(spd_96Q3);

	//================================ ## End.region Aatrox =================================
		
	//============== ##region Annie:
		////-------------------- W:
		//SpellData spd_5;
		//spd_5.angle			  = 22;
		//spd_5.charName        = "Annie";
		//spd_5.dangerlevel     = 2;
		//spd_5.name            = "Incinerate";
		//spd_5.radius          = 80;
		//spd_5.range           = 625;
		//spd_5.spellDelay      = 750;
		//spd_5.spellKey        = _W;
		//spd_5.spellName       = "AnnieW";		//L# : "Incinerate"
		//spd_5.spellType       = Cone;
		//vSpells->push_back(spd_5);

		//-------------------- R:												
		SpellData spd_97;
		spd_97.charName        = "Annie";	
		spd_97.dangerlevel     = 4;
		spd_97.missileName     = "InfernalGuardian_00";
		spd_97.name            = "Summon: Tibbers";	
		spd_97.projectileSpeed = FLT_MAX;					
		spd_97.radius	       = 290;					//L#: 290, do <250 gay choang, 251 ko choang, k tinh boundRadius
		spd_97.range		   = 600;						
		spd_97.spellDelay      = 250;											
		spd_97.spellKey        = _R;
		spd_97.spellName       = "AnnieR";				//L#: "InfernalGuardian";			
		spd_97.spellType       = Circular;	
		vSpells->push_back(spd_97);
	//============== ## End.region Annie =================================

	//============== ##region AurelionSol:
		//-------------------- W:
		SpellData spd_98;
		spd_98.charName        = "AurelionSol";
		spd_98.dangerlevel     = 2;
		spd_98.missileName     = "AurelionSolQMissile";
		spd_98.name            = "Starsurge";
		spd_98.projectileSpeed = 600;
		spd_98.radius          = 130;						//L#: 180
		spd_98.range           = 1200;
		spd_98.spellDelay      = 250;
		spd_98.spellKey        = _Q;
		spd_98.spellName       = "AurelionSolQ";			//ko co pCastSpell
		spd_98.spellType       = Line;
		spd_98.fixedRange	   = true;
		spd_98.waitExtra	   = 0;
		vSpells->push_back(spd_98);

		//-------------------- R:												
		SpellData spd_99;
		spd_99.charName        = "AurelionSol";
		spd_99.dangerlevel     = 4;
		spd_99.missileName     = "AurelionSolRBeamMissile";
		spd_99.name            = "Voice of Light";
		spd_99.projectileSpeed = 4600;
		spd_99.radius          = 110;
		spd_99.range           = 1625;
		spd_99.spellDelay      = 350;
		spd_99.spellKey        = _R;
		spd_99.spellName       = "AurelionSolR";		
		spd_99.spellType       = Line;
		spd_99.fixedRange	   = true;
		spd_99.waitExtra	   = 0;
		vSpells->push_back(spd_99);
	//============== ## End.region AurelionSol =================================

	//============== ##region Azir:
		//-------------------- R:												
		SpellData spd_100;
		spd_100.charName        = "Azir";
		spd_100.dangerlevel     = 3;
		spd_100.missileName     = "AzirSoldierRMissile";
		spd_100.name            = "Emperor's Divide";
		spd_100.projectileSpeed = 1200;
		spd_100.radius          = 450;
		spd_100.range           = 525;
		spd_100.spellDelay      = 500;
		spd_100.spellKey        = _R;
		spd_100.spellName       = "AzirR";		
		spd_100.spellType       = Line;
		spd_100.waitExtra	    = 0;
		vSpells->push_back(spd_100);
	//============== ## End.region Azir =================================

	//============== ##region Cassiopeia:
		//-------------------- R:												
		SpellData spd_101;
		spd_101.angle			= 40;
		spd_101.charName        = "Cassiopeia";
		spd_101.dangerlevel     = 4;
		spd_101.missileName     = "CassiopeiaR_00";
		spd_101.name            = "Petrifying Gaze";
		spd_101.projectileSpeed = 4000;
		spd_101.radius          = 145;
		spd_101.range           = 825;
		spd_101.spellDelay      = 1000;
		spd_101.spellKey        = _R;
		spd_101.spellName       = "CassiopeiaR";		
		spd_101.spellType       = Cone;
		spd_101.waitExtra	    = 0;
		vSpells->push_back(spd_101);

		////-------------------- W:												
		//SpellData spd_102;
		//spd_102.charName        = "Cassiopeia";
		//spd_102.dangerlevel     = 1;
		//spd_102.missileName     = "CassiopeiaWMissile";
		//spd_102.name            = "Miasama";
		//spd_102.projectileSpeed = 1500;
		//spd_102.radius          = 200;
		//spd_102.range           = 900;
		//spd_102.spellDelay      = 550;
		//spd_102.extraEndTime    = 500;
		//spd_102.spellKey        = _W;
		//spd_102.spellName       = "CassiopeiaW";		
		//spd_102.spellType       = Line;
		//spd_102.isPerpendicular = true;
		////trapTroyName = "cassiopeia_base_w_wcircle_tar_" + Situation.EmitterTeam() + ".troy",
		////spd_102.hasTrap			= true;
		//vSpells->push_back(spd_102);

		//-------------------- Q:												
		SpellData spd_103;
		spd_103.charName        = "Cassiopeia";
		spd_103.dangerlevel     = 1;
		spd_103.missileName     = "CassiopeiaQ";
		spd_103.name            = "Noxious Blast";
		spd_103.projectileSpeed = FLT_MAX;
		spd_103.radius          = 205;					//game : 160, do < 200 thi trung, 201 ko trung, ko tinh boundRadius
		spd_103.range           = 900;
		spd_103.spellDelay      = 750;
		spd_103.spellKey        = _Q;
		spd_103.spellName       = "CassiopeiaQ";		
		spd_103.spellType       = Circular;
		vSpells->push_back(spd_103);
	//============== ## End.region Cassiopeia =================================
		
	//============== ##region Velkoz:
		//-------------------- Q-1:												
		SpellData spd_104;
		spd_104.charName        = "Velkoz";
		spd_104.dangerlevel     = 2;
		spd_104.missileName     = "VelkozQMissile";
		spd_104.name            = "Plasma Fission";
		spd_104.projectileSpeed = 1300;
		spd_104.radius          = 50;
		spd_104.range           = 1250;
		spd_104.spellDelay      = 250;
		spd_104.spellKey        = _Q1;
		spd_104.spellName       = "VelkozQ";		
		spd_104.spellType       = Line;
		spd_104.collisionObjects.push_back(EnemyMinions);
		spd_104.collisionObjects.push_back(EnemyChampions);
		spd_104.fixedRange	    = true;
		spd_104.waitExtra		= 0;
		vSpells->push_back(spd_104);
		
		//-------------------- Q-2:												
		SpellData spd_105;
		spd_105.charName        = "Velkoz";
		spd_105.dangerlevel     = 2;
		spd_105.missileName     = "VelkozQMissileSplit";					// co 2 MissileSplit nhung chi lay 1 cai
		spd_105.name            = "Plasma Fission (Split)";
		spd_105.projectileSpeed = 2100;
		spd_105.radius          = 45;
		spd_105.range           = 1100;
		spd_105.spellDelay      = 50;										// dung` tam., nen dung "Velkoz_Base_Q_SplitImplosion" thi tot hon
		spd_105.spellKey        = _Q2;
		spd_105.spellName       = "VelkozQSplitActivate";					// "VelkozQMissileSplit" : ko co trong pCastSpell
		spd_105.spellType       = Line;
		spd_105.collisionObjects.push_back(EnemyMinions);
		spd_105.collisionObjects.push_back(EnemyChampions);
		spd_105.waitExtra		= 0;
		spd_105.isSpecial_11x	= true;										// ko co  pCast, ko ne' o day
		spd_105.isSpecial_22x	= true;										// ne' missile vi delay = 50 (chua dc tot lam, lam TAM THOI)
		vSpells->push_back(spd_105);

		//-------------------- W:												
		SpellData spd_106;
		spd_106.charName        = "Velkoz";
		spd_106.dangerlevel     = 2;
		spd_106.missileName     = "VelkozWMissile";
		spd_106.name            = "Void Rift";
		spd_106.projectileSpeed = 1700;									//L#: 1700
		spd_106.radius          = 90;									//L#: 90
		spd_106.range           = 1200;
		spd_106.spellDelay      = 300;
		spd_106.extraEndTime    = 1000;
		spd_106.spellKey        = _W;
		spd_106.spellName       = "VelkozW";							//ko co trong pCastSpell	
		spd_106.spellType       = Line;
		spd_106.fixedRange	    = true;
		spd_106.waitExtra		= 0;
		spd_106.isSpecial_11x	= true;									// ko co  pCast, ko ne' o day
		spd_106.isSpecial_22x	= true;									// ne' missile vi delay = 300, chu yeu ne' phat' no thu 2 thoi
		vSpells->push_back(spd_106);

		//-------------------- E:												
		SpellData spd_107;
		spd_107.charName        = "Velkoz";
		spd_107.dangerlevel     = 3;
		spd_107.missileName     = "VelkozEMissile";
		spd_107.name            = "Tectonic Disruption";
		spd_107.projectileSpeed = 1500;									//L#: 1500
		spd_107.radius          = 215;
		spd_107.range           = 800;
		spd_107.spellDelay      = 350;									//L#: 250
		spd_107.spellKey        = _E;
		spd_107.spellName       = "VelkozE";	
		spd_107.waitExtra       = 225;
		spd_107.spellType       = Circular;
		spd_107.waitExtra		= 0;
		vSpells->push_back(spd_107);
	//============== ## End.region Velkoz =================================
		
	//============== ##region Lucian:
		//-------------------- W:												
		SpellData spd_108;
		spd_108.charName        = "Lucian";
		spd_108.dangerlevel     = 1;
		spd_108.defaultOff      = true;
		spd_108.missileName     = "LucianWMissile";
		spd_108.name            = "Ardent Blaze";
		spd_108.projectileSpeed = 1600;							//L#: 1600
		spd_108.radius          = 70;							//L#: 80
		spd_108.range           = 950;
		spd_108.spellDelay      = 250;
		spd_108.spellKey        = _W;
		spd_108.spellName       = "LucianW";		
		spd_108.spellType       = Line;
		spd_108.collisionObjects.push_back(EnemyMinions);
		spd_108.collisionObjects.push_back(EnemyChampions);
		spd_108.fixedRange	    = true;
		spd_108.hasEndExplosion = true;
		spd_108.waitExtra	    = 0;
		spd_108.secondaryRadius = 350;							//L#:145
		vSpells->push_back(spd_108);

		//-------------------- Q:												
		SpellData spd_109;
		spd_109.charName        = "Lucian";
		spd_109.dangerlevel     = 3;
		//spd_109.isSpecial		= true;
		spd_109.missileName     = "LucianQ";
		spd_109.name            = "Piercing Light";
		spd_109.projectileSpeed = FLT_MAX;									
		spd_109.radius          = 65;									
		spd_109.range           = 1140;
		spd_109.spellDelay      = 550;
		spd_109.spellKey        = _Q;
		spd_109.spellName       = "LucianQ";								
		spd_109.spellType       = Line;
		vSpells->push_back(spd_109);
		
		//-------------------- R:												
		SpellData spd_110;
		spd_110.charName        = "Lucian";
		spd_110.dangerlevel     = 2;
		spd_110.missileName     = "LucianRMissile";
		spd_110.extraMissileNames.push_back("lucianrmissileoffhand");
		spd_110.name            = "The Culling";
		spd_110.projectileSpeed = 2800;									
		spd_110.radius          = 80;									
		spd_110.range           = 1400;
		spd_110.spellDelay      = 500;
		spd_110.spellKey        = _R;
		spd_110.spellName       = "lucianrmis";					//sao gio ko con pCastSpell roi				
		spd_110.spellType       = Line;
		spd_110.collisionObjects.push_back(EnemyMinions);
		spd_110.collisionObjects.push_back(EnemyChampions);
		//spd_110.usePackets		= true;
		spd_110.fixedRange	    = true;
		vSpells->push_back(spd_110);
	//============== ## End.region Lucian =================================
		
	//============== ##region Syndra:
		//-------------------- Q:												
		SpellData spd_111;
		spd_111.charName        = "Syndra";
		spd_111.dangerlevel     = 2;
		spd_111.missileName     = "SyndraQSpell";						// ne' = missile nen delay=0, phai lam TH dac biet
		spd_111.name            = "Dark Sphere";
		spd_111.projectileSpeed = FLT_MAX;									
		spd_111.radius          = 190;									
		spd_111.range           = 800;
		spd_111.spellDelay      = 650;
		spd_111.spellKey        = _Q;
		spd_111.spellName       = "SyndraQ";							//ko co trong pCastSpell				
		spd_111.spellType       = Circular;
		spd_111.isSpecial_11x	= true;
		spd_111.isSpecial_22x	= true;
		vSpells->push_back(spd_111);

		//-------------------- W:												
		SpellData spd_111w;
		spd_111w.charName        = "Syndra";
		spd_111w.dangerlevel     = 2;
		spd_111w.missileName     = "SyndraW_Special";		//L#: "syndrawcast"
		spd_111w.name            = "Force of Will";
		spd_111w.projectileSpeed = 1450;									
		spd_111w.radius          = 220;									
		spd_111w.range           = 950;
		spd_111w.spellDelay      = 250;
		spd_111w.spellKey        = _W;
		spd_111w.spellName       = "SyndraWCast";							//ko co trong pCastSpell				
		spd_111w.spellType       = Circular;
		spd_111w.isSpecial_00x	 = true;
		spd_111w.isSpecial_11x	 = true;
		spd_111w.isSpecial_22x	 = true;
		spd_111w.waitExtra		 = 0;
		vSpells->push_back(spd_111w);
		
		//-------------------- E:												
		SpellData spd_111e;
		spd_111e.charName        = "Syndra";
		spd_111e.dangerlevel     = 3;
		spd_111e.missileName     = "SyndraESphereMissile";		
		spd_111e.name            = "Scatter the Weak";
		spd_111e.projectileSpeed = 2000;									
		spd_111e.radius          = 100;									
		spd_111e.range           = 1300;
		spd_111e.spellDelay      = 250;
		spd_111e.spellKey        = _E;
		spd_111e.spellName       = "SyndraE";	
		spd_111e.extraSpellNames.push_back("SyndraE5");
		spd_111e.spellType       = Line;
		spd_111e.isSpecial_11x	 = true;
		spd_111e.isSpecial_22x	 = true;
		spd_111e.waitExtra		 = 0;
		vSpells->push_back(spd_111e);
	//============== ## End.region Syndra =================================
	
	//============== ##region Viktor:
		//-------------------- E-1:												
		SpellData spd_112;
		spd_112.charName        = "Viktor";
		spd_112.dangerlevel     = 3;
		spd_112.missileName     = "ViktorDeathRayMissile";					
		spd_112.extraMissileNames.push_back("ViktorEAugMissile");
		spd_112.name            = "Death Ray";
		spd_112.projectileSpeed = 1050;									
		spd_112.radius          = 75;									
		spd_112.range           = 750;
		spd_112.spellDelay      = 950;
		spd_112.spellKey        = _E;
		spd_112.spellName       = "ViktorDeathRay";								//ViktorDeathRay: ko co trong pCastSpell				
		spd_112.fixedRange		= true;
		spd_112.spellType       = Line;
		spd_112.isSpecial_11x   = true;											//Ko ne' dc o day
		spd_112.isSpecial_22x   = true;											//E2 co delay nen su dung ne' o day
		vSpells->push_back(spd_112);

		//-------------------- W:												
		SpellData spd_114;
		spd_114.charName        = "Viktor";
		spd_114.dangerlevel     = 3;
		spd_114.defaultOff      = true;
		spd_114.missileName     = "ViktorW_NO";								//ko co missile, dung` :(Type: 1)[TeamID: 0](Viktor_Catalyst_green) :40000152, [Time: 92.875] - [cur: 2454.00,95.75,900.00] - [src: 0.00,0.00,-1.#R] [des: 0.00,0.00,4836513560989113400000000000000.00]
		spd_114.name            = "Graviton Field";
		spd_114.projectileSpeed = FLT_MAX;									
		spd_114.radius          = 350;									
		spd_114.range           = 800;
		spd_114.spellDelay      = 1500;
		spd_114.extraEndTime    = 2500;
		spd_114.spellKey        = _W;
		spd_114.spellName       = "ViktorGravitonField";					//"ViktorGravitonField"		
		spd_114.spellType       = Circular;
		spd_114.waitExtra       = 50;
		vSpells->push_back(spd_114);
	//============== ## End.region Viktor =================================
		
	//============== ##region Ziggs:
		//-------------------- E:												
		SpellData spd_115;
		spd_115.charName        = "Ziggs";
		spd_115.dangerlevel     = 1;
		spd_115.missileName     = "ZiggsE2";
		spd_115.name            = "Hexplosive Minefield";
		spd_115.projectileSpeed = 1850;									//L#:3000 - Game: 1750
		spd_115.radius          = 235;									
		spd_115.range           = 900;
		spd_115.spellDelay      = 250;
		spd_115.spellKey        = _E;
		spd_115.spellName       = "ZiggsE";										
		spd_115.spellType       = Circular;
		vSpells->push_back(spd_115);
		
		//-------------------- W:												
		SpellData spd_116;
		spd_116.charName        = "Ziggs";
		spd_116.dangerlevel     = 2;
		spd_116.missileName     = "ZiggsW";
		spd_116.name            = "Satchel Charge";
		spd_116.projectileSpeed = 1750;									//L#:2000 - Game: 1750	
		spd_116.radius          = 275;									
		spd_116.range           = 1000;
		spd_116.spellDelay      = 250;
		spd_116.extraEndTime	= 600;									//L#:1000
		spd_116.spellKey        = _W;
		spd_116.spellName       = "ZiggsW";										
		spd_116.spellType       = Circular;
		vSpells->push_back(spd_116);
		
		//-------------------- Q:												
		SpellData spd_117;
		spd_117.charName        = "Ziggs";
		spd_117.dangerlevel     = 2;
		spd_117.missileName     = "ZiggsQSpell";
		spd_117.name            = "Bouncing Bomb";
		spd_117.projectileSpeed = 1700;							//L#:1700		
		spd_117.radius          = 155;							//L#:150	, do < 150 thi trung, 151 ko trung, ko tinh boundRadius, vu no coi phai 225
		spd_117.range           = 850;							//L#:850
		spd_117.spellDelay      = 250;							//L#: 125
		spd_117.spellKey        = _Q;
		spd_117.spellName       = "ZiggsQ";											
		spd_117.spellType       = Circular;
		spd_117.waitExtra       = 0;
		spd_117.isSpecial_11x	= true;
		spd_117.isSpecial_22x	= true;
		vSpells->push_back(spd_117);
		
		//-------------------- R:												
		SpellData spd_118;
		spd_118.charName        = "Ziggs";
		spd_118.dangerlevel     = 4;
		spd_118.missileName     = "ZiggsRBoom";
		spd_118.extraMissileNames.push_back("ZiggsRBoomMedium");
		spd_118.extraMissileNames.push_back("ZiggsRBoomLong");
		spd_118.extraMissileNames.push_back("ZiggsRBoomExtraLong");
		spd_118.name            = "Mega Inferno Bomb";
		spd_118.projectileSpeed = 1550;									
		spd_118.radius          = 500;									
		spd_118.range           = 5300;
		spd_118.spellDelay      = 450;				//L#:400 - Game:250
		spd_118.spellKey        = _R;
		spd_118.spellName       = "ZiggsR";										
		spd_118.spellType       = Circular;
		spd_118.defaultOff		= true;
		spd_118.waitExtra		= 300;
		//spd_118.isSpecial_22x	= true;
		vSpells->push_back(spd_118);
	//============== ## End.region Ziggs =================================
		
	//============== ##region Zilean:
		//-------------------- Q-1:												
		SpellData spd_119;
		spd_119.charName        = "Zilean";
		spd_119.dangerlevel     = 3;
		spd_119.missileName     = "ZileanQMissile";
		spd_119.name            = "Time Bomb";
		spd_119.projectileSpeed = 6000;									
		spd_119.radius          = 225;									
		spd_119.range           = 900;
		spd_119.spellDelay      = 750;				//delay luon = 0.47 + 0.25s
		spd_119.extraEndTime	= 1000;
		spd_119.spellKey        = _Q;
		spd_119.spellName       = "ZileanQ";										
		spd_119.spellType       = Circular;
		spd_119.waitExtra       = 0;
		//spd_119.isSpecial	    = true;
		vSpells->push_back(spd_119);

		////-------------------- Q-trap:												
		//	charName = "Zilean",
		//	dangerlevel = 3,
		//	spellName = "ZileanQ",
		//	name = "Time Bomb",
		//	radius = 160,
		//	range = 900,
		//	spellKey = SpellSlot.Q,
		//	spellType = SpellType.Circular,
		//	trapTroyName = "zilean_base_q_timebombground" + Situation.EmitterColor() + ".troy",
		//	extraDrawHeight = -100,
		//	hasTrap = true
	//============== ## End.region Zilean =================================

	//============== ##region Chogath:
		//-------------------- W:												
		SpellData spd_120;
		spd_120.angle	        = 28;					//L#:30
		spd_120.charName        = "Chogath";
		spd_120.dangerlevel     = 2;
		spd_120.missileName     = "FeralScream";		//ko co missile
		spd_120.name            = "Feral Scream";
		spd_120.projectileSpeed = FLT_MAX;									
		spd_120.radius          = 80;									
		spd_120.range           = 625;
		spd_120.spellDelay      = 500;
		spd_120.spellKey        = _W;
		spd_120.spellName       = "FeralScream";										
		spd_120.spellType       = Cone;
		vSpells->push_back(spd_120);

		//-------------------- Q:												
		SpellData spd_121;
		spd_121.charName        = "Chogath";
		spd_121.dangerlevel     = 3;
		spd_121.missileName     = "Rupture";			//ko co missile
		spd_121.name            = "Rupture";
		spd_121.projectileSpeed = FLT_MAX;									
		spd_121.radius          = 250;									
		spd_121.range           = 950;
		spd_121.spellDelay      = 1200;
		spd_121.spellKey        = _Q;
		spd_121.spellName       = "Rupture";										
		spd_121.spellType       = Circular;
		vSpells->push_back(spd_121);
	//============== ## End.region Chogath =================================
		
	//============== ##region Darius:
		//-------------------- E:												
		SpellData spd_122;
		spd_122.angle	        = 25;					
		spd_122.charName        = "Darius";
		spd_122.dangerlevel     = 3;
		spd_122.missileName     = "DariusAxeGrabCone";		
		spd_122.name            = "Axe Cone Grab";
		spd_122.projectileSpeed = FLT_MAX;									
		spd_122.radius          = 55;									
		spd_122.range           = 570;
		spd_122.spellDelay      = 450;
		spd_122.spellKey        = _E;
		spd_122.spellName       = "DariusAxeGrabCone";										
		spd_122.spellType       = Cone;
		spd_122.waitExtra		= 0;
		vSpells->push_back(spd_122);

		////-------------------- Q:												
		//SpellData spd_123;
		//spd_123.charName        = "Darius";
		//spd_123.dangerlevel     = 2;
		//spd_123.defaultOff		= true;
		//spd_123.missileName     = "DariusCleave";			//ko co missile
		//spd_123.name            = "Decimate";
		//spd_123.projectileSpeed = FLT_MAX;									
		//spd_123.radius          = 425;									
		//spd_123.range           = 425;
		//spd_123.spellDelay      = 750;
		//spd_123.spellKey        = _Q;
		//spd_123.spellName       = "DariusCleave";										
		//spd_123.spellType       = Circular;
		//vSpells->push_back(spd_123);
	//============== ## End.region Darius =================================
		
	//============== ##region Diana:
		//-------------------- Q:												
		SpellData spd_124;				
		spd_124.charName        = "Diana";
		spd_124.dangerlevel     = 3;		
		spd_124.missileName     = "DianaArc_xx";					//ko co missile(DianaArcThrow, DianaArcThrowInnerDianaArcThrowOuter .. -> ko chuan)
		spd_124.name            = "Crescent Strike";
		spd_124.projectileSpeed = 1400;									
		spd_124.radius          = 50;									
		spd_124.range           = 850;
		spd_124.fixedRange		= true;
		spd_124.spellDelay      = 250;
		spd_124.spellKey        = _Q;
		spd_124.spellName       = "DianaArc";										
		spd_124.spellType       = Arc_x;
		spd_124.hasEndExplosion	= true;
		spd_124.secondaryRadius	= 195;
		spd_124.extraEndTime	= 250;
		vSpells->push_back(spd_124);
	//============== ## End.region Diana =================================
		
	//============== ##region Ekko:
		//-------------------- Q-1:												
		SpellData spd_125;				
		spd_125.charName        = "Ekko";
		spd_125.dangerlevel     = 3;		
		spd_125.missileName     = "EkkoQMis";					
		spd_125.name            = "Timewinder";
		spd_125.projectileSpeed = 1650;									
		spd_125.radius          = 60;									
		spd_125.range           = 950;
		spd_125.spellDelay      = 250;
		spd_125.spellKey        = _Q1;
		spd_125.spellName       = "EkkoQ";										
		spd_125.spellType       = Line;
		spd_125.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_125);

		//-------------------- Q-2:												
		SpellData spd_126;				
		spd_126.charName        = "Ekko";
		spd_126.dangerlevel     = 3;		
		spd_126.missileName     = "ekkoqreturn";					
		spd_126.name            = "Timewinder (Return)";
		spd_126.projectileSpeed = 2300;									
		spd_126.radius          = 100;									
		spd_126.range           = 1250;
		spd_126.spellDelay      = 0;
		spd_126.spellKey        = _Q2;
		spd_126.spellName       = "ekkoqreturn";				//ko co trong pCastSpell							
		spd_126.spellType       = Line;
		vSpells->push_back(spd_126);

		//-------------------- W:												
		SpellData spd_127;				
		spd_127.charName        = "Ekko";
		spd_127.dangerlevel     = 2;		
		spd_127.missileName     = "EkkoWMis_x";						
		spd_127.name            = "Parallel Convergence";
		spd_127.projectileSpeed = FLT_MAX;									
		spd_127.radius          = 375;									
		spd_127.range           = 1750;
		spd_127.spellDelay      = 3250;
		spd_127.spellKey        = _W;
		spd_127.spellName       = "EkkoW";											
		spd_127.spellType       = Circular;
		spd_127.waitExtra       = 400;
		vSpells->push_back(spd_127);

		////-------------------- R:												
		//SpellData spd_128;				
		//spd_128.charName        = "Ekko";
		//spd_128.dangerlevel     = 4;		
		//spd_128.missileName     = "EkkoR";						//ko co missile
		//spd_128.name            = "Chronobreak";
		//spd_128.projectileSpeed = 1650;									
		//spd_128.radius          = 375;									
		//spd_128.range           = 1600;
		//spd_128.spellDelay      = 250;
		//spd_128.spellKey        = _R;
		//spd_128.spellName       = "EkkoR";											
		//spd_128.spellType       = Circular;
		//spd_128.isSpecial		= true;
		//vSpells->push_back(spd_128);
	//============== ## End.region Ekko =================================
	
	//============== ##region Fizz:
		////-------------------- Q:												
		//SpellData spd_129;				
		//spd_129.charName        = "Fizz";
		//spd_129.dangerlevel     = 2;		
		//spd_129.missileName     = "FizzQ";					//xx	
		//spd_129.name            = "Urchin Strike";
		//spd_129.projectileSpeed = 1400;									
		//spd_129.radius          = 150;									
		//spd_129.range           = 550;
		//spd_129.spellDelay      = 0;
		//spd_129.spellKey        = _Q;
		//spd_129.spellName       = "FizzQ";										
		//spd_129.spellType       = Line;
		////spd_129.isSpecial		= true;
		//vSpells->push_back(spd_129);

		//-------------------- R:												
		SpellData spd_130;				
		spd_130.charName        = "Fizz";
		spd_130.dangerlevel     = 4;		
		spd_130.missileName     = "FizzRMissile";					
		spd_130.name            = "Chum the Waters";
		spd_130.projectileSpeed = 1350;									
		spd_130.radius          = 110;									
		spd_130.range           = 1300;
		spd_130.spellDelay      = 250;
		spd_130.spellKey        = _R;
		spd_130.spellName       = "FizzR";											
		spd_130.spellType       = Line;
		spd_130.hasEndExplosion = true;
		spd_130.useEndPosition  = true;
		spd_130.secondaryRadius = 450;
		//spd_130.isSpecial		= true;
		spd_130.waitExtra		= 0;
		vSpells->push_back(spd_130);
	//============== ## End.region Fizz =================================
	
	//============== ##region Galio:
		//-------------------- Q:												
		SpellData spd_131;				
		spd_131.charName        = "Galio";
		spd_131.dangerlevel     = 2;		
		spd_131.missileName     = "GalioQMissile";						//se co 2 ne'Q vi goc >10
		//spd_131.extraMissileNames.push_back("GalioQMissileR");					
		spd_131.name            = "Winds of War";
		spd_131.projectileSpeed = 1300;									
		spd_131.radius          = 250;									
		spd_131.range           = 850;
		//spd_131.fixedRange		= true;
		spd_131.spellDelay      = 300;
		spd_131.spellKey        = _Q;
		spd_131.spellName       = "GalioQ";										
		spd_131.spellType       = Circular;
		spd_131.extraEndTime	= 1200;
		vSpells->push_back(spd_131);

		//-------------------- E:												
		SpellData spd_132;				
		spd_132.charName        = "Galio";
		spd_132.dangerlevel     = 3;		
		spd_132.missileName     = "GalioE";							//ko co missile	
		spd_132.name            = "Justice Punch";
		spd_132.projectileSpeed = 1400;									
		spd_132.radius          = 150;									
		spd_132.range           = 820;
		spd_132.spellDelay      = 500;
		spd_132.spellKey        = _E;
		spd_132.spellName       = "GalioE";										
		spd_132.spellType       = Line;
		spd_132.waitExtra		= 0;
		vSpells->push_back(spd_132);

		//-------------------- R:												
		SpellData spd_133;				
		spd_133.charName        = "Galio";
		spd_133.dangerlevel     = 3;		
		spd_133.missileName     = "GalioRMissile";					//ko co missile		
		spd_133.name            = "Hero's Entrance";
		spd_133.projectileSpeed = 10000;									
		spd_133.radius          = 675;									
		spd_133.range           = 5500;
		spd_133.spellDelay      = 1250;
		spd_133.spellKey        = _R;
		spd_133.spellName       = "GalioR";											
		spd_133.spellType       = Circular;
		//spd_133.waitExtra		= 0;
		vSpells->push_back(spd_133);
	//============== ## End.region Galio =================================

	//============== ##region Gnar:
		//-------------------- Q-1:												
		SpellData spd_134;				
		spd_134.charName        = "Gnar";
		spd_134.dangerlevel     = 2;		
		spd_134.missileName     = "GnarQMissile";						
		//spd_134.extraMissileNames.push_back("GnarQMissileReturn");	//choi duoc nhung speedMis cham, lay 2500 nhu Q1 la ko on			
		spd_134.name            = "Boomerang Throw";
		spd_134.projectileSpeed = 2250;									//Game: 2500					
		spd_134.radius          = 55;									
		spd_134.range           = 1150;
		spd_134.spellDelay      = 250;
		spd_134.spellKey        = _Q1;
		spd_134.spellName       = "GnarQMissile";										
		spd_134.spellType       = Line;
		spd_134.collisionObjects.push_back(EnemyMinions);
		spd_134.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_134);
			
		//-------------------- Q-2:		(Big)										
		SpellData spd_135;				
		spd_135.charName        = "Gnar";
		spd_135.dangerlevel     = 2;		
		spd_135.missileName     = "GnarBigQMissile";										
		spd_135.name            = "Boulder Toss";
		spd_135.projectileSpeed = 2100;									
		spd_135.radius          = 90;									
		spd_135.range           = 1000;
		spd_135.spellDelay      = 500;
		spd_135.spellKey        = _Q2;
		spd_135.spellName       = "GnarBigQMissile";										
		spd_135.spellType       = Line;
		spd_135.collisionObjects.push_back(EnemyMinions);
		spd_135.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_135);
	
		//-------------------- W:												
		SpellData spd_136;				
		spd_136.charName        = "Gnar";
		spd_136.dangerlevel     = 3;		
		spd_136.missileName     = "gnarbigw";								
		spd_136.name            = "Wallop";
		spd_136.projectileSpeed = FLT_MAX;									
		spd_136.radius          = 95;									
		spd_136.range           = 625;
		spd_136.spellDelay      = 600;
		spd_136.spellKey        = _W;
		spd_136.spellName       = "GnarBigW";										
		spd_136.spellType       = Line;
		vSpells->push_back(spd_136);

		//-------------------- R:												
		SpellData spd_137;				
		spd_137.charName        = "Gnar";
		spd_137.dangerlevel     = 4;		
		spd_137.missileName     = "GnarR_NO";							
		spd_137.name            = "GNAR!";
		spd_137.projectileSpeed = 0;									
		spd_137.radius          = 475;									
		spd_137.range           = 475;
		spd_137.spellDelay      = 200;
		spd_137.spellKey        = _R;
		spd_137.spellName       = "GnarR";											
		spd_137.spellType       = Circular;
		vSpells->push_back(spd_137);
		
		//-------------------- E-1:												
		SpellData spd_138;				
		spd_138.charName        = "Gnar";
		spd_138.dangerlevel     = 2;		
		spd_138.missileName     = "GnarE1_Ss";						
		spd_138.name            = "Hop(E1)";
		spd_138.projectileSpeed = 950;							//dash-speed-game: 904.2, L#: 880					
		spd_138.radius          = 165;									
		spd_138.range           = 475;
		spd_138.spellDelay      = 0;
		spd_138.spellKey        = _E1;
		spd_138.spellName       = "GnarE";											
		spd_138.spellType       = Circular;
		spd_138.isSpecial_11x   = true;
		spd_138.isSpecial_22x   = true;
		vSpells->push_back(spd_138);

		//-------------------- E-2:												
		SpellData spd_139;				
		spd_139.charName        = "Gnar";
		spd_139.dangerlevel     = 2;		
		spd_139.missileName     = "GnarE2_Ss";						
		spd_139.name            = "Crunch(E-Big)";
		spd_139.projectileSpeed = 800;							//dash-speed-game: 1009.511658								
		spd_139.radius          = 300;									
		spd_139.range           = 475;
		spd_139.spellDelay      = 0;
		spd_139.spellKey        = _E2;
		spd_139.spellName       = "gnarbige";											
		spd_139.spellType       = Circular;
		spd_139.isSpecial_11x   = true;
		spd_139.isSpecial_22x   = true;
		vSpells->push_back(spd_139);
	//============== ## End.region Gnar =================================
		
	//============== ##region Gragas:
		//-------------------- Q:												
		SpellData spd_140;				
		spd_140.charName        = "Gragas";
		spd_140.dangerlevel     = 2;		
		spd_140.missileName     = "GragasQMissile";											
		spd_140.name            = "Barrel Roll";
		spd_140.projectileSpeed = 1000;									
		spd_140.radius          = 275;									
		spd_140.range           = 975;
		spd_140.spellDelay      = 450;
		spd_140.extraEndTime    = 300;
		spd_140.spellKey        = _Q;
		spd_140.spellName       = "GragasQ";										
		spd_140.spellType       = Circular;
		spd_140.waitExtra       = 150;							
		vSpells->push_back(spd_140);

		//-------------------- E:												
		SpellData spd_140E;				
		spd_140E.charName        = "Gragas";
		spd_140E.dangerlevel     = 3;		
		spd_140E.missileName     = "GragasE_Ss";											
		spd_140E.name            = "Body Slam";
		spd_140E.projectileSpeed = 1000;								//L#: 1200, dash-speed-game : 913		
		spd_140E.radius          = 145;									
		spd_140E.range           = 750;
		spd_140E.spellDelay      = 0;
		spd_140E.spellKey        = _E;
		spd_140E.spellName       = "GragasE";										
		spd_140E.spellType       = Line;
		spd_140E.waitExtra		 = 150;
		spd_140E.collisionObjects.push_back(EnemyMinions);
		spd_140E.collisionObjects.push_back(EnemyChampions);
		spd_140E.isSpecial_11x   = true;							
		spd_140E.isSpecial_22x   = true;							
		vSpells->push_back(spd_140E);

		//-------------------- R:												
		SpellData spd_141;				
		spd_141.charName        = "Gragas";
		spd_141.dangerlevel     = 4;		
		spd_141.missileName     = "GragasRBoom";							
		spd_141.name            = "Explosive Cask";
		spd_141.projectileSpeed = 1650;					//Game: 1800(missile)					
		spd_141.radius          = 350;									
		spd_141.range           = 1050;
		spd_141.spellDelay      = 350;
		spd_141.spellKey        = _R;
		spd_141.spellName       = "GragasR";											
		spd_141.spellType       = Circular;
		spd_141.waitExtra       = 0;
		vSpells->push_back(spd_141);
	//============== ## End.region Gragas =================================
				
	//============== ##region Graves:
		////-------------------- Q-1:												
		//SpellData spd_142;				
		//spd_142.charName        = "Graves";
		//spd_142.dangerlevel     = 2;		
		//spd_142.missileName     = "GravesQLineMis";												
		//spd_142.name            = "End of the Line";
		//spd_142.projectileSpeed = 3000;									
		//spd_142.radius          = 72;									
		//spd_142.range           = 801;
		//spd_142.spellDelay      = 250;
		//spd_142.spellKey        = _Q;
		//spd_142.spellName       = "GravesQLineSpell";												
		//spd_142.spellType       = Line;
		//spd_142.fixedRange		= true;
		////spd_142.waitExtra       = 0;
		//vSpells->push_back(spd_142);
		
		//-------------------- Q-1+2:												
		SpellData spd_143;			
		spd_143.charName        = "Graves";
		spd_143.dangerlevel     = 2;		
		spd_143.missileName     = "GravesQLineMis";					//ko can dung missile						
		spd_143.name            = "End of the Line + Return";
		spd_143.projectileSpeed = 3000;									
		spd_143.radius          = 55;									
		spd_143.range           = 825;								//964 --> an dan.
		spd_143.spellDelay      = 250;
		spd_143.spellKey        = _Q;
		spd_143.spellName       = "GravesQLineSpell";											
		spd_143.spellType       = Line;
		spd_143.isSpecial_11x	= true;								
		spd_143.isSpecial_22x	= true;
		spd_143.waitExtra       = 0;
		vSpells->push_back(spd_143);

		//-------------------- W:												
		SpellData spd_144;				
		spd_144.charName        = "Graves";
		spd_144.dangerlevel     = 1;
		spd_144.defaultOff		= true;
		spd_144.missileName     = "GravesSmokeGrenadeBoom";											
		spd_144.name            = "Smoke Screen";
		spd_144.projectileSpeed = 1650;									
		spd_144.radius          = 230;									
		spd_144.range           = 900;
		spd_144.spellDelay      = 250;
		spd_144.spellKey        = _W;
		spd_144.spellName       = "GravesSmokeGrenade";			//xxx	GravesSmokeGrenade						
		spd_144.spellType       = Circular;
		vSpells->push_back(spd_144);

		//-------------------- R:												
		SpellData spd_145;				
		spd_145.charName        = "Graves";
		spd_145.dangerlevel     = 4;		
		spd_145.missileName     = "GravesChargeShotShot";							
		spd_145.name            = "Collateral Damage";
		spd_145.projectileSpeed = 1700;									//L#: 2100
		spd_145.radius          = 110;									
		spd_145.range           = 1225;
		spd_145.spellDelay      = 250;
		spd_145.spellKey        = _R;
		spd_145.spellName       = "GravesChargeShot";											
		spd_145.spellType       = Line;
		spd_145.waitExtra       = 0;
		spd_145.fixedRange		= true;
		vSpells->push_back(spd_145);

		////-------------------- R:												
		//SpellData spd_146;				
		//spd_146.charName        = "Graves";
		//spd_146.angle			= 32;
		//spd_146.dangerlevel     = 4;		
		//spd_146.missileName     = "Graves_R2_xx";				//"GravesChargeShotFxMissile", "GravesChargeShotFxMissile2"
		//spd_146.name            = "Collateral Damage (Explosion-R2)";
		//spd_146.projectileSpeed = 2000;									
		//spd_146.radius          = 100;									
		//spd_146.range           = 750;
		//spd_146.spellDelay      = 250;
		//spd_146.spellKey        = 12;
		//spd_146.spellName       = "GravesR2_Special";											
		//spd_146.spellType       = Cone;
		//spd_146.waitExtra       = 0;
		//spd_146.isSpecial_11x	= true;
		//spd_146.isSpecial_22x	= true;
		//vSpells->push_back(spd_146);
	//============== ## End.region Graves =================================

	//============== ##region Hecarim:
		//-------------------- R:												
		SpellData spd_147;				
		spd_147.charName        = "Hecarim";
		spd_147.dangerlevel     = 4;		
		spd_147.missileName     = "HecarimUltMissile";	
		spd_147.extraMissileNames.push_back("HecarimUltMissileSkn4R1");
		spd_147.extraMissileNames.push_back("HecarimUltMissileSkn4c");
		spd_147.extraMissileNames.push_back("HecarimUltMissileSkn4R2");
		spd_147.extraMissileNames.push_back("HecarimUltMissileSKn4L2");
		spd_147.extraMissileNames.push_back("HecarimUltMissileSkn4L1");
		spd_147.name            = "Onslaught of Shadows";
		spd_147.projectileSpeed = 1100;									
		spd_147.radius          = 85;									
		spd_147.range           = 1525;
		spd_147.spellDelay      = 0;
		spd_147.spellKey        = _R;
		spd_147.spellName       = "HecarimUltMissile";										
		spd_147.spellType       = Line;
		spd_147.fixedRange		= true;
		spd_147.waitExtra       = 0;
		//spd_147.usePackets    = true;
		vSpells->push_back(spd_147);
	//============== ## End.region Hecarim =================================
		
	//============== ##region Heimerdinger:
		//-------------------- W:												
		SpellData spd_148;				
		spd_148.charName        = "Heimerdinger";
		spd_148.dangerlevel     = 2;		
		spd_148.missileName     = "HeimerdingerWAttack2";	
		spd_148.extraMissileNames.push_back("HeimerdingerWAttack2Ult");
		spd_148.name            = "Hextech Micro-Rockets";
		spd_148.projectileSpeed = 1700;									
		spd_148.radius          = 70;									
		spd_148.range           = 1350;
		spd_148.spellDelay      = 250;
		spd_148.spellKey        = _W;
		spd_148.spellName       = "HeimerdingerW";										
		spd_148.spellType       = Line;
		vSpells->push_back(spd_148);

		//-------------------- E:												
		SpellData spd_149;				
		spd_149.charName        = "Heimerdinger";
		spd_149.dangerlevel     = 3;		
		spd_149.missileName     = "HeimerdingerESpell";	
		//spd_149.extraMissileNames.push_back("heimerdingerespell_ult");
		//spd_149.extraMissileNames.push_back("heimerdingerespell_ult2");
		//spd_149.extraMissileNames.push_back("heimerdingerespell_ult3");
		spd_149.name            = "CH-2 Electron Storm Grenade";
		spd_149.projectileSpeed = 1200;									
		spd_149.radius          = 230;									
		spd_149.range           = 925;
		spd_149.spellDelay      = 300;
		spd_149.spellKey        = _E;
		spd_149.spellName       = "HeimerdingerE";	
		//spd_149.extraSpellNames.push_back("HeimerdingerEUlt");
		spd_149.spellType       = Circular;
		spd_149.waitExtra       = 125;
		vSpells->push_back(spd_149);

		////-------------------- E:												
		//SpellData spd_149a;				
		//spd_149a.charName        = "Heimerdinger";
		//spd_149a.dangerlevel     = 3;		
		//spd_149a.missileName     = "heimerdingerespell_ult";	
		//spd_149a.extraMissileNames.push_back("heimerdingerespell_ult2");
		//spd_149a.extraMissileNames.push_back("heimerdingerespell_ult3");
		//spd_149a.name            = "CH-2 Electron Storm Grenade";
		//spd_149a.projectileSpeed = 1200;									
		//spd_149a.radius          = 200;									
		//spd_149a.range           = 925;
		//spd_149a.spellDelay      = 300;
		//spd_149a.spellKey        = 12;
		//spd_149a.spellName       = "HeimerdingerEUlt";	
		//spd_149a.spellType       = Line;
		//spd_149a.waitExtra       = 125;
		//vSpells->push_back(spd_149a);

		//-------------------- Q:												
		SpellData spd_150;				
		spd_150.charName        = "Heimerdinger";
		spd_150.dangerlevel     = 2;		
		spd_150.missileName     = "HeimerdingerTurretEnergyBlast";	//HeimerTYellowBasicAttack
		spd_150.name            = "Turret Energy Blast";
		spd_150.projectileSpeed = 1500;									
		spd_150.radius          = 50;									
		spd_150.range           = 1000;
		spd_150.spellDelay      = 435;
		spd_150.missileDelay    = 50;
		spd_150.spellKey        = _Q1;
		spd_150.spellName       = "HeimerdingerTurretEnergyBlast";	
		spd_150.spellType       = Line;
		//spd_150.isSpecial		= true;
		spd_150.waitExtra       = 125;
		vSpells->push_back(spd_150);

		//-------------------- Q-2:												
		SpellData spd_151;				
		spd_151.charName        = "Heimerdinger";
		spd_151.dangerlevel     = 3;		
		spd_151.missileName     = "HeimerdingerTurretBigEnergyBlast";	
		spd_151.name            = "Big Turret Energy Blast";
		spd_151.projectileSpeed = 1600;									
		spd_151.radius          = 60;									
		spd_151.range           = 1000;
		spd_151.spellDelay      = 450;
		spd_151.missileDelay    = 50;
		spd_151.spellKey        = _Q2;		//Q_2
		spd_151.spellName       = "HeimerdingerTurretBigEnergyBlast";	
		spd_151.spellType       = Line;
		spd_151.waitExtra       = 125;
		vSpells->push_back(spd_151);
	//============== ## End.region Heimerdinger =================================

	//============== ##region Illaoi:
		//-------------------- Q:												
		SpellData spd_152;				
		spd_152.charName        = "Illaoi";
		spd_152.dangerlevel     = 3;		
		spd_152.missileName     = "IllaoiQ";				//ko co missile
		spd_152.name            = "Tentacle Smash";
		spd_152.projectileSpeed = 8000;									
		spd_152.radius          = 100;									
		spd_152.range           = 875;
		spd_152.spellDelay      = 750;
		spd_152.spellKey        = _Q;
		spd_152.spellName       = "IllaoiQ";										
		spd_152.spellType       = Line;
		spd_152.fixedRange		= true;
		vSpells->push_back(spd_152);
		
		//-------------------- E:												
		SpellData spd_153;				
		spd_153.charName        = "Illaoi";
		spd_153.dangerlevel     = 3;		
		spd_153.missileName     = "IllaoiEMis";	
		spd_153.name            = "Test of Spirit";
		spd_153.projectileSpeed = 1900;									
		spd_153.radius          = 50;									
		spd_153.range           = 950;
		spd_153.spellDelay      = 250;
		spd_153.spellKey        = _E;
		spd_153.spellName       = "IllaoiE";	
		spd_153.spellType       = Line;
		spd_153.fixedRange		= true;
		spd_153.collisionObjects.push_back(EnemyMinions);
		vSpells->push_back(spd_153);

		//-------------------- R:												
		SpellData spd_154;				
		spd_154.charName        = "Illaoi";
		spd_154.dangerlevel     = 3;		
		spd_154.missileName     = "IllaoiR_NO";				//ko co missile
		spd_154.name            = "Leap of Faith";
		spd_154.projectileSpeed = 0;						//=0 de destPos = enemyPos, ko co missile nen ko sao			
		spd_154.radius          = 450;									
		spd_154.range           = 500;
		spd_154.spellDelay      = 500;
		spd_154.spellKey        = _R;		
		spd_154.spellName       = "IllaoiR";	
		spd_154.spellType       = Circular;
		vSpells->push_back(spd_154);
	//============== ## End.region Illaoi =================================	

	//============== ##region Irelia:
		//-------------------- W:												
		SpellData spd_155;				
		spd_155.charName        = "Irelia";
		spd_155.dangerlevel     = 2;		
		spd_155.missileName     = "IreliaW2";				
		spd_155.name            = "Defiant Dance";
		spd_155.projectileSpeed = 2250;									
		spd_155.radius          = 120;									
		spd_155.range           = 825;
		spd_155.spellDelay      = 250;
		spd_155.spellKey        = _W;
		spd_155.spellName       = "IreliaW2";										
		spd_155.spellType       = Line;
		spd_155.waitExtra		= 0;
		vSpells->push_back(spd_155);

		//-------------------- E:												
		SpellData spd_155E;				
		spd_155E.charName        = "Irelia";
		spd_155E.dangerlevel     = 3;		
		spd_155E.missileName     = "IreliaEMissile";						// dan nay dung de tinh 2 kiem
		spd_155E.extraMissileNames.push_back("IreliaEParticleMissile");		// dan nay dung de tinh 1 kiem
		spd_155E.extraMissileNames.push_back("IreliaESecondary");			// dan nay dung de set toa do kiem 1 = 0
		spd_155E.name            = "Flawless Duet";
		spd_155E.projectileSpeed = 500;									
		spd_155E.radius          = 70;									
		spd_155E.range           = 1700;
		spd_155E.spellDelay      = 350;
		spd_155E.spellKey        = _E;
		spd_155E.spellName       = "IreliaE";	
		//spd_155E.extraSpellNames.push_back("IreliaE2");
		spd_155E.spellType       = Line;
		spd_155E.isSpecial_11x	 = true;
		spd_155E.isSpecial_22x	 = true;
		spd_155E.waitExtra		 = 0;
		vSpells->push_back(spd_155E);

		//-------------------- R:												
		SpellData spd_156;				
		spd_156.charName        = "Irelia";
		spd_156.dangerlevel     = 2;		
		spd_156.missileName     = "IreliaR";	
		spd_156.name            = "Vanguard's Edge";
		spd_156.projectileSpeed = 1800;									
		spd_156.radius          = 160;									
		spd_156.range           = 1025;
		spd_156.spellDelay      = 400;
		spd_156.spellKey        = _R;
		spd_156.spellName       = "IreliaR";	
		spd_156.spellType       = Line;
		vSpells->push_back(spd_156);
	//============== ## End.region Irelia =================================	

	//============== ##region Ivern:
		//-------------------- Q:												
		SpellData spd_157;				
		spd_157.charName        = "Ivern";
		spd_157.dangerlevel     = 3;		
		spd_157.missileName     = "IvernQ";				
		spd_157.name            = "Rootcaller";
		spd_157.projectileSpeed = 1300;									
		spd_157.radius          = 65;									
		spd_157.range           = 1110;
		spd_157.spellDelay      = 250;
		spd_157.spellKey        = _Q;
		spd_157.spellName       = "IvernQ";										
		spd_157.spellType       = Line;
		spd_157.collisionObjects.push_back(EnemyMinions);
		spd_157.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_157);
	//============== ## End.region Ivern =================================	

	//============== ##region JarvanIV:
		//-------------------- Q:												
		SpellData spd_158;				
		spd_158.charName        = "JarvanIV";
		spd_158.dangerlevel     = 2;		
		spd_158.missileName     = "JarvanIVDragonStrike";				//ko co missile
		spd_158.name            = "Dragon Strike";
		spd_158.projectileSpeed = 1900;									
		spd_158.radius          = 80;									
		spd_158.range           = 845;
		spd_158.spellDelay      = 250;				//Game:400
		spd_158.spellKey        = _Q;
		spd_158.spellName       = "JarvanIVDragonStrike";										
		spd_158.spellType       = Line;
		spd_158.waitExtra       = 0;
		vSpells->push_back(spd_158);

		////-------------------- EQ:												
		//SpellData spd_158a;				
		//spd_158a.charName        = "JarvanIV";
		//spd_158a.dangerlevel     = 3;		
		//spd_158a.missileName     = "JarvanIVDragonStrike2";				//ko co missile		
		//spd_158a.name            = "Dragon Strike EQ";
		//spd_158a.projectileSpeed = 1750;								//L#: 1800						
		//spd_158a.radius          = 120;									
		//spd_158a.range           = 845;
		//spd_158a.spellDelay      = 250;
		//spd_158a.spellKey        = 11;
		//spd_158a.spellName       = "JarvanIVDragonStrike2";										
		//spd_158a.spellType       = Line;
		//spd_158a.useEndPosition  = true;
		//vSpells->push_back(spd_158a);

		////-------------------- E:												
		//SpellData spd_159;				
		//spd_159.charName        = "JarvanIV";
		//spd_159.dangerlevel     = 1;		
		//spd_159.missileName     = "JarvanIVDemacianStandard";				
		//spd_159.name            = "Demacian Standard";
		//spd_159.projectileSpeed = FLT_MAX;									
		//spd_159.radius          = 175;									
		//spd_159.range           = 800;
		//spd_159.spellDelay      = 500;
		//spd_159.spellKey        = _E;
		//spd_159.spellName       = "JarvanIVDemacianStandard";										
		//spd_159.spellType       = Circular;
		//vSpells->push_back(spd_159);

		////-------------------- R:												
		//SpellData spd_160;				
		//spd_160.charName        = "JarvanIV";
		//spd_160.dangerlevel     = 3;	
		//spd_160.defaultOff		= true;
		//spd_160.missileName     = "JarvanIVCataclysm";				
		//spd_160.name            = "Cataclysm";
		//spd_160.projectileSpeed = 1900;									
		//spd_160.radius          = 350;									
		//spd_160.range           = 825;
		//spd_160.spellDelay      = 0;
		//spd_160.spellKey        = _R;
		//spd_160.spellName       = "JarvanIVCataclysm";										
		//spd_160.spellType       = Circular;
		//vSpells->push_back(spd_160);
	//============== ## End.region JarvanIV =================================

	//============== ##region Karma:
		//-------------------- Q:												
		SpellData spd_161;				
		spd_161.charName        = "Karma";
		spd_161.dangerlevel     = 2;		
		spd_161.missileName     = "KarmaQMissile";	
		spd_161.extraMissileNames.push_back("KarmaQMissileMantra");
		spd_161.name            = "Inner Flame";
		spd_161.projectileSpeed = 1700;									
		spd_161.radius          = 60;									
		spd_161.range           = 950;
		spd_161.spellDelay      = 250;				
		spd_161.spellKey        = _Q;
		spd_161.spellName       = "KarmaQ";										
		spd_161.spellType       = Line;
		spd_161.waitExtra       = 0;
		spd_161.collisionObjects.push_back(EnemyMinions);
		spd_161.collisionObjects.push_back(EnemyChampions);
		spd_161.isSpecial_11x	= true;
		spd_161.isSpecial_22x	= true;
		spd_161.fixedRange		= true;
		vSpells->push_back(spd_161);
		
		////-------------------- R-Q:												
		//SpellData spd_162;				
		//spd_162.charName        = "Karma";
		//spd_162.dangerlevel     = 3;		
		//spd_162.missileName     = "KarmaQMissileMantra";				
		//spd_162.name            = "Soulflare (Mantra)";
		//spd_162.projectileSpeed = 1700;									
		//spd_162.radius          = 80;									
		//spd_162.range           = 1050;
		//spd_162.spellDelay      = 250;				
		//spd_162.spellKey        = 11;
		//spd_162.spellName       = "KarmaQMissileMantra";										
		//spd_162.spellType       = Line;
		//spd_162.waitExtra       = 0;
		//spd_162.collisionObjects.push_back(EnemyMinions);
		//spd_162.collisionObjects.push_back(EnemyChampions);
		//spd_162.hasEndExplosion = true,
		//spd_162.secondaryRadius = 275;
		//vSpells->push_back(spd_162);
	//============== ## End.region Karma =================================

	//============== ##region Kassadin:
		//-------------------- R:												
		SpellData spd_163;				
		spd_163.charName        = "Kassadin";
		spd_163.dangerlevel     = 1;		
		spd_163.missileName     = "RiftWalk";				
		spd_163.name            = "RiftWalk";
		spd_163.projectileSpeed = 8000;									
		spd_163.radius          = 270;									
		spd_163.range           = 450;
		spd_163.spellDelay      = 250;				
		spd_163.spellKey        = _R;
		spd_163.spellName       = "RiftWalk";										
		spd_163.spellType       = Circular;
		vSpells->push_back(spd_163);
		
		////-------------------- E:												
		//SpellData spd_164;		
		//spd_164.angle			= 38;				//L#:40
		//spd_164.charName        = "Kassadin";
		//spd_164.dangerlevel     = 2;		
		//spd_164.missileName     = "ForcePulse";				
		//spd_164.name            = "Force Pulse";
		//spd_164.projectileSpeed = FLT_MAX;									
		//spd_164.radius          = 80;									
		//spd_164.range           = 700;
		//spd_164.spellDelay      = 250;				
		//spd_164.spellKey        = _E;
		//spd_164.spellName       = "ForcePulse";										
		//spd_164.spellType       = Cone;
		//vSpells->push_back(spd_164);
	//============== ## End.region Kassadin =================================

	//============== ##region Khazix:
		//-------------------- W-1:												
		SpellData spd_165;				
		spd_165.charName        = "Khazix";
		spd_165.angle			= 22;
		spd_165.dangerlevel     = 2;		
		spd_165.missileName     = "KhazixWMissile";							
		spd_165.name            = "Void Spike";
		spd_165.projectileSpeed = 1700;									
		spd_165.radius          = 55;									
		spd_165.range           = 1025;
		spd_165.spellDelay      = 250;				
		spd_165.spellKey        = _W;
		spd_165.spellName       = "KhazixW";	
		spd_165.extraSpellNames.push_back("KhazixWLong");
		spd_165.spellType       = Line;
		spd_165.collisionObjects.push_back(EnemyMinions);
		spd_165.collisionObjects.push_back(EnemyChampions);
		spd_165.isSpecial_11x	= true;
		spd_165.isSpecial_22x	= true;
		spd_165.waitExtra       = 0;
		vSpells->push_back(spd_165);
		
		//-------------------- E-1:												
		SpellData spd_167;	
		spd_167.charName        = "Khazix";
		spd_167.dangerlevel     = 1;		
		spd_167.missileName     = "KhazixE1_Ss";			//	"KhazixEInvisMissile" ---> toa do ko chuan, luc dung' luc ko
		spd_167.name            = "Leap";
		spd_167.projectileSpeed = 1250;						// thay doi tuy k/c vo`			
		spd_167.radius          = 265;									
		spd_167.range           = 700;				
		spd_167.spellDelay      = 0;				
		spd_167.spellKey        = _E;
		spd_167.spellName       = "KhazixE";
		spd_167.spellType       = Circular;
		spd_167.isSpecial_11x	= true;
		spd_167.isSpecial_22x	= true;
		vSpells->push_back(spd_167);
	//============== ## End.region Khazix =================================

	//============== ##region Kled:
		//-------------------- Q-2:(ko cuoi~ ngua)												
		SpellData spd_169;
		spd_169.charName        = "Kled";
		spd_169.dangerlevel     = 2;		
		spd_169.missileName     = "KledRiderQMissile";				
		spd_169.name            = "Pocket Pistol";
		spd_169.projectileSpeed = 3000;									
		spd_169.radius          = 40;									
		spd_169.range           = 700;
		spd_169.spellDelay      = 250;				
		spd_169.spellKey        = _Q2;
		spd_169.spellName       = "KledRiderQ";										
		spd_169.spellType       = Line;
		vSpells->push_back(spd_169);

		//-------------------- Q-1:	(cuoi~ ngua)											
		SpellData spd_170;
		spd_170.charName        = "Kled";
		spd_170.dangerlevel     = 3;		
		spd_170.missileName     = "KledQMissile";				
		spd_170.name            = "Beartrap on a Rope";
		spd_170.projectileSpeed = 1600;									
		spd_170.radius          = 45;									
		spd_170.range           = 800;
		spd_170.spellDelay      = 250;				
		spd_170.spellKey        = _Q1;
		spd_170.spellName       = "KledQ";										
		spd_170.spellType       = Line;
		spd_170.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_170);
		
		////-------------------- E:												
		//SpellData spd_171;
		//spd_171.charName        = "Kled";
		//spd_171.dangerlevel     = 2;		
		//spd_171.missileName     = "KledE";						//xx	
		//spd_171.name            = "Jousting";
		//spd_171.projectileSpeed = 945;									
		//spd_171.radius          = 125;									
		//spd_171.range           = 750;
		//spd_171.spellDelay      = 0;				
		//spd_171.spellKey        = _E;
		//spd_171.spellName       = "KledE";										
		//spd_171.spellType       = Line;
		//vSpells->push_back(spd_171);
	//============== ## End.region Kled =================================

	//============== ##region Lissandra:
		////-------------------- W:												
		//SpellData spd_172;
		//spd_172.charName        = "Lissandra";
		//spd_172.dangerlevel     = 3;	
		//spd_172.defaultOff		= true;
		//spd_172.missileName     = "LissandraW";				
		//spd_172.name            = "Ring of Frost";
		//spd_172.projectileSpeed = 10000;									
		//spd_172.radius          = 450;									
		//spd_172.range           = 450;
		//spd_172.spellDelay      = 125;				
		//spd_172.spellKey        = _W;
		//spd_172.spellName       = "LissandraW";										
		//spd_172.spellType       = Circular;
		//vSpells->push_back(spd_172);
		
		//-------------------- Q-1:												
		SpellData spd_173;
		spd_173.charName        = "Lissandra";
		spd_173.dangerlevel     = 2;	
		spd_173.missileName     = "LissandraQMissile";				
		spd_173.name            = "Ice Shard";
		spd_173.projectileSpeed = 2200;									
		spd_173.radius          = 75;									
		spd_173.range           = 825;
		spd_173.spellDelay      = 250;				
		spd_173.spellKey        = _Q;
		spd_173.spellName       = "LissandraQMissile";										
		spd_173.spellType       = Line;
		spd_173.fixedRange      = true;
		vSpells->push_back(spd_173);

		////-------------------- Q-2:												
		//SpellData spd_174;
		//spd_174.charName        = "Lissandra";
		//spd_174.dangerlevel     = 2;	
		//spd_174.missileName     = "LissandraQShards";				
		//spd_174.name            = "Ice Shard Extended";
		//spd_174.projectileSpeed = 2200;									
		//spd_174.radius          = 90;									
		//spd_174.range           = 825;
		//spd_174.spellDelay      = 250;				
		//spd_174.spellKey        = 11;
		//spd_174.spellName       = "LissandraQShards";										
		//spd_174.spellType       = Line;
		//vSpells->push_back(spd_174);

		//-------------------- E:												
		SpellData spd_175;
		spd_175.charName        = "Lissandra";
		spd_175.dangerlevel     = 1;	
		spd_175.missileName     = "LissandraEMissile";				
		spd_175.name            = "Glacial Path";
		spd_175.projectileSpeed = 850;					//Game:1450						
		spd_175.radius          = 125;									
		spd_175.range           = 1205;					//L#:1025
		spd_175.spellDelay      = 250;				
		spd_175.spellKey        = _E;
		spd_175.spellName       = "LissandraE";										
		spd_175.spellType       = Line;
		spd_175.fixedRange      = true;
		vSpells->push_back(spd_175);
	//============== ## End.region Lissandra =================================
		
	//============== ##region Maokai:
		//-------------------- Q:												
		SpellData spd_176;
		spd_176.charName        = "Maokai";
		spd_176.dangerlevel     = 3;	
		spd_176.missileName     = "MaokaiQMissile";				
		spd_176.name            = "Arcane Smash";
		spd_176.projectileSpeed = 1000;										
		spd_176.radius          = 110;									
		spd_176.range           = 660;					
		spd_176.spellDelay      = 250;				
		spd_176.spellKey        = _Q;
		spd_176.spellName       = "MaokaiQ";										
		spd_176.spellType       = Line;
		vSpells->push_back(spd_176);

		//-------------------- E:												
		SpellData spd_177;
		spd_177.charName        = "Maokai";
		spd_177.dangerlevel     = 1;	
		spd_177.missileName     = "MaokaiEMissile";					
		spd_177.name            = "Sapling Toss";
		spd_177.projectileSpeed = 1000;										
		spd_177.radius          = 250;									
		spd_177.range           = 1100;					
		spd_177.spellDelay      = 250;				
		spd_177.spellKey        = _E;
		spd_177.spellName       = "MaokaiE";										
		spd_177.spellType       = Circular;
		vSpells->push_back(spd_177);
	//============== ## End.region Maokai =================================

	//============== ##region Malphite:	
		//-------------------- R:												
		SpellData spd_178;
		spd_178.charName        = "Malphite";
		spd_178.dangerlevel     = 4;	
		spd_178.missileName     = "MalphiteR_Ss";					
		spd_178.name            = "Unstoppable Force";
		spd_178.projectileSpeed = 2000;										
		spd_178.radius          = 300;									
		spd_178.range           = 1000;					
		spd_178.spellDelay      = 0;				
		spd_178.spellKey        = _R;
		spd_178.spellName       = "UFSlash";										
		spd_178.spellType       = Circular;
		spd_178.isSpecial_11x   = true;
		spd_178.isSpecial_22x   = true;
		vSpells->push_back(spd_178);
	//============== ## End.region Malphite =================================

	//============== ##region Malzahar:	
		//-------------------- Q:												
		SpellData spd_179;
		spd_179.charName        = "Malzahar";
		spd_179.dangerlevel     = 2;	
		spd_179.missileName     = "MalzaharQMissile_NO";		// ko can dung` 					
		spd_179.name            = "Call of the Void";
		spd_179.projectileSpeed = FLT_MAX;						// 1600, nhung Perpendicular va delay qua cao nen ko can					
		spd_179.radius          = 85;									
		spd_179.range           = 950;	
		//spd_179.sideRadius		= 400;
		spd_179.spellDelay      = 1000;					
		spd_179.spellKey        = _Q;
		spd_179.spellName       = "MalzaharQ";										
		spd_179.spellType       = Line;
		spd_179.isPerpendicular = true;
		spd_179.secondaryRadius = 475;
		vSpells->push_back(spd_179);
	//============== ## End.region Malzahar =================================

	//============== ##region Nocturne:	
		//-------------------- Q:												
		SpellData spd_180;
		spd_180.charName        = "Nocturne";
		spd_180.dangerlevel     = 2;	
		spd_180.missileName     = "NocturneDuskbringer";						
		spd_180.name            = "Duskbringer";
		spd_180.projectileSpeed = 1400;										
		spd_180.radius          = 60;									
		spd_180.range           = 1200;	
		spd_180.spellDelay      = 250;				
		spd_180.spellKey        = _Q;
		spd_180.spellName       = "NocturneDuskbringer";										
		spd_180.spellType       = Line;
		vSpells->push_back(spd_180);
	//============== ## End.region Nocturne =================================

	//============== ##region Olaf:	
		//-------------------- Q:												
		SpellData spd_181;
		spd_181.charName        = "Olaf";
		spd_181.dangerlevel     = 2;	
		spd_181.missileName     = "OlafAxeThrow";						
		spd_181.name            = "Axe Throw";
		spd_181.projectileSpeed = 1600;										
		spd_181.radius          = 90;									
		spd_181.range           = 1100;	
		spd_181.spellDelay      = 250;				
		spd_181.spellKey        = _Q;
		spd_181.spellName       = "OlafAxeThrowCast";										
		spd_181.spellType       = Line;
		vSpells->push_back(spd_181);
	//============== ## End.region Olaf =================================

	//============== ##region Poppy:	
		//-------------------- Q:												
		SpellData spd_182;
		spd_182.charName        = "Poppy";
		spd_182.dangerlevel     = 2;	
		spd_182.missileName     = "PoppyQSpell";				//ko co missile		
		spd_182.name            = "Hammer Shock";
		spd_182.projectileSpeed = FLT_MAX;										
		spd_182.radius          = 100;									
		spd_182.range           = 450;	
		spd_182.spellDelay      = 500;
		spd_182.extraEndTime	= 1000;
		spd_182.spellKey        = _Q;
		spd_182.spellName       = "PoppyQSpell";
		spd_182.waitExtra       = 200;
		spd_182.spellType       = Line;
		vSpells->push_back(spd_182);

		//-------------------- R:												
		SpellData spd_183;
		spd_183.charName        = "Poppy";
		spd_183.dangerlevel     = 3;	
		spd_183.missileName     = "PoppyRMissile";							
		spd_183.name            = "Keeper's Verdict (Line)";
		spd_183.projectileSpeed = 1750;										
		spd_183.radius          = 100;									
		spd_183.range           = 1150;	
		spd_183.spellDelay      = 300;
		spd_183.spellKey        = _R;
		spd_183.spellName       = "PoppyRSpell";										
		spd_183.spellType       = Line;
		spd_183.fixedRange		= true;
		spd_183.waitExtra       = 0;
		vSpells->push_back(spd_183);
	//============== ## End.region Poppy =================================

	//============== ##region RekSai:	
		//-------------------- Q:												
		SpellData spd_184;
		spd_184.charName        = "RekSai";
		spd_184.dangerlevel     = 2;	
		spd_184.missileName     = "RekSaiQBurrowedMis";							
		spd_184.name            = "Prey Seeker";
		spd_184.projectileSpeed = 1950;										
		spd_184.radius          = 65;									
		spd_184.range           = 1500;	
		spd_184.spellDelay      = 125;
		spd_184.spellKey        = _Q;
		spd_184.spellName       = "ReksaiQBurrowed";											
		spd_184.spellType       = Line;
		spd_184.fixedRange		= true;
		spd_184.collisionObjects.push_back(EnemyMinions);
		spd_184.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_184);

		////-------------------- W:												
		//SpellData spd_185;
		//spd_185.charName        = "RekSai";
		//spd_185.dangerlevel     = 3;	
		//spd_185.missileName     = "ReksaiWBurrowed";							
		//spd_185.name            = "Unburrow";
		//spd_185.projectileSpeed = 2300;										
		//spd_185.radius          = 160;									
		//spd_185.range           = 160;	
		//spd_185.spellDelay      = 250;
		//spd_185.extraEndTime	= 500;
		//spd_185.spellKey        = _W;
		//spd_185.spellName       = "ReksaiWBurrowed";										
		//spd_185.spellType       = Circular;
		//vSpells->push_back(spd_185);
	//============== ## End.region RekSai =================================

	//============== ##region Rengar:	
		//-------------------- E:												
		SpellData spd_186;
		spd_186.charName        = "Rengar";
		spd_186.dangerlevel     = 3;	
		spd_186.missileName     = "RengarEMis";	
		spd_186.extraMissileNames.push_back("RengerEEmpMis");
		spd_186.name            = "Bola Strike";
		spd_186.projectileSpeed = 1500;										
		spd_186.radius          = 70;									
		spd_186.range           = 1000;	
		spd_186.spellDelay      = 250;
		spd_186.spellKey        = _E;
		spd_186.spellName       = "RengarE";	
		spd_186.extraSpellNames.push_back("RengarEEmp");
		spd_186.spellType       = Line;
		spd_186.collisionObjects.push_back(EnemyMinions);
		spd_186.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_186);
	//============== ## End.region Rengar =================================

	//============== ##region Riven:	
		//-------------------- W:												
		SpellData spd_187;
		spd_187.charName        = "Riven";
		spd_187.dangerlevel     = 3;	
		spd_187.defaultOff		= true;
		spd_187.missileName     = "RivenMartyr_NO";	
		spd_187.name            = "Ki Burst";
		spd_187.projectileSpeed = 0;										
		spd_187.radius          = 300;									
		spd_187.range           = 300;	
		spd_187.spellDelay      = 50;
		spd_187.spellKey        = _W;
		spd_187.spellName       = "RivenMartyr";	
		spd_187.spellType       = Circular;
		spd_187.waitExtra       = 0;
		vSpells->push_back(spd_187);

		//-------------------- R:												
		SpellData spd_188;
		spd_188.angle			= 10.5f;
		//spd_188.isThreeWay	= true;
		spd_188.charName        = "Riven";
		spd_188.dangerlevel     = 4;	
		spd_188.missileName     = "RivenWindslashMissileCenter";		//RivenWindslashMissileCenter, RivenWindslashMissileLeft, RivenWindslashMissileRight
		spd_188.extraMissileNames.push_back("RivenWindslashMissileLeft");
		spd_188.extraMissileNames.push_back("RivenWindslashMissileRight");
		spd_188.name            = "Wind Slash";
		spd_188.projectileSpeed = 1600;										
		spd_188.radius          = 110;									
		spd_188.range           = 1100;	
		spd_188.spellDelay      = 250;
		spd_188.spellKey        = _R;
		spd_188.spellName       = "RivenIzunaBlade";	
		spd_188.spellType       = Line;
		spd_188.isSpecial_11x	= true;
		spd_188.isSpecial_22x	= true;
		spd_188.waitExtra       = 0;
		//spd_188.fixedRange		= true;
		vSpells->push_back(spd_188);
	//============== ## End.region Riven =================================
		
	//============== ##region Rumble:	
		//-------------------- E:												
		SpellData spd_189;
		spd_189.charName        = "Rumble";
		spd_189.dangerlevel     = 2;	
		spd_189.missileName     = "RumbleGrenadeMissile";	
		spd_189.name            = "Electro-Harpoon";
		spd_189.projectileSpeed = 2000;										
		spd_189.radius          = 60;									
		spd_189.range           = 950;	
		spd_189.spellDelay      = 250;
		spd_189.spellKey        = _E;
		spd_189.spellName       = "RumbleGrenade";	
		spd_189.spellType       = Line;
		//spd_189.waitExtra       = 0;
		spd_189.fixedRange		= true;
		spd_189.collisionObjects.push_back(EnemyMinions);
		spd_189.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_189);
		
		//-------------------- R:												
		SpellData spd_190;
		spd_190.charName        = "Rumble";
		spd_190.dangerlevel     = 4;	
		spd_190.missileName     = "RumbleCarpetBombMissile";	
		spd_190.name            = "Carpet Bomb";
		spd_190.projectileSpeed = 1650;							//Game: 1600							
		spd_190.radius          = 140;									
		spd_190.range           = 1250;						
		spd_190.spellDelay      = 550;								//game: 583.3f	
		spd_190.spellKey        = _R;
		spd_190.spellName       = "RumbleCarpetBomb_NO";			//L#:RumbleCarpetBomb, pCastSpell="RumbleCarpetBombDummy" --> ko can ne pCastSpell vi ko chuan
		spd_190.spellType       = Line;
		spd_190.waitExtra       = 0;
		spd_190.fixedRange		= true;
		spd_190.isSpecial_11x	= true;								//true de ko ne bang pCast(k co)
		spd_190.isSpecial_22x	= true;								//true de them delay 550
		vSpells->push_back(spd_190);
	//============== ## End.region Rumble =================================
	
	//============== ##region TahmKench:	
		//-------------------- Q:												
		SpellData spd_191;
		spd_191.charName        = "TahmKench";
		spd_191.dangerlevel     = 3;	
		spd_191.missileName     = "TahmKenchQMissile";	
		spd_191.name            = "Tongue Lash";
		spd_191.projectileSpeed = 2000;										
		spd_191.radius          = 70;									
		spd_191.range           = 900;	
		spd_191.spellDelay      = 250;
		spd_191.spellKey        = _Q;
		spd_191.spellName       = "TahmKenchQ";	
		spd_191.spellType       = Line;
		//spd_191.waitExtra       = 0;
		spd_191.fixedRange		= true;
		spd_191.collisionObjects.push_back(EnemyMinions);
		spd_191.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_191);

		//-------------------- W:												
		SpellData spd_191W;
		spd_191W.charName        = "TahmKench";
		spd_191W.dangerlevel     = 2;	
		spd_191W.missileName     = "TahmKenchW_NO";							// ko co missile
		spd_191W.name            = "Regurgitate";
		spd_191W.projectileSpeed = 1800;										
		spd_191W.radius          = 100;									
		spd_191W.range           = 975;										// 1150 van trung
		spd_191W.spellDelay      = 250;
		spd_191W.spellKey        = _W;
		spd_191W.spellName       = "TahmKenchWCastTimeAndAnimation";	
		spd_191W.spellType       = Line;
		spd_191W.waitExtra       = 0;
		spd_191W.fixedRange		= true;
		spd_191W.isSpecial_11x	= true;										// ne' o day, TH dac biet
		spd_191W.isSpecial_22x	= true;										// ko ne' o day vi k co missile
		spd_191W.collisionObjects.push_back(EnemyMinions);
		spd_191W.collisionObjects.push_back(EnemyChampions);
		spd_191W.hasEndExplosion = true;
		spd_191W.secondaryRadius = 265;
		spd_191W.extraEndTime	 = 275;
		vSpells->push_back(spd_191W);
	//============== ## End.region TahmKench =================================
	
	//============== ##region Neeko:	
		//-------------------- Q:												
		SpellData spd_192;
		spd_192.charName        = "Neeko";
		spd_192.dangerlevel     = 2;	
		spd_192.missileName     = "NeekoQ";	
		spd_192.name            = "Blooming Burst";
		spd_192.projectileSpeed = 1500;										
		spd_192.radius          = 210;									
		spd_192.range           = 800;	
		spd_192.spellDelay      = 250;
		spd_192.spellKey        = _Q;
		spd_192.spellName       = "NeekoQ";	
		spd_192.spellType       = Circular;
		spd_192.waitExtra       = 0;
		spd_192.extraEndTime    = 750;
		vSpells->push_back(spd_192);

		//-------------------- E:												
		SpellData spd_193;
		spd_193.charName        = "Neeko";
		spd_193.dangerlevel     = 2;	
		spd_193.missileName     = "NeekoE";	
		spd_193.name            = "Tangle-Barbs";
		spd_193.projectileSpeed = 1500;										
		spd_193.radius          = 60;									
		spd_193.range           = 1050;	
		spd_193.spellDelay      = 250;
		spd_193.spellKey        = _E;
		spd_193.spellName       = "NeekoE";	
		spd_193.spellType       = Line;
		spd_193.waitExtra       = 0;
		vSpells->push_back(spd_193);

		//-------------------- R:												
		SpellData spd_194;
		spd_194.charName        = "Neeko";
		spd_194.dangerlevel     = 2;	
		spd_194.missileName     = "NeekoRIndicatorMis";			
		spd_194.name            = "Pop Blossom";
		spd_194.projectileSpeed = 0;										
		spd_194.radius          = 610;									
		spd_194.range           = 610;	
		spd_194.spellDelay      = 2200;		
		spd_194.spellKey        = _R;
		spd_194.spellName       = "NeekoR";						
		spd_194.spellType       = Circular;
		spd_194.isSpecial_11x   = true;							//ko co pCast nen cho isSpecial_11x=true, ne' = missile cho all version dc
		spd_194.waitExtra       = 300;
		vSpells->push_back(spd_194);
	//============== ## End.region Neeko =================================
	
	//============== ##region Zoe:	
		//-------------------- Q-1:												
		SpellData spd_195;
		spd_195.charName        = "Zoe";
		spd_195.dangerlevel     = 2;	
		spd_195.missileName     = "ZoeQMissile";	
		spd_195.name            = "Paddle Star(Q1)";
		spd_195.projectileSpeed = 1200;										
		spd_195.radius          = 50;									
		spd_195.range           = 805;	
		spd_195.spellDelay      = 250;
		spd_195.spellKey        = _Q1;
		spd_195.spellName       = "ZoeQMissile";	
		spd_195.spellType       = Line;
		spd_195.collisionObjects.push_back(EnemyMinions);
		spd_195.collisionObjects.push_back(EnemyChampions);
		vSpells->push_back(spd_195);

		//-------------------- Q-2:												
		SpellData spd_195a;
		spd_195a.charName        = "Zoe";
		spd_195a.dangerlevel     = 2;	
		spd_195a.missileName     = "ZoeQMis2";	
		spd_195a.name            = "Paddle Star(Q2)";
		spd_195a.projectileSpeed = 2500;										
		spd_195a.radius          = 60;									
		spd_195a.range           = 1610;								// range thay doi theo missile
		spd_195a.spellDelay      = 0;
		spd_195a.spellKey        = _Q2;
		spd_195a.spellName       = "ZoeQ2_NO";			
		spd_195a.spellType       = Line;
		spd_195a.isSpecial_11x   = true;								// ko co pCast nen isSpecial_11x = true
		spd_195a.isSpecial_22x   = true;								// ne' = missile cho all version dc, dung` o day vi range thay doi
		spd_195a.collisionObjects.push_back(EnemyMinions);
		spd_195a.collisionObjects.push_back(EnemyChampions);
		spd_195a.waitExtra       = 0;
		vSpells->push_back(spd_195a);

		//-------------------- E:												
		SpellData spd_196;
		spd_196.charName        = "Zoe";
		spd_196.dangerlevel     = 3;	
		spd_196.missileName     = "ZoeE";					//"ZoeE" nhanh hon "ZoeEMis" 15ms
		spd_196.name            = "Sleepy Trouble Bubble";
		spd_196.projectileSpeed = 1700;										
		spd_196.radius          = 40;									
		spd_196.range           = 925;	
		spd_196.spellDelay      = 300;
		spd_196.spellKey        = _E;
		spd_196.spellName       = "ZoeE";	
		spd_196.spellType       = Line;
		spd_196.waitExtra       = 0;
		spd_196.collisionObjects.push_back(EnemyMinions);
		spd_196.collisionObjects.push_back(EnemyChampions);
		spd_196.hasEndExplosion = true;
		spd_196.secondaryRadius = 255;
		spd_196.extraEndTime    = 850;
		vSpells->push_back(spd_196);
	//============== ## End.region Zoe =================================

	//============== ##region Ornn:	
		//-------------------- Q:												
		SpellData spd_197;
		spd_197.charName        = "Ornn";
		spd_197.dangerlevel     = 2;	
		spd_197.missileName     = "OrnnQ";	
		spd_197.name            = "Volcanic Rupture";
		spd_197.projectileSpeed = 1800;					//Game: 1800					
		spd_197.radius          = 50;					//Game: 65			
		spd_197.range           = 815;	
		spd_197.spellDelay      = 300;
		spd_197.spellKey        = _Q;
		spd_197.spellName       = "OrnnQ";	
		spd_197.spellType       = Line;
		vSpells->push_back(spd_197);

		//-------------------- E:												
		SpellData spd_198;
		spd_198.charName        = "Ornn";
		spd_198.dangerlevel     = 3;	
		spd_198.missileName     = "OrnnE_";				//ko co missile
		spd_198.name            = "Searing Charge";
		spd_198.projectileSpeed = 1600;					//Game: 1600						
		spd_198.radius          = 90;					//Game: 100				
		spd_198.range           = 885;	
		spd_198.spellDelay      = 350;
		spd_198.spellKey        = _E;
		spd_198.spellName       = "OrnnE";				
		spd_198.spellType       = Line;
		spd_198.waitExtra       = 0;
		vSpells->push_back(spd_198);
	//============== ## End.region Ornn =================================

	//============== ##region Taliyah:	
		//-------------------- Q:												
		SpellData spd_199;
		spd_199.charName        = "Taliyah";
		spd_199.dangerlevel     = 2;	
		spd_199.missileName     = "TaliyahQMis";	
		spd_199.name            = "Threaded Volley";
		spd_199.projectileSpeed = 1450;										
		spd_199.radius          = 90;								
		spd_199.range           = 1000;	
		spd_199.spellDelay      = 250;
		spd_199.spellKey        = _Q;
		spd_199.spellName       = "TaliyahQ";	
		spd_199.spellType       = Line;
		spd_199.fixedRange		= true;
		spd_199.defaultOff		= true;
		vSpells->push_back(spd_199);
		
		//-------------------- W:												
		SpellData spd_200;
		spd_200.charName        = "Taliyah";
		spd_200.dangerlevel     = 3;	
		spd_200.missileName     = "TaliyahWVC_x";				//ko co missile
		spd_200.name            = "Seismic Shove";
		spd_200.projectileSpeed = 20000;										
		spd_200.radius          = 165;								
		spd_200.range           = 900;	
		spd_200.spellDelay      = 450;
		spd_200.extraEndTime	= 1000;
		spd_200.spellKey        = _W;
		spd_200.spellName       = "TaliyahWVC";
		//spd_200.extraSpellNames.push_back("TaliyahW");
		spd_200.spellType       = Circular;
		spd_200.waitExtra       = 0;
		vSpells->push_back(spd_200);
	//============== ## End.region Taliyah =================================

	////============== ##region Taric:	(phai check doi tuong khac)
	//	//-------------------- E:												
	//	SpellData spd_201;
	//	spd_201.charName        = "Taric";
	//	spd_201.dangerlevel     = 2;	
	//	spd_201.missileName     = "TaricEMissile";	
	//	spd_201.name            = "Dazzle";
	//	spd_201.projectileSpeed = 20000;										
	//	spd_201.radius          = 100;								
	//	spd_201.range           = 750;	
	//	spd_201.spellDelay      = 1000;
	//	spd_201.spellKey        = _E;
	//	spd_201.spellName       = "TaricE";			// ko co pCastSpell
	//	spd_201.spellType       = Line;
	//	spd_201.fixedRange		= true;
	//	//spd_201.isSpecial		= true;
	//	vSpells->push_back(spd_201);
	////============== ## End.region Taric =================================
	
	//============== ##region Tristana:	
		//-------------------- W:												
		SpellData spd_201;
		spd_201.charName        = "Tristana";
		spd_201.dangerlevel     = 1;	
		spd_201.missileName     = "RocketJump";		//ko co missile
		spd_201.name            = "Rocket Jump";
		spd_201.projectileSpeed = 1000;										
		spd_201.radius          = 270;								
		spd_201.range           = 900;	
		spd_201.spellDelay      = 250;
		spd_201.spellKey        = _W;
		spd_201.spellName       = "TristanaW";			
		spd_201.spellType       = Circular;
		vSpells->push_back(spd_201);
	//============== ## End.region Tristana =================================

	//============== ##region Tryndamere:	
		//-------------------- E:												
		SpellData spd_201E;
		spd_201E.charName        = "Tryndamere";
		spd_201E.dangerlevel     = 2;	
		spd_201E.missileName     = "TryndamereE_Ss";			
		spd_201E.name            = "Spinning Slash";
		spd_201E.projectileSpeed = 1100;							//dash-Speed-game: 900							
		spd_201E.radius          = 110;								
		spd_201E.range           = 865;	
		spd_201E.spellDelay      = 0;
		spd_201E.spellKey        = _E;
		spd_201E.spellName       = "TryndamereE";					//ko co pCastSpell
		//spd_201E.extraSpellNames.push_back("slash");				//"slash" xuat hien cung thoi diem voi "TryndamereE" nen ko dung lam extraSpellNames dc
		spd_201E.spellType       = Line;
		spd_201E.isSpecial_11x   = true;
		spd_201E.isSpecial_22x   = true;
		vSpells->push_back(spd_201E);
	//============== ## End.region Tryndamere =================================
	
	//============== ##region TwistedFate:	
		//-------------------- Q:												
		SpellData spd_202;
		spd_202.angle			= 28;
		//spd_202.isThreeWay		= true;
		spd_202.charName        = "TwistedFate";
		spd_202.dangerlevel     = 2;	
		spd_202.missileName     = "SealFateMissile";			
		spd_202.name            = "Wild Cards";
		spd_202.projectileSpeed = 1000;										
		spd_202.radius          = 40;								
		spd_202.range           = 1450;	
		spd_202.spellDelay      = 250;
		spd_202.spellKey        = _Q;
		spd_202.spellName       = "WildCards";			
		spd_202.spellType       = Line;
		spd_202.waitExtra       = 200;
		spd_202.isSpecial_11x	= true;
		spd_202.isSpecial_22x	= true;
		vSpells->push_back(spd_202);
	//============== ## End.region TwistedFate =================================

	//============== ##region Twitch:	
		//-------------------- W:												
		SpellData spd_203;
		spd_203.charName        = "Twitch";
		spd_203.dangerlevel     = 1;	
		spd_203.missileName     = "TwitchVenomCaskMissile";		
		spd_203.name            = "Venom Cask";
		spd_203.projectileSpeed = 1400;										
		spd_203.radius          = 280;								
		spd_203.range           = 900;	
		spd_203.spellDelay      = 250;
		spd_203.spellKey        = _W;
		spd_203.spellName       = "TwitchVenomCask";			
		spd_203.spellType       = Circular;
		vSpells->push_back(spd_203);
	//============== ## End.region Twitch =================================

	//============== ##region Urgot:	
		//-------------------- Q:												
		SpellData spd_205;
		spd_205.charName        = "Urgot";
		spd_205.dangerlevel     = 2;	
		spd_205.missileName     = "UrgotQMissile";		
		spd_205.name            = "Corrosive Charge";
		spd_205.projectileSpeed = 2400;										
		spd_205.radius          = 210;								
		spd_205.range           = 800;	
		spd_205.spellDelay      = 475;
		spd_205.extraEndTime	= 200;
		spd_205.spellKey        = _Q;
		spd_205.spellName       = "UrgotQ";			
		spd_205.spellType       = Circular;
		vSpells->push_back(spd_205);

		//-------------------- E:												
		SpellData spd_204;
		spd_204.charName        = "Urgot";
		spd_204.dangerlevel     = 2;	
		spd_204.missileName     = "UrgotE";				//ko co missile
		spd_204.name            = "Disdain";
		spd_204.projectileSpeed = 1500;										
		spd_204.radius          = 100;								
		spd_204.range           = 615;	
		spd_204.spellDelay      = 450;
		spd_204.spellKey        = _E;
		spd_204.spellName       = "UrgotE";			
		spd_204.spellType       = Line;
		vSpells->push_back(spd_204);

		//-------------------- R:												
		SpellData spd_206;
		spd_206.charName        = "Urgot";
		spd_206.dangerlevel     = 2;	
		spd_206.missileName     = "UrgotR";				
		spd_206.name            = "Fear Beyond Death";
		spd_206.projectileSpeed = 3200;					//Game:3200						
		spd_206.radius          = 80;								
		spd_206.range           = 1605;	
		spd_206.spellDelay      = 400;
		spd_206.missileDelay    = 150;
		spd_206.spellKey        = _R;
		spd_206.spellName       = "UrgotR";			
		spd_206.spellType       = Line;
		vSpells->push_back(spd_206);
	//============== ## End.region Urgot =================================
			
	//============== ##region Vi:	
		//-------------------- Q:												
		SpellData spd_207;
		spd_207.charName        = "Vi";
		spd_207.dangerlevel     = 3;	
		spd_207.missileName     = "ViQMissile";		
		spd_207.name            = "Vault Breaker";
		spd_207.projectileSpeed = 1500;										
		spd_207.radius          = 65;								
		spd_207.range           = 775;	
		spd_207.spellDelay      = 0;
		spd_207.spellKey        = _Q;
		spd_207.spellName       = "ViQMissile";		//pCastSpell name = ViQ, nhung k chuan		
		spd_207.spellType       = Line;
		spd_207.waitExtra       = 0;
		spd_207.collisionObjects.push_back(EnemyChampions);
		//spd_207.usePackets		= true;
		vSpells->push_back(spd_207);
	//============== ## End.region Vi =================================	

	////============== ##region Vladimir:	
	//	//-------------------- R:												
	//	SpellData spd_208;
	//	spd_208.charName        = "Vladimir";
	//	spd_208.dangerlevel     = 3;	
	//	spd_208.missileName     = "VladimirR";		
	//	spd_208.name            = "Hemoplague";
	//	spd_208.projectileSpeed = 2500;										
	//	spd_208.radius          = 375;								
	//	spd_208.range           = 700;	
	//	spd_208.spellDelay      = 250;
	//	spd_208.spellKey        = _R;
	//	spd_208.spellName       = "VladimirR";			
	//	spd_208.spellType       = Circular;
	//	vSpells->push_back(spd_208);
	////============== ## End.region Vladimir =================================	

	//============== ##region Zac:	
		//-------------------- Q:												
		SpellData spd_209;
		spd_209.charName        = "Zac";
		spd_209.dangerlevel     = 3;	
		spd_209.missileName     = "ZacQMissile";		
		spd_209.name            = "Stretching Strike";
		spd_209.projectileSpeed = 3600;										
		spd_209.radius          = 75;								
		spd_209.range           = 950;	
		spd_209.spellDelay      = 330;
		spd_209.spellKey        = _Q;
		spd_209.spellName       = "ZacQ";			
		spd_209.spellType       = Line;
		spd_209.fixedRange		= true;
		spd_209.waitExtra       = 200;
		spd_209.isSpecial_00x   = true;		// [-Evade in OnProcessSpell-]
		spd_209.isSpecial_11x   = true;
		vSpells->push_back(spd_209);

		//-------------------- E:												
		SpellData spd_210_zacE;
		spd_210_zacE.charName        = "Zac";
		spd_210_zacE.dangerlevel     = 3;	
		spd_210_zacE.missileName     = "ZacE_xx";				//dung` tam : "Zac_Base_E_LandPositionIndicator" va "Zac_Base_E_Moving"
		spd_210_zacE.name            = "Elastic Slingshot";
		spd_210_zacE.projectileSpeed = 1000;					//Game: 6xx - 1500				
		spd_210_zacE.radius          = 275;								
		spd_210_zacE.range           = 1800;					//tang theo lvl
		spd_210_zacE.spellDelay      = 0;
		spd_210_zacE.spellKey        = _E;
		spd_210_zacE.spellName       = "ZacE_Special";			
		spd_210_zacE.spellType       = Circular;
		spd_210_zacE.isSpecial_11x   = true;
		spd_210_zacE.isSpecial_22x   = true;
		spd_210_zacE.waitExtra		 = 0;
		spd_210_zacE.spellType       = Circular;
		vSpells->push_back(spd_210_zacE);

		//-------------------- R:												
		SpellData spd_210_zacR;
		spd_210_zacR.charName        = "Zac";
		spd_210_zacR.dangerlevel     = 2;	
		spd_210_zacR.missileName     = "ZacR_xx";				//dung` tam : "Zac_Base_E_LandPositionIndicator" va ko co "Zac_Base_E_Moving"
		spd_210_zacR.name            = "Let's Bounce!";
		spd_210_zacR.projectileSpeed = 850;										
		spd_210_zacR.radius          = 300;								
		spd_210_zacR.range           = 1000;						//tang theo lvl
		spd_210_zacR.spellDelay      = 0;
		spd_210_zacR.spellKey        = _R;
		spd_210_zacR.spellName       = "ZacR_Special";			
		spd_210_zacR.spellType       = Circular;
		spd_210_zacR.isSpecial_11x   = true;
		spd_210_zacR.isSpecial_22x   = true;
		spd_210_zacR.waitExtra		 = 150;
		spd_210_zacR.spellType       = Circular;
		vSpells->push_back(spd_210_zacR);

	//============== ## End.region Zac =================================	

	//============== ##region Yorick:	
		//-------------------- W:												
		SpellData spd_210_YorickW;
		spd_210_YorickW.charName        = "Yorick";
		spd_210_YorickW.dangerlevel     = 3;	
		spd_210_YorickW.missileName     = "YorickWMissile_NO";			//ko co
		spd_210_YorickW.name            = "Dark Procession";
		spd_210_YorickW.projectileSpeed = FLT_MAX;								
		spd_210_YorickW.radius          = 250;								
		spd_210_YorickW.range           = 600;				
		spd_210_YorickW.spellDelay      = 775;							
		spd_210_YorickW.spellKey        = _W;							//tam thoi CHUA LAM : if(CheckName("_W_Warning", missileObj->GetNameNpc()) && CheckName("Yorick", missileObj->GetNameNpc()))
		spd_210_YorickW.spellName       = "YorickW";					//"YorickW_Special"			
		spd_210_YorickW.spellType       = Circular;
		spd_210_YorickW.waitExtra		= 150;
		spd_210_YorickW.isSpecial_00x   = true;							// [-Evade in OnProcessSpell-]
		spd_210_YorickW.isSpecial_11x   = true;
		spd_210_YorickW.isSpecial_22x   = true;
		vSpells->push_back(spd_210_YorickW);

		//-------------------- E:												
		SpellData spd_210_YorickE;
		spd_210_YorickE.charName        = "Yorick";
		spd_210_YorickE.dangerlevel     = 3;	
		spd_210_YorickE.missileName     = "YorickEMissile_NO";			// "YorickEMissile" : ko can dung`	
		spd_210_YorickE.name            = "Mourning Mist";
		spd_210_YorickE.projectileSpeed = FLT_MAX;						// dan bay 1800, dan xuat hien Line thi FLT_MAX				
		spd_210_YorickE.radius          = 120;								
		spd_210_YorickE.range           = 700;							// range vong tron` nem' E
		spd_210_YorickE.spellDelay      = 450;							// Game: 330
		spd_210_YorickE.spellKey        = _E;
		spd_210_YorickE.spellName       = "YorickE";					
		spd_210_YorickE.spellType       = Line;
		spd_210_YorickE.waitExtra		= 0;
		spd_210_YorickE.isSpecial_11x   = true;
		spd_210_YorickE.isSpecial_22x   = true;
		vSpells->push_back(spd_210_YorickE);
	//============== ## End.region Yorick =================================

	//============== ##region Zyra:	
		//-------------------- Q:												
		SpellData spd_210_Q;
		spd_210_Q.charName        = "Zyra";
		spd_210_Q.dangerlevel     = 2;	
		spd_210_Q.missileName     = "ZyraQ_NO";			//"ZyraQ" : nhung ko ne dc do qua nhanh
		spd_210_Q.name            = "Deadly Spines";
		spd_210_Q.projectileSpeed = FLT_MAX;										
		spd_210_Q.radius          = 85;								
		spd_210_Q.range           = 850;	
		spd_210_Q.spellDelay      = 700;
		spd_210_Q.spellKey        = _Q;
		spd_210_Q.spellName       = "ZyraQ";			
		spd_210_Q.spellType       = Line;
		spd_210_Q.isPerpendicular = true;
		spd_210_Q.secondaryRadius = 425;
		spd_210_Q.extraEndTime	  = 550;
		vSpells->push_back(spd_210_Q);

		//-------------------- E:												
		SpellData spd_210;
		spd_210.charName        = "Zyra";
		spd_210.dangerlevel     = 3;	
		spd_210.missileName     = "ZyraE";				
		spd_210.name            = "Grasping Roots";
		spd_210.projectileSpeed = 1150;										
		spd_210.radius          = 70;								
		spd_210.range           = 1125;	
		spd_210.spellDelay      = 250;
		spd_210.spellKey        = _E;
		spd_210.spellName       = "ZyraE";			
		spd_210.spellType       = Line;
		spd_210.fixedRange		= true;
		spd_210.waitExtra		= 0;
		vSpells->push_back(spd_210);

		//-------------------- R:												
		SpellData spd_211;
		spd_211.charName        = "Zyra";
		spd_211.dangerlevel     = 4;	
		spd_211.defaultOff		= true;
		spd_211.missileName     = "ZyraRSplash_NO";				// ko can` vi qua nhanh	
		spd_211.name            = "Stranglethorns";
		spd_211.projectileSpeed = FLT_MAX;										
		spd_211.radius          = 550;								
		spd_211.range           = 700;	
		spd_211.spellDelay      = 2000;
		spd_211.extraEndTime    = 500;
		spd_211.spellKey        = _R;
		spd_211.spellName       = "ZyraR";	
		//spd_211.extraSpellNames = new[] { "ZyraBrambleZone" }
		spd_211.spellType       = Circular;
		spd_211.waitExtra		= 200;
		vSpells->push_back(spd_211);
	//============== ## End.region Zyra =================================

	//============== ##region Akali:
		//-------------------- Q:												
		SpellData spd_212;
		spd_212.charName        = "Akali";
		spd_212.defaultOff		= true;
		spd_212.dangerlevel     = 2;	
		spd_212.missileName     = "AkaliQMis_x";			//"AkaliQMis0->AkaliQMis5"	--> qua nhanh	
		spd_212.name            = "Five Point Strike";
		spd_212.projectileSpeed = 3200;										
		spd_212.radius          = 140;								
		spd_212.range           = 555;	
		spd_212.spellDelay      = 250;
		spd_212.spellKey        = _Q;
		spd_212.spellName       = "AkaliQ";			
		spd_212.spellType       = Line;
		spd_212.fixedRange		= true;
		vSpells->push_back(spd_212);

		//-------------------- E:												
		SpellData spd_213;
		spd_213.charName        = "Akali";
		spd_213.dangerlevel     = 3;	
		spd_213.missileName     = "AkaliEMis";				
		spd_213.name            = "Shuriken Flip";
		spd_213.projectileSpeed = 1525;										
		spd_213.radius          = 60;								
		spd_213.range           = 875;	
		spd_213.spellDelay      = 250;
		spd_213.spellKey        = _E;
		spd_213.spellName       = "AkaliE";			
		spd_213.spellType       = Line;
		spd_213.fixedRange		= true;
		spd_213.waitExtra		= 0;
		vSpells->push_back(spd_213);

		//-------------------- R1:												
		SpellData spd_214;
		spd_214.charName        = "Akali";
		spd_214.dangerlevel     = 3;	
		spd_214.missileName     = "AkaliPVFXMis1_NO";				//AkaliPVFXMis2, AkaliPVFXMisEnemy1
		spd_214.name            = "Perfect Execution";
		spd_214.projectileSpeed = 1500;															
		spd_214.radius          = 135;								
		spd_214.range           = 775;	
		spd_214.spellDelay      = 250;
		spd_214.spellKey        = _R1;
		spd_214.spellName       = "AkaliR";			
		spd_214.spellType       = Line;
		spd_214.waitExtra		= 0;
		//spd_214.fixedRange		= true;
		vSpells->push_back(spd_214);

		//-------------------- R2:												
		SpellData spd_214_R;
		spd_214_R.charName        = "Akali";
		spd_214_R.dangerlevel     = 3;	
		spd_214_R.missileName     = "AkaliPVFXMis2_NO";				//AkaliPVFXMis2, AkaliPVFXMisEnemy1
		spd_214_R.name            = "Perfect Execution 2";
		spd_214_R.projectileSpeed = 2500;								//(R2 speed = 3000)								
		spd_214_R.radius          = 135;								
		spd_214_R.range           = 775;	
		spd_214_R.spellDelay      = 125;
		spd_214_R.spellKey        = _R2;
		spd_214_R.spellName       = "AkaliRb";			
		spd_214_R.spellType       = Line;
		spd_214_R.waitExtra		  = 0;
		vSpells->push_back(spd_214_R);

	//============== ## End.region Akali =================================

	//============== ##region Orianna:
		//-------------------- Q:												
		SpellData spd_215;
		spd_215.charName        = "Orianna";
		spd_215.dangerlevel     = 2;	
		spd_215.missileName     = "OrianaIzuna";			// ten thuc la : "OrianaIzuna"		
		spd_215.name            = "Commnad: Attack";
		spd_215.projectileSpeed = 1425;						// // game : 1400							
		spd_215.radius          = 70;	
		spd_215.range           = 1650;						// range thay doi
		spd_215.spellDelay      = 0;
		spd_215.spellKey        = _Q;
		spd_215.spellName       = "OrianaIzunaCommand";			
		spd_215.spellType       = Line;
		spd_215.isSpecial_11x	= true;						// ko co pCast, k ne' o day
		spd_215.isSpecial_22x	= true;						// ne = missile va range thay doi
		spd_215.waitExtra		= 0;
		vSpells->push_back(spd_215);

		//-------------------- E:												
		SpellData spd_216;
		spd_216.charName        = "Orianna";
		spd_216.defaultOff		= true;
		spd_216.dangerlevel     = 2;	
		spd_216.missileName     = "OrianaRedact";					
		spd_216.name            = "Commnad: Protect";
		spd_216.projectileSpeed = 1900;						// game : 1850				
		spd_216.radius          = 70;	
		spd_216.range           = 1650;						// range thay doi
		spd_216.spellDelay      = 0;
		spd_216.spellKey        = _E;
		spd_216.spellName       = "OrianaRedact";			
		spd_216.spellType       = Line;
		spd_216.isSpecial_11x	= true;						// ko co pCast, k ne' o day
		spd_216.isSpecial_22x	= true;						// ne = missile va range thay doi
		spd_216.waitExtra		= 0;
		vSpells->push_back(spd_216);

		//-------------------- R:												
		SpellData spd_217;
		spd_217.charName        = "Orianna";
		spd_217.dangerlevel     = 4;	
		spd_217.missileName     = "OrianaR_NO";				// ko co missile, L#: OrianaDetonateCommand, ten thuc la : "Orianna_Base_R_VacuumIndicator"(Type: 1)		
		spd_217.name            = "Commnad: Shockwave";
		spd_217.projectileSpeed = FLT_MAX;												
		spd_217.radius          = 410;	
		spd_217.range           = 1000;	
		spd_217.spellDelay      = 500;
		spd_217.spellKey        = _R;
		spd_217.spellName       = "OrianaDetonateCommand";			
		spd_217.spellType       = Circular;
		spd_217.isSpecial_11x	= true;						// ne' o pCast, TH dac biet
		spd_217.isSpecial_22x	= true;						// ko co missile nen ko ne' o day
		spd_217.waitExtra		= 0;
		vSpells->push_back(spd_217);
		//[1924] (Type: 1)[TeamID: 0](Orianna_Base_W_Dissonance_tar) :40000309, [Time: 806.470] - [currentPos: 2466.26,95.75,647.98] - [serPos: 2466.26,95.75,647.98]
		//[1924] (Type: 1)[TeamID: 0](Orianna_Base_W_Dissonance_ball_green) :40000307, [Time: 806.470] - [currentPos: 2342.00,95.75,792.00] - [serPos: 2342.00,95.75,792.00]
	//============== ## End.region Orianna =================================
		
	//============== ##region Sejuani:
		//-------------------- Q:												
		SpellData spd_218;
		spd_218.charName        = "Sejuani";
		spd_218.dangerlevel     = 3;	
		spd_218.missileName     = "SejuaniQ_Ss";				//[5272] (Type: 1)[TeamID: 0](Sejuani_Base_Q_cas) :4000032e, [Time: 349.256] - [currentPos: 2106.26,95.75,886.15] - [serPos: 2106.26,95.75,886.15]	
		spd_218.name            = "Arctic Assault";
		spd_218.projectileSpeed = 1050;							//dash-speed-game: 1000
		spd_218.radius          = 120;	
		spd_218.range           = 845;	
		spd_218.spellDelay      = 0;
		spd_218.spellKey        = _Q;
		spd_218.spellName       = "SejuaniQ";			
		spd_218.spellType       = Line;
		spd_218.isSpecial_11x	= true;
		spd_218.isSpecial_22x	= true;
		vSpells->push_back(spd_218);

		////-------------------- W:												
		//SpellData spd_219;
		//spd_219.charName        = "Sejuani";
		//spd_219.dangerlevel     = 2;	
		//spd_219.missileName     = "SejuaniW_Special";		//Sejuani_Base_Temp_W_IndicatorBLU2			
		//spd_219.name            = "Winter's Wrath";
		//spd_219.projectileSpeed = 1600;									
		//spd_219.radius          = 70;	
		//spd_219.range           = 800;	
		//spd_219.spellDelay      = 250;
		//spd_219.spellKey        = _W;
		//spd_219.spellName       = "SejuaniWDummy";			
		//spd_219.spellType       = Line;
		//spd_219.isSpecial_22x	= true;
		//vSpells->push_back(spd_219);

		//-------------------- R:												
		SpellData spd_220;
		spd_220.charName        = "Sejuani";
		spd_220.dangerlevel     = 4;	
		spd_220.missileName     = "SejuaniRMissile";				
		spd_220.name            = "Glacial Prison";
		spd_220.projectileSpeed = 1600;				//L#:1600
		spd_220.radius          = 110;	
		spd_220.range           = 1200;	
		spd_220.spellDelay      = 250;
		spd_220.hasEndExplosion = true;
		spd_220.secondaryRadius = 400;
		spd_220.spellKey        = _R;
		spd_220.spellName       = "SejuaniR";		//extraSpellNames: "SejuaniGlacialPrison"		
		spd_220.spellType       = Line;
		spd_220.waitExtra       = 0;
		vSpells->push_back(spd_220);
	//============== ## End.region Sejuani =================================

	//============== ##region Shen:
		//-------------------- Q:												
		SpellData spd_221;
		spd_221.charName        = "Shen";
		spd_221.dangerlevel     = 3;	
		spd_221.missileName     = "ShenE_Ss";			
		spd_221.name            = "Shadow Dash";
		spd_221.projectileSpeed = 1250;							//L#: 1450, dash-speed-game: 1141.406128
		spd_221.radius          = 50;	
		spd_221.range           = 745;	
		spd_221.spellDelay      = 0;
		spd_221.spellKey        = _E;
		spd_221.spellName       = "ShenE";			
		spd_221.spellType       = Line;
		spd_221.isSpecial_11x	= true;
		spd_221.isSpecial_22x	= true;
		spd_221.waitExtra		= 0;
		vSpells->push_back(spd_221);
	//============== ## End.region Shen =================================

	//============== ##region XinZhao:
		//-------------------- W:												
		SpellData spd_222;
		spd_222.charName        = "XinZhao";
		spd_222.dangerlevel     = 2;	
		spd_222.missileName     = "XinZhaoW_NO";				//ko co missile, cung ko the ne FOW
		spd_222.name            = "Wind Becomes Lightning";
		spd_222.projectileSpeed = 6000;							
		spd_222.radius          = 70;	
		spd_222.range           = 910;	
		spd_222.spellDelay      = 500;
		spd_222.spellKey        = _W;
		spd_222.spellName       = "XinZhaoW";					
		spd_222.spellType       = Line;
		spd_222.waitExtra		= 200;
		vSpells->push_back(spd_222);

		//-------------------- R:												
		SpellData spd_223;
		spd_223.charName        = "XinZhao";
		spd_223.dangerlevel     = 3;	
		spd_223.missileName     = "XinZhaoR_NO";				//ko co missile, cung ko the ne FOW
		spd_223.name            = "Crescent Guard";
		spd_223.projectileSpeed = 0;							
		spd_223.radius          = 500;	
		spd_223.range           = 500;	
		spd_223.spellDelay      = 325;							// Game:325
		spd_223.spellKey        = _R;
		spd_223.spellName       = "XinZhaoR";					
		spd_223.spellType       = Circular;
		spd_223.waitExtra		= 0;
		vSpells->push_back(spd_223);
	//============== ## End.region XinZhao =================================

	//============== ##region Swain:
		//-------------------- Q:												
		SpellData spd_224;
		spd_224.angle			= 26;
		spd_224.charName        = "Swain";
		spd_224.dangerlevel     = 2;
		spd_224.missileName     = "SwainQ_xxx";					//co nhung speed 5000, nen ko can ne'
		spd_224.name            = "Death's Hand";
		spd_224.projectileSpeed = 5000;							
		spd_224.radius          = 100;	
		spd_224.range           = 765;	
		spd_224.spellDelay      = 250;
		spd_224.spellKey        = _Q;
		spd_224.spellName       = "SwainQ";			
		spd_224.spellType       = Cone;
		spd_224.waitExtra		= 0;
		vSpells->push_back(spd_224);

		//-------------------- W:												
		SpellData spd_225;
		spd_225.charName        = "Swain";
		spd_225.dangerlevel     = 3;
		spd_225.missileName     = "SwainW_xxx";					//ko can ne missile
		spd_225.name            = "Vision of Empire";
		spd_225.projectileSpeed = 10000;							
		spd_225.radius          = 325;	
		spd_225.range           = 3500;	
		spd_225.spellDelay      = 1500;
		spd_225.spellKey        = _W;
		spd_225.spellName       = "SwainW";			
		spd_225.spellType       = Circular;
		spd_225.waitExtra		= 200;
		vSpells->push_back(spd_225);

		//-------------------- E:												
		SpellData spd_226;
		spd_226.charName        = "Swain";
		spd_226.dangerlevel     = 3;
		spd_226.missileName     = "SwainE";		
		spd_226.extraMissileNames.push_back("SwainEReturnMissile");
		spd_226.name            = "Nevermove";
		spd_226.projectileSpeed = 1550;							
		spd_226.radius          = 85;	
		spd_226.range           = 900;	
		spd_226.spellDelay      = 250;
		spd_226.spellKey        = _E;
		spd_226.spellName       = "SwainE";			
		spd_226.spellType       = Line;
		spd_226.waitExtra		= 0;
		vSpells->push_back(spd_226);

		//-------------------- R:												
		SpellData spd_227;
		spd_227.charName        = "Swain";
		spd_227.dangerlevel     = 2;	
		spd_227.missileName     = "SwainR_xx";				//missile qua nhanh
		spd_227.name            = "Crescent Guard";
		spd_227.projectileSpeed = 0;							
		spd_227.radius          = 650;	
		spd_227.range           = 650;	
		spd_227.spellDelay      = 250;							
		spd_227.spellKey        = _R;
		spd_227.spellName       = "SwainRSoulFlare";			
		spd_227.spellType       = Circular;
		spd_227.defaultOff		= true;
		spd_227.waitExtra		= 0;
		vSpells->push_back(spd_227);
	//============== ## End.region Swain =================================
		
	//============== ##region Skarner:
		//-------------------- E:												
		SpellData spd_228;
		spd_228.charName        = "Skarner";
		spd_228.dangerlevel     = 3;
		spd_228.missileName     = "SkarnerFractureMissile";		
		spd_228.name            = "Fracture";
		spd_228.projectileSpeed = 1450;							
		spd_228.radius          = 70;	
		spd_228.range           = 1000;	
		spd_228.spellDelay      = 250;
		spd_228.spellKey        = _E;
		spd_228.spellName       = "SkarnerFractureMissile";			
		spd_228.spellType       = Line;
		spd_228.fixedRange	    = true;
		vSpells->push_back(spd_228);
	//============== ## End.region Skarner =================================
		
	//============== ##region Sion:
		//-------------------- Q:												
		SpellData spd_229;
		spd_229.charName        = "Sion";
		spd_229.dangerlevel     = 3;
		spd_229.missileName     = "SionQ_Ss";				//SionQHitParticleMissile2 --> ko can dung
		spd_229.name            = "Decimating Smash";
		spd_229.projectileSpeed = FLT_MAX;							
		spd_229.radius          = 190;	
		spd_229.range           = 775;						//Range cung thay doi : 300 +30 every 0.1s
		spd_229.spellDelay      = 1000;
		spd_229.spellKey        = _Q;
		spd_229.spellName       = "SionQ";			
		spd_229.spellType       = Line;
		spd_229.isSpecial_11x	= true;						// ko ne' o day, ne o special4
		spd_229.isSpecial_22x	= true;						// ko ne' o day, ne o special4
		spd_229.waitExtra		= 0;
		vSpells->push_back(spd_229);

		//-------------------- E:												
		SpellData spd_230;
		spd_230.charName        = "Sion";
		spd_230.dangerlevel     = 3;
		spd_230.missileName     = "SionEMissile";				
		spd_230.name            = "Roar of the Slayer";
		spd_230.projectileSpeed = 1800;							
		spd_230.radius          = 80;	
		spd_230.range           = 825;				//up to 1375 neu day? minion							
		spd_230.spellDelay      = 250;
		spd_230.spellKey        = _E;
		spd_230.spellName       = "SionE";			
		spd_230.spellType       = Line;	
		spd_230.isSpecial_11x	= true;
		spd_230.isSpecial_22x	= true;
		spd_230.waitExtra		= 250;
		vSpells->push_back(spd_230);

		//-------------------- R:												
		SpellData spd_231;
		spd_231.charName        = "Sion";
		spd_231.dangerlevel     = 3;
		spd_231.missileName     = "SionR_Ss";					// ko co missile
		spd_231.name            = "Unstoppable Onslaught";
		spd_231.projectileSpeed = 1000;							
		spd_231.radius          = 160;	
		spd_231.range           = 1600;											
		spd_231.spellDelay      = 500;
		spd_231.spellKey        = _R;
		spd_231.spellName       = "SionR";			
		spd_231.spellType       = Line;
		spd_231.isSpecial_11x	= true;							// ko ne' o day, ne o special4
		spd_231.isSpecial_22x	= true;							// ko ne' o day, ne o special4
		spd_231.waitExtra		= 0;
		vSpells->push_back(spd_231);
	//============== ## End.region Sion =================================

	//============== ##region Sylas:
		//-------------------- Q:												
		SpellData spd_232;
		spd_232.charName        = "Sylas";
		spd_232.dangerlevel     = 2;
		spd_232.missileName     = "SylasQ_NO";				//ko co missile
		spd_232.name            = "Chain Lash";
		spd_232.projectileSpeed = 6000;							
		spd_232.radius          = 60;	
		spd_232.range           = 775;						
		spd_232.spellDelay      = 450;
		spd_232.spellKey        = _Q;
		spd_232.spellName       = "SylasQ";			
		spd_232.spellType       = Line;
		spd_232.isSpecial_11x	= true;						// ne trong day, TH dac biet
		spd_232.isSpecial_22x	= true;						// ko co missile, k ne' o day
		spd_232.waitExtra		= 0;
		vSpells->push_back(spd_232);

		//-------------------- E:												
		SpellData spd_233;
		spd_233.charName        = "Sylas";
		spd_233.dangerlevel     = 3;
		spd_233.missileName     = "SylasE2";				
		spd_233.name            = "Abduct";
		spd_233.projectileSpeed = 1600;							
		spd_233.radius          = 60;	
		spd_233.range           = 850;									
		spd_233.spellDelay      = 250;
		spd_233.spellKey        = _E;
		spd_233.spellName       = "SylasE2";			
		spd_233.spellType       = Line;
		spd_233.collisionObjects.push_back(EnemyMinions);
		spd_233.collisionObjects.push_back(EnemyChampions);
		spd_233.waitExtra		= 0;
		vSpells->push_back(spd_233);
	//============== ## End.region Sylas =================================

	//============== ##region Kayle:
		//-------------------- Q:												
		SpellData spd_234;
		//spd_234.isSpecial		= true;
		spd_234.charName        = "Kayle";
		spd_234.dangerlevel     = 2;
		spd_234.missileName     = "KayleQ";				
		spd_234.name            = "Radiant Blast";
		spd_234.projectileSpeed = 2000;							
		spd_234.radius          = 60;	
		spd_234.range           = 900;						
		spd_234.spellDelay      = 320;
		spd_234.spellKey        = _Q;
		spd_234.spellName       = "KayleQ";			
		spd_234.spellType       = Line;
		spd_234.waitExtra		= 0;
		vSpells->push_back(spd_234);

	//============== ## End.region Kayle =================================

	//============== ##region Mordekaiser:
		SpellData spd_235;
		spd_235.charName        = "Mordekaiser";
		spd_235.dangerlevel     = 2;	
		spd_235.missileName     = "MordekaiserQ_NO";				//ko co missile		
		spd_235.name            = "Obliterate";
		spd_235.projectileSpeed = FLT_MAX;										
		spd_235.radius          = 80;									
		spd_235.range           = 650;	
		spd_235.spellDelay      = 500;
		//spd_235.extraEndTime	= 500;
		spd_235.spellKey        = _Q;
		spd_235.spellName       = "MordekaiserQ";
		spd_235.waitExtra       = 200;
		spd_235.spellType       = Line;
		vSpells->push_back(spd_235);

		SpellData spd_236;
		spd_236.charName        = "Mordekaiser";
		spd_236.dangerlevel     = 3;	
		spd_236.missileName     = "MordekaiserE";				
		spd_236.name            = "Death's Grasp";
		spd_236.projectileSpeed = FLT_MAX;											
		spd_236.radius          = 165;									
		spd_236.range           = 900;					
		spd_236.spellDelay      = 750;				
		spd_236.spellKey        = _E;
		spd_236.spellName       = "MordekaiserE";										
		spd_236.spellType       = Line;
		spd_236.fixedRange      = true;
		spd_233.waitExtra		= 100;
		vSpells->push_back(spd_236);
	//============== ## End.region Mordekaiser =================================	

	//============== ##region Pantheon:
		//-------------------- Q-2:	
		SpellData spd_237;
		spd_237.charName        = "Pantheon";	
		spd_237.dangerlevel     = 2;
		spd_237.missileName     = "PantheonQMissile";			
		spd_237.name            = "Comet Spear Q2";	
		spd_237.projectileSpeed = 2200;
		spd_237.radius	        = 60;				
		spd_237.range		    = 1200;						
		spd_237.spellDelay      = 250;										
		spd_237.spellKey        = 45;
		spd_237.spellName       = "PantheonQMissile";	
		spd_237.spellType       = Line;
		spd_237.fixedRange      = true;
		spd_237.waitExtra       = 0;
		vSpells->push_back(spd_237);

		//-------------------- Q-1:	
		SpellData spd_238;
		spd_238.charName        = "Pantheon";	
		spd_238.dangerlevel     = 2;
		spd_238.missileName     = "PantheonQ_NO";					//ko co Missile
		spd_238.name            = "Comet Spear Q1";	
		spd_238.projectileSpeed = 2700;
		spd_238.radius	        = 80;				
		spd_238.range		    = 575;						
		spd_238.spellDelay      = 250;											
		spd_238.spellKey        = _Q;
		spd_238.spellName       = "PantheonQTap";				
		spd_238.spellType       = Line;
		spd_238.fixedRange      = true;
		spd_238.waitExtra       = 0;
		vSpells->push_back(spd_238);

		//-------------------- R:	
		SpellData spd_238_r;
		spd_238_r.charName        = "Pantheon";	
		spd_238_r.dangerlevel     = 2;
		spd_238_r.missileName     = "PantheonRMissile3";					// "PantheonRMissile3", "PantheonRMissile2", "PantheonRMissile"
		spd_238_r.name            = "Grand Starfall";	
		spd_238_r.projectileSpeed = FLT_MAX;
		spd_238_r.radius	      = 450;				
		spd_238_r.range			  = 5500;						
		spd_238_r.spellDelay      = 5000;											
		spd_238_r.spellKey        = _R;
		spd_238_r.spellName       = "PantheonR";				
		spd_238_r.spellType       = Line;
		spd_238_r.waitExtra       = 0;
		//spd_238_r.isSpecial_11x	  = true;								// 
		spd_238_r.isSpecial_22x	  = true;									// ne o day cung dc, nhung lam voi missile+delay 
		vSpells->push_back(spd_238_r);
	//================================ ## End.region Pantheon =================================

	//============== ##region Senna:
		//-------------------- Q:												
		SpellData spd_239;
		spd_239.charName        = "Senna";
		spd_239.dangerlevel     = 2;
		spd_239.missileName     = "SennaQCast";				//ko co missile	
		spd_239.name            = "Piercing Darkness";
		spd_239.projectileSpeed = FLT_MAX;							
		spd_239.radius          = 75;	
		spd_239.range           = 1275;						
		spd_239.spellDelay      = 500;
		spd_239.spellKey        = _Q;
		spd_239.spellName       = "SennaQCast";			
		spd_239.spellType       = Line;
		spd_239.waitExtra		= 0;
		vSpells->push_back(spd_239);

		//-------------------- W:												
		SpellData spd_240;
		spd_240.charName        = "Senna";
		spd_240.dangerlevel     = 3;
		spd_240.missileName     = "SennaW";					//ko co missile	
		spd_240.name            = "Last Embrace";
		spd_240.projectileSpeed = 1250;							
		spd_240.radius          = 60;	
		spd_240.range           = 1175;						
		spd_240.spellDelay      = 250;
		spd_240.spellKey        = _W;
		spd_240.spellName       = "SennaW";			
		spd_240.spellType       = Line;
		vSpells->push_back(spd_240);

		//-------------------- R:												
		SpellData spd_241;
		spd_241.charName        = "Senna";
		spd_241.dangerlevel     = 3;
		spd_241.missileName     = "SennaR";					//ko co missile	
		spd_241.name            = "Dawning Shadow";
		spd_241.projectileSpeed = FLT_MAX;							
		spd_241.radius          = 170;	
		spd_241.range           = 20000;						
		spd_241.spellDelay      = 1000;
		spd_241.spellKey        = _R;
		spd_241.spellName       = "SennaR";			
		spd_241.spellType       = Line;
		vSpells->push_back(spd_241);
	//================================ ## End.region Senna =================================

		//============== ##region Aphelios:
		//-------------------- Q:												
		SpellData spd_242;
		spd_242.charName        = "Aphelios";
		spd_242.dangerlevel     = 2;
		spd_242.missileName     = "ApheliosCalibrumQ";					
		spd_242.name            = "Calibrum";
		spd_242.projectileSpeed = 1850;							
		spd_242.radius          = 60;	
		spd_242.range           = 1475;						
		spd_242.spellDelay      = 350;
		spd_242.spellKey        = _Q;
		spd_242.spellName       = "ApheliosCalibrumQ";			
		spd_242.spellType       = Line;
		spd_242.collisionObjects.push_back(EnemyMinions);
		spd_242.collisionObjects.push_back(EnemyChampions);
		spd_242.waitExtra		= 50;
		vSpells->push_back(spd_242);

		//-------------------- R:												
		SpellData spd_243;
		spd_243.charName        = "Aphelios";
		spd_243.dangerlevel     = 3;
		spd_243.missileName     = "ApheliosRMis";					
		spd_243.name            = "Moonlight Vigil";
		spd_243.projectileSpeed = 2200;							
		spd_243.radius          = 110;	
		spd_243.range           = 1600;						
		spd_243.spellDelay      = 500;
		spd_243.spellKey        = _R;
		spd_243.spellName       = "ApheliosR";			
		spd_243.spellType       = Line;
		spd_243.waitExtra		= 0;
		vSpells->push_back(spd_243);
	//================================ ## End.region Aphelios =================================

		//============== ##region Yuumi:
		//-------------------- Q:												
		SpellData spd_244;
		spd_244.charName        = "Yuumi";
		spd_244.dangerlevel     = 2;
		spd_244.missileName     = "YuumiQSkillShot";					
		spd_244.name            = "Prowling Projectile";
		spd_244.projectileSpeed = 1425;							
		spd_244.radius          = 60;	
		spd_244.range           = 1225;						
		spd_244.spellDelay      = 0;
		spd_244.spellKey        = _Q;
		spd_244.spellName       = "YuumiQSkillShot";					//ko co ten trong pCast		
		spd_244.spellType       = Line;
		spd_244.collisionObjects.push_back(EnemyMinions);
		spd_244.collisionObjects.push_back(EnemyChampions);
		spd_244.waitExtra		= 150;
		vSpells->push_back(spd_244);
		//================================ ## End.region Aphelios =================================

	}
};

class EvadeSpellDatabase
{
public:
	std::vector<EvadeSpellData> *vSpells;

	EvadeSpellDatabase()
	{
		vSpells = new std::vector<EvadeSpellData>;
		
	//============== ##region Vayne:	
		//-------------------- Q:
		EvadeSpellData espd_1;
		espd_1.charName        = "Vayne";
		espd_1.dangerlevel     = 1;
		espd_1.name            = "Tumble";
		espd_1.spellName       = "VayneTumble";
		espd_1.range		   = 300;
		espd_1.fixedRange	   = true;
		espd_1.speed		   = 900;
		espd_1.spellDelay	   = 50;
		espd_1.spellKey		   = Q_slot;
		espd_1.evadeType	   = _Dash;
		espd_1.castType 	   = _Position;
		vSpells->push_back(espd_1);
	//============== ## End.region Vayne =================================

	//============== ##region Ahri:	
		//-------------------- R:
		EvadeSpellData espd_2;
		espd_2.charName        = "Ahri";
		espd_2.dangerlevel     = 4;
		espd_2.name            = "AhriTumble";
		espd_2.spellName       = "AhriTumble";
		espd_2.range		   = 500;
		espd_2.speed		   = 1575;
		espd_2.spellDelay	   = 50;
		espd_2.spellKey		   = R_slot;
		espd_2.evadeType	   = _Dash;
		espd_2.castType 	   = _Position;
		vSpells->push_back(espd_2);
	//============== ## End.region Ahri =================================
			
	//============== ##region Blitzcrank:	
		//-------------------- W:
		EvadeSpellData espd_3;
		espd_3.charName        = "Blitzcrank";
		espd_3.dangerlevel     = 3;
		espd_3.name            = "Overdrive";
		espd_3.spellName       = "Overdrive";
		espd_3.spellDelay	   = 150;			//L#: 250
		espd_3.spellKey		   = W_slot;
		espd_3.speedArray[0]   = 70;
		espd_3.speedArray[1]   = 75;
		espd_3.speedArray[2]   = 80;
		espd_3.speedArray[3]   = 85;
		espd_3.speedArray[4]   = 90;
		espd_3.evadeType	   = _MovementSpeedBuff;
		espd_3.castType 	   = _Self;
		vSpells->push_back(espd_3);
	//============== ## End.region Blitzcrank =================================
	
	//============== ##region Caitlyn:	
		//-------------------- E:
		EvadeSpellData espd_4;
		espd_4.charName        = "Caitlyn";
		espd_4.dangerlevel     = 3;
		espd_4.name            = "CaitlynEntrapment";
		espd_4.spellName       = "CaitlynEntrapment";
		espd_4.range		   = 400;
		espd_4.spellDelay	   = 50;
		espd_4.speed		   = 975;
		espd_4.isReversed	   = true;
		espd_4.fixedRange	   = true;
		espd_4.spellKey		   = E_slot;
		espd_4.evadeType	   = _Dash;
		espd_4.castType 	   = _Position;
		vSpells->push_back(espd_4);
	//============== ## End.region Caitlyn =================================
	
	//============== ##region Corki:	
		//-------------------- W:
		EvadeSpellData espd_5;
		espd_5.charName        = "Corki";
		espd_5.dangerlevel     = 3;
		espd_5.name            = "CarpetBomb";
		espd_5.spellName       = "CarpetBomb";
		espd_5.range		   = 790;
		espd_5.spellDelay	   = 50;
		espd_5.speed		   = 975;
		espd_5.spellKey		   = W_slot;
		espd_5.evadeType	   = _Dash;
		espd_5.castType 	   = _Position;
		vSpells->push_back(espd_5);
	//============== ## End.region Corki =================================
	
	//============== ##region Draven:	
		//-------------------- W:
		EvadeSpellData espd_6;
		espd_6.charName        = "Draven";
		espd_6.dangerlevel     = 3;
		espd_6.name            = "Blood Rush";
		espd_6.spellName       = "DravenFury";
		espd_6.spellDelay	   = 150;			//L#: 250
		espd_6.spellKey		   = W_slot;
		espd_6.speedArray[0]   = 40;
		espd_6.speedArray[1]   = 45;
		espd_6.speedArray[2]   = 50;
		espd_6.speedArray[3]   = 55;
		espd_6.speedArray[4]   = 60;
		espd_6.evadeType	   = _MovementSpeedBuff;
		espd_6.castType 	   = _Self;
		vSpells->push_back(espd_6);
	//============== ## End.region Draven =================================
		
	//============== ##region Ekko:	
		//-------------------- E:
		EvadeSpellData espd_7;
		espd_7.charName        = "Ekko";
		espd_7.dangerlevel     = 3;
		espd_7.name            = "PhaseDive";
		espd_7.spellName       = "EkkoE";
		espd_7.range		   = 350;
		espd_7.fixedRange	   = true;
		espd_7.spellDelay	   = 50;
		espd_7.speed		   = 1150;
		espd_7.spellKey		   = E_slot;
		espd_7.evadeType	   = _Dash;
		espd_7.castType 	   = _Position;
		vSpells->push_back(espd_7);
		
		//-------------------- E_AA:
		EvadeSpellData espd_7a;
		espd_7a.charName        = "Ekko";
		espd_7a.dangerlevel     = 3;
		espd_7a.name            = "PhaseDive2";
		espd_7a.spellName       = "EkkoEAttack";
		espd_7a.range		    = 490;
		espd_7a.infrontTarget   = true;
		espd_7a.spellDelay	    = 200;				//L#: 250
		espd_7a.speed		    = FLT_MAX;
		espd_7a.spellKey	    = Recall_slot;
		espd_7a.evadeType	    = _Blink;
		espd_7a.castType 	    = _Target;
		espd_7a.spellTargets[0] = _EnemyChampions;
		espd_7a.spellTargets[1] = _EnemyMinions;
		espd_7a.isSpecial       = true;
		vSpells->push_back(espd_7a);
			
		//-------------------- R:
		EvadeSpellData espd_7b;
		espd_7b.charName        = "Ekko";
		espd_7b.dangerlevel     = 4;
		espd_7b.name            = "Chronobreak";
		espd_7b.spellName       = "EkkoR";
		espd_7b.range		    = 20000;
		espd_7b.spellDelay	    = 50;				
		espd_7b.spellKey	    = R_slot;
		espd_7b.evadeType	    = _Blink;
		espd_7b.castType 	    = _Self;
		espd_7b.isSpecial       = true;
		vSpells->push_back(espd_7b);

	//============== ## End.region Ekko =================================

	//============== ##region Ezreal:	
		//-------------------- E:
		EvadeSpellData espd_8;
		espd_8.charName        = "Ezreal";
		espd_8.dangerlevel     = 2;
		espd_8.name            = "ArcaneShift";
		espd_8.spellName       = "EzrealArcaneShift";
		espd_8.range		   = 450;
		espd_8.spellDelay	   = 200;		//L#:250
		espd_8.spellKey		   = E_slot;
		espd_8.evadeType	   = _Blink;
		espd_8.castType 	   = _Position;
		vSpells->push_back(espd_8);
	//============== ## End.region Ezreal =================================
		
	//============== ##region Fiora:	
		//-------------------- W:
		EvadeSpellData espd_9;
		espd_9.charName        = "Fiora";
		espd_9.dangerlevel     = 3;
		espd_9.name            = "FioraW";
		espd_9.spellName       = "FioraW";
		espd_9.range		   = 750;
		espd_9.spellDelay	   = 100;		
		espd_9.spellKey		   = W_slot;
		espd_9.evadeType	   = _WindWall;
		espd_9.castType 	   = _Position;
		vSpells->push_back(espd_9);

		//-------------------- Q:
		EvadeSpellData espd_10;
		espd_10.charName       = "Fiora";
		espd_10.dangerlevel    = 3;
		espd_10.name           = "FioraQ";
		espd_10.spellName      = "FioraQ";
		espd_10.range		   = 340;
		espd_10.fixedRange	   = true;
		espd_10.speed		   = 1100;
		espd_10.spellDelay	   = 50;		
		espd_10.spellKey	   = Q_slot;
		espd_10.evadeType	   = _Dash;
		espd_10.castType 	   = _Position;
		vSpells->push_back(espd_10);
	//============== ## End.region Fiora =================================
		
	//============== ##region Lucian:	
		//-------------------- E:
		EvadeSpellData espd_11;
		espd_11.charName       = "Lucian";
		espd_11.dangerlevel    = 1;
		espd_11.name           = "RelentlessPursuit";
		espd_11.spellName      = "LucianE";
		espd_11.range		   = 425;
		espd_11.spellDelay	   = 50;
		espd_11.speed		   = 1350;
		espd_11.spellKey	   = E_slot;
		espd_11.evadeType	   = _Dash;
		espd_11.castType 	   = _Position;
		vSpells->push_back(espd_11);
	//============== ## End.region Lucian =================================

	//============== ##region Sivir:	
		//-------------------- E:
		EvadeSpellData espd_12;
		espd_12.charName       = "Sivir";
		espd_12.dangerlevel    = 2;
		espd_12.name           = "SivirE";
		espd_12.spellName      = "SivirE";
		espd_12.spellDelay	   = 50;
		espd_12.spellKey	   = E_slot;
		espd_12.evadeType	   = _SpellShield;
		espd_12.castType 	   = _Self;
		vSpells->push_back(espd_12);
	//============== ## End.region Sivir =================================

	//============== ##region MasterYi:		
		//-------------------- Q:
		EvadeSpellData espd_13;
		espd_13.charName       = "MasterYi";
		espd_13.dangerlevel    = 3;
		espd_13.name           = "AlphaStrike";
		espd_13.spellName      = "AlphaStrike";
		espd_13.range		   = 600;
		espd_13.spellDelay	   = 100;
		espd_13.speed		   = FLT_MAX;
		espd_13.spellKey	   = Q_slot;
		espd_13.evadeType	   = _Blink;
		espd_13.castType 	   = _Target;
		espd_13.spellTargets[0]= _EnemyChampions;
		espd_13.spellTargets[1]= _EnemyMinions;
		espd_13.untargetable   = true;
		vSpells->push_back(espd_13);
	//============== ## End.region MasterYi =================================
			
	//============== ##region Fizz:		
		//-------------------- Q:
		EvadeSpellData espd_14;
		espd_14.charName       = "Fizz";
		espd_14.dangerlevel    = 3;
		espd_14.name           = "FizzPiercingStrike";
		espd_14.spellName      = "FizzPiercingStrike";
		espd_14.range		   = 550;
		espd_14.speed		   = 1400;
		espd_14.fixedRange	   = true;
		espd_14.spellDelay	   = 50;
		espd_14.spellKey	   = Q_slot;
		espd_14.evadeType	   = _Dash;
		espd_14.castType 	   = _Target;
		espd_14.spellTargets[0]= _EnemyMinions;
		espd_14.spellTargets[1]= _EnemyChampions;
		vSpells->push_back(espd_14);

		//-------------------- E:
		EvadeSpellData espd_15;
		espd_15.charName       = "Fizz";
		espd_15.dangerlevel    = 3;
		espd_15.name           = "FizzJump";
		espd_15.spellName      = "FizzJump";
		espd_15.range		   = 400;
		espd_15.speed		   = 1400;
		espd_15.fixedRange	   = true;
		espd_15.spellDelay	   = 50;
		espd_15.spellKey	   = E_slot;
		espd_15.evadeType	   = _Dash;
		espd_15.castType 	   = _Position;
		espd_15.untargetable   = true;
		vSpells->push_back(espd_15);
	//============== ## End.region Fizz =================================
			
	//============== ##region Garen:	
		//-------------------- Q:
		EvadeSpellData espd_16;
		espd_16.charName        = "Garen";
		espd_16.dangerlevel     = 3;
		espd_16.name            = "Decisive Strike";
		espd_16.spellName       = "GarenQ";
		espd_16.spellDelay	    = 150;			//L#: 250
		espd_16.spellKey		= Q_slot;
		espd_16.speedArray[0]   = 35;
		espd_16.speedArray[1]   = 35;
		espd_16.speedArray[2]   = 35;
		espd_16.speedArray[3]   = 35;
		espd_16.speedArray[4]   = 35;
		espd_16.evadeType	    = _MovementSpeedBuff;
		espd_16.castType 	    = _Self;
		vSpells->push_back(espd_16);
	//============== ## End.region Garen =================================
			
	//============== ##region Gragas:	
		//-------------------- E:
		EvadeSpellData espd_17;
		espd_17.charName        = "Gragas";
		espd_17.dangerlevel     = 2;
		espd_17.name            = "BodySlam";
		espd_17.spellName       = "GragasBodySlam";
		espd_17.range			= 600;	
		espd_17.spellDelay	    = 50;	
		espd_17.speed		    = 900;			
		espd_17.spellKey		= E_slot;
		espd_17.evadeType	    = _Dash;
		espd_17.castType 	    = _Position;
		vSpells->push_back(espd_17);
	//============== ## End.region Gragas =================================
			
	//============== ##region Gnar:	
		//-------------------- E-1:
		EvadeSpellData espd_18;
		espd_18.charName        = "Gnar";
		espd_18.dangerlevel     = 3;
		espd_18.name            = "GnarE";
		espd_18.spellName       = "GnarE";
		espd_18.range			= 475;	
		espd_18.spellDelay	    = 50;	
		espd_18.speed		    = 900;	
		espd_18.checkSpellName	= true;
		espd_18.spellKey		= E_slot;
		espd_18.evadeType	    = _Dash;
		espd_18.castType 	    = _Position;
		vSpells->push_back(espd_18);

		//-------------------- E-2:
		EvadeSpellData espd_19;
		espd_19.charName        = "Gnar";
		espd_19.dangerlevel     = 3;
		espd_19.name            = "GnarBigE";
		espd_19.spellName       = "GnarBigE";
		espd_19.range			= 475;	
		espd_19.spellDelay	    = 50;	
		espd_19.speed		    = 800;	
		espd_19.checkSpellName	= true;
		espd_19.spellKey		= (SpellSlot)100;;
		espd_19.evadeType	    = _Dash;
		espd_19.castType 	    = _Position;
		vSpells->push_back(espd_19);
	//============== ## End.region Gnar =================================
		
	//============== ##region Graves:	
		//-------------------- E:
		EvadeSpellData espd_20;
		espd_20.charName        = "Graves";
		espd_20.dangerlevel     = 2;
		espd_20.name            = "QuickDraw";
		espd_20.spellName       = "GravesMove";
		espd_20.range			= 425;	
		espd_20.spellDelay	    = 50;	
		espd_20.speed		    = 1250;	
		espd_20.spellKey		= E_slot;
		espd_20.evadeType	    = _Dash;
		espd_20.castType 	    = _Position;
		vSpells->push_back(espd_20);
	//============== ## End.region Graves =================================
				
	//============== ##region Karma:	
		//-------------------- E:
		EvadeSpellData espd_21;
		espd_21.charName        = "Karma";
		espd_21.dangerlevel     = 3;
		espd_21.name            = "Inspire";
		espd_21.spellName       = "KarmaSolkimShield";
		espd_21.spellDelay	    = 150;			//L#: 250
		espd_21.spellKey		= E_slot;
		espd_21.speedArray[0]   = 40;
		espd_21.speedArray[1]   = 45;
		espd_21.speedArray[2]   = 50;
		espd_21.speedArray[3]   = 55;
		espd_21.speedArray[4]   = 60;
		espd_21.evadeType	    = _MovementSpeedBuff;
		espd_21.castType 	    = _Self;		//L#:_Target, _Target deo co trong code
		vSpells->push_back(espd_21);
	//============== ## End.region Karma =================================

	//============== ##region Kassadin:	
		//-------------------- R:
		EvadeSpellData espd_22;
		espd_22.charName        = "Kassadin";
		espd_22.dangerlevel     = 3;
		espd_22.name            = "RiftWalk";
		espd_22.spellName       = "RiftWalk";
		espd_22.range		    = 450;
		espd_22.spellDelay	    = 200;			//L#:250
		espd_22.spellKey		= R_slot;
		espd_22.evadeType	    = _Blink;
		espd_22.castType 	    = _Position;
		vSpells->push_back(espd_22);
	//============== ## End.region Kassadin =================================
					
	//============== ##region Katarina:	
		//-------------------- E:
		EvadeSpellData espd_23;
		espd_23.charName        = "Katarina";
		espd_23.dangerlevel     = 3;
		espd_23.name            = "KatarinaE";
		espd_23.spellName       = "KatarinaE";
		espd_23.range		    = 700;
		espd_23.speed		    = FLT_MAX;
		espd_23.spellDelay	    = 50;		
		espd_23.spellKey		= E_slot;
		espd_23.evadeType	    = _Blink;
		espd_23.castType 	    = _Target;
		espd_23.spellTargets[0] = _Targetables;
		//espd_23.untargetable    = true;
		vSpells->push_back(espd_23);
	//============== ## End.region Katarina =================================

	//============== ##region Kayle:	
		//-------------------- W:
		EvadeSpellData espd_24;
		espd_24.charName        = "Kayle";
		espd_24.dangerlevel     = 3;
		espd_24.name            = "Divine Blessing";
		espd_24.spellName       = "JudicatorDivineBlessing";
		espd_24.spellDelay	    = 200;			//L#: 250
		espd_24.spellKey		= W_slot;
		espd_24.speedArray[0]   = 18;
		espd_24.speedArray[1]   = 21;
		espd_24.speedArray[2]   = 24;
		espd_24.speedArray[3]   = 27;
		espd_24.speedArray[4]   = 30;
		espd_24.evadeType	    = _MovementSpeedBuff;
		espd_24.castType 	    = _Self;		//L#: _Target, _Target ko co trong code _MovementSpeedBuff
		vSpells->push_back(espd_24);

		//-------------------- R:
		EvadeSpellData espd_25;
		espd_25.charName       = "Kayle";
		espd_25.dangerlevel    = 4;
		espd_25.name           = "Intervention";
		espd_25.spellName      = "JudicatorIntervention";
		espd_25.spellDelay	   = 250;			//L#: 250
		espd_25.spellKey	   = R_slot;
		espd_25.evadeType	   = _SpellShield;
		espd_25.castType 	   = _Self;			//L#: _Target, dung` _Self cung dc
		vSpells->push_back(espd_25);	
	//============== ## End.region Kayle =================================

	//============== ##region Kennen:	
		//-------------------- E:
		EvadeSpellData espd_26;
		espd_26.charName        = "Kennen";
		espd_26.dangerlevel     = 4;
		espd_26.name            = "Lightning Rush";
		espd_26.spellName       = "KennenLightningRush";
		espd_26.spellDelay	    = 200;			//L#: 250
		espd_26.spellKey		= E_slot;
		espd_26.speedArray[0]   = 100;
		espd_26.speedArray[1]   = 100;
		espd_26.speedArray[2]   = 100;
		espd_26.speedArray[3]   = 100;
		espd_26.speedArray[4]   = 100;
		espd_26.evadeType	    = _MovementSpeedBuff;
		espd_26.castType 	    = _Self;		
		vSpells->push_back(espd_26);	
	//============== ## End.region Kayle =================================

	//============== ##region Kindred:	
		//-------------------- Q:
		EvadeSpellData espd_27;
		espd_27.charName        = "Kindred";
		espd_27.dangerlevel     = 1;
		espd_27.name            = "KindredQ";
		espd_27.spellName       = "KindredQ";
		espd_27.range			= 300;	
		espd_27.fixedRange	    = true;
		espd_27.spellDelay	    = 50;	
		espd_27.speed		    = 733;	
		espd_27.spellKey		= Q_slot;
		espd_27.evadeType	    = _Dash;
		espd_27.castType 	    = _Position;
		vSpells->push_back(espd_27);
	//============== ## End.region Kindred =================================

	//============== ##region Kayn:	
		//-------------------- Q:
		EvadeSpellData espd_28;
		espd_28.charName        = "Kayn";
		espd_28.dangerlevel     = 1;
		espd_28.name            = "KaynQ";
		espd_28.spellName       = "KaynQ";
		espd_28.range			= 365;	
		espd_28.fixedRange	    = true;
		espd_28.spellDelay	    = 50;	
		espd_28.speed		    = 1000;				//chua check
		espd_28.spellKey		= Q_slot;
		espd_28.evadeType	    = _Dash;
		espd_28.castType 	    = _Position;
		vSpells->push_back(espd_28);

		//-------------------- E: xxx-chua thich lam`
	//============== ## End.region Kayn =================================

	//============== ##region Pyke:		
		//-------------------- E:
		EvadeSpellData espd_29;
		espd_29.charName       = "Pyke";
		espd_29.dangerlevel    = 3;
		espd_29.name           = "PykeE";
		espd_29.spellName      = "PykeE";
		espd_29.range		   = 600;
		espd_29.fixedRange	    = true;
		espd_29.speed		   = 1000;
		espd_29.spellDelay	   = 50;
		espd_29.spellKey	   = E_slot;
		espd_29.evadeType	   = _Dash;
		espd_29.castType 	   = _Position;
		vSpells->push_back(espd_29);
	//============== ## End.region Pyke =================================
		
	//============== ##region Kaisa:	
		//-------------------- E:
		EvadeSpellData espd_30;
		espd_30.charName        = "Kaisa";
		espd_30.dangerlevel     = 3;
		espd_30.name            = "KaisaE";
		espd_30.spellName       = "KaisaE";
		espd_30.spellDelay	    = 200;			
		espd_30.spellKey		= E_slot;
		espd_30.speedArray[0]   = 55;
		espd_30.speedArray[1]   = 60;
		espd_30.speedArray[2]   = 65;
		espd_30.speedArray[3]   = 70;
		espd_30.speedArray[4]   = 75;
		espd_30.evadeType	    = _MovementSpeedBuff;
		espd_30.castType 	    = _Self;		
		vSpells->push_back(espd_30);

		//-------------------- R: xxx-co-the-lam-dc-->ngai-lam`(phai lam` isSpecial)
	//============== ## End.region Kaisa =================================

	//============== ##region Rakan:	
		//-------------------- W:
		EvadeSpellData espd_31;
		espd_31.charName       = "Rakan";
		espd_31.dangerlevel    = 3;
		espd_31.name           = "RakanW";
		espd_31.spellName      = "RakanW";
		espd_31.range		   = 600;
		espd_31.speed		   = 2050;			//xxxx-chua-check
		espd_31.spellDelay	   = 50;
		espd_31.spellKey	   = W_slot;
		espd_31.evadeType	   = _Dash;
		espd_31.castType 	   = _Position;
		vSpells->push_back(espd_31);
		
		//-------------------- E:(chua-test)
		EvadeSpellData espd_32;
		espd_32.charName       = "Rakan";
		espd_32.dangerlevel    = 2;
		espd_32.name           = "RakanE";
		espd_32.spellName      = "RakanE";
		espd_32.range		   = 750;				//co the isSpecial voi xayah.range=1000
		espd_32.speed		   = 1250;
		espd_32.spellDelay	   = 50;
		espd_32.spellKey	   = E_slot;
		espd_32.evadeType	   = _Dash;
		espd_32.castType 	   = _Target;
		espd_32.spellTargets[0]= _AllyChampions;
		vSpells->push_back(espd_32);
	//============== ## End.region Rakan =================================

	//============== ##region Xayah:	
		//-------------------- R:
		EvadeSpellData espd_33;
		espd_33.charName        = "Xayah";
		espd_33.dangerlevel     = 4;
		espd_33.name            = "XayahR";
		espd_33.spellName       = "XayahR";
		espd_33.range		    = 1000;
		espd_33.speed		    = FLT_MAX;
		espd_33.spellDelay	    = 50;		
		espd_33.spellKey		= R_slot;
		espd_33.evadeType	    = _Blink;
		espd_33.castType 	    = _Target;
		espd_33.spellTargets[0] = _EnemyChampions;
		//espd_33.untargetable    = true;
		vSpells->push_back(espd_33);
	//============== ## End.region Xayah =================================

	//============== ##region Irelia:	
		//-------------------- Q:
		EvadeSpellData espd_34;
		espd_34.charName       = "Irelia";
		espd_34.dangerlevel    = 2;
		espd_34.name           = "IreliaQ";
		espd_34.spellName      = "IreliaQ";
		espd_34.range		   = 595;				
		espd_34.speed		   = 1000;
		espd_34.spellDelay	   = 50;
		espd_34.spellKey	   = Q_slot;
		espd_34.evadeType	   = _Dash;
		espd_34.castType 	   = _Target;
		espd_34.spellTargets[0]= _EnemyChampions;
		espd_34.spellTargets[1]= _EnemyMinions;
		vSpells->push_back(espd_34);
	//============== ## End.region Irelia =================================

	//============== ##region Braum:	
		//-------------------- W:
		EvadeSpellData espd_35;
		espd_35.charName       = "Braum";
		espd_35.dangerlevel    = 2;
		espd_35.name           = "BraumW";
		espd_35.spellName      = "BraumW";
		espd_35.range		   = 645;				
		espd_35.speed		   = 1000;
		espd_35.spellDelay	   = 50;
		espd_35.spellKey	   = W_slot;
		espd_35.evadeType	   = _Dash;
		espd_35.castType 	   = _Target;
		espd_35.spellTargets[0]= _AllyChampions;
		espd_35.spellTargets[1]= _AllyMinions;
		vSpells->push_back(espd_35);
	//============== ## End.region Braum =================================

	//============== ##region Akali:	
		//-------------------- E:	(co the lam E-2-isSpecial dc)
		EvadeSpellData espd_36;
		espd_36.charName        = "Akali";
		espd_36.dangerlevel     = 3;
		espd_36.name            = "Shuriken Flip";
		espd_36.spellName       = "AkaliE";
		espd_36.range		    = 400;
		espd_36.spellDelay	    = 50;
		espd_36.speed		    = 975;
		espd_36.isReversed	    = true;
		espd_36.fixedRange	    = true;
		espd_36.spellKey		= E_slot;
		espd_36.evadeType	    = _Dash;
		espd_36.castType 	    = _Position;
		vSpells->push_back(espd_36);

		//-------------------- R:
		EvadeSpellData espd_37;
		espd_37.charName       = "Akali";
		espd_37.dangerlevel    = 4;
		espd_37.name           = "Perfect Execution";
		espd_37.spellName      = "AkaliR";
		espd_37.range		   = 595;				//600->cothe tang len 750(luot2)			
		espd_37.speed		   = 1000;
		espd_37.spellDelay	   = 50;
		espd_37.spellKey	   = R_slot;
		espd_37.evadeType	   = _Dash;
		espd_37.castType 	   = _Position;
		vSpells->push_back(espd_37);
	//============== ## End.region Akali =================================

	//============== ##region Evelynn:	
		//-------------------- R:	
		EvadeSpellData espd_38;
		espd_38.charName        = "Evelynn";
		espd_38.dangerlevel     = 4;
		espd_38.name            = "Last Caress";
		espd_38.spellName       = "EvelynnR";
		espd_38.range		    = 600;
		espd_38.spellDelay	    = 50;
		espd_38.speed		    = FLT_MAX;
		//espd_38.isReversed	    = true;
		//espd_38.fixedRange	    = true;
		espd_38.spellKey		= R_slot;
		espd_38.evadeType	    = _Blink;
		espd_38.castType 	    = _Target;
		espd_38.spellTargets[0] = _EnemyChampions;
		vSpells->push_back(espd_38);
	//============== ## End.region Evelynn =================================

	//============== ##region Leblanc:	
		//-------------------- W:
		EvadeSpellData espd_39;
		espd_39.charName       = "Leblanc";
		espd_39.dangerlevel    = 2;
		espd_39.name           = "Distortion";
		espd_39.spellName      = "LeblancSlide";
		espd_39.range		   = 600;							
		espd_39.speed		   = 1600;
		espd_39.spellDelay	   = 50;
		espd_39.spellKey	   = W_slot;
		espd_39.evadeType	   = _Dash;
		espd_39.castType 	   = _Position;
		vSpells->push_back(espd_39);

		//-------------------- R:
		EvadeSpellData espd_40;
		espd_40.charName       = "Leblanc";
		espd_40.dangerlevel    = 2;
		espd_40.name           = "DistortionR";
		espd_40.spellName      = "LeblancRW";			//LeblancRWReturn --> RW-2
		espd_40.checkSpellName = true;
		espd_40.range		   = 600;							
		espd_40.speed		   = 1600;
		espd_40.spellDelay	   = 50;
		espd_40.spellKey	   = R_slot;
		espd_40.evadeType	   = _Dash;
		espd_40.castType 	   = _Position;
		vSpells->push_back(espd_40);
	//============== ## End.region Leblanc =================================

	//============== ##region LeeSin:	
		//-------------------- W:
		EvadeSpellData espd_41;
		espd_41.charName       = "LeeSin";
		espd_41.dangerlevel    = 3;
		espd_41.name           = "LeeSinW";
		espd_41.spellName      = "BlindMonkWOne";
		espd_41.checkSpellName = true;
		espd_41.range		   = 695;				
		espd_41.speed		   = 1400;
		espd_41.spellDelay	   = 50;
		espd_41.spellKey	   = W_slot;
		espd_41.evadeType	   = _Dash;
		espd_41.castType 	   = _Target;
		espd_41.spellTargets[0]= _AllyChampions;
		espd_41.spellTargets[1]= _AllyMinions;			//thieu mat tim-vang
		vSpells->push_back(espd_41);
	//============== ## End.region LeeSin =================================

	//============== ##region Lulu:	(CHUA-TEST)
		//-------------------- W:
		EvadeSpellData espd_42;
		espd_42.charName        = "Lulu";
		espd_42.dangerlevel     = 3;
		espd_42.name            = "Whimsy";
		espd_42.spellName       = "LuluW";
		espd_42.spellDelay	    = 150;			//L#: 250
		espd_42.spellKey		= W_slot;
		espd_42.speedArray[0]   = 25;
		espd_42.speedArray[1]   = 30;
		espd_42.speedArray[2]   = 35;
		espd_42.speedArray[3]   = 40;
		espd_42.speedArray[4]   = 45;
		espd_42.evadeType	    = _MovementSpeedBuff;
		espd_42.castType 	    = _Self;
		vSpells->push_back(espd_42);
	//============== ## End.region Lulu =================================
		
	//============== ##region Morgana:	
		//-------------------- E:
		EvadeSpellData espd_43;
		espd_43.charName       = "Morgana";
		espd_43.dangerlevel    = 3;
		espd_43.name           = "BlackShield";
		espd_43.spellName      = "BlackShield";
		espd_43.spellDelay	   = 50;
		espd_43.spellKey	   = E_slot;
		espd_43.evadeType	   = _SpellShield;
		espd_43.castType 	   = _Self;
		vSpells->push_back(espd_43);
	//============== ## End.region Morgana =================================

	//============== ##region Nocturne:	
		//-------------------- W:
		EvadeSpellData espd_44;
		espd_44.charName       = "Nocturne";
		espd_44.dangerlevel    = 3;
		espd_44.name           = "ShroudofDarkness";
		espd_44.spellName      = "NocturneShroudofDarkness";
		espd_44.spellDelay	   = 50;
		espd_44.spellKey	   = W_slot;
		espd_44.evadeType	   = _SpellShield;
		espd_44.castType 	   = _Self;
		vSpells->push_back(espd_44);
	//============== ## End.region Nocturne =================================

	//============== ##region Nidalee:	
		//-------------------- W:
		EvadeSpellData espd_45;
		espd_45.charName       = "Nidalee";
		espd_45.dangerlevel    = 4;
		espd_45.name           = "Pounce";
		espd_45.spellName      = "Pounce";			
		espd_45.checkSpellName = true;
		espd_45.range		   = 375;							
		espd_45.speed		   = 1750;
		espd_45.spellDelay	   = 150;
		espd_45.spellKey	   = W_slot;
		espd_45.evadeType	   = _Dash;
		espd_45.castType 	   = _Position;
		//espd_45.isSpecial	   = true;			//ko can, checkName cung dc
		vSpells->push_back(espd_45);
	//============== ## End.region Nidalee =================================

	//============== ##region Poppy:	(CHUA-TEST)
		//-------------------- W:
		EvadeSpellData espd_46;
		espd_46.charName        = "Poppy";
		espd_46.dangerlevel     = 3;
		espd_46.name            = "Steadfast Presence";
		espd_46.spellName       = "PoppyW";
		espd_46.spellDelay	    = 150;			//L#: 250
		espd_46.spellKey		= W_slot;
		espd_46.speedArray[0]   = 30;
		espd_46.speedArray[1]   = 30;
		espd_46.speedArray[2]   = 30;
		espd_46.speedArray[3]   = 30;
		espd_46.speedArray[4]   = 30;
		espd_46.evadeType	    = _MovementSpeedBuff;
		espd_46.castType 	    = _Self;
		vSpells->push_back(espd_46);
	//============== ## End.region Poppy =================================
		
	//============== ##region Riven:	
		//-------------------- Q:
		EvadeSpellData espd_47;
		espd_47.charName       = "Riven";
		espd_47.dangerlevel    = 1;
		espd_47.name           = "BrokenWings";
		espd_47.spellName      = "RivenTriCleave";			
		espd_47.range		   = 300;		//L#:260
		espd_47.fixedRange	   = true;
		espd_47.speed		   = 560;
		espd_47.spellDelay	   = 50;
		espd_47.spellKey	   = Q_slot;
		espd_47.evadeType	   = _Dash;
		espd_47.castType 	   = _Position;
		espd_47.isSpecial	   = true;			
		vSpells->push_back(espd_47);

		//-------------------- E:
		EvadeSpellData espd_48;
		espd_48.charName       = "Riven";
		espd_48.dangerlevel    = 1;
		espd_48.name           = "Valor";
		espd_48.spellName      = "RivenFeint";			
		espd_48.range		   = 350;		//L#:325
		espd_48.fixedRange	   = true;
		espd_48.speed		   = 1200;
		espd_48.spellDelay	   = 50;
		espd_48.spellKey	   = E_slot;
		espd_48.evadeType	   = _Dash;
		espd_48.castType 	   = _Position;
		vSpells->push_back(espd_48);
	//============== ## End.region Riven =================================

	//============== ##region Rumble:	(CHUA-TEST)
		//-------------------- W:
		EvadeSpellData espd_49;
		espd_49.charName        = "Rumble";
		espd_49.dangerlevel     = 3;
		espd_49.name            = "Scrap Shield";
		espd_49.spellName       = "RumbleShield";
		espd_49.spellDelay	    = 50;				//L#: 50
		espd_49.spellKey		= W_slot;
		espd_49.speedArray[0]   = 10;
		espd_49.speedArray[1]   = 15;
		espd_49.speedArray[2]   = 20;
		espd_49.speedArray[3]   = 25;
		espd_49.speedArray[4]   = 30;
		espd_49.evadeType	    = _MovementSpeedBuff;
		espd_49.castType 	    = _Self;
		vSpells->push_back(espd_49);
	//============== ## End.region Rumble =================================

	//============== ##region Skarner:	(CHUA-TEST)
		//-------------------- W:
		EvadeSpellData espd_50;
		espd_50.charName        = "Skarner";
		espd_50.dangerlevel     = 3;
		espd_50.name            = "Exoskeleton";
		espd_50.spellName       = "SkarnerExoskeleton";
		espd_50.spellDelay	    = 200;				//L#: 250
		espd_50.spellKey		= W_slot;
		espd_50.speedArray[0]   = 16;
		espd_50.speedArray[1]   = 20;
		espd_50.speedArray[2]   = 24;
		espd_50.speedArray[3]   = 28;
		espd_50.speedArray[4]   = 32;
		espd_50.evadeType	    = _MovementSpeedBuff;
		espd_50.castType 	    = _Self;
		vSpells->push_back(espd_50);
	//============== ## End.region Skarner =================================

	//============== ##region Shyvana:	(CHUA-TEST)
		//-------------------- W:
		EvadeSpellData espd_51;
		espd_51.charName        = "Shyvana";
		espd_51.dangerlevel     = 3;
		espd_51.name            = "Burnout";
		espd_51.spellName       = "ShyvanaImmolationAura";
		espd_51.spellDelay	    = 50;				//L#: 50
		espd_51.spellKey		= W_slot;
		espd_51.speedArray[0]   = 30;
		espd_51.speedArray[1]   = 35;
		espd_51.speedArray[2]   = 40;
		espd_51.speedArray[3]   = 45;
		espd_51.speedArray[4]   = 50;
		espd_51.evadeType	    = _MovementSpeedBuff;
		espd_51.castType 	    = _Self;
		vSpells->push_back(espd_51);
	//============== ## End.region Shyvana =================================

	//============== ##region Sona:	(CHUA-TEST)
		//-------------------- E:
		EvadeSpellData espd_52;
		espd_52.charName        = "Sona";
		espd_52.dangerlevel     = 3;
		espd_52.name            = "Song of Celerity";
		espd_52.spellName       = "SonaE";
		espd_52.spellDelay	    = 200;				//L#: 250
		espd_52.spellKey		= E_slot;
		espd_52.speedArray[0]   = 13;
		espd_52.speedArray[1]   = 14;
		espd_52.speedArray[2]   = 15;
		espd_52.speedArray[3]   = 16;
		espd_52.speedArray[4]   = 25;
		espd_52.evadeType	    = _MovementSpeedBuff;
		espd_52.castType 	    = _Self;
		vSpells->push_back(espd_52);
	//============== ## End.region Sona =================================

	//============== ##region Teemo:	(CHUA-TEST)
		//-------------------- W:
		EvadeSpellData espd_53;
		espd_53.charName        = "Teemo";
		espd_53.dangerlevel     = 3;
		espd_53.name            = "Move Quick";
		espd_53.spellName       = "MoveQuick";
		espd_53.spellDelay	    = 200;				//L#: 250
		espd_53.spellKey		= W_slot;
		espd_53.speedArray[0]   = 10;
		espd_53.speedArray[1]   = 14;
		espd_53.speedArray[2]   = 18;
		espd_53.speedArray[3]   = 22;
		espd_53.speedArray[4]   = 26;
		espd_53.evadeType	    = _MovementSpeedBuff;
		espd_53.castType 	    = _Self;
		vSpells->push_back(espd_53);
	//============== ## End.region Teemo =================================

	//============== ##region Udyr:	(CHUA-TEST)
		//-------------------- E:
		EvadeSpellData espd_54;
		espd_54.charName        = "Udyr";
		espd_54.dangerlevel     = 3;
		espd_54.name            = "Bear Stance";
		espd_54.spellName       = "UdyrBearStance";
		espd_54.spellDelay	    = 50;				//L#: 50
		espd_54.spellKey		= E_slot;
		espd_54.speedArray[0]   = 15;
		espd_54.speedArray[1]   = 20;
		espd_54.speedArray[2]   = 25;
		espd_54.speedArray[3]   = 30;
		espd_54.speedArray[4]   = 35;
		espd_54.evadeType	    = _MovementSpeedBuff;
		espd_54.castType 	    = _Self;
		vSpells->push_back(espd_54);
	//============== ## End.region Udyr =================================

	//============== ##region Zilean:	(CHUA-TEST)
		//-------------------- E:
		EvadeSpellData espd_55;
		espd_55.charName        = "Zilean";
		espd_55.dangerlevel     = 3;
		espd_55.name            = "Timewarp";
		espd_55.spellName       = "ZileanE";
		espd_55.spellDelay	    = 150;				//L#: 250
		espd_55.spellKey		= E_slot;
		espd_55.speedArray[0]   = 40;
		espd_55.speedArray[1]   = 55;
		espd_55.speedArray[2]   = 70;
		espd_55.speedArray[3]   = 85;
		espd_55.speedArray[4]   = 99;
		espd_55.evadeType	    = _MovementSpeedBuff;
		espd_55.castType 	    = _Self;
		vSpells->push_back(espd_55);
	//============== ## End.region Zilean =================================

	//============== ##region Shaco:	
		//-------------------- Q:
		EvadeSpellData espd_56;
		espd_56.charName        = "Shaco";
		espd_56.dangerlevel     = 3;
		espd_56.name            = "Deceive";
		espd_56.spellName       = "Deceive";
		espd_56.range		    = 400;
		espd_56.spellDelay	    = 150;		//L#:250	(ko co progress-bar)
		espd_56.spellKey		= Q_slot;
		espd_56.evadeType	    = _Blink;
		espd_56.castType 	    = _Position;
		vSpells->push_back(espd_56);
	//============== ## End.region Shaco =================================
		
	//============== ##region Talon:	
		//-------------------- Q:
		EvadeSpellData espd_57;
		espd_57.charName       = "Talon";
		espd_57.dangerlevel    = 3;
		espd_57.name           = "Noxian Diplomacy";
		espd_57.spellName      = "TalonQ";
		espd_57.range		   = 570;				
		espd_57.speed		   = 900;
		espd_57.spellDelay	   = 50;
		espd_57.spellKey	   = Q_slot;
		espd_57.evadeType	   = _Dash;
		espd_57.castType 	   = _Target;
		espd_57.spellTargets[0]= _EnemyChampions;
		espd_57.spellTargets[1]= _EnemyMinions;	
		espd_57.isSpecial	   = true;	
		vSpells->push_back(espd_57);

		//-------------------- R:
		EvadeSpellData espd_58;
		espd_58.charName        = "Talon";
		espd_58.dangerlevel     = 4;
		espd_58.name            = "Shadow Assault";
		espd_58.spellName       = "TalonR";
		espd_58.spellDelay	    = 150;				//L#: 250
		espd_58.spellKey		= R_slot;
		espd_58.speedArray[0]   = 40;
		espd_58.speedArray[1]   = 55;
		espd_58.speedArray[2]   = 70;
		espd_58.speedArray[3]   = 70;
		espd_58.speedArray[4]   = 70;
		espd_58.evadeType	    = _MovementSpeedBuff;
		espd_58.castType 	    = _Self;
		vSpells->push_back(espd_58);
	//============== ## End.region Talon =================================
			
	//============== ##region Tristana:	
		//-------------------- W:
		EvadeSpellData espd_59;
		espd_59.charName       = "Tristana";
		espd_59.dangerlevel    = 3;
		espd_59.name           = "RocketJump";
		espd_59.spellName      = "RocketJump";			
		espd_59.range		   = 900;		
		espd_59.speed		   = 1100;
		espd_59.spellDelay	   = 500;
		espd_59.spellKey	   = W_slot;
		espd_59.evadeType	   = _Dash;
		espd_59.castType 	   = _Position;
		vSpells->push_back(espd_59);
	//============== ## End.region Tristana =================================

	//============== ##region Tryndamere:	
		//-------------------- E:
		EvadeSpellData espd_60;
		espd_60.charName       = "Tryndamere";
		espd_60.dangerlevel    = 3;
		espd_60.name           = "SpinningSlash";
		espd_60.spellName      = "Slash";			
		espd_60.range		   = 660;		
		espd_60.speed		   = 900;
		espd_60.spellDelay	   = 50;
		espd_60.spellKey	   = E_slot;
		espd_60.evadeType	   = _Dash;
		espd_60.castType 	   = _Position;
		vSpells->push_back(espd_60);
	//============== ## End.region Tryndamere =================================

	//============== ##region Yasuo:	
		//-------------------- E:
		EvadeSpellData espd_61;
		espd_61.charName       = "Yasuo";
		espd_61.dangerlevel    = 2;
		espd_61.name           = "SweepingBlade";
		espd_61.spellName      = "YasuoDashWrapper";
		espd_61.range		   = 475;	
		espd_61.fixedRange	   = true;
		espd_61.speed		   = 1000;
		espd_61.spellDelay	   = 50;
		espd_61.spellKey	   = E_slot;
		espd_61.evadeType	   = _Dash;
		espd_61.castType 	   = _Target;
		espd_61.spellTargets[0]= _EnemyChampions;
		espd_61.spellTargets[1]= _EnemyMinions;	
		vSpells->push_back(espd_61);
		
		//-------------------- W:
		EvadeSpellData espd_62;
		espd_62.charName        = "Yasuo";
		espd_62.dangerlevel     = 3;
		espd_62.name            = "WindWall";
		espd_62.spellName       = "YasuoWMovingWall";
		espd_62.range		    = 400;
		espd_62.spellDelay	    = 100;			//L#:250
		espd_62.spellKey		= W_slot;
		espd_62.evadeType	    = _WindWall;
		espd_62.castType 	    = _Position;
		vSpells->push_back(espd_62);
	//============== ## End.region Yasuo =================================
		
	//============== ##region Elise:
		//-------------------- E:
		EvadeSpellData espd_63;
		espd_63.charName       = "Elise";
		espd_63.dangerlevel    = 4;
		espd_63.name           = "Rappel";
		espd_63.spellName      = "EliseSpiderEInitial";
		espd_63.spellDelay	   = 50;
		espd_63.checkSpellName = true;
		espd_63.spellKey	   = E_slot;
		espd_63.evadeType	   = _SpellShield;
		espd_63.castType 	   = _Self;
		espd_63.untargetable   = true;
		espd_63.isSpecial	   = true;
		vSpells->push_back(espd_63);
	//================================ ## End.region Elise =================================



	//=================//=================//=================//=================//=================//=================||
	//=================//=================//=================//=================//=================//=================||

	//============== ##region AllChampions:	
		EvadeSpellData espd_100;
		espd_100.charName		 = "AllChampions";
		espd_100.dangerlevel	 = 4;
		espd_100.name			 = "Flash";
		espd_100.spellName		 = "SummonerFlash";
		espd_100.range		     = 425;
		espd_100.fixedRange	     = true;	//test
		espd_100.spellDelay	     = 50;
		espd_100.isSummonerSpell = true;
		espd_100.spellKey		 = R_slot;
		espd_100.evadeType	     = _Blink;
		espd_100.castType 	     = _Position;
		vSpells->push_back(espd_100);
	//============== ## End.region AllChampions =================================

	




	}
};
