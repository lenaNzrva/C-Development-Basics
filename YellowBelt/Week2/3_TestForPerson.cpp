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
    void ChangeFirstName(int year, const string& first_name) 
    {
        M[year].first = first_name;
        years.insert(year);
    }
    void ChangeLastName(int year, const string& last_name) 
    {
        M[year].second = last_name;
        years.insert(year);
    }
    void GetFullName(int year)
    {
        string first_name, last_name;

        for (auto itr = years.begin(); *itr >= year; itr++)
        {
            first_name = M[*itr].first;
            last_name = M[*itr].second;
        }

        cout << first_name << "////" << last_name << endl;
    }
private:
map<int, pair<string, string>> M;
set<int> years;
};

int main()
{
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) 
    {
        person.GetFullName(year);
    }

    return 0;
}