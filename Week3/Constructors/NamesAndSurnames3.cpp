#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person 
{
public:
    Person(const string& FNameBirth, const string& LNameBirth, int year)
    {
        // f_name[year] = FNameBirth;
        // l_name[year] = LNameBirth;
        YearBirth = year;
        BFName = FNameBirth;
        BLName = LNameBirth;
        ChangeFirstName(year, FNameBirth);
        ChangeLastName(year, LNameBirth);
    }

    void ChangeFirstName(int year, const string& first_name)
    {
        if (year >= YearBirth)
        {
            f_name[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name)
    {
        if (year >= YearBirth)
        {
            l_name[year] = last_name;
        }
    }
    string GetFullName(int year) const
    {
        if (year<YearBirth)
        {
            return "No person";
        }
        else
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
        } //else {return BFName + " " + BLName;}
    }
    string GetFullNameWithHistory(int year) const
    {
        if (year<YearBirth)
        {
            return "No person";
        }
        else //if (year > YearBirth)
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

        }//else {return BFName + " " + BLName;}

    }


private:
map<int, string> f_name, l_name;
int YearBirth;
string BFName, BLName;

void func(int year, const map<int, string>& name, string& result, int& result_ind) const
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

void func2(int year, const map<int, string>& name, string& result, string test) const
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
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1960, "Appolinaria");
	person.ChangeLastName(1960, "Ivanova");
	for (int year : { 1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

    return 0;
}