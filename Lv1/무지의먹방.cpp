#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
	- food_times.size() = �� ������ ��
	- �� ���� �迭�� ���Ҵ� ������ ��
	- k���� �� ������ �迭�� ���° �����ΰ�?
	- ������ ������ -1 ����
*/

int solution_����(vector<long> food_times, long long k) {
	int answer = 0;
	
	long size = food_times.size();

	long iter = 0; //����

	//Ÿ�� üũ
	long long time = 0;
	
	while (true)
	{
		if (food_times[iter] == 0)//Ǫ�尡 ������ ���� Ǫ��� �Ѿ��
		{
			iter++;
		}
		else if (food_times[iter] > 0)//Ǫ�尡 ������ �Ծ��
		{
			food_times[iter]--;
		}

		//�԰���? => �ð� �þ�� �ϰ�, ���� Ǫ��� �Ѿ�� �Ѵ�.
		iter++;
		//��, iter�� �ִ� Ǫ�庸�� Ŀ���� �ٽ� ó�� Ǫ��� �̵��ؾ� �Ѵ�.
		if (iter == size) iter = 0;

		//�ð� ����
		time++;

		//��������
		if (time == k || k == 0) break;
	}
	
	//����ó��
	if (food_times[iter] == 0) answer = -1;
	else answer = iter + 1;


	return answer;
}


