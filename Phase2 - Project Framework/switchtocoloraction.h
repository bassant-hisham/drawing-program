#pragma once
#ifndef SWITCH_TO_COLOR_ACTION
#define SWITCH_TO_COLOR_ACTION
#include "Actions/Action.h"
class switchtocoloraction:public Action
{

	public:
		switchtocoloraction(ApplicationManager* pApp);

		virtual void ReadActionParameters();

		virtual void Execute();
	};

#endif


