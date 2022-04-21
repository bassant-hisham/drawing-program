#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include "..\defs.h"
#include "..\GUI\Output.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	GfxInfo RectGfxInfo;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	//void setid(int n);
	//int getid();
	virtual bool InsideArea(int x, int y) const;
	virtual void Save(ofstream& Outfile, Output* pOut);
	virtual void Load(ifstream& Infile, Output* pOut);
	virtual void Move(Point P);
	virtual CFigure* Copy();
	virtual void zoom(int);
	virtual void Resize(string size);
	void PrintInfo(Output* pOut);
	virtual Type GetFigType();
	virtual double getarea();
};

#endif