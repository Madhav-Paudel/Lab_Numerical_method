// C program for calculating derivative using backward difference formula
#include<stdio.h>
#include<math.h>
#define e 2.718281828459045
#define f(x) e*exp(x)


int main()
{
    float  h, x, d;
    printf("Enter the value at which derivative is required\n");
    scanf("%f", &x);
    printf("Enter increment h\n");
    scanf("%f", &h);
    
   

    d=((f(x))-(f(x-h)))/h;
    printf("Value of derivative = %f\n", d);
    return 0;
}
