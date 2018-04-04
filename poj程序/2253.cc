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
double Edge[Maxn][Maxn];
double dist[Maxn][Maxn];
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
                dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));
            }
        }
    }
}

struct Frog {
    int x;
    int y;
}frog[Maxn];

int main(){
    int i,j;
    int u,v;
    double w;
    int Count  = 0;
    while(~scanf("%d",&n) && n) {
        Count++;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                Edge[i][j] = INF;
            }
        }
        for(i = 0; i < n; i++) {
            scanf("%d%d",&frog[i].x,&frog[i].y);
        }
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                Edge[i][j] = Edge[j][i] = sqrt(1.0*(frog[i].x - frog[j].x)*(frog[i].x - frog[j].x) + 1.0*(frog[i].y - frog[j].y)*(frog[i].y - frog[j].y));
            }
        }
        Floyd();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",Count,dist[0][1]);
    }
    return 0;
}

