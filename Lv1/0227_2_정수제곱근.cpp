#include <string>
#include <vector>
#include <math.h>

using namespace std;

/*
	���� ���� n
	n�� �������ΰ� �Ǻ�
	n�� ���� ���� x�� �����̸� 
	x+1�� ����
	�ƴϸ� -1 ����
*/

long long solution_02271(long long n) {
	long long answer = 0;

	float size = sqrt(n);

	for (int i = 0; i <= size; i++)
	{
		if (i == size)
		{
			answer = pow(i + 1, 2);
		}
		else
		{
			answer = -1;
		}
	}

	return answer;
}

int main_02271()
{

	return 777;
}

