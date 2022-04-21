#pragma once
#include"Actions/Action.h"
class ExitAction :public Action
{
private:
	string Answer;
public:
	ExitAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

