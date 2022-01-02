#include <iostream>
#include <map>
#include <string>

using namespace std;

void BuildCharCounters(const string& word1, const string& word2)
{
    map<char, int> w1, w2;

    for (char c : word1)
    {
        w1[c]++;
    }

    for (char c : word2)
    {
        w2[c]++;
    }

    if (w1 == w2)
    {
        cout << "YES" << endl;
    }else
    {
        cout << "NO" << endl;
    }

}

int main()
{
    int N;
    string word1, word2;
    cin >> N;

    for (int i=0; i<N; ++i)
    {
        cin >> word1 >> word2;

        BuildCharCounters(word1, word2);
    }

    return 0;
}