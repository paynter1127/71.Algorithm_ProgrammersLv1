#include <string>
#include <vector>

using namespace std;

/*
	주어진 수가 1이 될때까지 작업을 반복하면 모든 수를 1로 만든다
	- 입력된 수가 짝수면 2로 나눈다
	- 입력된 수가 홀수면 3을 곱하고 1을 더한다
	- 위 반복
	- 단, 작업을 500번 반복해도 1이 안되면 -1 리턴
	- 참고 : 출제자 오류. 1인 경우에 0 반환 해야 한다.
*/

int solution_02282(int num) {
	int answer = 0;

	if (num == 1) return 0;

	for (int i = 1; i <= 500; i++)
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else if (num % 2 == 1)
		{
			num = num * 3 + 1;
		}
		
		if (num == 1)
		{
			return answer = i;
		}
	}

	return -1;
}