#include <iostream>

using namespace std;

int Factorial(int x)
{
    int fact = 1;
    if (x > 0)
    {
        for (int i = 2; i <= x; ++i)
        {
            fact *= i;
        }
    }
    else if (x < 0)
    {
        fact *= -1;
    }
    
    return fact;
}


int main()
{
    int x; 
    cin >> x;
    
    cout << Factorial(x);

    return 0;
}