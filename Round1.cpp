#include <limits> //max
#include "Round1.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
#include <future> //타임어택
#include <ctime>
#include <cstdlib> //종료함수
#include"gotoxy.h"
#include"Countdown.h"

using namespace std;

// ROUND 1
void Round1() {
	system("cls");
	int n = 6;
	int index;
	int call = 0;
	int x = 40;
	int y = 2;
	string input;


	//auto future = async(launch::async, countdown); //카운트다운과 round1이 동시에 실행되게 하는 함수 


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
	string** Word = new string * [6];
	for (int i = 0; i < n; i++) {
		Word[i] = new string[n];
	}

	// 배열에 값 넣기 
	for (int i = 0; i < n; i++) {
		gotoxy(38, 4 + 2 * i);    // 배열이 보여질 좌표 
		for (int j = 0; j < n; j++) {
			Word[i][j] = arr1[Index[call]];       // 랜덤 인덱스 배열안의 숫자 순서대로 Word의 값 부여 
			cout << setw(5) << Word[i][j];
			call++;
		}
		cout << endl;
		cout << endl;
	}

	int score = 100;
	bool On = true;

	clock_t startTime = clock(); //시간 start

	while (On) {  //단어를 전부 없앨때까지 계속 반복
		gotoxy(1, 3);
		cout << "점수: " << score;
		gotoxy(x, y);
		cout << "========== ROUND 1 ==========\n\n" << endl;
		gotoxy(48, 17);
		cout << "↓정답입력↓ ";// 사용자의 입력 받기
		gotoxy(48, 18);
		cin >> input;  // 사용자의 입력 (stirng)
		
		//사용자의 입력을 음절단위로 나누어 저장 
		vector<string> inputword;
		for (int i = 0; i < size(input); i++) {
			inputword.push_back(string(3, input[i]));
		}

		//Round1의 벡터와 같은지 비교 
		//같으면 배열에서 값을 삭제 (빈칸 처리)

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (const string& uword : inputword) {
					if (Word[i][j] == uword) {   //같으면 Word 배열에서 해당 값을 공백으로 변경
						Word[i][j] = " ";
					}
				}
			}
		}

		// 화면 클리어
		system("cls");

		// 값을 삭제한 배열을 화면에 반영
		for (int i = 0; i < n; i++) {
			gotoxy(38, 4 + 2 * i);    // 배열이 보여질 좌표 
			for (int j = 0; j < n; j++) {
				cout << setw(5) << Word[i][j];
			}
			cout << endl;
			cout << endl;
		} 

		// 게임종료 조건확인 (모든 단어 입력)
		bool allEmpty = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!Word[i][j].empty()) {  // 배열이 비어있지 않은게 하나라도 있다면 allEmpty를 false로 바꾸고 검사종료
					allEmpty = false;
					break;
				}
			}
			if (!allEmpty) {  // allEmpty가 (false)이면 for 문 종료 (배열이 하나라도 차있는 경우)
				break;
			}
		}

		if (allEmpty) {   //모든 배열이 비어있다면 (allEmpty =true)이면 종료
			On = false;
			clock_t endTime = clock();
			break;
		}
	}


	//future.get();


	//메모리 해제
	for (int i = 0; i < n; i++) {
		delete[]Word[i];
	}
	delete[]Word;
	
	}

