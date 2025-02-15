// C program for computing integral value using Composite Simpson's 3/8 Rule
#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x) + 3*(x)*(x))  
int main()
{
    float a, h, x0, xn, fx0, fxn, term, v;
    int i, k;

    printf("Enter lower and upper limit:\n");
    scanf("%f %f", &x0, &xn);
    
    printf("Enter number of segments:\n");
    scanf("%d", &k);  

    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;

    for (i = 1; i <= k - 1; i++)
    {
        a = x0 + i * h;
        if (i % 3 != 0)
            term += 3 * f(a);
        else
            term += 2 * f(a);
    }

    v = (3.0 / 8.0) * h * term; 

    printf("\nValue of integration = %f\n", v);
    return 0;
}
