#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <math.h> 
#include <algorithm>
#include <vector>
#include<windows.h>
#include<conio.h>
#include<dos.h>
#include<fstream>
#include"checker.h"
#include"console_function.h"
#include"draw.h"
#include"introduction.h"
#include"main_menu.h"
#include"PvP.h"
#include"splash_screen.h"
#include"win_animation.h"
#pragma warning (disable : 4996)
#define consoleM 120
#define consoleN 30
#define F1  59
#define F2  60
#define F3  61
#define F4  62
#define F5  63
#define F6  64
#define F7  65
#define F8  66
#define F9  67
using namespace std;
void game_introduction() {
	hide_pointer();
	absorb_input();
	clrscr();
	while (1) {
		clrscr();
		TextColor(14);
		gotoXY(35, 1);
		printf("     This is a simple CARO game");
		TextColor(15);
		gotoXY(20, 4);
		printf("- Each turn, you or your opponent can place one owned symbol to the table.");
		gotoXY(20, 5);
		printf("- To win this game, your symbols must be 5 in a row or a diagonal.");
		gotoXY(20, 6);
		printf("- There is no timer, think carefully before do your choice.\n\n\n\n\n");
		////////////////////////////////////////////////////////////////////////////////////////////
		TextColor(11);
		printf("                          CCCCCCC            A           RRRRRR             OOOOO      \n");
		printf("                         CCC     CC         AAA          RR    RR         OO     OO    \n");
		printf("                        CC                 AA AA         RR     RR       OO       OO   \n");
		printf("                       CCC                AA   AA        RR    RR        OO       OO   \n");
		printf("                        CC               AAAAAAAAA       RRRRR           OO       OO   \n");
		printf("                         CCC     CC     AA       AA      RR   RR          OO     OO    \n");
		printf("                          CCCCCCC      AA         AA     RR     RR          OOOOO      \n");
		gotoXY(35, 25);
		TextColor(13);
		printf("Press any key to continue !");
		while (1) {
			if (inputKey() != -1) return;
			Sleep(1);
		}
	}
}
