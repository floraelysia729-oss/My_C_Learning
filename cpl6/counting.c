#include<stdio.h>
#include<string.h>
int main()
{
    int R=0,C=0;
    scanf("%d%d",&R,&C);
    char map[R][C];
    for (int row=0;row<R;row++)
    {
        for (int col=0;col<C;col++)
        {
            scanf(" %c",&map[row][col]);
        }
    }
    int count=0;
    for (int row=0;row<R;row++)
    {
        for (int col=0;col<C-1;col++)
        {
            if (map[row][col]=='/'&&map[row][col+1]=='\\')
            {
                int r=row,c=col;
                int d=0,flag=1;
                while (d<=c&&2*d+1<R-r&&d<C-1-c)
                {
                    for (int i=0;i<=d;i++)
                    {
                        if (map[r+i][c-i]=='\\')
                        {
                            flag=0;
                        }
                        if (map[r+i][c+1+i]=='/')
                        {
                            flag=0;
                        }
                    }
                    for (int i=d;i>=0;i--)
                    {
                        if (map[r+d+i+1][c-d+i]=='/')
                        {
                            flag=0;
                        }
                        if (map[r+d+i+1][c+d+1-i]=='\\')
                        {
                            flag=0;
                        }
                    }
                    d++;

                    if (flag==1)
                    {
                        count++;
                    }
                    flag=1;

                }
            }
        }
    }
    printf("%d",count);

return 0;
}