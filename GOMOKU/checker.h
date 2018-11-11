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
#ifndef CHECKER_H
#define CHECKER_H
bool avalible(int x, int y) {
	return x >= 1 && x <= 20 && y >= 1 && y <= 20;
}
void check_win(int dirrect, int dirrectX[8], int dirrectY[8], int chr[100][100], int x, int y, int player, int depth, int &winner) {
	if (winner) return;
	if (depth == 5) {
		winner = player;
		return;
	}
	int newX = x + dirrectX[dirrect];
	int newY = y + dirrectY[dirrect];
	if (!avalible(newX, newY)) return;
	if (chr[newX][newY] == player)
		check_win(dirrect, dirrectX, dirrectY, chr, newX, newY, player, depth + 1, winner);
}
#endif // !CHECKER_H
