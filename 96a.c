#include<stdio.h>

int main()
{
        int c,state,flag=0,count=0;
        while((c=getchar())!='\n')
        {
                if(c=='1')
                {
                        if(state==1)
                                count++;
                        else
                        {
                                state=1;
                                count=1;
                        }
                }
                else
                {
                        if(state==0)
                                count++;
                        else
                        {
                                state=0;
                                count=1;
                        }
                }
                if(count>=7)
                        flag=1;
        }
        if(flag==1)
                printf("YES\n");
        else
                printf("NO\n");
        return 0;
}
