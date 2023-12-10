#include <stdio.h>

int main() {
    double doanhThu, hoaHong;
    printf("Nhap doanh thu ban hang (VND): ");
    scanf("%lf", &doanhThu);

    if(doanhThu <= 100000000) {
        hoaHong = doanhThu * 0.05;
    } else if(doanhThu <= 300000000) {
        hoaHong = doanhThu * 0.10;
    } else {
        hoaHong = doanhThu * 0.20;
    }

    printf("Hoa hong cua dai ly la: %.2lf VND\n", hoaHong);

    return 0;
}
