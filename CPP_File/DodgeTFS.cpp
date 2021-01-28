#include "DodgeMalphiteS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
//------ 1 so Spell-ThreeWay cho vao day ---------:

//////DWORD _threeCards[3] = {0};
//////DWORD * p1;
//-------------------------:
KNpc* GetMiddleObject(KNpc* b0, KNpc* b1, KNpc* b2, float range)
{
	//////if (b0 == 0 || b1 == 0 || b2 == 0) return 0;
	//////Vec3D src_0(b0->MissileSrcPos.x, b0->MissileSrcPos.y, b0->MissileSrcPos.z);
	//////Vec3D src_1(b1->MissileSrcPos.x, b1->MissileSrcPos.y, b1->MissileSrcPos.z);
	//////Vec3D src_2(b2->MissileSrcPos.x, b2->MissileSrcPos.y, b2->MissileSrcPos.z);

	//////Vec3D vector_0(b0->MissileDestPos.x, b0->MissileDestPos.y, b0->MissileDestPos.z);
	//////Vec3D vector_1(b1->MissileDestPos.x, b1->MissileDestPos.y, b1->MissileDestPos.z);
	//////Vec3D vector_2(b2->MissileDestPos.x, b2->MissileDestPos.y, b2->MissileDestPos.z);

	//////float KC_01 = Distance( Extend(src_0, vector_0, range), Extend(src_1, vector_1, range) );
	//////float KC_02 = Distance( Extend(src_0, vector_0, range), Extend(src_2, vector_2, range) );
	//////float KC_12 = Distance( Extend(src_1, vector_1, range), Extend(src_2, vector_2, range) );
	//////
	////////__oMsg("KC_01 : %f, KC_02 : %f, KC_12 : %f (%f, %f, %f)", KC_01, KC_02, KC_12, Distance_2D(b0->MissileDestPos, b0->MissileSrcPos), Distance_2D(b1->MissileDestPos, b1->MissileSrcPos), Distance_2D(b2->MissileDestPos, b2->MissileSrcPos));

	//////float soMAX = max(KC_01, KC_02);
	//////soMAX       = max(soMAX, KC_12);

	//////if (soMAX == KC_12) return b0;
	//////if (soMAX == KC_01) return b2;
	//////if (soMAX == KC_02) return b1;

	return 0;
}

////---------------------------------------------------------------------//--------------------//
//void Evade_TwistedFate_Q()
//{
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
//		//if (!CheckName(enemyHero->GetNameHero(), "TwistedFate")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500)	continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("WildCards") != 0) continue;
//			
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				it_onProcessSpells->second.spellDelay = 250;
//
//				SpellData spellData = it_onProcessSpells->second;
//				Vec3D StartPos(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
//				Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//				{
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((*11*))----- TwistedFate.Q-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//
//						float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));
//
//						Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
//						EndPos2.y = StartPos.y;
//						CreateSpellData(enemyHero, StartPos, EndPos2, spellData, 0, 0, false);
//						
//						Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
//						EndPos3.y = StartPos.y;
//						CreateSpellData(enemyHero, StartPos, EndPos3, spellData, 0, 0, false);
//					}
//				}
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			_threeCards[0] = 0;
//			_threeCards[1] = 0;
//			_threeCards[2] = 0;
//			
//			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			DWORD dw1 = *(DWORD*)dw0;
//			if (!dw1) return;
//
//			int countAllObj = *(DWORD*)(dw0 + 4);
//			if (!countAllObj) return;
//			
//			for (int kk = 0; kk < countAllObj; ++kk)
//			{
//				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//				if (dw3 == 0) continue;
//				KNpc *missileObj = (KNpc*)dw3;
//
//				if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//				if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//				if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//				if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//				if (CheckName("SealFateMissile", missileObj->GetNameNpc()))
//				{
//					if (_threeCards[0] == 0)
//					{
//						_threeCards[0] = (DWORD)missileObj;
//					}
//					if (_threeCards[1] == 0)
//					{
//						p1 = std::find (_threeCards, _threeCards + 3, (DWORD)missileObj);
//						if (p1 == _threeCards + 3)
//							_threeCards[1] = (DWORD)missileObj;
//					}
//					if (_threeCards[2] == 0)
//					{
//						p1 = std::find (_threeCards, _threeCards + 3, (DWORD)missileObj);
//						if (p1 == _threeCards + 3)
//						{
//							_threeCards[2] = (DWORD)missileObj;
//							break;
//						}
//					}
//				}
//			}
//			
//			if (_threeCards[0] == 0 || _threeCards[1] == 0 || _threeCards[2] == 0) return;
//
//			std::string mis_Name("WildCards");	// lay ten nay` thi se ko create missile neu da create o pCastSpell roi
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); // lay luon onProcessSpells cho missile
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	// cho delay vao cung dc k sao
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					for (int xx=0; xx < 3; ++xx)
//					{
//						KNpc* card = (KNpc*) _threeCards[xx];
//						Vec3D StartPos(card->MissileSrcPos.x , card->MissileSrcPos.y , card->MissileSrcPos.z);
//						Vec3D EndPos  (card->MissileDestPos.x, card->MissileDestPos.y, card->MissileDestPos.z);
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, card, 0);
//						}
//					}
//
//					//__oMsg("---((*22*))----- TwistedFate.Q-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}	
//			}
//			//KNpc* middleCard = GetMiddleObject( (KNpc*)_threeCards[0], (KNpc*)_threeCards[1], (KNpc*)_threeCards[2], 1450);
//			//if (middleCard)
//			//{
//			//	//std::string mis_Name(missileObj->GetNameNpc());	//"SealFateMissile"
//			//	std::string mis_Name("WildCards");					// lay ten nay` thi se ko create missile neu da create o pCastSpell roi
//			//	
//			//	std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); // lay luon onProcessSpells cho missile
//			//	if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			//	{
//			//		//it_onProcessSpells->second.spellDelay = 250;
//			//		SpellData spellData = it_onProcessSpells->second;
//
//			//		Vec3D StartPos(middleCard->MissileSrcPos.x , middleCard->MissileSrcPos.y , middleCard->MissileSrcPos.z);
//			//		Vec3D EndPos  (middleCard->MissileDestPos.x, middleCard->MissileDestPos.y, middleCard->MissileDestPos.z);
//
//			//		if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//			//		{
//			//			float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	// cho delay vao cung dc k sao
//			//			
//			//			//__oMsg("---((*22-Vao-Choi-Choi*)): delay = %f", spellData.spellDelay);
//			//			if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//			//			{
//			//				//__oMsg("---((*22*))----- TwistedFate.Q-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//			//				it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//			//				CreateSpellData(enemyHero, StartPos, EndPos, spellData, middleCard, 0);
//			//				
//			//				float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));
//
//			//				Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
//			//				EndPos2.y = StartPos.y;
//			//				CreateSpellData(enemyHero, StartPos, EndPos2, spellData, middleCard, 0, false);
//
//			//				Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
//			//				EndPos3.y = StartPos.y;
//			//				CreateSpellData(enemyHero, StartPos, EndPos3, spellData, middleCard, 0, false);
//			//			}
//			//		}
//			//	}
//			//}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//DWORD _threeTias[3] = {0};
//DWORD * p2;
//void Evade_Khazix_WLong()//bao gom ca W-ghe trong FOW
//{
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
//		//if (!CheckName(enemyHero->GetNameHero(), "Khazix")) continue;
//		
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2200)				continue;
//			if (Distance(enemyHero, myHero) < 400)				continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("KhazixWLong") != 0) continue;
//			
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				it_onProcessSpells->second.spellDelay = 250;
//
//				SpellData spellData = it_onProcessSpells->second;
//				Vec3D StartPos(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
//				Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//				{
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((*11*))----- KhazixWLong-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//
//						float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));
//
//						Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
//						EndPos2.y = StartPos.y;
//						CreateSpellData(enemyHero, StartPos, EndPos2, spellData, 0, 0);
//
//						Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
//						EndPos3.y = StartPos.y;
//						CreateSpellData(enemyHero, StartPos, EndPos3, spellData, 0, 0);
//					}
//				}
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			_threeTias[0] = 0;
//			_threeTias[1] = 0;
//			_threeTias[2] = 0;
//
//			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			DWORD dw1 = *(DWORD*)dw0;
//			if (!dw1) return;
//
//			int countAllObj = *(DWORD*)(dw0 + 4);
//			if (!countAllObj) return;
//
//			for (int kk = 0; kk < countAllObj; ++kk)
//			{
//				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//				if (dw3 == 0) continue;
//				KNpc *missileObj = (KNpc*)dw3;
//
//				if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//				if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//				if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//				if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//				if (CheckName("KhazixWMissile", missileObj->GetNameNpc()))
//				{
//					if (_threeTias[0] == 0)
//					{
//						_threeTias[0] = (DWORD)missileObj;
//					}
//					if (_threeTias[1] == 0)
//					{
//						p2 = std::find (_threeTias, _threeTias + 3, (DWORD)missileObj);
//						if (p2 == _threeTias + 3)
//							_threeTias[1] = (DWORD)missileObj;
//					}
//					if (_threeTias[2] == 0)
//					{
//						p2 = std::find (_threeTias, _threeTias + 3, (DWORD)missileObj);
//						if (p2 == _threeTias + 3)
//						{
//							_threeTias[2] = (DWORD)missileObj;
//							break;
//						}
//					}
//				}
//			}
//
//			//if (_threeTias[0] == 0 || _threeTias[1] == 0 || _threeTias[2] == 0) return;
//
//			std::string mis_Name("KhazixWLong");	// lay ten nay` thi se ko create missile neu da create o pCastSpell roi
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); // lay luon onProcessSpells cho missile
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	// cho delay vao cung dc k sao
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					for (int xx=0; xx < 3; ++xx)
//					{
//						if (_threeTias[xx] == 0) continue;
//
//						KNpc* card = (KNpc*) _threeTias[xx];
//						Vec3D StartPos(card->MissileSrcPos.x , card->MissileSrcPos.y , card->MissileSrcPos.z);
//						Vec3D EndPos  (card->MissileDestPos.x, card->MissileDestPos.y, card->MissileDestPos.z);
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, card, 0);
//						}
//					}
//					
//					if (_threeTias[0] == 0 && _threeTias[1] == 0 && _threeTias[2] == 0) return;
//
//					//__oMsg("---((*22*))----- KhazixWLong_CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str());
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}	
//			}
//		}
//	}
//}


////---------------------------------------------------------------------//--------------------//
//DWORD _threeBlade[3] = {0};
//DWORD * p3;
//void Evade_Riven_R()
//{
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
//		//if (!CheckName(enemyHero->GetNameHero(), "Riven")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500)	continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("RivenIzunaBlade") != 0) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				it_onProcessSpells->second.spellDelay = 250;
//
//				SpellData spellData = it_onProcessSpells->second;
//				Vec3D StartPos(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
//				Vec3D EndPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//				{
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((*11*))----- Riven.R-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//
//						float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));
//
//						Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
//						EndPos2.y = StartPos.y;
//						CreateSpellData(enemyHero, StartPos, EndPos2, spellData, 0, 0, false);
//
//						Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
//						EndPos3.y = StartPos.y;
//						CreateSpellData(enemyHero, StartPos, EndPos3, spellData, 0, 0, false);
//					}
//				}
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			_threeBlade[0] = 0;
//			_threeBlade[1] = 0;
//			_threeBlade[2] = 0;
//
//			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			DWORD dw1 = *(DWORD*)dw0;
//			if (!dw1) return;
//
//			int countAllObj = *(DWORD*)(dw0 + 4);
//			if (!countAllObj) return;
//
//			for (int kk = 0; kk < countAllObj; ++kk)
//			{
//				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//				if (dw3 == 0) continue;
//				KNpc *missileObj = (KNpc*)dw3;
//
//				if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//				if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//				if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//				if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//				if (CheckName("RivenWindslashMissile", missileObj->GetNameNpc()))	//RivenWindslashMissileCenter, RivenWindslashMissileLeft, RivenWindslashMissileRight
//				{
//					if (_threeBlade[0] == 0)
//					{
//						_threeBlade[0] = (DWORD)missileObj;
//						continue;
//					}
//					if (_threeBlade[1] == 0)
//					{
//						p3 = std::find (_threeBlade, _threeBlade + 3, (DWORD)missileObj);
//						if (p3 == _threeBlade + 3)
//						{
//							_threeBlade[1] = (DWORD)missileObj;
//							continue;
//						}
//					}
//					if (_threeBlade[2] == 0)
//					{
//						p3 = std::find (_threeBlade, _threeBlade + 3, (DWORD)missileObj);
//						if (p3 == _threeBlade + 3)
//						{
//							_threeBlade[2] = (DWORD)missileObj;
//							continue;
//						}
//					}
//					if (_threeBlade[0] != 0 && _threeBlade[1] != 0 && _threeBlade[2] != 0) break;
//				}
//			}
//			
//			if (_threeBlade[0] == 0 || _threeBlade[1] == 0 || _threeBlade[2] == 0) return;
//
//			std::string mis_Name("RivenIzunaBlade");	// lay ten nay` thi se ko create missile neu da create o pCastSpell roi
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); // lay luon onProcessSpells cho missile
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	// cho delay vao cung dc k sao
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					for (int xx=0; xx < 3; ++xx)
//					{
//						KNpc* _blade = (KNpc*) _threeBlade[xx];
//						Vec3D StartPos(_blade->MissileSrcPos.x , _blade->MissileSrcPos.y , _blade->MissileSrcPos.z);
//						Vec3D EndPos  (_blade->MissileDestPos.x, _blade->MissileDestPos.y, _blade->MissileDestPos.z);
//
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, _blade, 0);
//							//__oMsg("---((*22*))----- Riven_R_FOW_CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}	
//			}
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
void Evade_TwistedFate_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)	//Tam-Thoi-Lam-OPS-Thoi
{
	//////if (spellData.spellName.compare("WildCards") != 0) return;

	//////KNpc* myHero = GetPlayer();
	//////if (!myHero) return;

	//////if (Distance(hero, myHero) > 2500) return;

	//////Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	//////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	//////if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	//////{

	//////	//__oMsg("---((*11*))----- TFF_Q-CREATE_OPS-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	//////	CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);

	//////	float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));

	//////	Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
	//////	EndPos2.y = StartPos.y;
	//////	CreateSpellData(hero, StartPos, EndPos2, spellData, 0, 0);

	//////	Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
	//////	EndPos3.y = StartPos.y;
	//////	CreateSpellData(hero, StartPos, EndPos3, spellData, 0, 0);

	//////	//for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	//////	//{
	//////	//	it_2->second.KoUpCurrentPos = true;
	//////	//}
	//////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Riven_R_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)	//Tam-Thoi-Lam-OPS-Thoi
{
	////////if (spellData.spellName.compare("RivenIzunaBlade") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (Distance(hero, myHero) > 2200) return;

	////////Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////{

	////////	//__oMsg("---((*11*))----- Riven_R-CREATE_OPS-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////	CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);

	////////	float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));

	////////	Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
	////////	EndPos2.y = StartPos.y;
	////////	CreateSpellData(hero, StartPos, EndPos2, spellData, 0, 0);

	////////	Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
	////////	EndPos3.y = StartPos.y;
	////////	CreateSpellData(hero, StartPos, EndPos3, spellData, 0, 0);

	////////	//for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	//{
	////////	//	it_2->second.KoUpCurrentPos = true;
	////////	//}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Khazix_WLong_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)	//Tam-Thoi-Lam-OPS-Thoi
{
	////////if (spellData.spellName.compare("KhazixWLong") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (Distance(hero, myHero) > 2500) return;

	////////Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////{
	////////	
	////////	//__oMsg("---((*11*))----- KhazixWLong-CREATE_OPS-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////	CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);

	////////	float angle = spellData.angle * ((float)(3.14159265358979323846f / 180));

	////////	Vec3D EndPos2 = RotateAroundPoint(EndPos, StartPos, angle);
	////////	EndPos2.y = StartPos.y;
	////////	CreateSpellData(hero, StartPos, EndPos2, spellData, 0, 0);

	////////	Vec3D EndPos3 = RotateAroundPoint(EndPos, StartPos, -angle);
	////////	EndPos3.y = StartPos.y;
	////////	CreateSpellData(hero, StartPos, EndPos3, spellData, 0, 0);

	////////	//for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	//{
	////////	//	it_2->second.KoUpCurrentPos = true;
	////////	//}
	////////}
}

//---------------------------------------------------------------------//--------------------//
//FOW van lam dc, dung` : (Type: 1)[TeamID: 0](TahmKench_Base_W_Cas) :400018f6, [Time: 1282.833] - [currentPos: 9619.38,71.82,5600.59] - [serPos: 9619.38,71.82,5600.59]
void Evade_TahmKench_W()	
{
	////KNpc* myHero = GetPlayer();
	////if (!myHero) return;
	////if (G_Module == 0) return;

	////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////DWORD dwHero1 = *(DWORD*)tempHero;
	////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////if (!dwHero1 || !dwHero2 ) return;

	////int countHero = (dwHero2 - dwHero1)/4;
	////for (int i = 0; i < countHero; ++i)
	////{
	////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////	if (dwHero3 == 0) continue;
	////	KNpc *enemyHero = (KNpc*)dwHero3;
	////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
	////	if (Distance(enemyHero, myHero) > 1800)				continue;
	////	if (!CheckName(enemyHero->GetNameHero(), "TahmKench")) continue;
	////	

	////	//------//------//------:
	////	KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////	if (!args) continue;

	////	KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////	if(!pK_str2) continue;

	////	std::string spell_name(pK_str2->GetSkillName());
	////	if (spell_name.compare("TahmKenchWCastTimeAndAnimation") != 0) continue;
	////	
	////	if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
	////	if (GetTimeGame() - args->nTime_BatDauBAN < 0.025f) continue;

	////	KNpc* minionDevoured = 0;
	////	//------//------//------:
	////	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////	DWORD dwUnit1 = *(DWORD*)tempUnit;
	////	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////	if (!dwUnit1 || !dwUnit2 ) return;
	////	int countUnit = (dwUnit2 - dwUnit1)/4;
	////	for (int iii = 0; iii < countUnit; ++iii)
	////	{
	////		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////		if (dwUnit3 == 0) continue;
	////		KNpc *minion = (KNpc*)dwUnit3;
	////		if (IS_DEAD(minion))    continue;
	////		if (!IS_MINION(minion)) continue;
	////		if ((BYTE)minion->nIsTargetableToTeam == 4) continue;
	////		if (Distance(minion, enemyHero) > 175)	continue;

	////		if (minion->nTeam_ID != 0x12C)
	////		{
	////			if (minion->nTeam_ID != myHero->nTeam_ID)  continue;
	////			else
	////			{
	////				if (CheckName(sz__Minion, minion->GetNameNpc()) && GET_BUFF(minion, "tahmkenchwdevoured"))
	////				{
	////					minionDevoured = minion;
	////					break;
	////				}
	////			}
	////		}
	////		else
	////		{
	////			if (!CheckName(sz__SRU_, minion->GetNameNpc())) 
	////			{
	////				if(!CheckName(sz__Sru_, minion->GetNameNpc()))
	////				{
	////					if(!CheckName(sz__MiniKrug, minion->GetNameNpc()))
	////					{
	////						if(!CheckName("TT_N", minion->GetNameNpc()))					//TT_NWolf23.1.2 - TT_NWraith21.1.2 - TT_NGolem22.1.2
	////						{
	////							if(!CheckName("TT_S", minion->GetNameNpc())) continue;		//TT_Spiderboss8.1.1
	////						}
	////					}
	////				}
	////			}

	////			if (GET_BUFF(minion, "tahmkenchwdevoured"))
	////			{
	////				minionDevoured = minion;
	////				break;
	////			}
	////		}	
	////	}
	////	
	////	//------//------//------:
	////	if (minionDevoured != 0 && IsUnitInList(minionDevoured) && !IS_DEAD(minionDevoured))
	////	{
	////		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name)); 
	////		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////		{
	////			//__oMsg("-------- TahmKench_W_PREPARE---");
	////			SpellData spellData = it_onProcessSpells->second;
	////			Vec3D StartPos		= enemyHero->currentPos();
	////			Vec3D EndPos		= GET_REAL_FACING_POS(enemyHero);
	////			if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////			{
	////				float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////				{
	////					//__oMsg("---((*11*))----- TahmKench_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
	////				}
	////			}
	////		}
	////	}
	////}
}
