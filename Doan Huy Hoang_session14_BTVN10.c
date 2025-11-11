#include <stdio.h>

#define MAX 100

void nhapMang(int a[], int *n);
void inMang(int a[], int n);
void themPhanTu(int a[], int *n, int pos, int value);
void suaPhanTu(int a[], int n, int pos, int value);
void xoaPhanTu(int a[], int *n, int pos);
void sapXepTang(int a[], int n);
void sapXepGiam(int a[], int n);
int timKiemTuyenTinh(int a[], int n, int x);
int timKiemNhiPhan(int a[], int n, int x);

int main() {
    int a[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap so luong va gia tri cac phan tu\n");
        printf("2. In cac phan tu trong mang\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("===========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(a, &n);
                break;
            case 2:
                inMang(a, n);
                break;
            case 3: {
                int pos, value;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                themPhanTu(a, &n, pos, value);
                break;
            }
            case 4: {
                int pos, value;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                suaPhanTu(a, n, pos, value);
                break;
            }
            case 5: {
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                xoaPhanTu(a, &n, pos);
                break;
            }
            case 6: {
                char opt;
                printf("\na. Giam dan\nb. Tang dan\nChon (a/b): ");
                scanf(" %c", &opt);
                if (opt == 'a') sapXepGiam(a, n);
                else if (opt == 'b') sapXepTang(a, n);
                else printf("Lua chon khong hop le!\n");
                break;
            }
            case 7: {
                char opt;
                int x;
                printf("\nNhap gia tri can tim: ");
                scanf("%d", &x);
                printf("a. Tim kiem tuyen tinh\nb. Tim kiem nhi phan\nChon (a/b): ");
                scanf(" %c", &opt);
                int kq;
                if (opt == 'a')
                    kq = timKiemTuyenTinh(a, n, x);
                else
                    kq = timKiemNhiPhan(a, n, x);

                if (kq != -1)
                    printf("Tim thay %d tai vi tri %d\n", x, kq);
                else
                    printf("Khong tim thay %d trong mang\n", x);
                break;
            }
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

void nhapMang(int a[], int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void inMang(int a[], int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void themPhanTu(int a[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
    (*n)++;
    printf("Da them thanh cong!\n");
}


void suaPhanTu(int a[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    a[pos] = value;
    printf("Da sua thanh cong!\n");
}

void xoaPhanTu(int a[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
    printf("Da xoa thanh cong!\n");
}

void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf("Da sap xep tang dan!\n");
}


void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf("Da sap xep giam dan!\n");
}


int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

