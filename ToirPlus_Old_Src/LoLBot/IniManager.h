#pragma once
#include "IniFile.h"

class /*__declspec(dllexport)*/ CIniManager
{
private:
	CIniManager(void);
	static CIniManager *s_Instance;
	CIniFile* m_IniFile;
	char* m_szUsername;
	char* m_szCombo_Key;	
	char* m_szLaneClear_Key;
	char* m_szHarass_Key;
	char* m_szLastHit_Key;

	bool m_bAtkCurrentSelected;
	bool m_bCombo;
	bool m_bComboUseQ;
	bool m_bComboUseW;
	bool m_bComboUseE;
	bool m_bComboUseR;
	bool m_bClearLane;
	bool m_bClearLaneUseQ;
	bool m_bClearLaneUseW;
	bool m_bClearLaneUseE;
	bool m_bClearLaneUseR;
	bool m_bHarass;
	bool m_bHarassUseQ;
	bool m_bHarassUseW;
	bool m_bHarassUseE;
	bool m_bHarassUseR;
	bool m_bLastHit;
	bool m_bMove2Mouse;
	bool m_bEvadeLine;
	bool m_bEvadeCircle;
	bool m_bEvadeDangerous;
	bool m_bHackZoom;
	bool m_bModSkin;
	bool m_bPlayWithBot;
	int m_iPercentManaHarass;
	int m_iPercentManaClearLane;
	int m_iDelaySkillAfter;

	bool m_bBatTatVeHinh;
	bool m_bVeMatThuong;
	bool m_bVeMatKiemSoat;
	bool m_bVeCanhBaoGank;
	bool m_bVeDoanHuong;
	bool m_bVeTamTruDich;
	bool m_bVeTamTruDongMinh;
	bool m_bVeTimeEnemyRecall;
	bool m_bVeTimeEnemyHoiSkill;
	bool m_bVeTimeEnemyHoiSpell;
	bool m_bVeTimeXuatHienQuaiRung;
	bool m_bVePlayerDanhThuong;
	bool m_bVePlayerSkillQ;
	bool m_bVePlayerSkillW;
	bool m_bVePlayerSkillE;
	bool m_bVePlayerSkillR;
	bool m_bVeEnemyDanhThuong;
	bool m_bVeEnemySkillQ;
	bool m_bVeEnemySkillW;
	bool m_bVeEnemySkillE;
	bool m_bVeEnemySkillR;

	bool m_bHoiMau_Skill;
	bool m_bHoiMau_Item;
	bool m_bThieuDot;
	bool m_bThanhTay;
	bool m_bLaChan;
	bool m_bTrungPhat;
	bool m_bVoDanh;
	bool m_bHextech;
	bool m_bTiamat;
	bool m_bIronSolari;
	bool m_bSonThach;
	bool m_bDongHoCat;
	bool m_bQuyenTruongDTS;
	bool m_bKhanGiaiThuat;
	bool m_bHomMikael;
	bool m_bChuocToi;
	bool m_bKhienBang;

	int m_iPercentHP4Skill;
	int m_iPercentHP4Item;
	int m_iPercentHP4LaChan;
	int m_iPercentHP4IronSolari;
	int m_iPercentHP4SonThach;
	int m_iPercentHP4DongHoCat;
	int m_iPercentHP4QT_DTS;
	int m_iPercentHP4ChuocToi;

	bool m_bChooseLine2;

public:
	~CIniManager(void);

	static CIniManager* GetInstance();

	void WriteIniFile();
	void ReadIniFile();
	void ReadIniFile2(char *filename);
	
	char* GetUsername() const;
	void SetUsername(const char* val) ;

	char*	GetCombo_Key() const;
	void	SetCombo_Key(const char* val) ;
	char*	GetLaneClear_Key() const;
	void	SetLaneClear_Key(const char* val) ;
	char*	GetHarass_Key() const;
	void	SetHarass_Key(const char* val) ;
	char*	GetLastHit_Key() const;
	void	SetLastHit_Key(const char* val) ;

	bool GetAtkCurrentSelected() const { return m_bAtkCurrentSelected; }
	void SetAtkCurrentSelected(bool val) { m_bAtkCurrentSelected = val; }
	bool GetCombo() const { return m_bCombo; }
	void SetCombo(bool val) { m_bCombo = val; }
	bool GetComboUseQ() const { return m_bComboUseQ; }
	void SetComboUseQ(bool val) { m_bComboUseQ = val; }
	bool GetComboUseW() const { return m_bComboUseW; }
	void SetComboUseW(bool val) { m_bComboUseW = val; }
	bool GetComboUseE() const { return m_bComboUseE; }
	void SetComboUseE(bool val) { m_bComboUseE = val; }
	bool GetComboUseR() const { return m_bComboUseR; }
	void SetComboUseR(bool val) { m_bComboUseR = val; }
	bool GetClearLane() const { return m_bClearLane; }
	void SetClearLane(bool val) { m_bClearLane = val; }
	bool GetClearLaneUseQ() const { return m_bClearLaneUseQ; }
	void SetClearLaneUseQ(bool val) { m_bClearLaneUseQ = val; }
	bool GetClearLaneUseW() const { return m_bClearLaneUseW; }
	void SetClearLaneUseW(bool val) { m_bClearLaneUseW = val; }
	bool GetClearLaneUseE() const { return m_bClearLaneUseE; }
	void SetClearLaneUseE(bool val) { m_bClearLaneUseE = val; }
	bool GetClearLaneUseR() const { return m_bClearLaneUseR; }
	void SetClearLaneUseR(bool val) { m_bClearLaneUseR = val; }
	bool GetHarass() const { return m_bHarass; }
	void SetHarass(bool val) { m_bHarass = val; }
	bool GetHarassUseQ() const { return m_bHarassUseQ; }
	void SetHarassUseQ(bool val) { m_bHarassUseQ = val; }
	bool GetHarassUseW() const { return m_bHarassUseW; }
	void SetHarassUseW(bool val) { m_bHarassUseW = val; }
	bool GetHarassUseE() const { return m_bHarassUseE; }
	void SetHarassUseE(bool val) { m_bHarassUseE = val; }
	bool GetHarassUseR() const { return m_bHarassUseR; }
	void SetHarassUseR(bool val) { m_bHarassUseR = val; }
	bool GetLastHit() const { return m_bLastHit; }
	void SetLastHit(bool val) { m_bLastHit = val; }
	bool GetMove2Mouse() const { return m_bMove2Mouse; }
	void SetMove2Mouse(bool val) { m_bMove2Mouse = val; }
	bool GetEvadeLine() const { return m_bEvadeLine; }
	void SetEvadeLine(bool val) { m_bEvadeLine = val; }
	bool GetEvadeCircle() const { return m_bEvadeCircle; }
	void SetEvadeCircle(bool val) { m_bEvadeCircle = val; }
	bool GetEvadeDangerous() const { return m_bEvadeDangerous; }
	void SetEvadeDangerous(bool val) { m_bEvadeDangerous = val; }
	bool GetHackZoom() const { return m_bHackZoom; }
	void SetHackZoom(bool val) { m_bHackZoom = val; }
	bool GetModSkin() const { return m_bModSkin; }
	void SetModSkin(bool val) { m_bModSkin = val; }
	bool GetPlayWithBot() const { return m_bPlayWithBot; }
	void SetPlayWithBot(bool val) { m_bPlayWithBot = val; }

	int GetPercentManaClearLane() const { return m_iPercentManaClearLane; }
	void SetPercentManaClearLane(int val) { m_iPercentManaClearLane = val; }
	int GetPercentManaHarass() const { return m_iPercentManaHarass; }
	void SetPercentManaHarass(int val) { m_iPercentManaHarass = val; }
	int GetDelaySkillAfter() const { return m_iDelaySkillAfter; }
	void SetDelaySkillAfter(int val) { m_iDelaySkillAfter = val; }


	bool GetBatTatVeHinh() const { return m_bBatTatVeHinh; }
	void SetBatTatVeHinh(bool val) { m_bBatTatVeHinh = val; }
	bool GetVeMatThuong() const { return m_bVeMatThuong; }
	void SetVeMatThuong(bool val) { m_bVeMatThuong = val; }
	bool GetVeMatKiemSoat() const { return m_bVeMatKiemSoat; }
	void SetVeMatKiemSoat(bool val) { m_bVeMatKiemSoat = val; }
	bool GetVeCanhBaoGank() const { return m_bVeCanhBaoGank; }
	void SetVeCanhBaoGank(bool val) { m_bVeCanhBaoGank = val; }
	bool GetVeDoanHuong() const { return m_bVeDoanHuong; }
	void SetVeDoanHuong(bool val) { m_bVeDoanHuong = val; }
	bool GetVeTamTruDich() const { return m_bVeTamTruDich; }
	void SetVeTamTruDich(bool val) { m_bVeTamTruDich = val; }
	bool GetVeTamTruDongMinh() const { return m_bVeTamTruDongMinh; }
	void SetVeTamTruDongMinh(bool val) { m_bVeTamTruDongMinh = val; }
	bool GetVeTimeEnemyRecall() const { return m_bVeTimeEnemyRecall; }
	void SetVeTimeEnemyRecall(bool val) { m_bVeTimeEnemyRecall = val; }
	bool GetVeTimeEnemyHoiSkill() const { return m_bVeTimeEnemyHoiSkill; }
	void SetVeTimeEnemyHoiSkill(bool val) { m_bVeTimeEnemyHoiSkill = val; }
	bool GetVeTimeEnemyHoiSpell() const { return m_bVeTimeEnemyHoiSpell; }
	void SetVeTimeEnemyHoiSpell(bool val) { m_bVeTimeEnemyHoiSpell = val; }
	bool GetVeTimeXuatHienQuaiRung() const { return m_bVeTimeXuatHienQuaiRung; }
	void SetVeTimeXuatHienQuaiRung(bool val) { m_bVeTimeXuatHienQuaiRung = val; }
	bool GetVePlayerDanhThuong() const { return m_bVePlayerDanhThuong; }
	void SetVePlayerDanhThuong(bool val) { m_bVePlayerDanhThuong = val; }
	bool GetVePlayerSkillQ() const { return m_bVePlayerSkillQ; }
	void SetVePlayerSkillQ(bool val) { m_bVePlayerSkillQ = val; }
	bool GetVePlayerSkillW() const { return m_bVePlayerSkillW; }
	void SetVePlayerSkillW(bool val) { m_bVePlayerSkillW = val; }
	bool GetVePlayerSkillE() const { return m_bVePlayerSkillE; }
	void SetVePlayerSkillE(bool val) { m_bVePlayerSkillE = val; }
	bool GetVePlayerSkillR() const { return m_bVePlayerSkillR; }
	void SetVePlayerSkillR(bool val) { m_bVePlayerSkillR = val; }
	bool GetVeEnemyDanhThuong() const { return m_bVeEnemyDanhThuong; }
	void SetVeEnemyDanhThuong(bool val) { m_bVeEnemyDanhThuong = val; }
	bool GetVeEnemySkillQ() const { return m_bVeEnemySkillQ; }
	void SetVeEnemySkillQ(bool val) { m_bVeEnemySkillQ = val; }
	bool GetVeEnemySkillW() const { return m_bVeEnemySkillW; }
	void SetVeEnemySkillW(bool val) { m_bVeEnemySkillW = val; }
	bool GetVeEnemySkillE() const { return m_bVeEnemySkillE; }
	void SetVeEnemySkillE(bool val) { m_bVeEnemySkillE = val; }
	bool GetVeEnemySkillR() const { return m_bVeEnemySkillR; }
	void SetVeEnemySkillR(bool val) { m_bVeEnemySkillR = val; }

	bool GetHoiMau_Skill() const { return m_bHoiMau_Skill; }
	void SetHoiMau_Skill(bool val) { m_bHoiMau_Skill = val; }
	bool GetHoiMau_Item() const { return m_bHoiMau_Item; }
	void SetHoiMau_Item(bool val) { m_bHoiMau_Item = val; }
	bool GetThieuDot() const { return m_bThieuDot; }
	void SetThieuDot(bool val) { m_bThieuDot = val; }
	bool GetThanhTay() const { return m_bThanhTay; }
	void SetThanhTay(bool val) { m_bThanhTay = val; }
	bool GetLaChan() const { return m_bLaChan; }
	void SetLaChan(bool val) { m_bLaChan = val; }
	bool GetTrungPhat() const { return m_bTrungPhat; }
	void SetTrungPhat(bool val) { m_bTrungPhat = val; }
	bool GetVoDanh() const { return m_bVoDanh; }
	void SetVoDanh(bool val) { m_bVoDanh = val; }
	bool GetHextech() const { return m_bHextech; }
	void SetHextech(bool val) { m_bHextech = val; }
	bool GetTiamat() const { return m_bTiamat; }
	void SetTiamat(bool val) { m_bTiamat = val; }
	bool GetIronSolari() const { return m_bIronSolari; }
	void SetIronSolari(bool val) { m_bIronSolari = val; }
	bool GetSonThach() const { return m_bSonThach; }
	void SetSonThach(bool val) { m_bSonThach = val; }
	bool GetDongHoCat() const { return m_bDongHoCat; }
	void SetDongHoCat(bool val) { m_bDongHoCat = val; }
	bool GetQuyenTruongDTS() const { return m_bQuyenTruongDTS; }
	void SetQuyenTruongDTS(bool val) { m_bQuyenTruongDTS = val; }
	bool GetKhanGiaiThuat() const { return m_bKhanGiaiThuat; }
	void SetKhanGiaiThuat(bool val) { m_bKhanGiaiThuat = val; }
	bool GetHomMikael() const { return m_bHomMikael; }
	void SetHomMikael(bool val) { m_bHomMikael = val; }
	bool GetChuocToi() const { return m_bChuocToi; }
	void SetChuocToi(bool val) { m_bChuocToi = val; }
	bool GetKhienBang() const { return m_bKhienBang; }
	void SetKhienBang(bool val) { m_bKhienBang = val; }

	int GetPercentHP4Skill() const { return m_iPercentHP4Skill; }
	void SetPercentHP4Skill(int val) { m_iPercentHP4Skill = val; }
	int GetPercentHP4Item() const { return m_iPercentHP4Item; }
	void SetPercentHP4Item(int val) { m_iPercentHP4Item = val; }
	int GetPercentHP4LaChan() const { return m_iPercentHP4LaChan; }
	void SetPercentHP4LaChan(int val) { m_iPercentHP4LaChan = val; }
	int GetPercentHP4IronSolari() const { return m_iPercentHP4IronSolari; }
	void SetPercentHP4IronSolari(int val) { m_iPercentHP4IronSolari = val; }
	int GetPercentHP4SonThach() const { return m_iPercentHP4SonThach; }
	void SetPercentHP4SonThach(int val) { m_iPercentHP4SonThach = val; }
	int GetPercentHP4DongHoCat() const { return m_iPercentHP4DongHoCat; }
	void SetPercentHP4DongHoCat(int val) { m_iPercentHP4DongHoCat = val; }
	int GetPercentHP4QT_DTS() const { return m_iPercentHP4QT_DTS; }
	void SetPercentHP4QT_DTS(int val) { m_iPercentHP4QT_DTS = val; }
	int GetPercentHP4ChuocToi() const { return m_iPercentHP4ChuocToi; }
	void SetPercentHP4ChuocToi(int val) { m_iPercentHP4ChuocToi = val; }
	bool GetChooseLine2() const { return m_bChooseLine2; }
	void SetChooseLine2(bool val) { m_bChooseLine2 = val; }
};
