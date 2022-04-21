#include "violetF.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

violetF::violetF(ApplicationManager* pApp) :Action(pApp)
{
}

void violetF::ReadActionParameters()
{
}

void violetF::Execute()
{

	Output* pOut = pManager->GetOutput();
	pOut->getCrntFillColor();

	UI.FillColor = VIOLET;

	pOut->PrintMessage("Change the Fill Colour to VIOLET");
	pManager->passfillcolor(VIOLET);

}





