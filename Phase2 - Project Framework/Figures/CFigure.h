#ifndef CFIGURE_H
#define CFIGURE_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
enum Type
{
	rectangle,
	line,
	circle,
	triangle
	
};
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);//color Fclr);	//changes the figure's filling color
	int GetID();
	void SetID(int i);
	virtual bool InsideArea(int x, int y)const=0 ;
	
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	virtual void Move(Point P) = 0;		//Move the figure

	virtual void Save(ofstream &OutFile,Output*pOut) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile,Output* pOut) = 0;	//Load the figure parameters to the file
	virtual CFigure* Copy() = 0;
	void virtual Resize(string) = 0;
	void virtual zoom(int )=0;
	CFigure();
	virtual Type GetFigType() = 0;
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual double getarea()=0;
};

#endif