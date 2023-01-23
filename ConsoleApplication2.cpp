#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
private:
    int size;
    Element* matrix;
    int numNonZero;
public:
    SparseMatrix(int size) {
        this->size = size;
        matrix = new Element[size];
        numNonZero = 0;
    }

    void insert(int row, int col, int val) {
        if (val != 0) {
            matrix[numNonZero].row = row;
            matrix[numNonZero].col = col;
            matrix[numNonZero].val = val;
            numNonZero++;
        }
    }

    void printMatrix() {
        for (int i = 0; i < numNonZero; i++) {
            cout << "(" << matrix[i].row << ", " << matrix[i].col << ", " << matrix[i].val << ") ";
        }
        cout << endl;
    }
};

int main() {
    SparseMatrix m(5);
    m.insert(0, 0, 1);
    m.insert(0, 1, 15);
    m.insert(1, 2, 55);
    m.insert(2, 2, 14);
    m.insert(3, 3, 19);
    m.insert(9, 2, -79);

    m.printMatrix();

    return 0;
}
