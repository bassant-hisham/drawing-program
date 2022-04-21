#include "PasteAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;

PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pManager->PasteFigure();
	pManager->UpdateInterface();
	pOut->PrintMessage(to_string(pManager->GetPastedFiguresCount()) + " Figures has been pasted. If you want to paste again, click on the icon again.");
}


