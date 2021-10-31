#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A, B;
    
    cin >> A >> B;
    
    if (A > B) 
    {
        if (A%B == 0)
        {
            cout << B;
        }
        
        else 
        {
            int C = A%B;
            
            while(C != 0)
            {
                A = B;
                B = C;
                C = A%B;
            }
            
            cout << B;
            
        }
    }
        
    if (B > A) 
    {
        if (B%A == 0)
        {
            cout << A;
        }
        
        else 
        {
            int C = B%A;
            
            while(C != 0)
            {
                B = A;
                A = C;
                C = B%A;
            }
            
            cout << A;
            
        }
    }
    
    else
    {
        cout << A;
    }


    return 0;
}