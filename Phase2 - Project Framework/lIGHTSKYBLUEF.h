#pragma once
#include"Actions/Action.h"
class lIGHTSKYBLUEF:public Action
{
private:

public:
	lIGHTSKYBLUEF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

