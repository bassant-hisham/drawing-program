#pragma once
#include"Actions/Action.h"
class tHISTLEB :public Action
{
private:

public:
	tHISTLEB(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


