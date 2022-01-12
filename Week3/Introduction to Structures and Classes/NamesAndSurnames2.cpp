#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person 
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        f_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        l_name[year] = last_name;
    }
    string GetFullName(int year)
    {
        string f_result, l_result;
        int result_ind;
        func(year, f_name, f_result, result_ind);
        func(year, l_name, l_result, result_ind);

        if (f_result.empty() && l_result.empty())
        {
            return "Incognito";
        }
        else if (f_result.empty() && !l_result.empty())
        {
            return l_result + " with unknown first name";
        }
        else if (!f_result.empty() && l_result.empty())
        {
            return f_result + " with unknown last name";
        }
        else
        {
            return f_result + " " + l_result;
        }
    }
    string GetFullNameWithHistory(int year) 
    {
        int result_ind1, result_ind2;
        string f_result, l_result;
        string result = "";
        func(year, f_name, f_result, result_ind1);
        func(year, l_name, l_result, result_ind2);

        if (f_result.empty() && l_result.empty())
        {
            return "Incognito";
        }
        else if (f_result.empty() && !l_result.empty())
        {
            func2(result_ind2, l_name, result, l_result);
            return l_result + result + " with unknown first name";
        }
        else if (!f_result.empty() && l_result.empty())
        {
            func2(result_ind1, f_name, result, f_result);
            return f_result + result + " with unknown last name";
        }
        else
        {
            func2(result_ind1, f_name, result, f_result);
            string result2 = "";
            func2(result_ind2, l_name, result2, l_result);
            return f_result + result + " " + l_result +  result2;
        }
    }


private:
map<int, string> f_name, l_name;

void func(int year, const map<int, string>& name, string& result, int& result_ind)
{
    for (auto iter: name)
    {
        if (iter.first <= year)
        {
            result = iter.second;
            result_ind = iter.first;
        }
        else
        {
            break;
        }
    }
}

void func2(int year, const map<int, string>& name, string& result, string test)
{   
    for (auto iter = name.rbegin(); iter != name.rend(); ++iter)
    {
        if (iter->first < year && test != iter->second)
        {
            result += (iter->second + ", ");
            test = iter->second;
        }
    }
  
    if (!result.empty())
    {
        result.pop_back();
        result.pop_back();
        result = " (" + result;
        result += ")";
    }
    
}

};

int main()
{
    Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}