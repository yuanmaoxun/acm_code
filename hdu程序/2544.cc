#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

#define Maxn 1005
#define Maxm 10005
#define INF 0xfffff
int n,m;   //
int Edge[Maxn][Maxn];
int vis[Maxn];
int dist[Maxn];
int path[Maxn];

void Dijkstra(int v0) {

    int i, j , k;
    for(i = 1; i <= n; i++) {
        dist[i] = Edge[v0][i];
        vis[i] = 0;
//        if(i != v0 && dist[i] < INF){
//            path[i] = v0;
//        }
//        else{
//            path[i] = -1;
//        }
    }

    vis[v0] = 1;
    dist[v0] = 0; //将顶点v0加入顶点集合vis中

    for(i = 0; i < n-1; i++) {
        int Min = INF;
        int u = v0;
        for(j = 1; j <= n; j++) {
            if(!vis[j] && dist[j]<Min) {
                u = j;
                Min = dist[j];
            }
        }
        vis[u] = 1;   //将顶点u加入到集合vis中，表示他的最短路径以求的
        //修改剩下元素顶点dist和path数组元素值
        for(k = 1; k <= n; k++){
            if( !vis[k] && Edge[u][k] < INF && dist[u]+Edge[u][k] < dist[k]){
                dist[k] = dist[u] + Edge[u][k];
//                path[k] = u;
            }
        }
    }
}

int main(){
    int i,j,k;
    int u,v,w;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 || m == 0)
            break;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) {
                if(i == j)
                    Edge[i][j] =0;
                    else
                        Edge[i][j] =INF;
            }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            Edge[u][v] = Edge[v][u] = w;
        }


        Dijkstra( 1 );  //求定点到其他顶点的最短路径
//        int shortest[Maxn];
//        for(i = 1; i < n; i++) {
//            printf("%d\t", dist[i]);
//            memset(shortest, 0,sizeof(shortest));
//            int Count = 0;
//            shortest[Count] = i;
//            while(path[shortest[Count]] != 0) {
//                Count++;
//                shortest[Count] = path[shortest[Count-1]];
//            }
//            Count++;
//            shortest[Count] = 0;
//            for(j = Count; j>0; j--)
//                printf("%d->", shortest[j]);
            printf("%d\n", dist[n]);
//        }
    }
return 0;
}

/*
6 9
1 3 5
1 4 30
2 1 2
2 5 8
3 6 7
3 2 15
5 4 4
6 4 10
6 5 18
*/
