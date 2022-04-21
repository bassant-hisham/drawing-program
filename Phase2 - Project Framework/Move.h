#pragma once
#include"Actions/Action.h"
class Move:public Action
{
private:
	Point P1;
	Point p2;
public:
	Move(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

