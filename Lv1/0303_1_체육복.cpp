#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	��ȣ�� ü�� ��, ���̳� �� ��ȣ���Ը� ü���� �뿩 ����
	���� �л��� ü������
	�л� �� n
	lost : ���� ���� �л� ��ȣ �迭
	reserve : ������ ü������ ������ �л� ��ȣ �迭
	ü�� ���� �л� �ִ밪 ����
	- ��ü �л� �� 2~30
	- ���� �л� �� 1~n�̰� �ߺ� ����
	- ���� ü���� �� 1~n �̰� �ߺ� ����
	- ���� ü���� �л��� �뿩 ���� - �ڱⲨ ���� ���ϸ� ���� �� �� ���ٴ� ��***
	- ���� ü���� �л��� ���� �����ϰ� �� �� �뿩 �Ұ�
*/

int solution_03031(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	
	int firstSize = reserve.size();

	int Lsize = lost.size();
	//���� �ִ� �л� �� �ڱⲨ ���� ���ߴ��� üũ�ϰ� ���� �� ��
	for (int i = 0; i < Lsize; i++)
	{
		for (vector<int>::iterator iterR = reserve.begin(); iterR != reserve.end(); ++iterR)
		{
			if (lost[i] == *iterR)
			{
				//�ν�Ʈ��, �����굵 ���� �ؾ� �Ѵ�.
				lost.erase(lost.begin() + i);
				reserve.erase(iterR);
				Lsize = lost.size();
				i--;
				break;
			}
		}
	}

	Lsize = lost.size();
	for (int i = 0; i < Lsize; i++)
	{
		int size = reserve.size();
		for (int j = 0; j < size; j++)
		{
			//1���� ũ�� ���� �л� ã�� ����
			if (reserve[j] > lost[i] + 1) break;
			else //1���� ũ�� ������ ���� �л� ã��
			{
				if (lost[i] == reserve[j] + 1) //�ڷ� ���� �ֱ�
				{
					lost.erase(lost.begin() + i);
					Lsize = lost.size();
					i--;
					reserve.erase(reserve.begin() + j);//j �ε��� ����
					break;//������ ã�� for �� ������
				}
				else if (lost[i] == reserve[j]) //���� ��ȣ
				{
					lost.erase(lost.begin() + i);
					Lsize = lost.size();
					i--;
					reserve.erase(reserve.begin() + j);//j �ε��� ����
					break;//������ ã�� for �� ������
				}
				else if (lost[i] == reserve[j] - 1) //�� ��ȣ
				{
					lost.erase(lost.begin() + i);
					Lsize = lost.size();
					i--;
					reserve.erase(reserve.begin() + j);//j �ε��� ����
					break;//������ ã�� for �� ������
				}
			}
		}
	}

	int lastSize = reserve.size(); //���� �ְ� �� ��
	
	//���� �� �� 
	//int give = firstSize - lastSize;
	
	//���� ���� �� �ִ� �л� ����
	answer = n - lost.size();

	return answer;
}

int main_03031()
{
	//printf("%d", solution_03011(3, { 1, 3 }, { 1, 2, 3 }));
	
	return 787;
}