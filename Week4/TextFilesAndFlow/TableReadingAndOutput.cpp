#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string path = "input3.txt";
    // string path = "input.txt";
    // string path = "C:/Users/lena/Desktop/Cpp_Development_Basics/Week4/TextFilesAndFlow/input3.txt";
    ifstream input(path);

    if (input)
    {
        int N, M, V;
        string value;

        input >> N;
        input.ignore(1);
        input >> M;

        for (int j=0; j<N; ++j)
        {
            for (int i=0; i<M; ++i)
            {
                input >> V;
                input.ignore(1);
                if (i==0)
                {
                    cout << setw(10) << V;
                }
                else
                {
                    cout << setw(11) << V;
                }
            }
            if (j!= N-1)
            {
                cout << endl;
            }
        }



    }else{cout<<"smth wrong.";}

    return 0;
}
