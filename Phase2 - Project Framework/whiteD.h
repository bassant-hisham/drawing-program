#pragma once
#include"Actions/Action.h"
class whiteD :public Action
{
private:

public:
	whiteD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



