#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

/*
	�Ѹ� �� ���� ���ѳ� ���� ���Ѷ�
	participant ������ ���� ����
	completion ���� ����
	- ������ 100,000�� ����
	- ������ �̸��� 20�� ���� ���ĺ� �ҹ���
	- ���� ���� �ִ�.
*/

string solution_02284(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	multiset<string> p;
	multiset<string> c;

	p.insert(participant.begin(), participant.end());
	c.insert(completion.begin(), completion.end());
	
	multiset<string>::iterator pIter = p.begin();
	multiset<string>::iterator cIter = c.begin();
	
	while (true)
	{
		if (*pIter != *cIter)
		{
			answer = *pIter;
			break;
		}
		++pIter;
		++cIter;
		if (pIter == --p.end())
		{
			answer = *pIter;
			break;
		}
	}


	return answer;
}

int main_02284()
{
	

	vector<string> pp = { "leo", "kiki", "eden" };
	vector<string> qq = { "kiki", "eden" };
	


	//for (vector<string>::iterator iter = pp.begin(); iter != pp.end(); ++iter)
	//{
	//	cout << *iter << endl;
	//}

	/*
	multiset<string> p;
	p.insert(pp.begin(), pp.end());

	

	multiset<string>::iterator iter = p.begin();
	++iter;
	
	cout << "��? " << p.count(*iter) << endl;

	cout << endl;

	if (iter != p.end())
	{
	}

	for (multiset<string>::iterator iter = p.begin(); iter != p.end(); ++iter)
	{
		
		cout << *iter << endl;
	}
	*/
	


	return 787;
}