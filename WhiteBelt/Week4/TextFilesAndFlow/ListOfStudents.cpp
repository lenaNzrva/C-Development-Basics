#include <iostream>
#include <map>

using namespace std;

struct Student 
{
    string name, surname;
    int day, month, year;
};


int main()
{
    int N, M, k;
    string request;
    map<int, Student> Map;
    cin >> N;

    Student S;
    for (int i=0; i<N; i++)
    {
        cin >> S.name;
        cin >> S.surname;
        cin >> S.day;
        cin >> S.month;
        cin >> S.year;

        Map[i+1] = S;
    }

    cin >> M;
    for (int i=0; i<M; ++i)
    {
        cin >> request;
        cin >> k;

        if (Map.count(k) == 1)
        {
            if (request=="name")
            {
                cout << Map[k].name << " " << Map[k].surname << endl; 
            }
            else if (request=="date")
            {
                cout << Map[k].day << "." << Map[k].month << "." << Map[k].year << endl;
            }else {cout << "bad request" << endl;}
        }else {cout << "bad request" << endl;}

    }

    return 0;
}