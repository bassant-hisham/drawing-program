#pragma once
#include"Actions/Action.h"
class tHISTLEF :public Action
{
private:

public:
	tHISTLEF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

