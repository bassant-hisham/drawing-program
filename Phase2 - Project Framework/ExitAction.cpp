#include"ApplicationManager.h"
#include"ExitAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"

ExitAction::ExitAction(ApplicationManager* pApp):Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("if you didnot save type no if you saved type yes");
    Answer =pIn->GetSrting(pOut);
}
void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->Exit(Answer);
}
