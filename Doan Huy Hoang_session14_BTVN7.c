#include <stdio.h>
#include <stdbool.h>  
bool laNguyenTo(int n) {
    if (n < 2)
        return false; 

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false; 
    }

    return true; 
}

int main() {
    int n;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);

    if (laNguyenTo(n))
        printf("%d la so nguyen to.\n", n);
    else
        printf("%d khong phai so nguyen to.\n", n);

    return 0;
}

