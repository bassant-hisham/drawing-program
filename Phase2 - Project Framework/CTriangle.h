#pragma once
#ifndef CTRI_H
#define CTRI_H

#include "Figures/CFigure.h"
#include "CMUgraphicsLib/colors.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	GfxInfo TriGfxInfo;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool InsideArea(int x, int y) const;
	void ChngFillClr(color Fclr);
	void Save(ofstream& Outfile, Output* pOut);
	void Load(ifstream& Infile, Output* pOut);
	virtual void Move(Point P);
	virtual CFigure* Copy();
	virtual void Resize(string);
	virtual void zoom(int);
	void PrintInfo(Output* pOut);
	virtual Type GetFigType();
	virtual double getarea();
};

#endif