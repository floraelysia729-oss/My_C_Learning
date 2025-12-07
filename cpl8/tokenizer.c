#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// 【修改1】扩大缓冲区，题目要求输出可能达到20000字节
char buf[22000] = {0};
int error_flag = 0; // 全局错误标记

void process(char* s)
{
    if (error_flag) return; // 如果已经错了，就什么都别做

    // 【修改2】使用字符串数组进行精确匹配，完全替代 strstr
    char *keywords[] = {
        "const", "int", "float", "double", "long", "static", "void", "char",
        "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"
    };
    char *ops[] = {
        "+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"
    };

    // 检查是否是关键字 (精确匹配)
    for (int i = 0; i < 16; i++) {
        if (strcmp(keywords[i], s) == 0) {
            strcat(buf, "reserved ");
            return;
        }
    }

    // 检查是否是运算符 (精确匹配)
    for (int i = 0; i < 11; i++) {
        if (strcmp(ops[i], s) == 0) {
            strcat(buf, "operator ");
            return;
        }
    }

    // 数字检查逻辑 (逻辑基本没变，加上了错误标记)
    if (isdigit(*s))
    {
        char *p = s + 1;
        int point_count = 0;
        for (; *p != '\0'; p++)
        {
            if (!isdigit(*p) && *p != '.') {
                error_flag = 1; return;
            }
            if (*p == '.') point_count++;
        }
        if (point_count == 0) strcat(buf, "integer ");
        else if (point_count == 1) strcat(buf, "float ");
        else error_flag = 1; // 多个点，错误
    }
    // 以点开头的浮点数 (.1 是合法的，但单独一个 . 是非法的)
    else if (*s == '.')
    {
        char *p = s + 1;
        if (*p == '\0') { error_flag = 1; return; } // 单独一个点

        for (; *p != '\0'; p++)
        {
            if (!isdigit(*p)) { error_flag = 1; return; }
        }
        strcat(buf, "float ");
    }
    // 变量检查逻辑
    else if (isalpha(*s) || *s == '_')
    {
        char *p = s + 1;
        for (; *p != '\0'; p++)
        {
            if (!isalnum(*p) && *p != '_') {
                error_flag = 1; return;
            }
        }
        strcat(buf, "variable ");
    }
    else
    {
        error_flag = 1; // 无法识别的符号
    }
}

int main()
{
    char *m = malloc(4096);
    char *s = m;
    int flag = 0;

    while (scanf("%s", s) != EOF) {
        flag = 0;

        char *pos = strchr(s, ';');

        // 如果没有分号，说明是语句中间的单词
        if (pos == NULL) {
            process(s);
        }
        else {
            // 如果有分号，循环切割
            while (pos) {
                *pos = 0;

                // 处理分号前的部分 (防止空字符串，如 ;;)
                if (*s != '\0') process(s);

                // 【修改3】去掉行末多余空格，再加换行
                int len = strlen(buf);
                if (len > 0 && buf[len-1] == ' ') buf[len-1] = '\0';

                strcat(buf, "\n");
                flag = 1; // 标记读到了分号，语句结束

                s = pos + 1;
                pos = strchr(s, ';');
            }

            // 处理最后一个分号后的残留 (如 a=1;b 中的 b)
            if (*s != '\0') {
                process(s);
                flag = 0; // 有残留，说明语句没结束
            }
        }

        // 【修改4】一旦发现错误，立即报错并结束，防止打印部分结果
        if (error_flag) {
            printf("Compile Error");
            free(m);
            return 0;
        }

        s = m; // 重置指针
    }

    // 最后判断：必须是以分号完美结尾
    if (flag == 0)
    {
        printf("Compile Error");
    }
    else
    {
        printf("%s", buf);
    }

    free(m);
    return 0;
}