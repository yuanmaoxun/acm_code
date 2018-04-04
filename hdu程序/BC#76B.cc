#include<stdio.h>
#include<algorithm>
#include<iostream>
#define Maxn 200005
#define Maxm 5005
#define INF 0xffff
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));

using namespace std;
int main() {
//    char str[Maxn];
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    int n,k;
    bool flag;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d%d",&n,&k);
            if(k*(k+1) > 2*n) {
                printf("-1\n");
                continue;
            }
            for(int i=1;i<=k;i++) {
                num[i] = i;
            }
            ll res = n-(1+k)*k/2;
            ll temp = res/k;
            ll sum = 0;
            for(int i=1; i<=k; i++) {
                num[i] += temp;
                sum += num[i];
            }
            res = n-sum;
            //cout << "res"<<res <<endl;
            for(int i = k; i >= 1; i--) {
                if(res == 0)
                    break;
                num[i]++;
                res--;
                if(res == 0)
                    break;
            }
            ll ans = 1;
            for(int i = 1; i<=k; i++) {
                ans = (ans*num[i])%Mod;
            }
            printf("%I64d\n",ans);
        }
    }
return 0;
}
