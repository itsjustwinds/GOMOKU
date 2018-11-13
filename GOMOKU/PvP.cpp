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
void reset_data(point pos[100][100], int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn) {
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j) {
			pos[i][j] = { 0,0 };
			pre[i][j] = { 0,0 };
		}
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			dd[i][j] = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			chr[i][j] = 0;
	now = { 1,1 };
	Last = { 0,0 };
	turn = 1;
}
void load_PvP(int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn) {
	ifstream Fin("PvP_data.txt");
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> dd[i][j];
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> pre[i][j].x >> pre[i][j].y;
	Fin >> now.x >> now.y;
	Fin >> Last.x >> Last.y;
	Fin >> turn;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> chr[i][j];
	Fin.close();
}
void save_PvP(int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn) {
	ofstream Fout("PvP_data.txt");
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			Fout << dd[i][j] << " ";
		Fout << "\n";
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			Fout << pre[i][j].x << " " << pre[i][j].y << " ";
		Fout << "\n";
	}
	Fout << now.x << " " << now.y << " ";
	Fout << Last.x << " " << Last.y << " ";
	Fout << turn << "\n";
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			Fout << chr[i][j] << " ";
		Fout << "\n";
	}
	Fout.close();
}
int PvP(int saved_game, char player1, char player2) {
	point pos[100][100], now, pre[100][100], Last;
	int dd[100][100], turn;
	int chr[100][100];
	int done = 0;
	reset_data(pos, dd, chr, pre, now, Last, turn);
	if (saved_game) load_PvP(dd, chr, pre, now, Last, turn);
	clrscr();
	while (1) {
		hide_pointer();
		absorb_input();
		if (draw_board(pos, dd, chr, player1, player2,done,0) ) {
			return 1;
		}
		done = 1;
		while (1) {
			TextColor(8);
			gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
			printf("%d", turn);
			int tmp = inputKey();
			if (tmp != -1) {
				if (tmp == F9) {
					return 1;
				}
				if (tmp == F5) {
					save_PvP(dd, chr, pre, now, Last, turn);
					continue;
				}
				if (tmp == 'u') {
					dd[Last.x][Last.y] = 0;
					chr[Last.x][Last.y] = 0;
					Last = pre[Last.x][Last.y];
					turn = 3 - turn;
					break;
				}
				if (tmp == 72) {
					if (!avalible(now.x, now.y - 1)) continue;
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					if (chr[now.x][now.y] == 1) TextColor(9);
					else TextColor(12);
					if (chr[now.x][now.y] == 1) printf("%c", player1);
					if (chr[now.x][now.y] == 2) printf("%c", player2);
					if (chr[now.x][now.y] == 0) printf(" ");
					now = { now.x,now.y - 1 };
					TextColor(8);
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					printf("%d", turn);
				}
				if (tmp == 80) {
					if (!avalible(now.x, now.y + 1)) continue;
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					if (chr[now.x][now.y] == 1) TextColor(9);
					else TextColor(12);
					if (chr[now.x][now.y] == 1) printf("%c", player1);
					if (chr[now.x][now.y] == 2) printf("%c", player2);
					if (chr[now.x][now.y] == 0) printf(" ");
					now = { now.x,now.y + 1 };
					TextColor(8);
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					printf("%d", turn);
				}
				if (tmp == 75) {
					if (!avalible(now.x - 1, now.y)) continue;
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					if (chr[now.x][now.y] == 1) TextColor(9);
					else TextColor(12);
					if (chr[now.x][now.y] == 1) printf("%c", player1);
					if (chr[now.x][now.y] == 2) printf("%c", player2);
					if (chr[now.x][now.y] == 0) printf(" ");
					now = { now.x - 1,now.y };
					TextColor(8);
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					printf("%d", turn);
				}
				if (tmp == 77) {
					if (!avalible(now.x + 1, now.y)) continue;
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					if (chr[now.x][now.y] == 1) TextColor(9);
					else TextColor(12);
					if (chr[now.x][now.y] == 1) printf("%c", player1);
					if (chr[now.x][now.y] == 2) printf("%c", player2);
					if (chr[now.x][now.y] == 0) printf(" ");
					now = { now.x + 1,now.y };
					TextColor(8);
					gotoXY(pos[now.x][now.y].x, pos[now.x][now.y].y);
					printf("%d", turn);
				}
				if (tmp == 13) {
					if (dd[now.x][now.y]) continue;
					chr[now.x][now.y] = turn;
					dd[now.x][now.y] = 1;
					pre[now.x][now.y] = Last;
					turn = 3 - turn;
					Last = now;
					break;
				}
			}
			else Sleep(1);
		}
	}
	return 0;
}
int PvP_data(char player1, char player2) {
	hide_pointer();
	int x = 38, y = 15;
	int minn = 15, maxx = 16;
	while (1) {
		clrscr();
		absorb_input();
		gotoXY(0, 0);
		printf("[R] : return");
		gotoXY(40, 5);
		TextColor(14);
		printf("LOAD GAME PvP !");
		TextColor(12);
		gotoXY(40, 15);
		printf("New Game");
		gotoXY(40, 16);
		printf("saved game");
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
					absorb_input();
					return 0;
				}
				if (tmp == 13) {
					if (y == 15) {
						return PvP(0, player1, player2);
					}
					if (y == 16) {
						return PvP(1, player1, player2);
					}
				}
			}
			else Sleep(1);
		}
	}
}
