#include<stdio.h>

int main()
{
        char a[4];
        int t,c,ans=0;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%s",a);
                if(a[1]=='-')
                        ans--;
                else
                        ans++;
        }
        printf("%d\n",ans);
        return 0;
}
