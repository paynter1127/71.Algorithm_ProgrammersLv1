#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
	x���� ������ x�� �����ϴ� ���ڸ� n�� ���ϴ� ����Ʈ�� �����ؾ� �Ѵ�.
	- x�� ���� �ְ�,
	- ndms 1000���� �ڿ���
*/

vector<long long> solution_02242(int x, int n) {
	vector<long long> answer;

	int init = x;

	for (int i = 0; i < n; i++)
	{
		answer.push_back(x);
		x += init;
	}

	return answer;
}

int main_02242()
{
	std::cout << "Hello World!\n";

	
	solution_02242(2, 5);



	return 777;
}