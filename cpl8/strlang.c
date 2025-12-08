#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 结构体定义
typedef struct {
    char mod1[50];
    char strA[10000000];
    char mod2[50];
    char strB[10000000];
} Instruction;

Instruction cmds[405];

// 定义一个足够大的静态辅助数组，防止爆栈
// 为什么用 static？因为它不占用函数栈空间，而且每次调用时我们可以重复利用它
static char temp_buf[20000000000];

// --- 修复后的 operate1 (包含 substring 的情况) ---
char* operate1(char *s, char *s1, char *s2, char *mod)
{
    char *find = strstr(s, s1);

    // 如果找不到，或者 s1 是空字符串（防止死循环），直接返回
    if (find == NULL || strlen(s1) == 0) {
        return s;
    }

    // --- 核心修复逻辑 ---
    // 我们不直接在 s 上改，而是把结果拼接到 temp_buf 里，最后再拷回 s

    int prefix_len = find - s; // s1 前面的长度
    int s1_len = strlen(s1);

    temp_buf[0] = '\0'; // 清空缓冲

    // 1. 如果是普通替换 (.)
    if (strcmp(mod, ".") == 0) {
        strncat(temp_buf, s, prefix_len); // 复制 s1 前面的部分
        strcat(temp_buf, s2);             // 拼接 s2
        strcat(temp_buf, find + s1_len);  // 拼接 s1 后面的部分
    }
    // 2. 如果是移到开头 (^)
    else if (strcmp(mod, "^") == 0) {
        strcpy(temp_buf, s2);             // 先放 s2
        strncat(temp_buf, s, prefix_len); // 再放 s1 前面的
        strcat(temp_buf, find + s1_len);  // 再放 s1 后面的 (也就是把 s1 删了)
    }
    // 3. 如果是移到结尾 ($)
    else if (strcmp(mod, "$") == 0) {
        strncat(temp_buf, s, prefix_len); // 先放 s1 前面的
        strcat(temp_buf, find + s1_len);  // 再放 s1 后面的 (把 s1 删了)
        strcat(temp_buf, s2);             // 最后放 s2
    }

    // 把拼好的结果拷回 s
    strcpy(s, temp_buf);
    return s;
}

// --- 修复后的 operate2 (开头匹配 ^) ---
char* operate2(char *s, char *s1, char *s2, char *mod)
{
    // 检查 s 是否以 s1 开头
    // 方法：strstr 找到的位置必须等于 s 的首地址
    char *find = strstr(s, s1);
    if (find != s) { // 如果没找到，或者找到的不是第一个
        return s;
    }

    int s1_len = strlen(s1);
    temp_buf[0] = '\0';

    if (strcmp(mod, ".") == 0) {
        strcat(temp_buf, s2);            // 替换成 s2
        strcat(temp_buf, s + s1_len);    // 拼接剩下的
    }
    else if (strcmp(mod, "^") == 0) {
        strcat(temp_buf, s2);            // 放在开头
        strcat(temp_buf, s + s1_len);    // 拼接剩下的 (其实和上面一样)
    }
    else if (strcmp(mod, "$") == 0) {
        strcat(temp_buf, s + s1_len);    // 拼接剩下的 (s1 被删了)
        strcat(temp_buf, s2);            // s2 放到最后
    }

    strcpy(s, temp_buf);
    return s;
}

// --- 修复后的 operate3 (结尾匹配 $) ---
char* operate3(char *s, char *s1, char *s2, char *mod)
{
    int s_len = strlen(s);
    int s1_len = strlen(s1);

    // 如果 s 比 s1 还短，肯定不匹配
    if (s_len < s1_len) return s;

    // 检查后缀：比较 s 的最后 s1_len 个字符
    char *suffix_start = s + s_len - s1_len;
    if (strcmp(suffix_start, s1) != 0) {
        return s;
    }

    temp_buf[0] = '\0';

    if (strcmp(mod, ".") == 0) {
        strncat(temp_buf, s, s_len - s1_len); // 复制前面的
        strcat(temp_buf, s2);                 // 替换尾巴为 s2
    }
    else if (strcmp(mod, "^") == 0) {
        strcat(temp_buf, s2);                 // s2 放到开头
        strncat(temp_buf, s, s_len - s1_len); // 复制前面的 (s1 被删了)
    }
    else if (strcmp(mod, "$") == 0) {
        strncat(temp_buf, s, s_len - s1_len); // 复制前面的
        strcat(temp_buf, s2);                 // s2 放到结尾 (其实和情况1一样)
    }

    strcpy(s, temp_buf);
    return s;
}

// --- Main 函数 (保持之前的结构，无需改动) ---
int main()
{
    int n = 0;
    if (scanf("%d", &n) != 1) return 0;

    char buffer[2000000000];

    // 1. 读入指令
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        char *p1 = strchr(buffer, '[');
        char *p2 = strchr(p1, ']');
        char *p3 = strchr(p2 + 1, '[');
        char *p4 = strchr(p3, ']');

        *p1 = '\0'; *p2 = '\0'; *p3 = '\0'; *p4 = '\0';

        strcpy(cmds[i].mod1, buffer);
        strcpy(cmds[i].strA, p1 + 1);
        strcpy(cmds[i].mod2, p2 + 1);
        strcpy(cmds[i].strB, p3 + 1);
    }

    // 2. 读入主字符串 (开大内存)
    char *s = (char*)calloc(20000000000, sizeof(char));
    scanf("%s", s);

    // 3. 循环执行
    int found = 1;
    // 这里的 temp_check 是用来检测 s 是否发生了变化
    // 为了防止反复申请内存，我在循环外申请
    char *temp_check = (char*)calloc(20000000000, sizeof(char));

    while (found) {
        found = 0;

        for (int i = 0; i < n; i++) {
            strcpy(temp_check, s); // 备份当前状态

            if (strcmp(cmds[i].mod1, ".") == 0) {
                operate1(s, cmds[i].strA, cmds[i].strB, cmds[i].mod2);
            } else if (strcmp(cmds[i].mod1, "^") == 0) {
                operate2(s, cmds[i].strA, cmds[i].strB, cmds[i].mod2);
            } else if (strcmp(cmds[i].mod1, "$") == 0) {
                operate3(s, cmds[i].strA, cmds[i].strB, cmds[i].mod2);
            }

            // 如果变了，说明指令生效
            if (strcmp(s, temp_check) != 0) {
                found = 1;
                break; // 这里的 break 至关重要！一旦修改，必须从第 0 条指令重新开始
            }
        }
    }

    printf("%s\n", s);
    free(s);
    free(temp_check);
    return 0;
}