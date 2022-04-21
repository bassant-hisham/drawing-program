#include"SelectAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on the figure to be selected");
	pIn->GetPointClicked(P1.x, P1.y);

}

void SelectAction::Execute()
{
	ReadActionParameters();

	
	pManager->SelectFigure(P1.x, P1.y);
	pManager->UpdateInterface();
}
