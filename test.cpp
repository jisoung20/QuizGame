#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);

    // �о�� ������ ���
    std::string filePath = "C:\\Users\\jisou\\Desktop\\�ڵ���\\����������Ʈ\\��������1.txt";

    // ���� ����
    std::ifstream file(filePath, std::ios::binary);

    // ������ ������ �� �پ� �о�ͼ� ���
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // ���� �ݱ�
    file.close();
 
    //����2
    std::string filePath2 = "C:\\Users\\jisou\\Desktop\\�ڵ���\\����������Ʈ\\��������2.txt";
    std::ifstream file2(filePath2, std::ios::binary);
    //std::string line;
    while (std::getline(file2, line)) {
        std::cout << line << std::endl;
    }
    file2.close();

    //����3
    std::string filePath3 = "C:\\Users\\jisou\\Desktop\\�ڵ���\\����������Ʈ\\��������3.txt";
    std::ifstream file3(filePath3, std::ios::binary);
    //std::string line;
    while (std::getline(file3, line)) {
        std::cout << line << std::endl;
    }
    file3.close();


    SetConsoleOutputCP(949);
    return 0;
}