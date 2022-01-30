#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // string path = "C:/Users/lena/Desktop/Cpp_Development_Basics/need to add/TextFilesAndFlow/input.txt";
    string path = "input.txt";
    ifstream input(path);
    string str;

    if (input.is_open())
    {
        while (getline(input, str))
        {
            cout << str << endl;
        }
    }else{cout << "smth wrong";}

    return 0;
}