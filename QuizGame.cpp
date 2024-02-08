#include <iostream>
#include<conio.h>  // getch 함수
#include <windows.h>  //콘솔 디자인

//키보드값 전처리 
#define UP 0   // 컴파일시 UP은 0과 같은 취급
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int Keycontrol();
void gotoxy(int, int);

int main()
{
	system("mode con:cols=50 lines=10");   // 콘솔 사이즈 col:가로 / lines:세로
	system("color 9");            // 글꼴 색 
	std::cout << "역사퀴즈";

	int x = 24;
	int y = 12;
	gotoxy(x - 2, y);
	printf(">게임시작");
	
	return 0;
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


//