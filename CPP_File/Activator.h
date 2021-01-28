#include "Utils.h"




void CheckListItem();
void Check_D_F_Spells(KNpc *pPlayer);
void ActivatorAllItem();

void AutoHealItems(KNpc *pPlayer);
void AutoSummonerHeal(KNpc *pPlayer);
void AutoBarrier(KNpc *pPlayer);
void AutoIronSolari(KNpc *pPlayer);
void AutoDayChuyenChuocToi(KNpc *pPlayer);
void AutoSeraphs(KNpc *pPlayer);
void AutoZhonyas(KNpc *pPlayer);

void AutoCleaseMercurial(KNpc *pPlayer);
void AutoIgnite();
void AutoKhienBang(KNpc *pPlayer);
void AutoRiuMangXa(KNpc *pPlayer);
void AutoVoDanh(KNpc *pPlayer);
void AutoHextech(KNpc *pPlayer);


//--- SMITE --------------------------
void  Smite_MenuValueDefault();
void  Smite_OnDrawMenu();
void  Draw_Smite_Status();
float GetSmiteDamage(KNpc *pPlayer, KNpc *target);
void  LogicSmiteJungle(KNpc *pPlayer);	//KS + smite quai rung, smiteCombo o onB4Attack

void  Mikael_MenuValueDefault();
void  cbMikaelDrawMenu();
void  Mikael_update(KNpc *pPlayer);

KNpc* Get_EnemyLongDen_Around(KNpc* hero, float nRange);
int   GetMySkillWardIndex();
void  AutoWard_With_LanternThresh(KNpc* myHero);
void  AutoWard_With_InvisibleHero(KNpc* myHero);
