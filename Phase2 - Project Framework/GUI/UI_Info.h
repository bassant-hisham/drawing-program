#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	FIGURE,
	ZOOM,
	CHNG_COLOR_BAR,
	CHOOSE_COLORSD,
	CHOOSE_COLORSF,
	CHOOSE_COLORSB
};


enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//TODO: Add more items names here
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADD_FIRGURE,
	ITM_DELETE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_ZOOM_IN_OUT,
	ITM_RESIZE,
	ITM_SELECT,
	ITM_CHNG_DRAW_CLR,
	ITM_MOVE,
	ITM_SAVEGRAPH,
	ITM_LOADGRAPH,
	ITM_EXIT,
	ITM_SWITCHTOPLAYMODE,

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	ITM_CHOOSEBYCOLOUR,
	ITM_CHOOSEBYAREA,
	ITM_CHOOSEBYTYPE,
	ITM_CHOOSEBYTYPEANDCOLUR,
	ITM_SWITCHTODRAWMODE,

	PLAY_ITM_COUNT	//no. of menu items ==> This should be the last line in this enum

};
enum addfiguresmenuitems
{

	ITM_RECT,
	ITM_CIRC,
	ITM_LINE,
	ITM_TRI,
	ITM_SWITCHTODRAWMODE1,	//Recangle item in menu
	ADD_ITM_COUNT
};

enum ChangeColorBar
{
	CHNG_FILL,
	CHNG_BACKGROUND,
	CHNG_DRAWCOLOUR,
	ITM_SWITCHTODRAWMODE3,
	COLOR_BAR_COUNT
};

enum CHOOSE_COLORSD
{
	ITM_BlackD,
	ITM_BURLYWOODD,
	ITM_GAINSBOROD,
	ITM_GOLDENRODD,
	ITM_PINKD,
	ITM_VioletD,
	ITM_WhiteD,
	ITM_THISTLED,
	ITM_SWITCHTOcolorMODE1,
	CHOOSECOLORCOUNT
};
enum CHOOSE_COLORSF
{
	ITM_BURLYWOODF,
	ITM_GAINSBOROF,
	ITM_THISTLEF,
	ITM_PINKF,
	ITM_GOLDENRODF,
	ITM_VioletF,
	ITM_whiteF,
	ITM_LIGHTSKYBLUEF,
	ITM_SWITCHTOcolorMODE2,
	CHOOSECOLORCOUNT2
};
enum CHOOSE_COLORSB
{
	ITM_BURLYWOODB,
	ITM_GAINSBOROB,
	ITM_WhiteB,
	ITM_LEMONCHIFFONB,
	ITM_THISTLEB,
	ITM_PINKB,
	ITM_VioletB,
	ITM_LIGHTSKYBLUEB,
	ITM_SWITCHTOcolorMODE3,
	CHOOSECOLORCOUNT3
};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth; //Width of each item in toolbar menu




	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color Toolbarcolor;
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object 

#endif