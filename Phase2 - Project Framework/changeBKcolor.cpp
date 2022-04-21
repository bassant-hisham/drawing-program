#include "changeBKcolor.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
changeBKcolor::changeBKcolor(ApplicationManager* pApp):Action(pApp)
{
}

void changeBKcolor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Change the current background Colour");
   
}

void changeBKcolor::Execute()
{
  
    Output* pOut = pManager->GetOutput();
    ReadActionParameters();
    pOut->ClearToolBar();
    pOut->CreatechoosecolorsbarB();
    

   
}

