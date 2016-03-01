#include<stdio.h>

int main()
{
        int c;
        while((c=getchar())!='\n')
        {
                if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c!='y' && c!='A' && c!='E' && c!='I' && c!='O' && c!='U' && c!='Y')
                {
                        if(c>='A' && c<='Z')
                        {
                                c-='A'-'a';
                        }
                        putchar('.');
                        putchar(c);
                }
        }
        putchar('\n');
        return 0;
}                   
