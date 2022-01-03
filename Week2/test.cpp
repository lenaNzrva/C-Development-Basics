#include <iostream>
#include <map>
#include <string>

using namespace std;

void Print(const map<int, string> map)
{
    for (auto m:map)
    {
        cout << m.first << " " << m.second << endl;
    }
}

int main()
{
    map<int, string> m{ {10, "potato"}, {1, "banana"} };
    // auto nodeHandler = m.extract(10);    
    // nodeHandler.key() = 2;
    // m.insert(move(nodeHandler));

    Print(m);

    return 0;
}