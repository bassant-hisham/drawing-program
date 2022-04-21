#include "violetB.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Ccirc.h"

violetB::violetB(ApplicationManager* pApp) :Action(pApp)
{
}

void violetB::ReadActionParameters()
{
}

void violetB::Execute()
{

	Output* pOut = pManager->GetOutput();

	
	UI.BkGrndColor=pOut->getBkcolor();
	pOut->setBKcolor(VIOLET);
	pOut->PrintMessage("Change the Background Colour to VIOLET");


}




