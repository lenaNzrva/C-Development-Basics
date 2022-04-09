#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool IsPalindrome(const string& s)
{
    stringstream ss;
    for (int i = s.size()-1; i >= 0; --i)
    {
        ss << s[i];
    }

    return s == ss.str();
}

template <typename LHS, typename RHS, typename word>
void AssertEqual(LHS const &lhs, RHS const &rhs, word const &w)
{
    if(lhs!=rhs)
    {
        stringstream os;
        os << lhs << " != " << rhs << " (" << w << ")";
        throw runtime_error(os.str());
    }
}

void TestAll()
{
    {
        string s = "";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "X X";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "X";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "lena";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "madam";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "12eg[]][ge21";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "987yehjk]'``";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "lalalalala";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "   ";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "madam1";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "1madam";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "1madam1";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "maddam";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "ma1dd2am";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aacaa";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aaccaa";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aaaaa";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aaaa";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aa";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "abcde";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "asomea";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "abc cba";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "abc abc";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "pls pass this test aaaaa";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "   aaa  aaa";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    } 
    {
        string s = "1111";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    } 
    {
        string s = "!!!!";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    } 
    {
        string s = "abc abc";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "abc   cba";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aba  aba";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = " aaa  aaa   ";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "  aaa  aaa  ";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "aabba";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "abbaa";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "?";
        bool answ = IsPalindrome(s);
        bool GT = 1;
        AssertEqual(GT, answ, s);
    }

    {
        string s = "qweY_Yew";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }    
    {
        string s = "weY_Yewq";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "ZweY_YewX";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "123ab321";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "1 23 321";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
    }
    {
        string s = "1 23 3 21";
        bool answ = IsPalindrome(s);
        bool GT = 0;
        AssertEqual(GT, answ, s);
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