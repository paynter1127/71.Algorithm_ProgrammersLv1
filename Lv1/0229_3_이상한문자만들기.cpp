#include <string>
#include <vector>

using namespace std;

/*
	s �� �� �� �̻��� �ܾ�� ����
	�� �ܾ�� ���� ���ڷ� ����
	�� �ܾ� ¦����°�� �빮��, 
	�� �ܾ� Ȧ����°�� �ҹ��ڷ� �ٲ� ���ڿ� ���� �Լ�
	- ù ���ڴ� 0��° �ε����� ¦���� ó�� �϶�
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
		else //������ �ƴ϶��
		{
			if (initIndex % 2 == 0)//¦�� �ε���
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
