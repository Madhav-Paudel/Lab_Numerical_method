// C program fo solving Poison Equation by using finite difference method 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define g(x, y) (2 * (x) * (x) * (y) * (y)) 

int main() {
    int n, i, j, k, converged;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10], tl, tr, tu, tb, h;

    printf("Enter Dimension of plate: ");
    scanf("%d", &n);
    printf("Enter Grid Spacing (h): ");
    scanf("%f", &h);
    printf("Enter Temperatures at Left, Right, Bottom & Upper Boundaries: ");
    scanf("%f %f %f %f", &tl, &tr, &tb, &tu);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
        a[i][i] = -4; 
    }

    for (i = 0; i < n; i++) {
        if (i > 0) a[i][i - 1] = 1; 
        if (i < n - 1) a[i][i + 1] = 1; 
    }

    k = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            b[k++] = h * h * g(i, j);
        }
    }

    k = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i - 1 == 0) b[k] -= tl;
            if (i + 1 == n) b[k] -= tr;
            if (j - 1 == 0) b[k] -= tb;
            if (j + 1 == n) b[k] -= tu;
            k++;
        }
    }

    // --- Gauss-Seidel Iteration ---
    printf("Enter Accuracy Limit: ");
    scanf("%f", &error);

    for (i = 0; i < n; i++) new_x[i] = 0;

    while (1) {
        converged = 1; 
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * new_x[j];
                }
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i];

            E[i] = fabs((new_x[i] - old_x[i]) / (fabs(new_x[i]) + 1e-6)); 
            if (E[i] > error) converged = 0; 
        }

        if (converged) break; 
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, new_x[i]);
    }

    return 0;
}
