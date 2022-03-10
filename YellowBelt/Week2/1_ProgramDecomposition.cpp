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

        q.stops.clear();
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

struct BusesForStopResponse 
{
    stringstream SS;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) 
{
    os << r.SS.str();
    return os;
}

struct StopsForBusResponse
{
    stringstream SS;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) 
{
    os << r.SS.str();
    return os;
}

struct AllBusesResponse 
{
    stringstream SS;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) 
{
    os << r.SS.str();
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops)
    {
        for (auto &i : stops){buses_to_stop[i].push_back(bus);}

        stops_to_bus[bus] = stops;
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const
    {
        BusesForStopResponse response;
        if(buses_to_stop.count(stop))
        {
            for (auto &i : buses_to_stop.at(stop)){response.SS << i << " ";}
        }
        else {response.SS << "No stop";}

        return response;
    };

    StopsForBusResponse GetStopsForBus(const string& bus) const
    {
        StopsForBusResponse response;
        if (stops_to_bus.count(bus))
        {
            for (auto &i : stops_to_bus.at(bus))
            {
                response.SS << "Stop " << i << ":";
                if (buses_to_stop.at(i).size() == 1){response.SS << " no interchange";}
                else
                {
                    for (auto &j : buses_to_stop.at(i))
                    {
                        if (j != bus){response.SS << " " << j;}
                    }
                }
                response.SS << endl;
            }
        }
        else{response.SS << "No bus";}

        return response;
    }

    AllBusesResponse GetAllBuses() const
    {
        AllBusesResponse response;
        if (stops_to_bus.size())
        {
            for (auto &i : stops_to_bus)
            {
                response.SS << "Bus " << i.first << ":";
                for (auto &j : i.second)
                {
                    response.SS << " " << j;
                }
                response.SS << endl;
            }
        }
        else{response.SS << "No buses";}

        return response;
    }

private:
    map<string, vector<string>> buses_to_stop, stops_to_bus;
};

int main() {
    // int query_count;
    // Query q;

    // cin >> query_count;

    // BusManager bm;
    // for (int i = 0; i < query_count; ++i) 
    // {
    //     cin >> q;
    //     switch (q.type)
    //     {
    //         case QueryType::NewBus:
    //             bm.AddBus(q.bus, q.stops);
    //             break;
    //         case QueryType::BusesForStop:
    //             cout << bm.GetBusesForStop(q.stop) << endl;
    //             break;
    //         case QueryType::StopsForBus:
    //             cout << bm.GetStopsForBus(q.bus) << endl;
    //             break;
    //         case QueryType::AllBuses:
    //             cout << bm.GetAllBuses() << endl;
    //             break;
    //     }
    // }

    return 0;
}