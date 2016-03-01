#include<stdio.h>

int main()
{
    int c,a[100000],n=0,i,flag=0;

    while((c=getchar())!='\n')
        a[n++]=c-'0';

    for(i=0;i<n;i++)
    {
        if(a[i]%2==0 && a[i]<a[n-1])
        {
            a[i]=a[n-1]+a[i];
            a[n-1]=a[i]-a[n-1];
            a[i]=a[i]-a[n-1];
            flag=1;
            break;
        }
    }
    if(flag==0)
        for(i=n-1;i>=0;i--)
        {
            if(a[i]%2==0)
            {
                a[i]=a[n-1]+a[i];
                a[n-1]=a[i]-a[n-1];
                a[i]=a[i]-a[n-1];
                flag=1;
                break;
            }
        }
    if(flag==0)
    {
        printf("-1\n");
        return 0;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}

