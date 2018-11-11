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
#include"console_function.h"
#include"introduction.h"
#include"PvP.h"
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
#ifndef MAIN_MENU_H
#define MAIN_MENU_H
void get_icon(char &player1,char &player2) {
	ifstream Fin("data_icon.txt");
	Fin >> player1;
	Fin >> player2;
	Fin.close();
}
void get_symbol(char &x) {
	clrscr();
	absorb_input();
	gotoXY(60, 15);
	printf("type your symbol: ");
	while (1) {
		int tmp = inputKey();
		if (tmp != ' ' && tmp != -1) {
			x = char(tmp);
			return;
		}
		else Sleep(1);
	}
}
void update_icon(char player1, char player2) {
	ofstream Fout("data_icon.txt");
	Fout << player1 << player2;
	Fout.close();
}
void icon_change(char player1, char player2) {
	int x = 58, y = 15;
	int minn = 15, maxx = 16;
	while (1) {
		get_icon(player1, player2);
		clrscr();
		absorb_input();
		TextColor(12);
		gotoXY(0, 0);
		printf("[R] to exit");
		gotoXY(60, 15);
		printf("Player 1: %c", player1);
		gotoXY(60, 16);
		printf("Player 2: %c", player2);
		////////////////////////////////////////////////////
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
					return;
				}
				if (tmp == 13) {
					char symbol;
					get_symbol(symbol);
					if (y == 15) player1 = symbol;
					else player2 = symbol;
					update_icon(player1, player2);
					break;
				}
			}
			else Sleep(1);
		}
	}
}
int main_menu() {
	clrscr();
	absorb_input();
	hide_pointer();
	int x = 58, y = 15;
	int minn = 15, maxx = 19;
	char player1, player2;
	while (1) {
		get_icon(player1, player2);
		clrscr();
		absorb_input();
		TextColor(14);
		gotoXY(60, 5);
		printf("Please select game mode and press ENTER");
		//////////////////////////////////////////
		TextColor(12);
		gotoXY(60, 15);
		printf("Player vs Player");
		gotoXY(60, 16);
		printf("Player vs computer");
		gotoXY(60, 17);
		printf("Game introduction");
		gotoXY(60, 18);
		printf("Icon");
		gotoXY(60, 19);
		printf("Exit");
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
				if (tmp == 13) {
					if (y == 15) {
						if (PvP_data(player1,player2) == 1)
							return 0;
						return 1;
					}
					/*if (y == 16) {
						PvC_data();
						if (back) {
							back = 0;
							break;
						}
						return;
					}*/
					if (y == 17) {
						game_introduction();
						break;
					}
					if (y == 18) {
						icon_change(player1,player2);
						break;
					}
					if (y == 19) {
						return 0;
					}
				}
			}
			else Sleep(1);
		}
	}
}
#endif // !MAIN_MENU_H
