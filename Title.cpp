#include "Title.h"

#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <mmsystem.h>
#include"커서좌표이동.h"

using namespace std;

//값 지정
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SUBMIT 32

//타이틀 구현
void Title() {
	std::cout << "\n\n\n\n";
	std::cout << "\t\t"; std::cout << "    ▦▦        ▦       ▦         ▦      ▦▦▦▦   ▦    ▦▦▦▦▦▦▦▦   \n";
	std::cout << "\t\t"; std::cout << "  ▦    ▦  ▦▦▦       ▦         ▦            ▦   ▦           ▦          \n";
	std::cout << "\t\t"; std::cout << "  ▦    ▦      ▦       ▦         ▦      ▦▦▦▦   ▦           ▦          \n";
	std::cout << "\t\t"; std::cout << "    ▦▦    ▦▦▦       ▦         ▦▦▦        ▦   ▦         ▦  ▦        \n";
	std::cout << "\t\t"; std::cout << "                ▦      ▦ ▦       ▦            ▦   ▦       ▦      ▦      \n";
	std::cout << "\t\t"; std::cout << "        ▦▦▦▦▦     ▦   ▦      ▦     ▦▦▦▦▦▦▦     ▦          ▦    \n";
	std::cout << "\t\t"; std::cout << "                ▦    ▦     ▦     ▦           ▦    ▦   ▦              ▦  \n";
	std::cout << "\t\t"; std::cout << "                ▦   ▦       ▦    ▦           ▦    ▦                       \n";
	std::cout << "\t\t"; std::cout << "                ▦  ▦         ▦   ▦           ▦    ▦  ▦▦▦▦▦▦▦▦▦▦ \n";
	cout << endl;
	cout << "                                               ♥♡게임 정보♥♡\n" << endl;
	cout << "               1.시대가 발전함에 따라 잊어버리기 쉬운 우리 민족의 역사를 상기시키고자 이 게임을 제작하였습니다." << endl;
	cout << "               2.본 게임은 1단계부터 n단계까지 이루어져 있으며, 단계가 진행됨에 따라 난이도가 상승합니다." << endl;
	cout << "               3.본 게임은 단계별로 힌트가 있으며, 힌트 사용 시 50포인트가 소멸됩니다. " << endl;
	cout << "               4.본 게임을 clear하게 되면, 노아 리더님께로 부터 어마무시한 상품이 있습니다. ^0^" << endl;
	cout << endl;
}

//마우스 입력 받기
int keycontrol() {
	char temp = _getch();

	if (temp == 72 || temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 75 || temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 80 || temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 77 || temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == 32 || temp == ' ') {
		return SUBMIT;
	}
}
//메인화면 구현
int menudraw(){
	int x = 50; //24->50
	int y = 22;  //12-> 22
	gotoxy(x - 2, y);
	printf("> 게임시작\n");
	gotoxy(x, y + 1);
	printf("게임방법\n");
	gotoxy(x, y + 2);
	printf("종료");
	while (1) { //선택 할때 까지 무한반복
		int n = keycontrol();//키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: { // 입력 받은 값이 UP일경우
			if (y > 22) { // 최대 12
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 24) { // 최대 14
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			y -= 22;
			if (y == 0) {
				system("cls");
				//Game();
			}
			if (y == 1) {
				system("cls");
				//How();
			}
			if (y == 2) {
				system("cls");
				//Exit();
			}
		}
		}
	}

}