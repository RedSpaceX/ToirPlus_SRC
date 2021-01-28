#include "EventFake.h"
#include "OrbWalker/Dash.h"

//DWORD pObj, DWORD pStart, DWORD pEnd, DWORD pMaxEnd, BYTE pathCount, DWORD DashSpeedBuff, BYTE isDash, DWORD isDashGravityBuff, BYTE DashGravityCount, DWORD unk10, DWORD unk11, DWORD unk12

//if (ONPF_HookedList) 
//{
//	ONPF_HookedList->OPS_Called((KNpc*)(_unitTemp - VMT_ONPROCESSSPELL_OFFSET), (KCastSpell*)_spellCast);
//}

extern DWORD G_Module;
extern KNpc* MY_HERO;

OnNewPathFakeAction* ONPF_HookedList = 0;
Unit_Paths tempUnitPath[10];

OnDeleteObjectFakeAction* ODOF_HookedList = 0;

bool add1Lan_ONPF_TEST_1 = true;
bool add1Lan_Set_DetectedDashes_ONPF = true;
extern void Set_DetectedDashes_ONPF(KNpc* pObj, DWORD pStart, DWORD pEnd, DWORD pMaxEnd, BYTE pathCount, float dashSpeed, BYTE isDash, bool isDashGravity, int dashGravityCount, DWORD unk10, DWORD unk11, DWORD unk12);
//===============================================//===================================//
void OnNewPath_EventFake_InGameUpdate()	// check voi hero thoi cho do~ lang ngoang
{
	if (ONPF_HookedList == 0) ONPF_HookedList = new OnNewPathFakeAction;

	// Test --------------------
	if (ONPF_HookedList && add1Lan_ONPF_TEST_1 == true)
	{
		add1Lan_ONPF_TEST_1 = false;
		ONPF_HookedList->Add(ONPF_TEST_1);
	}
	
	// Set_DetectedDashes_ONPF --------------------
	if (ONPF_HookedList && add1Lan_Set_DetectedDashes_ONPF == true)
	{
		add1Lan_Set_DetectedDashes_ONPF = false;
		ONPF_HookedList->Add(Set_DetectedDashes_ONPF);
	}

	// Code Fake --------------------
	if ( !G_Module) return;

	DWORD tempHero	  = BASE_HERO - TEMP_ENTRY_POINT     + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD dw1 = *(DWORD*)tempHero;
	DWORD dw2 = *(DWORD*)tempHeroMax;
	if (!dw1 || !dw2 ) return;

	int index = 0;
	int nCount = (dw2 - dw1)/4;
	for (int jjj = 0; jjj < nCount; ++jjj)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*jjj);
		if (dw3 == 0) continue;
		KNpc *unit = (KNpc*)dw3;
		
		stMOVE *unitPmove = (stMOVE*) GET_PMOVE_NEW(unit);
		if (unitPmove == 0) continue;

		for (int i = 0; i < 10; ++i)	
		{
			if (tempUnitPath[i].networkID == 0)
			{
				bool coRoi = false;
				for (int k = 0; k < 10; ++k)	
				{
					if (tempUnitPath[k].networkID != 0 && tempUnitPath[k].networkID == unit->nIndex)
					{
						coRoi = true;
						break;
					}
				}
				
				if (coRoi == false)
				{
					tempUnitPath[i].Unit      = unit;
					tempUnitPath[i].networkID = unit->nIndex;
					tempUnitPath[i].endPos.x  = unitPmove->__strPosDest.x;
					tempUnitPath[i].endPos.y  = unitPmove->__strPosDest.y;
					tempUnitPath[i].endPos.z  = unitPmove->__strPosDest.z;
					tempUnitPath[i].dashGravityCount = unitPmove->nDashGravity;
					break;
				}
				else
				{
					break;
				}
			}
		}

		//if (unit != GetPlayer()) continue;
		for (int i = 0; i < 10; ++i)
		{
			if (tempUnitPath[i].networkID == 0) continue;
			if (tempUnitPath[i].networkID == unit->nIndex)
			{
				if ( fabs(tempUnitPath[i].endPos.x - unitPmove->__strPosDest.x) > FLT_EPSILON || fabs(tempUnitPath[i].endPos.z - unitPmove->__strPosDest.z) > FLT_EPSILON)
				{
					bool isDashGravity = false;									//ko lay dc cai nay, tu che 
					if (unitPmove->nDashGravity > tempUnitPath[i].dashGravityCount)
					{
						isDashGravity = true;
						tempUnitPath[i].dashGravityCount = unitPmove->nDashGravity;
					}

					tempUnitPath[i].endPos.x  = unitPmove->__strPosDest.x;
					tempUnitPath[i].endPos.y  = unitPmove->__strPosDest.y;
					tempUnitPath[i].endPos.z  = unitPmove->__strPosDest.z;
					tempUnitPath[i].lastNewPathTick = (float)GetTickCount();
					if (ONPF_HookedList) 
					{
						DWORD start  = unitPmove->nWayPoint_Start;
						DWORD end    = unitPmove->nWayPoint_End;
						DWORD maxEnd = unitPmove->nWayPoint_MaxEnd;
						int  count  = (end - start)/12;
						BYTE  isDash = (BYTE)unitPmove->nIsDash;					// =0 la dang dashing
						float dashSpeed		    = unitPmove->nDashSpeed;			// lay luon gia tri
						BYTE  dashGravityCount  = unitPmove->nDashGravity;
						DWORD unk10 = 0;											//ko lay dc cai nay
						DWORD unk11 = 0;											//ko lay dc cai nay
						DWORD unk12 = 0;											//ko lay dc cai nay
						
						ONPF_HookedList->ONPF_Called(unit, start, end, maxEnd, count, dashSpeed, isDash, isDashGravity, dashGravityCount, unk10, unk11, unk12);
						//__oMsg_2("index: %x - %x [%s] [%f, %f]", tempUnitPath[i].networkID, tempUnitPath[i].Unit->nIndex, tempUnitPath[i].Unit->GetNameNpc(), tempUnitPath[i].endPos.x, tempUnitPath[i].endPos.z);
					}
				}
			}
		}
	}


	/*for (int i = 0; i < 10; ++i)
	{
		if (tempUnitPath[i].Unit == 0) __oMsg_2("i=%d, index: %x", i, tempUnitPath[i].networkID);
		else __oMsg_2("i=%d, index: %x - %x [%s]", i, tempUnitPath[i].networkID, tempUnitPath[i].Unit->nIndex, tempUnitPath[i].Unit->GetNameNpc());
		if (i == 10) __oMsg_2(" ----------------------------- \n");
	}*/

}

//===============================================//===================================//
void ONPF_TEST_1(KNpc* pUnit, DWORD pStart, DWORD pEnd, DWORD pMaxEnd, BYTE pathCount, float dashSpeed, BYTE isDash, bool isDashGravity, int dashGravityCount, DWORD unk10, DWORD unk11, DWORD unk12)
{
	//__oMsg_2("ONPF_TEST_1: [%s] pUnit = %x, %d, %x, %x, %x", pUnit->GetNameNpc(), pUnit, pathCount, pStart, pEnd, pMaxEnd);
	//__oMsg_2("ONPF_TEST_1: dashSpeed: %f, isDash: %d, isDashGravity: %d, dashGravityCount: %d", dashSpeed, isDash, isDashGravity, dashGravityCount);
	//__oMsg_2("---------------- END.END.ONPF_TEST_1.END -----------------------------\n\n");
}


//===============================================//===================================//
//===============================================//===================================//
struct KObjectDeleted
{
	DWORD	dwObject;
	DWORD	nIndex;					// networkID
	DWORD	objectType;				// minion, missile ...
	//DWORD	ownerIndex;				// dung voi missile : networkID cua object ban' 
	DWORD	ownerID;				// dung voi missile : ID cua object ban' ra
	float	fFirstTimeDeleted;
};

std::vector<KObjectDeleted> *objectDeleted = 0;

//------------------------------------------------:
void fuckEraseObjectDeleted()
{
	////__try
	{
		if ( objectDeleted && objectDeleted->size() > 0 )
		{
			for (unsigned i = 0; i < objectDeleted->size(); ++i)
			{
				//if (objectDeleted->at(i).nIndex == 0)
				{
					if (GetTimeGame() - objectDeleted->at(i).fFirstTimeDeleted > 0.05f)
					{
						//__oMsg("(size=%d) ERASE: %d [%f]", objectDeleted->size(), i, objectDeleted->at(i).fFirstTimeDeleted);
						objectDeleted->erase(objectDeleted->begin() + i);
						//break;
					}
				}
			}
		}
	}
	////__except(1)
	////{
	////	__oMsg("fuckEraseObjectDeleted()");
	////}
}

//------------------------------------------------:
bool isInListObjectAll(DWORD nIndex)
{
	if ( !G_Module ) return false;
	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;

	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	if ( !dw0 ) return false;

	DWORD dw1 = *(DWORD*)(dw0 + 8);
	if ( !dw1 ) return false;

	int countObj = *(DWORD*)(dw0 + 0xC);
	if ( !countObj ) return false;

	for ( int kk = 0; kk < countObj; ++kk )
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
		if ( dw3 == 0 ) continue;
		KNpc *objectG = (KNpc*)dw3;

		if (objectG->nIndex == nIndex) return true;
	}
	return false;
}

//------------------------------------------------:
void OnDeleteObject_EventFake_InGameUpdate()		// *** CACH NAY KO ON? LAM ******		
{
	if ( !objectDeleted   ) objectDeleted   = new std::vector<KObjectDeleted>;
	if ( !ODOF_HookedList ) ODOF_HookedList = new OnDeleteObjectFakeAction;

	///*static bool setODOFOnce = true;
	//if ( setODOFOnce == true && ODOF_HookedList )
	//{
	//	setODOFOnce = false;
	//	ODOF_HookedList->Add(ODOF_TEST_1);
	//}*/

	//__oMsg("\n------------------------ SIZE: %d [TG: %.4f]", objectDeleted->size(), timeGame);

	//------ DELETE OBJECT VUA CO IS_OBJ_DELETED() == true:
	fuckEraseObjectDeleted();


	if ( !G_Module ) return;
	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;

	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	if ( !dw0 ) return;

	DWORD dw1 = *(DWORD*)(dw0 + 8);
	if ( !dw1 ) return;

	int countObj = *(DWORD*)(dw0 + 0xC);
	if ( !countObj ) return;
	
	//__oMsg("countObj : %d", countObj);

	for ( int kk = 0; kk < countObj; ++kk )
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
		if ( dw3 == 0 ) continue;
		KNpc *objectG = (KNpc*)dw3;
		
		if ( IS_OBJECT_TYPE(objectG, 0x8000) /*|| IS_MINION(objectG)*/ ) 		// Test voi Misille truoc
		{
			//__oMsg("[%s] GetTimeGame: %.5f", objectG->GetNameNpc(), GetTimeGame());
			if ( objectDeleted->size() == 0 ) 
			{
				KObjectDeleted temp;
				temp.dwObject		   = dw3;
				temp.nIndex			   = objectG->nIndex;
				temp.objectType		   = OBJECT_TYPE(objectG);
				temp.fFirstTimeDeleted = 99999999.9f;

				if ( !IS_OBJECT_TYPE(objectG, 0x8000) )							//OBJECTs k phai missile
				{
					temp.ownerID = objectG->nID;				
				}
				else															//OBJECT  MISSILE
				{
					temp.ownerID = objectG->nMissileOwnerID_1;
				}
		
				objectDeleted->push_back(temp);
				//__oMsg("add-first: %x", objectG->nIndex);

				continue;
			}
			
			bool had1Object = false;
			for (unsigned i = 0; i < objectDeleted->size(); ++i)
			{
				//if (objectDeleted->at(i).nIndex == 0) continue;
				if (objectDeleted->at(i).nIndex == objectG->nIndex)		// da co roi
				{
					had1Object = true;
					//__oMsg("co 1 object roi : [%d] %x", i, objectDeleted->at(i).nIndex);

					break;
				}
			}

			if (had1Object == false)	// van~ chua co
			{
				KObjectDeleted temp;
				temp.dwObject		   = dw3;
				temp.nIndex			   = objectG->nIndex;
				temp.objectType		   = OBJECT_TYPE(objectG);
				temp.fFirstTimeDeleted = 99999999.9f;

				if ( !IS_OBJECT_TYPE(objectG, 0x8000) )							//OBJECTs k phai missile
				{
					temp.ownerID = objectG->nID;				
				}
				else															//OBJECT  MISSILE
				{
					temp.ownerID = objectG->nMissileOwnerID_1;
				}

				//__oMsg("add-Object: %x", objectG->nIndex);
			}
		}
	}
	
	for (unsigned i = 0; i < objectDeleted->size(); ++i)
	{
		if (objectDeleted->at(i).nIndex   == 0) continue;
		if (objectDeleted->at(i).dwObject == 0) continue;
		
		if ( isInListObjectAll(objectDeleted->at(i).nIndex) ) continue;
		
		ODOF_HookedList->ODOF_Called(objectDeleted->at(i).dwObject, objectDeleted->at(i).nIndex, objectDeleted->at(i).objectType, objectDeleted->at(i).ownerID, GetTimeGame());

		//objectDeleted->at(i).dwObject			= 0;
		//objectDeleted->at(i).nIndex				= 0;
		//objectDeleted->at(i).objectType		    = 0;
		//objectDeleted->at(i).ownerID			= 0;	
		objectDeleted->at(i).fFirstTimeDeleted  = GetTimeGame();		
	}
}

//===============================================//===================================//
void ODOF_TEST_1(DWORD dwObject, DWORD networkID, DWORD objectType, DWORD ownerID, float timeDeleted)	 
{
	//__oMsg("ODeleteObjectFake_TEST_1: pUnit = %x [%x], [%x - %x]time: %.5f\n",  dwObject, networkID, ownerID, MY_HERO->nID, timeDeleted);
}