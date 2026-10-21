#include <stdio.h>

#define MAX_COLS 100

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int doDiemNong(int a[][MAX_COLS], int row, int col, int hangPeak[], int cotPeak[], int nhietDoPeak[]);

#ifndef UNIT_TEST
int main() {
    int row, col;
    int a[100][MAX_COLS];
    int hangPeak[10000], cotPeak[10000], nhietDoPeak[10000];

    printf("Nhap so hang luoi cam bien (row > 0): ");
    scanf("%d", &row);
    printf("Nhap so cot  luoi cam bien (col > 0): ");
    scanf("%d", &col);

    if (row <= 0 || col <= 0 || row > 100 || col > 100) {
        printf("Kich thuoc luoi cam bien khong hop le!\n");
        return 0;
    }

    printf("Nhap nhiet do tai cac o cam bien (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("  a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int soLuong = doDiemNong(a, row, col, hangPeak, cotPeak, nhietDoPeak);

    printf("\n--- CANH BAO RADAR: DIEM NONG QUAN TRONG ---\n");
    if (soLuong == 0) {
        printf("An toan: Khong phat hien diem nong qua nhiet tren luoi.\n");
    } else {
        printf("Phat hien %d diem nong bat thuong:\n", soLuong);
        for (int k = 0; k < soLuong; k++) {
            printf("  [!] Diem nong tai a[%d][%d] = %d do C\n",
                   hangPeak[k], cotPeak[k], nhietDoPeak[k]);
        }
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int doDiemNong(int a[][MAX_COLS], int row, int col, int hangPeak[], int cotPeak[], int nhietDoPeak[]) {
    if (row <= 0 || col <= 0 || col > MAX_COLS) {
        return 0;
    }

    int soLuong = 0;
    const int hangLanCan[] = {-1, 1, 0, 0};
    const int cotLanCan[] = {0, 0, -1, 1};

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int laDiemNong = 1;

            for (int huong = 0; huong < 4; huong++) {
                int r = i + hangLanCan[huong];
                int c = j + cotLanCan[huong];

                if (r >= 0 && r < row && c >= 0 && c < col &&
                    a[i][j] <= a[r][c]) {
                    laDiemNong = 0;
                    break;
                }
            }

            if (laDiemNong) {
                hangPeak[soLuong] = i;
                cotPeak[soLuong] = j;
                nhietDoPeak[soLuong] = a[i][j];
                soLuong++;
            }
        }
    }

    return soLuong;
}
