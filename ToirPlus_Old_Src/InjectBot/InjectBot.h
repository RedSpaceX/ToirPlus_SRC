#pragma once
// TODO: reference additional headers your program requires here
//#ifdef INJECT_EX_EXPORTS
//	#define INJECTBOT_API extern "C" __declspec(dllexport)
//#else
//	#define INJECTBOT_API extern "C" __declspec(dllimport)
//#endif

//INJECTBOT_API int InjectDll_Mgr(HWND hWnd);
//INJECTBOT_API int UnmapDll_Mgr(HWND hWnd);

extern "C"
{
	//__declspec(dllexport) int InjectDll_Mgr(HWND hWnd);
	//__declspec(dllexport) int UnmapDll_Mgr(HWND hWnd);
	__declspec(dllexport) int glo23523vsasfsabal(HWND hWnd);
	//__declspec(dllexport) int UnmapDll_Real(HWND hWnd);
}
int UnmapDll_Real(HWND hWnd);
bool CheckName(char *findSubString, char *inString);
bool CheckNameEx(char *sz1, char *sz2);
