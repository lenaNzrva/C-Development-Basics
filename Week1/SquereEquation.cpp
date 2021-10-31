#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float A, B, C; 
    
    cin >> A >> B >>C;
    
    if (A!=0)
    {
        
        float D = pow(B, 2) - 4*A*C;
        
        if (D > 0) 
        {
            float x_1 = (-B + sqrt(D))/(2*A);
            float x_2 = (-B - sqrt(D))/(2*A);
            
            cout << x_1 << " " << x_2;
        }
        
        else if (D == 0)
        {
            float x = -B/(2*A);
            
            cout << x;
        }
        
        else 
        {
            cout << "D less than 0";
        }
    }
    
    else if (A==0 && B!=0)
    {
        float x = C/B;
        
        cout << x;
    }
    
    else 
    {
        cout << "No solutions";
    }

    
    return 0;
}
