#include<stdio.h>
#include<string.h>

int main()
{
    char buffer1[1024];
    char buffer2[1024];
    char *s1=buffer1;
    fgets(s1,1024,stdin);
    s1[strcspn(s1, "\n")] = 0;
    char *s2=buffer2;
    fgets(s2,1024,stdin);
    s2[strcspn(s2, "\n")] = 0;

    char* argv[1024]={0};
    int count=0;
    char *p=strtok(s2," ");
    while (p!=NULL)
    {
        argv[count++]=p;
        p=strtok(NULL," ");
    }
    char output_buffer[2048];
    char temp[256];
    sprintf(temp,"%s\n",argv[0]);
    strcat(output_buffer,temp);
    for (count=1;argv[count]!=NULL;count++){
        if (argv[count][0] != '-') {
            continue;
        }

            char*check=strchr(s1,argv[count][1]);
            if (check==NULL)
            {
                printf("%s: invalid option--'%c'\n", argv[0], argv[count][1]);
                return 0;
            }
            else
                {
                if (*(check+1)==':')
                {
                    if (argv[count+1]!=NULL){
                        char temp[256];
                        sprintf(temp, "%c=%s\n", argv[count][1], argv[count + 1]);
                        strcat(output_buffer, temp);
                        count++;
                    }
                    else
                    {
                        printf("%s: option requires an argument -- '%c'\n", argv[0],argv[count][1]);
                        return 0;
                    }
                }
                else
                    {
                        char temp[256];
                        sprintf(temp, "%c\n",argv[count][1]);
                        strcat(output_buffer, temp);

                    }
                }
            }
    printf("%s",output_buffer);
        }

