#include<stdio.h>
#include<string.h>

int top=-1;
int head=0;
int stack[100005];

void In(int c)
{
    top++;
    stack[top]=c;
}

void Out()
{
    printf("%d\n",stack[head]);
    head++;
}

void Cat()
{
    if(head>top){
        printf("0 []\n");
    }
    else{
        printf("%d ",top-head+1);
        printf("[");
        for (int i=head;i<top;i++)
        {
            printf("%d,",stack[i]);
        }
        printf("%d]\n",stack[top]);
    }
}

int main()
{
    int n=0,c=0;
    char order[10];
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s", order);
        if (strcmp(order,"In")==0)
        {
            scanf ("%d",&c);
            In(c);
        }
        if (strcmp(order,"Out")==0)
        {
            Out();
        }
        if (strcmp(order,"Cat")==0)
        {
            Cat();
        }
    }
    return 0;
}