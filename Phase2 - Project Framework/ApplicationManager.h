#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];
	CFigure* LoadList[MaxFigCount];	//List of all figures (Array of pointers)
	int SelectedCount;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int index=201;
	int ClipboardMembersCount;
	CFigure* ClipboardList[MaxFigCount];
	CFigure* PastingList[MaxFigCount];  // List of figures being pasted
	int Pastedfigures; //number of pasted figires
	int q;
	int n = 0;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction();
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y,int *index) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SelectFigure(int x, int y);
	void DeleteFigure();
	bool UserSelecting();
	Type GetType(int x, int y) const;
	int passfillcolor(color u);
	void CopyFigure();
	void CutFigure();
	void ClearClipboard();
	int GetSelectedCount();
	int GetClipBoardCount();
	int GetFigCount();
	void MoveFigure(Point P,CFigure* c,int *index);
	void ResizeFigure(string size, CFigure* c, int* index);
	void zoomfigures( CFigure* c, int* index);
	string colors(color u);
	void SetIDofFigures() const;
	int getfigcount();
	void SaveAll(ofstream& Outfile);
   void LoadAll(ifstream& Infile);
    void PasteFigure();
    void DecrementSelectedCount();
    int GetPastedFiguresCount();
	Type GetType(int x, int y) ;
	void Exit(string);
	void savedrawgraph();
	void getdrawgraph();
	double comparearea(string,int*);
};

#endif