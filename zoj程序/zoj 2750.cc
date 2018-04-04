#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

#define Maxn 1005
#define Maxm 10005
#define INF 1000000000

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

struct Dic {
    string front;
    string back;
    int T;
}dic[Maxn];

int main(){
    int i,j,k;
    int u,v,w;
    char str[Maxn];
    char Front[5];
    char Back[5];
    int T;
    while(~scanf("%d", &n) && n) {
        for(i = 0; i < n; i++) {
            scanf("%d ",&dic[i].T);
            scanf("%s",str);
            int len = strlen(str);
            for(k = 0,j = len-1;k < 4,j>=len-4; k++,j--) {
                Front[k] = str[k];
                Back[3-k] = str[j];
            }
            Front[4] = Back[4] = '\0';
            dic[i].front = Front;
            dic[i].back = Back;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                Edge[i][j] = INF;
                if(i == j)
                    continue;
                if(dic[i].back == dic[j].front) {
                    Edge[i][j] = dic[i].T;
                }
            }
        }
//        for(i = 0; i < n; i++)
//            cout <<dic[i].front <<" " <<dic[i].back<<endl;
        Dijkstra(0);
        if(dist[n-1] == INF)
            printf("-1\n");
        else
            printf("%d\n",dist[n-1]);
    }
return 0;
}

