#include <stdio.h>

int timMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max; 
}

int main() {
    int a[100];
    int n;

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    int max = timMax(a, n);
    printf("So lon nhat trong mang la: %d\n", max);

    return 0;
}

