#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

/*
	������ : �������� && Ŭ���� ���� �÷��̾� �� / �������� ���� �÷��̾� ��
	- ��ü �������� ���� N
	- �����ִ� �������� ��ȣ �迭 stages (����� ��� ������ ��� ��)
	������ ���� ������������ ������������ �������� ��ȣ�� ��� �迭�� �����϶�. (1 ���� ��������)
	- �������� ���� N �� 1~500 �ڿ���
	- stages ���� 1~200,200 ����
	- stages ������ 1~ N+1���� �ڿ����� ��� �ִ�.
		. �� �ڿ����� ����ڰ� ������ ��������
		. N+1�� ������ ��������(N��������) ���� Ŭ������ �����
	- �������� ������ ���� ��ȣ ���������� ���� ����
	- �������� ���� ������ ������ �������� 0
*/


vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	//��� ��
	int manSize = stages.size();

	//���͸� ������ ����
	multiset<int> stage;
	for (vector<int>::iterator iter = stages.begin(); iter < stages.end(); ++iter)
	{
		stage.insert(*iter);
	}

	//�������� ���� �� ����
	multimap<float, int> failRate; //������, ��������

	int pNum = 0;
	int no = 0;
	
	//�������� �� ������ ���
	for (int i = N; i > 0; i--)
	{
		//������ �������� ����ó��
		if (i == N)
		{
			pNum += stage.count(i + 1);//�� Ǭ��
			no = stage.count(i); //�� Ǭ��
			
			if (pNum == 0 && no == 0) //����������, Ǯ���� ���� ���
			{
				failRate.insert(multimap<float, int>::value_type(0, i));
			}
			else//�� Ǭ���� �ְ� ���� ������ �� ���
			{
				pNum += no;
				failRate.insert(multimap<float, int>::value_type(no / pNum, i)); //������ �������� ������ �ֱ�
			}
			
		}
		else //������ ���������� �ƴ� ���
		{
			//pNum += stage.count(i); //������ 0�� �� �ִ�.
			no = stage.count(i); //�� Ǭ��
			pNum += no;

			if (pNum == 0)//���޵�, Ǯ���� ���� ���
			{
				failRate.insert(multimap<float, int>::value_type(0, i));
			}
			else
			{
				failRate.insert(multimap<float, int>::value_type(((float)no) / ((float)pNum), i));
			}
		}
	}
	
	
	/*
	for (int i = N; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (failRate.find(j)->second == i)
			{
				answer.push_back(failRate.find(j)->second);
			}
		}
	}
	*/


	return answer;
}

int main()
{
	printf("hello");

	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });

	cout << endl << sizeof(int) << endl;
	cout << sizeof(long) << endl;

	return 787;
}