#pragma once
#include"Actions/Action.h"
class violetB :public Action
{
private:

public:
	violetB (ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};



