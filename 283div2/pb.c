#include<stdio.h>
#include<string.h>

int a[1000][10],b[10];



        int main()
        {
                int lim,i,c,j,min=0,bingo;
                scanf("%d",&lim);
                getchar();
                for(i=0;i<lim;i++)
                {
                        c=getchar();
                        a[i]=c-'0';
                }
                for(j=1;j<10;j++)
                {
                        sum=0;
                        for(i=0;i<lim;i++)
                        {
                                if(a[i][j]==9)
                                        sum-=9;
                                else
                                        sum++;
                        }
                        if(sum<min)
                        {
                                min=sum;
                                bingo=j;
                        }
                }

                sort(bingo);
                for(i=0;i<lim;i++)
                        printf("%d",a[i][bingo]);
                printf("\n");
                return 0;
        }







}

