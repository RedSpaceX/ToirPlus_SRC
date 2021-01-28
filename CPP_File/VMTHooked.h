#pragma once
#include "Utils.h"





//==================================================================================//
DWORD GetOrg_Func(PDWORD vtable, int index);
void  Detour_VMT_ALL();
void  Retour_VMT_ALL();

UINT CountVMTFunctions(PDWORD pdwVMT);
bool SwapVMT(PDWORD *ppdwClassBase, PDWORD &pdwOldVMT, PDWORD &pdwNewVMT);
bool SwapVMT_Back(PDWORD *ppdwClassBase, PDWORD pdwOldVMT);
bool HookVMTFuncion(PDWORD *ppdwClassBase, DWORD dwNewFunction, UINT uiFunctionIndex);

//--------//---------------//------//------//------//------
class OnProcessSpellAction
{
public:
	typedef void (*CallbackOPS)(KNpc*, KCastSpell*);

	struct ActionOPS
	{
		CallbackOPS CallbackObject;

		ActionOPS(CallbackOPS callback)
		{
			CallbackObject = callback;
		}
	};

	std::vector<ActionOPS>* ActionOPSList;
	OnProcessSpellAction()
	{
		ActionOPSList = new std::vector<ActionOPS>;
	}

	void Add(CallbackOPS func)
	{
		ActionOPS action(func);
		ActionOPSList->push_back(action);
	}

	void OPS_Called(KNpc* hero, KCastSpell* pCast)
	{
		for (int i = (int)ActionOPSList->size() - 1; i >= 0; i--)
		{
			//try
			{
				if (ActionOPSList->at(i).CallbackObject != 0)
				{
					ActionOPSList->at(i).CallbackObject(hero, pCast);
				}
			}
			//catch (const std::exception& ex)
			{
				//__oMsg("ActionList: %s", xx_yy);
			}
		}
	}
};

//--------//---------------//------//------//------//------
class OnProcessSpellAction_222
{
public:
	typedef void (*CallbackOPS_222)(KNpc*, KCastSpell*);

	struct ActionOPS_222
	{
		CallbackOPS_222 CallbackObject_222;

		ActionOPS_222(CallbackOPS_222 callback_222)
		{
			CallbackObject_222 = callback_222;
		}
	};

	std::vector<ActionOPS_222>* ActionOPSList_222;
	OnProcessSpellAction_222()
	{
		ActionOPSList_222 = new std::vector<ActionOPS_222>;
	}

	void Add(CallbackOPS_222 func)
	{
		ActionOPS_222 action(func);
		ActionOPSList_222->push_back(action);
	}

	void OPS_Called(KNpc* minion, KCastSpell* pCast)
	{
		for (int i = (int)ActionOPSList_222->size() - 1; i >= 0; i--)
		{
			//try
			{
				if (ActionOPSList_222->at(i).CallbackObject_222 != 0)
				{
					ActionOPSList_222->at(i).CallbackObject_222(minion, pCast);
				}
			}
			//catch (const std::exception& ex)
			{
				//__oMsg("ActionList: %s", xx_yy);
			}
		}
	}
};

//--------//---------------//------//------//------//------
class OnCreateMissileAction
{
public:
	typedef void (*CallbackOCM)(KNpc*, KCastSpell*);

	struct ActionOCM
	{
		CallbackOCM CallbackObject;

		ActionOCM(CallbackOCM callback)
		{
			CallbackObject = callback;
		}
	};

	std::vector<ActionOCM>* ActionOCMList;
	OnCreateMissileAction()
	{
		ActionOCMList = new std::vector<ActionOCM>;
	}

	void Add(CallbackOCM func)
	{
		ActionOCM action(func);
		ActionOCMList->push_back(action);
	}

	void OCM_Called(KNpc* hero, KCastSpell* pCast)
	{
		for (int i = (int)ActionOCMList->size() - 1; i >= 0; i--)
		{
			if (ActionOCMList->at(i).CallbackObject != 0)
			{
				ActionOCMList->at(i).CallbackObject(hero, pCast);
			}
		}
	}
};

//--------//---------------//------//------//------//------
class OnPlayAnimationAction
{
public:
	typedef void (*CallbackOPA)(KNpc*, char*);

	struct ActionOPA
	{
		CallbackOPA CallbackObject;

		ActionOPA(CallbackOPA callback)
		{
			CallbackObject = callback;
		}
	};

	std::vector<ActionOPA>* ActionOPAList;
	OnPlayAnimationAction()
	{
		ActionOPAList = new std::vector<ActionOPA>;
	}

	void Add(CallbackOPA func)
	{
		ActionOPA action(func);
		ActionOPAList->push_back(action);
	}

	void OPA_Called(KNpc* hero, char* szAnimation)
	{
		for (int i = (int)ActionOPAList->size() - 1; i >= 0; i--)
		{
			if (ActionOPAList->at(i).CallbackObject != 0)
			{
				ActionOPAList->at(i).CallbackObject(hero, szAnimation);
			}
		}
	}
};


//--------//---------------//------//------//------//------
class OnSendRecvPacketAction
{
public:
	typedef void (*CallbackOSRP)(DWORD);

	struct ActionOSRP
	{
		CallbackOSRP CallbackObject;

		ActionOSRP(CallbackOSRP callback)
		{
			CallbackObject = callback;
		}
	};

	std::vector<ActionOSRP>* ActionOSRPList;
	OnSendRecvPacketAction()
	{
		ActionOSRPList = new std::vector<ActionOSRP>;
	}

	void Add(CallbackOSRP func)
	{
		ActionOSRP action(func);
		ActionOSRPList->push_back(action);
	}

	void OSRP_Called( DWORD buffer )
	{
		for (int i = (int)ActionOSRPList->size() - 1; i >= 0; i--)
		{
			//try
			{
				if (ActionOSRPList->at(i).CallbackObject != 0)
				{
					ActionOSRPList->at(i).CallbackObject( buffer );
				}
			}
			//catch (const std::exception& ex)
			{
				//__oMsg("ActionList: %s", xx_yy);
			}
		}
	}
};