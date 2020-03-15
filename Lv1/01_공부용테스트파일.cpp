#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/* < 연산자 오버로딩 >
	- 연산 대상에 대한 연산자 재정의
	- 함수반환형 operator 연산자 (연산대상);
*/
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}//생성자

	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
	void operator+=(const Point pos1)    //pos1+=pos2;   -->  pos1=pos1+pos2
	{
		xpos += pos1.xpos;
		ypos += pos1.ypos;
	}
	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator-(const Point &pos1, const Point &pos2);

	/*
	void operator-=(const Point &pos1)
	{
		xpos -= pos1.xpos;
		ypos -= pos1.ypos;
	}

	Point& operator-()
	{
		xpos = -xpos;
		ypos = -ypos;
		return *this;
	}
	Point& operator++()
	{
		xpos++;
		ypos++;
		return *this;
	} //전위 증가
	const Point operator++(int)
	{
		const Point refobj(xpos, ypos); //복사본 생성
		xpos++;
		ypos++;
		return refobj; //반환받을 한 라인에서만 사용하고 사라질 복사본 반환 const로
	} //후위증가
	
	
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
	friend Point& operator~(Point &pos);
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
	friend Point operator*(int times, Point& ref);
	friend Point operator*(Point& ref, int times);
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend istream& operator>>(istream& is, Point& pos);
	*/
};


Point operator+(const Point &pos1, const Point &pos2) //기존의 point 값이 변하지 않도록 const키워드를 붙이는것 이 중요하다.
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

/*


bool operator==(const Point &pos1, const Point &pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(const Point &pos1, const Point &pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Point& operator--(Point& ref)
{
	ref.xpos--;
	ref.ypos--;
	return ref;
} //전위 증가

const Point operator--(Point& ref, int)
{
	const Point refobj(ref); //복사본 생성
	ref.xpos--;
	ref.ypos--;
	return refobj; //반환받을 한 라인에서만 사용하고 사라질 복사본 반환

}

Point& operator~(Point &pos)
{
	int temp = pos.xpos;
	pos.xpos = pos.ypos;
	pos.ypos = temp;
	return pos;
}

//교환법칙
Point operator*(int times, Point& ref) //int형*point형
{
	Point pos(ref.xpos*times, ref.ypos*times);
	return pos;
}
Point operator*(Point& ref, int times) //point형*int형
{
	Point pos(ref.xpos*times, ref.ypos*times);
	return pos;
}

//전역함수로 cout<<pos 가능하게 만들기 os가 cout클래
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ',' << pos.ypos << ']' << endl;
	return os;
}
istream& operator>>(istream& is, Point& pos) //값을 집어넣어야 하기때문에 const를 뺴야함
{
	is >> pos.xpos >> pos.ypos;
	return is;
}
*/


int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos3 = pos2 - pos1;

	pos3.ShowPosition();
	pos3 += pos1;
	pos3.ShowPosition();
	//pos3 -= pos2;
	//pos3.ShowPosition();
	//
	//Point pos4(1, 1);
	//if (pos3 == pos4)
	//{
	//	cout << "같습니다" << endl;
	//}
	//
	//pos4 = pos1 + pos2;
	//
	//if (pos3 != pos4)
	//{
	//	cout << "같지 안습니다." << endl;
	//}
	//pos4 = -pos4;
	//pos4.ShowPosition();
	//pos4 = -pos4;
	//pos4.ShowPosition();
	//pos4 = ~pos4;
	//pos4.ShowPosition();
	//cout << "---------------------------------" << endl;
	//(++(++pos1)).ShowPosition();
	//cout << "전위끝" << endl;
	//pos1.ShowPosition();
	//
	//pos1++.ShowPosition(); //후위증가는 Pointer&전달한게 아니기 때문에
	//pos1.ShowPosition();
	//Point cpy = pos1 * 3;
	//cpy.ShowPosition();
	//
	//cpy = pos1 * 3;
	//cpy.ShowPosition();
	//cin >> cpy;
	//cout << cpy;
	//cpy = pos1;
	//cpy.ShowPosition(); //디폴트 대입연산자 생성&호출


	return 787;
}



/* < STL generate 사용 연습 > */
struct User
{
	int UID;
	int RaceType;
	int Sex;
	int Money;
};

struct SetUserInfo
{
	SetUserInfo() { UserCount = 0; } //생성자네...

	User operator() ()
	{
		User user;
		++UserCount;

		user.UID = UserCount;
		user.Money = 2000;

		if (0 == UserCount % 2)
		{
			user.RaceType = 1;
			user.Sex = 1;
			user.Money += 1000;
		}
		else
		{
			user.RaceType = 0;
			user.Sex = 0;
		}
		return user;
	}
	int UserCount;
};

int _main()
{
	vector<User> Users(5);
	generate(Users.begin(), Users.end(), SetUserInfo());

	char szUserInfo[256] = { 0, };
	vector<User>::iterator IterUser;

	for (IterUser = Users.begin(); IterUser != Users.end(); ++IterUser)
	{
		sprintf_s(szUserInfo, "UID %d, RaceType : %d, Sex : %d, Money : %d",
			IterUser->UID, IterUser->RaceType, IterUser->Sex, IterUser->Money);
		cout << szUserInfo << endl;
	}
	
	return 0;
}
