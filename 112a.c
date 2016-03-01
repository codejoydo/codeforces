#include<stdio.h>
#include<string.h>

int f(int num)
{
        if(num>0)
                return 1;
        else if(num<0)
                return -1;
        else
                return num;
}

int main()
{
        char a[101],b[101];
        int i;
        scanf("%s",a);
        scanf("%s",b);
        for(i=0;i<strlen(a);i++)
                if(a[i]>='A' && a[i]<='Z')
                        a[i]+='a'-'A';
        for(i=0;i<strlen(b);i++)
                if(b[i]>='A' && b[i]<='Z')
                        b[i]+='a'-'A';
        printf("%d\n",f(strcmp(a,b)));
        return 0;
}
        
