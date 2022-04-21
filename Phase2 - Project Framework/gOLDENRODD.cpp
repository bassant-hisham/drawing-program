#include "gOLDENRODD.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

gOLDENRODD::gOLDENRODD(ApplicationManager* pApp) :Action(pApp)
{
}

void gOLDENRODD::ReadActionParameters()
{
}

void gOLDENRODD::Execute()
{
	
	Output* pOut = pManager->GetOutput();

	pOut->getCrntDrawColor();
		UI.DrawColor = GOLDENROD;
		
		pOut->PrintMessage("Change the Draw Colour to GOLDENROD");
	   
		
}


	

