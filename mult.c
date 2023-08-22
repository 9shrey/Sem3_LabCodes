#include <stdio.h>

void readMatrix(int matrix[][100], int rows, int cols) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][100], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int resultMatrix[][100], int matrix1[][100], int matrix2[][100], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[100][100], matrix2[100][100], resultMatrix[100][100];
    int rows1, cols1, rows2, cols2;

    printf("Enter the dimensions of the first matrix (rows columns): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the dimensions of the second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible due to incompatible dimensions.\n");
        return 1;
    }

    printf("Enter the elements of the first matrix:\n");
    readMatrix(matrix1, rows1, cols1);

    printf("Enter the elements of the second matrix:\n");
    readMatrix(matrix2, rows2, cols2);

    multiplyMatrices(resultMatrix, matrix1, matrix2, rows1, cols1, cols2);

    printf("Product of the matrices:\n");
    displayMatrix(resultMatrix, rows1, cols2);

    return 0;
}
