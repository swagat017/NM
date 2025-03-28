#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double x[50], y[50], sumx = 0, sumxx = 0, sumy = 0, sumxy = 0, a, b;

    printf("C program for linear curve fitting, created by Swagat Nepal.\n");
    printf("_________________________________________________________________\n\n");
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    printf("Enter the values of x and corresponding y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        sumx += x[i];
        sumxx += x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
    }

    b = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
    a = (sumy - b * sumx) / n;

    if (b > 0)
    {
        printf("\nThe line is y = %.2f + %.2f * x\n", a, b);
    }
    else if (b < 0)
    {
        printf("\nThe line is y = %.2f - %.2f * x\n", a, -b);
    }
    else
    {
        printf("\nThe line is y = %.2f\n", a);
    }

    return 0;
}