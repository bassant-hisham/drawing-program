#pragma once
#include"Actions/Action.h"
class blackD :public Action
{
private:

public:
	blackD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



