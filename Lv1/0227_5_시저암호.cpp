#include <string>
#include <vector>

using namespace std;

/*
	���� ���ĺ��� �����Ÿ���ŭ �о� �ٸ� ���ĺ����� �ٲٴ� ���
	- ������ �о ����
	- s�� ���ĺ� ��ҹ��ڿ� ����
	- s�� ���̴� 8000����
	- n�� 25���� �ڿ���
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
		else if ('a' <= answer[i] && answer[i] <= 'z')//�ҹ���
		{
			if (answer[i] + n > 127)
			{
				answer[i] -= 26;
			}
			answer[i] += n;
			if (answer[i] > 'z') answer[i] -= 26;
			
		}
		else if ('A' <= answer[i] && answer[i] <= 'Z')//�빮��
		{
			answer[i] += n;
			if (answer[i] > 'Z') answer[i] -= 26;
		}

	}



	return answer;
}


int main_02275()
{
	//26�� ����
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