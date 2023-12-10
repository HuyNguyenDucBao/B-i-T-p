#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2;
    printf("Nhap he so a, b va c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    delta = b*b - 4*a*c;

    if(delta > 0) {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("Phuong trinh co 2 nghiem phan biet: x1 = %.2lf va x2 = %.2lf\n", x1, x2);
    } else if(delta == 0) {
        x1 = -b / (2*a);
        printf("Phuong trinh co nghiem kep: x1 = x2 = %.2lf\n", x1);
    } else {
        printf("Phuong trinh vo nghiem.\n");
    }

    return 0;
}
