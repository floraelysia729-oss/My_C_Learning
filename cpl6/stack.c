#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char stack[10005];
int top=-1;

int main()
{
    int n=0;
    scanf(" %d",&n);
    char orders[8];
    char letter;
    for (int i=0;i<n;i++)
    {
        scanf("%s",orders);
        if (strcmp(orders, "push")==0)
        {
            scanf(" %c",&letter);
            top++;
            stack[top]=letter;
        }
        if (strcmp(orders, "pop")==0)
        {
            if (top==-1)
            {
                printf("Empty\n");
            }
            else
            {
                top--;
            }
        }
        if (strcmp(orders, "top")==0)
        {
            if (top==-1)
            {
                printf("Empty\n");
            }
            else
            {
                printf("%c\n",stack[top]);
            }
        }
        if (strcmp(orders, "print")==0)
        {
            if (top==-1)
            {
                printf("Empty\n");
            }
            else
            {
                for (int i=top;i>=0;i--)
                {
                    printf("| %c |\n",stack[i]);
                }
                printf("|===|");
            }
        }


    }
}