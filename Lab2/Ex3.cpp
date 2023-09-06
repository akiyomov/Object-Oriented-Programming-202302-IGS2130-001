#include <iostream>

using namespace std;

// Function to input elements into a matrix
void MatInput(int* mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i * cols + j];
        }
    }
}

// Function to multiply two matrices
void MatMul(int* mat1, int* mat2, int* matMul, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            matMul[i * cols2 + j] = 0;
            for (int k = 0; k < cols1; k++) {
                matMul[i * cols2 + j] += mat1[i * cols1 + k] * mat2[k * cols2 + j];
            }
        }
    }
}

// Function to display a matrix
void MatDisplay(int* mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i * cols + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row1 = 3, col1 = 3;  // Dimensions of the first matrix
    int col2 = 3;           // Number of columns in the second matrix
    int* mat1 = new int[row1 * col1];
    int* mat2 = new int[col1 * col2];
    int* matMul = new int[row1 * col2];

    cout << "Enter elements in 1st matrix of size " << row1 << 'x' << col1 << ":\n";
    MatInput(mat1, row1, col1);

    cout << "Enter elements in 2nd matrix of size " << col1 << 'x' << col2 << ":\n";
    MatInput(mat2, col1, col2);

    MatMul(mat1, mat2, matMul, row1, col1, col2);

    cout << "Multiplication of two matrices: \n";
    MatDisplay(matMul, row1, col2);

    // Deallocate memory
    delete[] mat1;
    delete[] mat2;
    delete[] matMul;

    return 0;
}
