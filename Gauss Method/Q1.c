#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float a[20][20], x[20], rat, sum;

    // Title
    printf("C program to solve non linear equation using Gauss elimination method by Swagat Nepal.\n");

    // input section
    printf("Enter the number of unknown variables of augumented matrix A: ");
    scanf("%d", &n);

    printf("Enter the elements A[i][j] of the augumented matrix [A:C] corresponding to given system.");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("\t\nA[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss Elimination Method
    // Forward Eliminaiton
    for (i = 1; i <= n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Gauss elimination method fails.");
            exit(1);
        }
    }

    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i != j)
            {
                rat = a[i][j] / a[j][j];
                for (k = 1; k <= n + 1; k++)
                {
                    a[i][k] = a[i][k] - rat * a[j][k];
                }
            }
        }
    }

    // The given matrix is changed into diagonal matrix
    // Backward substitution method

    if (a[n][n] == 0.0 && a[n][n + 1] == 0.0)
    {
        printf("The system has infinite number of solutions and so the system is consistent.");
        exit(0);
    }

    if (a[n][n] == 0.0 && a[n][n + 1] != 0.0)
    {
        printf("The system has no solution and so the system is inconsistent.");
        exit(0);
    }

    // compute unique solution.
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }

    printf("The required approximate solution of the Gauss Elimination method is :\n");

    for (i = 1; i <= n; i++)
    {
        printf("\tx[%d] = %0.6f", i, x[i]);
    }

    return 0;
}