#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 必须开得足够大
int target_x[400000];
int target_y[400000];

int main()
{
    int n=0,m=0,d=0;
    scanf("%d%d%d",&n,&m,&d);

    int map0[n][m];
    for (int row=0;row<n;row++)
    {
        for (int col=0;col<m;col++)
        {
            scanf("%d",&map0[row][col]);
        }
    }

    // map 外扩 d
    // map[d][d] 对应 map0[0][0] (也就是逻辑坐标 1,1)
    int n1=n+2*d,m1=m+2*d;
    int map[n1][m1];
    memset(map,0,sizeof(map));
    for (int row=0;row<n;row++)
    {
        for (int col=0;col<m;col++)
        {
            map[row+d][col+d]=map0[row][col];
        }
    }

    long long now_value=0; // 用 long long 防止溢出
    int count=0;
    long long max_value = -9999999999999LL; // 初始值设极小

    for (int x=1;x<=n;x++)
    {
        now_value = 0; // 【重要】换行必须清零

        // === 修正1：计算该行第1个点 (x, 1) ===
        // 中心在 map 中的坐标是：行 (x-1+d), 列 (1-1+d) 即 d
        // 只遍历菱形区域，不要遍历整个 map (否则会超时)
        int center_row = x - 1 + d;
        int center_col = d;

        for (int r = center_row - d; r <= center_row + d; r++)
        {
            for (int c = center_col - d; c <= center_col + d; c++)
            {
                if (abs(r - center_row) + abs(c - center_col) <= d)
                {
                    now_value += map[r][c];
                }
            }
        }

        // 打擂台 (第1个点)
        if (max_value==now_value)
        {
            target_x[count]=x; target_y[count]=1;
            count++;
        }
        else if (max_value<now_value)
        {
            max_value=now_value;
            count=0;
            target_x[count]=x; target_y[count]=1;
            count++;
        }

        // === 修正2：向右滑动 (col 从 2 到 m) ===
        for (int col=2;col<=m;col++)
        {
            long long diff=0;
            for (int k=-d;k<=d;k++)
            {
                int width = d-abs(k);

                // 当前行的 map 索引
                int r = (x - 1 + d) + k;

                // 减去旧左边：上一个中心是 (col-1)，其 map 列索引是 (col-2+d)
                // 左边界 = 中心 - width
                int old_col = (col - 2 + d) - width;
                diff -= map[r][old_col];

                // 加上新右边：当前中心是 (col)，其 map 列索引是 (col-1+d)
                // 右边界 = 中心 + width
                int new_col = (col - 1 + d) + width;
                diff += map[r][new_col];
            }
            now_value += diff;

            // 打擂台 (后续的点)
            if (max_value==now_value)
            {
                target_x[count]=x; target_y[count]=col; // 这里记 col
                count++;
            }
            else if (max_value<now_value)
            {
                max_value=now_value;
                count=0;
                target_x[count]=x; target_y[count]=col; // 这里记 col
                count++;
            }
        }
    }

    printf("%lld %d\n",max_value, count);
    for (int i=0;i<count;i++)
    {
        printf("%d %d\n",target_x[i],target_y[i]); // 这里用 i
    }

    return 0;
}