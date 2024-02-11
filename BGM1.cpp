#pragma once
#include "BGM1.h"
#include <iostream>
#include <windows.h>
#pragma comment(lib,"winmm.lib")

//배경음악함수

void BGM1()
{
    // 배경 음악 파일 경로 -> "C:\\Users\\jisou\\Codingon\\0122\\QuizGame\\ami.wav";

    // 배경 음악 재생
    PlaySound(TEXT("C:\\Users\\jisou\\Codingon\\0122\\QuizGame\\bgm.wav"), NULL, SND_ASYNC | SND_LOOP);

    // 음악계속 재생하게 만든다.
}


