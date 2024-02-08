#include "gameclear.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //종료함수



void gameclear() {
	
    SetConsoleOutputCP(CP_UTF8);
    

    std::string line;
    std::string filePath2 = "C:\\Users\\jisou\\Desktop\\코딩온\\게임프로젝트\\세종.txt";
    std::ifstream file2(filePath2, std::ios::binary);
    //std::string line;
    while (std::getline(file2, line)) {
        std::cout << line << std::endl;
    }
    file2.close();

    int x;
    std::cin >> x;
    exit(0);

    SetConsoleOutputCP(949);
}