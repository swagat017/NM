#include <stdio.h>
#include <math.h>

// Define the function f(x) = 1 / (1 + x^2) using #define
#define f(x) (1.0 / (1 + (x) * (x)))

// Simpson's 1/3 Rule
double simpson_1_3(double a, double b, int n)
{
    if (n % 2 != 0)
    {
        printf("Error: n must be even for Simpson's 1/3 rule.\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2)
    {
        sum += 4 * f(a + i * h); // Odd indices
    }
    for (int i = 2; i < n - 1; i += 2)
    {
        sum += 2 * f(a + i * h); // Even indices
    }
    return (h / 3) * sum;
}

int main()
{
    double a, b;
    int n;

    printf("C program for Simpson's 1/3 method, created by Swagat Nepal.\n");
    printf("________________________________________________________________\n\n");
    printf("Enter the limits of integration (a and b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Simpson's 1/3 Rule
    double result = simpson_1_3(a, b, n);
    if (result != -1)
        printf("\nSimpson's 1/3 Rule: %.6f\n", result);

    return 0;
}
