#pragma once
#include"Actions/Action.h"
class pINKB :public Action
{
private:

public:
	pINKB(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



