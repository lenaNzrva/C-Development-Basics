#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int entry = -2;
    
    for (int i=0; i < str.size(); i++)
    {
        
        if (str[i] == 'f')
        {
            entry ++;
            
            if (entry == 0)
            {
                cout << i;
                return 0;
                // break; 
            }
        }
        
    }
    
    cout << entry;
    
    
    // if (entry == 1)
    // {
    //     cout << -1;
    // }
    
    // if (entry == 0)
    // {
    //     cout << -2;    
    // }
    
    
    return 0;
}