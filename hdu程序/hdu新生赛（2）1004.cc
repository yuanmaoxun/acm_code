#include<bits/stdc++.h>
#include<iostream>
#define Maxn 200//顶点个数最大值
#define Maxm 1000000 //边的个数最大值
using namespace std;
typedef struct {
    int u;
    int v;
    int w;
} edge;
edge edges[Maxm];
int father[Maxn];
bool cmp(edge a, edge b) {
    return a.w > b.w;
}

int find_set(int n) {
    return father[n] == n ? n : father[n] = find_set(father[n]);
}
void Kruskal(int len) {
    int sumweight = 0;
    for(int i = 0; i < len; i++) {
        int x = find_set(edges[i].u);
        int y = find_set(edges[i].v);
        if(x != y) {
            sumweight += edges[i].w;
            father[y]=x;
            //cout <<"select edges" <<edges[i].w <<endl;
        }
    }
    cout << sumweight << endl;
}
int num[Maxn][Maxn];
int main() {
    int u, v, w;
    int n, m;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d",&n)){
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                scanf("%d",&num[i][j]);
        }
        for(int i = 1; i <= n; i++)
            father[i]=i;
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edges[k].u = i+1;
                edges[k].v = j+1;
                edges[k].w = num[i][j];
                k++;
            }
            //cout << edges[i].u <<" " <<edges[i].v << " " <<edges[i].w <<endl;

        }
        sort(edges, edges + k, cmp);
        Kruskal(k);

    }

return 0;
}
