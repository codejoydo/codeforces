#include<stdio.h>

int main()
{
    int a[1000][1000],m,n,k,i,j,l,move=0;
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            a[j][i]=0;
    for(l=1;l<=k;l++)
    {
        scanf("%d%d",&i,&j);
        i--;j--;
        a[j][i]=1;
        if((i+1<m) && (j+1<n))
            if(a[j][i]==1 && a[j+1][i]==1 && a[j][i+1]==1 && a[j+1][i+1]==1)
            {
                move=l;
                break;
            }
        if((i-1>=0) && (j-1>=0))
            if(a[j][i]==1 && a[j-1][i]==1 && a[j][i-1]==1 && a[j-1][i-1]==1)
            {
                move=l;
                break;
            }
        if((i-1>=0) && (j+1<n))
            if(a[j][i]==1 && a[j+1][i]==1 && a[j][i-1]==1 && a[j+1][i-1]==1)
            {
                move=l;
                break;
            }
        if((i+1<m) && (j-1>=0))
            if(a[j][i]==1 && a[j-1][i]==1 && a[j][i+1]==1 && a[j-1][i+1]==1)
            {
                move=l;
                break;
            }
    }
    printf("%d\n",move);
    return 0;
}


