#include "bURLYWOODF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"

bURLYWOODF::bURLYWOODF(ApplicationManager* pApp) :Action(pApp)
{
}

void bURLYWOODF::ReadActionParameters()
{
}

void bURLYWOODF::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntFillColor();

	UI.FillColor = BURLYWOOD;

	pOut->PrintMessage("Change the Fill Colour to BURLYWOOD");

	pManager->passfillcolor(BURLYWOOD);

}



