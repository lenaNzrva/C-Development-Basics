#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) 
{
    string T;
    is >> T;
    if (T == "NEW_BUS")
    {
        int stop_count;
        string S;

        q.type = QueryType::NewBus;
        is >> q.bus;
        is >> stop_count;

        for (int i=0; i<stop_count; ++i)
        {
            is >> S;
            q.stops.push_back(S);
        }
    }
    else if(T == "BUSES_FOR_STOP")
    {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if(T == "STOPS_FOR_BUS")
    {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else{q.type = QueryType::AllBuses;}
    
    return is;
}

struct StopsForBusResponse 
{
};


ostream& operator << (ostream& os, const StopsForBusResponse& r) 
{
}


class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops)
    {
        stops_to_buses[bus] = stops;

        // cout << endl; 
        // for (auto &i : stops_to_buses)
        // {
        //     cout << i.first << ": ";
        //     for (auto &j : i.second)
        //     {
        //         cout << j << " ";
        //     }

        //     cout << endl;
        // }
    }

    StopsForBusResponse GetStopsForBus(const string& bus)
    {
        cout << bus;
        // vector<string> test = stops_to_buses.at(bus);

        for (string &i : stops_to_buses[bus])
        {
            cout << i << " ";
        }

    };

private:
    map<string, vector<string>> stops_to_buses;
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) 
    {
        cin >> q;
        switch (q.type) 
        {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            // case QueryType::BusesForStop:
            //     cout << bm.GetBusesForStop(q.stop) << endl;
            //     break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            // case QueryType::AllBuses:
            //     cout << bm.GetAllBuses() << endl;
            //     break;
        }
    }

    return 0;
}