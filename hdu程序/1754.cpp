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
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int Max[Maxn << 2];

void PushUp(int rt) {
    Max[rt] = max(Max[rt << 1],Max[rt << 1 | 1]);
}

void Build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d",&Max[rt]);
        return ;
    }
    int mid = (r + l) >> 1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}

void Update(int p, int M, int l, int r, int rt) {
    if(l == r){
        Max[rt] = M;
        return ;
    }
    int mid = (r + l) >> 1;
    if(p <= mid)
        Update(p, M, lson);
    else
        Update(p, M, rson);
    PushUp(rt);
}

int Query(int L, int R, int l, int r, int rt) {
    int res = 0;
    if(L <= l && R >= r)
        return Max[rt];
    int mid = (r + l) >> 1;
    if(L <= mid )
        res = max(res, Query(L, R, lson));
    if(R > mid)
        res = max(res, Query(L, R, rson));
return res;
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[10];
    int score[30][10];
    int a, b;
    #ifndef ONLINE_JUDGE
        freopen("F:\\input.txt","r",stdin);
    #endif
    while(~scanf("%d%d",&n,&m)) {
        Build(1, n, 1);
        while(m --){
            scanf("%s %d%d",&str,&a,&b);
            if(str[0] == 'U')
                Update(a, b, 1, n, 1);
            if(str[0] == 'Q')
                cout << Query(a, b, 1, n, 1) << endl;
        }
    }
return 0;
}





