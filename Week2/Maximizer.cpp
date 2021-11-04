#include <iostream>
using namespace std;

void UpdateIfGreate(int first, int& second)
{
    if (first > second)
    {
        second = first;
    }
}

//int main()
//{
//     int x = 4;
//     int y = 2;
    
//     UpdateIfGreater(x, y);
    
//     // cout << y;
    //return 0;
//}