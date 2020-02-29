#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	물품 구매
	물품 구매시는 부서 신청 금액 만큼 풀로 지원
	신청 금액 배열 d
	예산 budget
	몇개 부서에 물품 지원 가능한지 return 해라
	- d의 길이 1~100
	- d의 각 원소는 신청 금액 1~100,000 의 자연수
	- budget은 예산 1~천만
*/

int solution_02295(vector<int> d, int budget) {
	int answer = 0;

	//정렬 해서 빼나가면 되겠는데
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

