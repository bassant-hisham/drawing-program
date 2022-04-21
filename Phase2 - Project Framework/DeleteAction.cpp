#include "DeleteAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Delete the selected figures");
}

void DeleteAction::Execute()
{
	ReadActionParameters();
	 pManager->DeleteFigure();
}
