#include <iostream>
using namespace std;

int main() {
	float N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;

	float result = N;

	if (N > A)
	{
		result = N*(1 - X/100);
	}
	if (N > B)
	{
		result = N*(1 - Y/100);
	}

	cout << result;

	return 0;
}
