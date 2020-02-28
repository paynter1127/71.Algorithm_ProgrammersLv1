#include <string>
#include <vector>

using namespace std;

/*
	�־��� ���� 1�� �ɶ����� �۾��� �ݺ��ϸ� ��� ���� 1�� �����
	- �Էµ� ���� ¦���� 2�� ������
	- �Էµ� ���� Ȧ���� 3�� ���ϰ� 1�� ���Ѵ�
	- �� �ݺ�
	- ��, �۾��� 500�� �ݺ��ص� 1�� �ȵǸ� -1 ����
	- ���� : ������ ����. 1�� ��쿡 0 ��ȯ �ؾ� �Ѵ�.
*/

int solution_02282(int num) {
	int answer = 0;

	if (num == 1) return 0;

	for (int i = 1; i <= 500; i++)
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else if (num % 2 == 1)
		{
			num = num * 3 + 1;
		}
		
		if (num == 1)
		{
			return answer = i;
		}
	}

	return -1;
}