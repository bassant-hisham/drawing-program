#include "tHISTLEB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

tHISTLEB::tHISTLEB(ApplicationManager* pApp) :Action(pApp)
{
}

void tHISTLEB::ReadActionParameters()
{
}

void tHISTLEB::Execute()
{

	Output* pOut = pManager->GetOutput();

	UI.BkGrndColor = pOut->getBkcolor();
	UI.BkGrndColor = THISTLE;

	pOut->PrintMessage("Change the Background Colour to THISTLE");


}





