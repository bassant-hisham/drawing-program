#include "CutAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No Figures selected to be cut");
	}
	else
	{
		pManager->CutFigure();
		pManager->UpdateInterface();
		pOut->PrintMessage(to_string(pManager->GetClipBoardCount()) + " Figures has been cut and saved in clipboard");
	}
}
