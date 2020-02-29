#include <string>
#include <vector>

using namespace std;

/*
	�ִ� ������� �ּҰ���� ��ȯ �Լ�
*/


vector<int> solution_02294(int n, int m) {
	vector<int> answer;

	int bigNum = n;
	int smallNum = m;
	if (n < m)
	{
		bigNum = m;
		smallNum = n;
	}

	//�ִ� �����
	for (int i = smallNum; i > 0; i--)
	{
		if (n % i == 0 && m % i == 0) 
		{
			answer.push_back(i);
			break;
		}
	}

	//�ּ� �����
	while (true)
	{
		if (bigNum % m == 0 && bigNum % n == 0)
		{
			answer.push_back(bigNum);
			break;
		}
		bigNum++;
	}

	return answer;
}