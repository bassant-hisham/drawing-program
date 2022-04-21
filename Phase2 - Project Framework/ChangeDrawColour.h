
#pragma once

#include"Actions/Action.h"
class ChangeDrawColour : public Action
{
private:
	int n = 1;
public:
ChangeDrawColour(ApplicationManager* pApp=0);

	virtual void ReadActionParameters();

	virtual void Execute();
	int getnD();
};
