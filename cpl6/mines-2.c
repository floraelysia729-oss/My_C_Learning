#include <stdio.h>

// 全局变量方便调用，但在作业中也可以放main里
int n;
// 方向数组：前后左右上下
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

// 检查某个位置 (x,y,z) 周围有多少个雷
// is_q_mine: 1 表示把 '?' 当作雷，0 表示把 '?' 当作没雷
int count_mines(char map[n][n][n], int x, int y, int z, int is_q_mine) {
    int count = 0;
    for (int k = 0; k < 6; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        int nz = z + dz[k];

        // 边界检查
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && nz >= 0 && nz < n) {
            char neighbor = map[nx][ny][nz];
            if (neighbor == '*') {
                count++;
            } else if (neighbor == '?') {
                // 如果邻居是 ?，根据传入的假设决定算不算雷
                if (is_q_mine) count++;
            }
        }
    }
    return count;
}

int main() {
    scanf("%d", &n);

    // VLA (变长数组) 在 C99 标准下是合法的
    char map[n][n][n];
    int qx, qy, qz; // 用来存 '?' 的位置

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                scanf(" %c", &map[x][y][z]);
                if (map[x][y][z] == '?') {
                    qx = x; qy = y; qz = z;
                }
            }
        }
    }

    // --- 场景 A：假设 ? 不是雷 ---
    int valid_no_mine = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                // 只检查数字格
                if (map[x][y][z] >= '0' && map[x][y][z] <= '9') {
                    int expected = map[x][y][z] - '0';
                    // 传入 0，表示假设 ? 不是雷
                    if (count_mines(map, x, y, z, 0) != expected) {
                        valid_no_mine = 0;
                    }
                }
            }
        }
    }

    // --- 场景 B：假设 ? 是雷 ---
    int valid_has_mine = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                if (map[x][y][z] >= '0' && map[x][y][z] <= '9') {
                    int expected = map[x][y][z] - '0';
                    // 传入 1，表示假设 ? 是雷
                    if (count_mines(map, x, y, z, 1) != expected) {
                        valid_has_mine = 0;
                    }
                }
            }
        }
    }

    // --- 输出逻辑 ---

    // 优先选“雷最少”的情况，也就是场景 A (valid_no_mine)
    if (valid_no_mine) {
        printf("valid\n");
        // 如果 ? 没雷，填入它周围的雷数 (此时 ? 被视为无雷)
        printf("%d\n", count_mines(map, qx, qy, qz, 0));
    }
    else if (valid_has_mine) {
        printf("valid\n");
        printf("*\n");
    }
    else {
        // 都不合法
        printf("invalid\n");
        // 题目要求：输出 invalid 时，输出“? 处有雷情况下”不正确的坐标
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    if (map[x][y][z] >= '0' && map[x][y][z] <= '9') {
                        int expected = map[x][y][z] - '0';
                        // 再次计算场景 B (假设 ? 是雷)
                        if (count_mines(map, x, y, z, 1) != expected) {
                            // 题目坐标从1开始，并且按照字典序 (x,y,z 循环顺序天然满足字典序)
                            printf("%d %d %d\n", x + 1, y + 1, z + 1);
                        }
                    }
                }
            }
        }
    }

    return 0;
}