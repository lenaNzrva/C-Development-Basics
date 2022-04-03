#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// class Person 
// {
// public:
//     void ChangeFirstName(int year, const string& first_name) 
//     {
//         F[year] = first_name;
//     }
//     void ChangeLastName(int year, const string& last_name) 
//     {
//         L[year] = last_name;
//     }
//     string GetFullName(int year)
//     {
//         string first = GetName(F, year);
//         string last = GetName(L, year);

//         if (first.empty() && last.empty()){return "Incognito";}
//         else if (first.empty()){return last + " with unknown first name";}
//         else if (last.empty()){return first + " with unknown last name";}

//         return first + " " + last;
//     }
//     // map<int, string>& GetFirstName(){return F;}
//     // map<int, string>& GetLastName(){return L;}
// private:
//     map<int, string> F;
//     map<int, string> L;

//     string GetName(const map<int, string> &M, const int year)
//     {
//         string name;
//         for (auto [key, val] : M)
//         {
//             if (year >= key)
//             {
//                 name = val;
//             }
//             else {break;}
//         }

//         return name;
//     }
// };

template <typename LHS, typename RHS>
void AssertEqual(LHS const &lhs, RHS const &rhs)
{
    if(lhs!=rhs)
    {
        stringstream os;
        os << lhs << " != " << rhs;
        throw runtime_error(os.str());
    }
}


void TestAll()
{
    //Проверка добавления в словари
    {
        Person person;
        int year = 1998;
        string name = "Lena";
        person.ChangeFirstName(year, name);
        
        AssertEqual(name + " with unknown last name", person.GetFullName(year));

    }
}


class TestRunner 
{
public:
    template <class TestFunc>
    void RunTest(TestFunc func) 
    {
        try 
        {
            func();
            cerr << "OK" << endl;
        } 
        catch (runtime_error& e) 
        {
            ++fail_count;
            cerr << "fail: " << e.what() << endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0) 
        {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
        }
    }

private:
    int fail_count = 0;
};

int main()
{
    TestRunner runner;
    runner.RunTest(TestAll);

    return 0;
}