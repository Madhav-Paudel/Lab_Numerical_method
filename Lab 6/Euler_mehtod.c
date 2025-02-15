// C program to solve Ordinary Differential Equation using Euler Method
#include <stdio.h>
#include <math.h>

#define f(x, y) (2 * y)

int main()
{
    float x, xp, x0, y0, y, h;

    printf("Enter initial values of x and y:\n");
    scanf("%f %f", &x0, &y0);
    
    printf("Enter x at which function is to be evaluated:\n");
    scanf("%f", &xp);
    
    printf("Enter the step size:\n");
    scanf("%f", &h);

    y = y0;
    x = x0;

    while (x < xp)
    {
        y = y + f(x, y) * h; 
        x = x + h;  
    }

    // Output the result
    printf("Function value at x = %f is %f\n", xp, y);

    return 0;
}
