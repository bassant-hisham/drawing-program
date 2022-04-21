#include "gOLDENRODF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Ccirc.h"

gOLDENRODF::gOLDENRODF(ApplicationManager* pApp) :Action(pApp)
{
}

void gOLDENRODF::ReadActionParameters()
{
}

void gOLDENRODF::Execute()
{

	Output* pOut = pManager->GetOutput();

	
	
	
	pOut->getCrntFillColor();
	UI.FillColor = GOLDENROD;
	pOut->PrintMessage("Change the Fill Colour to GOLDENROD");
	pManager->passfillcolor(GOLDENROD);

}





