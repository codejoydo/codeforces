#include<stdio.h>
#include<string.h>

int main()
{
        int t;
        char a[101];
        scanf("%d",&t);
        while(t--)
        {
                scanf("%s",a);
                if(strlen(a)>10)
                         printf("%c%d%c\n",a[0],strlen(a)-2,a[strlen(a)-1]);
                else
                        printf("%s\n",a);
        }
        return 0;
}
