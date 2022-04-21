#pragma once
#include"Actions/Action.h"
class ChangeFillColour:public Action
{
public:
	ChangeFillColour(ApplicationManager* pApp=0);

	virtual void ReadActionParameters();
	virtual void Execute();
	
};

