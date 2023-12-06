#include <stdio.h>

int main() {
    const double ngaycong=26;
    double luongcoban;
    double ngaycongtt;
    double bn;
    printf("Nhap luong co ban: ");
    scanf("%lf",&luongcoban);
    printf("Nhap ngay cong thuc te: ");
    scanf("%lf",&ngaycongtt);
    // Tinh luong :
    if (ngaycongtt>ngaycong)
    {
        bn= luongcoban*((ngaycongtt-ngaycong)/ngaycong*1.5);
        printf ("tien luong nhan vien: %.2lf",luongcoban*((ngaycong/ngaycong)+bn));
    }
    else {printf("luong nhan vien: %.2lf",luongcoban*(ngaycongtt/ngaycong));}
    return 0;


}