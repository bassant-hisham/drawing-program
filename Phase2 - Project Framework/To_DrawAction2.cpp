#include"To_DrawAction2.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

To_DrawAction2::To_DrawAction2(ApplicationManager* pApp):Action(pApp)
{
}

void To_DrawAction2::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("return to play toolbar");
}

void To_DrawAction2::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pManager->getdrawgraph();
}
