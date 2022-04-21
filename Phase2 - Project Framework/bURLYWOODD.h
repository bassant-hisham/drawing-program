#pragma once
#include"Actions/Action.h"
class bURLYWOODD :public Action
{
private:

public:
	bURLYWOODD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

