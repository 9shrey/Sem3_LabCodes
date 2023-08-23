#include <stdio.h>
#include <stdlib.h>

void Mult(int **a, int **b, int **c, int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

void Read(int **a, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
}

void FreeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **a, **b, **c, row1, col1, row2, col2;

    printf("Enter the dimensions of Matrix 1: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the dimensions of Matrix 2: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Cannot Multiply!\n");
        exit(0);
    }

    a = (int **) malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
        a[i] = (int *) malloc(col1 * sizeof(int));

    b = (int **) malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
        b[i] = (int *) malloc(col2 * sizeof(int));

    c = (int **) malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
        c[i] = (int *) malloc(col2 * sizeof(int));

    printf("Enter elements of Matrix 1:\n");
    Read(a, row1, col1);

    printf("Enter elements of Matrix 2:\n");
    Read(b, row2, col2);

    Mult(a, b, c, row1, col1, col2);

    printf("Matrix A * Matrix B =\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }

    FreeMatrix(a, row1);
    FreeMatrix(b, row2);
    FreeMatrix(c, row1);

    return 0;
}

