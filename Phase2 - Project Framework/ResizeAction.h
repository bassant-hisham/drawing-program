#pragma once
#include"Actions/Action.h"
class ResizeAction :public Action
{
private:
	Point p1;
	Point p2;
	string size;
public:
	ResizeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

