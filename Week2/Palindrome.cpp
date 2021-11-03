#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string a)
{
    int n = a.length();
    bool same;
    
    if (n == 1)
    {
        same = 1;
    }
    
    else
    {
        for (int i = 0; i <= (n / 2) - 1; i++)
        {
            same = a[i] == a[n-i-1];
            
            if (same == 0)
            {
                break;
            } 
        }
    }
    
    return same;
    
}

int main()
{
    string str;
    cin >> str;
    
    cout << IsPalindrom(str);

    return 0;
}
