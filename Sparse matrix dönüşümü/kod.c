#include <stdio.h>

int main() {
    int mat[4][4] = {
        {0, 0, 5, 0},
        {0, 0, 0, 0},
        {3, 0, 0, 0},
        {0, 0, 0, 2}
    };

    struct Sparse sp[10];  // max 10 sıfır olmayan eleman
    int k = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(mat[i][j] != 0) {
                sp[k].row = i;
                sp[k].col = j;
                sp[k].value = mat[i][j];
                k++;
            }
        }
    }

    // Sparse matrisi yazdır
    for(int i = 0; i < k; i++) {
        printf("%d %d %d\n", sp[i].row, sp[i].col, sp[i].value);
    }

    return 0;
}
