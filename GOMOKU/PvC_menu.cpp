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
#include"PvC_hard.h"
#include"PvC_menu.h"
#include"PvC_normal.h"
#include"PvC_easy.h"
#include"PvP.h"
#include"splash_screen.h"
#include"win_animation.h"
#include"BOT.h"
#include"statistics.h"
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
int PvC_menu(char player1, char player2) {
	clrscr();
	absorb_input();
	hide_pointer();
	int x = 58, y = 15;
	int minn = 15, maxx = 18;
	while (1) {
		gotoXY(0, 0);
		TextColor(12);
		printf("[R] : return");
		for (int i = 15; i <= 19; ++i) {
			gotoXY(58, i);
			printf(" ");
		}
		absorb_input();
		TextColor(14);
		gotoXY(60, 5);
		printf("Player vs Computer");
		TextColor(12);
		gotoXY(60, 15);
		printf("Easy");
		gotoXY(60, 16);
		printf("Normal");
		gotoXY(60, 17);
		printf("Hard");
		gotoXY(60, 18);
		printf("Statistics");
		/////////////////////////////////////////////////////////////////
		gotoXY(x, y);
		printf("%c", char(175));
		while (1) {
			int tmp = inputKey();
			if (tmp != -1) {
				if (tmp == 72) {
					if (y > minn)y--;
					break;
				}
				if (tmp == 80) {
					if (y < maxx)y++;
					break;
				}
				if (tmp == 'r') {
					return 0;
				}
				if (tmp == 13) {
					if (y == 15) {
						if (PvC_easy_data(player1, player2) == 0) {
							clrscr();
							break;
						}
						return 1;
					}
					if (y == 16) {
						if (PvC_normal_data(player1,player2)==0) {
							clrscr();
							break;
						}
						return 1;
					}
					if (y == 17) {
						if (PvC_hard_data(player1, player2) == 0) {
							clrscr();
							break;
						}
						return 1;
					}
					if (y == 18) {
						statistics(1,0,0,1);
						clrscr();
						break;
					}
				}
			}
			else Sleep(1);
		}
	}
}