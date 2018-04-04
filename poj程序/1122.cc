#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

#define Maxn 105
#define Maxm 10005
#define INF 100000000

using namespace std;

int n,m;   //
int Edge[Maxn][Maxn];
int vis[Maxn];
int dist[Maxn];
int path[Maxn];

void Dijkstra(int v0) {

    int i, j , k;
    for(i = 0; i < n; i++) {
        dist[i] = Edge[v0][i];
        vis[i] = 0;
        if(i != v0 && dist[i] < INF){
            path[i] = v0;
        }
        else{
            path[i] = -1;
        }
    }

    vis[v0] = 1;
    dist[v0] = 0; //将顶点v0加入顶点集合vis中

    for(i = 0; i < n-1; i++) {
        int Min = INF;
        int u = v0;
        for(j = 0; j < n; j++) {
            if(!vis[j] && dist[j]<Min) {
                u = j;
                Min = dist[j];
            }
        }
        vis[u] = 1;   //将顶点u加入到集合vis中，表示他的最短路径以求的
        //修改剩下元素顶点dist和path数组元素值
        for(k = 0; k < n; k++){
            if( !vis[k] && Edge[u][k] < INF && dist[u]+Edge[u][k] < dist[k]){
                dist[k] = dist[u] + Edge[u][k];
                path[k] = u;
            }
        }
    }
}

int main(){
    int i,j,k;
    int u,v,w;
    int num[25][25];
    int station[25];
    while(~scanf("%d", &n)) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++){
                scanf("%d",&num[i][j]);
                Edge[i][j] = INF;
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++) {
                if(num[i][j] != -1) {
                    Edge[j][i] = num[i][j];
                }
            }
        }
        int fire;
        int x,sum;
        scanf("%d",&fire);
        sum = 0;
        memset(station,0,sizeof(station));
        while(~scanf("%d",&x)) {
            station[x-1] = 1;
            sum++;
        }
        Dijkstra(fire-1);  //求定点到其他顶点的最短路径
        printf("Org	Dest	Time	Path\n");
        while(sum) {
            int Min = INF;
            for(i = 0; i < n; i++) {
                if(dist[i] < Min && station[i]) {
                    Min = dist[i];
                    v = i;
                }
            }
            station[v] = 0;
            printf("%d	%d	%d",v+1,fire,dist[v]);
            while(v != -1) {
                printf("	%d",v+1);
                v = path[v];
            }
            printf("\n");
            sum--;
        }
       // printf("\n");
    }
return 0;
}

