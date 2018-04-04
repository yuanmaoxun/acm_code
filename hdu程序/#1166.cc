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
#define Maxn 50005
#define Maxm 5005
#define INF 0xffff;
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
int sum[Maxn << 2];

inline void Pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum [rt << 1 | 1];
}

void Build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d",&sum[rt]);
        return ;
    }
    int mid = (l + r) / 2;
    Build(lson);
    Build(rson);
    Pushup(rt);
}

void Updata(int point, int add, int l, int r, int rt) {
    if(l == r) {
        sum[rt] += add;
        return ;
    }
    int mid = (l + r) / 2;
    if(point <= mid)
        Updata(point, add, lson);
    else
        Updata(point, add, rson);
    Pushup(rt);
}

int Query(int L, int R, int l, int r, int rt) {
    int ans = 0;
    if(L <= l && R >= r)
        return sum[rt];
    int mid = (r + l) / 2;
    if(L <= mid)
        ans += Query(L, R, lson);

    if(R > mid)
        ans += Query(L, R, rson);

    return ans;

}
int main(){
    int i, t, j, k, m, n;
    int res, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[Maxn];
    string Str;
    int score[30][10];
    #ifndef ONLINE_JUDGE
        freopen("F:\\程序\\input.txt","r",stdin);
    #endif
    scanf("%d",&t);
    for(k = 1; k <= t; k++) {
        printf("Case %d:\n", k);
        scanf("%d",&n);
        Build(1, n, 1);
        while(~scanf("%s",str) && str[0] != 'E'){
            cin >> i >> j;
            if(str[0] == 'A') {
                Updata(i, j, 1, n, 1);
            }
            if(str[0] == 'S') {
                Updata(i, -j, 1, n, 1);
            }
            if(str[0] == 'Q') {
                cout << Query(i, j, 1, n, 1) << endl;
            }
        }
    }
return 0;
}








