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
#ifndef WIN_ANIMATION_H
#define WIN_ANIMATION_H
void win_animation(int winner) {
	srand(time(NULL));
	if (winner) {
		while (1) {
			clrscr();
			gotoXY(70, 10);
			TextColor(9);
			printf("        winner is player \n\n");
			TextColor(8+Rand(0,10000)%8);
			if (winner == 1) {
				printf("                                                                                      111          \n");
				printf("                                                                                    11111          \n");
				printf("                                                                                   111111          \n");
				printf("                                                                                      111          \n");
				printf("                                                                                      111          \n");
				printf("                                                                                      111          \n");
				printf("                                                                                      111          \n");
				printf("                                                                                   11111111        \n");
			}
			else {
				printf("                                                                                    222222         \n");
				printf("                                                                                   22    222       \n");
				printf("                                                                                  22      222      \n");
				printf("                                                                                   22     22       \n");
				printf("                                                                                         22        \n");
				printf("                                                                                        22         \n");
				printf("                                                                                       22          \n");
				printf("                                                                                     222           \n");
				printf("                                                                                    222222222      \n");
			}
			TextColor(15);
			gotoXY(75, 40);
			printf("press any key to exit");
			Sleep(500);
			if (inputKey() != -1)
				return;
		}
	}
}
#endif // !WIN_ANIMATION_H