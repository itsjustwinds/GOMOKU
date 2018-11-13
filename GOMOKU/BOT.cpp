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
db atk_col(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned >= 4) return 1e17;
	if (enermy == 2) return 0;
	return pointATK[owned] / (1 + enermy);
}
db atk_row(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	int owned = 0, enermy = 0;
	for (int i = 1; i <= 5; ++i) {
		if (!avalible(x - i, y))
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
	if (owned >= 4) return 1e17;
	if (enermy == 2) return 0;
	return pointATK[owned] / (1 + enermy);
}
db atk_main_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned >= 4) return 1e17;
	if (enermy == 2) return 0;
	return pointATK[owned] / (1 + enermy);
}
db atk_other_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned >= 4) return 1e17;
	if (enermy == 2) return 0;
	return pointATK[owned] / (1 + enermy);
}
/////////////////////////////////////////////////////////
db def_col(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned == 2) {
		if (enermy >= 4) return 1e17;
		return 0;
	}
	return pointDEF[enermy] / (owned + 1);
}
db def_row(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned == 2) {
		if (enermy >= 4) return 1e17;
		return 0;
	}
	return pointDEF[enermy] / (owned + 1);
}
db def_main_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned == 2) {
		if (enermy >= 4) return 1e17;
		return 0;
	}
	return pointDEF[enermy] / (owned + 1);
}
db def_other_dia(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
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
	if (owned == 2) {
		if (enermy >= 4) return 1e17;
		return 0;
	}
	return pointDEF[enermy] / (owned + 1);
}
//////////////////////////////////////////////////////////////////////////////////////
db cal(db pointATK[7], db pointDEF[7], int dd[100][100], int chr[100][100], int x, int y) {
	db res = 0;
	res += atk_col(pointATK, pointDEF, dd, chr, x, y) + atk_row(pointATK, pointDEF, dd, chr, x, y) + atk_main_dia(pointATK, pointDEF, dd, chr, x, y) + atk_other_dia(pointATK, pointDEF, dd, chr, x, y);
	res += def_col(pointATK, pointDEF, dd, chr, x, y) + def_row(pointATK, pointDEF, dd, chr, x, y) + def_main_dia(pointATK, pointDEF, dd, chr, x, y) + def_other_dia(pointATK, pointDEF, dd, chr, x, y);
	return res;
}

point calculate(point pos[100][100], int dd[100][100], int chr[100][100]) {
	point res;
	db maximum = -1e18;
	db pointATK[7] = { 0 ,9 ,200 ,700, 2000, 2304, 9216 };
	db pointDEF[7] = { 0 ,6 ,150 ,650 ,1500 ,3750, 18750 };
	vector<point > need_to_check;
	need_to_check.clear();
	int dirrectX[8] = { -1,-1,-1,0,1,1,1,0 };
	int dirrectY[8] = { -1,0,1,1,1,0,-1,-1 };
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j <= 20; ++j) {
			if (chr[i][j] == 0) continue;
			for (int dirrect = 0; dirrect < 8; ++dirrect) {
				int x = i + dirrectX[dirrect];
				int y = j + dirrectY[dirrect];
				if (!avalible(x, y) || chr[x][y] != 0) continue;
				need_to_check.push_back({ x, y });
			}
		}
	for (int now = 0; now < need_to_check.size(); ++now) {
		int i = need_to_check[now].x;
		int j = need_to_check[now].y;
		if (i == 13 && j == 13) {
			int tmp = 0;
		}
		if (chr[i][j]) continue;
		db tmp = cal(pointATK, pointDEF, dd, chr, i, j);
		if (tmp > maximum) {
			maximum = tmp;
			res = { i,j };
		}
	}
	return res;
}
