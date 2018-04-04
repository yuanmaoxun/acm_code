#include<stdio.h>
#include<algorithm>
#include<iostream>
#define Maxn 1005//顶点个数最大值
#define Maxm 15005 //边的个数最大值
using namespace std;
typedef struct {
    int u;
    int v;
    int w;
} edge;
edge edges[Maxm];
edge ans[Maxm];
int father[Maxn];
bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find_set(int n) {
    return father[n] == n ? n : father[n] = find_set(father[n]);
}

void Union (int R1, int R2) {
    int r1 = find_set(R1);
    int r2 = find_set(R2);
}

void Kruskal(int len) {
    int maxedge = 0;
    int Count = 0;
    for(int i = 0; i < len; i++) {
        int x = find_set(edges[i].u);
        int y = find_set(edges[i].v);
        if(x != y) {
            ans[Count].u = edges[i].u;
            ans[Count].v = edges[i].v;
            maxedge = max(edges[i].w , maxedge);
            father[y]=x;
            Count++;
            //cout <<"select edges" <<edges[i].w <<endl;
        }
    }
    printf("%d\n%d\n", maxedge, Count);
    for(int i = 0; i < Count; i++) {
        printf("%d %d\n", ans[i].u, ans[i].v);
    }
}

int main() {
    int u, v, w;
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 1; i <= n; i++)
            father[i]=i;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            edges[i].u=u;
            edges[i].v=v;
            edges[i].w=w;
        }
        sort(edges, edges + m, cmp);
        Kruskal(m);
    }
return 0;
}

