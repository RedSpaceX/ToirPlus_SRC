#include "stdafx.h"
#include "GameData.h"

SLMHTClientData::SLMHTClientData()
{
	m_slcdAtkCurrentSelected		= false;
	m_slcdCombo						= false;
	m_slcdComboUseQ					= false;
	m_slcdComboUseW					= false;
	m_slcdComboUseE					= false;
	m_slcdComboUseR					= false;
	m_slcdClearLane					= false;
	m_slcdClearLaneUseQ				= false;
	m_slcdClearLaneUseW				= false;
	m_slcdClearLaneUseE				= false;
	m_slcdClearLaneUseR				= false;
	m_slcdHarass					= false;
	m_slcdHarassUseQ				= false;
	m_slcdHarassUseW				= false;
	m_slcdHarassUseE				= false;
	m_slcdHarassUseR				= false;
	m_slcdLastHit					= false;
	m_slcdMove2Mouse				= false;
	m_slcdEvadeLine					= false;
	m_slcdEvadeCircle				= false;
	m_slcdEvadeDangerous			= false;
	m_slcdHackZoom					= false;
	m_slcdModSkin					= false;
	m_slcdDanhVoiMay				= false;
	m_slcdHoiMau_Skill				= false;
	m_slcdHoiMau_Item				= false;
	m_slcdThieuDot					= false;
	m_slcdThanhTay					= false;
	m_slcdLaChan					= false;
	m_slcdTrungPhat					= false;
	m_slcdVoDanh					= false;
	m_slcdHextech					= false;
	m_slcdTiamat					= false;
	m_slcdIronSolari				= false;
	m_slcdSonThach					= false;
	m_slcdDongHoCat					= false;
	m_slcdQuyenTruongDTS			= false;
	m_slcdKhanGiaiThuat				= false;
	m_slcdHomMikael					= false;
	m_slcdChuocToi					= false;
	m_slcdKhienBang					= false;

	SetCBPercentManaClearLane(45);
	SetCBPercentManaHarass(45);
	SetCBDelaySkillAfter(0);
	SetCBPercentHP4Skill(25);
	SetCBPercentHP4Item(45);
	SetCBPercentHP4LaChan(40);
	SetCBPercentHP4IronSolari(35);
	SetCBPercentHP4SonThach(35);
	SetCBPercentHP4DongHoCat(25);
	SetCBPercentHP4QT_DTS(35);
	SetCBPercentHP4ChuocToi(45);
}

SLMHTClientData* SLMHTClientData::sInstance = NULL;

SLMHTClientData* SLMHTClientData::GetInstance()
{
	if (sInstance == NULL)
	{
		sInstance = new SLMHTClientData();
	}
	return sInstance;
}
