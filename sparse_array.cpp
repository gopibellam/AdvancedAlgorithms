#include <iostream>
#include <vector>
using namespace std;
class SparseMatrix 
{
    int n;
    int m;
    vector<int> row_i;
    vector<int> col_i;
    vector<int> val;
    public:
    SparseMatrix(int rows, int cols) 
    {
        n = rows;
        m = cols;
    }
    void insertElement(int row, int col, int vall) 
    {
        if (row < 0||row >=n ||col < 0||col >= m) 
        {
            cout << "Invalid indices"<<endl;
            return;
        }
        row_i.push_back(row);
        col_i.push_back(col);
        val.push_back(vall);
    }
    void printSparseMatrix() 
    {
        cout <<"Row: ";
        for (size_t i = 0; i < val.size(); i++) 
        {
            cout<<row_i[i]<<" ";
        }
        cout <<endl<<"Column: ";
        for (size_t i = 0; i < val.size(); i++) 
        {
            cout<<col_i[i]<<" ";
        }
        cout <<endl<<"Value: ";
        for (size_t i = 0; i < val.size(); i++) 
        {
            cout<<val[i]<<" ";
        }
    }
};

int main() {
    SparseMatrix s(3, 3);
    s.insertElement(0, 0, 3);
    s.insertElement(1, 2, 5);
    s.insertElement(2, 1, 1);
    s.insertElement(1, 0, 2);
    s.insertElement(2, 1, 9);
    s.insertElement(2, 2, 8);
    s.printSparseMatrix();
    return 0;
}
