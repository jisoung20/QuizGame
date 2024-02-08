#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);

    // 읽어올 파일의 경로
    std::string filePath = "C:\\Users\\jisou\\Desktop\\코딩온\\게임프로젝트\\세종만원1.txt";

    // 파일 열기
    std::ifstream file(filePath, std::ios::binary);

    // 파일의 내용을 한 줄씩 읽어와서 출력
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // 파일 닫기
    file.close();
 
    //세종2
    std::string filePath2 = "C:\\Users\\jisou\\Desktop\\코딩온\\게임프로젝트\\세종만원2.txt";
    std::ifstream file2(filePath2, std::ios::binary);
    //std::string line;
    while (std::getline(file2, line)) {
        std::cout << line << std::endl;
    }
    file2.close();

    //세종3
    std::string filePath3 = "C:\\Users\\jisou\\Desktop\\코딩온\\게임프로젝트\\세종만원3.txt";
    std::ifstream file3(filePath3, std::ios::binary);
    //std::string line;
    while (std::getline(file3, line)) {
        std::cout << line << std::endl;
    }
    file3.close();


    SetConsoleOutputCP(949);
    return 0;
}