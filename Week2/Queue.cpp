#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

void COME(vector<string>& V, int N)
{
    for (int i=0; i<N; ++i)
    {
        V.push_back("QUIET");
    }
}

void WORRY(vector<string>& V, int N)
{
    V[N] = "WORRY";
}

void QUIET(vector<string>& V, int N)
{
    V[N] = "QUIET";
}

void NOT_COME(vector<string>& V, int N)
{
    for (int i=0; i>N; --i)
    {
        V.pop_back();
    }
}

void WORRY_COUNT(const vector<string>& V)
{
    int worrySum = 0;
    for (string v : V)
    {
        if (v == "WORRY")
        {
            worrySum++;
        }
    }

    cout << worrySum << endl;
}

void Print(const vector<string>& V)
{
    for (auto v : V)
    {
        cout << v << " ";
    }
}

int main()
{
    vector<string> queue;
    int Q;
    cin >> Q;


    string whatToDo;
    int N;
    for (int i=0; i<Q; ++i)
    {
        cin >> whatToDo >> N;

        if (whatToDo=="COME" && N > 0)
        {
            COME(queue, N);
        }else if (whatToDo=="WORRY")
        {
            WORRY(queue, N);
        }else if(whatToDo=="COME" && N < 0)
        {
            NOT_COME(queue, N);
        }else if(whatToDo=="QUIET")
        {
            QUIET(queue, N);
        }else if(whatToDo=="WORRY_COUNT")
        {
            WORRY_COUNT(queue);
        }
    }

    // Print(queue);

    return 0;
}