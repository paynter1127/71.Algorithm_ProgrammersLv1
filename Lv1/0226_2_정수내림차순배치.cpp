#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution_02262(long long n) {
	long long answer = 0;

	string s;
	s = to_string(n);
	
	//소팅 int 나 char 둘다 같은 결과를 반환하는데, char 이 논리적으로 맞을듯
	//sort(s.begin(), s.end(), greater<int>());
	sort(s.begin(), s.end(), greater<char>());

	//엔서에 넣기
	answer = stoll(s);
	
	


	return answer;
}

int main_02262()
{
	

	return 777;
}