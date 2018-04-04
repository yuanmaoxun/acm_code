#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int Mod = 1000000007;
const int Max = 100005;
typedef __int64 LL;


int A, B;
LL pri[Max], cnt[Max];



LL pow(LL p, LL n)      //  求 (p^n) % Mod ：用位运算。
{
    LL sum = 1;
    while(n > 0)
    {
        if(n & 1)
            sum = (sum * p) % Mod;
        n >>= 1;
        p = p * p % Mod;
    }
    return sum;
}



LL sum(LL p, LL n)      //  求 (1 + p + p^2 + p^3 +...+ p^n) % Mod : 用递归形式的二分。
{
    if(n == 0) return 1;
    if(n & 1)
        return ((1+pow(p, n/2+1)) * sum(p, n/2)) % Mod;
    else
        return ((1+pow(p, n/2+1)) * sum(p, n/2-1) + pow(p, n/2)) % Mod;
}



int main()
{
    int i, k;
    int T;
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    scanf("%d",&T);
    while(T--)
    {
        memset(pri,0,sizeof(pri));
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d", &B, &A);
        for(k = 0, i = 2; i * i <= A; i ++)   //  对A进行素因子分解：这种方法不用先求素数。
            if(A % i == 0)
            {
                pri[k] = i;
                while(A % i == 0)
                {
                    cnt[k] ++;
                    A /= i;
                }
                k ++;
            }
        if(A != 1)         //  要记得特殊判定：A为素数。
        {
            pri[k] = A;
            cnt[k ++] = 1;
        }
        LL ans = 1;
        for(i = 0; i < k; i ++)
            ans = ans * (sum(pri[i], cnt[i] * B) % Mod) % Mod;
        printf("%lld\n", ans);
    }
    return 0;
}
