#include <string>
#include <vector>
#include <math.h>

using namespace std;

/*
	양의 정수 n
	n이 제곱근인가 판별
	n이 양의 정수 x의 제곱이면 
	x+1을 리턴
	아니면 -1 리턴
*/

long long solution_02271(long long n) {
	long long answer = 0;

	float size = sqrt(n);

	for (int i = 0; i <= size; i++)
	{
		if (i == size)
		{
			answer = pow(i + 1, 2);
		}
		else
		{
			answer = -1;
		}
	}

	return answer;
}

int main_02271()
{

	return 777;
}

