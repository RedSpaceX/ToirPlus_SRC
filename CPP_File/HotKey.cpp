#include "HotKey.h"


int GetHotKey_Combo()
{
	int nKeyAscii = GetAscii_Key(CIniManager::GetInstance()->GetCombo_Key(), 0);
	return nKeyAscii;
}

//--------------------------------------------------------------------------------------------
int GetHotKey_LaneClear()
{
	int nKeyAscii = GetAscii_Key(CIniManager::GetInstance()->GetLaneClear_Key(), 1);
	return nKeyAscii;
}

//--------------------------------------------------------------------------------------------
int GetHotKey_Harass()
{
	int nKeyAscii = GetAscii_Key(CIniManager::GetInstance()->GetHarass_Key(), 2);
	return nKeyAscii;
}

//--------------------------------------------------------------------------------------------
int GetHotKey_LastHit()
{
	int nKeyAscii = GetAscii_Key(CIniManager::GetInstance()->GetLastHit_Key(), 3);
	return nKeyAscii;
}

//--------------------------------------------------------------------------------------------
int GetAscii_Key(char* nKey, int nMode)
{
	int nKeyAscii = 0;

	if		(CheckName(nKey, "SPACE")  && CheckName( "SPACE", nKey))	nKeyAscii = 0x20;
	else if (CheckName(nKey, "A")	   && CheckName( "A", nKey))		nKeyAscii = 0x41;
	else if (CheckName(nKey, "B")	   && CheckName( "B", nKey))		nKeyAscii = 0x42;
	else if (CheckName(nKey, "C")	   && CheckName( "C", nKey))		nKeyAscii = 0x43;
	else if (CheckName(nKey, "D")	   && CheckName( "D", nKey))		nKeyAscii = 0x44;
	else if (CheckName(nKey, "E")	   && CheckName( "E", nKey))		nKeyAscii = 0x45;
	else if (CheckName(nKey, "F")	   && CheckName( "F", nKey))		nKeyAscii = 0x46;
	else if (CheckName(nKey, "G")	   && CheckName( "G", nKey))		nKeyAscii = 0x47;
	else if (CheckName(nKey, "H")	   && CheckName( "H", nKey))		nKeyAscii = 0x48;
	else if (CheckName(nKey, "I")	   && CheckName( "I", nKey))		nKeyAscii = 0x49;
	else if (CheckName(nKey, "J")	   && CheckName( "J", nKey))		nKeyAscii = 0x4A;
	else if (CheckName(nKey, "K")	   && CheckName( "K", nKey))		nKeyAscii = 0x4B;
	else if (CheckName(nKey, "L")	   && CheckName( "L", nKey))		nKeyAscii = 0x4C;
	else if (CheckName(nKey, "M")	   && CheckName( "M", nKey))		nKeyAscii = 0x4D;
	else if (CheckName(nKey, "N")	   && CheckName( "N", nKey))		nKeyAscii = 0x4E;
	else if (CheckName(nKey, "O")	   && CheckName( "O", nKey))		nKeyAscii = 0x4F;
	else if (CheckName(nKey, "P")	   && CheckName( "P", nKey))		nKeyAscii = 0x50;
	else if (CheckName(nKey, "Q")	   && CheckName( "Q", nKey))		nKeyAscii = 0x51;
	else if (CheckName(nKey, "R")	   && CheckName( "R", nKey))		nKeyAscii = 0x52;
	else if (CheckName(nKey, "S")	   && CheckName( "S", nKey))		nKeyAscii = 0x53;
	else if (CheckName(nKey, "T")	   && CheckName( "T", nKey))		nKeyAscii = 0x54;
	else if (CheckName(nKey, "U")	   && CheckName( "U", nKey))		nKeyAscii = 0x55;
	else if (CheckName(nKey, "V")	   && CheckName( "V", nKey))		nKeyAscii = 0x56;
	else if (CheckName(nKey, "W")	   && CheckName( "W", nKey))		nKeyAscii = 0x57;
	else if (CheckName(nKey, "X")	   && CheckName( "X", nKey))		nKeyAscii = 0x58;
	else if (CheckName(nKey, "Y")	   && CheckName( "Y", nKey))		nKeyAscii = 0x59;
	else if (CheckName(nKey, "Z")	   && CheckName( "Z", nKey))		nKeyAscii = 0x5A;

	else if (CheckName(nKey, "0")	   && CheckName( "0", nKey))		nKeyAscii = 0x30;
	else if (CheckName(nKey, "1")	   && CheckName( "1", nKey))		nKeyAscii = 0x31;
	else if (CheckName(nKey, "2")	   && CheckName( "2", nKey))		nKeyAscii = 0x32;
	else if (CheckName(nKey, "3")	   && CheckName( "3", nKey))		nKeyAscii = 0x33;
	else if (CheckName(nKey, "4")	   && CheckName( "4", nKey))		nKeyAscii = 0x34;
	else if (CheckName(nKey, "5")	   && CheckName( "5", nKey))		nKeyAscii = 0x35;
	else if (CheckName(nKey, "6")	   && CheckName( "6", nKey))		nKeyAscii = 0x36;
	else if (CheckName(nKey, "7")	   && CheckName( "7", nKey))		nKeyAscii = 0x37;
	else if (CheckName(nKey, "8")	   && CheckName( "8", nKey))		nKeyAscii = 0x38;
	else if (CheckName(nKey, "9")	   && CheckName( "9", nKey))		nKeyAscii = 0x39;

	else if (CheckName(nKey, ";")	   && CheckName( ";", nKey))		nKeyAscii = 186;
	else if (CheckName(nKey, "=")	   && CheckName( "=", nKey))		nKeyAscii = 187;
	else if (CheckName(nKey, "-")	   && CheckName( "-", nKey))		nKeyAscii = 189;
	else if (CheckName(nKey, "/")	   && CheckName( "/", nKey))		nKeyAscii = 191;
	else if (CheckName(nKey, "`")	   && CheckName( "`", nKey))		nKeyAscii = 192;
	else if (CheckName(nKey, "[")	   && CheckName( "[", nKey))		nKeyAscii = 219;
	else if (CheckName(nKey, "\\")	   && CheckName( "\\", nKey))		nKeyAscii = 220;
	else if (CheckName(nKey, "[")	   && CheckName( "]", nKey))		nKeyAscii = 221;
	else if (CheckName(nKey, "'")	   && CheckName( "'", nKey))		nKeyAscii = 222;

	else if (CheckName(nKey, "TAB")    && CheckName( "TAB", nKey))		nKeyAscii = 9;
	else if (CheckName(nKey, "ENTER")  && CheckName( "ENTER", nKey))	nKeyAscii = 13;
	else if (CheckName(nKey, "SHIFT")  && CheckName( "SHIFT", nKey))	nKeyAscii = 16;
	else if (CheckName(nKey, "CTRL")   && CheckName( "CTRL", nKey))		nKeyAscii = 17;
	//else if (CheckName(nKey, "ALT")	   && CheckName( "ALT", nKey))		nKeyAscii = 18;
	else if (CheckName(nKey, "CAPSLOCK")&& CheckName( "CAPSLOCK", nKey))nKeyAscii = 20;
	else if (CheckName(nKey, "ESC")	   && CheckName( "ESC", nKey))		nKeyAscii = 27;
	
	else if (CheckName(nKey, "F1")	   && CheckName( "F1", nKey))		nKeyAscii = 112;
	else if (CheckName(nKey, "F2")	   && CheckName( "F2", nKey))		nKeyAscii = 113;
	else if (CheckName(nKey, "F3")	   && CheckName( "F3", nKey))		nKeyAscii = 114;
	else if (CheckName(nKey, "F4")	   && CheckName( "F4", nKey))		nKeyAscii = 115;
	else if (CheckName(nKey, "F5")	   && CheckName( "F5", nKey))		nKeyAscii = 116;
	else if (CheckName(nKey, "F6")	   && CheckName( "F6", nKey))		nKeyAscii = 117;
	else if (CheckName(nKey, "F7")	   && CheckName( "F7", nKey))		nKeyAscii = 118;
	else if (CheckName(nKey, "F8")	   && CheckName( "F8", nKey))		nKeyAscii = 119;
	else if (CheckName(nKey, "F9")	   && CheckName( "F9", nKey))		nKeyAscii = 120;
	//else if (CheckName(nKey, "F10")	   && CheckName( "F10", nKey))		nKeyAscii = 121;
	else if (CheckName(nKey, "F11")	   && CheckName( "F11", nKey))		nKeyAscii = 122;
	else if (CheckName(nKey, "F12")	   && CheckName( "F12", nKey))		nKeyAscii = 123;
	
	if		(!nKeyAscii && nMode == 0) nKeyAscii= 0x20;	// default = VK_SPACE
	else if	(!nKeyAscii && nMode == 1) nKeyAscii= 0x56;	// default = V
	else if	(!nKeyAscii && nMode == 2) nKeyAscii= 0x43;	// default = C
	else if	(!nKeyAscii && nMode == 3) nKeyAscii= 0x58;	// default = X
	return nKeyAscii;
}