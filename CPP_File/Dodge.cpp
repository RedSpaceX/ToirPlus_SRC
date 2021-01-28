#include "Dodge.h"

CDodge * CDodge::s_Instance = NULL;

//==1===RYZE=====================================================================================================
void CDodge::DodgeRYZE(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__RyzeQ)) || CheckName(pBuff.szSpellName,  (sz__ryzerq)))
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//==2===GRAGAS=====================================================================================================
void CDodge::DodgeGRAGAS(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__GragasQ)))			// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__GragasR)))			// R
	{
		//KNpc *pPlayer = GetPlayer();
		//float KhoangCach = Distance_2D(pPlayer->CurrentPos.x, pPlayer->CurrentPos.z, pBuff.MaxDestPos.x, pBuff.MaxDestPos.z);
		//__oMsg("khoang cach ==========gragas=======%f", KhoangCach);
		//if (KhoangCach >= 265.)
		//{
		//	pBuff.nDangerValue = 4;
		//}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
void CDodge::DodgeGRAGAS_BASETIME(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__GragasE)))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}
	}
}
//==3===EZREAL==========================================================================================================
void CDodge::DodgeEZREAL(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName, "EzrealQ"))				// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName, "EzrealW"))			// W
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName, "EzrealR"))		// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui, RESET_BUFFER_SPELL, true);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
		}*/
	}
}
//==4===CAITLYN==========================================================================================================
void CDodge::DodgeCAITLYN(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__CaitlynPiltoverPeacemaker)))		// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__CaitlynEntrapment)))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//==5===MORGANA==========================================================================================================
void CDodge::DodgeMORGANA(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__DarkBindingMissile)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
	//else if (CheckName(pBuff.szSpellName,  (sz__TormentedSoil)))			// W
	//{
	//	DodgeCircle(&pBuff.MaxDestPos, float(MORGANA_W_Radius), &pBuff);
	//}
}
//==6===CHOGATH==========================================================================================================
void CDodge::DodgeCHOGATH(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__Rupture)))		// Q
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(CHOGATH_Q_Radius), &pBuff);
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__FeralScream)))		// W
	{
		//PrintCastSpell(pEnemyPlayer);
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, CHOGATH_W_RadiusCone, CHOGATH_W_RadiusLine, CHOGATH_W_Range, &pBuff);
	}
}
//==7===AMUMU==========================================================================================================
void CDodge::DodgeAMUMU(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__BandageToss)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__CurseoftheSadMummy)))		// R
	{
		//KNpc* pPlayer = GetPlayer();
		//float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos);
		//__oMsg("khoang cach =================%f", KhoangCach);
		//if (KhoangCach > 495.)
		//{
		//	pBuff.nDangerValue = 4;
		//}
		EVADE_CIRCLE(&pBuff.SourcePos, &pBuff);
	}
}
//==8===GRAVES==========================================================================================================
void CDodge::DodgeGRAVES(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	float fDistance;
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName(pBuff.szSpellName,  (sz__GravesQLineSpell)))		// Q
	{
		KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);

		if (fDistance < 635.)
		{
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				} 
				else
				{
					if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
					{
						EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
					}
				}
			} 
			else
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			}*/
		}
		else
		{   
			int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, GRAVES_Q_Radius_2, GRAVES_Q_Range_2, &pBuff);
				} 
				else
				{
					DodgeMissileLine_45do_TIEN(&pBuff.SourcePos, &pBuff.MaxDestPos, GRAVES_Q_Radius_2, GRAVES_Q_Range_2, &pBuff);
				}
			} 
			else
			{
				DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, GRAVES_Q_Radius_2, GRAVES_Q_Range_2, &pBuff);
			}
		}
	}
	else if (CheckName(pBuff.szSpellName,  (sz__GravesSmokeGrenade)))		// W
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(GRAVES_W_Radius), &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__GravesChargeShot)))		// R
	{
		KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);
		//__oMsg("======xxx===== fDistance: %f", fDistance);
		if (fDistance <= 1050)
		{
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				} 
				else
				{
					if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
					{
						EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
					}
				}
			} 
			else
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			}*/
		}
		else if (fDistance <= 1300)
		{
			pBuff.nRange = 1300;
			pBuff.nRadius = 220;
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(GRAVES_R_Radius2), float(GRAVES_R_Range2), &pBuff);
				} 
				else
				{
					DodgeMissileLine_45do_TIEN(&pBuff.SourcePos, &pBuff.MaxDestPos, 180.0, GRAVES_R_Range2, &pBuff);
				}
			} 
			else
			{
				DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(GRAVES_R_Radius2), float(GRAVES_R_Range2), &pBuff);
			}*/
		}
	}
}
//==9===AATROX==========================================================================================================
void CDodge::DodgeAATROX(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__AatroxQ)))		// Q
	{
		// CHUA LAY DUOC pCastSpell
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(AATROX_Q_Radius), float(AATROX_Q_Range), &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__AatroxE)))		// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
void CDodge::DodgeAATROX_BASETIME(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__AatroxQ)))		// Q
	{
		DodgeCircle(&pBuff.MaxDestPos, float(AATROX_Q_Radius), &pBuff, AATROX_Q_DelayFlying, RESET_BASE_TIME);
	}
}
//=10===JANNA==========================================================================================================
void CDodge::DodgeJANNA(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__JannaQ)))		// Q:HowlingGale
	{
		// CHUA LAY DUOC pCastSpell
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(JANNA_Q_Radius), float(JANNA_Q_Range), &pBuff);
	}
}
//=11===SEJUANI==========================================================================================================
void CDodge::DodgeSEJUANI(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	float fDistance;
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName(pBuff.szSpellName,  (sz__SejuaniR)))		// R
	{
		KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);

		if (fDistance <= 1310 && fDistance >= 1080)
		{
			pBuff.nRadius = 175;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//KPos posNghiem1, posNghiem2;
		//TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, SEJUANI_R_Range);
		//float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		//float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		//float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		//float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		//if (tichVoHuong >= 0)
		//{
		//	pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
		//	//__oMsg("new max dest1 = (%f, %f)", posNghiem1->x, posNghiem1->z);
		//}
		//else
		//{
		//	pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
		//	//__oMsg("new max dest2 = (%f, %f)", posNghiem2->x, posNghiem2->z);
		//}

		//KPos diemVuongGoc;
		//GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		//fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);

		//if (fDistance <= 700.)
		//{
		//	DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//	/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		//	if (nTienLui != 0)
		//	{
		//		if (nTienLui == -1)
		//		{
		//			EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//		} 
		//		else
		//		{
		//			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
		//			{
		//				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//			} 
		//			else
		//			{
		//				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
		//			}
		//		}
		//	} 
		//	else
		//	{
		//		EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//	}*/
		//}
		//else if (fDistance <= 930.)
		//{
		//	pBuff.nRadius = 135.0;
		//	EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 1);
		//}
		//else if (fDistance <= 1200.)
		//{
		//	int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		//	if (nTienLui != 0)
		//	{
		//		pBuff.nRadius = 250.0;
		//		EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
		//	} 
		//	else
		//	{
		//		DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, 350.0, float(SEJUANI_R_Range), &pBuff);
		//	}
		//}
		//else
		//{
		//	DodgeCircle(&pBuff.MaxDestPos, float(SEJUANI_R_Radius_CIRCLE), &pBuff);
		//}
	}
}
void CDodge::DodgeSEJUANI_BASETIME(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__SejuaniQ), pBuff.szSpellName))		// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BASE_TIME);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BASE_TIME);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui, RESET_BASE_TIME);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BASE_TIME);
		}*/
	}
}
//=12===AHRI==========================================================================================================
void CDodge::DodgeAHRI(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__AhriOrbofDeception))||CheckName(pBuff.szSpellName,  (sz__AhriOrbofReturn)))		// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__AhriSeduce)))		// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//=13===KALISTA=======================================================================================================
void CDodge::DodgeKALISTA(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__KalistaMysticShot)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=14===JINX==========================================================================================================
void CDodge::DodgeJINX(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__JinxWMissile)))		// W
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__JinxR)))		// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui, RESET_BUFFER_SPELL, true);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
		}*/
	}
}
//=15===DR.MUNDO==========================================================================================================
void CDodge::DodgeMUNDO(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__InfectedCleaverMissile)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=16===BLITZCRANK==========================================================================================================
void CDodge::DodgeBLITZCRANK(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__RocketGrabMissile)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//=17===BRAND==========================================================================================================
void CDodge::DodgeBRAND(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__BrandQ)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__BrandW)))		// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=18===BRAUM==========================================================================================================
void CDodge::DodgeBRAUM(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__BraumQ)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__BraumRWrapper)))		// R
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=19===CORKI==========================================================================================================
void CDodge::DodgeCORKI(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__PhosphorusBomb)))		// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__MissileBarrageMissile)))		// R1
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 175.0) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__MissileBarrageMissile2)))
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 275.0) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=20===TAHM KENCH==========================================================================================================
void CDodge::DodgeTAHMKENCH(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__TahmKenchQ)))		// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	//if (CheckName(pBuff.szSpellName,  "TahmKenchWCastTimeAndAnimation"))		// W
	//{
	//	if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
	//	{
	//		UnBlockMove();
	//		return;
	//	}
	//	DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	//}
}
//=21===FIORA==========================================================================================================
void CDodge::DodgeFIORA(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__FioraW)))		// Q
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(FIORA_Q_Radius), float(FIORA_Q_Range), &pBuff);
		// KHONG LAY DUOC pCastSpell
	}
}
//=22===JARVAN4==========================================================================================================
void CDodge::DodgeJARVAN4(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__JarvanIVDragonStrike)))		// Q1
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__JarvanIVEQ)))				// Q2(luot) -> thuc ra ko vao day
	{
		int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}
	}
	else if (CheckName(pBuff.szSpellName,  (sz__JarvanIVDemacianStandard)))// E
	{
		//CHIEU NAY KO NE DC, KO LAY DC pCastSpell
		//DodgeCircle(&pBuff.MaxDestPos, float(JARVAN4_E_Radius), &pBuff);
	}
}
//=23===LUX==========================================================================================================
void CDodge::DodgeLUX(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__LuxLightBinding), pBuff.szSpellName)) // Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 2)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);	
	}
	else if (CheckName(pBuff.szSpellName,  (sz__LuxLightStrikeKugel)))	// E
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__LuxMaliceCannonMis)))		// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=24===NIDALEE==========================================================================================================
void CDodge::DodgeNIDALEE(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__JavelinToss)))				// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__Bushwhack)))				// W_NGUOI
	{
		// KHONG NGUY HIEM, KO CAN THIET
		//DodgeCircle( &pBuff.MaxDestPos, float(NIDALEE_W_Radius), &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__Swipe)))				// E_BAO
	{
		//DodgeCircle( &pEnemyPlayer->CurrentPos, float(NIDALEE_E_Radius), &pBuff);
	}
}
//=25===OLAF==========================================================================================================
void CDodge::DodgeOLAF(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__OlafAxeThrowCast)))				// Q
	{
		float nRange = Distance_2D(pBuff.SourcePos, pBuff.MaxDestPos);
		if (nRange < pBuff.nRange)
		{
			pBuff.nRange = nRange;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=26===NAUTILUS==========================================================================================================
void CDodge::DodgeNAUTILUS(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__NautilusAnchorDragMissile)))				// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);// con nay ko nen ne 45do vi de trung chieu keo' lai
	}
}
//=27===NOCTURNE==========================================================================================================
void CDodge::DodgeNOCTURNE(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__NocturneDuskbringer)))		// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=28===MISS FORTUNE==========================================================================================================
void CDodge::DodgeMISSFORTUNE(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__MissFortuneScattershot)))		// E
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(MISSFORTUNE_E_Radius), &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__MissFortuneBulletTime)))		// R
	{
		// HINH NON -> CHUA LAM DUOC
	}
}
//=29===VARUS==========================================================================================================
void CDodge::DodgeVARUS(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__VarusQMissilee)))				// Q
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(VARUS_Q_Radius), float(VARUS_Q_Range), &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__VarusE)))					// E
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__VarusR)))					// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//=30===VEIGAR==========================================================================================================
void CDodge::DodgeVEIGAR(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	if (CheckName(pBuff.szSpellName,  (sz__VeigarBalefulStrike)))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 2)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__VeigarDarkMatterCastLockout), pBuff.szSpellName))		// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <= 350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__VeigarEventHorizon)))					// E
	{
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=31===VELKOZ==========================================================================================================
void CDodge::DodgeVELKOZ(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	float fDistance;
	if (CheckName(pBuff.szSpellName,  (sz__VelkozQ)))						// Q1
	{
		//PrintCastSpell(pEnemyPlayer);
		KPos posNghiem1, posNghiem2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, VELKOZ_Q1_Range);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
		{
			pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
		}
		else
		{
			pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
		}
		KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);

		if (fDistance <= 1000)
		{
			if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 150.0) >= 1)
			{
				UnBlockMove();
				return;
			}
			//__oMsg("================VELKOZ===================1 ;%f", fDistance);
			//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(VELKOZ_Q1_Radius), float(VELKOZ_Q1_Range), &pBuff);
			/*pBuff.nFlag_TruocSau = false;
			pBuff.nDelay = 250;
			pBuff.nRange = 1100;
			pBuff.nRadius = 55;
			pBuff.nMissileSpeed = 1300;*/
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				} 
				else
				{
					if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
					{
						EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
					}
				}
			} 
			else
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			}*/
		}
		else
		{
			KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
			TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, 350.0);
			DodgeMissileLine_45do(&pBuff.MaxDestPos, pos_diem1, float(VELKOZ_Q2_Radius), float(VELKOZ_Q2_Range), &pBuff, 900., false);
			/*pBuff.nFlag_TruocSau = true;
			pBuff.nDelay = 1000*fDistance/1200;
			pBuff.nRange = 550;
			pBuff.nRadius = 45;
			pBuff.nMissileSpeed = 2100;
			DODGE_LINE_NEW(&pBuff.MaxDestPos, pos_diem1, &pBuff);*/
			delete pos_diem1, pos_diem2;

			//GIAO_DIEM_VUONG_GOC(diemVuongGoc, pos_diem1, &pBuff.MaxDestPos, &pPlayer->CurrentPos);
			//fDistance = Distance_2D(*diemVuongGoc, pBuff.MaxDestPos);
			//__oMsg("=================VELKOZ==================2 ;%f", fDistance);
		}
	}
	else if (CheckName(pBuff.szSpellName,  (sz__VelkozQSplit)))			// Q2
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(VELKOZ_Q2_Radius), float(VELKOZ_Q2_Range), &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__VelkozW)))				// W
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(VELKOZ_W_Radius), float(VELKOZ_W_Range), &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__VelkozE)))				// E
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 250.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__VelkozR), pBuff.szSpellName))				// R
	{
		// CHUA LAM DUOC
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(VELKOZ_W_Radius), float(VELKOZ_W_Range), &pBuff);
	}
}
//=32===LUCIAN==========================================================================================================
void CDodge::DodgeLUCIAN(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	float fDistance;
	if (CheckName( (sz__LucianQ), pBuff.szSpellName))						// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__LucianW), pBuff.szSpellName))			    // W
	{
		KPos posNghiem1, posNghiem2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, 1000);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
		{
			pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
		}
		else
		{
			pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
		}
		KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);

		if (fDistance <= 750)
		{
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				} 
				else
				{
					if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
					{
						EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
					}
				}
			} 
			else
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			}*/
		}
		else if(fDistance >750 && fDistance < 1050)
		{
			KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
			TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, 350.);// de vi cung gia tri, y nghia thi khac nhau
			DodgeMissileLine_45do(&pBuff.MaxDestPos, pos_diem1, float(LUCIAN_W_Radius2), 350., &pBuff, LUCIAN_W_DelayFlying, false);

			delete pos_diem1, pos_diem2;
		}
		else
		{
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == 1)
				{
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				} 
				else
				{
					if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
					{
						EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
					}
				}
			} 
			else
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			}*/
		}
		/*KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);
		//__oMsg("------------------------distance=%f", fDistance);
		if (fDistance >= 900 && fDistance <= 1200)
		DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(LUCIAN_W_Radius2), float(LUCIAN_W_Range), &pBuff);
		else
		DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(LUCIAN_W_Radius1), float(LUCIAN_W_Range), &pBuff);*/
	}
	else if (CheckName( (sz__LucianR), pBuff.szSpellName))				// R
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z		(1)(d: duong thang di qua 2 diem startPoint & endPoint)
		//dZ.x - dX.z  = C4   = dZ * pEnemyPlayer->CurrentPos.x - dX*pEnemyPlayer->CurrentPos.z 	(4)(song song voi d + di qua pEnemyPlayer)
		KNpc* pEnemyPlayer = (KNpc*)pBuff.pNpc;
		KPos posNghiem1, posNghiem2, posNew;
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C4 = dZ * pEnemyPlayer->CurrentPos.x - dX * pEnemyPlayer->CurrentPos.z;
		posNew.x = 1.0;
		//if (dX == 0. || dX == 0) continue; // OLD CODE FROM AUTO_DODGE FUNCTION
		if (dX == 0. || dX == 0) return; // NEW CODE
		posNew.z = (dZ - C4)/dX;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pEnemyPlayer->CurrentPos, posNew, LUCIAN_R_Range);
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;

		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			EVADE_LINE(&pEnemyPlayer->CurrentPos, &posNghiem1, &pBuff);
			//DODGE_LINE_NEW(&pEnemyPlayer->CurrentPos, &posNghiem1, &pBuff);
		else
			EVADE_LINE(&pEnemyPlayer->CurrentPos, &posNghiem2, &pBuff);
			//DODGE_LINE_NEW(&pEnemyPlayer->CurrentPos, &posNghiem2, &pBuff);
	}
}
//=33===DRAVEN==========================================================================================================
void CDodge::DodgeDRAVEN(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__DravenDoubleShot)))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__DravenRCast)))			    // R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui, RESET_BUFFER_SPELL, true);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
		}*/
	}
}
//=34===EKKO==========================================================================================================
void CDodge::DodgeEKKO(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__EkkoQ)))			// Q
	{
		//KNpc *pEnemyPlayer = GetEnemyPlayer( (sz__Ekko));
		//DodgeMissileLine(&pEnemyPlayer->CurrentPos, &pBuff.MaxDestPos, float(EKKO_Q_Radius), float(EKKO_Q_Range), &pBuff/*, pCastSpell, float(EKKO_Q_DelayFlying)*/);
		float nDistance = Distance_2D(pBuff.SourcePos, pBuff.PlayerPos);
		if (nDistance > 750)
		{
			pBuff.nRadius = 180;
			pBuff.nMissileSpeed = 750;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui, RESET_BUFFER_SPELL, true);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__EkkoW)))		// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName(pBuff.szSpellName,  (sz__EkkoR)))		// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(EKKO_R_Radius), &pBuff);
		// R can lam theo toa do cua bong
	}
}
//=35===DARIUS==========================================================================================================
void CDodge::DodgeDARIUS(KBuffer_Spell pBuff)
{
	//pEnemyPlayer = GetEnemyPlayer( (sz__Darius));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName(pBuff.szSpellName,  (sz__DariusAxeGrabCone)))		// E
	{
		DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(DARIUS_E_RadiusCone),DARIUS_E_RadiusLine, float(DARIUS_E_Range), &pBuff, DARIUS_E_DelayFlying);
		// HINH NON - CHUA LAM DUOC
	}
}
void CDodge::DodgeDARIUS_BASETIME(KBuffer_Spell pBuff)
{
	KNpc* pEnemyPlayer = (KNpc*)pBuff.pNpc;
	if (CheckName(pBuff.szSpellName,  (sz__DariusCleave)))			// Q
	{
		DodgeCircle(&pEnemyPlayer->CurrentPos, float(DARIUS_Q_Radius), &pBuff,DARIUS_Q_DelayFlying , RESET_BASE_TIME);
	}
}
//=36===KARMA==========================================================================================================
void CDodge::DodgeKARMA(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	float fDistance = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos);
	if (CheckName(pBuff.szSpellName,  (sz__KarmaQ)))			// Q1 GHE
	{
		if (fDistance < 800)// ne Q-ghe, Q-xin nhu nhau(ne voi radius = 80
		{
			if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 265.0) >= 1)
			{
				UnBlockMove();
				return;
			}
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
			if (nTienLui != 0)
			{
				if (nTienLui == -1)
				{
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				} 
				else
				{
					if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
					{
						EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
					}
				}
			} 
			else
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			}*/
		}
		else
		{
			if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 265.0) >= 1)
			{
				UnBlockMove();
				extern bool nKarma_radius_QR;
				if(nKarma_radius_QR == true) nKarma_radius_QR = false;
				return;
			}
			DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
			//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(KARMA_Q1_Radius_2), float(KARMA_Q1_Range), &pBuff);
		}
	}
	//else if (CheckName(pBuff.szSpellName,  (sz__KarmaQMantra)))		// Q2 + R : ko vao vi ko lay duoc skill name 'KarmaQMantra'
	//{
	//	if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 155.0) >= 1)
	//	{
	//		UnBlockMove();
	//		return;
	//	}
	//	DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(KARMA_Q1_Radius), float(KARMA_Q1_Range), &pBuff);
	//}
}
//=37===SIVIR==========================================================================================================
void CDodge::DodgeSIVIR(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__SivirQ)))			// Q1
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__SivirQReturn)))		// Q2
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(SIVIR_QReturn_Radius), float(SIVIR_QReturn_Range), &pBuff);
	}
}
//=38===GALIO==========================================================================================================
void CDodge::DodgeGALIO(KBuffer_Spell pBuff)
{
	//KNpc *pPlayer = GetPlayer();
	//float fDistance = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos);
	//if (CheckName(pBuff.szSpellName,  (sz__GalioResoluteSmite)))			// Q
	//{
	//	KNpc* pPlayer = GetPlayer();
	//	if(pPlayer->nAttackRange <=350.0)
	//	{
	//		float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
	//		if(KhoangCach <= 350.0)
	//		{
	//			UnBlockMove();
	//			return;
	//		}
	//	}
	//	EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	//}
	//else if (CheckName(pBuff.szSpellName,  (sz__GalioRighteousGust)))		// E
	//{
	//	int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
	//	if (nTienLui != 0)
	//	{
	//		if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
	//		{
	//			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	//		} 
	//		else
	//		{
	//			EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
	//		}
	//	} 
	//	else
	//	{
	//		EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	//	}
	//}
	//else if (CheckName(pBuff.szSpellName,  (sz__GalioIdolOfDurand)))		// R
	//{
	//	//__oMsg("---------khoang cach = %f", fDistance);
	//	//if (fDistance >= 485.)
	//	//{
	//	//	DodgeCircle(&pBuff.SourcePos, float(GALIO_R_Radius), &pBuff);
	//	//}
	//	//else
	//	//{
	//	//	DodgeCircle(&pBuff.SourcePos, float(GALIO_R_Radius), &pBuff, GALIO_R_DelayFlying, RESET_BUFFER_SPELL, true);
	//	//}
	//	EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	//}
}
//=39===TRISTANA==========================================================================================================
void CDodge::DodgeTRISTANA(KBuffer_Spell pBuff)
{
	if (CheckName(pBuff.szSpellName,  (sz__TristanaW)))			// W
	{
		// KHONG NGUY HIEM, KO CAN THIET
		//DodgeCircle(&pBuff.MaxDestPos, float(TRISTANA_W_Radius), &pBuff);
	}
}
//=40===KARTHUS==========================================================================================================
void CDodge::DodgeKARTHUS(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__KarthusLayWaste), pBuff.szSpellName))			// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=41===MALPHITE===========KHONG LAY DUOC pCastSpell -> CHUYEN SANG BEN KIA============================================
void CDodge::DodgeMALPHITE(KBuffer_Spell pBuff)
{
	
}
void CDodge::DodgeMALPHITE_BASETIME(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__UFSlash), pBuff.szSpellName))			// R
	{
		//if (KhoangCach < 235.)
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff, RESET_BASE_TIME);
	}
}
//=42===NASUS==========================================================================================================
void CDodge::DodgeNASUS(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__NasusE), pBuff.szSpellName))			// E
	{
		// KHONG NGUY HIEM, KO CAN NE
		//DodgeCircle(&pBuff.MaxDestPos, float(NASUS_R_Radius), &pBuff);
	}
}
//=43===YORICK==========================================================================================================
void CDodge::DodgeYORICK(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__YorickSummonDecayed), pBuff.szSpellName))			// W
	{
		// tam thoi ko ne ... chua can thiet lam 
		//DodgeCircle(&pBuff.MaxDestPos, float(YORICK_W_Radius), &pBuff);
	}
}
//=44===LEESIN==========================================================================================================
void CDodge::DodgeLEESIN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__BlindMonkQOne), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=45===LULU==========================================================================================================
void CDodge::DodgeLULU(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__LuluQ), pBuff.szSpellName))			// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=46===YASUO==========================================================================================================
void CDodge::DodgeYASUO(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__YasuoQ3), pBuff.szSpellName))			// Q3
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MousePos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MousePos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MousePos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MousePos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MousePos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MousePos, &pBuff);
		}*/
	}
	//else if (CheckName( (sz__YasuoQ2), pBuff.szSpellName))			// Q2
	//{
	//	EVADE_LINE(&pBuff.SourcePos, &pBuff.MousePos, &pBuff);
	//}
	//else if (CheckName( (sz__YasuoQ), pBuff.szSpellName))			// Q
	//{
	//	EVADE_LINE(&pBuff.SourcePos, &pBuff.MousePos, &pBuff);
	//}
}
//=47===KHAZIX==========================================================================================================
void CDodge::DodgeKHAZIX(KBuffer_Spell pBuff)
{
	//KNpc *pEnemyPlayer = GetEnemyPlayer( (sz__Khazix));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__KhazixWLong), pBuff.szSpellName))			// W
	{
		KPos posNghiem1, posNghiem2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, KHAZIX_W_Range);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
		else
			pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
		
		KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
		TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, 400);

		KNpc *g_pPlayer = GetPlayer();

		float radius = KHAZIX_W_Radius;
		if (g_pPlayer->nOverrideCollisionRadius > 100)
		{
			//radius = 40.;
		}
		if(IsINSIDE_TAMGIAC(&g_pPlayer->CurrentPos, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos)) // player nam trong tam giac source-dest-pos1
		{
			//__oMsg("=== 222 ======================================================");
			float R = (radius + g_pPlayer->nOverrideCollisionRadius);

			float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
			float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
			float C1       = dZ*pBuff.SourcePos.x - dX*pBuff.SourcePos.z;
			float calc1    = sqrt(dZ*dZ + dX*dX);
			//-----------------------------------
			float C4_1 = C1 - R*calc1; 					//(a) : dZ.x - dX.z  = C4_1
			float C4_2 = C1 + R*calc1; 					//(b) : dZ.x - dX.z  = C4_2
			//--------------------------------------------------------------------------------	
			//--------------------------------------------------------------------------------
			float __dX = pos_diem1->x - pBuff.SourcePos.x;
			float __dZ = pos_diem1->z - pBuff.SourcePos.z;
			float __C1       = __dZ*pBuff.SourcePos.x - __dX*pBuff.SourcePos.z;
			float __calc1    = sqrt(__dZ*__dZ + __dX*__dX);
			//-----------------------------------
			float __C4_1 = __C1 - R*__calc1; 					//(c) : __dZ.x - __dX.z  = __C4_1
			float __C4_2 = __C1 + R*__calc1; 					//(d) : __dZ.x - __dX.z  = __C4_2
			//--------------------------------------------------------------------------------
			KPos *Nghiem1 = new KPos, *Nghiem2 = new KPos, *Nghiem3 = new KPos, *Nghiem4 = new KPos, tmpPos, dodgePos;

			int  n1  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_1); //giao diem cua (a) va (c)
			if (!n1)  return;
			Nghiem1->x  = tmpPos.x;
			Nghiem1->z  = tmpPos.z;

			int  n2  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_2); //giao diem cua (a) va (d)
			if (!n2)  return;
			Nghiem2->x  = tmpPos.x;
			Nghiem2->z  = tmpPos.z;

			int  n3  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_1); //giao diem cua (b) va (c)
			if (!n3)  return;
			Nghiem3->x  = tmpPos.x;
			Nghiem3->z  = tmpPos.z;

			int  n4  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_2); //giao diem cua (b) va (d)
			if (!n4)  return;
			Nghiem4->x  = tmpPos.x;
			Nghiem4->z  = tmpPos.z;

			dodgePos.x = 0.;
			dodgePos.z = 0.;
			if(IsINSIDE_TAMGIAC(Nghiem1, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{	
				//__oMsg("a");
				dodgePos.x = Nghiem1->x;
				dodgePos.z = Nghiem1->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem2, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{
				//__oMsg("b");
				dodgePos.x = Nghiem2->x;
				dodgePos.z = Nghiem2->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem3, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{
				//__oMsg("c");
				dodgePos.x = Nghiem3->x;
				dodgePos.z = Nghiem3->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem4, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{
				//__oMsg("d");
				dodgePos.x = Nghiem4->x;
				dodgePos.z = Nghiem4->z;
			}
			//__oMsg("dodgePos->x = %f -------------- dodgePos->z = %f", dodgePos->x, dodgePos->z);
			KPos diemVuongGoc;
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, g_pPlayer->CurrentPos);
			float fDistance1 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, dodgePos);
			float fDistance2 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			//__oMsg("1xxxxxxxxxxx ---- fDistance1 = %f -------------- fDistance2 = %f", fDistance1, fDistance2);
			
			delete Nghiem1, Nghiem2, Nghiem3, Nghiem4;
			if (fDistance1 <= 750)
			{
				UnBlockMove();

				delete pos_diem1, pos_diem2;
				return;
			}
			else
			{
				//__oMsg("=== 222_2 ======================================================");
				DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem1, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem2, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
			}
			delete pos_diem1, pos_diem2;
		}
		else if(IsINSIDE_TAMGIAC(&g_pPlayer->CurrentPos, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos)) // player nam trong tam giac source-dest-pos2
		{
			//__oMsg("=== 333 ======================================================");
			float R = (radius + g_pPlayer->nOverrideCollisionRadius);

			float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
			float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
			float C1       = dZ*pBuff.SourcePos.x - dX*pBuff.SourcePos.z;
			float calc1    = sqrt(dZ*dZ + dX*dX);
			//-----------------------------------
			float C4_1 = C1 - R*calc1; 					//(a) : dZ.x - dX.z  = C4_1
			float C4_2 = C1 + R*calc1; 					//(b) : dZ.x - dX.z  = C4_2
			//--------------------------------------------------------------------------------	
			//--------------------------------------------------------------------------------
			float __dX = pos_diem2->x - pBuff.SourcePos.x;
			float __dZ = pos_diem2->z - pBuff.SourcePos.z;
			float __C1       = __dZ*pBuff.SourcePos.x - __dX*pBuff.SourcePos.z;
			float __calc1    = sqrt(__dZ*__dZ + __dX*__dX);
			//-----------------------------------
			float __C4_1 = __C1 - R*__calc1; 					//(c) : __dZ.x - __dX.z  = __C4_1
			float __C4_2 = __C1 + R*__calc1; 					//(d) : __dZ.x - __dX.z  = __C4_2
			//--------------------------------------------------------------------------------
			KPos *Nghiem1 = new KPos, *Nghiem2 = new KPos, *Nghiem3 = new KPos, *Nghiem4 = new KPos, tmpPos, dodgePos;

			int  n1  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_1); //giao diem cua (a) va (c)
			if (!n1)  return;
			Nghiem1->x  = tmpPos.x;
			Nghiem1->z  = tmpPos.z;

			int  n2  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_2); //giao diem cua (a) va (d)
			if (!n2)  return;
			Nghiem2->x  = tmpPos.x;
			Nghiem2->z  = tmpPos.z;

			int  n3  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_1); //giao diem cua (b) va (c)
			if (!n3)  return;
			Nghiem3->x  = tmpPos.x;
			Nghiem3->z  = tmpPos.z;

			int  n4  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_2); //giao diem cua (b) va (d)
			if (!n4)  return;
			Nghiem4->x  = tmpPos.x;
			Nghiem4->z  = tmpPos.z;

			dodgePos.x = 0.;
			dodgePos.z = 0.;
			if(IsINSIDE_TAMGIAC(Nghiem1, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("a");
				dodgePos.x = Nghiem1->x;
				dodgePos.z = Nghiem1->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem2, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("b");
				dodgePos.x = Nghiem2->x;
				dodgePos.z = Nghiem2->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem3, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("c");
				dodgePos.x = Nghiem3->x;
				dodgePos.z = Nghiem3->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem4, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("d");
				dodgePos.x = Nghiem4->x;
				dodgePos.z = Nghiem4->z;
			}
			//__oMsg("dodgePos->x = %f -------------- dodgePos->z = %f", dodgePos->x, dodgePos->z);
			KPos diemVuongGoc;
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, g_pPlayer->CurrentPos);
			float fDistance1 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, dodgePos);
			float fDistance2 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			//__oMsg("2xxxxxxxxxxx ---- fDistance1 = %f -------------- fDistance2 = %f", fDistance1, fDistance2);

			delete Nghiem1, Nghiem2, Nghiem3, Nghiem4;
			if (fDistance1 <= 750)
			{
				UnBlockMove();
				delete pos_diem1, pos_diem2;
				return;
			}
			else
			{
				//__oMsg("=== 333_2 ======================================================");
				DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem1, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem2, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
			}

			delete pos_diem1, pos_diem2;
		}
		else
		{
			//__oMsg("=== 444 ======================================================");
			DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
			DodgeMissileLine(&pBuff.SourcePos, pos_diem1, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);
			DodgeMissileLine(&pBuff.SourcePos, pos_diem2, float(KHAZIX_W_Radius), float(KHAZIX_W_Range), &pBuff, 350);

			delete pos_diem1, pos_diem2;
		}
	}
	else if (CheckName( (sz__KhazixW), pBuff.szSpellName))			// W
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 150) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__KhazixE), pBuff.szSpellName))			// E
	{
		//DodgeCircle(&pCastSpell->MousePos, float(KHAZIX_E_Radius), &pBuff);
		// KHONG LAY DUOC pCastSpell
	}
}
//=48===TWISTEDFATE==========================================================================================================
void CDodge::DodgeTWISTEDFATE(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__WildCards), pBuff.szSpellName))			// Q
	{
		KPos posNghiem1, posNghiem2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, TWISTEDFATE_Q_Range);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
		else
			pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
		
		KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
		TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, 800);

		/*KPos diemVuongGoc;
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
		fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);*/
		/*//__oMsg("--------------------- distance = %f", fDistance);
		DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff);
		DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem1, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff);
		DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem2, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff);*/
		//================================================================================================================
		//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z		(1)(d: duong thang di qua 2 diem startPoint & endPoint)
		//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z	(2)(vuong goc voi d, di qua vi tri cua nguoi choi)
		//dZ.x - dX.z  = C4   = dZ.dodge_x  - dX.dodge_z 	(4)(song song voi d + di qua diem dodge)
		//==>C4 = C1 - R*calc1
		//==>C4 = C1 + R*calc1
		//===========================================================================================================================
		KNpc *g_pPlayer = GetPlayer();

		float radius = float(TWISTEDFATE_Q_Radius);
		if (g_pPlayer->nOverrideCollisionRadius > 100)
		{
			radius = 10.;
		}
		if(IsINSIDE_TAMGIAC(&g_pPlayer->CurrentPos, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos)) // player nam trong tam giac source-dest-pos1
		{
			//__oMsg("=== 222 ======================================================");
			float R = (radius + g_pPlayer->nOverrideCollisionRadius);

			float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
			float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
			float C1       = dZ*pBuff.SourcePos.x - dX*pBuff.SourcePos.z;
			float calc1    = sqrt(dZ*dZ + dX*dX);
			//-----------------------------------
			float C4_1 = C1 - R*calc1; 					//(a) : dZ.x - dX.z  = C4_1
			float C4_2 = C1 + R*calc1; 					//(b) : dZ.x - dX.z  = C4_2
			//--------------------------------------------------------------------------------	
			//--------------------------------------------------------------------------------
			float __dX = pos_diem1->x - pBuff.SourcePos.x;
			float __dZ = pos_diem1->z - pBuff.SourcePos.z;
			float __C1       = __dZ*pBuff.SourcePos.x - __dX*pBuff.SourcePos.z;
			float __calc1    = sqrt(__dZ*__dZ + __dX*__dX);
			//-----------------------------------
			float __C4_1 = __C1 - R*__calc1; 					//(c) : __dZ.x - __dX.z  = __C4_1
			float __C4_2 = __C1 + R*__calc1; 					//(d) : __dZ.x - __dX.z  = __C4_2
			//--------------------------------------------------------------------------------
			KPos *Nghiem1 = new KPos, *Nghiem2 = new KPos, *Nghiem3 = new KPos, *Nghiem4 = new KPos, tmpPos, dodgePos;

			int  n1  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_1); //giao diem cua (a) va (c)
			if (!n1)  return;
			Nghiem1->x  = tmpPos.x;
			Nghiem1->z  = tmpPos.z;

			int  n2  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_2); //giao diem cua (a) va (d)
			if (!n2)  return;
			Nghiem2->x  = tmpPos.x;
			Nghiem2->z  = tmpPos.z;

			int  n3  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_1); //giao diem cua (b) va (c)
			if (!n3)  return;
			Nghiem3->x  = tmpPos.x;
			Nghiem3->z  = tmpPos.z;

			int  n4  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_2); //giao diem cua (b) va (d)
			if (!n4)  return;
			Nghiem4->x  = tmpPos.x;
			Nghiem4->z  = tmpPos.z;

			dodgePos.x = 0.;
			dodgePos.z = 0.;
			if(IsINSIDE_TAMGIAC(Nghiem1, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{	
				//__oMsg("a");
				dodgePos.x = Nghiem1->x;
				dodgePos.z = Nghiem1->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem2, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{
				//__oMsg("b");
				dodgePos.x = Nghiem2->x;
				dodgePos.z = Nghiem2->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem3, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{
				//__oMsg("c");
				dodgePos.x = Nghiem3->x;
				dodgePos.z = Nghiem3->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem4, &pBuff.SourcePos, pos_diem1, &pBuff.MaxDestPos))
			{
				//__oMsg("d");
				dodgePos.x = Nghiem4->x;
				dodgePos.z = Nghiem4->z;
			}
			//__oMsg("dodgePos->x = %f -------------- dodgePos->z = %f", dodgePos->x, dodgePos->z);
			KPos diemVuongGoc;
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
			float fDistance1 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, dodgePos);
			float fDistance2 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			//__oMsg("fDistance1 = %f -------------- fDistance2 = %f", fDistance1, fDistance2);

			delete Nghiem1, Nghiem2, Nghiem3, Nghiem4;

			if (fDistance1 <= 300)
			{
				UnBlockMove();
				delete pos_diem1, pos_diem2;
				return;
				//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
			}
			//else if(fDistance1 <= 550)
			else if(fDistance1 <= fDistance2)
			{
				//__oMsg("=== 222_1 ======================================================");
				MOVE_TO(dodgePos.x,dodgePos.z);
				if (pBuff.nTimer >= TWISTEDFATE_Q_DelayFlying)
				{
					UnBlockMove();
					RESET_BUFFER_SPELL(pBuff.index);
				}
			}
			else
			{
				//__oMsg("=== 222_2 ======================================================");
				DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem1, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem2, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
			}

			delete pos_diem1, pos_diem2;
		}
		else if(IsINSIDE_TAMGIAC(&g_pPlayer->CurrentPos, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos)) // player nam trong tam giac source-dest-pos2
		{
			//__oMsg("=== 333 ======================================================");
			float R = (radius + g_pPlayer->nOverrideCollisionRadius);

			float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
			float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
			float C1       = dZ*pBuff.SourcePos.x - dX*pBuff.SourcePos.z;
			float calc1    = sqrt(dZ*dZ + dX*dX);
			//-----------------------------------
			float C4_1 = C1 - R*calc1; 					//(a) : dZ.x - dX.z  = C4_1
			float C4_2 = C1 + R*calc1; 					//(b) : dZ.x - dX.z  = C4_2
			//--------------------------------------------------------------------------------	
			//--------------------------------------------------------------------------------
			float __dX = pos_diem2->x - pBuff.SourcePos.x;
			float __dZ = pos_diem2->z - pBuff.SourcePos.z;
			float __C1       = __dZ*pBuff.SourcePos.x - __dX*pBuff.SourcePos.z;
			float __calc1    = sqrt(__dZ*__dZ + __dX*__dX);
			//-----------------------------------
			float __C4_1 = __C1 - R*__calc1; 					//(c) : __dZ.x - __dX.z  = __C4_1
			float __C4_2 = __C1 + R*__calc1; 					//(d) : __dZ.x - __dX.z  = __C4_2
			//--------------------------------------------------------------------------------
			KPos *Nghiem1 = new KPos, *Nghiem2 = new KPos, *Nghiem3 = new KPos, *Nghiem4 = new KPos, tmpPos, dodgePos;

			int  n1  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_1); //giao diem cua (a) va (c)
			if (!n1)  return;
			Nghiem1->x  = tmpPos.x;
			Nghiem1->z  = tmpPos.z;

			int  n2  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_1, __dZ, -__dX, __C4_2); //giao diem cua (a) va (d)
			if (!n2)  return;
			Nghiem2->x  = tmpPos.x;
			Nghiem2->z  = tmpPos.z;

			int  n3  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_1); //giao diem cua (b) va (c)
			if (!n3)  return;
			Nghiem3->x  = tmpPos.x;
			Nghiem3->z  = tmpPos.z;

			int  n4  = NghiemHePTBacNhat(tmpPos,dZ, -dX, C4_2, __dZ, -__dX, __C4_2); //giao diem cua (b) va (d)
			if (!n4)  return;
			Nghiem4->x  = tmpPos.x;
			Nghiem4->z  = tmpPos.z;

			dodgePos.x = 0.;
			dodgePos.z = 0.;
			if(IsINSIDE_TAMGIAC(Nghiem1, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("a");
				dodgePos.x = Nghiem1->x;
				dodgePos.z = Nghiem1->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem2, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("b");
				dodgePos.x = Nghiem2->x;
				dodgePos.z = Nghiem2->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem3, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("c");
				dodgePos.x = Nghiem3->x;
				dodgePos.z = Nghiem3->z;
			}
			if(IsINSIDE_TAMGIAC(Nghiem4, &pBuff.SourcePos, pos_diem2, &pBuff.MaxDestPos))
			{
				//__oMsg("d");
				dodgePos.x = Nghiem4->x;
				dodgePos.z = Nghiem4->z;
			}
			//__oMsg("dodgePos->x = %f -------------- dodgePos->z = %f", dodgePos->x, dodgePos->z);
			KPos diemVuongGoc;
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
			float fDistance1 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, dodgePos);
			float fDistance2 = Distance_2D(diemVuongGoc, pBuff.SourcePos);
			//__oMsg("fDistance1 = %f -------------- fDistance2 = %f", fDistance1, fDistance2);

			delete Nghiem1, Nghiem2, Nghiem3, Nghiem4;

			if (fDistance1 <= 300)
			{
				UnBlockMove();
				delete pos_diem1, pos_diem2;
				return;
				//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
			}
			//else if(fDistance1 <= 550)
			else if(fDistance1 <= fDistance2)
			{
				//__oMsg("=== 333_1 ======================================================");
				MOVE_TO(dodgePos.x,dodgePos.z);
				if (pBuff.nTimer >= TWISTEDFATE_Q_DelayFlying)
				{
					UnBlockMove();
					RESET_BUFFER_SPELL(pBuff.index);
				}
			}
			else
			{
				//__oMsg("=== 333_2 ======================================================");
				DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem1, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
				DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem2, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
			}

			delete pos_diem1, pos_diem2;
		}
		else
		{
			//__oMsg("=== 444 ======================================================");
			DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
			DodgeMissileLine(&pBuff.SourcePos, pos_diem1, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);
			DodgeMissileLine(&pBuff.SourcePos, pos_diem2, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff, TWISTEDFATE_Q_DelayFlying);

			delete pos_diem1, pos_diem2;

		}
	}
}
//=49===THRESH==========================================================================================================
void CDodge::DodgeTHRESH(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ThreshQInternal), pBuff.szSpellName))			// Q
	{
		//-- ne o auto_dodge_2
	}
	else if (CheckName( (sz__ThreshE), pBuff.szSpellName))			// E
	{
		int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}
	}
}
//=50===SORAKA==========================================================================================================
void CDodge::DodgeSORAKA(KBuffer_Spell pBuff)
{
	KNpc* pPlayer = GetPlayer();
	if(pPlayer && pPlayer->nAttackRange <=350.0)
	{
		float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
		if(KhoangCach <= 350.0)
		{
			UnBlockMove();
			return;
		}
	}
	if (CheckName( (sz__SorakaQ), pBuff.szSpellName))			// Q
	{
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__SorakaE), pBuff.szSpellName))			// E
	{
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=51===ASHE==========================================================================================================
void CDodge::DodgeASHE(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__Volley), pBuff.szSpellName))			// W
	{
		//KNpc* pEnemyPlayer = GetEnemyPlayer( (sz__Ashe));
		//PrintCastSpell(pEnemyPlayer);
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(ASHE_W_RadiusCone),ASHE_W_RadiusLine, float(ASHE_W_Range), &pBuff);
	}
	if (CheckName( (sz__EnchantedCrystalArrow), pBuff.szSpellName))			// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	/*	int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui, RESET_BUFFER_SPELL, true);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL, true);
		}*/
	}
}
//=52===SONA==========================================================================================================
void CDodge::DodgeSONA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__SonaR), pBuff.szSpellName))			// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=53===FIZZ==========================================================================================================
void CDodge::DodgeFIZZ(KBuffer_Spell pBuff)
{
	KNpc *pPlayer = GetPlayer();
	if (CheckName( (sz__FizzR), pBuff.szSpellName))			// R
	{
		float fDistance = Distance_2D(pPlayer->CurrentPos, pBuff.MaxDestPos);
		//if (fDistance >= 350.)
		//{
		//	DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(FIZZ_R_Radius_Line), float(FIZZ_R_Range), &pBuff);
		//}
		//else
		//{
		//	DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(FIZZ_R_Radius_Circle), float(FIZZ_R_Range), &pBuff);
		//}
		float nRange = Distance_2D(pBuff.SourcePos, pBuff.MaxDestPos);
		if (nRange < pBuff.nRange)
		{
			pBuff.nRange = nRange;
		}
		if(nRange < 455.0)
		{
			if (fDistance >= 200.)
			{
				int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
				if (nTienLui != 0)
				{
					if (nTienLui == -1)
					{
						EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
						{
							EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
						} 
						else
						{
							EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
						}
					}
				} 
				else
				{
			
					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				}
			}
			else
			{
				DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, 120.0, FIZZ_R_Range, &pBuff);
			}
		}
		else if(nRange < 910.0)
		{
			if (fDistance >= 320.)
			{
				int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
				if (nTienLui != 0)
				{
					if (nTienLui == -1)
					{
						EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
						{
							EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
						} 
						else
						{
							EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
						}
					}
				} 
				else
				{

					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				}
			}
			else
			{
				DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, 200.0, FIZZ_R_Range, &pBuff);
			}
		}
		else
		{
			if (fDistance >= 450.)
			{
				int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
				if (nTienLui != 0)
				{
					if (nTienLui == -1)
					{
						EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
					} 
					else
					{
						if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
						{
							EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
						} 
						else
						{
							EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
						}
					}
				} 
				else
				{

					EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
				}
			}
			else
			{
				DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, 300.0, FIZZ_R_Range, &pBuff);
			}
		}
	}
}
//=54===ZED==========================================================================================================
void CDodge::DodgeZED(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ZedQ), pBuff.szSpellName))			// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=55===JHIN==========================================================================================================
void CDodge::DodgeJHIN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__JhinW), pBuff.szSpellName))			// W
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__JhinE), pBuff.szSpellName))			// E
	{
		// KHONG NGUY HIEM, KO CAN THIET
		//DodgeCircle(&pBuff.MaxDestPos, float(JHIN_E_Radius),&pBuff);
	}
	else if (CheckName( (sz__JhinR), pBuff.szSpellName))			// R
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(JHIN_R_Radius), float(JHIN_R_Range), &pBuff);
	}
}
//=56===XERATH==========================================================================================================
void CDodge::DodgeXERATH(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__XerathArcanopulseChargeUp), pBuff.szSpellName))					// Q
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(XERATH_Q_Radius), float(XERATH_Q_Range), &pBuff);
		// CHI NE DUOC LUC CHUAN BI XUAT CHIEU - LUC GIUONG CUNG
		EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__XerathArcaneBarrage2), pBuff.szSpellName))			// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__XerathMageSpear), pBuff.szSpellName))				// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__XerathLocusOfPower2), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(XERATH_R_Radius), &pBuff);
		// CHI NE DUOC LUC CHUAN BI XUAT CHIEU - LUC GIUONG CUNG
	}
}
//=57===MALZAHAR==========================================================================================================
void CDodge::DodgeMALZAHAR(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__MalzaharQ), pBuff.szSpellName))			// Q
	{
		KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
		TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, MALZAHAR_Q_Range2);
		//EVADE_LINE(&pBuff.MaxDestPos, pos_diem1, &pBuff);
		DODGE_LINE_NEW(&pBuff.MaxDestPos, pos_diem1, &pBuff);

		delete pos_diem1, pos_diem2;
	}
}
//=58===QUINN==========================================================================================================
void CDodge::DodgeQUINN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__QuinnQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 180.0) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=59===ANIVIA==========================================================================================================
void CDodge::DodgeANIVIA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__FlashFrost), pBuff.szSpellName))			// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__GlacialStorm), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(ANIVIA_R_Radius), &pBuff);
		// KHONG LAY DUOC pCastSpell
	}
}
//=60===ZYRA==========================================================================================================
void CDodge::DodgeZYRA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ZyraQ), pBuff.szSpellName))			// Q
	{
		KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
		TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, ZYRA_Q_Range);
		//DodgeMissileLine(&pBuff.MaxDestPos, pos_diem1, float(ZYRA_Q_Radius), float(ZYRA_Q_Range), &pBuff, ZYRA_Q_DelayFlying, false);
		//EVADE_LINE(&pBuff.MaxDestPos, pos_diem1, &pBuff);
		DODGE_LINE_NEW(&pBuff.MaxDestPos, pos_diem1, &pBuff);
		delete pos_diem1, pos_diem2;

	}
	else if (CheckName( (sz__ZyraE), pBuff.szSpellName))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__ZyraR), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(ZYRA_R_Radius), &pBuff, float(ZYRA_R_DelayFlying));
	}
}
//=61===ELISE==========================================================================================================
void CDodge::DodgeELISE(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__EliseHumanW), pBuff.szSpellName))			// W
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(ELISE_W_Radius), float(ELISE_W_Range), &pBuff);
	}
	else if (CheckName( (sz__EliseHumanE), pBuff.szSpellName))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=62===EVELYNN==========================================================================================================
void CDodge::DodgeEVELYNN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__EvelynnR), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(EVELYNN_R_Radius), &pBuff);
	}
}
//=63===DIANA==========================================================================================================
void CDodge::DodgeDIANA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__DianaArc), pBuff.szSpellName))			// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer && pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		KPos posNghiem1, posNghiem2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, DIANA_Q_Range);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			EVADE_CIRCLE(&posNghiem1, &pBuff);
		else
			EVADE_CIRCLE(&posNghiem2, &pBuff);

	}
}
//=64===KENNEN==========================================================================================================KennenShurikenHurlMissile1
void CDodge::DodgeKENNEN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__KennenShurikenHurlMissile1), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=65===POPPY==========================================================================================================
void CDodge::DodgePOPPY(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__PoppyQSpell), pBuff.szSpellName))			// Q
	{
		/*KPos *posNghiem1 = new KPos, *posNghiem2 = new KPos;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, &pBuff.SourcePos, &pBuff.MaxDestPos, 430.);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1->x + dZ*posNghiem1->z  - C2);
		if (tichVoHuong >= 0)
		{
		//__oMsg("Nghiem 1 = (%f, %f)", posNghiem1->x, posNghiem1->z);
		DodgeMissileLine(&pBuff.SourcePos, posNghiem1, float(POPPY_Q_Radius), float(POPPY_Q_Range), &pBuff);
		}
		else
		{
		//__oMsg("Nghiem 2 = %f, %f)", posNghiem2->x, posNghiem2->z);
		DodgeMissileLine(&pBuff.SourcePos, posNghiem2, float(POPPY_Q_Radius), float(POPPY_Q_Range), &pBuff);
		}*/
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(POPPY_Q_Radius), float(POPPY_Q_Range), &pBuff);
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_LINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__PoppyR), pBuff.szSpellName))			// R
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(POPPY_R_Radius), float(POPPY_R_Range), &pBuff);
	}
}
//=66===LEBLANC==========================================================================================================
void CDodge::DodgeLEBLANC(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__LeblancSlide), pBuff.szSpellName))			// W
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(LEBLANC_W_Radius), &pBuff);
	}
	if (CheckName("LeblancE", pBuff.szSpellName)/* || CheckName("LeblancRE", pBuff.szSpellName)*/)			// E va R-E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=67===BARD==========================================================================================================
void CDodge::DodgeBARD(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__BardQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 2)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	if (CheckName( (sz__BardR), pBuff.szSpellName))			// R
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff); // SKILL RAT DE NE, QTRONG LA CO MUON NE HAY KO
	}
}
//=68===ZILEAN==========================================================================================================
void CDodge::DodgeZILEAN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ZileanQ), pBuff.szSpellName))			// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=69===LISSANDRA==========================================================================================================
void CDodge::DodgeLISSANDRA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__LissandraQ), pBuff.szSpellName))			// Q
	{
		/*KPos *posNghiem1 = new KPos, *posNghiem2 = new KPos;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, &pBuff.SourcePos, &pBuff.MaxDestPos, 1000.);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1->x + dZ*posNghiem1->z  - C2);
		if (tichVoHuong >= 0)
		{
		DodgeMissileLine(&pBuff.SourcePos, posNghiem1, float(LISSANDRA_Q_Radius), float(LISSANDRA_Q_Range), &pBuff);
		}
		else
		{
		DodgeMissileLine(&pBuff.SourcePos, posNghiem2, float(LISSANDRA_Q_Radius), float(LISSANDRA_Q_Range), &pBuff);
		}*/
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(LISSANDRA_Q_Radius), float(LISSANDRA_Q_Range), &pBuff);
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			pBuff.nRange = 1000;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__LissandraE), pBuff.szSpellName))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=70===SWAIN==========================================================================================================
void CDodge::DodgeSWAIN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__SwainShadowGrasp), pBuff.szSpellName))			// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 300.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=71===AURELION SOL==========================================================================================================
void CDodge::DodgeAURELIONSOL(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__AurelionSolQ), pBuff.szSpellName))			// Q
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(AURELIONSOL_Q_Radius), float(AURELIONSOL_Q_Range), &pBuff);
	}
	else if (CheckName( (sz__AurelionSolR), pBuff.szSpellName))			// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=72===TWITCH==========================================================================================================
void CDodge::DodgeTWITCH(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__TwitchVenomCask), pBuff.szSpellName))			// W
	{
		// KHONG NGUY HIEM, KO CAN THIET
		//DodgeCircle(&pBuff.MaxDestPos, float(TWITCH_W_Radius), &pBuff);
	}
}
//=73===GNAR==========================================================================================================
void CDodge::DodgeGNAR(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__GnarQMissile), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 280) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__GnarBigQMissile), pBuff.szSpellName))			// Q BIG
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 220) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__GnarBigW), pBuff.szSpellName))			// W BIG
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(GNAR_WBig_Radius), float(GNAR_WBig_Range), &pBuff);
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__GnarR), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.SourcePos, float(GNAR_R_Radius), &pBuff);
		// XUAT CHIEU QUA NHANH, NEN DUNG TOC BIEN
	}
}
//=74===KOGMAW==========================================================================================================
void CDodge::DodgeKOGMAW(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__KogMawQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__KogMawVoidOozeMissile), pBuff.szSpellName))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__KogMawLivingArtillery), pBuff.szSpellName))			// R
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=75===SINGED==========================================================================================================
void CDodge::DodgeSINGED(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__MegaAdhesive), pBuff.szSpellName))			// W
	{
		// KHONG NGUY HIEM, KO CAN THIET
		//DodgeCircle(&pBuff.MaxDestPos, float(SINGED_W_Radius), &pBuff);
	}
}
//=76===CASSIOPEIA==========================================================================================================
void CDodge::DodgeCASSIOPEIA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__CassiopeiaQ), pBuff.szSpellName))			// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__CassiopeiaW), pBuff.szSpellName))			// W
	{
		KPos posNghiem1, posNghiem2;
		KPos MaxDest1, MaxDest2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, CASSIOPEIA_W_RangeCircle1);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			MaxDest1.x = posNghiem1.x, MaxDest1.z = posNghiem1.z;
		else
			MaxDest1.x = posNghiem2.x, MaxDest1.z = posNghiem2.z;

		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, CASSIOPEIA_W_RangeCircle2);
		dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			MaxDest2.x = posNghiem1.x, MaxDest2.z = posNghiem1.z;
		else
			MaxDest2.x = posNghiem2.x, MaxDest2.z = posNghiem2.z;
		float fDistance = Distance_2D(pBuff.SourcePos.x, pBuff.SourcePos.z, pBuff.MaxDestPos.x, pBuff.MaxDestPos.z);

		if (fDistance < CASSIOPEIA_W_RangeCircle1)
		{
			KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
			TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, &MaxDest1, &pBuff.SourcePos, CASSIOPEIA_W_RangeLine);
			//DodgeMissileLine(&MaxDest1, pos_diem1, float(CASSIOPEIA_W_RadiusLine), float(CASSIOPEIA_W_RangeLine), &pBuff, CASSIOPEIA_W_DelayFlying, false);
			DODGE_LINE_NEW(&MaxDest1, pos_diem1, &pBuff);
			delete pos_diem1, pos_diem2;
		}
		else if (fDistance > CASSIOPEIA_W_RangeCircle2)
		{
			KPos pos_diem1, pos_diem2;
			TIM_2DIEM_CACH_1DIEM(&pos_diem1, &pos_diem2, &MaxDest2, &pBuff.SourcePos, CASSIOPEIA_W_RangeLine);
			//DodgeMissileLine(&MaxDest2, &pos_diem1, float(CASSIOPEIA_W_RadiusLine), float(CASSIOPEIA_W_RangeLine), &pBuff, CASSIOPEIA_W_DelayFlying, false);
			DODGE_LINE_NEW(&MaxDest2, &pos_diem1, &pBuff);
		}
		else
		{
			KPos pos_diem1, pos_diem2;
			TIM_2DIEM_CACH_1DIEM(&pos_diem1, &pos_diem2, &pBuff.MaxDestPos, &pBuff.SourcePos, CASSIOPEIA_W_RangeLine);
			//DodgeMissileLine(&pBuff.MaxDestPos, &pos_diem1, float(CASSIOPEIA_W_RadiusLine), float(CASSIOPEIA_W_RangeLine), &pBuff, CASSIOPEIA_W_DelayFlying, false);
			DODGE_LINE_NEW(&pBuff.MaxDestPos, &pos_diem1, &pBuff);
		}
	}
	else if (CheckName( (sz__CassiopeiaR), pBuff.szSpellName))			// R
	{
		//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Cassiopeia));
		//PrintCastSpell(pEnemyPlayer);
		DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(CASSIOPEIA_R_RadiusCone),CASSIOPEIA_R_RadiusLine, float(CASSIOPEIA_R_Range), &pBuff, CASSIOPEIA_R_DelayFlying);
		// HINH NON
	}
}
//=77===HEIMERDINGER==========================================================================================================
void CDodge::DodgeHEIMERDINGER(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Heimerdinger));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__HeimerdingerW), pBuff.szSpellName))			// W
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__HeimerdingerEUlt), pBuff.szSpellName))			// R->E
	{
		float fDistance = Distance_2D(pBuff.MaxDestPos, pBuff.SourcePos);
		if (fDistance > HEIMERDINGER_E_Range)
		{
			//__oMsg("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			KPos posNghiem1, posNghiem2;
			TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, HEIMERDINGER_E_Range);
			float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
			float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
			float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
			float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
			if (tichVoHuong >= 0)
			{
				pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
				//__oMsg("new max dest1 = (%f, %f)", posNghiem1->x, posNghiem1->z);
			}
			else
			{
				pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
				//__oMsg("new max dest2 = (%f, %f)", posNghiem2->x, posNghiem2->z);
			}

		}

		KPos posNghiem1, posNghiem2, New_MaxDest;
		//-----------------------------------------------------------------
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.MaxDestPos, pBuff.SourcePos, 350.);
		float dX = pBuff.SourcePos.x - pBuff.MaxDestPos.x;
		float dZ = pBuff.SourcePos.z - pBuff.MaxDestPos.z;
		float C2 = dX * pBuff.MaxDestPos.x + dZ * pBuff.MaxDestPos.z; // duong thang vuong goc voi (1) va di qua MaxDestPos
		float tichVoHuong = (dX*pBuff.SourcePos.x + dZ*pBuff.SourcePos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			New_MaxDest.x = posNghiem1.x, New_MaxDest.z = posNghiem1.z;
		else
			New_MaxDest.x = posNghiem2.x, New_MaxDest.z = posNghiem2.z;
		//-----------------------------------------------------------------
		//dZ.x - dX.z  = C1   = dZ*pos1.x - dX*pos1.z  (1)(d)(di qua pos1, pos2)
		//dX.x + dZ.z  = C3  = dX*player_x + dZ*player_z (2)(vuong goc voi d va di qua player
		KNpc *g_pPlayer = GetPlayer();
		float player_x = g_pPlayer->CurrentPos.x;
		float player_z = g_pPlayer->CurrentPos.z;

		dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;

		float C1  = dZ*pBuff.SourcePos.x - dX*pBuff.SourcePos.z;
		float C3  = dX*player_x + dZ*player_z;

		//-----------------------------------
		KPos tmpPos0;
		int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C3);
		if (!Nghiem_0)  return;
		float vuonggoc_x  =  tmpPos0.x;
		float vuonggoc_z  =  tmpPos0.z;
		//------------------
		fDistance = Distance_2D(pBuff.MaxDestPos.x, pBuff.MaxDestPos.z, posNghiem1.x, posNghiem1.z);
		//__oMsg("posNghiem1-->distance: %f", fDistance);
		fDistance = Distance_2D(pBuff.MaxDestPos.x, pBuff.MaxDestPos.z, posNghiem2.x, posNghiem2.z);
		//__oMsg("posNghiem2-->distance: %f", fDistance);

		fDistance = Distance_2D(pBuff.MaxDestPos.x, pBuff.MaxDestPos.z,New_MaxDest.x, New_MaxDest.z);
		//__oMsg("new - maxdest, distance: %f", fDistance);
		float fDist_1 = Distance_2D(vuonggoc_x, vuonggoc_z, pBuff.MaxDestPos.x, pBuff.MaxDestPos.z);
		//__oMsg("vuonggoc-->distance: %f", fDist_1);
		float fDist_2 = Distance_2D(vuonggoc_x, vuonggoc_z, posNghiem1.x, posNghiem1.z);
		//__oMsg("vuonggoc-->posNghiem1: %f", fDist_2);
		float fDist_3 = Distance_2D(vuonggoc_x, vuonggoc_z, posNghiem2.x, posNghiem2.z);
		//__oMsg("vuonggoc-->posNghiem2: %f", fDist_3);
		//-----------------------------------------------------------------
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, New_MaxDest, pBuff.SourcePos, HEIMERDINGER_RE_Range);
		dX = pBuff.SourcePos.x - New_MaxDest.x;
		dZ = pBuff.SourcePos.z - New_MaxDest.z;
		C2 = dX * pBuff.MaxDestPos.x + dZ * pBuff.MaxDestPos.z; // duong thang vuong goc voi (1) va di qua MaxDestPos
		tichVoHuong = (dX*pBuff.SourcePos.x + dZ*pBuff.SourcePos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			DodgeMissileLine(&New_MaxDest, &posNghiem2, float(HEIMERDINGER_RE_Radius), HEIMERDINGER_RE_Range, &pBuff);
		else
			DodgeMissileLine(&New_MaxDest, &posNghiem1, float(HEIMERDINGER_RE_Radius), HEIMERDINGER_RE_Range, &pBuff);

	}
	else if (CheckName( (sz__HeimerdingerE), pBuff.szSpellName))			// E
	{
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=78===ILLAOI==========================================================================================================
void CDodge::DodgeILLAOI(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__IllaoiQ), pBuff.szSpellName))			// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__IllaoiE), pBuff.szSpellName))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__IllaoiR), pBuff.szSpellName))			// R
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		DodgeCircle(&pBuff.SourcePos, float(ILLAOI_R_Radius), &pBuff, 450.0);
	}
}
//=79===LEONA==========================================================================================================
void CDodge::DodgeLEONA(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__LeonaZenithBlade), pBuff.szSpellName))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__LeonaSolarFlare), pBuff.szSpellName))			// R
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=80===JAYCE==========================================================================================================
void CDodge::DodgeJAYCE(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__JayceShockBlast), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 200.0) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=81===KASSADIN==========================================================================================================
void CDodge::DodgeKASSADIN(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Kassadin));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__ForcePulse), pBuff.szSpellName))			// E
	{
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(KASSADIN_E_RadiusCone),KASSADIN_E_RadiusLine, float(KASSADIN_E_Range), &pBuff, KASSADIN_E_DelayFlying);
		// HINH NON
	}
	if (CheckName( (sz__RiftWalk), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(KASSADIN_R_Radius), &pBuff);
	}
}
//=82===SHEN==========================================================================================================
void CDodge::DodgeSHEN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ShenE), pBuff.szSpellName))			// E
	{
		//CHUA LAM DUOC
	}
}
//=83===VIKTOR==========================================================================================================
void CDodge::DodgeVIKTOR(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ViktorGravitonField), pBuff.szSpellName))			// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__ViktorDeathRay), pBuff.szSpellName))			// E
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, float(VIKTOR_E_Radius), float(VIKTOR_E_Range), &pBuff);
		// CHUA LAM DUOC KO LAY DUOC pCastSpell, cach cast kha phuc tap
	}
	else if (CheckName( (sz__ViktorChaosStorm), pBuff.szSpellName))			// R
	{
		//EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=84===GANGPLANK==========================================================================================================
void CDodge::DodgeGANGPLANK(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__GangplankR), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(GANGPLANK_R_Radius), &pBuff);
	}
}
//=85===NAMI==========================================================================================================
void CDodge::DodgeNAMI(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__NamiQ), pBuff.szSpellName))			// Q
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 300.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__NamiR), pBuff.szSpellName))			// R
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=86===PHANTHEON==========================================================================================================
void CDodge::DodgePHANTHEON(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Pantheon));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__PantheonE), pBuff.szSpellName))			// E
	{
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(PHANTHEON_E_RadiusCone),PHANTHEON_E_RadiusLine, float(PHANTHEON_E_Range), &pBuff, PHANTHEON_E_DelayFlying);
		// HINH NON
	}
	if (CheckName( (sz__PantheonRJump), pBuff.szSpellName))			// R
	{
		DodgeCircle(&pBuff.MaxDestPos, float(PHANTHEON_R_Radius), &pBuff, PHANTHEON_R_DelayFlyingJump);
	}
	else if (CheckName( (sz__PantheonRFall), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(PHANTHEON_R_Radius), &pBuff, PHANTHEON_R_DelayFlyingFall);
	}
}
//=87===MAOKAI==========================================================================================================
void CDodge::DodgeMAOKAI(KBuffer_Spell pBuff)
{
	//if (CheckName( (sz__MaokaiTrunkLine), pBuff.szSpellName))	// Q
	if (CheckName( (sz__MaokaiQ), pBuff.szSpellName))			// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=88===RENGAR==========================================================================================================
void CDodge::DodgeRENGAR(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__RengarE), pBuff.szSpellName))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=89===REKSAI==========================================================================================================
void CDodge::DodgeREKSAI(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__RekSaiQBurrowed), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=90===SKARNER==========================================================================================================
void CDodge::DodgeSKARNER(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__SkarnerFracture), pBuff.szSpellName))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=91===TARIC==========================================================================================================
void CDodge::DodgeTARIC(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Taric));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__TaricE), pBuff.szSpellName))			// E
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, TARIC_E_Radius, TARIC_E_Range, &pBuff);
		// KHONG LAY DUOC pCastSpell
	}
}
//=92===VI==========================================================================================================
void CDodge::DodgeVI(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ViQ), pBuff.szSpellName))			// Q
	{
		DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, VI_Q_Radius, VI_Q_Range, &pBuff);
		// CHI LAY DUOC LUC GIUONG CUNG
	}
}
//=93===TEEMO==========================================================================================================
void CDodge::DodgeTEEMO(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__TeemoRCast), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(TEEMO_R_Radius), &pBuff);
	}
}
//=94===URGOT==========================================================================================================
void CDodge::DodgeURGOT(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__UrgotHeatseekingMissile), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}
	}
	else if (CheckName( (sz__UrgotPlasmaGrenade), pBuff.szSpellName))			// E
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//=95===ORIANNA==========================================================================================================
void CDodge::DodgeORIANNA(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Orianna));
	//PrintCastSpell(pEnemyPlayer);
	// CAC SKILL DEU LIEN QUAN DEN QUA CAU TheDoomBall, chua xac dinh duoc
}
//=96===RUMBLE==========================================================================================================
void CDodge::DodgeRUMBLE(KBuffer_Spell pBuff)
{
	/*KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Rumble));
	PrintCastSpell(pEnemyPlayer);*/
	if (CheckName( (sz__RumbleGrenade), pBuff.szSpellName))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__RumbleCarpetBombDummy), pBuff.szSpellName))			// R
	{
		KPos posNghiem1, posNghiem2;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.MaxDestPos, pBuff.MousePos, RUMBLE_R_Range);
		float dX = pBuff.MaxDestPos.x - pBuff.MousePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.MousePos.z;
		float C2 = dX * pBuff.MaxDestPos.x + dZ * pBuff.MaxDestPos.z;
		float tichVoHuong = (dX*pBuff.MousePos.x + dZ*pBuff.MousePos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			DodgeMissileLine(&pBuff.MaxDestPos, &posNghiem2, RUMBLE_R_Radius, RUMBLE_R_Range, &pBuff, 350.0);
		else
			DodgeMissileLine(&pBuff.MaxDestPos, &posNghiem1, RUMBLE_R_Radius, RUMBLE_R_Range, &pBuff, 350.0);
	}
}
//=97===SHYVANA==========================================================================================================
void CDodge::DodgeSHYVANA(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Shyvana));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName(pBuff.szSpellName,  (sz__ShyvanaFireball)))			// E
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName(pBuff.szSpellName,  (sz__ShyvanaFireballDragon2)))			// E2
	{
		float nRange = Distance_2D(pBuff.SourcePos, pBuff.MaxDestPos);
		if (nRange < pBuff.nRange)
		{
			pBuff.nRange = nRange + 175;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		//if (nTienLui != 0)
		//{
		//	if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
		//	{
		//		EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//	} 
		//	else
		//	{
		//		EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
		//	}
		//} 
		//else
		//{
		//	EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//}
	}
	else if (CheckName( (sz__ShyvanaTransformLeap), pBuff.szSpellName))			// R
	{
		float nRange = Distance_2D(pBuff.SourcePos, pBuff.MaxDestPos);
		if (nRange < pBuff.nRange)
		{
			pBuff.nRange = nRange;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}
//=98===SION==========================================================================================================
void CDodge::DodgeSION(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Sion));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__SionQ), pBuff.szSpellName))			// Q
	{
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		////DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, SION_Q_Radius, SION_Q_Range, &pBuff, SION_Q_DelayFlying);
		//int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		//if (nTienLui != 0)
		//{
		//	if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
		//	{
		//		EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//	} 
		//	else
		//	{
		//		EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
		//	}
		//} 
		//else
		//{
		//	EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		//}
	}
	else if (CheckName( (sz__SionE), pBuff.szSpellName))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			pBuff.nRange = 1275;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	else if (CheckName( (sz__SionR), pBuff.szSpellName))			// R
	{
		//DodgeMissileLine(&pBuff.SourcePos, &pBuff.MaxDestPos, SION_R_Radius, SION_R_Range, &pBuff);
	}
}
//=99===SYNDRA==========================================================================================================
void CDodge::DodgeSYNDRA(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Syndra));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__SyndraQ), pBuff.szSpellName))			// Q
	{
		//DodgeCircle(&pBuff.MaxDestPos, SYNDRA_Q_Radius, &pBuff);
		// KHONG LAY DUOC pCastSpell
	}
	else if (CheckName( (sz__SyndraW), pBuff.szSpellName))			// W
	{
		//DodgeCircle(&pBuff.MaxDestPos, SYNDRA_W_Radius, &pBuff);
		// KHONG LAY DUOC pCastSpell
	}
	else if (CheckName(pBuff.szSpellName, sz__SyndraE))			// E
	{
		KPos posNghiem1, posNghiem2, real_endPoint;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, 800);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			real_endPoint.x = posNghiem1.x, real_endPoint.z = posNghiem1.z;     // chuyen diem endPoint ve dung vi tri cua no
		else
			real_endPoint.x = posNghiem2.x, real_endPoint.z = posNghiem2.z;

		KPos pos_diem1, pos_diem2, syphere_In;
		TIM_2DIEM_CACH_1DIEM(&pos_diem1, &pos_diem2, &real_endPoint, &pBuff.SourcePos, 210);  // 2 diem day cua hinh non, radius la k/c tu endPoint den pos1 hoac pos2
		
		//---get cau nam trong tam giac --------------
		DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
		DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
		DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
		DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
		DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
		if(dw1 && dw2)
		{
			int nCount = (dw2 - dw1)/4;
			KNpc *pPlayer = GetPlayer();
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*i);
				if (dw3 == 0) continue;
				KNpc *pSyndra_Sphere = (KNpc*)dw3;
				int isDie = IS_DEAD(pSyndra_Sphere) == true ? 1 : 0;
				if (pSyndra_Sphere->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pSyndra_Sphere->nHP <= 0)
					continue;
				if ((BYTE)pSyndra_Sphere->nIsTargetableToTeam == 4) continue;
				if (CheckName( (sz__Seed), pSyndra_Sphere->GetNameNpc()) == false) continue;
				if (CheckName( (sz__SyndraSphere), pSyndra_Sphere->GetNameHero()) == false) continue;
                if(IsINSIDE_TAMGIAC(&pSyndra_Sphere->CurrentPos, &pBuff.SourcePos, &pos_diem1, &pos_diem2))
				{
					syphere_In.x = pSyndra_Sphere->CurrentPos.x, syphere_In.z = pSyndra_Sphere->CurrentPos.z; 
				}
			}
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &syphere_In, &pBuff);
	}
	else if (CheckName("SyndraE5", pBuff.szSpellName))			// E5-emax
	{ 
		KPos posNghiem1, posNghiem2, real_endPoint;
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, 800);
		float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
		float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
		float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			real_endPoint.x = posNghiem1.x, real_endPoint.z = posNghiem1.z;     // chuyen diem endPoint ve dung vi tri cua no
		else
			real_endPoint.x = posNghiem2.x, real_endPoint.z = posNghiem2.z;

		KPos pos_diem1, pos_diem2, syphere_In;
		TIM_2DIEM_CACH_1DIEM(&pos_diem1, &pos_diem2, &real_endPoint, &pBuff.SourcePos, 450);  // 2 diem day cua hinh non, radius la k/c tu endPoint den pos1 hoac pos2

		//---get cau nam trong tam giac --------------
		DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
		DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
		DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
		DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
		DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
		if(dw1 && dw2)
		{
			int nCount = (dw2 - dw1)/4;
			KNpc *pPlayer = GetPlayer();
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*i);
				if (dw3 == 0) continue;
				KNpc *pSyndra_Sphere = (KNpc*)dw3;
				int isDie = IS_DEAD(pSyndra_Sphere) == true ? 1 : 0;
				if (pSyndra_Sphere->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pSyndra_Sphere->nHP <= 0)
					continue;
				if ((BYTE)pSyndra_Sphere->nIsTargetableToTeam == 4) continue;
				if (CheckName( (sz__Seed), pSyndra_Sphere->GetNameNpc()) == false) continue;
				if (CheckName( (sz__SyndraSphere), pSyndra_Sphere->GetNameHero()) == false) continue;
				if(IsINSIDE_TAMGIAC(&pSyndra_Sphere->CurrentPos, &pBuff.SourcePos, &pos_diem1, &pos_diem2))
				{
					syphere_In.x = pSyndra_Sphere->CurrentPos.x, syphere_In.z = pSyndra_Sphere->CurrentPos.z; 
				}
			}
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &syphere_In, &pBuff);
	}
}
//100===VLADIMIR==========================================================================================================
void CDodge::DodgeVLADIMIR(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Vladimir));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__VladimirHemoplague), pBuff.szSpellName))			// R
	{
		//DodgeCircle(&pBuff.MaxDestPos, float(VLADIMIR_R_Radius), &pBuff);
		// KHONG LAY DUOC pCastSpell, SKILL E LAY DUOC, NHUNG VONG TRONG TO KHO NE
	}
}
//101===ZIGGS==========================================================================================================
void CDodge::DodgeZIGGS(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ZiggsQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 250) >= 1)
		{
			UnBlockMove();
			return;
		}
		float fDistance = Distance_2D(pBuff.MaxDestPos, pBuff.SourcePos);
		if (fDistance > ZIGGS_Q_Range)
		{
			//__oMsg("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			KPos posNghiem1, posNghiem2;
			TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.SourcePos, pBuff.MaxDestPos, ZIGGS_Q_Range);
			float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
			float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
			float C2 = dX * pBuff.SourcePos.x + dZ * pBuff.SourcePos.z;
			float tichVoHuong = (dX*pBuff.MaxDestPos.x + dZ*pBuff.MaxDestPos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
			if (tichVoHuong >= 0)
			{
				pBuff.MaxDestPos.x = posNghiem1.x, pBuff.MaxDestPos.z = posNghiem1.z;
				//__oMsg("new max dest1 = (%f, %f)", posNghiem1->x, posNghiem1->z);
			}
			else
			{
				pBuff.MaxDestPos.x = posNghiem2.x, pBuff.MaxDestPos.z = posNghiem2.z;
				//__oMsg("new max dest2 = (%f, %f)", posNghiem2->x, posNghiem2->z);
			}
		}

		KPos posNghiem1, posNghiem2, New_MaxDest;
		//-----------------------------------------------------------------
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pBuff.MaxDestPos, pBuff.SourcePos, 150.);
		float dX = pBuff.SourcePos.x - pBuff.MaxDestPos.x;
		float dZ = pBuff.SourcePos.z - pBuff.MaxDestPos.z;
		float C2 = dX * pBuff.MaxDestPos.x + dZ * pBuff.MaxDestPos.z; // duong thang vuong goc voi (1) va di qua MaxDestPos
		float tichVoHuong = (dX*pBuff.SourcePos.x + dZ*pBuff.SourcePos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			New_MaxDest.x = posNghiem1.x, New_MaxDest.z = posNghiem1.z;
		else
			New_MaxDest.x = posNghiem2.x, New_MaxDest.z = posNghiem2.z;
		//-----------------------------------------------------------------
		//dZ.x - dX.z  = C1   = dZ*pos1.x - dX*pos1.z  (1)(d)(di qua pos1, pos2)
		//dX.x + dZ.z  = C3  = dX*player_x + dZ*player_z (2)(vuong goc voi d va di qua player
		KNpc *g_pPlayer = GetPlayer();
		float player_x = g_pPlayer->CurrentPos.x;
		float player_z = g_pPlayer->CurrentPos.z;

		dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
		dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;

		float C1  = dZ*pBuff.SourcePos.x - dX*pBuff.SourcePos.z;
		float C3  = dX*player_x + dZ*player_z;

		//-----------------------------------
		KPos tmpPos0;
		int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, (-dX), C1, dX, dZ, C3);
		if (!Nghiem_0)  return;
		float vuonggoc_x  =  tmpPos0.x;
		float vuonggoc_z  =  tmpPos0.z;
		//------------------
		fDistance = Distance_2D(pBuff.MaxDestPos.x, pBuff.MaxDestPos.z, posNghiem1.x, posNghiem1.z);
		//__oMsg("posNghiem1-->distance: %f", fDistance);
		fDistance = Distance_2D(pBuff.MaxDestPos.x, pBuff.MaxDestPos.z, posNghiem2.x, posNghiem2.z);
		//__oMsg("posNghiem2-->distance: %f", fDistance);

		fDistance = Distance_2D(pBuff.MaxDestPos.x, pBuff.MaxDestPos.z,New_MaxDest.x, New_MaxDest.z);
		//__oMsg("new - maxdest, distance: %f", fDistance);
		float fDist_1 = Distance_2D(vuonggoc_x, vuonggoc_z, pBuff.MaxDestPos.x, pBuff.MaxDestPos.z);
		//__oMsg("vuonggoc-->distance: %f", fDist_1);
		float fDist_2 = Distance_2D(vuonggoc_x, vuonggoc_z, posNghiem1.x, posNghiem1.z);
		//__oMsg("vuonggoc-->posNghiem1: %f", fDist_2);
		float fDist_3 = Distance_2D(vuonggoc_x, vuonggoc_z, posNghiem2.x, posNghiem2.z);
		//__oMsg("vuonggoc-->posNghiem2: %f", fDist_3);
		//-----------------------------------------------------------------
		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, New_MaxDest, pBuff.SourcePos, ZIGGS_Q_Range2);
		dX = pBuff.SourcePos.x - New_MaxDest.x;
		dZ = pBuff.SourcePos.z - New_MaxDest.z;
		C2 = dX * pBuff.MaxDestPos.x + dZ * pBuff.MaxDestPos.z; // duong thang vuong goc voi (1) va di qua MaxDestPos
		tichVoHuong = (dX*pBuff.SourcePos.x + dZ*pBuff.SourcePos.z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
		if (tichVoHuong >= 0)
			DodgeMissileLine(&New_MaxDest, &posNghiem2, float(ZIGGS_Q_Radius), ZIGGS_Q_Range2, &pBuff);
		else
			DodgeMissileLine(&New_MaxDest, &posNghiem1, float(ZIGGS_Q_Radius), ZIGGS_Q_Range2, &pBuff);

	}
	else if (CheckName( (sz__ZiggsW), pBuff.szSpellName))			// W
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__ZiggsE), pBuff.szSpellName))			// E
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__ZiggsR), pBuff.szSpellName))			// R
	{
		KNpc* pPlayer = GetPlayer();
		if(pPlayer->nAttackRange <=350.0)
		{
			float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos); 
			if(KhoangCach <= 350.0)
			{
				UnBlockMove();
				return;
			}
		}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//102===ZAC==========================================================================================================
void CDodge::DodgeZAC(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__ZacQ), pBuff.szSpellName))			// Q ==> chieu rat kho ne, gan nhu ko ne dc
	{
		EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
	else if (CheckName( (sz__ZacE), pBuff.szSpellName))			// E
	{
		//DodgeCircle(&pBuff.MaxDestPos, 150., &pBuff);
	}
}
//103===ANNIE==========================================================================================================
void CDodge::DodgeANNIE(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__Incinerate), pBuff.szSpellName))			// W
	{
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(ANNIE_W_RadiusCone),ANNIE_W_RadiusLine, float(ANNIE_W_Range), &pBuff, ANNIE_W_DelayFlying);
		// HINH NON
	}
	else if (CheckName( (sz__InfernalGuardian), pBuff.szSpellName))			// R
	{
		//KNpc *pPlayer = GetPlayer();
		//float KhoangCach = Distance_2D(pPlayer->CurrentPos, pBuff.MaxDestPos);
		//__oMsg("khoang cach ==========annie=======%f", KhoangCach);
		//if (KhoangCach >= 230.)
		//{
		//	pBuff.nDangerValue = 4;
		//}
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}
//104===MORDEKAISER==========================================================================================================
void CDodge::DodgeMORDEKAISER(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Mordekaiser));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__MordekaiserSyphonOfDestruction), pBuff.szSpellName))			// E
	{
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(MORDEKAISER_E_RadiusCone), MORDEKAISER_E_RadiusLine, float(MORDEKAISER_E_Range), &pBuff, MORDEKAISER_E_DelayFlying);
		// HINH NON
	}
}
//105===TALON==========================================================================================================
void CDodge::DodgeTALON(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Talon));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__TalonRake), pBuff.szSpellName))			// W
	{
		//DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TALON_W_RadiusCone), TALON_W_RadiusLine, float(TALON_W_Range), &pBuff, TALON_W_DelayFlying);
		// HINH NON
	}
}
//106===RIVEN==========================================================================================================
void CDodge::DodgeRIVEN(KBuffer_Spell pBuff)
{
	//KNpc*pEnemyPlayer = GetEnemyPlayer( (sz__Riven));
	//PrintCastSpell(pEnemyPlayer);
	if (CheckName( (sz__RivenIzunaBlade), pBuff.szSpellName))			// R
	{
		DodgeCone(&pBuff.SourcePos, &pBuff.MaxDestPos, float(RIVEN_R_RadiusCone),RIVEN_R_RadiusLine, float(RIVEN_R_Range), &pBuff, RIVEN_R_DelayFlying);
		// HINH NON
	}
}
//107===TRYNDAMERE==========================================================================================================
void CDodge::DodgeTRYNDAMERE_BASETIME(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__TryndamereE), pBuff.szSpellName))			// E
	{
		float nRange = Distance_2D(pBuff.SourcePos, pBuff.MaxDestPos);
		if (nRange < pBuff.nRange - 200)
		{
			pBuff.nRange = nRange;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BASE_TIME);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
}

//108===TALIYAH==========================================================================================================
void CDodge::DodgeTALIYAH(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__TaliyahQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, 200) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		/*int nTienLui = CheckMousePos(pBuff.SourcePos, pBuff.MaxDestPos, pBuff);
		if (nTienLui != 0)
		{
			if (!IsShouldDodge_45Do(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui))
			{
				EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
			} 
			else
			{
				EVADE_LINE_45DO(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, nTienLui);
			}
		} 
		else
		{
			EVADE_THEO_MOUSE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
		}*/
	}
	if (CheckName( (sz__TaliyahW), pBuff.szSpellName))			// W
	{
		EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff);
	}
}

//=109===RAKAN==========================================================================================================
void CDodge::DodgeRAKAN(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__RakanQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}

//=110===XAYAH==========================================================================================================
void CDodge::DodgeXAYAH(KBuffer_Spell pBuff)
{
	if (CheckName( (sz__XayahQ), pBuff.szSpellName))			// Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}

//=111===ZOE==========================================================================================================
void CDodge::DodgeZOE(KBuffer_Spell pBuff)
{
	//__oMsg("Zoe E");
	if (CheckName("ZoeE", pBuff.szSpellName))			// E
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//=112===PYKE==========================================================================================================
void CDodge::DodgePYKE(KBuffer_Spell pBuff)
{
	if (CheckName("PykeQRange", pBuff.szSpellName))// || CheckName("PykeE", pBuff.szSpellName))			// E Q
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//=113===IRELIA==========================================================================================================
void CDodge::DodgeIRELIA(KBuffer_Spell pBuff)
{
	if (CheckName("IreliaR", pBuff.szSpellName))			// R
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
//=114===KAISA==========================================================================================================
void CDodge::DodgeKAISA(KBuffer_Spell pBuff)
{
	if (CheckName("KaisaW", pBuff.szSpellName))			// W
	{
		if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
		{
			UnBlockMove();
			return;
		}
		DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff);
	}
}
