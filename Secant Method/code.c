#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (pow(x, 3) - 2 * x - 5)

int main()
{
    double x0, x1, x2, f0, f1, f2, e;
    int it = 1, n;

    //input
    printf("C program for Secant Method created by Swagat Nepal on 14th January, 2025.");
    printf("\n____________________________________________________________________________\n");
    printf("Enter the value of x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter max no of iterations (N): ");
    scanf("%d", &n);
    printf("Enter the value of tolerable error (E): ");
    scanf("%lf", &e);
    printf("\n____________________________________________________________________________\n");
    printf("Iterations\tx0\t\tx1\t\tx2\t\tf(x2)");
    printf("\n____________________________________________________________________________\n");
    do {
        f0 = f(x0);
        f1 = f(x1);
        if(f1 ==f0)
        {
            printf("Secant method fails!");
            exit(0);
        }
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);
        printf("\n%d\t\t%lf\t%lf\t%lf\t%lf", it, x0, x1, x2, f2);
        x0 = x1;
        x1 = x2;
        it++;
        if(it>n)
        {
            printf("\n\nThe solution doesn't converge.\n\n");
            break;
        }
    } while (fabs(f2) > e);
    printf("\n____________________________________________________________________________\n");
    printf("\nThe approximate root of the equations is %0.8f\n\n", x2);

    return 0;
}