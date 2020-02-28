#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	수포자 3인 모두 찍기
	- 수포자1 : 1,2,3,4,5,// 1,2,3,4,5,...
	- 수포자2 : 2,1,2,3,2,4,2,5,//  2,1,2,....
	- 수포자3 : 3,3,1,1,2,2,4,4,5,5,  //3,3,....
	- answers 는 정답
	- 가장 많이 맞은 사람이 누구인가? 
	- 최대 1만 문제
	- 동일 점수면 수포자들을 오름차순으로 정렬
*/

vector<int> solution_02283(vector<int> answers) {
	vector<int> answer;

	//세놈 답안
	int cNum[] = { 0, 0, 0 };

	int size = answers.size();

	//찍기 루틴
	int routine1[] = { 1,2,3,4,5 }; //5
	int routine2[] = { 2,1,2,3,2,4,2,5 }; //8
	int routine3[] = { 3,3,1,1,2,2,4,4,5,5 }; //10

	//찍은 답안 저장용 벡터
	vector<int> student1;
	vector<int> student2;
	vector<int> student3;

	//1번놈 답안
	while (student1.size() < size)
	{
		for (int i = 0; i < 5; i++)
		{
			student1.push_back(routine1[i]);
		}
	}
	//2번놈 답안
	while (student2.size() < size)
	{
		for (int i = 0; i < 8; i++)
		{
			student2.push_back(routine2[i]);
		}
	}
	//3번놈 답안
	while (student3.size() < size)
	{
		for (int i = 0; i < 10; i++)
		{
			student3.push_back(routine3[i]);
		}
	}

	//답안 비교하기
	for (int i = 0; i < size; i++)
	{
		//1번놈 먼저 처리
		if (student1[i] == answers[i])
		{
			cNum[0]++;
		}
		if (student2[i] == answers[i])
		{
			cNum[1]++;
		}
		if (student3[i] == answers[i])
		{
			cNum[2]++;
		}
	}

	//많이 맞은 놈 찾기
	vector<int> temp;
	temp.push_back(cNum[0]);
	temp.push_back(cNum[1]);
	temp.push_back(cNum[2]);
	sort(temp.begin(), temp.end(), greater<int>()); //내림차순
	
	for (int i = 0; i < 3; i++)
	{
		if (temp[0] == cNum[i])
		{
			answer.push_back(i + 1);
			printf("%d\n", answer[i]);
		}
	}

	

	return answer;
}

int main_02283()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);


	return 787;
}