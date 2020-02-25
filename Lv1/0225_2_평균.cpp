#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
	정수 배열 arr 의 평균값 리턴 해라
*/

double solution_02252(vector<int> arr) {
	double answer = 0;

	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		answer += arr[i];
	}

	answer = answer / size;

	return answer;
}

int main_02252()
{



	return 777;
}