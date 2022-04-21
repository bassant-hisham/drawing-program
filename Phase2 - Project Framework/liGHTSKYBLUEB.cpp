#include "lIGHTSKYBLUEB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

lIGHTSKYBLUEB::lIGHTSKYBLUEB(ApplicationManager* pApp) :Action(pApp)
{
}

void lIGHTSKYBLUEB::ReadActionParameters()
{
}

void lIGHTSKYBLUEB::Execute()
{

	Output* pOut = pManager->GetOutput();
	UI.BkGrndColor = pOut->getBkcolor();
	UI.BkGrndColor = LIGHTSKYBLUE;

	pOut->PrintMessage("Change the Background Colour to LIGHTSKYBLUE");


}




