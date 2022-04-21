#include "lIGHTSKYBLUEF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

lIGHTSKYBLUEF::lIGHTSKYBLUEF(ApplicationManager* pApp) :Action(pApp)
{
}

void lIGHTSKYBLUEF::ReadActionParameters()
{
}

void lIGHTSKYBLUEF::Execute()
{

	Output* pOut = pManager->GetOutput();
	
	pOut->getCrntFillColor();
	UI.FillColor = LIGHTSKYBLUE;

	pOut->PrintMessage("Change the Fill Colour to LIGHTSKYBLUE");

	pManager->passfillcolor(LIGHTSKYBLUE);
}




