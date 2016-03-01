#include<stdio.h>

int a[100],b[100];

void mergesort(int l,int r)
{
    int mid,i,j,k;
    if(l<r)
    {
        mid=l+(r-l)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);

        for(i=l,j=mid+1,k=0;i<=mid&&j<=r&&k<=r-l;k++)
        {
            if(a[i]>=a[j])
                b[k]=a[i++];
            else
                b[k]=a[j++];
        }
        if(i>mid)
            while(j<=r)
                b[k++]=a[j++];
        else
            while(i<=mid)
                b[k++]=a[i++];
        for(i=l,k=0;k<=r-l;k++,i++)
            a[i]=b[k];
    }
}

int main()
{
    int n,i,j,x=0,y=0,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(0,n-1);
    /*
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    */
    for(i=0,j=n-1;i<=j;) // mistake point
    {
        if(a[j]+y>=x)
        {
            x+=a[i++];
            count++;
        }
        else
            y+=a[j--];
    }
    printf("%d\n",count);
    return 0;
}





