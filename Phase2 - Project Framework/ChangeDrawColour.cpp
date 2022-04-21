#include"ChangeDrawColour.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
ChangeDrawColour::ChangeDrawColour(ApplicationManager* pApp) :Action(pApp)
{
}

void ChangeDrawColour::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Change the current Drawing Colour");
  
}

void ChangeDrawColour::Execute()
{
    Output* pOut = pManager->GetOutput();
    ReadActionParameters();
    pOut->ClearToolBar();
    pOut->CreatechoosecolorsbarD(); //choose the color you want 

}

int ChangeDrawColour::getnD()
{

    return n;
}
