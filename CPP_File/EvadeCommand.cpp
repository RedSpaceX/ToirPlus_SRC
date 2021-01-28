#include "EvadeCommand.h"
//#include "Position.h"
#include "EvadeUtils.h"
#include "Situation.h"


//extern SpellDetector*	_SpellDetector;
extern Evade*			_Evade;
//extern EvadeHelper*	_EvadeHelper;
extern EvadeUtils*		_EvadeUtils;
extern EvadeSpell*		_EvadeSpell;

extern GameObjectIssueOrderEventArgs* ArgsMove;

extern float LastAttackCommandT_Safe;
extern float LastCall_MoveToFunc;

//---------------------------------------------------------------------//--------------------//
void MOVE_TO_NODELAY_4EVADE(float &posX, float &posY)
{
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempFunc = MOVE_TO_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD nFunc 	= nTempFunc;

	DWORD nTempECX  = BASE - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX 		= *(DWORD*)nTempECX;
	if(!_ECX) return;
	float posZ		 = GetPlayer() ? GetPlayer()->CurrentPos.y : 0.0f;
	float buff[5]		 = {posX,posZ,posY};
	DWORD* nBuffer = (DWORD*)&buff[0];
	//float *nBuffer	 = buff;

	/*__asm
	{
		push 1
		push 0
		push 0
		push 0
		push nBuffer
		push 2
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}*/
	
	DWORD retnAddress	  = OFF_FUCKING_MOVE - TEMP_ENTRY_POINT;			//0xF66198;//0x3F8B7C;	(9.22)
	DWORD retnInstruction = hModule + retnAddress; 							//retn instruction 

	DWORD BASE_ANTI_ISSUEORDER	  = BASE_ANTI_ISSUE_ORDER - TEMP_ENTRY_POINT + hModule;
	*(DWORD*)BASE_ANTI_ISSUEORDER = 0x13;

	__asm
	{
		push retnHere
			mov ecx, _ECX
			push 0
			push 0
			push 0
			push 0
			push nBuffer
			push 2
			push retnInstruction
			jmp nTempFunc
retnHere:
	}
	*(DWORD*)BASE_ANTI_ISSUEORDER = 0x13;
}

//---------------------------------------------------------------------//--------------------//
void NormalAttack_4Evade(KNpc *pNpc)
{
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempFunc = MOVE_TO_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD nFunc 	= nTempFunc;

	DWORD nTempECX  = BASE - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX 		= *(DWORD*)nTempECX;

	if(!_ECX) return;
	DWORD Monster	= (DWORD)&pNpc->nTemp_1;

	DWORD* nBuffer	= (DWORD*)&pNpc->CurrentPos.x;

	/*__asm
	{
	push 1
	push 0
	push 0
	push Monster
	push nBuffer
	push 3
	mov ecx,_ECX
	mov eax,nFunc
	call eax
	}*/

	DWORD retnAddress	  = OFF_FUCKING_MOVE - TEMP_ENTRY_POINT ;			//0xF66198;//0x3F8B7C; (9.22)
	DWORD retnInstruction = hModule + retnAddress; 							//retn instruction 

	DWORD BASE_ANTI_ISSUEORDER	  = BASE_ANTI_ISSUE_ORDER - TEMP_ENTRY_POINT + hModule;
	*(DWORD*)BASE_ANTI_ISSUEORDER = 0x14;

	__asm
	{
		push retnHere
			mov ecx, _ECX
			push 1
			push 0
			push 0
			push Monster
			push nBuffer
			push 3
			push retnInstruction
			jmp nTempFunc
retnHere:
	}

	*(DWORD*)BASE_ANTI_ISSUEORDER = 0x14;
}

//---------------------------------------------------------------------//--------------------//
void EC_MoveTo(Vec3D movePos, bool xxx)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;
	if (!ShouldDodge())	return;

	static float move_4Evade_tick = 0;
	if ((float)GetTickCount() - move_4Evade_tick > 69)
	{
		_Evade->lastEvadeCommand->order			 = Order_MoveTo;
		_Evade->lastEvadeCommand->targetPosition = movePos;
		_Evade->lastEvadeCommand->timestamp      = _EvadeUtils->TickCount();
		_Evade->lastEvadeCommand->isProcessed    = false;

		_Evade->lastMoveToPosition				 = movePos;
		_Evade->lastMoveToServerPos				 = myHero->currentPos();
	
		////MOVE_TO(movePos.x, movePos.z, false);	// co the thay bang ham moi
	
		move_4Evade_tick = (float)GetTickCount();
		MOVE_TO_NODELAY_4EVADE(movePos.x, movePos.z);
	}
}

//---------------------------------------------------------------------//--------------------//
void EC_Attack(EvadeSpellData spellData, KNpc* target, bool xxx)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	static float aaaa_4Evade_tick = 0;
	if ((float)GetTickCount() - aaaa_4Evade_tick > 100)
	{
		_EvadeSpell->lastSpellEvadeCommand->order		   = Order_Attack;
		_EvadeSpell->lastSpellEvadeCommand->target		   = target;
		_EvadeSpell->lastSpellEvadeCommand->evadeSpellData = &spellData;
		_EvadeSpell->lastSpellEvadeCommand->timestamp      = _EvadeUtils->TickCount();
		_EvadeSpell->lastSpellEvadeCommand->isProcessed    = false;

	
		aaaa_4Evade_tick = (float)GetTickCount();
		NormalAttack_4Evade(target);	
	}
}

//---------------------------------------------------------------------//--------------------//
void EC_CastSpell(EvadeSpellData* spellData, KNpc* target)
{
	_EvadeSpell->lastSpellEvadeCommand->order		   = Order_CastSpell;
	_EvadeSpell->lastSpellEvadeCommand->target         = target;
	_EvadeSpell->lastSpellEvadeCommand->evadeSpellData = spellData;
	_EvadeSpell->lastSpellEvadeCommand->timestamp	   = (float)GetTickCount();
	_EvadeSpell->lastSpellEvadeCommand->isProcessed    = false;
	
	Cast2Target(target, spellData->spellKey /*, false*/);
	//myHero.Spellbook.CastSpell(spellData.spellKey, target, false);
}

//---------------------------------------------------------------------//--------------------//
void EC_CastSpell(EvadeSpellData* spellData, Vec3D movePos)
{
	_EvadeSpell->lastSpellEvadeCommand->order		   = Order_CastSpell;
	_EvadeSpell->lastSpellEvadeCommand->targetPosition = movePos;
	_EvadeSpell->lastSpellEvadeCommand->evadeSpellData = spellData;
	_EvadeSpell->lastSpellEvadeCommand->timestamp	   = (float)GetTickCount();
	_EvadeSpell->lastSpellEvadeCommand->isProcessed    = false;

	Cast2Pos(&movePos, spellData->spellKey /*, false*/);
	//myHero.Spellbook.CastSpell(spellData.spellKey, movePos.To3D(), false);
}

//---------------------------------------------------------------------//--------------------//
void EC_CastSpell(EvadeSpellData* spellData)	//chac la cast_ban_than
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	_EvadeSpell->lastSpellEvadeCommand->order		   = Order_CastSpell;
	_EvadeSpell->lastSpellEvadeCommand->evadeSpellData = spellData;
	_EvadeSpell->lastSpellEvadeCommand->timestamp	   = (float)GetTickCount();
	_EvadeSpell->lastSpellEvadeCommand->isProcessed    = false;
		
	Cast2Target(myHero, spellData->spellKey /*, false*/);
	//myHero.Spellbook.CastSpell(spellData.spellKey,false);
}

//---------------------------------------------------------------------//--------------------//