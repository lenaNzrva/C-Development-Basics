#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

class Date
{
public:
    Date(const string& str)
    {
        int intermediate_y, intermediate_m, intermediate_d; 
        stringstream ss(str);
        if(ss >> intermediate_y && ss.peek() == 45)
        {
            ss.ignore(1);
            if(ss >> intermediate_m && ss.peek() == 45)
            {
                ss.ignore(1);
                if(ss >> intermediate_d && ss.peek() == -1)
                {
                    if (intermediate_m < 1 || intermediate_m > 12)
                    {
                        cout << "Month value is invalid: " << intermediate_m << endl;
                        throw invalid_argument("");
                    }
                    else if (intermediate_d < 1 || intermediate_d > 31)
                    {
                        cout << "Day value is invalid: " << intermediate_d << endl;
                        throw invalid_argument("");
                    }
                    else
                    {
                        year = intermediate_y;
                        month = intermediate_m;
                        day = intermediate_d;
                    }
                }else
                {
                    cout << "Wrong date format: " << str << endl;
                    throw invalid_argument("");
                }
            }else
            {
                cout << "Wrong date format: " << str << endl;
                throw invalid_argument("");
            }
        }else
        {
            cout << "Wrong date format: " << str << endl;
            throw invalid_argument("");
        }

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
                cout << "Deleted successfully" << endl;

                if (M[date].size() == 0)
                {
                    M.erase(date);
                }
            }else {cout << "Event not found" << endl;}
            
        }else 
        {
            cout << "Deleted " << M[date].size() << " events" << endl;
            M.erase(date);
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
    void Print ()
    {
        for (auto i: M)
        {
            for (auto j: i.second)
            {
                cout << setw(4) << setfill('0') << i.first.y() << '-' << setw(2) << setfill('0') << i.first.m() << '-' << 
                setw(2) << setfill('0') << i.first.d() << ' ' << j << endl; 
            }
        }
    };
private:

    map<Date, set<string>> M;
};


int main()
{
    DataBase DB;
    string command;

    while (getline(cin, command))
    {
        if (command != "")
        {
            stringstream ss(command);
            string todo, data, event;

            getline(ss, todo, ' ');
            getline(ss, data, ' ');
            getline(ss, event, ' ');

            if (todo == "Add")
            {
                try
                {
                    Date date(data);
                    DB.AddEvent(date, event);
                }catch (invalid_argument& i){continue;}
            } 
            else if (todo == "Del")
            {
                try
                {
                    Date date(data);
                    DB.DeleteEvent(date, event);
                }catch (invalid_argument& i){continue;}
            }else if (todo == "Find")
            {
                try
                {
                    Date date(data);
                    DB.Find(date);
                }catch (invalid_argument& i){continue;}
            }else if (todo == "Print")
            {
                DB.Print();
            }else{cout << "Unknown command: " << todo << endl;}
        }
    }

    return 0;
}