#include <stdio.h>
#include <math.h>
#define f(x) (pow(x, 3) - 4 * x - 9)

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int it = 1;

    printf("C program for False Position Method created by Swagat Nepal on 21st January, 2025.\n");

    //input
    input:
    printf("Enter initial guesses x0 and x1: ");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error (e): ");
    scanf("%f", &e);

    f0 = f(x0);
    f1 = f(x1);
    if(f0 * f1 > 0.0)
    {
        printf("Wrong initial guesses!\n");
        goto input;
    }

    printf("\n_________________________________________________________________________\n");
    printf("Iterations \t x0 \t\t x1 \t\t x2 \t\t f(x2)");
    printf("\n_________________________________________________________________________\n");
    do
    {
        x2 = x0 - (f0 * (x0 - x1)) / (f0 - f1);
        f2 = f(x2);
        printf("\n %d \t\t %f \t %f \t %f \t %f", it, x0, x1, x2, f2);

        if(f0*f2<0.0){
            x1 = x2;
            f1 = f2;
        }
        else{
            x0 = x2;
            f0 = f2;
        }
        it++;
    } while (fabs(f2) > e);

    printf("\n_________________________________________________________________________\n");
    printf("\nThe approximate root of the given equation is %0.8f.\n\n", x2);
    return 0;
}