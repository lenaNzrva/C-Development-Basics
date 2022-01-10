#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int number;
    vector<int> array;
    cin >> N;

    for (int i=0; i<N; ++i)
    {
        cin >> number;
        array.push_back(number);
    }

    sort(array.begin(), array.end(), [](int a, int b) {return abs(a) < abs(b);});

    for (auto& i : array)
    {
        cout << i << " ";
    }

    return 0;
}