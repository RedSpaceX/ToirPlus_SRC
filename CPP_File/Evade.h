#pragma once
#include "Utils.h"
#include "fucker.h"




//---------------------------------------------------------------------------
void	OnGameUpdate_Evade();

void	RecalculatePath();
void	ContinueLastBlockedCommand();
void	CheckHeroInDanger();
void	DodgeSkillShots_func();

bool	isDodgeDangerousEnabled();
void	CheckDodgeOnlyDangerous();		//Dodge only dangerous event

void	SpellDetector_OnProcessDetectedSpells();

void	OnIssueOrder_Evade(KNpc* hero, GameObjectIssueOrderEventArgs* args);