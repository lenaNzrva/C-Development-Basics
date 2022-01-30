#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    
    if (B != 0)
    {
        int C = A/B;
        cout << C;
    }
    else
    {
        cout << "Impossible";
    }

    return 0;
}