#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n = 0;
    if(scanf("%d", &n) != 1) return 0;

    // 申请内存
    char* p = (char*)malloc(1005 * sizeof(char));
    char* temp = (char*)malloc(1005 * sizeof(char));

    // 初始化
    memset(p, 0, 1005);
    scanf("%s", p);

    // 计算长度 (p是地址，可以直接传给strlen)
    int len = strlen(p);

    while (n--)
    {
        strcpy(temp, p); // 备份：把 p 指向的内容拷贝到 temp 指向的内存

        // 用偏移量遍历，方便做边界检查
        for (int now = 0; now < len; now++)
        {
            // === 统计部分 ===
            int countA = 0;
            int countB = 0;

            for (int i = -3; i <= 3; i++)
            {
                if (i == 0) continue;

                int neighbor_idx = now + i;

                // 边界检查
                if (neighbor_idx >= 0 && neighbor_idx < len)
                {
                    // 【关键点】用指针算术代替 []
                    // p[neighbor_idx] 变成了 *(p + neighbor_idx)
                    char val = *(p + neighbor_idx);

                    if (val == 'A') countA++;
                    if (val == 'B') countB++;
                }
            }

            // === 规则部分 ===
            // 【关键点】p[now] 变成了 *(p + now)
            char me = *(p + now);

            if (me == 'A')
            {
                if (countB > 0)
                    *(temp + now) = '.'; // 有敌人死
                else {
                    // 按照你要求的 2,3,4 存活
                    if (countA >= 2 && countA <= 4) *(temp + now) = 'A';
                    else *(temp + now) = '.';
                }
            }
            else if (me == 'B')
            {
                if (countA > 0)
                    *(temp + now) = '.'; // 有敌人死
                else {
                    if (countB >= 2 && countB <= 4) *(temp + now) = 'B';
                    else *(temp + now) = '.';
                }
            }
            else // 如果是空地 (me == '.')
            {
                // 出生逻辑：周围有 2-4 个同伴且无敌人，则出生
                if (countA >= 2 && countA <= 4 && countB == 0)
                    *(temp + now) = 'A';
                else if (countB >= 2 && countB <= 4 && countA == 0)
                    *(temp + now) = 'B';
                else
                    *(temp + now) = '.';
            }
        }

        strcpy(p, temp); // 同步更新：把 temp 拷回 p
        printf("%s\n", p);
    }

    free(p);
    free(temp);
    return 0;
}