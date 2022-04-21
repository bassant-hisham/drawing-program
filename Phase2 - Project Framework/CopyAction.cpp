#include "CopyAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
}

void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedCount() == 0)
	{
		pOut->PrintMessage("No Figures selected to be copied");
	}
	else
	{
		pManager->CopyFigure();
		pManager->UpdateInterface();
		pOut->PrintMessage(to_string(pManager->GetClipBoardCount()) + " Figures has been copied to clipboard");
	}
}


