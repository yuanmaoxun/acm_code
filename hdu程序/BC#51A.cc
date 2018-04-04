
#include<stdio.h>
int main()
{
    int t,m;
    __int64 n;
    __int64 ans,i;
    scanf("%d",&t);
    while(t--)
    {
        m=0;

        scanf("%I64d",&n);
        if(n==2)ans=1;
        else if(n==4)ans=2;
        else if(n%2==0)
            ans=0;
        else
        {


                for(i=3; i*i<=n; i+=2)
                {
                    if(n%i==0)
                    {
                        m=1;
                        break;
                    }

                }
                if(m==0)
                    ans=n-1;
                else
                    ans=0;

        }

        printf("%I64d\n",ans);
    }
}
