#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	행, 열 크기 동일
	더하기 : 같은 열의 값을 더한 결과 
	두 행렬을 받아 덧셈을 반환하라
*/

vector<vector<int>> solution_02251(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	

	int sizeRow = arr1.size();
	int sizeCulomn = arr1[0].size();
	
	//for (int i = 0; i < sizeRow; i++)
	//{
	//	answer.push_back(arr1[i]);
	//}
	//이를 간추리는 다른 사람 풀이는
	answer = arr1; //이런 식으로 대입 연산이 되는구나 굳
	
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