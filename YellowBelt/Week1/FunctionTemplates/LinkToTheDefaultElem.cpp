#include <iostream>
#include <map>
using namespace std;

template <typename key, typename value>
value& GetRefStrict(map<key, value> &M, key K)
{
    if (M.count(K)){return M[K];}
    else{throw runtime_error("");}
}

int main()
{
    // map<int, string> m = {{0, "value"}};
    // string& item = GetRefStrict(m, 0);
    // item = "newvalue";
    // cout << m[0] << endl; // выведет newvalue

    return 0;
}