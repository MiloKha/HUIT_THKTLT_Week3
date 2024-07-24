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
void xuatMaxTrenTungCot(ArrPtr* a, int m, int n);
void xuatPhanTuDuongBien(ArrPtr* a, int m, int n);
void xuatPhanTuCucDai(ArrPtr* a, int m, int n);
void xuatPhanTuHoangHau(ArrPtr* a, int m, int n);
int timMin_DongK(ArrPtr* a, int m, int n, int k);
int timMax_CotK(ArrPtr* a, int m, int n, int k);
void lietKePhanTuYenNgua(ArrPtr* a, int m, int n);
void xuatDongChiChuaSoChan(ArrPtr* a, int m, int n);
void sapXep_TangDan_DongK(ArrPtr*& a, int m, int n, int k);
void sapXep_TangDan_TungDong(ArrPtr*& a, int m, int n);
void hoanVi(ItemType& x, ItemType& y);

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
        case 3:
            if (a != NULL) {
                xuatMaxTrenTungCot(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 4:
            if (a != NULL) {
                xuatPhanTuDuongBien(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 5:
            if (a != NULL) {
                xuatPhanTuCucDai(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 6:
            if (a != NULL) {
                xuatPhanTuHoangHau(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 7:
            if (a != NULL) {
                lietKePhanTuYenNgua(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 8:
            if (a != NULL) {
                xuatDongChiChuaSoChan(a, m, n);
            }
            else {
                printf("Ma tran chua duoc tao.\n");
            }
            break;
        case 9:
            if (a != NULL) {
                sapXep_TangDan_TungDong(a, m, n);
                xuatMang2C_SoNguyen(a, m, n);
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

void xuatMaxTrenTungCot(ArrPtr* a, int m, int n) {
    for (int j = 0; j < n; j++) {
        int vmax = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > vmax) {
                vmax = a[i][j];
            }
        }
        printf("Gia tri lon nhat tren cot %d: %d\n", j, vmax);
    }
}

void xuatPhanTuDuongBien(ArrPtr* a, int m, int n) {
    printf("Cac phan tu tren duong bien:\n");
    for (int j = 0; j < n; j++) printf("%4d", a[0][j]); // tren
    for (int j = n - 1; j >= 0; j--) printf("%4d", a[m - 1][j]); // duoi
    for (int i = m - 2; i > 0; i--) printf("%4d", a[i][0]); // trai
    for (int i = 1; i < m - 1; i++) printf("%4d", a[i][n - 1]); // phai
    printf("\n");
}

void xuatPhanTuCucDai(ArrPtr* a, int m, int n) {

    printf("Cac phan tu cuc dai:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool isCucDai = true;

            // ktra tren
            if (i > 0 && a[i][j] <= a[i - 1][j]) {
                isCucDai = false;
            }
            // ktra duoi
            if (i < m - 1 && a[i][j] <= a[i + 1][j]) {
                isCucDai = false;
            }
            // ktra trai
            if (j > 0 && a[i][j] <= a[i][j - 1]) {
                isCucDai = false;
            }
            // ktra phai
            if (j < n - 1 && a[i][j] <= a[i][j + 1]) {
                isCucDai = false;
            }

            if (isCucDai) {
                printf("%4d", a[i][j]);
            }
        }
    }
    printf("\n");
}

void xuatPhanTuHoangHau(ArrPtr* a, int m, int n) {
    printf("Cac phan tu hoang hau:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int vmax = a[i][j];
            int k;
            for (k = 0; k < n; k++) {
                if (a[i][k] > vmax) 
                    break;
            }
            if (k == n) {
                for (k = 0; k < m; k++) {
                    if (a[k][j] > vmax) 
                        break;
                }
                if (k == m) {
                    printf("%4d", a[i][j]);
                }
            }
        }
    }
    printf("\n");
}

int timMin_DongK(ArrPtr* a, int m, int n, int k) {
    int vmin = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] < vmin) {
            vmin = a[k][j];
        }
    }
    return vmin;
}

int timMax_CotK(ArrPtr* a, int m, int n, int k) {
    int vmax = a[0][k];
    for (int i = 1; i < m; i++) {
        if (a[i][k] > vmax) {
            vmax = a[i][k];
        }
    }
    return vmax;
}

void lietKePhanTuYenNgua(ArrPtr* a, int m, int n) {
    printf("Cac phan tu yen ngua:\n");
    int count = 0; 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int vmin = timMin_DongK(a, m, n, i);
            int vmax = timMax_CotK(a, m, n, j);

            if (a[i][j] == vmin && a[i][j] == vmax) {
                printf("%4d ", a[i][j]);
                count++;
            }
        }
    }

    if (count == 0) {
        printf("Khong co phan tu yen ngua nao.\n");
    }
    else {
        printf("\n");
    }
}

void xuatDongChiChuaSoChan(ArrPtr* a, int m, int n) {
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) break;
        }
        if (j == n) {
            for (j = 0; j < n; j++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}

void hoanVi(ItemType& x, ItemType& y) {
    ItemType temp = x;
    x = y;
    y = temp;
}

void sapXep_TangDan_DongK(ArrPtr*& a, int m, int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[k][i] > a[k][j]) {
                hoanVi(a[k][i], a[k][j]);
            }
        }
    }
}

void sapXep_TangDan_TungDong(ArrPtr*& a, int m, int n) {
    for (int i = 0; i < m; i++) {
        sapXep_TangDan_DongK(a, m, n, i);
    }
}