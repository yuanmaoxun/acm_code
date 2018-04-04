#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
int n,m;
ll a[100005],b[100005];

bool dis(int i,int x,ll val)
{
    return abs(b[i]-a[x])<=val;
}

bool check(ll val)
{
    int x=0;
    for(int i=0;i<m;i++)
    {
        while(x<n&&dis(i,x,val))
            x++;
    }
    return (x==n);
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        for(int j=0;j<m;j++) scanf("%lld",&b[j]);
        ll l=0,r=4e9;
        while(l<r)
        {
            ll mid=(l+r)/2;
            if(check(mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%I64d\n",l);
    }
    return 0;
}