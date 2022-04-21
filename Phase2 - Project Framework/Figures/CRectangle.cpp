#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
CRectangle::CRectangle()
{

}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::ChngDrawClr(color Dclr)
{
	RectGfxInfo.DrawClr = Dclr;
}

void CRectangle::ChngFillClr(color Fclr)
{
	RectGfxInfo.isFilled = true;
	RectGfxInfo.FillClr = Fclr;
}
bool CRectangle::InsideArea(int x, int y) const
{
	Point Left;
	Point Right;
	if (Corner1.x < Corner2.x)
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
void CRectangle::Save(ofstream& Outfile, Output* pOut)  //saving/writing information in the file of rectangle 
{
	Outfile << "Rect" << "  ";
	Outfile << GetID() << "   ";//Writing ID of the rectangle
	Outfile << Corner1.x << "   ";  //Writing x-coordinate of Corner 1 of the rectangle
	Outfile << Corner1.y << "   ";  //Writing y-coordinate of Corner1 of the rectangle
	Outfile << Corner2.x << "   ";  //Writing x-Coordinate of Corner2 of the rectangle
	Outfile << Corner2.y << "   "; //Writing y-coordinate of corner2 of the rectangle
	//Outfile << pOut->savedrawcolor(FigGfxInfo.DrawClr); //Writing the draw color of the Line
	if (FigGfxInfo.isFilled == true) //Seeing whether it is filled or not
	{
		//Outfile << pOut->savefillcolor(FigGfxInfo.FillClr); //if filled ,write the fill color
		return;
	}
	else
		Outfile << "NO_FIll \n";  //It is not filled,write No fill

}
void CRectangle::Load(ifstream& Infile, Output* pOut)   //loading/reading information from the file of rectangle
{
	Infile >> ID;  //read ID
	Infile >> Corner1.x; //read x-Coordinate of Corner 1 of the rectangle
	Infile >> Corner1.y; //read y-Coordinate of Corner 1 of the rectangle
	Infile >> Corner2.x;//read x-coordinate of corner 2 of the rectangle
	Infile >> Corner2.y; //read y-coordinate of corner 2 of the rectangle
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

void CRectangle::Move(Point p)
{
	Point Left;
	Point Right;
	if (Corner1.x < Corner2.x)
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

	int D1 = ((p.x - Right.x) * (p.x - Right.x)) + ((p.y - Right.y) * (p.y - Right.y));
	int D2 = ((Corner2.x - Corner1.x) * (Corner2.x - Corner1.x)) + ((Corner2.y - Corner1.y) * (Corner2.y - Corner1.y));
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			if (((((i - p.x) * (i - p.x)) + ((p.y - j) * (p.y - j))) == D2) && ((((i - Left.x) * (i - Left.x)) + ((j - Left.y) * (j - Left.y))) == D1))
			{
				Left.x = i;
				Left.y = j;
				Right.x = p.x;
				Right.y = p.y;
				break;

			}
		}
	}
	
	if (Corner1.x < Corner2.x)
	{
		Corner1.x = Left.x;
		Corner2.x = Right.x;

	}
	else
	{
		Corner2.x = Left.x;
		Corner1.x = Right.x;

	}
	if (Corner1.y > Corner2.y)
	{
		Corner1.y = Left.y;
		Corner2.y = Right.y;
	}
	else
	{
		Corner2.y = Left.y;
		Corner1.y = Right.y;
	}

}
CFigure* CRectangle::Copy()
{
	CRectangle* R = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return R;
}


void CRectangle::Resize(string size)
{

			if (size == "1/2")
		{
			Corner2.x = (Corner1.x + Corner2.x) / 2;
			Corner2.y = (Corner1.y + Corner2.y) / 2;
		}
		if (size == "1/4")
		{
			if (Corner1.x < Corner2.x)
			{
				Corner2.x = (Corner1.x + Corner2.x) / 4;
				Corner2.y = (Corner1.y + Corner2.y) / 4;
			}
			//else
			//{
				//Corner1.x = (Corner2.x + Corner1.x) / 4;
				//Corner1.y = (Corner2.y + Corner1.y) / 4;
			//}
		}
		if (size == "2")
		{
			if (Corner1.x < Corner2.x)
			{
				Corner2.x = 2 * Corner2.x - Corner1.x;
				Corner2.y = 2 * Corner2.y - Corner1.y;
			}
			else
			{
				Corner1.x = 2 * Corner1.x - Corner2.x;
				Corner1.y = 2 * Corner1.y - Corner2.y;
			}
		}
		if (size == "4")
		{
			if (Corner1.x < Corner2.x)
			{
				Corner2.x = (Corner2.x - Corner1.x);
				Corner2.y = (Corner2.y - Corner1.y);
			}
			else
			{
				Corner1.x = 4 * (Corner1.x - Corner2.x);
				Corner1.y = 4 * (Corner1.y - Corner2.y);
			}
		}
	}
	


void CRectangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Rectangle's ID: " + to_string(GetID()) + " ,corner1: ( " + to_string(Corner1.x) + ", " + to_string(Corner2.y) + "). corner2: ( " + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")");
}
void CRectangle::zoom(int n)
{
	if (n == 0||n==1)
	{
		Corner2.x = (Corner1.x + Corner2.x) / 2;
		Corner2.y = (Corner1.y + Corner2.y) / 2;
	}
	else if (n == 2)
	{
		if (Corner1.x < Corner2.x)
		{
			Corner2.x = 2 * Corner2.x - Corner1.x;
			Corner2.y = 2 * Corner2.y - Corner1.y;
		}
		else
		{
			Corner1.x = 2* Corner1.x - Corner2.x;
			Corner1.y = 2 * Corner1.y - Corner2.y;
		}
	}

}
Type CRectangle::GetFigType()
{
	return rectangle;
}

double CRectangle::getarea()
{
	Point Left;
	Point Right;
	if (Corner1.x < Corner2.x)
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
	double length = Right.x - Left.x;
	double width = Left.y - Right.y;
	double area = length * width;
	return area;
}
