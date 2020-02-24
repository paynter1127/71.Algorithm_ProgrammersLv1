// Lv1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution_02231(string s) {
	string answer = "";

	// z:122 / a:97 / A:65 / Z:90
	int iter = 122;

	//푸시백으로 다 처리 해봅시다.
	while (true)
	{
		for (int i = 0; i < s.size(); i++)
		{
			//소문자 먼저 돌리기
			if (s[i] == iter)
			{
				answer.push_back(iter);
			}
		}
		iter--;
		if (iter == 96) break;
	}
	
	//대문자 처리 합시다.
	iter = 90;
	while (true)
	{
		for (int i = 0; i < s.size(); i++)
		{
			//소문자 먼저 돌리기
			if (s[i] == iter)
			{
				answer.push_back(iter);
			}
		}
		iter--;
		if (iter == 64) break;
	}



	return answer;
}

int main_02231()
{
    std::cout << "Hello World!\n";

	//문자열 s에 나타나는 문자를 큰 것 부터 작은 순으로 정렬해 새로운 문자열을 리컨하는 함수
	// s는 영문 대소문자, 대문자는 소문자보다 작다.
	

	cout << solution_02231("ABCDEFGabcdefghijklmnopqrstuvwxyz");
	//리턴은 : gfedcbZ 이 되도록..
	//대문자는 Z 가 가장 작은 숫자로
	//소문자는 a 가 가장 작은 숫자로

	return 777;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
