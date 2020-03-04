#include <string>
#include <vector>
#include <map>

using namespace std;

/*
	1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ���� ��ȯ
	�Ҽ��� 1�� �ڱ� �ڽ����θ� ������ ����.
	n�� 2~100�� ����
*/

//�迭�� bool �� ó�� �ؼ� �غ�
int solution_03041(int n) {
	int answer = 0;

	bool* arr = new bool[n + 1]; // 0 ~ n ����

	//�ʱ�ȭ
	for (int i = 2; i < n + 1; i++)
	{
		arr[i] = true;
	}

	//�Ҽ��� �ƴ� ģ�� �ɷ�����
	//3 �̸� 2 ���� üũ
	for (int i = 2; i * i <= n + 1; i++)
	{
		if (arr[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				arr[j] = false;
			}
		}
	}

	for (int i = 2; i < n + 1; i++)
	{
		if (arr[i]) answer++;
	}


	return answer;
}


//ȿ���� �׽�Ʈ�� �� ������..
int solution_effectivenessError(int n) {
	int answer = 0;


	multimap<int, bool> list;
	//�ʱ�ȭ
	for (int i = 2; i < n + 1; i++)
	{
		list.insert(multimap<int, bool>::value_type(i, true));
	}

	//3�� ���
	//iter = 2 : 
	multimap<int, bool>::iterator iter = list.begin();
	for (iter; iter != list.end(); ++iter)
	{
		if (iter->second)
		{
			int a = 0;
			//�Ҽ� �Ǻ�
			for(int i = 1; i < iter->first; i++)
			{
				if (iter->first % i == 0)
				{
					a++;
					if (a > 1)
					{
						iter->second = false;
						
						break;
					}
				}
			}
		}
	}

	//true �� ���� ã��
	iter = list.begin();
	for (iter; iter != list.end(); ++iter)
	{
		if (iter->second) answer++;
	}
	
	

	return answer;
}