#include "Gameover.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib> //�����Լ�
#include"gotoxy.h"
#include"Round1.h"


using namespace std;

//����

void gameover() {
	int x = 40;
	int y = 2;
	string anychar;

	gotoxy(x, y);
	cout << "������ �����մϴ�" << endl;
	gotoxy(x, y + 1);
	//cout << "�ɸ��ð� : " << (endTime - startTime) / CLOCKS_PER_SEC;
	exit(0);

}