#pragma once
#include <stdio.h>
#include <windows.h>


//커서위치 이동함수
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	COORD pos;  //커서의 위치
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos); //커서의 위치를 지정된 좌표로 이동시킨다
}