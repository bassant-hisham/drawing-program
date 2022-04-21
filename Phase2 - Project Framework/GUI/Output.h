#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void addfigures(); const //create the addfigure bar
	void createChangeColorBar() const; //create the color bar
	void CreateStatusBar()const;	//create the status bar
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar()const;	//Clears the status bar
	void ClearToolBar() const; //clear the tool bar
	void ClearDrawArea() const;	//Clears the drawing area
	void CreatechoosecolorsbarD()const;//creats colors bar for drawing color
	void CreatechoosecolorsbarF()const;//creats colors bar for fill color
	void CreatechoosecolorsbarB()const;//creats colors bar for background color

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInf, bool selected = false) const; //draw a line
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriangleInfo, bool selected = false)const; //draw a tringle
	void DrawCirc(Point P1, Point P2, GfxInfo CircleInfo, bool selected = false)const; //draw a circle
	///Make similar functions for drawing all other figures.

	void PrintMessage(string msg) const;	//Print a message on Status bar
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	color getBkcolor() const;
	void setdrawcolor(color);
	void setBKcolor(color);
	/*string savedrawcolor(color);
	string saveBKcolor(color);
	string savefillcolor(color);
	color loaddrawcolor(string);
	color loadbkcolor(string);
	color loadfillcolor(string);*/
	

	~Output();
};

#endif