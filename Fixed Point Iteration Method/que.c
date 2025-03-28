#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g(x) (exp(x) / 3)
int main()
{
    float x0, x1, e;
    int it = 1, n;
    printf("C program for Fixed Point Iteration Method created by Swagat Nepal on 14th January, 2025.\n");
    printf("Enter the value of initial guess (x0): ");
    scanf("%f", &x0);
    printf("Enter max no of iteretions (N): ");
    scanf("%d", &n);
    printf("Enter the value of tolerable error (e): ");
    scanf("%f", &e);

    printf("\n_________________________________________________________________________\n");
    printf("Iterations\tx0\t\tg(x0)\t\tx1\t\tError");
    printf("\n_________________________________________________________________________\n");
    do
    {
        x1 = g(x0);
        printf("\n%d\t\t%f\t%f\t%f\t%f", it, x0, g(x0), x1, fabs(x1 - x0));
        if (fabs(x1 - x0) < e)
        {
            printf("\n_________________________________________________________________________\n");
            printf("The approximate root of the equation is %0.8f\n\n", x1);
            break;
        }
        x0 = x1;
        it++;
        if(it>n)
        {
            printf("\nThe solution doesn't converge.\n\n");
            exit(0);
        }
    } while (1);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #define g(x) (exp(x) / 3)

// int main()
// {
//     float x0, x1, e;
//     int it = 1, n;

//     printf("C program for Fixed Point Iteration Method created by Swagat Nepal on 14th January, 2025.\n");
//     printf("\n_________________________________________________________________________________\n");
//     printf("Enter the value of initial guess (x0): ");
//     scanf("%f", &x0);
//     printf("Enter max no of iterations (N): ");
//     scanf("%d", &n);
//     printf("Enter the value of tolerable error (e): ");
//     scanf("%f", &e);

//     printf("\n_________________________________________________________________________________\n");
//     printf("\nIterations\t     x0\t\t   g(x0)\t\t     x1\t\t  |x1 - x0|");
//     printf("\n_________________________________________________________________________________\n");

//     do
//     {
//         x1 = g(x0);
//         printf("\n%6d\t%10.6f\t%10.6f\t%10.6f\t%10.6f", it, x0, x1, x1, fabs(x1 - x0));

//         if (fabs(x1 - x0) < e)
//         {
//             printf("\n_________________________________________________________________________________\n");
//             printf("The approximate root of the equation is %0.8f\n\n", x1);
//             return 0;
//         }

//         x0 = x1;
//         it++;

//         if (it > n)
//         {
//             printf("\n_________________________________________________________________________________\n");
//             printf("The solution does not converge within %d iterations.\n\n", n);
//             return 1;
//         }

//     } while (1);

//     return 0;
// }
