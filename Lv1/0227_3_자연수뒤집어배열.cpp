#include <string>
#include <vector>

using namespace std;

/*
	�ڿ��� n�� ������ �� �ڸ� ���ڸ� ���ҷ� ������ �迭 ����
*/

vector<int> solution_0227_3(long long n) {
	vector<int> answer;

	while (n >= 1)
	{
		answer.push_back(n % 10);
		n /= 10;
	}

	return answer;
}

