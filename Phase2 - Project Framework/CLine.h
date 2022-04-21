#pragma once
#ifndef CLINE_H
#define CLINE_H

#include "Figures/CFigure.h"

#include "CMUgraphicsLib/colors.h"
class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	GfxInfo Line;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	CLine();
	virtual void Draw(Output* pOut) const;
	virtual bool InsideArea(int x, int y) const;
	void Load(ifstream& Infile, Output* pOut);
	void Save(ofstream& Outfile, Output* pOut);
	virtual void Move(Point P);
	virtual CFigure* Copy();
	virtual void Resize(string size);
	void zoom(int );
	void PrintInfo(Output* pOut);
	virtual Type GetFigType();
	virtual double getarea();
};


#endif