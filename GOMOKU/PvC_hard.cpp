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
#include"PvC_menu.h"
#include"PvC_hard.h"
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
ll atk_col(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x, y - i))
			break;
		if (chr[x][y - i] == 0) break;
		if (chr[x][y - i] == 1) {
			enermy++;
			break;
		}
		if (chr[x][y - i] == 2) ++owned;
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x, y + i))
			break;
		if (chr[x][y + i] == 0) break;
		if (chr[x][y + i] == 1) {
			enermy++;
			break;
		}
		if (chr[x][y + i] == 2) ++owned;
	}
	if (enermy == 2) return 0;
	return pointATK[owned] - pointDEF[enermy];
}
ll atk_row(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y ))
			break;
		if (chr[x - i][y] == 0)break;
		if (chr[x - i][y] == 1) {
			enermy++;
			break;
		}
		if (chr[x - i][y] == 2) ++owned;
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x + i, y))
			break;
		if (chr[x + i][y] == 0) break;
		if (chr[x + i][y] == 1) {
			enermy++;
			break;
		}
		if (chr[x + i][y] == 2) ++owned;
	}
	if (enermy == 2) return 0;
	return pointATK[owned] - pointDEF[enermy];
}
ll atk_main_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y - i))
			break;
		if (chr[x - i][y - i] == 0) break;
		if (chr[x - i][y - i] == 1) {
			enermy++;
			break;
		}
		if (chr[x - i][y - i] == 2) ++owned;
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x + i, y + i))
			break;
		if (chr[x + i][y + i] == 0) break;
		if (chr[x + i][y + i] == 1) {
			enermy++;
			break;
		}
		if (chr[x + i][y + i] == 2) ++owned;
	}
	if (enermy == 2) return 0;
	return pointATK[owned] - pointDEF[enermy];
}
ll atk_other_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y + i))
			break;
		if (chr[x - i][y + i] == 0) break;
		if (chr[x - i][y + i] == 1) {
			enermy++;
			break;
		}
		if (chr[x - i][y + i] == 2) ++owned;
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x + i, y - i))
			break;
		if (chr[x + i][y - i] == 0) break;
		if (chr[x + i][y - i] == 1) {
			enermy++;
			break;
		}
		if (chr[x + i][y - i] == 2) ++owned;
	}
	if (enermy == 2) return 0;
	return pointATK[owned] - pointDEF[enermy];
}
/////////////////////////////////////////////////////////
ll def_col(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x, y - i))
			break;
		if (chr[x][y - i] == 0) break;
		if (chr[x][y - i] == 1) enermy++;
		if (chr[x][y - i] == 2) {
			++owned;
			break;
		}
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x, y + i))
			break;
		if (chr[x][y + i] == 0) break;
		if (chr[x][y + i] == 1) enermy++;
		if (chr[x][y + i] == 2) {
			++owned;
			break;
		}
	}
	return pointDEF[enermy] - pointATK[owned];
}
ll def_row(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y))
			break;
		if (chr[x - i][y] == 0) break;
		if (chr[x - i][y] == 1) enermy++;
		if (chr[x - i][y] == 2) {
			++owned;
			break;
		}
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x + i, y))
			break;
		if (chr[x + i][y] == 0) break;
		if (chr[x + i][y] == 1) enermy++;
		if (chr[x + i][y] == 2) {
			++owned;
			break;
		}
	}
	return pointDEF[enermy] - pointATK[owned];
}
ll def_main_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y - i))
			break;
		if (chr[x - i][y - i] == 0) break;
		if (chr[x - i][y - i] == 1) enermy++;
		if (chr[x - i][y - i] == 2) {
			++owned;
			break;
		}
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x + i, y + i))
			break;
		if (chr[x + i][y + i] == 0) break;
		if (chr[x + i][y + i] == 1) enermy++;
		if (chr[x + i][y + i] == 2) {
			++owned;
			break;
		}
	}
	return pointDEF[enermy] - pointATK[owned];
}
ll def_other_dia(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y + i))
			break;
		if (chr[x - i][y + i] == 0) break;
		if (chr[x - i][y + i] == 1) enermy++;
		if (chr[x - i][y + i] == 2) {
			++owned;
			break;
		}
	}
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x + i, y - i))
			break;
		if (chr[x + i][y - i] == 0) break;
		if (chr[x + i][y - i] == 1) enermy++;
		if (chr[x + i][y - i] == 2) {
			++owned;
			break;
		}
	}
	return pointDEF[enermy] - pointATK[owned];
}
//////////////////////////////////////////////////////////////////////////////////////
ll cal(ll pointATK[7], ll pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	ll res = 0;
	res += atk_col(pointATK, pointDEF, dd, chr, x, y) + atk_row(pointATK, pointDEF, dd, chr, x, y) + atk_main_dia(pointATK, pointDEF, dd, chr, x, y) + atk_other_dia(pointATK, pointDEF, dd, chr, x, y);
	res += def_col(pointATK, pointDEF, dd, chr, x, y) + def_row(pointATK, pointDEF, dd, chr, x, y) + def_main_dia(pointATK, pointDEF, dd, chr, x, y) + def_other_dia(pointATK, pointDEF, dd, chr, x, y);
	return res;
}

point calculate(point pos[100][100], int dd[100][100], int chr[100][100]) {
	point res;
	ll maximum = -1e18;
	ll pointATK[7] = { 0 ,9 ,36 ,144, 576, 2304, 9216 };
	ll pointDEF[7] = { 0 ,4 ,24 , 144 ,864 ,5184, 31104};
	vector<point > need_to_check;
	need_to_check.clear();
	int dirrectX[8] = { -1,-1,-1,0,1,1,1,0 };
	int dirrectY[8] = { -1,0,1,1,1,0,-1,-1 };
	for (int i=1;i<=20;++i)
		for (int j = 1; j <= 20; ++j) {
			if (chr[i][j] == 0) continue;
			for (int dirrect = 0; dirrect < 8; ++dirrect) {
				int x = i + dirrectX[dirrect];
				int y = j + dirrectY[dirrect];
				if (!avalible(x, y) || chr[x][y] != 0) continue;
				need_to_check.push_back({ x, y });
			}
		}
	for (int now=0;now<need_to_check.size();++now){
		int i = need_to_check[now].x;
		int j = need_to_check[now].y;
		if (chr[i][j]) continue;
		ll tmp = cal( pointATK, pointDEF, dd, chr, i, j);
		if (tmp > maximum) {
			maximum = tmp;
			res = { i,j };
		}
	}
	return res;
}

void reset_data_PvC_hard(point pos[100][100], int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn) {
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

void load_PvC_hard(int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn) {
	ifstream Fin("PvC_hard_data.txt");
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

void save_PvC_hard(int dd[100][100], int chr[100][100], point pre[100][100], point &now, point &Last, int &turn) {
	ofstream Fout("PvC_hard_data.txt");
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

int PvC_hard(int saved_game, char player1, char player2) {
	point pos[100][100], now, pre[100][100], Last;
	int dd[100][100], turn;
	int chr[100][100];
	int done = 0;
	reset_data_PvC_hard(pos, dd, chr, pre, now, Last, turn);
	if (saved_game) load_PvC_hard(dd, chr, pre, now, Last, turn);
	clrscr();
	while (1) {
		hide_pointer();
		absorb_input();
		if (turn == 2) {
			point result = calculate(pos,dd,chr);
			chr[result.x][result.y] = turn;
			dd[result.x][result.y] = 1;
			pre[result.x][result.y] = Last;
			turn = 3 - turn;
			Last = result;
			continue;
		}
		if (draw_board(pos, dd, chr, player1, player2, done) == 1) {
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
					save_PvC_hard(dd, chr, pre, now, Last, turn);
					continue;
				}
				if (tmp == 'u') {
					dd[Last.x][Last.y] = 0;
					chr[Last.x][Last.y] = 0;
					Last = pre[Last.x][Last.y];
					turn = 3 - turn;
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

int PvC_hard_data(char player1, char player2) {
	clrscr();
	absorb_input();
	hide_pointer();
	gotoXY(0, 0);
	TextColor(12);
	printf("[R] : return");
	int x = 58, y = 15;
	int minn = 15, maxx = 16;
	while (1) {
		for (int i = 15; i <= 19; ++i) {
			gotoXY(58, i);
			printf(" ");
		}
		absorb_input();
		TextColor(14);
		gotoXY(60, 5);
		printf("Hard");
		TextColor(12);
		gotoXY(60, 15);
		printf("New game");
		gotoXY(60, 16);
		printf("Saved game");///////////////////////////////////////////////
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
					return 0;
				}
				if (tmp == 13) {
					if (y == 15) {
						return PvC_hard(0, player1, player2);
					}
					if (y == 16) {
						return PvC_hard(1, player1, player2);
					}
				}
			}
			else Sleep(1);
		}
	}
}