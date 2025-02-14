// C program for Gauss-Jordan Method
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, k, j;
    float pivot, term, a[10][11]; 

    printf("Enter the dimension of the system of equations:\n");
    scanf("%d", &n);

    printf("Enter coefficients of the augmented matrix row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (k = 0; k < n; k++) {
        pivot = a[k][k];

        if (fabs(pivot) < 0.000001) {
            printf("Method failed due to zero pivot element.\n");
            return 1;
        }

        // Make the pivot element 1 by dividing the row
        for (j = 0; j < n + 1; j++) {
            a[k][j] = a[k][j] / pivot;
        }

        // Make other elements in column k zero
        for (i = 0; i < n; i++) {
            if (i != k) {
                term = a[i][k];
                for (j = 0; j < n + 1; j++) {
                    a[i][j] = a[i][j] - a[k][j] * term;
                }
            }
        }
    }

    // Printing the solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\t", i + 1, a[i][n]);  
    }

    return 0;
}
