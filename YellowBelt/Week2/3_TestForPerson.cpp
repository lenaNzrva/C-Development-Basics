#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Person 
{
public:
    void ChangeFirstName(int year, const string& first_name) 
    {
        F[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) 
    {
        L[year] = last_name;
    }
    string GetFullName(int year)
    {
        string first = GetName(F, year);
        string last = GetName(L, year);

        if (first.empty() && last.empty()){return "Incognito";}
        else if (first.empty()){return last + " with unknown first name";}
        else if (last.empty()){return first + " with unknown last name";}

        return first + " " + last;
    }

private:
    map<int, string> F;
    map<int, string> L;

    string GetName(const map<int, string> &M, const int year)
    {
        string name;
        for (auto [key, val] : M)
        {
            if (year >= key)
            {
                name = val;
            }
            else {break;}
        }

        return name;
    }
};

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
    //unknown last name
    {
        Person person;
        int year = 1998;
        string name = "Lena";
        person.ChangeFirstName(year, name);
        AssertEqual(name + " with unknown last name", person.GetFullName(year));
    }
    {
        Person person;
        vector<int> year = {1998, 2001};
        string name = "Lena";
        person.ChangeFirstName(year[0], name);
        person.ChangeLastName(year[1], "Nazarova");
        AssertEqual(name + " with unknown last name", person.GetFullName(year[0])); 
    }
    // unknown first name
    {
        Person person;
        int year = 1998;
        string name = "Nazarova";
        person.ChangeLastName(year, name);
        AssertEqual(name + " with unknown first name", person.GetFullName(year));
    }
    {
        Person person;
        vector<int> year = {1998, 2001};
        string name = "Nazarova";
        person.ChangeLastName(year[0], name);
        person.ChangeFirstName(year[1], "Lena");
        AssertEqual(name + " with unknown first name", person.GetFullName(year[0])); 
    }
    // Incognito
    {
        Person person;
        int year = 1998;
        AssertEqual("Incognito", person.GetFullName(year));
    }
    {
        Person person;
        int year = 1998;
        person.ChangeFirstName(2005, "Lena");
        person.ChangeLastName(2007, "Nazarova");
        AssertEqual("Incognito", person.GetFullName(year));
    }
    // Normal
    {
        Person person;
        int year = 1998;
        string fname = "Lena";
        string lname = "Nazarova";
        person.ChangeFirstName(year, fname);
        person.ChangeLastName(year, lname);
        AssertEqual(fname +" "+ lname, person.GetFullName(year));         
    }
    {
        Person person;
        int year = 1998;
        string fname = "Lena";
        string lname = "Nazarova";
        person.ChangeFirstName(year, fname);
        person.ChangeLastName(year, lname);
        AssertEqual(fname +" "+ lname, person.GetFullName(2007));         
    }
    {
        Person person;
        vector<int> year = {1998, 2007, 2015};
        string fname = "Lena";
        string lname = "Nazarova";
        person.ChangeFirstName(year[0], fname);
        person.ChangeLastName(year[1], lname);
        AssertEqual(fname +" "+ lname, person.GetFullName(year[2]));         
    }
    {
        Person person;
        vector<int> year = {1998, 2007, 2015};
        string fname = "Lena";
        string lname = "Nazarova";
        person.ChangeFirstName(year[0], fname);
        person.ChangeLastName(year[1], lname);
        AssertEqual(fname +" "+ lname, person.GetFullName(year[2]));         
    }
    {
        Person person;
        vector<int> year = {1998, 2007, 2015, 2070};
        string fname_1 = "Lena";
        string fname_2 = "Elena";
        string lname = "Nazarova";
        person.ChangeFirstName(year[0], fname_1);
        person.ChangeFirstName(year[1], fname_2);
        person.ChangeLastName(year[2], lname);
        AssertEqual(fname_2 +" "+ lname, person.GetFullName(year[3]));         
    }
    {
        Person person;
        vector<int> year = {1998, 2007, 2015, 2008};
        string fname_1 = "Lena";
        string fname_2 = "Elena";
        string lname = "Nazarova";
        person.ChangeFirstName(year[0], fname_1);
        person.ChangeFirstName(year[2], fname_2);
        person.ChangeLastName(year[1], lname);
        AssertEqual(fname_1 +" "+ lname, person.GetFullName(year[3]));         
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