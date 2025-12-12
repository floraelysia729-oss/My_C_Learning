#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char name[20];
    double total_score1;
    double total_score2;
    double total_score3;
    int count;
}Team;

int comp1(const void*a,const void*b)
{
    const Team *teamA = (const Team *)a;
    const Team *teamB = (const Team *)b;
    if(teamA->total_score1 > teamB->total_score1) return -1;
    if(teamA->total_score1 < teamB->total_score1) return 1;
    return 0;
}

int comp2(const void*a,const void*b)
{
    const Team *teamA = (const Team *)a;
    const Team *teamB = (const Team *)b;
    if(teamA->total_score2 > teamB->total_score2) return -1;
    if(teamA->total_score2 < teamB->total_score2) return 1;
    return 0;
}

int comp3(const void*a,const void*b)
{
    const Team *teamA = (const Team *)a;
    const Team *teamB = (const Team *)b;
    if(teamA->total_score3 > teamB->total_score3) return -1;
    if(teamA->total_score3 < teamB->total_score3) return 1;
    return 0;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    Team team[n];
    for (int i=0;i<n;i++)
    {
        scanf("%s",team[i].name);
        team[i].total_score1 = 0;
        team[i].total_score2 = 0;
        team[i].total_score3 = 0;
        for (int j=0;j<11;j++)
        {
            char useless[1000];
            scanf("%s",useless);
            double score1=0,score2=0,score3=0;
            scanf("%lf %lf %lf",&score1,&score2,&score3);
            team[i].total_score1+=score1/11;
            team[i].total_score2+=score2/11;
            team[i].total_score3+=score3/11;
        }
    }
    qsort(team,n,sizeof(Team),comp1);
    for (int i=0;i<n;i++){
        printf("%s ",team[i].name);
    }
    printf("\n");
    qsort(team,n,sizeof(Team),comp2);
    for (int i=0;i<n;i++){
        printf("%s ",team[i].name);
    }
    printf("\n");
    qsort(team,n,sizeof(Team),comp3);
    for (int i=0;i<n;i++){
        printf("%s ",team[i].name);
    }
    printf("\n");
}