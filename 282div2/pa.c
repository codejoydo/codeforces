#include<stdio.h>

int main()
{
        int a,b;
        int x[2];

        x[0]=getchar()-'0';
        x[1]=getchar()-'0';


                if(x[0]== 1)
                        a=7;
                else if(x[0]== 2) 
                        a=2;
                else if(x[0]== 3)
                        a=3;
                else if(x[0]== 4)            
                        a=3;
                else if(x[0]== 5)
                        a=4;
                else if(x[0]== 6)
                        a=2;
                else if(x[0]== 9)
                        a=2;
                else if(x[0]== 8)
                        a=1;
                else if(x[0]== 7)
                        a=5;
                else if(x[0]== 0)
                        a=2;
                if(x[1]== 1)
                        b=7;
                else if(x[1]== 2) 
                        b=2;
                else if(x[1]== 3)
                        b=3;
                else if(x[1]== 4)            
                        b=3;
                else if(x[1]== 5)
                        b=4;
                else if(x[1]== 6)
                        b=2;
                else if(x[1]== 9)
                        b=2;
                else if(x[1]== 8)
                        b=1;
                else if(x[1]== 7)
                        b=5;
                else if(x[1]== 0)
                        b=2;
        
        printf("%d\n",a*b);
        return 0;
}

