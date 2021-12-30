#include <iostream>
#include <string>

using namespace std;

int main() {
	string x, y, z;

	cin >> x >> y >> z;

	string result = x;

	if (result > y)
	{
		result = y;
	}

	if (result > z)
	{
		result = z;
	}

	cout << result;


//	bool check_;
//	int check_x = 0;
//	int check_y = 0;
//	int check_z = 0;
//
//	for (auto i : x)
//	{
//		check_ = isupper(i);
//		check_x += check_;
//	}
//
//	for (auto i : y)
//	{
//		check_ = isupper(i);
//		check_y += check_;
//	}
//
//	for (auto i : z)
//	{
//		check_ = isupper(i);
//		check_z += check_;
//	}
//
//	if (check_x == 0 && check_y == 0 && check_z == 0)
//	{


//	}


	return 0;
}
