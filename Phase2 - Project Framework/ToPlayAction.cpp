#include"ToPlayAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

ToPlayAction::ToPlayAction(ApplicationManager* pApp): Action (pApp)
{
}

void ToPlayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("return to play toolbar");
}

void ToPlayAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->savedrawgraph();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
