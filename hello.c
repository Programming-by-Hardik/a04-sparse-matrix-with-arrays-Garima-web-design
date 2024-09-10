// sparse_matrix_assignment.c
// This program represents a sparse matrix using a 2D array in C and includes test cases.

#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of non-zero elements in the sparse matrix
#define N 4      // Number of columns in the original matrix (modifiable)

// Function prototypes
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols);
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount);
bool testCreateSparseMatrix();
bool testPrintSparseMatrix();

int main() {
    // Run test cases
    if (testCreateSparseMatrix()) {
        printf("testCreateSparseMatrix PASSED\n");
    } else {
        printf("testCreateSparseMatrix FAILED\n");
    }

    if (testPrintSparseMatrix()) {
        printf("testPrintSparseMatrix PASSED\n");
    } else {
        printf("testPrintSparseMatrix FAILED\n");
    }

    return 0;
}

// Function to convert a matrix into sparse matrix format
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols) {
    //WRITE THE FUNCTION DESCRIPTION HERE
  void convertToCSR(int rows, int cols, int matrix[rows][cols], 
                   int **values, int **col_indices, int **row_ptrs, int *nnz) {
    int count = 0;

    // Calculate the number of non-zero elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    // Allocate memory for CSR arrays
    *values = (int *)malloc(count * sizeof(int));
    *col_indices = (int *)malloc(count * sizeof(int));
    *row_ptrs = (int *)malloc((rows + 1) * sizeof(int));

    // Fill the row_ptrs array
    int index = 0;
    (*row_ptrs)[0] = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                (*values)[index] = matrix[i][j];
                (*col_indices)[index] = j;
                index++;
            }
        }
        (*row_ptrs)[i + 1] = index;
    }

    *nnz = count; // Number of non-zero elements
}

//converts an original matrix into its sparse matrix representation.
//the sparse matrix format is a 2D array where each row represents a non-zero element in the original matrix.
//the first row of the sparse matrix specifies the dimensions of the original matrix and the number of non-zero elements.








}

// Function to print sparse matrix representation
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount) {
    //WRITE THE FUNCTION DESCRIPTION HERE
   void printCSR(int rows, int *values, int *col_indices, int *row_ptrs, int nnz) {
    printf("Values: ");
    for (int i = 0; i < nnz; ++i) {
        printf("%d ", values[i]);
    }
    printf("\n");

    printf("Column Indices: ");
    for (int i = 0; i < nnz; ++i) {
        printf("%d ", col_indices[i]);
    }
    printf("\n");

    printf("Row Pointers: ");
    for (int i = 0; i <= rows; ++i) {
        printf("%d ", row_ptrs[i]);
    }
    printf("\n");
}


// Prints the sparse matrix in a readable format. The first row of the sparse matrix shows the dimensions of the original matrix and the number of non-zero elements, and the following rows show the position and value of each non-zero element.







}

//--------------------------------------------------------
//DON'T CHANGE THE CODE BELOW THIS!
//--------------------------------------------------------
// TEST CASES

// Test function for createSparseMatrix
bool testCreateSparseMatrix() {
    int originalMatrix[4][N] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {0, 0, 0, 5},
        {0, 2, 0, 6}
    };

    int expectedSparseMatrix[MAX][3] = {
        {4, 4, 5},   // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},   // Original matrix[0][2] = 3
        {1, 1, 4},   // Original matrix[1][1] = 4
        {2, 3, 5},   // Original matrix[2][3] = 5
        {3, 1, 2},   // Original matrix[3][1] = 2
        {3, 3, 6}    // Original matrix[3][3] = 6
    };

    int sparseMatrix[MAX][3];
    createSparseMatrix(sparseMatrix, originalMatrix, 4, N);

    // Compare the sparseMatrix with the expectedSparseMatrix
    for (int i = 0; i <= expectedSparseMatrix[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != expectedSparseMatrix[i][j]) {
                return false;  // If any value doesn't match, test fails
            }
        }
    }

    return true;  // Test passes if all values match
}

// Test function for printSparseMatrix
bool testPrintSparseMatrix() {
    // Define a sparse matrix with 5 non-zero elements
    int sparseMatrix[MAX][3] = {
        {4, 4, 5},   // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},   // Original matrix[0][2] = 3
        {1, 1, 4},   // Original matrix[1][1] = 4
        {2, 3, 5},   // Original matrix[2][3] = 5
        {3, 1, 2},   // Original matrix[3][1] = 2
        {3, 3, 6}    // Original matrix[3][3] = 6
    };

    // Simulate a successful print (visual inspection may be needed for testing this)
    printf("Expected Sparse Matrix Output:\n");
    printSparseMatrix(sparseMatrix, sparseMatrix[0][2]);

    // Since printSparseMatrix only prints the output, we assume it passes if the format is correct
    return true;
}
