#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    long long int a,b,c,d,r,x,y;
    long long int num,den,ans;
    double frac;
    scanf("%lld%lld%lld%lld%lld",&r,&a,&b,&c,&d);
    //    printf("%lld %lld %lld %lld %lld\n",r,a,b,c,d);
    x=c-a;
    y=d-b;
    num=x*x+y*y;
    //    printf("num=%lld\n",num);
    den=4*r*r;
    //    printf("den=%lld\n",den);
    frac=num/(double)den;
    //    printf("frac=%lf\n",frac);
    frac=sqrt(frac);
    ans=frac;
    if(frac>ans)
        printf("%lld\n",ans+1);
    else
        printf("%lld\n",ans);
    return 0;
}


