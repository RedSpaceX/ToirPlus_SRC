#pragma once
#include "Utils.h"
#include "Draw/Drawing.h"

bool __oMsg(const char * format, ...);
//bool __oMsg_PrintFile(const char * format, ...);
//bool __oMsg_Console(const char * format, ...);
void TestTest();
VOID CalcDistance();
void PrintWithConditional(float nRadius);
void PrintAllGameInfo(KNpc *pNpc);
void PrintAllGameInfo_222(KNpc *pNpc);
void Get_All_ObjectGame();
void Test_misile();

bool IS_OBJ_DELETED(KNpc* Obj, char* szFuck);
int OBJECT_TYPE(KNpc* obj);
bool IS_OBJECT_TYPE(KNpc* obj, DWORD objType);


void test_wardd();

