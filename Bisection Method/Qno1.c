#include<stdio.h>
#include<math.h>
#define f(x) exp(x) - 3 * x
void main() {
    long double x0, x1, x2, f0, f1, f2, e;
    int iteration = 1;
    printf("C program for bisection code created by Swagat Nepal on 4th December 2024.");

    //input section
    Input:
        printf("\nEnter the values of initial guesses.\n");
        printf("Lower initial guess x0: ");
        scanf("%ld", &x0);
        printf("Upper initial guess x1: ");
        scanf("%ld", &x1);
        printf("Enter the value of predefined error e: ");
        scanf("%ld", &e);

        f0 = f(x0);
        f1 = f(x1);

        if((f0 * f1)>0.0){
            printf("Wrong initial guess!");
            goto Input;
        }

        printf("\n________________________________________________________________________________________________________\n");
        printf("Iterations \t x0 \t\t x1\t\tx2\t\tf(x2)");
        printf("\n________________________________________________________________________________________________________\n");

        do
        {
            x2 = (x0 + x1) / 2;
            f2 = f(x2);

            printf("\n%d\t\t%f\t%f\t%f\t%f\n", iteration, x0, x1, x2, f2);
            iteration++;
            if (f0 * f1 < 0)
            {
                x1 = x2;
                f1 = f2;
            }
            else{
            x0 = x2;
            f0 = f2;
        }
    } while (fabs(f2) > e);

    printf("\n________________________________________________________________________________________________________\n");
    printf("The required approximate real root of the equation is %0.8f", x2);
}