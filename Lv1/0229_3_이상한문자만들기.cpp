#include <string>
#include <vector>

using namespace std;

/*
	s 는 한 개 이상의 단어로 구성
	각 단어는 공백 문자로 구분
	각 단어 짝수번째는 대문자, 
	각 단어 홀수번째는 소문자로 바꾼 문자열 리턴 함수
	- 첫 글자는 0번째 인덱스로 짝수로 처리 하라
*/

string solution_02293(string s) {
	string answer = "";

	int size = s.size();
	int initIndex = 0;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == ' ')
		{
			if (initIndex != 0) initIndex = 0;
			continue;
		}
		else //공백이 아니라면
		{
			if (initIndex % 2 == 0)//짝수 인덱스
			{
				s[i] = toupper(s[i]);
			}
			else if (initIndex % 2 == 1)
			{
				s[i] = tolower(s[i]);
			}
			initIndex++;
		}
	}

	answer = s;


	return answer;
}
