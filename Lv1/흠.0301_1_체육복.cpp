#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	번호는 체격 순, 앞이나 뒷 번호에게만 체육복 대여 가능
	많은 학생이 체육수업
	학생 수 n
	lost : 도난 당한 학생 번호 배열
	reserve : 여벌의 체육복을 가져온 학생 번호 배열
	체육 수업 학생 최대값 리턴
	- 전체 학생 수 2~30
	- 도난 학생 수 1~n이고 중복 없다
	- 여벌 체육복 수 1~n 이고 중복 없다
	- 여벌 체육복 학생만 대여 가능
	- 여벌 체육복 학생도 도난 가능하고 이 땐 대여 불가
*/

int solution_03011(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	//로스트를 기준으로 인덱스를 돌리고, 없으면 리저브의 앞, 리저브, 리저브 뒤 검색 해서 이터를 넘겨야 할듯
	//최대 학생수가 30명 밖에 되지 않으므로 리스트 쓰지 말고 삽입 삭제가 있어도 벡터에서 작업하자
	
	//정렬이 안되어 있다
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	vector<int>::iterator lostIter = lost.begin();
	
	for (lostIter; lostIter != lost.end(); ++lostIter)
	{
		//리저브 있는지 서칭
		for (vector<int>::iterator reIter = reserve.begin(); reIter != reserve.end(); ++reIter)
		{
			if (reIter != reserve.begin())//맨 앞이 아니면 앞도 서칭
			{
				if (*lostIter - 1 <= *(--reIter) && *(--reIter) <= *lostIter + 1)
				{
					reserve.erase(--reIter);
					lost.erase(lostIter);
					--lostIter;
					break;
				}
				++reIter;
			}

			if (*lostIter - 1 <= *reIter && *reIter <= *lostIter + 1)//현재 이터와 비교
			{
				reserve.erase(reIter);
				lost.erase(lostIter);
				--lostIter;
				break;
			}
			
			if(reIter != reserve.end()--)//맨 뒤 아니면 뒤도 서칭
			{
				if (*lostIter - 1 <= *(++reIter) && *(++reIter) <= *lostIter + 1)
				{
					reserve.erase(++reIter);
					lost.erase(lostIter);
					--lostIter;
					break;
				}
				--reIter;
			}
		}
	}
	
	answer = n - lost.size();

	return answer;
}

int main_03011()
{
	solution(5, { 2, 4 }, { 1, 3, 5 });
	return 787;
}