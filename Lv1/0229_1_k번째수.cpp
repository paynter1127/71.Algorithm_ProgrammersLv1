#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
	i ���� j���� �ڸ��� ���� �� k��° �� ���ϱ�
	- array ���̴� 1�̻� 100����
	- ���Ҵ� 1~100
	- commands ���� 1~50
	- commands ���� ���� 3
*/

vector<int> solution_02291(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	
	int size = commands.size(); //��� Ƚ��

	//���� ���� ����� �ű⿡ Ŀ��Ʈ ��ŭ �߶� �ֱ�
	for (int i = 0; i < size; i++)
	{
		vector<int> temp;
		temp.insert(temp.begin(), &array[commands[i][0] - 1], &array[commands[i][1]]);
		//��Ʈ
		sort(temp.begin(), temp.end());
		//�߶� ���� ���� Ŀ�ǵ��� �� �̾Ƽ� answer�� �ֱ�
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