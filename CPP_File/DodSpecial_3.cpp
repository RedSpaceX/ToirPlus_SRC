#include "DodSpecial_3.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"




extern SpellDetector* _SpellDetector;
extern bool			  DodgeFOWSpells_menu;

extern DWORD		  G_Module;
extern int			  myTeamId;
extern KNpc*		  MY_HERO;
extern bool			  canUse_VMT;


//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Fiora_W_Buff = 0;
void DodS_Fiora_W()
{
	if (!DodgeFOWSpells_menu) return;		// con nay lam ne' NO.FOW thoi

	//if (canUse_VMT)			  return;		//no for CNN
	
	if (!Fiora_W_Buff) Fiora_W_Buff = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)			   continue;
		if (IS_DEAD(enemyHero))							   continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	   continue;
		if (Distance(enemyHero, MY_HERO) > 1500)		   continue;
		if (IsCanSee(enemyHero) == false)				   continue;		// con nay lam ne' NO.FOW thoi
		if (!CheckName(enemyHero->GetNameHero(), "Fiora")) continue;
		
		std::map<DWORD, float>::iterator it_xxx = Fiora_W_Buff->find(enemyHero->nIndex);
		if (it_xxx != Fiora_W_Buff->end())
		{
			char szTemB[] = {70,105,111,114,97,87,0};		// "FioraW"
			KBuffs* buffW = GET_BUFF(enemyHero, szTemB);
			if (buffW)
			{
				if (fabs(it_xxx->second - buffW->nBegin_Time) > FLT_EPSILON )
				{
					it_xxx->second = buffW->nBegin_Time;

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

						if (CheckName("_W_Cas", object->GetNameNpc()) && CheckName("Fiora", object->GetNameNpc()))		// "Fiora_Base_W_Cas"
						{
							char szTemp[] = {70,105,111,114,97,87,95,83,115,0};		// "FioraW_Ss"
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = enemyHero->currentPos();
								Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);

								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									//__oMsg("---((***))----- Fiora_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
									CreateSpellData(enemyHero, StartPos, EndPos, spellData);
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Fiora_W_Buff->insert(std::pair<DWORD, float> (enemyHero->nIndex, GetTimeGame()));
		}
	}
}

//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Leblanc_WWR_Dash = 0;
void DodS_Leblanc_W_WR()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Leblanc_WWR_Dash) Leblanc_WWR_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)				 continue;
		if (IS_DEAD(enemyHero))								 continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)		 continue;
		if (Distance(enemyHero, MY_HERO) > 1500)			 continue;
		if (!CheckName(enemyHero->GetNameHero(), "Leblanc")) continue;

		std::map<DWORD, float>::iterator it_xxx = Leblanc_WWR_Dash->find(enemyHero->nIndex);

		if (it_xxx != Leblanc_WWR_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

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

						if (CheckName("_W_cas",object->GetNameNpc()) && CheckName("LeBlanc",object->GetNameNpc()))	//"LeBlanc_Skin04_W_cas" "LeBlanc_Base_W_mis"
						{
							char szTemp[] = {76,101,98,108,97,110,99,87,95,83,115,0};		// "LeblancW_Ss"
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = GET_START_POS(enemyHero);
								Vec3D EndPos   = GET_END_POS(enemyHero);

								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									if (object->currentPos().IsValid() && Distance(object->currentPos(), StartPos) < 100)	//cho~ nay hay thay doi giua EndPos hoac StartPos
									{
										//__oMsg("---((***))----- LeBlanc_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
										CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Leblanc_WWR_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}


//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Rakan_W_Dash = 0;
void DodS_Rakan_W()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Rakan_W_Dash) Rakan_W_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)			   continue;
		if (IS_DEAD(enemyHero))							   continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	   continue;
		if (Distance(enemyHero, MY_HERO) > 1500)		   continue;
		if (!CheckName(enemyHero->GetNameHero(), "Rakan")) continue;
		

		std::map<DWORD, float>::iterator it_xxx = Rakan_W_Dash->find(enemyHero->nIndex);

		if (it_xxx != Rakan_W_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

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

						if (CheckName("_W_indicator",object->GetNameNpc()) && CheckName("Rakan",object->GetNameNpc()))	//"Rakan_Base_W_indicator" 
						{
							char szTemp[] = {82,97,107,97,110,87,95,83,115,0};		// "RakanW_Ss"
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = GET_START_POS(enemyHero);
								Vec3D EndPos   = GET_END_POS(enemyHero);
								
								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									if (object->currentPos().IsValid() && Distance(object->currentPos(), EndPos) < 50)	//cho~ nay hay thay doi giua EndPos hoac StartPos
									{
										//__oMsg("---((***))----- Rakan_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), EndPos));
										CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Rakan_W_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}

//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Malphite_R_Dash = 0;
void DodS_Malphite_R()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Malphite_R_Dash) Malphite_R_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)				  continue;
		if (IS_DEAD(enemyHero))								  continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)		  continue;
		if (Distance(enemyHero, MY_HERO) > 1800)			  continue;
		if (!CheckName(enemyHero->GetNameHero(), "Malphite")) continue;
		

		std::map<DWORD, float>::iterator it_xxx = Malphite_R_Dash->find(enemyHero->nIndex);

		if (it_xxx != Malphite_R_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

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

						if (CheckName("R_cas_",object->GetNameNpc()) && CheckName("Malphite",object->GetNameNpc()))	//"Malphite_Skin06_R_cas_trail" 
						{
							char szTemp[] = {77,97,108,112,104,105,116,101,82,95,83,115,0};	// "MalphiteR_Ss"	
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = GET_START_POS(enemyHero);
								Vec3D EndPos   = GET_END_POS(enemyHero);

								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									if (object->currentPos().IsValid() && Distance(object->currentPos(), StartPos) < 50)	//cho~ nay hay thay doi giua EndPos hoac StartPos
									{
										//__oMsg("---((***))----- Malphite_R_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
										CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Malphite_R_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}

//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Sejuani_Q_Dash = 0;
void DodS_Sejuani_Q()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Sejuani_Q_Dash) Sejuani_Q_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)				 continue;
		if (IS_DEAD(enemyHero))							     continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)		 continue;
		if (Distance(enemyHero, MY_HERO) > 1500)			 continue;
		if (!CheckName(enemyHero->GetNameHero(), "Sejuani")) continue;
		

		std::map<DWORD, float>::iterator it_xxx = Sejuani_Q_Dash->find(enemyHero->nIndex);

		if (it_xxx != Sejuani_Q_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

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

						if (CheckName("_P_Buff",object->GetNameNpc()) && CheckName("Sejuani",object->GetNameNpc()))	// "Sejuani_Base_P_Buff" (FOW&&NOFOW), "Sejuani_Base_Q_cas" 
						{
							char szTemp[] = {83,101,106,117,97,110,105,81,95,83,115,0};	// "SejuaniQ_Ss"	
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = GET_START_POS(enemyHero);
								Vec3D EndPos   = GET_END_POS(enemyHero);

								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									if (object->currentPos().IsValid() && Distance(object->currentPos(), StartPos) < 50)	//cho~ nay hay thay doi giua EndPos hoac StartPos
									{
										spellData.range = StartPos.Distance2D(EndPos) + 150;

										//__oMsg("---((***))----- Sejuani_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
										CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Sejuani_Q_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}

//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Shen_E_Dash = 0;
void DodS_Shen_E()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Shen_E_Dash) Shen_E_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)			  continue;
		if (IS_DEAD(enemyHero))							  continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	  continue;
		if (Distance(enemyHero, MY_HERO) > 1500)		  continue;
		if (!CheckName(enemyHero->GetNameHero(), "Shen")) continue;
		

		std::map<DWORD, float>::iterator it_xxx = Shen_E_Dash->find(enemyHero->nIndex);

		if (it_xxx != Shen_E_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

					char szTemp[] = {83,104,101,110,69,95,83,115,0};	// "ShenE_Ss"	
					std::string mis_Name(szTemp);

					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
					{
						SpellData spellData = it_onMissileSpells->second;

						Vec3D StartPos = GET_START_POS(enemyHero);
						Vec3D EndPos   = GET_END_POS(enemyHero);

						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
						{
							spellData.range = StartPos.Distance2D(EndPos) + 125;

							//__oMsg("---((***))----- Shen_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f ",mis_Name.c_str(), StartPos.Distance2D(EndPos));
							CreateSpellData(enemyHero, StartPos, EndPos, spellData);
						}
					}
				}
			}
		}
		else
		{
			Shen_E_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}


//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Tryndamere_E_Dash = 0;
void DodS_Tryndamere_E()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Tryndamere_E_Dash) Tryndamere_E_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)					continue;
		if (IS_DEAD(enemyHero))									continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)			continue;
		if (Distance(enemyHero, MY_HERO) > 1500)				continue;
		if (!CheckName(enemyHero->GetNameHero(), "Tryndamere")) continue;
		

		std::map<DWORD, float>::iterator it_xxx = Tryndamere_E_Dash->find(enemyHero->nIndex);

		if (it_xxx != Tryndamere_E_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

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
						if (object->nIndex != 0)				continue;

						//if ((object->nIndex & 0x3fff) <= 0 || 
						//	(object->nIndex & 0x3fff) > 0xFF00) continue;

						if (IS_OBJ_DELETED(object) == true)		continue;

						if (CheckName("_E_Slash",object->GetNameNpc()) && CheckName("Tryndamere",object->GetNameNpc()))	// "Tryndamere_Base_E_Slash"
						{
							char szTemp[] = {84,114,121,110,100,97,109,101,114,101,69,95,83,115,0};	// "TryndamereE_Ss"	
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = GET_START_POS(enemyHero);
								Vec3D EndPos   = GET_END_POS(enemyHero);

								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									if (object->currentPos().IsValid() && Distance(object->currentPos(), StartPos) < 60)	//cho~ nay hay thay doi giua EndPos hoac StartPos
									{
										spellData.range = StartPos.Distance2D(EndPos) + 150;

										//__oMsg("---((***))----- Tryndamere_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
										CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Tryndamere_E_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}

//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Gragas_E_Dash = 0;
void DodS_Gragas_E()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Gragas_E_Dash) Gragas_E_Dash = new std::map<DWORD, float>;

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
		if (IS_DEAD(enemyHero))							    continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	    continue;
		if (Distance(enemyHero, MY_HERO) > 1500)			continue;
		if (!CheckName(enemyHero->GetNameHero(), "Gragas")) continue;
		
		std::map<DWORD, float>::iterator it_xxx = Gragas_E_Dash->find(enemyHero->nIndex);

		if (it_xxx != Gragas_E_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

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

						if (CheckName("_E_Cas",object->GetNameNpc()) && CheckName("Gragas",object->GetNameNpc()))	// "Gragas_Base_E_Cas"
						{
							char szTemp[] = {71,114,97,103,97,115,69,95,83,115,0};	// "GragasE_Ss"	
							std::string mis_Name(szTemp);

							std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
							if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
							{
								SpellData spellData = it_onMissileSpells->second;

								Vec3D StartPos = GET_START_POS(enemyHero);
								Vec3D EndPos   = GET_END_POS(enemyHero);
											
								if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
								{
									if (object->currentPos().IsValid() && Distance(object->currentPos(), StartPos) < 50)	//cho~ nay hay thay doi giua EndPos hoac StartPos
									{
										//__oMsg("---((***))----- Gragas_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
										CreateSpellData(enemyHero, StartPos, EndPos, spellData);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Gragas_E_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}


//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Gnar_E1E2_Dash = 0;
void DodS_Gnar_E1E2()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Gnar_E1E2_Dash) Gnar_E1E2_Dash = new std::map<DWORD, float>;

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

		if (enemyHero->nTeam_ID == myTeamId)			  continue;
		if (IS_DEAD(enemyHero))							  continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	  continue;
		if (Distance(enemyHero, MY_HERO) > 1500)		  continue;
		if (!CheckName(enemyHero->GetNameHero(), "Gnar")) continue;
		
		std::map<DWORD, float>::iterator it_xxx = Gnar_E1E2_Dash->find(enemyHero->nIndex);

		if (it_xxx != Gnar_E1E2_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();
					
					//-------- E.2(Big) -------------------------:
					if (enemyHero->nOverrideCollisionRadius > 150)	//E-2-BIG
					{
						char szTemp2[] = {71,110,97,114,69,50,95,83,115,0};	// "GnarE2_Ss"	
						std::string mis_Name(szTemp2);

						std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
						if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
						{
							SpellData spellData = it_onMissileSpells->second;

							Vec3D StartPos = GET_START_POS(enemyHero);
							Vec3D EndPos   = GET_END_POS(enemyHero);

							if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
							{
								stMOVE *enemyPos = (stMOVE*) GET_PMOVE_NEW(enemyHero);
								if(enemyPos)
								{
									if (enemyPos->nDashSpeed > 500.0f) 
										spellData.projectileSpeed = enemyPos->nDashSpeed;
								}
								//__oMsg("---((***))----- GnarE2_BIG_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f ",mis_Name.c_str(), StartPos.Distance2D(EndPos));
								CreateSpellData(enemyHero, StartPos, EndPos, spellData);
							}
						}
					}
					else	//-------- E.1(Small) ------------------------------------------------:
					{
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

												////////////////////////////
												////if ( CheckName("Gnar", object->GetNameNpc()))
												////{
												////	__oMsg("[%s] [%x, %x] [%.3f, %.3f, %.3f] [%x], %.4f",  object->GetNameNpc(), object->nIndex, object->nMissileOwnerID_1, object->currentPos().x, object->currentPos().y, object->currentPos().z, enemyHero->nID, GetTimeGame());
												////}
												////////////////////////////

							if (OBJECT_TYPE(object) != 1)			continue;
							if ((object->nIndex & 0x3fff) <= 0 || 
								(object->nIndex & 0x3fff) > 0xFF00) continue;
							if (IS_OBJ_DELETED(object) == true)		continue;

							if (CheckName("_E_Trail",object->GetNameNpc()) && CheckName("Gnar",object->GetNameNpc()))	// "Gnar_Base_E_Trail"
							{
								char szTemp1[] = {71,110,97,114,69,49,95,83,115,0};	// "GnarE1_Ss"	
								std::string mis_Name(szTemp1);

								std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
								if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
								{
									SpellData spellData = it_onMissileSpells->second;

									Vec3D StartPos = GET_START_POS(enemyHero);
									Vec3D EndPos   = GET_END_POS(enemyHero);

														////////////////////////////
														////__oMsg("obj[%.3f, %.3f, %.3f]", object->currentPos().x, object->currentPos().y, object->currentPos().z);
														////__oMsg("StartPos[%.3f, %.3f, %.3f]", StartPos.x, StartPos.y, StartPos.z);
														////__oMsg("EndPos[%.3f, %.3f, %.3f]", EndPos.x, EndPos.y, EndPos.z);

														////stMOVE *enemyPos = (stMOVE*) GET_PMOVE_NEW(enemyHero);
														////if(enemyPos)
														////{
														////	if ((BYTE)enemyPos->nIsDash == 0) __oMsg("Dash-Speed: %f", enemyPos->nDashSpeed);
														////}
														////////////////////////////

									if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
									{
										if (object->currentPos().IsValid() && Distance(object->currentPos(), StartPos) < 50)	//cho~ nay hay thay doi giua EndPos hoac StartPos
										{
											//__oMsg("---((***))----- GnarE1_SMALL_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - %f",mis_Name.c_str(), StartPos.Distance2D(EndPos), Distance(object->currentPos(), StartPos));
											CreateSpellData(enemyHero, StartPos, EndPos, spellData);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			Gnar_E1E2_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}

//--------------------//----------------------------------//--------------------//
std::map<DWORD, float> *Khazix_E12_Dash = 0;
void DodS_Khazix_E12()
{
	//if (canUse_VMT) return;		//no for CNN

	if (!Khazix_E12_Dash) Khazix_E12_Dash = new std::map<DWORD, float>;

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
		if (IS_DEAD(enemyHero))							    continue;
		if ((BYTE)enemyHero->nIsTargetableToTeam != 4)	    continue;
		if (Distance(enemyHero, MY_HERO) > 1500)			continue;
		if (!CheckName(enemyHero->GetNameHero(), "Khazix")) continue;			//"Khazix_Base_E_WeaponTrails" --> hinh nhu dung` dc, chua thu?
		

		std::map<DWORD, float>::iterator it_xxx = Khazix_E12_Dash->find(enemyHero->nIndex);

		if (it_xxx != Khazix_E12_Dash->end())
		{
			if (!IsDashing(enemyHero))
			{
				it_xxx->second = 0;
			}
			else
			{
				if (fabs(it_xxx->second) < FLT_EPSILON)
				{
					it_xxx->second = GetTimeGame();

					char szTemp1[] = {75,104,97,122,105,120,69,49,95,83,115,0};	// "KhazixE1_Ss"	
					std::string mis_Name(szTemp1);

					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
					{
						SpellData spellData = it_onMissileSpells->second;

						Vec3D StartPos = GET_START_POS(enemyHero);
						Vec3D EndPos   = GET_END_POS(enemyHero);

						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
						{
							spellData.range = StartPos.Distance2D(EndPos) + 5;

							stMOVE *enemyPos = (stMOVE*) GET_PMOVE_NEW(enemyHero);
							if(enemyPos)
							{
								if (enemyPos->nDashSpeed > 600.0f) 
									spellData.projectileSpeed = enemyPos->nDashSpeed;
							}
							
							//__oMsg("---((***))----- Khazix_E1_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f ",mis_Name.c_str(), StartPos.Distance2D(EndPos));
							CreateSpellData(enemyHero, StartPos, EndPos, spellData);
						}
					}
				}
			}
		}
		else
		{
			Khazix_E12_Dash->insert(std::pair<DWORD, float> (enemyHero->nIndex, 0));
		}
	}
}