#pragma once
#include <iostream>
#include "howto.h"
#include"gotoxy.h"
#include"Round1.h"

using namespace std;

//���ӹ��

void howto() {
	int x = 40;
	int y = 2;

	gotoxy(x, y);
	cout << "�������� �������" << endl;
	gotoxy(18, y + 2);
	cout << "1.6*6���� �̷���� �迭���� ������ ���� �׿� �´� �ܾ ã�� �Է��ϼ���." << endl;
	gotoxy(18, y + 4);
	cout << "2.������ ���߰� �Ǹ� �迭���� ���� �信 �ش��ϴ� ���ڰ� ������� �˴ϴ�." << endl;
	gotoxy(18, y + 6);
	cout << "3.��� ������ ���߰� �Ǹ� �迭�� ��� ���ڰ� ������� �ǰ�, �� �ܰ踦 clear�ϰ� �˴ϴ�.";
	gotoxy(18, y + 8);
	cout << "4.���� �ܰ� ���� �� ������, �׸� �ϰ� �ʹٸ� ���Ḧ ��������." << endl;

	gotoxy(18, y + 12);
	cout << "������ �����Ͻ÷��� �ƹ����ڳ� �Է��ϼ���! �� ";
	string a;
	cin >> a;
	Round1();

}