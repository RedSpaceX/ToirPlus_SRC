#include "DodgeIreliaS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
////---------------------------------------------------------------------//--------------------//
//struct IreliaBlade
//{
//	KNpc*	blade;
//	float	createTime;
//	Vec3D	lastDestPos;
//	Vec3D	lastSrcPos;
//	
//	IreliaBlade()
//	{
//		blade = 0;
//		createTime = 0;
//		lastSrcPos.x  = lastSrcPos.y  = lastSrcPos.z  = 0;
//		lastDestPos.x = lastDestPos.y = lastDestPos.z = 0;
//	}
//};
//IreliaBlade _iBlade[2];
//
////--------------------//--------------------:
//void Evade_Irelia_E()
//{
//	//------ RESET-BLADE ----------:
//	if (_iBlade[0].createTime != 0 && (float)GetTickCount() - _iBlade[0].createTime > 3900)
//	{
//		_iBlade[0].blade		 = 0;
//		_iBlade[0].createTime	 = 0;
//		_iBlade[0].lastSrcPos.x  = _iBlade[0].lastSrcPos.y  = _iBlade[0].lastSrcPos.z  = 0;
//		_iBlade[0].lastDestPos.x = _iBlade[0].lastDestPos.y = _iBlade[0].lastDestPos.z = 0;
//	}
//
//	if (_iBlade[1].createTime != 0 && (float)GetTickCount() - _iBlade[1].createTime > 3900)
//	{
//		_iBlade[1].blade		 = 0;
//		_iBlade[1].createTime	 = 0;
//		_iBlade[1].lastSrcPos.x  = _iBlade[1].lastSrcPos.y  = _iBlade[1].lastSrcPos.z  = 0;
//		_iBlade[1].lastDestPos.x = _iBlade[1].lastDestPos.y = _iBlade[1].lastDestPos.z = 0;
//	}
//	//-------------------------------//-----------------------//--
//
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwHero1 = *(DWORD*)tempHero;
//	DWORD dwHero2 = *(DWORD*)tempHeroMax;
//	if (!dwHero1 || !dwHero2 ) return;
//
//	int countHero = (dwHero2 - dwHero1)/4;
//	for (int i = 0; i < countHero; ++i)
//	{
//		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
//		if (dwHero3 == 0) continue;
//		KNpc *enemyHero = (KNpc*)dwHero3;
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Irelia")) continue;
//		//if (Distance(enemyHero, myHero) > 2500) continue;
//
//		//------//------//------:
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)     continue;
//			if (OBJECT_TYPE(missileObj) != 0x8001)	 continue;
//			
//			std::string misName(missileObj->GetNameNpc());
//			if (misName.compare("IreliaEMissile") == 0)
//			{
//				//------ add _iBlade[0] ----:
//				if (_iBlade[0].blade == 0 && (float)GetTickCount() - _iBlade[0].createTime > 4000)
//				{
//					_iBlade[0].blade	  = missileObj;
//					_iBlade[0].createTime = (float)GetTickCount();
//
//					_iBlade[0].lastSrcPos.x  = missileObj->MissileSrcPos.x;
//					_iBlade[0].lastSrcPos.y  = missileObj->MissileSrcPos.y;
//					_iBlade[0].lastSrcPos.z  = missileObj->MissileSrcPos.z;
//
//					_iBlade[0].lastDestPos.x  = missileObj->MissileDestPos.x;
//					_iBlade[0].lastDestPos.y  = missileObj->MissileDestPos.y;
//					_iBlade[0].lastDestPos.z  = missileObj->MissileDestPos.z;
//
//					//__oMsg(" ADDD-BLADE-00-00: %f - %x", Distance_2D(missileObj->MissileSrcPos, missileObj->MissileDestPos), missileObj->nMissileData);
//					break;
//				}
//				//------ add _iBlade[1] ----:
//				if (_iBlade[1].blade == 0 && (float)GetTickCount() - _iBlade[1].createTime > 4000)
//				{
//					if (_iBlade[0].blade != 0 && _iBlade[0].blade != missileObj && _iBlade[0].lastDestPos.x != missileObj->MissileDestPos.x && _iBlade[0].lastDestPos.z != missileObj->MissileDestPos.z)
//					{
//						_iBlade[1].blade	  = missileObj;
//						_iBlade[1].createTime = (float)GetTickCount();
//
//						_iBlade[1].lastSrcPos.x  = missileObj->MissileSrcPos.x;
//						_iBlade[1].lastSrcPos.y  = missileObj->MissileSrcPos.y;
//						_iBlade[1].lastSrcPos.z  = missileObj->MissileSrcPos.z;
//
//						_iBlade[1].lastDestPos.x  = missileObj->MissileDestPos.x;
//						_iBlade[1].lastDestPos.y  = missileObj->MissileDestPos.y;
//						_iBlade[1].lastDestPos.z  = missileObj->MissileDestPos.z;
//						//__oMsg(" ADDD-BLADE-11-11");
//						break;
//					}
//				}
//			}
//
//			if (_iBlade[0].blade != 0 && _iBlade[1].blade != 0)
//			{				
//				//__oMsg("--IreliaE_11-TimeGame:  %f", GetTimeGame());
//				std::string mis_Name("IreliaE_Special");
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					it_onMissileSpells->second.range      = _iBlade[0].lastDestPos.Distance2D(_iBlade[1].lastDestPos) + 15;
//					it_onMissileSpells->second.spellDelay = 250 + 1000 * _iBlade[1].lastDestPos.Distance2D(_iBlade[1].lastSrcPos)/2200 + 20;
//					SpellData spellData = it_onMissileSpells->second;
//
//					Vec3D StartPos = _iBlade[0].lastDestPos;
//					Vec3D EndPos   = _iBlade[1].lastDestPos;
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 || EndPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						float missileLifeTime = 4200;	//spellData.projectileSpeed > 0 ? 666 +  spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((***))----- Irelia_E_11__CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f, %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//							
//							if (Distance(myHero->currentPos(), StartPos) > Distance(myHero->currentPos(), EndPos))
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							else
//								CreateSpellData(enemyHero, EndPos, StartPos, spellData, 0, 0);
//
//							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//			else if (_iBlade[0].blade != 0)
//			{
//				if (misName.compare("IreliaEParticleMissile") == 0)
//				{
//					std::string mis_Name("IreliaE_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						it_onMissileSpells->second.range      = _iBlade[0].lastDestPos.Distance2D(enemyHero->currentPos()) + 15;
//						it_onMissileSpells->second.spellDelay = 250;
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = _iBlade[0].lastDestPos;
//						Vec3D EndPos   = enemyHero->currentPos();
//
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 || EndPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							float missileLifeTime = 4500;	//spellData.projectileSpeed > 0 ? 666 +  spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//							if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Irelia_E_22__CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f, %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//								if (Distance(myHero->currentPos(), StartPos) > Distance(myHero->currentPos(), EndPos))
//									CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								else
//									CreateSpellData(enemyHero, EndPos, StartPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//			if (misName.compare("IreliaEParticleMissile") == 0)
//			{
//				_iBlade[0].blade		 = 0;
//				_iBlade[0].createTime	 = 0;
//				_iBlade[0].lastSrcPos.x  = _iBlade[0].lastSrcPos.y  = _iBlade[0].lastSrcPos.z  = 0;
//				_iBlade[0].lastDestPos.x = _iBlade[0].lastDestPos.y = _iBlade[0].lastDestPos.z = 0;
//
//				_iBlade[1].blade		 = 0;
//				_iBlade[1].createTime	 = 0;
//				_iBlade[1].lastSrcPos.x  = _iBlade[1].lastSrcPos.y  = _iBlade[1].lastSrcPos.z  = 0;
//				_iBlade[1].lastDestPos.x = _iBlade[1].lastDestPos.y = _iBlade[1].lastDestPos.z = 0;
//			}
//		}
//	}	
//}


//////////--------------------//--------------------:
////////Vec3D destPos_E1(0,0,0);
void Evade_Irelia_E_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////KSkill_2*  pK_str2 = (KSkill_2*) spellCast->__pK_str2;
	////////if (!pK_str2) return;

	////////if (!CheckName("IreliaE", pK_str2->GetSkillName())) return;		//"IreliaE" va "IreliaE2"
	////////
	////////if (CheckName(pK_str2->GetSkillName(), "IreliaE"))
	////////{
	////////	Vec3D destE1(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////	destPos_E1 = destE1;
	////////	return;
	////////}
	////////
	////////if (destPos_E1.IsValid() && CheckName("IreliaE2", pK_str2->GetSkillName()))
	////////{
	////////	KNpc* myHero = GetPlayer();
	////////	if (!myHero) return;

	////////	if (Distance(hero, myHero) > 3000) return;

	////////	Vec3D Start_E2(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////	Vec3D Dest_E2 (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	////////	if (destPos_E1.Distance2D(myHero->currentPos()) < spellData.range + 1500 || Dest_E2.Distance2D(myHero->currentPos()) < spellData.range + 1500)
	////////	{
	////////		spellData.spellDelay = 250 + 1000 * Start_E2.Distance2D(Dest_E2)/2200 + 20;
	////////		spellData.range      = Distance(Dest_E2, destPos_E1) + 25;

	////////		//__oMsg("---((***))----- Irelia_E_12__CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f, %f", spellData.spellName.c_str(), Dest_E2.Distance2D(destPos_E1), spellData.spellDelay);

	////////		if (Distance(myHero->currentPos(), destPos_E1) > Distance(myHero->currentPos(), Dest_E2))
	////////			CreateSpellData(hero, destPos_E1, Dest_E2, spellData, 0, 0);
	////////		else
	////////			CreateSpellData(hero, Dest_E2, destPos_E1, spellData, 0, 0);
	////////		
	////////		Vec3D zero(0,0,0);
	////////		destPos_E1 = zero;
	////////	}
	////////}
}