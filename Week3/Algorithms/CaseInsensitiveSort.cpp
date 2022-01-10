#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    string S;
    vector<string> array;

    cin >> N;
    for (int i=0; i<N; ++i)
    {
        cin >> S;
        array.push_back(S);
    }

    sort(array.begin(), array.end(), [](string a, string b){for(int i=0; i<a.size(); ++i){a[i]=tolower(a[i]);b[i]=tolower(b[i]);} return a<b;});

    for (auto& i : array)
    {
        cout << i << " ";
    }


    return 0;
}