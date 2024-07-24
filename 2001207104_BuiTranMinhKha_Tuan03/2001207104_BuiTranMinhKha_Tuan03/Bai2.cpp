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
