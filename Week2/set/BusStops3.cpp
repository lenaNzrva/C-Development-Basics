#include <iostream>
#include <map>
#include<set>
using namespace std;

int main()
{
    int Q, N;
    int index = 1;
    string stop;
    map<set<string>, int> M;
    set<string> ToTest;

    cin >> Q;
    for (int i=0; i<Q; ++i)
    {
        cin >> N;
        for (int j=0; j<N; ++j)
        {
            cin >> stop;
            ToTest.insert(stop);
        }

        if (M.count(ToTest) == 0)
        {
            M[ToTest] = index;
            cout << "New bus " << index << endl;

            index++;
            ToTest.clear();
        }
        else
        {
            cout << "Already exists for " << M[ToTest] << endl;
            ToTest.clear();
        }
    }

    return 0;
}