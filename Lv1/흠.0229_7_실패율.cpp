#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

/*
	실패율 : 스테이지 && 클리어 못한 플레이어 수 / 스테이지 도달 플레이어 수
	- 전체 스테이지 개수 N
	- 멈춰있는 스테이지 번호 배열 stages (사이즈가 사람 도전한 사람 수)
	실패율 높은 스테이지부터 내림차순으로 스테이지 번호가 담긴 배열을 리턴하라. (1 부터 내림차순)
	- 스테이지 개수 N 은 1~500 자연수
	- stages 길이 1~200,200 이하(참여 유저 수)
	- stages 에서는 1~ N+1이하 자연수가 담겨 있다.
		. 각 자연수는 사용자가 도전중 스테이지
		. N+1은 마지막 스테이지(N스테이지) 까지 클리어한 사용자
	- 실패율이 같으면 작은 번호 스테이지가 먼저 오게
	- 스테이지 도달 유저가 없으면 실패율은 0

	=> 핵심1 : 실패율 순으로 정렬(실패율은 내림차순)
	=> 핵심2 : 실패율이 같으면 스테이지 순으로 정렬(스테이지는 오름 차순) 
		홀리 쉣....
		이거 행렬로 되나? 흠...
*/


//예전 풀던 것 세이브
vector<int> solution_02297(int N, vector<int> stages) {
	vector<int> answer;

	//사람 수
	int manSize = stages.size();

	//벡터를 셋으로 변경
	multiset<int> stage;
	for (vector<int>::iterator iter = stages.begin(); iter < stages.end(); ++iter)
	{
		stage.insert(*iter);
	}

	//실패율을 담을 맵 선언
	multimap<float, int> failRate; //실패율, 스테이지

	int pNum = 0;
	int no = 0;
	
	//스테이지 별 실패율 담기
	for (int i = N; i > 0; i--)
	{
		//마지막 스테이지 예외처리
		if (i == N)
		{
			pNum += stage.count(i + 1);//다 푼놈
			no = stage.count(i); //못 푼놈
			
			if (pNum == 0 && no == 0) //도달하지도, 풀지도 못한 경우
			{
				failRate.insert(multimap<float, int>::value_type(0, i));
			}
			else//다 푼놈이 있건 없건 도달은 한 경우
			{
				pNum += no;
				failRate.insert(multimap<float, int>::value_type(no / pNum, i)); //마지막 스테이지 실패율 넣기
			}
			
		}
		else //마지막 스테이지가 아닌 경우
		{
			//pNum += stage.count(i); //여전히 0일 수 있다.
			no = stage.count(i); //못 푼놈
			pNum += no;

			if (pNum == 0)//도달도, 풀지도 못한 경우
			{
				failRate.insert(multimap<float, int>::value_type(0, i));
			}
			else
			{
				failRate.insert(multimap<float, int>::value_type(((float)no) / ((float)pNum), i));
			}
		}
	}
	
	
	//-실패율이 같으면 작은 번호 스테이지가 먼저 오게
	multimap<float, int>::reverse_iterator rIter = failRate.rbegin();
	multimap<float, int>::reverse_iterator rIterFront = failRate.rbegin();
	++rIterFront;
	for (rIter; rIter != failRate.rend(); )
	{
		if (rIter->first == rIterFront->first) //실패율이 같으면
		{

		}
		answer.push_back(rIter->second);
	}

	return answer;
}

int main_02297()
{
	printf("hello");

	{
		//solution_02297(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
		//solution_02297(5, { 2, 1, 2, 6, 2, 4, 3, 3 });

		cout << endl << sizeof(int) << endl;
		cout << sizeof(long) << endl;
	}

	printf("멀티맵 정렬 테스트 \n");
	
	
	unordered_map<int, float> map;
	map.insert(unordered_map<int, float>::value_type(1, 1.0f / 8.0f));
	map.insert(unordered_map<int, float>::value_type(3, 2.0f / 4.0f));
	map.insert(unordered_map<int, float>::value_type(2, 3.0f / 7.0f));
	map.insert(unordered_map<int, float>::value_type(5, 0.0f / 1.0f));
	map.insert(unordered_map<int, float>::value_type(4, 1.0f / 2.0f));

	for (unordered_map<int, float>::iterator iter = map.begin(); iter != map.end(); ++iter)
	{
		cout << iter->first << " / " << iter->second << endl;
	}

	//결론 : 맵 과 같은 키와 벨류를 가지는 STL 은 sort함수로 정렬 할 수 없다. 
	// 직접 정렬 처리 해야 한다. 

	//sort(map.begin()->first, map.end()->first);
	//for (unordered_map<int, float>::iterator iter = map.begin(); iter != map.end(); ++iter)
	//{
	//	cout << iter->first << " / " << iter->second << endl;
	//}

	return 787;
}