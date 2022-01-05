#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int Q, N;
    string stop;
    map<vector<string>, int> StopsAndBuses;
    vector<string> stops;
    int value = 1;


    cin >> Q;
    for (int i=0; i<Q; ++i)
    {
        cin >> N;

        for (int j=0; j<N; ++j)
        {
            cin >> stop; 
            stops.push_back(stop);  
        }

        if (StopsAndBuses.count(stops) == 0)
        {
            StopsAndBuses[stops] = value;
            cout << "New bus " << value << endl;
            value ++;
            stops.clear();
        }
        else
        {
            cout << "Already exists for " << StopsAndBuses[stops] << endl;
            stops.clear();
        }

    }

    return 0;
}