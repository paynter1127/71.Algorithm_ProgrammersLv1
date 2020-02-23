#include <string>
#include <iostream>
using namespace std;

/*
	스타 로 가로 n 세로 m인 직사각형 출력하라
*/


int main()
{
	std::cout << "Hello World!\n";

	int a;
	int b;
	cin >> a >> b;
	cout << a + b << endl;

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	string s;

	for (int i = 0; i < a; i++)
	{
		s.push_back('*');
	}

	for (int i = 0; i < b; i++)
	{
		cout << s << endl;
	}
	



	return 777;
}