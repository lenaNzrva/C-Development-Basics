#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class Person 
{
public:
    void ChangeFirstName(int year, const string& first_name) {M[year].first = first_name;}
    void ChangeLastName(int year, const string& last_name) {M[year].second = last_name;}
    string GetFullName(int year)
    {
        string first_name, last_name;

        for (auto& [key, value] : M)
        {
            cout << key;
        }
        // stringstream os;
        // os << M[year].first << " " << M[year].second;
        // return os.str();
    }
private:
map<int, pair<string, string>> M;
};

int main()
{
    Person P;
    P.ChangeFirstName(1998, "Lena");
    cout << P.GetFullName(1998);

    return 0;
}