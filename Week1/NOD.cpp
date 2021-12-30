#include <iostream>
using namespace std;

int main() {

	int A, B;
	cin >> A >> B;

	if (A > B)
	{
		int C = A%B;
		while (C != 0)
		{
			A = B;
			B = C;
			C = A%B;
		}

		cout << B;
	}else if (A < B)
	{
		int C = B%A;
		while (C != 0)
		{
			B = A;
			A = C;
			C = B%A;
		}
		cout << A;
	}else
	{
		cout << A;
	}


	return 0;
}
