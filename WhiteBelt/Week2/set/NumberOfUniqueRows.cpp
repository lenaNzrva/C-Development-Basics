#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    string str;
    set<string> unique;
    cin >> N;

    for(int i=0; i<N; ++i)
    {
        cin >> str;
        unique.insert(str);
    } 

    cout << unique.size();

    return 0;
}