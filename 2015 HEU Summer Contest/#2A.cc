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
#define Maxn 1005
#define Maxm 35
#define debug puts("bug");
using namespace std;
int father[Maxn];

struct A {
    int u,v;
    int value;
} edge[1000005];

bool comp(A a,A b) {
    return a.value < b.value;
}

int find_set(int n) {
    return father[n] == n ? n : father[n] = find_set(father[n]);
}

int Kruskal(int length) {
    int ans = 0;
    int len = length;
    for( int i = 0; i < len ; i++) {
        int x = find_set(edge[i].u);
        int y = find_set(edge[i].v);
        if(x != y) {
            father[y] = x;
            ans = edge[i].value;
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

    while(cin >> n >> m) {
        for(i = 1; i <= n ; i++)   //³õÊ¼»¯father
            father[i] = i;
        t = 0;
        for(i = 1; i <= n; i++) {
            scanf("%s",str[i]);
            for(j = 1; j < i; j++) {
                int value = 0;
                for(k = 0; k < m; k++) {
                    value = max(value,abs(str[i][k] - str[j][k]));
                }
                edge[t].u = i;
                edge[t].v = j;
                edge[t].value = value;
//                cout << edge[t].value << endl;
                t++;
            }
        }
//        for(i = 0; i < t; i++) cout << edge[i].value << endl;
        sort(edge, edge + t, comp);
        res = Kruskal(t);
        cout << res << endl;
    }
    return 0;
}
