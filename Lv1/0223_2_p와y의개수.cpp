#include <string>
#include <iostream>
using namespace std;

/*
	y와 p의 개수가 같으면 true
	대소문자 구별 없다.
*/

bool solution_2(string s)
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

int _main()
{
	std::cout << "Hello World!\n";

	cout << solution_2("pPoooyY") << true;

	return 777;
}