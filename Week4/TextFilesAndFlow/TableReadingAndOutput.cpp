#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// void PrintM(int M, ifstream& input)
// {
//     int value;
//     for (int j=0; j<M; ++j)
//     {
//         input >> value;
//         input.ignore(1);
//         cout << value;
//         // cout << setfill('.');
//         // cout << setw(10);
//     }
// }

int main()
{
    // string path = "input.txt";
    string path = "C:/Users/lena/Desktop/Cpp_Development_Basics/Week4/TextFilesAndFlow/input3.txt";
    ifstream input(path);

    if (input)
    {
        int N, M;
        string value;
        input >> N;
        input.ignore(1);
        input >> M;

        for (int j=0; j+1<M; ++j)
        {
            getline(input, value, ',');
            cout << value;
        }
        getline(input, value, '\n');
        cout << value;
        
        

    }else{cout<<"smth wrong.";}

    return 0;
}