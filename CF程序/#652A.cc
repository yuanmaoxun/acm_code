//kengkeng
#include<bits/stdc++.h>
#define Maxn 100005
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
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    ll a,b;
    ll n,m;
    while(~scanf("%lld%lld",&n,&m)) {
        scanf("%lld%lld",&a,&b);
        if(n+a*8>=m) {
            printf("0\n");
            continue;
        }
        if(a <= b) {
            printf("-1\n");
            continue;
        }
        ll day = 1;
        ll ans = n+a*8-2*b;
        while(1) {
            if(ans >= m) {
                break;
            }
            ans -= b*10;
            ans += a*12;
            if(ans >= m) {
                break;
            }
            ans-= b*2;
            day++;
        }
        printf("%lld\n",day);
    }
return 0;
}





