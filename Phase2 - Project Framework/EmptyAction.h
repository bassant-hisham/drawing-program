#ifndef EMPTY_ACTION_H
#define EMPTY_ACTION_H
#include"Actions/Action.h"
class EmptyAction:public Action
{
private:
public:
	EmptyAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif

