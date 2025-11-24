#include<stdio.h>
#include<string.h>

int main()
{
    //输入包括三行
    int n=0,m=0,t=0;
    scanf("%d %d %d",&n,&m,&t);
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int b[m];
    for (int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }

    //b数组作为外循环（因为a数组单调不减）
    int deta[m];
    int flag=0;
    for (int i=0;i<m;i++)
    {
        deta[i]=t;
    }//不能用memset：memset按字节储存，赋值为-1或0是可以的


    for (int i=0;i<m;i++)
    {
        int target=t-b[i];
        int high=n-1;
        int low=0;
        int best_j = -1; // <-- 修正1: 初始值设为-1，代表 "未找到"
        while (low<=high)
        {
            int mid=low+(high-low)/2;
            if (a[mid]<=target)
            {
                best_j=mid; // 找到了一个可能的解，存下它
                low=mid+1;  // 继续往右找更大的
            }
            else
            {
                high=mid-1;
            }

        }

        // 修正2: 检查是否 "找到了" (即 best_j 是否不再是 -1)
        if (best_j != -1)
        {
            // 修正3: (最关键的) 必须计算差值并更新 deta[i] !
            deta[i] = target - a[best_j]; // 等价于 t - b[i] - a[best_j]
            flag = 1; // 并且在这里设置 flag
        }
        // 如果 best_j == -1 （没找到），我们就什么都不做
        // deta[i] 会保持为 't'，flag 也不会被设置
    }
    if (flag==0)
    {
        printf("-1");
    }
    else
    {
        int result=t;
        for (int i=0;i<m;i++)
        {

            result=deta[i]<result? deta[i]:result;
        }
        printf("%d",result);
    }
return 0;
}