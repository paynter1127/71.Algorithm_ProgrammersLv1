#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
	x부터 시작해 x씩 증가하는 숫자를 n개 지니는 리스트를 리턴해야 한다.
	- x의 범위 있고,
	- ndms 1000이하 자연수
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