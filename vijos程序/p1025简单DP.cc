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
#define Maxn 105
#define Maxm 10005
#define Mod 1000000007
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int fi[Maxn], ti[Maxn];
    int dp[Maxm];
    scanf("%d", &n);
    scanf("%d", &t);
    for(i = 1; i <= n; i++)
        cin >> fi[i] >> ti[i];
    memset(dp, 0, sizeof(dp));
    for(i = 1; i <= n; i++)
        for(j = t; j >= ti[i]; j--)
            dp[j]=max(dp[j], dp[j-ti[i]]+fi[i]);
    cout << dp[t] << endl;
return 0;
}
