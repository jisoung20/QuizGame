#include "Title.h"

#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <mmsystem.h>
#include"Ŀ����ǥ�̵�.h"

using namespace std;

//�� ����
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SUBMIT 32

//Ÿ��Ʋ ����
void Title() {
	std::cout << "\n\n\n\n";
	std::cout << "\t\t"; std::cout << "    �ˢ�        ��       ��         ��      �ˢˢˢ�   ��    �ˢˢˢˢˢˢˢ�   \n";
	std::cout << "\t\t"; std::cout << "  ��    ��  �ˢˢ�       ��         ��            ��   ��           ��          \n";
	std::cout << "\t\t"; std::cout << "  ��    ��      ��       ��         ��      �ˢˢˢ�   ��           ��          \n";
	std::cout << "\t\t"; std::cout << "    �ˢ�    �ˢˢ�       ��         �ˢˢ�        ��   ��         ��  ��        \n";
	std::cout << "\t\t"; std::cout << "                ��      �� ��       ��            ��   ��       ��      ��      \n";
	std::cout << "\t\t"; std::cout << "        �ˢˢˢˢ�     ��   ��      ��     �ˢˢˢˢˢˢ�     ��          ��    \n";
	std::cout << "\t\t"; std::cout << "                ��    ��     ��     ��           ��    ��   ��              ��  \n";
	std::cout << "\t\t"; std::cout << "                ��   ��       ��    ��           ��    ��                       \n";
	std::cout << "\t\t"; std::cout << "                ��  ��         ��   ��           ��    ��  �ˢˢˢˢˢˢˢˢˢ� \n";
	cout << endl;
	cout << "                                               �������� ��������\n" << endl;
	cout << "               1.�ô밡 �����Կ� ���� �ؾ������ ���� �츮 ������ ���縦 ����Ű���� �� ������ �����Ͽ����ϴ�." << endl;
	cout << "               2.�� ������ 1�ܰ���� n�ܰ���� �̷���� ������, �ܰ谡 ����ʿ� ���� ���̵��� ����մϴ�." << endl;
	cout << "               3.�� ������ �ܰ躰�� ��Ʈ�� ������, ��Ʈ ��� �� 50����Ʈ�� �Ҹ�˴ϴ�. " << endl;
	cout << "               4.�� ������ clear�ϰ� �Ǹ�, ��� �����Բ��� ���� ������� ��ǰ�� �ֽ��ϴ�. ^0^" << endl;
	cout << endl;
}

//���콺 �Է� �ޱ�
int keycontrol() {
	char temp = _getch();

	if (temp == 72 || temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 75 || temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 80 || temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 77 || temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == 32 || temp == ' ') {
		return SUBMIT;
	}
}
//����ȭ�� ����
int menudraw(){
	int x = 50; //24->50
	int y = 22;  //12-> 22
	gotoxy(x - 2, y);
	printf("> ���ӽ���\n");
	gotoxy(x, y + 1);
	printf("���ӹ��\n");
	gotoxy(x, y + 2);
	printf("����");
	while (1) { //���� �Ҷ� ���� ���ѹݺ�
		int n = keycontrol();//Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
		switch (n) {
		case UP: { // �Է� ���� ���� UP�ϰ��
			if (y > 22) { // �ִ� 12
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 24) { // �ִ� 14
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			y -= 22;
			if (y == 0) {
				system("cls");
				//Game();
			}
			if (y == 1) {
				system("cls");
				//How();
			}
			if (y == 2) {
				system("cls");
				//Exit();
			}
		}
		}
	}

}