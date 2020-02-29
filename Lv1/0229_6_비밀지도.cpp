#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <deque>

using namespace std;

/*
	���ڷ� ��ȣȭ ���� �ص��ϱ�
	1. �Ѻ��� ���̰� n�� �� �簢�� �迭, �� ĭ�� ����� ��"#"���� ����
	2. ��ü ������ �� �� ���� ���� ��´�. �ϳ��� ���̸� �� ó��
	3. ����1�� ����2�� ���� �迭�� ��ȣȭ
	4. �迭�� ������ ���� 1, ������ 0���� ǥ���� ���� �迭
	- n �� 1~16
*/

vector<string> solution_02296(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	int size = n;

	for (int i = 0; i < size; i++)
	{
		deque<string> result;
		int num1 = arr1[i];
		int num2 = arr2[i];
		string pushBack = "";

		for (int j = 0; j < size; j++)
		{
			if (bitset<16>(num1)[j] == 1 || bitset<16>(num2)[j] == 1)
			{
				result.push_front("#");
			}
			else result.push_front(" ");

			//pushBack.push_back(' ');
		}

		for (int j = 0; j < size; j++)
		{
			pushBack.push_back(result[j][0]);
		}

		answer.push_back(pushBack);
	}


	return answer;
}

int main_02296()
{
	int num = 20;
	
	//2�� ��ȯ �׽�Ʈ
	cout << bitset<5>(num) << endl;
	cout << bitset<5>(num)[4] << endl;
	cout << bitset<5>(num)[3] << endl;
	cout << bitset<5>(num)[2] << endl;
	cout << bitset<5>(num)[1] << endl;
	cout << bitset<5>(num)[0] << endl;

	

	return 787;
}