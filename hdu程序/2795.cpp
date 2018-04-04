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

int Max[Maxn << 2], w, h ;
void Pushup(int rt) {
    Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
}

void Build(int l, int r, int rt) {
    Max[rt] = w;
    if(r == l)
        return ;
    int mid = (r + l) >> 1;
    Build(lson);
    Build(rson);
}

int Query(int p,int l,int r,int rt) {
    if (l == r) {
        Max[rt] -= p;
        return l;
    }
    int mid = (l + r) >> 1;
    int res = (Max[rt << 1] >= p) ? Query(p , lson) : Query(p , rson);
    Pushup(rt);
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
    while(~scanf("%d%d%d",&h,&w,&n)) {
        int wi;
        if(h > n)
            h = n;
        Build(1, h, 1);
        while(n--) {
            scanf("%d",&wi);
            if(Max[1] < wi)
                cout << "-1" << endl;
            else
                cout << Query(wi, 1, h, 1) << endl;
        }
    }
return 0;
}





