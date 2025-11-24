#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    char* p;
    p=(char*)malloc(4096*sizeof(char));
    fgets(p,4096,stdin);
    int flag=1;
    char* s;
    s=p;
    while (*s!='\0')
    {
        if (*s==' ')
        {
            flag=1;
        }
        else
        {
            if (flag==1)
            {
                flag=0;
                *s=toupper(*s);
            }
            else
            {
                *s=tolower(*s);
            }
        }
        s++;

    }
    printf("%s",p);


    free(p);
}