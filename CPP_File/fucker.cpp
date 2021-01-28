#include "fucker.h"
#include "DelayAction.h"
#include "EvadeUtils.h"
#include "Spell.h"
#include "SpellDetector.h"
#include "Evade.h"
#include "EvadeSpells.h"
#include "SpecialEvadeSpell.h"
#include "SpellSpecial.h"

extern CIniFile* menu_IniFile;
cb_UseSpellFunc useSpellFunc_CB = 0;

DelayAction*		_DelayAction		= 0;
EvadeUtils*			_EvadeUtils			= 0;
SpellDetector*		_SpellDetector		= 0;
SpellDatabase*		_SpellDatabase		= 0;
EvadeSpellDatabase* _EvadeSpellDatabase = 0;
EvadeSpell*			_EvadeSpell			= 0;
PositionInfo*		_PositionInfo		= 0;

Evade*				_Evade				= 0;
EvadeHelper*		_EvadeHelper		= 0;
EvadeCommand*		_EvadeCommand		= 0;

//extern Position*			_Position;

extern bool DodgeSkillShots_menu, Enabled_NewEvade_MENU;
//-------------------------------------------------//-----------------------//----------
std::string str_tolower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower
		// static_cast<int(*)(int)>(std::tolower)         // wrong
		// [](int c){ return std::tolower(c); }           // wrong
		// [](char c){ return std::tolower(c); }          // wrong
		//[](unsigned char c){ return std::tolower(c); } // correct
	);
	return s;
}

//-------------------------------------------------//-----------------------//----------
float BoundRadius(KNpc* unit)
{
	return GetBoundingRadius(unit);

	//return 75.0f;
}

float BoundRadius_Minion(KNpc* unit)
{
	return 65.0f;
}
//-------------------------------------------------//-----------------------//----------
void InitClass_Evade()	//*********
{
	if (_DelayAction	== 0)		_DelayAction		= new DelayAction;
	if (_EvadeUtils		== 0)		_EvadeUtils			= new EvadeUtils;
	if (_SpellDatabase	== 0)		_SpellDatabase		= new SpellDatabase;
	
	
	
	if (_EvadeSpellDatabase	== 0)
	{
		_EvadeSpellDatabase = new EvadeSpellDatabase;
		LoadEvadeSpellList();
	}
	
	if (_EvadeSpell	== 0)			_EvadeSpell = new EvadeSpell;

	if (_SpellDetector	== 0)
	{
		_SpellDetector		= new SpellDetector;
		LoadSpellDictionary();
		InitChannelSpells();

		//for (std::map<std::string, std::string>::iterator it = _SpellDetector->channeledSpells.begin(); it!= _SpellDetector->channeledSpells.end(); ++it)
		//{
		//	__oMsg("channeledSpells: [%s]						   = %s", it->first.c_str(), it->second.c_str());
		//}
		//__oMsg("--------------------------------\n");

		//for (std::map<std::string, SpellData>::iterator it = _SpellDetector->onProcessSpells->begin(); it!= _SpellDetector->onProcessSpells->end(); ++it)
		//{
		//	SpellData xxx = it->second;
		//	__oMsg("onProcessSpells: it.1 = %s, it.2.spellName= %s, it.2.missileName=%s, size=%d", it->first.c_str(), it->second.spellName.c_str(), it->second.missileName.c_str(), _SpellDetector->onProcessSpells->size());
		//}

		//__oMsg("--------------------------------\n");
		//for (std::map<std::string, SpellData>::iterator it = _SpellDetector->onMissileSpells->begin(); it!= _SpellDetector->onMissileSpells->end(); ++it)
		//{
		//	__oMsg("onMissileSpells: it.1 = %s, it.2.spellName= %s, it.2.missileName= = %s, size=%d", it->first.c_str(), it->second.spellName.c_str(), it->second.missileName.c_str(), _SpellDetector->onMissileSpells->size());
		//}
	}

	//for (std::map<int, Spell>::iterator it = _SpellDetector->detectedSpells->begin(); it!= _SpellDetector->detectedSpells->end(); ++it)
	//{
	//	Spell spell = it->second;
	//	if (spell.predictedEndPos.x != 0 && spell.predictedEndPos.z != 0)
	//	{
	//		__oMsg(" ANH EM OI");
	//	}
	//}
	
	if (_PositionInfo	== 0)		_PositionInfo		= new PositionInfo;
	if (_Evade			== 0)		_Evade				= new Evade;
	if (_EvadeHelper	== 0)		_EvadeHelper		= new EvadeHelper;
	if (_EvadeCommand	== 0)		_EvadeCommand		= new EvadeCommand;

	//if (_Position		== 0)		_Position			= new Position;
}

//-------------------------------------------------//-----------------------//----------
bool AllClassReady()	//*********
{
	if (!_DelayAction || !_EvadeUtils || !_SpellDetector || !_SpellDatabase || !_EvadeSpellDatabase || !_EvadeSpell || !_Evade || !_PositionInfo || !_EvadeHelper)
		return false;
	return true;
}

//-------------------------------------------------//-----------------------//----------
class test_fuck
{
public:
	bool		aaa;
	float		bbb;
	int			ccc;
	test_fuck(bool _aaa, float _bbb, int _ccc)
	{
		aaa = _aaa;
		bbb = _bbb;
		ccc = _ccc;
	}
};
bool sort_111(test_fuck p1, test_fuck p2)
{
	if (p1.aaa < p2.aaa) return true;
	else if (p1.aaa > p2.aaa) return false;
	
	if (p1.bbb > p2.bbb) return true;
	else if (p1.bbb < p2.bbb) return false;

	if (p1.ccc < p2.ccc) return true;
	else if (p1.ccc > p2.ccc) return false;

	return false;

	
}

//-------------------------------------------------//-----------------------//----------
void OnGameUpdate_DelayAction()		//*********
{
	if (_DelayAction == 0) return;

	_DelayAction->DelayAction_OnOnUpdate();


	//std::vector<test_fuck> xxx;
	//test_fuck a1(true , 999, 5);
	//test_fuck a2(false, 222, 4);
	//test_fuck a3(true , 999, 1);
	//test_fuck a4(false, 777, 5);
	//test_fuck a5(false, 555, 9);
	//test_fuck a6(true , 222, 0);
	//test_fuck a7(true , 999, 8);

	//xxx.push_back(a1);
	//xxx.push_back(a2);
	//xxx.push_back(a3);
	//xxx.push_back(a4);
	//xxx.push_back(a5);
	//xxx.push_back(a6);
	//xxx.push_back(a7);

	//std::sort(xxx.begin(), xxx.end(), sort_111);
	////std::sort(xxx.begin(), xxx.end(), sort_222);

	//for (int i = 0; i<(int)xxx.size(); i++)
	//{
	//	__oMsg("%d -- %.2f -- %d", xxx[i].aaa, xxx[i].bbb, xxx[i].ccc);
	//}
	//__oMsg("-----------------------\n");
}



//-------------------------------------------------//-----------------------//----------
void OnGameUpdate_ezEvade_4DRAWING()
{
	if (AllClassReady() == false) return;

	if (Enabled_NewEvade_MENU == false) return;


	//--------SpellDrawer--------:
	extern void OnDraw_SpellDrawer();
	//__try
	{
		OnDraw_SpellDrawer();
	}
	//__except(EXCEPTION_EXECUTE_HANDLER)
	//{
	//	//__oMsg("ERROR : OnDraw.SpellDrawer - error");
	//	SEND_TEXT_SYSTEM("ERROR : OnDraw.SpellDrawer - error");
	//	
	//}



	//Test_misile();
}

//-------------------------------------------------//-----------------------//----------
float nTimeBlockMouse = 0;
void OnGameUpdate_ezEvade()
{
	InitClass_Evade();
	if (AllClassReady() == false) return;
	
	if(Enabled_NewEvade_MENU == false) return;



	//----------Block + UnBlock------:
	if (DodgeSkillShots_menu == true)
	{
		if (_Evade->isDodging == true)
		{
			Block_RightClick_FromUser();
			nTimeBlockMouse = (float)GetTickCount();
		}
		else
		{
			if ((float)GetTickCount() - nTimeBlockMouse > 50)
				UnBlock_RightClick_FromUser();
		}
	}

	//----------DelayAction------:
	__try
	{
		OnGameUpdate_DelayAction();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		//__oMsg("ERROR : OnGameUpdate.DelayAction - error");
		SEND_TEXT_SYSTEM("ERROR : OnGameUpdate.DelayAction - error");
		
	}

	//----------SpellDetector------:
	__try
	{
		OnGameUpdate_SpellDetector();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		//__oMsg("ERROR : OnGameUpdate.SpellDetector - error");
		SEND_TEXT_SYSTEM("ERROR : OnGameUpdate.SpellDetector - error");
		
	}
	
	//---------SpellDetector OnProcessSpell-------:
	__try
	{
		OnProcessSpell_SpellDetector();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		//__oMsg("ERROR : OnProcessSpell.SpellDetector - error");
		SEND_TEXT_SYSTEM("ERROR : OnProcessSpell.SpellDetector - error");
	}

	//---------SpellMissile-------:
	__try
	{
		OnCreate_SpellMissile();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{ 
		//__oMsg("ERROR : SpellMissile.OnCreate.Evade - error"); 
		SEND_TEXT_SYSTEM("ERROR : SpellMissile.OnCreate.Evade - error");
		
	}
	
	Evade_SpellSpecial();

	//--------Evade--------:
	OnGameUpdate_Evade();	//co try - __except roi

	
	//////////--------SpellDrawer--------:
	////////extern void OnDraw_SpellDrawer();
	////////__try
	////////{
	////////	OnDraw_SpellDrawer();
	////////}
	////////__except(EXCEPTION_EXECUTE_HANDLER)
	////////{
	////////	__oMsg("ERROR : OnDraw.SpellDrawer - error");
	////////	SEND_TEXT_SYSTEM("ERROR : OnDraw.SpellDrawer - error");
	////////	
	////////}	
}


//-------------------------------------------------//-----------------------//----------
void InitChannelSpells()			// ham nay dang ra o spellDetector
{
	_SpellDetector->channeledSpells["drain"]					= "FiddleSticks";
	_SpellDetector->channeledSpells["crowstorm"]				= "FiddleSticks";
	_SpellDetector->channeledSpells["katarinar"]				= "Katarina";
	_SpellDetector->channeledSpells["absolutezero"]				= "Nunu";
	_SpellDetector->channeledSpells["galioidolofdurand"]		= "Galio";
	_SpellDetector->channeledSpells["missfortunebullettime"]	= "MissFortune";
	_SpellDetector->channeledSpells["meditate"]					= "MasterYi";
	_SpellDetector->channeledSpells["malzaharr"]				= "Malzahar";
	_SpellDetector->channeledSpells["reapthewhirlwind"]			= "Janna";
	_SpellDetector->channeledSpells["karthusfallenone"]			= "Karthus";
	_SpellDetector->channeledSpells["karthusfallenone2"]		= "Karthus";
	_SpellDetector->channeledSpells["velkozr"]					= "Velkoz";
	_SpellDetector->channeledSpells["xerathlocusofpower2"]		= "Xerath";
	_SpellDetector->channeledSpells["zace"]						= "Zac";
	_SpellDetector->channeledSpells["pantheon_heartseeker"]		= "Pantheon";
	_SpellDetector->channeledSpells["jhinr"]					= "Jhin";
	_SpellDetector->channeledSpells["odinrecall"]				= "AllChampions";
	_SpellDetector->channeledSpells["recall"]					= "AllChampions";
}

//-------------------------------------------------//-----------------------//----------
bool sort_danger_X(EvadeSpellData p1, EvadeSpellData p2)	
{
	return (p1.dangerlevel < p2.dangerlevel);			//so sanh lay so be hon
}

//-------------------------------------------------//-----------------------//----------
void LoadEvadeSpellList()
{
	if (_EvadeSpell	== 0)			_EvadeSpell = new EvadeSpell;

	KNpc* myHero = GetPlayer();
	if (!myHero) return;

	for(int iii=0; iii < (int)_EvadeSpellDatabase->vSpells->size(); ++iii)
	{
		if (_EvadeSpellDatabase->vSpells->at(iii).charName.compare(myHero->GetNameHero()) == 0 || _EvadeSpellDatabase->vSpells->at(iii).charName.compare("AllChampions") == 0)
		{
			if (_EvadeSpellDatabase->vSpells->at(iii).isSummonerSpell == true)
			{
				SpellSlot spellKey = GetSummonerSlot(_EvadeSpellDatabase->vSpells->at(iii).spellName.c_str());
				if (spellKey == Unknown_slot)
				{
					continue;
				}
				else
				{
					_EvadeSpellDatabase->vSpells->at(iii).spellKey = spellKey;
				}
			}

			/*if (spell.isItem)
			{
				itemSpells.Add(spell);
				continue;
			}*/

			if (_EvadeSpellDatabase->vSpells->at(iii).isSpecial)
			{
				LoadSpecialSpell(_EvadeSpellDatabase->vSpells->at(iii));
			}
			
			char slotName[9];
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey == 0) sprintf_s(slotName, "%s", "Q");
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey == 1) sprintf_s(slotName, "%s", "W");
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey == 2) sprintf_s(slotName, "%s", "E");
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey == 3) sprintf_s(slotName, "%s", "R");
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey == 4) sprintf_s(slotName, "%s", "D");
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey == 5) sprintf_s(slotName, "%s", "F");
			if(_EvadeSpellDatabase->vSpells->at(iii).spellKey >= 6) sprintf_s(slotName, "%s%d", "Slot ", _EvadeSpellDatabase->vSpells->at(iii).spellKey);
			

			char CharName_SpellName[256];
			sprintf_s(CharName_SpellName, "%s - %s%s%s%s", /*_EvadeSpellDatabase->vSpells->at(iii).charName.c_str()*/ myHero->GetNameHero(), _EvadeSpellDatabase->vSpells->at(iii).name.c_str(), " (", slotName, ")");
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.NameMenu = CharName_SpellName;

			/*if (spell.isItem)
			{
				menuName = spell.name + " Settings";
			}*/
			
			char tmpchar_1[128];
			sprintf_s(tmpchar_1, "%s%s", _EvadeSpellDatabase->vSpells->at(iii).name.c_str(), " UseEvadeSpell");
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.UseSpell_Name = tmpchar_1;
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.UseSpell	  = true;
			
			char tmpchar_2[128];
			sprintf_s(tmpchar_2, "%s%s", _EvadeSpellDatabase->vSpells->at(iii).name.c_str(), " EvadeSpellDangerLevel");
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.EvadeSpellDangerLevel_Name = tmpchar_2;
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.EvadeSpellDangerLevel	   = _EvadeSpellDatabase->vSpells->at(iii).dangerlevel - 1;
			
			char tmpchar_3[128];
			sprintf_s(tmpchar_3, "%s%s", _EvadeSpellDatabase->vSpells->at(iii).name.c_str(), " EvadeSpellMode");
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.EvadeSpellMode_Name = tmpchar_3;
			_EvadeSpellDatabase->vSpells->at(iii).esSetting.EvadeSpellMode  	= GetDefaultSpellMode(_EvadeSpellDatabase->vSpells->at(iii));
			
			_EvadeSpell->evadeSpells->push_back(_EvadeSpellDatabase->vSpells->at(iii));
		}	
	}
	std::sort(_EvadeSpell->evadeSpells->begin(), _EvadeSpell->evadeSpells->end(), sort_danger_X);	//so sanh lay so be hon
}

//-------------------------------------------------//-----------------------//----------
void defaultValue_ListEvadeSpells()
{
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)
	{
		_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell              = menu_IniFile->ReadBoolean("Setting_EvadeSpells", (char*)_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell_Name.c_str(), _EvadeSpell->evadeSpells->at(i).esSetting.UseSpell);
		_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel = menu_IniFile->ReadInteger("Setting_EvadeSpells", (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel_Name.c_str(), _EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel);
		_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode	    = menu_IniFile->ReadInteger("Setting_EvadeSpells", (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode_Name.c_str(), _EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode);
	}
}

//-------------------------------------------------//-----------------------//----------
void setting_ListEvadeSpells_Menu()
{	
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)
	{
		if (Menu_Begin((char*)_EvadeSpell->evadeSpells->at(i).esSetting.NameMenu.c_str()))
		{
			Menu_Bool("Use Spell", (char*)_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell, "Setting_EvadeSpells");
			Menu_ComboBox("Danger Level", (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel, "Low\0Normal\0High\0Extreme\0\0", "Setting_EvadeSpells");
			Menu_ComboBox("Spell Mode", (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode, "Undodgeable\0Activation Time\0Always\0\0", "Setting_EvadeSpells");
			Menu_End();
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void setting_ListEvadeSpells_Menu_VN()
{	
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)
	{
		if (Menu_Begin((char*)_EvadeSpell->evadeSpells->at(i).esSetting.NameMenu.c_str()))
		{
			Menu_Bool(ConvertToUTF8(L"Sử Dụng Spell"), (char*)_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell, "Setting_EvadeSpells");
			Menu_ComboBox(ConvertToUTF8(L"Mức Độ Nguy Hiểm"), (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel, "Low\0Normal\0High\0Extreme\0\0", "Setting_EvadeSpells");
			Menu_ComboBox(ConvertToUTF8(L"Chế Độ Sử Dụng Spell"), (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode, "Undodgeable\0Activation Time\0Always\0\0", "Setting_EvadeSpells");
			Menu_End();
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void setting_ListEvadeSpells_Menu_CN()
{
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)
	{
		if (Menu_Begin((char*)_EvadeSpell->evadeSpells->at(i).esSetting.NameMenu.c_str()))
		{
			Menu_Bool(ConvertToUTF8(L"使用技能"), (char*)_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.UseSpell, "Setting_EvadeSpells");
			Menu_ComboBox(ConvertToUTF8(L"危险等级"), (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellDangerLevel, "Low\0Normal\0High\0Extreme\0\0", "Setting_EvadeSpells");
			Menu_ComboBox(ConvertToUTF8(L"技能躲避模式"), (char*)_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode_Name.c_str(), &_EvadeSpell->evadeSpells->at(i).esSetting.EvadeSpellMode, "Undodgeable\0Activation Time\0Always\0\0", "Setting_EvadeSpells");
			Menu_End();
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void LoadSpellDictionary()			// ham nay dang ra o spellDetector
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;


	//LoadSpecialSpellPlugins();
	
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + hModule;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)tempHero;
	DWORD dw2 = *(DWORD*)tempHeroMax;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	for (int kk = 0; kk < nCount; ++kk)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
		if (dw3 == 0) continue;
		KNpc *hero = (KNpc*)dw3;

		//if (hero == myHero /*|| Evade.devModeOn/*)
		//{
		//	foreach (var spell in SpellWindupDatabase.Spells.Where(
		//		s => (s.charName == hero.ChampionName)))
		//	{
		//		if (!windupSpells.ContainsKey(spell.spellName))
		//		{
		//			windupSpells.Add(spell.spellName, spell);
		//		}
		//	}
		//}

		if (hero->nTeam_ID != myHero->nTeam_ID /*|| Evade.devModeOn*/)
		{
			/*foreach (var spell in SpellDatabase.Spells.Where(
				s => (s.charName == hero.ChampionName) || (s.charName == "AllChampions")))
			{
				if (spell.hasTrap && spell.projectileSpeed > 3000)
				{
					if (spell.charName == "AllChampions")
					{
						var slot = hero.GetSpellSlot(spell.spellName);
						if (slot == SpellSlot.Unknown)
						{
							continue;
						}
					}

					if (!onProcessSpells.ContainsKey(spell.spellName.ToLower() + "trap"))
					{
						if (string.IsNullOrEmpty(spell.trapBaseName))
							spell.trapBaseName = spell.spellName + "1";

						if (string.IsNullOrEmpty(spell.trapTroyName))
							spell.trapTroyName = spell.spellName + "2";

						onProcessTraps.Add(spell.trapBaseName.ToLower(), spell);
						onProcessTraps.Add(spell.trapTroyName.ToLower(), spell);
						onProcessSpells.Add(spell.spellName.ToLower() + "trap", spell);

						LoadSpecialSpell(spell);

						string menuName = spell.charName + " (" + spell.spellKey.ToString() + ") Settings";

						var enableSpell = !spell.defaultOff;
						var trapSpellName = spell.spellName + "_trap";

						Menu newSpellMenu = new Menu(menuName, spell.charName + trapSpellName + "Settings").SetFontStyle(FontStyle.Regular, Color.SkyBlue);
						newSpellMenu.AddItem(new MenuItem(trapSpellName + "DrawSpell", "Draw Trap").SetValue(true));
						newSpellMenu.AddItem(new MenuItem(trapSpellName + "DodgeSpell", "Dodge Trap [Beta]")
							.SetValue(enableSpell)).SetTooltip(spell.name)
							.SetFontStyle(FontStyle.Regular, Color.SkyBlue);
						newSpellMenu.AddItem(new MenuItem(trapSpellName + "SpellRadius", "Trap Radius")
							.SetValue(new Slider((int)spell.radius, (int)spell.radius - 100, (int)spell.radius + 100)));
						newSpellMenu.AddItem(new MenuItem(trapSpellName + "DodgeIgnoreHP", "Dodge Only Below HP % <="))
							.SetValue(new Slider(Math.Max(0, spell.dangerlevel - 1) == 1 ? 90 : 100));
						newSpellMenu.AddItem(new MenuItem(trapSpellName + "DangerLevel", "Danger Level")
							.SetValue(new StringList(new[] { "Low", "Normal", "High" }, Math.Max(0, spell.dangerlevel - 1))));

						trapMenu.AddSubMenu(newSpellMenu);
					}
				}
			}*/


			for(int iii=0; iii < (int)_SpellDatabase->vSpells->size(); iii++)
			{
				SpellData spell = _SpellDatabase->vSpells->at(iii);
				if(CheckNameEx(hero->GetNameHero(), (char*)spell.charName.c_str()) || CheckName("AllChampions", (char*)spell.charName.c_str()))
				{
					if (spell.hasTrap && spell.projectileSpeed < 3000 || !spell.hasTrap)
					{
						if (spell.spellType != Circular && spell.spellType != Line && spell.spellType != Arc_x && spell.spellType != Cone) continue;
							
						//if (spell.charName == "AllChampions")
						//{
						//	var slot = hero.GetSpellSlot(spell.spellName);
						//	if (slot == SpellSlot.Unknown)
						//	{
						//		continue;
						//	}
						//}
						
						std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell.spellName)); //C#: ContainsKey
						if (it_onProcessSpells == _SpellDetector->onProcessSpells->end())
						{
							if(spell.missileName.empty()) spell.missileName = spell.spellName;

							_SpellDetector->onProcessSpells->insert(std::pair<std::string, SpellData> (str_tolower(spell.spellName), spell));
							_SpellDetector->onMissileSpells->insert(std::pair<std::string, SpellData> (str_tolower(spell.missileName), spell));

							if (spell.extraSpellNames.size() != 0)
							{
								for(int j=0; j < (int)spell.extraSpellNames.size(); j++)
								{
									_SpellDetector->onProcessSpells->insert(std::pair<std::string, SpellData> (str_tolower(spell.extraSpellNames[j]), spell));
								}
							}
							
							if (spell.extraMissileNames.size() != 0)
							{
								for(int j=0; j < (int)spell.extraMissileNames.size(); j++)
								{
									_SpellDetector->onMissileSpells->insert(std::pair<std::string, SpellData> (str_tolower(spell.extraMissileNames[j]), spell));
								}
							}

							//LoadSpecialSpell(spell);

						}
						
						std::map<std::string, SpellData>::iterator it_oPs_2 = _SpellDetector->onProcessSpells->find(str_tolower(spell.spellName)); 
						if (it_oPs_2 != _SpellDetector->onProcessSpells->end())
						{
							it_oPs_2->second.sSetting.NameMenu		  = spell.name;
							it_oPs_2->second.sSetting.key_spell		  = spell.spellName;
							it_oPs_2->second.sSetting.key_spell_lower = str_tolower(spell.spellName);
							
							char slotName[9] = {0};
							if(spell.spellKey == 0) sprintf_s(slotName, "%s", "Q");
							if(spell.spellKey == 1) sprintf_s(slotName, "%s", "W");
							if(spell.spellKey == 2) sprintf_s(slotName, "%s", "E");
							if(spell.spellKey == 3) sprintf_s(slotName, "%s", "R");
							if(spell.spellKey == 4) sprintf_s(slotName, "%s", "D");
							if(spell.spellKey == 5) sprintf_s(slotName, "%s", "F");
							if(spell.spellKey >= 6 && spell.spellKey <= 100) sprintf_s(slotName, "%s%d", "Slot ", spell.spellKey);

							if(spell.spellKey == 101) sprintf_s(slotName, "%s", "Q1");
							if(spell.spellKey == 102) sprintf_s(slotName, "%s", "Q2");
							if(spell.spellKey == 103) sprintf_s(slotName, "%s", "Q3");
							if(spell.spellKey == 104) sprintf_s(slotName, "%s", "Q4");
							if(spell.spellKey == 105) sprintf_s(slotName, "%s", "Q5");

							if(spell.spellKey == 111) sprintf_s(slotName, "%s", "W1");
							if(spell.spellKey == 112) sprintf_s(slotName, "%s", "W2");
							if(spell.spellKey == 113) sprintf_s(slotName, "%s", "W3");
							if(spell.spellKey == 114) sprintf_s(slotName, "%s", "W4");
							if(spell.spellKey == 115) sprintf_s(slotName, "%s", "W5");

							if(spell.spellKey == 121) sprintf_s(slotName, "%s", "E1");
							if(spell.spellKey == 122) sprintf_s(slotName, "%s", "E2");
							if(spell.spellKey == 123) sprintf_s(slotName, "%s", "E3");
							if(spell.spellKey == 124) sprintf_s(slotName, "%s", "E4");
							if(spell.spellKey == 125) sprintf_s(slotName, "%s", "E5");

							if(spell.spellKey == 131) sprintf_s(slotName, "%s", "R1");
							if(spell.spellKey == 132) sprintf_s(slotName, "%s", "R2");
							if(spell.spellKey == 133) sprintf_s(slotName, "%s", "R3");
							if(spell.spellKey == 134) sprintf_s(slotName, "%s", "R4");
							if(spell.spellKey == 135) sprintf_s(slotName, "%s", "R5");

							//__oMsg("vaolol-3: %s %s [%d]", slotName, spell.charName.c_str(), spell.spellKey);
							char HeroAndSpell[128];
							sprintf_s(HeroAndSpell, "%s%s%s%s", spell.charName.c_str(), " (", slotName, ") Settings");
							it_oPs_2->second.sSetting.Hero_spell = HeroAndSpell;
							
							char tmpchar_1[128];
							sprintf_s(tmpchar_1, "%s%s", spell.spellName.c_str(), " DrawSpell");
							it_oPs_2->second.sSetting.DrawSpell_Name = tmpchar_1;
							it_oPs_2->second.sSetting.DrawSpell		 = true;
							
							char tmpchar_2[128];
							bool enableSpell = !spell.defaultOff;
							bool isnewSpell  = CheckName("[Beta]", (char*)spell.name.c_str()) || spell.spellType == Cone;
							if (isnewSpell) sprintf_s(tmpchar_2, "%s%s", spell.spellName.c_str(), " DodgeSpell [Beta]");
							else			sprintf_s(tmpchar_2, "%s%s", spell.spellName.c_str(), " Dodge Spell");
							it_oPs_2->second.sSetting.DodgeSpell_Name = tmpchar_2;
							it_oPs_2->second.sSetting.DodgeSpell	  = enableSpell;

							char tmpchar_3[128];
							sprintf_s(tmpchar_3, "%s%s", spell.spellName.c_str(), " SpellRadius");
							it_oPs_2->second.sSetting.SpellRadius_Name = tmpchar_3;
							it_oPs_2->second.sSetting.SpellRadius	   = spell.radius;

							char tmpchar_4[128];
							sprintf_s(tmpchar_4, "%s%s", spell.spellName.c_str(), " FastEvade");
							it_oPs_2->second.sSetting.FastEvade_Name = tmpchar_4;
							it_oPs_2->second.sSetting.FastEvade	     = (spell.dangerlevel == 4) ? true : false;

							char tmpchar_5[128];
							sprintf_s(tmpchar_5, "%s%s", spell.spellName.c_str(), " DodgeIgnoreHP");
							it_oPs_2->second.sSetting.DodgeIgnoreHP_Name = tmpchar_5;
							it_oPs_2->second.sSetting.DodgeIgnoreHP	     = (spell.dangerlevel == 1) ? 90.0f : 100.0f;

							char tmpchar_6[128];
							sprintf_s(tmpchar_6, "%s%s", spell.spellName.c_str(), " DangerLevel");
							it_oPs_2->second.sSetting.DangerLevel_Name = tmpchar_6;
							it_oPs_2->second.sSetting.DangerLevel	   = spell.dangerlevel - 1;

							char tmpchar_7[128];
							sprintf_s(tmpchar_7, "%s%s", spell.spellName.c_str(), " ReactionTime");
							it_oPs_2->second.sSetting.ReactionTime_Name	 = tmpchar_7;
							it_oPs_2->second.sSetting.ReactionTime	     = 0;
						}
						
					}
				}
			}
		}	
	}
}

//-------------------------------------------------//-----------------------//----------
void defaultValue_ListSpellsEnemy()
{
	for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
	{
		if (CheckName((char*)it_xxx->first.c_str(), (char*)str_tolower(it_xxx->second.spellName).c_str()) == false) continue;
		
		it_xxx->second.sSetting.DodgeSpell    = menu_IniFile->ReadBoolean("Setting_Spells", (char*)it_xxx->second.sSetting.DodgeSpell_Name.c_str()	 , it_xxx->second.sSetting.DodgeSpell);
		it_xxx->second.sSetting.DrawSpell     = menu_IniFile->ReadBoolean("Setting_Spells", (char*)it_xxx->second.sSetting.DrawSpell_Name.c_str()	 , true);
		it_xxx->second.sSetting.FastEvade     = menu_IniFile->ReadBoolean("Setting_Spells", (char*)it_xxx->second.sSetting.FastEvade_Name.c_str()	 , it_xxx->second.sSetting.FastEvade);
		it_xxx->second.sSetting.ReactionTime  = menu_IniFile->ReadFloat  ("Setting_Spells", (char*)it_xxx->second.sSetting.ReactionTime_Name.c_str() , it_xxx->second.sSetting.ReactionTime);
		it_xxx->second.sSetting.SpellRadius	  = menu_IniFile->ReadFloat  ("Setting_Spells", (char*)it_xxx->second.sSetting.SpellRadius_Name.c_str()	 , it_xxx->second.sSetting.SpellRadius);
		it_xxx->second.sSetting.DodgeIgnoreHP = menu_IniFile->ReadFloat  ("Setting_Spells", (char*)it_xxx->second.sSetting.DodgeIgnoreHP_Name.c_str(), it_xxx->second.sSetting.DodgeIgnoreHP);
		it_xxx->second.sSetting.DangerLevel	  = menu_IniFile->ReadInteger("Setting_Spells", (char*)it_xxx->second.sSetting.DangerLevel_Name.c_str()	 , it_xxx->second.sSetting.DangerLevel);
	}
}

//-------------------------------------------------//-----------------------//----------
void setting_ListSpellsEnemy_Menu()
{	
	for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
	{
		//__oMsg(" %s ==== %s", (char*)it_xxx->first.c_str(),  (char*)it_xxx->second.spellName.c_str());
		if (CheckName((char*)it_xxx->first.c_str(), (char*)str_tolower(it_xxx->second.spellName).c_str()) == false) continue;
		
		if (Menu_Begin((char*)it_xxx->second.sSetting.Hero_spell.c_str()))
		{
			ImGui::TextColored(ImVec4(1.0f,1.0f,0.0f,1.0f), (char*)it_xxx->second.sSetting.NameMenu.c_str());	//yellow

			Menu_Bool("Dodge Spell", (char*)it_xxx->second.sSetting.DodgeSpell_Name.c_str(), &it_xxx->second.sSetting.DodgeSpell, "Setting_Spells");
			Menu_Bool("Draw Spell" , (char*)it_xxx->second.sSetting.DrawSpell_Name.c_str() , &it_xxx->second.sSetting.DrawSpell , "Setting_Spells");
			Menu_Bool("Force Fast Evade" , (char*)it_xxx->second.sSetting.FastEvade_Name.c_str() , &it_xxx->second.sSetting.FastEvade , "Setting_Spells");
			Menu_SliderFloat("Reaction Time", (char*)it_xxx->second.sSetting.ReactionTime_Name.c_str(), &it_xxx->second.sSetting.ReactionTime, 0, 300, "Setting_Spells");
			Menu_SliderFloat("Spell Radius", (char*)it_xxx->second.sSetting.SpellRadius_Name.c_str(), &it_xxx->second.sSetting.SpellRadius, it_xxx->second.radius - 100, it_xxx->second.radius + 100, "Setting_Spells");
			Menu_SliderFloat("Dodge Only Below HP % <", (char*)it_xxx->second.sSetting.DodgeIgnoreHP_Name.c_str(), &it_xxx->second.sSetting.DodgeIgnoreHP, 0, 100, "Setting_Spells");
			Menu_ComboBox("Danger Level", (char*)it_xxx->second.sSetting.DangerLevel_Name.c_str(), &it_xxx->second.sSetting.DangerLevel, "Low\0Normal\0High\0Extreme\0\0", "Setting_Spells");
			Menu_End();
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void setting_ListSpellsEnemy_Menu_VN()
{	
	for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
	{
		//__oMsg(" %s ==== %s", (char*)it_xxx->first.c_str(),  (char*)it_xxx->second.spellName.c_str());
		if (CheckName((char*)it_xxx->first.c_str(), (char*)str_tolower(it_xxx->second.spellName).c_str()) == false) continue;

		if (Menu_Begin((char*)it_xxx->second.sSetting.Hero_spell.c_str()))
		{
			ImGui::TextColored(ImVec4(1.0f,1.0f,0.0f,1.0f), (char*)it_xxx->second.sSetting.NameMenu.c_str());	//yellow

			Menu_Bool(ConvertToUTF8(L"Né Skill Này"), (char*)it_xxx->second.sSetting.DodgeSpell_Name.c_str(), &it_xxx->second.sSetting.DodgeSpell, "Setting_Spells");
			Menu_Bool(ConvertToUTF8(L"Vẻ Skill Này") , (char*)it_xxx->second.sSetting.DrawSpell_Name.c_str() , &it_xxx->second.sSetting.DrawSpell , "Setting_Spells");
			Menu_Bool(ConvertToUTF8(L"Ép Né Thật Nhanh") , (char*)it_xxx->second.sSetting.FastEvade_Name.c_str() , &it_xxx->second.sSetting.FastEvade , "Setting_Spells");
			Menu_SliderFloat(ConvertToUTF8(L"Reaction Time"), (char*)it_xxx->second.sSetting.ReactionTime_Name.c_str(), &it_xxx->second.sSetting.ReactionTime, 0, 300, "Setting_Spells");
			Menu_SliderFloat(ConvertToUTF8(L"Độ Rộng Skill"), (char*)it_xxx->second.sSetting.SpellRadius_Name.c_str(), &it_xxx->second.sSetting.SpellRadius, it_xxx->second.radius - 100, it_xxx->second.radius + 100, "Setting_Spells");
			Menu_SliderFloat(ConvertToUTF8(L"Chỉ Né Nếu %HP Thấp <"), (char*)it_xxx->second.sSetting.DodgeIgnoreHP_Name.c_str(), &it_xxx->second.sSetting.DodgeIgnoreHP, 0, 100, "Setting_Spells");
			Menu_ComboBox(ConvertToUTF8(L"Mức Độ Nguy Hiểm"), (char*)it_xxx->second.sSetting.DangerLevel_Name.c_str(), &it_xxx->second.sSetting.DangerLevel, "Low\0Normal\0High\0Extreme\0\0", "Setting_Spells");
			Menu_End();
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void setting_ListSpellsEnemy_Menu_CN()
{	
	for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
	{
		//__oMsg(" %s ==== %s", (char)it_xxx->first.c_str(),  (char)it_xxx->second.spellName.c_str());
		if (CheckName((char*)it_xxx->first.c_str(), (char*)str_tolower(it_xxx->second.spellName).c_str()) == false) continue;

		if (Menu_Begin((char*)it_xxx->second.sSetting.Hero_spell.c_str()))
		{
			ImGui::TextColored(ImVec4(1.0f,1.0f,0.0f,1.0f), (char*)it_xxx->second.sSetting.NameMenu.c_str());    //yellow

			Menu_Bool(ConvertToUTF8(L"躲避技能"), (char*)it_xxx->second.sSetting.DodgeSpell_Name.c_str(), &it_xxx->second.sSetting.DodgeSpell, "Setting_Spells");
			Menu_Bool(ConvertToUTF8(L"绘制技能"), (char*)it_xxx->second.sSetting.DrawSpell_Name.c_str() , &it_xxx->second.sSetting.DrawSpell , "Setting_Spells");
			Menu_Bool(ConvertToUTF8(L"强制快速躲避"), (char*)it_xxx->second.sSetting.FastEvade_Name.c_str() , &it_xxx->second.sSetting.FastEvade , "Setting_Spells");
			Menu_SliderFloat(ConvertToUTF8(L"躲避延迟"), (char*)it_xxx->second.sSetting.ReactionTime_Name.c_str(), &it_xxx->second.sSetting.ReactionTime, 0, 300, "Setting_Spells");
			Menu_SliderFloat(ConvertToUTF8(L"额外施法半径"), (char*)it_xxx->second.sSetting.SpellRadius_Name.c_str(), &it_xxx->second.sSetting.SpellRadius, it_xxx->second.radius - 100, it_xxx->second.radius + 100, "Setting_Spells");
			Menu_SliderFloat(ConvertToUTF8(L"只有在血量少于 %时躲避"), (char*)it_xxx->second.sSetting.DodgeIgnoreHP_Name.c_str(), &it_xxx->second.sSetting.DodgeIgnoreHP, 0, 100, "Setting_Spells");
			Menu_ComboBox(ConvertToUTF8(L"技能危险等级"), (char*)it_xxx->second.sSetting.DangerLevel_Name.c_str(), &it_xxx->second.sSetting.DangerLevel, "Low\0Normal\0High\0Extreme\0\0", "Setting_Spells");
			Menu_End();
		}
	}
}


//-------------------------------------------------//-----------------------//----------
void LoadSpellDatabaseFromIniFile()
{
	// TO DO ..
}




