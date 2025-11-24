#include<stdio.h>
int main()
{
    int n=0,L=0;
    scanf("%d %d",&n,&L);
    int value[n];
    int volume[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&value[i]);
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&volume[i]);
    }
    for (int j=0;j<n-1;j++)
    {
        for (int i=0;i<n-1-j;i++){
            int temp1=0,temp2=0;
            if (value[i]<value[i+1])
            {
                temp1=value[i];
                value[i]=value[i+1];
                value[i+1]=temp1;


                temp2=volume[i];
                volume[i]=volume[i+1];
                volume[i+1]=temp2;

            }

        }
    }


    int note=0;
    int result=0;
    while (L!=0&&note<n)
    {
        if (L>=volume[note])
        {
            L=L-volume[note];
        }
        else
        {
            volume[note]=L;
            L=0;
        }

        result+=value[note]*volume[note];
        note++;

    }
    printf("%d",result);



}