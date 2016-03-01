#include<stdio.h>

int main()
{
        int a[101],i=0,j,start,rest=1;
        
        while((a[i++]=getchar())!='\n');

        if(a[0]>='a' && a[0]<='z')
                start=0;
        else
                start=1;
        for(j=1;j<i;j++)
                if(a[j]>='a' && a[j]<='z')
                        rest=0;
        if((rest==1 && start==0)||(start==1 && rest==1))
                for(j=0;j<i;j++)
                {
                        if(a[j]>='a' && a[j]<='z')
                                putchar(a[j]-'a'+'A');
                        else if(a[j]>='A' && a[j]<='Z')
                                putchar(a[j]-'A'+'a');
                        else
                                putchar(a[j]);
                }
        else
                for(j=0;j<i;j++)
                        putchar(a[j]);
        return 0;
}
