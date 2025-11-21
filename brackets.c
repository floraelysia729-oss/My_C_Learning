#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int top=-1;
int stack[100000];

void push(char c)
{
    top++;
    stack[top]=c;
}

void pop()
{
    top--;
}

int main()
{
    int T=0,flag=1;
    scanf("%d",&T);
    char string[100000];
    while (T--)
    {
        scanf("%s", string);
        int len=strlen(string);
        for (int i=0;i<len;i++)
        {
            if (string[i]=='('||string[i]=='['||string[i]=='{')
            {
                push(string[i]);
            }
            if (string[i]==')'||string[i]==']'||string[i]=='}')
            {
                if (top==-1)
                {
                    flag=0;
                    break;
                }
                if (string[i]==')'&&stack[top]=='(')
                {
                    pop();
flag=1;
                }
                else if (string[i]==']'&&stack[top]=='[')
                {
                    pop();
flag=1;
                }
                else if (string[i]=='}'&&stack[top]=='{')
                {
                    pop();
flag=1;
                }
                else
                {

                    flag=0;
                    break;
                }

            }

        }
        if (top==-1&&flag==1)
        {
            printf("True\n");

        }
        else
        {
            printf("False\n");
        }
            top=-1;

    }
}