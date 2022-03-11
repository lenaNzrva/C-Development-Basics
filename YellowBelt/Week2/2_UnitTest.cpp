#include <iostream>

using namespace std;

int Linear(double b)
{
    if (b != 0){return 1;}
    
    return 0;
}

int Discriminant (double a, double b, double c)
{
    double D = b*b - 4*a*c;
    if (D > 0){return 2;}
    else if (D == 0){return 1;}

    return 0;
};

int Square(double a, double b, double c)
{
    if (b == 0 && c == 0){return 1;}
    else if (b == 0){return 2;}
    else if (c == 0){return 1;}

    return Discriminant(a,b,c);
};

int GetDistinctRealRootCount(double a, double b, double c)
{
    if (a==0){return Linear(b);}

    return Square(a,b,c);
}

int main()
{
    cout << GetDistinctRealRootCount(0, -30,25) << endl;
    return 0;
}