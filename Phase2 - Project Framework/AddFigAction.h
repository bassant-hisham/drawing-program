
#include"Actions/Action.h"
class AddFigAction :public Action
{
public:
	AddFigAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

