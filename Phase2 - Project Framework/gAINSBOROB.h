
#pragma once
#include"Actions/Action.h"
	class gAINSBOROB :public Action
{
private:

public:
	gAINSBOROB(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



