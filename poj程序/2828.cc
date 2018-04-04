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
#define Maxn 200005
#define Mod 1000000007
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int sum[Maxn << 2];
int Print[Maxn];
struct Queue {
    int pos;
    int val;
} Q[Maxn];

void PushUp (int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void Build(int l, int r, int rt) {
    if(l == r) {
        sum[rt] = 1;
        return ;
    }
    int mid = (l + r) / 2;
    Build(lson);
    Build(rson);
    PushUp(rt);
}

int Query(int p, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = 0;
        return l;
    }
    int res;
    int mid = (r + l) >> 1;
    if(p < sum[rt << 1]) {
        res = Query(p, lson);
    }
    else {
        res = Query(p - sum[rt << 1], rson);
    }
    PushUp(rt);
return res;
}

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
    while(~scanf("%d",&n)) {
        for(i = 1; i <= n; i++)
            scanf("%d%d", &Q[i].pos, &Q[i].val);
        Build(1, n, 1);
        for(i = n ; i > 0; i--) {
            Print[Query(Q[i].pos, 1, n, 1)] = Q[i].val;
        }
        for(i = 1; i <= n; i++) {
            if(i == n)
                cout << Print[i] << endl;
            else
                cout << Print[i] << " ";
        }
    }
return 0;
}




