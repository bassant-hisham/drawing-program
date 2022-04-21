#include "EmptyAction.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
EmptyAction::EmptyAction(ApplicationManager* pApp):Action(pApp)
{
}

void EmptyAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("A Click on Empty Place on the Tool Bar");
}

void EmptyAction::Execute()
{
	ReadActionParameters();
}











            