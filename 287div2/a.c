#include<stdio.h>

int main()
{
    int a[100],b[100],n,k,i,j,sum=0,min,index,count=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=0;j<n;j++)
    {
        min=101;
        for(i=0;i<n;i++)
        {
            if(a[i]==-1)
                continue;
            else
            {
                if(min>a[i])
                {
                    index=i;
                    min=a[i];
                }
            }
        }
        //      printf("min=%d,sum=%d\n",min,sum);
        if(sum+a[index]<=k)
        {
            sum+=a[index];
            a[index]=-1;
            b[count++]=index+1;
        }
        else
            break;
    }
    printf("%d\n",count);
    if(count)
    {
        for(i=0;i<count;i++)
            printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}



