#include <iostream>
#include <vector>
using namespace std;
struct SparseElement {
    int row;
    int col;
    int value;
    SparseElement* next;
    SparseElement(int r, int c, int v) 
    {
        row = r;
        col = c;
        value = v;
        next = nullptr;
    }
};

class SparseMatrix {
public:
    int numRows;
    int numCols;
    SparseElement** rr;
    SparseMatrix(int rows, int cols)
    {
        numRows = rows;
        numCols = cols;
        rr = new SparseElement*[numRows];
        for (int i = 0; i < numRows; i++) 
        {
            rr[i] = nullptr;
        }
    }
    void insertElement(int row, int col, int value) 
    {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) 
        {
            cout << "Invalid indices" <<endl;
            return;
        }
        SparseElement* newElement = new SparseElement(row, col, value);
        if (rr[row] == nullptr) 
        {
            rr[row] = newElement;
        } 
        else 
        {
            newElement->next = rr[row];
            rr[row] = newElement;
        }
    }
    void printSparseMatrix() 
    {
       for (int i = 0; i < numRows; i++) 
        {
            SparseElement* current = rr[i];
            while (current != nullptr) 
            {
                cout << i << " " << current->col << " " << current->value;
                if (current->next != nullptr) 
                {
                    cout << " -> ";
                }
                current = current->next;
            }
            if (i < numRows - 1) 
            {
                cout << " -> ";
            }
        }
    }

};

int main() {
    int numRows, numCols;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;
    SparseMatrix s(numRows,numCols);
    vector<vector<int>> matrix(numRows, vector<int>(numCols));
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
            cin>> matrix[i][j];
            if(matrix[i][j]!=0)
            {
                s.insertElement(i, j, matrix[i][j]);
            }
        }
    }
    cout << "Sparse Matrix:" << endl;
    s.printSparseMatrix();
    return 0;
}
