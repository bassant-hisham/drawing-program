#pragma once
#include "zoomAction.h""
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

zoomAction::zoomAction(ApplicationManager* pApp) : Action(pApp)
{
}

void zoomAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selct the figure you want to zoom in_out ");
	pIn->GetPointClicked(p1.x, p1.y);


}

void zoomAction::Execute()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->SelectFigure(p1.x, p1.y);
	int index = 0;
	CFigure* c = pManager->GetFigure(p1.x, p1.y, &index);
	c->SetSelected(false);
	pManager->zoomfigures( c, &index);
}

