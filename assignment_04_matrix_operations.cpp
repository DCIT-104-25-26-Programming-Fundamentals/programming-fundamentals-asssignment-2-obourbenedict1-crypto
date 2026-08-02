// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// ---------------------------------------------------------------------------
// Helper: read a matrix from the user
// ---------------------------------------------------------------------------
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// ---------------------------------------------------------------------------
// Helper: display a matrix in a neat grid
// ---------------------------------------------------------------------------
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// ---------------------------------------------------------------------------
// PART A — Transpose
// ---------------------------------------------------------------------------
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// ---------------------------------------------------------------------------
// PART B — Add two matrices (same dimensions)
// ---------------------------------------------------------------------------
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// ---------------------------------------------------------------------------
// PART C — Multiply two matrices (A is M x N, B is N x P, result is M x P)
// ---------------------------------------------------------------------------
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// ---------------------------------------------------------------------------
// Menu-driven main
// ---------------------------------------------------------------------------
int main() {
    int choice;

    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter values for the matrix:" << endl;
        readMatrix(matrix, rows, cols);

        transposeMatrix(matrix, rows, cols, result);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);
        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter values for Matrix A:" << endl;
        readMatrix(a, rows, cols);
        cout << "\nEnter values for Matrix B:" << endl;
        readMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols, result);

        cout << "\nMatrix A:" << endl;
        printMatrix(a, rows, cols);
        cout << "\nMatrix B:" << endl;
        printMatrix(b, rows, cols);
        cout << "\nSum (A + B):" << endl;
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        int m, n, n2, p;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A (N): ";
        cin >> n;

        cout << "\nEnter values for Matrix A:" << endl;
        readMatrix(a, m, n);

        cout << "\nEnter rows of Matrix B (must equal N = " << n << "): ";
        cin >> n2;
        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        if (n2 != n) {
            cout << "Error: Number of columns in A must equal number of rows in B."
                 << endl;
            return 0;
        }

        cout << "\nEnter values for Matrix B:" << endl;
        readMatrix(b, n2, p);

        multiplyMatrices(a, b, m, n, p, result);

        cout << "\nMatrix A:" << endl;
        printMatrix(a, m, n);
        cout << "\nMatrix B:" << endl;
        printMatrix(b, n2, p);
        cout << "\nProduct (A x B):" << endl;
        printMatrix(result, m, p);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
