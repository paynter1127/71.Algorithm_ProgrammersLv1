#include <string>
#include <vector>

using namespace std;
/*
	���� ���� x �ϻ��� ���̷��� x�� �ڸ����� ������ x�� �������� �Ѵ�
	18�� �ڸ��� ���� 1 + 8 = 9
	19�� 9�� ������.
	�� x�� �ϻ��� ������ �Ǻ��϶�
*/

bool solution_02281(int x) {
	bool answer = true;

	int n = x;
	int Psum = 0;

	while (n > 0)
	{
		Psum += n % 10;
		n /= 10;
	}

	if (x % Psum != 0) answer = false;
	

	return answer;
}