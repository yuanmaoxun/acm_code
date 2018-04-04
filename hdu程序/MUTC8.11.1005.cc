//¿Ó¿Ó
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define INF 0xffff;
#define PI  3.1415926535898
#define ll long long
#define Maxn 105
#define Maxm 500
#define Mod 1000000007
#define Clear(name, num) memset(name, num, sizeof(name));
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

ll Sum (int n) {
    ll sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
return sum;
}

int main(){
    ll i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int count = 1;
    while(~scanf("%lld%lld", &n, &m)) {
        if(n == -1 && m == -1)
            break;
        printf("Case #%d: ", count++);
        ll temp = n;
        sum = 0;
        sum += Sum(temp);
        for(i = 0; i < m; i++) {
             temp = sum;
             res = 0;
             k =0;
            while(temp) {
                res += temp % 10;
                k++;
                temp /= 10;
            }
            while(k--) {
                n *= 10;
            }
            n += sum;
            sum += res;
            if(n / Mod) {
                temp = n / Mod;
                temp %= 11;
                n %= Mod;
                n += temp * Mod;
            }
        }
        if(n % 11)
            printf("No\n");
        else
            printf("Yes\n");
    }

return 0;
}





