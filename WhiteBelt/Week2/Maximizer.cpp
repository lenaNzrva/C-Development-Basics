#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second)
{
    if (first > second)
    {
        second = first;
    }
}

int main()
{

    int a = 2;
    int b = 4;
    UpdateIfGreater(a, b);

    // cout << b;
    return 0;
}