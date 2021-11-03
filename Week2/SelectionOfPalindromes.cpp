#include <iostream>
#include <string>
#include <vector>

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

vector<string> PalindromFilter(vector<string> words, int minLength)
{
    
    vector<string> res;
    for (auto i: words)
    {
        if (i.length() >= minLength)
        {
            if ((IsPalindrom(i)) == 1)
                res.push_back(i);
        }
    }
    return res;
}
 
int main()
{
    // vector<string> words = {"abacaba", "aba"};
    // int minLength = 5;
    
    // vector<string> words = {"abacaba", "aba"};
    // int minLength = 2;
    
    vector<string> words = {"weew", "bro", "code"};
    int minLength = 4;
    
    vector<string> result_vector = PalindromFilter(words, minLength);
    
    for (auto i: result_vector)
    {
        cout << i << " ";
    }

    return 0;
}