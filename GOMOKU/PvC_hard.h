#pragma once
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
#ifndef PvC_HARD_H
#define PvC_HARD_H
ll cal(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll atk_row(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll atk_col(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll atk_main_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll atk_other_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll def_row(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll def_col(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll def_main_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
ll def_other_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
int PvC_hard_data(char player1, char player2);
int PvC_hard(int saved_game, char player1, char player2);
point calculate(point pos[100][100], int dd[100][100], int chr[100][100]);
void reset_data_PvC_hard(point pos[100][100], int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn);
void load_PvC_hard(int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn);
void save_PvC_hard(int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn);
#endif // !PvC_HARD_H
