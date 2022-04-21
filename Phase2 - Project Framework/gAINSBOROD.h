#pragma once
#include"Actions/Action.h"
class gAINSBOROD :public Action
{
private:

public:
	gAINSBOROD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



