#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    
    if (A <= B && A >= 1 && B <= 30000)
    {
        
        for (int i = A; i <= B; i++)
        {
            if (i % 2 == 0)
            {
                cout << i << " ";
            }
            // cout << i << " ";
        }
    }
    
    return 0;
}