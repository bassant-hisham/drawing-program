#include "whiteB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

whiteB::whiteB(ApplicationManager* pApp) :Action(pApp)
{
}

void whiteB::ReadActionParameters()
{
}

void whiteB::Execute()
{

	Output* pOut = pManager->GetOutput();

	UI.BkGrndColor = pOut->getBkcolor();
	UI.BkGrndColor = WHITE;

	pOut->PrintMessage("Change the BkGrnd Colour to White");


}





