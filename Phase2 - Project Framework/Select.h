#pragma once

#include "Actions/Action.h"

class Select : public Action
{
private:
	Point P1;
public:
	Select(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



