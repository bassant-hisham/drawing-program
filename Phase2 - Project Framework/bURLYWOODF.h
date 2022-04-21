#pragma once

#include"Actions/Action.h"
class bURLYWOODF :public Action
{
private:

public:
	bURLYWOODF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



