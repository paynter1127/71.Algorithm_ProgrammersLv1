#include <string>
#include <vector>

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

int 흠solution_02292(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	//학생 수 주는구나, 총 학생 n명
	int size = lost.size();
	int cannot = size;

	//로스트에서 리저브 받아 불가능 수 찾기
	for (int i = 0; i < size; i++)
	{
		
	}
	

	return answer;
}