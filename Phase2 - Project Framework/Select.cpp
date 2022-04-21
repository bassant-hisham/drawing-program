#include"Select.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

Select::Select(ApplicationManager* pApp) : Action(pApp)
{
}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on the figure to be selected");
	pIn->GetPointClicked(P1.x, P1.y);

}

		void Select::Execute()
		{
			ReadActionParameters();
			Output* pOut = pManager->GetOutput();

			pManager->SelectFigure(P1.x, P1.y);
			
		}

