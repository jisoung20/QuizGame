#pragma once
#include "BGM1.h"
#include <iostream>
#include <windows.h>
#pragma comment(lib,"winmm.lib")

//��������Լ�

void BGM1()
{
    // ��� ���� ���� ��� -> "C:\\Users\\jisou\\Codingon\\0122\\QuizGame\\ami.wav";

    // ��� ���� ���
    PlaySound(TEXT("C:\\Users\\jisou\\Codingon\\0122\\QuizGame\\bgm.wav"), NULL, SND_ASYNC | SND_LOOP);

    // ���ǰ�� ����ϰ� �����.
}


