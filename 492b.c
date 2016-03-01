#include<stdio.h>

int a[100000],b[100000];

void merge(int p,int m,int q,int n)
{
    int i,j,k;
    if(n-p==0)
        return;
    i=p;j=q;
    for(k=0;k<=n-p&&j<=n&&i<=m;k++)
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            i++;
        }
    }
    if(i>m)
        while(j<=n)
            b[k++]=a[j++];
    else
        while(i<=m)
            b[k++]=a[i++];
    i=p;
    for(k=0;k<=n-p;k++)
    {
        a[i++]=b[k];
    }
    return;
}

void mergesort(int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=l+(r-l)/2; //important: careful
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,mid+1,r);
    }
    return;
}

int main()
{
    double max,d;
    int n,l,i;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1);
    max=d=a[0]-0;
    for(i=1;i<n;i++)
    {
        d=(a[i]-a[i-1])/(double)2;
        if(d>max)
            max=d;
    }
    if(max<(l-a[n-1]))
        max=l-a[n-1];
    printf("%.10lf\n",max);
    return 0;
}


