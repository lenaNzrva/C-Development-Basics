#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings
{
    public:
    void AddString(const string& s) 
    {
        V.push_back(s);
        sort(begin(V), end(V));
    }

    vector<string> GetSortedStrings() 
    {
        return getsortedstrings(V);
    }

    private:
    vector<string> V;
    vector<string> getsortedstrings(const vector<string>& Vector)
    {
        return Vector;
    }
};


void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main()
{
    SortedStrings strings;
  
    // strings.AddString("first");
    // strings.AddString("third");
    // strings.AddString("second");
    // PrintSortedStrings(strings);

    // strings.AddString("second");
    // PrintSortedStrings(strings);

    return 0;
}