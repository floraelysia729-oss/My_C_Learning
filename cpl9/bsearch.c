#include <stdio.h>
#include <stdlib.h>

int comp(const void*a,const void*b)
{
    int val_a=*(int*)a;
    int val_b=*(int*)b;
    return val_a-val_b;
}

int main()
{
    int n=0,q=0;
    scanf("%d",&n);
    scanf("%d",&q);
    int arr[n];
    int *start;
    start=arr;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int j=0;j<q;j++)
    {
        int* find=malloc(1000*sizeof(int));
        scanf("%d",find);
        int *result=(int*)bsearch(find,arr,n,sizeof(int),comp);
        if (result==NULL)
        {
            printf("-1\n");
        }
        else{
            printf("%d\n",result-start);
        }
        free(find);
    }
}