#include <stdio.h>

void gaussJordan(double a[3][4], double res[3])
{
    int i, j, k;
    double ratio;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < 4; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        res[i] = a[i][3] / a[i][i];
    }
}

int main()
{
    int n, i;
    double x[50], y[50];
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumx2y = 0;

    printf("C program for parabola fitting, created by Swagat Nepal.\n");
    printf("________________________________________________________________\n\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the values of x and corresponding y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
        sumx3 += x[i] * x[i] * x[i];
        sumx4 += x[i] * x[i] * x[i] * x[i];
        sumx2y += x[i] * x[i] * y[i];
    }

    double mat[3][4] = {
        {n, sumx, sumx2, sumy},
        {sumx, sumx2, sumx3, sumxy},
        {sumx2, sumx3, sumx4, sumx2y}};

    double res[3];
    gaussJordan(mat, res);

    printf("\nThe parabola is: y = %.2f + %.2fx + %.2fx^2\n", res[0], res[1], res[2]);
    return 0;
}