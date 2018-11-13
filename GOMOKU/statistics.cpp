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
#include"PvP.h"
#include"splash_screen.h"
#include"win_animation.h"
#include"BOT.h"
#include"statistics.h"
#pragma warning (disable : 4996)
#define ll long long
#define db double
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
int statistics(int show,int player1,int player2,int mode) {
	point easy, normal, hard;
	ifstream Fin("statistics.txt");
	Fin >> easy.x >> easy.y >> normal.x >> normal.y >> hard.x >> hard.y;
	Fin.close();
	if (show) {
		clrscr();
		gotoXY(60, 5);
		TextColor(12);
		printf("Statistic");
		gotoXY(0, 0);
		printf("[R] : return");
		gotoXY(30, 15);
		printf("Easy   : ");
		gotoXY(30, 16);
		printf("Normal : ");
		gotoXY(30, 17);
		printf("Hard   : ");
		gotoXY(50, 10);
		printf("Win");
		gotoXY(70, 10);
		printf("Lose");
		gotoXY(100, 10);
		printf("Total match");
		gotoXY(50, 15);
		printf("%d", easy.x);
		gotoXY(70, 15);
		printf("%d", easy.y);
		gotoXY(100, 15);
		printf("%d", easy.x + easy.y);
		gotoXY(50, 16);
		printf("%d", normal.x);
		gotoXY(70, 16);
		printf("%d", normal.y);
		gotoXY(100, 16);
		printf("%d", normal.x + normal.y);
		gotoXY(50, 17);
		printf("%d",hard.x);
		gotoXY(70, 17);
		printf("%d", hard.y);
		gotoXY(100, 17);
		printf("%d", hard.x + hard.y);
		while (1) {
			int tmp = inputKey();
			if (tmp == 'r') return 0;
			else Sleep(1);
		}
	}
	if (mode == 1) easy = { easy.x + player1,easy.y + player2 };
	if (mode == 2) normal = { normal.x + player1,normal.y + player2 };
	if (mode == 3) hard = { hard.x + player1,hard.y + player2 };
	ofstream Fout("statistics.txt");
	Fout << easy.x <<" "<< easy.y <<" "<<normal.x <<" "<<normal.y <<" "<< hard.x <<" "<< hard.y;
	Fout.close();
}