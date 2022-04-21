#include "ChangeColoursAction.h"

#include"ApplicationManager.h"

#include"GUI\Input.h"
#include"GUI/Output.h"

ChangeColoursAction::ChangeColoursAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChangeColoursAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Change to Colours Tool Bar");
	

}

void ChangeColoursAction::Execute()
{
	ReadActionParameters();
	Output* pOut= pManager->GetOutput();
	pOut-> ClearToolBar();
	pOut->createChangeColorBar();//go to change color bar to change fill,bk.draw colors
}

