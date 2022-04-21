#include "bURLYWOODB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

bURLYWOODB::bURLYWOODB(ApplicationManager* pApp) :Action(pApp)
{
}

void bURLYWOODB::ReadActionParameters()
{
}

void bURLYWOODB::Execute()
{

	Output* pOut = pManager->GetOutput();
	UI.BkGrndColor = pOut->getBkcolor();
	UI.BkGrndColor = BURLYWOOD;
	pOut->PrintMessage("Change the Background Colour to BURLYWOOD");


}



