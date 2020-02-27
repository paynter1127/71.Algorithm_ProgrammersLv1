#include <string>
#include <vector>

using namespace std;

/*
	문장 알파벳을 일정거리만큼 밀어 다른 알파벳으로 바꾸는 방식
	- 공백은 밀어도 공백
	- s는 알파벳 대소문자와 공백
	- s의 길이는 8000이하
	- n은 25이하 자연수
*/

string solution_02275(string s, int n) {
	string answer = "";

	answer = s;

	int size = answer.size();

	for (int i = 0; i < size; i++)
	{
		if (answer[i] == ' ')
		{
			continue;
		}
		else if ('a' <= answer[i] && answer[i] <= 'z')//소문자
		{
			if (answer[i] + n > 127)
			{
				answer[i] -= 26;
			}
			answer[i] += n;
			if (answer[i] > 'z') answer[i] -= 26;
			
		}
		else if ('A' <= answer[i] && answer[i] <= 'Z')//대문자
		{
			answer[i] += n;
			if (answer[i] > 'Z') answer[i] -= 26;
		}

	}



	return answer;
}


int main_02275()
{
	//26개 문자
	//65
	char A = 'A';
	printf("%c", A);
	printf("%d\n", A);

	//90
	char Z = 'Z';
	printf("%c", Z);
	printf("%d\n", Z);

	Z++;
	if (Z + 1 > 90)
	{
		// 91 - 26 = 65
		Z -= 26;
	}
	printf("%c", Z);
	printf("%d\n", Z);

	//97
	char a = 'a';
	printf("%c", a);
	printf("%d\n", a);

	//122
	char z = 'z';
	printf("%c", z);
	printf("%d\n", z);

	//char ss = ' ';
	//printf("%d", ss);

	return 777;
}