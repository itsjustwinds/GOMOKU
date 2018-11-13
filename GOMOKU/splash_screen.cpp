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
void splash_screen() {
	int now = 0, color;
	clrscr();
	hide_pointer();
	while (++now) {
		//clrscr();
	///////////////////////////////////////////////////////////////////////////        G
		TextColor(8 + (now + 8 - 1) % 8);
		if (now >= 1) {
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(20, Y);
				printf("%c", char(219));
			}
		}

		if (now >= 2) {
			for (int X = 21; X <= 28; ++X) {
				gotoXY(X, 4);
				printf("%c", char(220));
			}
			for (int X = 21; X <= 28; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}

		if (now >= 3) {
			for (int Y = 12; Y >= 11; --Y) {
				gotoXY(29, Y);
				printf("%c", char(219));
			}
			for (int X = 28; X <= 30; ++X) {
				gotoXY(X, 10);
				printf("%c", char(220));
			}
		}
		/////////////////////////////////////////////////////////////////////////////   O
		TextColor(8 + (now + 8 - 2) % 8);
		if (now >= 4) {
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(33, Y);
				printf("%c", char(219));
			}
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(41, Y);
				printf("%c", char(219));
			}
			for (int X = 34; X <= 40; ++X) {
				gotoXY(X, 4);
				printf("%c", char(220));
			}
			for (int X = 34; X <= 40; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}
		///////////////////////////////////////////////////////////////////////////////   M
		TextColor(8 + (now + 8 - 3) % 8);
		if (now >= 5) {
			gotoXY(44, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(44, Y);
				printf("%c", char(219));
			}
			gotoXY(52, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(52, Y);
				printf("%c", char(219));
			}
			int tmpX = 45, tmpY = 5;
			for (int i = 1; i <= 4; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++; tmpY++;
			}
			tmpX--; tmpY--;
			for (int i = 1; i <= 4; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++; tmpY--;
			}
		}
		////////////////////////////////////////////////////////////////////////////      O
		if (now >= 6) {
			TextColor(8 + (now + 8 - 4) % 8);
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(55, Y);
				printf("%c", char(219));
			}
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(63, Y);
				printf("%c", char(219));
			}
			for (int X = 56; X <= 62; ++X) {
				gotoXY(X, 4);
				printf("%c", char(220));
			}
			for (int X = 56; X <= 62; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}
		/////////////////////////////////////////////////////////////////////////        K
		if (now >= 7) {
			TextColor(8 + (now + 8 - 5) % 8);
			gotoXY(66, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(66, Y);
				printf("%c", char(219));
			}
			int tmpX = 66, tmpY = 9;
			for (int i = 1; i <= 5; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++, tmpY--;
			}
			gotoXY(tmpX, tmpY);
			printf("%c", char(220));
			tmpX = 66, tmpY = 8;
			for (int i = 1; i <= 6; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++, tmpY++;
			}
		}
		/////////////////////////////////////////////////////////////////////             U
		if (now >= 8) {
			TextColor(8 + (now + 8 - 6) % 8);
			gotoXY(75, 4);
			printf("%c", char(220));
			gotoXY(83, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(75, Y);
				printf("%c", char(219));
			}
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(83, Y);
				printf("%c", char(219));
			}
			for (int X = 76; X <= 82; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}
		/////////////////////////////////////////////////////////////////////       myself
		if (now >= 9) {
			TextColor(14);
			gotoXY(95, 8);
			printf("By Hoang Minh Huy-18APCS1");
			gotoXY(100, 9);
			printf("HCMUS-VNU");

		}
		////////////////////////////////////////////////////////////////////// press

		if (now >= 10) {
			color = 8 + rand() % 8;
			TextColor(color);
			gotoXY(40, 20);
			printf("Press any key to continue...");
		}

		if (now <= 9) {
			while (inputKey() != -1) {}
			Sleep(400);
		}
		else {
			Sleep(400);
			if (inputKey() != -1)
				return;
		}
	}
}
