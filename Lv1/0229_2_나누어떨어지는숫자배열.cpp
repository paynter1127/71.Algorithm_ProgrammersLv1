#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	arr�� �� ��� �� divisor�� ������ �������� ���� ���� �������� ������ �迭 ��ȯ
	�ϳ��� ������ �迭�� -1 ��ȯ
	- arr�� �ڿ���
	- �ߺ� ����
	- divisor �ڿ���
	- arr �� ���� 1�̻�
*/

vector<int> solution_02292(vector<int> arr, int divisor) {
	vector<int> answer;


	vector<int>::iterator iter = arr.begin();

	for (iter; iter < arr.end(); ++iter)
	{
		if (*iter % divisor == 0)
		{
			answer.push_back(*iter);
		}
	}

	sort(answer.begin(), answer.end());

	if (answer.size() == 0) answer.push_back(-1);

	return answer;
}