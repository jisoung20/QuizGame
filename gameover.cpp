#include "Gameover.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib> //종료함수
#include"gotoxy.h"
#include"Round1.h"


using namespace std;

//종료

void gameover() {
	int x = 40;
	int y = 2;
	string anychar;

	gotoxy(x, y);
	cout << "게임을 종료합니다" << endl;
	gotoxy(x, y + 1);
	//cout << "걸린시간 : " << (endTime - startTime) / CLOCKS_PER_SEC;
	exit(0);

}