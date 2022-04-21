#include "pINKB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

pINKB::pINKB(ApplicationManager* pApp) :Action(pApp)
{
}

void pINKB::ReadActionParameters()
{
}

void pINKB::Execute()
{

	Output* pOut = pManager->GetOutput();

	UI.BkGrndColor = pOut->getBkcolor();
	UI.BkGrndColor = PINK;

	pOut->PrintMessage("Change the Background Colour to PINK");


}





#
