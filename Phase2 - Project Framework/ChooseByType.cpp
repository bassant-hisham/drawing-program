#include <iostream>
#include "ChooseByType.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "SaveAction.h"
#include"Select.h"
#include"ApplicationManager.h"



ChooseByType::ChooseByType(ApplicationManager* pApp) :Action(pApp)
{
}

void ChooseByType::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//selecting a figurep.
	pOut->PrintMessage("Click on the figure to be selected");
	pIn->GetPointClicked(p.x, p.y);
	pManager->SelectFigure(p.x, p.y);
	T = pManager->GetType(p.x, p.y);
	pManager->CutFigure();


	

	//pManager->DeleteFigure();
	return;
}

//Execute the action
void ChooseByType::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int countValid = 0;
	int countInvalid = 0;
	float grade = 0;
	//This action needs to read some parameters first

	ReadActionParameters();

		switch (T)
		{
		case(rectangle):
			pManager->GetOutput()->PrintMessage("Select Rectangles");
			break;
		case(triangle):
			pManager->GetOutput()->PrintMessage("Select Traingles");
			break;
		case(line):
			pManager->GetOutput()->PrintMessage("Select Lines");
			break;
		case(circle):
			pManager->GetOutput()->PrintMessage("Select Circles");
			break;
		}
	for (int i = 0; i < (pManager->getfigcount()); i++)
	{

			pIn->GetPointClicked(p.x, p.y);
			pManager->SelectFigure(p.x, p.y);
		   TSelected = pManager->GetType(p.x, p.y);
		   

		if (T == TSelected)
		{
			countValid++;
			pOut->PrintMessage("The valid counts" + to_string(countValid) + "\t");
		}
		else 
		{
			countInvalid++;
			pOut->PrintMessage("The inValid counts " + to_string(countInvalid));
		}
	}
    pOut->PrintMessage("The valid counts" + to_string(countValid) + "\t");
	pOut->PrintMessage("The inValid counts " + to_string(countInvalid));
	grade= ((float)countValid / (countValid + countInvalid))*100;
	pOut->PrintMessage("grade is" + to_string(grade));


}