#include "ResizeAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#pragma once
ResizeAction::ResizeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selct the figure you want to resize ");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->PrintMessage("enter the size you want");
	size = pIn->GetSrting(pOut);

}

void ResizeAction::Execute()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->SelectFigure(p1.x, p1.y);
	int index = 0;
	CFigure* c = pManager->GetFigure(p1.x, p1.y, &index);
	c->SetSelected(false);
	pManager->ResizeFigure(size, c, &index);
}

