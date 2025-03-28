#include<stdio.h>

int main()
{
    float x[100], y[100], xp, yp, p;
    int n, d = 1;
    char ch;

    printf("C program for Lagrange's Interpolation formula, created by Swagat Nepal.\n");
    printf("________________________________________________________________________\n\n");

    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    printf("Enter respective values of variables x and y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("\nThe table you entered is:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%0.3f \t %0.3f\t\n", x[i], y[i]);
    }

    do
    {
        yp = 0;
        printf("Enter the value of x to find respective value of y: ");
        scanf("%f", &xp);

        for (int i = 0; i < n; i++)
        {
            p = 1;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    p = p * ((xp - x[j]) / (x[i] - x[j]));
                }
            }
            yp += p * y[i];
        }

        printf("The respective value of the variable yp at xp = %0.3f is : %0.3f.\n", xp, yp);
        printf("Do you want to continue:(y/n) ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}