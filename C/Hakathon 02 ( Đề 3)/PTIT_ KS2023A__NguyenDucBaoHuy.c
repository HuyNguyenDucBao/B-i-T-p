#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TODOS 100

typedef struct {
    int id;
    char startDate[50];
    char endDate[50];
    char content[100];
    bool status;
} Todo;

Todo todoList[MAX_TODOS] = {
        {1, "01/01/2023", "02/01/2023", "Lam BT1", false},
        {2, "03/01/2023", "04/01/2023", "Lam BT2", true}
};
int size = 2;

void printTodoList() {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Ngay bat dau: %s, Ngay ket thuc: %s, Noi dung: %s, Trang thai: %s\n",
               todoList[i].id, todoList[i].startDate, todoList[i].endDate, todoList[i].content,
               todoList[i].status ? "Hoan thanh" : "Chua hoan thanh");
    }
}

void addTodo() {
    if (size < MAX_TODOS) {
        Todo newTodo;
        printf("Nhap thong tin cho cong viec moi:\n");
        printf("ID: ");
        scanf("%d", &newTodo.id);
        printf("Ngay bat dau: ");
        scanf("%s", newTodo.startDate);
        printf("Ngay ket thuc: ");
        scanf("%s", newTodo.endDate);
        printf("Noi dung: ");
        scanf(" %[^\n]s", newTodo.content);
        printf("Trang thai (1 cho Hoan thanh, 0 cho Chua hoan thanh): ");
        scanf("%d", &newTodo.status);

        todoList[size++] = newTodo;
        printf("Cong viec da duoc them moi.\n\n");
    } else {
        printf("Danh sach cong viec da day. Khong the them moi.\n\n");
    }
}

void updateTodo() {
    char content[100];
    printf("Nhap noi dung cua cong viec muon cap nhat: ");
    scanf(" %[^\n]s", content);

    for (int i = 0; i < size; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            printf("Nhap thong tin cap nhat cho cong viec:\n");
            printf("Ngay bat dau moi: ");
            scanf("%s", todoList[i].startDate);
            printf("Ngay ket thuc moi: ");
            scanf("%s", todoList[i].endDate);
            printf("Noi dung moi: ");
            scanf(" %[^\n]s", todoList[i].content);
            printf("Trang thai moi (1 cho Hoan thanh, 0 cho Chua hoan thanh): ");
            scanf("%d", &todoList[i].status);
            printf("Cong viec da duoc cap nhat.\n\n");
            return;
        }
    }

    printf("Khong tim thay cong viec.\n\n");
}

void deleteTodo() {
    char content[100];
    printf("Nhap noi dung cua cong viec muon xoa: ");
    scanf(" %[^\n]s", content);

    for (int i = 0; i < size; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            for (int j = i; j < size - 1; j++) {
                todoList[j] = todoList[j + 1];
            }
            size--;
            printf("Cong viec da duoc xoa.\n\n");
            return;
        }
    }

    printf("Khong tim thay cong viec.\n\n");
}

void sortTodoList() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(todoList[i].content, todoList[j].content) > 0) {
                Todo temp = todoList[i];
                todoList[i] = todoList[j];
                todoList[j] = temp;
            }
        }
    }
    printf("Danh sach cong viec sau khi sap xep:\n");
    printTodoList();
}

void searchTodo() {
    char content[100];
    printf("Nhap noi dung cua cong viec muon tim: ");
    scanf(" %[^\n]s", content);

    for (int i = 0; i < size; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            printf("Thong tin cua cong viec can tim:\n");
            printf("ID: %d, Ngay bat dau: %s, Ngay ket thuc: %s, Noi dung: %s, Trang thai: %s\n\n",
                   todoList[i].id, todoList[i].startDate, todoList[i].endDate, todoList[i].content,
                   todoList[i].status ? "Hoan thanh" : "Chua hoan thanh");
            return;
        }
    }

    printf("Khong tim thay cong viec.\n\n");
}

void searchByStatus() {
    int status;
    printf("Nhap trang thai cua cong viec muon tim (1 cho Hoan thanh, 0 cho Chua hoan thanh): ");
    scanf("%d", &status);

    printf("Danh sach cong viec co trang thai %s:\n", status ? "Hoan thanh" : "Chua hoan thanh");
    for (int i = 0; i < size; i++) {
        if (todoList[i].status == status) {
            printf("ID: %d, Ngay bat dau: %s, Ngay ket thuc: %s, Noi dung: %s, Trang thai: %s\n",
                   todoList[i].id, todoList[i].startDate, todoList[i].endDate, todoList[i].content,
                   todoList[i].status ? "Hoan thanh" : "Chua hoan thanh");
        }
    }
}

int main(void) {
    int choice;
    do {
        printf("************************MENU**************************\n");
        printf("1. In toan bo danh sach cong viec\n");
        printf("2. Them moi cong viec\n");
        printf("3. Cap nhat thong tin cong viec\n");
        printf("4. Xoa cong viec\n");
        printf("5. Sap xep danh sach cong viec\n");
        printf("6. Tim cong viec\n");
        printf("7. Tim cong viec theo trang thai\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printTodoList();
                break;
            case 2:
                addTodo();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            case 5:
                sortTodoList();
                break;
            case 6:
                searchTodo();
                break;
            case 7:
                searchByStatus();
                break;
            case 8:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (choice != 8);

}
