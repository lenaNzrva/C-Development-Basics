#include <iostream>

using namespace std;

class Rational {
public:
//   Rational();
  Rational(int numerator=0, int denominator=1)
  {
      N = numerator;
      D = denominator;

      if (N!=0 and D!=0)
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
      return Rational(1,2);
  }

int main() 
{
    
    return 0;
}