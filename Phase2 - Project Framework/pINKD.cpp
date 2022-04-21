#include "pINKD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

pINKD::pINKD(ApplicationManager* pApp) :Action(pApp)
{
}

void pINKD::ReadActionParameters()
{
}

void pINKD::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	UI.DrawColor = PINK;

	pOut->PrintMessage("Change the Draw Colour to PINK");


}






