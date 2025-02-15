// C program to estimate Romberg integration T(p,q)
#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x) + 1)  // Function to integrate

int main()
{
    float x0, xn, T[10][10], h, sm, a;
    int i, k, c, m, p, q;

    printf("Enter lower & upper limit:\n");
    scanf("%f %f", &x0, &xn);
    
    printf("Enter p & q of required T(p,q):\n");
    scanf("%d %d", &p, &q);

    if (p >= 10 || q >= 10) {
        printf("Error: p and q must be less than 10.\n");
        return 1;
    }

    h = (xn - x0); // Initial step size
    T[0][0] = (h / 2.0) * (f(x0) + f(xn));

    for (i = 1; i <= p; i++)
    {
        int intervals = pow(2, i - 1);
        sm = 0;
        
        for (k = 1; k <= intervals; k++)
        {
            a = x0 + (2 * k - 1) * h / pow(2, i);
            sm += f(a);
        }
        T[i][0] = 0.5 * (T[i - 1][0] + (h / pow(2, i - 1)) * sm);
    }

    for (c = 1; c <= p; c++)
    {
        for (k = 1; k <= c && k <= q; k++)
        {
            m = c - k;
            T[m + k][k] = (pow(4, k) * T[m + k][k - 1] - T[m + k - 1][k - 1]) / (pow(4, k) - 1);
        }
    }

    printf("\nRomberg Estimate of integration = %f\n", T[p][q]);

    return 0;
}
