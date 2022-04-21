#ifndef CHOOSE_BY_TYPE_H
#define CHOOSE_BY_TYPE_H
#include"Actions/Action.h"
#include "ApplicationManager.h"

class ChooseByType :public Action
{
private:
	CFigure* figure;
	Type T;
	Type TSelected;
	Point p;
public:
	ChooseByType(ApplicationManager* pApp);

	//Reads rectangle parameters
	void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif