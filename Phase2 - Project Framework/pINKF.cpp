#include "pINKF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

pINKF::pINKF(ApplicationManager* pApp) :Action(pApp)
{
}

void pINKF::ReadActionParameters()
{
}

void pINKF::Execute()
{

	Output* pOut = pManager->GetOutput();
	
	pOut->getCrntFillColor();
	UI.FillColor = PINK;

	pOut->PrintMessage("Change the Fill Colour to PINK");
	pManager->passfillcolor(PINK);

}






