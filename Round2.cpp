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
#include <future> //Ÿ�Ӿ���
#include <ctime>
#include <cstdlib> //�����Լ�
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


	//auto future = async(launch::async, countdown); //ī��Ʈ�ٿ�� round1�� ���ÿ� ����ǰ� �ϴ� �Լ� 


	string arr2[49] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "õ", "��", "��", "��", "��", "ȭ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ȣ", "��", "��", "��", "ȣ", "��", "��", "��", "��", "��", "ȭ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };

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
			Word[i][j] = arr2[Index[call]];       // ���� �ε��� �迭���� ���� ������� Word�� �� �ο� 
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
		string problem2[14] = { "1. ������ �����⸦ �̷� ����? ", "2. �İ����� �Ǳ��� ����? ", "3. ����ô� ������ ������ ���� ������ ����ϴ� ������?", "4. �Ŷ��� 1�� ħ���� ���Ƴ� �ֿ� �ι���?", "5. ����ô� �� ���� �强��?", "6. ����� ������ ħ���� �����鼭 õ���� ������?", "7. ȭ���� ���� �����?", "8. ������ �念�ǿ��� ����� �� �ؽð��?", "9. ������ �ı��� �Ǳ��ϰ� �Ͼ ������?", "10. ���� 14�⿡ �ı��� û�� �Ǳ��ϰ� �Ͼ ������?", "11. ������ â���� �����?","12. �Ϻ��� ������ �����ϸ鼭 �޾Ƴ� ����� ������?","13. 1884�� ������ȭ�İ� �Ϻ��� ���� ���� ����Ų ������?","14. ���г�ο�� ����Ų �����?" };
		string answer2[14] = { "���ʰ��","�ÿ�","��������","����","õ���强","��ȭ��","�ֹ���","�Ӻ��ϱ�","����ȣ��","����ȣ��","�����","��ȭ������","��������","������" };
		int a = 0;

		while (1) {
			gotoxy(x, y);
			cout << "========== ROUND 2 ==========\n\n" << endl;
			gotoxy(2, 19);
			cout << problem2[a];
			gotoxy(48, 21);
			cout << "�������Է¡� ";// ������� �Է� �ޱ�
			gotoxy(48, 22);
			cin >> input;  // ������� �Է� (stirng)

			//������� �Է��� ������ ���
			if (input == answer2[a]) {
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

			if (a == 14) {
				break;
			}


		}


		//�޸� ����
		for (int i = 0; i < n; i++) {
			delete[]Word[i];
		}
		delete[]Word;

		string next;


		//���� �� ����
		SetConsoleOutputCP(CP_UTF8);

		std::string line;
		std::string filePath2 = "C:\\Users\\jisou\\Desktop\\�ڵ���\\����������Ʈ\\��������3.txt";
		std::ifstream file2(filePath2, std::ios::binary);
		//std::string line;
		while (std::getline(file2, line)) {
			std::cout << line << std::endl;
		}
		file2.close();
		SetConsoleOutputCP(949);

		cout << endl;
		cout << "2�ܰ� Clear!" << endl;
		cout << "��� �ܰ踦 Ŭ�����ؼ� ������մ��� ������ּ���! ����Ͻðڽ��ϱ�?(���:Y , �׸��Ϸ��� �ƹ��ų� �Է�)" << endl;
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

