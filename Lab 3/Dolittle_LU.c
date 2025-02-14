// C program for matrix factorization using Doolittle LU Decomposition  
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float sum, a[10][10], u[10][10] = {0}, l[10][10] = {0};

    // Input matrix size
    printf("Enter the dimension of the matrix:\n");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Initialize L and U matrices
    for (i = 0; i < n; i++) {
        l[i][i] = 1;  // Diagonal elements of L are 1
    }

    // LU Decomposition
    for (j = 0; j < n; j++) {
        for (i = 0; i <= j; i++) {  // Upper triangular matrix U
            sum = 0;
            for (k = 0; k < i; k++) {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
        }

        for (i = j + 1; i < n; i++) {  // Lower triangular matrix L
            sum = 0;
            for (k = 0; k < j; k++) {
                sum += l[i][k] * u[k][j];
            }
            l[i][j] = (a[i][j] - sum) / u[j][j];
        }
    }

    // Print L matrix
    printf("\n**************** L Matrix ************\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%.2f", l[i][j]);
        }
        printf("\n");
    }

    // Print U matrix
    printf("\n**************** U Matrix ************\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%.2f", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}
