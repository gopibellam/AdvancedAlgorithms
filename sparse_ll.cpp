#include <iostream>
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
    SparseMatrix s(3,3);
    s.insertElement(0, 0, 3);
    s.insertElement(1, 2, 5);
    s.insertElement(2, 1, 1);
    s.insertElement(1, 0, 2);
    s.insertElement(2, 1, 9);
    s.insertElement(2, 2, 8);
    s.printSparseMatrix();
    return 0;
}
