#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution_02262(long long n) {
	long long answer = 0;

	string s;
	s = to_string(n);
	
	//���� int �� char �Ѵ� ���� ����� ��ȯ�ϴµ�, char �� �������� ������
	//sort(s.begin(), s.end(), greater<int>());
	sort(s.begin(), s.end(), greater<char>());

	//������ �ֱ�
	answer = stoll(s);
	
	


	return answer;
}

int main_02262()
{
	

	return 777;
}