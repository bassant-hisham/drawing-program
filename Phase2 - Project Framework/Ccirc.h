#ifndef  CCIRC_H
#define CCIRC_H

#include "Figures/CFigure.h"
#include "GUI/Output.h"
#include"DEFS.h"


class Ccirc : public CFigure
{
private:
	Point centre;
	Point radius;
	GfxInfo CircGfxInfo;
public:
	Ccirc(Point, Point, GfxInfo FigureGfxInfo);
	Ccirc();
	virtual void Draw(Output* pOut) const;
	void ChngFillClr(color Fclr);
	//void ChngDrawClr(color Dclr);
	virtual bool InsideArea(int x, int y) const;
	void Load(ifstream& Infile, Output* pOut);
	void Save(ofstream& Outfile, Output* pOut);
	virtual void Move(Point p);
	virtual CFigure* Copy();
	virtual void Resize(string size);
	void PrintInfo(Output* pOut);
	virtual void zoom(int n);
	virtual Type GetFigType();
	virtual double getarea();
	
};


#endif