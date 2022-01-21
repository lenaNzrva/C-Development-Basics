#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // string path = "input.txt";
    string path = "C:/Users/lena/Desktop/Cpp_Development_Basics/need to add/TextFilesAndFlow/input3.txt";
    ifstream input(path);

    if (input)
    {
        int N, M;
        string value;
        // input >> N;
        // input.ignore(1);
        // input >> M;

        getline(input, value);
        cout << value;


    }else{cout<<"smth wrong.";}

    return 0;
}