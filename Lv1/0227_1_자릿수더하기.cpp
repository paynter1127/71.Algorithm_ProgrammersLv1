#include <iostream>

using namespace std;
/*
	자연수N 각 자리수 합 구해서 return
	*/
int solution(int n)
{
	int answer = 0;

	while (n >= 1)
	{
		answer += n % 10;
		n = n / 10;
	}

	return answer;
}