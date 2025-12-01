#include <stdio.h>
#include <string.h>

char map[200][200];

// 绘制单个积木
// r, c 是【正面左上角 + 号】的坐标
void draw(int r, int c) {
    // 1. 顶面 (Top Face)
    map[r-2][c+2] = '+';
    map[r-2][c+3] = '-';
    map[r-2][c+4] = '+';

    map[r-1][c+1] = '/';
    map[r-1][c+2] = ' ';
    map[r-1][c+3] = '/';
    map[r-1][c+4] = '|';

    // 2. 正面 (Front Face)
    map[r][c]   = '+';
    map[r][c+1] = '-';
    map[r][c+2] = '+';
    map[r][c+3] = ' ';
    map[r][c+4] = '|';

    map[r+1][c]   = '|';
    map[r+1][c+1] = ' ';
    map[r+1][c+2] = '|';
    map[r+1][c+3] = '/';
    map[r+1][c+4] = '+';

    // 3. 底边 (Bottom Edge)
    map[r+2][c]   = '+';
    map[r+2][c+1] = '-';
    map[r+2][c+2] = '+';
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        memset(map, '.', sizeof(map));

        // === 修改点在这里 ===
        // 之前是 +3，导致顶部多了2行空行
        // 现在改为 +1，正好包裹住图形的最高点
        // H = 2*c (正面层叠) + 2*b (景深) + 1 (最后一行底)
        int H = 2 * c + 2 * b + 1;

        // 之前是 +3，改为 +1，正好包裹住最右边
        // W = 2*a (宽度) + 2*b (景深) + 1 (最右边的+)
        int W = 2 * a + 2 * b + 1;

        for (int x = 0; x < a; x++) {
            for (int y = 0; y < b; y++) {
                for (int z = 0; z < c; z++) {
                    int true_y = (b - 1) - y;

                    // 坐标计算公式
                    // H-1 是底线索引
                    // -2 回到正面左上角
                    // -2*z 垂直叠加
                    // -2*true_y 景深叠加
                    int r = (H - 1) - 2 - 2 * z - 2 * true_y;
                    int col = 2 * x + 2 * true_y;

                    draw(r, col);
                }
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] == '.') printf(" ");
                else printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}