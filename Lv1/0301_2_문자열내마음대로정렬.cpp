#include <string>
#include <vector>
#include <map>

using namespace std;

/*
	���ڿ� ����Ʈ strings�� ���� n�� �־����� ��,
	�� ���ڿ��� n��° ���� �������� �������� ����
	- stirngs ���� 1~50
	- strings ���Ҵ� �ҹ��� ���ĺ�
	- strings�� ���Ҵ� ���� 1~100 ���� ���ڿ�
	- ��� strings�� ���� ���̴� n���� ũ��
	- ���� ���ڿ��� �����̸� ���������� �ռ� ���ڿ��� �տ� ��ġ
*/


vector<string> solution_03012(vector<string> strings, int n) {
	vector<string> answer;

	//�ʿ� �ι�° Ű�� �־ �ڵ� ���� ��Ű��
	multimap<char, string> strMap;

	for (int i = 0; i < strings.size(); i++)
	{
		strMap.insert(multimap<char, string>::value_type(strings[i][n], strings[i]));
	}

	//�ι�° Ű�� ī��Ʈ�� ������ �ش� ������ ��ü�� Ű�� �־ ���Ľ�Ű�� ���ͷ� Ǫ����
	multimap<char, string>::iterator iter = strMap.begin();
	for (iter; iter != strMap.end(); ++iter)
	{
		int size = strMap.count(iter->first);
		if (size == 1)
		{
			answer.push_back(iter->second);
		}
		else//Ű�� �� �� �̻��� �ֵ� ����
		{
			multimap<string, bool> tempMap;
			for (int i = 0; i < size; i++)//��ü Ű ���� ���� ��Ű��
			{
				tempMap.insert(multimap<string, bool>::value_type(iter->second, true));
				++iter;
			}
			
			//���ĵ� Ű ������ �ֱ�
			for (multimap<string, bool>::iterator tempIter = tempMap.begin(); tempIter != tempMap.end(); ++tempIter)
			{
				answer.push_back(tempIter->first);
			}
			tempMap.clear();
			--iter;
		}
	}
	


	return answer;
}



//�����ڰ� �ǵ��� Ǯ�� ��
/*
bool compare(string a, string b, int i) 
{
	return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
	int i = n;
	sort(strings.begin(), strings.end(), compare);
	return strings;
}
*/