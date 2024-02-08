#pragma once
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
#include <future>  
#include <cstdlib> //종료함수
#include"커서좌표이동.h"
#include"Countdown.h"

using namespace std;

//게임시작


// ROUND 1
void Game() {
	system("cls");
	int n = 6;
	int index;
	int call = 0;
	int x = 40;
	int y = 2;
	string input;
	//countdown();

	auto future = async(launch::async, countdown);

	gotoxy(x, y);
	cout << "========== ROUND 1 ==========\n\n" << endl;

	string arr1[36] = { "안","중","근","이","순","신","세","종","대","왕","유","관","순","살","수","대","첩","백","제","귀","주","대","첩","선","덕","여","왕","신","민","회","공","민","왕","창","덕","궁" };

	//인덱스를 랜덤 순으로 뽑기 (중복x)

	vector<int> Index = {};

	while (Index.size() < 36) {
		bool check = true;
		index = rand() % 36 + 0;   // 랜덤 숫자 생성

		for (int i : Index) {   //중복확인

			if (i == index) {   //배열원소 = 뽑은 숫자
				check = false;
				break;
			}
		}
		if (check == true) {  // 중복이 아니면 배열에 추가
			Index.push_back(index);
		}
	}



	//2차원 배열 선언
	string** Game = new string * [6];
	for (int i = 0; i < n; i++) {
		Game[i] = new string[n];
	}

	// 배열에 값 넣기 
	for (int i = 0; i < n; i++) {
		gotoxy(38, 4 + 2*i);    // 배열이 보여질 좌표 
		for (int j = 0; j < n; j++) {
			Game[i][j] = arr1[Index[call]];       // 랜덤 인덱스 배열안의 숫자 순서대로 Game의 값 부여 
			cout << setw(5) << Game[i][j];
			call++;
		}
		cout <<endl;
		cout <<endl;
	}


	// 사용자의 입력 받기 
	gotoxy(48, 17);  
	cout << "↓정답입력↓ ";
	gotoxy(48, 18);
	cin >> input;  // 사용자의 입력 
	

	
	future.get();


	//메모리 해제
	for (int i = 0; i < n; i++) {
		delete []Game[i];
	}
	delete[]Game;

}



//게임방법

void How() {
	int x = 40;
	int y = 2;

	gotoxy(x, y);
	cout << "♡♥게임 방법♡♥" << endl;
	gotoxy(18, y+2);
	cout << "1.6*6으로 이루어진 배열에서 설명을 보고 그에 맞는 단어를 찾아 입력하세요." << endl;
	gotoxy(18, y+4);
	cout << "2.정답을 맞추게 되면 배열에서 맞춘 답에 해당하는 글자가 사라지게 됩니다." << endl;
	gotoxy(18, y+6);
	cout << "3.모든 정답을 맞추게 되면 배열의 모든 글자가 사라지게 되고, 본 단계를 clear하게 됩니다.";
	gotoxy(18, y+8);
	cout << "4.다음 단계 도전 시 다음을, 그만 하고 싶다면 종료를 누르세요." << endl;

}



//종료

void Exit() {
	int x = 40;
	int y = 2;
	string anychar;

	gotoxy(x, y);
	cout << "게임을 종료합니다" << endl;
	gotoxy(x, y+1);
	cout << "당신의 점수는 : " << endl;
	exit(0);
	
}

// 커서 위치 
