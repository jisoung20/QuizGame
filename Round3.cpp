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
#include <future> //Ÿ�Ӿ���
#include <ctime>
#include <cstdlib> //�����Լ�
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


	//auto future = async(launch::async, countdown); //ī��Ʈ�ٿ�� round1�� ���ÿ� ����ǰ� �ϴ� �Լ� 


	string arr3[49] = { "ô","ȭ","��","��","��","��","��","��","��","��","��","��","Ʈ","õ","��","��","��","��","��","��","��","ö","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ȭ","��","ġ","��","��","��","��","��","��","��" };

	//�ε����� ���� ������ �̱� (�ߺ�x)

	vector<int> Index = {};

	while (Index.size() < 49) {
		bool check = true;
		index = rand() % 49 + 0;   // ���� ���� ����

		for (int i : Index) {   //�ߺ�Ȯ��

			if (i == index) {   //�迭���� = ���� ����
				check = false;
				break;
			}
		}
		if (check == true) {  // �ߺ��� �ƴϸ� �迭�� �߰�
			Index.push_back(index);
		}
	}

	//2���� �迭 ����
	string** Word = new string * [7];
	for (int i = 0; i < n; i++) {
		Word[i] = new string[n];
	}

	// �迭�� �� �ֱ� 
	for (int i = 0; i < n; i++) {
		gotoxy(38, 4 + 2 * i);    // �迭�� ������ ��ǥ 
		for (int j = 0; j < n; j++) {
			Word[i][j] = arr3[Index[call]];       // ���� �ε��� �迭���� ���� ������� Word�� �� �ο� 
			cout << setw(5) << Word[i][j];
			call++;
		}
		cout << endl;
		cout << endl;
	}

	int score = 100;
	bool On = true;

	clock_t startTime = clock(); //�ð� start

	while (On) {  //�ܾ ���� ���ٶ����� ��� �ݺ�


		//2���� ����
		string problem3[15] = { "1. �Ｑ ������� �츮 ���� ���� ���� ������� ������ �����ϴ� ���� ���� ���� �����µ� �̸� �����̶�� �ϴ°�?","2. �ܼ��� ħ�����κ��� ���� ��Ű�� ���� �ٴ����� ���⸦ ������ ���ο� �Ʒ��� �޴� ���븦 �����Ͽ��µ� �� ������ �̸���?","3. ��츦 �� ���� ���ϴ� ���� ���ε��� �Ҹ��� �����Ͽ� �Ͼ ����� �����ΰ�?","4. �̱� ������� ��������̸� �����ڿ���, ���� ������ ������ �ʺ��Ǿ�����, �츮 ������ �ֱ� ȸ�� ��� ũ�� Ȱ���� �����?","5. '����� �� �ϴ��̴�.'��� �ΰ� �߽� ��� �Ѹ��� �ΰ� ���ε鿡�� �ֱ����� �Ҿ���� ������ �����ΰ�?","6. �츮 ���� ������ �ٴ�� �Ƿ� ����� �����ΰ�?","7. �츮 ���� ���ʷ� ������� ö���� �����ΰ�?","8. �Ϻ� ���� ������ ����ϴ� ��翡 ���ö� ��ź�� ���� ���� �߿� �ι��� ���̰ų� ũ�� ��ġ�� �ϰ� ������ ���� �����ΰ�?","9. 1919�� ������ �ֿ� ����� �ı��ϰ� �Ϻ� ������ �ϻ��� �������� ���� �渲������ ������ ��ü�� �����ΰ�?","10. ���� ���� ���� ��� ���������� �Ŀ��ߴ� ����� �Ź���� ��𿴴°�?","11. ���� �ô� �� ���� Ȱ���� �� ��� �߿��� �ֱ����� �۰��� ����� �����ΰ�?","12. �ӽ� ������ �ּ����� ���� �ֱ����� �����Ͽ� ���� ��� �� ���� �����ΰ�?","13. ������ 3.1��� ���� �츮 ������ �������� ������ �� ���ٴ� ���� ���ݰ�, �Ĺ� ��ġ ��å�� �ٲپ��µ� �̸� �����̶�� �ϴ°�?","14. ��âȣ ������ ������ ���� �⸣�� ����� ������ ���ؼ� �鼺���� ����ġ�� ���̶� �����ϰ� ��翡 ���� �б��� �����ΰ�?","15. ���� ���⿡ �츮 �ѱ��� �����ϰ� ������Ű�� ���ؼ� ���� ���� ���� ���� ����� �����ΰ�?" };
		string answer3[15] = { "ôȭ��","���ⱺ","�ӿ�����","���Ʈ","õ����","������","�Ѱ�ö��","������","�ǿ���","�����Ϻ�","������","�豸","��ȭ��ġ","�뼺�б�","�ֽð�" };
		int a = 0;

		while (1) {
			gotoxy(x, y);
			cout << "========== ROUND 3 ==========\n\n" << endl;
			gotoxy(2, 19);
			cout << problem3[a];
			gotoxy(48, 21);
			cout << "�������Է¡� ";// ������� �Է� �ޱ�
			gotoxy(48, 22);
			cin >> input;  // ������� �Է� (stirng)

			//������� �Է��� ������ ���
			if (input == answer3[a]) {
				a++;
				gotoxy(48, 23);
				cout << "�����Դϴ�!";

				//������� �Է��� ���������� ������ ���� 
				vector<string> inputword;

				for (size_t i = 0; i < input.length(); i += 2) {
					inputword.push_back(input.substr(i, 2));
				}

				//Round1�� ���Ϳ� ������ �� 
				//������ �迭���� ���� ���� (��ĭ ó��)


				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (const string& uword : inputword) {
							if (Word[i][j] == uword) {
								Word[i][j] = " ";
							}
						}
					}
				}

				// ȭ�� Ŭ����
				system("cls");

				// ���� ������ �迭�� ȭ�鿡 �ݿ�
				for (int i = 0; i < n; i++) {
					gotoxy(38, 4 + 2 * i);    // �迭�� ������ ��ǥ 
					for (int j = 0; j < n; j++) {
						cout << setw(5) << Word[i][j];
					}
					cout << endl;
					cout << endl;
				}

				// �������� ����Ȯ�� (��� �ܾ� �Է�)
				//bool allEmpty = true;
				//for (int i = 0; i < n; i++) {
				//	for (int j = 0; j < n; j++) {
				//		if (!Word[i][j].empty()) {  // �迭�� ������� ������ �ϳ��� �ִٸ� allEmpty�� false�� �ٲٰ� �˻�����
				//			allEmpty = false;
				//			break;
				//		}
				//	}
				//	if (!allEmpty) {  // allEmpty�� (false)�̸� for �� ���� (�迭�� �ϳ��� ���ִ� ���)
				//		break;
				//	}
				//}

				//if (allEmpty) {   //��� �迭�� ����ִٸ� (allEmpty =true)�̸� ����
				//	clock_t endTime = clock();
				//	break;
				//}
			}


			//������� �Է��� ������ ��� 
			else {
				gotoxy(48, 22);
				cout << "�����Դϴ�!";
			}
			//future.get();

			if (a == 15) {
				break;
			}


		}


		//�޸� ����
		for (int i = 0; i < n; i++) {
			delete[]Word[i];
		}
		delete[]Word;

		string next;


		cout << "3�ܰ� Clear!" << endl;
		cout << "��� �ܰ踦 Ŭ�����ϼ̽��ϴ�. ������մ��� �Ʒ��� Y�� �����ּ���(����:Y , �׸��Ϸ��� �ƹ��ų� �Է�)" << endl;
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

