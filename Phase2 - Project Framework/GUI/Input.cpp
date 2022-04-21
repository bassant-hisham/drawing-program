#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		pO->PrintMessage(Label);
	}
}

ActionType Input::GetUserAction() 
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_FIRGURE: return ADD_FIGURES;
			case ITM_ZOOM_IN_OUT:return ZOOM_IN_OUT;
			case ITM_SELECT:return SELECT;
			case ITM_CHNG_DRAW_CLR:return CHANGE_COLOR_BAR;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_RESIZE: return RESIZE;
			case ITM_MOVE: return MOVE;
			case ITM_SAVEGRAPH: return SAVE;
			case ITM_LOADGRAPH: return LOAD;
			case ITM_SWITCHTOPLAYMODE: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;//A click on empty place in desgin toolbar

			}

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;

	}
	else if (UI.InterfaceMode == CHNG_COLOR_BAR)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case CHNG_FILL:return CHNG_FILL_CLR;
			case CHNG_BACKGROUND:return CHNG_BK_CLR;
			case  CHNG_DRAWCOLOUR: return CHNG_DRAW_CLR;
			case ITM_SWITCHTODRAWMODE3:return TO_DRAW;

			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;


	}
	else if (UI.InterfaceMode == FIGURE)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_RECT:return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_LINE:return DRAW_LINE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_SWITCHTODRAWMODE1:return TO_DRAW;

			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;

	}

	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_CHOOSEBYTYPE: return CHOOSE_BY_TYPE;
			case ITM_CHOOSEBYCOLOUR: return CHOOSE_BY_COLOUR;
			case ITM_CHOOSEBYAREA: return CHOOSE_BY_AREA;
			case ITM_CHOOSEBYTYPEANDCOLUR:return CHOOSE_BY_TYPE_AND_COLUR;
			case ITM_SWITCHTODRAWMODE:return TO_DRAW2;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		else
		return STATUS;

	}
	else if (UI.InterfaceMode == CHOOSE_COLORSD)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_BlackD :return BlackD;
			case ITM_BURLYWOODD:return BURLYWOODD;
			case ITM_GAINSBOROD: return GAINSBOROD;
			case ITM_GOLDENRODD:return GOLDENRODD;
			case ITM_PINKD: return PINKD;
			case ITM_VioletD:return VioletD;
			case ITM_WhiteD:return WhiteD;
			case  ITM_THISTLED: return THISTLED;
			case ITM_SWITCHTOcolorMODE1:return SWITCH_TO_COLOR;

			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		else
		{
			return STATUS;
		}
	}
	///////////////////////////////////
	else if (UI.InterfaceMode == CHOOSE_COLORSF)	//GUI is in PLAY mode
	{
	if (y >= 0 && y < UI.ToolBarHeight)
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_BURLYWOODF:return BURLYWOODF;
		case ITM_GAINSBOROF:return GAINSBOROF;
		case ITM_THISTLEF: return THISTLEF;
		case ITM_PINKF:return PINKF;
		case ITM_GOLDENRODF: return GOLDENRODF;
		case ITM_VioletF:return VioletF;
		case ITM_whiteF:return WhiteF;
		case  ITM_LIGHTSKYBLUEF: return LIGHTSKYBLUEF;
		case ITM_SWITCHTOcolorMODE2:return SWITCH_TO_COLOR;

		default: return EMPTY;
		}
	}
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}
	else
	{
		return STATUS;
	}
	}
	else if (UI.InterfaceMode == CHOOSE_COLORSB)	//GUI is in PLAY mode
	{
	if (y >= 0 && y < UI.ToolBarHeight)
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_BURLYWOODB:return BURLYWOODB;
		case ITM_GAINSBOROB:return GAINSBOROB;
		case ITM_LEMONCHIFFONB: return LEMONCHIFFONB;
		case ITM_THISTLEB:return THISTLEB;
		case ITM_PINKB: return PINKB;
		case ITM_VioletB:return VioletB;
		case ITM_LIGHTSKYBLUEB:return LIGHTSKYBLUEB;
		case  ITM_WhiteB: return WhiteB;
		case ITM_SWITCHTOcolorMODE3:return SWITCH_TO_COLOR;

		default: return EMPTY;
		}
	}
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}
	else
	{
		return STATUS;
	}
	}

//This function reads the position where the user clicks to determine the desired action
}


///////////////////////////////////

//This function reads the position where the user clicks to determine the desired action


Input::~Input()
{

}
