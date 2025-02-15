// C program for Trapezoidal Rule 
#include<stdio.h>
#include<math.h>

#define f(x) ((x) + 2)  // Fix: Added parentheses to ensure correct evaluation

int main()
{
    float h, x0, x1, fx0, fx1, v;
    printf("Enter lower & upper limit:\n");
    scanf("%f %f", &x0, &x1);
    
    h = x1 - x0;
    fx0 = f(x0);
    fx1 = f(x1);
    v = h / 2 * (fx0 + fx1);
    
    printf("Value of integration = %f\n", v);
    return 0;
}
