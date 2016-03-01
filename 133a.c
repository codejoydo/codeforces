#include<stdio.h>

int main()
{
        int c,flag=0;
        while((c=getchar())!='\n')
                if(c=='H'||c=='Q'||c=='9')
                        flag=1;
        if(flag)
                printf("YES\n");
        else
                printf("NO\n");
        return 0;
}
