 // C program for Jacobi Iteration Method 
#include <stdio.h>
#include <math.h>

int main() {
    int i, j, n, k, max_iterations = 100;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10], tolerance;

    printf("Enter the number of equations (dimension of system):\n");
    scanf("%d", &n);

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

    printf("Enter the accuracy tolerance:\n");
    scanf("%f", &tolerance);

    for (i = 0; i < n; i++) {
        old_x[i] = 0.0;
    }

    for (k = 0; k < max_iterations; k++) {
        int converged = 1;
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * old_x[j];
                }
            }
            new_x[i] = sum / a[i][i];

            // Compute error
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);

            // Check if solution is within the error tolerance
            if (E[i] > tolerance) {
                converged = 0;
            }
        }

        // Update old values
        for (i = 0; i < n; i++) {
            old_x[i] = new_x[i];
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
