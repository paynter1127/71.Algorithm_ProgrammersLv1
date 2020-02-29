#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
	i 에서 j까지 자르고 정렬 후 k번째 수 구하기
	- array 길이는 1이상 100이하
	- 원소는 1~100
	- commands 길이 1~50
	- commands 원소 길이 3
*/

vector<int> solution_02291(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	
	int size = commands.size(); //명령 횟수

	//임의 벡터 만들고 거기에 커맨트 만큼 잘라 넣기
	for (int i = 0; i < size; i++)
	{
		vector<int> temp;
		temp.insert(temp.begin(), &array[commands[i][0] - 1], &array[commands[i][1]]);
		//소트
		sort(temp.begin(), temp.end());
		//잘라 넣은 데서 커맨드의 수 뽑아서 answer에 넣기
		answer.push_back(temp[commands[i][2] - 1]);
		temp.clear();
	}

	return answer;
}

int main_02291()
{
	solution_02291({ 1, 5, 2, 6, 3, 7, 4 }, { { 2, 5, 3 }, {4, 4, 1},{1, 7, 3} });

	return 787;
}