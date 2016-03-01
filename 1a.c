#include<stdio.h>
//long long int in code forces : %I64d
long long int f(long long int num,long long int a)
{
        if(((num/a)*a)<num)
                return (num/a)+1;
        else
                return num/a;
}

int main()
{
        long long int n,m,a;
        scanf("%I64d%I64d%I64d",&n,&m,&a);
        printf("%I64u\n",f(n,a)*f(m,a));
        return 0;
}
        
