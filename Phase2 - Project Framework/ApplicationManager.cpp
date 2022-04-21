#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"  
#include "AddFigAction.h"
#include "AddLineAction.h"
#include "AddCircAction.h"
#include "AddTriAction.h"

#include"SaveAction.h"
#include"LoadAction.h"
#include"Select.h"
#include"CutAction.h"
#include"CopyAction.h"
#include "PasteAction.h"
#include"ToPlayAction.h"
#include"To_DrawAction2.h"
#include"To_DrawAction.h"
#include"Move.h"
#include"zoomAction.h"
#include"ResizeAction.h"
#include"ExitAction.h"

#include"Ccirc.h"
#include"CLine.h"
#include"CTriangle.h"
#include"Figures/CRectangle.h"

#include"ChangeColoursAction.h"
#include"ChangeDrawColour.h"
#include"ChangeFillColour.h"
#include"changeBKcolor.h"
#include"switchtocoloraction.h"
#include"ChooseByColor.h"
#include"choosebyarea.h"
//#include"chosebytypeandcolor.h"

#include"DrawingArea.h"
#include"ToPlayAction.h"
#include"DeleteAction.h"

#include"bURLYWOODB.h"
#include"gAINSBOROB.h"
#include"lEMONCHIFFONB.h"
#include"pINKB.h"
#include"tHISTLEB.h"
#include"violetB.h"
#include"whiteB.h"

#include"lIGHTSKYBLUEB.h"

#include"blackD.h"
#include"bURLYWOODD.h"
#include"gAINSBOROD.h"
#include"gOLDENRODD.h"

#include"pINKD.h"
#include"whiteD.h"
#include"tHISTLED.h"
#include"violetD.h"

#include"bURLYWOODF.h"
#include"gAINSBOROF.h"
#include"tHISTLEF.h"
#include"pINKF.h"
#include"gOLDENRODF.h"
#include"violetF.h"
#include"lIGHTSKYBLUEF.h"
#include"whiteF.h"
#include"ChooseByType.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedCount = 0;
	Pastedfigures = 0;
	ClipboardMembersCount = 0;
	q = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	                
	for (int i = 0; i < MaxFigCount; i++)
		PastingList[i] = NULL;
	for (int i = 0; i < MaxFigCount; i++)
		ClipboardList[i] = NULL;

	
	
}



//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() 
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
    
	for (int i = 0; i < FigCount; i++)
	{
		if (i >= index)
			FigList[i]->ChngFillClr(UI.FillColor);
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		
	}
	
}


////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}



////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_FIGURES:
		pAct = new AddFigAction(this);
		break;
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	case SWITCH_TO_COLOR:
			pAct = new switchtocoloraction(this);
			break;
	case DRAWING_AREA:
			pAct = new DrawingArea(this);
				break;
	case TO_DRAW2:
		pAct = new To_DrawAction2(this);
		break;
	case TO_DRAW:
		pAct = new To_DrawAction(this);
		break;

    case TO_PLAY:
			pAct = new ToPlayAction(this);
			break;
	case SELECT:
			pAct = new Select(this);
			break;
	case CHOOSE_BY_TYPE:
			pAct = new ChooseByType(this);
			break;
	case CHOOSE_BY_AREA:
		pAct = new choosebyarea(this);
		break;
	//case CHOOSE_BY_COLOUR:
		//pAct = new ChooseByColor(this);
		//break;
	//case CHOOSE_BY_TYPE_AND_COLUR:
		//pAct = new choosebytypeandcolor(this);
		//break;
	case SAVE:
			pAct = new SaveAction(this);
			break;
	case LOAD:
			pAct = new LoadAction(this);
			break;
	case DEL:
			pAct = new DeleteAction(this);
			break;
	case CHANGE_COLOR_BAR:
		pAct = new ChangeColoursAction(this);
		break;
	case CHNG_DRAW_CLR:
		pAct = new ChangeDrawColour(this);
		break;

	case CHNG_BK_CLR:
		pAct = new changeBKcolor(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChangeFillColour(this);
		break;

	case BURLYWOODB:
		pAct = new bURLYWOODB(this);
		break;
	case GAINSBOROB:
		pAct = new gAINSBOROB(this);
		break;
	case LEMONCHIFFONB:
		pAct = new lEMONCHIFFONB(this);
		break;
	case PINKB:
		pAct = new pINKB(this);
		break;
	case THISTLEB:
		pAct = new tHISTLEB(this);
		break;
	case VioletB:
		pAct = new violetB(this);
		break;
	case WhiteB:
		pAct = new whiteB(this);
		break;
	case LIGHTSKYBLUEB:
		pAct = new lIGHTSKYBLUEB(this);
		break;

	case BlackD:
		pAct = new blackD(this);
		break;
	case BURLYWOODD:
		pAct = new bURLYWOODD(this);
		break;
	case GAINSBOROD:
		pAct = new gAINSBOROD(this);
		break;
	case PINKD:
		pAct = new pINKD(this);
		break;
	case GOLDENRODD:
		pAct= new gOLDENRODF(this);
	case THISTLED:
		pAct = new tHISTLED(this);
		break;
	case WhiteD:
		pAct = new whiteD(this);
		break;
	case VioletD:
		pAct = new violetD(this);
		break;


	case BURLYWOODF:
		pAct = new bURLYWOODF(this);
		break;
	case GAINSBOROF:
		pAct = new gAINSBOROF(this);
		break;;
	case GOLDENRODF:
		pAct = new gOLDENRODF(this);
		break;
	case PINKF:
		pAct = new pINKF(this);
		break;
	case THISTLEF:
		pAct = new tHISTLEF(this);
		break;
	case WhiteF:
		pAct = new whiteF (this);
		break;
	case VioletF:
		pAct = new violetF(this);
		break;
	case LIGHTSKYBLUEF:
		pAct = new lIGHTSKYBLUEF(this);
		break;

	case COPY:
		pAct = new CopyAction(this);
		break;
	case CUT:
		pAct = new CutAction(this);
		break;
	case MOVE:
		pAct = new Move(this);
		break;
	case PASTE:
		pAct = new PasteAction(this);
		break;
	case RESIZE:
		pAct = new ResizeAction(this);
		break;
	case ZOOM_IN_OUT:
		pAct = new zoomAction(this);
		break;
	case EXIT:
		pAct = new ExitAction(this);
		break;
	}


	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		
			delete pAct;	//Action is not needed any more ==> delete it
			pAct = NULL;
		
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig; //figures ID
	SetIDofFigures();
}
int ApplicationManager::getfigcount()
{
	return FigCount;
}

CFigure* ApplicationManager::GetFigure(int x, int y,int *index) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	int c = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->InsideArea(x, y))
		{
			*index = i;
			c++;
			return FigList[i];
		}
	}
	// if no figure is selected, parameteres won't be found in the figlist, so NULL is returned
	//indicating that nothing is selected
	if (c == 0)
		return NULL;
}
void ApplicationManager::SelectFigure(int x, int y)
{
	int index=0;
	CFigure* SelectedFig = GetFigure(x, y, & index);
	pOut = GetOutput();
	int c = 0;
	if (SelectedFig == NULL)
		c++;
	//if it is not selected yet, select it and increment the count by one
	
	else if (SelectedFig->IsSelected() == false)
	{
		SelectedFig->SetSelected(true);
		SelectedCount++;
	}
	//If user selected already selected figure, unselect it
	else
	{
		SelectedFig->SetSelected(false);
		SelectedCount--;
	}

	//if the selected figures are one only, print its info
	if (SelectedCount == 1)
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsSelected()==true)
			{
				FigList[i]->PrintInfo(pOut);
				break;
			}
		}
	}
	else if (c != 0)
	{
		pOut->PrintMessage("No Figure is selected. Click on the Select icon again and Select another figure.");
	}

	//if many selected print their number
	else pOut->PrintMessage("The number of selected figures=" + to_string(SelectedCount));

}

////////////////////////////////////////////////////////////////////////////////////



	///Add your code here to search for a figure given a point x,y	

	//return NULL;
//}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface


void ApplicationManager::DeleteFigure()
{
	
	int j = 0;
	for (int i = 0; i < FigCount; i++) //delete selected figures
	{
		
			if (FigList[i]->IsSelected())
			{
				
				delete FigList[i];
				FigList[i] = NULL;
				
			}
		
		
	}
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)   //put undeleted figures in new array
		{
			FigList[j] = FigList[i]; 
			j++;
		}
	}
	FigCount = j;
}

void ApplicationManager::CopyFigure()
{
	// Clear the figures from the clipboard
	ClearClipboard();
	ClipboardMembersCount = 0;
	int c = 0;
	q = 1;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == 1)
		{
			ClipboardList[c] = FigList[i];
			c++;
			ClipboardMembersCount++;
		}
	}
}

void ApplicationManager::ClearClipboard()
{
	if (ClipboardMembersCount != 0)
	{
		int c = ClipboardMembersCount;
		for (int i = 0; i < c; i++)
		{
			ClipboardList[i] = NULL;
			ClipboardMembersCount--;
		}
	}

}
void ApplicationManager::CutFigure()
{
	ClearClipboard();
	ClipboardMembersCount = 0;
	int c = 0;
	q = 2;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == 1)
		{
			ClipboardList[c] = FigList[i]->Copy();
			ClipboardMembersCount++;
			c++;
			SelectedCount--;
		}
	}
	DeleteFigure();
}

int ApplicationManager::GetSelectedCount()
{
	return SelectedCount;
}


int ApplicationManager::GetClipBoardCount()
{
	return ClipboardMembersCount;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}

void ApplicationManager::MoveFigure(Point P,CFigure*c,int *index)
{
	if (c != NULL)
	{
	 	c->Move(P);       //every object call its move function
		FigList[*index] = c;  // put the new figure in the loaction of the old  one
	}
	else return;
}

void ApplicationManager::ResizeFigure(string size, CFigure* c, int* index)
{
	if (c != NULL)
	{
		c->Resize(size);   
		DeleteFigure();  //delete the old figure 
		FigList[*index] = c; // put the new figure in the loaction of the old  one
		DecrementSelectedCount();


	}
	else return;
}
void ApplicationManager::zoomfigures(CFigure* c, int* index)
{
	if (c != NULL)

	{
		c->zoom(n);
		FigList[*index] = c;
		n++;

		if (n == 2)
		{
			c->zoom(n);
			FigList[*index] = c;
			n = 0;
		}


	}
}

bool ApplicationManager::UserSelecting()
{
	if (SelectedCount >= 2)
		return true;
	else false;
}

int ApplicationManager::passfillcolor(color u)
{
	
	UI.FillColor = u;
	index = FigCount;
	return index;
}



void ApplicationManager::SaveAll(ofstream& Outfile)
{
	Outfile << FigCount << "\n";
	/*Output << pOut->savedrawcolor(pOut-> getCrntDrawColor()) << "  ";
	Output << pOut->savefillcolor(pOut->getCrntFillColor()) << "  ";
	Output << pOOut->saveBkcolor(pOut->getCrnetBkcolor()) << "  ";*/
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(Outfile, pOut);
	}
}
void ApplicationManager::LoadAll(ifstream& Infile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(1);
	}
	DeleteFigure();
	CFigure* LoadedFig = NULL;
	for (int i = 0; i < FigCount; i++)
	{
		string figureTyp;
		Infile >> figureTyp;
		if (figureTyp == "RECT")
			LoadedFig = new CRectangle();
		else if (figureTyp == "TRIANG")
			LoadedFig = new CTriangle();
		else if (figureTyp == "CIRC")
			LoadedFig = new Ccirc();
		else if (figureTyp == "LINE")
			LoadedFig = new CLine();
		LoadedFig->Load(Infile, pOut);
		AddFigure(LoadedFig);
	}

}
Type ApplicationManager::GetType(int x, int y) 
{
	int index = 0;
	CFigure* F = GetFigure(x, y, &index);
	return F->GetFigType();
	
}

void ApplicationManager::PasteFigure()
{
		pOut = GetOutput();
		pIn = GetInput();
		int index = 0;
		Pastedfigures = 0;

		if (q == 2) // if last figures were cut
		{
			Point P;

			pOut->PrintMessage("Pasting Cut Figures: Click on the new location");
			pIn->GetPointClicked(P.x, P.y);

			for (int i = 0; i < ClipboardMembersCount; i++)
			{
				PastingList[i] = ClipboardList[i]->Copy();
				Pastedfigures++;
				PastingList[i]->Move(P);
			}
			for (int i = 0; i < ClipboardMembersCount; i++)
			{
				FigList[FigCount] = PastingList[i];
				FigCount++;
			}
		}
		else if (q == 1)   //if last figures were copied
		{
			Point P;
			pOut->PrintMessage("Pasting Copied Figures: Click on the new location");
			pIn->GetPointClicked(P.x, P.y);

			for (int i = 0; i < ClipboardMembersCount; i++)
			{
				ClipboardList[i]->SetSelected(0);
				PastingList[i] = ClipboardList[i]->Copy();
				Pastedfigures++;
				PastingList[i]->Move(P);
			}
			for (int i = 0; i < ClipboardMembersCount; i++)
			{
				FigList[FigCount] = PastingList[i];
				FigCount++;
			}
		}
		else pOut->PrintMessage(" No Figures in clipboard to be pasted ");
	
}
/*string ApplicationManager::colors(color u)
{

	if (u == RED)
		return "RED";
	else if (u == BURLYWOOD)
		return "BURLYWOOD";
	else if (u == GAINSBORO)
		return "GAINSBORO";
	else if (u == GOLDENROD)
		return"GOLDENROD";
	else if (u == LIGHTSKYBLUE)
		return"LIGHTSKYBLUE";
	else if (u == PINK)
		return"PINK";
	else if (u == THISTLE)
		return"THISTLE";
	else if (u == VIOLET)
		return"VIOLET";
	else if (u == WHITE)
		return"WHITE";
	else
		return "NO FILL";

}*/
void ApplicationManager::SetIDofFigures() const
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetID(i + 1);
	}
}
void ApplicationManager::DecrementSelectedCount()
{
		SelectedCount--;
}
int ApplicationManager::GetPastedFiguresCount()
{
	return Pastedfigures;
}
void ApplicationManager::Exit(string Answer)
{
	Action* pAct;
	if (Answer == "no")
	{
		pAct = new SaveAction(this);
		pAct->Execute();
	}
}
void ApplicationManager::savedrawgraph()
{
	Action* pAct;
	pAct = new SaveAction(this);
		pAct->Execute();
}
void ApplicationManager::getdrawgraph()
{
	Action* pAct;
	pAct = new LoadAction(this);
	pAct->Execute();
}
double ApplicationManager::comparearea(string s,int *index)
{
	double area1;
	double area;
	if (s == "s")
	{
		area1= FigList[*index]->getarea();
		for (int i = 0; i < FigCount; i++)
		{
			area = FigList[i]->getarea();
			if (area < area1)
			{
				area1 = area;
				*index = i;
			}
		}
		return area1;
	}
	else if (s == "l")
	{
		area1 = FigList[*index]->getarea();
		for (int i = 0; i < FigCount; i++)
		{
			area = FigList[i]->getarea();
			if (area > area1)
			{
				area1 = area;
				*index = i;
			}
		}
		return area1;

	}

}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
	ApplicationManager::~ApplicationManager()
	{
		for (int i = 0; i < FigCount; i++)
			delete FigList[i];
		delete pIn;
		delete pOut;

	}