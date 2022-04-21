#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	ADD_FIGURES,
	DRAW_RECT,
	DRAW_LINE,  //Draw Line
	DRAW_CIRC,	//Draw Circle
	DRAW_TRI, //Draw Triangle
	STATUS,  //A click on the status bar
	DRAWING_AREA,  //A click on the drawing area
	TO_DRAW,  //Switch interface to Draw mode
	TO_DRAW2,
	TO_PLAY,  //Switch interface to Play mode
	SELECT,
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	CHANGE_COLOR_BAR,
	EXIT,			//Exit the application		
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_BK_CLR,	//Change background color
	CHNG_FILL_CLR,	//Change the filling color
	//COLORS FOR CHANGING DRAWING COLOR
	BlackD,
	BURLYWOODD,
	GAINSBOROD,
	GOLDENRODD,
	PINKD,
	VioletD,
	WhiteD,
	THISTLED,
	//colors for changing FILLcolor
	BURLYWOODF,
	GAINSBOROF,
	THISTLEF,
	PINKF,
	GOLDENRODF,
	VioletF,
	WhiteF,
	LIGHTSKYBLUEF,
	//colors for changing backgroundcolor
	BURLYWOODB,
	GAINSBOROB,
	LEMONCHIFFONB,
	THISTLEB,
	PINKB,
	VioletB,
	LIGHTSKYBLUEB,
	WhiteB,
	EMPTY,  //A click on empty place in the toolbar	
	ZOOM_IN_OUT,
	DEL,            //Delete a figure(s)
	COPY,
	CUT,
	PASTE,
	RESIZE,  //Resize a figure(s)
	MOVE,			//Move a figure(s)
	ROTATE,			//Rotate a figure(s)
	RESTART,
	CHOOSE_BY_TYPE,
	CHOOSE_BY_COLOUR,
	CHOOSE_BY_AREA,
	CHOOSE_BY_TYPE_AND_COLUR,
	SWITCH_TO_COLOR,
	CHOOSECOLORS


	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif