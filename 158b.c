#include<stdio.h>

int main()
{
        int a[4]={0,0,0,0};
        int t,num,ans=0;    
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&num);
                a[num-1]++;
        }
//      printf("1=%d 2=%d 3=%d 4=%d ans=%d\n",a[0],a[1],a[2],a[3],ans);
        ans+=a[3];
        a[3]=0;
//      printf("1=%d 2=%d 3=%d 4=%d ans=%d\n",a[0],a[1],a[2],a[3],ans);
        while(a[2]>0)
        {
                if(a[0]>0)
                        a[0]--;
                a[2]--;
                ans+=1;
//      printf("1=%d 2=%d 3=%d 4=%d ans=%d\n",a[0],a[1],a[2],a[3],ans);
        }
        while(a[1]>0)
        {
                if(a[1]>=2)
                {
//                  printf("subtracted\n");    
                    a[1]--;    
                }
                else if(a[0]>0)
                    a[0]-=2;
                a[1]--;
                ans+=1;
//      printf("1=%d 2=%d 3=%d 4=%d ans=%d\n",a[0],a[1],a[2],a[3],ans);
        }
        while(a[0]>0)
        {
                a[0]-=4;
                ans++;
//      printf("1=%d 2=%d 3=%d 4=%d ans=%d\n",a[0],a[1],a[2],a[3],ans);
        }
//      printf("1=%d 2=%d 3=%d 4=%d ans=%d\n",a[0],a[1],a[2],a[3],ans);
        printf("%d\n",ans);
        return 0;
}
