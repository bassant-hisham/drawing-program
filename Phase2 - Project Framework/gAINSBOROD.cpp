#include "gAINSBOROD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

gAINSBOROD::gAINSBOROD(ApplicationManager* pApp) :Action(pApp)
{
}

void gAINSBOROD::ReadActionParameters()
{
}

void gAINSBOROD::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	UI.DrawColor = GAINSBORO;

	pOut->PrintMessage("Change the Draw Colour to GAINSBORO");


}



