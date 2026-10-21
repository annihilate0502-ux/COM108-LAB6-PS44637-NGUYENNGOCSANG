#include <stdio.h>

#define MAX_COLS 100

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void lamMoMaTran(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col);

#ifndef UNIT_TEST
int main() {
    int row, col;
    int src[100][MAX_COLS];
    int dest[100][MAX_COLS];

    printf("Nhap so hang (row > 0): ");
    scanf("%d", &row);
    printf("Nhap so cot  (col > 0): ");
    scanf("%d", &col);

    if (row <= 0 || col <= 0 || row > 100 || col > 100) {
        printf("Kich thuoc ma tran khong hop le!\n");
        return 0;
    }

    printf("Nhap cac diem anh cua ma tran (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("  src[%d][%d] = ", i, j);
            scanf("%d", &src[i][j]);
        }
    }

    lamMoMaTran(src, dest, row, col);

    printf("\n--- MA TRAN ANH DA LAM MO (BOX BLUR 3x3) ---\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", dest[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void lamMoMaTran(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col) {
    if (row <= 0 || col <= 0 || col > MAX_COLS) {
        return;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            long long tong = 0;
            int soLuong = 0;

            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    if (r >= 0 && r < row && c >= 0 && c < col) {
                        tong += src[r][c];
                        soLuong++;
                    }
                }
            }

            dest[i][j] = (int)(tong / soLuong);
        }
    }
}
