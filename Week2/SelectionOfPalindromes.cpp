#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength)
{
    vector<string> result; 
    for (string w : words)
    {
        string copy = w;
        reverse(begin(copy), end(copy));

        if(w == copy && w.size() >= minLength)
        {
            result.push_back(w);
        }
    }

    return result;
}

int main() {
    vector<string> words = {"weew", "bro", "code"};
    int minLength = 4;

    vector<string> res = PalindromFilter(words, minLength);

    // for (string r : res)
    // {
    //     cout << r << endl;
    // }

    return 0;
}