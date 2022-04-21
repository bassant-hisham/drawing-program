 #include "SaveAction.h"
#include "fstream"

#include "ApplicationManager.h"
using namespace std;

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Read the filnemae from the user
	pOut->PrintMessage("Input a filename:");
	filename = pIn->GetSrting(pOut);
	filename += ".txt";
	pOut->ClearStatusBar();

}

//Execute the action

 void SaveAction::Execute()
	{
		//This action needs to read some parameters first
		ReadActionParameters();
		ofstream Outfile;  //fstream is ofstream is a data type represents the output file stream to create file and ifstream that represents the input of the file stream
		//open a file
		Outfile.open(filename, ios::out | ios::trunc); //ios-out to open a file for writing
		if (!Outfile)
		{
			pManager->GetOutput()->PrintMessage("error");
			return;
		}
		else
		{
			pManager->GetOutput()->PrintMessage("Figure is saved" + filename);
			pManager->SaveAll(Outfile);
		}
		Outfile.close();
		return;
	}
	

