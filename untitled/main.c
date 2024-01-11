#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct{
    char maSach[6];
    char tenSach[MAX];
    char tacGia[MAX];
    int gia;
    char theLoai[MAX];
}Book;
void menu();
void vietHoaChuDau(char * name);
void addBook(Book a[], int * n);
void in(Book a[], int n);
void writeDataInFile(Book a[], int n);
void updateBookInformation(Book a[], int n);
void deleteBookByID(Book a[], int * n);
void sortDescending(Book a[], int n);
void sortUpAscending(Book a[], int n);
void searchBookByAuthor(Book a[], int n);
void searchBookByPrice(Book a[], int n);
void deleteData();

int main() {
    int n = 0, choice;
    Book a[MAX];
    do {
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(a, &n);
                break;
            case 2:
                updateBookInformation(a, n);
                break;
            case 3:
                deleteBookByID(a, &n);
                break;
            case 4:
                in(a, n);
                break;
            case 5:
                sortDescending(a, n);
                break;
            case 6:
                sortUpAscending(a, n);
                break;
            case 7:
                searchBookByAuthor(a, n);
                break;
            case 8:
                searchBookByPrice(a, n);
                break;
            case 9:
                deleteData();
                break;
            case 10:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 10);
    return 0;
}
void menu() {
    printf("CHUONG TRINH QUAN LY SINH VIEN C/C++\n");
    printf("*************************MENU**************************\n");
    printf("**  1. Them sach.                                    **\n");
    printf("**  2. Cap nhat thong tin sach boi ID.               **\n");
    printf("**  3. Xoa sach boi ID.                              **\n");
    printf("**  4. Hien thi thong tin sach.                      **\n");
    printf("**  5. Sap xep sach theo gia giam dan.               **\n");
    printf("**  6. Sap xep sach theo gia tang dan.               **\n");
    printf("**  7. Tim kiem sach theo ten tac gia.               **\n");
    printf("**  8. Tim kiem sach theo khoang gia.                **\n");
    printf("**  9. Xoa du lieu trong file book.txt               **\n");
    printf("**  10. Thoat, cam on da lua chon sach hay           **\n");
    printf("*******************************************************\n");
}
// Hàm chuẩn hóa tên
void vietHoaChuDau(char * name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (i == 0 || (i > 0 && name[i - 1] == ' ')) {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }
}
void addBook(Book a[], int *n) {
    int themSach;
    do {
        printf("Nhap thong tin sach:\n ");
        do {
            printf("Ma sach(5 ki tu): ");
            fflush(stdin);
            scanf("%s", a[*n].maSach);
            fflush(stdin); // loại bỏ kí tự \n thừa trong buffer
        } while (strlen(a[*n].maSach) != 5); // Nhập tên sách từ 10 kí tự trở lên
        do {
            printf("Ten Sach (10 ky tu tro len): ");
            fflush(stdin);
            fgets(a[*n].tenSach, sizeof(a[*n].tenSach), stdin);
            a[*n].tenSach[strcspn(a[*n].tenSach, "\n")] = '\0';
        } while (strlen(a[*n].tenSach) < 10);

        vietHoaChuDau(a[*n].tenSach);


        printf("Tac gia Sach: ");
        fflush(stdin);
        fgets(a[*n].tacGia, sizeof(a[*n].tacGia), stdin);
        a[*n].tacGia[strcspn(a[*n].tacGia, "\n")] = '\0';

        printf("The loai Sach: ");
        fflush(stdin);
        fgets(a[*n].theLoai, sizeof(a[*n].theLoai), stdin);
        a[*n].theLoai[strcspn(a[*n].theLoai, "\n")] = '\0';

        do {
            printf("Gia Sach: ");
            scanf("%d", &a[*n].gia);
            if (a[*n].gia < 1000) {
                printf("Gia sach khong hop le. Moi nhap lai.\n");
            }
        } while (a[*n].gia < 1000);

        writeDataInFile(a, *n);// Ghi dữ liệu vào file sau mỗi lần thêm sách
        (*n)++;
        printf("Ban co muon them sach tiep hay khong? (1: Co, 0: Khong): ");
        scanf("%d", &themSach);
        getchar(); // Loại bỏ ký tự \n thừa trong buffer
    } while(themSach == 1);
}
void in(Book a[], int n) {
    printf("\n| %-10s | %-25s | %-17s | %-14s | %-14s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
    printf("|----------------------------------------------------------------------------------------------|\n");
    for (int i = 0; i < n; ++i) {
        printf("| %-10s | %-25s | %-17s | %-14d | %-14s |\n",
               a[i].maSach,
               a[i].tenSach,
               a[i].tacGia,
               a[i].gia,
               a[i].theLoai);
    }

    writeDataInFile(a, n);
}

void writeDataInFile(Book a[], int n) {
    FILE *fp = fopen("book.txt", "w");
    if (fp != NULL) {
        printf("\n| %-10s | %-25s | %-17s | %-14s | %-14s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
        printf("|----------------------------------------------------------------------------------------------|\n");
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%s, %s, %s, %d, %s\n",
                    a[i].maSach,
                    a[i].tenSach,
                    a[i].tacGia,
                    a[i].gia,
                    a[i].theLoai);
        }
        fclose(fp);
    }
    if(fclose(fp) == 0){
        printf("Da nhap du lieu vao file.\n");
    }
}
void updateBookInformation(Book a[], int n) {
    char maSach[6];
    printf("Nhap ma sach can cap nhat: ");
    fflush(stdin);
    fgets(maSach, sizeof(maSach), stdin);
    maSach[strcspn(maSach, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].maSach, maSach) == 0) {
            printf("Nhap thong tin sach moi:\n");
            fflush(stdin);
            do {
                printf("Ten sach ( nhap 10 ky tu tro len ) : ");
                fflush(stdin);
                fgets(a[i].tenSach, sizeof(a[i].tenSach), stdin);
                a[i].tenSach[strcspn(a[i].tenSach, "\n")] = '\0';
            } while (strlen(a[i].tenSach) < 10);
            vietHoaChuDau(a[i].tenSach);
            printf("Tac gia: ");
            fflush(stdin);
            fgets(a[i].tacGia, sizeof(a[i].tacGia), stdin);
            a[i].tacGia[strcspn(a[i].tacGia, "\n")] = '\0';

            printf("The loai: ");
            fflush(stdin);
            fgets(a[i].theLoai, sizeof(a[i].theLoai), stdin);
            a[i].theLoai[strcspn(a[i].theLoai, "\n")] = '\0';

            do {
                printf("Gia sach: ");
                scanf("%d", &a[i].gia);
                if (a[i].gia < 1000) {
                    printf("Gia sach khong hop le, moi nhap lai: \n");
                }
            } while (a[i].gia < 1000);

            printf("Cap nhat thong tin sach thanh cong!\n");
            writeDataInFile(a, n);
            return;
        }
    }
    printf("Khong tim thay sach voi ma sach da nhap!\n");
}
void deleteBookByID(Book a[], int *n) {
    char maSach[6];
    printf("Nhap ma sach can xoa: ");
    fflush(stdin);
    fgets(maSach, sizeof(maSach), stdin);
    maSach[strcspn(maSach, "\n")] = '\0';

    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(a[i].maSach, maSach) == 0) {
            break;
        }
    }

    if (i != *n) {
        for (int j = i; j < *n - 1; j++) {
            a[j] = a[j + 1];
        }
        (*n)--;
        printf("Da xoa sach co ma %s\n", maSach);
        writeDataInFile(a, *n);
    } else {
        printf("Khong tim thay sach voi ma sach da nhap!\n");
    }
}
void sortUpAscending(Book a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j].gia > a[j+1].gia) {
                Book temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    in(a,n);
}

void sortDescending(Book a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j].gia < a[j+1].gia) {
                Book temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    in(a,n);
}

void searchBookByAuthor(Book a[], int n) {
    char tacgia[MAX];
    printf("Nhap ten tac gia can tim kiem: ");
    scanf(" %[^\n]", tacgia);

    int found = 0;
    printf("\nKet qua tim kiem theo tac gia '%s':\n", tacgia);
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].tacGia, tacgia) != NULL) {
            printf("%s | %s | %s | %s | %d\n", a[i].maSach, a[i].tenSach,
                   a[i].tacGia, a[i].theLoai, a[i].gia);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach cua tac gia '%s'\n", tacgia);
    }
}

void searchBookByPrice(Book a[], int n) {
    int giaMin, giaMax;
    printf("Nhap gia thap nhat: ");
    scanf("%d", &giaMin);
    printf("Nhap gia cao nhat: ");
    scanf("%d", &giaMax);

    int found = 0;
    printf("\nKet qua tim kiem trong khoang gia %d-%d:\n", giaMin, giaMax);
    for (int i = 0; i < n; ++i) {
        if (a[i].gia >= giaMin && a[i].gia <= giaMax) {
            printf("%s | %s | %s | %s | %d\n", a[i].maSach, a[i].tenSach,
                   a[i].tacGia, a[i].theLoai, a[i].gia);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach trong khoang gia vua nhap!!!\n");
    }
}
void deleteData(){
    FILE *file = fopen("book.txt","w");
    if (file != NULL){
        fclose(file);
        printf("Da xoa du lieu trong file book.txt.\n");
    }
}



