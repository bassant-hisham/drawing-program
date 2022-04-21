#ifndef CHANGE_COLOURS_ACTION_H
#define CHANGE_COLOURS_ACTION

#include"Actions\Action.h"

class ChangeColoursAction : public Action
{
public:
	ChangeColoursAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif

