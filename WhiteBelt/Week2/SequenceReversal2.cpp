#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> copy = v;
    reverse(begin(copy), end(copy));

    return copy;
}

int main()
{
    vector<int> vect = {1, 5, 3, 4, 2};
    // for (auto v: vect)
    // {
    //     cout << v << " ";
    // }

    vector<int> result = Reversed(vect);

    // cout << endl;

    // for (auto v: vect)
    // {
    //     cout << v << " ";
    // }

    // cout << endl;

    // for (auto v: result)
    // {
    //     cout << v << " ";
    // }

     
    return 0;
}