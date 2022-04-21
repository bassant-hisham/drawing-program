
#include "bURLYWOODD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

bURLYWOODD::bURLYWOODD(ApplicationManager* pApp) :Action(pApp)
{
}

void bURLYWOODD::ReadActionParameters()
{
}

void bURLYWOODD::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	UI.DrawColor = BURLYWOOD;

	pOut->PrintMessage("Change the Draw Colour to BURLYWOOD");


}



