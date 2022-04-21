#include "AddFigAction.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"

AddFigAction::AddFigAction(ApplicationManager* pApp):Action(pApp)
{
	
}

void AddFigAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Change to Figures Tool Bar");
}

void AddFigAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->addfigures();
}
