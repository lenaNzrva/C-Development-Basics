#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

class Date
{
public:
    Date(const string& str)
    {
        stringstream ss(str);
        ss >> year;
        ss.ignore(1);
        ss >> month;
        ss.ignore(1);
        ss >> day;
    }

    int y() const {return year;}
    int m() const {return month;}
    int d() const {return day;}

private:
    int year, month, day;
};

bool operator< (const Date lhs, const Date& rhs)
{
    if (lhs.y() < rhs.y()){return true;}
    else if(lhs.y() == rhs.y() && lhs.m() < rhs.m()){return true;}
    else if(lhs.m() == rhs.m() && lhs.d() < rhs.d()){return true;}
    else {return false;}
}

class DataBase
{
public:
    void AddEvent(Date& date, const string& event)
    {
        M[date].insert(event);
    }
    void DeleteEvent(Date& date, const string& event)
    {
        if (event != "")
        {

            if (M[date].count(event))
            {
                M[date].erase(event);
                cout << "Deleted successfully";
            }else {cout << "Event not found";}
            
        }else 
        {
            cout << "Deleted " << M[date].size() << " events";
            M[date].empty();
        }
    }

    void Find (const Date& date)
    {
        if (M.count(date))
        {
            for (string i: M[date])
            {
                cout << i << endl;
            }
        }   
    }
    void Print ();
private:

    map<Date, set<string>> M;
};


int main()
{
    DataBase DB;
    string command;

    while (getline(cin, command))
    {
        stringstream ss(command);
        string todo, data, event;

        getline(ss, todo, ' ');
        getline(ss, data, ' ');
        Date date(data);
        getline(ss, event, ' ');

        if (todo == "Add")
        {
            DB.AddEvent(date, event);
        } 
        else if (todo == "Del")
        {
            DB.DeleteEvent(date, event);
        }else if (todo == "Find")
        {
            DB.Find(date);
        }else if (todo == "Print")
        {
            DB.Print();
        }

        // cout << date.y() << date.m() << date.d();

        // cout << date << ' ' << date.month() << ' ' << date.day() << endl;
    }

    return 0;
}