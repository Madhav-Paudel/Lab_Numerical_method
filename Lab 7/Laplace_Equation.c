// C program fo solving elliptic Partial differential Equation by using finite difference method 
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>   

int main() {
    int n, i, j;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10], tl, tr, tu, tb;

    printf("Enter Dimension of plate\n");
    scanf("%d", &n);

    printf("Enter temperatures at left, right, bottom & upper part of plate\n");
    scanf("%f%f%f%f", &tl, &tr, &tb, &tu);

    // Initialize coefficient matrix 'a' and RHS vector 'b'
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0; 
        }
    }

    for (i = 0; i < n; i++) {
        a[i][i] = -4; 
        if (i > 0) a[i][i - 1] = 1; 
        if (i < n - 1) a[i][i + 1] = 1;
    }

    for (i = 0; i < n; i++) {
        b[i] = 0;
    }

    // Apply boundary conditions to vector 'b'
    for (i = 0; i < n; i++) {
        if (i == 0) {
            b[i] -= tl + tb; 
        }
        if (i == n - 1) {
            b[i] -= tr + tu; 
        }
        if (i > 0 && i < n - 1) {
            b[i] -= tb + tu;  
        }
    }

    for (i = 0; i < n; i++) {
        new_x[i] = 0;
    }

    printf("Enter Accuracy Limit\n");
    scanf("%f", &error);

    // Gauss-Seidel Iteration
    while (1) {
        int converged = 1; 

        for (i = 0; i < n; i++) {
            sum = b[i];

            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum = sum - a[i][j] * new_x[j];
                }
            }

            old_x[i] = new_x[i]; 
            new_x[i] = sum / a[i][i];

            if (fabs(new_x[i] - old_x[i]) / fabs(new_x[i]) > error) {
                converged = 0; 
            }
        }

        if (converged) {
            break;
        }
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d=%.2f\n", i + 1, new_x[i]);
    }

    return 0;
}
