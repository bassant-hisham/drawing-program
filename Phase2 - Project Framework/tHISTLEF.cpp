#include "tHISTLEF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"

tHISTLEF::tHISTLEF(ApplicationManager* pApp) :Action(pApp)
{
}

void tHISTLEF::ReadActionParameters()
{
}

void tHISTLEF::Execute()
{

	Output* pOut = pManager->GetOutput();
	pOut->getCrntFillColor();
	UI.FillColor = THISTLE;

	pOut->PrintMessage("Change the Fill Colour to  THISTLE");
	pManager->passfillcolor(THISTLE);
}






