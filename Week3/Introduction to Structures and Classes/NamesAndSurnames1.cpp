#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Person 
{
public:
  void ChangeFirstName(int year, const string& first_name) 
  {// добавить факт изменения имени на first_name в год year
    f_name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) 
  {// добавить факт изменения фамилии на last_name в год year
    l_name[year] = last_name;
  }
  string GetFullName(int year) 
  {// получить имя и фамилию по состоянию на конец года year
    if (f_name.count(year) == 1 && l_name.count(year) == 1)
    {
        return f_name[year] + " " + l_name[year];
    }
    else if (f_name.count(year) == 0 && l_name.count(year) == 1)
    {
        test = {f_name.begin(), f_name.lower_bound(year)};
        if (test.size() == 0)
        {
            return l_name[year] + " with unknown first name";
        }
        else
        {   
            for (auto iter : test)
            {
                result = iter.second;
            }
            return result + " " + l_name[year];
        }
    }
    else if (f_name.count(year) == 1 && l_name.count(year) == 0)
    {
        test = {l_name.begin(), l_name.lower_bound(year)};
        if (test.size() == 0)
        {
            return f_name[year] + " with unknown last name";
        }
        else
        {
            for (auto iter : test)
            {
                result = iter.second;
            }
            return f_name[year] + " " + result;
        }
    }
    else
    {
        test = {f_name.begin(), f_name.lower_bound(year)};
        test2 = {l_name.begin(), l_name.lower_bound(year)};

        if (test.size() != 0 && test2.size() != 0)
        {
            for (auto iter : test)
            {
                result = iter.second;
            }
            for (auto iter : test2)
            {
                result2 = iter.second;
            }
            return result + " " + result2;
        }
        else if (test.size() == 0 && test2.size() != 0)
        {
            for (auto iter : test2)
            {
                result2 = iter.second;
            }
            return result2 + " with unknown first name";
        }
        else if (test.size() != 0 && test2.size() == 0)
        {
            for (auto iter : test)
            {
                result = iter.second;
            }
            return result + " with unknown last name";
        }
        else
        {
            return "Incognito";
        }
    }
  }

private:
    string result, result2;
    map<int, string> test, test2;
    map<int, string> f_name, l_name;

};


int main()
{
    Person person;

    // person.ChangeFirstName(1965, "Polina");
    // person.ChangeLastName(1967, "Sergeeva");
    // for (int year : {1900, 1965, 1990}) {
    //     cout << person.GetFullName(year) << endl;
    // }
    
    // person.ChangeFirstName(1970, "Appolinaria");
    // for (int year : {1969, 1970}) {
    //     cout << person.GetFullName(year) << endl;
    // }
    
    // person.ChangeLastName(1968, "Volkova");
    // for (int year : {1969, 1970}) {
    //     cout << person.GetFullName(year) << endl;
    // }

    return 0;
}