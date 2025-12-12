#include<stdio.h>
#include<string.h>

typedef struct
{
    int index;
    int para[1000005];
} arr;

// 全局变量定义，防止栈溢出
arr P1;
arr P2;
arr add;

int main()
{
    // 【修改点1】 将单个字符 char 改为字符数组（字符串），长度设为100够用了
    char x1[100];
    char x2[100];

    P1.index=0; P2.index=0;

    scanf("%d %d", &P1.index, &P2.index);

    // 【修改点2】 使用 %s 读取字符串
    // 注意：x1 和 x2 是数组名，本身就是地址，所以不需要加 &
    scanf("%s %s", x1, x2);

    memset(P1.para, 0, 1000005 * sizeof(int));
    memset(P2.para, 0, 1000005 * sizeof(int));

    for (int i=P1.index; i>=0; i--)
    {
        scanf("%d", &P1.para[i]);
    }
    for (int i=P2.index; i>=0; i--)
    {
        scanf("%d", &P2.para[i]);
    }

    // --- 加法 ---
    // 【修改点3】 下面所有的 printf 中，原来的 %c%c 全部改为 %s%s

    int max = (P1.index > P2.index) ? P1.index : P2.index;
    for (int i=max; i>=0; i--)
    {
        add.para[i] = P1.para[i] + P2.para[i];
        if (i==max)
        {
            if (add.para[i] != 1)
            {
                // %c -> %s
                printf("%d%s%s^%d", add.para[i], x1, x2, i);
            }
            else
            {
                printf("%s%s^%d", x1, x2, i);
            }
        }
        else if (i<max && i>1)
        {
            if (add.para[i] > 0)
            {
                if (add.para[i] != 1)
                {
                    printf("+%d%s%s^%d", add.para[i], x1, x2, i);
                }
                else
                {
                    printf("+%s%s^%d", x1, x2, i);
                }
            }
            else if (add.para[i] == 0)
            {
                continue;
            }
            else
            {
                if (add.para[i] != -1)
                {
                    printf("%d%s%s^%d", add.para[i], x1, x2, i);
                }
                else
                {
                    printf("-%s%s^%d", x1, x2, i);
                }
            }
        }
        else if (i==1)
        {
            if (add.para[i] > 0)
            {
                if (add.para[i] != 1)
                {
                    printf("+%d%s%s", add.para[i], x1, x2);
                }
                else
                {
                    printf("+%s%s", x1, x2);
                }
            }
            else if (add.para[i] == 0)
            {
                continue;
            }
            else
            {
                if (add.para[i] != -1)
                {
                    printf("%d%s%s", add.para[i], x1, x2);
                }
                else
                {
                    printf("-%s%s", x1, x2);
                }
            }
        }
        else if (i==0 && add.para[0] != 0)
        {
            if (add.para[i] > 0){
                printf("+%d", add.para[i]);
            }
            else
            {
                printf("%d", add.para[i]);
            }
        }
    }
    printf("\n");


    // --- 减法 ---
    for (int i=max; i>=0; i--)
    {
        add.para[i] = P1.para[i] - P2.para[i];
        if (i==max)
        {
            if (add.para[i] != 1)
            {
                printf("%d%s%s^%d", add.para[i], x1, x2, i);
            }
            else
            {
                printf("%s%s^%d", x1, x2, i);
            }
        }
        else if (i<max && i>1)
        {
            if (add.para[i] > 0)
            {
                if (add.para[i] != 1)
                {
                    printf("+%d%s%s^%d", add.para[i], x1, x2, i);
                }
                else
                {
                    printf("+%s%s^%d", x1, x2, i);
                }
            }
            else if (add.para[i] == 0)
            {
                continue;
            }
            else
            {
                if (add.para[i] != -1)
                {
                    printf("%d%s%s^%d", add.para[i], x1, x2, i);
                }
                else
                {
                    printf("-%s%s^%d", x1, x2, i);
                }
            }
        }
        else if (i==1)
        {
            if (add.para[i] > 0)
            {
                if (add.para[i] != 1)
                {
                    printf("+%d%s%s", add.para[i], x1, x2);
                }
                else
                {
                    printf("+%s%s", x1, x2);
                }
            }
            else if (add.para[i] == 0)
            {
                continue;
            }
            else
            {
                if (add.para[i] != -1)
                {
                    printf("%d%s%s", add.para[i], x1, x2);
                }
                else
                {
                    printf("-%s%s", x1, x2);
                }
            }
        }
        else if (i==0 && add.para[0] != 0)
        {
            if (add.para[i] > 0){
                printf("+%d", add.para[i]);
            }
            else
            {
                printf("%d", add.para[i]);
            }
        }
    }
    printf("\n");



    // --- 乘法 ---
    max = P1.index + P2.index;
    memset(add.para, 0, 1000005 * sizeof(int));

    for (int i1=P1.index; i1>=0; i1--)
    {
        for (int i2=P2.index; i2>=0; i2--)
        {
            int i = i1 + i2;
            add.para[i] += P1.para[i1] * P2.para[i2];
        }
    }

    for (int i=max; i>=0; i--)
    {
        if (i==max)
        {
            if (add.para[i] != 1)
            {
                printf("%d%s%s^%d", add.para[i], x1, x2, i);
            }
            else
            {
                printf("%s%s^%d", x1, x2, i);
            }
        }
        else if (i<max && i>1)
        {
            if (add.para[i] > 0)
            {
                if (add.para[i] != 1)
                {
                    printf("+%d%s%s^%d", add.para[i], x1, x2, i);
                }
                else
                {
                    printf("+%s%s^%d", x1, x2, i);
                }
            }
            else if (add.para[i] == 0)
            {
                continue;
            }
            else
            {
                if (add.para[i] != -1)
                {
                    printf("%d%s%s^%d", add.para[i], x1, x2, i);
                }
                else
                {
                    printf("-%s%s^%d", x1, x2, i);
                }
            }
        }
        else if (i==1)
        {
            if (add.para[i] > 0)
            {
                if (add.para[i] != 1)
                {
                    printf("+%d%s%s", add.para[i], x1, x2);
                }
                else
                {
                    printf("+%s%s", x1, x2);
                }
            }
            else if (add.para[i] == 0)
            {
                continue;
            }
            else
            {
                if (add.para[i] != -1)
                {
                    printf("%d%s%s", add.para[i], x1, x2);
                }
                else
                {
                    printf("-%s%s", x1, x2);
                }
            }
        }
        else if (i==0 && add.para[0] != 0)
        {
            if (add.para[i] > 0){
                printf("+%d", add.para[i]);
            }
            else
            {
                printf("%d", add.para[i]);
            }
        }
    }
    printf("\n");

    return 0;
}