#pragma once
#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H
#include "Actions/Action.h"

class PasteAction : public Action
{
public:
	PasteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif