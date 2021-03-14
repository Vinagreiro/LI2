#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    double s, area;
    printf("Intruduza o valor dos lados A, B e C do triangulo:\n");
    scanf("%d %d %d", &a, &b, &c);

    if ((a < b + c) && (b < a + c) && (c < b + a)) {
        printf("A figura representa um triangulo\n");
        s = (a + b + c) / 2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

        if (a == b && b == c)
            printf("O Triangulo e Equilatero com Area = %.2lf\n", area);

        else if (a != b && a != c)
            printf("O Triangulo e Escaleno com Area = %.2lf\n", area);

        else
        printf("O Triangulo e Isoceles com Area = %.2lf\n", area);

    } else
        printf("A figura nao e um triangulo\n");
    return 0;
}