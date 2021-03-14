#include <stdio.h>
#include <math.h>
int main()
{
int a,b,c;
double x1,x2;
printf("introduza os valores dos termos a, b e c do polinimio ax^2 + bx + c\n ");
scanf("%d %d %d", &a, &b, &c);
x1 = (-1 * b + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
x2 = (-1 * b - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
printf("x1 = %lf \nx2 = %lf \n", x1, x2);
    return 0;
}