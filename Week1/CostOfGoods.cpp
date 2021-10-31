#include <iostream>

using namespace std;

int main()
{
    float N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    
    if (A < B)
    {
        if (N > A && N < B)
        {
            N *= (100 - X)/100;
            // float res = N*(100-X)/100;
            // cout << res;
        }
        else if (N > A && N > B)
        {
            // float res = N*(100-Y)/100;
            // cout << res;
            N *= (100 - Y)/100;
        }
        // else 
        // {
        //     cout << N;
        // }
    
        cout << N;
    }
    
    return 0;
}
