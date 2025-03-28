#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x*x - 3*x +2
#define df(x) 2*x -3

void main()
{
    float x0, f0, x1, f1, e, df0;
    int iteration = 1, n;

    printf("C program for Newton Raphson created by Swagat Nepal on 11th, Nov 2024.\n");
    printf("Enter value of initial guess (x0): ");
    scanf("%f", &x0);
    printf("Enter value of max number of iterations: ");
    scanf("%d", &n);
    printf("Enter the predefined error: ");
    scanf("%f", &e);
    printf("\n________________________________________________________________________________________________________\n");
    printf("Iterations\tx0\t\t\tf(x0)\t\t\tx1\t\t\tf(x1)");
    printf("\n________________________________________________________________________________________________________\n");
    do
    {
        f0 = f(x0);
        df0 = df(x0);
        if (df0 == 0.0)
        {
            printf("Newton Raphson method fails.\n");
            exit(0);
        }
        x1 = x0 - f0 / df0;
        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", iteration, x0, f0, x1, f1);
        iteration += 1;
        x0 = x1;

        if (iteration > n)
        {
            printf("The solution doesn't converge.\n");
            exit(0);
        }
        f1 = f(x1);
    } while (fabs(f1) > e);
    printf("\n________________________________________________________________________________________________________\n");
    printf("The approximate real root of the equation is %g", x1);
}