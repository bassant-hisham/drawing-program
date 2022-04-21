#include "CLine.h"
#include <fstream>
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
CLine::CLine(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
}
CLine::CLine()
{

}

void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CLine::InsideArea(int x, int y) const
{
	Point Left;
	Point Right;
	if (Corner1.x <= Corner2.x)
	{
		Left.x = Corner1.x;
		Right.x = Corner2.x;
	}
	else
	{
		Left.x = Corner2.x;
		Right.x = Corner1.x;
	}
	if (Corner1.y > Corner2.y)
	{
		Left.y = Corner1.y;
		Right.y = Corner2.y;
	}
	else
	{
		Left.y = Corner2.y;
		Right.y = Corner1.y;

	}
	Point q;
	q.x = x;
	q.y = y;
	if (q.x >= Left.x && q.x <= Right.x && q.y <= Left.y && q.y >= Right.y)
		return true;
	else return false;

}
void CLine::Save(ofstream& Outfile, Output* pOut)
{
	Outfile << "LINE" << "  ";
	Outfile << GetID() << "  ";
	Outfile << Corner1.x << "  ";
	Outfile << Corner1.y << "  ";
	Outfile << Corner2.x << "  ";
	Outfile << Corner2.y << "  ";
	//Outfile << pOut->savedrawcolor(FigGfxInfo.DrawClr); //Writing the draw color of the Line
	if (FigGfxInfo.isFilled == true) //Seeing whether it is filled or not
	{
		//Outfile << pOut->savefillcolor(FigGfxInfo.FillClr); //if filled ,write the fill color
		return;
	}
	else
		Outfile << "NO_FIll \n";  //It is not filled,write No fill
}
void CLine::Load(ifstream& Infile, Output* pOut)
{
	Infile >> ID;
	Infile >> Corner1.x;
	Infile >> Corner1.y;
	Infile >> Corner2.x;
	Infile >> Corner2.y;
	string fill;
	string color;
	Infile >> color;
	//FigGfxInfo.DrawClr = pOut->loaddrawcolor(color);
	Infile >> fill;
	if (fill == "NO FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		//FigGfxInfo.FillClr = pOut->loadfillcolor(fill);
	}

}
void CLine::Move(Point p)
{
	//determine the left and right corners
	Point Left;
	Point Right;
	if (Corner1.x <= Corner2.x)
	{
		Left.x = Corner1.x;
		Right.x = Corner2.x;
	}
	else
	{
		Left.x = Corner2.x;
		Right.x = Corner1.x;
	}
	if (Corner1.y > Corner2.y)
	{
		Left.y = Corner1.y;
		Right.y = Corner2.y;
	}
	else
	{
		Left.y = Corner2.y;
		Right.y = Corner1.y;
	}
	int D1 = (((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	int D2 = (((p.x - Right.x) * (p.x - Right.x)) + ((p.y - Right.x) * (p.y - Right.y)));
	//int slope = (Right.x - Left.x) / (Corner1.y - Corner2.y);

	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{

			if (((((i - p.x) * (i - p.x)) + ((j - p.y) * (j - p.y))) == D1) && (((i - Left.x) * (i - Left.x)) + ((j - Left.y) * (j - Left.y)) == D2))
			{
				Left.x = i;
				Left.y = j;
				Right.x = p.x;
				Right.y = p.y;
				break;
			}
		}
	}
	int delta1 = Right.x - Left.x;
	int delta2 = Right.y - Left.y;
	int i = p.x + delta1;
	int j = p.y + delta2;
	p.x = Right.x;
	p.y = Right.y;
	i = Left.x;
	j = Left.y;
	


	
		if (Corner1.x < Corner2.x)
		{
			  Corner1.x= Left.x;
			 Corner2.x= Right.x;
		}
		else
		{
			 Corner2.x= Left.x;
			 Corner1.x= Right.x;
		}
		if (Corner1.y > Corner2.y)
		{
			 Corner1.y= Left.y;
			Corner2.y= Right.y;
		}
		else
		{
			 Corner2.y= Left.y;
			 Corner1.y= Right.y;
		}
}
CFigure* CLine::Copy()
{
	CLine* L = new CLine(Corner1, Corner2, FigGfxInfo);
	return L;
}
void CLine::Resize(string size)
	{


		if (size == "1/2")
		{
			Corner2.x = (Corner1.x + Corner2.x) / 2;
			Corner2.y = (Corner1.y + Corner2.y) / 2;
		}
		if (size == "1/4")
		{
			Corner2.x = (Corner1.x + Corner2.x) / 4;
			Corner1.y = (Corner1.y + Corner2.y) / 4;

		}
		if (size == "2")
		{
			Corner2.x = 2 * Corner2.x - Corner1.x;
			Corner2.y = 2 * Corner2.y - Corner1.y;
		}
		if (size == "4")
		{
			Corner2.x = 4 * Corner2.x - Corner1.x;
			Corner1.y = 4 * Corner1.y - Corner2.y;

		}
	}
void CLine::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Line's ID: " + to_string(GetID()) + " ,corner1: ( " + to_string(Corner1.x) + ", " + to_string(Corner2.y) + "). corner2: ( " + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")");
}
void CLine::zoom(int n)
{
	if (n==0)
	{
		Corner2.x = (Corner1.x + Corner2.x) / 2;
		Corner2.y = (Corner1.y + Corner2.y) / 2;
	}
	if (n==1)
	{
		Corner2.x = 2 * Corner2.x - Corner1.x;
		Corner2.y = 2 * Corner2.y - Corner1.y;
	}
}
Type CLine::GetFigType()
{
	return line;
}

double CLine::getarea()
{
	return 0;
}
