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
#include"checker.h"
#include"console_function.h"
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
#ifndef BOT_H
#define BOT_H
db atk_col(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
db atk_row(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
db atk_main_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
db atk_other_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
/////////////////////////////////////////////////////////
db def_col(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
db def_row(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
db def_main_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
db def_other_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);
//////////////////////////////////////////////////////////////////////////////////////
db cal(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y);

point calculate(point pos[100][100], int dd[100][100], int chr[100][100]);

#endif // !BOT_H
