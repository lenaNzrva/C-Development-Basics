#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

void ADD(map<string, set<string>>& M)
{
    string W1, W2;
    cin >> W1 >> W2;

    M[W1].insert(W2);
    M[W2].insert(W1);
}

void COUNT(map<string, set<string>>& M)
{
    string W;
    cin >> W;

    cout << M[W].size() << endl;
}

void CHECK(map<string, set<string>>& M)
{
    string W1, W2;
    cin >> W1 >> W2;

    if (M[W1].count(W2) == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
} 

int main()
{
    int Q;
    string mode;
    map<string, set<string>> M;

    cin >> Q;
    for (int i=0; i<Q; ++i)
    {
        cin >> mode;

        if (mode == "ADD")
        {
            ADD(M);
        }
        else if (mode == "COUNT")
        {
            COUNT(M);
        }
        else
        {
            CHECK(M);
        }
    }

    return 0;
}