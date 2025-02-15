//  C program to solve Ordinary Differential Equation using Runge_Katta_method
#include<stdio.h>
#include<math.h>
#define f(x,y)  2*(x)+(y)
int main()
{
    float x,xp,x0,y0,y,h,m1,m2,m3,m4;
    printf("Enter initial values of x and y\n");
    scanf("%f %f",&x0,&y0);
    printf("Enter x at which function to be Evaluated\n");
    scanf("%f",&xp);
    printf("Enter the step size\n");
    scanf("%f",&h);
    y=y0;
    x=x0;
    for(x=x0;x<xp;x=x+h)
    {
        m1=f(x,y);
        m2=f(x+1/2.0*h,y+1/2.0*h*m1);
        m3=f(x+1/2.0*h,y+1/2.0*h*m2);
        m4=f(x+h,y+h*m3);
        y=y+h/6*(m1+2*m2+2*m3+m4);

    }
    printf("Function value at x=%f is %f\n",xp,y);
    return 0;

}