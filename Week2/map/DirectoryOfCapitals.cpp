#include <iostream>
#include <map>
#include <string>

using namespace std;

void PRINT(map<string, string>& directory)
{
    for (auto d : directory)
    {
        cout << d.first << " " << d.second << endl;
    }
}

void CHANGE_CAPITAL(map<string, string>& directory)
{
    string country, new_capital;
    cin >> country >> new_capital;
    if (directory.count(country) == 0)
    {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        directory[country] = new_capital;
    }else if (directory.count(country) == 1 && new_capital == directory[country]){
        cout << "Country " << country << " hasn't changed its capital " << endl;
    }else {
        cout << "Country " << country << " has changed its capital from " << directory[country] << " to "  << new_capital << endl;
        directory[country] = new_capital;
    }
}

void RENAME(map<string, string>& directory)
{
    string old_country_name, new_country_name;
    cin >> old_country_name >> new_country_name;

    if (old_country_name==new_country_name || directory.count(old_country_name)==0 || directory.count(new_country_name)==1)
    {
        cout << "Incorrect rename, skip" << endl;
    }else
    {
        cout << "Country " << old_country_name << " with capital " << directory[old_country_name] << " has been renamed to " << new_country_name << endl;
        directory[new_country_name] = directory[old_country_name];
        directory.erase(old_country_name);
    }
}

void ABOUT(map<string, string>& directory)
{
    string country;
    cin >> country;

    if (directory.count(country)==0)
    {
        cout << "Country " << country << " doesn't exist" << endl;
    }else
    {
        cout << "Country " << country << " has capital " << directory[country] << endl;
    }
}

void DUMP(map<string, string>& directory)
{
    if (directory.size()==0)
    {
        cout << "There are no countries in the world" << endl;
    }else
    {
        for (auto d:directory)
        {
            cout << d.first << "/" << d.second << " ";
        }

        cout << endl;
    }
}

int main()
{
    int Q;
    string mode;
    map<string, string> directory;

    cin >> Q;
    for (int i=0; i<Q; ++i)
    {
        cin >> mode;

        if (mode == "CHANGE_CAPITAL")
        {
            CHANGE_CAPITAL(directory);
            // PRINT(directory);
        }else if (mode == "RENAME")
        {
            RENAME(directory);
        }else if (mode == "ABOUT")
        {
            ABOUT(directory);
        }else
        {
            DUMP(directory);
        }
    }

    return 0;
}