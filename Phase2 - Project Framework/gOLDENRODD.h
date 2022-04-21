#pragma once
#include"Actions/Action.h"
class gOLDENRODD:public Action
{
private:

public:
	gOLDENRODD(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

