#include "AddLineAction.h"
#include "CLine.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddLineAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second corner");
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = false;

	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddLineAction::Execute()
{
	ReadActionParameters();
	CLine* L = new CLine(P1, P2, LineGfxInfo);
	pManager->AddFigure(L);
}
