#include "gAINSBOROF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

gAINSBOROF::gAINSBOROF(ApplicationManager* pApp) :Action(pApp)
{
}

void gAINSBOROF::ReadActionParameters()
{
}

void gAINSBOROF::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	UI.FillColor = GAINSBORO;

	pOut->PrintMessage("Change the Fill Colour to GAINSBORO");

	pManager->passfillcolor(GAINSBORO);
}






