#include <limits> //max
#include "Round1.h"
#include "Round2.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
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
		
		//1라운드 문제
		string problem1[11] = {"1. 조선시대의 장군으로 임진왜란에서 수군을 이끌고 전투마다 승리를 거두어 왜군을 물리치는데 큰 공을 세운 장군은 누구일까요 ? ", "2. 조선을 대표하는 최고의 성군으로 칭송받으며, 훈민정음을 창제하신 조선 제 4대 국왕은 누구일까요?", "3. 일제강점기 시절 아우내 장터에서 군중에게 태극기를 나눠주는 등 만세시위를 주도하다가 체포된 독립운동가는 누구일까요?", "4. 을지문덕 장군이 수나라의 30만 대군을 몰살시켜 크게 승리한 이 전투의 이름은 무엇일까요?", "5. 삼국시대 고구려/신라/백제 중 가장 먼저 전성기를 맞은 나라는?", "6. 고려 시대 현종 때 강감찬 장군이 거란 침략군에 맞서 싸워 침입을 막았는데요. 이 대첩은 무엇일까요?", "7. 신라 최초의 여왕은 누구일까요?", "8. 국권 회복을 위해 1907년 안창호, 양기탁 등이 주축이 되어 결성한 비밀결사 단체 000은 무엇일까요?", "9. 고려 제 31대 왕으로 반원 자주 정책을 추진했으며, 신진 세력을 등용하여 권문세족을 누르고 왕권을 강화시키려 한 왕의 이름은?", "10. 동아시아 궁전 건축사에 있어 비정형적 조형미를 간직한 대표적인 궁으로 나라에 전쟁이나 큰 재난이 일어나 공식 궁궐을 사용하지 못할 때를 대비하여 지은 궁궐이다. 1997년 유네스코가 선정한 세계문화유산으로 등재된 이 궁의 이름은?","11. 아시아 침략에 앞장선 이토 히로부미를 사살한 우리나라의 독립운동가는 누구일까요 ? ", };
		//1라운드 답
		string answer1[11] = {"이순신","세종대왕","유관순","살수대첩","백제","귀주대첩","선덕여왕","신민회","공민왕","창덕궁","안중근" };
		int a = 0;

		while (1) {
			gotoxy(x, y);
			cout << "========== ROUND 1 ==========\n\n" << endl;
			gotoxy(2, 17);
			cout << problem1[a];
			gotoxy(48, 20);
			cout << "↓정답입력↓ ";// 사용자의 입력 받기
			gotoxy(48, 21);
			cin >> input;  // 사용자의 입력 (stirng)
			
			//사용자의 입력이 정답인 경우
			if (input == answer1[a]) {
				a++;
				gotoxy(48, 22);
				cout << "정답입니다!";

				//사용자의 입력을 음절단위로 나누어 저장 
				vector<string> inputword;
				for (size_t i = 0; i < input.length(); i += 2) {
					inputword.push_back(input.substr(i, 2));
				}
				//Round1의 벡터와 같은지 비교 
				//같으면 배열에서 값을 삭제 (빈칸 처리)

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (const string& uword : inputword) {
							if (Word[i][j] == uword) {
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
			}
			//사용자의 입력이 오답인 경우 
			else {
				gotoxy(48, 22);
				cout << "오답입니다!";
			}
			//future.get();

			if (a == 11) {
				break;
			}
		}

	//동적메모리 해제
	for (int i = 0; i < n; i++) {
		delete[]Word[i];
	}
	delete[]Word;

	string next;

	//세종 얼굴 띄우기
	SetConsoleOutputCP(CP_UTF8);

	std::string line;
	std::string filePath2 = "C:\\Users\\jisou\\Desktop\\코딩온\\게임프로젝트\\세종만원1.txt";
	std::ifstream file2(filePath2, std::ios::binary);
	//std::string line;
	while (std::getline(file2, line)) {
		std::cout << line << std::endl;
	}
	file2.close();
	SetConsoleOutputCP(949);
	cout << endl;
		cout << "1단계 Clear!" << endl;
		cout << "모든 단계를 클리어해서 세종대왕님을 만들어주세요! 계속하시겠습니까?(계속:Y , 그만하려면 아무거나 입력)" << endl;
		cin >> next;
		if (next == "Y")
		{
			Round2();
			
		}
		else {
			On = false;
			exit(0);
			break;
		}

	}

}

