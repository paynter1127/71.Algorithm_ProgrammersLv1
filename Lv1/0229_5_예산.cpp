#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	��ǰ ����
	��ǰ ���Žô� �μ� ��û �ݾ� ��ŭ Ǯ�� ����
	��û �ݾ� �迭 d
	���� budget
	� �μ��� ��ǰ ���� �������� return �ض�
	- d�� ���� 1~100
	- d�� �� ���Ҵ� ��û �ݾ� 1~100,000 �� �ڿ���
	- budget�� ���� 1~õ��
*/

int solution_02295(vector<int> d, int budget) {
	int answer = 0;

	//���� �ؼ� �������� �ǰڴµ�
	sort(d.begin(), d.end());
	
	vector<int>::iterator iter = d.begin();
	for (iter; iter < d.end(); ++iter)
	{
		if (*iter <= budget)
		{
			budget -= *iter;
			answer++;
		}
		else break;
	}
	

	

	return answer;
}

int main_02295()
{
	std::cout << "hello";

	return 787;
}

