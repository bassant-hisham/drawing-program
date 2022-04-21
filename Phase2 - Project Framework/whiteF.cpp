#include "whiteF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

whiteF::whiteF(ApplicationManager* pApp) :Action(pApp)
{
}

void whiteF::ReadActionParameters()
{
}

void whiteF::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntFillColor();
	UI.FillColor = WHITE;

	pOut->PrintMessage("Change the Fill Colour to WHITE");
	pManager->passfillcolor(WHITE);

}




