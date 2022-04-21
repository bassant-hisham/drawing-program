#pragma once
#include"Actions/Action.h"
class whiteF:public Action
{
private:

public:
	whiteF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

