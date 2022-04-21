#include "tHISTLED.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

tHISTLED::tHISTLED(ApplicationManager* pApp) :Action(pApp)
{
}

void tHISTLED::ReadActionParameters()
{
}

void tHISTLED::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	UI.DrawColor= THISTLE;

	pOut->PrintMessage("Change the Draw Colour to  THISTLE");


}






