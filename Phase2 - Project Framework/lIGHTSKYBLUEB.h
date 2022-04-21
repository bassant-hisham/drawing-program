#pragma once
#include"Actions/Action.h"
class lIGHTSKYBLUEB :public Action
{
private:

public:
	lIGHTSKYBLUEB (ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

