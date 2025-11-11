#include <stdio.h>

long long giaiThua(int n) {
    long long gt = 1;
    for (int i = 1; i <= n; i++) {
        gt *= i;
    }
    return gt;
}

int main() {
    int n;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Khong co giai thua cho so am!\n");
    else
        printf("Giai thua cua %d la: %lld\n", n, giaiThua(n));

    return 0;
}

