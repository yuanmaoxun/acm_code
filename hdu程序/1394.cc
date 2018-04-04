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

int sum[Maxn << 2];

void PushUp(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void Build(int l, int r, int rt) {
    sum[rt] = 0;
    if(l == r) {
        return ;
    }
    int mid = (r + l) >> 1;
        Build(lson);
        Build(rson);
    PushUp(rt);
}

void Updata(int p, int l, int r, int rt){
    if(l == r) {
        sum[rt]++;
        return ;
    }
    int mid = (r + l) >> 1;
    if(p <= mid)
        Updata(p, lson);
    else
        Updata(p, rson);
    PushUp(rt);
}
int Quary(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        return sum[rt];
    }
    int res = 0;
    int mid = (r + l) >> 1;
    if(L <= mid)
        res += Quary(L, R, lson);
    if(R > mid)
        res += Quary(L, R, rson);
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
        Build(0, n - 1, 1);
        sum = 0;
        for(i = 0; i < n; i++){
            scanf("%d",&num[i]);
            sum += Quary(num[i], n -1, 0, n - 1, 1);
            Updata(num[i], 0, n -1, 1);
        }
//        cout << sum << endl;
        res = sum;
        for(i = 0; i < n; i++){
            sum += n - 2 * num[i] - 1;
            res = min(sum, res);
        }
        cout << res << endl;
    }
return 0;
}




