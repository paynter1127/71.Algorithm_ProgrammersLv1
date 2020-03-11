#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

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

int main()
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
