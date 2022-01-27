#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Rational {
public:
  Rational(int numerator=0, int denominator=1)
  {
      N = numerator;
      D = denominator;

      if (N!=0 && D!=0)
      {
        int nod = NOD(N, D);
        if (nod != 1){N=numerator/nod; D=denominator/nod;}
      }
      else if(D == 0)
      {
          throw invalid_argument("");
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
    if (rhs.Numerator()==0 || rhs.Denominator()==0)
    {
        throw domain_error("");
    }
    return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

ostream& operator<< (ostream& stream,const Rational& object)
{
    stream << object.Numerator()<<'/'<<object.Denominator();
    return stream;
}

istream& operator>> (istream& stream, Rational& object)
{
    string t1, t2;
    string test, test2;
    if (stream)
    {
        getline(stream, t1, '/');
        getline(stream, t2, ' ');

    }

    if (t1.size()!=0 && t2.size()!=0)
    {
        for (int i=0; i<t1.size(); ++i)
        {
            if (i==0 && (t1[i]=='-' || t1[i]=='+'))
            {
                test += t1[i];
            }
            else if (isdigit(t1[i]))
            {
                test += t1[i];
            }
            else
            {
                object;
                return stream;
            }
        }

        for (int i=0; i<t2.size(); ++i)
        {
            if (i==0 && (t2[i]=='-' || t2[i]=='+'))
            {
                test2 += t2[i];
            }
            else if (isdigit(t2[i]))
            {
                test2 += t2[i];
            }
            else
            {
                object;
                return stream;
            }
        }

        object = {stoi(test), stoi(test2)};
    }

    
    else
    {
        object;
    }

    return stream;

}

bool operator< (const Rational& lhs, const Rational& rhs)
{
    int lhsNewN, rhsNewN;
    if (lhs.Denominator() != rhs.Denominator())
    {
        lhsNewN = lhs.Numerator()*rhs.Denominator();
        rhsNewN = rhs.Numerator()*lhs.Denominator();
        return lhsNewN<rhsNewN;
    }else{return lhs.Numerator()<rhs.Numerator();}

}

bool operator> (const Rational& lhs, const Rational& rhs)
{
    int lhsNewN, rhsNewN;
    if (lhs.Denominator() != rhs.Denominator())
    {
        lhsNewN = lhs.Numerator()*rhs.Denominator();
        rhsNewN = rhs.Numerator()*lhs.Denominator();
        return lhsNewN>rhsNewN;
    }else{return lhs.Numerator()>rhs.Numerator();}

}

int main() {
    // try {
    //     Rational r(1, 0);
    //     cout << "Doesn't throw in case of zero denominator" << endl;
    //     return 1;
    // } catch (invalid_argument&) {
    // }

    // try {
    //     auto x = Rational(1, 2) / Rational(0, 1);
    //     cout << "Doesn't throw in case of division by zero" << endl;
    //     return 2;
    // } catch (domain_error&) {
    // }

    // cout << "OK" << endl;
    return 0;
}