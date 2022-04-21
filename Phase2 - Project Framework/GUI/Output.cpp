#include "Output.h"
#include<cmath>

Output::Output() //constructor
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = RED;	//Drawing color
	UI.FillColor = WHITE;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = PINK;	//Background color
	UI.HighlightColor = YELLOW;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = STEELBLUE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.Toolbarcolor = WHITE;
	int u = 0;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();

}



Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{

	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];


	MenuItemImages[ITM_ADD_FIRGURE] = "images\\MenuItems\\add figure.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_ZOOM_IN_OUT] = "images\\MenuItems\\ZOOM.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_paste.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_resize.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_select.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_move.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\Menu_change colour.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Menu_save.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\Menu_load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_exit.jpg";
	MenuItemImages[ITM_SWITCHTOPLAYMODE] = "images\\MenuItems\\Menu_play mode.jpg";



	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time

	for (int i = 0; i < DRAW_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	}
	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);






}
//////////////////////////////////////////////////////////////////////////////////////////



void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImage[PLAY_ITM_COUNT];

	MenuItemImage[ITM_CHOOSEBYCOLOUR] = "images\\MenuItems\\choose by colour.jpg";
	MenuItemImage[ITM_CHOOSEBYAREA] = "images\\MenuItems\\choose by area.jpg";
	MenuItemImage[ITM_CHOOSEBYTYPE] = "images\\MenuItems\\choose by type.jpg";
	MenuItemImage[ITM_CHOOSEBYTYPEANDCOLUR] = "images\\MenuItems\\choose by type and colour .jpg";
	MenuItemImage[ITM_SWITCHTODRAWMODE] = "images\\MenuItems\\Menu_draw mode.jpg";






	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImage[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
void Output::addfigures()
{

	UI.InterfaceMode = FIGURE;
	string MenuItemImagess[ADD_ITM_COUNT];

	MenuItemImagess[ITM_RECT] = "images\\MenuItems\\Menu_rectangle.jpg";
	MenuItemImagess[ITM_CIRC] = "images\\MenuItems\\Menu_circle.jpg";
	MenuItemImagess[ITM_LINE] = "images\\MenuItems\\Menu_line.jpg";
	MenuItemImagess[ITM_TRI] = "images\\MenuItems\\Menu_tringle.jpg";
	MenuItemImagess[ITM_SWITCHTODRAWMODE1] = "images\\MenuItems\\Menu_draw mode.jpg";



	for (int i = 0; i < ADD_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImagess[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

const void Output::createChangeColorBar() const
{
	{


		UI.InterfaceMode = CHNG_COLOR_BAR;
		string MenuItemimags[COLOR_BAR_COUNT];
		MenuItemimags[CHNG_FILL] = "images\\MenuItems\\fill colour.jpg";
		MenuItemimags[CHNG_BACKGROUND] = "images\\MenuItems\\background colour.jpg";
		MenuItemimags[CHNG_DRAWCOLOUR] = "images\\MenuItems\\outline colour.jpg";
		MenuItemimags[ITM_SWITCHTODRAWMODE3] = "images\\MenuItems\\Menu_draw mode.jpg";

		for (int i = 0; i < COLOR_BAR_COUNT; i++)
		{
			pWind->DrawImage(MenuItemimags[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		}
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	}

	return void();
}


//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}

void Output::CreatechoosecolorsbarD() const
{
	{
		{

			UI.InterfaceMode = CHOOSE_COLORSD;
			string MenuItemimg[CHOOSECOLORCOUNT];
			
			MenuItemimg[ITM_BlackD] = "images\\MenuItems\\black.jpg";;
			MenuItemimg[ITM_BURLYWOODD] = "images\\MenuItems\\BURLYWOODD.jpg";
			MenuItemimg[ITM_GAINSBOROD] = "images\\MenuItems\\GAINSBOROF.jpg";
			MenuItemimg[ITM_GOLDENRODD] = "images\\MenuItems\\GOLDENROD.jpg";
			MenuItemimg[ITM_WhiteD] = "images\\MenuItems\\white.jpg";
			MenuItemimg[ITM_PINKD] = "images\\MenuItems\\pink.jpg";
			MenuItemimg[ITM_VioletD] = "images\\MenuItems\\violet.jpg";
			MenuItemimg[ITM_THISTLED] = "images\\MenuItems\\THISTLE.jpg";
			MenuItemimg[ITM_SWITCHTOcolorMODE1] = "images\\MenuItems\\choose by colour.jpg";
			
		
			
		
		

			for (int i = 0; i < CHOOSECOLORCOUNT; i++)
			{
				pWind->DrawImage(MenuItemimg[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
			}
			pWind->SetPen(BLACK, 3);
			pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

		}
	}
}

void Output::CreatechoosecolorsbarF() const
{
	{
		{

			UI.InterfaceMode = CHOOSE_COLORSF;
			string MenuItemimg[CHOOSECOLORCOUNT2];

			MenuItemimg[ITM_BURLYWOODF] = "images\\MenuItems\\BURLYWOODD.jpg";
			MenuItemimg[ITM_GAINSBOROF] = "images\\MenuItems\\GAINSBOROF.jpg";
			MenuItemimg[ITM_THISTLEF] = "images\\MenuItems\\THISTLE.jpg";
			MenuItemimg[ITM_PINKF] = "images\\MenuItems\\pink.jpg";
			MenuItemimg[ITM_GOLDENRODF] = "images\\MenuItems\\GOLDENROD.jpg";
			MenuItemimg[ITM_VioletF] = "images\\MenuItems\\violet.jpg";
			MenuItemimg[ITM_whiteF] = "images\\MenuItems\\white.jpg";
			MenuItemimg[ITM_LIGHTSKYBLUEF] = "images\\MenuItems\\lightskyblue.jpg";
			MenuItemimg[ITM_SWITCHTOcolorMODE2] = "images\\MenuItems\\choose by colour.jpg";






			for (int i = 0; i < CHOOSECOLORCOUNT; i++)
			{
				pWind->DrawImage(MenuItemimg[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
			}
			pWind->SetPen(BLACK, 3);
			pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

		}
	}
}
void Output::CreatechoosecolorsbarB() const
{
	{
		{

			UI.InterfaceMode = CHOOSE_COLORSB;
			string MenuItemimg[CHOOSECOLORCOUNT3];

			MenuItemimg[ITM_BURLYWOODB] = "images\\MenuItems\\BURLYWOODD.jpg";
			MenuItemimg[ITM_GAINSBOROB] = "images\\MenuItems\\GAINSBOROF.jpg";
			MenuItemimg[ITM_LEMONCHIFFONB] = "images\\MenuItems\\lemon.jpg";
			MenuItemimg[ITM_PINKB] = "images\\MenuItems\\pink.jpg";
			MenuItemimg[ITM_THISTLEB] = "images\\MenuItems\\THISTLE.jpg";
			MenuItemimg[ITM_VioletB] = "images\\MenuItems\\violet.jpg";
			MenuItemimg[ITM_LIGHTSKYBLUEB] = "images\\MenuItems\\lightskyblue.jpg";
			MenuItemimg[ITM_WhiteB] = "images\\MenuItems\\white.jpg";
			MenuItemimg[ITM_SWITCHTOcolorMODE3] = "images\\MenuItems\\choose by colour.jpg";






			for (int i = 0; i < CHOOSECOLORCOUNT; i++)
			{
				pWind->DrawImage(MenuItemimg[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
			}
			pWind->SetPen(BLACK, 3);
			pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getBkcolor() const		//get current BKGround Color width
{
	return UI.BkGrndColor;
}

void Output::setdrawcolor(color u)
{
	UI.DrawColor = u;
}
void Output::setBKcolor(color u)
{
	UI.BkGrndColor = u;
}

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr; 

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width


	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected)const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected)const
{
	int raduis;
	raduis = sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, raduis, style);
}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInf, bool selected) const
{
	drawstyle style;

	style = FRAME;



	color DrawingClr;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInf.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInf.BorderWdth);	//Set Drawing color & width

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

/*string Output::savedrawcolor(color u)
{
	if (u == BLACK)
		return "BLACK";
	else if (u == BURLYWOOD)
		return "BURLYWOOD";
	else if (u == GAINSBOROB)
		return "GAINSBOROB";
	else if (u == GOLDENROD)
		return "GOLDENROD";
	else if (u == PINK)
		return "PINK";
	else if (u == THISTLEB)
		return "THISTLEB";
	else if (u == VIOLET)
		return "VIOLET";
	else if (u == WHITE)
		return "WHITE";
}
color Output::loaddrawcolor(string u)
{
	if (u == "BLACK")
		return BLACK;
	else if (u == "BURLYWOOD")
		return BURLYWOOD;
	else if (u == "GAINSBOROB")
		return GAINSBOROB;
	else if (u == "GOLDENROD")
		return GOLDENROD;
	else if (u == "PINK")
		return PINK;
	else if (u == "THISTLEB")
		return THISTLEB;
	else if (u == "VIOLET")
		return VIOLET;
	else if (u == "WHITE")
		return WHITE;
}
string Output::saveBKcolor(color u)
{
	if (u == BURLYWOOD)
		return "BURLYWOOD";
	else if (u == GAINSBOROB)
		return "GAINSBOROB";
	else if (u == LEMONCHIFFONB)
		return "LEMONCHIFFONB";
	else if (u == LIGHTSKYBLUE)
		return "LIGHTSKYBLUE";
	else if (u == PINK)
		return "PINK";
	else if (u == THISTLEB)
		return "THISTLEB";
	else if (u == VIOLET)
		return "VIOLET";
	else if (u == WHITE)
		return "WHITE";
}
color Output::loadbkcolor(string u)
{
	if (u == "BURLYWOOD")
		return BURLYWOOD;
	else if (u == "GAINSBOROB")
		return GAINSBOROB;
	else if (u == "LEMONCHIFFONB")
		return LEMONCHIFFONB;
	else if (u == "LIGHTSKYBLUE")
		return LIGHTSKYBLUE;
	else if (u == "PINK")
		return PINK;
	else if (u == "THISTLEB")
		return THISTLEB;
	else if (u == "VIOLET")
		return VIOLET;
	else if (u == "WHITE")
		return WHITE;
}

string Output::savefillcolor(color u)
{
	if (u == RED)
		return "RED";
	else if (u == BURLYWOOD)
		return "BURLYWOOD";
	else if (u == GAINSBORO)
		return "GAINSBORO";
	else if (u == GOLDENROD)
		return"GOLDENROD";
	else if (u == LIGHTSKYBLUE)
		return"LIGHTSKYBLUE";
	else if (u == PINK)
		return"PINK";
	else if (u == THISTLE)
		return"THISTLE";
	else if (u == VIOLET)
		return"VIOLET";
	else if (u == WHITE)
		return"WHITE";
	else
		return "NO FILL";


}
color Output::loadfillcolor(string u)
{
	if (u == "RED")
		return RED;
	else if (u == "BURLYWOOD")
		return BURLYWOOD;
	else if (u == "GAINSBORO")
		return GAINSBORO;
	else if (u == "GOLDENROD")
		return GOLDENROD;
	else if (u == "LIGHTSKYBLUE")
		return LIGHTSKYBLUE;
	else if (u == "PINK")
		return PINK;
	else if (u == "THISTLE")
		return THISTLE;
	else if (u == "VIOLET")
		return VIOLET;
	else if (u == "WHITE")
		return WHITE;
	else
		return 0;

}*/
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

