//¿Ó¿Ó
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define INF 0xffff;
#define PI  3.1415926535898
#define ll int long long
#define Maxn 5005
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

bool comp(ll a, ll b) {
    return a > b ;
}

int main(){
    int i, t, j, k, m, n, x;
    int res, sum, ans, key, len;
    int year, mon, day;
    int num;
    char str[105];
    int score[30][10];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    set <int> S;
    scanf("%d", &n);
    while(n--) {
       scanf("%d",&k);
        if(k == 1) {
            scanf("%d",&x);
            S.insert(x);
        }
        if(k == 2) {
            if(! S.empty())
                S.erase(S.begin());
        }
        if(k == 3) {
            if(! S.empty()) {
                printf("%d\n",*S.rbegin());
            }
            else
                puts("0");
        }
    }
return 0;
}




