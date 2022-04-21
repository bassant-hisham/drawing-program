#include "DrawingArea.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
DrawingArea::DrawingArea(ApplicationManager* pApp) :Action(pApp)
{
}

void DrawingArea::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("A Click on Empty Place on the drawing area");
}

void DrawingArea::Execute()
{
	ReadActionParameters();
}











