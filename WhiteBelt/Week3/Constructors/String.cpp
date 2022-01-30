#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
    ReversibleString() {}
    ReversibleString(const string& S) {NewString = S;}

    void Reverse()
    {
        // Temp = NewString;
        reverse(begin(NewString), end(NewString));
        // NewString = Temp;
    }

    string ToString() const
    {
        return NewString;
    }

private: 
    string NewString;
    string Temp;
};

int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}