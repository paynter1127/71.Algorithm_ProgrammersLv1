#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	��, �� ũ�� ����
	���ϱ� : ���� ���� ���� ���� ��� 
	�� ����� �޾� ������ ��ȯ�϶�
*/

vector<vector<int>> solution_02251(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	

	int sizeRow = arr1.size();
	int sizeCulomn = arr1[0].size();
	
	//for (int i = 0; i < sizeRow; i++)
	//{
	//	answer.push_back(arr1[i]);
	//}
	//�̸� ���߸��� �ٸ� ��� Ǯ�̴�
	answer = arr1; //�̷� ������ ���� ������ �Ǵ±��� ��
	
	for (int j = 0; j < sizeRow; j++)
	{
		for (int i = 0; i < sizeCulomn; i++)
		{
			answer[j][i] = arr1[j][i] + arr2[j][i];
		}
	}
	
	return answer;
}

int main_02251()
{
	cout << "hello world" << endl;

	vector<vector<int>> arr1 = { {0,1}, {2, 3} };
	//cout << arr1.size() << endl;

	vector<vector<int>> input;
	input.push_back(arr1[0]);
	input.push_back(arr1[1]);

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			cout <<  input[j][i];
		}
		cout << endl;
	}


	return 777;
}