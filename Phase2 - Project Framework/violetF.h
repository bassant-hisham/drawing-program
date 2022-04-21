#pragma once
#include"Actions/Action.h"
class violetF :public Action
{
private:

public:
	violetF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
