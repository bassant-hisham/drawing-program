#include "AddCircAction.h"
#include "Ccirc.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"WhiteF.h"

AddCircAction::AddCircAction(ApplicationManager* pApp): Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at centre");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point");
	pIn->GetPointClicked(P2.x, P2.y);
		CircGfxInfo.isFilled = false;
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddCircAction::Execute()
{
	ReadActionParameters();

	Ccirc* C = new Ccirc(P1, P2, CircGfxInfo);

	pManager->AddFigure(C);
}


