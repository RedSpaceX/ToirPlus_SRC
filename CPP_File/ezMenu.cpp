#include "ezMenu.h"

extern CIniFile*  menu_IniFile;

char* ezEvadeSection = "NewEvade";
bool Enabled_NewEvade_MENU;

bool DodgeSkillShots_menu, ActivateEvadeSpells_menu;
int  DodgeSkillShots_Key_menu, ActivateEvadeSpells_Key_menu;

bool DodgeDangerous_menu, DodgeFOWSpells_menu, DodgeCircularSpells_menu;
bool DodgeDangerousKeyEnabled_menu, DodgeOnlyOnComboKeyEnabled_menu, DontDodgeKeyEnabled_menu;
int	 DodgeDangerousKey_menu, DodgeDangerousKey2_menu, DodgeComboKey_menu, DontDodgeKey_menu;

bool HigherPrecision_menu, RecalculatePosition_menu, ContinueMovement_menu, CalculateWindupDelay_menu, CheckSpellCollision_menu, PreventDodgingUnderTower_menu, PreventDodgingNearEnemy_menu, AdvancedSpellDetection_menu/*, ClickRemove_menu*/;
int	 EvadeMode_menu;
bool ResetConfig_menu;

bool ClickOnlyOnce_menu, EnableEvadeDistance_menu;
float TickLimiter_menu, SpellDetectionTime_menu, ReactionTime_menu, DodgeInterval_menu;			

bool FastMovementBlock_menu;
float FastEvadeActivationTime_menu, SpellActivationTime_menu, RejectMinDistance_menu;

float ExtraPingBuffer_menu, ExtraCPADistance_menu, ExtraSpellRadius_menu, ExtraEvadeDistance_menu, ExtraAvoidDistance_menu, MinComfortZone_menu;

bool DrawSkillShots_menu, ShowStatus_menu, DrawSpellPos_menu, DrawEvadePosition_menu;
int  LowWidth_menu, LowColor_menu, NormalWidth_menu, NormalColor_menu, HighWidth_menu, HighColor_menu, ExtremeWidth_menu, ExtremeColor_menu;

//-------------------------------------------------//-----------------------//----------
void Init_ezEvade_Menu()
{
	Enabled_NewEvade_MENU				= menu_IniFile->ReadBoolean(ezEvadeSection, "Enable NewEvade", true);

	DodgeSkillShots_menu				= menu_IniFile->ReadBoolean(ezEvadeSection, "Dodge SkillShots", true);
	DodgeSkillShots_Key_menu			= menu_IniFile->ReadInteger(ezEvadeSection, "DodgeSkillShots Key", 75);	//phim K
	ActivateEvadeSpells_menu			= menu_IniFile->ReadBoolean(ezEvadeSection, "Use Evade Spells", true);
	ActivateEvadeSpells_Key_menu 		= menu_IniFile->ReadInteger(ezEvadeSection, "Use Evade Spells Key", 75);	//phim K
	DodgeDangerous_menu					= menu_IniFile->ReadBoolean(ezEvadeSection, "Dodge Only Dangerous", false);
	DodgeFOWSpells_menu					= menu_IniFile->ReadBoolean(ezEvadeSection, "Dodge FOW SkillShots", true);
	DodgeCircularSpells_menu			= menu_IniFile->ReadBoolean(ezEvadeSection, "Dodge Circular SkillShots", true);
	
	extern void defaultValue_ListSpellsEnemy();
	defaultValue_ListSpellsEnemy();

	extern void defaultValue_ListEvadeSpells();
	defaultValue_ListEvadeSpells();

	DodgeDangerousKeyEnabled_menu	= menu_IniFile->ReadBoolean(ezEvadeSection, "Enable Dodge Only Dangerous Keys", false);
	DodgeDangerousKey_menu			= menu_IniFile->ReadInteger(ezEvadeSection, "Dodge Only Dangerous Key", 32);	//phim Space - khi press
	DodgeDangerousKey2_menu			= menu_IniFile->ReadInteger(ezEvadeSection, "Dodge Only Dangerous Key 2", 86);	//phim V - khi press
	DodgeOnlyOnComboKeyEnabled_menu	= menu_IniFile->ReadBoolean(ezEvadeSection, "Enable Dodge Only On Combo Key", false);
	DodgeComboKey_menu				= menu_IniFile->ReadInteger(ezEvadeSection, "Dodge Only Combo Key", 32);		//phim Space - khi press
	DontDodgeKeyEnabled_menu		= menu_IniFile->ReadBoolean(ezEvadeSection, "Enable Dont Dodge Key", false);
	DontDodgeKey_menu				= menu_IniFile->ReadInteger(ezEvadeSection, "Dont Dodge Key", 90);				//phim Z - khi press 

	//---- Misc Settings -- :
	HigherPrecision_menu			= menu_IniFile->ReadBoolean(ezEvadeSection, "Enhanced Dodge Precision", false);
	RecalculatePosition_menu 		= menu_IniFile->ReadBoolean(ezEvadeSection, "Recalculate Path", true);
	ContinueMovement_menu 			= menu_IniFile->ReadBoolean(ezEvadeSection, "Continue Last Movement", true);
	CalculateWindupDelay_menu		= menu_IniFile->ReadBoolean(ezEvadeSection, "Calculate Windup Delay", true);
	CheckSpellCollision_menu		= menu_IniFile->ReadBoolean(ezEvadeSection, "Check Spell Collision", false);
	PreventDodgingUnderTower_menu	= menu_IniFile->ReadBoolean(ezEvadeSection, "Prevent Dodging Under Tower", false);
	PreventDodgingNearEnemy_menu	= menu_IniFile->ReadBoolean(ezEvadeSection, "Prevent Dodging Near Enemies", true);
	AdvancedSpellDetection_menu		= menu_IniFile->ReadBoolean(ezEvadeSection, "Advanced Spell Detection", true);
	//ClickRemove_menu				= menu_IniFile->ReadBoolean(ezEvadeSection, "Allow Left Click Removal", true);
	
		//---- Humanizer:(**CHECKED**)
	ClickOnlyOnce_menu				= menu_IniFile->ReadBoolean(ezEvadeSection, "Click Only Once", true);	
	EnableEvadeDistance_menu		= menu_IniFile->ReadBoolean(ezEvadeSection, "Extended Evade", false);	
	TickLimiter_menu				= menu_IniFile->ReadFloat(ezEvadeSection, "Tick Limiter", 100.0f);
	SpellDetectionTime_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Spell Detection Time", 0);
	//ReactionTime_menu				= menu_IniFile->ReadFloat(ezEvadeSection, "Reaction Time", 0);						//chuyen cai nay vao tung` Spell
	DodgeInterval_menu				= menu_IniFile->ReadFloat(ezEvadeSection, "Dodge Interval", 0);
		//---- Fast evade:
	FastMovementBlock_menu		    = menu_IniFile->ReadBoolean(ezEvadeSection, "Fast Movement Block", false);
	FastEvadeActivationTime_menu	= menu_IniFile->ReadFloat(ezEvadeSection, "FastEvade Activation Time", 65.0f);
	SpellActivationTime_menu		= menu_IniFile->ReadFloat(ezEvadeSection, "Spell Activation Time", 200.0f);			//L#: 400
	RejectMinDistance_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Collision Distance Buffer", 10.0f);
		//---- Extra Buffers:
	ExtraPingBuffer_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Extra Ping Buffer", 65.0f);
	ExtraCPADistance_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Extra Collision Distance", 10.0f);
	ExtraSpellRadius_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Extra Spell Radius", 0);
	ExtraEvadeDistance_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Extra Evade Distance", 75.0f);	//L# 100
	ExtraAvoidDistance_menu			= menu_IniFile->ReadFloat(ezEvadeSection, "Extra Avoid Distance", 50.0f);
	MinComfortZone_menu				= menu_IniFile->ReadFloat(ezEvadeSection, "Min Distance to Champion", 550.0f);
		//---- Evade Mode:
	EvadeMode_menu					= menu_IniFile->ReadInteger(ezEvadeSection, "Evade Mode", 0);
	
	//Draw--Menu-----
	DrawSkillShots_menu				= menu_IniFile->ReadBoolean(ezEvadeSection, "Draw SkillShots", true);
	ShowStatus_menu					= menu_IniFile->ReadBoolean(ezEvadeSection, "Show Evade Status", true);
	DrawSpellPos_menu				= menu_IniFile->ReadBoolean(ezEvadeSection, "Draw Spell Position", true);
	DrawEvadePosition_menu			= menu_IniFile->ReadBoolean(ezEvadeSection, "Draw Evade Position", false);
	
	LowWidth_menu					= menu_IniFile->ReadInteger(ezEvadeSection, "LowLineWidth", 1);
	LowColor_menu					= menu_IniFile->ReadInteger(ezEvadeSection, "LowColor", 9);				//WHITE_1	
	NormalWidth_menu				= menu_IniFile->ReadInteger(ezEvadeSection, "NormalLineWidth", 1);
	NormalColor_menu				= menu_IniFile->ReadInteger(ezEvadeSection, "NormalColor", 10);			//WHITE_2
	HighWidth_menu					= menu_IniFile->ReadInteger(ezEvadeSection, "HighLineWidth", 1);
	HighColor_menu					= menu_IniFile->ReadInteger(ezEvadeSection, "HighColor", 0);			//WHITE
	ExtremeWidth_menu				= menu_IniFile->ReadInteger(ezEvadeSection, "ExtremeLineWidth", 3);
	ExtremeColor_menu				= menu_IniFile->ReadInteger(ezEvadeSection, "ExtremeColor", 0);			//WHITE
	

	//Reset Config-----
	ResetConfig_menu				= menu_IniFile->ReadBoolean(ezEvadeSection, "Reset Evade Config", false);	
}

//-------------------------------------------------//-----------------------//----------
void ezEvade_Menu()
{
	if(Menu_Begin("ezEvade"))
	{
		Menu_Bool("Enable ezEvade", "Enable NewEvade", &Enabled_NewEvade_MENU, ezEvadeSection);
		Menu_Separator();

		
		if(Menu_Begin("Dodge SkillShots"))
		{
			Menu_Bool("Dodge SkillShots", "Dodge SkillShots", &DodgeSkillShots_menu, ezEvadeSection);
			Menu_KeyBinding("Dodge SkillShots KeyBind", "DodgeSkillShots Key", &DodgeSkillShots_Key_menu, ezEvadeSection);

			Menu_End();
		}
		
		Menu_Bool("Dodge Only Dangerous", "Dodge Only Dangerous", &DodgeDangerous_menu, ezEvadeSection);
		Menu_Bool("Dodge FOW SkillShots", "Dodge FOW SkillShots", &DodgeFOWSpells_menu, ezEvadeSection);
		Menu_Bool("Dodge Circular SkillShots", "Dodge Circular SkillShots", &DodgeCircularSpells_menu, ezEvadeSection);			//--xx--checked
		
		//--//spellDetector = new SpellDetector(menu);	// menu list all enemy-spell-trap + draw ....
		Menu_Separator();
		if(Menu_Begin("List Enemy-Spells"))
		{	
			extern void setting_ListSpellsEnemy_Menu_CN();
			extern void setting_ListSpellsEnemy_Menu_VN();
			extern void setting_ListSpellsEnemy_Menu();
			
			extern int nCurrentIndexLanguage;

			if (nCurrentIndexLanguage == 2 || nCurrentIndexLanguage == 8) setting_ListSpellsEnemy_Menu_CN();
			else if (nCurrentIndexLanguage == 3) setting_ListSpellsEnemy_Menu_VN();
			else setting_ListSpellsEnemy_Menu();

			Menu_End();
		}
		
		//--//evadeSpell = new EvadeSpell(menu);			// menu su dung spell de ne'
		if(Menu_Begin("Use Spells To Dodge"))
		{
			Menu_Bool("Use Evade Spells", "Use Evade Spells", &ActivateEvadeSpells_menu, ezEvadeSection);
			Menu_KeyBinding("Use Evade Spells KeyBind", "Use Evade Spells Key", &ActivateEvadeSpells_Key_menu, ezEvadeSection);

			if(Menu_Begin("Settings"))
			{
				extern void setting_ListEvadeSpells_Menu_CN();
				extern void setting_ListEvadeSpells_Menu_VN();
				extern void setting_ListEvadeSpells_Menu();

				extern int nCurrentIndexLanguage;

				if (nCurrentIndexLanguage == 2 || nCurrentIndexLanguage == 8) setting_ListEvadeSpells_Menu_CN();
				else if (nCurrentIndexLanguage == 3) setting_ListEvadeSpells_Menu_VN();
				else setting_ListEvadeSpells_Menu();

				Menu_End();
			}

			Menu_End();
		}

		Menu_Separator();
		if(Menu_Begin("Key Settings"))
		{		
			Menu_Bool("Enable Dodge Only Dangerous Keys", "Enable Dodge Only Dangerous Keys", &DodgeDangerousKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding("Dodge Only Dangerous Key", "Dodge Only Dangerous Key", &DodgeDangerousKey_menu, ezEvadeSection);
			Menu_KeyBinding("Dodge Only Dangerous Key 2", "Dodge Only Dangerous Key 2", &DodgeDangerousKey2_menu, ezEvadeSection);
			
			Menu_Separator();
			Menu_Bool("Enable Dodge Only On Combo Key", "Enable Dodge Only On Combo Key", &DodgeOnlyOnComboKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding("Dodge Only Combo Key", "Dodge Only Combo Key", &DodgeComboKey_menu, ezEvadeSection);
			
			Menu_Separator();
			Menu_Bool("Enable Dont Dodge Key", "Enable Dont Dodge Key", &DontDodgeKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding("Dont Dodge Key", "Dont Dodge Key", &DontDodgeKey_menu, ezEvadeSection);
			Menu_End();
		}
		
		Menu_Separator();
		if(Menu_Begin("Misc Settings"))
		{		
			Menu_Bool("Enhanced Dodge Precision", "Enhanced Dodge Precision", &HigherPrecision_menu, ezEvadeSection);
			Menu_Bool("Recalculate Path", "Recalculate Path", &RecalculatePosition_menu, ezEvadeSection);
			Menu_Bool("Continue Last Movement", "Continue Last Movement", &ContinueMovement_menu, ezEvadeSection);
			Menu_Bool("Calculate Windup Delay", "Calculate Windup Delay", &CalculateWindupDelay_menu, ezEvadeSection);
			Menu_Bool("Check Spell Collision", "Check Spell Collision", &CheckSpellCollision_menu, ezEvadeSection);
			Menu_Bool("Prevent Dodging Under Tower", "Prevent Dodging Under Tower", &PreventDodgingUnderTower_menu, ezEvadeSection);
			Menu_Bool("Prevent Dodging Near Enemies", "Prevent Dodging Near Enemies", &PreventDodgingNearEnemy_menu, ezEvadeSection);
			Menu_Bool("Advanced Spell Detection", "Advanced Spell Detection", &AdvancedSpellDetection_menu, ezEvadeSection);
			//Menu_Bool("Allow Left Click Removal", "Allow Left Click Removal", &ClickRemove_menu, ezEvadeSection);
			
			Menu_Separator();
			if(Menu_Begin("Humanizer"))
			{
				Menu_Bool("Click Only Once", "Click Only Once", &ClickOnlyOnce_menu, ezEvadeSection);
				Menu_Bool("Extended Evade", "Extended Evade", &EnableEvadeDistance_menu, ezEvadeSection);
				Menu_SliderFloat("Tick Limiter", "Tick Limiter", &TickLimiter_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat("Spell Detection Time", "Spell Detection Time", &SpellDetectionTime_menu, 0, 1000.0f, ezEvadeSection);
				//Menu_SliderFloat("Reaction Time", "Reaction Time", &ReactionTime_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat("Dodge Interval", "Dodge Interval", &DodgeInterval_menu, 0, 2000.0f, ezEvadeSection);
				Menu_End();
			}
			
			Menu_Separator();
			if(Menu_Begin("Fast Evade"))
			{
				Menu_Bool("Fast Movement Block", "Fast Movement Block", &FastMovementBlock_menu, ezEvadeSection);
				Menu_SliderFloat("FastEvade Activation Time", "FastEvade Activation Time", &FastEvadeActivationTime_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat("Spell Activation Time", "Spell Activation Time", &SpellActivationTime_menu, 0, 1000.0f, ezEvadeSection);
				Menu_SliderFloat("Collision Distance Buffer", "Collision Distance Buffer", &RejectMinDistance_menu, 0, 100.0f, ezEvadeSection);
				Menu_End();
			}
			
			Menu_Separator();
			if(Menu_Begin("Extra Buffers"))
			{
				Menu_SliderFloat("Extra Ping Buffer", "Extra Ping Buffer", &ExtraPingBuffer_menu, 0, 200.0f, ezEvadeSection);							//--xx--checked
				Menu_SliderFloat("Extra Collision Distance", "Extra Collision Distance", &ExtraCPADistance_menu, 0, 150.0f, ezEvadeSection);				//--xx--checked
				Menu_SliderFloat("Extra Spell Radius", "Extra Spell Radius", &ExtraSpellRadius_menu, 0, 100.0f, ezEvadeSection);							//--xx--checked
				Menu_SliderFloat("Extra Evade Distance", "Extra Evade Distance", &ExtraEvadeDistance_menu, 0, 300.0f, ezEvadeSection);					//--xx--checked
				Menu_SliderFloat("Extra Avoid Distance", "Extra Avoid Distance", &ExtraAvoidDistance_menu, 0, 300.0f, ezEvadeSection);
				Menu_SliderFloat("Min Distance to Champion", "Min Distance to Champion", &MinComfortZone_menu, 0, 1000.0f, ezEvadeSection);
				Menu_End();
			}

			//---- Evade Mode:
			Menu_Separator();
			Menu_ComboBox("Evade Mode", "Evade Mode", &EvadeMode_menu, "Smooth\0VerySmooth\0Fastest\0Hawk\0Kurisu\0GuessWho\0\0", ezEvadeSection);
			
			Menu_Separator();
			if(ImGui::Button("Reset Evade Config"))
			{
				ResetConfig_menu = !ResetConfig_menu;

				if (ResetConfig_menu == true)
				{
					ResetConfig();
					ResetConfig_menu = false;
				}
			}

			Menu_End();
		}
		
		//---- Draw--Menu:
		Menu_Separator();
		if(Menu_Begin("Draw"))
		{
			Menu_Bool("Draw SkillShots", "Draw SkillShots", &DrawSkillShots_menu, ezEvadeSection);
			Menu_Bool("Show Evade Status", "Show Evade Status", &ShowStatus_menu, ezEvadeSection);
			Menu_Bool("Draw Spell Position", "Draw Spell Position", &DrawSpellPos_menu, ezEvadeSection);
			Menu_Bool("Draw Evade Position", "Draw Evade Position", &DrawEvadePosition_menu, ezEvadeSection);

			if(Menu_Begin("DangerLevel Drawings"))
			{
				if(Menu_Begin("LowDrawing"))
				{
					Menu_SliderInt("Line Width", "LowLineWidth", &LowWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox("Color", "LowColor", &LowColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin("NormalDrawing"))
				{
					Menu_SliderInt("Line Width", "NormalLineWidth", &NormalWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox("Color", "NormalColor", &NormalColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin("HighDrawing"))
				{
					Menu_SliderInt("Line Width", "HighLineWidth", &HighWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox("Color", "HighColor", &HighColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin("ExtremeDrawing"))
				{
					Menu_SliderInt("Line Width", "ExtremeLineWidth", &ExtremeWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox("Color", "ExtremeColor", &ExtremeColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				Menu_End();
			}

			Menu_End();
		}

		Menu_End();
	}

	//if (ResetConfig_menu == true)
	//{
	//	ResetConfig();
	//	ResetConfig_menu = false;
	//}

	OnEvadeModeChange();
}

//-------------------------------------------------//-----------------------//----------
void ezEvade_Menu_VN()
{
	if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Né Mới")))
	{
		Menu_Bool(ConvertToUTF8(L"Bật Né Tổng"), "Enable NewEvade", &Enabled_NewEvade_MENU, ezEvadeSection);
		Menu_Separator();


		if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Nhanh Né Skill")))
		{
			Menu_Bool(ConvertToUTF8(L"Bật Tắt Né Skill"), "Dodge SkillShots", &DodgeSkillShots_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"Phím Nhanh Bật Tắt Né Skill"), "DodgeSkillShots Key", &DodgeSkillShots_Key_menu, ezEvadeSection);

			Menu_End();
		}

		Menu_Bool(ConvertToUTF8(L"Chỉ Né Những Skill Nguy Hiểm"), "Dodge Only Dangerous", &DodgeDangerous_menu, ezEvadeSection);
		Menu_Bool(ConvertToUTF8(L"Né Skill Trong Bụi"), "Dodge FOW SkillShots", &DodgeFOWSpells_menu, ezEvadeSection);
		Menu_Bool(ConvertToUTF8(L"Né Skill Hình Tròn"), "Dodge Circular SkillShots", &DodgeCircularSpells_menu, ezEvadeSection);			//--xx--checked

		//--//spellDetector = new SpellDetector(menu);	// menu list all enemy-spell-trap + draw ....
		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"List Skill Địch Trong Game")))
		{	
			extern void setting_ListSpellsEnemy_Menu_CN();
			extern void setting_ListSpellsEnemy_Menu_VN();
			extern void setting_ListSpellsEnemy_Menu();

			extern int nCurrentIndexLanguage;

			if (nCurrentIndexLanguage == 2 || nCurrentIndexLanguage == 8) setting_ListSpellsEnemy_Menu_CN();
			else if (nCurrentIndexLanguage == 3) setting_ListSpellsEnemy_Menu_VN();
			else setting_ListSpellsEnemy_Menu();

			Menu_End();
		}

		//--//evadeSpell = new EvadeSpell(menu);			// menu su dung spell de ne'
		if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Dùng Né Bằng Spell")))
		{
			Menu_Bool(ConvertToUTF8(L"Sử Dụng Spell Để Né"), "Use Evade Spells", &ActivateEvadeSpells_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"Phím Nhanh Bật Tắt Né Bằng Spell"), "Use Evade Spells Key", &ActivateEvadeSpells_Key_menu, ezEvadeSection);

			if(Menu_Begin(ConvertToUTF8(L"Cài Đặt")))
			{
				extern void setting_ListEvadeSpells_Menu_CN();
				extern void setting_ListEvadeSpells_Menu_VN();
				extern void setting_ListEvadeSpells_Menu();

				extern int nCurrentIndexLanguage;

				if (nCurrentIndexLanguage == 2 || nCurrentIndexLanguage == 8) setting_ListEvadeSpells_Menu_CN();
				else if (nCurrentIndexLanguage == 3) setting_ListEvadeSpells_Menu_VN();
				else setting_ListEvadeSpells_Menu();

				Menu_End();
			}

			Menu_End();
		}

		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Phím Tắt")))
		{		
			Menu_Bool(ConvertToUTF8(L"Sử Dụng Phím Nhanh Né Skill Nguy Hiểm"), "Enable Dodge Only Dangerous Keys", &DodgeDangerousKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"Phím Né Skill Nguy Hiểm"), "Dodge Only Dangerous Key", &DodgeDangerousKey_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"Phím Né Skill Nguy Hiểm 2"), "Dodge Only Dangerous Key 2", &DodgeDangerousKey2_menu, ezEvadeSection);

			Menu_Separator();
			Menu_Bool(ConvertToUTF8(L"Bật Tắt Chỉ Né Skill Khi Combo"), "Enable Dodge Only On Combo Key", &DodgeOnlyOnComboKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"Phím Chỉ Né Skill Nguy Hiểm Khi Combo"), "Dodge Only Combo Key", &DodgeComboKey_menu, ezEvadeSection);

			Menu_Separator();
			Menu_Bool(ConvertToUTF8(L"Sử Dụng Phím Không Né Skill"), "Enable Dont Dodge Key", &DontDodgeKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"Phím Nhanh Không Né Skill"), "Dont Dodge Key", &DontDodgeKey_menu, ezEvadeSection);
			Menu_End();
		}

		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Nâng Cao")))
		{		
			Menu_Bool(ConvertToUTF8(L"Tăng Cường Độ Chính Xác Cho Né"), "Enhanced Dodge Precision", &HigherPrecision_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Tính Toán Lại Đường Đi"), "Recalculate Path", &RecalculatePosition_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Tiếp Tục Di Chuyển Đến Điểm Cuối"), "Continue Last Movement", &ContinueMovement_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Tính Toán Lại Độ Trễ"), "Calculate Windup Delay", &CalculateWindupDelay_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Kiếm Tra Spell Bị Lính hoặc Tướng Chắn Đường"), "Check Spell Collision", &CheckSpellCollision_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Ngăn Chặn Né Dưới Trụ"), "Prevent Dodging Under Tower", &PreventDodgingUnderTower_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Ngăn Chặn Né Gần Địch"), "Prevent Dodging Near Enemies", &PreventDodgingNearEnemy_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Nâng Cao Khả Năng Phát Hiện Spell"), "Advanced Spell Detection", &AdvancedSpellDetection_menu, ezEvadeSection);
			//Menu_Bool(ConvertToUTF8(L"Allow Left Click Removal", "Allow Left Click Removal", &ClickRemove_menu, ezEvadeSection);

			Menu_Separator();
			if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Né Như Người")))
			{
				Menu_Bool(ConvertToUTF8(L"Chỉ Click Chuột 1 Lần"), "Click Only Once", &ClickOnlyOnce_menu, ezEvadeSection);
				Menu_Bool(ConvertToUTF8(L"Mở Rộng Né"), "Extended Evade", &EnableEvadeDistance_menu, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Giới Hạn Thời Gian Né"), "Tick Limiter", &TickLimiter_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Thời Gian Phát Hiện Skill Địch"), "Spell Detection Time", &SpellDetectionTime_menu, 0, 1000.0f, ezEvadeSection);
				//Menu_SliderFloat("Reaction Time", "Reaction Time", &ReactionTime_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Khoảng Thời Gian Né"), "Dodge Interval", &DodgeInterval_menu, 0, 2000.0f, ezEvadeSection);
				Menu_End();
			}

			Menu_Separator();
			if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Né Nhanh")))
			{
				Menu_Bool(ConvertToUTF8(L"Khóa Nhanh Di Chuyển"), "Fast Movement Block", &FastMovementBlock_menu, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Tăng Nhanh Thời Gian Kích Hoạt Né"), "FastEvade Activation Time", &FastEvadeActivationTime_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Thời Gian Kích Hoạt Spell"), "Spell Activation Time", &SpellActivationTime_menu, 0, 1000.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Khoảng Cách Va Chạm"), "Collision Distance Buffer", &RejectMinDistance_menu, 0, 100.0f, ezEvadeSection);
				Menu_End();
			}

			Menu_Separator();
			if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Thêm Bộ Đệm")))
			{
				Menu_SliderFloat(ConvertToUTF8(L"Tăng Ping Cho Bộ Đệm"), "Extra Ping Buffer", &ExtraPingBuffer_menu, 0, 200.0f, ezEvadeSection);							//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"Tăng Khoảng Cách Chắn Đường"), "Extra Collision Distance", &ExtraCPADistance_menu, 0, 150.0f, ezEvadeSection);				//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"Tăng Độ Rộng Spell"), "Extra Spell Radius", &ExtraSpellRadius_menu, 0, 100.0f, ezEvadeSection);							//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"Tăng Khoảng Cách Né"), "Extra Evade Distance", &ExtraEvadeDistance_menu, 0, 300.0f, ezEvadeSection);					//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"Tăng Khoảng Cách Tránh Né"), "Extra Avoid Distance", &ExtraAvoidDistance_menu, 0, 300.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"Khoảng Cách Nhỏ Nhất Đến Tướng"), "Min Distance to Champion", &MinComfortZone_menu, 0, 1000.0f, ezEvadeSection);
				Menu_End();
			}

			//---- Evade Mode:
			Menu_Separator();
			Menu_ComboBox(ConvertToUTF8(L"Chế Độ Né"), "Evade Mode", &EvadeMode_menu, "Smooth\0VerySmooth\0Fastest\0Hawk\0Kurisu\0GuessWho\0\0", ezEvadeSection);

			Menu_Separator();
			if(ImGui::Button(ConvertToUTF8(L"Khôi Phục Cài Đặt Né Mặc Định")))
			{
				ResetConfig_menu = !ResetConfig_menu;

				if (ResetConfig_menu == true)
				{
					ResetConfig();
					ResetConfig_menu = false;
				}
			}

			Menu_End();
		}

		//---- Draw--Menu:
		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"Cài Đặt Vẽ")))
		{
			Menu_Bool(ConvertToUTF8(L"Vẽ Skill Địch"), "Draw SkillShots", &DrawSkillShots_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Hiển Thị Tình Trạng Né"), "Show Evade Status", &ShowStatus_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Vẽ Vị Trí Spell Địch"), "Draw Spell Position", &DrawSpellPos_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"Vẽ Vị Trí Né"), "Draw Evade Position", &DrawEvadePosition_menu, ezEvadeSection);

			if(Menu_Begin(ConvertToUTF8(L"Hiển Thị Mức Độ Nguy Hiểm")))
			{
				if(Menu_Begin(ConvertToUTF8(L"Thấp")))
				{
					Menu_SliderInt(ConvertToUTF8(L"Độ Rộng Đường Vẽ"), "LowLineWidth", &LowWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"Màu Sắc"), "LowColor", &LowColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin(ConvertToUTF8(L"Bình Thường")))
				{
					Menu_SliderInt(ConvertToUTF8(L"Độ Rộng Đường Vẽ"), "NormalLineWidth", &NormalWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"Màu Sắc"), "NormalColor", &NormalColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin(ConvertToUTF8(L"Cao")))
				{
					Menu_SliderInt(ConvertToUTF8(L"Độ Rộng Đường Vẽ"), "HighLineWidth", &HighWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"Màu Sắc"), "HighColor", &HighColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin(ConvertToUTF8(L"Nguy Hiểm")))
				{
					Menu_SliderInt(ConvertToUTF8(L"Độ Rộng Đường Vẽ"), "ExtremeLineWidth", &ExtremeWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"Màu Sắc"), "ExtremeColor", &ExtremeColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				Menu_End();
			}

			Menu_End();
		}

		Menu_End();
	}
	OnEvadeModeChange();
}

//------------------------------------------------------------------------------:
void ezEvade_Menu_CN()
{
	if(Menu_Begin(ConvertToUTF8(L"新躲避 +")))
	{
		Menu_Bool(ConvertToUTF8(L"开启新躲避"), "Enable NewEvade", &Enabled_NewEvade_MENU, ezEvadeSection);
		Menu_Separator();


		if(Menu_Begin(ConvertToUTF8(L"躲避技能设置")))
		{
			Menu_Bool(ConvertToUTF8(L"躲避技能"), "Dodge SkillShots", &DodgeSkillShots_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"躲避技能快捷键"), "DodgeSkillShots Key", &DodgeSkillShots_Key_menu, ezEvadeSection);

			Menu_End();
		}

		if(Menu_Begin(ConvertToUTF8(L"使用技能躲避设置")))	
		{
			if(Menu_Begin(ConvertToUTF8(L"正在维护...尽请期待...")))
			{

				Menu_End();
			}


			//Menu_Bool(ConvertToUTF8(L"使用技能躲避"), "Use Evade Spells", &ActivateEvadeSpells, ezEvadeSection);
			//Menu_KeyBinding(ConvertToUTF8(L"使用技能躲避快捷键"), "Use Evade Spells Key", &ActivateEvadeSpells_Key, ezEvadeSection);

			Menu_End();
		}

		Menu_Bool(ConvertToUTF8(L"只躲避危险技能"), "Dodge Only Dangerous", &DodgeDangerous_menu, ezEvadeSection);
		Menu_Bool(ConvertToUTF8(L"躲避无视野技能"), "Dodge FOW SkillShots", &DodgeFOWSpells_menu, ezEvadeSection);
		Menu_Bool(ConvertToUTF8(L"躲避圆形技能"), "Dodge Circular SkillShots", &DodgeCircularSpells_menu, ezEvadeSection);			//--xx--checked

		//--//spellDetector = new SpellDetector(menu);	// menu list all enemy-spell-trap + draw ....
		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"敌方需要躲避技能列表")))
		{
			extern void setting_ListSpellsEnemy_Menu_CN();
			extern void setting_ListSpellsEnemy_Menu_VN();
			extern void setting_ListSpellsEnemy_Menu();

			extern int nCurrentIndexLanguage;

			if (nCurrentIndexLanguage == 2 || nCurrentIndexLanguage == 8) setting_ListSpellsEnemy_Menu_CN();
			else if (nCurrentIndexLanguage == 3) setting_ListSpellsEnemy_Menu_VN();
			else setting_ListSpellsEnemy_Menu();

			Menu_End();
		}

		//--//evadeSpell = new EvadeSpell(menu);			// menu su dung spell de ne'
		if(Menu_Begin(ConvertToUTF8(L"使用技能躲避")))
		{
			Menu_Bool(ConvertToUTF8(L"使用技能躲避"), "Use Evade Spells", &ActivateEvadeSpells_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"使用技能躲避按键"), "Use Evade Spells Key", &ActivateEvadeSpells_Key_menu, ezEvadeSection);

			if(Menu_Begin(ConvertToUTF8(L"设置")))
			{
				extern void setting_ListEvadeSpells_Menu_CN();
				extern void setting_ListEvadeSpells_Menu_VN();
				extern void setting_ListEvadeSpells_Menu();

				extern int nCurrentIndexLanguage;

				if (nCurrentIndexLanguage == 2 || nCurrentIndexLanguage == 8) setting_ListEvadeSpells_Menu_CN();
				else if (nCurrentIndexLanguage == 3) setting_ListEvadeSpells_Menu_VN();
				else setting_ListEvadeSpells_Menu();

				Menu_End();
			}

			Menu_End();
		}

		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"快捷键设置")))
		{
			Menu_Bool(ConvertToUTF8(L"开启只躲避危险技能快捷键"), "Enable Dodge Only Dangerous Keys", &DodgeDangerousKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"只躲避危险技能快捷键1"), "Dodge Only Dangerous Key", &DodgeDangerousKey_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"只躲避危险技能快捷键2"), "Dodge Only Dangerous Key 2", &DodgeDangerousKey2_menu, ezEvadeSection);

			Menu_Separator();
			Menu_Bool(ConvertToUTF8(L"开启只有连招时才躲避按键"), "Enable Dodge Only On Combo Key", &DodgeOnlyOnComboKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"只有连招时才躲避按键"), "Dodge Only Combo Key", &DodgeComboKey_menu, ezEvadeSection);

			Menu_Separator();
			Menu_Bool(ConvertToUTF8(L"开启不躲避按键"), "Enable Dont Dodge Key", &DontDodgeKeyEnabled_menu, ezEvadeSection);
			Menu_KeyBinding(ConvertToUTF8(L"不躲避按键"), "Dont Dodge Key", &DontDodgeKey_menu, ezEvadeSection);
			Menu_End();
		}

		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"其他设置")))
		{
			Menu_Bool(ConvertToUTF8(L"增强躲避判断"), "Enhanced Dodge Precision", &HigherPrecision_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"重新计算路径"), "Recalculate Path", &RecalculatePosition_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"躲避后继续之前移动"), "Continue Last Movement", &ContinueMovement_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"计算风墙的延迟"), "Calculate Windup Delay", &CalculateWindupDelay_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"检查施法碰撞"), "Check Spell Collision", &CheckSpellCollision_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"不在塔下躲避"), "Prevent Dodging Under Tower", &PreventDodgingUnderTower_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"不躲敌方贴脸释放出的技能"), "Prevent Dodging Near Enemies", &PreventDodgingNearEnemy_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"高级法术检测"), "Advanced Spell Detection", &AdvancedSpellDetection_menu, ezEvadeSection);
			//Menu_Bool(ConvertToUTF8(L"允许左键点击移除"), "Allow Left Click Removal", &ClickRemove_menu, ezEvadeSection);

			Menu_Separator();
			if(Menu_Begin(ConvertToUTF8(L"人性化")))
			{
				Menu_Bool(ConvertToUTF8(L"只移动一次"), "Click Only Once", &ClickOnlyOnce_menu, ezEvadeSection);
				Menu_Bool(ConvertToUTF8(L"延长躲避路径"), "Extended Evade", &EnableEvadeDistance_menu, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"两次移动间延迟"), "Tick Limiter", &TickLimiter_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"法术检测时间"), "Spell Detection Time", &SpellDetectionTime_menu, 0, 1000.0f, ezEvadeSection);
				//Menu_SliderFloat(ConvertToUTF8(L"躲避延迟"), "Reaction Time", &ReactionTime_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"躲避间隔延迟"), "Dodge Interval", &DodgeInterval_menu, 0, 2000.0f, ezEvadeSection);
				Menu_End();
			}

			Menu_Separator();
			if(Menu_Begin(ConvertToUTF8(L"快速躲避")))
			{
				Menu_Bool(ConvertToUTF8(L"屏蔽快速移动"), "Fast Movement Block", &FastMovementBlock_menu, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"快速躲避激活时间"), "FastEvade Activation Time", &FastEvadeActivationTime_menu, 0, 500.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"施法激活时间"), "Spell Activation Time", &SpellActivationTime_menu, 0, 1000.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"碰撞距离缓冲"), "Collision Distance Buffer", &RejectMinDistance_menu, 0, 100.0f, ezEvadeSection);
				Menu_End();
			}

			Menu_Separator();
			if(Menu_Begin(ConvertToUTF8(L"额外缓冲")))
			{
				Menu_SliderFloat(ConvertToUTF8(L"额外ping缓冲"), "Extra Ping Buffer", &ExtraPingBuffer_menu, 0, 200.0f, ezEvadeSection);							//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"额外碰撞距离"), "Extra Collision Distance", &ExtraCPADistance_menu, 0, 150.0f, ezEvadeSection);				//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"额外施法半径"), "Extra Spell Radius", &ExtraSpellRadius_menu, 0, 100.0f, ezEvadeSection);							//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"额外躲避距离"), "Extra Evade Distance", &ExtraEvadeDistance_menu, 0, 300.0f, ezEvadeSection);					//--xx--checked
				Menu_SliderFloat(ConvertToUTF8(L"额外敌方技能距离判断"), "Extra Avoid Distance", &ExtraAvoidDistance_menu, 0, 300.0f, ezEvadeSection);
				Menu_SliderFloat(ConvertToUTF8(L"躲避点与敌方英雄最小距离"), "Min Distance to Champion", &MinComfortZone_menu, 0, 1000.0f, ezEvadeSection);
				Menu_End();
			}

			//---- Evade Mode:
			Menu_Separator();
			Menu_ComboBox(ConvertToUTF8(L"躲避模式"), "Evade Mode", &EvadeMode_menu, "Smooth\0VerySmooth\0Fastest\0Hawk\0Kurisu\0GuessWho\0\0", ezEvadeSection);

			Menu_Separator();
			if(ImGui::Button(ConvertToUTF8(L"恢复默认")))
			{
				ResetConfig_menu = !ResetConfig_menu;

				if (ResetConfig_menu == true)
				{
					ResetConfig();
					ResetConfig_menu = false;
				}
			}

			Menu_End();
		}

		//---- Draw--Menu:
		Menu_Separator();
		if(Menu_Begin(ConvertToUTF8(L"线圈")))
		{
			Menu_Bool(ConvertToUTF8(L"绘制技能路径"), "Draw SkillShots", &DrawSkillShots_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"显示躲避状态"), "Show Evade Status", &ShowStatus_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"绘制技能落点"), "Draw Spell Position", &DrawSpellPos_menu, ezEvadeSection);
			Menu_Bool(ConvertToUTF8(L"绘制躲避位置"), "Draw Evade Position", &DrawEvadePosition_menu, ezEvadeSection);

			if(Menu_Begin(ConvertToUTF8(L"危险等级绘制")))
			{
				if(Menu_Begin(ConvertToUTF8(L"低危险技能绘制")))
				{
					Menu_SliderInt(ConvertToUTF8(L"线条宽度"), "LowLineWidth", &LowWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"颜色"), "LowColor", &LowColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin(ConvertToUTF8(L"中危险技能绘制")))
				{
					Menu_SliderInt(ConvertToUTF8(L"线条宽度"), "NormalLineWidth", &NormalWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"颜色"), "NormalColor", &NormalColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin(ConvertToUTF8(L"高危险技能绘制")))
				{
					Menu_SliderInt(ConvertToUTF8(L"线条宽度"), "HighLineWidth", &HighWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"颜色"), "HighColor", &HighColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				if(Menu_Begin(ConvertToUTF8(L"最高危险技能绘制")))
				{
					Menu_SliderInt(ConvertToUTF8(L"线条宽度"), "ExtremeLineWidth", &ExtremeWidth_menu, 1, 10, ezEvadeSection);
					Menu_ComboBox(ConvertToUTF8(L"颜色"), "ExtremeColor", &ExtremeColor_menu, "WHITE\0GREEN\0GREY\0RED\0YELLOW\0ORANGE\0BLUE\0PURPLE\0BLACK\0WHITE_1\0WHITE_2\0\0", ezEvadeSection);
					Menu_End();
				}
				Menu_End();
			}

			Menu_End();
		}

		Menu_End();
	}
	OnEvadeModeChange();
}

//-------------------------------------------------//-----------------------//----------


//-------------------------------------------------//-----------------------//----------
int  old_mode = 0;
void ResetConfig(bool kappa)
{
	//--- SAU KHI RESET-CONFIG  ===> phai writeFile nua
	//__oMsg("RESET-CONFIG====");
	

	DodgeSkillShots_menu			= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge SkillShots", DodgeSkillShots_menu);

	DodgeSkillShots_Key_menu		= 75;
	menu_IniFile->WriteInteger(ezEvadeSection, "DodgeSkillShots Key", DodgeSkillShots_Key_menu);

	ActivateEvadeSpells_menu		= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Use Evade Spells", ActivateEvadeSpells_menu);

	ActivateEvadeSpells_Key_menu	= 75;
	menu_IniFile->WriteInteger(ezEvadeSection, "Use Evade Spells Key", ActivateEvadeSpells_Key_menu);

	DodgeDangerous_menu				= false;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge Only Dangerous", DodgeDangerous_menu);

	DodgeFOWSpells_menu				= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge FOW SkillShots", DodgeFOWSpells_menu);

	DodgeCircularSpells_menu		= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge Circular SkillShots", DodgeCircularSpells_menu);

	HigherPrecision_menu			= false;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Enhanced Dodge Precision", HigherPrecision_menu);

	RecalculatePosition_menu		= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Recalculate Path", RecalculatePosition_menu);

	ContinueMovement_menu			= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Continue Last Movement", ContinueMovement_menu);

	CalculateWindupDelay_menu		= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Calculate Windup Delay", CalculateWindupDelay_menu);

	CheckSpellCollision_menu		= false;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Check Spell Collision", CheckSpellCollision_menu);

	PreventDodgingUnderTower_menu	= false;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Under Tower", PreventDodgingUnderTower_menu);

	PreventDodgingNearEnemy_menu	= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Near Enemies", PreventDodgingNearEnemy_menu);

	AdvancedSpellDetection_menu		= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Advanced Spell Detection", AdvancedSpellDetection_menu);

	//LoadPingTester_menu				= true;
	// ....
	
	ClickOnlyOnce_menu				= true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Click Only Once", ClickOnlyOnce_menu);

	EnableEvadeDistance_menu		= false;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Extended Evade", EnableEvadeDistance_menu);

	TickLimiter_menu				= 100.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Tick Limiter", TickLimiter_menu);

	SpellDetectionTime_menu			= 0;
	menu_IniFile->WriteFloat(ezEvadeSection, "Spell Detection Time", SpellDetectionTime_menu);

	//ReactionTime_menu				= 0;
	//menu_IniFile->WriteFloat(ezEvadeSection, "Reaction Time", ReactionTime_menu);

	DodgeInterval_menu				= 0;
	menu_IniFile->WriteFloat(ezEvadeSection, "Dodge Interval", DodgeInterval_menu);

	FastMovementBlock_menu			= false;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Fast Movement Block", FastMovementBlock_menu);

	FastEvadeActivationTime_menu	= 65.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "FastEvade Activation Time", FastEvadeActivationTime_menu);

	SpellActivationTime_menu		= 400.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Spell Activation Time", SpellActivationTime_menu);

	RejectMinDistance_menu			= 10.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Collision Distance Buffer", RejectMinDistance_menu);

	ExtraPingBuffer_menu			= 65.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Extra Ping Buffer", ExtraPingBuffer_menu);

	ExtraCPADistance_menu			= 10.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Extra Collision Distance", ExtraCPADistance_menu);

	ExtraSpellRadius_menu			= 0;
	menu_IniFile->WriteFloat(ezEvadeSection, "Extra Spell Radius", ExtraSpellRadius_menu);

	ExtraEvadeDistance_menu			= 75.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Extra Evade Distance", ExtraEvadeDistance_menu);	//L# 100

	ExtraAvoidDistance_menu			= 50.0f;
	menu_IniFile->WriteFloat(ezEvadeSection, "Extra Avoid Distance", ExtraAvoidDistance_menu);

	MinComfortZone_menu				= 550;
	menu_IniFile->WriteFloat(ezEvadeSection, "Min Distance to Champion", MinComfortZone_menu);


	//// drawings
	DrawSkillShots_menu = true;
	menu_IniFile->WriteBoolean(ezEvadeSection, "Draw SkillShots", DrawSkillShots_menu);

	//menu.Item("DrawSkillShots").SetValue(true);
	//menu.Item("ShowStatus").SetValue(true);
	//menu.Item("DrawSpellPos").SetValue(false);
	//menu.Item("DrawEvadePosition").SetValue(false);

	if (kappa)
	{
		old_mode = 0;
		// profiles
		EvadeMode_menu = 0;
		menu_IniFile->WriteInteger(ezEvadeSection, "Evade Mode", EvadeMode_menu);

		// keys
		DodgeDangerousKeyEnabled_menu	= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enable Dodge Only Dangerous Keys", DodgeDangerousKeyEnabled_menu);

		DodgeDangerousKey_menu			= 32;
		menu_IniFile->WriteInteger(ezEvadeSection, "Dodge Only Dangerous Key", DodgeDangerousKey_menu);

		DodgeDangerousKey2_menu			= 86;
		menu_IniFile->WriteInteger(ezEvadeSection, "Dodge Only Dangerous Key 2", DodgeDangerousKey2_menu);

		DodgeOnlyOnComboKeyEnabled_menu = false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enable Dodge Only On Combo Key", DodgeOnlyOnComboKeyEnabled_menu);

		DodgeComboKey_menu				= 32;
		menu_IniFile->WriteInteger(ezEvadeSection, "Dodge Only Combo Key", DodgeComboKey_menu);

		DontDodgeKeyEnabled_menu		= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enable Dont Dodge Key", DontDodgeKeyEnabled_menu);

		DontDodgeKey_menu				= 90;
		menu_IniFile->WriteInteger(ezEvadeSection, "Dont Dodge Key", DontDodgeKey_menu);
	}

	//FastMovementBlock_menu			= false;
	//menu_IniFile->WriteBoolean(ezEvadeSection, "Fast Movement Block", FastMovementBlock_menu);	//them vi evadeMode=0 ==> FastMovementBlock_menu=true
}

//-------------------------------------------------//-----------------------//----------
bool changedComboBox = false;
void OnEvadeModeChange()
{
	if (HasChangeInt(old_mode, EvadeMode_menu))
	{
		old_mode = EvadeMode_menu;
		changedComboBox = true;
		//__oMsg(" CHANGE -------------> old_mode: %d", old_mode);
	}
	else changedComboBox = false;
	
	if(changedComboBox == false) return;

	//__oMsg("EvadeMode_menu -------- : %d, old_mode: %d", EvadeMode_menu, old_mode);

	int mode = EvadeMode_menu;

	if (mode == 2)	//"Fastest"
	{
		ResetConfig(false);

		FastMovementBlock_menu			= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Fast Movement Block", FastMovementBlock_menu);

		FastEvadeActivationTime_menu	= 120;		
		menu_IniFile->WriteFloat(ezEvadeSection, "FastEvade Activation Time", FastEvadeActivationTime_menu);

		RejectMinDistance_menu			= 25;
		menu_IniFile->WriteFloat(ezEvadeSection, "Collision Distance Buffer", RejectMinDistance_menu);

		ExtraCPADistance_menu			= 25;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Collision Distance", ExtraCPADistance_menu);

		ExtraPingBuffer_menu			= 80;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Ping Buffer", ExtraPingBuffer_menu);
	}
	else if (mode == 1)	//"Very Smooth"
	{
		ResetConfig(false);

		FastEvadeActivationTime_menu	= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "FastEvade Activation Time", FastEvadeActivationTime_menu);

		RejectMinDistance_menu			= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "Collision Distance Buffer", RejectMinDistance_menu);

		ExtraCPADistance_menu			= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Collision Distance", ExtraCPADistance_menu);

		ExtraPingBuffer_menu			= 40;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Ping Buffer", ExtraPingBuffer_menu);
	}
	else if (mode == 0)	//"Smooth"
	{
		ResetConfig(false);
		
		FastMovementBlock_menu			= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Fast Movement Block", FastMovementBlock_menu);
		
		FastEvadeActivationTime_menu	= 65;
		menu_IniFile->WriteFloat(ezEvadeSection, "FastEvade Activation Time", FastEvadeActivationTime_menu);
		
		RejectMinDistance_menu			= 10;
		menu_IniFile->WriteFloat(ezEvadeSection, "Collision Distance Buffer", RejectMinDistance_menu);
	
		ExtraCPADistance_menu			= 10;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Collision Distance", ExtraCPADistance_menu);

		ExtraPingBuffer_menu			= 65;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Ping Buffer", ExtraPingBuffer_menu);
	}
	else if (mode == 3)	//"Hawk"
	{
		ResetConfig(false);

		DodgeDangerous_menu				= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge Only Dangerous", DodgeDangerous_menu);

		DodgeFOWSpells_menu				= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge FOW SkillShots", DodgeFOWSpells_menu);

		DodgeCircularSpells_menu		= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge Circular SkillShots", DodgeCircularSpells_menu);

		DodgeDangerousKeyEnabled_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enable Dodge Only Dangerous Keys", DodgeDangerousKeyEnabled_menu);

		HigherPrecision_menu			= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enhanced Dodge Precision", HigherPrecision_menu);

		RecalculatePosition_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Recalculate Path", RecalculatePosition_menu);

		ContinueMovement_menu			= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Continue Last Movement", ContinueMovement_menu);

		CalculateWindupDelay_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Calculate Windup Delay", CalculateWindupDelay_menu);

		CheckSpellCollision_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Check Spell Collision", CheckSpellCollision_menu);

		PreventDodgingUnderTower_menu	= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Under Tower", PreventDodgingUnderTower_menu);

		PreventDodgingNearEnemy_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Near Enemies", PreventDodgingNearEnemy_menu);

		AdvancedSpellDetection_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Advanced Spell Detection", AdvancedSpellDetection_menu);

		ClickOnlyOnce_menu				= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Click Only Once", ClickOnlyOnce_menu);

		EnableEvadeDistance_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Extended Evade", EnableEvadeDistance_menu);

		TickLimiter_menu				= 200;
		menu_IniFile->WriteFloat(ezEvadeSection, "Tick Limiter", TickLimiter_menu);

		SpellDetectionTime_menu			= 375;
		menu_IniFile->WriteFloat(ezEvadeSection, "Spell Detection Time", SpellDetectionTime_menu);

		//ReactionTime_menu				= 285;
		//menu_IniFile->WriteFloat(ezEvadeSection, "Reaction Time", ReactionTime_menu);

		DodgeInterval_menu				= 235;
		menu_IniFile->WriteFloat(ezEvadeSection, "Dodge Interval", DodgeInterval_menu);

		FastEvadeActivationTime_menu	= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "FastEvade Activation Time", FastEvadeActivationTime_menu);

		SpellActivationTime_menu		= 200;
		menu_IniFile->WriteFloat(ezEvadeSection, "Spell Activation Time", SpellActivationTime_menu);

		RejectMinDistance_menu			= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "Collision Distance Buffer", RejectMinDistance_menu);

		ExtraPingBuffer_menu			= 65;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Ping Buffer", ExtraPingBuffer_menu);

		ExtraCPADistance_menu			= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Collision Distance", ExtraCPADistance_menu);

		ExtraSpellRadius_menu			= 0;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Spell Radius", ExtraSpellRadius_menu);

		ExtraEvadeDistance_menu			= 150;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Evade Distance", ExtraEvadeDistance_menu);	//L# 200

		ExtraAvoidDistance_menu			= 200;
		menu_IniFile->WriteFloat(ezEvadeSection, "Extra Avoid Distance", ExtraAvoidDistance_menu);

		MinComfortZone_menu				= 550;
		menu_IniFile->WriteFloat(ezEvadeSection, "Min Distance to Champion", MinComfortZone_menu);
	}

	else if (mode == 4)	//"Kurisu"
	{
		ResetConfig(false);

		DodgeFOWSpells_menu				= false;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Dodge FOW SkillShots", DodgeFOWSpells_menu);

		DodgeDangerousKeyEnabled_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enable Dodge Only Dangerous Keys", DodgeDangerousKeyEnabled_menu);

		RecalculatePosition_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Recalculate Path", RecalculatePosition_menu);

		ContinueMovement_menu			= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Continue Last Movement", ContinueMovement_menu);

		CalculateWindupDelay_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Calculate Windup Delay", CalculateWindupDelay_menu);
		
		PreventDodgingUnderTower_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Under Tower", PreventDodgingUnderTower_menu);

		PreventDodgingNearEnemy_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Near Enemies", PreventDodgingNearEnemy_menu);

		MinComfortZone_menu				= 850;
		menu_IniFile->WriteFloat(ezEvadeSection, "Min Distance to Champion", MinComfortZone_menu);	
	}

	else if (mode == 5)	//"GuessWho"
	{
		ResetConfig(false);
	
		DodgeDangerousKeyEnabled_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enable Dodge Only Dangerous Keys", DodgeDangerousKeyEnabled_menu);
		
		DodgeDangerousKey2_menu			= 109;
		menu_IniFile->WriteInteger(ezEvadeSection, "Dodge Only Dangerous Key 2", DodgeDangerousKey2_menu);
		
		HigherPrecision_menu			= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Enhanced Dodge Precision", HigherPrecision_menu);
	
		CheckSpellCollision_menu		= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Check Spell Collision", CheckSpellCollision_menu);
		
		PreventDodgingUnderTower_menu	= true;
		menu_IniFile->WriteBoolean(ezEvadeSection, "Prevent Dodging Under Tower", PreventDodgingUnderTower_menu);

		//menu.Item("ShowStatus").SetValue(false);
		//menu.Item("DrawSpellPos").SetValue(true);
	}
}

//-------------------------------------------------//-----------------------//----------
extern int  _enableSmite_Key;
extern bool _enable_Smite;
extern int  Riven_Brustkey;
extern bool	Riven_shycombo;
void func_onOff_binding(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		

	case WM_KEYDOWN:
		//todo ..
		break;
		
		
	case WM_KEYUP:
		bool isChat = IS_CHATTING();

		if ((int)wParam == DodgeSkillShots_Key_menu && isRiotOnTop() && !isChat)	//---- DodgeSkillShots_Key
		{
			DodgeSkillShots_menu = !DodgeSkillShots_menu;
			SEND_TEXT_SYSTEM(DodgeSkillShots_menu ?  "Dodge SkillShots : ON" :  "Dodge SkillShots : OFF");
			if(DodgeSkillShots_menu == false)
			{
				UnBlock_RightClick_FromUser();
			}
		}

		if ((int)wParam == ActivateEvadeSpells_Key_menu && isRiotOnTop() && !isChat)	//---- Use Evade Spells Key
		{
			ActivateEvadeSpells_menu = !ActivateEvadeSpells_menu;
			SEND_TEXT_SYSTEM(ActivateEvadeSpells_menu ?  "Use Evade Spells Key : ON" :  "Use Evade Spells Key : OFF");
		}

		
		if ((int)wParam == _enableSmite_Key && isRiotOnTop() && !isChat)	//---- Use Evade Spells Key
		{
			_enable_Smite = !_enable_Smite;
		}

		if ((int)wParam == Riven_Brustkey && isRiotOnTop() && !isChat)	
		{
			Riven_shycombo =! Riven_shycombo;
		}
	}

	
}
