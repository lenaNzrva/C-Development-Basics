#include <iostream>
#include <set>
#include <vector>

using namespace std;

void ADD(vector<set<string>>& V)
{
    string word1, word2;
    cin >> word1 >> word2;

    V.push_back({word1, word2});
}

int COUNT(const vector<set<string>>& V)
{
    string word;
    cin >> word;
    set<string> test;

    for (auto v : V)
    {
        if (v.count(word) == 1)
        {
            for (auto str : v)
            {
                test.insert(str);
            }
        } 
    }
    return test.size();
}

string CHECK(const vector<set<string>>& V)
{
    string word1, word2;
    cin >> word1 >> word2;

    for (auto v : V)
    {
        if (v.count(word1) == 1 && v.count(word2) == 1)
        {
            return "YES";
        }
    }

    return "NO";
}

int main()
{
    int Q;
    string mode;
    vector<set<string>> V; 

    cin >> Q;
    for (int i=0; i<Q; ++i)
    {
        cin >> mode;

        if (mode == "ADD")
        {
            ADD(V);
        }

        else if (mode == "COUNT")
        {
            int result = COUNT(V);
            if (result != 0)
            {
                cout << result - 1 << endl;
            } 
            else
            {
                cout << 0 << endl;
            }
        }

        else
        {
            string result = CHECK(V);
            cout << result << endl;
        }

    }

    return 0;
}