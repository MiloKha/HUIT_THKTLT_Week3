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
void menu();


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
        printf("2. Xuat cac phan tu tren duong cheo chinh\n");
        printf("3. Xuat cac phan tu thuoc duong cheo song song duong cheo chinh\n");
        printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
        printf("5. Sap xep ma tran theo kien zic zac\n");
        printf("6. Sap xep duong cheo chinh\n");
        printf("7. Thoat\n");
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
