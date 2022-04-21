#include"To_DrawAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

To_DrawAction::To_DrawAction(ApplicationManager* pApp) :Action(pApp)
{
}

void To_DrawAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("return to play toolbar");
}

void To_DrawAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}

