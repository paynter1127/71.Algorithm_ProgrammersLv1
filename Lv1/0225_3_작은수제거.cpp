#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	���� ���� �迭 arr
	������ ������ �迭 ����

	�迭�� ��� ������ -1�� �� �迭 ����
	(�迭 ����� 1�̸� -1 �����̳�)
*/

vector<int> solution_02253(vector<int> arr) {
	vector<int> answer;

	

	int size = arr.size();
	if (size == 1)
	{
		answer.push_back(-1);
		return answer;
	}
	else
	{
		answer = arr;
		sort(arr.begin(), arr.end());

		int iter = 0;
		for (iter; iter < size; iter++)
		{
			if (arr[0] == answer[iter])
			{
				answer.erase(answer.begin() + iter);
				break;
			}
		}
	}


	return answer;
}

int main_02253()
{


	return 777;
}
