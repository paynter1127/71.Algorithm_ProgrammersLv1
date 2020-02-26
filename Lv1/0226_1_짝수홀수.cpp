#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
	정수 num이 짝수면 Even,
	홀수면 Odd 반환
*/

string solution_02261(int num) {
	string answer = "";
	
	
	if (num % 2 == 1 || num % 2 == -1)
	{
		answer = "Odd";
	}
	else if (num % 2 == 0)
	{
		answer = "Even";
	}


	return answer;
}


int main_02261()
{

	


	return 777;
}