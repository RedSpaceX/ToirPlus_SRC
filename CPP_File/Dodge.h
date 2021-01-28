#pragma once
#include "stdafx.h"
#include "GameData.h"
#include "InjectBot.h"
#include "SpellData.h"
#include "Utils.h"
#include "CBaseDodge.h"
#include <cmath>
#include "DataString.h"

class CDodge:public CBaseDodge{
	CDodge(){}
	static CDodge * s_Instance;
public:
	static CDodge * GetInstance()
	{
		if (s_Instance == NULL)
		{
			s_Instance = new CDodge;
		}
		return s_Instance;
	}
	//=====DODGE FUNCTIONS FOR EACH HERO=========================================================================
	void DodgeRYZE(KBuffer_Spell);				//==1===RYZE========================
	void DodgeGRAGAS(KBuffer_Spell);			//==2===GRAGAS======================
	void DodgeGRAGAS_BASETIME(KBuffer_Spell);	//==2=B=GRAGAS======================
	void DodgeEZREAL(KBuffer_Spell);			//==3===EZREAL======================
	void DodgeCAITLYN(KBuffer_Spell);			//==4===CAITLYN=====================
	void DodgeMORGANA(KBuffer_Spell);			//==5===MORGANA=====================
	void DodgeCHOGATH(KBuffer_Spell);			//==6===CHOGATH=====================
	void DodgeAMUMU(KBuffer_Spell);				//==7===AMUMU=======================
	void DodgeGRAVES(KBuffer_Spell);			//==8===GRAVES======================
	void DodgeAATROX(KBuffer_Spell);			//==9===AATROX======================
	void DodgeAATROX_BASETIME(KBuffer_Spell);	//==9=B=AATROX======================
	void DodgeJANNA(KBuffer_Spell);				//=10===JANNA=======================
	void DodgeSEJUANI(KBuffer_Spell);			//=11===SEJUANI=====================
	void DodgeSEJUANI_BASETIME(KBuffer_Spell);	//=11=B=SEJUANI=====================
	void DodgeAHRI(KBuffer_Spell);				//=12===AHRI========================
	void DodgeKALISTA(KBuffer_Spell);			//=13===KALISTA=====================
	void DodgeJINX(KBuffer_Spell);				//=14===JINX========================
	void DodgeMUNDO(KBuffer_Spell);				//=15===MUNDO=======================
	void DodgeBLITZCRANK(KBuffer_Spell);		//=16===BLITZCRANK==================
	void DodgeBRAND(KBuffer_Spell);				//=17===BRAND=======================
	void DodgeBRAUM(KBuffer_Spell);				//=18===BRAUM=======================
	void DodgeCORKI(KBuffer_Spell);				//=19===CORKI=======================
	void DodgeTAHMKENCH(KBuffer_Spell);			//=20===TAHM KENCH==================
	void DodgeFIORA(KBuffer_Spell);				//=21===FIORA=======================
	void DodgeJARVAN4(KBuffer_Spell);			//=22===JARVAN4=====================
	void DodgeLUX(KBuffer_Spell);				//=23===LUX=========================
	void DodgeNIDALEE(KBuffer_Spell);			//=24===NIDALEE=====================
	void DodgeOLAF(KBuffer_Spell);				//=25===OLAF========================
	void DodgeNAUTILUS(KBuffer_Spell);			//=26===NAUTILUS====================
	void DodgeNOCTURNE(KBuffer_Spell);			//=27===NOCTURNE====================
	void DodgeMISSFORTUNE(KBuffer_Spell);		//=28===MISS FORTUNE================
	void DodgeVARUS(KBuffer_Spell);				//=29===VARUS=======================
	void DodgeVEIGAR(KBuffer_Spell);			//=30===VEIGAR======================
	void DodgeVELKOZ(KBuffer_Spell);			//=31===VELKOZ======================
	void DodgeLUCIAN(KBuffer_Spell);			//=32===LUCIAN======================
	void DodgeDRAVEN(KBuffer_Spell);			//=33===DRAVEN======================
	void DodgeEKKO(KBuffer_Spell);				//=34===EKKO========================
	void DodgeDARIUS(KBuffer_Spell);			//=35===DARIUS======================
	void DodgeDARIUS_BASETIME(KBuffer_Spell);	//=35=B=DARIUS======================
	void DodgeKARMA(KBuffer_Spell);				//=36===KARMA=======================
	void DodgeSIVIR(KBuffer_Spell);				//=37===SIVIR=======================
	void DodgeGALIO(KBuffer_Spell);				//=38===GALIO=======================
	void DodgeTRISTANA(KBuffer_Spell);			//=39===TRISTANA====================
	void DodgeKARTHUS(KBuffer_Spell);			//=40===KARTHUS=====================
	void DodgeMALPHITE(KBuffer_Spell);			//=41===MALPHITE====================
	void DodgeMALPHITE_BASETIME(KBuffer_Spell);	//=41=B=MALPHITE====================
	void DodgeNASUS(KBuffer_Spell);				//=42===NASUS=======================
	void DodgeYORICK(KBuffer_Spell);			//=43===YORICK======================
	void DodgeLEESIN(KBuffer_Spell);			//=44===LEESIN======================
	void DodgeLULU(KBuffer_Spell);				//=45===LULU========================
	void DodgeYASUO(KBuffer_Spell);				//=46===YASUO=======================
	void DodgeKHAZIX(KBuffer_Spell);			//=47===KHAZIX======================
	void DodgeTWISTEDFATE(KBuffer_Spell);		//=48===TWISTEDFATE=================
	void DodgeTHRESH(KBuffer_Spell);			//=49===THRESH======================
	void DodgeSORAKA(KBuffer_Spell);			//=50===SORAKA======================
	void DodgeASHE(KBuffer_Spell);				//=51===ASHE========================
	void DodgeSONA(KBuffer_Spell);				//=52===SONA========================
	void DodgeFIZZ(KBuffer_Spell);				//=53===FIZZ========================
	void DodgeZED(KBuffer_Spell);				//=54===ZED=========================
	void DodgeJHIN(KBuffer_Spell);				//=55===JHIN========================
	void DodgeXERATH(KBuffer_Spell);			//=56===XERATH======================
	void DodgeMALZAHAR(KBuffer_Spell);			//=57===MALZAHAR====================
	void DodgeQUINN(KBuffer_Spell);				//=58===QUINN=======================
	void DodgeANIVIA(KBuffer_Spell);			//=59===ANIVIA======================
	void DodgeZYRA(KBuffer_Spell);				//=60===ZYRA========================
	void DodgeELISE(KBuffer_Spell);				//=61===ELISE=======================
	void DodgeEVELYNN(KBuffer_Spell);			//=62===EVELYNN=====================
	void DodgeDIANA(KBuffer_Spell);				//=63===DIANA=======================
	void DodgeKENNEN(KBuffer_Spell);			//=64===KENNEN======================
	void DodgePOPPY(KBuffer_Spell);				//=65===POPPY=======================
	void DodgeLEBLANC(KBuffer_Spell);			//=66===LEBLANC=====================
	void DodgeBARD(KBuffer_Spell);				//=67===BARD========================
	void DodgeZILEAN(KBuffer_Spell);			//=68===ZILEAN======================
	void DodgeLISSANDRA(KBuffer_Spell);			//=69===LISSANDRA===================
	void DodgeSWAIN(KBuffer_Spell);				//=70===SWAIN=======================
	void DodgeAURELIONSOL(KBuffer_Spell);		//=71===AURELION SOL================
	void DodgeTWITCH(KBuffer_Spell);			//=72===TWITCH======================
	void DodgeGNAR(KBuffer_Spell);				//=73===GNAR========================
	void DodgeKOGMAW(KBuffer_Spell);			//=74===KOGMAW======================
	void DodgeSINGED(KBuffer_Spell);			//=75===SINGED======================
	void DodgeCASSIOPEIA(KBuffer_Spell);		//=76===CASSIOPEIA==================
	void DodgeHEIMERDINGER(KBuffer_Spell);		//=77===HEIMERDINGER================
	void DodgeILLAOI(KBuffer_Spell);			//=78===ILLAOI======================
	void DodgeLEONA(KBuffer_Spell);				//=79===LEONA=======================
	void DodgeJAYCE(KBuffer_Spell);				//=80===JAYCE=======================
	void DodgeKASSADIN(KBuffer_Spell);			//=81===KASSADIN====================
	void DodgeSHEN(KBuffer_Spell);				//=82===SHEN========================
	void DodgeVIKTOR(KBuffer_Spell);			//=83===VIKTOR======================
	void DodgeGANGPLANK(KBuffer_Spell);			//=84===GANGPLANK===================
	void DodgeNAMI(KBuffer_Spell);				//=85===NAMI========================
	void DodgePHANTHEON(KBuffer_Spell);			//=86===PHANTHEON===================
	void DodgeMAOKAI(KBuffer_Spell);			//=87===MAOKAI======================
	void DodgeRENGAR(KBuffer_Spell);			//=88===RENGAR======================
	void DodgeREKSAI(KBuffer_Spell);			//=89===REKSAI======================
	void DodgeSKARNER(KBuffer_Spell);			//=90===SKARNER=====================
	void DodgeTARIC(KBuffer_Spell);				//=91===TARIC=======================
	void DodgeVI(KBuffer_Spell) ;				//=92===VI==========================
	void DodgeTEEMO(KBuffer_Spell);				//=93===TEEMO=======================
	void DodgeURGOT(KBuffer_Spell);				//=94===URGOT=======================
	void DodgeORIANNA(KBuffer_Spell);			//=95===ORIANNA=====================
	void DodgeRUMBLE(KBuffer_Spell);			//=96===RUMBLE======================
	void DodgeSHYVANA(KBuffer_Spell);			//=97===SHYVANA=====================
	void DodgeSION(KBuffer_Spell);				//=98===SION========================
	void DodgeSYNDRA(KBuffer_Spell);			//=99===SYNDRA======================
	void DodgeVLADIMIR(KBuffer_Spell);			//100===VLADIMIR====================
	void DodgeZIGGS(KBuffer_Spell);				//101===ZIGGS=======================
	void DodgeZAC(KBuffer_Spell);				//102===ZAC=========================
	void DodgeANNIE(KBuffer_Spell);				//103===ANNIE=======================
	void DodgeMORDEKAISER(KBuffer_Spell);		//104===MORDEKAISER=================
	void DodgeTALON(KBuffer_Spell);				//105===TALON=======================
	void DodgeRIVEN(KBuffer_Spell);				//106===RIVEN=======================
	void DodgeTRYNDAMERE_BASETIME(KBuffer_Spell);//107=B=TRYNDAMERE=================
	void DodgeTALIYAH(KBuffer_Spell);			//108===TALIYAH=====================
	void DodgeRAKAN(KBuffer_Spell);				//109===RAKAN=====================
	void DodgeXAYAH(KBuffer_Spell pBuff);		//110===XAYAH=====================
	void DodgeZOE(KBuffer_Spell pBuff);			//111===ZOE=====================
	void DodgePYKE(KBuffer_Spell pBuff);		//112===PYKE=====================
	void DodgeIRELIA(KBuffer_Spell pBuff);		//113===IRELIA=====================
	void DodgeKAISA(KBuffer_Spell pBuff);		//113===KAISA=====================
};

