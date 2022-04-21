#pragma once
#include"Actions/Action.h"
class pINKD :public Action
{
private:

public:
	pINKD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


