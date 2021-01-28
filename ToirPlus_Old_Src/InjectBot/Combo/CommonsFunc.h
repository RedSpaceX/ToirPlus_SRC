#pragma once
#include "Utils.h"

enum SKILL_HERO
{
	SKILL_Q = 0,
	SKILL_W = 1,
	SKILL_E = 2,
	SKILL_R = 3,
	_Q = 0,
	_W = 1,
	_E = 2,
	_R = 3,
};
enum BuffType{
	Internal_Buff				= 0,
	Aura_Buff					= 1,
	CombatEnchancer_Buff		= 2,
	CombatDehancer_Buff			= 3,
	SpellShield_Buff			= 4,
	Stun_Buff					= 5,
	Invisibility_Buff			= 6,
	Silence_Buff				= 7,
	Taunt_Buff					= 8,
	Polymorph_Buff				= 9,
	Slow_Buff					= 10,
	Snare_Buff					= 11,
	Damage_Buff					= 12,
	Heal_Buff					= 13,
	Haste_Buff					= 14,
	SpellImmunity_Buff			= 15,
	PhysicalImmunity_Buff		= 16,
	Invulnerability_Buff		= 17,
	Sleep_Buff					= 18,
	NearSight_Buff				= 19,
	Frenzy_Buff					= 20,
	Fear_Buff					= 21,
	Charm_Buff					= 22,
	Poison_Buff					= 23,
	Suppression_Buff			= 24,
	Blind_Buff					= 25,
	Counter_Buff				= 26,
	Shred_Buff					= 27,
	Flee_Buff					= 28,
	Knockup_Buff				= 29,
	Knockback_Buff				= 30,
	Disarm_Buff					= 31
};

void		DO_SKILL_LINE(KNpc* pEnemy, int sttSkill, float nKhoangCach = 200);
void		DO_SKILL_LINE_4LUA(KNpc* pEnemy, int sttSkill, float nKhoangCach = 200);

void		DO_SKILL_LINE_POS(KPos *StartPos, KPos* EndPos, int sttSkill);
void		DO_SKILL_LINE_POS_4LUA(KPos *StartPos, KPos* EndPos, int sttSkill);

void		DO_SKILL_TO_POS(KPos *pPos, int sttSkill);//cai nay chi danh cho lua
void		RELEASE_SKILL_TO_POS(KPos *pPos, int sttSkill);//cai nay chi danh cho lua

void		RELEASE_SKILL_LINE(KNpc* pEnemy, int sttSkill, float nKhoangCach = 160);
void		RELEASE_SKILL_LINE_4LUA(KNpc* pEnemy, int sttSkill, float nKhoangCach = 160);

void		RELEASE_SKILL_LINE_2(KNpc* pEnemy, int sttSkill, float nKhoangCach = 100);// Kieu Skill R-VelKoz
void		RELEASE_SKILL_LINE_2_4LUA(KNpc* pEnemy, int sttSkill, float nKhoangCach = 100);// Kieu Skill R-VelKoz

//void		CANCEL_SKILL(int sttSkill);
void		DO_SKILL_TARGET(KNpc *pEnemy, int sttSkill);
void		DO_SKILL_TARGET_4LUA(KNpc *pEnemy, int sttSkill);

bool		DO_SKILL_SMITE(KNpc *pEnemy);
KNpc*		GetJungle(float nRange = 0);
KNpc*		GetJungle_Small(float nRange = 0);
KNpc*		GetJungleNearest(float nRange = 0);

KPos		GetPos_DuDoan(KNpc *pEnemy, float nKhoangCach);

int			CountSkillAttacking(KNpc *pNpcIsAttacked);
int			CountNPCAttack(KNpc *pNpcIsAttacked);
int			CountMinionAttack(KNpc *pNpcIsAttacked);

bool		IS_INLINE_SKILL(KNpc *pNpc, KPos *startPoint,KPos *endPoint, float nRadius, float nRange, bool isHasMinion);
int			NPC_INLINE_SKILL(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach = 10);
int			NPC_INLINE_SKILL2(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach = 10);
int			CHAMP_INLINE_SKILL(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach = 10);
int			HERO_R_INLINE_SKILL(KNpc* pEnemy1, KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach = 10);
int			CountEnemyInQuadOf(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nWidth, float nLength);

void		ThongBaoDutDiem(KNpc *pEnemy, int SttSkill);
bool		hasSpell(int stt, char* szName);
bool		DO_SKILL_ITEM(KNpc* pNPC, char* ITEM_NAME);
int			GET_STT_SKILL(char* SKILL_NAME);

bool		hasItem(int nID);
KItem*		GET_ITEM(int nID);
KItem*		GET_ITEM_2(KNpc* pNPC, int nID);

int			GET_ITEM_ID(int nSlotItem);
bool		BUY_ITEM(int nID);
bool		SELL_ITEM(int nIndex);
bool		UP_LEVEL(int nSTT_Skill);

KPos		GET_ENEMY_POS_B();

KBuffs*		GET_BUFF(KNpc* pNpc ,char* szBuffName);
char*		GET_BUFF_NAME(KBuffs* pBuff);
KNpc*		GetObjectByBuff(KBuffs *pCurBuff);
void		Get_All_BuffNameActive(KNpc* pNpc, char* (&nResult)[60]);
int			COUNT_BUFF_BY_TYPE(KNpc* pNpc, int nType);
int			GET_BUFF_DUNGIM(KNpc* pEnemy);
int			GET_BUFF_SLOW(KNpc* pEnemy);
int			GET_BUFF_BATLOI(KNpc* pEnemy);
int			GET_BUFF_MIKAEL(KNpc* unit);
int			GET_BUFF_THANHTAY(KNpc* unit);
int			GET_BUFF_DACBIET(KNpc* pEnemy);


//-----------New---------------------------------
bool isRiotOnTop();
KPos  mousePosKpos();
Vec3D mousePosVec3D();

bool IsUnderTurretEnemy(KPos* pos, float range = 922);
bool IsUnderTurretEnemy(Vec3D* pos, float range = 922);
bool IsUnderTurretAlly(KPos* pos, float range = 910);
bool IsUnderTurretAlly(Vec3D* pos, float range = 910);

int CountAlliesInRange (KPos*  pos, float range);
int CountAlliesInRange (Vec3D* pos, float range);
int CountEnemiesInRange(KPos*  pos, float range);
int CountEnemiesInRange(Vec3D* pos, float range);

bool IsGoodPosition(Vec3D* dashPos, float segment);
bool IsGoodPosition(KPos*  dashPos, float segment);

bool IsImmobileTarget(KNpc* target);
bool UnitCanMove(KNpc *unit);

float calDamage(KNpc* unit, float dmgRaw, DamageType dmgType);
KNpc* GetEnemyDash(float kc2enemy = 600.0f, float kc2endPos = 285.0f);

KNpc* InterrupSpell(float range);

bool CanCast(int stt);
BYTE StateSpell(int stt);

void Cast2Target(KNpc* unit, int stt);
void Cast2Pos(KPos* pos, int stt);
void Cast2Pos(Vec3D* pos, int stt);

Vec3D GetEnemySpawnPos();
int R_Collision(KNpc *pPlayer, KNpc *target, float radius, Vec3D posEnd);		// dung cho BaseUlt hoac enemyHero collision
int Minion_Collision(KNpc *pPlayer, KNpc *target, float radius, Vec3D posEnd);	// dung cho enemyMinion-collision
KNpc* GetMinionNearestOneNPC(KNpc* target, float rangeAroundNpc, float rangeAroundMe, bool isEnemy = true);

void prio_redList();
void prio_whiteList();
void prio_blackList();
void prio_meleeList();
void prio_meleeList_2();
bool isHeroCanDash(char* c);
void prio_dashList();
void prio_dashList_2();
