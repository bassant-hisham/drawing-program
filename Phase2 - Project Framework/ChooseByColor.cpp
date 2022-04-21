/*#include <iostream>
#include "ChooseByColor.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "SaveAction.h"
#include"Select.h"
#include"ApplicationManager.h"
#include "CMUgraphicsLib/colors.h"

using namespace std;



ChooseByColor::ChooseByColor(ApplicationManager* pApp) :Action(pApp)
{

}

void ChooseByColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//selecting a figurep.
	pOut->PrintMessage("Select a Figure");
	pIn->GetPointClicked(p.x, p.y);
	pManager->SelectFigure(p.x, p.y);
	color ColorOrgFig = pManager->GetOutput()->getCrntFillColor();
	return;
}

//Execute the action
void ChooseByColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int countValid = 0;
	int countInvalid = 0;
	float grade = 0;
	//This action needs to read s;ome parameters first
	ReadActionParameters();

	for (int i = 0; i < (pManager->getfigcount()); i++)
	{
		pIn->GetPointClicked(p.x, p.y);
		pManager->SelectFigure(p.x, p.y);
		pOut->PrintMessage("Select a Figure with the same colors");
		pIn->GetPointClicked(p.x, p.y);
		pManager->SelectFigure(p.x, p.y);
		color ColorSelectedFig = pManager->GetOutput()->getCrntFillColor();
		if (ColorSelectedFig == ColorOrgFig)
		{
			countValid++;
			pManager->GetOutput()->PrintMessage("The valid counts" + to_string(countValid) + "\t");
			pManager->GetOutput()->PrintMessage("The inValid counts " + to_string(countInvalid));
		}
		else
		{			countInvalid++;
		pManager->GetOutput()->PrintMessage("The valid counts" + to_string(countValid) + "\t");
		pManager->GetOutput()->PrintMessage("The inValid counts " + to_string(countInvalid));
	}
}
	
	pManager->GetOutput()->PrintMessage("The valid counts" + to_string(countValid) + "\t");
	pManager->GetOutput()->PrintMessage("The inValid counts " + to_string(countInvalid));
	grade = ((float)countValid / (countValid + countInvalid))*100;
	pManager->GetOutput()->PrintMessage("grade is" + to_string(grade));

}*/
