
//¿Ó¿Ó
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define INF 0xffff;
#define PI  3.1415926535898
#define ll long long
#define Maxn 5005
#define Mod 100
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

ll quick_mod(ll a, ll b, ll m) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans * a) % m;
            b--;
        }
        b /= 2;
        a = a * a % m;
    }
return ans;
}
int main(){
    int t;
    __int64 i, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
            scanf("%I64d",&n);
            res = quick_mod(5, n, Mod);
            printf("%I64d\n", res);

return 0;
}





