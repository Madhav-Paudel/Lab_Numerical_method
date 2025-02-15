// C program to solve Ordinary Differential Equation using Taylor series method
#include <stdio.h>
#include <math.h>

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main() {
    float x, x0, yx0, yx, fdy, sdy, tdy;

    // Input initial values
    printf("Enter initial values of x and y:\n");
    scanf("%f %f", &x0, &yx0);
    
    // Input the x value where function needs to be evaluated
    printf("Enter x at which function is to be evaluated:\n");
    scanf("%f", &x);
    
    // First derivative: dy/dx = x^2 + y^2
    fdy = (x0 * x0) + (yx0 * yx0);

    // Second derivative: d²y/dx² = 2x + 2y * dy/dx
    sdy = (2 * x0) + (2 * yx0 * fdy);

    // Third derivative: d³y/dx³ = 2 + 2y * d²y/dx² + 2(dy/dx)
    tdy = (2 + (2 * yx0 * sdy) + (2 * fdy));

    // Taylor Series Expansion
    yx = yx0 + ((x - x0) * fdy) 
              + (((x - x0) * (x - x0) * sdy) / fact(2)) 
              + (((x - x0) * (x - x0) * (x - x0) * tdy) / fact(3));

    // Output the result
    printf("Function value at x = %f is %f\n", x, yx);

    return 0;
}
