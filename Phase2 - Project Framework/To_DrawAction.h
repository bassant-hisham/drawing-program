#pragma once
#include"Actions/Action.h"
class To_DrawAction: public Action
{
public:
	To_DrawAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


