#pragma once
#include <stdio.h>
#include <windows.h>


//Ŀ����ġ �̵��Լ�
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	COORD pos;  //Ŀ���� ��ġ
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos); //Ŀ���� ��ġ�� ������ ��ǥ�� �̵���Ų��
}