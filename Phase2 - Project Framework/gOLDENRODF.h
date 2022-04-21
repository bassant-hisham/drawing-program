
#pragma once
#include"Actions/Action.h"
class gOLDENRODF :public Action
{
private:

public:
	gOLDENRODF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


