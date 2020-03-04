#include <string>
#include <vector>
#include <map>

using namespace std;

/*
	1부터 입력받은 숫자 n 사이에 있는 소수의 개수 반환
	소수는 1과 자기 자신으로만 나누어 진다.
	n은 2~100만 사이
*/

//배열을 bool 로 처리 해서 해봐
int solution_03041(int n) {
	int answer = 0;

	bool* arr = new bool[n + 1]; // 0 ~ n 까지

	//초기화
	for (int i = 2; i < n + 1; i++)
	{
		arr[i] = true;
	}

	//소수가 아닌 친구 걸러내기
	//3 이면 2 먼저 체크
	for (int i = 2; i * i <= n + 1; i++)
	{
		if (arr[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				arr[j] = false;
			}
		}
	}

	for (int i = 2; i < n + 1; i++)
	{
		if (arr[i]) answer++;
	}


	return answer;
}


//효율성 테스트가 좀 빡센데..
int solution_effectivenessError(int n) {
	int answer = 0;


	multimap<int, bool> list;
	//초기화
	for (int i = 2; i < n + 1; i++)
	{
		list.insert(multimap<int, bool>::value_type(i, true));
	}

	//3일 경우
	//iter = 2 : 
	multimap<int, bool>::iterator iter = list.begin();
	for (iter; iter != list.end(); ++iter)
	{
		if (iter->second)
		{
			int a = 0;
			//소수 판별
			for(int i = 1; i < iter->first; i++)
			{
				if (iter->first % i == 0)
				{
					a++;
					if (a > 1)
					{
						iter->second = false;
						
						break;
					}
				}
			}
		}
	}

	//true 인 개수 찾기
	iter = list.begin();
	for (iter; iter != list.end(); ++iter)
	{
		if (iter->second) answer++;
	}
	
	

	return answer;
}