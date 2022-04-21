#ifndef TO_DRAW_ACTION_H
#define TO_DRAW_ACTION_H
#include"Actions/Action.h"
class To_DrawAction2:public Action
{
		public:
			To_DrawAction2(ApplicationManager* pApp);

			virtual void ReadActionParameters();

			virtual void Execute();
};

#endif