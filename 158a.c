#include<stdio.h>

int main()
{
        int n,k,i,score,count=0;
        int a[50];
        scanf("%d%d",&n,&k); 
        for(i=0;i<n;i++)
               scanf("%d",&a[i]);
        score=a[k-1];
        for(i=0;i<n;i++)
               if(a[i]>=score && a[i]>0)
                       count++;
        printf("%d\n",count);
        return 0;
}
