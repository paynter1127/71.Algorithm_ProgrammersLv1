#include <string>
#include <iostream>
using namespace std;

/*
	y�� p�� ������ ������ true
	��ҹ��� ���� ����.
*/

bool solution(string s)
{
	bool answer = true;
	
	int size = s.size();

	int pNum = 0;
	int yNum = 0;

	for(int i = 0; i < size; i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
			pNum++;
		else if (s[i] == 'y' || s[i] == 'Y')
			yNum++;
	}

	if (pNum != yNum) answer = false;


	return answer;
}

int main()
{
	std::cout << "Hello World!\n";

	cout << solution("pPoooyY") << true;

	return 777;
}