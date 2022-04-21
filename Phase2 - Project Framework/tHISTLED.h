#pragma once
#include"Actions/Action.h"
class tHISTLED:public Action
{
private:

public:
	tHISTLED(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



