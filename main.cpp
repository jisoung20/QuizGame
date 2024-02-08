#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include<ctime>
#include<cstdlib>
#include <mmsystem.h>
#include"BGM1.h"
#include"gotoxy.h"
#include"gameover.h"
#include"howto.h"
#include"Round1.h"
#include"gameclear.h"
#include"Countdown.h"
#include"Title.h"
#pragma comment(lib,"winmm.lib")

	// 메인화면 시작과 동시에 BGM재생시작(BGM은 게임이 종료될때까지 실행된다)★
	// 
	//1.사용자가 메뉴에서 시작을 선택하면★    
	//1-1Round1 실행
	// Round1의 시작과 동시에 카운트다운이 활성화된다.
	// 사용자의 입력을 받아 배열이 삭제됨.
	// 
	//2.사용방법선택시 
	//2-1사용방법 화면 띄우기 
	//2-2 게임시작으로 연결
	// 
	//3게임종료 선택시
	//3-1게임종료 


//값 지정
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SUBMIT 32

using namespace std;

//void gotoxy(int x, int y);
int keycontrol();
int menudraw();

int main() {

	srand(time(NULL));
	BGM1();   //게임실행과 동시에 BGM 시작
	
	//게임타이틀 구현
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
		cout << "               2.본 게임은 1단계부터 3단계까지 이루어져 있으며, 단계가 진행됨에 따라 난이도가 상승합니다." << endl;
		cout << "               3.본 게임을 clear하게 되면, 노아 리더님께로부터 어마무시한 상품이 있습니다. ^0^" << endl;
		cout << endl;
	
		menudraw(); //메뉴띄우기
	


	return 0;
}

//마우스 입력 받기
int keycontrol() {
	char temp = _getch();  //사용자의 입력을 기다렸다가 입력을 받은 즉시 입력값의 아스키코드를 반환한다

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
int menudraw() {
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
				Round1();
			}
			if (y == 1) {
				system("cls");
				howto();
			}
			if (y == 2) {
				system("cls");
				exit(0);
			}
		}

		}

	}
}





