#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
	- food_times.size() = 총 음식의 수
	- 각 벡터 배열의 원소는 음식의 양
	- k초일 때 음식은 배열의 몇번째 음식인가?
	- 음식이 없으면 -1 리턴
*/

int solution_무지(vector<long> food_times, long long k) {
	int answer = 0;
	
	long size = food_times.size();

	long iter = 0; //이터

	//타임 체크
	long long time = 0;
	
	while (true)
	{
		if (food_times[iter] == 0)//푸드가 없으면 다음 푸드로 넘어가라
		{
			iter++;
		}
		else if (food_times[iter] > 0)//푸드가 있으면 먹어라
		{
			food_times[iter]--;
		}

		//먹고나면? => 시간 늘어나야 하고, 다음 푸드로 넘어가야 한다.
		iter++;
		//단, iter이 최대 푸드보다 커지면 다시 처음 푸드로 이동해야 한다.
		if (iter == size) iter = 0;

		//시간 증가
		time++;

		//종료하자
		if (time == k || k == 0) break;
	}
	
	//예외처리
	if (food_times[iter] == 0) answer = -1;
	else answer = iter + 1;


	return answer;
}


