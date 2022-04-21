#include "CTriangle.h"
#include"math.h"
#include"stdio.h"
#include <fstream>
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "CMUgraphicsLib/colors.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;
}
CTriangle::CTriangle()
{
}
void CTriangle::Draw(Output* pOut) const
{ 
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
void CTriangle::ChngFillClr(color Fclr)
{
	TriGfxInfo.isFilled = true;
	TriGfxInfo.FillClr = Fclr;
}
bool CTriangle::InsideArea(int x, int y) const
{
	
	double a = sqrt((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x) + (Corner1.y - Corner2.y) * (Corner1.y - Corner2.y));
	double b = sqrt((Corner1.x - Corner3.x) * (Corner1.x - Corner3.x) + (Corner1.y - Corner3.y) * (Corner1.y - Corner3.y));
	double c = sqrt((Corner2.x - Corner3.x) * (Corner2.x - Corner3.x) + (Corner2.y - Corner3.y) * (Corner2.y - Corner3.y));
	double sa= sqrt((Corner1.x - x) * (Corner1.x -x) + (Corner1.y - y) * (Corner1.y - y));
	double sb = sqrt((x - Corner2.x) * (x - Corner2.x) + (y - Corner2.y) * (y - Corner2.y));
	double sc = sqrt((Corner3.x - x) * (Corner3.x - x) + (Corner3.y - y) * (Corner3.y - y));
	double s1 = (sa + sb + a) / 2;
	double s2 = (sb + c + sc) / 2;
	double s3 = (sa + b + sc) / 2;
	double s = (a + b + c) / 2;


	double area = sqrt(s * (s - a) * (s - b) * (s - c));
	double area1 = sqrt(s1 * (s1 - a) * (s - sb) * (s - sa));
	double area2 = sqrt(s2 * (s2 - c) * (s - sb) * (s - sc));
	double area3 = sqrt(s3 * (s3 - b) * (s - sc) * (s - sa));
	if (area=area1+area2+area3)
		return true;
	
	/*if ((Corner2.x - Corner1.x) / (Corner2.y - Corner1.y) == (x - Corner1.x) / (y - Corner1.y) && x<Corner1.x && x>Corner2.x && y<Corner1.y&&y>Corner2.y)
		return true;
	if ((Corner2.x - Corner1.x) / (Corner2.y - Corner1.y) == (x - Corner1.x) / (y - Corner1.y) && x>Corner1.x && x<Corner2.x && y>Corner1.y && y<Corner2.y)
		return true;
	if ((Corner2.x - Corner1.x) / (Corner2.y - Corner1.y) == (x - Corner1.x) / (y - Corner1.y) && x<Corner1.x && x>Corner2.x && y>Corner1.y && y<Corner2.y)
		return true;
	if ((Corner2.x - Corner1.x) / (Corner2.y - Corner1.y) == (x - Corner1.x) / (y - Corner1.y) && x>Corner1.x && x<Corner2.x && y<Corner1.y && y>Corner2.y)
		return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner1.x) / (y - Corner1.y) && x<Corner1.x && x>Corner3.x && y<Corner1.y && y>Corner3.y)
		return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner1.x) / (y - Corner1.y) && x>Corner1.x && x<Corner3.x && y>Corner1.y && y<Corner3.y)
		return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner1.x) / (y - Corner1.y) && x>Corner1.x && x<Corner3.x && y<Corner1.y && y>Corner3.y)
		return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner1.x) / (y - Corner1.y) && x<Corner1.x && x>Corner3.x && y>Corner1.y && y<Corner3.y)
		return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner2.x) / (y - Corner2.y) && x<Corner2.x && x>Corner3.x && y > Corner2.y && y < Corner3.y)
		return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner2.x) / (y - Corner2.y) && x>Corner2.x && x<Corner3.x && y > Corner2.y && y < Corner3.y)
		return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner2.x) / (y - Corner2.y) && x<Corner2.x && x>Corner3.x && y<Corner2.y && y>Corner3.y)
		return true;
	if ((Corner2.x - Corner1.x) / (Corner2.y - Corner1.y) == (x - Corner2.x) / (y - Corner2.y) && x < Corner2.x && x<Corner3.x && y > Corner3.y && y < Corner3.y)
		return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x > Corner1.x && x<Corner3.x && y > Corner1.y && y < Corner3.y)
		return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x > Corner1.x && x<Corner3.x && y < Corner1.y && y > Corner3.y)
	return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x < Corner1.x && x>Corner3.x && y > Corner1.y && y < Corner3.y)
	return true;
	else if ((Corner1.x - Corner3.x) / (Corner1.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x < Corner1.x && x>Corner3.x && y < Corner1.y && y > Corner3.y)
	return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x < Corner2.x && x>Corner3.x && y < Corner2.y && y > Corner3.y)
		return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x > Corner2.x && x<Corner3.x && y < Corner2.y && y > Corner3.y)
		return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x < Corner2.x && x>Corner3.x && y > Corner2.y && y < Corner3.y)
		return true;
	else if ((Corner2.x - Corner3.x) / (Corner2.y - Corner3.y) == (x - Corner3.x) / (y - Corner3.y) && x > Corner2.x && x<Corner3.x && y > Corner2.y && y > Corner3.y)
		return true;
	else 
		return false;
	*/
}

void CTriangle::Save(ofstream& Outfile, Output* pOut)
{
	Outfile << "TRIANG" << "  ";
	Outfile << GetID() << "  ";
	Outfile << Corner1.x << "  ";
	Outfile << Corner1.y << "  ";
	Outfile << Corner2.x << "  ";
	Outfile << Corner2.y << "  ";
	Outfile << Corner3.x << "  ";
	Outfile << Corner3.y << "  ";
	//Outfile << pOut->savedrawcolor(FigGfxInfo.DrawClr); //Writing the draw color of the triangle
	if (FigGfxInfo.isFilled == true) //Seeing whether it is filled or not
	{
		//Outfile << pOut->savefillcolor(FigGfxInfo.FillClr); //if filled ,write the fill color
		return;
	}
	else
		Outfile << "NO_FIll \n";  //It is not filled,write No fill

}
void CTriangle::Load(ifstream& Infile, Output* pOut)
{
	Infile >> ID;
	Infile >> Corner1.x;
	Infile >> Corner1.y;
	Infile >> Corner2.x;
	Infile >> Corner2.y;
	Infile >> Corner3.x;
	Infile >> Corner3.y;
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
void CTriangle::Move(Point p)
{
	//Point Top;
	//if (Corner1.y > Corner2.y && Corner1.y > Corner3.y)
		//Top.y = Corner1.y;
	//else if (Corner2.y > Corner1.y && Corner1.y > Corner3.y)
		//Top.y = Corner2.y;
	//else
		//Top.y = Corner3.y;

	
		
	
}
CFigure* CTriangle::Copy()
{
	CTriangle* T = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	return T;
}

void CTriangle::Resize(string size)
{
	
}
void CTriangle::zoom(int n)
{

}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Triangle's ID: " + to_string(GetID()) + " ,corner1: ( " + to_string(Corner1.x) + ", " + to_string(Corner2.y) + "). corner2: ( " + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "). corner3: (" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")");
}
Type CTriangle::GetFigType()
{
	return triangle;
}

double CTriangle::getarea()
{
	double a = sqrt((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x) + (Corner1.y - Corner2.y) * (Corner1.y - Corner2.y));
	double b = sqrt((Corner1.x - Corner3.x) * (Corner1.x - Corner3.x) + (Corner1.y - Corner3.y) * (Corner1.y - Corner3.y));
	double c = sqrt((Corner2.x - Corner3.x) * (Corner2.x - Corner3.x) + (Corner2.y - Corner3.y) * (Corner2.y - Corner3.y));
	double s = (a + b + c) / 2;
	double area = sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}
