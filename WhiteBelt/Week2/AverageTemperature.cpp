#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

void Print(const vector<int>& vector)
{
    for (auto v : vector)
    {
        cout << v << " ";
    }
}


int average(const vector<int>& vector, int N)
{
    return accumulate(vector.begin(), vector.end(), 0) / N;
}


int main()
{
    int N;
    cin >> N;
    
    vector<int> V(N);
    int temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        V[i] = temp;
    }

    int av = average(V, N);

    vector<int> new_v; 
    for (int i=0; i<N; ++i)
    {
        if (V[i] > av)
        {
            new_v.push_back(i);
        }
    }

    cout << new_v.size() << endl;
    Print(new_v);

    return 0;
}