#include<stdio.h>

int check(long long L,int d[],long long N,long long R,long long M,long long D)
{
    long long count=0;
    long long sum=0;
    for (int i=0;i<N;i++)
    {
        if (d[i]<R&&d[i]>L)
        {
            count++;
            sum+=d[i]-L;
        }
    }
    if (count>=M&&sum>=D)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    long long N=0,R=0,M=0,D=0;
    long long L=0,result=-1;
    scanf("%lld %lld %lld %lld",&N,&R,&M,&D);
    int d[N];
    for (int i=0;i<N;i++)
    {
        scanf("%d", &d[i]);
    }
    long long low=0,high=R;
    while (low<=high)
    {
        L=low+(high-low)/2;
        if (check(L,d,N,R,M,D)==1)
        {
            result=L;
            low=L+1;
        }
        else
        {
            high=L-1;
        }

    }
    printf("%lld",result);

}
