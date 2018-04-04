
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
char str[212345];
int a[212345];
int x,y,q;
void Extend_gcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return;
    }
    Extend_gcd(b,a%b,y,x);
    y-=x*(a/b);
    return;
}
int main()
{
    int T,p,b,x,y;
    while(~scanf("%d",&T))
    {
        scanf("%s",str);
        int len=strlen(str);
        a[0]=1;
        for(int i=1; i<=len; i++)
        {
            a[i]=(a[i-1]*(str[i-1]-28))%9973;
            //printf("s%d\n",a[i]);
        }
        while(T--)
        {
            scanf("%d%d",&p,&b);
            Extend_gcd(a[p-1],9973,x,y);
            x=(x+9973)%9973;
            int ans=(x*a[b])%9973;
            printf("%d\n",ans);
        }
    }
    return 0;
}
