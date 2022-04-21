#pragma once
#include"Actions/Action.h"
class violetD:public Action
{
private:

public:
	violetD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

