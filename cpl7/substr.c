#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int substr()
{
    char *p1,*p2;
    p1=(char*)malloc(10000*sizeof(char));
    scanf("%s",p1);

    p2=(char*)malloc(10000*sizeof(char));
    scanf("%s",p2);

    char* start = p1;
    char* find =strstr(p1,p2);
    while (find!=NULL)
    {
        int index=find-start;
        printf("%d ",index);
        find=strstr(find+1,p2);
    }

    free(p1);
    free(p2);


}