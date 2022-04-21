#pragma once
#include"Actions/Action.h"
class bURLYWOODB:public Action
{
private:

public:
	bURLYWOODB(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

