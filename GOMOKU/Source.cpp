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
//////////////////////////////////////////////////////////////////////////////////////////////////////
int game() {
	splash_screen();
	return main_menu();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	srand(time(NULL));
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS);
	SetConsoleMode(hin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		if (game() == 0) break;
	}
}