#include "LoadAction.h"
#include "fstream"

#include "ApplicationManager.h"
using namespace std;

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Input a filename:");
	filename = pIn->GetSrting(pOut);
	filename += ".txt";
	pOut->ClearStatusBar();


}

//Execute the action

	void LoadAction::Execute()
	{
		//This action needs to read some parameters first
		ReadActionParameters();

		ifstream Infile;
		Infile.open(filename, ios::in);
		if (!(Infile.is_open()))
		{
			pManager->GetOutput()->PrintMessage("error in loading the file");
			return;

		}
		else
		{
			pManager->GetOutput()->PrintMessage("File is loaded" + filename);
			Infile.close();
		}
		pManager->LoadAll(Infile);
		pManager->UpdateInterface();
		return;
	}
