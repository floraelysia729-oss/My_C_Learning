#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int T=0;
    scanf("%d",&T);
    while (T--)
    {
        char *s1=malloc(1000*sizeof(char));
        char *s2=malloc(1000*sizeof(char));

        int d1,d2,size;
        scanf(" %[^;];%[^;];%d;%d;%d",s1,s2,&d1,&d2,&size);
        char s3[2000];
        int k=0,i=0,j=0;
        while (s1[i]!='\0'&&s2[j]!='\0')
        {
            for (int t = 0; t < d1 && s1[i] != '\0'; t++) {
                s3[k++] = s1[i++];
            }

            for (int t = 0; t < d2 && s2[j] != '\0'; t++) {
                s3[k++] = s2[j++];
            }

        }
        while (s1[i] != '\0') s3[k++] = s1[i++];
        while (s2[j] != '\0') s3[k++] = s2[j++];
        s3[k]='\0';
        if (k>=size)
        {
            s3[size-1]='\0';
        }
        printf("%s\n",s3);
        free(s1);
        free(s2);


    }
}

