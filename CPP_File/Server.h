#pragma once
#include "stdafx.h"
#include "Utils.h"
#include <ctime>
#include <winioctl.h>
#include <winhttp.h>
#pragma comment (lib,"Winhttp.lib")
#include <atlbase.h>
#include <atlstr.h>
#include <comutil.h>
#include <wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")
#include <Iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#include <fstream>
#include <sstream>
#include <vector>
#include <Wincrypt.h>



using namespace std;
extern bool g_bCheckConnectDLL;

#define TEMP_FILE_NAME "~DF93F76506ABFD2A67V4IP.TMP"

std::string str_Encrypt(const std::string& str_in);	// NEW
std::string str_Decrypt(const std::string& str_in);	// NEW

void Crypt(TCHAR *inp, DWORD inplen, TCHAR* key, DWORD keylen);
void Crypt_2(char *inp, DWORD inplen, char* key, DWORD keylen);
void get_path(char* path_out);
//
// IDENTIFY data (from ATAPI driver source)
//
typedef struct _IDENTIFY_DATA {
	USHORT GeneralConfiguration;            // 00 00
	USHORT NumberOfCylinders;               // 02  1
	USHORT Reserved1;                       // 04  2
	USHORT NumberOfHeads;                   // 06  3
	USHORT UnformattedBytesPerTrack;        // 08  4
	USHORT UnformattedBytesPerSector;       // 0A  5
	USHORT SectorsPerTrack;                 // 0C  6
	USHORT VendorUnique1[3];                // 0E  7-9
	USHORT SerialNumber[10];                // 14  10-19
	USHORT BufferType;                      // 28  20
	USHORT BufferSectorSize;                // 2A  21
	USHORT NumberOfEccBytes;                // 2C  22
	USHORT FirmwareRevision[4];             // 2E  23-26
	USHORT ModelNumber[20];                 // 36  27-46
	UCHAR  MaximumBlockTransfer;            // 5E  47
	UCHAR  VendorUnique2;                   // 5F
	USHORT DoubleWordIo;                    // 60  48
	USHORT Capabilities;                    // 62  49
	USHORT Reserved2;                       // 64  50
	UCHAR  VendorUnique3;                   // 66  51
	UCHAR  PioCycleTimingMode;              // 67
	UCHAR  VendorUnique4;                   // 68  52
	UCHAR  DmaCycleTimingMode;              // 69
	USHORT TranslationFieldsValid:1;        // 6A  53
	USHORT Reserved3:15;
	USHORT NumberOfCurrentCylinders;        // 6C  54
	USHORT NumberOfCurrentHeads;            // 6E  55
	USHORT CurrentSectorsPerTrack;          // 70  56
	ULONG  CurrentSectorCapacity;           // 72  57-58
	USHORT CurrentMultiSectorSetting;       //     59
	ULONG  UserAddressableSectors;          //     60-61
	USHORT SingleWordDMASupport : 8;        //     62
	USHORT SingleWordDMAActive : 8;
	USHORT MultiWordDMASupport : 8;         //     63
	USHORT MultiWordDMAActive : 8;
	USHORT AdvancedPIOModes : 8;            //     64
	USHORT Reserved4 : 8;
	USHORT MinimumMWXferCycleTime;          //     65
	USHORT RecommendedMWXferCycleTime;      //     66
	USHORT MinimumPIOCycleTime;             //     67
	USHORT MinimumPIOCycleTimeIORDY;        //     68
	USHORT Reserved5[2];                    //     69-70
	USHORT ReleaseTimeOverlapped;           //     71
	USHORT ReleaseTimeServiceCommand;       //     72
	USHORT MajorRevision;                   //     73
	USHORT MinorRevision;                   //     74
	USHORT Reserved6[50];                   //     75-126
	USHORT SpecialFunctionsEnabled;         //     127
	USHORT Reserved7[128];                  //     128-255
} IDENTIFY_DATA, *PIDENTIFY_DATA;

typedef struct _IDEInfo 
{
	char model [128];
	char serialNumber [256];
	char firmware [128];
} IDE_INFO, *pIDE_INFO;

bool IsWin7OrLater();
BOOL DnsFlushResolverCache();

char* GetCurrentVersion();
char* GetCurrentVersion4WinXP();

void  check_ourIP();

char* GetRequestResult(const char*, const char*);
char* GetRequestResult4WinXP(const char*, const char*);

char* GetTimeServer();
char* GetTimeServer4WinXP();

DWORD WINAPI ChooseLine(void*);

bool TestConnect();
bool TestConnect4WinXP();

DWORD WINAPI CheckLogin(void *);

DWORD WINAPI ReadConfig(void *);
DWORD WINAPI WriteConfig(void *);
void GetPhysicalDriveSerialNumber(UINT nDriveNumber IN, CString& strSerialNumber OUT);
char* GetHardDiskSN(unsigned int diskIndex);
IDE_INFO ReadPhysicalDriveInNTUsingSmart (void);
char *ConvertToString (DWORD diskdata [256], int firstIndex, int lastIndex, char* buf);
char* GetMACAddress();
BOOL IsWow64();
void GetOS(char theos[256]);
char* GetIPHost();
//=====================================================
//======== Encrypt - Decrypt using Wincrypt.h =========
//=====================================================
class CCrypt
{
public:
	CCrypt(void);
	virtual ~CCrypt(void) {
		if ( m_hKey )  CryptDestroyKey( m_hKey ); 
		if ( m_hHash ) CryptDestroyHash( m_hHash ); 
		if ( m_hProv ) CryptReleaseContext( m_hProv, 0); 
	}
	BOOL SetKey( LPCSTR szKey= 0, LPCSTR pszSalt= 0 );

	BOOL EncryptDecrypt( BYTE* pData, DWORD* dwDataLen, LPCSTR pKey, BOOL fEncrypt );

	CString EncryptStrToHex(   LPCSTR szText, LPCSTR pKey= 0, LPCSTR pszSalt= 0 );
	CString DecryptStrFromHex( LPCSTR szHex,  LPCSTR pKey= 0, LPCSTR pszSalt= 0 );

	CString EncodeToHex(   BYTE* p, int nLen );
	int     DecodeFromHex( LPCSTR pSrc, BYTE* pDest, int nBufLen );

private:
	HCRYPTPROV  m_hProv;
	HCRYPTHASH  m_hHash;
	HCRYPTKEY   m_hKey;

	BOOL        m_fOK;
	DWORD       m_nLastErr;
	//CString     m_sErrMsg;
	char*       m_pszDefaultKeyRaw;
};
//=====================================================
//======== Encrypt - Decrypt using Wincrypt.h ===END===
//=====================================================

//=====================================================
//========== File Manager - User Information ==========
//=====================================================
class CUserInfo
{
	char m_szUser[64];
	char m_szPass[64];
	char m_szSessionID[125];
	bool m_isLogin;
	bool m_isSavePass;
	bool m_isEncrypt;

public:
	CUserInfo()
	{
		//int x = sizeof(m_szSessionID);
		memset(m_szUser, NULL, 64*sizeof(char));
		memset(m_szPass, NULL, sizeof(m_szPass));
		memset(m_szSessionID, NULL, sizeof(m_szSessionID));
		m_isLogin = false;
		m_isSavePass = false;
		m_isEncrypt = false;
	}
	const char* GetUser() const { return m_szUser; }
	void SetUser(const char *val) { strcpy_s(m_szUser, val); }
	const char* GetPass() const { return m_szPass; }
	void SetPass(const char *val) { strcpy_s(m_szPass, val); }
	const char* GetSessionID() const { return m_szSessionID; }
	void SetSessionID(const char *val) { strcpy_s(m_szSessionID, val); }
	bool GetLogin() const { return m_isLogin; }
	void SetLogin(bool val) { m_isLogin = val; }
	bool GetSavePass() const { return m_isSavePass; }
	void SetSavePass(bool val) { m_isSavePass = val; }
	bool GetEncrypt() const { return m_isEncrypt; }
	void SetEncrypt(bool val) { m_isEncrypt = val; }

	void Encrypt()
	{
		if (GetEncrypt() == false)
		{
			//for (int i1 = 0; m_szUser[i1]; ++i1)
			//{
			//	m_szUser[i1] = m_szUser[i1] + 121; // key ma hoa username
			//}
			//for (int i2 = 0; m_szPass[i2]; ++i2)
			//{
			//	m_szPass[i2] = m_szPass[i2] + 129; // key ma hoa password
			//}
			//for (int i3 = 0; m_szSessionID[i3]; ++i3)
			//{
			//	m_szSessionID[i3] = m_szSessionID[i3] + 125; // key ma hoa session ID
			//}

//----MaHoa Kieu Cu -----------------------------------------------------------------------------------------
			//CCrypt crypt;
			//CString sEncryptedUsername= crypt.EncryptStrToHex( m_szUser );			// use default rawKey
			//CString sEncryptedPassword= crypt.EncryptStrToHex( m_szPass );			// use default rawKey
			//CString sEncryptedSessionID= crypt.EncryptStrToHex( m_szSessionID );	// use default rawKey
			//strcpy(m_szUser, sEncryptedUsername.GetString());
			//strcpy(m_szPass, sEncryptedPassword.GetString());
			//strcpy(m_szSessionID, sEncryptedSessionID.GetString());

//----MaHoa Kieu Moi -----------------------------------------------------------------------------------------
			//char sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };//key dung cho ham Crypt()
			char sz__fdC_Y_yum3ww09_1[] = { 103, 102, 66, 40, 85, 34, 120, 114, 119, 41, 110, 119, 46, 57, 0 };//key dung cho ham Crypt_2()
			char* Key = sz__fdC_Y_yum3ww09_1;

			char* Data_User = m_szUser;
			Crypt_2(Data_User, strlen(Data_User), Key, strlen(Key));
			strcpy_s(m_szUser, Data_User);

			char* Data_Pass = m_szPass;
			Crypt_2(Data_Pass, strlen(Data_Pass), Key, strlen(Key));
			strcpy_s(m_szPass, Data_Pass);

			char* Data_SessionID = m_szSessionID;
			Crypt_2(Data_SessionID, strlen(Data_SessionID), Key, strlen(Key));
			strcpy_s(m_szSessionID, Data_SessionID);

			SetEncrypt(true);
		}
	}
	void Decrypt()
	{
		if (GetEncrypt() == true)
		{
			//for (int i1 = 0; m_szUser[i1]; ++i1)
			//{
			//	m_szUser[i1] = m_szUser[i1] - 121; // key ma hoa username
			//}
			//for (int i2 = 0; m_szPass[i2]; ++i2)
			//{
			//	m_szPass[i2] = m_szPass[i2] - 129; // key ma hoa password
			//}
			//for (int i3 = 0; m_szSessionID[i3]; ++i3)
			//{
			//	m_szSessionID[i3] = m_szSessionID[i3] - 125; // key ma hoa session ID
			//}

//----MaHoa Kieu Cu -----------------------------------------------------------------------------------------
			//CCrypt crypt;
			//CString sDecryptedUsername= crypt.DecryptStrFromHex( m_szUser );		// use default rawKey
			//CString sDecryptedPassword= crypt.DecryptStrFromHex( m_szPass );		// use default rawKey
			//CString sDecryptedSessionID= crypt.DecryptStrFromHex( m_szSessionID );	// use default rawKey
			//strcpy(m_szUser, sDecryptedUsername.GetString());
			//strcpy(m_szPass, sDecryptedPassword.GetString());
			//strcpy(m_szSessionID, sDecryptedSessionID.GetString());

//----MaHoa Kieu Moi -----------------------------------------------------------------------------------------
			//char sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };//key dung cho ham Crypt()
			char sz__fdC_Y_yum3ww09_1[] = { 103, 102, 66, 40, 85, 34, 120, 114, 119, 41, 110, 119, 46, 57, 0 };//key dung cho ham Crypt_2()
			char* Key = sz__fdC_Y_yum3ww09_1;

			char* Data_User = m_szUser;
			Crypt_2(Data_User, strlen(Data_User), Key, strlen(Key));
			strcpy_s(m_szUser, Data_User);

			char* Data_Pass = m_szPass;
			Crypt_2(Data_Pass, strlen(Data_Pass), Key, strlen(Key));
			strcpy_s(m_szPass, Data_Pass);

			char* Data_SessionID = m_szSessionID;
			Crypt_2(Data_SessionID, strlen(Data_SessionID), Key, strlen(Key));
			strcpy_s(m_szSessionID, Data_SessionID);

			SetEncrypt(false);
		}
	}
};

class CFileUserInfoMgr
{
	
public:
	CUserInfo m_ListUser[20];
	static CFileUserInfoMgr *s_Instance;

	static CFileUserInfoMgr* GetInstance()
	{
		if (!s_Instance)
		{
			s_Instance = new CFileUserInfoMgr;
		}
		return s_Instance;
	}
	CFileUserInfoMgr(){ memset(m_ListUser, NULL, 20*sizeof(CUserInfo)); }
	CUserInfo* GetListUser() const { return (CUserInfo*)&m_ListUser; }
	void SetListUser(CUserInfo *listUser, int nCount) { memcpy(m_ListUser, listUser, sizeof(CUserInfo)*nCount); }
	void AddUser(CUserInfo &aUser);
	CUserInfo GetUserLogin();
	void SaveInfo2File(char* filename);
	void ReadInfoFromFile(char* filename);
	//void ShowListUser();
};
//=====================================================
//========== File Manager - User Information ===END====
//=====================================================

//============ Process Result From Server =============
enum SERVER_RETURN
{
	SR_SESSION_ID			= 0,
	SR_TIME_SERVER			= 1,
	SR_ERROR_CODE			= 2,
};
enum ERROR_CODE
{
	EC_SUCCESSFUL			= 0,
	EC_INVALID_USERNAME		= 1,
	EC_WRONG_PASSWORD		= 2,
	EC_LOGIN_OTHER_PLACE	= 3,
	EC_EXPIRED_ACCOUNT		= 4,
	EC_IP_HOST_FROM_VN      = 5,
};
vector<string> split(const string &source, char delimit);
char* GetValueFromVectorString(vector<string> vSource, int indexValue);
//============ Process Result From Server =====END=====
