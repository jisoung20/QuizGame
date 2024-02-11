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
		
		//1���� ����
		string problem1[11] = {"1. �����ô��� �屺���� �����ֶ����� ������ �̲��� �������� �¸��� �ŵξ� �ֱ��� ����ġ�µ� ū ���� ���� �屺�� �����ϱ�� ? ", "2. ������ ��ǥ�ϴ� �ְ��� �������� Ī�۹�����, �ƹ������� â���Ͻ� ���� �� 4�� ������ �����ϱ��?", "3. ���������� ���� �ƿ쳻 ���Ϳ��� ���߿��� �±ر⸦ �����ִ� �� ���������� �ֵ��ϴٰ� ü���� ��������� �����ϱ��?", "4. �������� �屺�� �������� 30�� �뱺�� ������� ũ�� �¸��� �� ������ �̸��� �����ϱ��?", "5. �ﱹ�ô� ����/�Ŷ�/���� �� ���� ���� �����⸦ ���� �����?", "6. ��� �ô� ���� �� ������ �屺�� �Ŷ� ħ������ �¼� �ο� ħ���� ���Ҵµ���. �� ��ø�� �����ϱ��?", "7. �Ŷ� ������ ������ �����ϱ��?", "8. ���� ȸ���� ���� 1907�� ��âȣ, ���Ź ���� ������ �Ǿ� �Ἲ�� ��а�� ��ü 000�� �����ϱ��?", "9. ��� �� 31�� ������ �ݿ� ���� ��å�� ����������, ���� ������ ����Ͽ� �ǹ������� ������ �ձ��� ��ȭ��Ű�� �� ���� �̸���?", "10. ���ƽþ� ���� ����翡 �־� �������� �����̸� ������ ��ǥ���� ������ ���� �����̳� ū �糭�� �Ͼ ���� �ñ��� ������� ���� ���� ����Ͽ� ���� �ñ��̴�. 1997�� ���׽��ڰ� ������ ���蹮ȭ�������� ����� �� ���� �̸���?","11. �ƽþ� ħ���� ���弱 ���� ���κι̸� ����� �츮������ ��������� �����ϱ�� ? ", };
		//1���� ��
		string answer1[11] = {"�̼���","�������","������","�����ø","����","���ִ�ø","��������","�Ź�ȸ","���ο�","â����","���߱�" };
		int a = 0;

		while (1) {
			gotoxy(x, y);
			cout << "========== ROUND 1 ==========\n\n" << endl;
			gotoxy(2, 17);
			cout << problem1[a];
			gotoxy(48, 20);
			cout << "�������Է¡� ";// ������� �Է� �ޱ�
			gotoxy(48, 21);
			cin >> input;  // ������� �Է� (stirng)
			
			//������� �Է��� ������ ���
			if (input == answer1[a]) {
				a++;
				gotoxy(48, 22);
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
			}
			//������� �Է��� ������ ��� 
			else {
				gotoxy(48, 22);
				cout << "�����Դϴ�!";
			}
			//future.get();

			if (a == 11) {
				break;
			}
		}

	//�����޸� ����
	for (int i = 0; i < n; i++) {
		delete[]Word[i];
	}
	delete[]Word;

	string next;

	//���� �� ����
	SetConsoleOutputCP(CP_UTF8);

	std::string line;
	std::string filePath2 = "C:\\Users\\jisou\\Desktop\\�ڵ���\\����������Ʈ\\��������1.txt";
	std::ifstream file2(filePath2, std::ios::binary);
	//std::string line;
	while (std::getline(file2, line)) {
		std::cout << line << std::endl;
	}
	file2.close();
	SetConsoleOutputCP(949);
	cout << endl;
		cout << "1�ܰ� Clear!" << endl;
		cout << "��� �ܰ踦 Ŭ�����ؼ� ������մ��� ������ּ���! ����Ͻðڽ��ϱ�?(���:Y , �׸��Ϸ��� �ƹ��ų� �Է�)" << endl;
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

