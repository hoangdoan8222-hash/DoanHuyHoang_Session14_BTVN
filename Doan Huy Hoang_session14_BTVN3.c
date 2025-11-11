#include <stdio.h>

int tinhTong(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    printf("Nhap 2 so nguyen: ");
    scanf("%d%d", &x, &y);

    int tong = tinhTong(x, y);  
    printf("Tong = %d\n", tong);

    return 0;
}

