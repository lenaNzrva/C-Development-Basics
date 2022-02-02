#include <iostream>
#include <vector>

using namespace std;

class Matrix
{   
public:
    Matrix(int num_rows=0, int num_cols=0)
    {
        Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols)
    {
        if (num_rows < 0 || num_cols < 0)
        {
            
        }

        M.clear();

        vector<int> intermediate(num_cols, 0); 
        for (int i=0; i<num_rows; ++i)
        {
            M.push_back(intermediate);
        }
    }

    int At(int i, int j) const
    {
        return M[i][j];
    }

    int& At(int i, int j)
    {
        vector<vector<int>>& a = M;
        vector<int>& b = a[i];
        int& c = b[j];

        return c;
    }

    int GetNumRows () const
    {
        return M.size();
    }

    int GetNumColumns () const
    {
        return M[0].size();
    }
private: 
    vector<vector<int>> M;
};

int main()
{
    Matrix name(5,5);

    return 0;
}