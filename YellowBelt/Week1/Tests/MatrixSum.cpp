#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;

class Matrix
{   
public:
    Matrix(int num_rows=0, int num_cols=0)
    {
        ChangeM(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols)
    {
        ChangeM(num_rows, num_cols);
    }

    int At(int i, int j) const
    {
        // cout << i << ' ' << M.size() << ' ' << j << ' ' << M[0].size() << endl;
        if (i >= M.size() || j >= M[0].size()){throw out_of_range("");}
        else{return M[i][j];}  
    }

    int& At(int i, int j)
    {
        // cout << i << ' ' << M.size() << ' ' << j << ' ' << M[0].size() << endl;
        if (i >= M.size() || j >= M[0].size()){throw out_of_range("");}
        else
        {
            vector<vector<int>>& a = M;
            vector<int>& b = a[i];
            int& c = b[j];

            return c;
        }
    }

    int GetNumRows () const
    {
        return M.size();
    }

    int GetNumColumns () const
    {
        if (M.size() == 0)
        {
            return 0;
        }
        return M[0].size();
    }
private: 
    vector<vector<int>> M;

    void ChangeM(int num_rows, int num_cols)
    {
        if (num_rows<0 || num_cols<0){throw out_of_range("");}
        else if (num_rows==0 || num_cols==0)
        {
            M.clear();
        }
        else
        {
            M.clear();
            vector<int> intermediate(num_cols, 0); 

            for (int i=0; i<num_rows; ++i){M.push_back(intermediate);}

            // cout << M.size() << "X" << M[0].size() << endl;
        }
    }
};

Matrix operator+ (const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.GetNumColumns() == rhs.GetNumColumns() && lhs.GetNumRows()==rhs.GetNumRows())
    {
        Matrix M(lhs.GetNumRows(), lhs.GetNumColumns());

        for (int i=0; i<lhs.GetNumRows(); ++i)
        {
            for (int j=0; j<lhs.GetNumColumns(); ++j){M.At(i,j) = lhs.At(i,j)+rhs.At(i,j);}
        }

        return M;
    }
    else
    {
        throw invalid_argument("");
    }
}
istream& operator>> (istream& stream, Matrix& object)
{
    int num_rows, num_cols, number;
    stream >> num_rows;
    stream.ignore(1);
    stream >> num_cols;

    object.Reset(num_rows, num_cols);
    for (int i=0; i<num_rows; ++i)
    {
        for (int j=0; j<num_cols; ++j)
        {
            stream >> number;
            object.At(i,j) = number;
        }
    }

    return stream;
}
ostream& operator<< (ostream& stream, Matrix object)
{
    stream << object.GetNumRows() << ' ' << object.GetNumColumns() << endl;
    for (int i=0; i<object.GetNumRows(); ++i)
    {
        for (int j=0; j<object.GetNumColumns(); ++j)
        {
            if (j>0){stream << ' ' << object.At(i,j);}
            else{stream << object.At(i,j);}
        }
        stream << endl;
    }

    return stream;
}
bool operator== (const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.GetNumColumns() == rhs.GetNumColumns() && lhs.GetNumRows()==rhs.GetNumRows())
    {
        if (lhs.GetNumColumns()==0){return true;}
        else
        {
            int count = 0;
            for (int i=0; i<lhs.GetNumRows(); ++i)
            {
                for (int j=0; j<lhs.GetNumColumns(); ++j){count += (lhs.At(i,j)==rhs.At(i,j));}
            }

            if (count == (lhs.GetNumColumns()*lhs.GetNumRows())){return true;}
            else{return false;}
        }

    }else{return false;}
}



int main() 
{
    Matrix one, two;

    cin >> one >> two;

    cout << endl << one+two;

}