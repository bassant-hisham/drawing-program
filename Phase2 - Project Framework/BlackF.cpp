#include "BlackF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

BlackF::BlackF(ApplicationManager* pApp) :Action(pApp)
{
}

void BlackF::ReadActionParameters()
{
}

void BlackF::Execute()
{

	Output* pOut = pManager->GetOutput();

	UI.FillColor = BLACK;

	pOut->PrintMessage("Change the Fill Colour to BLACK");


}




