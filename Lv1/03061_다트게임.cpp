#include <string>
#include <iostream>

using namespace std;

/*
	1. �� �� 
	2. ������ 0 ~ 10��
	3. SDT 123����
	4. *��Ÿ��(����, �� 2��) #������(���� -)
	5. ��Ÿ�� ó�� ����
	6. ��Ÿ�� ��ø ����
	7. ��Ÿ��, ������ ��ø����. -2��
	8. SDT �ϳ��� ����
	9. *�� #�� �������� �ϳ��� ���� or ����
*/

struct NumSet
{
	int a;
	int b;
};

NumSet calculator_03061(string tryNum, int exPoint)
{
	NumSet tempPoint;
	tempPoint.a = 0;
	tempPoint.b = exPoint;

	//���� �ֱ� 
	if (tryNum[0] == '1' && tryNum[1] == '0') tempPoint.a = 10;
	else tempPoint.a = atoi(&tryNum[0]);

	for (int i = 1; i < tryNum.size(); i++)
	{
		if (tryNum[i] == 'S' || tryNum[i] == 's') continue;
		else if (tryNum[i] == 'D' || tryNum[i] == 'd')
		{
			tempPoint.a *= tempPoint.a;
			continue;
		}
		else if (tryNum[i] == 'T' || tryNum[i] == 'T')
		{
			tempPoint.a *= (tempPoint.a * tempPoint.a);
			continue;
		}

		if (tryNum[i] == '*')
		{
			tempPoint.a *= 2;
			tempPoint.b *= 2;
		}
		else if (tryNum[i] == '#')
		{
			tempPoint.a *= -1;
		}
	}

	return tempPoint;
}

int solution_03061(string dartResult) {
	int answer = 0;

	int point[3] = { 0,0,0 }; //���� �ɹ� ����
	string tryNum[3];

	int size = dartResult.length();
	int idx[2];
	
	//ù Ʈ���� ����
	for (int i = 2; i < size; i++)
	{
		if ('0' <= dartResult[i] && dartResult[i] <= '9')
		{
			idx[0] = i;
			break;
		}
	}
	//�� ��° Ʈ���� ����
	for (int i = idx[0] + 2; i < size; i++)
	{
		if ('0' <= dartResult[i] && dartResult[i] <= '9')
		{
			idx[1] = i;
			break;
		}
	}

	//���ڿ� �߶� �������
	for (int i = 0; i < size; i++)
	{
		if (i < idx[0]) tryNum[0].push_back(dartResult[i]);
		else if (idx[0] <= i && i < idx[1]) tryNum[1].push_back(dartResult[i]);
		else tryNum[2].push_back(dartResult[i]);
	}

	int gabage = 0;
	NumSet numSet;
	numSet = calculator_03061(tryNum[0], gabage);
	point[0] = numSet.a;
	
	numSet = calculator_03061(tryNum[1], point[0]);
	point[1] = numSet.a;
	point[0] = numSet.b;
	
	numSet = calculator_03061(tryNum[2], point[1]);
	point[2] = numSet.a;
	point[1] = numSet.b;

	answer = point[0] + point[1] + point[2];

	return answer;
}


int main_03061()
{
	cout << solution_03061("1S2D*3T");

	return 787;
}