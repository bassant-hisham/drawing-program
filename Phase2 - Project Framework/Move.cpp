#include "Move.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
Move::Move(ApplicationManager* pApp) : Action(pApp)
{
}

void Move::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selct the figure you want to Move ");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Selct the Point you want the figure to Move to ");
	pIn->GetPointClicked(p2.x, p2.y);

}

void Move::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->SelectFigure(P1.x, P1.y);
	int index = 0;
	CFigure* c = pManager->GetFigure(P1.x, P1.y, &index);
	c->SetSelected(false);
	pManager->DecrementSelectedCount();
	pManager->MoveFigure(p2, c, &index);
}
