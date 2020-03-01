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
	- ���� ü���� �л��� �뿩 ����
	- ���� ü���� �л��� ���� �����ϰ� �� �� �뿩 �Ұ�
*/

int solution_03011(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	//�ν�Ʈ�� �������� �ε����� ������, ������ �������� ��, ������, ������ �� �˻� �ؼ� ���͸� �Ѱܾ� �ҵ�
	//�ִ� �л����� 30�� �ۿ� ���� �����Ƿ� ����Ʈ ���� ���� ���� ������ �־ ���Ϳ��� �۾�����
	
	//������ �ȵǾ� �ִ�
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	vector<int>::iterator lostIter = lost.begin();
	
	for (lostIter; lostIter != lost.end(); ++lostIter)
	{
		//������ �ִ��� ��Ī
		for (vector<int>::iterator reIter = reserve.begin(); reIter != reserve.end(); ++reIter)
		{
			if (reIter != reserve.begin())//�� ���� �ƴϸ� �յ� ��Ī
			{
				if (*lostIter - 1 <= *(--reIter) && *(--reIter) <= *lostIter + 1)
				{
					reserve.erase(--reIter);
					lost.erase(lostIter);
					--lostIter;
					break;
				}
				++reIter;
			}

			if (*lostIter - 1 <= *reIter && *reIter <= *lostIter + 1)//���� ���Ϳ� ��
			{
				reserve.erase(reIter);
				lost.erase(lostIter);
				--lostIter;
				break;
			}
			
			if(reIter != reserve.end()--)//�� �� �ƴϸ� �ڵ� ��Ī
			{
				if (*lostIter - 1 <= *(++reIter) && *(++reIter) <= *lostIter + 1)
				{
					reserve.erase(++reIter);
					lost.erase(lostIter);
					--lostIter;
					break;
				}
				--reIter;
			}
		}
	}
	
	answer = n - lost.size();

	return answer;
}

int main_03011()
{
	solution(5, { 2, 4 }, { 1, 3, 5 });
	return 787;
}