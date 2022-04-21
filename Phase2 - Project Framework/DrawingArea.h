
#ifndef DRAWING_AREA_ACTION_H
#define DRAWING_AREA_ACTION_H
#include"Actions/Action.h"
	class DrawingArea:public Action
{
private:
public:
	DrawingArea(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif

