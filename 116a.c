#include<stdio.h>

int main()
{
        int t,temp,num,i=0,s=0;
        scanf("%d",&temp);
        t=2*temp;
        while(t--)
        {
                scanf("%d",&num);
                if(t&1)
                        i-=num;
                else
                        i+=num;
                if(i<0)
                        i=0;
                if(s<i)
                        s=i;
//              printf("s=%d i=%d\n",s,i);
        }
        printf("%d\n",s);
        return 0;
}
