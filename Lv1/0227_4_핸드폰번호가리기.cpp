#include <string>
#include <vector>

using namespace std;

/*
	��ȭ��ȣ �� 4�ڸ� �����ϰ� ������ *�� ���
*/

string solution_02274(string phone_number) {
	string answer = "";

	int size = phone_number.size();

	for (int i = 0; i < size - 4; i++)
	{
		answer.push_back('*');
	}
	for (int i = 0; i < 4; i++)
	{
		answer.push_back(phone_number[size - 4 + i]);
	}


	return answer;
}

