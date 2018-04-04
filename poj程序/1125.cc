//Floyd
//注意Edge的初始化
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
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
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

int main(){
    int i,j;
    int u,v,w;
    int a,t;
    int sum[Maxn];
    while(~scanf("%d",&n) && n) {
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j)
                    Edge[i][j] = 0;
                else
                    Edge[i][j] = INF;
            }
        }
        for(i = 0; i < n; i++) {
            scanf("%d",&m);
            for(j = 0; j < m ; j++) {
                scanf("%d%d",&a,&t);
                Edge[i][--a] = t;
            }
        }
        Floyd();
        for(i = 0; i < n; i++)
            sum[i] = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                sum[i] = max(sum[i],dist[i][j]);
            }
        }
        int ans;
        int Min = INF;
        for(i = 0; i < n; i++ ) {
            if(Min > sum[i]) {
                ans = i;
                Min = sum[i];
            }
        }
        if(Min == INF)
            printf("disjoint\n");
        else
        printf("%d %d\n",ans+1,Min);
    }
}

