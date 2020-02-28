#include <string>
#include <vector>

using namespace std;
/*
	양의 정수 x 하샤드 수이려면 x의 자릿수의 합으로 x가 나눠져야 한다
	18의 자리수 합은 1 + 8 = 9
	19은 9로 나눠짐.
	수 x가 하샤드 수인지 판별하라
*/

bool solution_02281(int x) {
	bool answer = true;

	int n = x;
	int Psum = 0;

	while (n > 0)
	{
		Psum += n % 10;
		n /= 10;
	}

	if (x % Psum != 0) answer = false;
	

	return answer;
}