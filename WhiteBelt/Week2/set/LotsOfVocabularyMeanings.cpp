#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) 
{
    set<string> test;

    for (auto iter : m)
    {
        test.insert(iter.second);
    }


    return test;
}

// int main()
// {
//     map<int, string> test = {{1, "odd"}, {2, "even"}, {3, "odd"}, {4, "even"}, {5, "odd"}};
//     BuildMapValuesSet(test);

//     return 0;
// }   