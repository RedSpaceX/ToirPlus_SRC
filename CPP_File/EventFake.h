#pragma once
#include "Utils.h"


//--------------------------------------//------------------------------------------||
//--- OnNewPathFakeAction --------------//------------------------------------------||
class OnNewPathFakeAction
{
public:
	typedef void (*Callback_OnNewPathFake)(KNpc*, DWORD, DWORD, DWORD, BYTE, float, BYTE, bool, int, DWORD, DWORD, DWORD);

	struct Action_OnNewPathFake
	{
		Callback_OnNewPathFake CallbackObject;

		Action_OnNewPathFake(Callback_OnNewPathFake callback)
		{
			CallbackObject = callback;
		}
	};

	std::vector<Action_OnNewPathFake>* Action_OnNewPathFake_List;
	OnNewPathFakeAction()
	{
		Action_OnNewPathFake_List = new std::vector<Action_OnNewPathFake>;
	}

	void Add(Callback_OnNewPathFake func)
	{
		Action_OnNewPathFake action(func);
		Action_OnNewPathFake_List->push_back(action);
	}

	void ONPF_Called(KNpc* pUnit, DWORD pStart, DWORD pEnd, DWORD pMaxEnd, BYTE pathCount, float dashSpeed, BYTE isDash, bool isDashGravity, int dashGravityCount, DWORD unk10, DWORD unk11, DWORD unk12)
	{
		for (int i = (int)Action_OnNewPathFake_List->size() - 1; i >= 0; i--)
		{
			//try
			{
				if (Action_OnNewPathFake_List->at(i).CallbackObject != 0)
				{
					Action_OnNewPathFake_List->at(i).CallbackObject(pUnit, pStart, pEnd, pMaxEnd, pathCount, dashSpeed, isDash, isDashGravity, dashGravityCount, unk10, unk11, unk12);
				}
			}
			//catch (const std::exception& ex)
			{
				//__oMsg("ActionList: %s", xx_yy);
			}
		}
	}
};

//--------------------------//-----------------------//
struct	Unit_Paths
{
	KNpc*		Unit;
	DWORD		networkID;
	Vec3D		endPos;
	int			dashGravityCount;
	float		lastNewPathTick;
	Unit_Paths()
	{
		Unit	  = 0;
		networkID = 0;
		endPos.x  = 0;
		endPos.y  = 0;
		endPos.z  = 0;
		dashGravityCount = 0;
		lastNewPathTick  = 0;
	}
};

//--------------------------------------//------------------------------------------||
//--- OnDeleteObjectFakeAction --------------//------------------------------------------||
class OnDeleteObjectFakeAction
{
public:
	typedef void (*Callback_OnDeleteObjectFake)(DWORD, DWORD, DWORD, DWORD, float);

	struct Action_OnDeleteObjectFake
	{
		Callback_OnDeleteObjectFake CallbackObject;

		Action_OnDeleteObjectFake(Callback_OnDeleteObjectFake callback)
		{
			CallbackObject = callback;
		}
	};

	std::vector<Action_OnDeleteObjectFake>* Action_OnDeleteObjectFake_List;
	OnDeleteObjectFakeAction()
	{
		Action_OnDeleteObjectFake_List = new std::vector<Action_OnDeleteObjectFake>;
	}

	void Add(Callback_OnDeleteObjectFake func)
	{
		Action_OnDeleteObjectFake action(func);
		Action_OnDeleteObjectFake_List->push_back(action);
	}

	void ODOF_Called(DWORD dwObject, DWORD networkID, DWORD objectType, DWORD ownerID, float timeDeleted)
	{
		for (int i = (int)Action_OnDeleteObjectFake_List->size() - 1; i >= 0; i--)
		{
			//try
			{
				if (Action_OnDeleteObjectFake_List->at(i).CallbackObject != 0)
				{
					Action_OnDeleteObjectFake_List->at(i).CallbackObject(dwObject, networkID, objectType, ownerID, timeDeleted);
				}
			}
			//catch (const std::exception& ex)
			{
				//__oMsg("ActionList: %s", xx_yy);
			}
		}
	}
};

//--------------------------//-----------------------//
void OnNewPath_EventFake_InGameUpdate();
void ONPF_TEST_1(KNpc* pUnit, DWORD pStart, DWORD pEnd, DWORD pMaxEnd, BYTE pathCount, float dashSpeed, BYTE isDash, bool isDashGravity, int dashGravityCount, DWORD unk10, DWORD unk11, DWORD unk12);

void OnDeleteObject_EventFake_InGameUpdate();
void ODOF_TEST_1(DWORD dwObject, DWORD networkID, DWORD objectType, DWORD ownerID, float timeDeleted);