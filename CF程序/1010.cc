//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
//#include<time.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>

//#include<bits/c++std.h>

#define Size 1000005
#define maxn 150
#define N 55
#define inf 2e9
#define INF 2e18
#define LL long long int
#define i64 __int64
#define ULL unsigned long long
#define Mod 1000000007
#define pi 4*atan(1)
#define eps 1e-9
#define lson now*2,l,l+(r-l)/2
#define rson now*2+1,l+(r-l)/2+1,r

using namespace std;
LL n,m,k;
LL MOD = Mod;
int ql,qr;

LL prime[Size + 10];///素数，最多1e7
LL primeCnt[Size + 10];
void mathInit()///线性筛求质数, 欧拉函数, 莫比乌斯函数 (逆元单独用函数来计算，故不放在此函数中)
{
    primeCnt[0] = primeCnt[1] = 0;
    memset(primeCnt, 0, sizeof(primeCnt));
    memset(prime,0,sizeof(prime));
    for(LL i=2; i <= Size; ++i)
    {
        if(!prime[i])//判断可利用isPrime
        {
            prime[++prime[0]] = i;
            primeCnt[i] = primeCnt[i-1] + 1;
        }
        else
        {
            primeCnt[i] = primeCnt[i-1];
        }
        for(LL j = 1; j <= prime[0] && prime[j] <= Size / i; ++j)
        {
            prime[i * prime[j]] = 1;//同理可以改成isPrime
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

LL vis[1000][1000];

LL phi(LL x, LL a)
{
//    cout<<x<<" "<<a<<endl;
    if(a < 1000 && x < 1000 && vis[x][a])
    {
        return vis[x][a];
    }
    if(x == 0)
        return 0;
    if(a == 1)
    {
        return (x + 1)/2;
    }
    LL tmp = phi(x, a - 1) - phi(x/prime[a], a-1);
    if(x < 1000 && a < 1000)
        vis[x][a] = tmp;
    return tmp;
}

LL p(LL x)
{
    if(x < 1000000)
    {
        return primeCnt[x];
    }
    LL a = p(pow(x, 1.0/4));
    LL c = p(pow(x, 1.0/3));
    LL b = p(sqrt(x));
    LL sum = phi(x, a) + (b + a - 2) * (b - a + 1) / 2;
    for(LL i = a + 1; i <= b; ++i)
    {
        LL w = x / prime[i];
        LL lim = p(sqrt(w));
        sum -= p(w);
        if (i <= c)
        {
            for(LL j = i; j <= lim; ++j)
            {
                sum = sum - p(w/prime[j]) + j - 1;
            }
        }
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t;
    LL xx,yy,zz;
    LL b,c,d;
    LL Case=0;
    memset(vis, 0, sizeof(vis));
    mathInit();
//    cin>>t;
//    while(t--)
    while(scanf("%I64d", &n) != EOF)
    {
        printf("%I64d\n", p(n));
    }
    return 0;
}
