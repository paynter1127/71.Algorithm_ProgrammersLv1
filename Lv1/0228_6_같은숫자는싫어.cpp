#include <vector>
#include <iostream>

using namespace std;

/*
	�迭 arr�� ���� 0~ 9
	arr���� ���� ���ڴ� �ϳ��� ����� ���� ����
	���� �� ���� ���� �����ؾ� ��
	- arrũ�� 100�� ����
*/

vector<int> solution_02286(vector<int> arr)
{
	vector<int> answer;

	vector<int>::iterator iter1 = arr.begin();
	vector<int>::iterator iter2 = arr.begin();
	++iter2;

	//ó���� �ֱ�
	answer.push_back(*iter1);

	for (iter2; iter2 < arr.end(); ++iter2)
	{
		if (*iter1 != *iter2)
		{
			answer.push_back(*iter2);
		}
		++iter1;
	}

	return answer;
}

int main_02286()
{
	solution_02286({ 4, 4, 4, 3, 3 });

	return 787;
}