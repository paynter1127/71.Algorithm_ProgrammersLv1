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
	- 여벌 체육복 학생만 대여 가능 - 자기꺼 도난 당하면 빌려 줄 수 없다는 말***
	- 여벌 체육복 학생도 도난 가능하고 이 땐 대여 불가
*/

int solution_03031(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	
	int firstSize = reserve.size();

	int Lsize = lost.size();
	//여벌 있는 학생 중 자기꺼 도난 당했는지 체크하고 삭제 할 것
	for (int i = 0; i < Lsize; i++)
	{
		for (vector<int>::iterator iterR = reserve.begin(); iterR != reserve.end(); ++iterR)
		{
			if (lost[i] == *iterR)
			{
				//로스트도, 리저브도 삭제 해야 한다.
				lost.erase(lost.begin() + i);
				reserve.erase(iterR);
				Lsize = lost.size();
				i--;
				break;
			}
		}
	}

	Lsize = lost.size();
	for (int i = 0; i < Lsize; i++)
	{
		int size = reserve.size();
		for (int j = 0; j < size; j++)
		{
			//1보다 크면 여분 학생 찾기 정지
			if (reserve[j] > lost[i] + 1) break;
			else //1보다 크지 않으면 여분 학생 찾기
			{
				if (lost[i] == reserve[j] + 1) //뒤로 빌려 주기
				{
					lost.erase(lost.begin() + i);
					Lsize = lost.size();
					i--;
					reserve.erase(reserve.begin() + j);//j 인덱스 삭제
					break;//리저브 찾기 for 문 나가기
				}
				else if (lost[i] == reserve[j]) //같은 번호
				{
					lost.erase(lost.begin() + i);
					Lsize = lost.size();
					i--;
					reserve.erase(reserve.begin() + j);//j 인덱스 삭제
					break;//리저브 찾기 for 문 나가기
				}
				else if (lost[i] == reserve[j] - 1) //앞 번호
				{
					lost.erase(lost.begin() + i);
					Lsize = lost.size();
					i--;
					reserve.erase(reserve.begin() + j);//j 인덱스 삭제
					break;//리저브 찾기 for 문 나가기
				}
			}
		}
	}

	int lastSize = reserve.size(); //빌려 주고 난 후
	
	//빌려 준 수 
	//int give = firstSize - lastSize;
	
	//수업 들을 수 있는 학생 수는
	answer = n - lost.size();

	return answer;
}

int main_03031()
{
	//printf("%d", solution_03011(3, { 1, 3 }, { 1, 2, 3 }));
	
	return 787;
}