// write a program to do Bisection Method 
#include <stdio.h>
#include <math.h>

int a0, a1, a2, a3;  


float f(float x) {
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}

int main() {
    float xl, xm, xu, fxl, fxm, fxu, E, Era;
    int max_iterations = 100, iteration = 0;  

    // Input coefficients
    printf("Enter coefficients a3, a2, a1, and a0: ");
    scanf("%d %d %d %d", &a3, &a2, &a1, &a0);

    // Input initial bracket and tolerance
    printf("Enter initial bracket (xl, xu) and error tolerance E: ");
    scanf("%f %f %f", &xl, &xu, &E);

   
    fxl = f(xl);
    fxu = f(xu);
    
    if (fxl * fxu > 0) {
        printf("Invalid bracket! f(xl) and f(xu) must have opposite signs.\n");
        return 1;
    }

    do {
        xm = (xl + xu) / 2; 
        fxm = f(xm);

        if (fabs(fxm) < 1e-6) { 
            printf("Root = %f\n", xm);
            return 0;
        }

      
        if (fxl * fxm < 0) {
            xu = xm;
        } else {
            xl = xm;
            fxl = fxm; 
        }

        // Calculate relative error
        Era = fabs((xu - xl) / xu);

        if (Era < E) {  // Check stopping condition
            printf("Root = %f\n", xm);
            return 0;
        }

        iteration++;
    } while (iteration < max_iterations);

    printf("Method did not converge within %d iterations.\n", max_iterations);
    return 1;
}
