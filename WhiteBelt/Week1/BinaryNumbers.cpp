#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector <int> v;
    cin >> N;
    
    while (N != 0)
    {
        v.push_back(N%2);
        N = N/2;
    }
    
    reverse(v.begin(), v.end());
    
    for (auto i: v)
    {
        cout << i;
    }
    

    return 0;
}