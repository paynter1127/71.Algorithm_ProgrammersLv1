#include <string>
#include <vector>
#include <map>

using namespace std;

/*
	문자열 리스트 strings와 정수 n이 주어졌을 때,
	각 문자열을 n번째 글자 기준으로 오름차순 정렬
	- stirngs 길이 1~50
	- strings 원소는 소문자 알파벳
	- strings의 원소는 길이 1~100 이하 문자열
	- 모든 strings의 원소 길이는 n보다 크다
	- 같은 문자열이 여럿이면 사전순으로 앞선 문자열이 앞에 위치
*/


vector<string> solution_03012(vector<string> strings, int n) {
	vector<string> answer;

	//맵에 두번째 키를 넣어서 자동 정렬 시키기
	multimap<char, string> strMap;

	for (int i = 0; i < strings.size(); i++)
	{
		strMap.insert(multimap<char, string>::value_type(strings[i][n], strings[i]));
	}

	//두번째 키의 카운트가 많으면 해당 데이터 전체를 키로 넣어서 정렬시키고 벡터로 푸쉬백
	multimap<char, string>::iterator iter = strMap.begin();
	for (iter; iter != strMap.end(); ++iter)
	{
		int size = strMap.count(iter->first);
		if (size == 1)
		{
			answer.push_back(iter->second);
		}
		else//키가 두 개 이상인 애들 검출
		{
			multimap<string, bool> tempMap;
			for (int i = 0; i < size; i++)//전체 키 사전 정렬 시키기
			{
				tempMap.insert(multimap<string, bool>::value_type(iter->second, true));
				++iter;
			}
			
			//정렬된 키 엔서에 넣기
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



//출제자가 의도한 풀이 법
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