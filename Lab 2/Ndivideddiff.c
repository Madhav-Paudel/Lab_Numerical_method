// c program for newton's divided difference 
#include <stdio.h>

int main() {
    int n, i, j;
    float v = 0, p, xv, x[10], fx[10], a[10];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xv);

    for (i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i = %d: ", i);
        scanf("%f %f", &x[i], &fx[i]);
        a[i] = fx[i];  // Initializing divided difference table
    }

    // Constructing Newton's Divided Difference Table
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - i]);
        }
    }

    // Interpolation Calculation
    for (i = 0; i < n; i++) {
        p = 1;
        for (j = 0; j < i; j++) {  // Fixing index range
            p *= (xv - x[j]);
        }
        v += a[i] * p;
    }

    printf("Interpolated value at x = %.3f is %.3f\n", xv, v);
    return 0;
}
