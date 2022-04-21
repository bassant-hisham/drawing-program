#pragma once
#include"Actions/Action.h"
class lEMONCHIFFONB :public Action
{
private:

public:
	lEMONCHIFFONB(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

