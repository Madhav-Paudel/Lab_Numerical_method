// C program for Gauss-Seidel Method 
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k, max_iterations = 100;
    float sum, error, a[10][10], b[10], new_x[10], old_x[10], tolerance;

    // Input system dimension
    printf("Enter the number of equations (dimension of system):\n");
    scanf("%d", &n);

    // Input coefficient matrix
    printf("Enter coefficients row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter RHS vector:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Input accuracy limit
    printf("Enter the accuracy tolerance:\n");
    scanf("%f", &tolerance);

    for (i = 0; i < n; i++) {
        new_x[i] = 0.0;
    }

    for (k = 0; k < max_iterations; k++) {
        int converged = 1; 

        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * new_x[j]; 
                }
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i];

            if (fabs(new_x[i] - old_x[i]) / fabs(new_x[i]) > tolerance) {
                converged = 0;
            }
        }

        if (converged) {
            break;
        }
    }

    // Print final solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6f\t", i + 1, new_x[i]);
    }

    return 0;
}
