#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

void Print(const vector<bool>& V)
{
    for (auto v : V)
    {
        cout << v << " ";
    }
}

int main()
{
    //Количество операций Q
    int Q;
    cin >> Q;

    //Изначально очередь пуста
    vector<bool> queue;

    for (int i=0; i<Q; ++i)
    {
        string mode;
        cin >> mode;

        if (mode == "WORRY_COUNT")
        {
            cout << count(begin(queue), end(queue), true) << endl;
        }else
        {
            int N;
            cin >> N;

            if (mode == "COME")
            {
                queue.resize(queue.size() + N, false);

            }else if (mode == "WORRY" || mode == "QUIET")
            {
                queue[N] = !queue[N];
                // queue[N] = (mode == "WORRY");
            }
        }

    }

    // Print(queue);

    return 0;
}