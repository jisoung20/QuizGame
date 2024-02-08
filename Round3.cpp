#include "Round3.h"
#include <limits> //max
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
#include"gameclear.h"

using namespace std;

// ROUND 3
void Round3() {
	system("cls");
	int n = 7;
	int index;
	int call = 0;
	int x = 40;
	int y = 2;
	string input;


	//auto future = async(launch::async, countdown); //카운트다운과 round1이 동시에 실행되게 하는 함수 


	string arr3[49] = { "척","화","비","별","기","군","임","오","군","란","헐","버","트","천","도","교","광","혜","원","한","강","철","교","윤","봉","길","의","열","단","동","아","일","보","안","익","태","김","구","문","화","통","치","주","시","경","대","성","학","교" };

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
			Word[i][j] = arr3[Index[call]];       // 랜덤 인덱스 배열안의 숫자 순서대로 Word의 값 부여 
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
		string problem3[15] = { "1. 흥선 대원군은 우리 나라 여러 곳에 서양과의 교섭을 금지하는 글을 적은 비석을 세웠는데 이를 무엇이라고 하는가?","2. 외세의 침입으로부터 나라를 지키기 위해 근대적인 무기를 가지고 새로운 훈련을 받는 군대를 조직하였는데 이 군대의 이름은?","3. 대우를 잘 받지 못하는 구식 군인들의 불만이 폭발하여 일어난 사건은 무엇인가?","4. 미국 선교사로 언어학자이며 사학자였고, 육영 공원의 교수로 초빙되었으며, 우리 나라의 주권 회복 운동에 크게 활약한 사람은?","5. '사람이 곧 하늘이다.'라는 인간 중심 사상에 뿌리를 두고 국민들에게 애국심을 불어넣은 종교는 무엇인가?","6. 우리 나라 최초의 근대식 의료 기관은 무엇인가?","7. 우리 나라 최초로 만들어진 철교는 무엇인가?","8. 일본 왕의 생일을 기념하는 행사에 도시락 폭탄을 던져 여러 중요 인물을 죽이거나 크게 다치게 하고 순국한 분은 누구인가?","9. 1919년 일제의 주요 기관을 파괴하고 일본 관리를 암살할 목적으로 만주 길림성에서 조직된 단체는 무엇인가?","10. 조선 물건 쓰기 운동을 적극적으로 후원했던 당시의 신문사는 어디였는가?","11. 일제 시대 때 음악 활동을 한 사람 중에서 애국가를 작곡한 사람은 누구인가?","12. 임시 정부의 주석으로 한인 애국단을 조직하여 독립 운동을 한 분은 누구인가?","13. 일제는 3.1운동을 통해 우리 민족을 무력으로 지배할 수 없다는 것을 깨닫고, 식민 통치 정책을 바꾸었는데 이를 무엇이라고 하는가?","14. 안창호 선생이 나라의 힘을 기르는 방법은 교육을 통해서 백성들을 깨우치는 것이라 생각하고 평양에 세운 학교는 무엇인가?","15. 조선 말기에 우리 한글을 보급하고 발전시키기 위해서 가장 많은 공을 세운 사람은 누구인가?" };
		string answer3[15] = { "척화비","별기군","임오군란","헐버트","천도교","광혜원","한강철교","윤봉길","의열단","동아일보","안익태","김구","문화통치","대성학교","주시경" };
		int a = 0;

		while (1) {
			gotoxy(x, y);
			cout << "========== ROUND 3 ==========\n\n" << endl;
			gotoxy(2, 19);
			cout << problem3[a];
			gotoxy(48, 21);
			cout << "↓정답입력↓ ";// 사용자의 입력 받기
			gotoxy(48, 22);
			cin >> input;  // 사용자의 입력 (stirng)

			//사용자의 입력이 정답인 경우
			if (input == answer3[a]) {
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

			if (a == 15) {
				break;
			}


		}


		//메모리 해제
		for (int i = 0; i < n; i++) {
			delete[]Word[i];
		}
		delete[]Word;

		string next;


		cout << "3단계 Clear!" << endl;
		cout << "모든 단계를 클리어하셨습니다. 세종대왕님을 뵈려면 Y를 눌러주세요(보기:Y , 그만하려면 아무거나 입력)" << endl;
		cin >> next;
		if (next == "Y")
		{
			gameclear();

		}
		else {
			On = false;
			break;
		}

	}

}

