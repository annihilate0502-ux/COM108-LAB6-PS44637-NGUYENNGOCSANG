#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void lamMinTinHieu(float raw[], float smooth[], int n);

#ifndef UNIT_TEST
int main() {
    int n;
    float raw[100];
    float smooth[100];

    printf("Nhap so luong mau tin hieu cam bien (n > 0): ");
    scanf("%d", &n);

    if (n <= 0 || n > (int)(sizeof(raw) / sizeof(raw[0]))) {
        printf("So luong mau khong hop le!\n");
        return 0;
    }

    printf("Nhap %d gia tri tin hieu tho:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  raw[%d] = ", i);
        scanf("%f", &raw[i]);
    }

    lamMinTinHieu(raw, smooth, n);

    printf("\n--- KET QUA LAM MIN TIN HIEU (MOVING AVERAGE) ---\n");
    printf("Tin hieu goc: ");
    for (int i = 0; i < n; i++) printf("%.2f ", raw[i]);
    printf("\nTin hieu min: ");
    for (int i = 0; i < n; i++) printf("%.2f ", smooth[i]);
    printf("\n");

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void lamMinTinHieu(float raw[], float smooth[], int n) {
    if (n <= 0) {
        return;
    }

    if (n == 1) {
        smooth[0] = raw[0];
        return;
    }

    smooth[0] = (raw[0] + raw[1]) / 2.0f;

    for (int i = 1; i < n - 1; i++) {
        smooth[i] = (raw[i - 1] + raw[i] + raw[i + 1]) / 3.0f;
    }

    smooth[n - 1] = (raw[n - 2] + raw[n - 1]) / 2.0f;
}
