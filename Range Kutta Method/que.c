#include <stdio.h>
#define f(x, y) (y * y - x * x) / (y * y + x * x)

int main()
{
    float x0, y0, xn, yn, h, k1, k2, k3, k4, k;
    int i, n;

    printf("C program for 4th order Range-Kutta method created by Swagat Nepal.\n");
    printf("________________________________________________________________________\n\n");

    printf("Enter the values of x0 & y0: \n");
    scanf("%f %f", &x0, &y0);

    printf("Enter calculation point xn: ");
    scanf("%f", &xn);

    printf("Enter no. of steps: ");
    scanf("%d", &n);

    h = (xn - x0) / n;
    printf("\n x0 \t y0 \t \tyn\n");
    printf("_________________________________________________________________________\n");
    
    for (i = 0; i < n; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f((x0 + h / 2), (y0 + k1 / 2));
        k3 = h * f((x0 + h / 2), (y0 + k2 / 2));
        k4 = h * f((x0 + h), (y0 + k3));

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;

        printf("%.4f \t %.4f \t %.4f \n", x0, y0, yn);
        
        x0 = x0 + h;
        y0 = yn;
    }

    printf("_________________________________________________________________________\n");
    printf("\nThe approximate value of y at x = %.3f is: %.5f\n", xn, yn);

    return 0;
}
