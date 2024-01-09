#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char maSV[6];
    char hoTen[31];
    char lop[11];
    float diemToan;
    float diemLy;
    float diemHoa;
} SinhVien;

// Function
int isValidHoTen(char *hoTen);
int isValidMaSV(char *maSV);
int isValidLop(char *lop);
void chuanHoa(SinhVien *sv);
float nhapDiem(const char* monHoc);
void inThongTin(SinhVien sv);
void nhapSinhVien(SinhVien *sv);
void themSinhVien();
void suaSinhVien();
void xoaSinhVien();
void hienThongTin();
int compareTang(const void *a, const void *b);
int compareGiam(const void *a, const void *b);
void sapXepSinhVienTheoDiemTB(int (*compare)(const void *, const void *));
void timKiemTheoLop();
void timKiemTheoDiemTrongKhoang();
void xoainfoTxt();

int main() {
    // Hien thi menu va thuc hien cac chuc nang tuong ung
    int choice;
    do {
        printf("\n*************** Menu quan ly sinh vien *****************\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Hien thi thong tin sinh vien\n");
        printf("5. Sap xep sinh vien theo diem trung binh (Tang hoac Giam)\n");
        printf("6. Tim kiem theo lop\n");
        printf("7. Tim kiem theo diem trong khoang (min-max)\n");
        printf("8. Xoa du lieu file student.txt\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themSinhVien();
                break;
            case 2:
                suaSinhVien();
                break;
            case 3:
                xoaSinhVien();
                break;
            case 4:
                hienThongTin();
                break;
            case 5:
                printf("1. Sap xep theo tang dan\n");
                printf("2. Sap xep theo giam dan\n");
                int sortChoice;
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    sapXepSinhVienTheoDiemTB(compareTang);
                } else if (sortChoice == 2) {
                    sapXepSinhVienTheoDiemTB(compareGiam);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                timKiemTheoLop();
                break;
            case 7:
                timKiemTheoDiemTrongKhoang();
                break;
            case 8:
                xoainfoTxt();
                break;
            case 9:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 9);
    return 0;
}

// Các hàm
int isValidHoTen(char *hoTen) {
    return strlen(hoTen) >= 5 && strlen(hoTen) <= 30;
}

int isValidMaSV(char *maSV) {
    return strlen(maSV) == 5;
}

int isValidLop(char *lop) {
    return strlen(lop) > 0;
}

void chuanHoa(SinhVien *sv) {
    char *start = sv->hoTen;
    char *end = start + strlen(sv->hoTen) - 1;

    while (isspace((unsigned char)*start)) start++;
    while (start <= end && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    memmove(sv->hoTen, start, end - start + 2);

    sv->hoTen[0] = toupper((unsigned char)sv->hoTen[0]);

    for (int i = 1; sv->hoTen[i]; i++) {
        sv->hoTen[i] = isspace((unsigned char)sv->hoTen[i - 1]) ? toupper((unsigned char)sv->hoTen[i]) : tolower((unsigned char)sv->hoTen[i]);
    }
}

float nhapDiem(const char* monHoc) {
    float diem;
    int result;
    do {
        printf("Nhap diem %s: ", monHoc);
        result = scanf("%f", &diem);
        while(getchar() != '\n'); // Xóa bộ nhớ đệm
        if (result == 0) { // Kiểm tra xem giá trị nhập vào có phải là số không
            printf("Diem khong hop le. Vui long nhap lai trong khoanng (0-10).\n");
            continue; // Nếu không phải số, quay lại đầu vòng lặp
        }
        if (diem < 0 || diem > 10) {
            printf("Diem khong hop le. Vui long nhap lai trong khoanng (0-10).\n");
        }
    } while (diem < 0 || diem > 10);
    return diem;
}

void inThongTin(SinhVien sv){
    printf("* MaSV: %s, Ho va ten: %s, Lop: %s, Toan: %.2f, Ly: %.2f, Hoa: %.2f, \n", sv.maSV, sv.hoTen, sv.lop, sv.diemToan, sv.diemLy, sv.diemHoa);
}

void nhapSinhVien(SinhVien *sv) {
    char temp[100];
    do {
        printf("Nhap ma sinh vien: ");
        scanf("%s", temp);
        if(!isValidMaSV(temp)) {
            printf("Ma sinh vien phai co 5 ky tu. Vui long nhap lai.\n");
        } else {
            strcpy(sv->maSV, temp);
        }
    } while (!isValidMaSV(temp));

    do {
        printf("Nhap ho ten: ");
        getchar();
        gets(sv->hoTen);
        sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;
        chuanHoa(sv);
        if (!isValidHoTen(sv->hoTen)) {
            printf("Vui long nhap du Ho va Ten cua sinh vien!\n");
        }
    } while (!isValidHoTen(sv->hoTen));

    do {
        printf("Nhap lop: ");
        scanf("%10s", sv->lop);
    } while (!isValidLop(sv->lop));

    sv->diemToan = nhapDiem("Toan");
    sv->diemLy = nhapDiem("Ly");
    sv->diemHoa = nhapDiem("Hoa");
}

void themSinhVien() {
    SinhVien sv;
    FILE *file = fopen("student.txt", "ab");
    if (file != NULL) {
        nhapSinhVien(&sv);
        fwrite(&sv, sizeof(SinhVien), 1, file);
        fclose(file);
    } else {
        printf("Khong the mo file student.txt\n");
    }
}

void suaSinhVien() {
    char maSV[6];
    printf("Nhap ma sinh vien can sua: ");
    scanf("%5s", maSV);
    FILE *file = fopen("student.txt", "r+b");
    if (file != NULL) {
        SinhVien sv;
        while (fread(&sv, sizeof(SinhVien), 1, file) == 1) {
            if (strcmp(sv.maSV, maSV) == 0) // xét đkien nếu string compare (so sánh chỗi) maSV (giá trị nhập vào) và ma.maSV trả về true( giống nhau)
            {
                printf("Nhap thong tin moi cho sinh vien:\n");
                nhapSinhVien(&sv);
                fseek(file, -sizeof(SinhVien), SEEK_CUR);   // di chuyển con trỏ đến vị trí sinh viên có sv.maSV (sinh viên đã chọn) trùng với dữ liệu maSV nhập vào trong file
                fwrite(&sv, sizeof(SinhVien), 1, file);  // sau đó ghi đè lên thông tin cũ của sinh viên cũ
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("Khong tim thay sinh vien co ma %s\n", maSV);
    } else {
        printf("Khong the mo file student.txt\n");
    }
}

void xoaSinhVien() {
    char maSV[6];
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%5s", maSV);
    FILE *file = fopen("student.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    if (file != NULL && temp != NULL) {
        SinhVien sv;
        while (fread(&sv, sizeof(SinhVien), 1, file) == 1) {
            if (strcmp(sv.maSV, maSV) != 0) {
                fwrite(&sv, sizeof(SinhVien), 1, temp);
            }
        }
        fclose(file);
        fclose(temp);
        remove("student.txt");
        rename("temp.txt", "student.txt");
    } else {
        printf("Khong the mo file student.txt\n");
    }
}

void hienThongTin() {
    SinhVien sv;
    FILE *file = fopen("student.txt", "rb");
    if (file != NULL) {
        // Kiểm tra xem file có dữ liệu hay không
        fseek(file, 0, SEEK_END); //di chuyển con trỏ về vị trí cuối file
        if (ftell(file) == 0) // nếu trả về vị trí hiện tại của con trỏ file = 0 (con trỏ không di chuyển khỏi vị trí)
        {
            printf("File khong co du lieu, vui long nhap du lieu.\n");
        } else {
            rewind(file);  // đặt lại con trỏ file về đầu file trước khi bắt đầu đọc dữ liệu
            while (fread(&sv, sizeof(SinhVien), 1, file) == 1) {
                inThongTin(sv);
            }
        }
    } else {
        printf("File khong ton tai, vui long kiem tra lai.\n");
    }
    fclose(file);
}

int compareTang(const void *a, const void *b) {
    SinhVien *svA = (SinhVien *)a;
    SinhVien *svB = (SinhVien *)b;
    float diemTBA = (svA->diemToan + svA->diemLy + svA->diemHoa) / 3;
    float diemTBB = (svB->diemToan + svB->diemLy + svB->diemHoa) / 3;
    return (diemTBA - diemTBB); // Sắp xếp tăng dần
}

int compareGiam(const void *a, const void *b) {
    SinhVien *svA = (SinhVien *)a;
    SinhVien *svB = (SinhVien *)b;
    float diemTBA = (svA->diemToan + svA->diemLy + svA->diemHoa) / 3;
    float diemTBB = (svB->diemToan + svB->diemLy + svB->diemHoa) / 3;
    return (diemTBB - diemTBA); // Sắp xếp giảm dần
}

void sapXepSinhVienTheoDiemTB(int (*compare)(const void *, const void *)) {
    SinhVien sv[100];
    int n = 0, i;
    FILE *file = fopen("student.txt", "rb");
    if (file != NULL) {
        while (fread(&sv[n], sizeof(SinhVien), 1, file) == 1) {
            n++;
        }
        fclose(file);
        qsort(sv, n, sizeof(SinhVien), compare);
        for (i = 0; i < n; i++) {
            float diemTB = (sv[i].diemToan + sv[i].diemLy + sv[i].diemHoa) / 3;
            printf("* Ma SV: %s, Ho ten: %s, Lop: %s, Diem Toan: %.2f, Diem Ly: %.2f, Diem Hoa: %.2f, DiemTB: %.2f\n", sv[i].maSV,
                   sv[i].hoTen, sv[i].lop, sv[i].diemToan, sv[i].diemLy, sv[i].diemHoa, diemTB);
        }
    } else {
        printf("Khong the mo file student.txt\n");
    }
}

void timKiemTheoLop() {
    char lop[10];
    printf("Nhap lop can tim kiem: ");
    scanf("%s", lop);
    FILE *file = fopen("student.txt", "rb");
    if (file != NULL) {
        SinhVien sv;
        int count =0;
        while (fread(&sv, sizeof(SinhVien), 1, file) == 1) {
            if (strcmp(sv.lop, lop) == 0) {
                inThongTin(sv);
                count++;
            }
        }
        if (count == 0) {
            printf("Chua co du lieu ve sinh vien cua lop %s.\n", lop);
        }
        fclose(file);
    } else {
        printf("Khong the mo file student.txt\n");
    }
}

void timKiemTheoDiemTrongKhoang() {
    float min, max;
    do {
        printf("Nhap khoang diem can tim kiem (min-max): ");
        scanf("%f-%f", &min, &max);
        if (min < 1 || max > 10) {
            printf("Gia tri nhap vao khong hop le. Vui long nhap lai.\n");
        }
    } while (min < 1 || max > 10);

    FILE *file = fopen("student.txt", "rb");
    if (file != NULL) {
        SinhVien sv;
        int count = 0;
        while (fread(&sv, sizeof(SinhVien), 1, file) == 1) {
            float diemTB = (sv.diemToan + sv.diemLy + sv.diemHoa) / 3;
            if (diemTB >= min && diemTB <= max) {
                printf("* MaSV: %s, Ho va ten: %s, Lop: %s, Toan: %.2f, Ly: %.2f, Hoa: %.2f, DiemTB: %.2f\n", sv.maSV, sv.hoTen, sv.lop, sv.diemToan, sv.diemLy, sv.diemHoa, diemTB);
                count++;
            }
        }
        if (count == 0) {
            printf("Khong co du lieu can tim.\n");
        }
        fclose(file);
    } else {
        printf("Khong the mo file student.txt\n");
    }
}



void xoainfoTxt() {
    FILE *file = fopen("student.txt", "w");

    if (file != NULL) {
        printf("Da xoa du lieu trong file student.txt.\n");
        fclose(file);
    }
}

//int main() {
//    // Hien thi menu va thuc hien cac chuc nang tuong ung
//    int choice;
//    do {
//        printf("\n*************** Menu quan ly sinh vien *****************\n");
//        printf("1. Them sinh vien\n");
//        printf("2. Sua sinh vien\n");
//        printf("3. Xoa sinh vien\n");
//        printf("4. Hien thi thong tin sinh vien\n");
//        printf("5. Sap xep sinh vien theo diem trung binh (Tang hoac Giam)\n");
//        printf("6. Tim kiem theo lop\n");
//        printf("7. Tim kiem theo diem trong khoang (min-max)\n");
//        printf("8. Xoa du lieu file student.txt\n");
//        printf("0. Thoat\n");
//        printf("Nhap lua chon cua ban: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//            case 1:
//                themSinhVien();
//                break;
//            case 2:
//                suaSinhVien();
//                break;
//            case 3:
//                xoaSinhVien();
//                break;
//            case 4:
//                hienThongTin();
//                break;
//            case 5:
//                printf("1. Sap xep theo tang dan\n");
//                printf("2. Sap xep theo giam dan\n");
//                int sortChoice;
//                scanf("%d", &sortChoice);
//                if (sortChoice == 1) {
//                    sapXepSinhVienTheoDiemTB(compareTang);
//                } else if (sortChoice == 2) {
//                    sapXepSinhVienTheoDiemTB(compareGiam);
//                } else {
//                    printf("Lua chon khong hop le.\n");
//                }
//                break;
//            case 6:
//                timKiemTheoLop();
//                break;
//            case 7:
//                timKiemTheoDiemTrongKhoang();
//                break;
//            case 8:
//                xoainfoTxt();
//                break;
//            case 9:
//                printf("Thoat chuong trinh\n");
//                break;
//            default:
//                printf("Lua chon khong hop le\n");
//                break;
//        }
//    } while (choice != 9);
//    return 0;
//}
