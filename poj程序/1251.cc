#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#define Maxn 3000//顶点个数最大值
#define Maxm 1500000 //边的个数最大值
using namespace std;
typedef struct {
    int u;
    int v;
    int w;
} edge;
edge edges[Maxm];
int father[Maxn];
int i, j;
bool cmp(edge a, edge b) {
    return a.w < b.w;
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
    printf("%d\n",sumweight);
}

int main() {
    int u, v, w;
    int n, m;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(cin >> n,n) {
        getchar();
        for(i = 1; i <= n; i++)
            father[i] = i;
        int k = 0;
        for(i = 1; i <= n-1; i++) {
            char temp ;
            cin >>temp;
            u = temp - 'A' + 1;
            cin >>m;
            for(j = 1; j <= m; j++){
                cin >>temp;
                v = temp - 'A' +1;
                cin >>w;
                //cout << u <<" " <<v <<" " <<w<<endl;
                edges[k].u=u;
                edges[k].v=v;
                edges[k].w=w;
                k++;
                //cout <<edges[k].u <<" " <<edges[k].v<<" "<<edges[k].w<<endl;
            }
        }
        sort(edges,edges+k,cmp);
//        for(i =0; i < k; i++)
//        cout <<edges[i].u <<" " <<edges[i].v<<" "<<edges[i].w<<endl;
    Kruskal(k);
    }

return 0;
}
