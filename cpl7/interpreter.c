#include<stdio.h>

int main()
{
    int X=0;
    scanf("%x",&X);
    printf("%d\n",X);
    printf("%u\n",X);
    printf("%.6f\n",*(float*)&X);
    printf("%.4e\n",*(float*)&X);
}