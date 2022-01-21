#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // const string ipath = "C:/Users/lena/Desktop/Cpp_Development_Basics/need to add/TextFilesAndFlow/input.txt";
    // const string opath = "C:/Users/lena/Desktop/Cpp_Development_Basics/need to add/TextFilesAndFlow/output.txt";
    const string ipath = "input.txt";
    const string opath = "output.txt";
    ifstream input(ipath);
    ofstream output(opath);
    string str;

    if (input.is_open())
    {
        while (getline(input, str))
        {
            output << str << endl;
        }
    }else{cout << "smth wrong";}

    return 0;
}