#pragma once
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
#include <future>  
#include <cstdlib> //�����Լ�
#include"Ŀ����ǥ�̵�.h"
#include"Countdown.h"

using namespace std;

//���ӽ���


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
	string** Game = new string * [6];
	for (int i = 0; i < n; i++) {
		Game[i] = new string[n];
	}

	// �迭�� �� �ֱ� 
	for (int i = 0; i < n; i++) {
		gotoxy(38, 4 + 2*i);    // �迭�� ������ ��ǥ 
		for (int j = 0; j < n; j++) {
			Game[i][j] = arr1[Index[call]];       // ���� �ε��� �迭���� ���� ������� Game�� �� �ο� 
			cout << setw(5) << Game[i][j];
			call++;
		}
		cout <<endl;
		cout <<endl;
	}


	// ������� �Է� �ޱ� 
	gotoxy(48, 17);  
	cout << "�������Է¡� ";
	gotoxy(48, 18);
	cin >> input;  // ������� �Է� 
	

	
	future.get();


	//�޸� ����
	for (int i = 0; i < n; i++) {
		delete []Game[i];
	}
	delete[]Game;

}



//���ӹ��

void How() {
	int x = 40;
	int y = 2;

	gotoxy(x, y);
	cout << "�������� �������" << endl;
	gotoxy(18, y+2);
	cout << "1.6*6���� �̷���� �迭���� ������ ���� �׿� �´� �ܾ ã�� �Է��ϼ���." << endl;
	gotoxy(18, y+4);
	cout << "2.������ ���߰� �Ǹ� �迭���� ���� �信 �ش��ϴ� ���ڰ� ������� �˴ϴ�." << endl;
	gotoxy(18, y+6);
	cout << "3.��� ������ ���߰� �Ǹ� �迭�� ��� ���ڰ� ������� �ǰ�, �� �ܰ踦 clear�ϰ� �˴ϴ�.";
	gotoxy(18, y+8);
	cout << "4.���� �ܰ� ���� �� ������, �׸� �ϰ� �ʹٸ� ���Ḧ ��������." << endl;

}



//����

void Exit() {
	int x = 40;
	int y = 2;
	string anychar;

	gotoxy(x, y);
	cout << "������ �����մϴ�" << endl;
	gotoxy(x, y+1);
	cout << "����� ������ : " << endl;
	exit(0);
	
}

// Ŀ�� ��ġ 
