#include"switchtocoloraction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

switchtocoloraction::switchtocoloraction(ApplicationManager* pApp) : Action(pApp)
{
}

void switchtocoloraction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("return to play toolbar");
}

void switchtocoloraction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->createChangeColorBar();
}
