#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) exp(x) - 3 * x

void main()
{
    double x0, x1, f0, f1, x2, f2, e;
    int i = 1, iteration;
    printf("Choose Initial Case of X0 and X1: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter the number of iteration and predefined error: ");
    scanf("%d %lf", &iteration, &e);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0)
    {
        printf("Error: f(x0)*f(x1) must be negative");
        exit(0);
    }
    printf("\n_________________________________________________________________________________\n");
    printf("Iteration \t X0 \t\t X1 \t\t X2 \t\t F(X2)");
    printf("\n_________________________________________________________________________________\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("\n %d \t\t %lf \t %lf \t %lf \t %lf", i, x0, x1, x2, f2);
        i++;
        if (f2 * f1 < 0)
        {
            x0 = x2;
        }
        else
        {
            x1 = x2;
        }
        if (i > iteration)
        {
            printf("\n The solution is not converged");
            exit(0);
        }
    } while (fabs(f(x2)) > e);
    printf("\n_________________________________________________________________________________\n");
    printf("The required approximate real roots is %.8f \n", x2);
}