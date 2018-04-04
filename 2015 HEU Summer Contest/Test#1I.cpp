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
#define PI  3.1415926535898
#define ll long long
#define Maxn 105
#define Maxm 35
#define debug puts("bug");
using namespace std;
int father[10000];

struct A {
    int u,v;
    int value;
} edge[100000000];

bool comp(A a,A b) {
    return a.value < b.value;
}

int find_set(int n) {
    return father[n] == n ? n : father[n] = find_set(father[n]);
}

int Kruskal(int len) {
    int ans = 0;
    for( int i = 1; i <= len; i++) {
        int x = find_set(edge[i].u);
        int y = find_set(edge[i].v);
        if(x != y) {
            father[y] = x;
            ans += edge[i].value;
        }
    }
    return ans;
}

int main() {
    int i, j, t, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn][Maxm];
    int score[30][10];
    #ifndef ONLINE_JUDGE
        freopen("F://input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    while(~scanf("%d",&n)) {
        if( n == 0) break;
        for(i = 1; i <= n ; i++)   //³õÊ¼»¯father
            father[i] = i;
        for(i = 1; i <= n * (n - 1) / 2; i++) {
            scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].value,&k);
            if(k == 1) edge[i]. value = 0;
        }
        sort(edge + 1, edge + n * (n - 1) / 2 + 1, comp);
        len = n * (n - 1) / 2;
        res = Kruskal(len);
        cout << res << endl;
    }
    return 0;
}
