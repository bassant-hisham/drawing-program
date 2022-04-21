#pragma once

#include"Actions/Action.h"
class whiteB :public Action
{
private:

public:
	whiteB(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


