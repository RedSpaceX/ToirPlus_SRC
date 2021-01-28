#pragma once
#include "Utils.h"
#include "D3dx9math.h"
#include "detours.h"






void	LoadGameTexture();
HRESULT WINAPI Hook_EndScene(LPDIRECT3DDEVICE9 pDevice);

KRenderer* GetRenderer();
LPDIRECT3DDEVICE9 Get_Device();
//void World2Screen(D3DXVECTOR4* pPosOutIn);
//void World2Screen_ViewPort(D3DXVECTOR3* pPosIn, D3DXVECTOR3* pPosOut);
void WorldPos_to_ScreenPos(KPos* pWorldPos, KPos* pScreenPos);

D3DTLVERTEX CreateD3DTLVERTEX(float X, float Y, float Z, float RHW, D3DCOLOR nColor, float U, float V);

void	Detour_EndScene();
void	Retour_EndScene();

bool	bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask);
DWORD	FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask);

DWORD	GetTexture_Game(char* szTextureName, DWORD nSource = 0);
void	GameDrawCircle(KPos* pPos, float nRadius, int pTexture, DWORD nColor = 0xffffffff);
void	GameDrawCircle_Red(KPos* pPos, float nRadius, int pTexture);
void	GameDrawCircle_MiniMap(KPos* pPos, float nRadius, int pTexture);// co ve chi dung dc voi MinimapCircularRangeIndicator.dds

void	GameDrawCircle_2ChuaCanDung(KPos* pPos, float nRadius);

void	GameDrawLineMissile(KPos* pSourcePos, KPos* pDestPos, float nRadius, int pTexture);

KPos	GetWorldPosBar(KNpc* pNpc);
int		GetBarDetail(KNpc* pNpc);
void	GameDraw2D( float nPosXscreen, float nPosYscreen, float nDai, float nRong, DWORD nColor, int pTexture = 0, int nThamSo1=0);// ve icon 2d thi cho pTexture vao
KPos	GetScreenPosBar(KNpc* pNpc, bool nIsHP = false); // mac dinh get ScreenPos MP_Bar( dung cho phien ban cu:7.7->7.23)
KPos	GetScreenPosBarTopCenter(KNpc* pNpc);	// dung cho phien ban cu:7.24
KPos	GetScreenPosBarCenter(KNpc* pNpc);		// dung cho phien ban cu:7.24  --> lay me cai nay cho xong

KPos	GetScreenPosMiniMap(KPos* pWorldPos); 
DWORD	LoadFolderSource_Old(char* szFolderName);			// folder source cua CharacterTextures 0-9
DWORD	LoadFolderSource(char* szFolderName);

KPos	GetGameCursorPos(); 

DWORD	LoadFolderSource_TEST(char* szFolderName);		// folder source cua CharacterTextures 0-9
void	GameTEST();
void    GameDrawMana_Test2();

void    GameDrawMiniMap_Test();

