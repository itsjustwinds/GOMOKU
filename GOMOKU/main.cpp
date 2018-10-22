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
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct point {
	int x, y;
};

point pos[100][100],trc[100][100],last_move;

int dd[100][100], winner,color[100][100],New_game,turn;

char chr[100][100];
/////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& cout, const string &a) {
	for (int i = 0; i < (int)a.size(); ++i)
		cout << a[i];
	return cout;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();
		return key;
	}
	return -1;
}

void absorb_input() {
	while (inputKey() != -1) {}
}

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void hide_pointer() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = 0;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

void appear_pointer() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = 1;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
bool avalible(int x, int y) {
	return x >= 1 && x <= 13 && y >= 1 && y <= 13;
}

void check(int x, int y, int directX, int directY, char k, int dem) {
	if (dem == 5) {
		if (k == 'X') winner = 1;
		if (k == 'O') winner = 2;
		return;
	}
	if (avalible(x, y) == 0 || chr[x][y] != k) return;
	check(x + directX, y + directY, directX, directY, k, dem + 1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void splash_screen() {
	int now = 0, color;
	hide_pointer();
	while (++now) {
		//clrscr();
	///////////////////////////////////////////////////////////////////////////        G
		TextColor(8 + (now + 8 - 1) % 8);
		if (now >= 1) {
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(20, Y);
				printf("%c", char(219));
			}
		}

		if (now >= 2) {
			for (int X = 21; X <= 28; ++X) {
				gotoXY(X, 4);
				printf("%c", char(220));
			}
			for (int X = 21; X <= 28; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}

		if (now >= 3) {
			for (int Y = 12; Y >= 11; --Y) {
				gotoXY(29, Y);
				printf("%c", char(219));
			}
			for (int X = 28; X <= 30; ++X) {
				gotoXY(X, 10);
				printf("%c", char(220));
			}
		}
		/////////////////////////////////////////////////////////////////////////////   O
		TextColor(8 + (now + 8 - 2) % 8);
		if (now >= 4) {
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(33, Y);
				printf("%c", char(219));
			}
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(41, Y);
				printf("%c", char(219));
			}
			for (int X = 34; X <= 40; ++X) {
				gotoXY(X, 4);
				printf("%c", char(220));
			}
			for (int X = 34; X <= 40; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}
		///////////////////////////////////////////////////////////////////////////////   M
		TextColor(8 + (now + 8 - 3) % 8);
		if (now >= 5) {
			gotoXY(44, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(44, Y);
				printf("%c", char(219));
			}
			gotoXY(52, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(52, Y);
				printf("%c", char(219));
			}
			int tmpX = 45, tmpY = 5;
			for (int i = 1; i <= 4; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++; tmpY++;
			}
			tmpX--; tmpY--;
			for (int i = 1; i <= 4; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++; tmpY--;
			}
		}
		////////////////////////////////////////////////////////////////////////////      O
		if (now >= 6) {
			TextColor(8 + (now + 8 - 4) % 8);
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(55, Y);
				printf("%c", char(219));
			}
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(63, Y);
				printf("%c", char(219));
			}
			for (int X = 56; X <= 62; ++X) {
				gotoXY(X, 4);
				printf("%c", char(220));
			}
			for (int X = 56; X <= 62; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}
		/////////////////////////////////////////////////////////////////////////        K
		if (now >= 7) {
			TextColor(8 + (now + 8 - 5) % 8);
			gotoXY(66, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(66, Y);
				printf("%c", char(219));
			}
			int tmpX = 66, tmpY = 9;
			for (int i = 1; i <= 5; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++, tmpY--;
			}
			gotoXY(tmpX, tmpY);
			printf("%c", char(220));
			tmpX = 66, tmpY = 8;
			for (int i = 1; i <= 6; ++i) {
				gotoXY(tmpX, tmpY);
				printf("%c", char(219));
				tmpX++, tmpY++;
			}
		}
		/////////////////////////////////////////////////////////////////////             U
		if (now >= 8) {
			TextColor(8 + (now + 8 - 6) % 8);
			gotoXY(75, 4);
			printf("%c", char(220));
			gotoXY(83, 4);
			printf("%c", char(220));
			for (int Y = 5; Y <= 12; ++Y) {
				gotoXY(75, Y);
				printf("%c", char(219));
			}
			for (int Y = 5; Y <= 13; ++Y) {
				gotoXY(83, Y);
				printf("%c", char(219));
			}
			for (int X = 76; X <= 82; ++X) {
				gotoXY(X, 13);
				printf("%c", char(219));
			}
		}
		/////////////////////////////////////////////////////////////////////       myself
		if (now >= 9) {
			TextColor(14);
			gotoXY(95, 8);
			printf("By Hoang Minh Huy-18APCS1");
			gotoXY(100, 9);
			printf("HCMUS-VNU");

		}
		////////////////////////////////////////////////////////////////////// press

		if (now >= 10) {
			color = 8 + rand() % 8;
			TextColor(color);
			gotoXY(40, 20);
			printf("Press any key to continue...");
		}

		if (now <= 9) {
			while (inputKey() != -1) {}
			Sleep(400);
		}
		else {
			Sleep(400);
			if (inputKey() != -1)
				return;
		}
	}
}

void game_introduction() {
	hide_pointer();
	absorb_input();
	clrscr();
	while (1) {
		clrscr();
		TextColor(14);
		gotoXY(35, 1);
		printf("     This is a simple CARO game");
		TextColor(15);
		gotoXY(20, 4);
		printf("- Each turn, you or your opponent can place one owned symbol to the table.");
		gotoXY(20, 5);
		printf("- To win this game, your symbols must be 5 in a row or a diagonal.");
		gotoXY(20, 6);
		printf("- There is no timer, think carefully before do your choice.\n\n\n\n\n");
		////////////////////////////////////////////////////////////////////////////////////////////
		TextColor(11);
		printf("                          CCCCCCC            A           RRRRRR             OOOOO      \n");
		printf("                         CCC     CC         AAA          RR    RR         OO     OO    \n");
		printf("                        CC                 AA AA         RR     RR       OO       OO   \n");
		printf("                       CCC                AA   AA        RR    RR        OO       OO   \n");
		printf("                        CC               AAAAAAAAA       RRRRR           OO       OO   \n");
		printf("                         CCC     CC     AA       AA      RR   RR          OO     OO    \n");
		printf("                          CCCCCCC      AA         AA     RR     RR          OOOOO      \n");
		gotoXY(35, 25);
		TextColor(13);
		printf("Press any key to continue !");
		while (1) {
			if (inputKey() != -1) return;
			Sleep(1);
		}
	}
}

void load_game_PvP() {
	if (New_game) {
		turn = 1;
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				chr[i][j] = '.';
		return;
	}
	ifstream Fin("data_PvP.txt");
	int ok=0;
	while (Fin >>turn) {
		ok = 1;
		break;
	}
	if (!ok) {
			New_game = 1;
			load_game_PvP();
			Fin.close();
			return;
		}
	//////////////////////////////////////////////////////////////
	Fin >> last_move.x >> last_move.y;
	///////////////////////////////////////////////////// trc[][]
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> trc[i][j].x >> trc[i][j].y;
	///////////////////////////////////////////////////// dd[][]
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> dd[i][j];
	///////////////////////////////////////////////////// color[][]
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> color[i][j];
	//////////////////////////////////////////////////// chr[][]
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			Fin >> chr[i][j];
	Fin.close();
}
void save_PvP() {
	ofstream Fout("data_PvP.txt");
	Fout << turn << " " << last_move.x << " " << last_move.y << "\n";
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
		Fout << trc[i][j].x << " " << trc[i][j].y << " ";
		Fout << "\n";
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			Fout << dd[i][j] << " ";
		Fout << "\n";
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			Fout << color[i][j] << " ";
		Fout << "\n";
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			Fout << chr[i][j];
		Fout << "\n";
	}
	Fout.close();
}
void PvP_data() {
	hide_pointer();
	int x = 38, y = 15;
	int minn = 15, maxx = 16;
	while (1) {
		clrscr();
		absorb_input();
		gotoXY(40, 5);
		TextColor(14);
		printf("LOAD GAME !");
		TextColor(12);
		gotoXY(40, 15);
		printf("New Game");
		gotoXY(40, 16);
		printf("saved game");
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
				if (tmp == 13) {
					if (y == 15) {
						New_game = 1;
						return;
					}
					if (y == 16) {
						New_game = 0;
						return;
					}
				}
			}
			else Sleep(1);
		}
	}
}
void PvP() {
	//left-top: (5,3)
	//left-bottom: (5,25)
	//right-top: (57,3)
	//right-bottom: (57,25)
	hide_pointer();
	absorb_input();
	clrscr();
	load_game_PvP();
	while (1) {
		clrscr();
		gotoXY(80, 2);
		TextColor(15);
		printf("UNDO: Shift+U");
		////////////////////////////////////////////////////////////// line
		TextColor(14);
		int cnt = 0;
		gotoXY(7, 0);
		printf("1   2   3   4   5   6   7   8   9  10  11  12   13");
		TextColor(11);
		printf("    X");
		TextColor(14);
		for (int Y = 2; Y <= 26; Y += 2) {
			++cnt;
			gotoXY(2, Y);
			printf("%d", cnt);
		}
		TextColor(11);
		gotoXY(2, 28);
		printf("Y");
		TextColor(13);
		for (int Y = 1; Y <= 27; Y += 2) {
			gotoXY(6, Y);
			for (int i = 1; i <= 77; ++i) {
				if (i % 2) printf("%c", char(196));
				else if (i % 3 == 0)printf("%c", char(197));
			}
		}
		//////////////////////////////////////////////////////////////// sympol
		for (int Y = 2; Y <= 27; Y += 2) {
			gotoXY(6, Y);
			int cnt = 1;
			for (int i = 1; i <= 53; ++i)
				if (i % 4 == 2) {
					printf(" ");
					pos[cnt][Y / 2] = { 5 + i,Y };
					++cnt;
				}
				else if (i % 4 == 0)
					printf("%c", char(179));
				else printf(" ");
		}
		////////////////////////////////////////////////////////////////////// first and last columm
		for (int Y = 1; Y <= 27; ++Y) {
			gotoXY(5, Y);
			if (Y % 4 != 1 && Y % 4 != 3)printf("%c", char(179));
			else printf("%c", char(195));
		}
		for (int Y = 1; Y <= 27; ++Y) {
			gotoXY(57, Y);
			if (Y % 4 != 1 && Y % 4 != 3)printf("%c", char(179));
			else printf("%c", char(180));
		}
		///////////////////////////////////////////////////////////////////////first and last line
		for (int X = 5; X <= 57; ++X) {
			gotoXY(X, 1);
			if (X % 4 != 1)printf("%c", char(196));
			else printf("%c", char(194));
		}
		for (int X = 5; X <= 57; ++X) {
			gotoXY(X, 27);
			if (X % 4 != 1)printf("%c", char(196));
			else printf("%c", char(193));
		}
		//////////////////////////////////////////////////////////////////////////
		gotoXY(5, 1);
		printf("%c", char(218));
		gotoXY(5, 27);
		printf("%c", char(192));
		gotoXY(57, 1);
		printf("%c", char(191));
		gotoXY(57, 27);
		printf("%c", char(217));
		///////////////////////////////////////////////////////////////////////////
		for (int i = 1; i <= 13; ++i)
			for (int j = 1; j <= 13; ++j)
				if (dd[i][j]) {
					int X = pos[i][j].x;
					int Y = pos[i][j].y;
					gotoXY(X, Y);
					if (chr[i][j] == 'X') {
						TextColor(color[i][j]);
						printf("X");
					}
					else {
						TextColor(color[i][j]);
						printf("O");
					}
				}
		/////////////////////////////////////////////////////////////////////////// check for winner
		for (int X = 1; X <= 13; ++X)
			for (int Y = 1; Y <= 13; ++Y)
				if (dd[X][Y]==1) {
					////////// up
					check(X, Y - 1, 0, -1, chr[X][Y], 1);
					////////// down
					check(X, Y + 1, 0, 1, chr[X][Y], 1);
					////////// left
					check(X - 1, Y, -1, 0, chr[X][Y], 1);
					//////////right
					check(X + 1, Y, 1, 0, chr[X][Y], 1);
					//////////up-left
					check(X - 1, Y - 1, -1, -1, chr[X][Y], 1);
					//////////up-right
					check(X + 1, Y - 1, 1, -1, chr[X][Y], 1);
					/////////down-left
					check(X - 1, Y + 1, -1, 1, chr[X][Y], 1);
					/////////down-right
					check(X + 1, Y + 1, 1, 1, chr[X][Y], 1);
				}
		if (winner) {
			while (1) {
				clrscr();
				gotoXY(45, 5);
				TextColor(9);
				printf("     winner is player \n\n");
				TextColor(8 + rand() % 8);
				if (winner == 1) {
					printf("                                                        111          \n");
					printf("                                                      11111          \n");
					printf("                                                     111111          \n");
					printf("                                                        111          \n");
					printf("                                                        111          \n");
					printf("                                                        111          \n");
					printf("                                                        111          \n");
					printf("                                                     11111111        \n");
				}
				else {
					printf("                                                      222222         \n");
					printf("                                                     22    222       \n");
					printf("                                                    22      222      \n");
					printf("                                                     22     22       \n");
					printf("                                                           22        \n");
					printf("                                                          22         \n");
					printf("                                                         22          \n");
					printf("                                                       222           \n");
					printf("                                                      222222222      \n");
				}
				TextColor(15);
				gotoXY(50, 25);
				printf("press any key to exit");
				Sleep(500);
				if (inputKey() != -1)
					return;
			}
		}
		///////////////////////////////////////////////////////////////////////////
		gotoXY(65, 5);
		TextColor(12);
		printf("press directional key to do your move : player %d!", turn);
		gotoXY(65, 8);
		printf("press ENTER to mark it as your symbol.");
		TextColor(15);
		point now = { 1,1 };
		while (1) {
			int X = pos[now.x][now.y].x;
			int Y = pos[now.y][now.y].y;
			gotoXY(X, Y);
			TextColor(7);
			printf("%d",turn);
			int tmp = inputKey();
			if (tmp != -1) {
				if (tmp == 'S') {
					save_PvP();
					continue;
				}
				if (tmp == 'U') {
					if (last_move.x == 0 &&last_move.y == 0) continue;
					turn = 3 - turn;
					chr[last_move.x][last_move.y] = 0;
					dd[last_move.x][last_move.y] = 0;
					last_move = trc[last_move.x][last_move.y];
					break;
				}
				if (tmp == 72) {
					if (!avalible(now.x, now.y - 1)) continue;
					gotoXY(X, Y);
					TextColor(color[now.x][now.y]);
					printf("%c", chr[now.x][now.y]);
					X = pos[now.x][now.y - 1].x;
					Y = pos[now.x][now.y - 1].y;
					gotoXY(X, Y);
					TextColor(7);
					printf("%d",turn);
					now.y--;	
					continue;
				}
				if (tmp == 80) {
					if (!avalible(now.x, now.y + 1)) continue;
					gotoXY(X, Y);
					TextColor(color[now.x][now.y]);
					printf("%c", chr[now.x][now.y]);
					X = pos[now.x][now.y + 1].x;
					Y = pos[now.x][now.y + 1].y;
					gotoXY(X, Y);
					TextColor(7);
					printf("%d",turn);
					now.y++;
					continue;
				}
				if (tmp == 75) {
					if (!avalible(now.x - 1, now.y)) continue;
					gotoXY(X, Y);
					TextColor(color[now.x][now.y]);
					printf("%c", chr[now.x][now.y]);
					X = pos[now.x - 1][now.y].x;
					Y = pos[now.x - 1][now.y].y;
					gotoXY(X, Y);
					TextColor(7);
					printf("%d",turn);
					now.x--;
					continue;
				}
				if (tmp == 77) {
					if (!avalible(now.x + 1, now.y)) continue;
					gotoXY(X, Y);
					TextColor(color[now.x][now.y]);
					printf("%c", chr[now.x][now.y]);
					X = pos[now.x + 1][now.y].x;
					Y = pos[now.x + 1][now.y].y;
					gotoXY(X, Y);
					TextColor(7);
					printf("%d",turn);
					now.x++;
					continue;
				}
				if (tmp == 13) {
					if (dd[now.x][now.y])
					{
						absorb_input();
						break;
					}
					dd[now.x][now.y] = 1;
					color[now.x][now.y] = 8 + rand() % 8;
					if (turn == 1) chr[now.x][now.y] = 'X';
					else chr[now.x][now.y] = 'O';
					turn = 3 - turn;
					absorb_input();
					trc[now.x][now.y] = last_move;
					last_move = { now.x,now.y };
					break;
				}
			}
			else Sleep(1);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void game_menu() {
	clrscr();
	absorb_input();
	hide_pointer();
	int x=38, y=15;
	int minn = 15, maxx = 15;
	while (1) {
		clrscr();
		absorb_input();
		TextColor(14);
		gotoXY(40, 5);
		printf("Please select game mode and press ENTER");
		//////////////////////////////////////////
		TextColor(12);
		gotoXY(40, 15);
		printf("Player vs Player");

		//gotoXY(40, 16);
		//printf("choose2");

		//gotoXY(40, 17);
		//printf("choose3");
		/////////////////////////////////////////////////////////////////
		gotoXY(x, y);
		printf("%c", char(175));
		while (1) {
			int tmp=inputKey();
			if (tmp!=-1) {
				if (tmp == 72) {
					if (y>minn)y--;
					break;
				}
				if (tmp == 80) {
					if (y<maxx)y++;
					break;
				}
				if (tmp == 13) {
					if (y == 15) {
						PvP_data();
						PvP();
						return;
					}
				}
			}
			else Sleep(1);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS);
	SetConsoleMode(hin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	splash_screen();
	game_introduction();
	game_menu();
}
