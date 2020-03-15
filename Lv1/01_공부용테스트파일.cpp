#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/* < ������ �����ε� >
	- ���� ��� ���� ������ ������
	- �Լ���ȯ�� operator ������ (������);
*/
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}//������

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
	} //���� ����
	const Point operator++(int)
	{
		const Point refobj(xpos, ypos); //���纻 ����
		xpos++;
		ypos++;
		return refobj; //��ȯ���� �� ���ο����� ����ϰ� ����� ���纻 ��ȯ const��
	} //��������
	
	
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


Point operator+(const Point &pos1, const Point &pos2) //������ point ���� ������ �ʵ��� constŰ���带 ���̴°� �� �߿��ϴ�.
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
} //���� ����

const Point operator--(Point& ref, int)
{
	const Point refobj(ref); //���纻 ����
	ref.xpos--;
	ref.ypos--;
	return refobj; //��ȯ���� �� ���ο����� ����ϰ� ����� ���纻 ��ȯ

}

Point& operator~(Point &pos)
{
	int temp = pos.xpos;
	pos.xpos = pos.ypos;
	pos.ypos = temp;
	return pos;
}

//��ȯ��Ģ
Point operator*(int times, Point& ref) //int��*point��
{
	Point pos(ref.xpos*times, ref.ypos*times);
	return pos;
}
Point operator*(Point& ref, int times) //point��*int��
{
	Point pos(ref.xpos*times, ref.ypos*times);
	return pos;
}

//�����Լ��� cout<<pos �����ϰ� ����� os�� coutŬ��
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ',' << pos.ypos << ']' << endl;
	return os;
}
istream& operator>>(istream& is, Point& pos) //���� ����־�� �ϱ⶧���� const�� ������
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
	//	cout << "�����ϴ�" << endl;
	//}
	//
	//pos4 = pos1 + pos2;
	//
	//if (pos3 != pos4)
	//{
	//	cout << "���� �Ƚ��ϴ�." << endl;
	//}
	//pos4 = -pos4;
	//pos4.ShowPosition();
	//pos4 = -pos4;
	//pos4.ShowPosition();
	//pos4 = ~pos4;
	//pos4.ShowPosition();
	//cout << "---------------------------------" << endl;
	//(++(++pos1)).ShowPosition();
	//cout << "������" << endl;
	//pos1.ShowPosition();
	//
	//pos1++.ShowPosition(); //���������� Pointer&�����Ѱ� �ƴϱ� ������
	//pos1.ShowPosition();
	//Point cpy = pos1 * 3;
	//cpy.ShowPosition();
	//
	//cpy = pos1 * 3;
	//cpy.ShowPosition();
	//cin >> cpy;
	//cout << cpy;
	//cpy = pos1;
	//cpy.ShowPosition(); //����Ʈ ���Կ����� ����&ȣ��


	return 787;
}



/* < STL generate ��� ���� > */
struct User
{
	int UID;
	int RaceType;
	int Sex;
	int Money;
};

struct SetUserInfo
{
	SetUserInfo() { UserCount = 0; } //�����ڳ�...

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
