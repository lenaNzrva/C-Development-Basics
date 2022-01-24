#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Rational {
public:
//   Rational();
  Rational(int numerator=0, int denominator=1)
  {
      N = numerator;
      D = denominator;

    //   if (N==int(N) && D==int(D))

      if (N!=0 && D!=0)
      {
        int nod = NOD(N, D);
        if (nod != 1){N=numerator/nod; D=denominator/nod;}
      }

      if (N>0 && D<0){N*=-1; D*=-1;}
      else if (N<0 && D<0){N*=-1; D*=-1;}
      if(N==0){D=1;}
  }

  int Numerator() const
  {
      return N;
  }
  int Denominator() const
  {
      return D;
  }

private:
    int N, D;

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
};

Rational operator+ (const Rational& lhs, const Rational& rhs)
  {
      int lhsNewN, rhsNewN;
      if (lhs.Denominator() != rhs.Denominator())
      {
          lhsNewN = lhs.Numerator()*rhs.Denominator();
          rhsNewN = rhs.Numerator()*lhs.Denominator();
          return Rational(lhsNewN+rhsNewN, rhs.Denominator()*lhs.Denominator());
      }else{return Rational(lhs.Numerator()+rhs.Numerator(), lhs.Denominator());}
  }

Rational operator- (const Rational& lhs, const Rational& rhs)
{
    int lhsNewN, rhsNewN;
    if (lhs.Denominator() != rhs.Denominator())
    {
        lhsNewN = lhs.Numerator()*rhs.Denominator();
        rhsNewN = rhs.Numerator()*lhs.Denominator();
        return Rational(lhsNewN-rhsNewN, rhs.Denominator()*lhs.Denominator());
    }else{return Rational(lhs.Numerator()-rhs.Numerator(), lhs.Denominator());}
}

bool operator== (const Rational& lhs, const Rational& rhs)
{
    int lhsNewN, rhsNewN;
    if (lhs.Denominator() != rhs.Denominator())
    {
        lhsNewN = lhs.Numerator()*rhs.Denominator();
        rhsNewN = rhs.Numerator()*lhs.Denominator();
        return lhsNewN==rhsNewN;
    }else{return lhs.Numerator()==rhs.Numerator();}
}

Rational operator* (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator/ (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

ostream& operator<< (ostream& stream,const Rational& object)
{
    stream << object.Numerator()<<'/'<<object.Denominator();
    return stream;
}

istream& operator>> (istream& stream, Rational& object)
{
    string test;
    getline(stream, test, '/');
    cout << test << endl;

    return stream;
}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}