#include <iostream>
#include <tuple>
#include <sstream>
using namespace std;


class Rational {
public:
    Rational()
    {
        N = 0;
        D = 1;
    }   
    Rational(int numerator, int denominator)
    {
        N = numerator;
        D = denominator;

        if (N == 0){D = 1;}
        else
        {
            reduction(N, D);
            minus(N,D);
        }
    }

    int Numerator() const {return N;}
    int Denominator() const {return D;}

private:
    int N;
    int D;

    void reduction(int &N, int &D)
    {
        int nod = NOD(N,D);

        N /= nod;
        D /= nod;
    }

    int NOD(int A, int B)
    {
        if (A > B)
        {
            int C = A%B;
            while (C != 0)
            {
                A = B;
                B = C;
                C = A%B;
            }

            return B;
        }else if (A < B)
        {
            int C = B%A;
            while (C != 0)
            {
                B = A;
                A = C;
                C = B%A;
            }
            return A;
        }else
        {
            return A;
        }
    }

    void minus(int &N, int &D)
    {
        if ((D < 0 && N > 0) || (D < 0 && N < 0))
        {
            N *= -1;
            D *= -1;
        }
    }
};


template <typename LHS, typename RHS>
void AssertEqual(LHS const &lhs, RHS const &rhs)
{
    if(lhs!=rhs)
    {
        stringstream os;
        os << lhs << " != " << rhs;
        throw runtime_error(os.str());
    }
}

void TestAll()
{
    {
        Rational R;
        stringstream ClassAnsw;
        string GT = "0/1";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
    }
    {
        Rational R(2,6);
        stringstream ClassAnsw;
        string GT = "1/3";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
    }
    {
        Rational R(48,36);
        stringstream ClassAnsw;
        string GT = "4/3";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
    }
    {
        Rational R(-1,3);
        stringstream ClassAnsw;
        string GT = "-1/3";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
    }
    {
        Rational R(1,-3);
        stringstream ClassAnsw;
        string GT = "-1/3";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
    }
    {
        Rational R(-1,-3);
        stringstream ClassAnsw;
        string GT = "1/3";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
    }
    {
        Rational R(0,732);
        stringstream ClassAnsw;
        string GT = "0/1";
        ClassAnsw << R.Numerator() << "/" << R.Denominator();
        AssertEqual(GT, ClassAnsw.str());
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