#pragma once

//#include "stdafx.h"
#include "Log.h"



class DelayAction
{
public:
	typedef void (*Callback)();
	
	struct Action
	{
		Callback CallbackObject;
		float Time;

		Action(float time, Callback callback)
		{
			Time = time + (float)GetTickCount();
			CallbackObject = callback;
		}
	};

	std::vector<Action>* ActionList;
	DelayAction()
	{
		ActionList = new std::vector<Action>;
	}
		
	void Add(float time, Callback func)	// time tinh theo ms
	{
		Action action(time, func);
		ActionList->push_back(action);
	}

	void DelayAction_OnOnUpdate()
	{
		for (int i = (int)ActionList->size() - 1; i >= 0; i--)
		{
			//__oMsg("ActionList: %x, timeGame: %f", ActionList, GetTimeGame());
			if (ActionList->at(i).Time <= (float)GetTickCount())
			{
				//try
				{
					if (ActionList->at(i).CallbackObject != 0)
					{
						ActionList->at(i).CallbackObject();
						//Will somehow result in calling ALL non-internal marked classes of the called assembly and causes NullReferenceExceptions.
					}
				}
				//catch (const std::exception& ex)
				//{
				//	//__oMsg("ActionList: %s", xx_yy);
				//}

				ActionList->erase(ActionList->begin() + i);
			}
		}
	}
};

//----------------------------------------
//void OnGameUpdate_DelayAction();