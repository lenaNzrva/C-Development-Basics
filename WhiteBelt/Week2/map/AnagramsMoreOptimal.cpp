#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounters(const string& word)
{
    map<char, int> w;
    for (char c : word)
    {
        w[c]++;
    }

    return w;
}


int main()
{
    int N;
    string word1, word2;
    cin >> N;

    for (int i=0; i<N; ++i)
    {
        cin >> word1 >> word2;

        if(BuildCharCounters(word1) == BuildCharCounters(word2))
        {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}