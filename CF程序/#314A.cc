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
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int main(){
    ll i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    ll mini, maxi;
    char str[105];
    ll num[100005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    scanf("%lld", &n);
    for(i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }
    for( i = 0; i < n; i++) {
       if(i == 0){
        maxi = num[n - 1] - num[0];
        mini = num[1] - num[0];

       }
       else
          if(i == n - 1) {
        maxi = num[n - 1] - num[0];
        mini = num[n - 1] - num [n - 2];
       }
       else {
        mini = min(num[i] - num[i - 1], num[i + 1] - num[i]);
        maxi = max(num[i] - num[0], num[n - 1] - num[i]);
       }
       cout << mini << " " << maxi << endl;
    }
return 0;
}





