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

// Function to add two matrices
void MatAdd(int* mat1, int* mat2, int* matAdd, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matAdd[i * cols + j] = mat1[i * cols + j] + mat2[i * cols + j];
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
    int row, col;
    
    cout << "Enter size of matrix (row, col): ";
    cin >> row >> col;

    // Allocate memory for matrices
    int* mat1 = new int[row * col];
    int* mat2 = new int[row * col];
    int* matAdd = new int[row * col];

    cout << "Enter elements in 1st matrix of size " << row << 'x' << col << ":\n";
    MatInput(mat1, row, col);
    cout << "Enter elements in 2nd matrix of size " << row << 'x' << col << ":\n";
    MatInput(mat2, row, col);

    MatAdd(mat1, mat2, matAdd, row, col);

    cout << "Sum of two matrices: \n";
    MatDisplay(matAdd, row, col);

    // Deallocate memory
    delete[] mat1;
    delete[] mat2;
    delete[] matAdd;

    return 0;
}
