#pragma once
#include"Actions/Action.h"
#include "ApplicationManager.h"

class choosebyarea :public Action
{
private:
	CFigure* figure;
	Point p;
	double area;
	int index = 0;
	double areaselected;
	string s;
public:
	choosebyarea(ApplicationManager* pApp);

	//Reads rectangle parameters
	void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

