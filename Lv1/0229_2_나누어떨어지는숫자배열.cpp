#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	arr의 각 요소 중 divisor로 나누어 떨어지는 값을 오름 차순으로 정렬한 배열 반환
	하나도 없으면 배열에 -1 반환
	- arr은 자연수
	- 중복 없다
	- divisor 자연수
	- arr 은 길이 1이상
*/

vector<int> solution_02292(vector<int> arr, int divisor) {
	vector<int> answer;


	vector<int>::iterator iter = arr.begin();

	for (iter; iter < arr.end(); ++iter)
	{
		if (*iter % divisor == 0)
		{
			answer.push_back(*iter);
		}
	}

	sort(answer.begin(), answer.end());

	if (answer.size() == 0) answer.push_back(-1);

	return answer;
}