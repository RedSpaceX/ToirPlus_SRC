#pragma once
#include "D3dx9math.h"
#include "Address_Game.h"

extern DWORD G_Module;
struct SLMHTClientData
{
private:
	bool m_slcdAtkCurrentSelected;
	bool m_slcdCombo;
	bool m_slcdComboUseQ;
	bool m_slcdComboUseW;
	bool m_slcdComboUseE;
	bool m_slcdComboUseR;
	bool m_slcdClearLane;
	bool m_slcdClearLaneUseQ;
	bool m_slcdClearLaneUseW;
	bool m_slcdClearLaneUseE;
	bool m_slcdClearLaneUseR;
	bool m_slcdHarass;
	bool m_slcdHarassUseQ;
	bool m_slcdHarassUseW;
	bool m_slcdHarassUseE;
	bool m_slcdHarassUseR;
	bool m_slcdLastHit;
	bool m_slcdMove2Mouse;
	bool m_slcdEvadeLine;
	bool m_slcdEvadeCircle;
	bool m_slcdEvadeDangerous;
	bool m_slcdHackZoom;
	bool m_slcdModSkin;
	bool m_slcdDanhVoiMay;

	int m_slcdPercentManaClearLane;
	int m_slcdPercentManaHarass;
	int m_slcdDelaySkillAfter;

	bool m_slcdBatTatVe;
	bool m_slcdVeMatThuong;
	bool m_slcdVeMatKiemSoat;
	bool m_slcdVeCanhBaoGank;
	bool m_slcdVeDoanHuong;
	bool m_slcdVeTamTruDich;
	bool m_slcdVeTamTruDongMinh;
	bool m_slcdVeTimeEnemyRecall;
	bool m_slcdVeTimeEnemyHoiSkill;
	bool m_slcdVeTimeEnemyHoiSpell;
	bool m_slcdVeTimeXuatHienQuaiRung;
	bool m_slcdVePlayerDanhThuong;
	bool m_slcdVePlayerSkillQ;
	bool m_slcdVePlayerSkillW;
	bool m_slcdVePlayerSkillE;
	bool m_slcdVePlayerSkillR;
	bool m_slcdVeEnemyDanhThuong;
	bool m_slcdVeEnemySkillQ;
	bool m_slcdVeEnemySkillW;
	bool m_slcdVeEnemySkillE;
	bool m_slcdVeEnemySkillR;

	bool m_slcdHoiMau_Skill;
	bool m_slcdHoiMau_Item;
	bool m_slcdThieuDot;
	bool m_slcdThanhTay;
	bool m_slcdLaChan;
	bool m_slcdTrungPhat;
	bool m_slcdVoDanh;
	bool m_slcdHextech;
	bool m_slcdTiamat;
	bool m_slcdIronSolari;
	bool m_slcdSonThach;
	bool m_slcdDongHoCat;
	bool m_slcdQuyenTruongDTS;
	bool m_slcdKhanGiaiThuat;
	bool m_slcdHomMikael;
	bool m_slcdChuocToi;
	bool m_slcdKhienBang;

	int m_slcdPercentHP4Skill;
	int m_slcdPercentHP4Item;
	int m_slcdPercentHP4LaChan;
	int m_slcdPercentHP4IronSolari;
	int m_slcdPercentHP4SonThach;
	int m_slcdPercentHP4DongHoCat;
	int m_slcdPercentHP4QT_DTS;
	int m_slcdPercentHP4ChuocToi;

	SLMHTClientData();

	static SLMHTClientData* sInstance;
public:
	static SLMHTClientData* GetInstance();

	bool GetCBAtkCurrentSelected() const { return m_slcdAtkCurrentSelected; }
	void SetCBAtkCurrentSelected(bool val) { m_slcdAtkCurrentSelected = val; }
	bool GetCBCombo() const { return m_slcdCombo; }
	void SetCBCombo(bool val) { m_slcdCombo = val; }
	bool GetCBComboUseQ() const { return m_slcdComboUseQ; }
	void SetCBComboUseQ(bool val) { m_slcdComboUseQ = val; }
	bool GetCBComboUseW() const { return m_slcdComboUseW; }
	void SetCBComboUseW(bool val) { m_slcdComboUseW = val; }
	bool GetCBComboUseE() const { return m_slcdComboUseE; }
	void SetCBComboUseE(bool val) { m_slcdComboUseE = val; }
	bool GetCBComboUseR() const { return m_slcdComboUseR; }
	void SetCBComboUseR(bool val) { m_slcdComboUseR = val; }
	bool GetCBClearLane() const { return m_slcdClearLane; }
	void SetCBClearLane(bool val) { m_slcdClearLane = val; }
	bool GetCBClearLaneUseQ() const { return m_slcdClearLaneUseQ; }
	void SetCBClearLaneUseQ(bool val) { m_slcdClearLaneUseQ = val; }
	bool GetCBClearLaneUseW() const { return m_slcdClearLaneUseW; }
	void SetCBClearLaneUseW(bool val) { m_slcdClearLaneUseW = val; }
	bool GetCBClearLaneUseE() const { return m_slcdClearLaneUseE; }
	void SetCBClearLaneUseE(bool val) { m_slcdClearLaneUseE = val; }
	bool GetCBClearLaneUseR() const { return m_slcdClearLaneUseR; }
	void SetCBClearLaneUseR(bool val) { m_slcdClearLaneUseR = val; }
	bool GetCBHarass() const { return m_slcdHarass; }
	void SetCBHarass(bool val) { m_slcdHarass = val; }
	bool GetCBHarassUseQ() const { return m_slcdHarassUseQ; }
	void SetCBHarassUseQ(bool val) { m_slcdHarassUseQ = val; }
	bool GetCBHarassUseW() const { return m_slcdHarassUseW; }
	void SetCBHarassUseW(bool val) { m_slcdHarassUseW = val; }
	bool GetCBHarassUseE() const { return m_slcdHarassUseE; }
	void SetCBHarassUseE(bool val) { m_slcdHarassUseE = val; }
	bool GetCBHarassUseR() const { return m_slcdHarassUseR; }
	void SetCBHarassUseR(bool val) { m_slcdHarassUseR = val; }
	bool GetCBLastHit() const { return m_slcdLastHit; }
	void SetCBLastHit(bool val) { m_slcdLastHit = val; }
	bool GetCBMove2Mouse() const { return m_slcdMove2Mouse; }
	void SetCBMove2Mouse(bool val) { m_slcdMove2Mouse = val; }

	bool GetCBEvadeLine() const { return m_slcdEvadeLine; }
	void SetCBEvadeLine(bool val) { m_slcdEvadeLine = val; }
	bool GetCBEvadeCircle() const { return m_slcdEvadeCircle; }
	void SetCBEvadeCircle(bool val) { m_slcdEvadeCircle = val; }
	bool GetCBEvadeDangerous() const { return m_slcdEvadeDangerous; }
	void SetCBEvadeDangerous(bool val) { m_slcdEvadeDangerous = val; }

	bool GetCBHackZoom() const { return m_slcdHackZoom; }
	void SetCBHackZoom(bool val) { m_slcdHackZoom = val; }
	bool GetCBModSkin() const { return m_slcdModSkin; }
	void SetCBModSkin(bool val) { m_slcdModSkin = val; }

	bool GetCBDanhVoiMay() const { return m_slcdDanhVoiMay; }
	void SetCBDanhVoiMay(bool val) { m_slcdDanhVoiMay = val; }

	int GetCBPercentManaClearLane() const { return m_slcdPercentManaClearLane; }
	void SetCBPercentManaClearLane(int val) { m_slcdPercentManaClearLane = val; }
	int GetCBPercentManaHarass() const { return m_slcdPercentManaHarass; }
	void SetCBPercentManaHarass(int val) { m_slcdPercentManaHarass = val; }
	int GetCBDelaySkillAfter() const { return m_slcdDelaySkillAfter; }
	void SetCBDelaySkillAfter(int val) { m_slcdDelaySkillAfter = val; }

	bool GetCBBatTatVe() const { return m_slcdBatTatVe; }
	void SetCBBatTatVe(bool val) { m_slcdBatTatVe = val; }
	bool GetCBVeMatThuong() const { return m_slcdVeMatThuong; }
	void SetCBVeMatThuong(bool val) { m_slcdVeMatThuong = val; }
	bool GetCBVeMatKiemSoat() const { return m_slcdVeMatKiemSoat; }
	void SetCBVeMatKiemSoat(bool val) { m_slcdVeMatKiemSoat = val; }
	bool GetCBVeCanhBaoGank() const { return m_slcdVeCanhBaoGank; }
	void SetCBVeCanhBaoGank(bool val) { m_slcdVeCanhBaoGank = val; }
	bool GetCBVeDoanHuong() const { return m_slcdVeDoanHuong; }
	void SetCBVeDoanHuong(bool val) { m_slcdVeDoanHuong = val; }
	bool GetCBVeTamTruDich() const { return m_slcdVeTamTruDich; }
	void SetCBVeTamTruDich(bool val) { m_slcdVeTamTruDich = val; }
	bool GetCBVeTamTruDongMinh() const { return m_slcdVeTamTruDongMinh; }
	void SetCBVeTamTruDongMinh(bool val) { m_slcdVeTamTruDongMinh = val; }
	bool GetCBVeTimeEnemyRecall() const { return m_slcdVeTimeEnemyRecall; }
	void SetCBVeTimeEnemyRecall(bool val) { m_slcdVeTimeEnemyRecall = val; }
	bool GetCBVeTimeEnemyHoiSkill() const { return m_slcdVeTimeEnemyHoiSkill; }
	void SetCBVeTimeEnemyHoiSkill(bool val) { m_slcdVeTimeEnemyHoiSkill = val; }
	bool GetCBVeTimeEnemyHoiSpell() const { return m_slcdVeTimeEnemyHoiSpell; }
	void SetCBVeTimeEnemyHoiSpell(bool val) { m_slcdVeTimeEnemyHoiSpell = val; }
	bool GetCBVeTimeXuatHienQuaiRung() const { return m_slcdVeTimeXuatHienQuaiRung; }
	void SetCBVeTimeXuatHienQuaiRung(bool val) { m_slcdVeTimeXuatHienQuaiRung = val; }
	bool GetCBVePlayerDanhThuong() const { return m_slcdVePlayerDanhThuong; }
	void SetCBVePlayerDanhThuong(bool val) { m_slcdVePlayerDanhThuong = val; }
	bool GetCBVePlayerSkillQ() const { return m_slcdVePlayerSkillQ; }
	void SetCBVePlayerSkillQ(bool val) { m_slcdVePlayerSkillQ = val; }
	bool GetCBVePlayerSkillW() const { return m_slcdVePlayerSkillW; }
	void SetCBVePlayerSkillW(bool val) { m_slcdVePlayerSkillW = val; }
	bool GetCBVePlayerSkillE() const { return m_slcdVePlayerSkillE; }
	void SetCBVePlayerSkillE(bool val) { m_slcdVePlayerSkillE = val; }
	bool GetCBVePlayerSkillR() const { return m_slcdVePlayerSkillR; }
	void SetCBVePlayerSkillR(bool val) { m_slcdVePlayerSkillR = val; }
	bool GetCBVeEnemyDanhThuong() const { return m_slcdVeEnemyDanhThuong; }
	void SetCBVeEnemyDanhThuong(bool val) { m_slcdVeEnemyDanhThuong = val; }
	bool GetCBVeEnemySkillQ() const { return m_slcdVeEnemySkillQ; }
	void SetCBVeEnemySkillQ(bool val) { m_slcdVeEnemySkillQ = val; }
	bool GetCBVeEnemySkillW() const { return m_slcdVeEnemySkillW; }
	void SetCBVeEnemySkillW(bool val) { m_slcdVeEnemySkillW = val; }
	bool GetCBVeEnemySkillE() const { return m_slcdVeEnemySkillE; }
	void SetCBVeEnemySkillE(bool val) { m_slcdVeEnemySkillE = val; }
	bool GetCBVeEnemySkillR() const { return m_slcdVeEnemySkillR; }
	void SetCBVeEnemySkillR(bool val) { m_slcdVeEnemySkillR = val; }

	bool GetCBHoiMau_Skill() const { return m_slcdHoiMau_Skill; }
	void SetCBHoiMau_Skill(bool val) { m_slcdHoiMau_Skill = val; }
	bool GetCBHoiMau_Item() const { return m_slcdHoiMau_Item; }
	void SetCBHoiMau_Item(bool val) { m_slcdHoiMau_Item = val; }
	bool GetCBThieuDot() const { return m_slcdThieuDot; }
	void SetCBThieuDot(bool val) { m_slcdThieuDot = val; }
	bool GetCBThanhTay() const { return m_slcdThanhTay; }
	void SetCBThanhTay(bool val) { m_slcdThanhTay = val; }
	bool GetCBLaChan() const { return m_slcdLaChan; }
	void SetCBLaChan(bool val) { m_slcdLaChan = val; }
	bool GetCBTrungPhat() const { return m_slcdTrungPhat; }
	void SetCBTrungPhat(bool val) { m_slcdTrungPhat = val; }
	bool GetCBVoDanh() const { return m_slcdVoDanh; }
	void SetCBVoDanh(bool val) { m_slcdVoDanh = val; }
	bool GetCBHextech() const { return m_slcdHextech; }
	void SetCBHextech(bool val) { m_slcdHextech = val; }
	bool GetCBTiamat() const { return m_slcdTiamat; }
	void SetCBTiamat(bool val) { m_slcdTiamat = val; }
	bool GetCBIronSolari() const { return m_slcdIronSolari; }
	void SetCBIronSolari(bool val) { m_slcdIronSolari = val; }
	bool GetCBSonThach() const { return m_slcdSonThach; }
	void SetCBSonThach(bool val) { m_slcdSonThach = val; }
	bool GetCBDongHoCat() const { return m_slcdDongHoCat; }
	void SetCBDongHoCat(bool val) { m_slcdDongHoCat = val; }
	bool GetCBQuyenTruongDTS() const { return m_slcdQuyenTruongDTS; }
	void SetCBQuyenTruongDTS(bool val) { m_slcdQuyenTruongDTS = val; }
	bool GetCBKhanGiaiThuat() const { return m_slcdKhanGiaiThuat; }
	void SetCBKhanGiaiThuat(bool val) { m_slcdKhanGiaiThuat = val; }
	bool GetCBHomMikael() const { return m_slcdHomMikael; }
	void SetCBHomMikael(bool val) { m_slcdHomMikael = val; }
	bool GetCBChuocToi() const { return m_slcdChuocToi; }
	void SetCBChuocToi(bool val) { m_slcdChuocToi = val; }
	bool GetCBKhienBang() const { return m_slcdKhienBang; }
	void SetCBKhienBang(bool val) { m_slcdKhienBang = val; }

	int GetCBPercentHP4Skill() const { return m_slcdPercentHP4Skill; }
	void SetCBPercentHP4Skill(int val) { m_slcdPercentHP4Skill = val; }
	int GetCBPercentHP4Item() const { return m_slcdPercentHP4Item; }
	void SetCBPercentHP4Item(int val) { m_slcdPercentHP4Item = val; }
	int GetCBPercentHP4LaChan() const { return m_slcdPercentHP4LaChan; }
	void SetCBPercentHP4LaChan(int val) { m_slcdPercentHP4LaChan = val; }
	int GetCBPercentHP4IronSolari() const { return m_slcdPercentHP4IronSolari; }
	void SetCBPercentHP4IronSolari(int val) { m_slcdPercentHP4IronSolari = val; }
	int GetCBPercentHP4SonThach() const { return m_slcdPercentHP4SonThach; }
	void SetCBPercentHP4SonThach(int val) { m_slcdPercentHP4SonThach = val; }
	int GetCBPercentHP4DongHoCat() const { return m_slcdPercentHP4DongHoCat; }
	void SetCBPercentHP4DongHoCat(int val) { m_slcdPercentHP4DongHoCat = val; }
	int GetCBPercentHP4QT_DTS() const { return m_slcdPercentHP4QT_DTS; }
	void SetCBPercentHP4QT_DTS(int val) { m_slcdPercentHP4QT_DTS = val; }
	int GetCBPercentHP4ChuocToi() const { return m_slcdPercentHP4ChuocToi; }
	void SetCBPercentHP4ChuocToi(int val) { m_slcdPercentHP4ChuocToi = val; }
};

//==================================================================================//
class Vec3D {

public:

	union {
		float data[3];
		struct {
			float x;
			float y;
			float z;
		};
	};

	// Constructors

	// Vectors default to 0, 0, 0.
	Vec3D() {
		x = 0;
		y = 0;
		z = 0;
	}

	// Construct with values, 3D
	Vec3D(float ax, float ay, float az) {
		x = ax;
		y = ay;
		z = az;
	}

	// Construct with values, 2D
	Vec3D(float ax, float ay) {
		x = ax;
		y = ay;
		z = 0;
	}

	// Copy constructor
	Vec3D(const Vec3D& o) {
		x = o.x;
		y = o.y;
		z = o.z;
	}

	// Addition

	Vec3D operator+(const Vec3D& o) {
		return Vec3D(x + o.x, y + o.y, z + o.z);
	}

	Vec3D& operator+=(const Vec3D& o) {
		x += o.x;
		y += o.y;
		z += o.z;
		return *this;
	}

	// Subtraction

	Vec3D operator-() {
		return Vec3D(-x, -y, -z);
	}

	Vec3D operator-(const Vec3D o) {
		return Vec3D(x - o.x, y - o.y, z - o.z);
	}

	Vec3D& operator-=(const Vec3D o) {
		x -= o.x;
		y -= o.y;
		z -= o.z;
		return *this;
	}

	// Multiplication by scalars

	Vec3D operator*(const float s) {
		return Vec3D(x * s, y * s, z * s);
	}

	Vec3D& operator*=(const float s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}

	// Division by scalars

	Vec3D operator/(const float s) {
		return Vec3D(x / s, y / s, z / s);
	}

	Vec3D& operator/=(const float s) {
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	// Dot product

	float operator*(const Vec3D o) {
		return (x * o.x) + (y * o.y) + (z * o.z);
	}

	// An in-place dot product does not exist because
	// the result is not a vector.

	// Cross product

	Vec3D operator^(const Vec3D o) {
		float nx = y * o.z - o.y * z;
		float ny = z * o.x - o.z * x;
		float nz = x * o.y - o.x * y;
		return Vec3D(nx, ny, nz);
	}

	Vec3D& operator^=(const Vec3D o) {
		float nx = y * o.z - o.y * z;
		float ny = z * o.x - o.z * x;
		float nz = x * o.y - o.x * y;
		x = nx;
		y = ny;
		z = nz;
		return *this;
	}
	bool operator==(Vec3D *pos)
	{
		if (pos == NULL && this == NULL) return true;
		else if (pos == NULL && 0 == x && 0 == y && 0 == z) return true;
		else if (pos == NULL && (0 != x || 0 != y || 0 != z)) return false;
		else if (x == pos->x && y == pos->y && z == pos->z) return true;
		return false;
	}
	bool operator==(Vec3D &pos)
	{
		/*if (pos == NULL && this == NULL) return true;
		else */if (pos == NULL && 0 == x && 0 == y && 0 == z) return true;
		else if (pos == NULL && (0 != x || 0 != y || 0 != z)) return false;
		else if (x == pos.x && y == pos.y && z == pos.z) return true;
		return false;
	}
	// Other functions

	// Length of vector
	float Leng() {
		return sqrt(Leng_sqr());
	}

	// Length of vector squared
	float Leng_sqr() {
		return (x * x) + (y * y) + (z * z);
	}
	
	bool IsValid()
	{
		if(x == 0 && y == 0 && z == 0) return false;
		return true;
	}

	Vec3D To2D()
	{
		return Vec3D(x, 0, z);
	}

	float DistanceSq(Vec3D v) {
		return (x-v.x)*(x-v.x) + (z-v.z)*(z-v.z);
	}

	float Distance2D(Vec3D v) {
		return sqrt((x-v.x)*(x-v.x) + (z-v.z)*(z-v.z));
	}

	Vec3D Normalized() {
		Vec3D v;
		if(Leng() == 0) return v;
		return Vec3D(*this) / Leng();
	}

	//// Returns a normalised copy of the vector
	//// Will break if it's length is 0
	//Vec normalised() {
	//	return Vec(*this) / Leng();
	//}

	//// Modified the vector so it becomes normalised
	//Vec& normalise() {
	//	(*this) /= Leng();
	//	return *this;
	//}
};

//==================================================================================//
enum DamageType
{
	DmgMagical  = 0,
	DmgPhysical = 1,
	DmgTrue		= 2,
};
enum HitChance
{
	Immobile = 8,			///     The target is immobile.
	Dashing = 7,			///     The unit is dashing.
	VeryHigh = 6,			///     Very high probability of hitting the target.
	High = 5,				///     High probability of hitting the target.
	Medium = 4,				///     Medium probability of hitting the target.
	Low = 3,				///     Low probability of hitting the target.
	Impossible = 2,			///     Impossible to hit the target.
	OutOfRange = 1,			///     The target is out of range.
	eCollision = 0			///     The target is blocked by other units.
};

enum SkillshotType
{
	SkillshotLine,			///     The skillshot is linear.
	SkillshotCircle,		///     The skillshot is circular.
	SkillshotCone			///     The skillshot is conical.
};

enum CollisionableObjects
{
	Minions,				///     Minions.
	Heroes,					///     Enemy heroes.
	YasuoWall,				///     Yasuo's Wind Wall (W)
	Walls,					///     Walls.
	Allies,					///     Ally heroes.
	None_1,
	None_2,
	None_3
};
//==================================================================================//
struct KItem_2{	//details	
	int 		nTemp_1[25];
	int 		nID;
	int 		nTemp_2[5];	
	int 		nPrice;	
};
//==================================================================================//
struct KItem_1{			
	int 		nTemp_1[4];
	int			pName;//lay con tro ra name TA
	int 		nTemp_2[3];
	DWORD		_KItem_2;
	int			nCharges;// lay BYTE(vi du bthuoc di rung)
};
//==================================================================================//
struct KItem{		
	//DWORD 		_KItem_1;// _KItem_1 == 0: ko co
	int			nCount;		//lay BYTE
	int 		nTemp_2[2];
	DWORD 		_KItem_1;// _KItem_1 == 0: ko co
	//int 		nTemp_3[21];	
	//DWORD 		_KItem_1;// _KItem_1 == 0: ko co
};

//==================================================================================//
struct KPos
{
	float x, y, z;
	KPos(){ x = y = z = 0;}
	KPos(float x1, float y1, float z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}
	KPos operator=(KPos pos)
	{
		x = pos.x, y = pos.y, z = pos.z;
		return *this;
	}
	bool operator==(KPos *pos)
	{
		if (pos == NULL && this == NULL) return true;
		else if (pos == NULL && 0 == x && 0 == y && 0 == z) return true;
		else if (pos == NULL && (0 != x || 0 != y || 0 != z)) return false;
		else if (x == pos->x && y == pos->y && z == pos->z) return true;
		return false;
	}
	bool operator==(KPos &pos)
	{
		/*if (pos == NULL && this == NULL) return true;
		else */if (pos == NULL && 0 == x && 0 == y && 0 == z) return true;
		else if (pos == NULL && (0 != x || 0 != y || 0 != z)) return false;
		else if (x == pos.x && y == pos.y && z == pos.z) return true;
		return false;
	}
	bool operator!=(KPos *pos)
	{
		if (*this == *pos) return false;
		return true;
	}
	bool operator!=(KPos &pos)
	{
		if (*this == pos) return false;
		return true;;
	}
};
//==================================================================================//
struct KBuffer_Spell
{
	KPos SourcePos, MaxDestPos, MousePos; // vi tri chuot cua tuong dich
	KPos MousePos_Player;			// vi tri chuot cua ban than nguoi choi
	KPos PlayerPos;					// vi tri cua ban than nguoi choi
	float nTimer;
	float nSpecialTimer;
	float nTimeGameCAST_SKILL;
	bool isCasting;

	int index;
	char szHeroName[40];
	char szPlayerName[40];
	char szSpellName[48];

	float nDelay;
	float nRange;
	float nRadius;
	float nRadius_2;
	float nMissileSpeed;
	int nDangerValue;
	bool nIsDangerous;
	bool nFlag_TruocSau;
	bool IsSetSpellData;
	bool IsEvaded;
	DWORD pNpc;
};
//==================================================================================//
struct KSkill_1{		
	int 		nTemp_1[2];
	int			nID_Player;					
	int			nID_Target;	
	KPos SourcePos, MaxDestPos, MousePos;
};
////==================================================================================//
//struct KSkill_3{
//	int			nTemp_1[274];
//	float		nSpeed;
//	int 		nTemp_2;
//	int			nFlags;						//4
//	int			nAffectsTypeFlags;			//8
//	int			nAffectsStatusFlags;		//0xC
//	int 		nTemp_3[84];
//
//	float		nChannelDuration;			//0x220: level 1
//	int 		nTemp_4[7];
//	float		nCoolDown;					//0x240: thoi gian hoi time cua spell level 1
//	int 		nTemp_5[22];
//	int			nMaxAmmo;					//0x2C4: max dan. level 1
//	int 		nTemp_6[6];
//	int			nAmmo_Used;					//0x2E0: dan. level 1
//	int 		nTemp_7[6];
//	float		nAmmoRechargeTime;			//0x2FC: level 1
//	int 		nTemp_8[17];
//	int			nConsideredAsAutoAttack;	//0x344: BYTE
//	int 		nTemp_9;
//	float		nCast_Range;				//0x34C: level 1
//	int 		nTemp_10[6];
//	float		nCastRangeDisplayOverride;	//0x368: level 1
//	int 		nTemp_11[6];
//	float		nCast_Radius;				//0x384: level 1 : dung cho skill aoe xyz
//	int 		nTemp_12[5];
//	float		nCastConeAngle;				//0x39C: Goc' skill hinh` non'
//	float		nCastConeDistance;			//0x3A0: skill hinh` non'
//	int 		nTemp_13;
//	float		nBounceRadius;				//0x3A8: wat??: chieu dai canh day' hinh non??
//
//	int 		nTemp_14[6];
//	int			nCastType;					//0x3C4:type?? 3:giong Q_ryze, 0:W_R_ryze,1:E_ryze
//	float		nCastFrame;					//0x3C8
//	int 		nTemp_15[2];
//	float		nMissileSpeed;				//0x3D4
//	float		nMissileAccel;				//0x3D8
//	float		nMissile_MaxSpeed;			//0x3DC
//	float		nMissile_MinSpeed;			//0x3E0
//	float		nMissileFixedTravelTime;	//0x3E4
//	float		nMissileLifetime;			//0x3E8
//
//	int 		nTemp_16[25];
//	float		nLine_Width;				//0x450: chieu rong cua SKILL LINE
//	float		nLine_DragLength;			//0x454:
//
//	int 		nTemp_17[37];
//	float		nManaCost;					//0x4EC: level 1
//	int 		nTemp_18[12];
//
//	int			nTargettingType; 			//0x520:BYTE: 0,4:cast dc luon, 1: can target,2,hinh tron xyz,3:hinh non xyz,6:line,non nguoc xyz, 7:line,cast xyz
//	int 		nTemp_19[43];
//	float		nCastRadiusSecondary;		//0x5D0: level 1
//
//};
////==================================================================================//
//struct KSkill_3_Temp{  
//	float   nTemp_1[290];
//	float  nMis_speed;    
//
//	float  nCast_Range;    //3A4(6.07): level 1
//	int   nTemp_2[6];
//	float  nCast_Radius;    //3DC(6.07): level 1 : dung cho skill aoe xyz
//	int   nTemp_3[12];
//	float  nCastConeAngle;    //0x414: Goc' skill hinh` non'
//	float  nCastConeDistance;   //0x418: skill hinh` non'
//	int   nTemp_4[11];
//	float  nMissileSpeed;    //448H(6.07)
//	float  nMissileAccel;    //0x44C
//	float  nMissile_MaxSpeed;   //0x450
//	float  nMissile_MinSpeed;   //0x454
//	float  nMissileFixedTravelTime; //0x458
//	float  nMissileLifetime;   //0x45C
//
//	int   nTemp_5[25];
//	float  nLine_Width;    //0x4C4: chieu rong cua SKILL LINE
//	float  nLine_DragLength;   //0x4C8:
//
//	int   nTemp_6[50];
//
//	int   nTargettingType;    //594H(6.07):BYTE: 0,4:cast dc luon, 1: can target,2,hinh tron xyz,3:hinh non xyz,6:line,non nguoc xyz, 7:line,cast xyz
//};
//==================================================================================//
struct KSkill_2{		
	int 		nTemp_1[6];
	char		szName[16];					
	int			nLen_Name;
	int			nMaxLen_Name;
	int 		nTemp_2;
	int 		nTemp_3;
	DWORD		*__pK_str3;		//0x34

	char*		GetSkillName() // lay ten skill
	{
		char * strName = szName;
		if(nLen_Name > 15)
		{
			DWORD dw = *(DWORD*)&szName;
			strName = (char *)dw;
		}
		return strName;
	}
};
//==================================================================================//
struct KSkill{		
	int 		nTemp_1[8];
	int			nLevel;					//0x10
	int 		nTemp_2;
	float		nCooldownExpires;		//0x14: time co the cast lan tiep theo
	int			nAmmo;					//0x18: --gio sai offset nay
	int 		nTemp_2_1[8];
	float		nCooldownExpires_2;		//0x1C: dung cho Leblanc
	float		nTotalCooldown_2;		//0x20: dung cho Leblanc
	int			nStack;					// dung cho W-Velkoz, 1 so con co bay~ (BYTE) - gio la Ammo luon
	int 		nTemp_3[2];
	float		nCooldownExpires_3;		// dung cho W-Velkoz khi stack = 0
	int 		nTemp_3_1[3];
	int			nToggle;			//1: chua active,:2 dang active ==> dung cho skill buff,1 cung la loai skill buff
	float		nTotalCooldown;			//0x2C: time hoi spell
	int 		nTemp_4[4];
	float		nAdd_Dmg;				// dung cho Q-Nasus
	float		nAdd_Dmg2;				// dung cho R-Zed
	int 		nTemp_5[39];
	DWORD		*__pK_str1;				//0xD0
	DWORD		*__pK_str2;				//0xD4
};
//==================================================================================//
//==================================================================================//
struct KCastSpell{
	int			nTemp_1[2];
	DWORD		*__pK_str2;		//0x4: co the dung check dang cast skill nao(0-1-2-3-normal...)
	int			nTemp_2[23];
	int			nMy_ID_1;
	int			nMy_ID_2;
	int			nTemp_2_1[4];
	KPos		SourcePos;
	KPos		MaxDestPos;
	KPos		MousePos;
	int			nTemp_3[4];
	int			nEnemy_ID;
	int			nTemp_4[255];
	float		nDelay_AAAnimate;			// 0x3A4(v7.12)		//Delay AA va Delay cua skill channeling --> phai check khi update
	float		nDelay_AAAnimate_2;
	int			nTemp_5_1[2];
	float		nCoolDownAA;	// 0x414(v7.12) -> time de cast AA tiep theo
	int			nTemp_5_2[5];
	int			nSlot;
	int			nTemp_5[15];
	
	
	float		nTime_DanBatDauBay;			// 0x40C(v7.12) -> time nay sap xi bang nTimeNow luc ban' dan.
	float		nTime_CDExpiresAA;			// 0x410(v7.12) -> time dan ra khoi nong`
	
	int			nTemp_6[4];
	float		nTime_BatDauBAN;
	

};
////==================================================================================//
//struct KTurret{
//	int			nTemp_1[3];
//	int			nLane;			//0xC: 0:bottom,1:mid, khac 1: top
//};
//==================================================================================//
struct stMOVE{
	int  nTemp_1[4];
	KPos __strPosDest_OLD; //0x60
	int  nTemp_2[95];
	int  nIsMoving;   //lay BYTE: 1=moving
	//int  nTemp_3[5];
	int  nTemp_3[2];
	KPos  __strPosStart;  //0x2B0
	KPos  __strPosDest;  //0x2B0
	DWORD nWayPoint_Start;
	DWORD nWayPoint_End;
	DWORD nWayPoint_MaxEnd;
	BYTE  nTempDash_1;
	BYTE  nIsDash;				// == 0 la dang dash, hoi nguoi doi ti
	BYTE  nTempDash_3;
	BYTE  nTempDash_4;
	int  nTemp_3_0;
	float nDashSpeed;
	int  nTemp_3_1[5];
	int  nIsDashing;		//BYTE
	int  nTemp_3_2[49];
	//int  nDashGravity;	//lay BYTE ra so roi check choac
	BYTE  nTempDashGravity_1;
	BYTE  nDashGravity;				
	BYTE  nTempDashGravity_3;
	BYTE  nTempDashGravity_4;

	int  nTemp_4[56];
	int  nIsInFog; // 1: in fog, lay byte
	int  nInFog2; // gia tri thay doi lien tuc; neu trong bong toi thi ko thay doi
	
	int  nTemp_5[2];
	int nTeamID; //0x454(v7.7)
};
////==================================================================================//
//struct stNORMAL_ATTACK{
//	//int   nTemp_1[3];
//	int   nTemp_1[579];
//	float  nCooldownExpires;
//	DWORD  *__pK_str2x;
//};
////==================================================================================//
//struct KTimer{
//	int		 nTemp_1[11];
//	float	 nTime_Game;    //0x2C
//	int		 nTemp_2;
//	float	 nTime_PauseGame;  //0x34
//};
//==================================================================================//
struct KNpc{//v6.07		
	int 		nTemp_1;
	DWORD		nIs_Nexus;			// if(nIs_Nexus == offset_0x318C81C): phao dai			===>MA HOA ROI(SOLVED)
									// if(nIs_Nexus == offset_0x318C3B8): inhibitor
	int 		nTemp_1_1[6];

	int			nID;				// dac trung cho tung loai tuong : 0x07170716=Ryze...

	int 		nTemp_2[10];

/**/int 		nTeam_ID;			//0x64:quan minh(blue), 0xC8:Doi phuong(red or purple), 0:ko thuoc ben nao
									//0x12C:Neutral
/**/int			nType_1;	// =0x1401:Hero, 0x2401:Turret(thap ban), 0x20005: may cuc xxx, 0x00005: shop va trai linh(barracks)	===>MA HOA ROI(SOLVED)
									// =0xC01: linh, 0xC01:linh sumon (isMakerObj: off_1A cmp1)
									//IsHero:nType_1>>12 - IsTurret: nType_1>>13 - IsClone: nType_1>>10 - IsMinion: nType_1>>11
	int 		nTemp_2_1[6];
/**/char		szPlayerName[16];	//0x20	
/**/int			nLen_Name;
/**/int			nMaxlen_Name;
	DWORD		pNpcData;			//0x38 : v7.03
	int 		nTemp_4;
	int			nType_2;			//1: UNIT_AI, 2: UNIT ko danh dc
	int 		nTemp_5[3];
/**///KPos		CurrentPos;				//0x5C
	
	int 		nTemp_6[12];
/**/DWORD	    nIndex;				//0xFC	(4.294.967.295)
	int 		nTemp_6_2[8];
	KPos		BBoxMin;
	KPos		BBoxMax;
	int 		nTemp_6_2_1[4];
	int         nDeleted;
	int 		nTemp_6_1_1[37];
	int			nCanSee;			//0xDC: BYTE: 0:xa, 1:gan : nhin thay trong man hinh`		===>MA HOA ROI(NOT-YET-SOLVED)
	int 		nTemp_7[9];
	Vec3D		ServerPosition;	

	int 		nTemp_8[2];
	int 		nTemp_9[11];
	int			nTotal_Die;			//0x114: so lan chet																	===>MA HOA ROI(NOT-YET-SOLVED)
/**/int			nIsDie;				//0x118: BYTE: 0:song, 1:Die		"%s was killed by %s" - "%s was made Zombie by %s"	===>MA HOA ROI(SOLVED-TAM-THOI)
	KPos		CurrentPos;

	int 		nTemp_9_11;
	//int 		nTemp_9_112;
	
	DWORD		nMissileData;
	int 		nTemp_9_12[23];
	DWORD		nMissileOwnerID_1;
	DWORD		nMissileOwnerID_2;
	

	int			nTemp_10__1[4];				//----
	KPos		MissileSrcPos;				//----(co' dung` trong Sivir)
	KPos		MissileDestPos;				//----(co' dung` trong Sivir)
	KPos		MissileCursorPos;			//----(co' dung` trong Sivir)
	int			nTemp_10[4];				//----
	DWORD		nMissileTargetID;			//----
	int			nTemp_10_1[102];				//----


	//int			nTemp_10[103];
	float		nSpawnTime;			//===>MA HOA ROI(NOT-YET-SOLVED) ==> ko dung` nua~
/**/float		nMP;				//0x184
	int 		nTemp_11[3];
/**/float		nMaxMP;				//0x194
	int 		nTemp_11_1[19];
	float		nJhinMissile;		// Dan Jhin, choang Annie
	int 		nTemp_12[45];
	int			nIsInvulnerable;	//BYTE	: nIsInvulnerable & 1 = 1-ko the tan cong
	int 		nTemp_12_1[57];

/**/float		nOverrideCollisionRadius;//0x3A8	:Ban kinh va cham(kha quan trong)	===>CO VE SAI SAI, LAY TAM VAY
	float		nOverrideCollisionHeight;//0x3AC
	int 		nTemp_13[542];
/**/int			nIsTargetable;		//0x160:(BYTE) co the select dc ko hay(danh dc hay ko)->0:ko, 1: co :lay cai nay cx hon 1F8
	int 		nTemp_14[3];		
/**/int			nIsTargetableToTeam;//0x170: =3: chua hien cot mau,chua the tan cong - =4:hinh nhu la danh dc???
	
	int 		nTemp_15[24];
	int			nIsBasing;			// =6 la dang B ve tru da
	int 		nTemp_15_1[7];
/**/float		nHP;				//0x244
	int 		nTemp_16[3];
/**/float		nMaxHP;				//0x254
	int 		nTemp_17[11];
/**/float		nGiap_Mau;
	int 		nTemp_18[3];
/**/float		nGiap_Mau_KoBiet;
	int 		nTemp_19[3];
/**/float		nGiap_Mau_AP;
	int 		nTemp_18_1[3];
/**/float		nGiap_Mau_Rengar;

	int 		nTemp_20[35];//int 		nTemp_20[367];
/**///char		szName_Hero[16];	//0x8D0: lay tu szName_Hero[2] tro di(code goi la SkinName)
	//int			nLen_Name_Hero;		
	//int			nMax_Len_Name_Hero; //0x8E4

	//int 		nTemp_21_0[3];
	int			nModSkinID;			//===>MA HOA ROI, CO THE SAI DAY (NOT-YET-SOLVED)

	int 		nTemp_21[13];		//0x8C0
	int 		nPlayerControlled;	//BYTE: 0x92C: 0:may', 1:nguoi choi
	int 		nTemp_22[165];
	float		nXyenPhep_Diem;
	int 		nTemp_23[6];
	float		nXyenGiap_Diem;
	int 		nTemp_24[14];
/**/float		nFlat_PhysicalDamageMod;	//0xA8C: nFlat_PhysicalDamageMod + nPercent_PhysicalDamageMod = dam_Physical
	float		nPercent_PhysicalDamageMod;	//0xA90:
	int 		nTemp_24_1[2];
/**/float		nFlat_MagicDamageMod;		//0xA94: dmg magic flat: suc manh phep thuat(anh huong den skill)
	float		nPercent_MagicDamageMod;	//0xA98:
	int 		nTemp_25[25];
/**/float		nAttackSpeedMod;			//0xAF4
/**/float		nBaseAttackDamage;			//0xAF8 ..**.. dam thuong` ==>DAM = nFlat_PhysicalDamageMod + nBaseAttackDamage 
	float		nFlat_BaseAttackDamage;		//0xAFC
	float		nPercent_BaseAttackDamage;	//0xB00
	int 		nTemp_26[6];
/**/float		nCritChance;				// 100*ty le chi mang
/**/float		nArmor;						//0xB20	: Tong Giap
/**/float		nArmor_CongThem;			//0xB20	: Giap Cong Them
/**/float		nSpellBlock;				//0xB28	: Tong Khang phep
/**/float		nSpellBlock_CongThem;		//0xB28	: Khang Phep Cong Them
	int 		nTemp_27[2];
/**/float		nMoveSpeed;					//0xB44
	int 		nTemp_27_1;
/**/float		nAttackRange;				//0xB48
	float		nCastRange;					//0xB4C

	int 		nTemp_28[362];
	float		nHoiMauMoiGiay;

	int 		nTemp_28_11[40];
	int			nIsBot;				//0x1188: 0:ko phai bot - 1:bot
/**/int			nPet_ID_1;			//0x118C:chua co pet kiem chung
/**/int			nPet_ID_2;			//0x1190
/**/int			nPet_ID_3;			//0x1194
/**/int			nAI_LastPetSpawnedID;//0x1198:chua co pet kiem chung
	int 		nTemp_29[44];

	//int			nBar_Source;		// 1528h(7.6)
	int 		nTemp_29_1[73];
/**/float		nGold;				//0x11AC
	int 		nTemp_31_3[29];
	Vec3D		facingPos;			// y luon = 0;
	int 		nTemp_31[300];
	
	int			nCombatType;		//1: Melee, 2: Ranger
	
	int 		nTemp_31_11[71];

	int			pBuffs;					
	int			pMax_Buffs;	
	
	int			nTemp_40[152];
					//0x2c04
	//int			nTemp_41[295]; 
	
	
	////int 		nTemp_21_00[45];
	//char		szName_Hero[16];	//0x8D0: lay tu szName_Hero[2] tro di(code goi la SkinName)
	//int			nLen_Name_Hero;		
	//int			nMax_Len_Name_Hero; //0x8E4
	////int 		nTemp_21_001[3];

	DWORD		_pMOVE;				//===>MA HOA ROI(SOLVED)

	int 		nTemp_31_1[241];

	int			nActiveSpellSlot;	//0x2458 : 0-1-2-3 khi ng choi an phim
	int 		nTemp_32[91];
	int 		_pCastSpellBook;
	int 		nTemp_32_1[7];
/**/DWORD 		*_pCastSpell;		//0x2470 : lien quan den toa do cast spell, dich den...xyz
	int 		nTemp_33[269];

/**/int			nIsCastingSpell;	//0x2878: BYTE: 0: ko cast, 1: dang cast
	int 		nTemp_30[43];
/**/DWORD		_pSkill[63];			//0x23A8 + 0x518 = 0x2968   --> 2A64

	int 		nTemp_35[292];			//

//-------tam thoi dang tim den doan nay-------
	//DWORD		*_pTurret;			//0x2B0C
	//int 		nTemp_37[184];
	//int			nCombatType;		//0x2DF0 : 2:summonrif
	//int 		nTemp_38[2];
	//int			nPetReturnRadius;	//0x2DFC: =200.00	
	//int			nTemp_39[84];

	//int 		nTemp_21_00[45];
	char		szName_Hero[16];	//0x8D0: lay tu szName_Hero[2] tro di(code goi la SkinName)
	int			nLen_Name_Hero;		
	int			nMax_Len_Name_Hero; //0x8E4
	int 		nTemp_21_0011[3];

	int			nEnemy_ID;			//0x33e8 : khi danh normal_atk doi phuong (o duoi chut co toa do x,z)
	//int 		nTemp_43[7];	
	//float		nDeathDuration;		//0x3304:time de hoi` sinh
	//int 		nTemp_44[136];	
	//int			nRoamState;			//0x3528:linh dao choi??-or- thu tu turret: 1:first, !2:third, con lai:second, 4,5: turret nexus
	//int			nOriginalState;		//0x352C:
	//int			nCampNumber;		//0x3530:

	//int 		nTemp_45[11];	
	//int			nExp;				//0x3560
	//int			nTemp_46[3];	
	//int			nLevel;				//0x3570

	//int 		nTemp_47[8];		
	//int			nPointSkill;		//0x3594: so diem co the cong vao lvl
	int 		nTemp_48[23];		
	int			nBLOCK_MOVE;			//0x34c4 : gia tri = 0 la ko khoa (co the di chuyen duoc) gia tri = 1 la dang bi khoa (ko the di chuyen = chuot duoc)
	int 		nTemp_49[128];	
	
	int			nTemp_50[8];
	int			nIsMinion;			//0x35AC: Minion(linh) = 2
	//int 		nTemp_51;
	int			nMinion_Level;		//0x35B4: 	
	//int 		nTemp_52[217];
	int 		nTemp_52[852];
	int			nBar_Source;//3b2c(7.15)	//===>MA HOA ROI(SOLVED)->TAM THOI CHUA DUNG
	int 		nTemp_53[49];
	
	float		nCooldownExpiresBA;			//===>MA HOA ROI(SOLVED): ko lay offset nay nua
	DWORD		_pNormalAttack;  //0x2ee4	//cu~

	int 		nTemp_53_1[26];
	BYTE		nIsMove_temp1;
	BYTE		nIsMove;					//===>MA HOA ROI(SOLVED)
	BYTE		nIsMove_temp3;
	BYTE		nIsMove_temp4;

	int 		nTemp_53_2[404];

	DWORD		nIS_MOVE_1;
	DWORD		nIS_MOVE_2;

	int 		nTemp_53_2_1[33];

	int			nLevel;					// 3c5c(7.15)
	int 		nTemp_54[9];
	int			nRemainingPoint;
	
	int 		nTemp_55[8];
/**/DWORD		_pItem[39];			//gio no gop item voi skill la 1, vcc, pItem[0] = _pSkill[6]

	bool		IsEnemy(int nTeamID) // ke thu
	{
		if (nTeam_ID == nTeamID || nTeam_ID == 0 || nTeam_ID == 0x12C)
			return false;
		return true;
	}
	bool		IsAlly(int nTeamID) // dong minh
	{
		if (nTeam_ID != nTeamID || nTeam_ID == 0 || nTeam_ID == 0x12C)
			return false;
		return true;
	}
	bool		IsMinion() // linh
	{
		if ((nType_1 >> 11) == 1 && nTeam_ID != 0x12C)
			return true;
		return false;
	}
	bool		IsTurret() // tru
	{
		if ((nType_1 >> 13) & 1)
			return true;
		return false;
	}
	bool		IsChampion() // tuong
	{
		if ((nType_1 >> 12) & 1)
			return true;
		return false;
	}
	bool		IsNexus() // Nexus
	{
		if ((nIs_Nexus == NEXUS - TEMP_ENTRY_POINT + G_Module) /*&& nIsTargetableToTeam == 4*/)
			return true;
		return false;
	}
	bool		IsInhibitor() // Inhibitor
	{
		if ((nIs_Nexus == INHIBITOR - TEMP_ENTRY_POINT + G_Module) /*&& nIsTargetableToTeam == 4*/)
			return true;
		return false;
	}
	bool isJungle()
	{
		return (nTeam_ID == 0x12C) ? true : false;
	}

	float       percentHP(){return 100*nHP/nMaxHP > 100 ? 100 : 100*nHP/nMaxHP;}
	float       percentMP(){return 100*nMP/nMaxMP > 100 ? 100 : 100*nMP/nMaxMP;}

	bool		isDead(){return nHP <= 0 ? true : false;}
	bool		isTargetable(){return (BYTE)nIsTargetable == 1;}
	bool		isMelee(){return (BYTE)nCombatType == 1;}
	bool		isRanged(){return (BYTE)nCombatType == 2;}
	bool		isRecall(){return (BYTE)nIsBasing == 6;}
	
	Vec3D       currentPos()
	{
		Vec3D temp(CurrentPos.x, CurrentPos.y, CurrentPos.z);
		return temp;
	}
	Vec3D       startPos()
	{
		Vec3D rs;
		if(_pMOVE)
		{
			DWORD tempMov  = *(DWORD*)(_pMOVE + 4);
			stMOVE *strMove = (stMOVE*)tempMov;
			if(strMove){ rs.x = strMove->__strPosStart.x, rs.y = strMove->__strPosStart.y, rs.z = strMove->__strPosStart.z; }
		}
		return rs;
	}
	Vec3D       endPos()
	{
		Vec3D rs;
		if(_pMOVE)
		{
			DWORD tempMov  = *(DWORD*)(_pMOVE + 4);
			stMOVE *strMove = (stMOVE*)tempMov;
			if(strMove){ rs.x = strMove->__strPosDest.x, rs.y = strMove->__strPosDest.y, rs.z = strMove->__strPosDest.z; }
		}
		return rs;
	}
	char*		GetNameNpc() // lay ten nhan vat
	{
		char * szName = szPlayerName;
		if((BYTE)nLen_Name > 15)
		{
			DWORD dw = *(DWORD*)&szPlayerName;
			szName = (char *)dw;
		}
		return szName;
	}
	char*		GetNameHero() // lay ten tuong
	{
		char * szName = szName_Hero;
		if((BYTE)nLen_Name_Hero > 15)
		{
			DWORD dw = *(DWORD*)&szName_Hero;
			szName = (char *)dw;
		}
		return szName;
	}
	stMOVE CauTrucMOVE;
};
//==================================================================================//
struct KBuffs{
	int			nTemp_1;

	int			nIndex;			//1-2-3-4... if(nIndex == -1) continue;
	
	DWORD		__pBuffs_1;		//0x4: chua name, dung de nhan dang loaij buff phai chiu
	float		nBegin_Time;	// thoi gian bi buff	
	float		nEnd_Time;		// thoi gian het buff (expire) : so sanh nEnd_Time voi Time_now de biet dc buff con ton tai hay ko
	int			nTemp_2[3];
	int			nStart_Count;	// nCount = (nEnd_Count - nStart_Count)/8;
	int			nEnd_Count;
	int			nMaxEnd_Count;
	DWORD		__pOwenerData;	// cau truc OwnerData-Buff
	int			nTemp_3[17];
	int			nCount;
	int			nTemp_4[2];
	int			nStart_NhanDang;// if(nStart_NhanDang == nEnd_NhanDang) ===> ko co hieu ung buff do'
	int			nEnd_NhanDang;
	int			nMaxEnd_NhanDang;//if(nEnd_NhanDang == nMaxEnd_NhanDang) ===> dang co hieu ung buff 
};
//==================================================================================//
struct KBuffs_1{
	int			nTemp_1[2];		
	char		szName[32];		//0x8: dua vao name de biet cac loai buff bat' loi nhu : choang,cham,giat,tung ...
};

//==================================================================================//
struct KBuff_OwnerData{// tren pBuffs - pMax_Buffs 1 ti(thuoc cau truc NPC)
	int			nTemp1;			
	DWORD		pOwnerNpc;		
	int			nOwnerId;
	int			nOwnerNetworkId;
};

//==================================================================================//
struct KEnemyDistance
{
	KNpc *pEnemy;
	float fDistance;
	float nCount2BeKill;
	int   nThuTuUuTien;
	float nHP;
	float nMaxHP;
	float nDamage;
	float nDamageAP;
	float fCalcDamage;
	float fCalcAPDmg;
	float fCalcADDmg;
	float nTimeGiaoKalista;
	int	  nCan_See;		//khac voi nCanSee trong KNpc
	float nTick_Start;
	float nTick_End;
	float fDistance_toTru;
	DWORD nIndex;		// networkID
};

struct KEnemyInfo
{
	KNpc *DeadHeroes;
	KNpc *pEnemy;
	DWORD nIndex;
	int   nCan_See;		//khac voi nCanSee trong KNpc
	float nTick_Start;
	float nTick_End;
	KPos  LastSeenPosition;
	Vec3D LastEndPos;
	float LastSeen;
	DWORD IndexDead;
	float TimeDead;
	float TimeLife;
	float MoveSpeed;
	float LastSeenRange;
};

//==================================================================================//
struct KHackZoom
{
	int    nTemp_1[149];
	float  nHackZoom;	// 0x21C : default=1.28 (CameraZoomToMinMaxEnable)
};
struct EndGame
{
	int    nTemp_1[2];
	int nGiaTri;
};

//==================================================================================//
struct KRenderer
{
	int				nTemp_1[3];
	DWORD			pDeviceHandler;
	int				nTemp_1_1[2];
	int				nWidth;						//0x20
	int				nHeight;					//0x24
	int				nTemp_2[25];
	D3DXMATRIX		nViewMatrix;				//0x80
	D3DXMATRIX		nProjectionMatrix ;			//0xBC
};

//==================================================================================//
struct KWorldData
{
	int		nTemp1[25];
	float	fOffsetX;					//0x64	(**)		(9.20.1)
	float	fOffsetY;					//		(**)
	float	fOffsetZ;					//		(**)
	float	fMaxX;						// 
	float	fMaxY;						// 
	float	fMaxZ;						// 

	int		nTemp2;
	DWORD	pCellInfo;					//0xxx	(**)
	DWORD	pHeightMapInfo;				//0x34	

	int		nHeightMapCellCountX;		//0x38 
	int		nHeightMapCellCountZ;		//0x3C

	float	fHeightMapCellSizeX;		//0x40
	float	fHeightMapCellSizeZ;		//0x44

	int		nTemp3[323];
	int		nCellCountX;				//0x59C	 (**)		(9.20.1), //(8.23: BASE_MAPDATA_2 = 0x32BA750	//--[00B08BEE]	===> sub__B0C350)
	int		nCellCountZ;				//		 (**)
	int		nTemp4;
	float	fCellScale;					//0x5A8	 (**)		(9.20.1)
};

////==================================================================================//
//struct KGameEvent
//{
//	DWORD	pName_evtPlayerMoveClick_MouseTriggered;
//	int		nTemp_1[3];
//	int		nLen_EventName;
//	int		nMaxLen_EventName;
//	int		nTemp_2[8];
//	int		nThamSoBang1;
//	int		nPosXScreen;
//	int		nPosYScreen;
//	int		nThamSo_Click; //0=RClick-down, 1=RClick-up, 2=RClick-hold
//	int		nTemp_3[3];
//	DWORD	pName_evtPlayerReleaseMoveClick;
//};

//==================================================================================//
struct KSelectTarget
{
	int		nTemp_1[6];
	DWORD   nIDTargetSelected;
	BYTE    nTempByte1;
	BYTE    nTempByte2;
	BYTE    nSelectOrNot;
	BYTE    nTempByte4;
};

//==================================================================================//
struct D3DTLVERTEX
{
	float fX;
	float fY;
	float fZ;
	float fRHW;
	D3DCOLOR   Color;
	float fU;
	float fV;
};

//==================================================================================//
struct KTextureName
{
	DWORD*		pName;
	int			nTemp1[3];
	int			nLen_Name;
	int			nMaxLen_Name;
};

////==================================================================================//
//struct ByPass_Send
//{
//	DWORD			nTemp1;
//};

////==================================================================================//
//struct Hack_Velkoz_R
//{
//	DWORD			nTemp1;
//	DWORD			nTemp2;
//};

//==================================================================================//
struct KOptionMenuCustomLua
{
	int		nSttLine;
	bool	nOptDefault;
	bool	nOptionReturn;
	char	szTextLine[40];
	int		nSttXX;
};

//==================================================================================//
struct KMissileData
{
	int			nTemp1[6];
	char		szMissileName[16];
	int			nLen_MissileName;		
	int			nMax_Len_MissileName;
	int			nTemp2;
	DWORD		nOwnerData;
	DWORD		nMissile_Struct_3; 

	char*		GetMissileOwner_Name() // lay ten skill chua dan.
	{
		char * szName = szMissileName;
		if((BYTE)nLen_MissileName > 15)
		{
			DWORD dw = *(DWORD*)&szMissileName;
			szName = (char *)dw;
		}
		return szName;
	}
};

//==================================================================================//
struct KMissile_OwnerData  //du lieu nay = 1 du lieu o myHero(duoi ten 1 ti) 
{
	int			nTemp1[8];
	char		szMissileOwnerCharName[16];
	int			nLen_MissileOwnerCharName;		
	int			nMax_Len_MissileOwnerCharName;
	 

	char*		GetMissileOwner_CharName() // lay ten skill chua dan.
	{
		char * szName = szMissileOwnerCharName;
		if((BYTE)nLen_MissileOwnerCharName > 15)
		{
			DWORD dw = *(DWORD*)&szMissileOwnerCharName;
			szName = (char *)dw;
		}
		return szName;
	}
};

//==================================================================================//
struct KMissile_Struct_3  //du lieu nay giong KSkill_3, chua thong tin phep 
{
	int			nTemp_1[227];
	float		nRange;
	int			nTemp_1_1[6];
	float		nRange_2;
	int			nTemp_1_2[6];
	float		nRadius;

	int			nTemp_2[20];
	float		nMissileSpeed;
	int			nTemp_3;
	float		nMissileMinSpeed;
	float		nMissileMaxSpeed;
	int			nTemp_4[9];
	float		nMissileWidth;
};


//==================================================================================//
//struct KLoadScripts
//{
//	char szPathFile[120]; // MAX 999 SCRIPTS
//	char szNameFile[40];
//	bool bActive;
//	bool bIsRunning;
//	lua_State* LState;
//};

//==================================================================================//
struct KTexture_Test
{
	//int			nTemp_1[6];
	int			nTemp_1[12];
	char		sz_Name[16];
	int			nLen_Name;
	int			nMaxLen_Name;
	char*		GetTexture_Test_Name() // lay ten skill chua dan.
	{
		char * szName = sz_Name;
		if((BYTE)nLen_Name > 15)
		{
			DWORD dw = *(DWORD*)&sz_Name;
			szName = (char *)dw;
		}
		return szName;
	}
};

//-----------------------------------------------------------------------------------------------
struct _Object
{
	float t1;
	Vec3D vect;
};

//-----------------------------------------------------------------------------------------------
struct KPathOutWayPoint
{
	int			nTemp1;			//Bang 0
	DWORD		nTemp2;			//Bang BASE_MAPDATA
	Vec3D		vStartPos;
	Vec3D		vEndPos;
	DWORD		pWayPointStart;
	DWORD		pWayPointEnd;
	DWORD		pWayPointMaxEnd;
	int			nTemp3[250];
};

////-----------------------------------------------------------------------------------------------
//struct KDashing
//{
//	KNpc*		unit;				
//	Vec3D		vEndPos;
//	int			dashGravity;
//	bool		isDashGravity;
//};


