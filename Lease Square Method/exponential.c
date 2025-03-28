#include <stdio.h>
#include <math.h>

void gaussJordan(double a[2][3], double res[2])
{
    int i, j, k;
    double ratio;

    // Gauss-Jordan elimination process
    for (i = 0; i < 2; i++)
    {
        // Make the diagonal element 1
        double diag = a[i][i];
        for (k = 0; k < 3; k++)
        {
            a[i][k] /= diag;
        }

        // Eliminate the other elements in the column
        for (j = 0; j < 2; j++)
        {
            if (i != j)
            {
                ratio = a[j][i];
                for (k = 0; k < 3; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    // Extract the solution
    for (i = 0; i < 2; i++)
    {
        res[i] = a[i][2];
    }
}

int main()
{
    int n, i;
    double x[50], y[50];
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, sumY = 0, sumxY = 0;

    printf("C program for exponential curve fitting (y = ae^bx), created by Swagat Nepal.\n");
    printf("________________________________________________________________\n\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the values of x and corresponding y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);

        // Check if y is positive for logarithmic transformation
        if (y[i] <= 0)
        {
            printf("Error: y must be greater than 0 for logarithmic transformation.\n");
            return -1;
        }

        // Compute the sum values for the transformed data
        sumx += x[i];
        sumy += log(y[i]); // Y = ln(y)
        sumxy += x[i] * log(y[i]);
        sumx2 += x[i] * x[i];
        sumY += log(y[i]);
        sumxY += x[i] * log(y[i]);
    }

    // Set up the system of normal equations
    double mat[2][3] = {
        {n, sumx, sumY},
        {sumx, sumx2, sumxY}};

    double res[2]; // [A, b]
    gaussJordan(mat, res);

    // A is ln(a), so a = exp(A)
    double a = exp(res[0]);
    double b = res[1];

    // Output the result
    printf("\nThe exponential curve is: y = %.3fe^%.3fx\n", a, b);
    return 0;
}
