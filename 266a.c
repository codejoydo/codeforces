#include<stdio.h>

int main()
{
        int a[50];
        int lim,t,i,j;
        scanf("%d",&lim);
        t=lim;
        getchar();
        for(i=0;i<t;i++)
                a[i]=getchar();
        getchar();
        for(i=0;i<t-1;i++)
        {
                if(a[i]==a[i+1])
                {
                        t--;
                        for(j=i;j<t;j++)
                                a[j]=a[j+1];
                        i--;
                }
        }
        printf("%d\n",lim-t);
        return 0;
}

