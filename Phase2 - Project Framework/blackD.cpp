#include "blackD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

blackD::blackD(ApplicationManager* pApp) :Action(pApp)
{
}

void blackD::ReadActionParameters()
{
}

void blackD::Execute()
{

	Output* pOut = pManager->GetOutput();


	
	pOut->getCrntDrawColor();
	UI.DrawColor = BLACK;
	pOut->PrintMessage("Change the Draw Colour to BLACK");


}




