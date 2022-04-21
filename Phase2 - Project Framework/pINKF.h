#pragma once
#include"Actions/Action.h"
class pINKF :public Action
{
private:

public:
	pINKF (ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


