#include <stdio.h>
#include <math.h>

// Define the function f(x) = 1 / (1 + x^2) using #define
#define f(x) (1.0 / (1 + (x) * (x)))

// Simpson's 3/8 Rule
double simpson_3_8(double a, double b, int n)
{
    if (n % 3 != 0)
    {
        printf("Error: n must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 3)
    {
        sum += 3 * f(a + i * h); // Indices 1, 4, 7, ...
    }
    for (int i = 2; i < n - 1; i += 3)
    {
        sum += 3 * f(a + i * h); // Indices 2, 5, 8, ...
    }
    for (int i = 3; i < n - 2; i += 3)
    {
        sum += 2 * f(a + i * h); // Indices 3, 6, 9, ...
    }
    return (3 * h / 8) * sum;
}

int main()
{
    double a, b;
    int n;

    printf("C program for Simpson's 3/8 method, created by Swagat Nepal.\n");
    printf("________________________________________________________________\n\n");

    printf("Enter the limits of integration (a and b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Simpson's 3/8 Rule
    double result = simpson_3_8(a, b, n);
    if (result != -1)
        printf("\nSimpson's 3/8 Rule: %.6f\n", result);

    return 0;
}
