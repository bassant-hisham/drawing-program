#include <iostream>
#include "choosebyarea.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "SaveAction.h"
#include"Select.h"
#include"ApplicationManager.h"

choosebyarea::choosebyarea(ApplicationManager* pApp) :Action(pApp)
{
}

void choosebyarea::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//selecting a figurep.
	pOut->PrintMessage(" type 's' for smallest or 'l' for largest area");
	s = pIn->GetSrting(pOut);
 	pOut->PrintMessage(" select the smallest or the largest area");
	pIn->GetPointClicked(p.x, p.y);
	pManager->SelectFigure(p.x, p.y);
	figure = pManager->GetFigure(p.x, p.y, &index);
	area = figure->getarea();


	double area1 = pManager->comparearea(s,&index);

	while (area1 != area)
	{
		pOut->PrintMessage(" select the smallest or the largest area"); 
		pIn->GetPointClicked(p.x, p.y);
		pManager->SelectFigure(p.x, p.y);
		figure = pManager->GetFigure(p.x, p.y, &index);
		area = figure->getarea();
		double area1 = pManager->comparearea(s,&index);
	}
	
	return;
}

//Execute the action
void choosebyarea::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int countValid = 0;
	int countInvalid = 0;
	float grade = 0;
	//This action needs to read some parameters first

	ReadActionParameters();
	int u = pManager->getfigcount();
	if (s == "s")
	{
	for (int i = 0; i < u; i++)
	{
		pOut->PrintMessage(" select next smallest area");
		pIn->GetPointClicked(p.x, p.y);
		pManager->SelectFigure(p.x, p.y);
		figure = pManager->GetFigure(p.x, p.y, &index);
		areaselected = figure->getarea();
		double area1 = pManager->comparearea(s,&index);
		
			if (area1==areaselected)
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

	
	}

	else if (s == "l")
	{
		for (int i = 0; i < u; i++)
		{
			pOut->PrintMessage(" select next the largest area");
			pIn->GetPointClicked(p.x, p.y);
			pManager->SelectFigure(p.x, p.y);
			figure = pManager->GetFigure(p.x, p.y, &index);
			areaselected = figure->getarea();
			double area1 = pManager->comparearea(s,&index);


			if (area1 == areaselected)
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
		
	}
	
	

 
	pOut->PrintMessage("The valid counts" + to_string(countValid) + "\t");
	pOut->PrintMessage("The inValid counts " + to_string(countInvalid));
	grade = ((float)countValid / (countValid + countInvalid)) * 100;
	pOut->PrintMessage("grade is" + to_string(grade));


}