#include "ChangeFillColour.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
ChangeFillColour::ChangeFillColour(ApplicationManager* pApp) :Action(pApp)
{
   
}

void ChangeFillColour::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Change the current FillColour");
}

void ChangeFillColour::Execute()
{
    Output* pOut = pManager->GetOutput();
    ReadActionParameters();
    pOut->ClearToolBar();
    pOut->CreatechoosecolorsbarF();

}



