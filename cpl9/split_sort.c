#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char**strsplit(char*arr, const char*key){
    char*token=strtok(arr,key);
    char**arr1=malloc(10000000*sizeof(char*));
    int i=0;
    while (token!=NULL)
    {
        arr1[i] = token;
        i++;
        token=strtok(NULL,key);
    }
    arr1[i]=NULL;
    return arr1;
}

int comp(const void*a,const void*b)
{
    char*val_a=*(char**)a;
    char*val_b=*(char**)b;
    return strcmp(val_a,val_b);
}

int main()
{
    char*s1=malloc(1000000);
    char*key=malloc(1000);
    scanf("%s",s1);
    scanf("%s",key);
    char **arr1=strsplit(s1,key);
    int count = 0;
    while (arr1[count] != NULL) {
        count++;
    }
    qsort(arr1,count,sizeof(char*),comp);
    for (int i=0;i<count;i++)
    {
        printf("%s\n",arr1[i]);
    }
    free(arr1);
    free(s1);
    free(key);
}