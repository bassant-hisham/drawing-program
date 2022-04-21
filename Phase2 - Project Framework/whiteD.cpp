#include "whiteD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

whiteD::whiteD(ApplicationManager* pApp) :Action(pApp)
{
}

void whiteD::ReadActionParameters()
{
}

void whiteD::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	pOut->setdrawcolor(WHITE);

	pOut->PrintMessage("Change the Draw Colour to WHITE");


}



