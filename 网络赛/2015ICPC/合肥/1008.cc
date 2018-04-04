#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
#define Max 5000100
long long int quickpow(long long int m,long long int n)
{
    long long int b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = b*m;
          n = n >> 1 ;
          m = m*m;
    }
    return b;
}
int main()
{
    int T;
    scanf("%d",&T);
    long long int s1,s2,d;
    int k=0;
    while(T--)
    {
        int flag=0;
        scanf("%lld%lld%lld",&d,&s1,&s2);
        printf("Case #%d: ",++k);
        int n;
        if(d==1)
        {
            long long int sum=2;
            int t=0;
            int q=1;
            while(s1--)
            {
                t++;
                if(t==1) sum++;
                else if(t==2) continue;
                else
                {
                    sum+=quickpow(2,q);
                    q++;
                }
            }
            printf("%lld\n",sum);
        }
        else
        {
            for(int i=0; i<=32; i++)
            {
                if(d==quickpow(2,i)-1)
                {
                    flag=1;
                    n=i;
                    break;
                }
                else if(i&&d>quickpow(2,i)-1&&d<quickpow(2,i+1)-1)
                {
                    n=i+1;
                    break;
                }
            }
            //printf("%d\n",n);
            if(flag)
            {
                long long int sum=0;
                sum+=quickpow(2,n);
                int p=0;
                s1--;
                while(s1>0)
                {
                    s1--;
                    sum+=quickpow(2,p);
                    p++;
                }
                printf("%lld\n",sum);
            }
            else
            {
                //long long int sum=0;
                //sum=d;
                for(long long int i=d+1; i<=quickpow(2,n); i++)
                {
                    //puts("sos");
                    long long int m=i;
                    long long int u=m;
                    int y=0;
                    while(m)
                    {
                        //puts("sos");
                        if(m%2)
                        {
                            y++;
                        }
                        m=m/2;
                    }
                    if(y>=s1&&y<=s2)
                    {
                        printf("%lld\n",u);
                        break;
                    }
                }
            }
        }

    }
    return 0;
}
