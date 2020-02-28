#include <vector>
#include <iostream>

using namespace std;

/*
	배열 arr은 숫자 0~ 9
	arr에서 연속 숫자는 하나만 남기고 전부 제거
	제거 후 원소 순서 유지해야 함
	- arr크기 100만 이하
*/

vector<int> solution_02286(vector<int> arr)
{
	vector<int> answer;

	vector<int>::iterator iter1 = arr.begin();
	vector<int>::iterator iter2 = arr.begin();
	++iter2;

	//처음거 넣기
	answer.push_back(*iter1);

	for (iter2; iter2 < arr.end(); ++iter2)
	{
		if (*iter1 != *iter2)
		{
			answer.push_back(*iter2);
		}
		++iter1;
	}

	return answer;
}

int main_02286()
{
	solution_02286({ 4, 4, 4, 3, 3 });

	return 787;
}