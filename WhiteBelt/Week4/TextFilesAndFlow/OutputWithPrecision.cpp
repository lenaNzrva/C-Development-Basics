#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string path1 = "input.txt";
    ifstream input(path1);

    // string path2 = "C:/Users/lena/Desktop/Cpp_Development_Basics/need to add/TextFilesAndFlow/input2.txt";
    // ifstream input(path2);

    double value;   
    string TValue;
    if(input)
    {
        cout << fixed << setprecision(3);
        while (input >> value)
        {  
            cout << value << endl; 
        }
    }else{cout << "smth wrong.";}

    return 0;
}