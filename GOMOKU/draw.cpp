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
int draw_board(point pos[100][100], int dd[100][100], int chr[100][100], char player1, char player2,int done) {
	int dirrectX[8] = { -1,-1,-1,0,1,1,1,0 };
	int dirrectY[8] = { -1,0,1,1,1,0,-1,-1 };
	int winner = 0;
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			if (chr[i][j] == 0) continue;
			for (int dirrect = 0; dirrect < 8; ++dirrect)
				check_win(dirrect, dirrectX, dirrectY, chr, i, j, chr[i][j], 1, winner);
			if (winner) break;
		}
		if (winner) break;
	}
	if (winner) {
		win_animation(winner);
		return 1;
	}
	TextColor(13);
	gotoXY(120, 5);
	printf("Player vs Player");
	TextColor(14);
	gotoXY(100, 12);
	printf("[F9] : back to menu");
	gotoXY(100, 13);
	printf("[F5] : save game");
	gotoXY(100, 14);
	printf("[U] : undo");
	gotoXY(100, 15);
	printf("Use narrow key to move");
	gotoXY(100, 16);
	printf("[ENTER] : choose");

	int x = 5, y = 5;
	for (int j = 0; j < 20; ++j)
		for (int i = 0; i < 20; ++i) {
			pos[i + 1][j + 1] = { x + i * 4,y + j * 2 };
			if (dd[i + 1][j + 1]) {
				if (chr[i + 1][j + 1] == 1) TextColor(9);
				if (chr[i + 1][j + 1] == 2) TextColor(12);
				gotoXY(x + i * 4, y + j * 2);
				if (chr[i + 1][j + 1] == 1) printf("%c", player1);
				if (chr[i + 1][j + 1] == 2) printf("%c", player2);
			}
			else {
				gotoXY(x + i * 4, y + j * 2);
				printf("%c", ' ');
			}
		}
	if (done) return 0;
	TextColor(2);
	x = 3, y = 5;
	for (int j = 0; j < 20; ++j)
		for (int i = 0; i <= 20; ++i) {
			gotoXY(x + i * 4, y + j * 2);
			printf("%c", char(179));
		}
	x = 5, y = 4;
	for (int j = 0; j <= 20; ++j)
		for (int i = 0; i < 20; ++i) {
			gotoXY(x + i * 4, y + j * 2);
			printf("%c", char(196));
			gotoXY(x + i * 4 - 1, y + j * 2);
			printf("%c", char(196));
			gotoXY(x + i * 4 + 1, y + j * 2);
			printf("%c", char(196));
		}
	x = 3, y = 4;
	for (int j = 1; j < 20; ++j)
		for (int i = 0; i <= 20; ++i) {
			gotoXY(x + i * 4, y + j * 2);
			printf("%c", char(197));
		}
	for (int i = 0; i <= 20; ++i) {
		gotoXY(x + i * 4, 4);
		printf("%c", char(194));
		gotoXY(x + i * 4, 44);
		printf("%c", char(193));
	}
	for (int j = 0; j <= 20; ++j) {
		gotoXY(3, y + j * 2);
		printf("%c", char(195));
		gotoXY(83, y + j * 2);
		printf("%c", char(180));
	}
	gotoXY(3, 4);
	printf("%c", char(218));
	gotoXY(83, 4);
	printf("%c", char(191));
	gotoXY(3, 44);
	printf("%c", char(192));
	gotoXY(83, 44);
	printf("%c", char(217));
	return 0;
}
