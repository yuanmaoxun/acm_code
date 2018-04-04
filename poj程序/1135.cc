#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

#define Maxn 105
#define Maxm 10005
#define INF 1000000
using namespace std;
int n,m;   //
int Edge[Maxn][Maxn];
int vis[Maxn];
int dist[Maxn];
int path[Maxn];

double Maxtime1;
double Maxtime2;

void Dijkstra(int v0) {

    int i, j , k;
    for(i = 0; i < n; i++) {
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
                //path[k] = u;
            }
        }
    }
}

int main(){
    int i,j,k;
    int u,v,w;
    int Count = 1;
    while(~scanf("%d%d", &n, &m)) {

        if(n == 0 && m == 0)
            break;
        for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            Edge[i][j] = INF;
        }
        for( i = 0; i < m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            Edge[u][v] = Edge[v][u] = w;
        }
        Dijkstra( 0 );  //求定点到其他顶点的最短路径
        Maxtime1 = Maxtime2 = -1;
        int ans,res1,res2;
        for(i = 0; i < n; i++) {
            if(Maxtime1 < dist[i]){
                Maxtime1 = dist[i];
                ans = i+1;
            }
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(Edge[i][j] != INF && (dist[i] + dist[j] + Edge[i][j])/2.0 > Maxtime2) {
                    Maxtime2 = (dist[i] + dist[j] + Edge[i][j]) / 2.0;
                    res1 = i+1;
                    res2 = j+1;
                }
            }
        }
        //cout << Maxtime1 <<" " <<Maxtime2<<endl;
        printf("System #%d\n",Count++);
        if(Maxtime2 <= Maxtime1)
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",Maxtime1,ans);
        else
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",Maxtime2,res1,res2);
    }
return 0;
}
