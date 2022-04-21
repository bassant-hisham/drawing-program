#pragma once
#include"Actions/Action.h"
class zoomAction :public Action
{
private:
	Point p1;
	Point p2;
	string size;
public:
	zoomAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

