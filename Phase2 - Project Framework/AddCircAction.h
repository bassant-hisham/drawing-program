#pragma once
#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Actions/Action.h"

class AddCircAction : public Action
{
private:
	Point P1, P2; 
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif