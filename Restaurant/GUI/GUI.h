#ifndef __GUI_H_
#define __GUI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include "..\Rest\Order.h"

#include <string>
#include <Windows.h>
#include <shobjidl.h> 
#include<iostream>
#include <fstream>

using namespace std;

class GUI
{

private:
	window *pWind;
	color OrdersClrs[TYPE_CNT];
	GUI_MODE GMode;
	color GUIL;
	color GUID;
	color GUIS;
	color GUIF;
	color GUIR;
	string MusicDir;
	int oFsize;
	int OrderWidth ;	//width of the order to be drawn on GUI
	int OrderHeight ; 		//height of the order to be drawn on GUI
	int MaxHorizOrders	;	//The max no. of orders the can be drawn in on Horizontal line in a region
	int	MaxVerticalOrders;   //The max no. of orders the can be drawn in on Vertical line in a region	
	int	MaxRegionOrderCount  ;//Max no of orders that can be drawn in a single region
	bool MusicOn;
	bool MusicMode;
	bool Draw;
	bool dSpeed;
	bool Traffic;
	// Some Static Constant Data Members: ---------------------

	static const int	
		WindWidth=1200, WindHeight=650,		//Window width and height
		StatusBarHeight = 150,	//Status Bar Height
		MenuBarHeight = 50,		//Menu Bar Height (distance from top of window to bottom line of menu bar)
		MenuItemWidth = 155,		//Width of each item in menu bar menu
		
		DrawingAreaHeight = WindHeight - MenuBarHeight - StatusBarHeight,		
		YHalfDrawingArea = MenuBarHeight + DrawingAreaHeight/2, //The y coordinate of half the Drawing area

		RestStartX = (int)(WindWidth * 0.4), //The x coordinate of the upper left corner of the Rest
		RestEndX = (int)(WindWidth * 0.6),   //The x coordinate of the lower right corner of the Rest

		RestWidth = RestEndX - RestStartX, //The width of the Rest (Note: the Rest is a Square)		

		RestStartY = YHalfDrawingArea - RestWidth/2, //The y coordinate of the upper left corner of the Rest
		RestEndY = YHalfDrawingArea + RestWidth/2,   //The y coordinate of the lower right corner of the Rest


		FontSize = 20;	//font size used to draw orders ID on Interface
		
		

		
		
		
		

	/////////
	////////
	////////

	int OrderCount;		//the total number of orders to be drawn
	
	Order * OrdListForDrawing[MaxPossibleOrdCnt]; // This Array of Pointers is used for drawing elements in the GUI
	//NOTES: 
	//Orders are assumed to be sorted by arrival time
	// At every time step, you should update those pointers 
	// to point to the current waiting orders only
	

	//Numbers Of the Orders and Motorcycles in Each Region
	int NumberOfVIPOrders[REG_CNT];        
	int NumberOfNormalOrders[REG_CNT];
	int NumberOfFrozenOrders[REG_CNT];
	int bufferSize ;
	char oldDir[MAX_PATH]; 


	// 
	// TODO: Add more members if needed
	//

	void DrawSingleOrder(Order* pO, int RegionCount) const;		//draws ONE order 
	void DrawOrders() const;		//drwas ALL orders in OrdListForDrawing



	void DrawString(const int iX, const int iY, const string Text); // prints a message in the passed coordinates
	void DrawRestArea() const;	    // draws the restaurant area
	
	void ClearStatusBar() const;    // clears the status bar
	void ClearDrawingArea() const;	// clears the Drawing area from all drawings
	void DrawNumbersForRegions() const;    // Draws the number of orders of all Regions
	void ResetDrawNumbers(); // Resets the Region Order Number to zero
	void CreateMenuBar();
	void ClearMenuBar() const;
	void ChangeMode();
public:
	GUI();
	~GUI();
	// Input Functions  ---------------------------
	void waitForClick(int &x,int &y) const;	// waits a user click from the user
	void getClick(int &x,int &y) const;	// gets a user click from the user
	bool MenuClicked(int x , int y);
	void ClearMouseClicks() const;
	string GetString() const ; // reads a string (keyboard input) from the user
	string GetFileName(string mode = "TXT");
	string SaveFileName();
	bool getTraffic();
	bool getSpeed();
	// Output Functions  ---------------------------
	void PrintMessage(string msg, string line1 = "", string line2 = "", string line3 = "", string line4 = "", string line5 = "", string line6 = "", string line7 = "") const; // prints a message in the status bar
	void PrintMenuMessage(string msg) const;
	void PrintTime(int time, color clr = WHITE) const;
	void UpdateInterface();
	void AddOrderForDrawing(Order* pOrd);	//Adds a new order to the drawing list
	void ResetDrawingList();		//resets drawing list (should be called every timestep after drawing)
	PROG_MODE getGUIMode() ;			//returns the mode of the program

};

#endif