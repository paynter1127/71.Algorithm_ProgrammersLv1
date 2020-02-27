#include <string>
#include <vector>

using namespace std;

/*
	자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 리턴
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

