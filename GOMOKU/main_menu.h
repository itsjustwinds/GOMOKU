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
void get_icon(char &player1, char &player2);
void get_symbol(char &x);
void update_icon(char player1, char player2);
void icon_change(char player1, char player2);
int main_menu();
#endif // !MAIN_MENU_H
