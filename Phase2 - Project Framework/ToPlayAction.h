
#ifndef TO_PLAY_ACTION_H
#define TO_PLAY_ACTION_H
#include "Actions/Action.h"

class ToPlayAction : public Action
{
public:
	ToPlayAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif
