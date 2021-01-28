#include "SpellData.h"


//==================================================================================//
//==================================================================================//
//==================================================================================//
void SetSpellData(KBuffer_Spell &pBuff)
{
////////	//==0===ALL CHAMPIONS===========================================================================================
////////	//if (CheckName(pBuff.szSpellName, "summonersnowball")) //Poro Throw
////////	//{
////////	//	pBuff.nDelay = 0;
////////	//	pBuff.nRange = 1600;
////////	//	pBuff.nRadius = 60;
////////	//	pBuff.nMissileSpeed = 1300;
////////	//	pBuff.nDangerValue = 1;
////////	//	pBuff.nIsDangerous = false;
////////	//	pBuff.nFlag_TruocSau = false;
////////	//}
////////	//==1===RYZE=====================================================================================================
////////	if (CheckName(pBuff.szHeroName,  (sz__Ryze)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__RyzeQ)))
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 55;
////////			pBuff.nMissileSpeed = 1550;// du lieu game = 1700
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==2===GRAGAS==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Gragas)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__GragasQ))) // Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 975;
////////			pBuff.nRadius = 255;
////////			pBuff.nMissileSpeed = 1000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__GragasE)))			// E
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 700;
////////			pBuff.nRadius = 150;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__GragasR))) // R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1050;
////////			pBuff.nRadius = 350;
////////			pBuff.nMissileSpeed = 1750;
////////			pBuff.nDangerValue = 5;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==3===EZREAL==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Ezreal)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  "EzrealQ"))				// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  "EzrealW"))			// W
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1050;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1600;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  "EzrealR"))		// R
////////		{
////////			pBuff.nDelay = 1000;
////////			pBuff.nRange = 20000;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==4===CAITLYN==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Caitlyn)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__CaitlynPiltoverPeacemaker)))		// Q
////////		{
////////			pBuff.nDelay = 625;
////////			pBuff.nRange = 1300;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 2200;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__CaitlynEntrapment)))			// E
////////		{
////////			pBuff.nDelay = 150;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1600;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==5===MORGANA==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Morgana)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__DarkBindingMissile)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1300;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==6===CHOGATH==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Chogath)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__Rupture)))		// Q
////////		{
////////			pBuff.nDelay = 1000;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 180;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==7===AMUMU==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Amumu)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__BandageToss)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__CurseoftheSadMummy)))		// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 560;
////////			pBuff.nRadius = 560;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 5;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==8===GRAVES==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Graves)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__GravesQLineSpell)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 825;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1600;//game-data: 902??
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__GravesChargeShot)))		// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 1550;//game-data = 1400
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//==9===AATROX==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Aatrox)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__AatroxQ)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 650;
////////			pBuff.nRadius = 285;
////////			pBuff.nMissileSpeed = 450;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__AatroxE)))		// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 95;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=11===SEJUANI==========================================================================================================
////////	if (CheckName(pBuff.szHeroName,  (sz__Sejuani)))
////////	{
////////		if (CheckName( (sz__SejuaniQ), pBuff.szSpellName))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 700;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1350;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__SejuaniR)))		// R
////////		{
////////			pBuff.nDelay = 270;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1500;//game-data = 1200 hay sao ay
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=12===AHRI==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Ahri)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__AhriOrbofDeception))||CheckName(pBuff.szSpellName,  (sz__AhriOrbofReturn)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 1450; //game-data = 1100
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__AhriSeduce)))		// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1250; //game-data = 1200
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=13===KALISTA=======================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Kalista)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__KalistaMysticShot)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 50;
////////			pBuff.nMissileSpeed = 2000;// du lieu game = 1200
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=14===JINX==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Jinx)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__JinxWMissile)))		// W
////////		{
////////			pBuff.nDelay = 600;
////////			pBuff.nRange = 1500;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 3300;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__JinxR)))		// R
////////		{
////////			pBuff.nDelay = 600;
////////			pBuff.nRange = 25000;
////////			pBuff.nRadius = 140;
////////			pBuff.nMissileSpeed = 2200;// chi so trong game la 1700
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=15===DR.MUNDO==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__DrMundo)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__InfectedCleaverMissile)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=16===BLITZCRANK==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Blitzcrank)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__RocketGrabMissile)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1050;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=17===BRAND==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Brand)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__BrandQ)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1050;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1275;// game-data = 1200
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__BrandW)))		// W
////////		{
////////			pBuff.nDelay = 850;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 180;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=18===BRAUM==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Braum)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__BraumQ)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 1150; // game-data = 1100
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__BraumRWrapper)))		// R
////////		{
////////			pBuff.nDelay = 500;
////////			pBuff.nRange = 1250;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=19===CORKI==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Corki)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__PhosphorusBomb)))		// Q
////////		{
////////			pBuff.nDelay = 500;
////////			pBuff.nRange = 825;
////////			pBuff.nRadius = 270;
////////			pBuff.nMissileSpeed = 1125;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__MissileBarrageMissile)))		// R1
////////		{
////////			pBuff.nDelay = 175;
////////			pBuff.nRange = 1300;
////////			pBuff.nRadius = 40;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__MissileBarrageMissile2)))		// R2
////////		{
////////			pBuff.nDelay = 175;
////////			pBuff.nRange = 1500;
////////			pBuff.nRadius = 40;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=20===TAHM KENCH==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__TahmKench)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__TahmKenchQ)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 77;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		//else if (CheckName(pBuff.szSpellName,  "TahmKenchWCastTimeAndAnimation"))		// W
////////		//{
////////		//	//pBuff.nDelay = 250;
////////		//	pBuff.nRange = 900;
////////		//	pBuff.nRadius = 77;
////////		//	pBuff.nMissileSpeed = 2000;
////////		//	pBuff.nDangerValue = 2;
////////		//	pBuff.nIsDangerous = false;
////////		//	pBuff.nFlag_TruocSau = false;
////////		//}
////////	}
////////	//=22===JARVAN4==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__JarvanIV)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__JarvanIVDragonStrike)))		// Q1
////////		{
////////			pBuff.nDelay = 350;// game-data = 400
////////			pBuff.nRange = 800;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1800;// game-data = 20???
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__JarvanIVEQ)))				// Q2-luot
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 800;
////////			pBuff.nRadius = 85;
////////			pBuff.nMissileSpeed = 1800;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__JarvanIVDemacianStandard)))// E
////////		{
////////			pBuff.nDelay = 900;
////////			pBuff.nRange = 860;
////////			pBuff.nRadius = 30;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=23===LUX ==========================================================================================================	
////////	else if (CheckName(pBuff.szHeroName,  (sz__Lux)))
////////	{
////////		if (CheckName( (sz__LuxLightBinding), pBuff.szSpellName)) // Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1175;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__LuxLightStrikeKugel)))	// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 275;
////////			pBuff.nMissileSpeed = 1300;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__LuxMaliceCannonMis)))		// R
////////		{
////////			pBuff.nDelay = 1000;
////////			pBuff.nRange = 3500;
////////			pBuff.nRadius = 110;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=24===NIDALEE==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Nidalee)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__JavelinToss)))				// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1500;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1300;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=25===OLAF==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Olaf)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__OlafAxeThrowCast)))				// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1225;//game-data = 1600
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=26===NAUTILUS==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Nautilus)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__NautilusAnchorDragMissile)))				// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1150;
////////			pBuff.nRadius = 85;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=27===NOCTURNE==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Nocturne)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__NocturneDuskbringer)))		// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 68;
////////			pBuff.nMissileSpeed = 1400;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=29===VARUS==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Varus)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__VarusQ)))				// Q
////////		{
////////			pBuff.nDelay = 0;
////////			pBuff.nRange = 1600;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1900;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__VarusE)))					// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 925;
////////			pBuff.nRadius = 220;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__VarusR)))					// R
////////		{
////////			pBuff.nDelay = 250;			//game-data = 241.8
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 1600; //game-data = 1200
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=30===VEIGAR==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Veigar)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__VeigarBalefulStrike)))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1500;// game-data = 1200
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__VeigarDarkMatterCastLockout), pBuff.szSpellName))		// W
////////		{
////////			pBuff.nDelay = 750;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 140;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__VeigarEventHorizon)))					// E
////////		{
////////			pBuff.nDelay = 750;
////////			pBuff.nRange = 700;
////////			pBuff.nRadius = 325;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=31===VELKOZ==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Velkoz)))
////////	{
////////		if (CheckName( (sz__VelkozQ), pBuff.szSpellName))						// Q1
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 55;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__VelkozQSplit), pBuff.szSpellName))			// Q2
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 550;
////////			pBuff.nRadius = 45;
////////			pBuff.nMissileSpeed = 2100;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = true;
////////		}
////////		else if (CheckName(pBuff.szSpellName, sz__VelkozW))				// W
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1050;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1450;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__VelkozE)))				// E
////////		{
////////			pBuff.nDelay = 600;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=32===LUCIAN==========================================================================================================
////////	else if (CheckName( (sz__Lucian), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__LucianQ), pBuff.szSpellName))						// Q
////////		{
////////			pBuff.nDelay = 550;//game-data = 400
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = MAX_INT;//game-data = 500
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__LucianW), pBuff.szSpellName))			    // W
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 70;
////////			pBuff.nRadius_2 = 170;
////////			pBuff.nMissileSpeed = 1250;//game-data = 500
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__LucianR), pBuff.szSpellName))				// R
////////		{
////////			pBuff.nDelay = 500;// game-data = 10
////////			pBuff.nRange = 1400;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 2800; // game-data = 500
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=33===DRAVEN==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Draven)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__DravenDoubleShot)))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 130;
////////			pBuff.nMissileSpeed = 1200;// game-data = 1600
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__DravenRCast)))			    // R
////////		{
////////			pBuff.nDelay = 500;
////////			pBuff.nRange = 25000;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=34===EKKO==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Ekko)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__EkkoQ)))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1200;// game-data = 1200
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__EkkoW)))		// W
////////		{
////////			pBuff.nDelay = 1000;
////////			pBuff.nRange = 1600;
////////			pBuff.nRadius = 300;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=36===KARMA==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Karma)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__KarmaQ)))			// Q1 GHE
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1350;// du lieu game 902
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__KarmaQMantra)))		// Q2 + R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1700;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=37===SIVIR==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Sivir)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__SivirQ)))			// Q1
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1275;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 1350;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=38===GALIO==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Galio)))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__GalioResoluteSmite)))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1040;
////////			pBuff.nRadius = 190;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__GalioRighteousGust)))		// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1180;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = 1300;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__GalioIdolOfDurand)))		// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 600;
////////			pBuff.nRadius = 600;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 5;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=40===KARTHUS==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Karthus)))
////////	{
////////		if (CheckName( (sz__KarthusLayWaste), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 750;
////////			pBuff.nRange = 875;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=41===MALPHITE==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Malphite)))
////////	{
////////		if (CheckName( (sz__UFSlash), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 0;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 270;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 5;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=44===LEESIN==========================================================================================================
////////	else if (CheckName(  (sz__LeeSin), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__BlindMonkQOne), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1550;// game-data = 1800
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=45===LULU==========================================================================================================
////////	else if (CheckName(  (sz__Lulu), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__LuluQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 925;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1275;// game-data = 1400
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=46===YASUO==========================================================================================================
////////	else if (CheckName(  (sz__Yasuo), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__YasuoQ3), pBuff.szSpellName))			// Q3 : LOC XOAY
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1000;// game-data=5000???, chac la Q1-Q2
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		//else if (CheckName( (sz__YasuoQ2), pBuff.szSpellName))			// Q2
////////		//{
////////		//	pBuff.nDelay = 250;
////////		//	pBuff.nRange = 525;
////////		//	pBuff.nRadius = 35;
////////		//	pBuff.nMissileSpeed = MAX_INT;
////////		//	pBuff.nDangerValue = 2;
////////		//	pBuff.nIsDangerous = true;
////////		//	pBuff.nFlag_TruocSau = false;
////////		//}
////////		//else if (CheckName( (sz__YasuoQ), pBuff.szSpellName))			// Q
////////		//{
////////		//	pBuff.nDelay = 250;
////////		//	pBuff.nRange = 525;
////////		//	pBuff.nRadius = 35;
////////		//	pBuff.nMissileSpeed = MAX_INT;
////////		//	pBuff.nDangerValue = 2;
////////		//	pBuff.nIsDangerous = true;
////////		//	pBuff.nFlag_TruocSau = false;
////////		//}
////////	}
////////	//=47===KHAZIX==========================================================================================================
////////	else if (CheckName(  (sz__Khazix), pBuff.szHeroName))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__KhazixW) ))			// W
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1450;// du lieu game = 828.5
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=49===THRESH==========================================================================================================
////////	else if (CheckName(  (sz__Thresh), pBuff.szHeroName))
////////	{
////////		//if (CheckName( (sz__ThreshQInternal), pBuff.szSpellName))			// Q
////////		if (CheckName(pBuff.szSpellName, "ThreshQ" ))			// Q
////////		{
////////			pBuff.nDelay = 500;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1800;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ThreshE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 200;
////////			pBuff.nRange = 500;
////////			pBuff.nRadius = 110;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = true;
////////		}
////////	}
////////	//=50===SORAKA==========================================================================================================
////////	else if (CheckName(  (sz__Soraka), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__SorakaQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 970;
////////			pBuff.nRadius = 205;
////////			pBuff.nMissileSpeed = 1100;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__SorakaE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 950;
////////			pBuff.nRange = 925;
////////			pBuff.nRadius = 210;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=51===ASHE==========================================================================================================
////////	else if (CheckName(  (sz__Ashe), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__EnchantedCrystalArrow), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 25000;
////////			pBuff.nRadius = 130;
////////			pBuff.nMissileSpeed = 1600;// du lieu game = 902
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=52===SONA==========================================================================================================
////////	else if (CheckName(  (sz__Sona), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__SonaR), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 140;
////////			pBuff.nMissileSpeed = 2400;
////////			pBuff.nDangerValue = 5;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=53===FIZZ==========================================================================================================
////////	else if (CheckName(  (sz__Fizz), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__FizzR), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1275;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 1350;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=54===ZED==========================================================================================================
////////	else if (CheckName(  (sz__Zed), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__ZedQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 925;
////////			pBuff.nRadius = 55;
////////			pBuff.nMissileSpeed = 1500;// du lieu game 902
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=55===JHIN==========================================================================================================
////////	else if (CheckName(  (sz__Jhin), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__JhinW), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 675;// game-data = 750
////////			pBuff.nRange = 2250;
////////			pBuff.nRadius = 40;
////////			pBuff.nMissileSpeed = MAX_INT;// game-data = 5000
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName("JhinRShot", pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 250;// game-data = 750
////////			pBuff.nRange = 3500;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 6500;// game-data = 5000
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=56===XERATH==========================================================================================================
////////	else if (CheckName(  (sz__Xerath), pBuff.szHeroName))
////////	{
////////		if (CheckName(pBuff.szSpellName, "XerathArcanopulse2"))					// Q-Release
////////		{
////////			pBuff.nDelay = 550;
////////			pBuff.nRange = 1525;
////////			pBuff.nRadius = 85;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__XerathArcaneBarrage2), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 750;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 200;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__XerathMageSpear), pBuff.szSpellName))				// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1250;// game-data = 1600
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName, "XerathRMissileWrapper"))			// R
////////		{
////////			pBuff.nDelay = 575;
////////			pBuff.nRange = 5600;
////////			pBuff.nRadius = 125;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=57===MALZAHAR==========================================================================================================
////////	else if (CheckName( (sz__Malzahar), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__MalzaharQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 1100;// game-data = 250
////////			pBuff.nRange = 350;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = 500;// game-data = 1600
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = true;
////////		}
////////	}
////////	//=58===QUINN==========================================================================================================
////////	else if (CheckName( (sz__Quinn), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__QuinnQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1050;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1300;//game-data = 1550
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=59===ANIVIA==========================================================================================================
////////	else if (CheckName( (sz__Anivia), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__FlashFrost), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 300;// game-data = 250
////////			pBuff.nRange = 1150;
////////			pBuff.nRadius = 125;
////////			pBuff.nMissileSpeed = 750;// game-data = 850
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=60===ZYRA==========================================================================================================
////////	else if (CheckName( (sz__Zyra), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__ZyraQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 1050;// game-data = 250
////////			pBuff.nRange = 350;
////////			pBuff.nRadius = 110;
////////			pBuff.nMissileSpeed = 1400;// game-data = 1400
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = true;
////////		}
////////		else if (CheckName( (sz__ZyraE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1150;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ZyraR), pBuff.szSpellName))			// R
////////		{
////////			//pBuff.nDelay = 250;
////////			//pBuff.nRange = 1100;
////////			//pBuff.nRadius = 110;
////////			//pBuff.nMissileSpeed = 850;
////////			//pBuff.nDangerValue = 3;
////////			//pBuff.nIsDangerous = true;
////////			//pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=61===ELISE==========================================================================================================
////////	else if (CheckName( (sz__Elise), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__EliseHumanE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1200;// game-data = 1600
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=63===DIANA==========================================================================================================
////////	else if (CheckName( (sz__Diana), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__DianaArc), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 850;
////////			pBuff.nRadius = 170;
////////			pBuff.nMissileSpeed = 1400;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=64===KENNEN==========================================================================================================
////////	else if (CheckName( (sz__Kennen), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__KennenShurikenHurlMissile1), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 175;//game-data = 175
////////			pBuff.nRange = 1175;
////////			pBuff.nRadius = 50;
////////			pBuff.nMissileSpeed = 1400;//game-data = 1700
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=65===POPPY==========================================================================================================
////////	else if (CheckName( (sz__Poppy), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__PoppyQSpell), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 520;
////////			pBuff.nRange = 430;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1300;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName("PoppyRSpell", pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 1150;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 1600;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=66===LEBLANC==========================================================================================================
////////	else if (CheckName( (sz__Leblanc), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__LeblancE), pBuff.szSpellName))			// E va R-E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 925;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1650;// du lieu game = 0
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=67===BARD==========================================================================================================
////////	else if (CheckName( (sz__Bard), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__BardQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = 1600;	// du lieu trong game = 0
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		if (CheckName( (sz__BardR), pBuff.szSpellName))			// R : SKILL RAT DE NE, QTRONG LA CO MUON NE HAY KO
////////		{
////////			pBuff.nDelay = 550;
////////			pBuff.nRange = 3400;
////////			pBuff.nRadius = 280;
////////			pBuff.nMissileSpeed = 2100;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=68===ZILEAN==========================================================================================================
////////	else if (CheckName( (sz__Zilean), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__ZileanQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 140;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=69===LISSANDRA==========================================================================================================
////////	else if (CheckName( (sz__Lissandra), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__LissandraQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 750;
////////			pBuff.nRadius = 75;
////////			pBuff.nMissileSpeed = 1800;// game-data = 2200
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__LissandraE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 750;//game-data = 850
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=70===SWAIN==========================================================================================================
////////	else if (CheckName( (sz__Swain), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__SwainShadowGrasp), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 800;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=71===AURELION SOL==========================================================================================================
////////	else if (CheckName( (sz__AurelionSol), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__AurelionSolQ), pBuff.szSpellName))			// Q
////////		{
////////			//CHUA LAM DUOC
////////		}
////////		else if (CheckName( (sz__AurelionSolR), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 1420;
////////			pBuff.nRadius = 110;
////////			pBuff.nMissileSpeed = 4600;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=73===GNAR==========================================================================================================
////////	else if (CheckName( (sz__Gnar), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__GnarQMissile), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 55;
////////			pBuff.nMissileSpeed = 1500;// game-data = 2500
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__GnarBigQMissile), pBuff.szSpellName))			// Q BIG
////////		{
////////			pBuff.nDelay = 500;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1700;//game-data = 2100
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__GnarBigW), pBuff.szSpellName))			// W BIG
////////		{
////////			pBuff.nDelay = 600;
////////			pBuff.nRange = 525;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName("GnarBigE", pBuff.szSpellName))			// E BIG
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 475;
////////			pBuff.nRadius = 220;
////////			pBuff.nMissileSpeed = 950;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName, "GnarE"))			// E
////////		{
////////			pBuff.nDelay = 50;
////////			pBuff.nRange = 473;
////////			pBuff.nRadius = 150;
////////			pBuff.nMissileSpeed = 903;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=74===KOGMAW==========================================================================================================
////////	else if (CheckName( (sz__KogMaw), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__KogMawQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1500;// du lieu game = 1650
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__KogMawVoidOozeMissile), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1300;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 1300;// du lieu game = 1400
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__KogMawLivingArtillery), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 750;
////////			pBuff.nRange = 2200;
////////			pBuff.nRadius = 150;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=76===CASSIOPEIA==========================================================================================================
////////	else if (CheckName( (sz__Cassiopeia), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__CassiopeiaQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 655;
////////			pBuff.nRange = 600;
////////			pBuff.nRadius = 115;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__CassiopeiaW), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 500;// data-game = 250
////////			pBuff.nRange = 400;
////////			pBuff.nRadius = 110;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = true;
////////		}
////////	}
////////	//=77===HEIMERDINGER==========================================================================================================
////////	else if (CheckName( (sz__Heimerdinger), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__HeimerdingerW), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1350;
////////			pBuff.nRadius = 35;
////////			pBuff.nMissileSpeed = 1700;// du lieu game la 902
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__HeimerdingerEUlt), pBuff.szSpellName))			// R->E
////////		{
////////			
////////		}
////////		else if (CheckName( (sz__HeimerdingerE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 450;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 155;
////////			pBuff.nMissileSpeed = 1750;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=78===ILLAOI==========================================================================================================
////////	else if (CheckName( (sz__Illaoi), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__IllaoiQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 750;// game-data = 750
////////			pBuff.nRange = 850;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = MAX_INT; // game-data = 500
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__IllaoiE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 50;
////////			pBuff.nMissileSpeed = 1350;// game-data = 0
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__IllaoiR), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 500;// chua chuan
////////			pBuff.nRange = 0;
////////			pBuff.nRadius = 335;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=79===LEONA==========================================================================================================
////////	else if (CheckName( (sz__Leona), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__LeonaZenithBlade), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = 1400;//game-data = 1200
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__LeonaSolarFlare), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 1100;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 260;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=80===JAYCE==========================================================================================================
////////	else if (CheckName( (sz__Jayce), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__JayceShockBlast), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;			// game-data = 214
////////			pBuff.nRange = 1750;
////////			pBuff.nRadius = 100;
////////			pBuff.nMissileSpeed = 2100; // game-data = 1200(chua di qua day phoi)
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=83===VIKTOR==========================================================================================================
////////	else if (CheckName( (sz__Viktor), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__ViktorGravitonField), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 1100;
////////			pBuff.nRange = 625;
////////			pBuff.nRadius = 240;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ViktorDeathRay), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 575;
////////			pBuff.nRadius = 85;
////////			pBuff.nMissileSpeed = 1050;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ViktorChaosStorm), pBuff.szSpellName))			// R
////////		{
////////			//pBuff.nDelay = 1100;
////////			//pBuff.nRange = 625;
////////			//pBuff.nRadius = 240;
////////			//pBuff.nMissileSpeed = MAX_INT;
////////			//pBuff.nDangerValue = 2;
////////			//pBuff.nIsDangerous = false;
////////			//pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=85===NAMI==========================================================================================================
////////	else if (CheckName( (sz__Nami), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__NamiQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 650;
////////			pBuff.nRange = 875;
////////			pBuff.nRadius = 110;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__NamiR), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 450; // game-data = 500
////////			pBuff.nRange = 2750;
////////			pBuff.nRadius = 230;
////////			pBuff.nMissileSpeed = 750;// game-data = 850
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=86===PHANTHEON==========================================================================================================
////////	else if (CheckName( (sz__Pantheon), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__PantheonRJump), pBuff.szSpellName))			// R => bay len
////////		{
////////			pBuff.nDelay = 2500;
////////			pBuff.nRange = 5500;
////////			pBuff.nRadius = 600;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__PantheonRFall), pBuff.szSpellName))			// R => ha xuong
////////		{
////////			// co the ko can lam
////////		}
////////	}
////////	//=87===MAOKAI==========================================================================================================
////////	else if (CheckName( (sz__Maokai), pBuff.szHeroName))
////////	{
////////		//if (CheckName( (sz__MaokaiTrunkLine), pBuff.szSpellName))	// Q
////////		if (CheckName( (sz__MaokaiQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 375;		// du lieu game = 375
////////			pBuff.nRange = 600;
////////			pBuff.nRadius = 85;
////////			pBuff.nMissileSpeed = 1800;// du lieu game = 1600
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=88===RENGAR==========================================================================================================
////////	else if (CheckName( (sz__Rengar), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__RengarE), pBuff.szSpellName))			// E(RengarE) - E.cuonghoa(RengarEEmp)
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 70;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=89===REKSAI==========================================================================================================
////////	else if (CheckName( (sz__RekSai), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__RekSaiQBurrowed), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 135;// game-data = 125
////////			pBuff.nRange = 1450;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = 1675; // game-data = 4000
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=90===SKARNER==========================================================================================================
////////	else if (CheckName( (sz__Skarner), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__SkarnerFracture), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1300;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=94===URGOT==========================================================================================================
////////	else if (CheckName( (sz__Urgot), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__UrgotHeatseekingMissile), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 145;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = 1600;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__UrgotPlasmaGrenade), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 165;
////////			pBuff.nMissileSpeed = 1750;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=96===RUMBLE==========================================================================================================
////////	else if (CheckName( (sz__Rumble), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__RumbleGrenade), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 860;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1300;// game-data=1200
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__RumbleCarpetBombDummy), pBuff.szSpellName))			// R
////////		{//ko lam theo ne EVADE rai bom co the thay doi dc vi tri theo chuot
////////			pBuff.nDelay = 600;
////////			pBuff.nRange = 1200;
////////			pBuff.nRadius = 150;
////////			pBuff.nMissileSpeed = 1600;
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=97===SHYVANA==========================================================================================================
////////	else if (CheckName( (sz__Shyvana), pBuff.szHeroName))
////////	{
////////		if (CheckName(pBuff.szSpellName,  (sz__ShyvanaFireball)))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 60;
////////			pBuff.nMissileSpeed = 1200;// data-game = 700
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName,  (sz__ShyvanaFireballDragon2)))			// E2
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 150;
////////			pBuff.nMissileSpeed = 1200;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ShyvanaTransformLeap), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = 700;// data-game = 700
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//=98===SION==========================================================================================================
////////	else if (CheckName( (sz__Sion), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__SionQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 870;
////////			pBuff.nRange = 600;
////////			pBuff.nRadius = 180;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__SionE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 800;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//101===ZIGGS==========================================================================================================
////////	else if (CheckName( (sz__Ziggs), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__ZiggsQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 850;
////////			pBuff.nRadius = 50;
////////			pBuff.nMissileSpeed = 1700;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ZiggsW), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 220;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ZiggsE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 300;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 180;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 1;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName( (sz__ZiggsR), pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 1100;
////////			pBuff.nRange = 5300;
////////			pBuff.nRadius = 420;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 4;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//102===ZAC==========================================================================================================
////////	else if (CheckName( (sz__Zac), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__ZacQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 500;
////////			pBuff.nRange = 550;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	//103===ANNIE==========================================================================================================
////////	else if (CheckName( (sz__Annie), pBuff.szHeroName))
////////	{
////////		if (CheckName( "AnnieR", pBuff.szSpellName))			// R
////////		{
////////			pBuff.nDelay = 1050;
////////			pBuff.nRange = 600;
////////			pBuff.nRadius = 230;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 5;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
////////	//107===TRYNDAMERE==========================================================================================================
////////	else if (CheckName(pBuff.szHeroName,  (sz__Tryndamere)))
////////	{
////////		if (CheckName( (sz__TryndamereE), pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 710;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1250;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
//////////108===TALIYAH==========================================================================================================
////////	else if (CheckName(  (sz__Taliyah), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__TaliyahQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1800;//game-data = 3600
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		if (CheckName( (sz__TaliyahW), pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 700;
////////			pBuff.nRange = 900;
////////			pBuff.nRadius = 115;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
//////////=109===RAKAN==========================================================================================================
////////	else if (CheckName( (sz__Rakan), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__RakanQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 850;
////////			pBuff.nRadius = 65;
////////			pBuff.nMissileSpeed = 1350;//game-data = 1850
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
//////////=110===XAYAH==========================================================================================================
////////	else if (CheckName( (sz__Xayah), pBuff.szHeroName))
////////	{
////////		if (CheckName( (sz__XayahQ), pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 300;//game-data = 250
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 50;
////////			pBuff.nMissileSpeed = 1750;//game-data = 700
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
//////////=111===FIORA==========================================================================================================
////////	else if (CheckName(sz__Fiora, pBuff.szHeroName))
////////	{
////////		if (CheckName(sz__FioraW, pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 475;
////////			pBuff.nRange = 775;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 3500;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
//////////=112===Syndra==========================================================================================================
////////	else if (CheckName(sz__Syndra, pBuff.szHeroName))
////////	{
////////		if (CheckName(sz__SyndraQ, pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 625;
////////			pBuff.nRange = 800;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = MAX_INT;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName("SyndraWCast", pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 950;
////////			pBuff.nRadius = 150;
////////			pBuff.nMissileSpeed = 1350;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName("SyndraE5", pBuff.szSpellName))			// E-to
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1220;
////////			pBuff.nRadius = 128;
////////			pBuff.nMissileSpeed = 2850;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName(pBuff.szSpellName, "SyndraE"))			// E-nho
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1220;
////////			pBuff.nRadius = 128;
////////			pBuff.nMissileSpeed = 2850;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////
//////////=113===Orianna==========================================================================================================
////////	else if (CheckName(sz__Orianna, pBuff.szHeroName))
////////	{
////////		if (CheckName("OrianaIzunaCommand", pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 150;
////////			pBuff.nRange = 850;
////////			pBuff.nRadius = 90;
////////			pBuff.nMissileSpeed = 1650;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	else if (CheckName("Zoe", pBuff.szHeroName))
////////	{
////////		if (CheckName("ZoeE", pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = true;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	else if (CheckName("Pyke", pBuff.szHeroName))
////////	{
////////		if (CheckName("PykeQRange", pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1100;
////////			pBuff.nRadius = 80;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////		else if (CheckName("PykeE", pBuff.szSpellName))			// E
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 550;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	else if (CheckName("Irelia", pBuff.szHeroName))
////////	{
////////		if (CheckName("IreliaR", pBuff.szSpellName))			// Q
////////		{
////////			pBuff.nDelay = 250;
////////			pBuff.nRange = 1000;
////////			pBuff.nRadius = 160;
////////			pBuff.nMissileSpeed = 2000;
////////			pBuff.nDangerValue = 3;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}
////////	else if (CheckName("Kaisa", pBuff.szHeroName))
////////	{
////////		if (CheckName("KaisaW", pBuff.szSpellName))			// W
////////		{
////////			pBuff.nDelay = 150;
////////			pBuff.nRange = 3000;
////////			pBuff.nRadius = 120;
////////			pBuff.nMissileSpeed = 1500;
////////			pBuff.nDangerValue = 2;
////////			pBuff.nIsDangerous = false;
////////			pBuff.nFlag_TruocSau = false;
////////		}
////////	}

}
