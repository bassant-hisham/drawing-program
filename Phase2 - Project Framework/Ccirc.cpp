#include "Ccirc.h"
#include <fstream>
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
Ccirc::Ccirc(Point c, Point r, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	centre = c;
	radius = r;
}
Ccirc::Ccirc() : CFigure(CircGfxInfo)
{

	Point P;
	Point P2;
	P.x = 0;
	P.y = 0;
	P2.x = 0;
	P2.y = 0;


		centre = P;
		radius = P2;
	

}


void Ccirc::Draw(Output* pOut) const
{
	pOut->DrawCirc(centre, radius, FigGfxInfo, Selected);
}

void Ccirc::ChngFillClr(color Fclr)
{

 CircGfxInfo.isFilled = true;
 CircGfxInfo.FillClr = Fclr;
}
bool Ccirc::InsideArea(int x, int y) const
{
	int Radius;
	//calculating radius of the circle
	Radius = sqrt((radius.x - centre.x) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y));
	Point q;
	q.x = x;
	q.y = y;

	//calculating distance from the centre to the selected point
	int dist;
	dist = sqrt((q.x - centre.x) * (q.x - centre.x) + (q.y - centre.y) * (q.y - centre.y));

	//checking if the calculated distance less than or equal the radius(to be in the circle)
	if (dist <= Radius)
		return true;
	else return false;
}
void Ccirc::Save(ofstream& Outfile, Output* pOut)
{
	//Output* pOut = pManager->GetOutput();
	Outfile << "CIRCLE" << "  ";
	Outfile << GetID() << "   "; //Writing ID of the circle
	Outfile << centre.x << "   "; //Writing x-coordinate of centre of the circle
	Outfile << centre.y << "   ";//Writing y-coordinate of centre of the circle
	Outfile << radius.x << "   ";  //Writing x-Coordinate of radius of the circle
	Outfile << radius.y << "   ";  //Writing y-coordinate of radius of the circle
	//Outfile << pOut->savedrawcolor(FigGfxInfo.DrawClr); //Writing the draw color of the Circle
	if (FigGfxInfo.isFilled == true) //Seeing whether it is filled or not
	{
		//Outfile << pOut->savefillcolor(FigGfxInfo.FillClr); //if filled ,write the fill color
		return;
	}
	else
		Outfile << "NO_FIll \n";  //It is not filled,write No fill

}
void Ccirc::Load(ifstream& Infile, Output* pOut)
{
	Infile >> ID;  //read ID
	Infile >> centre.x;//read x-Coordinate of Centre of the circle
	Infile >> centre.y; //read y-Coordinate of Centre of the circle
	Infile >> radius.x;//read x-coordinate of radius of the circle
	Infile >> radius.y; //read y-coordinate of radius of the circle
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
void  Ccirc::Move(Point p2)
{
	int D=((p2.x - centre.x) * (p2.x - centre.x) + (p2.y - centre.y) * (p2.y - centre.y));
	int D1= ((radius.x - centre.x) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y));
	
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			if ((radius.x - i) * (radius.x - i) + (radius.y - j) * (radius.y - j) == D && ((p2.x - i) * (p2.x - i) + (p2.y - j) * (p2.y - j)) == D1)
			{
				radius.x= i;
				radius.y= j;
				break;
			}
		}
	}
	centre = p2;

}
CFigure* Ccirc::Copy()
{
	Ccirc* C = new Ccirc(centre, radius, FigGfxInfo);
	return C;
}

void Ccirc::Resize(string size)
{

	if (size == "2")
	{

		double D1 = (sqrt(((radius.x - centre.x)) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y)));
		



	}
	if (size == "1/2")
	{

		double D1 = (sqrt(((radius.x - centre.x)) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y)));
		float Area = D1 * D1 * (22 / 7);

		for (int i = 0; i < 2000; i++)
		{
			for (int j = 0; j < 2000; j++)
			{
				if (sqrt((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j)) == D1 / sqrt(2) && (((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j))) * (2) * ((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j)) == (1 / 2) * Area)
				{
					radius.x = i;
					radius.y = j;
				}
			}
		}
	}
	if (size == "1/4")
	{

		double D1 = (sqrt(((radius.x - centre.x)) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y)));
		float Area = D1 * D1 * (22 / 7);

		for (int i = 0; i < 2000; i++)
		{
			for (int j = 0; j < 2000; j++)
			{
				if (sqrt((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j)) == D1 / 2 && (((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j))) * (2) * ((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j)) == (1 / 4) * Area)
				{
					radius.x = i;
					radius.y = j;
				}
			}
		}
	}
	if (size == "4")
	{
		double D1 = (sqrt(((radius.x - centre.x)) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y)));
		float Area = D1 * D1 * (22 / 7);

		for (int i = 0; i < 2000; i++)
		{
			for (int j = 0; j < 2000; j++)
			{
				if (sqrt((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j)) == D1 * 2 && (((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j))) * (2) * ((centre.x - i) * (centre.x - i) + (centre.y - j) * (centre.y - j)) == 4 * Area)
				{
					radius.x = i;
					radius.y = j;
				}
			}
		}

	}
}
void Ccirc::PrintInfo(Output* pOut)
{
	int Radius;
	//calculating radius of the circle
	Radius = sqrt((radius.x - centre.x) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y));
	pOut->PrintMessage("Circle's ID: " + to_string(GetID()) + " ,Centre: ( " + to_string(centre.x) + ", " + to_string(centre.y) + "). Radius: " + to_string(Radius));
}
void Ccirc::zoom(int n)
{

}
Type Ccirc::GetFigType()
{
	return circle;
}

double Ccirc::getarea()
{
	double rad = sqrt((radius.x - centre.x) * (radius.x - centre.x) + (radius.y - centre.y) * (radius.y - centre.y));
	double pi = 2 * acos(0.0);
	double area = pi * (rad * rad);
	return area;

}
