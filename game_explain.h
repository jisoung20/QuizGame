#pragma once
#include <iostream>

using namespace std;

class game_explain
{
public:
	game_explain()
	{
		cout << endl;
		cout << "♥♡게임 정보♥♡" << endl;
		cout << "1.시대가 발전함에 따라 잊어버리기 쉬운 우리 민족의 역사를 상기시키고자 이 게임을 제작하였습니다." << endl;
		cout << "2.본 게임은 1단계부터 n단계까지 이루어져 있으며, 단계가 진행됨에 따라 난이도가 상승합니다." << endl;
		cout << "3.본 게임은 단계별로 힌트가 있으며, 힌트 사용 시 50포인트가 소멸됩니다. " << endl;
		cout << "4.본 게임을 clear하게 되면, 노아 리더님께로 부터 어마무시한 상품이 있습니다. ^0^" << endl;
		cout << endl;
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "♡♥게임 방법♡♥" << endl;
		cout << "1.6*6으로 이루어진 배열에서 설명을 보고 그에 맞는 답을 입력하면 정답입니다." << endl;
		cout << "2.정답을 맞추게 되면 배열에서 맞춘 답에 해당하는 글자가 사라지게 됩니다." << endl;
		cout << "3.모든 정답을 맞추게 되면 배열의 모든 글자가 사라지게 되고, 본 단계를 clear하게 됩니다." << endl;
		cout << "4.다음 단계 도전 시 다음을, 그만 하고 싶다면 종료를 누르세요." << endl;

	}

	~game_explain(){}

};

int main()
{
	game_explain G;
	G;





	return 0;
}