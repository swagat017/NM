#include <stdio.h>
#include <math.h>
#define f(x) (exp(2.8 * (x)) + cos(x) - 3 * (x) * (x))
int main()
{
    float x0, x1, f0, f1, x2, f2, e;
    int it = 1;

    printf("\nC program for bisection method created by Swagat Nepal on 17th Dec, 2024.");

// input
Input:
    printf("\nEnter the values of initial guesses.\nEnter lower initial guess x0 and upper initial guess x1: ");
    scanf("%f %f", &x0, &x1);
    printf("\nEnter the value of predefined error: ");
    scanf("%f", &e);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0.0)
    {
        printf("Wrong initial guess!");
        goto Input;
    }

    printf("\n_________________________________________________________________________________\n");
    printf("Iteration \t X0 \t\t X1 \t\t X2 \t\t F(X2)");
    printf("\n_________________________________________________________________________________\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("\n%d\t%f\t\t%f\t\t%f\t\t%f\n", it, x0, x1, x2, f2);
        it++;
        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
    } while (fabs(f2) > e);

    printf("\n_________________________________________________________________________________\n");
    printf("\nThe required approximate real root is %0.8f", x2);

    return 0;
}