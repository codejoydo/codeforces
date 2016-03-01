#include<stdio.h>
#include<string.h>
int pw(int num,int base)
{
        if(num==0)
                return 1;
        return base*pw(num-1,base);
}

int main()
{
        char a[17];
        int t,type,pow,i,j,n,c,b[5],x;
        scanf("%d",&t);
        while(t--)
        {
                type=1;
                scanf("%s",a);
                n=strlen(a);

                for(i=2;i<n;i++)
                        if(a[i]=='C' && (a[i-1]>='0' && a[i-1]<='9'))
                        {
                                type=0;
                                break;
                        }
                if(type)
                {
                        c=0;
                        pow=0;
                        printf("R");
                        for(i=0;a[i]!='\0';i++)
                        {
                                if(a[i]>='A' && a[i]<='Z')
                                        continue;
                                printf("%c",a[i]);
                        }
                        printf("C");
                        for(i=n-1;i>=0;i--)
                        {
                                if(a[i]>='0' && a[i]<='9')
                                        continue;
                                c+=(a[i]-'A'+1)*pw(pow++,26);
                        }
                        printf("%d\n",c);
                }
                else
                {
                        c=0;
                        pow=0;
                        for(i=n-1;i>=0;i--)
                        {
                                if(a[i]=='C')
                                        break;
                                c+=(a[i]-'0')*pw(pow++,10);
                        }
                        i=0;
                        c--;
                        b[0]=c%26;
                        while(c>=0)
                        {
                                i++;
                                c-=pw(i,26);
                                if(c<0)
                                        break;
                                b[i]=c/pw(i,26);
                                if(a[i]==0)
                                        b[i]=26;
                        }
                        for(j=i-1;j>=0;j--)
                        {
                                putchar(b[j]%26+'A');
                        }
                        for(j=1;j<n;j++)
                        {
                                if(a[j]=='C')
                                        break;
                                printf("%c",a[j]);
                        }
                        printf("\n");
                }
        }
        return 0;
}
