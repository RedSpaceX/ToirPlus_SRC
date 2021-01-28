#include "stdafx.h"

#include "IniManager.h"
#include "Utils.h"
#include "DataString.h"
#include <string>

using namespace std;

CIniManager* CIniManager::s_Instance = 0;

CIniManager::CIniManager(void)
{
	m_IniFile = 0;
	m_szUsername = 0;
}

CIniManager::~CIniManager(void)
{
}

CIniManager* CIniManager::GetInstance()
{
	if (!s_Instance)
	{
		s_Instance = new CIniManager();
	}
	return s_Instance;
}

extern HINSTANCE			hDll;
static bool s_AlreadyTriggered = false;
char g_szPath2DllFile_APP[MAX_PATH];
void CIniManager::WriteIniFile()
{
	if (m_IniFile )
	{
		delete []m_IniFile ;
		m_IniFile  = 0;
	}
	if (s_AlreadyTriggered == false)
	{
		GetModuleFileNameA(hDll, g_szPath2DllFile_APP, MAX_PATH);
		s_AlreadyTriggered = true;
	}
	string strPath(g_szPath2DllFile_APP);
	strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
	strPath = strPath.append( (sz__config_AutoLoLs_ini));
	//__oMsg("[INI]duong dan den file-write: %s", strPath.c_str());
	m_IniFile = new CIniFile(strPath.c_str());
	m_IniFile->WriteString( (sz__User_Information),  (sz__Username), m_szUsername);
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Attack_Current_Selected, GetAtkCurrentSelected()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Combo), GetCombo()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Combo_Q, GetComboUseQ()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Combo_W, GetComboUseW()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Combo_E, GetComboUseE()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Combo_R, GetComboUseR()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Clear_Lane), GetClearLane()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__ClearLane_Q, GetClearLaneUseQ()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__ClearLane_W, GetClearLaneUseW()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__ClearLane_E, GetClearLaneUseE()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__ClearLane_R, GetClearLaneUseR()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Harass), GetHarass()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Harass_Q, GetHarassUseQ()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Harass_W, GetHarassUseW()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Harass_E, GetHarassUseE()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  sz__Harass_R, GetHarassUseR()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__LastHit), GetLastHit()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Move_to_mouse_position), GetMove2Mouse()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Evade_line), GetEvadeLine());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Evade_circle), GetEvadeCircle());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Evade_dangerous), GetEvadeDangerous());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Hack_Zoom), GetHackZoom());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Mod_Skin), GetModSkin());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Play_With_Bot), GetPlayWithBot());

	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Limit_Percent_Mana_to_ClearLane), GetPercentManaClearLane());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Limit_Percent_Mana_to_Harass), GetPercentManaHarass());
	m_IniFile->WriteInteger( (sz__App_Information),  sz__Delay_Skill_After, GetDelaySkillAfter());

	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Bat_Tat_Ve), GetBatTatVeHinh()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ve_Mat_Thuong), GetVeMatThuong()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ve_Mat_Kiem_Soat), GetVeMatKiemSoat()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Canh_Bao_Gank), GetVeCanhBaoGank()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Doan_Huong_Dich), GetVeDoanHuong()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_Tru_Dich), GetVeTamTruDich()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_Tru_Dong_Minh), GetVeTamTruDongMinh()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_bien_ve)		, GetVeTimeEnemyRecall()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_hoi_skill)		, GetVeTimeEnemyHoiSkill()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_hoi_spell)		, GetVeTimeEnemyHoiSpell()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_hoi_sinh_quai_rung), GetVeTimeXuatHienQuaiRung()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_Danh_Thuong_Player), GetVePlayerDanhThuong()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_Q_Player), GetVePlayerSkillQ()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_W_Player), GetVePlayerSkillW()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_E_Player), GetVePlayerSkillE()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_R_Player), GetVePlayerSkillR()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_Danh_Thuong_Enemy), GetVeEnemyDanhThuong()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_Q_Enemy), GetVeEnemySkillQ()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_W_Enemy), GetVeEnemySkillW()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_E_Enemy), GetVeEnemySkillE()); 
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tam_R_Enemy), GetVeEnemySkillR()); 

	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Heal_Skill), GetHoiMau_Skill());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Heal_Item), GetHoiMau_Item());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Ignite), GetThieuDot());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Cleanse), GetThanhTay());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Barrier), GetLaChan());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Smite), GetTrungPhat());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Blade_of_the_Ruined_King), GetVoDanh());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Hextech_Items), GetHextech());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Tiamat_Hydra), GetTiamat());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Iron_Solari), GetIronSolari());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Mountain), GetSonThach());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Zhonya), GetDongHoCat());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Seraph), GetQuyenTruongDTS());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Quick_Silver), GetKhanGiaiThuat());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Mikael), GetHomMikael());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Redemption), GetChuocToi());
	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__Randuin), GetKhienBang());

	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Heal_Skill), GetPercentHP4Skill());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Heal_Item), GetPercentHP4Item());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Barrier), GetPercentHP4LaChan());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Iron_Solari), GetPercentHP4IronSolari());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Mountain), GetPercentHP4SonThach());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Zhonya), GetPercentHP4DongHoCat());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Seraph), GetPercentHP4QT_DTS());
	m_IniFile->WriteInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Redemption), GetPercentHP4ChuocToi());

	m_IniFile->WriteBoolean( (sz__App_Information),  (sz__line2), GetChooseLine2());

	delete []m_szUsername; m_szUsername = 0;
}

void CIniManager::ReadIniFile()
{
	if (m_IniFile )
	{
		delete []m_IniFile ;
		m_IniFile  = 0;
	}
	if (s_AlreadyTriggered == false)
	{
		GetModuleFileNameA(hDll, g_szPath2DllFile_APP, MAX_PATH);
		s_AlreadyTriggered = true;
	}
	string strPath(g_szPath2DllFile_APP);
	strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);
	strPath = strPath.append( (sz__config_AutoLoLs_ini));
	//__oMsg("[INI]duong dan den file-read: %s", strPath.c_str());
	m_IniFile = new CIniFile(strPath.c_str());
	if (m_szUsername)
	{
		delete []m_szUsername;
		m_szUsername = 0;
	}
	m_szUsername			= m_IniFile->ReadString( (sz__User_Information),  (sz__Username), "");
	SetAtkCurrentSelected(		m_IniFile->ReadBoolean( (sz__App_Information),  sz__Attack_Current_Selected, true));
	SetCombo(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Combo), true));
	SetComboUseQ(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_Q, true));
	SetComboUseW(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_W, true));
	SetComboUseE(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_E, true));
	SetComboUseR(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_R, true));
	SetClearLane(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Clear_Lane), true));
	SetClearLaneUseQ(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_Q, true));
	SetClearLaneUseW(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_W, true));
	SetClearLaneUseE(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_E, true));
	SetClearLaneUseR(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_R, false));
	SetHarass(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Harass), true));
	SetHarassUseQ(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_Q, true));
	SetHarassUseW(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_W, true));
	SetHarassUseE(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_E, true));
	SetHarassUseR(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_R, false));
	SetLastHit(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__LastHit), true));
	SetMove2Mouse(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Move_to_mouse_position), true));
	SetEvadeLine(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Evade_line), true));
	SetEvadeCircle(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Evade_circle), false));
	SetEvadeDangerous(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Evade_dangerous), false));
	SetHackZoom(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Hack_Zoom), false));
	SetModSkin(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Mod_Skin), false));
	SetPlayWithBot(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Play_With_Bot), false));

	SetPercentManaHarass(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Limit_Percent_Mana_to_Harass), 35));
	SetPercentManaClearLane(	m_IniFile->ReadInteger( (sz__App_Information),  (sz__Limit_Percent_Mana_to_ClearLane), 35));
	SetDelaySkillAfter(			m_IniFile->ReadInteger( (sz__App_Information),  sz__Delay_Skill_After, 0));

	SetBatTatVeHinh(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Bat_Tat_Ve), false));
	SetVeMatThuong(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_Mat_Thuong), true));
	SetVeMatKiemSoat(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_Mat_Kiem_Soat), true));
	SetVeCanhBaoGank(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Canh_Bao_Gank), true));
	SetVeDoanHuong(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Doan_Huong_Dich), true));
	SetVeTamTruDich(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Tru_Dich), true));
	SetVeTamTruDongMinh(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Tru_Dong_Minh), true));
	SetVeTimeEnemyRecall(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_bien_ve)		, true));
	SetVeTimeEnemyHoiSkill(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_hoi_skill)	, true));
	SetVeTimeEnemyHoiSpell(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_hoi_spell)	, true));
	SetVeTimeXuatHienQuaiRung(	m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_hoi_sinh_quai_rung), true));
	SetVePlayerDanhThuong(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Danh_Thuong_Player), true));
	SetVePlayerSkillQ(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Q_Player), false));
	SetVePlayerSkillW(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_W_Player), false));
	SetVePlayerSkillE(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_E_Player), false));
	SetVePlayerSkillR(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_R_Player), true));
	SetVeEnemyDanhThuong(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Danh_Thuong_Enemy), true));
	SetVeEnemySkillQ(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Q_Enemy), false));
	SetVeEnemySkillW(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_W_Enemy), false));
	SetVeEnemySkillE(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_E_Enemy), false));
	SetVeEnemySkillR(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_R_Enemy), true));

	SetHoiMau_Skill(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Heal_Skill), true));
	SetHoiMau_Item(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Heal_Item), true));
	SetThieuDot(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ignite), true));
	SetThanhTay(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Cleanse), true));
	SetLaChan(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Barrier), true));
	SetTrungPhat(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Smite), true));
	SetVoDanh(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Blade_of_the_Ruined_King), true));
	SetHextech(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Hextech_Items), true));
	SetTiamat(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tiamat_Hydra), true));
	SetIronSolari(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Iron_Solari), true));
	SetSonThach(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Mountain), true));
	SetDongHoCat(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Zhonya), true));
	SetQuyenTruongDTS(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Seraph), true));
	SetKhanGiaiThuat(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Quick_Silver), true));
	SetHomMikael(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Mikael), true));
	SetChuocToi(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Redemption), true));
	SetKhienBang(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Randuin), true));
	
	SetPercentHP4Skill(			m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Heal_Skill), 15));
	SetPercentHP4Item(			m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Heal_Item), 40));
	SetPercentHP4LaChan(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Barrier), 25));
	SetPercentHP4IronSolari(	m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Iron_Solari), 35));
	SetPercentHP4SonThach(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Mountain), 35));
	SetPercentHP4DongHoCat(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Zhonya), 15));
	SetPercentHP4QT_DTS(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Seraph), 20));
	SetPercentHP4ChuocToi(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Redemption), 30));

	SetChooseLine2(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__line2), false));
}

void CIniManager::ReadIniFile2(char* path_out)
{
	if (m_IniFile )
	{
		delete []m_IniFile ;
		m_IniFile  = 0;
	}
	if (s_AlreadyTriggered == false)
	{
		GetModuleFileNameA(hDll, g_szPath2DllFile_APP, MAX_PATH);
		s_AlreadyTriggered = true;
	}

	//char path_out[MAX_PATH]  = "";
	//get_path(path_out);
	string strPath(path_out);
	if (strlen(path_out) > 0) 
	{
		memset(path_out, 0, strlen(path_out));
	}
	strPath = strPath.substr(0, strPath.find_last_of(char(92)) + 1);

	strPath = strPath.append( (sz__config_AutoLoLs_ini));
	//__oMsg("[INI]duong dan den file-read: %s", strPath.c_str());
	m_IniFile = new CIniFile(strPath.c_str());
	if (m_szUsername)
	{
		delete []m_szUsername;
		m_szUsername = 0;
	}
	m_szUsername			= m_IniFile->ReadString( (sz__User_Information),  (sz__Username), "");
	SetAtkCurrentSelected(		m_IniFile->ReadBoolean( (sz__App_Information),  sz__Attack_Current_Selected, true));
	SetCombo(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Combo), true));
	SetComboUseQ(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_Q, true));
	SetComboUseW(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_W, true));
	SetComboUseE(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_E, true));
	SetComboUseR(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Combo_R, true));
	SetClearLane(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Clear_Lane), true));
	SetClearLaneUseQ(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_Q, true));
	SetClearLaneUseW(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_W, true));
	SetClearLaneUseE(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_E, true));
	SetClearLaneUseR(			m_IniFile->ReadBoolean( (sz__App_Information),  sz__ClearLane_R, false));
	SetHarass(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Harass), true));
	SetHarassUseQ(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_Q, true));
	SetHarassUseW(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_W, true));
	SetHarassUseE(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_E, true));
	SetHarassUseR(				m_IniFile->ReadBoolean( (sz__App_Information),  sz__Harass_R, false));
	SetLastHit(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__LastHit), true));
	SetMove2Mouse(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Move_to_mouse_position), true));
	SetEvadeLine(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Evade_line), true));
	SetEvadeCircle(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Evade_circle), false));
	SetEvadeDangerous(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Evade_dangerous), false));
	SetHackZoom(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Hack_Zoom), false));
	SetModSkin(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Mod_Skin), false));
	SetPlayWithBot(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Play_With_Bot), false));

	SetPercentManaHarass(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Limit_Percent_Mana_to_Harass), 35));
	SetPercentManaClearLane(	m_IniFile->ReadInteger( (sz__App_Information),  (sz__Limit_Percent_Mana_to_ClearLane), 35));
	SetDelaySkillAfter(			m_IniFile->ReadInteger( (sz__App_Information),  sz__Delay_Skill_After, 0));

	SetBatTatVeHinh(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Bat_Tat_Ve), false));
	SetVeMatThuong(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_Mat_Thuong), true));
	SetVeMatKiemSoat(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_Mat_Kiem_Soat), true));
	SetVeCanhBaoGank(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Canh_Bao_Gank), true));
	SetVeDoanHuong(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Doan_Huong_Dich), true));
	SetVeTamTruDich(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Tru_Dich), true));
	SetVeTamTruDongMinh(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Tru_Dong_Minh), true));
	SetVeTimeEnemyRecall(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_bien_ve)		, true));
	SetVeTimeEnemyHoiSkill(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_hoi_skill)	, true));
	SetVeTimeEnemyHoiSpell(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_enemy_hoi_spell)	, true));
	SetVeTimeXuatHienQuaiRung(	m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ve_thoi_gian_hoi_sinh_quai_rung), true));
	SetVePlayerDanhThuong(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Danh_Thuong_Player), true));
	SetVePlayerSkillQ(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Q_Player), false));
	SetVePlayerSkillW(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_W_Player), false));
	SetVePlayerSkillE(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_E_Player), false));
	SetVePlayerSkillR(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_R_Player), true));
	SetVeEnemyDanhThuong(		m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Danh_Thuong_Enemy), true));
	SetVeEnemySkillQ(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_Q_Enemy), false));
	SetVeEnemySkillW(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_W_Enemy), false));
	SetVeEnemySkillE(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_E_Enemy), false));
	SetVeEnemySkillR(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tam_R_Enemy), true));

	SetHoiMau_Skill(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Heal_Skill), true));
	SetHoiMau_Item(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Heal_Item), true));
	SetThieuDot(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Ignite), true));
	SetThanhTay(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Cleanse), true));
	SetLaChan(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Barrier), true));
	SetTrungPhat(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Smite), true));
	SetVoDanh(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Blade_of_the_Ruined_King), true));
	SetHextech(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Hextech_Items), true));
	SetTiamat(					m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Tiamat_Hydra), true));
	SetIronSolari(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Iron_Solari), true));
	SetSonThach(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Mountain), true));
	SetDongHoCat(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Zhonya), true));
	SetQuyenTruongDTS(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Seraph), true));
	SetKhanGiaiThuat(			m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Quick_Silver), true));
	SetHomMikael(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Mikael), true));
	SetChuocToi(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Redemption), true));
	SetKhienBang(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__Randuin), true));

	SetPercentHP4Skill(			m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Heal_Skill), 15));
	SetPercentHP4Item(			m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Heal_Item), 40));
	SetPercentHP4LaChan(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Barrier), 25));
	SetPercentHP4IronSolari(	m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Iron_Solari), 35));
	SetPercentHP4SonThach(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Mountain), 35));
	SetPercentHP4DongHoCat(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Zhonya), 15));
	SetPercentHP4QT_DTS(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Seraph), 20));
	SetPercentHP4ChuocToi(		m_IniFile->ReadInteger( (sz__App_Information),  (sz__Percent_HP_to_Use_Redemption), 30));

	SetChooseLine2(				m_IniFile->ReadBoolean( (sz__App_Information),  (sz__line2), false));
}

char* CIniManager::GetUsername() const { return m_szUsername; }
void CIniManager::SetUsername(const char* val) {
	if (m_szUsername)
	{
		delete []m_szUsername;
		m_szUsername = 0;
	}
	m_szUsername = new char[strlen(val) + 1];
	strcpy_s(m_szUsername, MAX_PATH, val);
}
