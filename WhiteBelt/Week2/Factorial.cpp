#include <iostream>
using namespace std;

int Factorial(int a)
{
	if (a <= 0)
	{
		return 1;
	}
	else if (a != 1)
	{
		return Factorial(a-1)*a;
	}else
	{
		return 1;
	}

}


int main() {
	int a;
	cin >> a;

	a = Factorial(a);

	cout << a;

	return 0;
}
