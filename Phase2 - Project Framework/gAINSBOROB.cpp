#include "gAINSBOROB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

gAINSBOROB::gAINSBOROB(ApplicationManager* pApp) :Action(pApp)
{
}

void gAINSBOROB::ReadActionParameters()
{
}

void gAINSBOROB::Execute()
{

	Output* pOut = pManager->GetOutput();

	UI.BkGrndColor = pOut->getBkcolor();
	UI.BkGrndColor = GAINSBORO;

	pOut->PrintMessage("Change the Background Colour to GAINSBORO");


}





