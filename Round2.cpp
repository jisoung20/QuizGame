#include "Round2.h"
#include "Round3.h"
#include <limits> //max
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
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

// ROUND 2
void Round2() {
	system("cls");
	int n = 7;
	int index;
	int call = 0;
	int x = 40;
	int y = 2;
	string input;


	//auto future = async(launch::async, countdown); //카운트다운과 round1이 동시에 실행되게 하는 함수 


	string arr2[49] = { "근", "초", "고", "왕", "궁", "예", "과", "거", "제", "도", "서", "희", "천", "리", "장", "성", "강", "화", "도", "최", "무", "선", "앙", "부", "일", "구", "정", "묘", "호", "란", "병", "자", "호", "란", "최", "재", "우", "강", "화", "도", "조", "약", "갑", "신", "정", "변", "전", "봉", "준" };

	//인덱스를 랜덤 순으로 뽑기 (중복x)

	vector<int> Index = {};

	while (Index.size() < 49) {
		bool check = true;
		index = rand() % 49 + 0;   // 랜덤 숫자 생성

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
	string** Word = new string * [7];
	for (int i = 0; i < n; i++) {
		Word[i] = new string[n];
	}

	// 배열에 값 넣기 
	for (int i = 0; i < n; i++) {
		gotoxy(38, 4 + 2 * i);    // 배열이 보여질 좌표 
		for (int j = 0; j < n; j++) {
			Word[i][j] = arr2[Index[call]];       // 랜덤 인덱스 배열안의 숫자 순서대로 Word의 값 부여 
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


		//2라운드 문제
		string problem2[14] = { "1. 백제의 전성기를 이룬 왕은? ", "2. 후고구려를 건국한 왕은? ", "3. 고려시대 일정한 시험을 거쳐 관리로 등용하는 제도는?", "4. 거란의 1차 침입을 막아낸 주요 인물은?", "5. 고려시대 때 지은 장성은?", "6. 고려가 몽골의 침입을 받으면서 천도한 수도는?", "7. 화포를 만든 사람은?", "8. 세종이 장영실에게 만들게 한 해시계는?", "9. 여진이 후금을 건국하고 일어난 전쟁은?", "10. 인조 14년에 후금이 청을 건국하고 일어난 전쟁은?", "11. 동학을 창시한 사람은?","12. 일본이 조선을 협박하면서 받아낸 불평등 조약은?","13. 1884년 급진개화파가 일본의 힘을 빌려 일으킨 정변은?","14. 동학농민운동을 일으킨 사람은?" };
		string answer2[14] = { "근초고왕","궁예","과거제도","서희","천리장성","강화도","최무선","앙부일구","정묘호란","병자호란","최재우","강화도조약","갑신정변","전봉준" };
		int a = 0;

		while (1) {
			gotoxy(x, y);
			cout << "========== ROUND 2 ==========\n\n" << endl;
			gotoxy(2, 19);
			cout << problem2[a];
			gotoxy(48, 21);
			cout << "↓정답입력↓ ";// 사용자의 입력 받기
			gotoxy(48, 22);
			cin >> input;  // 사용자의 입력 (stirng)

			//사용자의 입력이 정답인 경우
			if (input == answer2[a]) {
				a++;
				gotoxy(48, 23);
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

				// 게임종료 조건확인 (모든 단어 입력)
				//bool allEmpty = true;
				//for (int i = 0; i < n; i++) {
				//	for (int j = 0; j < n; j++) {
				//		if (!Word[i][j].empty()) {  // 배열이 비어있지 않은게 하나라도 있다면 allEmpty를 false로 바꾸고 검사종료
				//			allEmpty = false;
				//			break;
				//		}
				//	}
				//	if (!allEmpty) {  // allEmpty가 (false)이면 for 문 종료 (배열이 하나라도 차있는 경우)
				//		break;
				//	}
				//}

				//if (allEmpty) {   //모든 배열이 비어있다면 (allEmpty =true)이면 종료
				//	clock_t endTime = clock();
				//	break;
				//}
			}


			//사용자의 입력이 오답인 경우 
			else {
				gotoxy(48, 22);
				cout << "오답입니다!";
			}
			//future.get();

			if (a == 14) {
				break;
			}


		}


		//메모리 해제
		for (int i = 0; i < n; i++) {
			delete[]Word[i];
		}
		delete[]Word;

		string next;


		//세종 얼굴 띄우기
		SetConsoleOutputCP(CP_UTF8);

		std::string line;
		std::string filePath2 = "C:\\Users\\jisou\\Desktop\\코딩온\\게임프로젝트\\세종만원3.txt";
		std::ifstream file2(filePath2, std::ios::binary);
		//std::string line;
		while (std::getline(file2, line)) {
			std::cout << line << std::endl;
		}
		file2.close();
		SetConsoleOutputCP(949);

		cout << endl;
		cout << "2단계 Clear!" << endl;
		cout << "모든 단계를 클리어해서 세종대왕님을 만들어주세요! 계속하시겠습니까?(계속:Y , 그만하려면 아무거나 입력)" << endl;
		cin >> next;
		if (next == "Y")
		{
			Round3();

		}
		else {
			On = false;
			break;
		}

	}

}

