#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<< (ostream& stream,const vector<size_t>& object)
{
    for (auto i: object){stream << i << ' ';}
    return stream;
}

int main()
{
    unsigned int N;
    int Temp;
    vector<int> V;

    cin >> N;
    for (unsigned int i=0; i<N; ++i)
    {
        cin >> Temp;
        V.push_back(Temp);
    }

    int64_t sum = 0;
    for (auto i: V){sum += i;}
    int avg = sum/static_cast<int>(V.size());

    int c = count_if(V.begin(), V.end(), [avg](auto i){return i > avg;});

    vector<size_t> results;
    auto it = find_if(begin(V), end(V), [avg](int i){return i > avg;});
    while (it != end(V)) 
    {
        results.push_back(distance(begin(V), it));
        it = find_if(next(it), end(V), [avg](int i){return i > avg;});
    }

    cout << c << endl;
    cout << results;

    return 0;
}