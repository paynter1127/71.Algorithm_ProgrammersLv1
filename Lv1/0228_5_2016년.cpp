#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
	2016�� 1�� 1���� �ݿ���
	a�� b���� ���������ΰ�?
	- 2016���� ���� 366�� 2�� 29�� ����
	- 2�� 29, 4�� 30, 6�� 30, 9�� 30, 11�� 30
*/


string solution_02285(int a, int b) {
	string answer[] = { "emp", "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

	unordered_map<int, int> data;
	//������ �ֱ�
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
	days += b;//�� ���ϰ�
	days %= 7;
	if (days == 0) days = 7;
	

	return answer[days];
}

int main_02285()
{
	
	cout << solution_02285(1, 7);
	


	return 787;
}

