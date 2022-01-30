#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool IsPalindrom(string a)
{
    if (a == "")
    {
        return true;
    }

	string copy = a;
	reverse(begin(copy), end(copy));

	return copy == a;

}

int main() {
	string a;
	cin >> a;
    // a = "";

	bool result = IsPalindrom(a);

	cout << result;

	return 0;
}