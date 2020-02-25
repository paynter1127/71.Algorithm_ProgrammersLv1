#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	정수 저장 배열 arr
	작은수 제거한 배열 리턴

	배열이 비어 있으면 -1이 들어간 배열 리턴
	(배열 사이즈가 1이면 -1 리턴이네)
*/

vector<int> solution_02253(vector<int> arr) {
	vector<int> answer;

	

	int size = arr.size();
	if (size == 1)
	{
		answer.push_back(-1);
		return answer;
	}
	else
	{
		answer = arr;
		sort(arr.begin(), arr.end());

		int iter = 0;
		for (iter; iter < size; iter++)
		{
			if (arr[0] == answer[iter])
			{
				answer.erase(answer.begin() + iter);
				break;
			}
		}
	}


	return answer;
}

int main_02253()
{


	return 777;
}
