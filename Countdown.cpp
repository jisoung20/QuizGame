#pragma once
#include "Countdown.h"
#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "gotoxy.h"
#include <future>


using namespace std;

void countdown() {

    int time = 5;
    for (time; time > 0; time--) {
        gotoxy(1, 1);
        cout << "남은 시간: " << time << "초" << std::endl;
        this_thread::sleep_for(chrono::seconds(1)); // 1초 동안 대기
    }
    gotoxy(1, 1);
    std::cout << " TIME OVER !! " << std::endl;

}