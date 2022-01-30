#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

void Print(const vector<string>& V)
{
    for (auto v:V)
    {
        cout<<v<<" ";
    }
}

int main()
{
    //число операций Q
    int Q;
    cin >> Q;
    int day;

    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_count = 0;
    vector<vector<string>> affairs(months[month_count]);

    // cout << affairs[0].size();
    // vector<vector<string>> current;
    // current = affairs;

    for (int i=0; i<Q; ++i)
    {
        if (month_count==11)
        {
            month_count = -1;
        }

        string mode;
        cin >> mode;

        if (mode == "ADD")
        {
            string whatToDo;

            cin >> day >> whatToDo;

            affairs[day-1].push_back(whatToDo);
        }else if (mode == "DUMP")
        {
            cin >> day;

            cout << affairs[day-1].size() << " ";

            for (string dela : affairs[day-1])
            {
                cout << dela << " ";
            }

            cout << endl; 

        }else if (mode == "NEXT")
        {
            month_count++;
            // vector<vector<string>> new_affairs(months[month_count]);

            if (months[month_count] >= months[month_count-1])
            {
                affairs.resize(affairs.size()+(months[month_count]-months[month_count-1]));
                // cout << affairs.size();
            }else
            {
                int number =  months[month_count-1] - months[month_count];

                int where = months[month_count]-1;

                for (int t=1; t<=number; ++t)
                {
                    affairs[where].insert(affairs[where].end(), affairs[where+t].begin(), affairs[where+t].end());
                }

                affairs.resize(months[month_count]);
                // cout << affairs.size();

                // Print(affairs[where]);

            }
        }
    }

    return 0;
}