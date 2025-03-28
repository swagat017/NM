#include <stdio.h>
#include <math.h>

// Define the function f(x) = 1 / (1 + x^2) using #define
#define f(x) (1.0 / (1 + (x) * (x)))

// Trapezoidal Rule
double trapezoidal(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        sum += 2 * f(a + i * h);
    }
    return (h / 2) * sum;
}

int main()
{
    double a, b;
    int n;

    printf("C program for Trapezoidal method, created by Swagat Nepal.\n");
    printf("________________________________________________________________\n\n");

    printf("Enter the lower limit then upper limit(a and b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Trapezoidal Rule
    double result = trapezoidal(a, b, n);
    printf("\nTrapezoidal Rule: %.6f\n", result);

    return 0;
}
