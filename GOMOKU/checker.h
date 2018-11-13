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
#ifndef CHECKER_H
#define CHECKER_H
bool avalible(int x, int y);
void check_win(int dirrect, int dirrectX[8], int dirrectY[8], int chr[100][100], int x, int y, int player, int depth, int &winner);
#endif // !CHECKER_H
