#include "DodSpecial_4.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"




extern SpellDetector* _SpellDetector;
extern bool			  DodgeFOWSpells_menu;

extern DWORD		  G_Module;
extern int			  myTeamId;
extern KNpc*		  MY_HERO;
extern bool			  canUse_VMT;


//---------------------------------------------------------------------//--------------------//
std::map<DWORD, Vec3D> *Lux_R_MisBeam = 0;	
void DodS_FOWFOW_Lux_R()					// FOW 
{
	if ( !DodgeFOWSpells_menu ) return;		// FOW.FOW

	if (Lux_R_MisBeam == 0) Lux_R_MisBeam = new std::map<DWORD, Vec3D>;

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwHero1 = *(DWORD*)tempHero;
	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	if (!dwHero1 || !dwHero2 ) return;

	int countHero = (dwHero2 - dwHero1)/4;
	for (int i = 0; i < countHero; ++i)
	{
		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
		if (dwHero3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dwHero3;

		if (enemyHero->nTeam_ID == myTeamId)			 continue;
		if (IS_DEAD(enemyHero))							 continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	 continue;
		if (IsCanSee(enemyHero))						 continue;		//FOW.FOW
		if (!CheckName(enemyHero->GetNameHero(), "Lux")) continue;
		
		//------//------//------:
		std::map<DWORD, Vec3D>::iterator it_xxx = Lux_R_MisBeam->find(enemyHero->nIndex);
		if (it_xxx != Lux_R_MisBeam->end())
		{
			int sttHiu = 0;

			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dwUnit1 = *(DWORD*)tempUnit;
			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
			if (!dwUnit1 || !dwUnit2 ) return;
			int countUnit = (dwUnit2 - dwUnit1)/4;
			for (int iii = 0; iii < countUnit; ++iii)
			{
				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
				if (dwUnit3 == 0) continue;
				KNpc *eHiu = (KNpc*)dwUnit3;
				
				if (!IS_MINION(eHiu))							continue;
				if (IS_DEAD(eHiu))								continue;
				if (eHiu->nTeam_ID == 0x12C)					continue;
				if (eHiu->nTeam_ID == myTeamId )				continue;
				if ((BYTE)eHiu->nIsTargetableToTeam == 4 )		continue;
				if (Distance(MY_HERO, eHiu) > 4500)				continue;

				if (!CheckName(eHiu->GetNameNpc(), "hiu"))		continue;
				char szTemp[] = {84,101,115,116,67,117,98,101,82,101,110,100,101,114,0};	// "TestCubeRender"
				if (!CheckNameEx(eHiu->GetNameHero(), szTemp))	continue;

				sttHiu += 1;		
				if (sttHiu <= 1) continue;	//0 la diem gan nhat, 1 la diem xa nhat (lay diem 0 se tao. 2lan createSpell) (luc nguoc, luc xuoi, chua dc chuan lam)

				if (fabs(it_xxx->second.x - eHiu->currentPos().x) > FLT_EPSILON)
				{
					////__oMsg("%f - %f", it_xxx->second.x, eHiu->currentPos().x);
					it_xxx->second = eHiu->currentPos();

					DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
					DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
					if (!dw0) return;

					DWORD dw1 = *(DWORD*)(dw0 + 8);
					if (!dw1) return;

					int countAllObj = *(DWORD*)(dw0 + 0xC);
					if (!countAllObj) return;

					for (int kk = 0; kk < countAllObj; ++kk)
					{
						DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
						if (dw3 == 0) continue;
						KNpc *object = (KNpc*)dw3;

						if (OBJECT_TYPE(object) != 1)			continue;
						if ((object->nIndex & 0x3fff) <= 0 || 
							(object->nIndex & 0x3fff) > 0xFF00) continue;

						if (IS_OBJ_DELETED(object) == true)		continue;		

						char szTemp[] = {82,95,109,105,115,95,98,101,97,109,95,109,105,100,100,108,101,0};			// "R_mis_beam_middle"
						if (CheckName(szTemp, object->GetNameNpc()) && CheckName("Lux", object->GetNameNpc()))		// ""
						{
							char szTemp[] = {76,117,120,82,95,83,115,0};		// "LuxR_Ss"
							std::string MISS_NAME(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(MISS_NAME)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D dir = (eHiu->currentPos() - object->currentPos()).Normalized();
								Vec3D StartPos = object->currentPos() + dir * 1750;
								Vec3D EndPos   = object->currentPos() - dir * 1750;

								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									//__oMsg("---((***))----- FOW.FOW_LUX_R_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(MY_HERO->currentPos()), Distance(object->currentPos(), eHiu->currentPos()));
									CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									break;
								}
							}
						}
					}
				}
			
				break;
			}
		}
		else
		{
			Lux_R_MisBeam->insert(std::pair<DWORD, Vec3D> (enemyHero->nIndex, MY_HERO->currentPos()));	//lay tam toa do minh vao
		}		
	}	
}

//---------------------------------------------------------------------//--------------------//
std::map<DWORD, Vec3D> *Xerath_Q_HiuMax = 0;	
void DodS_FOWFOW__AND__NOFOW_Xerath_Q()			// FOW + NO_FOW	( co the loi neu team enemy co ca Xerath + Jayce )
{
	if (Xerath_Q_HiuMax == 0) Xerath_Q_HiuMax = new std::map<DWORD, Vec3D>;

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwHero1 = *(DWORD*)tempHero;
	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	if (!dwHero1 || !dwHero2 ) return;

	int countHero = (dwHero2 - dwHero1)/4;
	for (int i = 0; i < countHero; ++i)
	{
		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
		if (dwHero3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dwHero3;

		if (enemyHero->nTeam_ID == myTeamId)				continue;
		if (IS_DEAD(enemyHero))								continue;
		//if ((BYTE)enemyHero->nIsTargetableToTeam != 4)		continue;
		//if (!IsCanSee(enemyHero))							continue;			//FOW nhung ban' 1 cai no hien xerath roi
		if (Distance(enemyHero, MY_HERO) > 2200)			continue;
		if (!CheckName(enemyHero->GetNameHero(), "Xerath")) continue;

		//------//------//------:
		std::map<DWORD, Vec3D>::iterator it_xxx = Xerath_Q_HiuMax->find(enemyHero->nIndex);
		if (it_xxx != Xerath_Q_HiuMax->end())
		{
			Vec3D posHiu_XaNhat(0,0,0);
			float max_KC        = 0;

			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dwUnit1 = *(DWORD*)tempUnit;
			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
			if (!dwUnit1 || !dwUnit2 ) return;
			int countUnit = (dwUnit2 - dwUnit1)/4;
			for (int iii = 0; iii < countUnit; ++iii)
			{
				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
				if (dwUnit3 == 0) continue;
				KNpc *eHiu = (KNpc*)dwUnit3;

				if (!IS_MINION(eHiu))							continue;
				if ((BYTE)eHiu->nIsTargetableToTeam != 3)		continue;		//xerath 4 truoc, 3 sau (cham hon 40-50ms), lay =3 vi jayce lay = 2 va lay=4 se~ qua ne, qua ko
				if (IS_DEAD(eHiu))								continue;
				if (eHiu->nTeam_ID == 0x12C)					continue;
				if (eHiu->nTeam_ID == myTeamId)					continue;
				if (Distance(MY_HERO, eHiu) > 2200)				continue;

				if (!CheckNameEx(eHiu->GetNameNpc(), "hiu"))		continue;
				char szTemp[] = {84,101,115,116,67,117,98,101,82,101,110,100,101,114,49,48,86,105,115,105,111,110,0};	// "TestCubeRender10Vision"
				if (!CheckNameEx(eHiu->GetNameHero(), szTemp))	continue;

				float distant = Distance(eHiu, enemyHero);
				if (distant > max_KC)
				{
					max_KC = distant;
					posHiu_XaNhat = eHiu->currentPos();
					//__oMsg("[%x - %x]%d, %.2f (%.3f)", eHiu, eHiu->nIndex, (BYTE)eHiu->nIsTargetableToTeam, eHiu->nHP, GetTimeGame());
				}
			}

			if (posHiu_XaNhat.IsValid())
			{
				if (fabs(it_xxx->second.x - posHiu_XaNhat.x) > FLT_EPSILON)
				{
					it_xxx->second = posHiu_XaNhat;

					char szTemp[] = {88,101,114,97,116,104,81,95,83,115,0};		// "XerathQ_Ss"
					std::string MISS_NAME(szTemp);

					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(MISS_NAME)); 
					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
					{
						SpellData spellData = it_onMissileSpells->second;

						Vec3D StartPos = enemyHero->currentPos();
						Vec3D EndPos   = posHiu_XaNhat;

						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1500)
						{
							//__oMsg("---((***))----- DodS_FOWFOW__AND__NOFOW_Xerath_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",MISS_NAME.c_str(), StartPos.Distance2D(MY_HERO->currentPos()), Distance(StartPos, EndPos));
							spellData.range = 115.0f + Distance(StartPos, EndPos);
							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
						}
					}		
				}
			}
		}
		else
		{
			Xerath_Q_HiuMax->insert(std::pair<DWORD, Vec3D> (enemyHero->nIndex, enemyHero->currentPos()));	
		}
	}	
}


//---------------------------------------------------------------------//--------------------//
std::map<DWORD, Vec3D> *Sion_Q_StartPos = 0;
std::map<DWORD, Vec3D> *Sion_R_StartPos = 0;

void DodS_NOFOW_Sion_R_and_Q()
{
	if (!Sion_Q_StartPos) Sion_Q_StartPos = new std::map<DWORD, Vec3D>;
	if (!Sion_R_StartPos) Sion_R_StartPos = new std::map<DWORD, Vec3D>;

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwHero1 = *(DWORD*)tempHero;
	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	if (!dwHero1 || !dwHero2 ) return;

	int countHero = (dwHero2 - dwHero1)/4;
	for (int i = 0; i < countHero; ++i)
	{
		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
		if (dwHero3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dwHero3;

		if (enemyHero->nTeam_ID == myTeamId)				continue;
		if (IS_DEAD(enemyHero))								continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)		continue;
		if (!IsCanSee(enemyHero))							continue;			
		if (Distance(enemyHero, MY_HERO) > 1500)			continue;
		if (!CheckName(enemyHero->GetNameHero(), "Sion"))	continue;

		KCastSpell* spellCast = (KCastSpell*)enemyHero->_pCastSpell;
		if (!spellCast) continue;

		KSkill_2*  pK_str2 = (KSkill_2*) spellCast->__pK_str2;
		if(!pK_str2) continue;

		std::string SPELL_NAME(pK_str2->GetSkillName());

		//---Q---//------//------:
		if (SPELL_NAME.compare("SionQ") == 0)
		{
			std::map<DWORD, Vec3D>::iterator it_xxx = Sion_Q_StartPos->find(enemyHero->nIndex);
			if (it_xxx != Sion_Q_StartPos->end())
			{
				KBuffs* buffQ = GET_BUFF(enemyHero, "SionQ");
				if (buffQ)
				{
					float startTime = buffQ->nBegin_Time;
					if (GetTimeGame() - startTime > 0.4f)
					{
						if (fabs(it_xxx->second.x - spellCast->SourcePos.x) > FLT_EPSILON)
						{
							it_xxx->second.x = spellCast->SourcePos.x;
							it_xxx->second.y = spellCast->SourcePos.y;
							it_xxx->second.z = spellCast->SourcePos.z;

							char szTemp[] = {83,105,111,110,81,95,83,115,0};		// "SionQ_Ss"
							std::string MISS_NAME(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(MISS_NAME)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
								Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

								if (StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									spellData.extraEndTime = 400;

									//__oMsg("---((***))----- DodS_FOWFOW_Sion_Q-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f, delay: %f",MISS_NAME.c_str(), StartPos.Distance2D(MY_HERO->currentPos()), Distance(StartPos, EndPos),spellData.spellDelay);
									CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
								}
							}
						}
					}
				}
			}
			else
			{
				Sion_Q_StartPos->insert(std::pair<DWORD, Vec3D> (enemyHero->nIndex, MY_HERO->currentPos()));
			}
		}


		//---R---//------//------:
		char szSionR[] = {83,105,111,110,82,0};		// "SionR"
		if (SPELL_NAME.compare(szSionR) == 0)
		{
			std::map<DWORD, Vec3D>::iterator it_rrr = Sion_R_StartPos->find(enemyHero->nIndex);
			if (it_rrr != Sion_R_StartPos->end())
			{
				Vec3D startPos  = enemyHero->currentPos();
				if (startPos.Distance2D(MY_HERO->currentPos()) < 1200)
				{
					if (fabs(it_rrr->second.x - spellCast->SourcePos.x) > FLT_EPSILON)
					{
						it_rrr->second.x = spellCast->SourcePos.x;
						it_rrr->second.y = spellCast->SourcePos.y;
						it_rrr->second.z = spellCast->SourcePos.z;

						char szTemp[] = {83,105,111,110,82,95,83,115,0};		// "SionR_Ss"
						std::string MISS_NAME(szTemp);

						std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(MISS_NAME)); 
						if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
						{
							SpellData spellData = it_onMissileSpells->second;

							Vec3D facingPos = GET_REAL_FACING_POS(enemyHero);
							Vec3D endPos    = enemyHero->currentPos() + (facingPos - enemyHero->currentPos()).Normalized() * 1600;
							spellData.range = 1600;
							spellData.projectileSpeed = 400.0f + enemyHero->nMoveSpeed;

							//__oMsg("---((***))----- DodS_FOWFOW_Sion_R-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f, delay: %f",MISS_NAME.c_str(), startPos.Distance2D(MY_HERO->currentPos()), Distance(startPos, endPos),spellData.spellDelay);
							CreateSpellData(enemyHero, startPos, endPos, spellData, 0, 0);
						}
					}
				}
			}
			else
			{
				Sion_R_StartPos->insert(std::pair<DWORD, Vec3D> (enemyHero->nIndex, MY_HERO->currentPos()));
			}
		}
	}
}

