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
#pragma warning (disable : 4996)
#define ll long long
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
#ifndef CONSOLE_FUNCTION_H
#define CONSOLE_FUNCTION_H
struct point {
	int x, y;
};
long long Rand(long long l, long long h);
int inputKey();
void absorb_input();
void clrscr();
void gotoXY(int column, int line);
void TextColor(int color);
void appear_pointer();
void hide_pointer();
#endif // !CONSOLE_FUNCTION_H
