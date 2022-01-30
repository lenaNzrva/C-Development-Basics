#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void NEW_BUS(map<string, vector<string>>& BusesStops, vector<string>& BusesInLine)
{
    string bus, stop;
    int stop_count;

    cin >> bus >> stop_count;
    BusesInLine.push_back(bus);
    for(int i=0; i<stop_count; ++i)
    {
        cin >> stop;
        BusesStops[bus].push_back(stop);
    }
}

vector<string> BUSES_FOR_STOP(map<string, vector<string>>& BusesStops, const vector<string>& BusesInLine, string stop)
{
    
    vector<string> stops;

    for (auto busesinline : BusesInLine)
    {
        for (auto V : BusesStops[busesinline])
        {
            if (V==stop)
            {
                stops.push_back(busesinline);
            }
        }
    }

    return stops;
}

void STOPS_FOR_BUS(map<string, vector<string>>& BusesStops, const vector<string>& BusesInLine)
{
    string bus;
    cin >> bus;

    if (BusesStops.count(bus)==0)
    {
        cout << "No bus" << endl;
    }

    else
    {
        for (auto stops : BusesStops[bus])
        {
            vector<string> buses = BUSES_FOR_STOP(BusesStops, BusesInLine, stops);
            
            if (buses.size()==1)
            {
                cout << "Stop " << stops << ": no interchange" << endl;
            }
            else
            {
                cout << "Stop " << stops << ": " ;
                for (auto b : buses)
                {
                    if (b != bus)
                    {
                        cout << b << " ";
                    }
                }
                cout << endl;
            }
        }

    }

}

int main()
{
    int Q;
    string mode;
    cin >> Q;

    map<string, vector<string>> BusesStops;
    vector<string> BusesInLine;
    

    for (int i=0; i<Q; ++i)
    {
        cin >> mode;

        if (mode=="NEW_BUS")
        {
            NEW_BUS(BusesStops, BusesInLine);
        }
        
        else if (mode=="BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            vector<string> stops = BUSES_FOR_STOP(BusesStops, BusesInLine, stop);

            if (stops.size()==0)
            {
                cout << "No stop" << endl;
            }else
            {
                for (auto s : stops)
                {
                    cout << s <<" ";
                }
                cout << endl;
            }
        }
        
        else if(mode=="STOPS_FOR_BUS")
        {
            STOPS_FOR_BUS(BusesStops, BusesInLine);
        }

        else if(mode=="ALL_BUSES")
        {
            if(BusesStops.size() == 0)
            {
                cout << "No buses" << endl;
            }
            else
            {
                for (auto iter : BusesStops)
                {
                    cout << "Bus " << iter.first << ": ";
                    for (auto s : iter.second)
                    {
                        cout << s << " ";
                    }
                    cout << endl;
                }   
            }
        }


        // for (auto iter : BusesStops)
        // {
        //     cout << iter.first;
        // }

    }

    return 0;
}