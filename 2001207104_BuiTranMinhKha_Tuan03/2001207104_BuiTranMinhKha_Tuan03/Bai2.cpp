#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef int ItemType;
typedef ItemType** ArrPtr;

void taoNgauNhienMaTranVuong(ArrPtr& a, int n);
void menu();
void xuatDuongCheoChinh(ArrPtr a, int n);
void xuatDuongCheoSongSong(ArrPtr a, int n);
int timMaxTamGiacTren(ArrPtr a, int n);
void sapXepZicZac(ArrPtr& a, int n);
void sapXepDuongCheoChinh(ArrPtr& a, int n);
void xoaMaTran(ArrPtr& a, int n);
void sapXepDuongCheoPhu(ArrPtr& a, int n, bool tangDan);
void sapXepDong(ArrPtr& a, int n);
void sapXepCot(ArrPtr& a, int n);

int main() {
    menu();
    return 0;
}

void menu() {
    ArrPtr a = nullptr;
    int n;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Tao/xuat ma tran vuong\n");
        printf("2. Xuat duong cheo chinh\n");
        printf("3. Xuat duong cheo song song\n");
        printf("4. Tim phan tu max tam giac tren\n");
        printf("5. Sap xep ma tran zic zac\n");
        printf("6. Sap xep duong cheo chinh\n");
        printf("7. Sap xep duong cheo phu\n");
        printf("8. Sap xep dong\n");
        printf("9. Sap xep cot\n");
        printf("10. Sap xep duong cheo va song song\n");
        printf("11. Chia phan tu chan le\n");
        printf("12. Kiem tra doi xung qua duong cheo chinh\n");
        printf("13. Thoat\n");
        printf("Chon chuc nang: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap cap cua ma tran vuong (n >= 5): ");
            scanf_s("%d", &n);
            if (n >= 5) {
                taoNgauNhienMaTranVuong(a, n);
            }
            else {
                printf("Cap ma tran phai lon hon hoac bang 5.\n");
            }
            break;
        case 2:
            if (a != nullptr) {
                xuatDuongCheoChinh(a, n);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 3:
            if (a != nullptr) {
                xuatDuongCheoSongSong(a, n);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 4:
            if (a != nullptr) {
                int max = timMaxTamGiacTren(a, n);
                printf("Phan tu lon nhat trong tam giac tren la: %d\n", max);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 5:
            if (a != nullptr) {
                sapXepZicZac(a, n);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 6:
            if (a != nullptr) {
                sapXepDuongCheoChinh(a, n);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 7:
            if (a != nullptr) {
                printf("Sap xep duong cheo phu tang dan (0) hay giam dan (1)? ");
                int tangDan;
                scanf_s("%d", &tangDan);
                sapXepDuongCheoPhu(a, n, tangDan == 0);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 8:
            if (a != nullptr) {
                sapXepDong(a, n);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 9:
            if (a != nullptr) {
                sapXepCot(a, n);
            }
            else {
                printf("Chua tao ma tran.\n");
            }
            break;
        case 13:
            xoaMaTran(a, n);
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (choice != 7);
}

void taoNgauNhienMaTranVuong(ArrPtr& a, int n) {
    a = new ItemType * [n];
    for (int i = 0; i < n; i++) {
        a[i] = new ItemType[n];
    }

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100; 
        }
    }

    printf("Ma tran vuong ngau nhien la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void xuatDuongCheoChinh(ArrPtr a, int n) {
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}

void xuatDuongCheoSongSong(ArrPtr a, int n) {
    printf("Cac phan tu thuoc duong cheo song song duong cheo chinh:\n");

    for (int k = 1; k < n; k++) {
        for (int i = 0, j = k; j < n; i++, j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    for (int k = 1; k < n; k++) {
        for (int i = k, j = 0; i < n; i++, j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int timMaxTamGiacTren(ArrPtr a, int n) {
    int max = a[0][1];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

void sapXepZicZac(ArrPtr& a, int n) {
    int* temp = new int[n * n];
    int index = 0;

    // Copy các phần tử ma trận vào temp
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }

    // Simple bubble sort để phân loại zig-zag
    for (int i = 0; i < n * n - 1; i++) {
        for (int j = 0; j < n * n - 1 - i; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap temp[j] and temp[j + 1]
                int tmp = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tmp;
            }
        }
    }

    // Copy trở lại ma trận
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[index++];
        }
    }


    printf("Ma tran sau khi sap xep zic zac:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    delete[] temp;
}

void sapXepDuongCheoChinh(ArrPtr& a, int n) {
    int* diag = new int[n];

    for (int i = 0; i < n; i++) {
        diag[i] = a[i][i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (diag[j] > diag[j + 1]) {
                int tmp = diag[j];
                diag[j] = diag[j + 1];
                diag[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][i] = diag[i];
    }

    printf("Ma tran sau khi sap xep duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    delete[] diag;
}

void xoaMaTran(ArrPtr& a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void sapXepDuongCheoPhu(ArrPtr& a, int n, bool tangDan) {
    int* diag = new int[n];

    for (int i = 0; i < n; i++) {
        diag[i] = a[i][n - 1 - i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((tangDan && diag[j] > diag[j + 1]) || (!tangDan && diag[j] < diag[j + 1])) {
                int tmp = diag[j];
                diag[j] = diag[j + 1];
                diag[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][n - 1 - i] = diag[i];
    }

    printf("Ma tran sau khi sap xep duong cheo phu (%s):\n", tangDan ? "tang dan" : "giam dan");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    delete[] diag;
}

void sapXepDong(ArrPtr& a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - 1 - j; k++) {
                if ((i % 2 == 0 && a[i][k] < a[i][k + 1]) || (i % 2 != 0 && a[i][k] > a[i][k + 1])) {
                    int tmp = a[i][k];
                    a[i][k] = a[i][k + 1];
                    a[i][k + 1] = tmp;
                }
            }
        }
    }

    printf("Ma tran sau khi sap xep dong:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void sapXepCot(ArrPtr& a, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = 0; k < n - 1 - i; k++) {
                if ((j % 2 == 0 && a[k][j] > a[k + 1][j]) || (j % 2 != 0 && a[k][j] < a[k + 1][j])) {
                    int tmp = a[k][j];
                    a[k][j] = a[k + 1][j];
                    a[k + 1][j] = tmp;
                }
            }
        }
    }

    printf("Ma tran sau khi sap xep cot:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}