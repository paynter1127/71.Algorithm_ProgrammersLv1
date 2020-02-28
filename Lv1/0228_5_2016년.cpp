#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
	2016년 1월 1일은 금요일
	a월 b일은 무슨요일인가?
	- 2016년은 윤년 366일 2월 29일 존재
	- 2월 29, 4월 30, 6월 30, 9월 30, 11월 30
*/


string solution_02285(int a, int b) {
	string answer[] = { "emp", "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

	unordered_map<int, int> data;
	//데이터 넣기
	data.insert(unordered_map<int, int>::value_type(1, 31));
	data.insert(unordered_map<int, int>::value_type(2, 29));
	data.insert(unordered_map<int, int>::value_type(3, 31));
	data.insert(unordered_map<int, int>::value_type(4, 30));
	data.insert(unordered_map<int, int>::value_type(5, 31));
	data.insert(unordered_map<int, int>::value_type(6, 30));
	data.insert(unordered_map<int, int>::value_type(7, 31));
	data.insert(unordered_map<int, int>::value_type(8, 31));
	data.insert(unordered_map<int, int>::value_type(9, 30));
	data.insert(unordered_map<int, int>::value_type(10, 31));
	data.insert(unordered_map<int, int>::value_type(11, 30));
	data.insert(unordered_map<int, int>::value_type(12, 31));
	
	int days = 0;

	if(a != 1)
	{
		for (int i = 1; i < a; i++)
		{
			days += data.find(i)->second;
		}
	}
	days += b;//일 더하고
	days %= 7;
	if (days == 0) days = 7;
	

	return answer[days];
}

int main_02285()
{
	
	cout << solution_02285(1, 7);
	


	return 787;
}

