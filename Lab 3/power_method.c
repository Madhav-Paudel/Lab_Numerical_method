// C program for calculating the largest eigenvalue and eigenvector using the Power Method
#include <stdio.h>
#include <math.h>

#define MAX_ITER 100  

int main() {
    int n, i, j, iter;
    float epsilon, max_value, a[10][10], x[10], y[10], nx[10], error;

    printf("Enter the dimension of the matrix:\n");
    scanf("%d", &n);

    printf("Enter the matrix coefficients row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the initial guess vector:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the accuracy limit:\n");
    scanf("%f", &epsilon);

    for (iter = 0; iter < MAX_ITER; iter++) {
        for (i = 0; i < n; i++) {
            y[i] = 0;
            for (j = 0; j < n; j++) {
                y[i] += a[i][j] * x[j];
            }
        }

        max_value = fabs(y[0]);
        for (i = 1; i < n; i++) {
            if (fabs(y[i]) > max_value) {
                max_value = fabs(y[i]);
            }
        }

        for (i = 0; i < n; i++) {
            nx[i] = y[i] / max_value;
        }

        error = 0;
        for (i = 0; i < n; i++) {
            error += fabs(nx[i] - x[i]);
        }

        if (error < epsilon) {
            break;
        }

        for (i = 0; i < n; i++) {
            x[i] = nx[i];
        }
    }

    printf("\nLargest Eigenvalue: %f\n", max_value);
    printf("Corresponding Eigenvector:\n");
    for (i = 0; i < n; i++) {
        printf("%f\t", nx[i]);
    }

    return 0;
}
