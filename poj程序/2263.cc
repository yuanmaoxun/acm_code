//Floyd
//循环输入时注意Edge的初始化
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<map>
#define INF 0x3f3f3f
#define Maxn 1005
using namespace std;

int n,m;
int Edge[Maxn][Maxn];
int dist[Maxn][Maxn];
int path[Maxn][Maxn];

void Floyd() {
    int i,j,k;
    for(i = 0; i < n; i++) {   //初始化
        for(j = 0; j < n; j++) {
            dist[i][j] = Edge[i][j];
            if(i != j && dist[i][j] < INF)
                path[i][j] = i;  //i到j有直接路径
            else                 //i到j没有直接路径
                path[i][j] = -1;
        }
    }
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(k == i || k == j)
                    continue;
                dist[i][j] = max(dist[i][j],min(dist[i][k],dist[k][j]));
            }
        }
    }
}

int main(){
    int i,j;
    int Count = 0;
    int u,v,w;
    char a[35],b[35];
    while(~scanf("%d%d",&n,&m)) {
        Count++;
        map<string,int> ID;
        if(n == 0&& m== 0)
            break;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                Edge[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%s %s %d",a,b,&w);
            if(ID[a] == 0) {
                ID[a] = ID.size();
            }
            if(ID[b] == 0) {
                ID[b] = ID.size();
            }
            u = ID[a] - 1;
            v = ID[b] - 1;
            Edge[u][v] = w;
            Edge[v][u] = w;
        }
        Floyd();
        scanf("%s %s",a,b);
        u = ID[a] - 1;
        v = ID[b] - 1;
        printf("Scenario #%d\n%d tons\n\n",Count,dist[u][v]);
    }
}
