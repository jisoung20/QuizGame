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
#include <future> //Ÿ�Ӿ���
#include <ctime>
#include <cstdlib> //�����Լ�
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


	//auto future = async(launch::async, countdown); //ī��Ʈ�ٿ�� round1�� ���ÿ� ����ǰ� �ϴ� �Լ� 


	string arr1[36] = { "��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ø","��","��","��","��","��","ø","��","��","��","��","��","��","ȸ","��","��","��","â","��","��" };

	//�ε����� ���� ������ �̱� (�ߺ�x)

	vector<int> Index = {};

	while (Index.size() < 36) {
		bool check = true;
		index = rand() % 36 + 0;   // ���� ���� ����

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
	string** Word = new string * [6];
	for (int i = 0; i < n; i++) {
		Word[i] = new string[n];
	}

	// �迭�� �� �ֱ� 
	for (int i = 0; i < n; i++) {
		gotoxy(38, 4 + 2 * i);    // �迭�� ������ ��ǥ 
		for (int j = 0; j < n; j++) {
			Word[i][j] = arr1[Index[call]];       // ���� �ε��� �迭���� ���� ������� Word�� �� �ο� 
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
		gotoxy(1, 3);
		cout << "����: " << score;
		gotoxy(x, y);
		cout << "========== ROUND 1 ==========\n\n" << endl;
		gotoxy(48, 17);
		cout << "�������Է¡� ";// ������� �Է� �ޱ�
		gotoxy(48, 18);
		cin >> input;  // ������� �Է� (stirng)
		
		//������� �Է��� ���������� ������ ���� 
		vector<string> inputword;
		for (int i = 0; i < size(input); i++) {
			inputword.push_back(string(3, input[i]));
		}

		//Round1�� ���Ϳ� ������ �� 
		//������ �迭���� ���� ���� (��ĭ ó��)

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (const string& uword : inputword) {
					if (Word[i][j] == uword) {   //������ Word �迭���� �ش� ���� �������� ����
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
		bool allEmpty = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!Word[i][j].empty()) {  // �迭�� ������� ������ �ϳ��� �ִٸ� allEmpty�� false�� �ٲٰ� �˻�����
					allEmpty = false;
					break;
				}
			}
			if (!allEmpty) {  // allEmpty�� (false)�̸� for �� ���� (�迭�� �ϳ��� ���ִ� ���)
				break;
			}
		}

		if (allEmpty) {   //��� �迭�� ����ִٸ� (allEmpty =true)�̸� ����
			On = false;
			clock_t endTime = clock();
			break;
		}
	}


	//future.get();


	//�޸� ����
	for (int i = 0; i < n; i++) {
		delete[]Word[i];
	}
	delete[]Word;
	
	}

