#include "DodgeSyndraS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"
#include "Position.h"


extern SpellDetector* _SpellDetector;
//---------------------------------------------------------------------//--------------------//
void Evade_Syndra_W()
{
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Syndra")) continue;
	////////	if (Distance(enemyHero, myHero) > 2500)				continue;

	////////	//------//------//------:
	////////	KNpc* objectPicked = 0;
	////////	
	////////	//------//------//------:
	////////	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	////////	if (!dw0) return;

	////////	DWORD dw1 = *(DWORD*)(dw0 + 8);
	////////	if (!dw1) return;

	////////	int nCount = *(DWORD*)(dw0 + 0xC);
	////////	if (!nCount) return;

	////////	for (int kk = 0; kk < nCount; ++kk)
	////////	{
	////////		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	////////		if (dw3 == 0) continue;
	////////		KNpc *missileObj = (KNpc*)dw3;

	////////		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	////////		if (missileObj->nIndex < 0x3FFFFCC8)     continue;
	////////		if (OBJECT_TYPE(missileObj) != 1)		 continue;

	////////		if (CheckName("Syndra",missileObj->GetNameNpc()) && CheckName("W_cas",missileObj->GetNameNpc()))	// "Syndra_Base_W_cas" va Dashing
	////////		{
	////////			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////			DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////			if (!dwUnit1 || !dwUnit2 ) return;
	////////			int countUnit = (dwUnit2 - dwUnit1)/4;
	////////			for (int iii = 0; iii < countUnit; ++iii)
	////////			{
	////////				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////				if (dwUnit3 == 0) continue;
	////////				KNpc *enemyHiu = (KNpc*)dwUnit3;
	////////				if (IS_DEAD(enemyHiu))    continue;
	////////				if (!IS_MINION(enemyHiu)) continue;
	////////				if (!IsCanSee(enemyHiu))  continue;
	////////				
	////////				if (enemyHiu->nTeam_ID == 0x12C)
	////////				{
	////////					if (!CheckName(sz__SRU_, enemyHiu->GetNameNpc())) 
	////////					{
	////////						if(!CheckName(sz__Sru_, enemyHiu->GetNameNpc()))
	////////						{
	////////							if(!CheckName(sz__MiniKrug, enemyHiu->GetNameNpc()))
	////////							{
	////////								if(!CheckName("TT_N", enemyHiu->GetNameNpc()))					//TT_NWolf23.1.2 - TT_NWraith21.1.2 - TT_NGolem22.1.2
	////////								{
	////////									if(!CheckName("TT_S", enemyHiu->GetNameNpc())) continue;	//TT_Spiderboss8.1.1
	////////								}
	////////							}
	////////						}
	////////					}
	////////				}
	////////				else
	////////				{
	////////					if (enemyHiu->nTeam_ID == myHero->nTeam_ID)
	////////					{
	////////						if (CheckName(sz__Minion, enemyHiu->GetNameNpc()) && GET_BUFF(enemyHiu, "syndrawbuff") /*&& IsDashing(enemyHiu)*/)
	////////						{
	////////							objectPicked = enemyHiu;
	////////							//__oMsg("vao----222--22");
	////////							break;
	////////						}
	////////					}
	////////					else
	////////					{
	////////						if ((BYTE)enemyHiu->nIsTargetableToTeam != 4 && CheckName(sz__Seed, enemyHiu->GetNameNpc()) && CheckName(sz__SyndraSphere, enemyHiu->GetNameHero()))
	////////						{
	////////							if (IsDashing(enemyHiu))
	////////							{
	////////								objectPicked = enemyHiu;
	////////								//__oMsg("vao----333--33");
	////////								break;
	////////							}
	////////						}
	////////					}
	////////				}

	////////				if (GET_BUFF(enemyHiu, "syndrawbuff") /*&& IsDashing(enemyHiu)*/)
	////////				{
	////////					objectPicked = enemyHiu;
	////////					//__oMsg("vao----111--11");
	////////					break;
	////////				}
	////////			}
	////////		}
	////////	}

	////////	if (objectPicked != 0 && IsUnitInList(objectPicked) && !IS_DEAD(objectPicked) && objectPicked->currentPos().y > enemyHero->currentPos().y + 40)
	////////	{
	////////		//__oMsg("--Syndra-W-YES-222: %f", GetTimeGame());
	////////		std::string mis_Name("SyndraW_Special");

	////////		std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	////////		if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	////////		{
	////////			//it_onMissileSpells->second.range = max_KC + 25;
	////////			SpellData spellData = it_onMissileSpells->second;

	////////			Vec3D StartPos = objectPicked->currentPos();
	////////			Vec3D EndPos   = GET_END_POS(objectPicked);
	////////			if (EndPos.IsValid() == false) continue;

	////////			if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////			{
	////////				//if (IsCanSee(enemyHero))	//xerath ko can cai nay
	////////				{
	////////					//--------------------------------:
	////////					if(it_onMissileSpells->second.projectileSpeed == 0) continue;
	////////					float missileLifeTime = 1000 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;

	////////					if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
	////////					{
	////////						//__oMsg("---((***))----- SYNDRA.W-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
	////////						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////						it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}	
}

//---------------------------------------------------------------------//--------------------//
////////struct _qSphere
////////{
////////	KNpc* sphere;
////////	float timeCreateSpell;
////////	_qSphere()
////////	{
////////		sphere = 0;
////////		timeCreateSpell = 0;
////////	}
////////};
////////
////////std::vector<_qSphere*> _listSphere;
////////float radius_cone = 210;
////////std::map<float, Vec3D> *_qSpots = 0;
//---------------------------------------------------------------------//--------------------//
void Evade_Syndra_E()
{
	////////if (_qSpots == 0)
	////////{
	////////	_qSpots = new std::map<float, Vec3D>;
	////////	return;
	////////}

	//////////---- Remove _qSpots :
	////////if ((int)_qSpots->size() > 0)
	////////{
	////////	for (std::map<float, Vec3D>::iterator it_xxx=_qSpots->begin(); it_xxx!=_qSpots->end(); ++it_xxx)
	////////	{
	////////		float timestamp = it_xxx->first;
	////////		if (GetTimeGame() - timestamp > 1.2f /** 0.6f*/)
	////////		{
	////////			_qSpots->erase(it_xxx);
	////////			break;
	////////		}
	////////	}
	////////}
	//////////---------//------------||

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
	////////	if (Distance(enemyHero, myHero) > 2000)				continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Syndra")) continue;
	////////	

	////////	//------//------//------:
	////////	//std::vector<_qSpots*> _listSphere;

	////////	KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////////	if (!args) continue;

	////////	KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////////	if(!pK_str2) continue;

	////////	std::string spell_name(pK_str2->GetSkillName());

	////////	if (spell_name.compare("SyndraE5") == 0)
	////////		radius_cone = 460;
	////////	
	////////	if (spell_name.compare("SyndraE5") != 0 && spell_name.compare("SyndraE") != 0) continue;

	////////	Vec3D estart(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	////////	Vec3D eend_1(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
	////////	Vec3D eend = Extend(estart, eend_1, 800);

	////////	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////	if (!dwUnit1 || !dwUnit2 ) return;
	////////	int countUnit = (dwUnit2 - dwUnit1)/4;
	////////	for (int iii = 0; iii < countUnit; ++iii)
	////////	{
	////////		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////		if (dwUnit3 == 0) continue;
	////////		KNpc *sphere = (KNpc*)dwUnit3;
	////////		if (sphere->nTeam_ID == myHero->nTeam_ID)	continue;
	////////		if ((BYTE)sphere->nIsTargetableToTeam == 4) continue;
	////////		if (IS_DEAD(sphere))    continue;
	////////		if (!IS_MINION(sphere)) continue;
	////////		if (Distance(myHero, sphere) > 2000) continue;

	////////		if (CheckName(sz__Seed, sphere->GetNameNpc()) && CheckName(sz__SyndraSphere, sphere->GetNameHero()))
	////////		{	
	////////			Vec3D direction = (eend - estart).Normalized();
	////////			Vec3D cnLeft    = eend + Perpendicular(direction) * (radius_cone + 155 + 50);
	////////			Vec3D cnRight   = eend - Perpendicular(direction) * (radius_cone + 155 + 50);

	////////			if( !isLeftOfLineSegment(sphere->currentPos(), estart , cnLeft) && !isLeftOfLineSegment(sphere->currentPos(), cnLeft, cnRight) && !isLeftOfLineSegment(sphere->currentPos(), cnRight, estart))
	////////			{
	////////				bool coSphereGanNhau = false;

	////////				if ((int)_listSphere.size() == 0)
	////////				{
	////////					if ((int)_qSpots->size() > 0)
	////////					{
	////////						int tempSize = (int)_qSpots->size();
	////////						for (std::map<float, Vec3D>::iterator it_xxx=_qSpots->begin(); it_xxx!=_qSpots->end(); ++it_xxx)
	////////						{
	////////							if (tempSize != (int)_qSpots->size()) break;

	////////							Vec3D pos  = it_xxx->second;
	////////							Vec3D dir1 = (pos - enemyHero->currentPos());
	////////							Vec3D dir2 = (sphere->currentPos() - enemyHero->currentPos());
	////////							if (Distance(pos, sphere->currentPos()) <= 30 || AngleBetween(dir1, dir2) < 15)
	////////							{
	////////								coSphereGanNhau = true;
	////////								//__oMsg(" 1-co_SPOT_Gan_SPHERE-2");
	////////								break;
	////////							}
	////////						}
	////////					}
	////////					
	////////					if (coSphereGanNhau == false)
	////////					{
	////////						_qSphere* temp_sphere		  = new _qSphere;
	////////						temp_sphere->sphere			  = sphere;
	////////						temp_sphere->timeCreateSpell  = 0;

	////////						_listSphere.push_back(temp_sphere);
	////////						//__oMsg("insertSphere-1");
	////////						continue;
	////////					}
	////////				}
	////////				else
	////////				{
	////////					for (int xx = 0; xx < (int)_listSphere.size(); ++xx)
	////////					{
	////////						if (_listSphere[xx]->sphere != 0 && IsUnitInList(_listSphere[xx]->sphere) && !IS_DEAD(_listSphere[xx]->sphere))
	////////						{
	////////							if ((BYTE)_listSphere[xx]->sphere->nIsTargetableToTeam != 4 && CheckName(sz__Seed, _listSphere[xx]->sphere->GetNameNpc()) && CheckName(sz__SyndraSphere, _listSphere[xx]->sphere->GetNameHero()))
	////////							{
	////////								if (Distance(_listSphere[xx]->sphere, sphere) <= 30)
	////////								{
	////////									coSphereGanNhau = true;
	////////									//__oMsg(" 1-co_SPHERE_Gan_SPHERE");
	////////									break;
	////////								}
	////////							}
	////////						}
	////////					}

	////////					if (coSphereGanNhau == false)
	////////					{
	////////						if ((int)_qSpots->size() > 0)
	////////						{
	////////							int tempSize = (int)_qSpots->size();
	////////							for (std::map<float, Vec3D>::iterator it_xxx=_qSpots->begin(); it_xxx!=_qSpots->end(); ++it_xxx)
	////////							{
	////////								if (tempSize != (int)_qSpots->size()) break;

	////////								Vec3D pos = it_xxx->second;
	////////								Vec3D dir1 = (pos - enemyHero->currentPos());
	////////								Vec3D dir2 = (sphere->currentPos() - enemyHero->currentPos());
	////////								if (Distance(pos, sphere->currentPos()) <= 30 || AngleBetween(dir1, dir2) < 15)
	////////								{
	////////									coSphereGanNhau = true;
	////////									//__oMsg(" 1-co_SPOT_Gan_SPHERE-2");
	////////									break;
	////////								}
	////////							}
	////////						}
	////////						if (coSphereGanNhau == false)
	////////						{
	////////							_qSphere* temp_sphere		  = new _qSphere;
	////////							temp_sphere->sphere			  = sphere;
	////////							temp_sphere->timeCreateSpell  = 0;
	////////							_listSphere.push_back(temp_sphere);
	////////							//__oMsg("insertSphere-2");
	////////							continue;
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////	
	////////	//------//------//------:
	////////	std::string mis_Name("SyndraE_Special");

	////////	for (int xx = 0; xx < (int)_listSphere.size(); ++xx)
	////////	{
	////////		if (_listSphere[xx]->sphere != 0 && IsUnitInList(_listSphere[xx]->sphere) && !IS_DEAD(_listSphere[xx]->sphere))
	////////		{
	////////			if ((BYTE)_listSphere[xx]->sphere->nIsTargetableToTeam != 4 && CheckName(sz__Seed, _listSphere[xx]->sphere->GetNameNpc()) && CheckName(sz__SyndraSphere, _listSphere[xx]->sphere->GetNameHero()))
	////////			{
	////////				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	////////				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	////////				{
	////////					float max_KC = 1250 - Distance(_listSphere[xx]->sphere, enemyHero);

	////////					it_onMissileSpells->second.range = max_KC + 25;
	////////					it_onMissileSpells->second.spellDelay = 250 + 1000 * Distance(_listSphere[xx]->sphere, enemyHero) / it_onMissileSpells->second.projectileSpeed;
	////////					//__oMsg("		  [xx=%d]--Syndra-E-YES-222: KC = %f - %f, spellDelay: %f (%d)", xx, max_KC, GetTimeGame(), it_onMissileSpells->second.spellDelay, _listSphere.size());

	////////					SpellData spellData = it_onMissileSpells->second;

	////////					Vec3D StartPos = _listSphere[xx]->sphere->currentPos();
	////////					Vec3D EndPos   = _listSphere[xx]->sphere->currentPos() + (_listSphere[xx]->sphere->currentPos() - enemyHero->currentPos()).Normalized() * spellData.range;

	////////					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////					{
	////////						//--------------------------------:
	////////						if (it_onMissileSpells->second.projectileSpeed == 0) continue;
	////////						float missileLifeTime = 666 + spellData.spellDelay + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;

	////////						if ((float)GetTickCount() - _listSphere[xx]->timeCreateSpell > missileLifeTime)
	////////						{
	////////							//__oMsg("---((*11*))----- SYNDRA.E-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
	////////							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////							//it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
	////////							_listSphere[xx]->timeCreateSpell = (float)GetTickCount();
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}	
}

//---------------------------------------------------------------------//--------------------//
float timeCreate_qSpots = 0;
void Evade_Syndra_E2()
{
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
	////////	if (Distance(enemyHero, myHero) > 2000)				continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Syndra")) continue;
	////////	
	////////	//------//------//------:

	////////	KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////////	if (!args) continue;

	////////	KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////////	if(!pK_str2) continue;

	////////	std::string spell_name(pK_str2->GetSkillName());

	////////	if (spell_name.compare("SyndraE5") == 0)
	////////		radius_cone = 460;

	////////	if (spell_name.compare("SyndraE5") != 0 && spell_name.compare("SyndraE") != 0) continue;

	////////	Vec3D estart(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	////////	Vec3D eend_1(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
	////////	Vec3D eend = Extend(estart, eend_1, 800);


	////////	//------//------//------:
	////////	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	////////	if (!dw0) return;

	////////	DWORD dw1 = *(DWORD*)(dw0 + 8);
	////////	if (!dw1) return;

	////////	int nCount = *(DWORD*)(dw0 + 0xC);
	////////	if (!nCount) return;

	////////	for (int kk = 0; kk < nCount; ++kk)
	////////	{
	////////		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	////////		if (dw3 == 0) continue;
	////////		KNpc *missileObj = (KNpc*)dw3;

	////////		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	////////		if (missileObj->nIndex < 0x3FFFFCC8)     continue;
	////////		//if (OBJECT_TYPE(missileObj) != 1 && OBJECT_TYPE(missileObj) != 0x8001)  continue;
	////////		if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
	////////		if (!IS_OBJECT_TYPE(missileObj, 0x8000))	  continue;
	////////		if (Distance(missileObj->currentPos(), myHero->currentPos()) > 2000) continue;

	////////		if (CheckName("SyndraQSpell",missileObj->GetNameNpc()))
	////////		{
	////////			Vec3D direction = (eend - estart).Normalized();
	////////			Vec3D cnLeft    = eend + Perpendicular(direction) * (radius_cone + 155 + 50);
	////////			Vec3D cnRight   = eend - Perpendicular(direction) * (radius_cone + 155 + 50);

	////////			Vec3D missilePos(missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
	////////			if( !isLeftOfLineSegment(missilePos, estart , cnLeft) && !isLeftOfLineSegment(missilePos, cnLeft, cnRight) && !isLeftOfLineSegment(missilePos, cnRight, estart))
	////////			{
	////////				bool coSphereGanNhau = false;

	////////				if ((int)_qSpots->size() == 0)
	////////				{
	////////					if ((int)_listSphere.size() > 0)
	////////					{
	////////						for (int xx = 0; xx < (int)_listSphere.size(); ++xx)
	////////						{
	////////							if (_listSphere[xx]->sphere != 0 && IsUnitInList(_listSphere[xx]->sphere) && !IS_DEAD(_listSphere[xx]->sphere))
	////////							{
	////////								if ((BYTE)_listSphere[xx]->sphere->nIsTargetableToTeam != 4 && CheckName(sz__Seed, _listSphere[xx]->sphere->GetNameNpc()) && CheckName(sz__SyndraSphere, _listSphere[xx]->sphere->GetNameHero()))
	////////								{
	////////									Vec3D dir1 = (missilePos - enemyHero->currentPos());
	////////									Vec3D dir2 = (_listSphere[xx]->sphere->currentPos() - enemyHero->currentPos());

	////////									if (Distance(_listSphere[xx]->sphere, missilePos) <= 30 || AngleBetween(dir1, dir2) < 15)
	////////									{
	////////										coSphereGanNhau = true;
	////////										//__oMsg(" 2-co_SPHERE_Gan_SPOT-1");
	////////										break;
	////////									}
	////////								}
	////////							}
	////////						}
	////////					}

	////////					if (coSphereGanNhau == false)
	////////					{
	////////						_qSpots->insert( std::pair<float, Vec3D>(GetTimeGame(), missilePos) );
	////////						//__oMsg("insert_qSpots-1");
	////////						continue;
	////////					}	
	////////				}
	////////				else
	////////				{
	////////					int tempSize = (int)_qSpots->size();
	////////					for (std::map<float, Vec3D>::iterator it_xxx=_qSpots->begin(); it_xxx!=_qSpots->end(); ++it_xxx)
	////////					{
	////////						if (tempSize != (int)_qSpots->size()) break;

	////////						Vec3D pos = it_xxx->second;
	////////						if (pos.IsValid() && Distance(pos, missilePos) <= 30)
	////////						{
	////////							coSphereGanNhau = true;
	////////							//__oMsg(" 2-co_SPOT_Gan_SPOT");
	////////							break;
	////////						}
	////////					}
	////////					if (coSphereGanNhau == false)
	////////					{
	////////						if ((int)_listSphere.size() > 0)
	////////						{
	////////							for (int xx = 0; xx < (int)_listSphere.size(); ++xx)
	////////							{
	////////								if (_listSphere[xx]->sphere != 0 && IsUnitInList(_listSphere[xx]->sphere) && !IS_DEAD(_listSphere[xx]->sphere))
	////////								{
	////////									if ((BYTE)_listSphere[xx]->sphere->nIsTargetableToTeam != 4 && CheckName(sz__Seed, _listSphere[xx]->sphere->GetNameNpc()) && CheckName(sz__SyndraSphere, _listSphere[xx]->sphere->GetNameHero()))
	////////									{
	////////										Vec3D dir1 = (missilePos - enemyHero->currentPos());
	////////										Vec3D dir2 = (_listSphere[xx]->sphere->currentPos() - enemyHero->currentPos());

	////////										if (Distance(_listSphere[xx]->sphere, missilePos) <= 30 || AngleBetween(dir1, dir2) < 15)
	////////										{
	////////											coSphereGanNhau = true;
	////////											//__oMsg(" 2-co_SPHERE_Gan_SPOT-2");
	////////											break;
	////////										}
	////////									}
	////////								}
	////////							}
	////////						}

	////////						if (coSphereGanNhau == false)
	////////						{
	////////							_qSpots->insert( std::pair<float, Vec3D>(GetTimeGame(), missilePos) );
	////////							//__oMsg("insert_qSpots-2");
	////////							continue;
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}

	////////	//------//------//------:
	////////	std::string mis_Name("SyndraE_Special");
	////////	
	////////	int tempSize = (int)_qSpots->size();
	////////	for (std::map<float, Vec3D>::iterator it_xxx=_qSpots->begin(); it_xxx!=_qSpots->end(); ++it_xxx)
	////////	{
	////////		if (tempSize != (int)_qSpots->size()) break;

	////////		Vec3D pos = it_xxx->second;
	////////		if (pos.IsValid())
	////////		{
	////////			std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	////////			if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	////////			{
	////////				float max_KC = 1250 - Distance(pos, enemyHero->currentPos());

	////////				it_onMissileSpells->second.range      = max_KC + 25;
	////////				it_onMissileSpells->second.spellDelay = 250 + 1000 * Distance(pos, enemyHero->currentPos()) / it_onMissileSpells->second.projectileSpeed;
	////////				//__oMsg("		  --Syndra-E-YES-222: KC = %f - %f, spellDelay: %f (size: %d)", max_KC, GetTimeGame(), it_onMissileSpells->second.spellDelay, _qSpots->size());

	////////				SpellData spellData = it_onMissileSpells->second;

	////////				Vec3D StartPos = pos;
	////////				Vec3D EndPos   = pos + (pos - enemyHero->currentPos()).Normalized() * spellData.range;
	////////				//__oMsg("D-StartPos-EndPos: %f - (%.3f, %.3f, %.3f)", Distance(StartPos, EndPos), EndPos.x, EndPos.y, EndPos.z);
	////////				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////				{
	////////					//--------------------------------:
	////////					if (it_onMissileSpells->second.projectileSpeed == 0) continue;
	////////					float missileLifeTime = 555 + spellData.spellDelay + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;

	////////					if ((float)GetTickCount() - timeCreate_qSpots > missileLifeTime)
	////////					{
	////////						//__oMsg("---((*22*))----- SYNDRA.E-CREATE-MISSLE-2222: MissileNam: %s, KC_Missile = %.3f - (%.3f, %.3f, %.3f)",mis_Name.c_str(), StartPos.Distance2D(EndPos), it_xxx->second.x, it_xxx->second.y, it_xxx->second.z);
	////////						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////						timeCreate_qSpots = (float)GetTickCount();
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}	
}