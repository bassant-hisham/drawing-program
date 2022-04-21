#include "lEMONCHIFFONB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

lEMONCHIFFONB::lEMONCHIFFONB(ApplicationManager* pApp) :Action(pApp)
{
}

void lEMONCHIFFONB::ReadActionParameters()
{
}

void lEMONCHIFFONB::Execute()
{

	Output* pOut = pManager->GetOutput();
	UI.BkGrndColor = pOut->getBkcolor();

	UI.BkGrndColor = LEMONCHIFFON;

	pOut->PrintMessage("Change the BackgroundColour to LEMONCHIFFON");


}




