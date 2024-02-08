#pragma once
#include <iostream>
#include "howto.h"
#include"gotoxy.h"
#include"Round1.h"

using namespace std;

//게임방법

void howto() {
	int x = 40;
	int y = 2;

	gotoxy(x, y);
	cout << "♡♥게임 방법♡♥" << endl;
	gotoxy(18, y + 2);
	cout << "1.6*6으로 이루어진 배열에서 설명을 보고 그에 맞는 단어를 찾아 입력하세요." << endl;
	gotoxy(18, y + 4);
	cout << "2.정답을 맞추게 되면 배열에서 맞춘 답에 해당하는 글자가 사라지게 됩니다." << endl;
	gotoxy(18, y + 6);
	cout << "3.모든 정답을 맞추게 되면 배열의 모든 글자가 사라지게 되고, 본 단계를 clear하게 됩니다.";
	gotoxy(18, y + 8);
	cout << "4.다음 단계 도전 시 다음을, 그만 하고 싶다면 종료를 누르세요." << endl;

	gotoxy(18, y + 12);
	cout << "게임을 시작하시려면 아무문자나 입력하세요! → ";
	string a;
	cin >> a;
	Round1();

}