#include<stdio.h>

int main()
{
        int left=0,right=0,count=0;
        int a[100001][2],i=0,j,n,sum=0,rem,hash=0,err=0;
        int c;
        while((c=getchar())!='\n')
        {
                count++;
                if(c=='(')
                {
                        a[i++][0]=-1;
                        left++;
                        a[i-1][1]=0;
                }
                else if(c=='#')
                {
                        if(j)
                                a[j][1]=1;
                        a[i++][0]=1;
                        a[i-1][1]=2;
                        j=i-1;
                        hash++;
                }
                else if(c==')')
                {
                        a[i++][0]=1;
                        right++;
                        a[i-1][1]=0;
                }
        }

        n=i; 
//              for(i=0;i<n;i++)
  //                    printf("%d ",a[i][0]);
    //          printf("\n");
        rem=left-right-hash;
//              printf("rem=%d\n",rem);
        for(i=0;i<n;i++)
        {
//                printf("err=%d\n",err);
                err+=a[i][0];
                if (i==j)
                        err+=rem;
                if(err>0)
                {
                        printf("-1\n");
                        return 0;
                }

        }

        if(rem<0)
        {
                printf("-1\n");
                return 0;
        }

        //      for(i=0;i<n;i++)
        //              printf("%d ",a[i][1]);
        //      printf("\n");

        for(i=0;i<n;i++)
        {
                //              printf("i=%d\n",i+1);
                //              for(j=0;j<=i;j++)
                //                      printf("%d ",a[j][0]);
                //              printf("\n");
                sum+=a[i][0];
                //              printf("sum=%d\n",sum);
                if(a[i][1])
                {
                        if(a[i][1]==2)
                                a[i][0]+=rem;
                        printf("%d\n",a[i][0]);
                        /*                {
                                          if(sum*-1<rem)
                                          {
                                          a[i][0]+=sum*-1;
                                          rem-=sum*-1;
                                          sum+=sum*-1;
                                          printf("%d\n",a[i][0]);
                                          }
                                          else
                                          {
                                          a[i][0]+=rem;
                                          rem=0;
                                          sum+=rem;
                                          printf("%d\n",a[i][0]);
                                          }*/
                }
                }
                //      printf("sum=%d\n",sum);
                return 0;
        }




