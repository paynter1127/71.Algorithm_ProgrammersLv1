#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <deque>

using namespace std;

/*
	숫자로 암호화 지도 해독하기
	1. 한변의 길이가 n인 정 사각형 배열, 각 칸은 공백과 벽"#"으로 구성
	2. 전체 지도는 두 장 지도 겹쳐 얻는다. 하나라도 벽이면 벽 처리
	3. 지도1과 지도2는 정부 배열로 암호화
	4. 배열은 가로줄 벽을 1, 공백을 0으로 표시한 이진 배열
	- n 은 1~16
*/

vector<string> solution_02296(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	int size = n;

	for (int i = 0; i < size; i++)
	{
		deque<string> result;
		int num1 = arr1[i];
		int num2 = arr2[i];
		string pushBack = "";

		for (int j = 0; j < size; j++)
		{
			if (bitset<16>(num1)[j] == 1 || bitset<16>(num2)[j] == 1)
			{
				result.push_front("#");
			}
			else result.push_front(" ");

			//pushBack.push_back(' ');
		}

		for (int j = 0; j < size; j++)
		{
			pushBack.push_back(result[j][0]);
		}

		answer.push_back(pushBack);
	}


	return answer;
}

int main_02296()
{
	int num = 20;
	
	//2진 변환 테스트
	cout << bitset<5>(num) << endl;
	cout << bitset<5>(num)[4] << endl;
	cout << bitset<5>(num)[3] << endl;
	cout << bitset<5>(num)[2] << endl;
	cout << bitset<5>(num)[1] << endl;
	cout << bitset<5>(num)[0] << endl;

	

	return 787;
}