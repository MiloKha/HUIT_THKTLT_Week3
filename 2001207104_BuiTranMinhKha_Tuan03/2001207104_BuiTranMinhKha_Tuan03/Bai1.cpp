#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 
typedef int ItemType;
typedef ItemType* ArrPtr;

void initArrayPoiter(ArrPtr*& a, ItemType& m, ItemType& n);
void deleteArrayPoiter(ArrPtr*& a, ItemType m, ItemType n);
void nhapSoNguyenDuong(int& x);
void nhapMang2C_SoNguyen(ArrPtr*& a, ItemType& m, ItemType& n);
void taoNgauNhienMang2C_SoNguyen(ArrPtr*& a, ItemType& m, ItemType& n);
void xuatMang2C_SoNguyen(ArrPtr*& a, ItemType m, ItemType n);
void tinhTongGiaTriTungDong(ArrPtr* a, int m, int n);



int main() {
    ArrPtr* a = NULL; 
    ItemType m = 0, n = 0; 
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Tao va xuat ma tran chua cac phan tu ngau nhien.\n");
        printf("2. Tinh va xuat tong gia tri tung dong.\n");
        printf("3. Xuat phan tu lon nhat tren tung cot.\n");
        printf("4. Xuat cac phan tu thuoc cac duong bien.\n");
        printf("5. Xuat cac phan tu cuc dai.\n");
        printf("6. Xuat cac phan tu hoang hau.\n");
        printf("7. Xuat cac phan tu la diem yen ngua.\n");
        printf("8. Xuat dong chi chua so chan.\n");
        printf("9. Sap xep mang tang theo tung dong.\n");
        printf("0. Thoat.\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            taoNgauNhienMang2C_SoNguyen(a, m, n);
            xuatMang2C_SoNguyen(a, m, n);
            break;
        case 2:
            if (a != NULL) {
                tinhTongGiaTriTungDong(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 0:
            deleteArrayPoiter(a, m, n);
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}


void initArrayPoiter(ArrPtr*& a, ItemType& m, ItemType& n) {
    a = (ArrPtr*)malloc(m * sizeof(ArrPtr));
    for (int i = 0; i < m; i++) {
        a[i] = (ItemType*)malloc(n * sizeof(ItemType));
    }
}

void deleteArrayPoiter(ArrPtr*& a, ItemType m, ItemType n) {
    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
}

void nhapSoNguyenDuong(int& x) {
    do {
        scanf_s("%d", &x);
    } while (x <= 0);
}

void nhapMang2C_SoNguyen(ArrPtr*& a, ItemType& m, ItemType& n) {
    printf("Nhap so dong: ");
    nhapSoNguyenDuong(m);
    printf("Nhap so cot: ");
    nhapSoNguyenDuong(n);
    initArrayPoiter(a, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }
}

void taoNgauNhienMang2C_SoNguyen(ArrPtr*& a, ItemType& m, ItemType& n) {
    printf("Nhap so dong: ");
    nhapSoNguyenDuong(m);
    printf("Nhap so cot: ");
    nhapSoNguyenDuong(n);
    initArrayPoiter(a, m, n);
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100; 
        }
    }
}

void xuatMang2C_SoNguyen(ArrPtr*& a, ItemType m, ItemType n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTongGiaTriTungDong(ArrPtr* a, int m, int n) {
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        printf("Tong gia tri dong %d: %d\n", i, sum);
    }
}