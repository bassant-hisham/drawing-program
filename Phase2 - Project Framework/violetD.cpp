#include "violetD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

violetD::violetD(ApplicationManager* pApp) :Action(pApp)
{
}

void violetD::ReadActionParameters()
{
}

void violetD::Execute()
{

	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
	UI.DrawColor= VIOLET;

	pOut->PrintMessage("Change the Draw Colour to VIOLET");


}
