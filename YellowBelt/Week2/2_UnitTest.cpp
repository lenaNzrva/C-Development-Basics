#include <iostream>
#include <sstream>

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
    else if (c == 0){return 2;}

    return Discriminant(a,b,c);
};

int GetDistinctRealRootCount(double a, double b, double c)
{
    if (a==0){return Linear(b);}

    return Square(a,b,c);
}

template <typename A, typename B, typename C, typename RHS>
void AssertEqual(A a, B b, C c, RHS rhs)
{   
    auto lhs = GetDistinctRealRootCount(a,b,c);
    if (lhs != rhs)
    {
        stringstream os;
        os << a << "X^2 + (" << b << "X) + (" << c << ")" << endl << 
        lhs << "(func res) != " << rhs << "(real res)"; 
        throw runtime_error(os.str());}
}

void TestAll()
{
    // a = 0:
    {
        int a = 0;
        int b = 3;
        int c = 15;
        int answer = 1;
        AssertEqual(a,b,c,answer);
    }
    {
        int a = 0;
        int b = 4;
        int c = -16;
        int answer = 1;
        AssertEqual(a,b,c,answer);
    }
    // a = 0, b = 0:
    {
        int a = 0;
        int b = 0;
        int c = -16;
        int answer = 0;
        AssertEqual(a,b,c,answer);
    }
    // b = 0, с = 0:
    {
        int a = 4;
        int b = 0;
        int c = 0;
        int answer = 1;
        AssertEqual(a,b,c,answer);        
    }
    // b = 0:
    {
        int a = 4;
        int b = 0;
        int c = -17;
        int answer = 2;
        AssertEqual(a,b,c,answer); 
    }
    // c = 0:
    {
        int a = 1;
        int b = 1;
        int c = 0;
        int answer = 2;
        AssertEqual(a,b,c,answer);         
    }
    // D > 0:
    {
        int a = 3;
        int b = -14;
        int c = -5;
        int answer = 2;
        AssertEqual(a,b,c,answer);         
    }
    // D == 0:
    {
        int a = 3;
        int b = -18;
        int c = 27;
        int answer = 1;
        AssertEqual(a,b,c,answer);          
    }
    // D < 0:
    {
        int a = 2;
        int b = 1;
        int c = 5;
        int answer = 0;
        AssertEqual(a,b,c,answer);         
    }

}


class TestRunner 
{
public:
    template <class TestFunc>
    void RunTest(TestFunc func) 
    {
        try 
        {
            func();
            cerr << "OK" << endl;
        } 
        catch (runtime_error& e) 
        {
            ++fail_count;
            cerr << "fail: " << e.what() << endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0) 
        {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
        }
    }

private:
    int fail_count = 0;
};



int main()
{
    TestRunner runner;
    runner.RunTest(TestAll);

    return 0;
}