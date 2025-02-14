// C program for calculating derivative using forward difference formula
#include<stdio.h>
#include<math.h>
#define PI 3.1415

// Define the function whose derivative is to be calculated
float f(float x) {
    return sin(x);  
}

int main()
{
    float angle, h, x, d;
    printf("Enter Angle in Degree\n");
    scanf("%f", &angle);
    printf("Enter increment h\n");
    scanf("%f", &h);
    x = PI / 180 * angle;  // Convert degrees to radians
    d = (f(x + h) - f(x)) / h;  
    printf("Value of derivative = %f\n", d);
    return 0;
}
