#pragma once
#include"Actions/Action.h"
class changeBKcolor :public Action
{
private:
	int n = 3;
public:
	changeBKcolor(ApplicationManager* pApp=0);

	virtual void ReadActionParameters();
	virtual void Execute();
	int getnBK();
};
