
#pragma once
#include"Actions/Action.h"
class gAINSBOROF :public Action
{
private:

public:
	gAINSBOROF(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



